/*
 * VDC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VDC".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Sat Apr  6 01:20:50 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VDC.h"
#include "rtwtypes.h"
#include "VDC_private.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_VDC_T VDC_B;

/* Block states (default storage) */
DW_VDC_T VDC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_VDC_T VDC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_VDC_T VDC_Y;

/* Real-time model */
static RT_MODEL_VDC_T VDC_M_;
RT_MODEL_VDC_T *const VDC_M = &VDC_M_;

/*
 * Output and update for action system:
 *    '<S12>/LimitReached'
 *    '<S15>/Latched Error'
 */
void VDC_LimitReached(real_T *rty_Out)
{
  /* SignalConversion generated from: '<S14>/Out ' incorporates:
   *  Constant: '<S14>/Constant'
   */
  *rty_Out = 1.0;
}

/*
 * Output and update for action system:
 *    '<Root>/Automatic Failure Mode'
 *    '<Root>/Manual Failure Mode Selection'
 */
void VDC_AutomaticFailureMode(real_T rtu_In1, real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S2>/In1' */
  *rty_Out1 = rtu_In1;
}

/* Model output function */
static void VDC_output(void)
{
  real_T rtb_Abs;
  real_T rtb_Abs1;
  real_T rtb_Merge1_e;
  real_T rtb_Merge1_j;
  real_T rtb_Merge_j;
  real_T rtb_Product;
  boolean_T rtb_LogicalOperator;

  /* If: '<S20>/If' incorporates:
   *  Abs: '<S20>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S20>/Sum'
   */
  if (fabs(VDC_U.APPS1_Value - VDC_U.APPS2_Value) > 0.1) {
    /* Outputs for IfAction SubSystem: '<S20>/Imp' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Sum: '<S23>/Add' incorporates:
     *  Constant: '<S23>/Constant'
     *  DataStoreRead: '<S23>/Data Store Read'
     */
    rtb_Merge1_j = VDC_DW.ERROR_Counter + 1.0;

    /* End of Outputs for SubSystem: '<S20>/Imp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S20>/Not Imp' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* SignalConversion generated from: '<S24>/0' incorporates:
     *  Constant: '<S24>/Constant'
     */
    rtb_Merge1_j = 0.0;

    /* End of Outputs for SubSystem: '<S20>/Not Imp' */
  }

  /* End of If: '<S20>/If' */

  /* DataStoreWrite: '<S20>/Data Store Write' */
  VDC_DW.ERROR_Counter = rtb_Merge1_j;

  /* Outputs for IfAction SubSystem: '<S20>/Signal_OK' incorporates:
   *  ActionPort: '<S26>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S20>/Signal_Failure' incorporates:
   *  ActionPort: '<S25>/Action Port'
   */
  /* If: '<S20>/If1' incorporates:
   *  Constant: '<S20>/Number_of_Periods'
   *  SignalConversion generated from: '<S25>/Out1'
   *  SignalConversion generated from: '<S26>/Out1'
   */
  rtb_Merge1_j = (rtb_Merge1_j > 4.0);

  /* End of Outputs for SubSystem: '<S20>/Signal_Failure' */
  /* End of Outputs for SubSystem: '<S20>/Signal_OK' */

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S7>/Logical Operator1'
   *  Logic: '<S7>/NOT'
   *  RelationalOperator: '<S21>/Compare'
   */
  rtb_LogicalOperator = (VDC_U.Shutdown_PackageIntck && VDC_U.TorqueEnable &&
    (!VDC_U.CriticalDisconnection) && (VDC_U.Car_State == 15.0) &&
    (!(rtb_Merge1_j != 0.0)));

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/Accumulator_Current'
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  rtb_Product = VDC_U.Accumulator_Voltage * VDC_U.Accumulator_Current;

  /* Outport: '<Root>/Power' incorporates:
   *  Constant: '<S13>/0-100 to 0-2'
   *  Product: '<S13>/Divide5'
   */
  VDC_Y.Power = rtb_Product / 1000.0;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* If: '<S12>/If' incorporates:
   *  DataStoreRead: '<S12>/Data Store Read30'
   *  If: '<S15>/If'
   *  SignalConversion generated from: '<S12>/Power'
   */
  if (rtb_Product >= 80000.0) {
    /* Outputs for IfAction SubSystem: '<S12>/LimitReached' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    VDC_LimitReached(&rtb_Merge1_e);

    /* End of Outputs for SubSystem: '<S12>/LimitReached' */

    /* Outputs for IfAction SubSystem: '<S12>/OK_OrLatch' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
  } else if (VDC_DW.A > 0.0) {
    /* Outputs for IfAction SubSystem: '<S15>/Latched Error' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* If: '<S15>/If' */
    VDC_LimitReached(&rtb_Merge1_e);

    /* End of Outputs for SubSystem: '<S15>/Latched Error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S15>/OK' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* If: '<S15>/If' incorporates:
     *  Constant: '<S17>/Constant'
     *  SignalConversion generated from: '<S17>/Out '
     */
    rtb_Merge1_e = 0.0;

    /* End of Outputs for SubSystem: '<S15>/OK' */

    /* End of Outputs for SubSystem: '<S12>/OK_OrLatch' */
  }

  /* End of If: '<S12>/If' */

  /* DataStoreWrite: '<S12>/Data Store Write20' */
  VDC_DW.A = rtb_Merge1_e;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* Outport: '<Root>/PowerLimitReached' */
  VDC_Y.PowerLimitReached = rtb_Merge1_e;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Outport: '<Root>/PowerMean500ms' incorporates:
   *  SignalConversion generated from: '<S12>/Power'
   */
  VDC_Y.PowerMean500ms = rtb_Product;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* If: '<Root>/If' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Inport: '<Root>/TV_Mode'
   */
  if (rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/Automatic Failure Mode' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    VDC_AutomaticFailureMode(VDC_U.TV_Mode, &rtb_Merge_j);

    /* End of Outputs for SubSystem: '<Root>/Automatic Failure Mode' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/Manual Failure Mode Selection' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    VDC_AutomaticFailureMode(6.0, &rtb_Merge_j);

    /* End of Outputs for SubSystem: '<Root>/Manual Failure Mode Selection' */
  }

  /* End of If: '<Root>/If' */

  /* Abs: '<Root>/Abs' incorporates:
   *  Inport: '<Root>/RR_Vel_ms_Wheel'
   */
  rtb_Abs = fabs(VDC_U.RR_Vel_ms_Wheel);

  /* Abs: '<Root>/Abs1' incorporates:
   *  Inport: '<Root>/RL_Vel_ms_Wheel'
   */
  rtb_Abs1 = fabs(VDC_U.RL_Vel_ms_Wheel);

  /* MATLAB Function: '<Root>/Torque demanded by the driver' incorporates:
   *  Constant: '<Root>/AP_sat_down'
   *  Constant: '<Root>/AP_sat_up'
   *  Constant: '<Root>/Max_Motor_Torque_Rear_FM4 [Nm]'
   *  Inport: '<Root>/APPS1_Value'
   */
  rtb_Product = 0.0;
  if (!(VDC_U.APPS1_Value <= 0.0)) {
    if (VDC_U.APPS1_Value >= 1.0) {
      rtb_Product = 1.0;
    } else if ((VDC_U.APPS1_Value >= 0.0) && (VDC_U.APPS1_Value <= 1.0)) {
      rtb_Product = VDC_U.APPS1_Value;
    }
  }

  rtb_Product *= 27.0;

  /* End of MATLAB Function: '<Root>/Torque demanded by the driver' */

  /* MATLAB Function: '<Root>/Enable regen?' incorporates:
   *  Inport: '<Root>/el_Vel_X'
   */
  if ((rtb_Abs < 0.55) || (rtb_Abs1 < 0.55)) {
    rtb_Merge1_e = 0.0;
  } else {
    rtb_Merge1_e = !(VDC_U.el_Vel_X >= 8.0);
  }

  /* End of MATLAB Function: '<Root>/Enable regen?' */

  /* If: '<Root>/FAILURE MODE' */
  if ((!(rtb_Merge_j == 1.0)) && (!(rtb_Merge_j == 2.0))) {
    if (rtb_Merge_j == 3.0) {
      real_T d;

      /* Outputs for IfAction SubSystem: '<Root>/TC+TV' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [º]'
       *  Constant: '<Root>/Steering_wheel_sat [º]'
       *  Inport: '<Root>/SteeringSensor_Value'
       *  Inport: '<Root>/el_SlipAngle'
       */
      rtb_Merge_j = fabs(VDC_U.SteeringSensor_Value);
      if (rtb_Merge_j <= 10.0) {
        rtb_Merge_j = rtb_Product;
        d = rtb_Product;
      } else if (fabs(VDC_U.el_SlipAngle) > 6.0) {
        rtb_Merge_j = rtb_Product;
        d = rtb_Product;
      } else {
        d = (rtb_Merge_j - 10.0) / 115.0 * rtb_Product;
        if ((rtb_Merge1_e == 0.0) && (d > rtb_Product)) {
          d = rtb_Product;
        }

        if (VDC_U.SteeringSensor_Value < -10.0) {
          rtb_Merge_j = rtb_Product - d;
          d = rtb_Product;
        } else {
          rtb_Merge_j = rtb_Product;
          d = rtb_Product - d;
        }
      }

      /* End of MATLAB Function: '<S8>/MATLAB Function' */

      /* MATLAB Function: '<S8>/Rigid Axle with TC 2024 ' incorporates:
       *  Inport: '<Root>/VDC_Max_Tyre_Slip'
       *  Inport: '<Root>/el_Vel_X'
       */
      if ((VDC_U.el_Vel_X == 0.0) || (rtb_Abs == 0.0)) {
        rtb_Abs = 1.0;
      } else {
        rtb_Abs /= VDC_U.el_Vel_X;
      }

      if ((VDC_U.el_Vel_X == 0.0) || (rtb_Abs1 == 0.0)) {
        rtb_Abs1 = 1.0;
      } else {
        rtb_Abs1 /= VDC_U.el_Vel_X;
      }

      if (fmax(rtb_Abs, rtb_Abs1) < VDC_U.VDC_Max_Tyre_Slip) {
        /* Merge: '<Root>/Merge1' */
        VDC_B.Merge1 = d;

        /* Merge: '<Root>/Merge2' */
        VDC_B.Merge2 = rtb_Merge_j;
        VDC_DW.correction_k = 0.0;

        /* Merge: '<Root>/Merge3' */
        VDC_B.Merge3 = false;
      } else {
        /* Merge: '<Root>/Merge3' */
        VDC_B.Merge3 = true;
        if (VDC_DW.correction_k == 0.0) {
          VDC_DW.correction_k = 1.0;

          /* Merge: '<Root>/Merge1' */
          VDC_B.Merge1 = d - 0.060606060606060608;

          /* Merge: '<Root>/Merge2' */
          VDC_B.Merge2 = rtb_Merge_j - 0.060606060606060608;
        } else {
          VDC_DW.correction_k++;
          rtb_Abs = VDC_DW.correction_k * VDC_DW.correction_k *
            0.030303030303030304 + 0.030303030303030304 * VDC_DW.correction_k;

          /* Merge: '<Root>/Merge1' */
          VDC_B.Merge1 = d - rtb_Abs;

          /* Merge: '<Root>/Merge2' */
          VDC_B.Merge2 = rtb_Merge_j - rtb_Abs;
        }
      }

      /* End of MATLAB Function: '<S8>/Rigid Axle with TC 2024 ' */
      /* End of Outputs for SubSystem: '<Root>/TC+TV' */
    } else if (rtb_Merge_j == 4.0) {
      /* Outputs for IfAction SubSystem: '<Root>/RIGIDAXLE WITH TC' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* MinMax: '<S6>/Max' */
      rtb_Abs1 = fmax(rtb_Abs, rtb_Abs1);

      /* MATLAB Function: '<S6>/Rigid Axle with TC 2024 ' incorporates:
       *  Inport: '<Root>/VDC_Max_Tyre_Slip'
       *  Inport: '<Root>/el_Vel_X'
       */
      if ((VDC_U.el_Vel_X == 0.0) || (rtb_Abs1 == 0.0)) {
        rtb_Abs1 = 1.0;
      } else {
        rtb_Abs1 /= VDC_U.el_Vel_X;
      }

      if (rtb_Abs1 < VDC_U.VDC_Max_Tyre_Slip) {
        /* Merge: '<Root>/Merge1' */
        VDC_B.Merge1 = rtb_Product;

        /* Merge: '<Root>/Merge2' */
        VDC_B.Merge2 = rtb_Product;
        VDC_DW.correction = 0.0;

        /* Merge: '<Root>/Merge3' */
        VDC_B.Merge3 = false;
      } else {
        /* Merge: '<Root>/Merge3' */
        VDC_B.Merge3 = true;
        if (VDC_DW.correction == 0.0) {
          VDC_DW.correction = 1.0;

          /* Merge: '<Root>/Merge1' */
          VDC_B.Merge1 = rtb_Product - 0.060606060606060608;

          /* Merge: '<Root>/Merge2' */
          VDC_B.Merge2 = rtb_Product - 0.060606060606060608;
        } else {
          VDC_DW.correction++;
          rtb_Abs = rtb_Product - (VDC_DW.correction * VDC_DW.correction *
            0.030303030303030304 + 0.030303030303030304 * VDC_DW.correction);

          /* Merge: '<Root>/Merge1' */
          VDC_B.Merge1 = rtb_Abs;

          /* Merge: '<Root>/Merge2' */
          VDC_B.Merge2 = rtb_Abs;
        }
      }

      /* End of MATLAB Function: '<S6>/Rigid Axle with TC 2024 ' */
      /* End of Outputs for SubSystem: '<Root>/RIGIDAXLE WITH TC' */
    } else if (rtb_Merge_j == 5.0) {
      /* Outputs for IfAction SubSystem: '<Root>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* Merge: '<Root>/Merge2' incorporates:
       *  MATLAB Function: '<S5>/Rigid Axle 2024 '
       *  SignalConversion generated from: '<S5>/Tq_RL_FM5 [Nm] (0,inf)'
       */
      VDC_B.Merge2 = rtb_Product;

      /* Merge: '<Root>/Merge1' incorporates:
       *  MATLAB Function: '<S5>/Rigid Axle 2024 '
       *  SignalConversion generated from: '<S5>/Tq_RR_FM5 [Nm] (0,inf)'
       */
      VDC_B.Merge1 = rtb_Product;

      /* Merge: '<Root>/Merge3' incorporates:
       *  MATLAB Function: '<S5>/Rigid Axle 2024 '
       *  SignalConversion generated from: '<S5>/warning'
       */
      VDC_B.Merge3 = false;

      /* End of Outputs for SubSystem: '<Root>/RIGIDAXLE' */
    }
  }

  /* End of If: '<Root>/FAILURE MODE' */

  /* Outputs for Atomic SubSystem: '<Root>/WORKSHOP_MODE_RESTRICTIONS' */
  /* If: '<S11>/If' incorporates:
   *  Inport: '<Root>/Workshop_Mode_Enable'
   */
  if (VDC_U.Workshop_Mode_Enable == 1.0) {
    /* Outputs for IfAction SubSystem: '<S11>/Torque_Reduction ' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Product: '<S32>/Divide' incorporates:
     *  Constant: '<S32>/Constant'
     */
    rtb_Merge_j = VDC_B.Merge1 / 15.0;

    /* Saturate: '<S32>/Saturation' */
    if (rtb_Merge_j > 10.0) {
      rtb_Merge_j = 10.0;
    } else if (rtb_Merge_j < -10.0) {
      rtb_Merge_j = -10.0;
    }

    /* End of Saturate: '<S32>/Saturation' */

    /* Product: '<S32>/Divide1' incorporates:
     *  Constant: '<S32>/Constant'
     */
    rtb_Abs1 = VDC_B.Merge2 / 15.0;

    /* Saturate: '<S32>/Saturation1' */
    if (rtb_Abs1 > 10.0) {
      rtb_Abs1 = 10.0;
    } else if (rtb_Abs1 < -10.0) {
      rtb_Abs1 = -10.0;
    }

    /* End of Saturate: '<S32>/Saturation1' */
    /* End of Outputs for SubSystem: '<S11>/Torque_Reduction ' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/BYPASS' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* SignalConversion generated from: '<S31>/In1' */
    rtb_Merge_j = VDC_B.Merge1;

    /* SignalConversion generated from: '<S31>/In2' */
    rtb_Abs1 = VDC_B.Merge2;

    /* End of Outputs for SubSystem: '<S11>/BYPASS' */
  }

  /* End of If: '<S11>/If' */

  /* Saturate: '<S11>/Saturation' */
  if (rtb_Merge_j > 27.0) {
    /* Outport: '<Root>/Torque_R_out' */
    VDC_Y.Torque_R_out = 27.0;
  } else if (rtb_Merge_j < -27.0) {
    /* Outport: '<Root>/Torque_R_out' */
    VDC_Y.Torque_R_out = -27.0;
  } else {
    /* Outport: '<Root>/Torque_R_out' */
    VDC_Y.Torque_R_out = rtb_Merge_j;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Saturate: '<S11>/Saturation1' */
  if (rtb_Abs1 > 27.0) {
    /* Outport: '<Root>/Torque_L_out' */
    VDC_Y.Torque_L_out = 27.0;
  } else if (rtb_Abs1 < -27.0) {
    /* Outport: '<Root>/Torque_L_out' */
    VDC_Y.Torque_L_out = -27.0;
  } else {
    /* Outport: '<Root>/Torque_L_out' */
    VDC_Y.Torque_L_out = rtb_Abs1;
  }

  /* End of Saturate: '<S11>/Saturation1' */
  /* End of Outputs for SubSystem: '<Root>/WORKSHOP_MODE_RESTRICTIONS' */

  /* Outport: '<Root>/TC_Warning' */
  VDC_Y.TC_Warning = VDC_B.Merge3;

  /* Outport: '<Root>/APPS_Implausibility' */
  VDC_Y.APPS_Implausibility = rtb_Merge1_j;

  /* Outport: '<Root>/Torque_OK' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  VDC_Y.Torque_OK = rtb_LogicalOperator;

  /* Outport: '<Root>/Regenerative_Enable' */
  VDC_Y.Regenerative_Enable = rtb_Merge1_e;

  /* Outport: '<Root>/Throttle_Torque' */
  VDC_Y.Throttle_Torque = rtb_Product;
}

/* Model update function */
static void VDC_update(void)
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
  if (!(++VDC_M->Timing.clockTick0)) {
    ++VDC_M->Timing.clockTickH0;
  }

  VDC_M->Timing.t[0] = VDC_M->Timing.clockTick0 * VDC_M->Timing.stepSize0 +
    VDC_M->Timing.clockTickH0 * VDC_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void VDC_initialize(void)
{
  /* Start for DataStoreMemory: '<S20>/Data Store Memory1' */
  VDC_DW.ERROR_Counter = 0.0;

  /* Start for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Start for DataStoreMemory: '<S12>/Data Store Memory10' */
  VDC_DW.A = 0.0;

  /* End of Start for SubSystem: '<S1>/PowerLimitDetection' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S8>/Rigid Axle with TC 2024 ' */
  VDC_DW.correction_k = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/TC+TV' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/RIGIDAXLE WITH TC' */
  /* SystemInitialize for MATLAB Function: '<S6>/Rigid Axle with TC 2024 ' */
  VDC_DW.correction = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/RIGIDAXLE WITH TC' */

  /* SystemInitialize for Merge: '<Root>/Merge1' */
  VDC_B.Merge1 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge2' */
  VDC_B.Merge2 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge3' */
  VDC_B.Merge3 = false;
}

/* Model terminate function */
static void VDC_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  VDC_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  VDC_update();
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
  VDC_initialize();
}

