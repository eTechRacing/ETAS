/*
 * File    : Inverters_Data_main.c
 *
 * Abstract:
 *      This file provides the main functionality for integration in the
 *      INTECRIO experiment environment, consisting of several void/void C
 *      functions being mapped onto the underlying ERCOSEK as processes.
 *
 * Compiler specified defines:
 *      RT              - Required.
 *      MODEL=modelname - Required.
 *      NUMST=#         - Required. Number of sample times.
 *      NCSTATES=#      - Required. Number of continuous states.
 *      TID01EQ=1 or 0  - Optional. Only define to 1 if sample time task
 *                        id's 0 and 1 have equal rates.
 *      MULTITASKING    - Optional. (use MT for a synonym).
 */

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtmodel.h"
#include "rt_sim.h"
#include "rt_nonfinite.h"
#include "ext_work.h"
#if defined(ES910) || defined(INTECRIO_VP)|| defined(TARGET_QNX86)
# include "rtExtModeEtas.h"
#endif

/*=========*
 * Defines *
 *=========*/
#ifndef TRUE
# define FALSE                         (0)
# define TRUE                          (1)
#endif

#ifndef EXIT_FAILURE
# define EXIT_FAILURE                  1
#endif

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS                  0
#endif

#define QUOTE1(name)                   #name
#define QUOTE(name)                    QUOTE1(name)              /* need to expand name    */
#ifndef RT
# error "must define RT"
#endif

#ifndef MODEL
# error "must define MODEL"
#endif

#ifndef NUMST
# error "must define number of sample times, NUMST"
#endif

#ifndef NCSTATES
# error "must define NCSTATES"
#endif

#define RUN_FOREVER                    -1.0
#define EXPAND_CONCAT(name1,name2)     name1 ## name2
#define CONCAT(name1,name2)            EXPAND_CONCAT(name1,name2)
#define RT_MODEL                       CONCAT(MODEL,_rtModel)

/*=======================*
 * External declarations *
 *=======================*/
extern RT_MODEL *MODEL(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

#if NCSTATES > 0

extern void rt_ODECreateIntegrationData(RTWSolverInfo *si);
extern void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);

# define rt_CreateIntegrationData(S)   rt_ODECreateIntegrationData(rtmGetRTWSolverInfo(S));
# define rt_UpdateContinuousStates(S)  rt_ODEUpdateContinuousStates(rtmGetRTWSolverInfo(S));
#else
# define rt_CreateIntegrationData(S)   rtsiSetSolverName(rtmGetRTWSolverInfo(S),"FixedStepDiscrete");
# define rt_UpdateContinuousStates(S)  rtmSetT(S, rtsiGetSolverStopTime(rtmGetRTWSolverInfo(S)));
#endif

/* Prototypes from ...\common\protocol\l1\p_sysdef.h.
 * Used for debug and error output via L1 communication channel
 */
extern void asdWriteUserDebug(char *s, ...);
extern void asdWriteUserError(char *s, ...);

/*==================================*
 * Global data local to this module *
 *==================================*/
static struct {
  int_T stopExecutionFlag;
  int_T isrOverrun;
  int_T overrunFlags[NUMST];
  const char_T *errmsg;
} GBLbuf;

#ifdef EXT_MODE
#  define rtExtModeSingleTaskUpload(S) { int stIdx; rtExtModeUploadCheckTrigger(rtmGetNumSampleTimes(S)); for (stIdx=0; stIdx<NUMST; stIdx++) { if (rtmIsSampleHit(S, stIdx, 0 /*unused*/)) { rtExtModeUpload(stIdx,rtmGetTaskTime(S,stIdx)); } } }
#else
# define rtExtModeSingleTaskUpload(S)                            /* Do nothing */
#endif

static RT_MODEL *S = NULL;

#ifdef EXT_MODE

RT_MODEL ** p_S;

#endif

static int_T errorFlag;

/*=================*
 * Local functions *
 *=================*/
