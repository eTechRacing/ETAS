/*
 * VDCv2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VDCv2".
 *
 * Model version              : 4.93
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sat Jun  8 15:15:34 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VDCv2.h"
#include "rtwtypes.h"
#include "VDCv2_private.h"
#include <math.h>
#include <string.h>
#include "look1_binlxpw.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_VDCv2_T VDCv2_B;

/* Block states (default storage) */
DW_VDCv2_T VDCv2_DW;

/* External inputs (root inport signals with default storage) */
ExtU_VDCv2_T VDCv2_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_VDCv2_T VDCv2_Y;

/* Real-time model */
static RT_MODEL_VDCv2_T VDCv2_M_;
RT_MODEL_VDCv2_T *const VDCv2_M = &VDCv2_M_;

/*
 * Output and update for action system:
 *    '<S23>/LimitReached'
 *    '<S26>/Latched Error'
 */
void VDCv2_LimitReached(real_T *rty_Out)
{
  /* SignalConversion generated from: '<S25>/Out ' incorporates:
   *  Constant: '<S25>/Constant'
   */
  *rty_Out = 1.0;
}

/*
 * System initialize for atomic system:
 *    '<S52>/Rigid Axle with TC 2024 '
 *    '<S17>/Rigid Axle with TC 2024 '
 *    '<S31>/TC 2024'
 */
