/*
 * VDC_Winter_Testing.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VDC_Winter_Testing".
 *
 * Model version              : 4.218
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Oct 10 15:43:48 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VDC_Winter_Testing.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_VDC_Winter_Testing_T VDC_Winter_Testing_DW;

/* External inputs (root inport signals with default storage) */
ExtU_VDC_Winter_Testing_T VDC_Winter_Testing_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_VDC_Winter_Testing_T VDC_Winter_Testing_Y;

/* Real-time model */
static RT_MODEL_VDC_Winter_Testing_T VDC_Winter_Testing_M_;
RT_MODEL_VDC_Winter_Testing_T *const VDC_Winter_Testing_M =
  &VDC_Winter_Testing_M_;

/* Model output function */
static void VDC_Winter_Testing_output(void)
{
  real_T Throttle_Response;
  real_T rtb_Merge1_e;
  real_T rtb_Throttle_Torque;
  boolean_T rtb_LogicalOperator;

  /* If: '<S7>/If' incorporates:
   *  Abs: '<S7>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S7>/Sum'
   */
  if (fabs(VDC_Winter_Testing_U.APPS1_Value - VDC_Winter_Testing_U.APPS2_Value) >
      0.1) {
    /* Outputs for IfAction SubSystem: '<S7>/Imp' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Sum: '<S10>/Add' incorporates:
     *  Constant: '<S10>/Constant'
     *  DataStoreRead: '<S10>/Data Store Read'
     */
    rtb_Merge1_e = VDC_Winter_Testing_DW.ERROR_Counter + 1.0;

    /* End of Outputs for SubSystem: '<S7>/Imp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S7>/Not Imp' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* SignalConversion generated from: '<S11>/0' incorporates:
     *  Constant: '<S11>/Constant'
     */
    rtb_Merge1_e = 0.0;

    /* End of Outputs for SubSystem: '<S7>/Not Imp' */
  }

  /* End of If: '<S7>/If' */

  /* DataStoreWrite: '<S7>/Data Store Write' */
  VDC_Winter_Testing_DW.ERROR_Counter = rtb_Merge1_e;

  /* Outputs for IfAction SubSystem: '<S7>/Signal_OK' incorporates:
   *  ActionPort: '<S13>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S7>/Signal_Failure' incorporates:
   *  ActionPort: '<S12>/Action Port'
   */
  /* If: '<S7>/If1' incorporates:
   *  Constant: '<S7>/Number_of_Periods'
   *  SignalConversion generated from: '<S12>/Out1'
   *  SignalConversion generated from: '<S13>/Out1'
   */
  rtb_Merge1_e = (rtb_Merge1_e > 4.0);

  /* End of Outputs for SubSystem: '<S7>/Signal_Failure' */
  /* End of Outputs for SubSystem: '<S7>/Signal_OK' */

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S3>/Logical Operator1'
   *  Logic: '<S3>/NOT'
   *  RelationalOperator: '<S8>/Compare'
   */
  rtb_LogicalOperator = (VDC_Winter_Testing_U.Shutdown_PackageIntck &&
    VDC_Winter_Testing_U.TorqueEnable &&
    (!VDC_Winter_Testing_U.CriticalDisconnection) &&
    (VDC_Winter_Testing_U.Car_State == 15.0) && (!(rtb_Merge1_e != 0.0)));

  /* MATLAB Function: '<Root>/Torque demanded by the driver' incorporates:
   *  Constant: '<Root>/AP_sat_down'
   *  Constant: '<Root>/AP_sat_up'
   *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
   *  Inport: '<Root>/APPS1_Value'
   */
  if (VDC_Winter_Testing_U.APPS1_Value <= 0.05) {
    Throttle_Response = 0.0;
  } else if (VDC_Winter_Testing_U.APPS1_Value >= 1.0) {
    Throttle_Response = 1.0;
  } else {
    Throttle_Response = (VDC_Winter_Testing_U.APPS1_Value - 0.05) / 0.95;
  }

  rtb_Throttle_Torque = Throttle_Response * 27.0;

  /* End of MATLAB Function: '<Root>/Torque demanded by the driver' */

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Saturate: '<Root>/Saturation1'
   */
  if (rtb_Throttle_Torque > 27.0) {
    Throttle_Response = 27.0;
    rtb_Throttle_Torque = 27.0;
  } else if (rtb_Throttle_Torque < 0.0) {
    Throttle_Response = 0.0;
    rtb_Throttle_Torque = 0.0;
  } else {
    Throttle_Response = rtb_Throttle_Torque;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/Safety' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Inport: '<Root>/RacingMode'
   */
  if (rtb_LogicalOperator && (VDC_Winter_Testing_U.RacingMode != 1.0) && (fmax
       (VDC_Winter_Testing_U.RR_rads_Motor, VDC_Winter_Testing_U.RL_rads_Motor) <
       1727.8759594743863)) {
    /* Outport: '<Root>/Torque_R' */
    VDC_Winter_Testing_Y.Torque_R = Throttle_Response;

    /* Outport: '<Root>/Torque_L' */
    VDC_Winter_Testing_Y.Torque_L = rtb_Throttle_Torque;
  } else if (rtb_LogicalOperator && (VDC_Winter_Testing_U.RacingMode == 1.0) &&
             (fmax(VDC_Winter_Testing_U.RR_rads_Motor,
                   VDC_Winter_Testing_U.RL_rads_Motor) < 209.43951023931953)) {
    Throttle_Response /= 9.0;

    /* Outport: '<Root>/Torque_R' */
    VDC_Winter_Testing_Y.Torque_R = Throttle_Response;

    /* Outport: '<Root>/Torque_L' */
    VDC_Winter_Testing_Y.Torque_L = Throttle_Response;
  } else {
    /* Outport: '<Root>/Torque_R' */
    VDC_Winter_Testing_Y.Torque_R = 0.0;

    /* Outport: '<Root>/Torque_L' */
    VDC_Winter_Testing_Y.Torque_L = 0.0;
  }

  /* End of MATLAB Function: '<Root>/Safety' */

  /* Outport: '<Root>/APPS_Implausibility' */
  VDC_Winter_Testing_Y.APPS_Implausibility = rtb_Merge1_e;

  /* Outport: '<Root>/Torque_OK' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  VDC_Winter_Testing_Y.Torque_OK = rtb_LogicalOperator;

  /* Outport: '<Root>/BrakeLight_Control' incorporates:
   *  Constant: '<Root>/Brake_Light_Threshold'
   *  Inport: '<Root>/BrakePedal_Value'
   *  MATLAB Function: '<Root>/Brake_Light'
   */
  VDC_Winter_Testing_Y.BrakeLight_Control =
    (VDC_Winter_Testing_U.BrakePedal_Value > 0.2);
}

/* Model update function */
static void VDC_Winter_Testing_update(void)
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
  if (!(++VDC_Winter_Testing_M->Timing.clockTick0)) {
    ++VDC_Winter_Testing_M->Timing.clockTickH0;
  }

  VDC_Winter_Testing_M->Timing.t[0] = VDC_Winter_Testing_M->Timing.clockTick0 *
    VDC_Winter_Testing_M->Timing.stepSize0 +
    VDC_Winter_Testing_M->Timing.clockTickH0 *
    VDC_Winter_Testing_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void VDC_Winter_Testing_initialize(void)
{
  /* Start for DataStoreMemory: '<S7>/Data Store Memory1' */
  VDC_Winter_Testing_DW.ERROR_Counter = 0.0;

  /* ConstCode for Outport: '<Root>/VDC_Max_Tyre_Slip' incorporates:
   *  Constant: '<Root>/Max_Tyre_Slip'
   */
  VDC_Winter_Testing_Y.VDC_Max_Tyre_Slip = 1.3;
}

/* Model terminate function */
static void VDC_Winter_Testing_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  VDC_Winter_Testing_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  VDC_Winter_Testing_update();
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
  VDC_Winter_Testing_initialize();
}