#if !defined(MULTITASKING)             /* SINGLETASKING */

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *      Perform one step of the model. This function is modeled such that
 *      it could be called from an interrupt service routine (ISR) with minor
 *      modifications.
 */
static void rt_OneStep(RT_MODEL *S)
{
  real_T tnext;

  /***********************************************
   * Check and see if base step time is too fast *
   ***********************************************/
  if (GBLbuf.isrOverrun++) {
    GBLbuf.stopExecutionFlag = 1;
    return;
  }

  /***********************************************
   * Check and see if error status has been set  *
   ***********************************************/
  if (rtmGetErrorStatus(S) != NULL) {
    GBLbuf.stopExecutionFlag = 1;
    return;
  }

  /* enable interrupts here */
  tnext = rt_SimGetNextSampleHit();
  rtsiSetSolverStopTime(rtmGetRTWSolverInfo(S),tnext);
  MdlOutputs(0);
  rtExtModeSingleTaskUpload(S);
  MdlUpdate(0);
  rt_SimUpdateDiscreteTaskSampleHits(rtmGetNumSampleTimes(S),
    rtmGetTimingData(S),
    rtmGetSampleHitPtr(S),
    rtmGetTPtr(S));
  if (rtmGetSampleTime(S,0) == CONTINUOUS_SAMPLE_TIME) {
    rt_UpdateContinuousStates(S);
  }

  GBLbuf.isrOverrun--;
  rtExtModeCheckEndTrigger();
}                                      /* end rtOneStep */

#else                                  /* MULTITASKING */
# if TID01EQ == 1
#  define FIRST_TID                    1
# else
#  define FIRST_TID                    0
# endif

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *      Perform one step of the model. This function is modeled such that
 *      it could be called from an interrupt service routine (ISR) with minor
 *      modifications.
 *
 *      This routine is modeled for use in a multitasking environment and
 *      therefore needs to be fully re-entrant when it is called from an
 *      interrupt service routine.
 *
 * Note:
 *      Error checking is provided which will only be used if this routine
 *      is attached to an interrupt.
 *
 */
static void rt_OneStep(RT_MODEL *S)
{
  int_T eventFlags[NUMST];
  int_T i;
  real_T tnext;
  int_T *sampleHit = rtmGetSampleHitPtr(S);

  /***********************************************
   * Check and see if base step time is too fast *
   ***********************************************/
  if (GBLbuf.isrOverrun++) {
    GBLbuf.stopExecutionFlag = 1;
    return;
  }

  /***********************************************
   * Check and see if error status has been set  *
   ***********************************************/
  if (rtmGetErrorStatus(S) != NULL) {
    GBLbuf.stopExecutionFlag = 1;
    return;
  }

  /* enable interrupts here */

  /************************************************************************
   * Update discrete events and buffer event flags locally so that ISR is *
   * re-entrant.                                                          *
   ************************************************************************/
  tnext = rt_SimUpdateDiscreteEvents(rtmGetNumSampleTimes(S),
    rtmGetTimingData(S),
    rtmGetSampleHitPtr(S),
    rtmGetPerTaskSampleHitsPtr(S));
  rtsiSetSolverStopTime(rtmGetRTWSolverInfo(S),tnext);
  for (i=FIRST_TID+1; i < NUMST; i++) {
    eventFlags[i] = sampleHit[i];
  }

  /*******************************************
   * Step the model for the base sample time *
   *******************************************/
  MdlOutputs(FIRST_TID);
  rtExtModeUploadCheckTrigger(rtmGetNumSampleTimes(S));
  rtExtModeUpload(FIRST_TID,rtmGetTaskTime(S, FIRST_TID));
  MdlUpdate(FIRST_TID);
  if (rtmGetSampleTime(S,0) == CONTINUOUS_SAMPLE_TIME) {
    rt_UpdateContinuousStates(S);
  } else {
    rt_SimUpdateDiscreteTaskTime(rtmGetTPtr(S),
      rtmGetTimingData(S), 0);
  }

#if FIRST_TID == 1

  rt_SimUpdateDiscreteTaskTime(rtmGetTPtr(S),
    rtmGetTimingData(S),1);

#endif

  /************************************************************************
   * Model step complete for base sample time, now it is okay to          *
   * re-interrupt this ISR.                                               *
   ************************************************************************/
  GBLbuf.isrOverrun--;

  /*********************************************
   * Step the model for any other sample times *
   *********************************************/
  for (i=FIRST_TID+1; i<NUMST; i++) {
    if (eventFlags[i]) {
      if (GBLbuf.overrunFlags[i]++) {  /* Are we sampling too fast for */
        GBLbuf.stopExecutionFlag= 1;   /*   sample time "i"?           */
        return;
      }

      MdlOutputs(i);
      rtExtModeUpload(i, rtmGetTaskTime(S,i));
      MdlUpdate(i);
      rt_SimUpdateDiscreteTaskTime(rtmGetTPtr(S),
        rtmGetTimingData(S),i);

      /* Indicate task complete for sample time "i" */
      GBLbuf.overrunFlags[i]--;
    }
  }

  rtExtModeCheckEndTrigger();
}                                      /* end rtOneStep */

