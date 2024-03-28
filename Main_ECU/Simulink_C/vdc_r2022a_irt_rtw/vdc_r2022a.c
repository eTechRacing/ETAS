/*
 * vdc_r2022a.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "vdc_r2022a".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Thu Mar 28 16:26:59 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "vdc_r2022a.h"
#include "rtwtypes.h"
#include "vdc_r2022a_private.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_vdc_r2022a_T vdc_r2022a_B;

/* Block states (default storage) */
DW_vdc_r2022a_T vdc_r2022a_DW;

/* External inputs (root inport signals with default storage) */
ExtU_vdc_r2022a_T vdc_r2022a_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_vdc_r2022a_T vdc_r2022a_Y;

/* Real-time model */
static RT_MODEL_vdc_r2022a_T vdc_r2022a_M_;
RT_MODEL_vdc_r2022a_T *const vdc_r2022a_M = &vdc_r2022a_M_;

/*
 * Output and update for action system:
 *    '<S11>/LimitReached'
 *    '<S14>/Latched Error'
 */
void vdc_r2022a_LimitReached(real_T *rty_Out)
{
  /* SignalConversion generated from: '<S13>/Out ' incorporates:
   *  Constant: '<S13>/Constant'
   */
  *rty_Out = 1.0;
}

/*
 * Output and update for action system:
 *    '<Root>/Automatic Failure Mode'
 *    '<Root>/Manual Failure Mode Selection'
 */
void vdc_r2022a_AutomaticFailureMode(real_T rtu_In1, real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S2>/In1' */
  *rty_Out1 = rtu_In1;
}

