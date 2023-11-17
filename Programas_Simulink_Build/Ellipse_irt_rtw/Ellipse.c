/*
 * Ellipse.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ellipse".
 *
 * Model version              : 10.0
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Fri Nov 17 17:13:30 2023
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
  /* Outport: '<Root>/Roll_Tx' incorporates:
   *  Inport: '<Root>/el_ROLL'
   */
  Ellipse_Y.Roll_Tx = Ellipse_U.el_ROLL;

  /* Outport: '<Root>/Pitch_Tx' incorporates:
   *  Inport: '<Root>/el_PITCH'
   */
  Ellipse_Y.Pitch_Tx = Ellipse_U.el_PITCH;

  /* Outport: '<Root>/Yaw_Tx' incorporates:
   *  Inport: '<Root>/el_YAW'
   */
  Ellipse_Y.Yaw_Tx = Ellipse_U.el_YAW;

  /* Outport: '<Root>/Lat_EKF' incorporates:
   *  Inport: '<Root>/el_LATITUDE_EKF'
   */
  Ellipse_Y.Lat_EKF = Ellipse_U.el_LATITUDE_EKF;

  /* Outport: '<Root>/Long_EKF' incorporates:
   *  Inport: '<Root>/el_LONGITUDE_EKF'
   */
  Ellipse_Y.Long_EKF = Ellipse_U.el_LONGITUDE_EKF;

  /* Outport: '<Root>/Vel_X' incorporates:
   *  Inport: '<Root>/el_Vel_X'
   */
  Ellipse_Y.Vel_X = Ellipse_U.el_Vel_X;

  /* Outport: '<Root>/Vel_Y' incorporates:
   *  Inport: '<Root>/el_Vel_Y'
   */
  Ellipse_Y.Vel_Y = Ellipse_U.el_Vel_Y;

  /* Outport: '<Root>/Vel_Z' incorporates:
   *  Inport: '<Root>/el_Vel_Z'
   */
  Ellipse_Y.Vel_Z = Ellipse_U.el_Vel_Z;

  /* Outport: '<Root>/Accel_X_IMU_Tx' incorporates:
   *  Inport: '<Root>/el_ACCEL_X'
   */
  Ellipse_Y.Accel_X_IMU_Tx = Ellipse_U.el_ACCEL_X;

  /* Outport: '<Root>/Accel_Y_IMU_Tx' incorporates:
   *  Inport: '<Root>/el_ACCEL_Y'
   */
  Ellipse_Y.Accel_Y_IMU_Tx = Ellipse_U.el_ACCEL_Y;

  /* Outport: '<Root>/Accel_Z_IMU_Tx' incorporates:
   *  Inport: '<Root>/el_ACCEL_Z'
   */
  Ellipse_Y.Accel_Z_IMU_Tx = Ellipse_U.el_ACCEL_Z;

  /* Outport: '<Root>/Gyro_X_Tx' incorporates:
   *  Inport: '<Root>/el_GYRO_X'
   */
  Ellipse_Y.Gyro_X_Tx = Ellipse_U.el_GYRO_X;

  /* Outport: '<Root>/Gyro_Y_Tx' incorporates:
   *  Inport: '<Root>/el_GYRO_Y'
   */
  Ellipse_Y.Gyro_Y_Tx = Ellipse_U.el_GYRO_Y;

  /* Outport: '<Root>/Gyro_Z_Tx' incorporates:
   *  Inport: '<Root>/el_GYRO_Z'
   */
  Ellipse_Y.Gyro_Z_Tx = Ellipse_U.el_GYRO_Z;

  /* Outport: '<Root>/TrackAngle' incorporates:
   *  Inport: '<Root>/el_AngleTrack'
   */
  Ellipse_Y.TrackAngle = Ellipse_U.el_AngleTrack;

  /* Outport: '<Root>/SlipAngle' incorporates:
   *  Inport: '<Root>/el_SlipAngle'
   */
  Ellipse_Y.SlipAngle = Ellipse_U.el_SlipAngle;

  /* Outport: '<Root>/CurvRadius' incorporates:
   *  Inport: '<Root>/el_CurvatureRadius'
   */
  Ellipse_Y.CurvRadius = Ellipse_U.el_CurvatureRadius;

  /* Outport: '<Root>/Status_Auto' incorporates:
   *  Inport: '<Root>/el_AUTO_STATUS'
   */
  Ellipse_Y.Status_Auto = Ellipse_U.el_AUTO_STATUS;

  /* Outport: '<Root>/Time' incorporates:
   *  Inport: '<Root>/el_TIME_STAMP'
   */
  Ellipse_Y.Time = Ellipse_U.el_TIME_STAMP;

  /* Outport: '<Root>/General_Tx' incorporates:
   *  Inport: '<Root>/el_GENERAL'
   */
  Ellipse_Y.General_Tx = Ellipse_U.el_GENERAL;

  /* Outport: '<Root>/Clock_Tx' incorporates:
   *  Inport: '<Root>/el_CLOCK'
   */
  Ellipse_Y.Clock_Tx = Ellipse_U.el_CLOCK;
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
  Ellipse_M->Sizes.numY = (21);        /* Number of model outputs */
  Ellipse_M->Sizes.numU = (21);        /* Number of model inputs */
  Ellipse_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Ellipse_M->Sizes.numSampTimes = (1); /* Number of sample times */
  Ellipse_M->Sizes.numBlocks = (21);   /* Number of blocks */
  return Ellipse_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