#endif                                 /* MULTITASKING */

/* Function: checkForErrors ===================================================
 *
 * Abstract:
 *      Check for errors and produce appropriate output if applicable.
 *
 */
static int_T checkForErrors(RT_MODEL *S)
{
  if (GBLbuf.errmsg) {
    asdWriteUserError("IRT RTI: %s\n",GBLbuf.errmsg);
    errorFlag = 1;
    return 1;
  }

  if (GBLbuf.isrOverrun) {
    asdWriteUserError("IRT RTI: %s: ISR overrun - base sampling rate is "
                      "too fast\n", QUOTE(MODEL));
    errorFlag = 1;
    return 1;
  }

  if (rtmGetErrorStatus(S) != NULL) {
    asdWriteUserError("IRT RTI: %s\n", rtmGetErrorStatus(S));
    errorFlag = 1;
    return 1;
  }

#ifdef MULTITASKING

  else {
    int_T i;
    for (i=1; i<NUMST; i++) {
      if (GBLbuf.overrunFlags[i]) {
        asdWriteUserError("IRT RTI: %s ISR overrun - sampling rate is "
                          "too fast for sample time index %d\n",
                          QUOTE(MODEL), i);
        errorFlag = 1;
        return 1;
      }
    }
  }
#endif

  return 0;
}                                      /* end checkForErrors */

/*===================*
 * Visible functions *
 *===================*/
void irt_Terminate_Inverters_Data();

/* Function: irt_Start_Inverters_Data ========================================================
 *
 * Abstract:
 *   Initialize model on the INTECRIO experimental target.
 *   This void/void function is a process being mapped onto an init task of
 *   the underlying ERCOSEK operating system.
 *
 */