/* Model output function */
static void vdc_r2022a_output(void)
{
  real_T Throttle_Response;
  real_T rtb_Abs1;
  real_T rtb_Merge1_c;
  real_T rtb_Merge_j;
  real_T rtb_Product;
  boolean_T rtb_LogicalOperator;

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/Accumulator_Current'
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  rtb_Product = vdc_r2022a_U.Accumulator_Voltage *
    vdc_r2022a_U.Accumulator_Current;

  /* Outport: '<Root>/Power' incorporates:
   *  Constant: '<S12>/0-100 to 0-2'
   *  Product: '<S12>/Divide5'
   */
  vdc_r2022a_Y.Power = rtb_Product / 1000.0;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* If: '<S11>/If' incorporates:
   *  DataStoreRead: '<S11>/Data Store Read30'
   *  If: '<S14>/If'
   *  SignalConversion generated from: '<S11>/Power'
   */
  if (rtb_Product >= 80000.0) {
    /* Outputs for IfAction SubSystem: '<S11>/LimitReached' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    vdc_r2022a_LimitReached(&rtb_Merge1_c);

    /* End of Outputs for SubSystem: '<S11>/LimitReached' */

    /* Outputs for IfAction SubSystem: '<S11>/OK_OrLatch' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
  } else if (vdc_r2022a_DW.A > 0.0) {
    /* Outputs for IfAction SubSystem: '<S14>/Latched Error' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* If: '<S14>/If' */
    vdc_r2022a_LimitReached(&rtb_Merge1_c);

    /* End of Outputs for SubSystem: '<S14>/Latched Error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S14>/OK' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* If: '<S14>/If' incorporates:
     *  Constant: '<S16>/Constant'
     *  SignalConversion generated from: '<S16>/Out '
     */
    rtb_Merge1_c = 0.0;

    /* End of Outputs for SubSystem: '<S14>/OK' */

    /* End of Outputs for SubSystem: '<S11>/OK_OrLatch' */
  }

  /* End of If: '<S11>/If' */

  /* DataStoreWrite: '<S11>/Data Store Write20' */
  vdc_r2022a_DW.A = rtb_Merge1_c;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* Outport: '<Root>/PowerLimitReached' */
  vdc_r2022a_Y.PowerLimitReached = rtb_Merge1_c;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Outport: '<Root>/PowerMean500ms' incorporates:
   *  SignalConversion generated from: '<S11>/Power'
   */
  vdc_r2022a_Y.PowerMean500ms = rtb_Product;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* If: '<S18>/If' incorporates:
   *  Abs: '<S18>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S18>/Sum'
   */
  if (fabs(vdc_r2022a_U.APPS1_Value - vdc_r2022a_U.APPS2_Value) > 0.1) {
    /* Outputs for IfAction SubSystem: '<S18>/Imp' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S21>/Constant'
     *  DataStoreRead: '<S21>/Data Store Read'
     */
    rtb_Product = vdc_r2022a_DW.ERROR_Counter + 1.0;

    /* End of Outputs for SubSystem: '<S18>/Imp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/Not Imp' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* SignalConversion generated from: '<S22>/0' incorporates:
     *  Constant: '<S22>/Constant'
     */
    rtb_Product = 0.0;

    /* End of Outputs for SubSystem: '<S18>/Not Imp' */
  }

  /* End of If: '<S18>/If' */

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S19>/Constant'
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/NOT'
   *  RelationalOperator: '<S19>/Compare'
   */
  rtb_LogicalOperator = (vdc_r2022a_U.Shutdown_PackageIntck &&
    vdc_r2022a_U.TorqueEnable && (!vdc_r2022a_U.CriticalDisconnection) &&
    (vdc_r2022a_U.Car_State == 15.0) && (!(rtb_Product != 0.0)));

  /* If: '<Root>/If' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Inport: '<Root>/TV_Mode'
   */
  if (rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/Automatic Failure Mode' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    vdc_r2022a_AutomaticFailureMode(vdc_r2022a_U.TV_Mode, &rtb_Merge_j);

    /* End of Outputs for SubSystem: '<Root>/Automatic Failure Mode' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/Manual Failure Mode Selection' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    vdc_r2022a_AutomaticFailureMode(5.0, &rtb_Merge_j);

    /* End of Outputs for SubSystem: '<Root>/Manual Failure Mode Selection' */
  }

  /* End of If: '<Root>/If' */

  /* Abs: '<Root>/Abs' incorporates:
   *  Inport: '<Root>/RR_Vel_ms_Wheel'
   */
  rtb_Merge1_c = fabs(vdc_r2022a_U.RR_Vel_ms_Wheel);

  /* Abs: '<Root>/Abs1' incorporates:
   *  Inport: '<Root>/RL_Vel_ms_Wheel'
   */
  rtb_Abs1 = fabs(vdc_r2022a_U.RL_Vel_ms_Wheel);

  /* MATLAB Function: '<Root>/Torque demanded by the driver' incorporates:
   *  Constant: '<Root>/AP_sat_down'
   *  Constant: '<Root>/AP_sat_up'
   *  Constant: '<Root>/Max_Motor_Torque_Rear_FM4 [Nm]'
   *  Inport: '<Root>/APPS1_Value'
   */
  Throttle_Response = 0.0;
  if (!(vdc_r2022a_U.APPS1_Value <= 0.0)) {
    if (vdc_r2022a_U.APPS1_Value >= 1.0) {
      Throttle_Response = 1.0;
    } else if ((vdc_r2022a_U.APPS1_Value >= 0.0) && (vdc_r2022a_U.APPS1_Value <=
                1.0)) {
      Throttle_Response = vdc_r2022a_U.APPS1_Value;
    }
  }

  Throttle_Response *= 27.0;

  /* End of MATLAB Function: '<Root>/Torque demanded by the driver' */

  /* If: '<Root>/FAILURE MODE' */
  if ((!(rtb_Merge_j == 1.0)) && (!(rtb_Merge_j == 2.0))) {
    if (rtb_Merge_j == 3.0) {
      real_T rtb_Merge_n_tmp;

      /* Outputs for IfAction SubSystem: '<Root>/TC+TV' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [º]'
       *  Constant: '<Root>/Steering_wheel_sat [º]'
       *  Inport: '<Root>/SteeringSensor_Value'
       */
      rtb_Merge_n_tmp = fabs(vdc_r2022a_U.SteeringSensor_Value);
      if (rtb_Merge_n_tmp <= 10.0) {
        rtb_Merge_j = Throttle_Response;
      } else if (vdc_r2022a_U.SteeringSensor_Value < -10.0) {
        rtb_Merge_j = Throttle_Response - (rtb_Merge_n_tmp - 10.0) / 115.0 *
          Throttle_Response;
      } else {
        rtb_Merge_j = Throttle_Response;
        Throttle_Response -= (rtb_Merge_n_tmp - 10.0) / 115.0 *
          Throttle_Response;
      }

      /* End of MATLAB Function: '<S7>/MATLAB Function' */

      /* MATLAB Function: '<S7>/Rigid Axle with TC 2024 ' incorporates:
       *  Inport: '<Root>/VDC_Max_tire_slip'
       *  Inport: '<Root>/el_Vel_X'
       */
      if (fmax(rtb_Merge1_c / vdc_r2022a_U.el_Vel_X, rtb_Abs1 /
               vdc_r2022a_U.el_Vel_X) < vdc_r2022a_U.VDC_Max_tire_slip) {
        /* Merge: '<Root>/Merge1' */
        vdc_r2022a_B.Merge1 = Throttle_Response;

        /* Merge: '<Root>/Merge2' */
        vdc_r2022a_B.Merge2 = rtb_Merge_j;
        vdc_r2022a_DW.correction_c = 0.0;

        /* Merge: '<Root>/Merge3' */
        vdc_r2022a_B.Merge3 = false;
      } else {
        /* Merge: '<Root>/Merge3' */
        vdc_r2022a_B.Merge3 = true;
        if (vdc_r2022a_DW.correction_c == 0.0) {
          vdc_r2022a_DW.correction_c = 1.0;

          /* Merge: '<Root>/Merge1' */
          vdc_r2022a_B.Merge1 = Throttle_Response - 1.0;

          /* Merge: '<Root>/Merge2' */
          vdc_r2022a_B.Merge2 = rtb_Merge_j - 1.0;
        } else {
          vdc_r2022a_DW.correction_c++;

          /* Merge: '<Root>/Merge1' */
          vdc_r2022a_B.Merge1 = Throttle_Response - vdc_r2022a_DW.correction_c;

          /* Merge: '<Root>/Merge2' */
          vdc_r2022a_B.Merge2 = rtb_Merge_j - vdc_r2022a_DW.correction_c;
        }
      }

      /* End of MATLAB Function: '<S7>/Rigid Axle with TC 2024 ' */
      /* End of Outputs for SubSystem: '<Root>/TC+TV' */
    } else if (rtb_Merge_j == 4.0) {
      /* Outputs for IfAction SubSystem: '<Root>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* MATLAB Function: '<S5>/Rigid Axle with TC 2024 ' incorporates:
       *  Inport: '<Root>/VDC_Max_tire_slip'
       *  Inport: '<Root>/el_Vel_X'
       *  MinMax: '<S5>/Max'
       */
      if (fmax(rtb_Merge1_c, rtb_Abs1) / vdc_r2022a_U.el_Vel_X <
          vdc_r2022a_U.VDC_Max_tire_slip) {
        /* Merge: '<Root>/Merge1' */
        vdc_r2022a_B.Merge1 = Throttle_Response;

        /* Merge: '<Root>/Merge2' */
        vdc_r2022a_B.Merge2 = Throttle_Response;
        vdc_r2022a_DW.correction = 0.0;

        /* Merge: '<Root>/Merge3' */
        vdc_r2022a_B.Merge3 = false;
      } else {
        /* Merge: '<Root>/Merge3' */
        vdc_r2022a_B.Merge3 = true;
        if (vdc_r2022a_DW.correction == 0.0) {
          vdc_r2022a_DW.correction = 1.0;

          /* Merge: '<Root>/Merge1' */
          vdc_r2022a_B.Merge1 = Throttle_Response - 1.0;

          /* Merge: '<Root>/Merge2' */
          vdc_r2022a_B.Merge2 = Throttle_Response - 1.0;
        } else {
          vdc_r2022a_DW.correction++;

          /* Merge: '<Root>/Merge1' */
          vdc_r2022a_B.Merge1 = Throttle_Response - vdc_r2022a_DW.correction;

          /* Merge: '<Root>/Merge2' */
          vdc_r2022a_B.Merge2 = Throttle_Response - vdc_r2022a_DW.correction;
        }
      }

      /* End of MATLAB Function: '<S5>/Rigid Axle with TC 2024 ' */
      /* End of Outputs for SubSystem: '<Root>/RIGIDAXLE' */
    }
  }

  /* End of If: '<Root>/FAILURE MODE' */

  /* Outputs for Atomic SubSystem: '<Root>/WORKSHOP_MODE_RESTRICTIONS' */
  /* If: '<S10>/If' incorporates:
   *  Inport: '<Root>/Workshop_Mode_Enable'
   */
  if (vdc_r2022a_U.Workshop_Mode_Enable == 1.0) {
    /* Outputs for IfAction SubSystem: '<S10>/Torque_Reduction ' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* Product: '<S28>/Divide' incorporates:
     *  Constant: '<S28>/Constant'
     */
    rtb_Merge_j = vdc_r2022a_B.Merge1 / 15.0;

    /* Saturate: '<S28>/Saturation' */
    if (rtb_Merge_j > 10.0) {
      rtb_Merge_j = 10.0;
    } else if (rtb_Merge_j < -10.0) {
      rtb_Merge_j = -10.0;
    }

    /* End of Saturate: '<S28>/Saturation' */

    /* Product: '<S28>/Divide1' incorporates:
     *  Constant: '<S28>/Constant'
     */
    rtb_Merge1_c = vdc_r2022a_B.Merge2 / 15.0;

    /* Saturate: '<S28>/Saturation1' */
    if (rtb_Merge1_c > 10.0) {
      rtb_Merge1_c = 10.0;
    } else if (rtb_Merge1_c < -10.0) {
      rtb_Merge1_c = -10.0;
    }

    /* End of Saturate: '<S28>/Saturation1' */
    /* End of Outputs for SubSystem: '<S10>/Torque_Reduction ' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/BYPASS' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* SignalConversion generated from: '<S27>/In1' */
    rtb_Merge_j = vdc_r2022a_B.Merge1;

    /* SignalConversion generated from: '<S27>/In2' */
    rtb_Merge1_c = vdc_r2022a_B.Merge2;

    /* End of Outputs for SubSystem: '<S10>/BYPASS' */
  }

  /* End of If: '<S10>/If' */

  /* Saturate: '<S10>/Saturation' */
  if (rtb_Merge_j > 580.0) {
    /* Outport: '<Root>/Torque_R_out' */
    vdc_r2022a_Y.Torque_R_out = 580.0;
  } else if (rtb_Merge_j < -580.0) {
    /* Outport: '<Root>/Torque_R_out' */
    vdc_r2022a_Y.Torque_R_out = -580.0;
  } else {
    /* Outport: '<Root>/Torque_R_out' */
    vdc_r2022a_Y.Torque_R_out = rtb_Merge_j;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Saturate: '<S10>/Saturation1' */
  if (rtb_Merge1_c > 580.0) {
    /* Outport: '<Root>/Torque_L_out' */
    vdc_r2022a_Y.Torque_L_out = 580.0;
  } else if (rtb_Merge1_c < -580.0) {
    /* Outport: '<Root>/Torque_L_out' */
    vdc_r2022a_Y.Torque_L_out = -580.0;
  } else {
    /* Outport: '<Root>/Torque_L_out' */
    vdc_r2022a_Y.Torque_L_out = rtb_Merge1_c;
  }

  /* End of Saturate: '<S10>/Saturation1' */
  /* End of Outputs for SubSystem: '<Root>/WORKSHOP_MODE_RESTRICTIONS' */

  /* Outport: '<Root>/TC_WARNING' */
  vdc_r2022a_Y.TC_WARNING = vdc_r2022a_B.Merge3;

  /* Outport: '<Root>/APPS_Implausibility' */
  vdc_r2022a_Y.APPS_Implausibility = rtb_Product;

  /* Outport: '<Root>/Torque_OK' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  vdc_r2022a_Y.Torque_OK = rtb_LogicalOperator;
}

/* Model update function */
static void vdc_r2022a_update(void)
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
  if (!(++vdc_r2022a_M->Timing.clockTick0)) {
    ++vdc_r2022a_M->Timing.clockTickH0;
  }

  vdc_r2022a_M->Timing.t[0] = vdc_r2022a_M->Timing.clockTick0 *
    vdc_r2022a_M->Timing.stepSize0 + vdc_r2022a_M->Timing.clockTickH0 *
    vdc_r2022a_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void vdc_r2022a_initialize(void)
{
  /* Start for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Start for DataStoreMemory: '<S11>/Data Store Memory10' */
  vdc_r2022a_DW.A = 0.0;

  /* End of Start for SubSystem: '<S1>/PowerLimitDetection' */

  /* Start for DataStoreMemory: '<S18>/Data Store Memory1' */
  vdc_r2022a_DW.ERROR_Counter = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S7>/Rigid Axle with TC 2024 ' */
  vdc_r2022a_DW.correction_c = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/TC+TV' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/RIGIDAXLE' */
  /* SystemInitialize for MATLAB Function: '<S5>/Rigid Axle with TC 2024 ' */
  vdc_r2022a_DW.correction = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/RIGIDAXLE' */

  /* SystemInitialize for Merge: '<Root>/Merge1' */
  vdc_r2022a_B.Merge1 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge2' */
  vdc_r2022a_B.Merge2 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge3' */
  vdc_r2022a_B.Merge3 = false;
}

/* Model terminate function */
static void vdc_r2022a_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  vdc_r2022a_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  vdc_r2022a_update();
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
  vdc_r2022a_initialize();
}

void MdlTerminate(void)
{
  vdc_r2022a_terminate();
}

/* Registration function */
RT_MODEL_vdc_r2022a_T *vdc_r2022a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)vdc_r2022a_M, 0,
                sizeof(RT_MODEL_vdc_r2022a_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = vdc_r2022a_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "vdc_r2022a_M points to
       static memory which is guaranteed to be non-NULL" */
    vdc_r2022a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    vdc_r2022a_M->Timing.sampleTimes = (&vdc_r2022a_M->Timing.sampleTimesArray[0]);
    vdc_r2022a_M->Timing.offsetTimes = (&vdc_r2022a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    vdc_r2022a_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    vdc_r2022a_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(vdc_r2022a_M, &vdc_r2022a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = vdc_r2022a_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    vdc_r2022a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(vdc_r2022a_M, 10.0);
  vdc_r2022a_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    vdc_r2022a_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(vdc_r2022a_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(vdc_r2022a_M->rtwLogInfo, (NULL));
    rtliSetLogT(vdc_r2022a_M->rtwLogInfo, "tout");
    rtliSetLogX(vdc_r2022a_M->rtwLogInfo, "");
    rtliSetLogXFinal(vdc_r2022a_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(vdc_r2022a_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(vdc_r2022a_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(vdc_r2022a_M->rtwLogInfo, 0);
    rtliSetLogDecimation(vdc_r2022a_M->rtwLogInfo, 1);
    rtliSetLogY(vdc_r2022a_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(vdc_r2022a_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(vdc_r2022a_M->rtwLogInfo, (NULL));
  }

  vdc_r2022a_M->solverInfoPtr = (&vdc_r2022a_M->solverInfo);
  vdc_r2022a_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&vdc_r2022a_M->solverInfo, 0.2);
  rtsiSetSolverMode(&vdc_r2022a_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  vdc_r2022a_M->blockIO = ((void *) &vdc_r2022a_B);
  (void) memset(((void *) &vdc_r2022a_B), 0,
                sizeof(B_vdc_r2022a_T));

  /* states (dwork) */
  vdc_r2022a_M->dwork = ((void *) &vdc_r2022a_DW);
  (void) memset((void *)&vdc_r2022a_DW, 0,
                sizeof(DW_vdc_r2022a_T));

  /* external inputs */
  vdc_r2022a_M->inputs = (((void*)&vdc_r2022a_U));
  (void)memset(&vdc_r2022a_U, 0, sizeof(ExtU_vdc_r2022a_T));

  /* external outputs */
  vdc_r2022a_M->outputs = (&vdc_r2022a_Y);
  (void)memset(&vdc_r2022a_Y, 0, sizeof(ExtY_vdc_r2022a_T));

  /* Initialize Sizes */
  vdc_r2022a_M->Sizes.numContStates = (0);/* Number of continuous states */
  vdc_r2022a_M->Sizes.numY = (8);      /* Number of model outputs */
  vdc_r2022a_M->Sizes.numU = (33);     /* Number of model inputs */
  vdc_r2022a_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  vdc_r2022a_M->Sizes.numSampTimes = (1);/* Number of sample times */
  vdc_r2022a_M->Sizes.numBlocks = (118);/* Number of blocks */
  vdc_r2022a_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  return vdc_r2022a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
