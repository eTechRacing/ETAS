/*
 * VDCv2mk2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VDCv2mk2".
 *
 * Model version              : 4.161
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Fri Jun 28 12:51:54 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VDCv2mk2.h"
#include "rtwtypes.h"
#include "VDCv2mk2_private.h"
#include <math.h>
#include <string.h>
#include "look1_binlxpw.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_VDCv2mk2_T VDCv2mk2_B;

/* Block states (default storage) */
DW_VDCv2mk2_T VDCv2mk2_DW;

/* External inputs (root inport signals with default storage) */
ExtU_VDCv2mk2_T VDCv2mk2_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_VDCv2mk2_T VDCv2mk2_Y;

/* Real-time model */
static RT_MODEL_VDCv2mk2_T VDCv2mk2_M_;
RT_MODEL_VDCv2mk2_T *const VDCv2mk2_M = &VDCv2mk2_M_;

/*
 * Output and update for action system:
 *    '<S24>/LimitReached'
 *    '<S27>/Latched Error'
 */
void VDCv2mk2_LimitReached(real_T *rty_Out)
{
  /* SignalConversion generated from: '<S26>/Out ' incorporates:
   *  Constant: '<S26>/Constant'
   */
  *rty_Out = 1.0;
}

/*
 * Output and update for atomic system:
 *    '<S53>/MATLAB Function'
 *    '<S54>/MATLAB Function'
 */
void VDCv2mk2_MATLABFunction(real_T rtu_steering_max_angle, real_T rtu_steering,
  real_T rtu_steering_deadzone, real_T rtu_Throttle_Torque,
  B_MATLABFunction_VDCv2mk2_T *localB)
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
 *    '<S5>/RIGIDAXLE'
 */
void VDCv2mk2_RIGIDAXLE(real_T rtu_Throttle_TorqueNm, real_T
  *rty_Tq_RR_FM4Nm0inf, real_T *rty_Tq_RL_FM4Nm0inf, real_T *rty_tv_mode)
{
  /* SignalConversion generated from: '<S52>/Tq_RL_FM4 [Nm] (0,inf)' incorporates:
   *  MATLAB Function: '<S52>/Rigid Axle 2024 '
   */
  *rty_Tq_RL_FM4Nm0inf = rtu_Throttle_TorqueNm;

  /* SignalConversion generated from: '<S52>/Tq_RR_FM4 [Nm] (0,inf)' incorporates:
   *  MATLAB Function: '<S52>/Rigid Axle 2024 '
   */
  *rty_Tq_RR_FM4Nm0inf = rtu_Throttle_TorqueNm;

  /* SignalConversion generated from: '<S52>/tv_mode' incorporates:
   *  Constant: '<S52>/Constant'
   */
  *rty_tv_mode = 4.0;
}

/*
 * Output and update for atomic system:
 *    '<S7>/Torque demanded by the driver'
 *    '<S1>/Torque demanded by the driver'
 *    '<S2>/Torque demanded by the driver'
 */
