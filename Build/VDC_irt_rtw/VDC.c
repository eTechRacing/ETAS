/*
 * VDC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VDC".
 *
 * Model version              : 4.214
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sat Sep  7 16:40:11 2024
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
 * Output and update for atomic system:
 *    '<S50>/MATLAB Function'
 *    '<S51>/MATLAB Function'
 */
void VDC_MATLABFunction(real_T rtu_steering_max_angle, real_T rtu_steering,
  real_T rtu_steering_deadzone, real_T rtu_Throttle_Torque,
  B_MATLABFunction_VDC_T *localB)
{
  real_T d;
  d = fabs(rtu_steering);
  if (d <= rtu_steering_deadzone) {
    localB->Torque_L_Nm = rtu_Throttle_Torque;
    localB->Torque_R_Nm = rtu_Throttle_Torque;
  } else {
    d = (d - rtu_steering_deadzone) / (rtu_steering_max_angle -
      rtu_steering_deadzone) * rtu_Throttle_Torque;
    if (d > rtu_Throttle_Torque) {
      d = rtu_Throttle_Torque;
    }

    if (rtu_steering < -rtu_steering_deadzone) {
      localB->Torque_L_Nm = rtu_Throttle_Torque - d;
      localB->Torque_R_Nm = rtu_Throttle_Torque;
    } else {
      localB->Torque_L_Nm = rtu_Throttle_Torque;
      localB->Torque_R_Nm = rtu_Throttle_Torque - d;
    }
  }
}

/*
 * Output and update for action system:
 *    '<S7>/RIGIDAXLE'
 *    '<S1>/RIGIDAXLE'
 *    '<S2>/RIGIDAXLE'
 *    '<S4>/RIGIDAXLE'
 */
void VDC_RIGIDAXLE(real_T rtu_Throttle_TorqueNm, real_T *rty_Tq_RR_SM4Nm027,
                   real_T *rty_Tq_RL_SM4Nm027, real_T *rty_sensorics_mode)
{
  /* SignalConversion generated from: '<S49>/Tq_RL_SM4 [Nm] (0,27)' incorporates:
   *  MATLAB Function: '<S49>/Rigid Axle 2024 '
   */
  *rty_Tq_RL_SM4Nm027 = rtu_Throttle_TorqueNm;

  /* SignalConversion generated from: '<S49>/Tq_RR_SM4 [Nm] (0,27)' incorporates:
   *  MATLAB Function: '<S49>/Rigid Axle 2024 '
   */
  *rty_Tq_RR_SM4Nm027 = rtu_Throttle_TorqueNm;

  /* SignalConversion generated from: '<S49>/sensorics_mode' incorporates:
   *  Constant: '<S49>/RigidAxle'
   */
  *rty_sensorics_mode = 4.0;
}

/*
 * Output and update for atomic system:
 *    '<S7>/Torque demanded by the driver'
 *    '<S1>/Torque demanded by the driver'
 *    '<S2>/Torque demanded by the driver'
 */
void VDC_Torquedemandedbythedriver(real_T rtu_AP, real_T rtu_pedal_sat_down,
  real_T rtu_pedal_sat_up, real_T rtu_max_torque,
  B_Torquedemandedbythedriver_V_T *localB)
{
  real_T Throttle_Response;
  if (rtu_AP <= rtu_pedal_sat_down) {
    Throttle_Response = 0.0;
  } else if (rtu_AP >= rtu_pedal_sat_up) {
    Throttle_Response = 1.0;
  } else {
    Throttle_Response = (rtu_AP - rtu_pedal_sat_down) / (rtu_pedal_sat_up -
      rtu_pedal_sat_down);
  }

  localB->Throttle_Torque = Throttle_Response * rtu_max_torque;
}

/*
 * System initialize for atomic system:
 *    '<S17>/Rigid Axle with TC 2024 '
 *    '<S25>/Rigid Axle with TC 2024 '
 */