void MdlTerminate(void)
{
  VDC_Winter_Testing_terminate();
}

/* Registration function */
RT_MODEL_VDC_Winter_Testing_T *VDC_Winter_Testing(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)VDC_Winter_Testing_M, 0,
                sizeof(RT_MODEL_VDC_Winter_Testing_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = VDC_Winter_Testing_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "VDC_Winter_Testing_M points to
       static memory which is guaranteed to be non-NULL" */
    VDC_Winter_Testing_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    VDC_Winter_Testing_M->Timing.sampleTimes =
      (&VDC_Winter_Testing_M->Timing.sampleTimesArray[0]);
    VDC_Winter_Testing_M->Timing.offsetTimes =
      (&VDC_Winter_Testing_M->Timing.offsetTimesArray[0]);

    /* task periods */
    VDC_Winter_Testing_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    VDC_Winter_Testing_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(VDC_Winter_Testing_M, &VDC_Winter_Testing_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = VDC_Winter_Testing_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    VDC_Winter_Testing_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(VDC_Winter_Testing_M, 10.0);
  VDC_Winter_Testing_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    VDC_Winter_Testing_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(VDC_Winter_Testing_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(VDC_Winter_Testing_M->rtwLogInfo, (NULL));
    rtliSetLogT(VDC_Winter_Testing_M->rtwLogInfo, "tout");
    rtliSetLogX(VDC_Winter_Testing_M->rtwLogInfo, "");
    rtliSetLogXFinal(VDC_Winter_Testing_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(VDC_Winter_Testing_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(VDC_Winter_Testing_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(VDC_Winter_Testing_M->rtwLogInfo, 0);
    rtliSetLogDecimation(VDC_Winter_Testing_M->rtwLogInfo, 1);
    rtliSetLogY(VDC_Winter_Testing_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(VDC_Winter_Testing_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(VDC_Winter_Testing_M->rtwLogInfo, (NULL));
  }

  VDC_Winter_Testing_M->solverInfoPtr = (&VDC_Winter_Testing_M->solverInfo);
  VDC_Winter_Testing_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&VDC_Winter_Testing_M->solverInfo, 0.2);
  rtsiSetSolverMode(&VDC_Winter_Testing_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* states (dwork) */
  VDC_Winter_Testing_M->dwork = ((void *) &VDC_Winter_Testing_DW);
  (void) memset((void *)&VDC_Winter_Testing_DW, 0,
                sizeof(DW_VDC_Winter_Testing_T));

  /* external inputs */
  VDC_Winter_Testing_M->inputs = (((void*)&VDC_Winter_Testing_U));
  (void)memset(&VDC_Winter_Testing_U, 0, sizeof(ExtU_VDC_Winter_Testing_T));

  /* external outputs */
  VDC_Winter_Testing_M->outputs = (&VDC_Winter_Testing_Y);
  (void)memset(&VDC_Winter_Testing_Y, 0, sizeof(ExtY_VDC_Winter_Testing_T));

  /* Initialize Sizes */
  VDC_Winter_Testing_M->Sizes.numContStates = (0);/* Number of continuous states */
  VDC_Winter_Testing_M->Sizes.numY = (6);/* Number of model outputs */
  VDC_Winter_Testing_M->Sizes.numU = (29);/* Number of model inputs */
  VDC_Winter_Testing_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  VDC_Winter_Testing_M->Sizes.numSampTimes = (1);/* Number of sample times */
  VDC_Winter_Testing_M->Sizes.numBlocks = (67);/* Number of blocks */
  VDC_Winter_Testing_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  return VDC_Winter_Testing_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