void irt_Start_Inverters_Data()
{
  const char *status;

  /* Simulate arguments */
#ifdef EXT_MODE

  int_T argc = 0;
  const char_T *argv[] = { "" };

#endif

  /*****************************************
   * Terminate simulation if still running *
   *****************************************/
  if (S != NULL) {
    irt_Terminate_Inverters_Data();
  }

  rtExtModeParseArgs(argc, argv, NULL);

  /****************************
   * Initialize global memory *
   ****************************/
  (void)memset(&GBLbuf, 0, sizeof(GBLbuf));
  errorFlag = 0;

  /************************
   * Initialize the model *
   ************************/
  rt_InitInfAndNaN(sizeof(real_T));
  S = MODEL();
  if (rtmGetErrorStatus(S) != NULL) {
    asdWriteUserError("IRT RTI: Error during model registration: %s\n",
                      rtmGetErrorStatus(S));
    errorFlag = 1;
    return;
  }

#ifdef EXT_MODE

  p_S = &S;

#endif

  MdlInitializeSizes();
  MdlInitializeSampleTimes();
  status = rt_SimInitTimingEngine(rtmGetNumSampleTimes(S),
    rtmGetStepSize(S),
    rtmGetSampleTimePtr(S),
    rtmGetOffsetTimePtr(S),
    rtmGetSampleHitPtr(S),
    rtmGetSampleTimeTaskIDPtr(S),
    rtmGetTStart(S),
    &rtmGetSimTimeStep(S),
    &rtmGetTimingData(S));
  if (status != NULL) {
    asdWriteUserError("IRT RTI: Failed to initialize sample time "
                      "engine: %s\n", status);
    errorFlag = 1;
    return;
  }

  rt_CreateIntegrationData(S);

#ifdef EXT_MODE
# if defined(ES910) || defined(INTECRIO_VP) || defined(TARGET_QNX86)

  rtExtModeEtasStartup( rtmGetRTWExtModeInfo(S),
                       rtmGetNumSampleTimes(S),
                       (boolean_T *)&rtmGetStopRequested(S));

# else
#  ifdef ES113X

  rtExtModeCheckInit(rtmGetNumSampleTimes(S));

#  else
#    error "External mode activated for unsupported target."
#  endif
# endif
#endif

#ifdef IRTWaitForStartMsg

  rtmGetStopRequested(S) = TRUE;

#else

  rtmGetStopRequested(S) = FALSE;

#endif

  asdWriteUserDebug("IRT RTI: ** starting model Inverters_Data **\n");
  MdlStart();
  if (rtmGetErrorStatus(S) != NULL) {
    GBLbuf.stopExecutionFlag = 1;
  }

  /*************************************************************************
   * Execute the model.  You may attach rtOneStep to an ISR, if so replace *
   * the call to rtOneStep (below) with a call to a background task        *
   * application.                                                          *
   *************************************************************************/
}                                      /* end irt_Start_Inverters_Data */

/* Function: irt_OneStep_Inverters_Data ======================================================
 *
 * Abstract:
 *   Perform one step of the model.
 *   This void/void function is a process being mapped onto an alarm task of
 *   the underlying ERCOSEK operating system.
 *
 */
void irt_OneStep_Inverters_Data()
{
  if (errorFlag) {
    return;
  }

  if (S == NULL) {
    asdWriteUserError("IRT RTI: Error during model execution: "
                      "simulation structure not initialized\n");
    errorFlag = 1;
    return;
  }

  if (!GBLbuf.stopExecutionFlag && !rtmGetStopRequested(S)) {
    rt_OneStep(S);
  }

  checkForErrors(S);
}                                      /* end irt_OneStep_Inverters_Data */

/* Function: irt_Terminate_Inverters_Data ====================================================
 *
 * Abstract:
 *   Shutdown the model on the INTECRIO experimental target.
 *   This void/void function is a process being mapped onto an init or
 *   software task of the underlying ERCOSEK operating system, which is
 *   called upon termination of the experiment.
 *
 */
void irt_Terminate_Inverters_Data()
{
  if (S != NULL) {
    if (errorFlag) {
      return;
    }

    if (!GBLbuf.stopExecutionFlag && !rtmGetStopRequested(S)) {
      /* Execute model last time step */
      rt_OneStep(S);
    }

    /********************
     * Cleanup and exit *
     ********************/
#ifdef EXT_MODE
# if defined(ES910) || defined(INTECRIO_VP)|| defined(TARGET_QNX86)

    rtExtModeEtasCleanup(rtmGetNumSampleTimes(S));

# else

    rtExtModeShutdown(rtmGetNumSampleTimes(S));

# endif
#endif

    if (checkForErrors(S)) {
      return;
    }

    MdlTerminate();
    S = NULL;
  }
}                                      /* end irt_Terminate_Inverters_Data */

/* EOF: Inverters_Data_main.c */
