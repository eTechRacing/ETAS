/*
 * Ellipse.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ellipse".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Jun 10 10:43:30 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ellipse.h"
#include "Ellipse_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Ellipse_T Ellipse_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Ellipse_T Ellipse_Y;

/* Real-time model */
RT_MODEL_Ellipse_T Ellipse_M_;
RT_MODEL_Ellipse_T *const Ellipse_M = &Ellipse_M_;

/* Model output function */
static void Ellipse_output(void)
{
  /* Outport: '<Root>/Roll_Tx' incorporates:
   *  Inport: '<Root>/ROLL'
   */
  Ellipse_Y.Roll_Tx = Ellipse_U.ROLL;

  /* Outport: '<Root>/Pitch_Tx' incorporates:
   *  Inport: '<Root>/PITCH'
   */
  Ellipse_Y.Pitch_Tx = Ellipse_U.PITCH;

  /* Outport: '<Root>/Yaw_Tx' incorporates:
   *  Inport: '<Root>/YAW'
   */
  Ellipse_Y.Yaw_Tx = Ellipse_U.YAW;

  /* Outport: '<Root>/Lat_EKF' incorporates:
   *  Inport: '<Root>/LATITUDE_EKF'
   */
  Ellipse_Y.Lat_EKF = Ellipse_U.LATITUDE_EKF;

  /* Outport: '<Root>/Long_EKF' incorporates:
   *  Inport: '<Root>/LONGITUDE_EKF'
   */
  Ellipse_Y.Long_EKF = Ellipse_U.LONGITUDE_EKF;

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
   *  Inport: '<Root>/ACCEL_X_IMU'
   */
  Ellipse_Y.Accel_X_IMU_Tx = Ellipse_U.ACCEL_X_IMU;

  /* Outport: '<Root>/Accel_Y_IMU_Tx' incorporates:
   *  Inport: '<Root>/ACCEL_Y_IMU'
   */
  Ellipse_Y.Accel_Y_IMU_Tx = Ellipse_U.ACCEL_Y_IMU;

  /* Outport: '<Root>/Accel_Z_IMU_Tx' incorporates:
   *  Inport: '<Root>/ACCEL_Z_IMU'
   */
  Ellipse_Y.Accel_Z_IMU_Tx = Ellipse_U.ACCEL_Z_IMU;

  /* Outport: '<Root>/Gyro_X_Tx' incorporates:
   *  Inport: '<Root>/GYRO_X'
   */
  Ellipse_Y.Gyro_X_Tx = Ellipse_U.GYRO_X;

  /* Outport: '<Root>/Gyro_Y_Tx' incorporates:
   *  Inport: '<Root>/GYRO_Y'
   */
  Ellipse_Y.Gyro_Y_Tx = Ellipse_U.GYRO_Y;

  /* Outport: '<Root>/Gyro_Z_Tx' incorporates:
   *  Inport: '<Root>/GYRO_Z'
   */
  Ellipse_Y.Gyro_Z_Tx = Ellipse_U.GYRO_Z;

  /* Outport: '<Root>/Accel_X_Mag_Tx' incorporates:
   *  Inport: '<Root>/ACCEL_X_MAG'
   */
  Ellipse_Y.Accel_X_Mag_Tx = Ellipse_U.ACCEL_X_MAG;

  /* Outport: '<Root>/Accel_Y_Mag_Tx' incorporates:
   *  Inport: '<Root>/ACCEL_Y_MAG'
   */
  Ellipse_Y.Accel_Y_Mag_Tx = Ellipse_U.ACCEL_Y_MAG;

  /* Outport: '<Root>/Accel_Z_Mag_Tx' incorporates:
   *  Inport: '<Root>/ACCEL_Z_MAG'
   */
  Ellipse_Y.Accel_Z_Mag_Tx = Ellipse_U.ACCEL_Z_MAG;

  /* Outport: '<Root>/TrackAngle' incorporates:
   *  Inport: '<Root>/ANGLE_TRACK'
   */
  Ellipse_Y.TrackAngle = Ellipse_U.ANGLE_TRACK;

  /* Outport: '<Root>/SlipAngle' incorporates:
   *  Inport: '<Root>/ANGLE_SLIP'
   */
  Ellipse_Y.SlipAngle = Ellipse_U.ANGLE_SLIP;

  /* Outport: '<Root>/CurvRadius' incorporates:
   *  Inport: '<Root>/CURVATURE_RADIUS'
   */
  Ellipse_Y.CurvRadius = Ellipse_U.CURVATURE_RADIUS;

  /* Outport: '<Root>/Status_Auto' incorporates:
   *  Inport: '<Root>/AUTO_STATUS'
   */
  Ellipse_Y.Status_Auto = Ellipse_U.AUTO_STATUS;

  /* Outport: '<Root>/Time' incorporates:
   *  Inport: '<Root>/TIME_STAMP'
   */
  Ellipse_Y.Time = Ellipse_U.TIME_STAMP;

  /* Outport: '<Root>/General_Tx' incorporates:
   *  Inport: '<Root>/GENERAL'
   */
  Ellipse_Y.General_Tx = Ellipse_U.GENERAL;

  /* Outport: '<Root>/Clock_Tx' incorporates:
   *  Inport: '<Root>/CLOCK'
   */
  Ellipse_Y.Clock_Tx = Ellipse_U.CLOCK;
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
  Ellipse_M->solverInfoPtr = (&Ellipse_M->solverInfo);
  Ellipse_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Ellipse_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Ellipse_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* external inputs */
  Ellipse_M->inputs = (((void*)&Ellipse_U));
  (void)memset((void *)&Ellipse_U, 0, sizeof(ExtU_Ellipse_T));

  /* external outputs */
  Ellipse_M->outputs = (&Ellipse_Y);
  (void) memset((void *)&Ellipse_Y, 0,
                sizeof(ExtY_Ellipse_T));

  /* Initialize Sizes */
  Ellipse_M->Sizes.numContStates = (0);/* Number of continuous states */
  Ellipse_M->Sizes.numY = (24);        /* Number of model outputs */
  Ellipse_M->Sizes.numU = (24);        /* Number of model inputs */
  Ellipse_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Ellipse_M->Sizes.numSampTimes = (1); /* Number of sample times */
  Ellipse_M->Sizes.numBlocks = (24);   /* Number of blocks */
  return Ellipse_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
