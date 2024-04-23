/*
 * Ellipse.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ellipse".
 *
 * Model version              : 13.0
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Apr 23 14:19:23 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ellipse.h"
#include <string.h>
#include "rt_nonfinite.h"

/* External inputs (root inport signals with default storage) */
ExtU_Ellipse_T Ellipse_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Ellipse_T Ellipse_Y;

/* Real-time model */
static RT_MODEL_Ellipse_T Ellipse_M_;
RT_MODEL_Ellipse_T *const Ellipse_M = &Ellipse_M_;

/* Model output function */
static void Ellipse_output(void)
{
  /* Outport: '<Root>/Lat_EKF' incorporates:
   *  Inport: '<Root>/el_LATITUDE_EKF'
   */
  Ellipse_Y.Lat_EKF = Ellipse_U.el_LATITUDE_EKF;

  /* Outport: '<Root>/Long_EKF' incorporates:
   *  Inport: '<Root>/el_LONGITUDE_EKF'
   */
  Ellipse_Y.Long_EKF = Ellipse_U.el_LONGITUDE_EKF;

  /* Outport: '<Root>/TrackAngle' incorporates:
   *  Inport: '<Root>/el_AngleTrack'
   */
  Ellipse_Y.TrackAngle = Ellipse_U.el_AngleTrack;

  /* Outport: '<Root>/CurvRadius' incorporates:
   *  Inport: '<Root>/el_CurvatureRadius'
   */
  Ellipse_Y.CurvRadius = Ellipse_U.el_CurvatureRadius;

  /* Outport: '<Root>/Status_Auto' incorporates:
   *  Inport: '<Root>/el_AUTO_STATUS'
   */
  Ellipse_Y.Status_Auto = Ellipse_U.el_AUTO_STATUS;
}

/* Model update function */
static void Ellipse_update(void)
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
  if (!(++Ellipse_M->Timing.clockTick0)) {
    ++Ellipse_M->Timing.clockTickH0;
  }

  Ellipse_M->Timing.t[0] = Ellipse_M->Timing.clockTick0 *
    Ellipse_M->Timing.stepSize0 + Ellipse_M->Timing.clockTickH0 *
    Ellipse_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Ellipse_initialize(void)
{
}

/* Model terminate function */
static void Ellipse_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Ellipse_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Ellipse_update();
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
  Ellipse_initialize();
}

void MdlTerminate(void)
{
  Ellipse_terminate();
}

/* Registration function */
RT_MODEL_Ellipse_T *Ellipse(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Ellipse_M, 0,
                sizeof(RT_MODEL_Ellipse_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Ellipse_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Ellipse_M points to
       static memory which is guaranteed to be non-NULL" */
    Ellipse_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Ellipse_M->Timing.sampleTimes = (&Ellipse_M->Timing.sampleTimesArray[0]);
    Ellipse_M->Timing.offsetTimes = (&Ellipse_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Ellipse_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Ellipse_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Ellipse_M, &Ellipse_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Ellipse_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Ellipse_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Ellipse_M, 10.0);
  Ellipse_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Ellipse_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Ellipse_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Ellipse_M->rtwLogInfo, (NULL));
    rtliSetLogT(Ellipse_M->rtwLogInfo, "tout");
    rtliSetLogX(Ellipse_M->rtwLogInfo, "");
    rtliSetLogXFinal(Ellipse_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Ellipse_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Ellipse_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Ellipse_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Ellipse_M->rtwLogInfo, 1);
    rtliSetLogY(Ellipse_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Ellipse_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Ellipse_M->rtwLogInfo, (NULL));
  }

  Ellipse_M->solverInfoPtr = (&Ellipse_M->solverInfo);
  Ellipse_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Ellipse_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Ellipse_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* external inputs */
  Ellipse_M->inputs = (((void*)&Ellipse_U));
  (void)memset(&Ellipse_U, 0, sizeof(ExtU_Ellipse_T));

  /* external outputs */
  Ellipse_M->outputs = (&Ellipse_Y);
  (void)memset(&Ellipse_Y, 0, sizeof(ExtY_Ellipse_T));

  /* Initialize Sizes */
  Ellipse_M->Sizes.numContStates = (0);/* Number of continuous states */
  Ellipse_M->Sizes.numY = (5);         /* Number of model outputs */
  Ellipse_M->Sizes.numU = (5);         /* Number of model inputs */
  Ellipse_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Ellipse_M->Sizes.numSampTimes = (1); /* Number of sample times */
  Ellipse_M->Sizes.numBlocks = (5);    /* Number of blocks */
  return Ellipse_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