void VDCv2_RigidAxlewithTC2024_Init(DW_RigidAxlewithTC2024_VDCv2_T *localDW)
{
  localDW->correction = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S52>/Rigid Axle with TC 2024 '
 *    '<S17>/Rigid Axle with TC 2024 '
 *    '<S31>/TC 2024'
 */
void VDCv2_RigidAxlewithTC2024(real_T rtu_MAX_SLR, real_T rtu_Throttle_Torque_R,
  real_T rtu_Throttle_Torque_L, real_T rtu_el_Vel_X, real_T rtu_Vel_ms_wheel_RR,
  real_T rtu_Vel_ms_wheel_RL, B_RigidAxlewithTC2024_VDCv2_T *localB,
  DW_RigidAxlewithTC2024_VDCv2_T *localDW)
{
  real_T x;
  real_T y;
  if ((rtu_el_Vel_X == 0.0) || (rtu_Vel_ms_wheel_RR == 0.0)) {
    x = 1.0;
  } else {
    x = rtu_Vel_ms_wheel_RR / rtu_el_Vel_X;
  }

  if ((rtu_el_Vel_X == 0.0) || (rtu_Vel_ms_wheel_RL == 0.0)) {
    y = 1.0;
  } else {
    y = rtu_Vel_ms_wheel_RL / rtu_el_Vel_X;
  }

  if (fmax(x, y) < rtu_MAX_SLR) {
    localB->Motor_Torque_RR = rtu_Throttle_Torque_R;
    localB->Motor_Torque_RL = rtu_Throttle_Torque_L;
    localDW->correction = 0.0;
  } else if (localDW->correction == 0.0) {
    localDW->correction = 1.0;
    localB->Motor_Torque_RR = rtu_Throttle_Torque_R - 0.060606060606060608;
    localB->Motor_Torque_RL = rtu_Throttle_Torque_L - 0.060606060606060608;
  } else {
    localDW->correction++;
    x = localDW->correction * localDW->correction * 0.030303030303030304 +
      0.030303030303030304 * localDW->correction;
    localB->Motor_Torque_RR = rtu_Throttle_Torque_R - x;
    localB->Motor_Torque_RL = rtu_Throttle_Torque_L - x;
  }
}

/*
 * Output and update for action system:
 *    '<S7>/RIGIDAXLE'
 *    '<S1>/RIGIDAXLE'
 *    '<S2>/RIGIDAXLE'
 *    '<S5>/RIGIDAXLE'
 */
void VDCv2_RIGIDAXLE(real_T rtu_Throttle_TorqueNm, real_T *rty_Tq_RR_FM4Nm0inf,
                     real_T *rty_Tq_RL_FM4Nm0inf, real_T *rty_tv_mode)
{
  /* SignalConversion generated from: '<S51>/Tq_RL_FM4 [Nm] (0,inf)' incorporates:
   *  MATLAB Function: '<S51>/Rigid Axle 2024 '
   */
  *rty_Tq_RL_FM4Nm0inf = rtu_Throttle_TorqueNm;

  /* SignalConversion generated from: '<S51>/Tq_RR_FM4 [Nm] (0,inf)' incorporates:
   *  MATLAB Function: '<S51>/Rigid Axle 2024 '
   */
  *rty_Tq_RR_FM4Nm0inf = rtu_Throttle_TorqueNm;

  /* SignalConversion generated from: '<S51>/tv_mode' incorporates:
   *  Constant: '<S51>/Constant'
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
    Throttle_Response = (rtu_AP - rtu_pedal_sat_down / rtu_pedal_sat_up) -
      rtu_pedal_sat_down;
  }

  localB->Throttle_Torque = Throttle_Response * rtu_max_torque;
}

/*
 * System initialize for action system:
 *    '<S1>/RIGIDAXLE WITH TC'
 *    '<S2>/RIGIDAXLE WITH TC'
 *    '<S5>/RIGIDAXLE WITH TC'
 */
void VDCv2_RIGIDAXLEWITHTC_Init(DW_RIGIDAXLEWITHTC_VDCv2_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S11>/Rigid Axle with TC 2024 ' */
  localDW->correction = 0.0;
}

/*
 * Output and update for action system:
 *    '<S1>/RIGIDAXLE WITH TC'
 *    '<S2>/RIGIDAXLE WITH TC'
 *    '<S5>/RIGIDAXLE WITH TC'
 */
void VDCv2_RIGIDAXLEWITHTC(real_T rtu_RR_Vel_ms_Wheelms, real_T
  rtu_RL_Vel_ms_Wheelms, real_T rtu_Throttle_TorqueNm, real_T rtu_MAX_SLR,
  real_T rtu_el_Vel_Xms, real_T *rty_Tq_RR_FM2Nm0inf, real_T
  *rty_Tq_RL_FM2Nm0inf, real_T *rty_tv_mode, DW_RIGIDAXLEWITHTC_VDCv2_T *localDW)
{
  real_T rtb_Max;

  /* MinMax: '<S11>/Max' */
  rtb_Max = fmax(rtu_RR_Vel_ms_Wheelms, rtu_RL_Vel_ms_Wheelms);

  /* MATLAB Function: '<S11>/Rigid Axle with TC 2024 ' */
  if ((rtu_el_Vel_Xms == 0.0) || (rtb_Max == 0.0)) {
    rtb_Max = 1.0;
  } else {
    rtb_Max /= rtu_el_Vel_Xms;
  }

  if (rtb_Max < rtu_MAX_SLR) {
    /* SignalConversion generated from: '<S11>/Tq_RR_FM2 [Nm] (0,inf)' */
    *rty_Tq_RR_FM2Nm0inf = rtu_Throttle_TorqueNm;

    /* SignalConversion generated from: '<S11>/Tq_RL_FM2 [Nm] (0,inf)' */
    *rty_Tq_RL_FM2Nm0inf = rtu_Throttle_TorqueNm;
    localDW->correction = 0.0;
  } else if (localDW->correction == 0.0) {
    localDW->correction = 1.0;

    /* SignalConversion generated from: '<S11>/Tq_RR_FM2 [Nm] (0,inf)' */
    *rty_Tq_RR_FM2Nm0inf = rtu_Throttle_TorqueNm - 0.060606060606060608;

    /* SignalConversion generated from: '<S11>/Tq_RL_FM2 [Nm] (0,inf)' */
    *rty_Tq_RL_FM2Nm0inf = rtu_Throttle_TorqueNm - 0.060606060606060608;
  } else {
    localDW->correction++;
    rtb_Max = rtu_Throttle_TorqueNm - (localDW->correction * localDW->correction
      * 0.030303030303030304 + 0.030303030303030304 * localDW->correction);

    /* SignalConversion generated from: '<S11>/Tq_RR_FM2 [Nm] (0,inf)' */
    *rty_Tq_RR_FM2Nm0inf = rtb_Max;

    /* SignalConversion generated from: '<S11>/Tq_RL_FM2 [Nm] (0,inf)' */
    *rty_Tq_RL_FM2Nm0inf = rtb_Max;
  }

  /* End of MATLAB Function: '<S11>/Rigid Axle with TC 2024 ' */

  /* SignalConversion generated from: '<S11>/tv_mode' incorporates:
   *  Constant: '<S11>/Constant'
   */
  *rty_tv_mode = 2.0;
}

/* Model output function */
static void VDCv2_output(void)
{
  real_T rtb_Merge1_e;
  real_T rtb_Merge1_j;
  real_T rtb_Product;
  real_T rtb_SoCCurrent;
  real_T rtb_tq_RL;
  int32_T regen_en;
  boolean_T rtb_LogicalOperator;

  /* If: '<S44>/If' incorporates:
   *  Abs: '<S44>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S44>/Sum'
   */
  if (fabs(VDCv2_U.APPS1_Value - VDCv2_U.APPS2_Value) > 0.1) {
    /* Outputs for IfAction SubSystem: '<S44>/Imp' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    /* Sum: '<S47>/Add' incorporates:
     *  Constant: '<S47>/Constant'
     *  DataStoreRead: '<S47>/Data Store Read'
     */
    rtb_Merge1_j = VDCv2_DW.ERROR_Counter + 1.0;

    /* End of Outputs for SubSystem: '<S44>/Imp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S44>/Not Imp' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* SignalConversion generated from: '<S48>/0' incorporates:
     *  Constant: '<S48>/Constant'
     */
    rtb_Merge1_j = 0.0;

    /* End of Outputs for SubSystem: '<S44>/Not Imp' */
  }

  /* End of If: '<S44>/If' */

  /* DataStoreWrite: '<S44>/Data Store Write' */
  VDCv2_DW.ERROR_Counter = rtb_Merge1_j;

  /* Outputs for IfAction SubSystem: '<S44>/Signal_OK' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/Signal_Failure' incorporates:
   *  ActionPort: '<S49>/Action Port'
   */
  /* If: '<S44>/If1' incorporates:
   *  Constant: '<S44>/Number_of_Periods'
   *  SignalConversion generated from: '<S49>/Out1'
   *  SignalConversion generated from: '<S50>/Out1'
   */
  rtb_Merge1_j = (rtb_Merge1_j > 4.0);

  /* End of Outputs for SubSystem: '<S44>/Signal_Failure' */
  /* End of Outputs for SubSystem: '<S44>/Signal_OK' */

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S45>/Constant'
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/NOT'
   *  RelationalOperator: '<S45>/Compare'
   */
  rtb_LogicalOperator = (VDCv2_U.Shutdown_PackageIntck && VDCv2_U.TorqueEnable &&
    (!VDCv2_U.CriticalDisconnection) && (VDCv2_U.Car_State == 15.0) &&
    (!(rtb_Merge1_j != 0.0)));

  /* Product: '<S3>/Product' incorporates:
   *  Inport: '<Root>/Accumulator_Current'
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  rtb_Product = VDCv2_U.Accumulator_Voltage * VDCv2_U.Accumulator_Current;

  /* Outport: '<Root>/Power' incorporates:
   *  Constant: '<S24>/0-100 to 0-2'
   *  Product: '<S24>/Divide5'
   */
  VDCv2_Y.Power = rtb_Product / 1000.0;

  /* Outputs for Atomic SubSystem: '<S3>/PowerLimitDetection' */
  /* If: '<S23>/If' incorporates:
   *  DataStoreRead: '<S23>/Data Store Read30'
   *  If: '<S26>/If'
   *  SignalConversion generated from: '<S23>/Power'
   */
  if (rtb_Product >= 80000.0) {
    /* Outputs for IfAction SubSystem: '<S23>/LimitReached' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    VDCv2_LimitReached(&rtb_Merge1_e);

    /* End of Outputs for SubSystem: '<S23>/LimitReached' */

    /* Outputs for IfAction SubSystem: '<S23>/OK_OrLatch' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
  } else if (VDCv2_DW.A > 0.0) {
    /* Outputs for IfAction SubSystem: '<S26>/Latched Error' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* If: '<S26>/If' */
    VDCv2_LimitReached(&rtb_Merge1_e);

    /* End of Outputs for SubSystem: '<S26>/Latched Error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/OK' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* If: '<S26>/If' incorporates:
     *  Constant: '<S28>/Constant'
     *  SignalConversion generated from: '<S28>/Out '
     */
    rtb_Merge1_e = 0.0;

    /* End of Outputs for SubSystem: '<S26>/OK' */

    /* End of Outputs for SubSystem: '<S23>/OK_OrLatch' */
  }

  /* End of If: '<S23>/If' */

  /* DataStoreWrite: '<S23>/Data Store Write20' */
  VDCv2_DW.A = rtb_Merge1_e;

  /* End of Outputs for SubSystem: '<S3>/PowerLimitDetection' */

  /* Outport: '<Root>/PowerLimitReached' */
  VDCv2_Y.PowerLimitReached = rtb_Merge1_e;

  /* Outputs for Atomic SubSystem: '<S3>/PowerLimitDetection' */
  /* Outport: '<Root>/PowerMean500ms' incorporates:
   *  SignalConversion generated from: '<S23>/Power'
   */
  VDCv2_Y.PowerMean500ms = rtb_Product;

  /* End of Outputs for SubSystem: '<S3>/PowerLimitDetection' */

  /* If: '<Root>/If' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Inport: '<Root>/RacingMode'
   */
  if ((VDCv2_U.RacingMode == 1.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/WORKSHOP' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* MATLAB Function: '<S9>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    rtb_Product = 0.0;
    if (!(VDCv2_U.APPS1_Value <= 0.0)) {
      if (VDCv2_U.APPS1_Value >= 1.0) {
        rtb_Product = 1.0;
      } else if ((VDCv2_U.APPS1_Value >= 0.0) && (VDCv2_U.APPS1_Value <= 1.0)) {
        rtb_Product = VDCv2_U.APPS1_Value;
      }
    }

    rtb_Product = rtb_Product * 27.0 / 5.5;

    /* End of MATLAB Function: '<S9>/Torque demanded by the driver' */

    /* Merge: '<Root>/Merge1' incorporates:
     *  SignalConversion generated from: '<S9>/TQ_L'
     */
    VDCv2_B.Merge1 = rtb_Product;

    /* Merge: '<Root>/Merge2' incorporates:
     *  SignalConversion generated from: '<S9>/TQ_R'
     */
    VDCv2_B.Merge2 = rtb_Product;

    /* End of Outputs for SubSystem: '<Root>/WORKSHOP' */
  } else if ((VDCv2_U.RacingMode == 2.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/SKIDPAD' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* MATLAB Function: '<S7>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDCv2_Torquedemandedbythedriver(VDCv2_U.APPS1_Value, 0.0, 1.0, 27.0,
      &VDCv2_B.sf_Torquedemandedbythedriver_m);

    /* If: '<S7>/If' incorporates:
     *  Inport: '<Root>/Disconnection_Mode'
     */
    if (VDCv2_U.Disconnection_Mode == 1.0) {
      /* Outputs for IfAction SubSystem: '<S7>/TC+TV' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      /* MATLAB Function: '<S52>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [º]'
       *  Constant: '<Root>/Steering_wheel_sat [º]'
       *  Inport: '<Root>/SteeringSensor_Value'
       *  Inport: '<Root>/el_SlipAngle'
       */
      rtb_Product = fabs(VDCv2_U.SteeringSensor_Value);
      if (rtb_Product <= 10.0) {
        rtb_Merge1_e = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
        rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
      } else if (fabs(VDCv2_U.el_SlipAngle) > 0.10471975511965977) {
        rtb_Merge1_e = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
        rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
      } else {
        rtb_Product = (rtb_Product - 10.0) / 115.0 *
          VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
        if (rtb_Product > VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque)
        {
          rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
        }

        if (VDCv2_U.SteeringSensor_Value < -10.0) {
          rtb_Merge1_e = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque
            - rtb_Product;
          rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
        } else {
          rtb_Merge1_e = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
          rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque -
            rtb_Product;
        }
      }

      /* End of MATLAB Function: '<S52>/MATLAB Function' */

      /* MATLAB Function: '<S52>/Rigid Axle with TC 2024 ' incorporates:
       *  Constant: '<Root>/Max_Tyre_Slip'
       *  Inport: '<Root>/RL_Vel_ms_Wheel'
       *  Inport: '<Root>/RR_Vel_ms_Wheel'
       *  Inport: '<Root>/el_Vel_X'
       */
      VDCv2_RigidAxlewithTC2024(1.0, rtb_Product, rtb_Merge1_e, VDCv2_U.el_Vel_X,
        VDCv2_U.RR_Vel_ms_Wheel, VDCv2_U.RL_Vel_ms_Wheel,
        &VDCv2_B.sf_RigidAxlewithTC2024, &VDCv2_DW.sf_RigidAxlewithTC2024);

      /* Merge: '<Root>/Merge1' incorporates:
       *  SignalConversion generated from: '<S52>/Tq_RL_FM1 [Nm] (0,inf)'
       */
      VDCv2_B.Merge1 = VDCv2_B.sf_RigidAxlewithTC2024.Motor_Torque_RL;

      /* Merge: '<Root>/Merge2' incorporates:
       *  SignalConversion generated from: '<S52>/Tq_RR_FM1 [Nm] (0,inf)'
       */
      VDCv2_B.Merge2 = VDCv2_B.sf_RigidAxlewithTC2024.Motor_Torque_RR;

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S52>/Constant'
       *  SignalConversion generated from: '<S52>/tv_mode'
       */
      VDCv2_B.Merge3 = 1.0;

      /* End of Outputs for SubSystem: '<S7>/TC+TV' */
    } else if (VDCv2_U.Disconnection_Mode >= 3.0) {
      /* Outputs for IfAction SubSystem: '<S7>/TV with TC OFF ' incorporates:
       *  ActionPort: '<S53>/Action Port'
       */
      /* MATLAB Function: '<S53>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [º]'
       *  Constant: '<Root>/Steering_wheel_sat [º]'
       *  Inport: '<Root>/SteeringSensor_Value'
       */
      rtb_Product = fabs(VDCv2_U.SteeringSensor_Value);
      if (rtb_Product <= 10.0) {
        /* Merge: '<Root>/Merge1' */
        VDCv2_B.Merge1 = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;

        /* Merge: '<Root>/Merge2' */
        VDCv2_B.Merge2 = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
      } else {
        rtb_Product = (rtb_Product - 10.0) / 115.0 *
          VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
        if (rtb_Product > VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque)
        {
          rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
        }

        if (VDCv2_U.SteeringSensor_Value < -10.0) {
          /* Merge: '<Root>/Merge1' */
          VDCv2_B.Merge1 =
            VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque - rtb_Product;

          /* Merge: '<Root>/Merge2' */
          VDCv2_B.Merge2 =
            VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;
        } else {
          /* Merge: '<Root>/Merge1' */
          VDCv2_B.Merge1 =
            VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque;

          /* Merge: '<Root>/Merge2' */
          VDCv2_B.Merge2 =
            VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque - rtb_Product;
        }
      }

      /* End of MATLAB Function: '<S53>/MATLAB Function' */

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S53>/Constant'
       *  SignalConversion generated from: '<S53>/tv_mode'
       */
      VDCv2_B.Merge3 = 3.0;

      /* End of Outputs for SubSystem: '<S7>/TV with TC OFF ' */
    } else {
      /* Outputs for IfAction SubSystem: '<S7>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S51>/Action Port'
       */
      VDCv2_RIGIDAXLE(VDCv2_B.sf_Torquedemandedbythedriver_m.Throttle_Torque,
                      &VDCv2_B.Merge2, &VDCv2_B.Merge1, &VDCv2_B.Merge3);

      /* End of Outputs for SubSystem: '<S7>/RIGIDAXLE' */
    }

    /* End of If: '<S7>/If' */
    /* End of Outputs for SubSystem: '<Root>/SKIDPAD' */
  } else if ((VDCv2_U.RacingMode == 3.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/ACCELERATION' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* MATLAB Function: '<S1>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDCv2_Torquedemandedbythedriver(VDCv2_U.APPS1_Value, 0.0, 1.0, 27.0,
      &VDCv2_B.sf_Torquedemandedbythedriver_k);

    /* If: '<S1>/If' incorporates:
     *  Constant: '<Root>/Max_Tyre_Slip'
     *  Inport: '<Root>/Disconnection_Mode'
     *  Inport: '<Root>/RL_Vel_ms_Wheel'
     *  Inport: '<Root>/RR_Vel_ms_Wheel'
     *  Inport: '<Root>/el_Vel_X'
     */
    if (VDCv2_U.Disconnection_Mode >= 2.0) {
      /* Outputs for IfAction SubSystem: '<S1>/RIGIDAXLE WITH TC' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      VDCv2_RIGIDAXLEWITHTC(VDCv2_U.RR_Vel_ms_Wheel, VDCv2_U.RL_Vel_ms_Wheel,
                            VDCv2_B.sf_Torquedemandedbythedriver_k.Throttle_Torque,
                            1.0, VDCv2_U.el_Vel_X, &VDCv2_B.Merge2,
                            &VDCv2_B.Merge1, &VDCv2_B.Merge3,
                            &VDCv2_DW.RIGIDAXLEWITHTC);

      /* End of Outputs for SubSystem: '<S1>/RIGIDAXLE WITH TC' */
    } else {
      /* Outputs for IfAction SubSystem: '<S1>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      VDCv2_RIGIDAXLE(VDCv2_B.sf_Torquedemandedbythedriver_k.Throttle_Torque,
                      &VDCv2_B.Merge2, &VDCv2_B.Merge1, &VDCv2_B.Merge3);

      /* End of Outputs for SubSystem: '<S1>/RIGIDAXLE' */
    }

    /* End of If: '<S1>/If' */
    /* End of Outputs for SubSystem: '<Root>/ACCELERATION' */
  } else if ((VDCv2_U.RacingMode == 4.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/AUTOX1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MATLAB Function: '<S2>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/AP_sat_down'
     *  Constant: '<Root>/AP_sat_up'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDCv2_Torquedemandedbythedriver(VDCv2_U.APPS1_Value, 0.0, 1.0, 27.0,
      &VDCv2_B.sf_Torquedemandedbythedriver_a);

    /* If: '<S2>/If' incorporates:
     *  Constant: '<Root>/Max_Tyre_Slip'
     *  Inport: '<Root>/Disconnection_Mode'
     *  Inport: '<Root>/RL_Vel_ms_Wheel'
     *  Inport: '<Root>/RR_Vel_ms_Wheel'
     *  Inport: '<Root>/el_Vel_X'
     */
    if (VDCv2_U.Disconnection_Mode == 1.0) {
      /* Outputs for IfAction SubSystem: '<S2>/TC+TV' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [º]'
       *  Constant: '<Root>/Steering_wheel_sat [º]'
       *  Inport: '<Root>/SteeringSensor_Value'
       */
      rtb_Product = fabs(VDCv2_U.SteeringSensor_Value);
      if (rtb_Product <= 10.0) {
        rtb_Merge1_e = VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
      } else {
        rtb_Product = (rtb_Product - 10.0) / 115.0 *
          VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        if (rtb_Product > VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque)
        {
          rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        }

        if (VDCv2_U.SteeringSensor_Value < -10.0) {
          rtb_Merge1_e = VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
          rtb_Product += VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        } else {
          rtb_Merge1_e = VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque
            + rtb_Product;
          rtb_Product = VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque;
        }
      }

      /* End of MATLAB Function: '<S17>/MATLAB Function' */

      /* MATLAB Function: '<S17>/Rigid Axle with TC 2024 ' incorporates:
       *  Constant: '<Root>/Max_Tyre_Slip'
       *  Inport: '<Root>/RL_Vel_ms_Wheel'
       *  Inport: '<Root>/RR_Vel_ms_Wheel'
       *  Inport: '<Root>/el_Vel_X'
       */
      VDCv2_RigidAxlewithTC2024(1.0, rtb_Product, rtb_Merge1_e, VDCv2_U.el_Vel_X,
        VDCv2_U.RR_Vel_ms_Wheel, VDCv2_U.RL_Vel_ms_Wheel,
        &VDCv2_B.sf_RigidAxlewithTC2024_o, &VDCv2_DW.sf_RigidAxlewithTC2024_o);

      /* Merge: '<Root>/Merge1' incorporates:
       *  SignalConversion generated from: '<S17>/Tq_RL_FM1 [Nm] (0,inf)'
       */
      VDCv2_B.Merge1 = VDCv2_B.sf_RigidAxlewithTC2024_o.Motor_Torque_RL;

      /* Merge: '<Root>/Merge2' incorporates:
       *  SignalConversion generated from: '<S17>/Tq_RR_FM1 [Nm] (0,inf)'
       */
      VDCv2_B.Merge2 = VDCv2_B.sf_RigidAxlewithTC2024_o.Motor_Torque_RR;

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S17>/Constant'
       *  SignalConversion generated from: '<S17>/tv_mode'
       */
      VDCv2_B.Merge3 = 1.0;

      /* End of Outputs for SubSystem: '<S2>/TC+TV' */
    } else if (VDCv2_U.Disconnection_Mode == 2.0) {
      /* Outputs for IfAction SubSystem: '<S2>/RIGIDAXLE WITH TC' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      VDCv2_RIGIDAXLEWITHTC(VDCv2_U.RR_Vel_ms_Wheel, VDCv2_U.RL_Vel_ms_Wheel,
                            VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque,
                            1.0, VDCv2_U.el_Vel_X, &VDCv2_B.Merge2,
                            &VDCv2_B.Merge1, &VDCv2_B.Merge3,
                            &VDCv2_DW.RIGIDAXLEWITHTC_i);

      /* End of Outputs for SubSystem: '<S2>/RIGIDAXLE WITH TC' */
    } else {
      /* Outputs for IfAction SubSystem: '<S2>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      VDCv2_RIGIDAXLE(VDCv2_B.sf_Torquedemandedbythedriver_a.Throttle_Torque,
                      &VDCv2_B.Merge2, &VDCv2_B.Merge1, &VDCv2_B.Merge3);

      /* End of Outputs for SubSystem: '<S2>/RIGIDAXLE' */
    }

    /* End of If: '<S2>/If' */
    /* End of Outputs for SubSystem: '<Root>/AUTOX1' */
  } else if ((VDCv2_U.RacingMode == 5.0) && rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<Root>/ENDURANCE' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Lookup_n-D: '<S32>/SoC // Current' incorporates:
     *  Inport: '<Root>/SoC_High'
     */
    rtb_SoCCurrent = look1_binlxpw(VDCv2_U.SoC_High, rtCP_SoCCurrent_bp01Data,
      rtCP_SoCCurrent_tableData, 156U);

    /* MATLAB Function: '<S32>/enable regen' incorporates:
     *  Constant: '<S32>/98% SoC'
     *  Inport: '<Root>/RL_rads_Motor'
     *  Inport: '<Root>/RR_rads_Motor'
     *  Inport: '<Root>/SoC_High'
     */
    rtb_Product = 0.0;
    rtb_Merge1_e = 0.0;
    regen_en = 0;
    if (VDCv2_U.SoC_High < 98.0) {
      regen_en = 1;
    }

    if (VDCv2_U.SoC_High >= 98.0) {
      regen_en = 0;
    }

    if (regen_en == 1) {
      rtb_Product = rtb_SoCCurrent * 0.0 / VDCv2_U.RR_rads_Motor;
      rtb_Merge1_e = rtb_SoCCurrent * 0.0 / VDCv2_U.RL_rads_Motor;
    }

    /* MATLAB Function: '<S32>/state' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Inport: '<Root>/APPS1_Value'
     */
    VDCv2_B.state = 1.0;
    if (VDCv2_U.APPS1_Value < 0.45) {
      VDCv2_B.state = 0.0;
    } else if (((!(VDCv2_U.APPS1_Value >= 0.45)) || (!(VDCv2_U.APPS1_Value <=
                  0.5))) && (VDCv2_U.APPS1_Value > 0.5)) {
      VDCv2_B.state = 2.0;
    }

    /* End of MATLAB Function: '<S32>/state' */

    /* MATLAB Function: '<S32>/Torque demanded by the driver' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Max_Motor_Torque_Rear [Nm]'
     *  Inport: '<Root>/APPS1_Value'
     *  MATLAB Function: '<S32>/enable regen'
     *  MinMax: '<S32>/Min'
     */
    rtb_SoCCurrent = 0.0;
    rtb_tq_RL = 0.0;
    if ((VDCv2_B.state == 0.0) && (regen_en == 1)) {
      rtb_SoCCurrent = VDCv2_U.APPS1_Value / 0.45 * -fmin(rtb_Merge1_e,
        rtb_Product);
      rtb_tq_RL = rtb_SoCCurrent;
    }

    if (VDCv2_B.state == 1.0) {
      rtb_SoCCurrent = 0.0;
      rtb_tq_RL = 0.0;
    }

    if (VDCv2_B.state == 2.0) {
      rtb_SoCCurrent = (VDCv2_U.APPS1_Value - 0.5) * 27.0;
      rtb_tq_RL = rtb_SoCCurrent;
    }

    /* MinMax: '<S32>/Min1' incorporates:
     *  MATLAB Function: '<S32>/Torque demanded by the driver'
     */
    rtb_Merge1_e = fmin(rtb_SoCCurrent, rtb_tq_RL);

    /* If: '<S5>/If' incorporates:
     *  Constant: '<Root>/Max_Tyre_Slip'
     *  Inport: '<Root>/Disconnection_Mode'
     *  Inport: '<Root>/RL_Vel_ms_Wheel'
     *  Inport: '<Root>/RR_Vel_ms_Wheel'
     *  Inport: '<Root>/el_Vel_X'
     */
    if (VDCv2_U.Disconnection_Mode == 1.0) {
      /* Outputs for IfAction SubSystem: '<S5>/TC+TV' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* MATLAB Function: '<S31>/MATLAB Function' incorporates:
       *  Constant: '<Root>/Maximum_Steering_angle [º]'
       *  Constant: '<Root>/Steering_wheel_sat [º]'
       *  Inport: '<Root>/SteeringSensor_Value'
       *  Inport: '<Root>/el_SlipAngle'
       *  MATLAB Function: '<S32>/enable regen'
       */
      if (fabs(VDCv2_U.SteeringSensor_Value) <= 10.0) {
        rtb_SoCCurrent = rtb_Merge1_e;
      } else if (fabs(VDCv2_U.el_SlipAngle) > 0.10471975511965977) {
        rtb_SoCCurrent = rtb_Merge1_e;
      } else {
        rtb_Product = (fabs(VDCv2_U.SteeringSensor_Value) - 10.0) / 115.0 *
          rtb_Merge1_e;
        if ((regen_en == 0) && (rtb_Product > rtb_Merge1_e)) {
          rtb_Product = rtb_Merge1_e;
        }

        if (VDCv2_U.SteeringSensor_Value < -10.0) {
          rtb_SoCCurrent = rtb_Merge1_e - rtb_Product;
        } else {
          rtb_SoCCurrent = rtb_Merge1_e;
          rtb_Merge1_e -= rtb_Product;
        }
      }

      /* End of MATLAB Function: '<S31>/MATLAB Function' */

      /* MATLAB Function: '<S31>/TC 2024' incorporates:
       *  Constant: '<Root>/Max_Tyre_Slip'
       *  Inport: '<Root>/RL_Vel_ms_Wheel'
       *  Inport: '<Root>/RR_Vel_ms_Wheel'
       *  Inport: '<Root>/el_Vel_X'
       */
      VDCv2_RigidAxlewithTC2024(1.0, rtb_Merge1_e, rtb_SoCCurrent,
        VDCv2_U.el_Vel_X, VDCv2_U.RR_Vel_ms_Wheel, VDCv2_U.RL_Vel_ms_Wheel,
        &VDCv2_B.sf_TC2024, &VDCv2_DW.sf_TC2024);

      /* Merge: '<S5>/Merge1' incorporates:
       *  SignalConversion generated from: '<S31>/Tq_RL_FM1 [Nm] (0,inf)'
       */
      VDCv2_B.Merge1_f = VDCv2_B.sf_TC2024.Motor_Torque_RL;

      /* Merge: '<S5>/Merge' incorporates:
       *  SignalConversion generated from: '<S31>/Tq_RR_FM1 [Nm] (0,inf)'
       */
      VDCv2_B.Merge = VDCv2_B.sf_TC2024.Motor_Torque_RR;

      /* Merge: '<Root>/Merge3' incorporates:
       *  Constant: '<S31>/Constant1'
       *  SignalConversion generated from: '<S31>/tv_mode1'
       */
      VDCv2_B.Merge3 = 1.0;

      /* End of Outputs for SubSystem: '<S5>/TC+TV' */
    } else if (VDCv2_U.Disconnection_Mode == 2.0) {
      /* Outputs for IfAction SubSystem: '<S5>/RIGIDAXLE WITH TC' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      VDCv2_RIGIDAXLEWITHTC(VDCv2_U.RR_Vel_ms_Wheel, VDCv2_U.RL_Vel_ms_Wheel,
                            rtb_Merge1_e, 1.0, VDCv2_U.el_Vel_X, &VDCv2_B.Merge,
                            &VDCv2_B.Merge1_f, &VDCv2_B.Merge3,
                            &VDCv2_DW.RIGIDAXLEWITHTC_j);

      /* End of Outputs for SubSystem: '<S5>/RIGIDAXLE WITH TC' */
    } else {
      /* Outputs for IfAction SubSystem: '<S5>/RIGIDAXLE' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      VDCv2_RIGIDAXLE(rtb_Merge1_e, &VDCv2_B.Merge2, &VDCv2_B.Merge1,
                      &VDCv2_B.Merge3);

      /* End of Outputs for SubSystem: '<S5>/RIGIDAXLE' */
    }

    /* End of If: '<S5>/If' */

    /* If: '<S33>/If' incorporates:
     *  Inport: '<Root>/el_Vel_X'
     */
    if (VDCv2_U.el_Vel_X > 9.0) {
      /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* Merge: '<Root>/Merge2' incorporates:
       *  Gain: '<S42>/Gain'
       */
      VDCv2_B.Merge2 = 0.25 * VDCv2_B.Merge;

      /* Merge: '<Root>/Merge1' incorporates:
       *  Gain: '<S42>/Gain1'
       */
      VDCv2_B.Merge1 = 0.25 * VDCv2_B.Merge1_f;

      /* End of Outputs for SubSystem: '<S33>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      /* Merge: '<Root>/Merge1' incorporates:
       *  SignalConversion generated from: '<S43>/Tq_RL'
       */
      VDCv2_B.Merge1 = VDCv2_B.Merge1_f;

      /* Merge: '<Root>/Merge2' incorporates:
       *  SignalConversion generated from: '<S43>/Tq_RR'
       */
      VDCv2_B.Merge2 = VDCv2_B.Merge;

      /* End of Outputs for SubSystem: '<S33>/If Action Subsystem1' */
    }

    /* End of If: '<S33>/If' */
    /* End of Outputs for SubSystem: '<Root>/ENDURANCE' */
  }

  /* End of If: '<Root>/If' */

  /* Outport: '<Root>/Torque_R_out' */
  VDCv2_Y.Torque_R_out = VDCv2_B.Merge1;

  /* Outport: '<Root>/Torque_L_out' */
  VDCv2_Y.Torque_L_out = VDCv2_B.Merge2;

  /* Outport: '<Root>/APPS_Implausibility' */
  VDCv2_Y.APPS_Implausibility = rtb_Merge1_j;

  /* Outport: '<Root>/Torque_OK' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  VDCv2_Y.Torque_OK = rtb_LogicalOperator;

  /* Outport: '<Root>/TV_Mode' */
  VDCv2_Y.TV_Mode = VDCv2_B.Merge3;

  /* Outport: '<Root>/BrakeLight_Control' incorporates:
   *  Constant: '<Root>/Brake_Light_Threshold'
   *  Inport: '<Root>/BrakePedal_Value'
   *  Inport: '<Root>/RacingMode'
   *  MATLAB Function: '<Root>/Brake_Light'
   */
  VDCv2_Y.BrakeLight_Control = (((VDCv2_U.RacingMode == 5.0) && (VDCv2_B.state ==
    0.0)) || ((VDCv2_U.RacingMode != 5.0) && (VDCv2_U.BrakePedal_Value > 0.2)));
}

/* Model update function */
static void VDCv2_update(void)
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
  if (!(++VDCv2_M->Timing.clockTick0)) {
    ++VDCv2_M->Timing.clockTickH0;
  }

  VDCv2_M->Timing.t[0] = VDCv2_M->Timing.clockTick0 * VDCv2_M->Timing.stepSize0
    + VDCv2_M->Timing.clockTickH0 * VDCv2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void VDCv2_initialize(void)
{
  /* Start for DataStoreMemory: '<S44>/Data Store Memory1' */
  VDCv2_DW.ERROR_Counter = 0.0;

  /* Start for Atomic SubSystem: '<S3>/PowerLimitDetection' */
  /* Start for DataStoreMemory: '<S23>/Data Store Memory10' */
  VDCv2_DW.A = 0.0;

  /* End of Start for SubSystem: '<S3>/PowerLimitDetection' */

  /* ConstCode for Outport: '<Root>/VDC_Max_Tyre_Slip' incorporates:
   *  Constant: '<Root>/Max_Tyre_Slip'
   */
  VDCv2_Y.VDC_Max_Tyre_Slip = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/SKIDPAD' */
  /* SystemInitialize for IfAction SubSystem: '<S7>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S52>/Rigid Axle with TC 2024 ' */
  VDCv2_RigidAxlewithTC2024_Init(&VDCv2_DW.sf_RigidAxlewithTC2024);

  /* End of SystemInitialize for SubSystem: '<S7>/TC+TV' */
  /* End of SystemInitialize for SubSystem: '<Root>/SKIDPAD' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ACCELERATION' */
  /* SystemInitialize for IfAction SubSystem: '<S1>/RIGIDAXLE WITH TC' */
  VDCv2_RIGIDAXLEWITHTC_Init(&VDCv2_DW.RIGIDAXLEWITHTC);

  /* End of SystemInitialize for SubSystem: '<S1>/RIGIDAXLE WITH TC' */
  /* End of SystemInitialize for SubSystem: '<Root>/ACCELERATION' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/AUTOX1' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S17>/Rigid Axle with TC 2024 ' */
  VDCv2_RigidAxlewithTC2024_Init(&VDCv2_DW.sf_RigidAxlewithTC2024_o);

  /* End of SystemInitialize for SubSystem: '<S2>/TC+TV' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/RIGIDAXLE WITH TC' */
  VDCv2_RIGIDAXLEWITHTC_Init(&VDCv2_DW.RIGIDAXLEWITHTC_i);

  /* End of SystemInitialize for SubSystem: '<S2>/RIGIDAXLE WITH TC' */
  /* End of SystemInitialize for SubSystem: '<Root>/AUTOX1' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ENDURANCE' */
  /* SystemInitialize for IfAction SubSystem: '<S5>/TC+TV' */
  /* SystemInitialize for MATLAB Function: '<S31>/TC 2024' */
  VDCv2_RigidAxlewithTC2024_Init(&VDCv2_DW.sf_TC2024);

  /* End of SystemInitialize for SubSystem: '<S5>/TC+TV' */

  /* SystemInitialize for IfAction SubSystem: '<S5>/RIGIDAXLE WITH TC' */
  VDCv2_RIGIDAXLEWITHTC_Init(&VDCv2_DW.RIGIDAXLEWITHTC_j);

  /* End of SystemInitialize for SubSystem: '<S5>/RIGIDAXLE WITH TC' */

  /* SystemInitialize for Merge: '<S5>/Merge' */
  VDCv2_B.Merge = 0.0;

  /* SystemInitialize for Merge: '<S5>/Merge1' */
  VDCv2_B.Merge1_f = 0.0;

  /* SystemInitialize for Outport: '<S5>/Pedal_State' */
  VDCv2_B.state = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/ENDURANCE' */

  /* SystemInitialize for Merge: '<Root>/Merge1' */
  VDCv2_B.Merge1 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge2' */
  VDCv2_B.Merge2 = 0.0;

  /* SystemInitialize for Merge: '<Root>/Merge3' */
  VDCv2_B.Merge3 = 0.0;
}

/* Model terminate function */
static void VDCv2_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  VDCv2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  VDCv2_update();
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
  VDCv2_initialize();
}

void MdlTerminate(void)
{
  VDCv2_terminate();
}

/* Registration function */
RT_MODEL_VDCv2_T *VDCv2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)VDCv2_M, 0,
                sizeof(RT_MODEL_VDCv2_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = VDCv2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "VDCv2_M points to
       static memory which is guaranteed to be non-NULL" */
    VDCv2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    VDCv2_M->Timing.sampleTimes = (&VDCv2_M->Timing.sampleTimesArray[0]);
    VDCv2_M->Timing.offsetTimes = (&VDCv2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    VDCv2_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    VDCv2_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(VDCv2_M, &VDCv2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = VDCv2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    VDCv2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(VDCv2_M, 10.0);
  VDCv2_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    VDCv2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(VDCv2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(VDCv2_M->rtwLogInfo, (NULL));
    rtliSetLogT(VDCv2_M->rtwLogInfo, "tout");
    rtliSetLogX(VDCv2_M->rtwLogInfo, "");
    rtliSetLogXFinal(VDCv2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(VDCv2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(VDCv2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(VDCv2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(VDCv2_M->rtwLogInfo, 1);
    rtliSetLogY(VDCv2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(VDCv2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(VDCv2_M->rtwLogInfo, (NULL));
  }

  VDCv2_M->solverInfoPtr = (&VDCv2_M->solverInfo);
  VDCv2_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&VDCv2_M->solverInfo, 0.2);
  rtsiSetSolverMode(&VDCv2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  VDCv2_M->blockIO = ((void *) &VDCv2_B);
  (void) memset(((void *) &VDCv2_B), 0,
                sizeof(B_VDCv2_T));

  /* states (dwork) */
  VDCv2_M->dwork = ((void *) &VDCv2_DW);
  (void) memset((void *)&VDCv2_DW, 0,
                sizeof(DW_VDCv2_T));

  /* external inputs */
  VDCv2_M->inputs = (((void*)&VDCv2_U));
  (void)memset(&VDCv2_U, 0, sizeof(ExtU_VDCv2_T));

  /* external outputs */
  VDCv2_M->outputs = (&VDCv2_Y);
  (void)memset(&VDCv2_Y, 0, sizeof(ExtY_VDCv2_T));

  /* Initialize Sizes */
  VDCv2_M->Sizes.numContStates = (0);  /* Number of continuous states */
  VDCv2_M->Sizes.numY = (10);          /* Number of model outputs */
  VDCv2_M->Sizes.numU = (34);          /* Number of model inputs */
  VDCv2_M->Sizes.sysDirFeedThru = (1); /* The model is direct feedthrough */
  VDCv2_M->Sizes.numSampTimes = (1);   /* Number of sample times */
  VDCv2_M->Sizes.numBlocks = (195);    /* Number of blocks */
  VDCv2_M->Sizes.numBlockIO = (15);    /* Number of block outputs */
  return VDCv2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