void VDCv2_Torquedemandedbythedriver(real_T rtu_AP, real_T rtu_pedal_sat_down,
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
 * System initialize for action system:
 *    '<S1>/RIGIDAXLE WITH TC'
 *    '<S2>/RIGIDAXLE WITH TC'
 */
void VDCv2mk2_RIGIDAXLEWITHTC_Init(DW_RIGIDAXLEWITHTC_VDCv2mk2_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S12>/Rigid Axle with TC 2024 ' */
  localDW->correction = 0.0;
}

/*
 * Output and update for action system:
 *    '<S1>/RIGIDAXLE WITH TC'
 *    '<S2>/RIGIDAXLE WITH TC'
 */
void VDCv2mk2_RIGIDAXLEWITHTC(real_T rtu_RR_Vel_ms_Wheelms, real_T
  rtu_RL_Vel_ms_Wheelms, real_T rtu_Throttle_TorqueNm, real_T rtu_MAX_SLR,
  real_T rtu_el_Vel_Xms, real_T *rty_Tq_RR_FM2Nm0inf, real_T
  *rty_Tq_RL_FM2Nm0inf, real_T *rty_tv_mode, DW_RIGIDAXLEWITHTC_VDCv2mk2_T
  *localDW)
{
  real_T rtb_Max_g;

  /* MinMax: '<S12>/Max' */
  rtb_Max_g = fmax(rtu_RR_Vel_ms_Wheelms, rtu_RL_Vel_ms_Wheelms);

  /* MATLAB Function: '<S12>/Rigid Axle with TC 2024 ' */
  if ((rtu_el_Vel_Xms < 0.5) || (rtb_Max_g < 0.5)) {
    localDW->correction = 0.0;

    /* SignalConversion generated from: '<S12>/Tq_RR_FM2 [Nm] (0,inf)' */
    *rty_Tq_RR_FM2Nm0inf = rtu_Throttle_TorqueNm;

    /* SignalConversion generated from: '<S12>/Tq_RL_FM2 [Nm] (0,inf)' */
    *rty_Tq_RL_FM2Nm0inf = rtu_Throttle_TorqueNm;
  } else {
    rtb_Max_g /= rtu_el_Vel_Xms;
    if (rtb_Max_g < rtu_MAX_SLR) {
      /* SignalConversion generated from: '<S12>/Tq_RR_FM2 [Nm] (0,inf)' */
      *rty_Tq_RR_FM2Nm0inf = rtu_Throttle_TorqueNm;

      /* SignalConversion generated from: '<S12>/Tq_RL_FM2 [Nm] (0,inf)' */
      *rty_Tq_RL_FM2Nm0inf = rtu_Throttle_TorqueNm;
      localDW->correction = 0.0;
    } else if (localDW->correction == 0.0) {
      localDW->correction = 1.0;

      /* SignalConversion generated from: '<S12>/Tq_RR_FM2 [Nm] (0,inf)' */
      *rty_Tq_RR_FM2Nm0inf = rtu_Throttle_TorqueNm - 0.060606060606060608;

      /* SignalConversion generated from: '<S12>/Tq_RL_FM2 [Nm] (0,inf)' */
      *rty_Tq_RL_FM2Nm0inf = rtu_Throttle_TorqueNm - 0.060606060606060608;
    } else {
      localDW->correction++;
      rtb_Max_g = rtu_Throttle_TorqueNm - (localDW->correction *
        localDW->correction * 0.030303030303030304 + 0.030303030303030304 *
        localDW->correction);

      /* SignalConversion generated from: '<S12>/Tq_RR_FM2 [Nm] (0,inf)' */
      *rty_Tq_RR_FM2Nm0inf = rtb_Max_g;

      /* SignalConversion generated from: '<S12>/Tq_RL_FM2 [Nm] (0,inf)' */
      *rty_Tq_RL_FM2Nm0inf = rtb_Max_g;
    }
  }

  /* End of MATLAB Function: '<S12>/Rigid Axle with TC 2024 ' */

  /* SignalConversion generated from: '<S12>/tv_mode' incorporates:
   *  Constant: '<S12>/Constant'
   */
  *rty_tv_mode = 2.0;
}

/* Model output function */
static void VDCv2mk2_output(void)
{
  real_T rtb_Merge1_e;
  real_T rtb_Merge1_j;
  real_T rtb_Product;
  real_T rtb_Torque_L_Nm;
  real_T rtb_Torque_R_Nm;
  real_T rtb_max_regen_torque_RL;
  int32_T regen_en;
  boolean_T rtb_LogicalOperator;

  /* If: '<S45>/If' incorporates:
   *  Abs: '<S45>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S45>/Sum'
   */
  if (fabs(VDCv2mk2_U.APPS1_Value - VDCv2mk2_U.APPS2_Value) > 0.1) {
    /* Outputs for IfAction SubSystem: '<S45>/Imp' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* Sum: '<S48>/Add' incorporates:
     *  Constant: '<S48>/Constant'
     *  DataStoreRead: '<S48>/Data Store Read'
     */
    rtb_Merge1_j = VDCv2mk2_DW.ERROR_Counter + 1.0;

    /* End of Outputs for SubSystem: '<S45>/Imp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S45>/Not Imp' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* SignalConversion generated from: '<S49>/0' incorporates:
     *  Constant: '<S49>/Constant'
     */
    rtb_Merge1_j = 0.0;

    /* End of Outputs for SubSystem: '<S45>/Not Imp' */
  }

  /* End of If: '<S45>/If' */

  /* DataStoreWrite: '<S45>/Data Store Write' */
  VDCv2mk2_DW.ERROR_Counter = rtb_Merge1_j;

  /* Outputs for IfAction SubSystem: '<S45>/Signal_OK' incorporates:
   *  ActionPort: '<S51>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S45>/Signal_Failure' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* If: '<S45>/If1' incorporates:
   *  Constant: '<S45>/Number_of_Periods'
   *  SignalConversion generated from: '<S50>/Out1'
   *  SignalConversion generated from: '<S51>/Out1'
   */
  rtb_Merge1_j = (rtb_Merge1_j > 4.0);

  /* End of Outputs for SubSystem: '<S45>/Signal_Failure' */
  /* End of Outputs for SubSystem: '<S45>/Signal_OK' */

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S46>/Constant'
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/NOT'
   *  RelationalOperator: '<S46>/Compare'
   */
  rtb_LogicalOperator = (VDCv2mk2_U.Shutdown_PackageIntck &&
    VDCv2mk2_U.TorqueEnable && (!VDCv2mk2_U.CriticalDisconnection) &&
    (VDCv2mk2_U.Car_State == 15.0) && (!(rtb_Merge1_j != 0.0)));

  /* Product: '<S3>/Product' incorporates:
   *  Inport: '<Root>/Accumulator_Current'
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  rtb_Product = VDCv2mk2_U.Accumulator_Voltage * VDCv2mk2_U.Accumulator_Current;

  /* Outport: '<Root>/Power' incorporates:
   *  Constant: '<S25>/0-100 to 0-2'
   *  Product: '<S25>/Divide5'
   */
  VDCv2mk2_Y.Power = rtb_Product / 1000.0;

  /* Outputs for Atomic SubSystem: '<S3>/PowerLimitDetection' */
  /* If: '<S24>/If' incorporates:
   *  DataStoreRead: '<S24>/Data Store Read30'
   *  If: '<S27>/If'
   *  SignalConversion generated from: '<S24>/Power'
   */
  if (rtb_Product >= 80000.0) {
    /* Outputs for IfAction SubSystem: '<S24>/LimitReached' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    VDCv2mk2_LimitReached(&rtb_Merge1_e);

    /* End of Outputs for SubSystem: '<S24>/LimitReached' */

    /* Outputs for IfAction SubSystem: '<S24>/OK_OrLatch' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
  } else if (VDCv2mk2_DW.A > 0.0) {
    /* Outputs for IfAction SubSystem: '<S27>/Latched Error' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* If: '<S27>/If' */
    VDCv2mk2_LimitReached(&rtb_Merge1_e);

    /* End of Outputs for SubSystem: '<S27>/Latched Error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S27>/OK' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* If: '<S27>/If' incorporates:
     *  Constant: '<S29>/Constant'
     *  SignalConversion generated from: '<S29>/Out '
     */
    rtb_Merge1_e = 0.0;

    /* End of Outputs for SubSystem: '<S27>/OK' */

    /* End of Outputs for SubSystem: '<S24>/OK_OrLatch' */
  }

  /* End of If: '<S24>/If' */

  /* DataStoreWrite: '<S24>/Data Store Write20' */
  VDCv2mk2_DW.A = rtb_Merge1_e;

  /* End of Outputs for SubSystem: '<S3>/PowerLimitDetection' */

  /* Outport: '<Root>/PowerLimitReached' */
  VDCv2mk2_Y.PowerLimitReached = rtb_Merge1_e;

  /* Outputs for Atomic SubSystem: '<S3>/PowerLimitDetection' */
  /* Outport: '<Root>/PowerMean500ms' incorporates:
   *  SignalConversion generated from: '<S24>/Power'
   */
  VDCv2mk2_Y.PowerMean500ms = rtb_Product;

  /* End of Outputs for SubSystem: '<S3>/PowerLimitDetection' */

  /* If: '<Root>/If' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Inport: '<Root>/RacingMode'
   */
  if ((VDCv2mk2_U.RacingMode == 1.0) && rtb_LogicalOperator) {
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
    if ((VDCv2mk2_U.APPS1_Value <= 0.0) || (fmax(VDCv2mk2_U.RR_Vel_ms_Wheel,
          VDCv2mk2_U.RL_Vel_ms_Wheel) > 5.0)) {
      rtb_Torque_L_Nm = 0.0;
    } else if (VDCv2mk2_U.APPS1_Value >= 1.0) {
      rtb_Torque_L_Nm = 1.0;
    } else {
      rtb_Torque_L_Nm = VDCv2mk2_U.APPS1_Value;
    }

    rtb_Product = rtb_Torque_L_Nm * 5.4;

    /* End of MATLAB Function: '<S10>/Torque demanded by the driver' */

    /* Saturate: '<S10>/Saturation' */
    if (rtb_Product > 6.0) {
      rtb_Product = 6.0;
    } else if (rtb_Product < 0.0) {
      rtb_Product = 0.0;
    }

    /* End of Saturate: '<S10>/Saturation' */

    /* Merge: '<Root>/Merge1' incorporates:
     *  SignalConversion generated from: '<S10>/TQ_L'
     */
    VDCv2mk2_B.Merge1 = rtb_Product;

    /* Merge: '<Root>/Merge2' incorporates:
     *  SignalConversion generated from: '<S10>/TQ_R'
     */
    VDCv2mk2_B.Merge2 = rtb_Product;

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S10>/TT'
     */
    VDCv2mk2_B.Merge4 = rtb_Product;

    /* End of Outputs for SubSystem: '<Root>/WORKSHOP' */
  } else if ((VDCv2mk2_U.RacingMode == 2.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/SKIDPAD' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* MATLAB Function: '<S7>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDCv2_Torquedemandedbythedriver(VDCv2mk2_U.APPS1_Value, 0.0, 1.0, 27.0,
      &VDCv2mk2_B.sf_Torquedemandedbythedriver_m);

    /* If: '<S7>/If' incorporates:
     *  Inport: '<Root>/Disconnection_Mode'
     */
    if (VDCv2mk2_U.Disconnection_Mode == 1.0) {
      /* Outputs for IfAction SubSystem: '<S7>/TC+TV' incorporates:
       *  ActionPort: '<S53>/Action Port'
       */
      /* MATLAB Function: '<S53>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [�]'
       *  Constant: '<Root>/Steering_wheel_sat [�]'
       *  Inport: '<Root>/SteeringSensor_Value'
       */
      VDCv2mk2_MATLABFunction(125.0, VDCv2mk2_U.SteeringSensor_Value, 10.0,
        VDCv2mk2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque,
        &VDCv2mk2_B.sf_MATLABFunction);

      /* MATLAB Function: '<S53>/Rigid Axle with TC 2024 ' incorporates:
       *  Constant: '<Root>/Max_Tyre_Slip'
       *  Inport: '<Root>/RL_Vel_ms_Wheel'
       *  Inport: '<Root>/RR_Vel_ms_Wheel'
       *  Inport: '<Root>/el_Vel_X'
       */
      if ((VDCv2mk2_U.el_Vel_X < 0.5) || (VDCv2mk2_U.RR_Vel_ms_Wheel < 0.5) ||
          (VDCv2mk2_U.RL_Vel_ms_Wheel < 0.5)) {
        VDCv2mk2_DW.correction_h = 0.0;

        /* SignalConversion generated from: '<S53>/Tq_RR_FM1 [Nm] (0,inf)' */
        rtb_Product = VDCv2mk2_B.sf_MATLABFunction.Torque_R_Nm;

        /* SignalConversion generated from: '<S53>/Tq_RL_FM1 [Nm] (0,inf)' */
        rtb_Merge1_e = VDCv2mk2_B.sf_MATLABFunction.Torque_L_Nm;
      } else {
        if ((VDCv2mk2_U.el_Vel_X == 0.0) || (VDCv2mk2_U.RR_Vel_ms_Wheel == 0.0))
        {
          rtb_Merge1_e = 1.0;
        } else {
          rtb_Merge1_e = VDCv2mk2_U.RR_Vel_ms_Wheel / VDCv2mk2_U.el_Vel_X;
        }

        if ((VDCv2mk2_U.el_Vel_X == 0.0) || (VDCv2mk2_U.RL_Vel_ms_Wheel == 0.0))
        {
          rtb_max_regen_torque_RL = 1.0;
        } else {
          rtb_max_regen_torque_RL = VDCv2mk2_U.RL_Vel_ms_Wheel /
            VDCv2mk2_U.el_Vel_X;
        }

        if (fmax(rtb_Merge1_e, rtb_max_regen_torque_RL) < 1.0) {
          /* SignalConversion generated from: '<S53>/Tq_RR_FM1 [Nm] (0,inf)' */
          rtb_Product = VDCv2mk2_B.sf_MATLABFunction.Torque_R_Nm;

          /* SignalConversion generated from: '<S53>/Tq_RL_FM1 [Nm] (0,inf)' */
          rtb_Merge1_e = VDCv2mk2_B.sf_MATLABFunction.Torque_L_Nm;
          VDCv2mk2_DW.correction_h = 0.0;
        } else if (VDCv2mk2_DW.correction_h == 0.0) {
          VDCv2mk2_DW.correction_h = 1.0;

          /* SignalConversion generated from: '<S53>/Tq_RR_FM1 [Nm] (0,inf)' */
          rtb_Product = VDCv2mk2_B.sf_MATLABFunction.Torque_R_Nm -
            0.060606060606060608;

          /* SignalConversion generated from: '<S53>/Tq_RL_FM1 [Nm] (0,inf)' */
          rtb_Merge1_e = VDCv2mk2_B.sf_MATLABFunction.Torque_L_Nm -
            0.060606060606060608;
        } else {
          VDCv2mk2_DW.correction_h++;

          /* SignalConversion generated from: '<S53>/Tq_RR_FM1 [Nm] (0,inf)' */
          rtb_Product = VDCv2mk2_B.sf_MATLABFunction.Torque_R_Nm -
            (VDCv2mk2_DW.correction_h * VDCv2mk2_DW.correction_h *
             0.030303030303030304 + 0.030303030303030304 *
             VDCv2mk2_DW.correction_h);

          /* SignalConversion generated from: '<S53>/Tq_RL_FM1 [Nm] (0,inf)' */
          rtb_Merge1_e = VDCv2mk2_B.sf_MATLABFunction.Torque_L_Nm -
            (VDCv2mk2_DW.correction_h * VDCv2mk2_DW.correction_h *
             0.030303030303030304 + 0.030303030303030304 *
             VDCv2mk2_DW.correction_h);
        }
      }

      /* End of MATLAB Function: '<S53>/Rigid Axle with TC 2024 ' */

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S53>/Constant'
       *  SignalConversion generated from: '<S53>/tv_mode'
       */
      VDCv2mk2_B.Merge3 = 1.0;

      /* End of Outputs for SubSystem: '<S7>/TC+TV' */
    } else if (VDCv2mk2_U.Disconnection_Mode <= 3.0) {
      /* Outputs for IfAction SubSystem: '<S7>/TV with TC OFF ' incorporates:
       *  ActionPort: '<S54>/Action Port'
       */
      /* MATLAB Function: '<S54>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [�]'
       *  Constant: '<Root>/Steering_wheel_sat [�]'
       *  Inport: '<Root>/SteeringSensor_Value'
       */
      VDCv2mk2_MATLABFunction(125.0, VDCv2mk2_U.SteeringSensor_Value, 10.0,
        VDCv2mk2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque,
        &VDCv2mk2_B.sf_MATLABFunction_a);

      /* SignalConversion generated from: '<S54>/Tq_RL_FM3 [Nm] (0,inf)' */
      rtb_Merge1_e = VDCv2mk2_B.sf_MATLABFunction_a.Torque_L_Nm;

      /* SignalConversion generated from: '<S54>/Tq_RR_FM3 [Nm] (0,inf)' */
      rtb_Product = VDCv2mk2_B.sf_MATLABFunction_a.Torque_R_Nm;

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S54>/Constant'
       *  SignalConversion generated from: '<S54>/tv_mode'
       */
      VDCv2mk2_B.Merge3 = 3.0;

      /* End of Outputs for SubSystem: '<S7>/TV with TC OFF ' */
    } else {
      /* Outputs for IfAction SubSystem: '<S7>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      VDCv2mk2_RIGIDAXLE
        (VDCv2mk2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque, &rtb_Product,
         &rtb_Merge1_e, &VDCv2mk2_B.Merge3);

      /* End of Outputs for SubSystem: '<S7>/RIGIDAXLE' */
    }

    /* End of If: '<S7>/If' */

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S7>/TT'
     */
    VDCv2mk2_B.Merge4 =
      VDCv2mk2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;

    /* Saturate: '<S7>/Saturation' */
    if (rtb_Product > 27.0) {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = 27.0;
    } else if (rtb_Product < 0.0) {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = 0.0;
    } else {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = rtb_Product;
    }

    /* End of Saturate: '<S7>/Saturation' */

    /* Saturate: '<S7>/Saturation1' */
    if (rtb_Merge1_e > 27.0) {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = 27.0;
    } else if (rtb_Merge1_e < 0.0) {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = 0.0;
    } else {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = rtb_Merge1_e;
    }

    /* End of Saturate: '<S7>/Saturation1' */
    /* End of Outputs for SubSystem: '<Root>/SKIDPAD' */
  } else if ((VDCv2mk2_U.RacingMode == 3.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/ACCELERATION' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* MATLAB Function: '<S1>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDCv2_Torquedemandedbythedriver(VDCv2mk2_U.APPS1_Value, 0.0, 1.0, 27.0,
      &VDCv2mk2_B.sf_Torquedemandedbythedriver_k);

    /* If: '<S1>/If' incorporates:
     *  Constant: '<Root>/Max_Tyre_Slip'
     *  Inport: '<Root>/Disconnection_Mode'
     *  Inport: '<Root>/RL_Vel_ms_Wheel'
     *  Inport: '<Root>/RR_Vel_ms_Wheel'
     *  Inport: '<Root>/el_Vel_X'
     */
    if (VDCv2mk2_U.Disconnection_Mode <= 2.0) {
      /* Outputs for IfAction SubSystem: '<S1>/RIGIDAXLE WITH TC' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      VDCv2mk2_RIGIDAXLEWITHTC(VDCv2mk2_U.RR_Vel_ms_Wheel,
        VDCv2mk2_U.RL_Vel_ms_Wheel,
        VDCv2mk2_B.sf_Torquedemandedbythedriver_k.Throttle_Torque, 1.0,
        VDCv2mk2_U.el_Vel_X, &rtb_Product, &rtb_Merge1_e, &VDCv2mk2_B.Merge3,
        &VDCv2mk2_DW.RIGIDAXLEWITHTC);

      /* End of Outputs for SubSystem: '<S1>/RIGIDAXLE WITH TC' */
    } else {
      /* Outputs for IfAction SubSystem: '<S1>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      VDCv2mk2_RIGIDAXLE
        (VDCv2mk2_B.sf_Torquedemandedbythedriver_k.Throttle_Torque, &rtb_Product,
         &rtb_Merge1_e, &VDCv2mk2_B.Merge3);

      /* End of Outputs for SubSystem: '<S1>/RIGIDAXLE' */
    }

    /* End of If: '<S1>/If' */

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S1>/TT'
     */
    VDCv2mk2_B.Merge4 =
      VDCv2mk2_B.sf_Torquedemandedbythedriver_k.Throttle_Torque;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Product > 27.0) {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = 27.0;
    } else if (rtb_Product < 0.0) {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = 0.0;
    } else {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = rtb_Product;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_Merge1_e > 27.0) {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = 27.0;
    } else if (rtb_Merge1_e < 0.0) {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = 0.0;
    } else {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = rtb_Merge1_e;
    }

    /* End of Saturate: '<S1>/Saturation1' */
    /* End of Outputs for SubSystem: '<Root>/ACCELERATION' */
  } else if ((VDCv2mk2_U.RacingMode == 4.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/AUTOX1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MATLAB Function: '<S2>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDCv2_Torquedemandedbythedriver(VDCv2mk2_U.APPS1_Value, 0.0, 1.0, 27.0,
      &VDCv2mk2_B.sf_Torquedemandedbythedriver_a);

    /* If: '<S2>/If' incorporates:
     *  Constant: '<Root>/Max_Tyre_Slip'
     *  Inport: '<Root>/Disconnection_Mode'
     *  Inport: '<Root>/RL_Vel_ms_Wheel'
     *  Inport: '<Root>/RR_Vel_ms_Wheel'
     *  Inport: '<Root>/el_Vel_X'
     */
    if (VDCv2mk2_U.Disconnection_Mode == 1.0) {
      /* Outputs for IfAction SubSystem: '<S2>/TC+TV' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [�]'
       *  Constant: '<Root>/Steering_wheel_sat [�]'
       *  Inport: '<Root>/SteeringSensor_Value'
       */
      rtb_Product = fabs(VDCv2mk2_U.SteeringSensor_Value);
      if (rtb_Product <= 10.0) {
        rtb_Product = VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        rtb_Torque_L_Nm =
          VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
      } else {
        rtb_Merge1_e = (rtb_Product - 10.0) / 115.0 *
          VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        if (rtb_Merge1_e >
            VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque) {
          rtb_Merge1_e =
            VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        }

        if (VDCv2mk2_U.SteeringSensor_Value < -10.0) {
          rtb_Product =
            VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
          rtb_Torque_L_Nm =
            VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque +
            rtb_Merge1_e;
        } else {
          rtb_Product =
            VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque +
            rtb_Merge1_e;
          rtb_Torque_L_Nm =
            VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        }
      }

      /* End of MATLAB Function: '<S18>/MATLAB Function' */

      /* MATLAB Function: '<S18>/Rigid Axle with TC 2024 ' incorporates:
       *  Constant: '<Root>/Max_Tyre_Slip'
       *  Inport: '<Root>/RL_Vel_ms_Wheel'
       *  Inport: '<Root>/RR_Vel_ms_Wheel'
       *  Inport: '<Root>/el_Vel_X'
       */
      if ((VDCv2mk2_U.el_Vel_X < 0.5) || (VDCv2mk2_U.RR_Vel_ms_Wheel < 0.5) ||
          (VDCv2mk2_U.RL_Vel_ms_Wheel < 0.5)) {
        VDCv2mk2_DW.correction_i = 0.0;
      } else {
        if ((VDCv2mk2_U.el_Vel_X == 0.0) || (VDCv2mk2_U.RR_Vel_ms_Wheel == 0.0))
        {
          rtb_Merge1_e = 1.0;
        } else {
          rtb_Merge1_e = VDCv2mk2_U.RR_Vel_ms_Wheel / VDCv2mk2_U.el_Vel_X;
        }

        if ((VDCv2mk2_U.el_Vel_X == 0.0) || (VDCv2mk2_U.RL_Vel_ms_Wheel == 0.0))
        {
          rtb_max_regen_torque_RL = 1.0;
        } else {
          rtb_max_regen_torque_RL = VDCv2mk2_U.RL_Vel_ms_Wheel /
            VDCv2mk2_U.el_Vel_X;
        }

        if (fmax(rtb_Merge1_e, rtb_max_regen_torque_RL) < 1.0) {
          VDCv2mk2_DW.correction_i = 0.0;
        } else if (VDCv2mk2_DW.correction_i == 0.0) {
          VDCv2mk2_DW.correction_i = 1.0;

          /* SignalConversion generated from: '<S18>/Tq_RR_FM1 [Nm] (0,inf)' */
          rtb_Torque_L_Nm -= 0.060606060606060608;

          /* SignalConversion generated from: '<S18>/Tq_RL_FM1 [Nm] (0,inf)' */
          rtb_Product -= 0.060606060606060608;
        } else {
          VDCv2mk2_DW.correction_i++;
          rtb_Merge1_e = VDCv2mk2_DW.correction_i * VDCv2mk2_DW.correction_i *
            0.030303030303030304 + 0.030303030303030304 *
            VDCv2mk2_DW.correction_i;

          /* SignalConversion generated from: '<S18>/Tq_RR_FM1 [Nm] (0,inf)' */
          rtb_Torque_L_Nm -= rtb_Merge1_e;

          /* SignalConversion generated from: '<S18>/Tq_RL_FM1 [Nm] (0,inf)' */
          rtb_Product -= rtb_Merge1_e;
        }
      }

      /* End of MATLAB Function: '<S18>/Rigid Axle with TC 2024 ' */

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S18>/Constant'
       *  SignalConversion generated from: '<S18>/tv_mode'
       */
      VDCv2mk2_B.Merge3 = 1.0;

      /* End of Outputs for SubSystem: '<S2>/TC+TV' */
    } else if (VDCv2mk2_U.Disconnection_Mode == 2.0) {
      /* Outputs for IfAction SubSystem: '<S2>/RIGIDAXLE WITH TC' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      VDCv2mk2_RIGIDAXLEWITHTC(VDCv2mk2_U.RR_Vel_ms_Wheel,
        VDCv2mk2_U.RL_Vel_ms_Wheel,
        VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque, 1.0,
        VDCv2mk2_U.el_Vel_X, &rtb_Torque_L_Nm, &rtb_Product, &VDCv2mk2_B.Merge3,
        &VDCv2mk2_DW.RIGIDAXLEWITHTC_i);

      /* End of Outputs for SubSystem: '<S2>/RIGIDAXLE WITH TC' */
    } else {
      /* Outputs for IfAction SubSystem: '<S2>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      VDCv2mk2_RIGIDAXLE
        (VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque,
         &rtb_Torque_L_Nm, &rtb_Product, &VDCv2mk2_B.Merge3);

      /* End of Outputs for SubSystem: '<S2>/RIGIDAXLE' */
    }

    /* End of If: '<S2>/If' */

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S2>/TT'
     */
    VDCv2mk2_B.Merge4 =
      VDCv2mk2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;

    /* Saturate: '<S2>/Saturation' */
    if (rtb_Torque_L_Nm > 27.0) {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = 27.0;
    } else if (rtb_Torque_L_Nm < 0.0) {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = 0.0;
    } else {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = rtb_Torque_L_Nm;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Saturate: '<S2>/Saturation1' */
    if (rtb_Product > 27.0) {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = 27.0;
    } else if (rtb_Product < 0.0) {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = 0.0;
    } else {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = rtb_Product;
    }

    /* End of Saturate: '<S2>/Saturation1' */
    /* End of Outputs for SubSystem: '<Root>/AUTOX1' */
  } else if ((VDCv2mk2_U.RacingMode == 5.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/ENDURANCE' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Lookup_n-D: '<S33>/SoC // Current' incorporates:
     *  Inport: '<Root>/SoC_High'
     */
    rtb_Product = look1_binlxpw(VDCv2mk2_U.SoC_High, rtCP_SoCCurrent_bp01Data,
      rtCP_SoCCurrent_tableData, 156U);

    /* MATLAB Function: '<S33>/enable regen' incorporates:
     *  Constant: '<S33>/98% SoC'
     *  Inport: '<Root>/Accumulator_Voltage'
     *  Inport: '<Root>/RL_rads_Motor'
     *  Inport: '<Root>/RR_rads_Motor'
     *  Inport: '<Root>/SoC_High'
     */
    rtb_Merge1_e = 0.0;
    rtb_max_regen_torque_RL = 0.0;
    regen_en = 0;
    if ((VDCv2mk2_U.SoC_High < 98.0) && (fmin(VDCv2mk2_U.RR_rads_Motor,
          VDCv2mk2_U.RL_rads_Motor) > 33.0)) {
      regen_en = 1;
    }

    if (VDCv2mk2_U.SoC_High >= 98.0) {
      regen_en = 0;
    }

    if (regen_en == 1) {
      rtb_Merge1_e = fmin(rtb_Product * VDCv2mk2_U.Accumulator_Voltage /
                          VDCv2mk2_U.RR_rads_Motor, 27.0);
      rtb_max_regen_torque_RL = fmin(rtb_Product *
        VDCv2mk2_U.Accumulator_Voltage / VDCv2mk2_U.RL_rads_Motor, 27.0);
    }

    /* Outport: '<Root>/Regenerative_Enable' incorporates:
     *  MATLAB Function: '<S33>/enable regen'
     */
    VDCv2mk2_Y.Regenerative_Enable = regen_en;

    /* MinMax: '<S33>/Min' */
    rtb_Product = fmin(rtb_max_regen_torque_RL, rtb_Merge1_e);

    /* MATLAB Function: '<S33>/state' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDCv2mk2_B.state = 1.0;
    if (VDCv2mk2_U.APPS1_Value < 0.45) {
      VDCv2mk2_B.state = 0.0;
    } else if (((!(VDCv2mk2_U.APPS1_Value >= 0.45)) || (!(VDCv2mk2_U.APPS1_Value
      <= 0.55))) && (VDCv2mk2_U.APPS1_Value > 0.55)) {
      VDCv2mk2_B.state = 2.0;
    }

    /* End of MATLAB Function: '<S33>/state' */

    /* MATLAB Function: '<S33>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     *  Outport: '<Root>/Regenerative_Enable'
     */
    rtb_Merge1_e = 0.0;
    rtb_max_regen_torque_RL = 0.0;
    if ((VDCv2mk2_B.state == 0.0) && (VDCv2mk2_Y.Regenerative_Enable == 1.0)) {
      rtb_Merge1_e = rtb_Product / 0.45 * VDCv2mk2_U.APPS1_Value - rtb_Product;
      rtb_max_regen_torque_RL = rtb_Merge1_e;
    }

    if (VDCv2mk2_B.state == 1.0) {
      rtb_Merge1_e = 0.0;
      rtb_max_regen_torque_RL = 0.0;
    }

    if (VDCv2mk2_B.state == 2.0) {
      rtb_Merge1_e = (VDCv2mk2_U.APPS1_Value - 0.55) / 0.44999999999999996 *
        27.0;
      rtb_max_regen_torque_RL = rtb_Merge1_e;
    }

    /* MinMax: '<S33>/Min1' incorporates:
     *  MATLAB Function: '<S33>/Torque demanded by the driver'
     */
    rtb_Product = fmin(rtb_Merge1_e, rtb_max_regen_torque_RL);

    /* If: '<S5>/If' incorporates:
     *  Inport: '<Root>/Disconnection_Mode'
     */
    if (VDCv2mk2_U.Disconnection_Mode == 1.0) {
      /* Outputs for IfAction SubSystem: '<S5>/TC+TV' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      /* MATLAB Function: '<S32>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [�]'
       *  Constant: '<Root>/Steering_wheel_sat [�]'
       *  Inport: '<Root>/SteeringSensor_Value'
       *  Outport: '<Root>/Regenerative_Enable'
       */
      rtb_Torque_L_Nm = fabs(VDCv2mk2_U.SteeringSensor_Value);
      if (rtb_Torque_L_Nm <= 10.0) {
        rtb_Torque_L_Nm = rtb_Product;
        rtb_Torque_R_Nm = rtb_Product;
      } else {
        rtb_Merge1_e = (rtb_Torque_L_Nm - 10.0) / 115.0 * rtb_Product;
        if ((VDCv2mk2_Y.Regenerative_Enable == 0.0) && (rtb_Merge1_e >
             rtb_Product)) {
          rtb_Merge1_e = rtb_Product;
        }

        if (VDCv2mk2_U.SteeringSensor_Value < -10.0) {
          rtb_Torque_L_Nm = rtb_Product - rtb_Merge1_e;
          rtb_Torque_R_Nm = rtb_Product;
        } else {
          rtb_Torque_L_Nm = rtb_Product;
          rtb_Torque_R_Nm = rtb_Product - rtb_Merge1_e;
        }
      }

      /* End of MATLAB Function: '<S32>/MATLAB Function' */

      /* MATLAB Function: '<S32>/TC 2024' incorporates:
       *  Constant: '<Root>/Max_Tyre_Slip'
       *  Inport: '<Root>/RL_Vel_ms_Wheel'
       *  Inport: '<Root>/RR_Vel_ms_Wheel'
       *  Inport: '<Root>/el_Vel_X'
       */
      if ((VDCv2mk2_U.el_Vel_X < 0.5) || (VDCv2mk2_U.RR_Vel_ms_Wheel < 0.5) ||
          (VDCv2mk2_U.RL_Vel_ms_Wheel < 0.5)) {
        /* Merge: '<S5>/Merge' */
        VDCv2mk2_B.Merge = rtb_Torque_R_Nm;

        /* Merge: '<S5>/Merge1' */
        VDCv2mk2_B.Merge1_f = rtb_Torque_L_Nm;
      } else {
        if ((VDCv2mk2_U.el_Vel_X == 0.0) || (VDCv2mk2_U.RR_Vel_ms_Wheel == 0.0))
        {
          rtb_Merge1_e = 1.0;
        } else {
          rtb_Merge1_e = VDCv2mk2_U.RR_Vel_ms_Wheel / VDCv2mk2_U.el_Vel_X;
        }

        if ((VDCv2mk2_U.el_Vel_X == 0.0) || (VDCv2mk2_U.RL_Vel_ms_Wheel == 0.0))
        {
          rtb_max_regen_torque_RL = 1.0;
        } else {
          rtb_max_regen_torque_RL = VDCv2mk2_U.RL_Vel_ms_Wheel /
            VDCv2mk2_U.el_Vel_X;
        }

        if (fmax(rtb_Merge1_e, rtb_max_regen_torque_RL) < 1.0) {
          /* Merge: '<S5>/Merge' */
          VDCv2mk2_B.Merge = rtb_Torque_R_Nm;

          /* Merge: '<S5>/Merge1' */
          VDCv2mk2_B.Merge1_f = rtb_Torque_L_Nm;
          VDCv2mk2_DW.correction_e = 0.0;
        } else if (VDCv2mk2_DW.correction_e == 0.0) {
          VDCv2mk2_DW.correction_e = 1.0;

          /* Merge: '<S5>/Merge' */
          VDCv2mk2_B.Merge = rtb_Torque_R_Nm - 0.060606060606060608;

          /* Merge: '<S5>/Merge1' */
          VDCv2mk2_B.Merge1_f = rtb_Torque_L_Nm - 0.060606060606060608;
        } else {
          VDCv2mk2_DW.correction_e++;

          /* Merge: '<S5>/Merge' */
          VDCv2mk2_B.Merge = rtb_Torque_R_Nm - (VDCv2mk2_DW.correction_e *
            VDCv2mk2_DW.correction_e * 0.030303030303030304 +
            0.030303030303030304 * VDCv2mk2_DW.correction_e);

          /* Merge: '<S5>/Merge1' */
          VDCv2mk2_B.Merge1_f = rtb_Torque_L_Nm - (VDCv2mk2_DW.correction_e *
            VDCv2mk2_DW.correction_e * 0.030303030303030304 +
            0.030303030303030304 * VDCv2mk2_DW.correction_e);
        }
      }

      /* End of MATLAB Function: '<S32>/TC 2024' */

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S32>/Constant1'
       *  SignalConversion generated from: '<S32>/tv_mode1'
       */
      VDCv2mk2_B.Merge3 = 1.0;

      /* End of Outputs for SubSystem: '<S5>/TC+TV' */
    } else if (VDCv2mk2_U.Disconnection_Mode == 2.0) {
      /* Outputs for IfAction SubSystem: '<S5>/RIGIDAXLE WITH TC' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* MinMax: '<S31>/Max' incorporates:
       *  Inport: '<Root>/RL_Vel_ms_Wheel'
       *  Inport: '<Root>/RR_Vel_ms_Wheel'
       */
      rtb_Merge1_e = fmax(VDCv2mk2_U.RR_Vel_ms_Wheel, VDCv2mk2_U.RL_Vel_ms_Wheel);

      /* MATLAB Function: '<S31>/Rigid Axle with TC 2024 ' incorporates:
       *  Constant: '<Root>/Max_Tyre_Slip'
       *  Inport: '<Root>/el_Vel_X'
       */
      if ((VDCv2mk2_U.el_Vel_X < 0.5) || (rtb_Merge1_e < 0.5)) {
        /* Merge: '<S5>/Merge' */
        VDCv2mk2_B.Merge = rtb_Product;

        /* Merge: '<S5>/Merge1' */
        VDCv2mk2_B.Merge1_f = rtb_Product;
      } else {
        if (VDCv2mk2_U.el_Vel_X == 0.0) {
          rtb_Merge1_e = 1.0;
        } else {
          rtb_Merge1_e /= VDCv2mk2_U.el_Vel_X;
        }

        if (rtb_Merge1_e < 1.0) {
          /* Merge: '<S5>/Merge' */
          VDCv2mk2_B.Merge = rtb_Product;

          /* Merge: '<S5>/Merge1' */
          VDCv2mk2_B.Merge1_f = rtb_Product;
          VDCv2mk2_DW.correction = 0.0;
        } else if (VDCv2mk2_DW.correction == 0.0) {
          VDCv2mk2_DW.correction = 1.0;

          /* Merge: '<S5>/Merge' */
          VDCv2mk2_B.Merge = rtb_Product - 0.060606060606060608;

          /* Merge: '<S5>/Merge1' */
          VDCv2mk2_B.Merge1_f = rtb_Product - 0.060606060606060608;
        } else {
          VDCv2mk2_DW.correction++;

          /* Merge: '<S5>/Merge' */
          VDCv2mk2_B.Merge = rtb_Product - (VDCv2mk2_DW.correction *
            VDCv2mk2_DW.correction * 0.030303030303030304 + 0.030303030303030304
            * VDCv2mk2_DW.correction);

          /* Merge: '<S5>/Merge1' */
          VDCv2mk2_B.Merge1_f = rtb_Product - (VDCv2mk2_DW.correction *
            VDCv2mk2_DW.correction * 0.030303030303030304 + 0.030303030303030304
            * VDCv2mk2_DW.correction);
        }
      }

      /* End of MATLAB Function: '<S31>/Rigid Axle with TC 2024 ' */

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S31>/Constant'
       *  SignalConversion generated from: '<S31>/tv_mode'
       */
      VDCv2mk2_B.Merge3 = 2.0;

      /* End of Outputs for SubSystem: '<S5>/RIGIDAXLE WITH TC' */
    } else {
      /* Outputs for IfAction SubSystem: '<S5>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      VDCv2mk2_RIGIDAXLE(rtb_Product, &VDCv2mk2_B.Merge2_l, &VDCv2mk2_B.Merge3_n,
                         &VDCv2mk2_B.Merge3);

      /* End of Outputs for SubSystem: '<S5>/RIGIDAXLE' */
    }

    /* End of If: '<S5>/If' */

    /* If: '<S34>/If' incorporates:
     *  Inport: '<Root>/el_Vel_X'
     */
    if (VDCv2mk2_U.el_Vel_X > 9.0) {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      /* Merge: '<S5>/Merge2' incorporates:
       *  Gain: '<S43>/Gain'
       */
      VDCv2mk2_B.Merge2_l = 0.25 * VDCv2mk2_B.Merge;

      /* Merge: '<S5>/Merge3' incorporates:
       *  Gain: '<S43>/Gain1'
       */
      VDCv2mk2_B.Merge3_n = 0.25 * VDCv2mk2_B.Merge1_f;

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      /* Merge: '<S5>/Merge3' incorporates:
       *  SignalConversion generated from: '<S44>/Tq_RL'
       */
      VDCv2mk2_B.Merge3_n = VDCv2mk2_B.Merge1_f;

      /* Merge: '<S5>/Merge2' incorporates:
       *  SignalConversion generated from: '<S44>/Tq_RR'
       */
      VDCv2mk2_B.Merge2_l = VDCv2mk2_B.Merge;

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem1' */
    }

    /* End of If: '<S34>/If' */

    /* Merge: '<Root>/Merge4' incorporates:
     *  SignalConversion generated from: '<S5>/TT'
     */
    VDCv2mk2_B.Merge4 = rtb_Product;

    /* Saturate: '<S5>/Saturation' */
    if (VDCv2mk2_B.Merge2_l > 27.0) {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = 27.0;
    } else if (VDCv2mk2_B.Merge2_l < -27.0) {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = -27.0;
    } else {
      /* Merge: '<Root>/Merge2' */
      VDCv2mk2_B.Merge2 = VDCv2mk2_B.Merge2_l;
    }

    /* End of Saturate: '<S5>/Saturation' */

    /* Saturate: '<S5>/Saturation1' */
    if (VDCv2mk2_B.Merge3_n > 27.0) {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = 27.0;
    } else if (VDCv2mk2_B.Merge3_n < -27.0) {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = -27.0;
    } else {
      /* Merge: '<Root>/Merge1' */
      VDCv2mk2_B.Merge1 = VDCv2mk2_B.Merge3_n;
    }

    /* End of Saturate: '<S5>/Saturation1' */
    /* End of Outputs for SubSystem: '<Root>/ENDURANCE' */
  }

  /* End of If: '<Root>/If' */

  /* MATLAB Function: '<Root>/Safety' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  if (rtb_LogicalOperator && (fmax(VDCv2mk2_U.RR_rads_Motor,
        VDCv2mk2_U.RL_rads_Motor) < 152788.74536821953)) {
    /* Saturate: '<Root>/Saturation' */
    if (VDCv2mk2_B.Merge2 > 27.0) {
      /* Outport: '<Root>/Torque_R' */
      VDCv2mk2_Y.Torque_R = 27.0;
    } else if (VDCv2mk2_B.Merge2 < -27.0) {
      /* Outport: '<Root>/Torque_R' */
      VDCv2mk2_Y.Torque_R = -27.0;
    } else {
      /* Outport: '<Root>/Torque_R' */
      VDCv2mk2_Y.Torque_R = VDCv2mk2_B.Merge2;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Saturate: '<Root>/Saturation1' */
    if (VDCv2mk2_B.Merge1 > 27.0) {
      /* Outport: '<Root>/Torque_L' */
      VDCv2mk2_Y.Torque_L = 27.0;
    } else if (VDCv2mk2_B.Merge1 < -27.0) {
      /* Outport: '<Root>/Torque_L' */
      VDCv2mk2_Y.Torque_L = -27.0;
    } else {
      /* Outport: '<Root>/Torque_L' */
      VDCv2mk2_Y.Torque_L = VDCv2mk2_B.Merge1;
    }

    /* End of Saturate: '<Root>/Saturation1' */
  } else {
    /* Outport: '<Root>/Torque_R' */
    VDCv2mk2_Y.Torque_R = 0.0;

    /* Outport: '<Root>/Torque_L' */
    VDCv2mk2_Y.Torque_L = 0.0;
  }

  /* End of MATLAB Function: '<Root>/Safety' */

  /* Outport: '<Root>/APPS_Implausibility' */
  VDCv2mk2_Y.APPS_Implausibility = rtb_Merge1_j;

  /* Outport: '<Root>/Torque_OK' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  VDCv2mk2_Y.Torque_OK = rtb_LogicalOperator;

  /* Outport: '<Root>/TV_Mode' */
  VDCv2mk2_Y.TV_Mode = VDCv2mk2_B.Merge3;

  /* Outport: '<Root>/BrakeLight_Control' incorporates:
   *  Constant: '<Root>/Brake_Light_Threshold'
   *  Inport: '<Root>/BrakePedal_Value'
   *  Inport: '<Root>/RacingMode'
   *  MATLAB Function: '<Root>/Brake_Light'
   */
  VDCv2mk2_Y.BrakeLight_Control = (((VDCv2mk2_U.RacingMode == 5.0) &&
    (VDCv2mk2_B.state == 0.0)) || ((VDCv2mk2_U.RacingMode != 5.0) &&
    (VDCv2mk2_U.BrakePedal_Value > 0.2)));

  /* Outport: '<Root>/Throttle_Torque' */
  VDCv2mk2_Y.Throttle_Torque = VDCv2mk2_B.Merge4;
}

/* Model update function */
static void VDCv2mk2_update(void)
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
  if (!(++VDCv2mk2_M->Timing.clockTick0)) {
    ++VDCv2mk2_M->Timing.clockTickH0;
  }

  VDCv2mk2_M->Timing.t[0] = VDCv2mk2_M->Timing.clockTick0 *
    VDCv2mk2_M->Timing.stepSize0 + VDCv2mk2_M->Timing.clockTickH0 *
    VDCv2mk2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void VDCv2mk2_initialize(void)
{
  /* Start for DataStoreMemory: '<S45>/Data Store Memory1' */
  VDCv2mk2_DW.ERROR_Counter = 0.0;

  /* Start for Atomic SubSystem: '<S3>/PowerLimitDetection' */
  /* Start for DataStoreMemory: '<S24>/Data Store Memory10' */
  VDCv2mk2_DW.A = 0.0;

  /* End of Start for SubSystem: '<S3>/PowerLimitDetection' */

  /* ConstCode for Outport: '<Root>/VDC_Max_Tyre_Slip' incorporates:
   *  Constant: '<Root>/Max_Tyre_Slip'
   */
  VDCv2mk2_Y.VDC_Max_Tyre_Slip = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/SKIDPAD' */
  /* SystemInitialize for IfAction SubSystem: '<S7>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S53>/Rigid Axle with TC 2024 ' */
  VDCv2mk2_DW.correction_h = 0.0;

  /* End of SystemInitialize for SubSystem: '<S7>/TC+TV' */
  /* End of SystemInitialize for SubSystem: '<Root>/SKIDPAD' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ACCELERATION' */
  /* SystemInitialize for IfAction SubSystem: '<S1>/RIGIDAXLE WITH TC' */
  VDCv2mk2_RIGIDAXLEWITHTC_Init(&VDCv2mk2_DW.RIGIDAXLEWITHTC);

  /* End of SystemInitialize for SubSystem: '<S1>/RIGIDAXLE WITH TC' */
  /* End of SystemInitialize for SubSystem: '<Root>/ACCELERATION' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/AUTOX1' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S18>/Rigid Axle with TC 2024 ' */
  VDCv2mk2_DW.correction_i = 0.0;

  /* End of SystemInitialize for SubSystem: '<S2>/TC+TV' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/RIGIDAXLE WITH TC' */
  VDCv2mk2_RIGIDAXLEWITHTC_Init(&VDCv2mk2_DW.RIGIDAXLEWITHTC_i);

  /* End of SystemInitialize for SubSystem: '<S2>/RIGIDAXLE WITH TC' */
  /* End of SystemInitialize for SubSystem: '<Root>/AUTOX1' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ENDURANCE' */
  /* SystemInitialize for IfAction SubSystem: '<S5>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S32>/TC 2024' */
  VDCv2mk2_DW.correction_e = 0.0;

  /* End of SystemInitialize for SubSystem: '<S5>/TC+TV' */

  /* SystemInitialize for IfAction SubSystem: '<S5>/RIGIDAXLE WITH TC' */
  /* SystemInitialize for MATLAB Function: '<S31>/Rigid Axle with TC 2024 ' */
  VDCv2mk2_DW.correction = 0.0;

  /* End of SystemInitialize for SubSystem: '<S5>/RIGIDAXLE WITH TC' */

  /* SystemInitialize for Merge: '<S5>/Merge' */
  VDCv2mk2_B.Merge = 0.0;

  /* SystemInitialize for Merge: '<S5>/Merge1' */
  VDCv2mk2_B.Merge1_f = 0.0;

  /* SystemInitialize for Merge: '<S5>/Merge2' */
  VDCv2mk2_B.Merge2_l = 0.0;

  /* SystemInitialize for Merge: '<S5>/Merge3' */
  VDCv2mk2_B.Merge3_n = 0.0;

  /* SystemInitialize for Outport: '<S5>/Pedal_State' */
  VDCv2mk2_B.state = 0.0;

  /* SystemInitialize for Outport: '<Root>/Regenerative_Enable' incorporates:
   *  Outport: '<S5>/regen_en'
   */
  VDCv2mk2_Y.Regenerative_Enable = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/ENDURANCE' */

  /* SystemInitialize for Merge: '<Root>/Merge2' */
  VDCv2mk2_B.Merge2 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge1' */
  VDCv2mk2_B.Merge1 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge3' */
  VDCv2mk2_B.Merge3 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge4' */
  VDCv2mk2_B.Merge4 = 0.0;
}

/* Model terminate function */
static void VDCv2mk2_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  VDCv2mk2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  VDCv2mk2_update();
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
  VDCv2mk2_initialize();
}

void MdlTerminate(void)
{
  VDCv2mk2_terminate();
}

/* Registration function */
RT_MODEL_VDCv2mk2_T *VDCv2mk2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)VDCv2mk2_M, 0,
                sizeof(RT_MODEL_VDCv2mk2_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = VDCv2mk2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "VDCv2mk2_M points to
       static memory which is guaranteed to be non-NULL" */
    VDCv2mk2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    VDCv2mk2_M->Timing.sampleTimes = (&VDCv2mk2_M->Timing.sampleTimesArray[0]);
    VDCv2mk2_M->Timing.offsetTimes = (&VDCv2mk2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    VDCv2mk2_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    VDCv2mk2_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(VDCv2mk2_M, &VDCv2mk2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = VDCv2mk2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    VDCv2mk2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(VDCv2mk2_M, 10.0);
  VDCv2mk2_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    VDCv2mk2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(VDCv2mk2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(VDCv2mk2_M->rtwLogInfo, (NULL));
    rtliSetLogT(VDCv2mk2_M->rtwLogInfo, "tout");
    rtliSetLogX(VDCv2mk2_M->rtwLogInfo, "");
    rtliSetLogXFinal(VDCv2mk2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(VDCv2mk2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(VDCv2mk2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(VDCv2mk2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(VDCv2mk2_M->rtwLogInfo, 1);
    rtliSetLogY(VDCv2mk2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(VDCv2mk2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(VDCv2mk2_M->rtwLogInfo, (NULL));
  }

  VDCv2mk2_M->solverInfoPtr = (&VDCv2mk2_M->solverInfo);
  VDCv2mk2_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&VDCv2mk2_M->solverInfo, 0.2);
  rtsiSetSolverMode(&VDCv2mk2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  VDCv2mk2_M->blockIO = ((void *) &VDCv2mk2_B);
  (void) memset(((void *) &VDCv2mk2_B), 0,
                sizeof(B_VDCv2mk2_T));

  /* states (dwork) */
  VDCv2mk2_M->dwork = ((void *) &VDCv2mk2_DW);
  (void) memset((void *)&VDCv2mk2_DW, 0,
                sizeof(DW_VDCv2mk2_T));

  /* external inputs */
  VDCv2mk2_M->inputs = (((void*)&VDCv2mk2_U));
  (void)memset(&VDCv2mk2_U, 0, sizeof(ExtU_VDCv2mk2_T));

  /* external outputs */
  VDCv2mk2_M->outputs = (&VDCv2mk2_Y);
  (void)memset(&VDCv2mk2_Y, 0, sizeof(ExtY_VDCv2mk2_T));

  /* Initialize Sizes */
  VDCv2mk2_M->Sizes.numContStates = (0);/* Number of continuous states */
  VDCv2mk2_M->Sizes.numY = (12);       /* Number of model outputs */
  VDCv2mk2_M->Sizes.numU = (34);       /* Number of model inputs */
  VDCv2mk2_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  VDCv2mk2_M->Sizes.numSampTimes = (1);/* Number of sample times */
  VDCv2mk2_M->Sizes.numBlocks = (225); /* Number of blocks */
  VDCv2mk2_M->Sizes.numBlockIO = (17); /* Number of block outputs */
  return VDCv2mk2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