void VDC_RigidAxlewithTC2024_Init(DW_RigidAxlewithTC2024_VDC_T *localDW)
{
  localDW->correction = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S17>/Rigid Axle with TC 2024 '
 *    '<S25>/Rigid Axle with TC 2024 '
 */
void VDC_RigidAxlewithTC2024(real_T rtu_MAX_SLR, real_T rtu_Throttle_Torque,
  real_T rtu_el_Vel_X, real_T rtu_Max_Vel_ms_Wheel, B_RigidAxlewithTC2024_VDC_T *
  localB, DW_RigidAxlewithTC2024_VDC_T *localDW)
{
  if ((rtu_el_Vel_X < 0.5) || (rtu_Max_Vel_ms_Wheel < 0.5)) {
    localB->TC_Warning = 0.0;
    localDW->correction = 0.0;
    localB->Motor_Torque_RR = rtu_Throttle_Torque;
    localB->Motor_Torque_RL = rtu_Throttle_Torque;
  } else if (rtu_Max_Vel_ms_Wheel / rtu_el_Vel_X < rtu_MAX_SLR) {
    localB->Motor_Torque_RR = rtu_Throttle_Torque;
    localB->Motor_Torque_RL = rtu_Throttle_Torque;
    localDW->correction = 0.0;
    localB->TC_Warning = 0.0;
  } else {
    localB->TC_Warning = 1.0;
    if (localDW->correction == 0.0) {
      localDW->correction = 1.0;
      localB->Motor_Torque_RR = rtu_Throttle_Torque - 0.060606060606060608;
      localB->Motor_Torque_RL = rtu_Throttle_Torque - 0.060606060606060608;
    } else {
      real_T Motor_Torque_RR_tmp;
      localDW->correction++;
      Motor_Torque_RR_tmp = rtu_Throttle_Torque - (localDW->correction *
        localDW->correction * 0.030303030303030304 + 0.030303030303030304 *
        localDW->correction);
      localB->Motor_Torque_RR = Motor_Torque_RR_tmp;
      localB->Motor_Torque_RL = Motor_Torque_RR_tmp;
    }
  }
}

/*
 * Output and update for action system:
 *    '<S35>/If Action Subsystem'
 *    '<S30>/If Action Subsystem'
 */
void VDC_IfActionSubsystem(real_T rtu_Tq_RR, real_T rtu_Tq_RL, real_T *rty_TQ_RR,
  real_T *rty_TQ_RL)
{
  /* Gain: '<S36>/Gain' */
  *rty_TQ_RR = 0.25 * rtu_Tq_RR;

  /* Gain: '<S36>/Gain1' */
  *rty_TQ_RL = 0.25 * rtu_Tq_RL;
}

/*
 * Output and update for action system:
 *    '<S35>/If Action Subsystem1'
 *    '<S30>/If Action Subsystem1'
 */
void VDC_IfActionSubsystem1(real_T rtu_Tq_RR, real_T rtu_Tq_RL, real_T
  *rty_TQ_RL, real_T *rty_TQ_RR)
{
  /* SignalConversion generated from: '<S37>/Tq_RL' */
  *rty_TQ_RL = rtu_Tq_RL;

  /* SignalConversion generated from: '<S37>/Tq_RR' */
  *rty_TQ_RR = rtu_Tq_RR;
}

/* Model output function */
static void VDC_output(void)
{
  real_T rtb_Merge1_j;
  real_T rtb_Torque_L_Nm_l;
  real_T rtb_Torque_R_Nm_k;
  boolean_T rtb_LogicalOperator;

  /* If: '<S42>/If' incorporates:
   *  Abs: '<S42>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S42>/Sum'
   */
  if (fabs(VDC_U.APPS1_Value - VDC_U.APPS2_Value) > 0.1) {
    /* Outputs for IfAction SubSystem: '<S42>/Imp' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    /* Sum: '<S45>/Add' incorporates:
     *  Constant: '<S45>/Constant'
     *  DataStoreRead: '<S45>/Data Store Read'
     */
    rtb_Merge1_j = VDC_DW.ERROR_Counter + 1.0;

    /* End of Outputs for SubSystem: '<S42>/Imp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S42>/Not Imp' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    /* SignalConversion generated from: '<S46>/0' incorporates:
     *  Constant: '<S46>/Constant'
     */
    rtb_Merge1_j = 0.0;

    /* End of Outputs for SubSystem: '<S42>/Not Imp' */
  }

  /* End of If: '<S42>/If' */

  /* DataStoreWrite: '<S42>/Data Store Write' */
  VDC_DW.ERROR_Counter = rtb_Merge1_j;

  /* Outputs for IfAction SubSystem: '<S42>/Signal_OK' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S42>/Signal_Failure' incorporates:
   *  ActionPort: '<S47>/Action Port'
   */
  /* If: '<S42>/If1' incorporates:
   *  Constant: '<S42>/Number_of_Periods'
   *  SignalConversion generated from: '<S47>/Out1'
   *  SignalConversion generated from: '<S48>/Out1'
   */
  rtb_Merge1_j = (rtb_Merge1_j > 4.0);

  /* End of Outputs for SubSystem: '<S42>/Signal_Failure' */
  /* End of Outputs for SubSystem: '<S42>/Signal_OK' */

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S43>/Constant'
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/NOT'
   *  RelationalOperator: '<S43>/Compare'
   */
  rtb_LogicalOperator = (VDC_U.Shutdown_PackageIntck && VDC_U.TorqueEnable &&
    (!VDC_U.CriticalDisconnection) && (VDC_U.Car_State == 15.0) &&
    (!(rtb_Merge1_j != 0.0)));

  /* If: '<Root>/If' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Inport: '<Root>/RacingMode'
   */
  if ((VDC_U.RacingMode == 1.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/WORKSHOP' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* MATLAB Function: '<S10>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     *  Inport: '<Root>/RL_Vel_ms_Wheel'
     *  Inport: '<Root>/RR_Vel_ms_Wheel'
     *  MinMax: '<Root>/Max'
     */
    if ((VDC_U.APPS1_Value <= 0.05) || (fmax(VDC_U.RR_Vel_ms_Wheel,
          VDC_U.RL_Vel_ms_Wheel) > 5.0)) {
      rtb_Torque_L_Nm_l = 0.0;
    } else if (VDC_U.APPS1_Value >= 1.0) {
      rtb_Torque_L_Nm_l = 1.0;
    } else {
      rtb_Torque_L_Nm_l = (VDC_U.APPS1_Value - 0.05) / 0.95;
    }

    rtb_Torque_L_Nm_l *= 3.0;

    /* End of MATLAB Function: '<S10>/Torque demanded by the driver' */

    /* Saturate: '<S10>/Saturation' */
    if (rtb_Torque_L_Nm_l > 3.0) {
      rtb_Torque_L_Nm_l = 3.0;
    } else if (rtb_Torque_L_Nm_l < 0.0) {
      rtb_Torque_L_Nm_l = 0.0;
    }

    /* End of Saturate: '<S10>/Saturation' */

    /* Merge: '<Root>/Merge1' incorporates:
     *  SignalConversion generated from: '<S10>/TQ_L'
     */
    VDC_B.Merge1 = rtb_Torque_L_Nm_l;

    /* Merge: '<Root>/Merge2' incorporates:
     *  SignalConversion generated from: '<S10>/TQ_R'
     */
    VDC_B.Merge2 = rtb_Torque_L_Nm_l;

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S10>/TT'
     */
    VDC_B.Merge4 = rtb_Torque_L_Nm_l;

    /* End of Outputs for SubSystem: '<Root>/WORKSHOP' */
  } else if ((VDC_U.RacingMode == 2.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/SKIDPAD' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* MATLAB Function: '<S7>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDC_Torquedemandedbythedriver(VDC_U.APPS1_Value, 0.05, 1.0, 27.0,
      &VDC_B.sf_Torquedemandedbythedriver_m);

    /* Outputs for IfAction SubSystem: '<S7>/RIGIDAXLE' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* If: '<S7>/If' */
    VDC_RIGIDAXLE(VDC_B.sf_Torquedemandedbythedriver_m.Throttle_Torque,
                  &rtb_Torque_L_Nm_l, &rtb_Torque_R_Nm_k, &VDC_B.Merge3);

    /* End of Outputs for SubSystem: '<S7>/RIGIDAXLE' */

    /* Merge: '<Root>/Merge6' incorporates:
     *  SignalConversion generated from: '<S7>/TC_Warning'
     */
    VDC_B.Merge6 = VDC_B.TC_Warning_l;

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S7>/TT'
     */
    VDC_B.Merge4 = VDC_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;

    /* Saturate: '<S7>/Saturation' */
    if (rtb_Torque_L_Nm_l > 27.0) {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = 27.0;
    } else if (rtb_Torque_L_Nm_l < 0.0) {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = 0.0;
    } else {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = rtb_Torque_L_Nm_l;
    }

    /* End of Saturate: '<S7>/Saturation' */

    /* Saturate: '<S7>/Saturation1' */
    if (rtb_Torque_R_Nm_k > 27.0) {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = 27.0;
    } else if (rtb_Torque_R_Nm_k < 0.0) {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = 0.0;
    } else {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = rtb_Torque_R_Nm_k;
    }

    /* End of Saturate: '<S7>/Saturation1' */
    /* End of Outputs for SubSystem: '<Root>/SKIDPAD' */
  } else if ((VDC_U.RacingMode == 3.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/ACCELERATION' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* MATLAB Function: '<S1>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDC_Torquedemandedbythedriver(VDC_U.APPS1_Value, 0.05, 1.0, 27.0,
      &VDC_B.sf_Torquedemandedbythedriver_k);

    /* Outputs for IfAction SubSystem: '<S1>/RIGIDAXLE' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* If: '<S1>/If' */
    VDC_RIGIDAXLE(VDC_B.sf_Torquedemandedbythedriver_k.Throttle_Torque,
                  &rtb_Torque_L_Nm_l, &rtb_Torque_R_Nm_k, &VDC_B.Merge3);

    /* End of Outputs for SubSystem: '<S1>/RIGIDAXLE' */

    /* Merge: '<Root>/Merge6' incorporates:
     *  SignalConversion generated from: '<S1>/TC_Warning'
     */
    VDC_B.Merge6 = VDC_B.TC_Warning;

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S1>/TT'
     */
    VDC_B.Merge4 = VDC_B.sf_Torquedemandedbythedriver_k.Throttle_Torque;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Torque_L_Nm_l > 27.0) {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = 27.0;
    } else if (rtb_Torque_L_Nm_l < 0.0) {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = 0.0;
    } else {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = rtb_Torque_L_Nm_l;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_Torque_R_Nm_k > 27.0) {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = 27.0;
    } else if (rtb_Torque_R_Nm_k < 0.0) {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = 0.0;
    } else {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = rtb_Torque_R_Nm_k;
    }

    /* End of Saturate: '<S1>/Saturation1' */
    /* End of Outputs for SubSystem: '<Root>/ACCELERATION' */
  } else if (((VDC_U.RacingMode == 4.0) && rtb_LogicalOperator) ||
             ((VDC_U.RacingMode == 5.0) && rtb_LogicalOperator)) {
    /* Outputs for IfAction SubSystem: '<Root>/AUTOX1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MATLAB Function: '<S2>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDC_Torquedemandedbythedriver(VDC_U.APPS1_Value, 0.05, 1.0, 27.0,
      &VDC_B.sf_Torquedemandedbythedriver_a);

    /* Outputs for IfAction SubSystem: '<S2>/RIGIDAXLE' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* If: '<S2>/If' */
    VDC_RIGIDAXLE(VDC_B.sf_Torquedemandedbythedriver_a.Throttle_Torque,
                  &rtb_Torque_R_Nm_k, &rtb_Torque_L_Nm_l, &VDC_B.Merge3);

    /* End of Outputs for SubSystem: '<S2>/RIGIDAXLE' */

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S2>/TT'
     */
    VDC_B.Merge4 = VDC_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;

    /* Saturate: '<S2>/Saturation' */
    if (rtb_Torque_R_Nm_k > 27.0) {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = 27.0;
    } else if (rtb_Torque_R_Nm_k < 0.0) {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = 0.0;
    } else {
      /* Merge: '<Root>/Merge2' */
      VDC_B.Merge2 = rtb_Torque_R_Nm_k;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Saturate: '<S2>/Saturation1' */
    if (rtb_Torque_L_Nm_l > 27.0) {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = 27.0;
    } else if (rtb_Torque_L_Nm_l < 0.0) {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = 0.0;
    } else {
      /* Merge: '<Root>/Merge1' */
      VDC_B.Merge1 = rtb_Torque_L_Nm_l;
    }

    /* End of Saturate: '<S2>/Saturation1' */
    /* End of Outputs for SubSystem: '<Root>/AUTOX1' */
  }

  /* End of If: '<Root>/If' */

  /* MATLAB Function: '<Root>/Safety' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  if (rtb_LogicalOperator && (fmax(VDC_U.RR_rads_Motor, VDC_U.RL_rads_Motor) <
       1727.8759594743863)) {
    /* Saturate: '<Root>/Saturation' */
    if (VDC_B.Merge2 > 27.0) {
      /* Outport: '<Root>/Torque_R' */
      VDC_Y.Torque_R = 27.0;
    } else if (VDC_B.Merge2 < -27.0) {
      /* Outport: '<Root>/Torque_R' */
      VDC_Y.Torque_R = -27.0;
    } else {
      /* Outport: '<Root>/Torque_R' */
      VDC_Y.Torque_R = VDC_B.Merge2;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Saturate: '<Root>/Saturation1' */
    if (VDC_B.Merge1 > 27.0) {
      /* Outport: '<Root>/Torque_L' */
      VDC_Y.Torque_L = 27.0;
    } else if (VDC_B.Merge1 < -27.0) {
      /* Outport: '<Root>/Torque_L' */
      VDC_Y.Torque_L = -27.0;
    } else {
      /* Outport: '<Root>/Torque_L' */
      VDC_Y.Torque_L = VDC_B.Merge1;
    }

    /* End of Saturate: '<Root>/Saturation1' */
  } else {
    /* Outport: '<Root>/Torque_R' */
    VDC_Y.Torque_R = 0.0;

    /* Outport: '<Root>/Torque_L' */
    VDC_Y.Torque_L = 0.0;
  }

  /* End of MATLAB Function: '<Root>/Safety' */

  /* Outport: '<Root>/APPS_Implausibility' */
  VDC_Y.APPS_Implausibility = rtb_Merge1_j;

  /* Outport: '<Root>/Torque_OK' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  VDC_Y.Torque_OK = rtb_LogicalOperator;

  /* Outport: '<Root>/Sensorics_Mode' */
  VDC_Y.Sensorics_Mode = VDC_B.Merge3;

  /* Outport: '<Root>/BrakeLight_Control' incorporates:
   *  Constant: '<Root>/Brake_Light_Threshold'
   *  Inport: '<Root>/BrakePedal_Value'
   *  Inport: '<Root>/RacingMode'
   *  MATLAB Function: '<Root>/Brake_Light'
   */
  VDC_Y.BrakeLight_Control = (((VDC_U.RacingMode == 5.0) && (VDC_B.state == 0.0))
    || (VDC_U.BrakePedal_Value > 0.2));

  /* Outport: '<Root>/Throttle_Torque' */
  VDC_Y.Throttle_Torque = VDC_B.Merge4;

  /* Outport: '<Root>/TC_Warning' */
  VDC_Y.TC_Warning = VDC_B.Merge6;
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
  /* Start for DataStoreMemory: '<S42>/Data Store Memory1' */
  VDC_DW.ERROR_Counter = 0.0;

  /* ConstCode for Outport: '<Root>/VDC_Max_Tyre_Slip' incorporates:
   *  Constant: '<Root>/Max_Tyre_Slip'
   */
  VDC_Y.VDC_Max_Tyre_Slip = 1.3;

  /* SystemInitialize for IfAction SubSystem: '<Root>/SKIDPAD' */
  /* SystemInitialize for IfAction SubSystem: '<S7>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S50>/Rigid Axle with TC 2024 ' */
  VDC_DW.correction_h = 0.0;

  /* SystemInitialize for Outport: '<S50>/TC_Warning' */
  VDC_B.TC_Warning_l = 0.0;

  /* End of SystemInitialize for SubSystem: '<S7>/TC+TV' */
  /* End of SystemInitialize for SubSystem: '<Root>/SKIDPAD' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ACCELERATION' */
  /* SystemInitialize for IfAction SubSystem: '<S1>/RIGIDAXLE WITH TC' */
  /* SystemInitialize for MATLAB Function: '<S12>/Rigid Axle with TC 2024 ' */
  VDC_DW.correction_g = 0.0;

  /* SystemInitialize for Outport: '<S12>/TC_Warning' */
  VDC_B.TC_Warning = 0.0;

  /* End of SystemInitialize for SubSystem: '<S1>/RIGIDAXLE WITH TC' */
  /* End of SystemInitialize for SubSystem: '<Root>/ACCELERATION' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/AUTOX1' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S18>/Rigid Axle with TC 2024 ' */
  VDC_DW.correction_i = 0.0;

  /* End of SystemInitialize for SubSystem: '<S2>/TC+TV' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/RIGIDAXLE WITH TC' */
  /* SystemInitialize for MATLAB Function: '<S17>/Rigid Axle with TC 2024 ' */
  VDC_RigidAxlewithTC2024_Init(&VDC_DW.sf_RigidAxlewithTC2024_p2);

  /* End of SystemInitialize for SubSystem: '<S2>/RIGIDAXLE WITH TC' */
  /* End of SystemInitialize for SubSystem: '<Root>/AUTOX1' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ENDURANCE' */
  /* SystemInitialize for IfAction SubSystem: '<S4>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S26>/TC 2024' */
  VDC_DW.correction = 0.0;

  /* End of SystemInitialize for SubSystem: '<S4>/TC+TV' */

  /* SystemInitialize for IfAction SubSystem: '<S4>/RIGIDAXLE WITH TC' */
  /* SystemInitialize for MATLAB Function: '<S25>/Rigid Axle with TC 2024 ' */
  VDC_RigidAxlewithTC2024_Init(&VDC_DW.sf_RigidAxlewithTC2024_c);

  /* End of SystemInitialize for SubSystem: '<S4>/RIGIDAXLE WITH TC' */

  /* SystemInitialize for Outport: '<S4>/Pedal_State' */
  VDC_B.state = 0.0;

  /* SystemInitialize for Outport: '<Root>/Regenerative_Enable' incorporates:
   *  Outport: '<S4>/regen_en'
   */
  VDC_Y.Regenerative_Enable = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/ENDURANCE' */

  /* SystemInitialize for Merge: '<Root>/Merge2' */
  VDC_B.Merge2 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge1' */
  VDC_B.Merge1 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge3' */
  VDC_B.Merge3 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge4' */
  VDC_B.Merge4 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge6' */
  VDC_B.Merge6 = 0.0;
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
  VDC_M->Sizes.numU = (29);            /* Number of model inputs */
  VDC_M->Sizes.sysDirFeedThru = (1);   /* The model is direct feedthrough */
  VDC_M->Sizes.numSampTimes = (1);     /* Number of sample times */
  VDC_M->Sizes.numBlocks = (218);      /* Number of blocks */
  VDC_M->Sizes.numBlockIO = (22);      /* Number of block outputs */
  return VDC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