void MdlTerminate(void)
{
  VDC_terminate();
}

/* Registration function */
RT_MODEL_VDC_T *VDC(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)VDC_M, 0,
                sizeof(RT_MODEL_VDC_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = VDC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "VDC_M points to
       static memory which is guaranteed to be non-NULL" */
    VDC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    VDC_M->Timing.sampleTimes = (&VDC_M->Timing.sampleTimesArray[0]);
    VDC_M->Timing.offsetTimes = (&VDC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    VDC_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    VDC_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(VDC_M, &VDC_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = VDC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    VDC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(VDC_M, 10.0);
  VDC_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    VDC_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(VDC_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(VDC_M->rtwLogInfo, (NULL));
    rtliSetLogT(VDC_M->rtwLogInfo, "tout");
    rtliSetLogX(VDC_M->rtwLogInfo, "");
    rtliSetLogXFinal(VDC_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(VDC_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(VDC_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(VDC_M->rtwLogInfo, 0);
    rtliSetLogDecimation(VDC_M->rtwLogInfo, 1);
    rtliSetLogY(VDC_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(VDC_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(VDC_M->rtwLogInfo, (NULL));
  }

  VDC_M->solverInfoPtr = (&VDC_M->solverInfo);
  VDC_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&VDC_M->solverInfo, 0.2);
  rtsiSetSolverMode(&VDC_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  VDC_M->blockIO = ((void *) &VDC_B);
  (void) memset(((void *) &VDC_B), 0,
                sizeof(B_VDC_T));

  /* states (dwork) */
  VDC_M->dwork = ((void *) &VDC_DW);
  (void) memset((void *)&VDC_DW, 0,
                sizeof(DW_VDC_T));

  /* external inputs */
  VDC_M->inputs = (((void*)&VDC_U));
  (void)memset(&VDC_U, 0, sizeof(ExtU_VDC_T));

  /* external outputs */
  VDC_M->outputs = (&VDC_Y);
  (void)memset(&VDC_Y, 0, sizeof(ExtY_VDC_T));

  /* Initialize Sizes */
  VDC_M->Sizes.numContStates = (0);    /* Number of continuous states */
  VDC_M->Sizes.numY = (10);            /* Number of model outputs */
  VDC_M->Sizes.numU = (34);            /* Number of model inputs */
  VDC_M->Sizes.sysDirFeedThru = (1);   /* The model is direct feedthrough */
  VDC_M->Sizes.numSampTimes = (1);     /* Number of sample times */
  VDC_M->Sizes.numBlocks = (135);      /* Number of blocks */
  VDC_M->Sizes.numBlockIO = (3);       /* Number of block outputs */
  return VDC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
