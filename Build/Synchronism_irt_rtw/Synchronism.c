/*
 * Synchronism.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Synchronism".
 *
 * Model version              : 13.0
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Apr 22 17:12:40 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Synchronism.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_Synchronism_T Synchronism_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Synchronism_T Synchronism_Y;

/* Real-time model */
static RT_MODEL_Synchronism_T Synchronism_M_;
RT_MODEL_Synchronism_T *const Synchronism_M = &Synchronism_M_;

/* Model output function */
static void Synchronism_output(void)
{
  real_T rtb_Add;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read'
   */
  rtb_Add = Synchronism_DW.counter + 1.0;

  /* If: '<S1>/If' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S1>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read'
   *  Sum: '<S1>/Add'
   */
  if (Synchronism_DW.counter + 1.0 > 200.0) {
    /* Outputs for IfAction SubSystem: '<S1>/Reset_counter' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* SignalConversion generated from: '<S4>/1' incorporates:
     *  Constant: '<S4>/Constant'
     */
    rtb_Add = 1.0;

    /* End of Outputs for SubSystem: '<S1>/Reset_counter' */
  }

  /* End of If: '<S1>/If' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  Synchronism_DW.counter = rtb_Add;

  /* Outport: '<Root>/Sync_CAN1' */
  Synchronism_Y.Sync_CAN1 = rtb_Add;

  /* Outport: '<Root>/Sync_CAN2' */
  Synchronism_Y.Sync_CAN2 = rtb_Add;
}

/* Model update function */
static void Synchronism_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Synchronism_M->Timing.clockTick0)) {
    ++Synchronism_M->Timing.clockTickH0;
  }

  Synchronism_M->Timing.t[0] = Synchronism_M->Timing.clockTick0 *
    Synchronism_M->Timing.stepSize0 + Synchronism_M->Timing.clockTickH0 *
    Synchronism_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Synchronism_initialize(void)
{
  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  Synchronism_DW.counter = 0.0;
}

/* Model terminate function */
static void Synchronism_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Synchronism_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Synchronism_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Synchronism_initialize();
}

void MdlTerminate(void)
{
  Synchronism_terminate();
}

/* Registration function */
RT_MODEL_Synchronism_T *Synchronism(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Synchronism_M, 0,
                sizeof(RT_MODEL_Synchronism_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Synchronism_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Synchronism_M points to
       static memory which is guaranteed to be non-NULL" */
    Synchronism_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Synchronism_M->Timing.sampleTimes = (&Synchronism_M->
      Timing.sampleTimesArray[0]);
    Synchronism_M->Timing.offsetTimes = (&Synchronism_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    Synchronism_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Synchronism_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Synchronism_M, &Synchronism_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Synchronism_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Synchronism_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Synchronism_M, 10.0);
  Synchronism_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Synchronism_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Synchronism_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Synchronism_M->rtwLogInfo, (NULL));
    rtliSetLogT(Synchronism_M->rtwLogInfo, "tout");
    rtliSetLogX(Synchronism_M->rtwLogInfo, "");
    rtliSetLogXFinal(Synchronism_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Synchronism_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Synchronism_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Synchronism_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Synchronism_M->rtwLogInfo, 1);
    rtliSetLogY(Synchronism_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Synchronism_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Synchronism_M->rtwLogInfo, (NULL));
  }

  Synchronism_M->solverInfoPtr = (&Synchronism_M->solverInfo);
  Synchronism_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Synchronism_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Synchronism_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* states (dwork) */
  Synchronism_M->dwork = ((void *) &Synchronism_DW);
  (void) memset((void *)&Synchronism_DW, 0,
                sizeof(DW_Synchronism_T));

  /* external outputs */
  Synchronism_M->outputs = (&Synchronism_Y);
  (void)memset(&Synchronism_Y, 0, sizeof(ExtY_Synchronism_T));

  /* Initialize Sizes */
  Synchronism_M->Sizes.numContStates = (0);/* Number of continuous states */
  Synchronism_M->Sizes.numY = (2);     /* Number of model outputs */
  Synchronism_M->Sizes.numU = (0);     /* Number of model inputs */
  Synchronism_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Synchronism_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Synchronism_M->Sizes.numBlocks = (15);/* Number of blocks */
  Synchronism_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  return Synchronism_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
