/*
 * Torque_Control.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 10.24
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Tue Mar 26 15:45:11 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_Control.h"
#include "rtwtypes.h"
#include "Torque_Control_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "polyfit_qSahpz3o.h"
#include "mldivide_8ZFDevWm.h"
#include <string.h>
#include "look1_binlxpw.h"

/* Block signals (default storage) */
B_Torque_Control_T Torque_Control_B;

/* Block states (default storage) */
DW_Torque_Control_T Torque_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Torque_Control_T Torque_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Torque_Control_T Torque_Control_Y;

/* Real-time model */
static RT_MODEL_Torque_Control_T Torque_Control_M_;
RT_MODEL_Torque_Control_T *const Torque_Control_M = &Torque_Control_M_;

/*
 * Output and update for action system:
 *    '<S12>/LimitReached'
 *    '<S15>/Latched Error'
 */
void Torque_Control_LimitReached(real_T *rty_Out)
{
  /* SignalConversion generated from: '<S14>/Out ' incorporates:
   *  Constant: '<S14>/Constant'
   */
  *rty_Out = 1.0;
}

/*
 * Output and update for action system:
 *    '<S100>/Braking with Regenerative'
 *    '<S159>/Braking with Regenerative'
 */
void Torque__BrakingwithRegenerative(real_T rtu_MaxRegTorque, real_T
  rtu_Tq_RR_wc, real_T rtu_Tq_RL_wc, real_T *rty_TQ_RR, real_T *rty_TQ_RL)
{
  real_T rtb_RegTq_RL_d;
  real_T rtb_RegTq_RR_m;

  /* MATLAB Function: '<S112>/MATLAB Function' */
  rtb_RegTq_RR_m = 0.0;
  rtb_RegTq_RL_d = 0.0;
  if ((!(rtu_Tq_RR_wc == 0.0)) || (!(rtu_Tq_RL_wc == 0.0))) {
    if ((rtu_Tq_RR_wc != 0.0) && (rtu_Tq_RL_wc == 0.0)) {
      rtb_RegTq_RL_d = rtu_Tq_RR_wc;
    } else if ((rtu_Tq_RR_wc == 0.0) && (rtu_Tq_RL_wc != 0.0)) {
      rtb_RegTq_RR_m = rtu_Tq_RL_wc;
    } else if (rtu_Tq_RR_wc == rtu_Tq_RL_wc) {
      if (rtu_Tq_RR_wc >= rtu_MaxRegTorque) {
        rtb_RegTq_RR_m = rtu_MaxRegTorque;
        rtb_RegTq_RL_d = rtu_MaxRegTorque;
      } else {
        rtb_RegTq_RR_m = rtu_Tq_RR_wc;
        rtb_RegTq_RL_d = rtu_Tq_RL_wc;
      }
    } else if (rtu_Tq_RR_wc > rtu_Tq_RL_wc) {
      if (rtu_Tq_RR_wc < rtu_MaxRegTorque) {
        rtb_RegTq_RR_m = rtu_Tq_RL_wc * rtu_Tq_RL_wc / rtu_Tq_RR_wc;
        rtb_RegTq_RL_d = rtu_Tq_RL_wc;
      } else {
        rtb_RegTq_RR_m = rtu_MaxRegTorque * rtu_Tq_RL_wc / rtu_Tq_RR_wc;
        rtb_RegTq_RL_d = rtu_MaxRegTorque;
      }
    } else if (rtu_Tq_RR_wc < rtu_Tq_RL_wc) {
      if (rtu_Tq_RL_wc < rtu_MaxRegTorque) {
        rtb_RegTq_RR_m = rtu_Tq_RR_wc;
        rtb_RegTq_RL_d = rtu_Tq_RR_wc * rtu_Tq_RR_wc / rtu_Tq_RL_wc;
      } else {
        rtb_RegTq_RR_m = rtu_MaxRegTorque;
        rtb_RegTq_RL_d = rtu_MaxRegTorque * rtu_Tq_RR_wc / rtu_Tq_RL_wc;
      }
    }
  }

  /* End of MATLAB Function: '<S112>/MATLAB Function' */

  /* Gain: '<S112>/Gain' */
  *rty_TQ_RR = -rtb_RegTq_RR_m;

  /* Gain: '<S112>/Gain1' */
  *rty_TQ_RL = -rtb_RegTq_RL_d;
}

/*
 * Output and update for action system:
 *    '<S111>/If Action 1'
 *    '<S167>/If Action 1'
 */
void Torque_Control_IfAction1(real_T rtu_Trans_max_dynamic, real_T
  *rty_Trans_limit)
{
  /* SignalConversion generated from: '<S113>/Trans_max_dynamic' */
  *rty_Trans_limit = rtu_Trans_max_dynamic;
}

/*
 * Output and update for action system:
 *    '<S111>/If Action 2'
 *    '<S167>/If Action 2'
 */
void Torque_Control_IfAction2(real_T rtu_Trans_max_static, real_T
  *rty_Trans_limit)
{
  /* SignalConversion generated from: '<S114>/Trans_max_static ' */
  *rty_Trans_limit = rtu_Trans_max_static;
}

/*
 * Output and update for atomic system:
 *    '<S101>/Accelerator behaviour '
 *    '<S176>/Accelerator behaviour '
 */
void Torque_Con_Acceleratorbehaviour(real_T rtu_Ap, real_T rtu_Ap_Sat_up, real_T
  rtu_Ap_Sat_down, B_Acceleratorbehaviour_Torque_T *localB)
{
  if (rtu_Ap <= rtu_Ap_Sat_down) {
    localB->throttle = 0.0;
  } else if (rtu_Ap >= rtu_Ap_Sat_up) {
    localB->throttle = 1.0;
  } else {
    real_T throttle_tmp;
    throttle_tmp = rtu_Ap_Sat_up - rtu_Ap_Sat_down;
    localB->throttle = 1.0 / throttle_tmp * rtu_Ap + (1.0 - rtu_Ap_Sat_up /
      throttle_tmp);
  }
}

/*
 * Output and update for action system:
 *    '<S101>/Mech_Braking'
 *    '<S101>/Inertia Braking'
 *    '<S160>/Mech_Braking'
 *    '<S160>/Inertia Braking'
 *    '<S73>/Mech_Braking'
 *    '<S73>/Inertia Braking'
 */
void Torque_Control_Mech_Braking(real_T *rty_Tq_RR, real_T *rty_Tq_RL)
{
  /* SignalConversion generated from: '<S124>/Tq_RR  ' incorporates:
   *  Constant: '<S124>/Constant'
   */
  *rty_Tq_RR = 0.0;

  /* SignalConversion generated from: '<S124>/Tq_RL' incorporates:
   *  Constant: '<S124>/Constant1'
   */
  *rty_Tq_RL = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S70>/MATLAB Function1'
 *    '<S70>/MATLAB Function2'
 */
void Torque_Control_MATLABFunction1(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction1_Torque_Cont_T *localB)
{
  if (rtu_v > 0.0) {
    localB->value = rtu_cte;
  } else {
    localB->value = 1.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S108>/MATLAB Function'
 *    '<S165>/MATLAB Function'
 */
void Torque_Control_MATLABFunction(real_T rtu_w_INV1, real_T rtu_w_INV2,
  B_MATLABFunction_Torque_Contr_T *localB)
{
  if (rtu_w_INV1 > rtu_w_INV2) {
    localB->w = rtu_w_INV1;
  } else {
    localB->w = rtu_w_INV2;
  }
}

/*
 * Output and update for atomic system:
 *    '<S151>/MATLAB Function'
 *    '<S96>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_h(real_T rtu_SKF_prev, real_T rtu_SKF_Initial,
  real_T rtu_Cte_SKF, B_MATLABFunction_Torque_Con_f_T *localB)
{
  localB->SKF_act0 = (2.0 - rtu_Cte_SKF) * rtu_SKF_prev;
  if (localB->SKF_act0 > rtu_SKF_Initial) {
    localB->SKF_act0 = rtu_SKF_Initial;
  }
}

/*
 * Output and update for atomic system:
 *    '<S148>/MATLAB Function'
 *    '<S193>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_l(real_T rtu_CKF_Initial, real_T rtu_CKF_prev,
  B_MATLABFunction_Torque_Con_h_T *localB)
{
  if (rtu_CKF_prev < rtu_CKF_Initial) {
    localB->CKF_act1 = rtu_CKF_prev;
  } else {
    localB->CKF_act1 = rtu_CKF_Initial;
  }
}

/*
 * Output and update for atomic system:
 *    '<S147>/MATLAB Function1'
 *    '<S192>/MATLAB Function'
 *    '<S92>/MATLAB Function'
 */
void Torque_Contro_MATLABFunction1_n(real_T rtu_CKF_prev, real_T rtu_CKF_Initial,
  real_T rtu_Cte_CKF, B_MATLABFunction1_Torque_Co_o_T *localB)
{
  localB->CKF_act0 = (2.0 - rtu_Cte_CKF) * rtu_CKF_prev;
  if (localB->CKF_act0 > rtu_CKF_Initial) {
    localB->CKF_act0 = rtu_CKF_Initial;
  }
}

/*
 * Output and update for atomic system:
 *    '<S105>/MATLAB Function'
 *    '<S105>/MATLAB Function1'
 *    '<S104>/MATLAB Function1'
 *    '<S104>/MATLAB Function2'
 *    '<S161>/MATLAB Function1'
 *    '<S161>/MATLAB Function2'
 *    '<S163>/MATLAB Function1'
 *    '<S163>/MATLAB Function2'
 */
void Torque_Control_MATLABFunction_f(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction_Torque_Con_j_T *localB)
{
  if ((rtu_v > 0.0) && (rtu_v < 60000.0)) {
    localB->value = rtu_v;
  } else {
    localB->value = rtu_cte;
  }
}

/*
 * Output and update for atomic system:
 *    '<S110>/MATLAB Function1'
 *    '<S110>/MATLAB Function2'
 */
void Torque_Contro_MATLABFunction1_p(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction1_Torque_Co_n_T *localB)
{
  if (rtu_v > 0.0) {
    localB->value = rtu_v;
  } else {
    localB->value = rtu_cte;
  }
}

/*
 * Output and update for action system:
 *    '<S11>/Automatic Failure Mode'
 *    '<S11>/Manual Failure Mode Selection'
 *    '<S8>/Enabled '
 *    '<S8>/NotEnabled'
 */
void Torque_Con_AutomaticFailureMode(real_T rtu_In1, real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S65>/In1' */
  *rty_Out1 = rtu_In1;
}

/* Model output function */
static void Torque_Control_output(void)
{
  /* local block i/o variables */
  real_T rtb_Abs2;
  real_T rtb_Switch;
  real_T rtb_Switch_h;
  real_T rtb_Product_p;
  real_T rtb_Product1;
  real_T rtb_Switch1;
  real_T rtb_Product_k;
  real_T rtb_TomotorTqRT;
  real_T rtb_Product1_e;
  real_T rtb_Product2;
  real_T rtb_Product_e;
  real_T rtb_Product1_h;
  real_T rtb_Switch1_o;
  real_T rtb_Product_h;
  real_T rtb_Switch1_m;
  real_T rtb_Merge1_pl;
  real_T rtb_Merge2;
  real_T rtb_Integrator;
  real_T rtb_Integrator_d;
  real_T rtb_Integrator_j;
  real_T rtb_Merge1_p;
  real_T tmp[12];
  real_T A[9];
  real_T kamm_data_1[4];
  real_T a[3];
  real_T b_a[2];
  real_T kamm_data[2];
  real_T kamm_data_0[2];
  real_T Mz;
  real_T X_idx_1;
  real_T a21;
  real_T maxval;
  real_T mz;
  real_T p;
  real_T rtb_Gain_f;
  real_T rtb_Merge1_h;
  real_T rtb_alpha_m;
  real_T rtb_value_a;
  real_T *lastU;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T LogicalOperator;
  boolean_T rtb_Compare_m;

  /* If: '<S56>/If' incorporates:
   *  Abs: '<S56>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S56>/Sum'
   */
  if (fabs(Torque_Control_U.APPS1_Value - Torque_Control_U.APPS2_Value) > 0.1) {
    Torque_Control_DW.If_ActiveSubsystem = 0;

    /* Outputs for IfAction SubSystem: '<S56>/Imp' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    /* Merge: '<S56>/Merge' incorporates:
     *  Constant: '<S59>/Constant'
     *  DataStoreRead: '<S59>/Data Store Read'
     *  Sum: '<S59>/Add'
     */
    Torque_Control_B.Merge_jz = Torque_Control_DW.ERROR_Counter + 1.0;

    /* End of Outputs for SubSystem: '<S56>/Imp' */
  } else {
    Torque_Control_DW.If_ActiveSubsystem = 1;

    /* Outputs for IfAction SubSystem: '<S56>/Not Imp' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    /* Merge: '<S56>/Merge' incorporates:
     *  Constant: '<S60>/Constant'
     *  SignalConversion generated from: '<S60>/0'
     */
    Torque_Control_B.Merge_jz = 0.0;

    /* End of Outputs for SubSystem: '<S56>/Not Imp' */
  }

  /* End of If: '<S56>/If' */

  /* DataStoreWrite: '<S56>/Data Store Write' */
  Torque_Control_DW.ERROR_Counter = Torque_Control_B.Merge_jz;

  /* If: '<S56>/If1' incorporates:
   *  Constant: '<S56>/Number_of_Periods'
   */
  if (Torque_Control_B.Merge_jz > 4.0) {
    Torque_Control_DW.If1_ActiveSubsystem = 0;

    /* Outputs for IfAction SubSystem: '<S56>/Signal_Failure' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    /* SignalConversion generated from: '<S61>/Out1' incorporates:
     *  Constant: '<S61>/Constant'
     */
    rtb_Merge1_h = 1.0;

    /* End of Outputs for SubSystem: '<S56>/Signal_Failure' */
  } else {
    Torque_Control_DW.If1_ActiveSubsystem = 1;

    /* Outputs for IfAction SubSystem: '<S56>/Signal_OK' incorporates:
     *  ActionPort: '<S62>/Action Port'
     */
    /* SignalConversion generated from: '<S62>/Out1' incorporates:
     *  Constant: '<S62>/Constant'
     */
    rtb_Merge1_h = 0.0;

    /* End of Outputs for SubSystem: '<S56>/Signal_OK' */
  }

  /* End of If: '<S56>/If1' */

  /* Logic: '<S9>/Logical Operator1' */
  Torque_Control_B.LogicalOperator1 = !(rtb_Merge1_h != 0.0);

  /* Logic: '<S9>/Logical Operator' incorporates:
   *  Constant: '<S57>/Constant'
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S9>/NOT'
   *  RelationalOperator: '<S57>/Compare'
   */
  LogicalOperator = (Torque_Control_U.Shutdown_PackageIntck &&
                     Torque_Control_U.TorqueEnable &&
                     (!Torque_Control_U.CriticalDisconnection) &&
                     (Torque_Control_U.Car_State == 15.0) &&
                     Torque_Control_B.LogicalOperator1);

  /* Outputs for Atomic SubSystem: '<Root>/TEST_MODE_IN' */
  /* If: '<S10>/If' incorporates:
   *  Inport: '<Root>/Workshop_Mode_Enable'
   */
  if (Torque_Control_U.Workshop_Mode_Enable == 1.0) {
    Torque_Control_DW.If_ActiveSubsystem_m = 0;

    /* Outputs for IfAction SubSystem: '<S10>/TEST_CONSTANTS' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  Constant: '<S64>/Constant'
     *  SignalConversion generated from: '<S64>/Out1'
     */
    Torque_Control_B.Merge_m = 800.0;

    /* Merge: '<S10>/Merge1' incorporates:
     *  Constant: '<S64>/Constant1'
     *  SignalConversion generated from: '<S64>/Out2'
     */
    Torque_Control_B.Merge1 = 800.0;

    /* Merge: '<S10>/Merge2' incorporates:
     *  Constant: '<S64>/Constant2'
     *  SignalConversion generated from: '<S64>/Out3'
     */
    Torque_Control_B.Merge2 = 800.0;

    /* Merge: '<S10>/Merge3' incorporates:
     *  Constant: '<S64>/Constant3'
     *  SignalConversion generated from: '<S64>/Out4'
     */
    Torque_Control_B.Merge3_o = 800.0;

    /* End of Outputs for SubSystem: '<S10>/TEST_CONSTANTS' */
  } else {
    Torque_Control_DW.If_ActiveSubsystem_m = 1;

    /* Outputs for IfAction SubSystem: '<S10>/BYPASS' incorporates:
     *  ActionPort: '<S63>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  Inport: '<Root>/Susp_F_R'
     *  SignalConversion generated from: '<S63>/In1'
     */
    Torque_Control_B.Merge_m = Torque_Control_U.Susp_F_R;

    /* Merge: '<S10>/Merge1' incorporates:
     *  Inport: '<Root>/Susp_F_L'
     *  SignalConversion generated from: '<S63>/In2'
     */
    Torque_Control_B.Merge1 = Torque_Control_U.Susp_F_L;

    /* Merge: '<S10>/Merge2' incorporates:
     *  Inport: '<Root>/Susp_R_R'
     *  SignalConversion generated from: '<S63>/In3'
     */
    Torque_Control_B.Merge2 = Torque_Control_U.Susp_R_R;

    /* Merge: '<S10>/Merge3' incorporates:
     *  Inport: '<Root>/Susp_R_L'
     *  SignalConversion generated from: '<S63>/In4'
     */
    Torque_Control_B.Merge3_o = Torque_Control_U.Susp_R_L;

    /* End of Outputs for SubSystem: '<S10>/BYPASS' */
  }

  /* End of If: '<S10>/If' */
  /* End of Outputs for SubSystem: '<Root>/TEST_MODE_IN' */

  /* Outputs for Atomic SubSystem: '<Root>/Regeneration_Enable' */
  /* If: '<S8>/If' incorporates:
   *  Abs: '<Root>/Abs'
   *  Abs: '<Root>/Abs1'
   *  Constant: '<S8>/Enabled'
   *  Constant: '<S8>/Zero '
   *  Gain: '<S8>/Gain'
   *  Gain: '<S8>/Gain1'
   *  Inport: '<Root>/RL_Vel_ms_Wheel'
   *  Inport: '<Root>/RR_Vel_ms_Wheel'
   */
  if ((3.6 * fabs(Torque_Control_U.RR_Vel_ms_Wheel) > 2.0) && (3.6 * fabs
       (Torque_Control_U.RL_Vel_ms_Wheel) > 2.0)) {
    Torque_Control_DW.If_ActiveSubsystem_o = 0;

    /* Outputs for IfAction SubSystem: '<S8>/Enabled ' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    Torque_Con_AutomaticFailureMode(1.0, &Torque_Control_B.Merge1_a);

    /* End of Outputs for SubSystem: '<S8>/Enabled ' */
  } else {
    Torque_Control_DW.If_ActiveSubsystem_o = 1;

    /* Outputs for IfAction SubSystem: '<S8>/NotEnabled' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    Torque_Con_AutomaticFailureMode(0.0, &Torque_Control_B.Merge1_a);

    /* End of Outputs for SubSystem: '<S8>/NotEnabled' */
  }

  /* End of If: '<S8>/If' */
  /* End of Outputs for SubSystem: '<Root>/Regeneration_Enable' */

  /* Abs: '<Root>/Abs2' incorporates:
   *  Inport: '<Root>/RR_rads_Motor'
   */
  rtb_Abs2 = fabs(Torque_Control_U.RR_rads_Motor);

  /* Abs: '<Root>/Abs3' incorporates:
   *  Inport: '<Root>/RL_rads_Motor'
   */
  Torque_Control_B.Abs3 = fabs(Torque_Control_U.RL_rads_Motor);

  /* If: '<Root>/If2' */
  rtPrevAction = Torque_Control_DW.If2_ActiveSubsystem;
  rtAction = -1;
  if (LogicalOperator) {
    rtAction = 0;
  }

  Torque_Control_DW.If2_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S11>/FAILURE MODE' */
    switch (Torque_Control_DW.FAILUREMODE_ActiveSubsystem) {
     case 0:
      /* Disable for If: '<S143>/SKF or CKF' */
      Torque_Control_DW.SKForCKF_ActiveSubsystem_e = -1;

      /* Disable for If: '<S70>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
      Torque_Control_DW.Steer_angisinSteer_SatrangeLong = -1;

      /* Disable for If: '<S101>/Braking Conditions' */
      Torque_Control_DW.BrakingConditions_ActiveSubs_f3 = -1;

      /* Disable for If: '<S100>/If' */
      Torque_Control_DW.If_ActiveSubsystem_c = -1;
      break;

     case 1:
     case 3:
      break;

     case 2:
      /* Disable for If: '<S88>/SKF or CKF' */
      if (Torque_Control_DW.SKForCKF_ActiveSubsystem == 1) {
        /* Disable for If: '<S89>/If1' */
        Torque_Control_DW.If1_ActiveSubsystem_o = -1;
      }

      Torque_Control_DW.SKForCKF_ActiveSubsystem = -1;

      /* Disable for If: '<S69>/If1' */
      Torque_Control_DW.If1_ActiveSubsystem_g = -1;

      /* Disable for If: '<S69>/If' */
      Torque_Control_DW.If_ActiveSubsystem_b = -1;

      /* Disable for If: '<S73>/Braking Conditions' */
      Torque_Control_DW.BrakingConditions_ActiveSubsyst = -1;
      break;
    }

    Torque_Control_DW.FAILUREMODE_ActiveSubsystem = -1;

    /* End of Disable for If: '<S11>/FAILURE MODE' */
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<Root>/Vehicle Dynamics Control Modes' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S11>/Automatic Failure Mode' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    /* If: '<S11>/If' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Torque_Con_AutomaticFailureMode(3.0, &Torque_Control_B.Merge_a);

    /* End of Outputs for SubSystem: '<S11>/Automatic Failure Mode' */

    /* If: '<S11>/FAILURE MODE' */
    rtPrevAction = Torque_Control_DW.FAILUREMODE_ActiveSubsystem;
    rtAction = -1;
    if (Torque_Control_B.Merge_a == 1.0) {
      rtAction = 0;
    } else if (Torque_Control_B.Merge_a == 2.0) {
      rtAction = 1;
    } else if (Torque_Control_B.Merge_a == 3.0) {
      rtAction = 2;
    } else if (Torque_Control_B.Merge_a == 4.0) {
      rtAction = 3;
    }

    Torque_Control_DW.FAILUREMODE_ActiveSubsystem = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for If: '<S143>/SKF or CKF' */
        Torque_Control_DW.SKForCKF_ActiveSubsystem_e = -1;

        /* Disable for If: '<S70>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
        Torque_Control_DW.Steer_angisinSteer_SatrangeLong = -1;

        /* Disable for If: '<S101>/Braking Conditions' */
        Torque_Control_DW.BrakingConditions_ActiveSubs_f3 = -1;

        /* Disable for If: '<S100>/If' */
        Torque_Control_DW.If_ActiveSubsystem_c = -1;
        break;

       case 1:
       case 3:
        break;

       case 2:
        /* Disable for If: '<S88>/SKF or CKF' */
        if (Torque_Control_DW.SKForCKF_ActiveSubsystem == 1) {
          /* Disable for If: '<S89>/If1' */
          Torque_Control_DW.If1_ActiveSubsystem_o = -1;
        }

        Torque_Control_DW.SKForCKF_ActiveSubsystem = -1;

        /* Disable for If: '<S69>/If1' */
        Torque_Control_DW.If1_ActiveSubsystem_g = -1;

        /* Disable for If: '<S69>/If' */
        Torque_Control_DW.If_ActiveSubsystem_b = -1;

        /* Disable for If: '<S73>/Braking Conditions' */
        Torque_Control_DW.BrakingConditions_ActiveSubsyst = -1;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      {
        real_T k;

        /* Outputs for IfAction SubSystem: '<S11>/VDC Complete' incorporates:
         *  ActionPort: '<S70>/Action Port'
         */
        /* MATLAB Function: '<S143>/MATLAB Function1' incorporates:
         *  Constant: '<S143>/Steering Wheel Maximum Angle'
         *  Gain: '<S11>/Gain'
         *  Inport: '<Root>/SteeringSensor_Value'
         */
        if (-Torque_Control_U.SteeringSensor_Value > 100.0) {
          rtb_value_a = 100.0;
        } else if (-Torque_Control_U.SteeringSensor_Value < -100.0) {
          rtb_value_a = -100.0;
        } else {
          rtb_value_a = -Torque_Control_U.SteeringSensor_Value;
        }

        /* End of MATLAB Function: '<S143>/MATLAB Function1' */

        /* MATLAB Function: '<S108>/MATLAB Function' */
        Torque_Control_MATLABFunction(Torque_Control_B.Abs3, rtb_Abs2,
          &Torque_Control_B.sf_MATLABFunction_h);

        /* Derivative: '<S108>/Derivative' */
        rtb_alpha_m = Torque_Control_M->Timing.t[0];
        if ((Torque_Control_DW.TimeStampA_d >= rtb_alpha_m) &&
            (Torque_Control_DW.TimeStampB_c >= rtb_alpha_m)) {
          rtb_alpha_m = 0.0;
        } else {
          maxval = Torque_Control_DW.TimeStampA_d;
          lastU = &Torque_Control_DW.LastUAtTimeA_n;
          if (Torque_Control_DW.TimeStampA_d < Torque_Control_DW.TimeStampB_c) {
            if (Torque_Control_DW.TimeStampB_c < rtb_alpha_m) {
              maxval = Torque_Control_DW.TimeStampB_c;
              lastU = &Torque_Control_DW.LastUAtTimeB_b;
            }
          } else if (Torque_Control_DW.TimeStampA_d >= rtb_alpha_m) {
            maxval = Torque_Control_DW.TimeStampB_c;
            lastU = &Torque_Control_DW.LastUAtTimeB_b;
          }

          rtb_alpha_m = (Torque_Control_B.sf_MATLABFunction_h.w - *lastU) /
            (rtb_alpha_m - maxval);
        }

        /* End of Derivative: '<S108>/Derivative' */

        /* If: '<S143>/SKF or CKF' */
        if ((rtb_value_a > -10.0) && (rtb_value_a < 10.0)) {
          Torque_Control_DW.SKForCKF_ActiveSubsystem_e = 0;

          /* Outputs for IfAction SubSystem: '<S143>/SKF' incorporates:
           *  ActionPort: '<S146>/Action Port'
           */
          /* If: '<S146>/If' */
          Torque_Control_DW.If_ActiveSubsystem_h = -1;
          if (rtb_alpha_m >= 900.0) {
            Torque_Control_DW.If_ActiveSubsystem_h = 0;

            /* Outputs for IfAction SubSystem: '<S146>/Spin' incorporates:
             *  ActionPort: '<S152>/Action Port'
             */
            /* Switch: '<S152>/Switch1' incorporates:
             *  DataStoreRead: '<S108>/SKF_prev '
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            if (Torque_Control_DW.A_k > 0.0) {
              p = Torque_Control_DW.A_k;
            } else {
              p = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of Switch: '<S152>/Switch1' */

            /* Switch: '<S152>/Switch' incorporates:
             *  Constant: '<S152>/Constant'
             *  Inport: '<Root>/VDC_Cte_SKF'
             */
            if (Torque_Control_U.VDC_Cte_SKF >= 0.9) {
              k = Torque_Control_U.VDC_Cte_SKF;
            } else {
              k = 1.0;
            }

            /* End of Switch: '<S152>/Switch' */

            /* Product: '<S152>/Product' */
            rtb_value_a = p * k;

            /* MATLAB Function: '<S152>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            if (rtb_value_a < Torque_Control_U.VDC_SKF_Initial) {
              /* Merge: '<S146>/Merge' incorporates:
               *  SignalConversion generated from: '<S152>/SKF_act1'
               */
              Torque_Control_B.Merge_agp = rtb_value_a;
            } else {
              /* Merge: '<S146>/Merge' incorporates:
               *  SignalConversion generated from: '<S152>/SKF_act1'
               */
              Torque_Control_B.Merge_agp = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of MATLAB Function: '<S152>/MATLAB Function' */
            /* End of Outputs for SubSystem: '<S146>/Spin' */
          } else if (rtb_alpha_m < 900.0) {
            Torque_Control_DW.If_ActiveSubsystem_h = 1;

            /* Outputs for IfAction SubSystem: '<S146>/No spin' incorporates:
             *  ActionPort: '<S151>/Action Port'
             */
            /* Switch: '<S151>/Switch1' incorporates:
             *  DataStoreRead: '<S108>/SKF_prev '
             */
            if (Torque_Control_DW.A_k > 0.0) {
              /* Switch: '<S151>/Switch1' */
              rtb_Switch1_m = Torque_Control_DW.A_k;
            } else {
              /* Switch: '<S151>/Switch1' incorporates:
               *  Inport: '<Root>/VDC_SKF_Initial'
               */
              rtb_Switch1_m = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of Switch: '<S151>/Switch1' */

            /* MATLAB Function: '<S151>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_Cte_SKF'
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            Torque_Control_MATLABFunction_h(rtb_Switch1_m,
              Torque_Control_U.VDC_SKF_Initial, Torque_Control_U.VDC_Cte_SKF,
              &Torque_Control_B.sf_MATLABFunction_hg);

            /* Merge: '<S146>/Merge' incorporates:
             *  SignalConversion generated from: '<S151>/SKF_act0'
             */
            Torque_Control_B.Merge_agp =
              Torque_Control_B.sf_MATLABFunction_hg.SKF_act0;

            /* End of Outputs for SubSystem: '<S146>/No spin' */
          }

          /* End of If: '<S146>/If' */

          /* Saturate: '<S146>/Saturation' */
          if (Torque_Control_B.Merge_agp > 1.0) {
            /* Saturate: '<S146>/Saturation' */
            Torque_Control_B.Saturation_hh = 1.0;
          } else if (Torque_Control_B.Merge_agp < 0.3) {
            /* Saturate: '<S146>/Saturation' */
            Torque_Control_B.Saturation_hh = 0.3;
          } else {
            /* Saturate: '<S146>/Saturation' */
            Torque_Control_B.Saturation_hh = Torque_Control_B.Merge_agp;
          }

          /* End of Saturate: '<S146>/Saturation' */
          /* End of Outputs for SubSystem: '<S143>/SKF' */
        } else {
          Torque_Control_DW.SKForCKF_ActiveSubsystem_e = 1;

          /* Outputs for IfAction SubSystem: '<S143>/CKF' incorporates:
           *  ActionPort: '<S144>/Action Port'
           */
          /* If: '<S144>/If1' */
          Torque_Control_DW.If1_ActiveSubsystem_pl = -1;
          if (rtb_alpha_m >= 900.0) {
            Torque_Control_DW.If1_ActiveSubsystem_pl = 0;

            /* Outputs for IfAction SubSystem: '<S144>/Spin ' incorporates:
             *  ActionPort: '<S148>/Action Port'
             */
            /* Switch: '<S148>/Switch1' incorporates:
             *  DataStoreRead: '<S108>/CKF_prev'
             *  Inport: '<Root>/VDC_CKF_Initial'
             */
            if (Torque_Control_DW.B_p > 0.0) {
              p = Torque_Control_DW.B_p;
            } else {
              p = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of Switch: '<S148>/Switch1' */

            /* Switch: '<S148>/Switch' incorporates:
             *  Constant: '<S148>/Constant'
             *  Inport: '<Root>/VDC_Cte_CKF'
             */
            if (Torque_Control_U.VDC_Cte_CKF > 0.9) {
              k = Torque_Control_U.VDC_Cte_CKF;
            } else {
              k = 1.0;
            }

            /* End of Switch: '<S148>/Switch' */

            /* Product: '<S148>/Product' */
            rtb_Product_h = p * k;

            /* MATLAB Function: '<S148>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             */
            Torque_Control_MATLABFunction_l(Torque_Control_U.VDC_CKF_Initial,
              rtb_Product_h, &Torque_Control_B.sf_MATLABFunction_l);

            /* Merge: '<S144>/Merge' incorporates:
             *  SignalConversion generated from: '<S148>/CKF_act1 '
             */
            Torque_Control_B.Merge_az =
              Torque_Control_B.sf_MATLABFunction_l.CKF_act1;

            /* End of Outputs for SubSystem: '<S144>/Spin ' */
          } else if (rtb_alpha_m < 900.0) {
            Torque_Control_DW.If1_ActiveSubsystem_pl = 1;

            /* Outputs for IfAction SubSystem: '<S144>/No spin' incorporates:
             *  ActionPort: '<S147>/Action Port'
             */
            /* Switch: '<S147>/Switch1' incorporates:
             *  DataStoreRead: '<S108>/CKF_prev'
             */
            if (Torque_Control_DW.B_p > 0.0) {
              /* Switch: '<S147>/Switch1' */
              rtb_Switch1_o = Torque_Control_DW.B_p;
            } else {
              /* Switch: '<S147>/Switch1' incorporates:
               *  Inport: '<Root>/VDC_CKF_Initial'
               */
              rtb_Switch1_o = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of Switch: '<S147>/Switch1' */

            /* MATLAB Function: '<S147>/MATLAB Function1' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             *  Inport: '<Root>/VDC_Cte_CKF'
             */
            Torque_Contro_MATLABFunction1_n(rtb_Switch1_o,
              Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_CKF,
              &Torque_Control_B.sf_MATLABFunction1_n);

            /* Merge: '<S144>/Merge' incorporates:
             *  SignalConversion generated from: '<S147>/CKF_act0'
             */
            Torque_Control_B.Merge_az =
              Torque_Control_B.sf_MATLABFunction1_n.CKF_act0;

            /* End of Outputs for SubSystem: '<S144>/No spin' */
          }

          /* End of If: '<S144>/If1' */

          /* Saturate: '<S144>/Saturation' */
          if (Torque_Control_B.Merge_az > 1.0) {
            /* Saturate: '<S144>/Saturation' */
            Torque_Control_B.Saturation_h = 1.0;
          } else if (Torque_Control_B.Merge_az < 0.3) {
            /* Saturate: '<S144>/Saturation' */
            Torque_Control_B.Saturation_h = 0.3;
          } else {
            /* Saturate: '<S144>/Saturation' */
            Torque_Control_B.Saturation_h = Torque_Control_B.Merge_az;
          }

          /* End of Saturate: '<S144>/Saturation' */
          /* End of Outputs for SubSystem: '<S143>/CKF' */
        }

        /* End of If: '<S143>/SKF or CKF' */

        /* DataStoreWrite: '<S108>/Data Store Write' */
        Torque_Control_DW.A_k = Torque_Control_B.Saturation_hh;

        /* DataStoreWrite: '<S108>/Data Store Write1' */
        Torque_Control_DW.B_p = Torque_Control_B.Saturation_h;

        /* Saturate: '<S108>/Saturation' */
        if (rtb_alpha_m > 6000.0) {
          /* Saturate: '<S108>/Saturation' */
          Torque_Control_B.Saturation_p = 6000.0;
        } else if (rtb_alpha_m < 0.0) {
          /* Saturate: '<S108>/Saturation' */
          Torque_Control_B.Saturation_p = 0.0;
        } else {
          /* Saturate: '<S108>/Saturation' */
          Torque_Control_B.Saturation_p = rtb_alpha_m;
        }

        /* End of Saturate: '<S108>/Saturation' */

        /* Switch: '<S108>/Switch' */
        if (rtb_alpha_m >= 900.0) {
          /* Switch: '<S108>/Switch' */
          Torque_Control_B.Switch_m = rtb_alpha_m;
        } else {
          /* Switch: '<S108>/Switch' incorporates:
           *  Constant: '<S108>/Constant'
           */
          Torque_Control_B.Switch_m = 0.0;
        }

        /* End of Switch: '<S108>/Switch' */
        /* Gain: '<S103>/To motor Tq (RT)' incorporates:
         *  Inport: '<Root>/VDC_Max_Regen_Motor_Tq'
         */
        rtb_TomotorTqRT = 0.25 * Torque_Control_U.VDC_Max_Regen_Motor_Tq;

        /* If: '<S70>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' incorporates:
         *  Constant: '<S11>/Steering Wheel Saturation (per site) [deg] '
         *  Gain: '<S11>/Gain'
         *  Inport: '<Root>/SteeringSensor_Value'
         */
        rtAction = (int8_T)((!(-Torque_Control_U.SteeringSensor_Value >= -10.0))
                            || (!(-Torque_Control_U.SteeringSensor_Value <= 10.0)));
        Torque_Control_DW.Steer_angisinSteer_SatrangeLong = rtAction;
        if (rtAction == 0) {
          real_T My;
          real_T my;
          int32_T r1;
          int32_T r2;

          /* Outputs for IfAction SubSystem: '<S70>/Longitudinal Dynamics' incorporates:
           *  ActionPort: '<S105>/Action Port'
           */
          /* Merge: '<S70>/Merge' incorporates:
           *  Constant: '<S105>/Constant1'
           *  SignalConversion generated from: '<S105>/Fx_FR'
           */
          Torque_Control_B.Merge_l = 0.0;

          /* Merge: '<S70>/Merge1' incorporates:
           *  Constant: '<S105>/Constant2'
           *  SignalConversion generated from: '<S105>/Fx_FL'
           */
          Torque_Control_B.Merge1_e = 0.0;

          /* Merge: '<S70>/Merge4' incorporates:
           *  Gain: '<S105>/Gain'
           *  Sum: '<S105>/Add'
           */
          Torque_Control_B.Merge4 = (((Torque_Control_B.Merge_m +
            Torque_Control_B.Merge1) + Torque_Control_B.Merge2) +
            Torque_Control_B.Merge3_o) * 0.1019367991845056;

          /* MATLAB Function: '<S105>/minimum value' */
          rtb_Gain_f = Torque_Control_B.Merge2;
          if (Torque_Control_B.Merge3_o < Torque_Control_B.Merge2) {
            rtb_Gain_f = Torque_Control_B.Merge3_o;
          }

          /* End of MATLAB Function: '<S105>/minimum value' */

          /* MATLAB Function: '<S137>/Kamm_Circle LatD' incorporates:
           *  Constant: '<S105>/Constant'
           */
          Torque_Control_B.kamm_data[0] = (rtNaN);
          Torque_Control_B.kamm_data[17] = 0.0;
          Torque_Control_B.kamm_data[34] = 100.0;
          Torque_Control_B.kamm_data[51] = 200.0;
          Torque_Control_B.kamm_data[68] = 300.0;
          Torque_Control_B.kamm_data[85] = 400.0;
          Torque_Control_B.kamm_data[102] = 500.0;
          Torque_Control_B.kamm_data[119] = 600.0;
          Torque_Control_B.kamm_data[136] = 700.0;
          Torque_Control_B.kamm_data[153] = 800.0;
          Torque_Control_B.kamm_data[170] = 900.0;
          Torque_Control_B.kamm_data[187] = 1000.0;
          Torque_Control_B.kamm_data[204] = 1100.0;
          Torque_Control_B.kamm_data[221] = 1200.0;
          Torque_Control_B.kamm_data[238] = 1300.0;
          Torque_Control_B.kamm_data[255] = 1400.0;
          Torque_Control_B.kamm_data[272] = 1500.0;
          Torque_Control_B.kamm_data[289] = 1600.0;
          Torque_Control_B.kamm_data[306] = 1700.0;
          Torque_Control_B.kamm_data[323] = 1800.0;
          Torque_Control_B.kamm_data[340] = 1900.0;
          Torque_Control_B.kamm_data[357] = 2000.0;
          Torque_Control_B.kamm_data[374] = 2100.0;
          Torque_Control_B.kamm_data[391] = 2200.0;
          Torque_Control_B.kamm_data[408] = 2300.0;
          Torque_Control_B.kamm_data[425] = 2400.0;
          Torque_Control_B.kamm_data[442] = 2500.0;
          Torque_Control_B.kamm_data[459] = 2600.0;
          Torque_Control_B.kamm_data[476] = 2700.0;
          Torque_Control_B.kamm_data[493] = 2800.0;
          Torque_Control_B.kamm_data[510] = 2900.0;
          Torque_Control_B.kamm_data[527] = 3000.0;
          Torque_Control_B.kamm_data[1] = 0.0;
          Torque_Control_B.kamm_data[18] = 0.0;
          Torque_Control_B.kamm_data[35] = (rtNaN);
          Torque_Control_B.kamm_data[52] = (rtNaN);
          Torque_Control_B.kamm_data[69] = (rtNaN);
          Torque_Control_B.kamm_data[86] = (rtNaN);
          Torque_Control_B.kamm_data[103] = (rtNaN);
          Torque_Control_B.kamm_data[120] = (rtNaN);
          Torque_Control_B.kamm_data[137] = (rtNaN);
          Torque_Control_B.kamm_data[154] = (rtNaN);
          Torque_Control_B.kamm_data[171] = (rtNaN);
          Torque_Control_B.kamm_data[188] = (rtNaN);
          Torque_Control_B.kamm_data[205] = (rtNaN);
          Torque_Control_B.kamm_data[222] = (rtNaN);
          Torque_Control_B.kamm_data[239] = (rtNaN);
          Torque_Control_B.kamm_data[256] = (rtNaN);
          Torque_Control_B.kamm_data[273] = (rtNaN);
          Torque_Control_B.kamm_data[290] = (rtNaN);
          Torque_Control_B.kamm_data[307] = (rtNaN);
          Torque_Control_B.kamm_data[324] = (rtNaN);
          Torque_Control_B.kamm_data[341] = (rtNaN);
          Torque_Control_B.kamm_data[358] = (rtNaN);
          Torque_Control_B.kamm_data[375] = (rtNaN);
          Torque_Control_B.kamm_data[392] = (rtNaN);
          Torque_Control_B.kamm_data[409] = (rtNaN);
          Torque_Control_B.kamm_data[426] = (rtNaN);
          Torque_Control_B.kamm_data[443] = (rtNaN);
          Torque_Control_B.kamm_data[460] = (rtNaN);
          Torque_Control_B.kamm_data[477] = (rtNaN);
          Torque_Control_B.kamm_data[494] = (rtNaN);
          Torque_Control_B.kamm_data[511] = (rtNaN);
          Torque_Control_B.kamm_data[528] = (rtNaN);
          Torque_Control_B.kamm_data[2] = 100.0;
          Torque_Control_B.kamm_data[19] = 350.0;
          Torque_Control_B.kamm_data[36] = 340.0;
          Torque_Control_B.kamm_data[53] = 156.0;
          Torque_Control_B.kamm_data[70] = (rtNaN);
          Torque_Control_B.kamm_data[87] = (rtNaN);
          Torque_Control_B.kamm_data[104] = (rtNaN);
          Torque_Control_B.kamm_data[121] = (rtNaN);
          Torque_Control_B.kamm_data[138] = (rtNaN);
          Torque_Control_B.kamm_data[155] = (rtNaN);
          Torque_Control_B.kamm_data[172] = (rtNaN);
          Torque_Control_B.kamm_data[189] = (rtNaN);
          Torque_Control_B.kamm_data[206] = (rtNaN);
          Torque_Control_B.kamm_data[223] = (rtNaN);
          Torque_Control_B.kamm_data[240] = (rtNaN);
          Torque_Control_B.kamm_data[257] = (rtNaN);
          Torque_Control_B.kamm_data[274] = (rtNaN);
          Torque_Control_B.kamm_data[291] = (rtNaN);
          Torque_Control_B.kamm_data[308] = (rtNaN);
          Torque_Control_B.kamm_data[325] = (rtNaN);
          Torque_Control_B.kamm_data[342] = (rtNaN);
          Torque_Control_B.kamm_data[359] = (rtNaN);
          Torque_Control_B.kamm_data[376] = (rtNaN);
          Torque_Control_B.kamm_data[393] = (rtNaN);
          Torque_Control_B.kamm_data[410] = (rtNaN);
          Torque_Control_B.kamm_data[427] = (rtNaN);
          Torque_Control_B.kamm_data[444] = (rtNaN);
          Torque_Control_B.kamm_data[461] = (rtNaN);
          Torque_Control_B.kamm_data[478] = (rtNaN);
          Torque_Control_B.kamm_data[495] = (rtNaN);
          Torque_Control_B.kamm_data[512] = (rtNaN);
          Torque_Control_B.kamm_data[529] = (rtNaN);
          Torque_Control_B.kamm_data[3] = 200.0;
          Torque_Control_B.kamm_data[20] = 688.0;
          Torque_Control_B.kamm_data[37] = 676.0;
          Torque_Control_B.kamm_data[54] = 654.0;
          Torque_Control_B.kamm_data[71] = 573.0;
          Torque_Control_B.kamm_data[88] = 269.0;
          Torque_Control_B.kamm_data[105] = (rtNaN);
          Torque_Control_B.kamm_data[122] = (rtNaN);
          Torque_Control_B.kamm_data[139] = (rtNaN);
          Torque_Control_B.kamm_data[156] = (rtNaN);
          Torque_Control_B.kamm_data[173] = (rtNaN);
          Torque_Control_B.kamm_data[190] = (rtNaN);
          Torque_Control_B.kamm_data[207] = (rtNaN);
          Torque_Control_B.kamm_data[224] = (rtNaN);
          Torque_Control_B.kamm_data[241] = (rtNaN);
          Torque_Control_B.kamm_data[258] = (rtNaN);
          Torque_Control_B.kamm_data[275] = (rtNaN);
          Torque_Control_B.kamm_data[292] = (rtNaN);
          Torque_Control_B.kamm_data[309] = (rtNaN);
          Torque_Control_B.kamm_data[326] = (rtNaN);
          Torque_Control_B.kamm_data[343] = (rtNaN);
          Torque_Control_B.kamm_data[360] = (rtNaN);
          Torque_Control_B.kamm_data[377] = (rtNaN);
          Torque_Control_B.kamm_data[394] = (rtNaN);
          Torque_Control_B.kamm_data[411] = (rtNaN);
          Torque_Control_B.kamm_data[428] = (rtNaN);
          Torque_Control_B.kamm_data[445] = (rtNaN);
          Torque_Control_B.kamm_data[462] = (rtNaN);
          Torque_Control_B.kamm_data[479] = (rtNaN);
          Torque_Control_B.kamm_data[496] = (rtNaN);
          Torque_Control_B.kamm_data[513] = (rtNaN);
          Torque_Control_B.kamm_data[530] = (rtNaN);
          Torque_Control_B.kamm_data[4] = 300.0;
          Torque_Control_B.kamm_data[21] = 1002.0;
          Torque_Control_B.kamm_data[38] = 994.0;
          Torque_Control_B.kamm_data[55] = 982.0;
          Torque_Control_B.kamm_data[72] = 959.0;
          Torque_Control_B.kamm_data[89] = 888.0;
          Torque_Control_B.kamm_data[106] = 694.0;
          Torque_Control_B.kamm_data[123] = 345.0;
          Torque_Control_B.kamm_data[140] = (rtNaN);
          Torque_Control_B.kamm_data[157] = (rtNaN);
          Torque_Control_B.kamm_data[174] = (rtNaN);
          Torque_Control_B.kamm_data[191] = (rtNaN);
          Torque_Control_B.kamm_data[208] = (rtNaN);
          Torque_Control_B.kamm_data[225] = (rtNaN);
          Torque_Control_B.kamm_data[242] = (rtNaN);
          Torque_Control_B.kamm_data[259] = (rtNaN);
          Torque_Control_B.kamm_data[276] = (rtNaN);
          Torque_Control_B.kamm_data[293] = (rtNaN);
          Torque_Control_B.kamm_data[310] = (rtNaN);
          Torque_Control_B.kamm_data[327] = (rtNaN);
          Torque_Control_B.kamm_data[344] = (rtNaN);
          Torque_Control_B.kamm_data[361] = (rtNaN);
          Torque_Control_B.kamm_data[378] = (rtNaN);
          Torque_Control_B.kamm_data[395] = (rtNaN);
          Torque_Control_B.kamm_data[412] = (rtNaN);
          Torque_Control_B.kamm_data[429] = (rtNaN);
          Torque_Control_B.kamm_data[446] = (rtNaN);
          Torque_Control_B.kamm_data[463] = (rtNaN);
          Torque_Control_B.kamm_data[480] = (rtNaN);
          Torque_Control_B.kamm_data[497] = (rtNaN);
          Torque_Control_B.kamm_data[514] = (rtNaN);
          Torque_Control_B.kamm_data[531] = (rtNaN);
          Torque_Control_B.kamm_data[5] = 400.0;
          Torque_Control_B.kamm_data[22] = 1295.0;
          Torque_Control_B.kamm_data[39] = 1288.0;
          Torque_Control_B.kamm_data[56] = 1280.0;
          Torque_Control_B.kamm_data[73] = 1263.0;
          Torque_Control_B.kamm_data[90] = 1235.0;
          Torque_Control_B.kamm_data[107] = 1168.0;
          Torque_Control_B.kamm_data[124] = 1001.0;
          Torque_Control_B.kamm_data[141] = 740.0;
          Torque_Control_B.kamm_data[158] = 389.0;
          Torque_Control_B.kamm_data[175] = (rtNaN);
          Torque_Control_B.kamm_data[192] = (rtNaN);
          Torque_Control_B.kamm_data[209] = (rtNaN);
          Torque_Control_B.kamm_data[226] = (rtNaN);
          Torque_Control_B.kamm_data[243] = (rtNaN);
          Torque_Control_B.kamm_data[260] = (rtNaN);
          Torque_Control_B.kamm_data[277] = (rtNaN);
          Torque_Control_B.kamm_data[294] = (rtNaN);
          Torque_Control_B.kamm_data[311] = (rtNaN);
          Torque_Control_B.kamm_data[328] = (rtNaN);
          Torque_Control_B.kamm_data[345] = (rtNaN);
          Torque_Control_B.kamm_data[362] = (rtNaN);
          Torque_Control_B.kamm_data[379] = (rtNaN);
          Torque_Control_B.kamm_data[396] = (rtNaN);
          Torque_Control_B.kamm_data[413] = (rtNaN);
          Torque_Control_B.kamm_data[430] = (rtNaN);
          Torque_Control_B.kamm_data[447] = (rtNaN);
          Torque_Control_B.kamm_data[464] = (rtNaN);
          Torque_Control_B.kamm_data[481] = (rtNaN);
          Torque_Control_B.kamm_data[498] = (rtNaN);
          Torque_Control_B.kamm_data[515] = (rtNaN);
          Torque_Control_B.kamm_data[532] = (rtNaN);
          Torque_Control_B.kamm_data[6] = 500.0;
          Torque_Control_B.kamm_data[23] = 1536.0;
          Torque_Control_B.kamm_data[40] = 1529.0;
          Torque_Control_B.kamm_data[57] = 1521.0;
          Torque_Control_B.kamm_data[74] = 1509.0;
          Torque_Control_B.kamm_data[91] = 1491.0;
          Torque_Control_B.kamm_data[108] = 1459.0;
          Torque_Control_B.kamm_data[125] = 1395.0;
          Torque_Control_B.kamm_data[142] = 1230.0;
          Torque_Control_B.kamm_data[159] = 1032.0;
          Torque_Control_B.kamm_data[176] = 760.0;
          Torque_Control_B.kamm_data[193] = 411.0;
          Torque_Control_B.kamm_data[210] = (rtNaN);
          Torque_Control_B.kamm_data[227] = (rtNaN);
          Torque_Control_B.kamm_data[244] = (rtNaN);
          Torque_Control_B.kamm_data[261] = (rtNaN);
          Torque_Control_B.kamm_data[278] = (rtNaN);
          Torque_Control_B.kamm_data[295] = (rtNaN);
          Torque_Control_B.kamm_data[312] = (rtNaN);
          Torque_Control_B.kamm_data[329] = (rtNaN);
          Torque_Control_B.kamm_data[346] = (rtNaN);
          Torque_Control_B.kamm_data[363] = (rtNaN);
          Torque_Control_B.kamm_data[380] = (rtNaN);
          Torque_Control_B.kamm_data[397] = (rtNaN);
          Torque_Control_B.kamm_data[414] = (rtNaN);
          Torque_Control_B.kamm_data[431] = (rtNaN);
          Torque_Control_B.kamm_data[448] = (rtNaN);
          Torque_Control_B.kamm_data[465] = (rtNaN);
          Torque_Control_B.kamm_data[482] = (rtNaN);
          Torque_Control_B.kamm_data[499] = (rtNaN);
          Torque_Control_B.kamm_data[516] = (rtNaN);
          Torque_Control_B.kamm_data[533] = (rtNaN);
          Torque_Control_B.kamm_data[7] = 600.0;
          Torque_Control_B.kamm_data[24] = 1745.0;
          Torque_Control_B.kamm_data[41] = 1737.0;
          Torque_Control_B.kamm_data[58] = 1729.0;
          Torque_Control_B.kamm_data[75] = 1721.0;
          Torque_Control_B.kamm_data[92] = 1704.0;
          Torque_Control_B.kamm_data[109] = 1686.0;
          Torque_Control_B.kamm_data[126] = 1649.0;
          Torque_Control_B.kamm_data[143] = 1585.0;
          Torque_Control_B.kamm_data[160] = 1455.0;
          Torque_Control_B.kamm_data[177] = 1270.0;
          Torque_Control_B.kamm_data[194] = 1038.0;
          Torque_Control_B.kamm_data[211] = 756.0;
          Torque_Control_B.kamm_data[228] = 419.0;
          Torque_Control_B.kamm_data[245] = (rtNaN);
          Torque_Control_B.kamm_data[262] = (rtNaN);
          Torque_Control_B.kamm_data[279] = (rtNaN);
          Torque_Control_B.kamm_data[296] = (rtNaN);
          Torque_Control_B.kamm_data[313] = (rtNaN);
          Torque_Control_B.kamm_data[330] = (rtNaN);
          Torque_Control_B.kamm_data[347] = (rtNaN);
          Torque_Control_B.kamm_data[364] = (rtNaN);
          Torque_Control_B.kamm_data[381] = (rtNaN);
          Torque_Control_B.kamm_data[398] = (rtNaN);
          Torque_Control_B.kamm_data[415] = (rtNaN);
          Torque_Control_B.kamm_data[432] = (rtNaN);
          Torque_Control_B.kamm_data[449] = (rtNaN);
          Torque_Control_B.kamm_data[466] = (rtNaN);
          Torque_Control_B.kamm_data[483] = (rtNaN);
          Torque_Control_B.kamm_data[500] = (rtNaN);
          Torque_Control_B.kamm_data[517] = (rtNaN);
          Torque_Control_B.kamm_data[534] = (rtNaN);
          Torque_Control_B.kamm_data[8] = 700.0;
          Torque_Control_B.kamm_data[25] = 1964.0;
          Torque_Control_B.kamm_data[42] = 1956.0;
          Torque_Control_B.kamm_data[59] = 1948.0;
          Torque_Control_B.kamm_data[76] = 1940.0;
          Torque_Control_B.kamm_data[93] = 1926.0;
          Torque_Control_B.kamm_data[110] = 1909.0;
          Torque_Control_B.kamm_data[127] = 1884.0;
          Torque_Control_B.kamm_data[144] = 1848.0;
          Torque_Control_B.kamm_data[161] = 1777.0;
          Torque_Control_B.kamm_data[178] = 1656.0;
          Torque_Control_B.kamm_data[195] = 1484.0;
          Torque_Control_B.kamm_data[212] = 1278.0;
          Torque_Control_B.kamm_data[229] = 1029.0;
          Torque_Control_B.kamm_data[246] = 742.0;
          Torque_Control_B.kamm_data[263] = 416.0;
          Torque_Control_B.kamm_data[280] = (rtNaN);
          Torque_Control_B.kamm_data[297] = (rtNaN);
          Torque_Control_B.kamm_data[314] = (rtNaN);
          Torque_Control_B.kamm_data[331] = (rtNaN);
          Torque_Control_B.kamm_data[348] = (rtNaN);
          Torque_Control_B.kamm_data[365] = (rtNaN);
          Torque_Control_B.kamm_data[382] = (rtNaN);
          Torque_Control_B.kamm_data[399] = (rtNaN);
          Torque_Control_B.kamm_data[416] = (rtNaN);
          Torque_Control_B.kamm_data[433] = (rtNaN);
          Torque_Control_B.kamm_data[450] = (rtNaN);
          Torque_Control_B.kamm_data[467] = (rtNaN);
          Torque_Control_B.kamm_data[484] = (rtNaN);
          Torque_Control_B.kamm_data[501] = (rtNaN);
          Torque_Control_B.kamm_data[518] = (rtNaN);
          Torque_Control_B.kamm_data[535] = (rtNaN);
          Torque_Control_B.kamm_data[9] = 800.0;
          Torque_Control_B.kamm_data[26] = 2212.0;
          Torque_Control_B.kamm_data[43] = 2204.0;
          Torque_Control_B.kamm_data[60] = 2195.0;
          Torque_Control_B.kamm_data[77] = 2187.0;
          Torque_Control_B.kamm_data[94] = 2175.0;
          Torque_Control_B.kamm_data[111] = 2158.0;
          Torque_Control_B.kamm_data[128] = 2141.0;
          Torque_Control_B.kamm_data[145] = 2107.0;
          Torque_Control_B.kamm_data[162] = 2063.0;
          Torque_Control_B.kamm_data[179] = 1990.0;
          Torque_Control_B.kamm_data[196] = 1868.0;
          Torque_Control_B.kamm_data[213] = 1704.0;
          Torque_Control_B.kamm_data[230] = 1505.0;
          Torque_Control_B.kamm_data[247] = 1275.0;
          Torque_Control_B.kamm_data[264] = 1018.0;
          Torque_Control_B.kamm_data[281] = 730.0;
          Torque_Control_B.kamm_data[298] = 404.0;
          Torque_Control_B.kamm_data[315] = (rtNaN);
          Torque_Control_B.kamm_data[332] = (rtNaN);
          Torque_Control_B.kamm_data[349] = (rtNaN);
          Torque_Control_B.kamm_data[366] = (rtNaN);
          Torque_Control_B.kamm_data[383] = (rtNaN);
          Torque_Control_B.kamm_data[400] = (rtNaN);
          Torque_Control_B.kamm_data[417] = (rtNaN);
          Torque_Control_B.kamm_data[434] = (rtNaN);
          Torque_Control_B.kamm_data[451] = (rtNaN);
          Torque_Control_B.kamm_data[468] = (rtNaN);
          Torque_Control_B.kamm_data[485] = (rtNaN);
          Torque_Control_B.kamm_data[502] = (rtNaN);
          Torque_Control_B.kamm_data[519] = (rtNaN);
          Torque_Control_B.kamm_data[536] = (rtNaN);
          Torque_Control_B.kamm_data[10] = 900.0;
          Torque_Control_B.kamm_data[27] = 2465.0;
          Torque_Control_B.kamm_data[44] = 2456.0;
          Torque_Control_B.kamm_data[61] = 2448.0;
          Torque_Control_B.kamm_data[78] = 2439.0;
          Torque_Control_B.kamm_data[95] = 2428.0;
          Torque_Control_B.kamm_data[112] = 2411.0;
          Torque_Control_B.kamm_data[129] = 2394.0;
          Torque_Control_B.kamm_data[146] = 2367.0;
          Torque_Control_B.kamm_data[163] = 2333.0;
          Torque_Control_B.kamm_data[180] = 2279.0;
          Torque_Control_B.kamm_data[197] = 2200.0;
          Torque_Control_B.kamm_data[214] = 2081.0;
          Torque_Control_B.kamm_data[231] = 1921.0;
          Torque_Control_B.kamm_data[248] = 1729.0;
          Torque_Control_B.kamm_data[265] = 1512.0;
          Torque_Control_B.kamm_data[282] = 1268.0;
          Torque_Control_B.kamm_data[299] = 1002.0;
          Torque_Control_B.kamm_data[316] = 711.0;
          Torque_Control_B.kamm_data[333] = 345.0;
          Torque_Control_B.kamm_data[350] = (rtNaN);
          Torque_Control_B.kamm_data[367] = (rtNaN);
          Torque_Control_B.kamm_data[384] = (rtNaN);
          Torque_Control_B.kamm_data[401] = (rtNaN);
          Torque_Control_B.kamm_data[418] = (rtNaN);
          Torque_Control_B.kamm_data[435] = (rtNaN);
          Torque_Control_B.kamm_data[452] = (rtNaN);
          Torque_Control_B.kamm_data[469] = (rtNaN);
          Torque_Control_B.kamm_data[486] = (rtNaN);
          Torque_Control_B.kamm_data[503] = (rtNaN);
          Torque_Control_B.kamm_data[520] = (rtNaN);
          Torque_Control_B.kamm_data[537] = (rtNaN);
          Torque_Control_B.kamm_data[11] = 1000.0;
          Torque_Control_B.kamm_data[28] = 2684.0;
          Torque_Control_B.kamm_data[45] = 2675.0;
          Torque_Control_B.kamm_data[62] = 2666.0;
          Torque_Control_B.kamm_data[79] = 2657.0;
          Torque_Control_B.kamm_data[96] = 2647.0;
          Torque_Control_B.kamm_data[113] = 2629.0;
          Torque_Control_B.kamm_data[130] = 2612.0;
          Torque_Control_B.kamm_data[147] = 2592.0;
          Torque_Control_B.kamm_data[164] = 2558.0;
          Torque_Control_B.kamm_data[181] = 2520.0;
          Torque_Control_B.kamm_data[198] = 2462.0;
          Torque_Control_B.kamm_data[215] = 2378.0;
          Torque_Control_B.kamm_data[232] = 2262.0;
          Torque_Control_B.kamm_data[249] = 2119.0;
          Torque_Control_B.kamm_data[266] = 1940.0;
          Torque_Control_B.kamm_data[283] = 1737.0;
          Torque_Control_B.kamm_data[300] = 1508.0;
          Torque_Control_B.kamm_data[317] = 1259.0;
          Torque_Control_B.kamm_data[334] = 989.0;
          Torque_Control_B.kamm_data[351] = 680.0;
          Torque_Control_B.kamm_data[368] = 240.0;
          Torque_Control_B.kamm_data[385] = (rtNaN);
          Torque_Control_B.kamm_data[402] = (rtNaN);
          Torque_Control_B.kamm_data[419] = (rtNaN);
          Torque_Control_B.kamm_data[436] = (rtNaN);
          Torque_Control_B.kamm_data[453] = (rtNaN);
          Torque_Control_B.kamm_data[470] = (rtNaN);
          Torque_Control_B.kamm_data[487] = (rtNaN);
          Torque_Control_B.kamm_data[504] = (rtNaN);
          Torque_Control_B.kamm_data[521] = (rtNaN);
          Torque_Control_B.kamm_data[538] = (rtNaN);
          Torque_Control_B.kamm_data[12] = 1100.0;
          Torque_Control_B.kamm_data[29] = 2853.0;
          Torque_Control_B.kamm_data[46] = 2843.0;
          Torque_Control_B.kamm_data[63] = 2833.0;
          Torque_Control_B.kamm_data[80] = 2822.0;
          Torque_Control_B.kamm_data[97] = 2811.0;
          Torque_Control_B.kamm_data[114] = 2795.0;
          Torque_Control_B.kamm_data[131] = 2775.0;
          Torque_Control_B.kamm_data[148] = 2755.0;
          Torque_Control_B.kamm_data[165] = 2728.0;
          Torque_Control_B.kamm_data[182] = 2693.0;
          Torque_Control_B.kamm_data[199] = 2651.0;
          Torque_Control_B.kamm_data[216] = 2591.0;
          Torque_Control_B.kamm_data[233] = 2510.0;
          Torque_Control_B.kamm_data[250] = 2412.0;
          Torque_Control_B.kamm_data[267] = 2282.0;
          Torque_Control_B.kamm_data[284] = 2124.0;
          Torque_Control_B.kamm_data[301] = 1940.0;
          Torque_Control_B.kamm_data[318] = 1735.0;
          Torque_Control_B.kamm_data[335] = 1504.0;
          Torque_Control_B.kamm_data[352] = 1250.0;
          Torque_Control_B.kamm_data[369] = 962.0;
          Torque_Control_B.kamm_data[386] = 608.0;
          Torque_Control_B.kamm_data[403] = 108.0;
          Torque_Control_B.kamm_data[420] = (rtNaN);
          Torque_Control_B.kamm_data[437] = (rtNaN);
          Torque_Control_B.kamm_data[454] = (rtNaN);
          Torque_Control_B.kamm_data[471] = (rtNaN);
          Torque_Control_B.kamm_data[488] = (rtNaN);
          Torque_Control_B.kamm_data[505] = (rtNaN);
          Torque_Control_B.kamm_data[522] = (rtNaN);
          Torque_Control_B.kamm_data[539] = (rtNaN);
          Torque_Control_B.kamm_data[13] = 1200.0;
          Torque_Control_B.kamm_data[30] = 2999.0;
          Torque_Control_B.kamm_data[47] = 2988.0;
          Torque_Control_B.kamm_data[64] = 2976.0;
          Torque_Control_B.kamm_data[81] = 2964.0;
          Torque_Control_B.kamm_data[98] = 2952.0;
          Torque_Control_B.kamm_data[115] = 2936.0;
          Torque_Control_B.kamm_data[132] = 2914.0;
          Torque_Control_B.kamm_data[149] = 2893.0;
          Torque_Control_B.kamm_data[166] = 2872.0;
          Torque_Control_B.kamm_data[183] = 2837.0;
          Torque_Control_B.kamm_data[200] = 2799.0;
          Torque_Control_B.kamm_data[217] = 2755.0;
          Torque_Control_B.kamm_data[234] = 2694.0;
          Torque_Control_B.kamm_data[251] = 2619.0;
          Torque_Control_B.kamm_data[268] = 2527.0;
          Torque_Control_B.kamm_data[285] = 2412.0;
          Torque_Control_B.kamm_data[302] = 2275.0;
          Torque_Control_B.kamm_data[319] = 2114.0;
          Torque_Control_B.kamm_data[336] = 1936.0;
          Torque_Control_B.kamm_data[353] = 1729.0;
          Torque_Control_B.kamm_data[370] = 1507.0;
          Torque_Control_B.kamm_data[387] = 1233.0;
          Torque_Control_B.kamm_data[404] = 896.0;
          Torque_Control_B.kamm_data[421] = 461.0;
          Torque_Control_B.kamm_data[438] = (rtNaN);
          Torque_Control_B.kamm_data[455] = (rtNaN);
          Torque_Control_B.kamm_data[472] = (rtNaN);
          Torque_Control_B.kamm_data[489] = (rtNaN);
          Torque_Control_B.kamm_data[506] = (rtNaN);
          Torque_Control_B.kamm_data[523] = (rtNaN);
          Torque_Control_B.kamm_data[540] = (rtNaN);
          Torque_Control_B.kamm_data[14] = 1300.0;
          Torque_Control_B.kamm_data[31] = 3128.0;
          Torque_Control_B.kamm_data[48] = 3115.0;
          Torque_Control_B.kamm_data[65] = 3101.0;
          Torque_Control_B.kamm_data[82] = 3087.0;
          Torque_Control_B.kamm_data[99] = 3074.0;
          Torque_Control_B.kamm_data[116] = 3059.0;
          Torque_Control_B.kamm_data[133] = 3035.0;
          Torque_Control_B.kamm_data[150] = 3012.0;
          Torque_Control_B.kamm_data[167] = 2988.0;
          Torque_Control_B.kamm_data[184] = 2962.0;
          Torque_Control_B.kamm_data[201] = 2923.0;
          Torque_Control_B.kamm_data[218] = 2884.0;
          Torque_Control_B.kamm_data[235] = 2838.0;
          Torque_Control_B.kamm_data[252] = 2778.0;
          Torque_Control_B.kamm_data[269] = 2709.0;
          Torque_Control_B.kamm_data[286] = 2625.0;
          Torque_Control_B.kamm_data[303] = 2517.0;
          Torque_Control_B.kamm_data[320] = 2396.0;
          Torque_Control_B.kamm_data[337] = 2259.0;
          Torque_Control_B.kamm_data[354] = 2104.0;
          Torque_Control_B.kamm_data[371] = 1924.0;
          Torque_Control_B.kamm_data[388] = 1730.0;
          Torque_Control_B.kamm_data[405] = 1484.0;
          Torque_Control_B.kamm_data[422] = 1169.0;
          Torque_Control_B.kamm_data[439] = 772.0;
          Torque_Control_B.kamm_data[456] = 213.0;
          Torque_Control_B.kamm_data[473] = (rtNaN);
          Torque_Control_B.kamm_data[490] = (rtNaN);
          Torque_Control_B.kamm_data[507] = (rtNaN);
          Torque_Control_B.kamm_data[524] = (rtNaN);
          Torque_Control_B.kamm_data[541] = (rtNaN);
          Torque_Control_B.kamm_data[15] = 1400.0;
          Torque_Control_B.kamm_data[32] = 3228.0;
          Torque_Control_B.kamm_data[49] = 3215.0;
          Torque_Control_B.kamm_data[66] = 3201.0;
          Torque_Control_B.kamm_data[83] = 3187.0;
          Torque_Control_B.kamm_data[100] = 3172.0;
          Torque_Control_B.kamm_data[117] = 3157.0;
          Torque_Control_B.kamm_data[134] = 3134.0;
          Torque_Control_B.kamm_data[151] = 3111.0;
          Torque_Control_B.kamm_data[168] = 3087.0;
          Torque_Control_B.kamm_data[185] = 3063.0;
          Torque_Control_B.kamm_data[202] = 3026.0;
          Torque_Control_B.kamm_data[219] = 2989.0;
          Torque_Control_B.kamm_data[236] = 2952.0;
          Torque_Control_B.kamm_data[253] = 2896.0;
          Torque_Control_B.kamm_data[270] = 2841.0;
          Torque_Control_B.kamm_data[287] = 2772.0;
          Torque_Control_B.kamm_data[304] = 2691.0;
          Torque_Control_B.kamm_data[321] = 2603.0;
          Torque_Control_B.kamm_data[338] = 2500.0;
          Torque_Control_B.kamm_data[355] = 2379.0;
          Torque_Control_B.kamm_data[372] = 2243.0;
          Torque_Control_B.kamm_data[389] = 2091.0;
          Torque_Control_B.kamm_data[406] = 1927.0;
          Torque_Control_B.kamm_data[423] = 1713.0;
          Torque_Control_B.kamm_data[440] = 1414.0;
          Torque_Control_B.kamm_data[457] = 1030.0;
          Torque_Control_B.kamm_data[474] = 553.0;
          Torque_Control_B.kamm_data[491] = (rtNaN);
          Torque_Control_B.kamm_data[508] = (rtNaN);
          Torque_Control_B.kamm_data[525] = (rtNaN);
          Torque_Control_B.kamm_data[542] = (rtNaN);
          Torque_Control_B.kamm_data[16] = 1500.0;
          Torque_Control_B.kamm_data[33] = 3327.0;
          Torque_Control_B.kamm_data[50] = 3312.0;
          Torque_Control_B.kamm_data[67] = 3296.0;
          Torque_Control_B.kamm_data[84] = 3280.0;
          Torque_Control_B.kamm_data[101] = 3263.0;
          Torque_Control_B.kamm_data[118] = 3247.0;
          Torque_Control_B.kamm_data[135] = 3223.0;
          Torque_Control_B.kamm_data[152] = 3198.0;
          Torque_Control_B.kamm_data[169] = 3173.0;
          Torque_Control_B.kamm_data[186] = 3147.0;
          Torque_Control_B.kamm_data[203] = 3116.0;
          Torque_Control_B.kamm_data[220] = 3078.0;
          Torque_Control_B.kamm_data[237] = 3040.0;
          Torque_Control_B.kamm_data[254] = 3001.0;
          Torque_Control_B.kamm_data[271] = 2947.0;
          Torque_Control_B.kamm_data[288] = 2893.0;
          Torque_Control_B.kamm_data[305] = 2828.0;
          Torque_Control_B.kamm_data[322] = 2756.0;
          Torque_Control_B.kamm_data[339] = 2670.0;
          Torque_Control_B.kamm_data[356] = 2576.0;
          Torque_Control_B.kamm_data[373] = 2471.0;
          Torque_Control_B.kamm_data[390] = 2353.0;
          Torque_Control_B.kamm_data[407] = 2228.0;
          Torque_Control_B.kamm_data[424] = 2100.0;
          Torque_Control_B.kamm_data[441] = 1921.0;
          Torque_Control_B.kamm_data[458] = 1649.0;
          Torque_Control_B.kamm_data[475] = 1278.0;
          Torque_Control_B.kamm_data[492] = 814.0;
          Torque_Control_B.kamm_data[509] = 217.0;
          Torque_Control_B.kamm_data[526] = (rtNaN);
          Torque_Control_B.kamm_data[543] = (rtNaN);
          mz = 1.0;
          Mz = 16.0;
          k = 8.0;
          p = 15.0;
          while (p != 1.0) {
            p = Torque_Control_B.kamm_data[(int32_T)k];
            if (rtb_Gain_f > p) {
              mz = k;
            } else if (rtb_Gain_f < p) {
              Mz = k;
            }

            k = floor((Mz + mz) / 2.0);
            p = Mz - mz;
            if (rtb_Gain_f == Torque_Control_B.kamm_data[(int32_T)Mz]) {
              p = 1.0;
              mz = Mz;
            } else if (rtb_Gain_f == Torque_Control_B.kamm_data[(int32_T)mz]) {
              p = 1.0;
              Mz = mz;
            } else if (rtb_Gain_f == Torque_Control_B.kamm_data[(int32_T)k]) {
              p = 1.0;
              Mz = k;
              mz = k;
            }
          }

          my = 1.0;
          My = 31.0;
          k = 16.0;
          p = 30.0;
          while (p != 1.0) {
            if (Torque_Control_B.kamm_data[17 * (int32_T)k] > 0.0) {
              My = k;
            }

            k = floor((My + my) / 2.0);
            p = My - my;
            if (Torque_Control_B.kamm_data[17 * (int32_T)My] == 0.0) {
              p = 1.0;
              my = My;
            } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == 0.0) {
              p = 1.0;
              My = my;
            } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == 0.0) {
              p = 1.0;
              My = k;
              my = k;
            }
          }

          if ((Mz == mz) && (My != my)) {
            r1 = 17 * (int32_T)my;
            kamm_data[0] = Torque_Control_B.kamm_data[r1];
            r2 = 17 * (int32_T)My;
            kamm_data[1] = Torque_Control_B.kamm_data[r2];
            kamm_data_0[0] = Torque_Control_B.kamm_data[r1 + (int32_T)mz];
            kamm_data_0[1] = Torque_Control_B.kamm_data[r2 + (int32_T)mz];
            polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
            rtb_alpha_m = b_a[0] * 0.0 + b_a[1];
          } else if ((Mz != mz) && (My == my)) {
            kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
            kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
            kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)mz];
            kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)Mz];
            polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
            rtb_alpha_m = b_a[0] * rtb_Gain_f + b_a[1];
          } else if ((Mz == mz) && (My == my)) {
            rtb_alpha_m = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
              Mz];
          } else {
            tmp[0] = 1.0;
            tmp[1] = 1.0;
            tmp[2] = 1.0;
            tmp[3] = 1.0;
            p = Torque_Control_B.kamm_data[(int32_T)mz];
            tmp[4] = p;
            tmp[5] = p;
            p = Torque_Control_B.kamm_data[(int32_T)Mz];
            tmp[6] = p;
            tmp[7] = p;
            p = Torque_Control_B.kamm_data[17 * (int32_T)my];
            tmp[8] = p;
            k = Torque_Control_B.kamm_data[17 * (int32_T)My];
            tmp[9] = k;
            tmp[10] = p;
            tmp[11] = k;
            kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)mz];
            kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
              (int32_T)mz];
            kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)Mz];
            kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
              (int32_T)Mz];
            mldivide_8ZFDevWm(tmp, kamm_data_1, a);
            rtb_alpha_m = (a[1] * rtb_Gain_f + a[0]) + a[2] * 0.0;
          }

          mz = 1.0;
          Mz = 16.0;
          k = 8.0;
          p = 15.0;
          while (p != 1.0) {
            p = Torque_Control_B.kamm_data[(int32_T)k];
            if (rtb_Gain_f > p) {
              mz = k;
            } else if (rtb_Gain_f < p) {
              Mz = k;
            }

            k = floor((Mz + mz) / 2.0);
            p = Mz - mz;
            if (rtb_Gain_f == Torque_Control_B.kamm_data[(int32_T)Mz]) {
              p = 1.0;
              mz = Mz;
            } else if (rtb_Gain_f == Torque_Control_B.kamm_data[(int32_T)mz]) {
              p = 1.0;
              Mz = mz;
            } else if (rtb_Gain_f == Torque_Control_B.kamm_data[(int32_T)k]) {
              p = 1.0;
              Mz = k;
              mz = k;
            }
          }

          my = 1.0;
          My = 31.0;
          k = 16.0;
          p = 30.0;
          while (p != 1.0) {
            if (Torque_Control_B.kamm_data[17 * (int32_T)k] > 0.0) {
              My = k;
            }

            k = floor((My + my) / 2.0);
            p = My - my;
            if (Torque_Control_B.kamm_data[17 * (int32_T)My] == 0.0) {
              p = 1.0;
              my = My;
            } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == 0.0) {
              p = 1.0;
              My = my;
            } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == 0.0) {
              p = 1.0;
              My = k;
              my = k;
            }
          }

          if ((Mz == mz) && (My != my)) {
            r1 = 17 * (int32_T)my;
            kamm_data[0] = Torque_Control_B.kamm_data[r1];
            r2 = 17 * (int32_T)My;
            kamm_data[1] = Torque_Control_B.kamm_data[r2];
            kamm_data_0[0] = Torque_Control_B.kamm_data[r1 + (int32_T)mz];
            kamm_data_0[1] = Torque_Control_B.kamm_data[r2 + (int32_T)mz];
            polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
            mz = b_a[0] * 0.0 + b_a[1];
          } else if ((Mz != mz) && (My == my)) {
            kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
            kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
            kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)mz];
            kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)Mz];
            polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
            mz = b_a[0] * rtb_Gain_f + b_a[1];
          } else if ((Mz == mz) && (My == my)) {
            mz = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)Mz];
          } else {
            tmp[0] = 1.0;
            tmp[1] = 1.0;
            tmp[2] = 1.0;
            tmp[3] = 1.0;
            p = Torque_Control_B.kamm_data[(int32_T)mz];
            tmp[4] = p;
            tmp[5] = p;
            p = Torque_Control_B.kamm_data[(int32_T)Mz];
            tmp[6] = p;
            tmp[7] = p;
            p = Torque_Control_B.kamm_data[17 * (int32_T)my];
            tmp[8] = p;
            k = Torque_Control_B.kamm_data[17 * (int32_T)My];
            tmp[9] = k;
            tmp[10] = p;
            tmp[11] = k;
            kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)mz];
            kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
              (int32_T)mz];
            kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)Mz];
            kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
              (int32_T)Mz];
            mldivide_8ZFDevWm(tmp, kamm_data_1, a);
            mz = (a[1] * rtb_Gain_f + a[0]) + a[2] * 0.0;
          }

          /* Product: '<S137>/Product' incorporates:
           *  MATLAB Function: '<S137>/Kamm_Circle LatD'
           */
          rtb_Product_e = rtb_alpha_m * Torque_Control_B.Saturation_hh;

          /* Product: '<S137>/Product1' incorporates:
           *  MATLAB Function: '<S137>/Kamm_Circle LatD'
           */
          rtb_Product1_h = mz * Torque_Control_B.Saturation_hh;

          /* MATLAB Function: '<S105>/MATLAB Function' incorporates:
           *  Constant: '<S105>/Constant4'
           */
          Torque_Control_MATLABFunction_f(-1.0, rtb_Product_e,
            &Torque_Control_B.sf_MATLABFunction_f);

          /* MATLAB Function: '<S105>/MATLAB Function1' incorporates:
           *  Constant: '<S105>/Constant3'
           */
          Torque_Control_MATLABFunction_f(-1.0, rtb_Product1_h,
            &Torque_Control_B.sf_MATLABFunction1_d);

          /* Merge: '<S70>/Merge3' incorporates:
           *  SignalConversion generated from: '<S105>/Fx_RL '
           */
          Torque_Control_B.Merge3_d =
            Torque_Control_B.sf_MATLABFunction1_d.value;

          /* Merge: '<S70>/Merge2' incorporates:
           *  SignalConversion generated from: '<S105>/Fx_RR '
           */
          Torque_Control_B.Merge2_i = Torque_Control_B.sf_MATLABFunction_f.value;

          /* Merge: '<S70>/Merge6' incorporates:
           *  Constant: '<S105>/Constant5'
           *  SignalConversion generated from: '<S105>/Fy_R'
           */
          Torque_Control_B.Merge6 = 0.0;

          /* Merge: '<S70>/Merge5' incorporates:
           *  Constant: '<S105>/Constant7'
           *  SignalConversion generated from: '<S105>/Handling [-] (-inf,inf)'
           */
          Torque_Control_B.Merge5 = 0.0;

          /* Merge: '<S70>/Merge7' incorporates:
           *  Constant: '<S105>/Constant6'
           *  SignalConversion generated from: '<S105>/Flag CarBehavior'
           */
          Torque_Control_B.Merge7 = 0.0;

          /* End of Outputs for SubSystem: '<S70>/Longitudinal Dynamics' */
        } else {
          real_T My;
          real_T X_idx_0;
          real_T b_idx_0;
          real_T my;
          real_T rtb_Divide_b;
          int32_T r1;
          int32_T r2;
          int32_T r3;

          /* Outputs for IfAction SubSystem: '<S70>/Lateral Dynamics' incorporates:
           *  ActionPort: '<S104>/Action Port'
           */
          /* Merge: '<S70>/Merge' incorporates:
           *  Constant: '<S104>/Constant1'
           *  SignalConversion generated from: '<S104>/Fx_FR'
           */
          Torque_Control_B.Merge_l = 0.0;

          /* Merge: '<S70>/Merge1' incorporates:
           *  Constant: '<S104>/Constant2'
           *  SignalConversion generated from: '<S104>/Fx_FL'
           */
          Torque_Control_B.Merge1_e = 0.0;

          /* Product: '<S132>/Divide' incorporates:
           *  Constant: '<S132>/Steering_Ratio [-]'
           */
          rtb_Gain_f = -Torque_Control_U.SteeringSensor_Value / 3.72;

          /* MATLAB Function: '<S132>/Bicycle Model' incorporates:
           *  Constant: '<S132>/Constant7'
           *  Constant: '<S132>/Constant8'
           *  Constant: '<S132>/Wheelbase [m]'
           *  Inport: '<Root>/el_Vel_X'
           */
          rtb_value_a = rtb_Gain_f * 2.0 * 3.1415926535897931 / 360.0;
          A[0] = Torque_Control_ConstB.u602pi;
          A[3] = Torque_Control_ConstB.u602pi_d;
          A[6] = -360.0 * Torque_Control_U.el_Vel_X;
          A[1] = 0.92 * Torque_Control_ConstB.u602pi;
          A[4] = -0.61 * Torque_Control_ConstB.u602pi_d;
          A[7] = 0.0;
          A[2] = -1.0;
          A[5] = 1.0;
          A[8] = 1.53 / Torque_Control_U.el_Vel_X;
          a[0] = 0.0;
          a[1] = 0.0;
          a[2] = rtb_value_a;
          r1 = 0;
          r2 = 1;
          r3 = 2;
          maxval = fabs(Torque_Control_ConstB.u602pi);
          a21 = fabs(A[1]);
          if (a21 > maxval) {
            maxval = a21;
            r1 = 1;
            r2 = 0;
          }

          if (maxval < 1.0) {
            r1 = 2;
            r2 = 1;
            r3 = 0;
          }

          A[r2] /= A[r1];
          A[r3] /= A[r1];
          A[r2 + 3] -= A[r1 + 3] * A[r2];
          A[r3 + 3] -= A[r1 + 3] * A[r3];
          A[r2 + 6] -= A[r1 + 6] * A[r2];
          A[r3 + 6] -= A[r1 + 6] * A[r3];
          if (fabs(A[r3 + 3]) > fabs(A[r2 + 3])) {
            int32_T rtemp;
            rtemp = r2;
            r2 = r3;
            r3 = rtemp;
          }

          A[r3 + 3] /= A[r2 + 3];
          A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
          X_idx_1 = a[r2] - a[r1] * A[r2];
          maxval = ((a[r3] - a[r1] * A[r3]) - A[r3 + 3] * X_idx_1) / A[r3 + 6];
          X_idx_1 = (X_idx_1 - A[r2 + 6] * maxval) / A[r2 + 3];
          X_idx_0 = ((a[r1] - A[r1 + 6] * maxval) - A[r1 + 3] * X_idx_1) / A[r1];
          rtb_alpha_m = atan((Torque_Control_U.el_Vel_X * tan(X_idx_1) + maxval *
                              0.61) / Torque_Control_U.el_Vel_X);
          b_idx_0 = rtb_alpha_m;
          r1 = 0;
          if (rtIsNaN(rtb_alpha_m)) {
            r1 = 1;
          }

          if (r1 - 1 >= 0) {
            b_idx_0 = 0.0;
          }

          Torque_Control_B.radius = Torque_Control_U.el_Vel_X / maxval;
          Torque_Control_B.yf = Torque_Control_ConstB.u602pi * X_idx_0;
          Torque_Control_B.yr = Torque_Control_ConstB.u602pi_d * X_idx_1;

          /* Sum: '<S104>/Sum3' incorporates:
           *  Inport: '<Root>/el_GYRO_Y'
           *  MATLAB Function: '<S132>/Bicycle Model'
           */
          Torque_Control_B.Sum3 = maxval - Torque_Control_U.el_GYRO_Y;

          /* Product: '<S135>/Divide' incorporates:
           *  Constant: '<S103>/Constant1'
           *  Constant: '<S104>/Yaw_Inertia [kg//m^3]'
           *  Product: '<S135>/Product'
           */
          Torque_Control_B.Divide_f = Torque_Control_B.Sum3 * 43.21 / 0.025;

          /* Product: '<S134>/Divide' */
          rtb_Divide_b = Torque_Control_B.Divide_f /
            Torque_Control_ConstB.Divide1;

          /* Sum: '<S104>/Sum' */
          maxval = Torque_Control_B.Merge2 + Torque_Control_B.Merge3_o;

          /* Gain: '<S104>/Fy per wheel' incorporates:
           *  Gain: '<S104>/Gravity'
           *  Inport: '<Root>/el_ACCEL_Y'
           *  Product: '<S104>/Product'
           */
          a21 = 0.1019367991845056 * maxval * Torque_Control_U.el_ACCEL_Y * 0.5;

          /* MATLAB Function: '<S128>/Kamm_Circle LatD' */
          Torque_Control_B.kamm_data[0] = (rtNaN);
          Torque_Control_B.kamm_data[17] = 0.0;
          Torque_Control_B.kamm_data[34] = 100.0;
          Torque_Control_B.kamm_data[51] = 200.0;
          Torque_Control_B.kamm_data[68] = 300.0;
          Torque_Control_B.kamm_data[85] = 400.0;
          Torque_Control_B.kamm_data[102] = 500.0;
          Torque_Control_B.kamm_data[119] = 600.0;
          Torque_Control_B.kamm_data[136] = 700.0;
          Torque_Control_B.kamm_data[153] = 800.0;
          Torque_Control_B.kamm_data[170] = 900.0;
          Torque_Control_B.kamm_data[187] = 1000.0;
          Torque_Control_B.kamm_data[204] = 1100.0;
          Torque_Control_B.kamm_data[221] = 1200.0;
          Torque_Control_B.kamm_data[238] = 1300.0;
          Torque_Control_B.kamm_data[255] = 1400.0;
          Torque_Control_B.kamm_data[272] = 1500.0;
          Torque_Control_B.kamm_data[289] = 1600.0;
          Torque_Control_B.kamm_data[306] = 1700.0;
          Torque_Control_B.kamm_data[323] = 1800.0;
          Torque_Control_B.kamm_data[340] = 1900.0;
          Torque_Control_B.kamm_data[357] = 2000.0;
          Torque_Control_B.kamm_data[374] = 2100.0;
          Torque_Control_B.kamm_data[391] = 2200.0;
          Torque_Control_B.kamm_data[408] = 2300.0;
          Torque_Control_B.kamm_data[425] = 2400.0;
          Torque_Control_B.kamm_data[442] = 2500.0;
          Torque_Control_B.kamm_data[459] = 2600.0;
          Torque_Control_B.kamm_data[476] = 2700.0;
          Torque_Control_B.kamm_data[493] = 2800.0;
          Torque_Control_B.kamm_data[510] = 2900.0;
          Torque_Control_B.kamm_data[527] = 3000.0;
          Torque_Control_B.kamm_data[1] = 0.0;
          Torque_Control_B.kamm_data[18] = 0.0;
          Torque_Control_B.kamm_data[35] = (rtNaN);
          Torque_Control_B.kamm_data[52] = (rtNaN);
          Torque_Control_B.kamm_data[69] = (rtNaN);
          Torque_Control_B.kamm_data[86] = (rtNaN);
          Torque_Control_B.kamm_data[103] = (rtNaN);
          Torque_Control_B.kamm_data[120] = (rtNaN);
          Torque_Control_B.kamm_data[137] = (rtNaN);
          Torque_Control_B.kamm_data[154] = (rtNaN);
          Torque_Control_B.kamm_data[171] = (rtNaN);
          Torque_Control_B.kamm_data[188] = (rtNaN);
          Torque_Control_B.kamm_data[205] = (rtNaN);
          Torque_Control_B.kamm_data[222] = (rtNaN);
          Torque_Control_B.kamm_data[239] = (rtNaN);
          Torque_Control_B.kamm_data[256] = (rtNaN);
          Torque_Control_B.kamm_data[273] = (rtNaN);
          Torque_Control_B.kamm_data[290] = (rtNaN);
          Torque_Control_B.kamm_data[307] = (rtNaN);
          Torque_Control_B.kamm_data[324] = (rtNaN);
          Torque_Control_B.kamm_data[341] = (rtNaN);
          Torque_Control_B.kamm_data[358] = (rtNaN);
          Torque_Control_B.kamm_data[375] = (rtNaN);
          Torque_Control_B.kamm_data[392] = (rtNaN);
          Torque_Control_B.kamm_data[409] = (rtNaN);
          Torque_Control_B.kamm_data[426] = (rtNaN);
          Torque_Control_B.kamm_data[443] = (rtNaN);
          Torque_Control_B.kamm_data[460] = (rtNaN);
          Torque_Control_B.kamm_data[477] = (rtNaN);
          Torque_Control_B.kamm_data[494] = (rtNaN);
          Torque_Control_B.kamm_data[511] = (rtNaN);
          Torque_Control_B.kamm_data[528] = (rtNaN);
          Torque_Control_B.kamm_data[2] = 100.0;
          Torque_Control_B.kamm_data[19] = 350.0;
          Torque_Control_B.kamm_data[36] = 340.0;
          Torque_Control_B.kamm_data[53] = 156.0;
          Torque_Control_B.kamm_data[70] = (rtNaN);
          Torque_Control_B.kamm_data[87] = (rtNaN);
          Torque_Control_B.kamm_data[104] = (rtNaN);
          Torque_Control_B.kamm_data[121] = (rtNaN);
          Torque_Control_B.kamm_data[138] = (rtNaN);
          Torque_Control_B.kamm_data[155] = (rtNaN);
          Torque_Control_B.kamm_data[172] = (rtNaN);
          Torque_Control_B.kamm_data[189] = (rtNaN);
          Torque_Control_B.kamm_data[206] = (rtNaN);
          Torque_Control_B.kamm_data[223] = (rtNaN);
          Torque_Control_B.kamm_data[240] = (rtNaN);
          Torque_Control_B.kamm_data[257] = (rtNaN);
          Torque_Control_B.kamm_data[274] = (rtNaN);
          Torque_Control_B.kamm_data[291] = (rtNaN);
          Torque_Control_B.kamm_data[308] = (rtNaN);
          Torque_Control_B.kamm_data[325] = (rtNaN);
          Torque_Control_B.kamm_data[342] = (rtNaN);
          Torque_Control_B.kamm_data[359] = (rtNaN);
          Torque_Control_B.kamm_data[376] = (rtNaN);
          Torque_Control_B.kamm_data[393] = (rtNaN);
          Torque_Control_B.kamm_data[410] = (rtNaN);
          Torque_Control_B.kamm_data[427] = (rtNaN);
          Torque_Control_B.kamm_data[444] = (rtNaN);
          Torque_Control_B.kamm_data[461] = (rtNaN);
          Torque_Control_B.kamm_data[478] = (rtNaN);
          Torque_Control_B.kamm_data[495] = (rtNaN);
          Torque_Control_B.kamm_data[512] = (rtNaN);
          Torque_Control_B.kamm_data[529] = (rtNaN);
          Torque_Control_B.kamm_data[3] = 200.0;
          Torque_Control_B.kamm_data[20] = 688.0;
          Torque_Control_B.kamm_data[37] = 676.0;
          Torque_Control_B.kamm_data[54] = 654.0;
          Torque_Control_B.kamm_data[71] = 573.0;
          Torque_Control_B.kamm_data[88] = 269.0;
          Torque_Control_B.kamm_data[105] = (rtNaN);
          Torque_Control_B.kamm_data[122] = (rtNaN);
          Torque_Control_B.kamm_data[139] = (rtNaN);
          Torque_Control_B.kamm_data[156] = (rtNaN);
          Torque_Control_B.kamm_data[173] = (rtNaN);
          Torque_Control_B.kamm_data[190] = (rtNaN);
          Torque_Control_B.kamm_data[207] = (rtNaN);
          Torque_Control_B.kamm_data[224] = (rtNaN);
          Torque_Control_B.kamm_data[241] = (rtNaN);
          Torque_Control_B.kamm_data[258] = (rtNaN);
          Torque_Control_B.kamm_data[275] = (rtNaN);
          Torque_Control_B.kamm_data[292] = (rtNaN);
          Torque_Control_B.kamm_data[309] = (rtNaN);
          Torque_Control_B.kamm_data[326] = (rtNaN);
          Torque_Control_B.kamm_data[343] = (rtNaN);
          Torque_Control_B.kamm_data[360] = (rtNaN);
          Torque_Control_B.kamm_data[377] = (rtNaN);
          Torque_Control_B.kamm_data[394] = (rtNaN);
          Torque_Control_B.kamm_data[411] = (rtNaN);
          Torque_Control_B.kamm_data[428] = (rtNaN);
          Torque_Control_B.kamm_data[445] = (rtNaN);
          Torque_Control_B.kamm_data[462] = (rtNaN);
          Torque_Control_B.kamm_data[479] = (rtNaN);
          Torque_Control_B.kamm_data[496] = (rtNaN);
          Torque_Control_B.kamm_data[513] = (rtNaN);
          Torque_Control_B.kamm_data[530] = (rtNaN);
          Torque_Control_B.kamm_data[4] = 300.0;
          Torque_Control_B.kamm_data[21] = 1002.0;
          Torque_Control_B.kamm_data[38] = 994.0;
          Torque_Control_B.kamm_data[55] = 982.0;
          Torque_Control_B.kamm_data[72] = 959.0;
          Torque_Control_B.kamm_data[89] = 888.0;
          Torque_Control_B.kamm_data[106] = 694.0;
          Torque_Control_B.kamm_data[123] = 345.0;
          Torque_Control_B.kamm_data[140] = (rtNaN);
          Torque_Control_B.kamm_data[157] = (rtNaN);
          Torque_Control_B.kamm_data[174] = (rtNaN);
          Torque_Control_B.kamm_data[191] = (rtNaN);
          Torque_Control_B.kamm_data[208] = (rtNaN);
          Torque_Control_B.kamm_data[225] = (rtNaN);
          Torque_Control_B.kamm_data[242] = (rtNaN);
          Torque_Control_B.kamm_data[259] = (rtNaN);
          Torque_Control_B.kamm_data[276] = (rtNaN);
          Torque_Control_B.kamm_data[293] = (rtNaN);
          Torque_Control_B.kamm_data[310] = (rtNaN);
          Torque_Control_B.kamm_data[327] = (rtNaN);
          Torque_Control_B.kamm_data[344] = (rtNaN);
          Torque_Control_B.kamm_data[361] = (rtNaN);
          Torque_Control_B.kamm_data[378] = (rtNaN);
          Torque_Control_B.kamm_data[395] = (rtNaN);
          Torque_Control_B.kamm_data[412] = (rtNaN);
          Torque_Control_B.kamm_data[429] = (rtNaN);
          Torque_Control_B.kamm_data[446] = (rtNaN);
          Torque_Control_B.kamm_data[463] = (rtNaN);
          Torque_Control_B.kamm_data[480] = (rtNaN);
          Torque_Control_B.kamm_data[497] = (rtNaN);
          Torque_Control_B.kamm_data[514] = (rtNaN);
          Torque_Control_B.kamm_data[531] = (rtNaN);
          Torque_Control_B.kamm_data[5] = 400.0;
          Torque_Control_B.kamm_data[22] = 1295.0;
          Torque_Control_B.kamm_data[39] = 1288.0;
          Torque_Control_B.kamm_data[56] = 1280.0;
          Torque_Control_B.kamm_data[73] = 1263.0;
          Torque_Control_B.kamm_data[90] = 1235.0;
          Torque_Control_B.kamm_data[107] = 1168.0;
          Torque_Control_B.kamm_data[124] = 1001.0;
          Torque_Control_B.kamm_data[141] = 740.0;
          Torque_Control_B.kamm_data[158] = 389.0;
          Torque_Control_B.kamm_data[175] = (rtNaN);
          Torque_Control_B.kamm_data[192] = (rtNaN);
          Torque_Control_B.kamm_data[209] = (rtNaN);
          Torque_Control_B.kamm_data[226] = (rtNaN);
          Torque_Control_B.kamm_data[243] = (rtNaN);
          Torque_Control_B.kamm_data[260] = (rtNaN);
          Torque_Control_B.kamm_data[277] = (rtNaN);
          Torque_Control_B.kamm_data[294] = (rtNaN);
          Torque_Control_B.kamm_data[311] = (rtNaN);
          Torque_Control_B.kamm_data[328] = (rtNaN);
          Torque_Control_B.kamm_data[345] = (rtNaN);
          Torque_Control_B.kamm_data[362] = (rtNaN);
          Torque_Control_B.kamm_data[379] = (rtNaN);
          Torque_Control_B.kamm_data[396] = (rtNaN);
          Torque_Control_B.kamm_data[413] = (rtNaN);
          Torque_Control_B.kamm_data[430] = (rtNaN);
          Torque_Control_B.kamm_data[447] = (rtNaN);
          Torque_Control_B.kamm_data[464] = (rtNaN);
          Torque_Control_B.kamm_data[481] = (rtNaN);
          Torque_Control_B.kamm_data[498] = (rtNaN);
          Torque_Control_B.kamm_data[515] = (rtNaN);
          Torque_Control_B.kamm_data[532] = (rtNaN);
          Torque_Control_B.kamm_data[6] = 500.0;
          Torque_Control_B.kamm_data[23] = 1536.0;
          Torque_Control_B.kamm_data[40] = 1529.0;
          Torque_Control_B.kamm_data[57] = 1521.0;
          Torque_Control_B.kamm_data[74] = 1509.0;
          Torque_Control_B.kamm_data[91] = 1491.0;
          Torque_Control_B.kamm_data[108] = 1459.0;
          Torque_Control_B.kamm_data[125] = 1395.0;
          Torque_Control_B.kamm_data[142] = 1230.0;
          Torque_Control_B.kamm_data[159] = 1032.0;
          Torque_Control_B.kamm_data[176] = 760.0;
          Torque_Control_B.kamm_data[193] = 411.0;
          Torque_Control_B.kamm_data[210] = (rtNaN);
          Torque_Control_B.kamm_data[227] = (rtNaN);
          Torque_Control_B.kamm_data[244] = (rtNaN);
          Torque_Control_B.kamm_data[261] = (rtNaN);
          Torque_Control_B.kamm_data[278] = (rtNaN);
          Torque_Control_B.kamm_data[295] = (rtNaN);
          Torque_Control_B.kamm_data[312] = (rtNaN);
          Torque_Control_B.kamm_data[329] = (rtNaN);
          Torque_Control_B.kamm_data[346] = (rtNaN);
          Torque_Control_B.kamm_data[363] = (rtNaN);
          Torque_Control_B.kamm_data[380] = (rtNaN);
          Torque_Control_B.kamm_data[397] = (rtNaN);
          Torque_Control_B.kamm_data[414] = (rtNaN);
          Torque_Control_B.kamm_data[431] = (rtNaN);
          Torque_Control_B.kamm_data[448] = (rtNaN);
          Torque_Control_B.kamm_data[465] = (rtNaN);
          Torque_Control_B.kamm_data[482] = (rtNaN);
          Torque_Control_B.kamm_data[499] = (rtNaN);
          Torque_Control_B.kamm_data[516] = (rtNaN);
          Torque_Control_B.kamm_data[533] = (rtNaN);
          Torque_Control_B.kamm_data[7] = 600.0;
          Torque_Control_B.kamm_data[24] = 1745.0;
          Torque_Control_B.kamm_data[41] = 1737.0;
          Torque_Control_B.kamm_data[58] = 1729.0;
          Torque_Control_B.kamm_data[75] = 1721.0;
          Torque_Control_B.kamm_data[92] = 1704.0;
          Torque_Control_B.kamm_data[109] = 1686.0;
          Torque_Control_B.kamm_data[126] = 1649.0;
          Torque_Control_B.kamm_data[143] = 1585.0;
          Torque_Control_B.kamm_data[160] = 1455.0;
          Torque_Control_B.kamm_data[177] = 1270.0;
          Torque_Control_B.kamm_data[194] = 1038.0;
          Torque_Control_B.kamm_data[211] = 756.0;
          Torque_Control_B.kamm_data[228] = 419.0;
          Torque_Control_B.kamm_data[245] = (rtNaN);
          Torque_Control_B.kamm_data[262] = (rtNaN);
          Torque_Control_B.kamm_data[279] = (rtNaN);
          Torque_Control_B.kamm_data[296] = (rtNaN);
          Torque_Control_B.kamm_data[313] = (rtNaN);
          Torque_Control_B.kamm_data[330] = (rtNaN);
          Torque_Control_B.kamm_data[347] = (rtNaN);
          Torque_Control_B.kamm_data[364] = (rtNaN);
          Torque_Control_B.kamm_data[381] = (rtNaN);
          Torque_Control_B.kamm_data[398] = (rtNaN);
          Torque_Control_B.kamm_data[415] = (rtNaN);
          Torque_Control_B.kamm_data[432] = (rtNaN);
          Torque_Control_B.kamm_data[449] = (rtNaN);
          Torque_Control_B.kamm_data[466] = (rtNaN);
          Torque_Control_B.kamm_data[483] = (rtNaN);
          Torque_Control_B.kamm_data[500] = (rtNaN);
          Torque_Control_B.kamm_data[517] = (rtNaN);
          Torque_Control_B.kamm_data[534] = (rtNaN);
          Torque_Control_B.kamm_data[8] = 700.0;
          Torque_Control_B.kamm_data[25] = 1964.0;
          Torque_Control_B.kamm_data[42] = 1956.0;
          Torque_Control_B.kamm_data[59] = 1948.0;
          Torque_Control_B.kamm_data[76] = 1940.0;
          Torque_Control_B.kamm_data[93] = 1926.0;
          Torque_Control_B.kamm_data[110] = 1909.0;
          Torque_Control_B.kamm_data[127] = 1884.0;
          Torque_Control_B.kamm_data[144] = 1848.0;
          Torque_Control_B.kamm_data[161] = 1777.0;
          Torque_Control_B.kamm_data[178] = 1656.0;
          Torque_Control_B.kamm_data[195] = 1484.0;
          Torque_Control_B.kamm_data[212] = 1278.0;
          Torque_Control_B.kamm_data[229] = 1029.0;
          Torque_Control_B.kamm_data[246] = 742.0;
          Torque_Control_B.kamm_data[263] = 416.0;
          Torque_Control_B.kamm_data[280] = (rtNaN);
          Torque_Control_B.kamm_data[297] = (rtNaN);
          Torque_Control_B.kamm_data[314] = (rtNaN);
          Torque_Control_B.kamm_data[331] = (rtNaN);
          Torque_Control_B.kamm_data[348] = (rtNaN);
          Torque_Control_B.kamm_data[365] = (rtNaN);
          Torque_Control_B.kamm_data[382] = (rtNaN);
          Torque_Control_B.kamm_data[399] = (rtNaN);
          Torque_Control_B.kamm_data[416] = (rtNaN);
          Torque_Control_B.kamm_data[433] = (rtNaN);
          Torque_Control_B.kamm_data[450] = (rtNaN);
          Torque_Control_B.kamm_data[467] = (rtNaN);
          Torque_Control_B.kamm_data[484] = (rtNaN);
          Torque_Control_B.kamm_data[501] = (rtNaN);
          Torque_Control_B.kamm_data[518] = (rtNaN);
          Torque_Control_B.kamm_data[535] = (rtNaN);
          Torque_Control_B.kamm_data[9] = 800.0;
          Torque_Control_B.kamm_data[26] = 2212.0;
          Torque_Control_B.kamm_data[43] = 2204.0;
          Torque_Control_B.kamm_data[60] = 2195.0;
          Torque_Control_B.kamm_data[77] = 2187.0;
          Torque_Control_B.kamm_data[94] = 2175.0;
          Torque_Control_B.kamm_data[111] = 2158.0;
          Torque_Control_B.kamm_data[128] = 2141.0;
          Torque_Control_B.kamm_data[145] = 2107.0;
          Torque_Control_B.kamm_data[162] = 2063.0;
          Torque_Control_B.kamm_data[179] = 1990.0;
          Torque_Control_B.kamm_data[196] = 1868.0;
          Torque_Control_B.kamm_data[213] = 1704.0;
          Torque_Control_B.kamm_data[230] = 1505.0;
          Torque_Control_B.kamm_data[247] = 1275.0;
          Torque_Control_B.kamm_data[264] = 1018.0;
          Torque_Control_B.kamm_data[281] = 730.0;
          Torque_Control_B.kamm_data[298] = 404.0;
          Torque_Control_B.kamm_data[315] = (rtNaN);
          Torque_Control_B.kamm_data[332] = (rtNaN);
          Torque_Control_B.kamm_data[349] = (rtNaN);
          Torque_Control_B.kamm_data[366] = (rtNaN);
          Torque_Control_B.kamm_data[383] = (rtNaN);
          Torque_Control_B.kamm_data[400] = (rtNaN);
          Torque_Control_B.kamm_data[417] = (rtNaN);
          Torque_Control_B.kamm_data[434] = (rtNaN);
          Torque_Control_B.kamm_data[451] = (rtNaN);
          Torque_Control_B.kamm_data[468] = (rtNaN);
          Torque_Control_B.kamm_data[485] = (rtNaN);
          Torque_Control_B.kamm_data[502] = (rtNaN);
          Torque_Control_B.kamm_data[519] = (rtNaN);
          Torque_Control_B.kamm_data[536] = (rtNaN);
          Torque_Control_B.kamm_data[10] = 900.0;
          Torque_Control_B.kamm_data[27] = 2465.0;
          Torque_Control_B.kamm_data[44] = 2456.0;
          Torque_Control_B.kamm_data[61] = 2448.0;
          Torque_Control_B.kamm_data[78] = 2439.0;
          Torque_Control_B.kamm_data[95] = 2428.0;
          Torque_Control_B.kamm_data[112] = 2411.0;
          Torque_Control_B.kamm_data[129] = 2394.0;
          Torque_Control_B.kamm_data[146] = 2367.0;
          Torque_Control_B.kamm_data[163] = 2333.0;
          Torque_Control_B.kamm_data[180] = 2279.0;
          Torque_Control_B.kamm_data[197] = 2200.0;
          Torque_Control_B.kamm_data[214] = 2081.0;
          Torque_Control_B.kamm_data[231] = 1921.0;
          Torque_Control_B.kamm_data[248] = 1729.0;
          Torque_Control_B.kamm_data[265] = 1512.0;
          Torque_Control_B.kamm_data[282] = 1268.0;
          Torque_Control_B.kamm_data[299] = 1002.0;
          Torque_Control_B.kamm_data[316] = 711.0;
          Torque_Control_B.kamm_data[333] = 345.0;
          Torque_Control_B.kamm_data[350] = (rtNaN);
          Torque_Control_B.kamm_data[367] = (rtNaN);
          Torque_Control_B.kamm_data[384] = (rtNaN);
          Torque_Control_B.kamm_data[401] = (rtNaN);
          Torque_Control_B.kamm_data[418] = (rtNaN);
          Torque_Control_B.kamm_data[435] = (rtNaN);
          Torque_Control_B.kamm_data[452] = (rtNaN);
          Torque_Control_B.kamm_data[469] = (rtNaN);
          Torque_Control_B.kamm_data[486] = (rtNaN);
          Torque_Control_B.kamm_data[503] = (rtNaN);
          Torque_Control_B.kamm_data[520] = (rtNaN);
          Torque_Control_B.kamm_data[537] = (rtNaN);
          Torque_Control_B.kamm_data[11] = 1000.0;
          Torque_Control_B.kamm_data[28] = 2684.0;
          Torque_Control_B.kamm_data[45] = 2675.0;
          Torque_Control_B.kamm_data[62] = 2666.0;
          Torque_Control_B.kamm_data[79] = 2657.0;
          Torque_Control_B.kamm_data[96] = 2647.0;
          Torque_Control_B.kamm_data[113] = 2629.0;
          Torque_Control_B.kamm_data[130] = 2612.0;
          Torque_Control_B.kamm_data[147] = 2592.0;
          Torque_Control_B.kamm_data[164] = 2558.0;
          Torque_Control_B.kamm_data[181] = 2520.0;
          Torque_Control_B.kamm_data[198] = 2462.0;
          Torque_Control_B.kamm_data[215] = 2378.0;
          Torque_Control_B.kamm_data[232] = 2262.0;
          Torque_Control_B.kamm_data[249] = 2119.0;
          Torque_Control_B.kamm_data[266] = 1940.0;
          Torque_Control_B.kamm_data[283] = 1737.0;
          Torque_Control_B.kamm_data[300] = 1508.0;
          Torque_Control_B.kamm_data[317] = 1259.0;
          Torque_Control_B.kamm_data[334] = 989.0;
          Torque_Control_B.kamm_data[351] = 680.0;
          Torque_Control_B.kamm_data[368] = 240.0;
          Torque_Control_B.kamm_data[385] = (rtNaN);
          Torque_Control_B.kamm_data[402] = (rtNaN);
          Torque_Control_B.kamm_data[419] = (rtNaN);
          Torque_Control_B.kamm_data[436] = (rtNaN);
          Torque_Control_B.kamm_data[453] = (rtNaN);
          Torque_Control_B.kamm_data[470] = (rtNaN);
          Torque_Control_B.kamm_data[487] = (rtNaN);
          Torque_Control_B.kamm_data[504] = (rtNaN);
          Torque_Control_B.kamm_data[521] = (rtNaN);
          Torque_Control_B.kamm_data[538] = (rtNaN);
          Torque_Control_B.kamm_data[12] = 1100.0;
          Torque_Control_B.kamm_data[29] = 2853.0;
          Torque_Control_B.kamm_data[46] = 2843.0;
          Torque_Control_B.kamm_data[63] = 2833.0;
          Torque_Control_B.kamm_data[80] = 2822.0;
          Torque_Control_B.kamm_data[97] = 2811.0;
          Torque_Control_B.kamm_data[114] = 2795.0;
          Torque_Control_B.kamm_data[131] = 2775.0;
          Torque_Control_B.kamm_data[148] = 2755.0;
          Torque_Control_B.kamm_data[165] = 2728.0;
          Torque_Control_B.kamm_data[182] = 2693.0;
          Torque_Control_B.kamm_data[199] = 2651.0;
          Torque_Control_B.kamm_data[216] = 2591.0;
          Torque_Control_B.kamm_data[233] = 2510.0;
          Torque_Control_B.kamm_data[250] = 2412.0;
          Torque_Control_B.kamm_data[267] = 2282.0;
          Torque_Control_B.kamm_data[284] = 2124.0;
          Torque_Control_B.kamm_data[301] = 1940.0;
          Torque_Control_B.kamm_data[318] = 1735.0;
          Torque_Control_B.kamm_data[335] = 1504.0;
          Torque_Control_B.kamm_data[352] = 1250.0;
          Torque_Control_B.kamm_data[369] = 962.0;
          Torque_Control_B.kamm_data[386] = 608.0;
          Torque_Control_B.kamm_data[403] = 108.0;
          Torque_Control_B.kamm_data[420] = (rtNaN);
          Torque_Control_B.kamm_data[437] = (rtNaN);
          Torque_Control_B.kamm_data[454] = (rtNaN);
          Torque_Control_B.kamm_data[471] = (rtNaN);
          Torque_Control_B.kamm_data[488] = (rtNaN);
          Torque_Control_B.kamm_data[505] = (rtNaN);
          Torque_Control_B.kamm_data[522] = (rtNaN);
          Torque_Control_B.kamm_data[539] = (rtNaN);
          Torque_Control_B.kamm_data[13] = 1200.0;
          Torque_Control_B.kamm_data[30] = 2999.0;
          Torque_Control_B.kamm_data[47] = 2988.0;
          Torque_Control_B.kamm_data[64] = 2976.0;
          Torque_Control_B.kamm_data[81] = 2964.0;
          Torque_Control_B.kamm_data[98] = 2952.0;
          Torque_Control_B.kamm_data[115] = 2936.0;
          Torque_Control_B.kamm_data[132] = 2914.0;
          Torque_Control_B.kamm_data[149] = 2893.0;
          Torque_Control_B.kamm_data[166] = 2872.0;
          Torque_Control_B.kamm_data[183] = 2837.0;
          Torque_Control_B.kamm_data[200] = 2799.0;
          Torque_Control_B.kamm_data[217] = 2755.0;
          Torque_Control_B.kamm_data[234] = 2694.0;
          Torque_Control_B.kamm_data[251] = 2619.0;
          Torque_Control_B.kamm_data[268] = 2527.0;
          Torque_Control_B.kamm_data[285] = 2412.0;
          Torque_Control_B.kamm_data[302] = 2275.0;
          Torque_Control_B.kamm_data[319] = 2114.0;
          Torque_Control_B.kamm_data[336] = 1936.0;
          Torque_Control_B.kamm_data[353] = 1729.0;
          Torque_Control_B.kamm_data[370] = 1507.0;
          Torque_Control_B.kamm_data[387] = 1233.0;
          Torque_Control_B.kamm_data[404] = 896.0;
          Torque_Control_B.kamm_data[421] = 461.0;
          Torque_Control_B.kamm_data[438] = (rtNaN);
          Torque_Control_B.kamm_data[455] = (rtNaN);
          Torque_Control_B.kamm_data[472] = (rtNaN);
          Torque_Control_B.kamm_data[489] = (rtNaN);
          Torque_Control_B.kamm_data[506] = (rtNaN);
          Torque_Control_B.kamm_data[523] = (rtNaN);
          Torque_Control_B.kamm_data[540] = (rtNaN);
          Torque_Control_B.kamm_data[14] = 1300.0;
          Torque_Control_B.kamm_data[31] = 3128.0;
          Torque_Control_B.kamm_data[48] = 3115.0;
          Torque_Control_B.kamm_data[65] = 3101.0;
          Torque_Control_B.kamm_data[82] = 3087.0;
          Torque_Control_B.kamm_data[99] = 3074.0;
          Torque_Control_B.kamm_data[116] = 3059.0;
          Torque_Control_B.kamm_data[133] = 3035.0;
          Torque_Control_B.kamm_data[150] = 3012.0;
          Torque_Control_B.kamm_data[167] = 2988.0;
          Torque_Control_B.kamm_data[184] = 2962.0;
          Torque_Control_B.kamm_data[201] = 2923.0;
          Torque_Control_B.kamm_data[218] = 2884.0;
          Torque_Control_B.kamm_data[235] = 2838.0;
          Torque_Control_B.kamm_data[252] = 2778.0;
          Torque_Control_B.kamm_data[269] = 2709.0;
          Torque_Control_B.kamm_data[286] = 2625.0;
          Torque_Control_B.kamm_data[303] = 2517.0;
          Torque_Control_B.kamm_data[320] = 2396.0;
          Torque_Control_B.kamm_data[337] = 2259.0;
          Torque_Control_B.kamm_data[354] = 2104.0;
          Torque_Control_B.kamm_data[371] = 1924.0;
          Torque_Control_B.kamm_data[388] = 1730.0;
          Torque_Control_B.kamm_data[405] = 1484.0;
          Torque_Control_B.kamm_data[422] = 1169.0;
          Torque_Control_B.kamm_data[439] = 772.0;
          Torque_Control_B.kamm_data[456] = 213.0;
          Torque_Control_B.kamm_data[473] = (rtNaN);
          Torque_Control_B.kamm_data[490] = (rtNaN);
          Torque_Control_B.kamm_data[507] = (rtNaN);
          Torque_Control_B.kamm_data[524] = (rtNaN);
          Torque_Control_B.kamm_data[541] = (rtNaN);
          Torque_Control_B.kamm_data[15] = 1400.0;
          Torque_Control_B.kamm_data[32] = 3228.0;
          Torque_Control_B.kamm_data[49] = 3215.0;
          Torque_Control_B.kamm_data[66] = 3201.0;
          Torque_Control_B.kamm_data[83] = 3187.0;
          Torque_Control_B.kamm_data[100] = 3172.0;
          Torque_Control_B.kamm_data[117] = 3157.0;
          Torque_Control_B.kamm_data[134] = 3134.0;
          Torque_Control_B.kamm_data[151] = 3111.0;
          Torque_Control_B.kamm_data[168] = 3087.0;
          Torque_Control_B.kamm_data[185] = 3063.0;
          Torque_Control_B.kamm_data[202] = 3026.0;
          Torque_Control_B.kamm_data[219] = 2989.0;
          Torque_Control_B.kamm_data[236] = 2952.0;
          Torque_Control_B.kamm_data[253] = 2896.0;
          Torque_Control_B.kamm_data[270] = 2841.0;
          Torque_Control_B.kamm_data[287] = 2772.0;
          Torque_Control_B.kamm_data[304] = 2691.0;
          Torque_Control_B.kamm_data[321] = 2603.0;
          Torque_Control_B.kamm_data[338] = 2500.0;
          Torque_Control_B.kamm_data[355] = 2379.0;
          Torque_Control_B.kamm_data[372] = 2243.0;
          Torque_Control_B.kamm_data[389] = 2091.0;
          Torque_Control_B.kamm_data[406] = 1927.0;
          Torque_Control_B.kamm_data[423] = 1713.0;
          Torque_Control_B.kamm_data[440] = 1414.0;
          Torque_Control_B.kamm_data[457] = 1030.0;
          Torque_Control_B.kamm_data[474] = 553.0;
          Torque_Control_B.kamm_data[491] = (rtNaN);
          Torque_Control_B.kamm_data[508] = (rtNaN);
          Torque_Control_B.kamm_data[525] = (rtNaN);
          Torque_Control_B.kamm_data[542] = (rtNaN);
          Torque_Control_B.kamm_data[16] = 1500.0;
          Torque_Control_B.kamm_data[33] = 3327.0;
          Torque_Control_B.kamm_data[50] = 3312.0;
          Torque_Control_B.kamm_data[67] = 3296.0;
          Torque_Control_B.kamm_data[84] = 3280.0;
          Torque_Control_B.kamm_data[101] = 3263.0;
          Torque_Control_B.kamm_data[118] = 3247.0;
          Torque_Control_B.kamm_data[135] = 3223.0;
          Torque_Control_B.kamm_data[152] = 3198.0;
          Torque_Control_B.kamm_data[169] = 3173.0;
          Torque_Control_B.kamm_data[186] = 3147.0;
          Torque_Control_B.kamm_data[203] = 3116.0;
          Torque_Control_B.kamm_data[220] = 3078.0;
          Torque_Control_B.kamm_data[237] = 3040.0;
          Torque_Control_B.kamm_data[254] = 3001.0;
          Torque_Control_B.kamm_data[271] = 2947.0;
          Torque_Control_B.kamm_data[288] = 2893.0;
          Torque_Control_B.kamm_data[305] = 2828.0;
          Torque_Control_B.kamm_data[322] = 2756.0;
          Torque_Control_B.kamm_data[339] = 2670.0;
          Torque_Control_B.kamm_data[356] = 2576.0;
          Torque_Control_B.kamm_data[373] = 2471.0;
          Torque_Control_B.kamm_data[390] = 2353.0;
          Torque_Control_B.kamm_data[407] = 2228.0;
          Torque_Control_B.kamm_data[424] = 2100.0;
          Torque_Control_B.kamm_data[441] = 1921.0;
          Torque_Control_B.kamm_data[458] = 1649.0;
          Torque_Control_B.kamm_data[475] = 1278.0;
          Torque_Control_B.kamm_data[492] = 814.0;
          Torque_Control_B.kamm_data[509] = 217.0;
          Torque_Control_B.kamm_data[526] = (rtNaN);
          Torque_Control_B.kamm_data[543] = (rtNaN);
          mz = 1.0;
          Mz = 16.0;
          k = 8.0;
          p = 15.0;
          while (p != 1.0) {
            p = Torque_Control_B.kamm_data[(int32_T)k];
            if (Torque_Control_B.Merge2 > p) {
              mz = k;
            } else if (Torque_Control_B.Merge2 < p) {
              Mz = k;
            }

            k = floor((Mz + mz) / 2.0);
            p = Mz - mz;
            if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data[(int32_T)
                Mz]) {
              p = 1.0;
              mz = Mz;
            } else if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data
                       [(int32_T)mz]) {
              p = 1.0;
              Mz = mz;
            } else if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data
                       [(int32_T)k]) {
              p = 1.0;
              Mz = k;
              mz = k;
            }
          }

          my = 1.0;
          My = 31.0;
          k = 16.0;
          p = 30.0;
          while (p != 1.0) {
            p = Torque_Control_B.kamm_data[17 * (int32_T)k];
            if (a21 > p) {
              my = k;
            } else if (a21 < p) {
              My = k;
            }

            k = floor((My + my) / 2.0);
            p = My - my;
            if (Torque_Control_B.kamm_data[17 * (int32_T)My] == a21) {
              p = 1.0;
              my = My;
            } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == a21) {
              p = 1.0;
              My = my;
            } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == a21) {
              p = 1.0;
              My = k;
              my = k;
            }
          }

          if ((Mz == mz) && (My != my)) {
            r1 = 17 * (int32_T)my;
            kamm_data[0] = Torque_Control_B.kamm_data[r1];
            r2 = 17 * (int32_T)My;
            kamm_data[1] = Torque_Control_B.kamm_data[r2];
            kamm_data_0[0] = Torque_Control_B.kamm_data[r1 + (int32_T)mz];
            kamm_data_0[1] = Torque_Control_B.kamm_data[r2 + (int32_T)mz];
            polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
            rtb_alpha_m = b_a[0] * a21 + b_a[1];
          } else if ((Mz != mz) && (My == my)) {
            kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
            kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
            kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)mz];
            kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)Mz];
            polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
            rtb_alpha_m = b_a[0] * Torque_Control_B.Merge2 + b_a[1];
          } else if ((Mz == mz) && (My == my)) {
            rtb_alpha_m = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
              Mz];
          } else {
            tmp[0] = 1.0;
            tmp[1] = 1.0;
            tmp[2] = 1.0;
            tmp[3] = 1.0;
            p = Torque_Control_B.kamm_data[(int32_T)mz];
            tmp[4] = p;
            tmp[5] = p;
            p = Torque_Control_B.kamm_data[(int32_T)Mz];
            tmp[6] = p;
            tmp[7] = p;
            p = Torque_Control_B.kamm_data[17 * (int32_T)my];
            tmp[8] = p;
            k = Torque_Control_B.kamm_data[17 * (int32_T)My];
            tmp[9] = k;
            tmp[10] = p;
            tmp[11] = k;
            kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)mz];
            kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
              (int32_T)mz];
            kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)Mz];
            kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
              (int32_T)Mz];
            mldivide_8ZFDevWm(tmp, kamm_data_1, a);
            rtb_alpha_m = (a[1] * Torque_Control_B.Merge2 + a[0]) + a[2] * a21;
          }

          mz = 1.0;
          Mz = 16.0;
          k = 8.0;
          p = 15.0;
          while (p != 1.0) {
            p = Torque_Control_B.kamm_data[(int32_T)k];
            if (Torque_Control_B.Merge3_o > p) {
              mz = k;
            } else if (Torque_Control_B.Merge3_o < p) {
              Mz = k;
            }

            k = floor((Mz + mz) / 2.0);
            p = Mz - mz;
            if (Torque_Control_B.Merge3_o == Torque_Control_B.kamm_data[(int32_T)
                Mz]) {
              p = 1.0;
              mz = Mz;
            } else if (Torque_Control_B.Merge3_o == Torque_Control_B.kamm_data
                       [(int32_T)mz]) {
              p = 1.0;
              Mz = mz;
            } else if (Torque_Control_B.Merge3_o == Torque_Control_B.kamm_data
                       [(int32_T)k]) {
              p = 1.0;
              Mz = k;
              mz = k;
            }
          }

          my = 1.0;
          My = 31.0;
          k = 16.0;
          p = 30.0;
          while (p != 1.0) {
            p = Torque_Control_B.kamm_data[17 * (int32_T)k];
            if (a21 > p) {
              my = k;
            } else if (a21 < p) {
              My = k;
            }

            k = floor((My + my) / 2.0);
            p = My - my;
            if (Torque_Control_B.kamm_data[17 * (int32_T)My] == a21) {
              p = 1.0;
              my = My;
            } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == a21) {
              p = 1.0;
              My = my;
            } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == a21) {
              p = 1.0;
              My = k;
              my = k;
            }
          }

          if ((Mz == mz) && (My != my)) {
            r1 = 17 * (int32_T)my;
            kamm_data[0] = Torque_Control_B.kamm_data[r1];
            r2 = 17 * (int32_T)My;
            kamm_data[1] = Torque_Control_B.kamm_data[r2];
            kamm_data_0[0] = Torque_Control_B.kamm_data[r1 + (int32_T)mz];
            kamm_data_0[1] = Torque_Control_B.kamm_data[r2 + (int32_T)mz];
            polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
            mz = b_a[0] * a21 + b_a[1];
          } else if ((Mz != mz) && (My == my)) {
            kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
            kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
            kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)mz];
            kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)Mz];
            polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
            mz = b_a[0] * Torque_Control_B.Merge3_o + b_a[1];
          } else if ((Mz == mz) && (My == my)) {
            mz = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)Mz];
          } else {
            tmp[0] = 1.0;
            tmp[1] = 1.0;
            tmp[2] = 1.0;
            tmp[3] = 1.0;
            p = Torque_Control_B.kamm_data[(int32_T)mz];
            tmp[4] = p;
            tmp[5] = p;
            p = Torque_Control_B.kamm_data[(int32_T)Mz];
            tmp[6] = p;
            tmp[7] = p;
            p = Torque_Control_B.kamm_data[17 * (int32_T)my];
            tmp[8] = p;
            k = Torque_Control_B.kamm_data[17 * (int32_T)My];
            tmp[9] = k;
            tmp[10] = p;
            tmp[11] = k;
            kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)mz];
            kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
              (int32_T)mz];
            kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
              (int32_T)Mz];
            kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
              (int32_T)Mz];
            mldivide_8ZFDevWm(tmp, kamm_data_1, a);
            mz = (a[1] * Torque_Control_B.Merge3_o + a[0]) + a[2] * a21;
          }

          /* Product: '<S128>/Product1' incorporates:
           *  MATLAB Function: '<S128>/Kamm_Circle LatD'
           */
          rtb_Product1_e = rtb_alpha_m * Torque_Control_B.Saturation_h;

          /* MATLAB Function: '<S104>/MATLAB Function2' incorporates:
           *  Constant: '<S104>/Constant4'
           */
          Torque_Control_MATLABFunction_f(-1.0, rtb_Product1_e,
            &Torque_Control_B.sf_MATLABFunction2_mv);

          /* Product: '<S128>/Product2' incorporates:
           *  MATLAB Function: '<S128>/Kamm_Circle LatD'
           */
          rtb_Product2 = mz * Torque_Control_B.Saturation_h;

          /* MATLAB Function: '<S104>/MATLAB Function1' incorporates:
           *  Constant: '<S104>/Constant3'
           */
          Torque_Control_MATLABFunction_f(-1.0, rtb_Product2,
            &Torque_Control_B.sf_MATLABFunction1_c);

          /* MATLAB Function: '<S104>/Force Difference with  Max. Tire Forces' */
          if (rtb_Divide_b > 0.0) {
            mz = Torque_Control_B.sf_MATLABFunction1_c.value;
            rtb_alpha_m = Torque_Control_B.sf_MATLABFunction1_c.value -
              rtb_Divide_b;
            if (rtb_alpha_m > Torque_Control_B.sf_MATLABFunction2_mv.value) {
              rtb_alpha_m = Torque_Control_B.sf_MATLABFunction2_mv.value;
              mz = Torque_Control_B.sf_MATLABFunction2_mv.value + rtb_Divide_b;
            }
          } else if (rtb_Divide_b < 0.0) {
            rtb_alpha_m = Torque_Control_B.sf_MATLABFunction2_mv.value;
            Mz = fabs(rtb_Divide_b);
            mz = Torque_Control_B.sf_MATLABFunction2_mv.value - Mz;
            if (mz > Torque_Control_B.sf_MATLABFunction1_c.value) {
              mz = Torque_Control_B.sf_MATLABFunction1_c.value;
              rtb_alpha_m = Torque_Control_B.sf_MATLABFunction1_c.value - Mz;
            }
          } else if (Torque_Control_B.sf_MATLABFunction2_mv.value >
                     Torque_Control_B.sf_MATLABFunction1_c.value) {
            mz = Torque_Control_B.sf_MATLABFunction1_c.value;
            rtb_alpha_m = Torque_Control_B.sf_MATLABFunction1_c.value;
          } else {
            rtb_alpha_m = Torque_Control_B.sf_MATLABFunction2_mv.value;
            mz = Torque_Control_B.sf_MATLABFunction2_mv.value;
          }

          /* Merge: '<S70>/Merge4' incorporates:
           *  Gain: '<S104>/Gravity1'
           *  Sum: '<S104>/Sum1'
           *  Sum: '<S104>/Sum2'
           */
          Torque_Control_B.Merge4 = ((Torque_Control_B.Merge_m +
            Torque_Control_B.Merge1) + maxval) * 0.1019367991845056;

          /* Merge: '<S70>/Merge3' incorporates:
           *  MATLAB Function: '<S104>/Force Difference with  Max. Tire Forces'
           *  SignalConversion generated from: '<S104>/Fx_RL '
           */
          Torque_Control_B.Merge3_d = mz;

          /* Merge: '<S70>/Merge2' incorporates:
           *  MATLAB Function: '<S104>/Force Difference with  Max. Tire Forces'
           *  SignalConversion generated from: '<S104>/Fx_RR '
           */
          Torque_Control_B.Merge2_i = rtb_alpha_m;

          /* Merge: '<S70>/Merge6' incorporates:
           *  MATLAB Function: '<S128>/Kamm_Circle LatD'
           *  SignalConversion generated from: '<S104>/Fy_R [N] (0,inf)'
           */
          Torque_Control_B.Merge6 = a21;

          /* Gain: '<S132>/Gain1' */
          Torque_Control_B.Gain1_h = 57.295779513082323 * rtb_Gain_f;

          /* Gain: '<S132>/Gain4' incorporates:
           *  MATLAB Function: '<S132>/Bicycle Model'
           */
          Torque_Control_B.Gain4 = 57.295779513082323 * X_idx_0;

          /* Gain: '<S132>/Gain3' incorporates:
           *  MATLAB Function: '<S132>/Bicycle Model'
           */
          Torque_Control_B.Gain3 = 57.295779513082323 * X_idx_1;

          /* Gain: '<S132>/Gain2' incorporates:
           *  MATLAB Function: '<S132>/Bicycle Model'
           */
          Torque_Control_B.Gain2 = 57.295779513082323 * b_idx_0;

          /* Gain: '<S132>/Gain' incorporates:
           *  MATLAB Function: '<S132>/Bicycle Model'
           */
          Torque_Control_B.Gain_a = (X_idx_0 + rtb_value_a) * 57.295779513082323;

          /* Merge: '<S70>/Merge5' incorporates:
           *  Constant: '<S104>/Constant5'
           *  SignalConversion generated from: '<S104>/Handling [-] (-inf,inf)'
           */
          Torque_Control_B.Merge5 = 0.0;

          /* Merge: '<S70>/Merge7' incorporates:
           *  Constant: '<S104>/Constant6'
           *  SignalConversion generated from: '<S104>/Flag CarBehavior'
           */
          Torque_Control_B.Merge7 = 1.0;

          /* End of Outputs for SubSystem: '<S70>/Lateral Dynamics' */
        }

        /* End of If: '<S70>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */

        /* MATLAB Function: '<S110>/MATLAB Function1' incorporates:
         *  Constant: '<S110>/Constant1'
         */
        Torque_Contro_MATLABFunction1_p(0.0, Torque_Control_B.Merge2_i,
          &Torque_Control_B.sf_MATLABFunction1_p);

        /* Product: '<S156>/Divide' incorporates:
         *  Constant: '<S103>/Transmision Ratio[-]'
         *  Product: '<S156>/Product'
         */
        Torque_Control_B.Divide = Torque_Control_B.sf_MATLABFunction1_p.value *
          Torque_Control_ConstB.udifference1 / 4.0;

        /* MATLAB Function: '<S110>/MATLAB Function2' incorporates:
         *  Constant: '<S110>/Constant'
         */
        Torque_Contro_MATLABFunction1_p(0.0, Torque_Control_B.Merge3_d,
          &Torque_Control_B.sf_MATLABFunction2_m);

        /* Product: '<S155>/Divide' incorporates:
         *  Constant: '<S103>/Transmision Ratio[-]'
         *  Product: '<S155>/Product'
         */
        Torque_Control_B.Divide_g = Torque_Control_B.sf_MATLABFunction2_m.value *
          Torque_Control_ConstB.udifference1 / 4.0;

        /* Sum: '<S110>/Add' */
        rtb_Gain_f = Torque_Control_B.Divide - Torque_Control_B.Divide_g;

        /* MATLAB Function: '<S101>/Accelerator behaviour ' incorporates:
         *  Inport: '<Root>/APPS1_Value'
         *  Inport: '<Root>/VDC_Apps_Sat_Down'
         *  Inport: '<Root>/VDC_Apps_Sat_Up'
         */
        Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
          Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
          &Torque_Control_B.sf_Acceleratorbehaviour);

        /* If: '<S101>/Braking Conditions' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
            (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1) &&
            (Torque_Control_B.Merge1_a == 1.0)) {
          Torque_Control_DW.BrakingConditions_ActiveSubs_f3 = 0;

          /* Outputs for IfAction SubSystem: '<S101>/Regenerative+Mech Braking' incorporates:
           *  ActionPort: '<S125>/Action Port'
           */
          /* MATLAB Function: '<S125>/MATLAB Function' */
          if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
            rtb_value_a = 0.0;
          } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
            rtb_value_a = 1.0;
          } else {
            rtb_value_a = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
          }

          /* Merge: '<S101>/Merge1' incorporates:
           *  MATLAB Function: '<S125>/MATLAB Function'
           *  SignalConversion generated from: '<S125>/Tq_RL'
           */
          Torque_Control_B.Merge1_j = rtb_value_a * Torque_Control_B.Divide_g;

          /* Merge: '<S101>/Merge' incorporates:
           *  MATLAB Function: '<S125>/MATLAB Function'
           *  SignalConversion generated from: '<S125>/Tq_RR  '
           */
          Torque_Control_B.Merge_dw = rtb_value_a * Torque_Control_B.Divide;

          /* End of Outputs for SubSystem: '<S101>/Regenerative+Mech Braking' */
        } else if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
                   (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1) &&
                   (Torque_Control_B.Merge1_a == 0.0)) {
          Torque_Control_DW.BrakingConditions_ActiveSubs_f3 = 1;

          /* Outputs for IfAction SubSystem: '<S101>/Mech_Braking' incorporates:
           *  ActionPort: '<S124>/Action Port'
           */
          Torque_Control_Mech_Braking(&Torque_Control_B.Merge_dw,
            &Torque_Control_B.Merge1_j);

          /* End of Outputs for SubSystem: '<S101>/Mech_Braking' */
        } else if ((Torque_Control_U.BrakeSensor_Value < 0.1) &&
                   (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1)) {
          Torque_Control_DW.BrakingConditions_ActiveSubs_f3 = 2;

          /* Outputs for IfAction SubSystem: '<S101>/Inertia Braking' incorporates:
           *  ActionPort: '<S123>/Action Port'
           */
          Torque_Control_Mech_Braking(&Torque_Control_B.Merge_dw,
            &Torque_Control_B.Merge1_j);

          /* End of Outputs for SubSystem: '<S101>/Inertia Braking' */
        } else {
          Torque_Control_DW.BrakingConditions_ActiveSubs_f3 = 3;

          /* Outputs for IfAction SubSystem: '<S101>/Accelerating' incorporates:
           *  ActionPort: '<S121>/Action Port'
           */
          /* SignalConversion generated from: '<S121>/Throttle' */
          Torque_Control_B.Throttle =
            Torque_Control_B.sf_Acceleratorbehaviour.throttle;

          /* Merge: '<S101>/Merge1' incorporates:
           *  Product: '<S121>/Product'
           */
          Torque_Control_B.Merge1_j = Torque_Control_B.Throttle *
            Torque_Control_B.Divide_g;

          /* Merge: '<S101>/Merge' incorporates:
           *  Product: '<S121>/Product1'
           */
          Torque_Control_B.Merge_dw = Torque_Control_B.Throttle *
            Torque_Control_B.Divide;

          /* End of Outputs for SubSystem: '<S101>/Accelerating' */
        }

        /* End of If: '<S101>/Braking Conditions' */

        /* If: '<S100>/If' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if ((Torque_Control_B.Merge1_a == 1.0) &&
            (Torque_Control_U.BrakeSensor_Value > 0.0)) {
          Torque_Control_DW.If_ActiveSubsystem_c = 0;

          /* Outputs for IfAction SubSystem: '<S100>/Braking with Regenerative' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          Torque__BrakingwithRegenerative(rtb_TomotorTqRT,
            Torque_Control_B.Merge_dw, Torque_Control_B.Merge1_j, &rtb_Merge1_pl,
            &rtb_Merge2);

          /* End of Outputs for SubSystem: '<S100>/Braking with Regenerative' */
        } else {
          Torque_Control_DW.If_ActiveSubsystem_c = 1;

          /* Outputs for IfAction SubSystem: '<S100>/Acelerating and braking without Regenerative' incorporates:
           *  ActionPort: '<S111>/Action Port'
           */
          /* If: '<S111>/If1' incorporates:
           *  Constant: '<S103>/Maximum Transmission Torque Dynamic [Nm]'
           *  Constant: '<S103>/Maximum Transmission Torque Static [Nm]'
           */
          if ((rtb_Abs2 > Torque_Control_ConstB.approx2095_g) &&
              (Torque_Control_B.Abs3 > Torque_Control_ConstB.approx2095_g)) {
            Torque_Control_DW.If1_ActiveSubsystem_e = 0;

            /* Outputs for IfAction SubSystem: '<S111>/If Action 1' incorporates:
             *  ActionPort: '<S113>/Action Port'
             */
            Torque_Control_IfAction1(140.0, &Torque_Control_B.Merge2_m);

            /* End of Outputs for SubSystem: '<S111>/If Action 1' */
          } else {
            Torque_Control_DW.If1_ActiveSubsystem_e = 1;

            /* Outputs for IfAction SubSystem: '<S111>/If Action 2' incorporates:
             *  ActionPort: '<S114>/Action Port'
             */
            Torque_Control_IfAction2(130.0, &Torque_Control_B.Merge2_m);

            /* End of Outputs for SubSystem: '<S111>/If Action 2' */
          }

          /* End of If: '<S111>/If1' */

          /* MATLAB Function: '<S111>/MATLAB Function' incorporates:
           *  Constant: '<S103>/Tq_diff_Max'
           */
          if (rtb_Gain_f < -100.0) {
            rtb_Gain_f = -100.0;
          } else if (rtb_Gain_f > 100.0) {
            rtb_Gain_f = 100.0;
          }

          /* End of MATLAB Function: '<S111>/MATLAB Function' */

          /* MATLAB Function: '<S111>/minimum value' incorporates:
           *  Constant: '<S103>/Maximum Torque per engine [Nm]'
           */
          rtb_value_a = Torque_Control_B.Merge2_m;
          if (Torque_Control_B.Merge2_m > 120.0) {
            rtb_value_a = 120.0;
          }

          if (Torque_Control_B.Merge_dw < rtb_value_a) {
            rtb_value_a = Torque_Control_B.Merge_dw;
          }

          /* End of MATLAB Function: '<S111>/minimum value' */

          /* MATLAB Function: '<S111>/minimum value1' incorporates:
           *  Constant: '<S103>/Maximum Torque per engine [Nm]'
           */
          rtb_alpha_m = Torque_Control_B.Merge2_m;
          if (Torque_Control_B.Merge2_m > 120.0) {
            rtb_alpha_m = 120.0;
          }

          if (Torque_Control_B.Merge1_j < rtb_alpha_m) {
            rtb_alpha_m = Torque_Control_B.Merge1_j;
          }

          /* End of MATLAB Function: '<S111>/minimum value1' */

          /* MATLAB Function: '<S116>/MATLAB Function' */
          if ((!(rtb_value_a == Torque_Control_B.Merge_dw)) || (!(rtb_alpha_m ==
                Torque_Control_B.Merge1_j))) {
            if (Torque_Control_B.Merge_dw > Torque_Control_B.Merge1_j) {
              rtb_alpha_m = rtb_value_a - fabs(rtb_Gain_f);
              if (rtb_alpha_m < 0.0) {
                rtb_alpha_m = 0.0;
              }
            } else if (Torque_Control_B.Merge_dw < Torque_Control_B.Merge1_j) {
              rtb_value_a = rtb_alpha_m - fabs(rtb_Gain_f);
              if (rtb_value_a < 0.0) {
                rtb_value_a = 0.0;
              }
            }
          }

          /* Merge: '<S100>/Merge2' incorporates:
           *  MATLAB Function: '<S116>/MATLAB Function'
           *  SignalConversion generated from: '<S111>/TQ_RL'
           */
          rtb_Merge2 = rtb_alpha_m;

          /* Merge: '<S100>/Merge1' incorporates:
           *  MATLAB Function: '<S116>/MATLAB Function'
           *  SignalConversion generated from: '<S111>/TQ_RR'
           */
          rtb_Merge1_pl = rtb_value_a;

          /* SignalConversion generated from: '<S111>/Flag_Power' */
          Torque_Control_B.OutportBufferForFlag_Power =
            Torque_Control_ConstB.Constant;

          /* End of Outputs for SubSystem: '<S100>/Acelerating and braking without Regenerative' */
        }

        /* End of If: '<S100>/If' */

        /* Merge: '<S11>/Merge Tq_RR' incorporates:
         *  Constant: '<S103>/Transmision Ratio[-]'
         *  Product: '<S100>/To wheel Tq'
         */
        Torque_Control_B.MergeTq_RR = rtb_Merge1_pl * 4.0;

        /* Merge: '<S11>/Merge Tq_RL' incorporates:
         *  Constant: '<S103>/Transmision Ratio[-]'
         *  Product: '<S100>/To wheel Tq1'
         */
        Torque_Control_B.MergeTq_RL = 4.0 * rtb_Merge2;

        /* MATLAB Function: '<S70>/MATLAB Function1' incorporates:
         *  Constant: '<S70>/Constant'
         */
        Torque_Control_MATLABFunction1(0.0, Torque_Control_B.Divide_g,
          &Torque_Control_B.sf_MATLABFunction1);

        /* MATLAB Function: '<S70>/MATLAB Function2' incorporates:
         *  Constant: '<S70>/Constant'
         */
        Torque_Control_MATLABFunction1(0.0, Torque_Control_B.Divide,
          &Torque_Control_B.sf_MATLABFunction2);

        /* Merge: '<S11>/Merge3' incorporates:
         *  SignalConversion generated from: '<S70>/CKF_act'
         */
        Torque_Control_B.Merge3_i = Torque_Control_B.Saturation_h;

        /* SignalConversion generated from: '<S70>/Flags_[num5]' */
        Torque_Control_B.OutportBufferForFlags_num5[0] = Torque_Control_B.Merge7;
        Torque_Control_B.OutportBufferForFlags_num5[1] =
          Torque_Control_B.sf_MATLABFunction1.value;
        Torque_Control_B.OutportBufferForFlags_num5[2] =
          Torque_Control_B.sf_MATLABFunction2.value;
        Torque_Control_B.OutportBufferForFlags_num5[3] =
          Torque_Control_B.OutportBufferForFlag_Power;

        /* Merge: '<S11>/Merge2' incorporates:
         *  SignalConversion generated from: '<S70>/SKF_act'
         */
        Torque_Control_B.Merge2_b = Torque_Control_B.Saturation_hh;

        /* End of Outputs for SubSystem: '<S11>/VDC Complete' */
      }
      break;

     case 1:
      {
        real_T My;
        real_T k;
        real_T my;
        int32_T r1;
        int32_T r2;

        /* Outputs for IfAction SubSystem: '<S11>/VDC without Longitudinal' incorporates:
         *  ActionPort: '<S71>/Action Port'
         */
        /* MATLAB Function: '<S165>/MATLAB Function' */
        Torque_Control_MATLABFunction(Torque_Control_B.Abs3, rtb_Abs2,
          &Torque_Control_B.sf_MATLABFunction_hu);

        /* Derivative: '<S165>/Derivative' */
        rtb_alpha_m = Torque_Control_M->Timing.t[0];
        if ((Torque_Control_DW.TimeStampA_p >= rtb_alpha_m) &&
            (Torque_Control_DW.TimeStampB_n >= rtb_alpha_m)) {
          rtb_Gain_f = 0.0;
        } else {
          maxval = Torque_Control_DW.TimeStampA_p;
          lastU = &Torque_Control_DW.LastUAtTimeA_o;
          if (Torque_Control_DW.TimeStampA_p < Torque_Control_DW.TimeStampB_n) {
            if (Torque_Control_DW.TimeStampB_n < rtb_alpha_m) {
              maxval = Torque_Control_DW.TimeStampB_n;
              lastU = &Torque_Control_DW.LastUAtTimeB_m;
            }
          } else if (Torque_Control_DW.TimeStampA_p >= rtb_alpha_m) {
            maxval = Torque_Control_DW.TimeStampB_n;
            lastU = &Torque_Control_DW.LastUAtTimeB_m;
          }

          rtb_Gain_f = (Torque_Control_B.sf_MATLABFunction_hu.w - *lastU) /
            (rtb_alpha_m - maxval);
        }

        /* End of Derivative: '<S165>/Derivative' */

        /* If: '<S191>/If1' */
        Torque_Control_DW.If1_ActiveSubsystem_p = -1;
        if (rtb_Gain_f >= 900.0) {
          Torque_Control_DW.If1_ActiveSubsystem_p = 0;

          /* Outputs for IfAction SubSystem: '<S191>/Spin ' incorporates:
           *  ActionPort: '<S193>/Action Port'
           */
          /* Switch: '<S193>/Switch1' incorporates:
           *  DataStoreRead: '<S165>/CKF_prev'
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          if (Torque_Control_DW.B_c > 0.0) {
            p = Torque_Control_DW.B_c;
          } else {
            p = Torque_Control_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S193>/Switch1' */

          /* Switch: '<S193>/Switch' incorporates:
           *  Constant: '<S193>/Constant'
           *  Inport: '<Root>/VDC_Cte_CKF'
           */
          if (Torque_Control_U.VDC_Cte_CKF >= 0.9) {
            k = Torque_Control_U.VDC_Cte_CKF;
          } else {
            k = 1.0;
          }

          /* End of Switch: '<S193>/Switch' */

          /* Product: '<S193>/Product' */
          rtb_Product_k = p * k;

          /* MATLAB Function: '<S193>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          Torque_Control_MATLABFunction_l(Torque_Control_U.VDC_CKF_Initial,
            rtb_Product_k, &Torque_Control_B.sf_MATLABFunction_o);

          /* Merge: '<S191>/Merge' incorporates:
           *  SignalConversion generated from: '<S193>/CKF_act1 '
           */
          Torque_Control_B.Merge_n =
            Torque_Control_B.sf_MATLABFunction_o.CKF_act1;

          /* End of Outputs for SubSystem: '<S191>/Spin ' */
        } else if (rtb_Gain_f < 900.0) {
          Torque_Control_DW.If1_ActiveSubsystem_p = 1;

          /* Outputs for IfAction SubSystem: '<S191>/No spin' incorporates:
           *  ActionPort: '<S192>/Action Port'
           */
          /* Switch: '<S192>/Switch1' incorporates:
           *  DataStoreRead: '<S165>/CKF_prev'
           */
          if (Torque_Control_DW.B_c > 0.0) {
            /* Switch: '<S192>/Switch1' */
            rtb_Switch1 = Torque_Control_DW.B_c;
          } else {
            /* Switch: '<S192>/Switch1' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             */
            rtb_Switch1 = Torque_Control_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S192>/Switch1' */

          /* MATLAB Function: '<S192>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           *  Inport: '<Root>/VDC_Cte_CKF'
           */
          Torque_Contro_MATLABFunction1_n(rtb_Switch1,
            Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_CKF,
            &Torque_Control_B.sf_MATLABFunction_gw);

          /* Merge: '<S191>/Merge' incorporates:
           *  SignalConversion generated from: '<S192>/CKF_act0'
           */
          Torque_Control_B.Merge_n =
            Torque_Control_B.sf_MATLABFunction_gw.CKF_act0;

          /* End of Outputs for SubSystem: '<S191>/No spin' */
        }

        /* End of If: '<S191>/If1' */

        /* Saturate: '<S191>/Saturation' */
        if (Torque_Control_B.Merge_n > 1.0) {
          rtb_Gain_f = 1.0;
        } else if (Torque_Control_B.Merge_n < 0.3) {
          rtb_Gain_f = 0.3;
        } else {
          rtb_Gain_f = Torque_Control_B.Merge_n;
        }

        /* End of Saturate: '<S191>/Saturation' */

        /* DataStoreWrite: '<S165>/Data Store Write1' */
        Torque_Control_DW.B_c = rtb_Gain_f;

        /* Gain: '<S164>/Fy per wheel' incorporates:
         *  Gain: '<S164>/Gravity1'
         *  Inport: '<Root>/el_ACCEL_Y'
         *  Product: '<S164>/Product'
         *  Sum: '<S164>/Sum1'
         */
        rtb_value_a = (Torque_Control_B.Merge2 + Torque_Control_B.Merge3_o) *
          0.1019367991845056 * Torque_Control_U.el_ACCEL_Y * 0.5;

        /* MATLAB Function: '<S163>/Kamm_Circle LatD' */
        Torque_Control_B.kamm_data[0] = (rtNaN);
        Torque_Control_B.kamm_data[17] = 0.0;
        Torque_Control_B.kamm_data[34] = 100.0;
        Torque_Control_B.kamm_data[51] = 200.0;
        Torque_Control_B.kamm_data[68] = 300.0;
        Torque_Control_B.kamm_data[85] = 400.0;
        Torque_Control_B.kamm_data[102] = 500.0;
        Torque_Control_B.kamm_data[119] = 600.0;
        Torque_Control_B.kamm_data[136] = 700.0;
        Torque_Control_B.kamm_data[153] = 800.0;
        Torque_Control_B.kamm_data[170] = 900.0;
        Torque_Control_B.kamm_data[187] = 1000.0;
        Torque_Control_B.kamm_data[204] = 1100.0;
        Torque_Control_B.kamm_data[221] = 1200.0;
        Torque_Control_B.kamm_data[238] = 1300.0;
        Torque_Control_B.kamm_data[255] = 1400.0;
        Torque_Control_B.kamm_data[272] = 1500.0;
        Torque_Control_B.kamm_data[289] = 1600.0;
        Torque_Control_B.kamm_data[306] = 1700.0;
        Torque_Control_B.kamm_data[323] = 1800.0;
        Torque_Control_B.kamm_data[340] = 1900.0;
        Torque_Control_B.kamm_data[357] = 2000.0;
        Torque_Control_B.kamm_data[374] = 2100.0;
        Torque_Control_B.kamm_data[391] = 2200.0;
        Torque_Control_B.kamm_data[408] = 2300.0;
        Torque_Control_B.kamm_data[425] = 2400.0;
        Torque_Control_B.kamm_data[442] = 2500.0;
        Torque_Control_B.kamm_data[459] = 2600.0;
        Torque_Control_B.kamm_data[476] = 2700.0;
        Torque_Control_B.kamm_data[493] = 2800.0;
        Torque_Control_B.kamm_data[510] = 2900.0;
        Torque_Control_B.kamm_data[527] = 3000.0;
        Torque_Control_B.kamm_data[1] = 0.0;
        Torque_Control_B.kamm_data[18] = 0.0;
        Torque_Control_B.kamm_data[35] = (rtNaN);
        Torque_Control_B.kamm_data[52] = (rtNaN);
        Torque_Control_B.kamm_data[69] = (rtNaN);
        Torque_Control_B.kamm_data[86] = (rtNaN);
        Torque_Control_B.kamm_data[103] = (rtNaN);
        Torque_Control_B.kamm_data[120] = (rtNaN);
        Torque_Control_B.kamm_data[137] = (rtNaN);
        Torque_Control_B.kamm_data[154] = (rtNaN);
        Torque_Control_B.kamm_data[171] = (rtNaN);
        Torque_Control_B.kamm_data[188] = (rtNaN);
        Torque_Control_B.kamm_data[205] = (rtNaN);
        Torque_Control_B.kamm_data[222] = (rtNaN);
        Torque_Control_B.kamm_data[239] = (rtNaN);
        Torque_Control_B.kamm_data[256] = (rtNaN);
        Torque_Control_B.kamm_data[273] = (rtNaN);
        Torque_Control_B.kamm_data[290] = (rtNaN);
        Torque_Control_B.kamm_data[307] = (rtNaN);
        Torque_Control_B.kamm_data[324] = (rtNaN);
        Torque_Control_B.kamm_data[341] = (rtNaN);
        Torque_Control_B.kamm_data[358] = (rtNaN);
        Torque_Control_B.kamm_data[375] = (rtNaN);
        Torque_Control_B.kamm_data[392] = (rtNaN);
        Torque_Control_B.kamm_data[409] = (rtNaN);
        Torque_Control_B.kamm_data[426] = (rtNaN);
        Torque_Control_B.kamm_data[443] = (rtNaN);
        Torque_Control_B.kamm_data[460] = (rtNaN);
        Torque_Control_B.kamm_data[477] = (rtNaN);
        Torque_Control_B.kamm_data[494] = (rtNaN);
        Torque_Control_B.kamm_data[511] = (rtNaN);
        Torque_Control_B.kamm_data[528] = (rtNaN);
        Torque_Control_B.kamm_data[2] = 100.0;
        Torque_Control_B.kamm_data[19] = 350.0;
        Torque_Control_B.kamm_data[36] = 340.0;
        Torque_Control_B.kamm_data[53] = 156.0;
        Torque_Control_B.kamm_data[70] = (rtNaN);
        Torque_Control_B.kamm_data[87] = (rtNaN);
        Torque_Control_B.kamm_data[104] = (rtNaN);
        Torque_Control_B.kamm_data[121] = (rtNaN);
        Torque_Control_B.kamm_data[138] = (rtNaN);
        Torque_Control_B.kamm_data[155] = (rtNaN);
        Torque_Control_B.kamm_data[172] = (rtNaN);
        Torque_Control_B.kamm_data[189] = (rtNaN);
        Torque_Control_B.kamm_data[206] = (rtNaN);
        Torque_Control_B.kamm_data[223] = (rtNaN);
        Torque_Control_B.kamm_data[240] = (rtNaN);
        Torque_Control_B.kamm_data[257] = (rtNaN);
        Torque_Control_B.kamm_data[274] = (rtNaN);
        Torque_Control_B.kamm_data[291] = (rtNaN);
        Torque_Control_B.kamm_data[308] = (rtNaN);
        Torque_Control_B.kamm_data[325] = (rtNaN);
        Torque_Control_B.kamm_data[342] = (rtNaN);
        Torque_Control_B.kamm_data[359] = (rtNaN);
        Torque_Control_B.kamm_data[376] = (rtNaN);
        Torque_Control_B.kamm_data[393] = (rtNaN);
        Torque_Control_B.kamm_data[410] = (rtNaN);
        Torque_Control_B.kamm_data[427] = (rtNaN);
        Torque_Control_B.kamm_data[444] = (rtNaN);
        Torque_Control_B.kamm_data[461] = (rtNaN);
        Torque_Control_B.kamm_data[478] = (rtNaN);
        Torque_Control_B.kamm_data[495] = (rtNaN);
        Torque_Control_B.kamm_data[512] = (rtNaN);
        Torque_Control_B.kamm_data[529] = (rtNaN);
        Torque_Control_B.kamm_data[3] = 200.0;
        Torque_Control_B.kamm_data[20] = 688.0;
        Torque_Control_B.kamm_data[37] = 676.0;
        Torque_Control_B.kamm_data[54] = 654.0;
        Torque_Control_B.kamm_data[71] = 573.0;
        Torque_Control_B.kamm_data[88] = 269.0;
        Torque_Control_B.kamm_data[105] = (rtNaN);
        Torque_Control_B.kamm_data[122] = (rtNaN);
        Torque_Control_B.kamm_data[139] = (rtNaN);
        Torque_Control_B.kamm_data[156] = (rtNaN);
        Torque_Control_B.kamm_data[173] = (rtNaN);
        Torque_Control_B.kamm_data[190] = (rtNaN);
        Torque_Control_B.kamm_data[207] = (rtNaN);
        Torque_Control_B.kamm_data[224] = (rtNaN);
        Torque_Control_B.kamm_data[241] = (rtNaN);
        Torque_Control_B.kamm_data[258] = (rtNaN);
        Torque_Control_B.kamm_data[275] = (rtNaN);
        Torque_Control_B.kamm_data[292] = (rtNaN);
        Torque_Control_B.kamm_data[309] = (rtNaN);
        Torque_Control_B.kamm_data[326] = (rtNaN);
        Torque_Control_B.kamm_data[343] = (rtNaN);
        Torque_Control_B.kamm_data[360] = (rtNaN);
        Torque_Control_B.kamm_data[377] = (rtNaN);
        Torque_Control_B.kamm_data[394] = (rtNaN);
        Torque_Control_B.kamm_data[411] = (rtNaN);
        Torque_Control_B.kamm_data[428] = (rtNaN);
        Torque_Control_B.kamm_data[445] = (rtNaN);
        Torque_Control_B.kamm_data[462] = (rtNaN);
        Torque_Control_B.kamm_data[479] = (rtNaN);
        Torque_Control_B.kamm_data[496] = (rtNaN);
        Torque_Control_B.kamm_data[513] = (rtNaN);
        Torque_Control_B.kamm_data[530] = (rtNaN);
        Torque_Control_B.kamm_data[4] = 300.0;
        Torque_Control_B.kamm_data[21] = 1002.0;
        Torque_Control_B.kamm_data[38] = 994.0;
        Torque_Control_B.kamm_data[55] = 982.0;
        Torque_Control_B.kamm_data[72] = 959.0;
        Torque_Control_B.kamm_data[89] = 888.0;
        Torque_Control_B.kamm_data[106] = 694.0;
        Torque_Control_B.kamm_data[123] = 345.0;
        Torque_Control_B.kamm_data[140] = (rtNaN);
        Torque_Control_B.kamm_data[157] = (rtNaN);
        Torque_Control_B.kamm_data[174] = (rtNaN);
        Torque_Control_B.kamm_data[191] = (rtNaN);
        Torque_Control_B.kamm_data[208] = (rtNaN);
        Torque_Control_B.kamm_data[225] = (rtNaN);
        Torque_Control_B.kamm_data[242] = (rtNaN);
        Torque_Control_B.kamm_data[259] = (rtNaN);
        Torque_Control_B.kamm_data[276] = (rtNaN);
        Torque_Control_B.kamm_data[293] = (rtNaN);
        Torque_Control_B.kamm_data[310] = (rtNaN);
        Torque_Control_B.kamm_data[327] = (rtNaN);
        Torque_Control_B.kamm_data[344] = (rtNaN);
        Torque_Control_B.kamm_data[361] = (rtNaN);
        Torque_Control_B.kamm_data[378] = (rtNaN);
        Torque_Control_B.kamm_data[395] = (rtNaN);
        Torque_Control_B.kamm_data[412] = (rtNaN);
        Torque_Control_B.kamm_data[429] = (rtNaN);
        Torque_Control_B.kamm_data[446] = (rtNaN);
        Torque_Control_B.kamm_data[463] = (rtNaN);
        Torque_Control_B.kamm_data[480] = (rtNaN);
        Torque_Control_B.kamm_data[497] = (rtNaN);
        Torque_Control_B.kamm_data[514] = (rtNaN);
        Torque_Control_B.kamm_data[531] = (rtNaN);
        Torque_Control_B.kamm_data[5] = 400.0;
        Torque_Control_B.kamm_data[22] = 1295.0;
        Torque_Control_B.kamm_data[39] = 1288.0;
        Torque_Control_B.kamm_data[56] = 1280.0;
        Torque_Control_B.kamm_data[73] = 1263.0;
        Torque_Control_B.kamm_data[90] = 1235.0;
        Torque_Control_B.kamm_data[107] = 1168.0;
        Torque_Control_B.kamm_data[124] = 1001.0;
        Torque_Control_B.kamm_data[141] = 740.0;
        Torque_Control_B.kamm_data[158] = 389.0;
        Torque_Control_B.kamm_data[175] = (rtNaN);
        Torque_Control_B.kamm_data[192] = (rtNaN);
        Torque_Control_B.kamm_data[209] = (rtNaN);
        Torque_Control_B.kamm_data[226] = (rtNaN);
        Torque_Control_B.kamm_data[243] = (rtNaN);
        Torque_Control_B.kamm_data[260] = (rtNaN);
        Torque_Control_B.kamm_data[277] = (rtNaN);
        Torque_Control_B.kamm_data[294] = (rtNaN);
        Torque_Control_B.kamm_data[311] = (rtNaN);
        Torque_Control_B.kamm_data[328] = (rtNaN);
        Torque_Control_B.kamm_data[345] = (rtNaN);
        Torque_Control_B.kamm_data[362] = (rtNaN);
        Torque_Control_B.kamm_data[379] = (rtNaN);
        Torque_Control_B.kamm_data[396] = (rtNaN);
        Torque_Control_B.kamm_data[413] = (rtNaN);
        Torque_Control_B.kamm_data[430] = (rtNaN);
        Torque_Control_B.kamm_data[447] = (rtNaN);
        Torque_Control_B.kamm_data[464] = (rtNaN);
        Torque_Control_B.kamm_data[481] = (rtNaN);
        Torque_Control_B.kamm_data[498] = (rtNaN);
        Torque_Control_B.kamm_data[515] = (rtNaN);
        Torque_Control_B.kamm_data[532] = (rtNaN);
        Torque_Control_B.kamm_data[6] = 500.0;
        Torque_Control_B.kamm_data[23] = 1536.0;
        Torque_Control_B.kamm_data[40] = 1529.0;
        Torque_Control_B.kamm_data[57] = 1521.0;
        Torque_Control_B.kamm_data[74] = 1509.0;
        Torque_Control_B.kamm_data[91] = 1491.0;
        Torque_Control_B.kamm_data[108] = 1459.0;
        Torque_Control_B.kamm_data[125] = 1395.0;
        Torque_Control_B.kamm_data[142] = 1230.0;
        Torque_Control_B.kamm_data[159] = 1032.0;
        Torque_Control_B.kamm_data[176] = 760.0;
        Torque_Control_B.kamm_data[193] = 411.0;
        Torque_Control_B.kamm_data[210] = (rtNaN);
        Torque_Control_B.kamm_data[227] = (rtNaN);
        Torque_Control_B.kamm_data[244] = (rtNaN);
        Torque_Control_B.kamm_data[261] = (rtNaN);
        Torque_Control_B.kamm_data[278] = (rtNaN);
        Torque_Control_B.kamm_data[295] = (rtNaN);
        Torque_Control_B.kamm_data[312] = (rtNaN);
        Torque_Control_B.kamm_data[329] = (rtNaN);
        Torque_Control_B.kamm_data[346] = (rtNaN);
        Torque_Control_B.kamm_data[363] = (rtNaN);
        Torque_Control_B.kamm_data[380] = (rtNaN);
        Torque_Control_B.kamm_data[397] = (rtNaN);
        Torque_Control_B.kamm_data[414] = (rtNaN);
        Torque_Control_B.kamm_data[431] = (rtNaN);
        Torque_Control_B.kamm_data[448] = (rtNaN);
        Torque_Control_B.kamm_data[465] = (rtNaN);
        Torque_Control_B.kamm_data[482] = (rtNaN);
        Torque_Control_B.kamm_data[499] = (rtNaN);
        Torque_Control_B.kamm_data[516] = (rtNaN);
        Torque_Control_B.kamm_data[533] = (rtNaN);
        Torque_Control_B.kamm_data[7] = 600.0;
        Torque_Control_B.kamm_data[24] = 1745.0;
        Torque_Control_B.kamm_data[41] = 1737.0;
        Torque_Control_B.kamm_data[58] = 1729.0;
        Torque_Control_B.kamm_data[75] = 1721.0;
        Torque_Control_B.kamm_data[92] = 1704.0;
        Torque_Control_B.kamm_data[109] = 1686.0;
        Torque_Control_B.kamm_data[126] = 1649.0;
        Torque_Control_B.kamm_data[143] = 1585.0;
        Torque_Control_B.kamm_data[160] = 1455.0;
        Torque_Control_B.kamm_data[177] = 1270.0;
        Torque_Control_B.kamm_data[194] = 1038.0;
        Torque_Control_B.kamm_data[211] = 756.0;
        Torque_Control_B.kamm_data[228] = 419.0;
        Torque_Control_B.kamm_data[245] = (rtNaN);
        Torque_Control_B.kamm_data[262] = (rtNaN);
        Torque_Control_B.kamm_data[279] = (rtNaN);
        Torque_Control_B.kamm_data[296] = (rtNaN);
        Torque_Control_B.kamm_data[313] = (rtNaN);
        Torque_Control_B.kamm_data[330] = (rtNaN);
        Torque_Control_B.kamm_data[347] = (rtNaN);
        Torque_Control_B.kamm_data[364] = (rtNaN);
        Torque_Control_B.kamm_data[381] = (rtNaN);
        Torque_Control_B.kamm_data[398] = (rtNaN);
        Torque_Control_B.kamm_data[415] = (rtNaN);
        Torque_Control_B.kamm_data[432] = (rtNaN);
        Torque_Control_B.kamm_data[449] = (rtNaN);
        Torque_Control_B.kamm_data[466] = (rtNaN);
        Torque_Control_B.kamm_data[483] = (rtNaN);
        Torque_Control_B.kamm_data[500] = (rtNaN);
        Torque_Control_B.kamm_data[517] = (rtNaN);
        Torque_Control_B.kamm_data[534] = (rtNaN);
        Torque_Control_B.kamm_data[8] = 700.0;
        Torque_Control_B.kamm_data[25] = 1964.0;
        Torque_Control_B.kamm_data[42] = 1956.0;
        Torque_Control_B.kamm_data[59] = 1948.0;
        Torque_Control_B.kamm_data[76] = 1940.0;
        Torque_Control_B.kamm_data[93] = 1926.0;
        Torque_Control_B.kamm_data[110] = 1909.0;
        Torque_Control_B.kamm_data[127] = 1884.0;
        Torque_Control_B.kamm_data[144] = 1848.0;
        Torque_Control_B.kamm_data[161] = 1777.0;
        Torque_Control_B.kamm_data[178] = 1656.0;
        Torque_Control_B.kamm_data[195] = 1484.0;
        Torque_Control_B.kamm_data[212] = 1278.0;
        Torque_Control_B.kamm_data[229] = 1029.0;
        Torque_Control_B.kamm_data[246] = 742.0;
        Torque_Control_B.kamm_data[263] = 416.0;
        Torque_Control_B.kamm_data[280] = (rtNaN);
        Torque_Control_B.kamm_data[297] = (rtNaN);
        Torque_Control_B.kamm_data[314] = (rtNaN);
        Torque_Control_B.kamm_data[331] = (rtNaN);
        Torque_Control_B.kamm_data[348] = (rtNaN);
        Torque_Control_B.kamm_data[365] = (rtNaN);
        Torque_Control_B.kamm_data[382] = (rtNaN);
        Torque_Control_B.kamm_data[399] = (rtNaN);
        Torque_Control_B.kamm_data[416] = (rtNaN);
        Torque_Control_B.kamm_data[433] = (rtNaN);
        Torque_Control_B.kamm_data[450] = (rtNaN);
        Torque_Control_B.kamm_data[467] = (rtNaN);
        Torque_Control_B.kamm_data[484] = (rtNaN);
        Torque_Control_B.kamm_data[501] = (rtNaN);
        Torque_Control_B.kamm_data[518] = (rtNaN);
        Torque_Control_B.kamm_data[535] = (rtNaN);
        Torque_Control_B.kamm_data[9] = 800.0;
        Torque_Control_B.kamm_data[26] = 2212.0;
        Torque_Control_B.kamm_data[43] = 2204.0;
        Torque_Control_B.kamm_data[60] = 2195.0;
        Torque_Control_B.kamm_data[77] = 2187.0;
        Torque_Control_B.kamm_data[94] = 2175.0;
        Torque_Control_B.kamm_data[111] = 2158.0;
        Torque_Control_B.kamm_data[128] = 2141.0;
        Torque_Control_B.kamm_data[145] = 2107.0;
        Torque_Control_B.kamm_data[162] = 2063.0;
        Torque_Control_B.kamm_data[179] = 1990.0;
        Torque_Control_B.kamm_data[196] = 1868.0;
        Torque_Control_B.kamm_data[213] = 1704.0;
        Torque_Control_B.kamm_data[230] = 1505.0;
        Torque_Control_B.kamm_data[247] = 1275.0;
        Torque_Control_B.kamm_data[264] = 1018.0;
        Torque_Control_B.kamm_data[281] = 730.0;
        Torque_Control_B.kamm_data[298] = 404.0;
        Torque_Control_B.kamm_data[315] = (rtNaN);
        Torque_Control_B.kamm_data[332] = (rtNaN);
        Torque_Control_B.kamm_data[349] = (rtNaN);
        Torque_Control_B.kamm_data[366] = (rtNaN);
        Torque_Control_B.kamm_data[383] = (rtNaN);
        Torque_Control_B.kamm_data[400] = (rtNaN);
        Torque_Control_B.kamm_data[417] = (rtNaN);
        Torque_Control_B.kamm_data[434] = (rtNaN);
        Torque_Control_B.kamm_data[451] = (rtNaN);
        Torque_Control_B.kamm_data[468] = (rtNaN);
        Torque_Control_B.kamm_data[485] = (rtNaN);
        Torque_Control_B.kamm_data[502] = (rtNaN);
        Torque_Control_B.kamm_data[519] = (rtNaN);
        Torque_Control_B.kamm_data[536] = (rtNaN);
        Torque_Control_B.kamm_data[10] = 900.0;
        Torque_Control_B.kamm_data[27] = 2465.0;
        Torque_Control_B.kamm_data[44] = 2456.0;
        Torque_Control_B.kamm_data[61] = 2448.0;
        Torque_Control_B.kamm_data[78] = 2439.0;
        Torque_Control_B.kamm_data[95] = 2428.0;
        Torque_Control_B.kamm_data[112] = 2411.0;
        Torque_Control_B.kamm_data[129] = 2394.0;
        Torque_Control_B.kamm_data[146] = 2367.0;
        Torque_Control_B.kamm_data[163] = 2333.0;
        Torque_Control_B.kamm_data[180] = 2279.0;
        Torque_Control_B.kamm_data[197] = 2200.0;
        Torque_Control_B.kamm_data[214] = 2081.0;
        Torque_Control_B.kamm_data[231] = 1921.0;
        Torque_Control_B.kamm_data[248] = 1729.0;
        Torque_Control_B.kamm_data[265] = 1512.0;
        Torque_Control_B.kamm_data[282] = 1268.0;
        Torque_Control_B.kamm_data[299] = 1002.0;
        Torque_Control_B.kamm_data[316] = 711.0;
        Torque_Control_B.kamm_data[333] = 345.0;
        Torque_Control_B.kamm_data[350] = (rtNaN);
        Torque_Control_B.kamm_data[367] = (rtNaN);
        Torque_Control_B.kamm_data[384] = (rtNaN);
        Torque_Control_B.kamm_data[401] = (rtNaN);
        Torque_Control_B.kamm_data[418] = (rtNaN);
        Torque_Control_B.kamm_data[435] = (rtNaN);
        Torque_Control_B.kamm_data[452] = (rtNaN);
        Torque_Control_B.kamm_data[469] = (rtNaN);
        Torque_Control_B.kamm_data[486] = (rtNaN);
        Torque_Control_B.kamm_data[503] = (rtNaN);
        Torque_Control_B.kamm_data[520] = (rtNaN);
        Torque_Control_B.kamm_data[537] = (rtNaN);
        Torque_Control_B.kamm_data[11] = 1000.0;
        Torque_Control_B.kamm_data[28] = 2684.0;
        Torque_Control_B.kamm_data[45] = 2675.0;
        Torque_Control_B.kamm_data[62] = 2666.0;
        Torque_Control_B.kamm_data[79] = 2657.0;
        Torque_Control_B.kamm_data[96] = 2647.0;
        Torque_Control_B.kamm_data[113] = 2629.0;
        Torque_Control_B.kamm_data[130] = 2612.0;
        Torque_Control_B.kamm_data[147] = 2592.0;
        Torque_Control_B.kamm_data[164] = 2558.0;
        Torque_Control_B.kamm_data[181] = 2520.0;
        Torque_Control_B.kamm_data[198] = 2462.0;
        Torque_Control_B.kamm_data[215] = 2378.0;
        Torque_Control_B.kamm_data[232] = 2262.0;
        Torque_Control_B.kamm_data[249] = 2119.0;
        Torque_Control_B.kamm_data[266] = 1940.0;
        Torque_Control_B.kamm_data[283] = 1737.0;
        Torque_Control_B.kamm_data[300] = 1508.0;
        Torque_Control_B.kamm_data[317] = 1259.0;
        Torque_Control_B.kamm_data[334] = 989.0;
        Torque_Control_B.kamm_data[351] = 680.0;
        Torque_Control_B.kamm_data[368] = 240.0;
        Torque_Control_B.kamm_data[385] = (rtNaN);
        Torque_Control_B.kamm_data[402] = (rtNaN);
        Torque_Control_B.kamm_data[419] = (rtNaN);
        Torque_Control_B.kamm_data[436] = (rtNaN);
        Torque_Control_B.kamm_data[453] = (rtNaN);
        Torque_Control_B.kamm_data[470] = (rtNaN);
        Torque_Control_B.kamm_data[487] = (rtNaN);
        Torque_Control_B.kamm_data[504] = (rtNaN);
        Torque_Control_B.kamm_data[521] = (rtNaN);
        Torque_Control_B.kamm_data[538] = (rtNaN);
        Torque_Control_B.kamm_data[12] = 1100.0;
        Torque_Control_B.kamm_data[29] = 2853.0;
        Torque_Control_B.kamm_data[46] = 2843.0;
        Torque_Control_B.kamm_data[63] = 2833.0;
        Torque_Control_B.kamm_data[80] = 2822.0;
        Torque_Control_B.kamm_data[97] = 2811.0;
        Torque_Control_B.kamm_data[114] = 2795.0;
        Torque_Control_B.kamm_data[131] = 2775.0;
        Torque_Control_B.kamm_data[148] = 2755.0;
        Torque_Control_B.kamm_data[165] = 2728.0;
        Torque_Control_B.kamm_data[182] = 2693.0;
        Torque_Control_B.kamm_data[199] = 2651.0;
        Torque_Control_B.kamm_data[216] = 2591.0;
        Torque_Control_B.kamm_data[233] = 2510.0;
        Torque_Control_B.kamm_data[250] = 2412.0;
        Torque_Control_B.kamm_data[267] = 2282.0;
        Torque_Control_B.kamm_data[284] = 2124.0;
        Torque_Control_B.kamm_data[301] = 1940.0;
        Torque_Control_B.kamm_data[318] = 1735.0;
        Torque_Control_B.kamm_data[335] = 1504.0;
        Torque_Control_B.kamm_data[352] = 1250.0;
        Torque_Control_B.kamm_data[369] = 962.0;
        Torque_Control_B.kamm_data[386] = 608.0;
        Torque_Control_B.kamm_data[403] = 108.0;
        Torque_Control_B.kamm_data[420] = (rtNaN);
        Torque_Control_B.kamm_data[437] = (rtNaN);
        Torque_Control_B.kamm_data[454] = (rtNaN);
        Torque_Control_B.kamm_data[471] = (rtNaN);
        Torque_Control_B.kamm_data[488] = (rtNaN);
        Torque_Control_B.kamm_data[505] = (rtNaN);
        Torque_Control_B.kamm_data[522] = (rtNaN);
        Torque_Control_B.kamm_data[539] = (rtNaN);
        Torque_Control_B.kamm_data[13] = 1200.0;
        Torque_Control_B.kamm_data[30] = 2999.0;
        Torque_Control_B.kamm_data[47] = 2988.0;
        Torque_Control_B.kamm_data[64] = 2976.0;
        Torque_Control_B.kamm_data[81] = 2964.0;
        Torque_Control_B.kamm_data[98] = 2952.0;
        Torque_Control_B.kamm_data[115] = 2936.0;
        Torque_Control_B.kamm_data[132] = 2914.0;
        Torque_Control_B.kamm_data[149] = 2893.0;
        Torque_Control_B.kamm_data[166] = 2872.0;
        Torque_Control_B.kamm_data[183] = 2837.0;
        Torque_Control_B.kamm_data[200] = 2799.0;
        Torque_Control_B.kamm_data[217] = 2755.0;
        Torque_Control_B.kamm_data[234] = 2694.0;
        Torque_Control_B.kamm_data[251] = 2619.0;
        Torque_Control_B.kamm_data[268] = 2527.0;
        Torque_Control_B.kamm_data[285] = 2412.0;
        Torque_Control_B.kamm_data[302] = 2275.0;
        Torque_Control_B.kamm_data[319] = 2114.0;
        Torque_Control_B.kamm_data[336] = 1936.0;
        Torque_Control_B.kamm_data[353] = 1729.0;
        Torque_Control_B.kamm_data[370] = 1507.0;
        Torque_Control_B.kamm_data[387] = 1233.0;
        Torque_Control_B.kamm_data[404] = 896.0;
        Torque_Control_B.kamm_data[421] = 461.0;
        Torque_Control_B.kamm_data[438] = (rtNaN);
        Torque_Control_B.kamm_data[455] = (rtNaN);
        Torque_Control_B.kamm_data[472] = (rtNaN);
        Torque_Control_B.kamm_data[489] = (rtNaN);
        Torque_Control_B.kamm_data[506] = (rtNaN);
        Torque_Control_B.kamm_data[523] = (rtNaN);
        Torque_Control_B.kamm_data[540] = (rtNaN);
        Torque_Control_B.kamm_data[14] = 1300.0;
        Torque_Control_B.kamm_data[31] = 3128.0;
        Torque_Control_B.kamm_data[48] = 3115.0;
        Torque_Control_B.kamm_data[65] = 3101.0;
        Torque_Control_B.kamm_data[82] = 3087.0;
        Torque_Control_B.kamm_data[99] = 3074.0;
        Torque_Control_B.kamm_data[116] = 3059.0;
        Torque_Control_B.kamm_data[133] = 3035.0;
        Torque_Control_B.kamm_data[150] = 3012.0;
        Torque_Control_B.kamm_data[167] = 2988.0;
        Torque_Control_B.kamm_data[184] = 2962.0;
        Torque_Control_B.kamm_data[201] = 2923.0;
        Torque_Control_B.kamm_data[218] = 2884.0;
        Torque_Control_B.kamm_data[235] = 2838.0;
        Torque_Control_B.kamm_data[252] = 2778.0;
        Torque_Control_B.kamm_data[269] = 2709.0;
        Torque_Control_B.kamm_data[286] = 2625.0;
        Torque_Control_B.kamm_data[303] = 2517.0;
        Torque_Control_B.kamm_data[320] = 2396.0;
        Torque_Control_B.kamm_data[337] = 2259.0;
        Torque_Control_B.kamm_data[354] = 2104.0;
        Torque_Control_B.kamm_data[371] = 1924.0;
        Torque_Control_B.kamm_data[388] = 1730.0;
        Torque_Control_B.kamm_data[405] = 1484.0;
        Torque_Control_B.kamm_data[422] = 1169.0;
        Torque_Control_B.kamm_data[439] = 772.0;
        Torque_Control_B.kamm_data[456] = 213.0;
        Torque_Control_B.kamm_data[473] = (rtNaN);
        Torque_Control_B.kamm_data[490] = (rtNaN);
        Torque_Control_B.kamm_data[507] = (rtNaN);
        Torque_Control_B.kamm_data[524] = (rtNaN);
        Torque_Control_B.kamm_data[541] = (rtNaN);
        Torque_Control_B.kamm_data[15] = 1400.0;
        Torque_Control_B.kamm_data[32] = 3228.0;
        Torque_Control_B.kamm_data[49] = 3215.0;
        Torque_Control_B.kamm_data[66] = 3201.0;
        Torque_Control_B.kamm_data[83] = 3187.0;
        Torque_Control_B.kamm_data[100] = 3172.0;
        Torque_Control_B.kamm_data[117] = 3157.0;
        Torque_Control_B.kamm_data[134] = 3134.0;
        Torque_Control_B.kamm_data[151] = 3111.0;
        Torque_Control_B.kamm_data[168] = 3087.0;
        Torque_Control_B.kamm_data[185] = 3063.0;
        Torque_Control_B.kamm_data[202] = 3026.0;
        Torque_Control_B.kamm_data[219] = 2989.0;
        Torque_Control_B.kamm_data[236] = 2952.0;
        Torque_Control_B.kamm_data[253] = 2896.0;
        Torque_Control_B.kamm_data[270] = 2841.0;
        Torque_Control_B.kamm_data[287] = 2772.0;
        Torque_Control_B.kamm_data[304] = 2691.0;
        Torque_Control_B.kamm_data[321] = 2603.0;
        Torque_Control_B.kamm_data[338] = 2500.0;
        Torque_Control_B.kamm_data[355] = 2379.0;
        Torque_Control_B.kamm_data[372] = 2243.0;
        Torque_Control_B.kamm_data[389] = 2091.0;
        Torque_Control_B.kamm_data[406] = 1927.0;
        Torque_Control_B.kamm_data[423] = 1713.0;
        Torque_Control_B.kamm_data[440] = 1414.0;
        Torque_Control_B.kamm_data[457] = 1030.0;
        Torque_Control_B.kamm_data[474] = 553.0;
        Torque_Control_B.kamm_data[491] = (rtNaN);
        Torque_Control_B.kamm_data[508] = (rtNaN);
        Torque_Control_B.kamm_data[525] = (rtNaN);
        Torque_Control_B.kamm_data[542] = (rtNaN);
        Torque_Control_B.kamm_data[16] = 1500.0;
        Torque_Control_B.kamm_data[33] = 3327.0;
        Torque_Control_B.kamm_data[50] = 3312.0;
        Torque_Control_B.kamm_data[67] = 3296.0;
        Torque_Control_B.kamm_data[84] = 3280.0;
        Torque_Control_B.kamm_data[101] = 3263.0;
        Torque_Control_B.kamm_data[118] = 3247.0;
        Torque_Control_B.kamm_data[135] = 3223.0;
        Torque_Control_B.kamm_data[152] = 3198.0;
        Torque_Control_B.kamm_data[169] = 3173.0;
        Torque_Control_B.kamm_data[186] = 3147.0;
        Torque_Control_B.kamm_data[203] = 3116.0;
        Torque_Control_B.kamm_data[220] = 3078.0;
        Torque_Control_B.kamm_data[237] = 3040.0;
        Torque_Control_B.kamm_data[254] = 3001.0;
        Torque_Control_B.kamm_data[271] = 2947.0;
        Torque_Control_B.kamm_data[288] = 2893.0;
        Torque_Control_B.kamm_data[305] = 2828.0;
        Torque_Control_B.kamm_data[322] = 2756.0;
        Torque_Control_B.kamm_data[339] = 2670.0;
        Torque_Control_B.kamm_data[356] = 2576.0;
        Torque_Control_B.kamm_data[373] = 2471.0;
        Torque_Control_B.kamm_data[390] = 2353.0;
        Torque_Control_B.kamm_data[407] = 2228.0;
        Torque_Control_B.kamm_data[424] = 2100.0;
        Torque_Control_B.kamm_data[441] = 1921.0;
        Torque_Control_B.kamm_data[458] = 1649.0;
        Torque_Control_B.kamm_data[475] = 1278.0;
        Torque_Control_B.kamm_data[492] = 814.0;
        Torque_Control_B.kamm_data[509] = 217.0;
        Torque_Control_B.kamm_data[526] = (rtNaN);
        Torque_Control_B.kamm_data[543] = (rtNaN);
        mz = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          p = Torque_Control_B.kamm_data[(int32_T)k];
          if (Torque_Control_B.Merge2 > p) {
            mz = k;
          } else if (Torque_Control_B.Merge2 < p) {
            Mz = k;
          }

          k = floor((Mz + mz) / 2.0);
          p = Mz - mz;
          if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data[(int32_T)Mz])
          {
            p = 1.0;
            mz = Mz;
          } else if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data
                     [(int32_T)mz]) {
            p = 1.0;
            Mz = mz;
          } else if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data
                     [(int32_T)k]) {
            p = 1.0;
            Mz = k;
            mz = k;
          }
        }

        my = 1.0;
        My = 31.0;
        k = 16.0;
        p = 30.0;
        while (p != 1.0) {
          p = Torque_Control_B.kamm_data[17 * (int32_T)k];
          if (rtb_value_a > p) {
            my = k;
          } else if (rtb_value_a < p) {
            My = k;
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_value_a) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == rtb_value_a)
          {
            p = 1.0;
            My = my;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_value_a)
          {
            p = 1.0;
            My = k;
            my = k;
          }
        }

        if ((Mz == mz) && (My != my)) {
          r1 = 17 * (int32_T)my;
          kamm_data[0] = Torque_Control_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          kamm_data[1] = Torque_Control_B.kamm_data[r2];
          kamm_data_0[0] = Torque_Control_B.kamm_data[r1 + (int32_T)mz];
          kamm_data_0[1] = Torque_Control_B.kamm_data[r2 + (int32_T)mz];
          polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
          rtb_alpha_m = b_a[0] * rtb_value_a + b_a[1];
        } else if ((Mz != mz) && (My == my)) {
          kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
          kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
          kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)mz];
          kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
          rtb_alpha_m = b_a[0] * Torque_Control_B.Merge2 + b_a[1];
        } else if ((Mz == mz) && (My == my)) {
          rtb_alpha_m = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
            Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          p = Torque_Control_B.kamm_data[(int32_T)mz];
          tmp[4] = p;
          tmp[5] = p;
          p = Torque_Control_B.kamm_data[(int32_T)Mz];
          tmp[6] = p;
          tmp[7] = p;
          p = Torque_Control_B.kamm_data[17 * (int32_T)my];
          tmp[8] = p;
          k = Torque_Control_B.kamm_data[17 * (int32_T)My];
          tmp[9] = k;
          tmp[10] = p;
          tmp[11] = k;
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)mz];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)mz];
          kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)Mz];
          mldivide_8ZFDevWm(tmp, kamm_data_1, a);
          rtb_alpha_m = (a[1] * Torque_Control_B.Merge2 + a[0]) + a[2] *
            rtb_value_a;
        }

        mz = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          p = Torque_Control_B.kamm_data[(int32_T)k];
          if (Torque_Control_B.Merge3_o > p) {
            mz = k;
          } else if (Torque_Control_B.Merge3_o < p) {
            Mz = k;
          }

          k = floor((Mz + mz) / 2.0);
          p = Mz - mz;
          if (Torque_Control_B.Merge3_o == Torque_Control_B.kamm_data[(int32_T)
              Mz]) {
            p = 1.0;
            mz = Mz;
          } else if (Torque_Control_B.Merge3_o == Torque_Control_B.kamm_data
                     [(int32_T)mz]) {
            p = 1.0;
            Mz = mz;
          } else if (Torque_Control_B.Merge3_o == Torque_Control_B.kamm_data
                     [(int32_T)k]) {
            p = 1.0;
            Mz = k;
            mz = k;
          }
        }

        my = 1.0;
        My = 31.0;
        k = 16.0;
        p = 30.0;
        while (p != 1.0) {
          p = Torque_Control_B.kamm_data[17 * (int32_T)k];
          if (rtb_value_a > p) {
            my = k;
          } else if (rtb_value_a < p) {
            My = k;
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_value_a) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == rtb_value_a)
          {
            p = 1.0;
            My = my;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_value_a)
          {
            p = 1.0;
            My = k;
            my = k;
          }
        }

        if ((Mz == mz) && (My != my)) {
          r1 = 17 * (int32_T)my;
          kamm_data[0] = Torque_Control_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          kamm_data[1] = Torque_Control_B.kamm_data[r2];
          kamm_data_0[0] = Torque_Control_B.kamm_data[r1 + (int32_T)mz];
          kamm_data_0[1] = Torque_Control_B.kamm_data[r2 + (int32_T)mz];
          polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
          mz = b_a[0] * rtb_value_a + b_a[1];
        } else if ((Mz != mz) && (My == my)) {
          kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
          kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
          kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)mz];
          kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
          mz = b_a[0] * Torque_Control_B.Merge3_o + b_a[1];
        } else if ((Mz == mz) && (My == my)) {
          mz = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          p = Torque_Control_B.kamm_data[(int32_T)mz];
          tmp[4] = p;
          tmp[5] = p;
          p = Torque_Control_B.kamm_data[(int32_T)Mz];
          tmp[6] = p;
          tmp[7] = p;
          p = Torque_Control_B.kamm_data[17 * (int32_T)my];
          tmp[8] = p;
          k = Torque_Control_B.kamm_data[17 * (int32_T)My];
          tmp[9] = k;
          tmp[10] = p;
          tmp[11] = k;
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)mz];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)mz];
          kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)Mz];
          mldivide_8ZFDevWm(tmp, kamm_data_1, a);
          mz = (a[1] * Torque_Control_B.Merge3_o + a[0]) + a[2] * rtb_value_a;
        }

        /* Product: '<S163>/Product' incorporates:
         *  MATLAB Function: '<S163>/Kamm_Circle LatD'
         */
        rtb_Product_p = rtb_alpha_m * rtb_Gain_f;

        /* MATLAB Function: '<S163>/MATLAB Function2' incorporates:
         *  Constant: '<S163>/Constant1'
         */
        Torque_Control_MATLABFunction_f(-1.0, rtb_Product_p,
          &Torque_Control_B.sf_MATLABFunction2_a);

        /* MATLAB Function: '<S161>/MATLAB Function2' incorporates:
         *  Constant: '<S161>/Constant'
         */
        Torque_Control_MATLABFunction_f(0.0,
          Torque_Control_B.sf_MATLABFunction2_a.value,
          &Torque_Control_B.sf_MATLABFunction2_o);

        /* Product: '<S183>/Product' */
        rtb_alpha_m = Torque_Control_B.sf_MATLABFunction2_o.value *
          Torque_Control_ConstB.udifference;

        /* Product: '<S163>/Product1' incorporates:
         *  MATLAB Function: '<S163>/Kamm_Circle LatD'
         */
        rtb_Product1 = mz * rtb_Gain_f;

        /* MATLAB Function: '<S163>/MATLAB Function1' incorporates:
         *  Constant: '<S163>/Constant'
         */
        Torque_Control_MATLABFunction_f(-1.0, rtb_Product1,
          &Torque_Control_B.sf_MATLABFunction1_a);

        /* MATLAB Function: '<S161>/MATLAB Function1' incorporates:
         *  Constant: '<S161>/Constant1'
         */
        Torque_Control_MATLABFunction_f(0.0,
          Torque_Control_B.sf_MATLABFunction1_a.value,
          &Torque_Control_B.sf_MATLABFunction1_g);

        /* Product: '<S182>/Product' */
        maxval = Torque_Control_B.sf_MATLABFunction1_g.value *
          Torque_Control_ConstB.udifference;

        /* If: '<S160>/Braking Conditions' incorporates:
         *  Inport: '<Root>/APPS1_Value'
         *  Inport: '<Root>/BrakeSensor_Value'
         *  Inport: '<Root>/VDC_Apps_Sat_Down'
         */
        if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
            (Torque_Control_U.APPS1_Value <= Torque_Control_U.VDC_Apps_Sat_Down)
            && (Torque_Control_B.Merge1_a == 1.0)) {
          Torque_Control_DW.BrakingConditions_ActiveSubsy_f = 0;

          /* Outputs for IfAction SubSystem: '<S160>/Regenerative+Mech Braking' incorporates:
           *  ActionPort: '<S179>/Action Port'
           */
          /* MATLAB Function: '<S179>/MATLAB Function' */
          if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
            rtb_value_a = 0.0;
          } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
            rtb_value_a = 1.0;
          } else {
            rtb_value_a = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
          }

          /* Merge: '<S160>/Merge1' incorporates:
           *  MATLAB Function: '<S179>/MATLAB Function'
           *  SignalConversion generated from: '<S179>/Tq_RL'
           */
          Torque_Control_B.Merge1_c = rtb_value_a * maxval;

          /* Merge: '<S160>/Merge' incorporates:
           *  MATLAB Function: '<S179>/MATLAB Function'
           *  SignalConversion generated from: '<S179>/Tq_RR  '
           */
          Torque_Control_B.Merge_ag = rtb_value_a * rtb_alpha_m;

          /* End of Outputs for SubSystem: '<S160>/Regenerative+Mech Braking' */
        } else if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
                   (Torque_Control_U.APPS1_Value <=
                    Torque_Control_U.VDC_Apps_Sat_Down) &&
                   (Torque_Control_B.Merge1_a == 0.0)) {
          Torque_Control_DW.BrakingConditions_ActiveSubsy_f = 1;

          /* Outputs for IfAction SubSystem: '<S160>/Mech_Braking' incorporates:
           *  ActionPort: '<S178>/Action Port'
           */
          Torque_Control_Mech_Braking(&Torque_Control_B.Merge_ag,
            &Torque_Control_B.Merge1_c);

          /* End of Outputs for SubSystem: '<S160>/Mech_Braking' */
        } else if ((Torque_Control_U.BrakeSensor_Value == 0.0) &&
                   (Torque_Control_U.APPS1_Value == 0.0)) {
          Torque_Control_DW.BrakingConditions_ActiveSubsy_f = 2;

          /* Outputs for IfAction SubSystem: '<S160>/Inertia Braking' incorporates:
           *  ActionPort: '<S177>/Action Port'
           */
          Torque_Control_Mech_Braking(&Torque_Control_B.Merge_ag,
            &Torque_Control_B.Merge1_c);

          /* End of Outputs for SubSystem: '<S160>/Inertia Braking' */
        } else {
          Torque_Control_DW.BrakingConditions_ActiveSubsy_f = 3;

          /* Outputs for IfAction SubSystem: '<S160>/Accelerating' incorporates:
           *  ActionPort: '<S176>/Action Port'
           */
          /* MATLAB Function: '<S176>/Accelerator behaviour ' incorporates:
           *  Inport: '<Root>/VDC_Apps_Sat_Up'
           */
          Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
            Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
            &Torque_Control_B.sf_Acceleratorbehaviour_i);

          /* Merge: '<S160>/Merge1' incorporates:
           *  Product: '<S176>/Product'
           */
          Torque_Control_B.Merge1_c =
            Torque_Control_B.sf_Acceleratorbehaviour_i.throttle * maxval;

          /* Merge: '<S160>/Merge' incorporates:
           *  Product: '<S176>/Product1'
           */
          Torque_Control_B.Merge_ag =
            Torque_Control_B.sf_Acceleratorbehaviour_i.throttle * rtb_alpha_m;

          /* End of Outputs for SubSystem: '<S160>/Accelerating' */
        }

        /* End of If: '<S160>/Braking Conditions' */

        /* If: '<S159>/If' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         *  Inport: '<Root>/VDC_Max_Regen_Motor_Tq'
         */
        if ((Torque_Control_B.Merge1_a == 1.0) &&
            (Torque_Control_U.BrakeSensor_Value > 0.0)) {
          Torque_Control_DW.If_ActiveSubsystem_l = 0;

          /* Outputs for IfAction SubSystem: '<S159>/Braking with Regenerative' incorporates:
           *  ActionPort: '<S168>/Action Port'
           */
          Torque__BrakingwithRegenerative
            (Torque_Control_U.VDC_Max_Regen_Motor_Tq, Torque_Control_B.Merge_ag,
             Torque_Control_B.Merge1_c, &Torque_Control_B.MergeTq_RR,
             &Torque_Control_B.MergeTq_RL);

          /* End of Outputs for SubSystem: '<S159>/Braking with Regenerative' */
        } else {
          Torque_Control_DW.If_ActiveSubsystem_l = 1;

          /* Outputs for IfAction SubSystem: '<S159>/Acelerating and braking without Regenerative' incorporates:
           *  ActionPort: '<S167>/Action Port'
           */
          /* If: '<S167>/If1' */
          if ((rtb_Abs2 > Torque_Control_ConstB.approx2095) &&
              (Torque_Control_B.Abs3 > Torque_Control_ConstB.approx2095)) {
            Torque_Control_DW.If1_ActiveSubsystem_oe = 0;

            /* Outputs for IfAction SubSystem: '<S167>/If Action 1' incorporates:
             *  ActionPort: '<S169>/Action Port'
             */
            Torque_Control_IfAction1(Torque_Control_ConstB.TowheelTqdynamic,
              &Torque_Control_B.Merge2_d);

            /* End of Outputs for SubSystem: '<S167>/If Action 1' */
          } else {
            Torque_Control_DW.If1_ActiveSubsystem_oe = 1;

            /* Outputs for IfAction SubSystem: '<S167>/If Action 2' incorporates:
             *  ActionPort: '<S170>/Action Port'
             */
            Torque_Control_IfAction2(Torque_Control_ConstB.TowheelTqstatic,
              &Torque_Control_B.Merge2_d);

            /* End of Outputs for SubSystem: '<S167>/If Action 2' */
          }

          /* End of If: '<S167>/If1' */

          /* MATLAB Function: '<S167>/minimum value' */
          rtb_value_a = Torque_Control_B.Merge2_d;
          if (Torque_Control_ConstB.Product < Torque_Control_B.Merge2_d) {
            rtb_value_a = Torque_Control_ConstB.Product;
          }

          if (Torque_Control_B.Merge_ag < rtb_value_a) {
            rtb_value_a = Torque_Control_B.Merge_ag;
          }

          /* End of MATLAB Function: '<S167>/minimum value' */

          /* MATLAB Function: '<S167>/minimum value1' */
          rtb_alpha_m = Torque_Control_B.Merge2_d;
          if (Torque_Control_ConstB.Product < Torque_Control_B.Merge2_d) {
            rtb_alpha_m = Torque_Control_ConstB.Product;
          }

          if (Torque_Control_B.Merge1_c < rtb_alpha_m) {
            rtb_alpha_m = Torque_Control_B.Merge1_c;
          }

          /* End of MATLAB Function: '<S167>/minimum value1' */

          /* MATLAB Function: '<S171>/MATLAB Function' */
          if ((rtb_value_a == Torque_Control_B.Merge_ag) && (rtb_alpha_m ==
               Torque_Control_B.Merge1_c)) {
            /* Merge: '<S11>/Merge Tq_RR' */
            Torque_Control_B.MergeTq_RR = rtb_value_a;

            /* Merge: '<S11>/Merge Tq_RL' */
            Torque_Control_B.MergeTq_RL = rtb_alpha_m;
          } else if (Torque_Control_B.Merge_ag > Torque_Control_B.Merge1_c) {
            /* Merge: '<S11>/Merge Tq_RR' */
            Torque_Control_B.MergeTq_RR = rtb_value_a;

            /* Merge: '<S11>/Merge Tq_RL' */
            Torque_Control_B.MergeTq_RL = Torque_Control_B.Merge1_c /
              Torque_Control_B.Merge_ag * rtb_value_a;
          } else if (Torque_Control_B.Merge_ag < Torque_Control_B.Merge1_c) {
            /* Merge: '<S11>/Merge Tq_RR' */
            Torque_Control_B.MergeTq_RR = Torque_Control_B.Merge_ag /
              Torque_Control_B.Merge1_c * rtb_alpha_m;

            /* Merge: '<S11>/Merge Tq_RL' */
            Torque_Control_B.MergeTq_RL = rtb_alpha_m;
          } else {
            /* Merge: '<S11>/Merge Tq_RR' */
            Torque_Control_B.MergeTq_RR = rtb_value_a;

            /* Merge: '<S11>/Merge Tq_RL' */
            Torque_Control_B.MergeTq_RL = rtb_alpha_m;
          }

          /* End of MATLAB Function: '<S171>/MATLAB Function' */
          /* End of Outputs for SubSystem: '<S159>/Acelerating and braking without Regenerative' */
        }

        /* End of If: '<S159>/If' */

        /* Merge: '<S11>/Merge3' incorporates:
         *  SignalConversion generated from: '<S71>/CKF_act'
         */
        Torque_Control_B.Merge3_i = rtb_Gain_f;

        /* End of Outputs for SubSystem: '<S11>/VDC without Longitudinal' */
      }
      break;

     case 2:
      {
        /* Outputs for IfAction SubSystem: '<S11>/Steering TV with TC' incorporates:
         *  ActionPort: '<S69>/Action Port'
         */
        /* MATLAB Function: '<S88>/MATLAB Function1' incorporates:
         *  Constant: '<S88>/Steering Wheel Maximum Angle'
         *  Gain: '<S11>/Gain'
         *  Inport: '<Root>/SteeringSensor_Value'
         */
        if ((-Torque_Control_U.SteeringSensor_Value > 100.0) ||
            (-Torque_Control_U.SteeringSensor_Value < -100.0)) {
          rtb_value_a = 100.0;
        } else {
          rtb_value_a = -Torque_Control_U.SteeringSensor_Value;
        }

        /* End of MATLAB Function: '<S88>/MATLAB Function1' */

        /* MinMax: '<S79>/Max' */
        Torque_Control_B.wrads = fmax(Torque_Control_B.Abs3, rtb_Abs2);

        /* Derivative: '<S79>/Derivative' */
        rtb_alpha_m = Torque_Control_M->Timing.t[0];
        if ((Torque_Control_DW.TimeStampA >= rtb_alpha_m) &&
            (Torque_Control_DW.TimeStampB >= rtb_alpha_m)) {
          rtb_alpha_m = 0.0;
        } else {
          maxval = Torque_Control_DW.TimeStampA;
          lastU = &Torque_Control_DW.LastUAtTimeA;
          if (Torque_Control_DW.TimeStampA < Torque_Control_DW.TimeStampB) {
            if (Torque_Control_DW.TimeStampB < rtb_alpha_m) {
              maxval = Torque_Control_DW.TimeStampB;
              lastU = &Torque_Control_DW.LastUAtTimeB;
            }
          } else if (Torque_Control_DW.TimeStampA >= rtb_alpha_m) {
            maxval = Torque_Control_DW.TimeStampB;
            lastU = &Torque_Control_DW.LastUAtTimeB;
          }

          rtb_alpha_m = (Torque_Control_B.wrads - *lastU) / (rtb_alpha_m -
            maxval);
        }

        /* End of Derivative: '<S79>/Derivative' */

        /* If: '<S88>/SKF or CKF' */
        rtPrevAction = Torque_Control_DW.SKForCKF_ActiveSubsystem;
        rtAction = (int8_T)((!(rtb_value_a > -10.0)) || (!(rtb_value_a < 10.0)));
        Torque_Control_DW.SKForCKF_ActiveSubsystem = rtAction;
        if ((rtPrevAction != rtAction) && (rtPrevAction == 1)) {
          /* Disable for If: '<S89>/If1' */
          Torque_Control_DW.If1_ActiveSubsystem_o = -1;
        }

        if (rtAction == 0) {
          /* Outputs for IfAction SubSystem: '<S88>/SKF' incorporates:
           *  ActionPort: '<S91>/Action Port'
           */
          /* If: '<S91>/If' */
          Torque_Control_DW.If_ActiveSubsystem_p = -1;
          if (rtb_alpha_m >= 900.0) {
            real_T k;
            Torque_Control_DW.If_ActiveSubsystem_p = 0;

            /* Outputs for IfAction SubSystem: '<S91>/Spin' incorporates:
             *  ActionPort: '<S97>/Action Port'
             */
            /* Switch: '<S97>/Switch1' incorporates:
             *  DataStoreRead: '<S79>/SKF_prev '
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            if (Torque_Control_DW.A > 0.0) {
              p = Torque_Control_DW.A;
            } else {
              p = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of Switch: '<S97>/Switch1' */

            /* Switch: '<S97>/Switch' incorporates:
             *  Constant: '<S97>/Constant'
             *  Inport: '<Root>/VDC_Cte_SKF'
             */
            if (Torque_Control_U.VDC_Cte_SKF >= 0.9) {
              k = Torque_Control_U.VDC_Cte_SKF;
            } else {
              k = 1.0;
            }

            /* End of Switch: '<S97>/Switch' */

            /* Product: '<S97>/Product' */
            rtb_value_a = p * k;

            /* MATLAB Function: '<S97>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            if (rtb_value_a < Torque_Control_U.VDC_SKF_Initial) {
              /* Merge: '<S91>/Merge' incorporates:
               *  SignalConversion generated from: '<S97>/SKF_act1'
               */
              Torque_Control_B.Merge_d = rtb_value_a;
            } else {
              /* Merge: '<S91>/Merge' incorporates:
               *  SignalConversion generated from: '<S97>/SKF_act1'
               */
              Torque_Control_B.Merge_d = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of MATLAB Function: '<S97>/MATLAB Function' */
            /* End of Outputs for SubSystem: '<S91>/Spin' */
          } else if (rtb_alpha_m < 900.0) {
            Torque_Control_DW.If_ActiveSubsystem_p = 1;

            /* Outputs for IfAction SubSystem: '<S91>/No spin' incorporates:
             *  ActionPort: '<S96>/Action Port'
             */
            /* Switch: '<S96>/Switch' incorporates:
             *  DataStoreRead: '<S79>/SKF_prev '
             */
            if (Torque_Control_DW.A > 0.0) {
              /* Switch: '<S96>/Switch' */
              rtb_Switch_h = Torque_Control_DW.A;
            } else {
              /* Switch: '<S96>/Switch' incorporates:
               *  Inport: '<Root>/VDC_SKF_Initial'
               */
              rtb_Switch_h = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of Switch: '<S96>/Switch' */

            /* MATLAB Function: '<S96>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_Cte_SKF'
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            Torque_Control_MATLABFunction_h(rtb_Switch_h,
              Torque_Control_U.VDC_SKF_Initial, Torque_Control_U.VDC_Cte_SKF,
              &Torque_Control_B.sf_MATLABFunction_i);

            /* Merge: '<S91>/Merge' incorporates:
             *  SignalConversion generated from: '<S96>/SKF_act0'
             */
            Torque_Control_B.Merge_d =
              Torque_Control_B.sf_MATLABFunction_i.SKF_act0;

            /* End of Outputs for SubSystem: '<S91>/No spin' */
          }

          /* End of If: '<S91>/If' */

          /* Saturate: '<S91>/Saturation' */
          if (Torque_Control_B.Merge_d > 1.0) {
            /* Saturate: '<S91>/Saturation' */
            Torque_Control_B.Saturation_j = 1.0;
          } else if (Torque_Control_B.Merge_d < 0.3) {
            /* Saturate: '<S91>/Saturation' */
            Torque_Control_B.Saturation_j = 0.3;
          } else {
            /* Saturate: '<S91>/Saturation' */
            Torque_Control_B.Saturation_j = Torque_Control_B.Merge_d;
          }

          /* End of Saturate: '<S91>/Saturation' */
          /* End of Outputs for SubSystem: '<S88>/SKF' */
        } else {
          /* Outputs for IfAction SubSystem: '<S88>/CKF' incorporates:
           *  ActionPort: '<S89>/Action Port'
           */
          /* If: '<S89>/If1' */
          rtAction = -1;
          if (rtb_alpha_m >= 900.0) {
            rtAction = 0;
          } else if (rtb_alpha_m < 900.0) {
            rtAction = 1;
          }

          Torque_Control_DW.If1_ActiveSubsystem_o = rtAction;
          switch (rtAction) {
           case 0:
            /* Outputs for IfAction SubSystem: '<S89>/Spin ' incorporates:
             *  ActionPort: '<S93>/Action Port'
             */
            /* Switch: '<S93>/Switch1' incorporates:
             *  DataStoreRead: '<S79>/CKF_prev'
             */
            if (Torque_Control_DW.B > 0.0) {
              /* Switch: '<S93>/Switch1' */
              Torque_Control_B.Switch1 = Torque_Control_DW.B;
            } else {
              /* Switch: '<S93>/Switch1' incorporates:
               *  Inport: '<Root>/VDC_CKF_Initial'
               */
              Torque_Control_B.Switch1 = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of Switch: '<S93>/Switch1' */
            /* Switch: '<S93>/Switch' incorporates:
             *  Constant: '<S93>/Constant'
             *  Inport: '<Root>/VDC_Cte_CKF'
             */
            if (Torque_Control_U.VDC_Cte_CKF >= 0.9) {
              p = Torque_Control_U.VDC_Cte_CKF;
            } else {
              p = 1.0;
            }

            /* End of Switch: '<S93>/Switch' */

            /* Product: '<S93>/Product' */
            rtb_value_a = Torque_Control_B.Switch1 * p;

            /* MATLAB Function: '<S93>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             */
            if (rtb_value_a < Torque_Control_U.VDC_CKF_Initial) {
              /* Merge: '<S89>/Merge' incorporates:
               *  SignalConversion generated from: '<S93>/CKF_act1 '
               */
              Torque_Control_B.Merge_j = rtb_value_a;
            } else {
              /* Merge: '<S89>/Merge' incorporates:
               *  SignalConversion generated from: '<S93>/CKF_act1 '
               */
              Torque_Control_B.Merge_j = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of MATLAB Function: '<S93>/MATLAB Function' */
            /* End of Outputs for SubSystem: '<S89>/Spin ' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S89>/No spin' incorporates:
             *  ActionPort: '<S92>/Action Port'
             */
            /* Switch: '<S92>/Switch' incorporates:
             *  DataStoreRead: '<S79>/CKF_prev'
             */
            if (Torque_Control_DW.B > 0.0) {
              /* Switch: '<S92>/Switch' */
              rtb_Switch = Torque_Control_DW.B;
            } else {
              /* Switch: '<S92>/Switch' incorporates:
               *  Inport: '<Root>/VDC_CKF_Initial'
               */
              rtb_Switch = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of Switch: '<S92>/Switch' */

            /* MATLAB Function: '<S92>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             *  Inport: '<Root>/VDC_Cte_CKF'
             */
            Torque_Contro_MATLABFunction1_n(rtb_Switch,
              Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_CKF,
              &Torque_Control_B.sf_MATLABFunction_m0);

            /* Merge: '<S89>/Merge' incorporates:
             *  SignalConversion generated from: '<S92>/CKF_act0'
             */
            Torque_Control_B.Merge_j =
              Torque_Control_B.sf_MATLABFunction_m0.CKF_act0;

            /* End of Outputs for SubSystem: '<S89>/No spin' */
            break;
          }

          /* End of If: '<S89>/If1' */

          /* Saturate: '<S89>/Saturation' */
          if (Torque_Control_B.Merge_j > 1.0) {
            /* Saturate: '<S89>/Saturation' */
            Torque_Control_B.Saturation_n = 1.0;
          } else if (Torque_Control_B.Merge_j < 0.3) {
            /* Saturate: '<S89>/Saturation' */
            Torque_Control_B.Saturation_n = 0.3;
          } else {
            /* Saturate: '<S89>/Saturation' */
            Torque_Control_B.Saturation_n = Torque_Control_B.Merge_j;
          }

          /* End of Saturate: '<S89>/Saturation' */
          /* End of Outputs for SubSystem: '<S88>/CKF' */
        }

        /* End of If: '<S88>/SKF or CKF' */

        /* DataStoreWrite: '<S79>/Data Store Write' */
        Torque_Control_DW.A = Torque_Control_B.Saturation_j;

        /* DataStoreWrite: '<S79>/Data Store Write1' */
        Torque_Control_DW.B = Torque_Control_B.Saturation_n;

        /* Saturate: '<S79>/Saturation' */
        if (rtb_alpha_m > 6000.0) {
          /* Saturate: '<S79>/Saturation' */
          Torque_Control_B.Saturation = 6000.0;
        } else if (rtb_alpha_m < 0.0) {
          /* Saturate: '<S79>/Saturation' */
          Torque_Control_B.Saturation = 0.0;
        } else {
          /* Saturate: '<S79>/Saturation' */
          Torque_Control_B.Saturation = rtb_alpha_m;
        }

        /* End of Saturate: '<S79>/Saturation' */

        /* Switch: '<S79>/Switch' */
        if (rtb_alpha_m >= 900.0) {
          /* Switch: '<S79>/Switch' */
          Torque_Control_B.Switch = rtb_alpha_m;
        } else {
          /* Switch: '<S79>/Switch' incorporates:
           *  Constant: '<S79>/Constant'
           */
          Torque_Control_B.Switch = 0.0;
        }

        /* End of Switch: '<S79>/Switch' */
        /* MATLAB Function: '<S69>/Accelerator behaviour' incorporates:
         *  Inport: '<Root>/APPS1_Value'
         *  Inport: '<Root>/VDC_Apps_Sat_Down'
         *  Inport: '<Root>/VDC_Apps_Sat_Up'
         */
        if (Torque_Control_U.APPS1_Value <= Torque_Control_U.VDC_Apps_Sat_Down)
        {
          rtb_value_a = 0.0;
        } else if (Torque_Control_U.APPS1_Value >=
                   Torque_Control_U.VDC_Apps_Sat_Up) {
          rtb_value_a = 1.0;
        } else {
          rtb_value_a = (Torque_Control_U.APPS1_Value -
                         Torque_Control_U.VDC_Apps_Sat_Down) /
            (Torque_Control_U.VDC_Apps_Sat_Up -
             Torque_Control_U.VDC_Apps_Sat_Down);
        }

        /* End of MATLAB Function: '<S69>/Accelerator behaviour' */

        /* MATLAB Function: '<S69>/MATLAB Function1' incorporates:
         *  Constant: '<S69>/Steering Wheel Maximum Angle'
         *  Gain: '<S11>/Gain'
         *  Inport: '<Root>/SteeringSensor_Value'
         */
        if (-Torque_Control_U.SteeringSensor_Value > 140.0) {
          rtb_alpha_m = 140.0;
        } else if (-Torque_Control_U.SteeringSensor_Value < -140.0) {
          rtb_alpha_m = -140.0;
        } else {
          rtb_alpha_m = -Torque_Control_U.SteeringSensor_Value;
        }

        /* End of MATLAB Function: '<S69>/MATLAB Function1' */

        /* MATLAB Function: '<S69>/Steering TV 2017 (without TC)' incorporates:
         *  Constant: '<S11>/Steering Wheel Saturation (per site) [deg] '
         *  Constant: '<S69>/Steering Wheel Maximum Angle'
         *  Constant: '<S69>/Tq_diff_max [Nm]'
         *  Constant: '<S69>/Tq_max_motor [Nm]'
         */
        maxval = 0.0;
        a21 = 0.0;
        if ((rtb_alpha_m >= -10.0) && (rtb_alpha_m <= 10.0)) {
          maxval = 120.0;
          a21 = 120.0;
        } else if (rtb_alpha_m > 10.0) {
          maxval = 120.0;
          a21 = 120.0 - (rtb_alpha_m - 10.0) / 130.0 * 100.0;
        } else if (rtb_alpha_m < -10.0) {
          a21 = 120.0;
          maxval = 120.0 - (fabs(rtb_alpha_m) - 10.0) / 130.0 * 100.0;
        }

        /* End of MATLAB Function: '<S69>/Steering TV 2017 (without TC)' */

        /* If: '<S69>/If1' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if ((Torque_Control_U.BrakeSensor_Value > 0.2) && (rtb_value_a <= 0.0) &&
            (Torque_Control_B.Merge1_a == 1.0)) {
          Torque_Control_DW.If1_ActiveSubsystem_g = 0;

          /* Outputs for IfAction SubSystem: '<S69>/Regenerating' incorporates:
           *  ActionPort: '<S80>/Action Port'
           */
          /* SignalConversion generated from: '<S80>/Tq_RR_calculated' */
          rtb_Gain_f = maxval;

          /* SignalConversion generated from: '<S80>/Tq_RL_calculated' */
          maxval = a21;

          /* End of Outputs for SubSystem: '<S69>/Regenerating' */
        } else {
          Torque_Control_DW.If1_ActiveSubsystem_g = 1;

          /* Outputs for IfAction SubSystem: '<S69>/Accelerating, Inertia or Braking without Regen' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          /* SignalConversion generated from: '<S74>/Tq_RL_calculated' */
          rtb_Gain_f = a21;

          /* End of Outputs for SubSystem: '<S69>/Accelerating, Inertia or Braking without Regen' */
        }

        /* End of If: '<S69>/If1' */

        /* If: '<S69>/If' incorporates:
         *  Constant: '<S11>/Steering Wheel Saturation (per site) [deg] '
         */
        if ((rtb_alpha_m >= -10.0) && (rtb_alpha_m <= 10.0)) {
          Torque_Control_DW.If_ActiveSubsystem_b = 0;

          /* Outputs for IfAction SubSystem: '<S69>/Longitudinal Dynamics' incorporates:
           *  ActionPort: '<S77>/Action Port'
           */
          /* Product: '<S77>/Product' incorporates:
           *  Gain: '<S69>/Transmission Ratio'
           */
          rtb_alpha_m = 4.0 * maxval * Torque_Control_B.Saturation_j;

          /* Product: '<S77>/Product1' incorporates:
           *  Gain: '<S69>/Transmission Ratio1'
           */
          maxval = 4.0 * rtb_Gain_f * Torque_Control_B.Saturation_j;

          /* End of Outputs for SubSystem: '<S69>/Longitudinal Dynamics' */
        } else {
          Torque_Control_DW.If_ActiveSubsystem_b = 1;

          /* Outputs for IfAction SubSystem: '<S69>/Lateral Dynamics' incorporates:
           *  ActionPort: '<S76>/Action Port'
           */
          /* Product: '<S76>/Product' incorporates:
           *  Gain: '<S69>/Transmission Ratio'
           */
          rtb_alpha_m = 4.0 * maxval * Torque_Control_B.Saturation_n;

          /* Product: '<S76>/Product1' incorporates:
           *  Gain: '<S69>/Transmission Ratio1'
           */
          maxval = 4.0 * rtb_Gain_f * Torque_Control_B.Saturation_n;

          /* End of Outputs for SubSystem: '<S69>/Lateral Dynamics' */
        }

        /* End of If: '<S69>/If' */

        /* If: '<S73>/Braking Conditions' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if ((Torque_Control_U.BrakeSensor_Value > 0.2) && (rtb_value_a <= 0.0) &&
            (Torque_Control_B.Merge1_a == 1.0)) {
          Torque_Control_DW.BrakingConditions_ActiveSubsyst = 0;

          /* Outputs for IfAction SubSystem: '<S73>/Regenerative+Mech Braking' incorporates:
           *  ActionPort: '<S85>/Action Port'
           */
          /* MATLAB Function: '<S85>/MATLAB Function' */
          if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
            rtb_value_a = 0.0;
          } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
            rtb_value_a = 1.0;
          } else {
            rtb_value_a = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
          }

          rtb_Gain_f = rtb_value_a * rtb_alpha_m;
          rtb_value_a *= maxval;

          /* End of MATLAB Function: '<S85>/MATLAB Function' */

          /* MATLAB Function: '<S85>/MATLAB Function1' incorporates:
           *  Inport: '<Root>/VDC_Max_Regen_Motor_Tq'
           */
          rtb_alpha_m = 0.0;
          maxval = 0.0;
          if ((!(rtb_Gain_f == 0.0)) || (!(rtb_value_a == 0.0))) {
            if ((rtb_Gain_f != 0.0) && (rtb_value_a == 0.0)) {
              maxval = rtb_Gain_f;
            } else if ((rtb_Gain_f == 0.0) && (rtb_value_a != 0.0)) {
              rtb_alpha_m = rtb_value_a;
            } else if (rtb_Gain_f == rtb_value_a) {
              if (rtb_Gain_f >= Torque_Control_U.VDC_Max_Regen_Motor_Tq) {
                rtb_alpha_m = Torque_Control_U.VDC_Max_Regen_Motor_Tq;
                maxval = Torque_Control_U.VDC_Max_Regen_Motor_Tq;
              } else {
                rtb_alpha_m = rtb_Gain_f;
                maxval = rtb_value_a;
              }
            } else if (rtb_Gain_f > rtb_value_a) {
              if (rtb_Gain_f < Torque_Control_U.VDC_Max_Regen_Motor_Tq) {
                rtb_alpha_m = rtb_value_a * rtb_value_a / rtb_Gain_f;
                maxval = rtb_value_a;
              } else {
                rtb_alpha_m = Torque_Control_U.VDC_Max_Regen_Motor_Tq *
                  rtb_value_a / rtb_Gain_f;
                maxval = Torque_Control_U.VDC_Max_Regen_Motor_Tq;
              }
            } else if (rtb_Gain_f < rtb_value_a) {
              if (rtb_value_a < Torque_Control_U.VDC_Max_Regen_Motor_Tq) {
                rtb_alpha_m = rtb_Gain_f;
                maxval = rtb_Gain_f * rtb_Gain_f / rtb_value_a;
              } else {
                rtb_alpha_m = Torque_Control_U.VDC_Max_Regen_Motor_Tq;
                maxval = Torque_Control_U.VDC_Max_Regen_Motor_Tq * rtb_Gain_f /
                  rtb_value_a;
              }
            }
          }

          /* End of MATLAB Function: '<S85>/MATLAB Function1' */

          /* Merge: '<S11>/Merge Tq_RR' incorporates:
           *  Gain: '<S85>/Gain'
           */
          Torque_Control_B.MergeTq_RR = -rtb_alpha_m;

          /* Merge: '<S11>/Merge Tq_RL' incorporates:
           *  Gain: '<S85>/Gain1'
           */
          Torque_Control_B.MergeTq_RL = -maxval;

          /* End of Outputs for SubSystem: '<S73>/Regenerative+Mech Braking' */
        } else if ((Torque_Control_U.BrakeSensor_Value > 0.2) && (rtb_value_a <=
                    0.0) && (Torque_Control_B.Merge1_a == 0.0)) {
          Torque_Control_DW.BrakingConditions_ActiveSubsyst = 1;

          /* Outputs for IfAction SubSystem: '<S73>/Mech_Braking' incorporates:
           *  ActionPort: '<S84>/Action Port'
           */
          Torque_Control_Mech_Braking(&Torque_Control_B.MergeTq_RR,
            &Torque_Control_B.MergeTq_RL);

          /* End of Outputs for SubSystem: '<S73>/Mech_Braking' */
        } else if ((Torque_Control_U.BrakeSensor_Value <= 0.2) && (rtb_value_a <=
                    0.0)) {
          Torque_Control_DW.BrakingConditions_ActiveSubsyst = 2;

          /* Outputs for IfAction SubSystem: '<S73>/Inertia Braking' incorporates:
           *  ActionPort: '<S83>/Action Port'
           */
          Torque_Control_Mech_Braking(&Torque_Control_B.MergeTq_RR,
            &Torque_Control_B.MergeTq_RL);

          /* End of Outputs for SubSystem: '<S73>/Inertia Braking' */
        } else {
          Torque_Control_DW.BrakingConditions_ActiveSubsyst = 3;

          /* Outputs for IfAction SubSystem: '<S73>/Accelerating' incorporates:
           *  ActionPort: '<S82>/Action Port'
           */
          /* Merge: '<S11>/Merge Tq_RL' incorporates:
           *  Product: '<S82>/Product'
           */
          Torque_Control_B.MergeTq_RL = rtb_value_a * maxval;

          /* Merge: '<S11>/Merge Tq_RR' incorporates:
           *  Product: '<S82>/Product1'
           */
          Torque_Control_B.MergeTq_RR = rtb_value_a * rtb_alpha_m;

          /* End of Outputs for SubSystem: '<S73>/Accelerating' */
        }

        /* End of If: '<S73>/Braking Conditions' */

        /* Merge: '<S11>/Merge3' incorporates:
         *  SignalConversion generated from: '<S69>/CKF_act'
         */
        Torque_Control_B.Merge3_i = Torque_Control_B.Saturation_n;

        /* Merge: '<S11>/Merge2' incorporates:
         *  SignalConversion generated from: '<S69>/SKF_act'
         */
        Torque_Control_B.Merge2_b = Torque_Control_B.Saturation_j;

        /* End of Outputs for SubSystem: '<S11>/Steering TV with TC' */
      }
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S11>/Rigid Axle' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      /* MATLAB Function: '<S68>/Rigid Axle without TC ' incorporates:
       *  Constant: '<S11>/Max_Motor_Torque_Rear_FM4 [Nm]'
       *  Constant: '<S11>/Transmission_Gear_Ratio_MtoW'
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       *  Inport: '<Root>/VDC_Apps_Sat_Up'
       */
      if (Torque_Control_U.APPS1_Value <= Torque_Control_U.VDC_Apps_Sat_Down) {
        rtb_Gain_f = 0.0;
      } else if (Torque_Control_U.APPS1_Value >=
                 Torque_Control_U.VDC_Apps_Sat_Up) {
        rtb_Gain_f = 1.0;
      } else {
        rtb_Gain_f = (Torque_Control_U.APPS1_Value -
                      Torque_Control_U.VDC_Apps_Sat_Down) /
          (Torque_Control_U.VDC_Apps_Sat_Up - Torque_Control_U.VDC_Apps_Sat_Down);
      }

      rtb_value_a = 679.54199999999992 * rtb_Gain_f;

      /* Merge: '<S11>/Merge Tq_RL' incorporates:
       *  MATLAB Function: '<S68>/Rigid Axle without TC '
       *  SignalConversion generated from: '<S68>/Tq_RL_FM4 [Nm] (0,inf)'
       */
      Torque_Control_B.MergeTq_RL = rtb_value_a;

      /* Merge: '<S11>/Merge Tq_RR' incorporates:
       *  SignalConversion generated from: '<S68>/Tq_RR_FM4 [Nm] (0,inf)'
       */
      Torque_Control_B.MergeTq_RR = rtb_value_a;

      /* End of Outputs for SubSystem: '<S11>/Rigid Axle' */
      break;
    }

    /* End of If: '<S11>/FAILURE MODE' */
    /* End of Outputs for SubSystem: '<Root>/Vehicle Dynamics Control Modes' */
  }

  /* End of If: '<Root>/If2' */

  /* Outport: '<Root>/Torque_RRwc' */
  Torque_Control_Y.Torque_RRwc = Torque_Control_B.Merge_dw;

  /* Outport: '<Root>/Torque_RLwc' */
  Torque_Control_Y.Torque_RLwc = Torque_Control_B.Merge1_j;

  /* Outport: '<Root>/Max_Torque_RR' */
  Torque_Control_Y.Max_Torque_RR = Torque_Control_B.Divide;

  /* Outport: '<Root>/Max_Torque_RL' */
  Torque_Control_Y.Max_Torque_RL = Torque_Control_B.Divide_g;

  /* Outport: '<Root>/Max_Fx_RR' */
  Torque_Control_Y.Max_Fx_RR = Torque_Control_B.Merge2_i;

  /* Outport: '<Root>/Max_Fx_RL' */
  Torque_Control_Y.Max_Fx_RL = Torque_Control_B.Merge3_d;

  /* Outport: '<Root>/Throttle' */
  Torque_Control_Y.Throttle = Torque_Control_B.Throttle;

  /* Outport: '<Root>/Fy_R' */
  Torque_Control_Y.Fy_R = Torque_Control_B.Merge6;

  /* Outport: '<Root>/Mass' */
  Torque_Control_Y.Mass = Torque_Control_B.Merge4;

  /* Outport: '<Root>/Handling' */
  Torque_Control_Y.Handling = Torque_Control_B.Merge5;

  /* Outport: '<Root>/SKF_actual' */
  Torque_Control_Y.SKF_actual = Torque_Control_B.Merge2_b;

  /* Outport: '<Root>/CKF_actual' */
  Torque_Control_Y.CKF_actual = Torque_Control_B.Merge3_i;

  /* Outport: '<Root>/APPS_Implausibility' */
  Torque_Control_Y.APPS_Implausibility = rtb_Merge1_h;

  /* Outport: '<Root>/TV_Flag_WheelSpinRR' */
  Torque_Control_Y.TV_Flag_WheelSpinRR =
    Torque_Control_B.OutportBufferForFlags_num5[1];

  /* Outport: '<Root>/TV_Flag_WheelSpinRL' */
  Torque_Control_Y.TV_Flag_WheelSpinRL =
    Torque_Control_B.OutportBufferForFlags_num5[2];

  /* Outport: '<Root>/TV_Flag_Power' */
  Torque_Control_Y.TV_Flag_Power = Torque_Control_B.OutportBufferForFlags_num5[3];

  /* Outport: '<Root>/TV_Flag_CarBehaviour' */
  Torque_Control_Y.TV_Flag_CarBehaviour =
    Torque_Control_B.OutportBufferForFlags_num5[0];

  /* Outport: '<Root>/Torque_OK' */
  Torque_Control_Y.Torque_OK = LogicalOperator;

  /* Gain: '<Root>/Gain1' */
  Torque_Control_B.Gain1 = 0.25 * Torque_Control_B.MergeTq_RL;

  /* Gain: '<Root>/Gain' */
  Torque_Control_B.Gain = 0.25 * Torque_Control_B.MergeTq_RR;

  /* MATLAB Function: '<Root>/BrakePedal_Pressed' incorporates:
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/BrakeSensor_Value'
   *  Inport: '<Root>/VDC_Apps_Sat_Down'
   */
  Torque_Control_B.Braking = ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
    (Torque_Control_U.APPS1_Value < Torque_Control_U.VDC_Apps_Sat_Down));

  /* If: '<Root>/If' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant1'
   *  Constant: '<S26>/Constant2'
   *  Constant: '<S26>/Constant3'
   *  Constant: '<S27>/Constant1'
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S27>/Constant3'
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S28>/Constant2'
   *  Constant: '<S28>/Constant3'
   *  Constant: '<S30>/Constant'
   *  Constant: '<S31>/Time constant'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Time constant'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S47>/Time constant'
   *  Constant: '<S50>/Constant'
   *  Constant: '<S6>/Max_Tq_per_motor'
   *  Constant: '<S6>/initial_limitation'
   *  DiscreteIntegrator: '<S36>/Integrator'
   *  DiscreteIntegrator: '<S44>/Integrator'
   *  DiscreteIntegrator: '<S52>/Integrator'
   *  Inport: '<Root>/Highest_CellTemp'
   *  Inport: '<Root>/Temp_IGBT'
   *  Inport: '<Root>/Temp_Motors'
   *  MATLAB Function: '<S6>/Torque Limitation Temperature Controller'
   *  Merge: '<Root>/Merge'
   *  MinMax: '<S31>/Max'
   *  MinMax: '<S39>/Max'
   *  MinMax: '<S47>/Max'
   *  Product: '<S26>/Divide'
   *  Product: '<S26>/Product4'
   *  Product: '<S27>/Divide'
   *  Product: '<S27>/Product4'
   *  Product: '<S28>/Divide'
   *  Product: '<S28>/Product4'
   *  Product: '<S29>/1//T'
   *  Product: '<S37>/1//T'
   *  Product: '<S45>/1//T'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S25>/Compare'
   *  RelationalOperator: '<S30>/Compare'
   *  RelationalOperator: '<S34>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   *  RelationalOperator: '<S42>/Compare'
   *  RelationalOperator: '<S46>/Compare'
   *  RelationalOperator: '<S50>/Compare'
   *  Saturate: '<S26>/Saturation1'
   *  Saturate: '<S27>/Saturation1'
   *  Saturate: '<S28>/Saturation1'
   *  SignalConversion generated from: '<S6>/Tq_R'
   *  Sum: '<S26>/Add1'
   *  Sum: '<S26>/Add2'
   *  Sum: '<S26>/Add3'
   *  Sum: '<S27>/Add1'
   *  Sum: '<S27>/Add2'
   *  Sum: '<S27>/Add3'
   *  Sum: '<S28>/Add1'
   *  Sum: '<S28>/Add2'
   *  Sum: '<S28>/Add3'
   *  Sum: '<S29>/Sum1'
   *  Sum: '<S31>/Sum1'
   *  Sum: '<S37>/Sum1'
   *  Sum: '<S39>/Sum1'
   *  Sum: '<S45>/Sum1'
   *  Sum: '<S47>/Sum1'
   */
  Torque_Control_DW.If_ActiveSubsystem_e = 1;

  /* Outputs for IfAction SubSystem: '<Root>/Power Limitation Temperature' incorporates:
   *  ActionPort: '<S6>/Action Port'
   */
  Torque_Control_B.Compare = (100.0 - Torque_Control_B.Probe[0] <= 0.0);
  rtb_Compare_m = (Torque_Control_U.Highest_CellTemp >= 50.0);
  rtb_Merge1_h = ((45.0 / (Torque_Control_U.Highest_CellTemp - 5.0) - 0.4) *
                  (real_T)rtb_Compare_m - (real_T)rtb_Compare_m) + 1.0;
  if (Torque_Control_DW.Integrator_IC_LOADING != 0) {
    Torque_Control_DW.Integrator_DSTATE = rtb_Merge1_h;
  }

  if (Torque_Control_B.Compare || (Torque_Control_DW.Integrator_PrevResetState
       != 0)) {
    Torque_Control_DW.Integrator_DSTATE = rtb_Merge1_h;
  }

  rtb_Integrator = Torque_Control_DW.Integrator_DSTATE;
  if (rtb_Integrator > 1.0) {
    rtb_alpha_m = 1.0;
  } else if (rtb_Integrator < 0.0) {
    rtb_alpha_m = 0.0;
  } else {
    rtb_alpha_m = rtb_Integrator;
  }

  Torque_Control_B.Compare_n = (100.0 - Torque_Control_B.Probe_o[0] <= 0.0);
  rtb_Compare_m = (Torque_Control_U.Temp_IGBT >= 50.0);
  rtb_Gain_f = ((45.0 / (Torque_Control_U.Temp_IGBT - 5.0) - 0.4) * (real_T)
                rtb_Compare_m - (real_T)rtb_Compare_m) + 1.0;
  if (Torque_Control_DW.Integrator_IC_LOADING_k != 0) {
    Torque_Control_DW.Integrator_DSTATE_b = rtb_Gain_f;
  }

  if (Torque_Control_B.Compare_n ||
      (Torque_Control_DW.Integrator_PrevResetState_f != 0)) {
    Torque_Control_DW.Integrator_DSTATE_b = rtb_Gain_f;
  }

  rtb_Integrator_d = Torque_Control_DW.Integrator_DSTATE_b;
  if (rtb_Integrator_d > 1.0) {
    maxval = 1.0;
  } else if (rtb_Integrator_d < 0.0) {
    maxval = 0.0;
  } else {
    maxval = rtb_Integrator_d;
  }

  Torque_Control_B.Compare_e = (100.0 - Torque_Control_B.Probe_n[0] <= 0.0);
  rtb_Compare_m = (Torque_Control_U.Temp_Motors >= 110.0);
  rtb_value_a = ((105.0 / (Torque_Control_U.Temp_Motors - 5.0) - 0.4) * (real_T)
                 rtb_Compare_m - (real_T)rtb_Compare_m) + 1.0;
  if (Torque_Control_DW.Integrator_IC_LOADING_e != 0) {
    Torque_Control_DW.Integrator_DSTATE_j = rtb_value_a;
  }

  if (Torque_Control_B.Compare_e ||
      (Torque_Control_DW.Integrator_PrevResetState_j != 0)) {
    Torque_Control_DW.Integrator_DSTATE_j = rtb_value_a;
  }

  rtb_Integrator_j = Torque_Control_DW.Integrator_DSTATE_j;
  if (rtb_Integrator_j > 1.0) {
    a21 = 1.0;
  } else if (rtb_Integrator_j < 0.0) {
    a21 = 0.0;
  } else {
    a21 = rtb_Integrator_j;
  }

  if (Torque_Control_B.Braking == 1.0) {
    /* Product: '<S20>/Product5' incorporates:
     *  Gain: '<S20>/Gain5'
     *  Inport: '<Root>/SoC_High'
     *  Lookup_n-D: '<S20>/Lookup_SoC_SoP_chg'
     *  Lookup_n-D: '<S20>/Lookup_Temp_SoP_chg'
     *  MinMax: '<S22>/Min'
     *  Product: '<S20>/Product'
     */
    X_idx_1 = look1_binlxpw(0.01 * Torque_Control_U.SoC_High,
      rtCP_Lookup_SoC_SoP_chg_bp01Dat, rtCP_Lookup_SoC_SoP_chg_tableDa, 7U) *
      look1_binlxpw(Torque_Control_U.Highest_CellTemp,
                    rtCP_Lookup_Temp_SoP_chg_bp01Da,
                    rtCP_Lookup_Temp_SoP_chg_tableD, 4U) * fmin(fmin(rtb_alpha_m,
      maxval), a21);

    /* Saturate: '<S6>/Saturation1' */
    if (X_idx_1 > 1.0) {
      X_idx_1 = -1.0;
    } else if (X_idx_1 < 0.0) {
      X_idx_1 = -0.0;
    } else {
      X_idx_1 = -X_idx_1;
    }

    /* End of Saturate: '<S6>/Saturation1' */
  } else {
    /* Product: '<S20>/Product4' incorporates:
     *  Gain: '<S20>/Gain6'
     *  Inport: '<Root>/SoC_Low'
     *  Lookup_n-D: '<S20>/Lookup_SoC_SoP_dischg'
     *  MinMax: '<S22>/Min'
     */
    X_idx_1 = look1_binlxpw(0.01 * Torque_Control_U.SoC_Low,
      rtCP_Lookup_SoC_SoP_dischg_bp01, rtCP_Lookup_SoC_SoP_dischg_tabl, 7U) *
      fmin(fmin(rtb_alpha_m, maxval), a21);

    /* Saturate: '<S6>/Saturation' */
    if (X_idx_1 > 1.0) {
      X_idx_1 = 1.0;
    } else if (X_idx_1 < 0.0) {
      X_idx_1 = 0.0;
    }

    /* End of Saturate: '<S6>/Saturation' */
  }

  mz = X_idx_1 * 2.0 * 120.0;
  p = Torque_Control_B.Gain1 + Torque_Control_B.Gain;
  if (p > mz) {
    Mz = Torque_Control_B.Gain1 / p * mz;

    /* Merge: '<Root>/Merge3' */
    Torque_Control_B.Merge3 = mz - Mz;
  } else {
    Mz = Torque_Control_B.Gain1;

    /* Merge: '<Root>/Merge3' */
    Torque_Control_B.Merge3 = Torque_Control_B.Gain;
  }

  Torque_Control_B.Merge = Mz;
  Torque_Control_B.Compare_f = (rtb_alpha_m < 1.0);
  Torque_Control_B.Compare_d = (maxval < 1.0);
  Torque_Control_B.Compare_g = (a21 < 1.0);
  Torque_Control_B.uT = 1.0 / fmax(Torque_Control_B.Probe[0], 100.0) *
    (rtb_Merge1_h - rtb_Integrator);
  Torque_Control_B.uT_i = 1.0 / fmax(Torque_Control_B.Probe_o[0], 100.0) *
    (rtb_Gain_f - rtb_Integrator_d);
  Torque_Control_B.uT_m = 1.0 / fmax(Torque_Control_B.Probe_n[0], 100.0) *
    (rtb_value_a - rtb_Integrator_j);

  /* End of If: '<Root>/If' */
  /* End of Outputs for SubSystem: '<Root>/Power Limitation Temperature' */

  /* Outport: '<Root>/Meas VDC Torque_L' */
  Torque_Control_Y.MeasVDCTorque_L = Torque_Control_B.Merge3;

  /* Outport: '<Root>/Meas VDC Torque_R' */
  Torque_Control_Y.MeasVDCTorque_R = Torque_Control_B.Merge;

  /* Outport: '<Root>/Torque_L' */
  Torque_Control_Y.Torque_L = Torque_Control_B.MergeTq_RR;

  /* Outport: '<Root>/Torque_R' */
  Torque_Control_Y.Torque_R = Torque_Control_B.MergeTq_RL;

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Max_Power_charge [kW]'
   *  Constant: '<S7>/Max_Power_discharge [kW]'
   */
  if (Torque_Control_B.Braking == 1.0) {
    rtb_Merge1_h = -60000.0;
  } else {
    rtb_Merge1_h = 80000.0;
  }

  if (Torque_Control_B.Merge * rtb_Abs2 + Torque_Control_B.Merge3 *
      Torque_Control_B.Abs3 > rtb_Merge1_h) {
    rtb_Gain_f = Torque_Control_B.Merge / (Torque_Control_B.Merge +
      Torque_Control_B.Merge3);
    rtb_Gain_f = rtb_Gain_f * rtb_Merge1_h / ((rtb_Abs2 - Torque_Control_B.Abs3)
      * rtb_Gain_f + Torque_Control_B.Abs3);
    rtb_Merge1_h = (rtb_Merge1_h - rtb_Gain_f * rtb_Abs2) /
      Torque_Control_B.Abs3;
  } else {
    rtb_Gain_f = Torque_Control_B.Merge;
    rtb_Merge1_h = Torque_Control_B.Merge3;
  }

  /* If: '<Root>/If1' */
  if (LogicalOperator) {
    Torque_Control_DW.If1_ActiveSubsystem_a = 0;

    /* Outputs for IfAction SubSystem: '<Root>/Calculate Current Conversion' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S3>/KT_R_EMY' */
    /* Merge: '<Root>/Merge2' incorporates:
     *  Gain: '<S19>/A//Nm'
     *  MATLAB Function: '<S7>/MATLAB Function'
     */
    Torque_Control_B.Merge2_e = 0.2 * rtb_Gain_f;

    /* End of Outputs for SubSystem: '<S3>/KT_R_EMY' */

    /* Outputs for Atomic SubSystem: '<S3>/KT_L_TORKY' */
    /* Merge: '<Root>/Merge1' incorporates:
     *  Gain: '<S18>/A//Nm'
     *  Gain: '<S3>/Gain'
     */
    Torque_Control_B.Merge1_a0 = -(0.2 * rtb_Merge1_h);

    /* End of Outputs for SubSystem: '<S3>/KT_L_TORKY' */
    /* End of Outputs for SubSystem: '<Root>/Calculate Current Conversion' */
  } else {
    Torque_Control_DW.If1_ActiveSubsystem_a = 1;

    /* Outputs for IfAction SubSystem: '<Root>/Current 0' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<Root>/Merge1' incorporates:
     *  Constant: '<S4>/Constant'
     *  SignalConversion generated from: '<S4>/Current L'
     */
    Torque_Control_B.Merge1_a0 = 0.0;

    /* Merge: '<Root>/Merge2' incorporates:
     *  Constant: '<S4>/Constant'
     *  SignalConversion generated from: '<S4>/Current R'
     */
    Torque_Control_B.Merge2_e = 0.0;

    /* End of Outputs for SubSystem: '<Root>/Current 0' */
  }

  /* End of If: '<Root>/If1' */

  /* Outport: '<Root>/current_L' */
  Torque_Control_Y.current_L = Torque_Control_B.Merge1_a0;

  /* Outport: '<Root>/current_R' */
  Torque_Control_Y.current_R = Torque_Control_B.Merge2_e;

  /* Outport: '<Root>/TV_Flag_Temperature' incorporates:
   *  Logic: '<Root>/AND'
   */
  Torque_Control_Y.TV_Flag_Temperature = (Torque_Control_B.Compare_f &&
    Torque_Control_B.Compare_d && Torque_Control_B.Compare_g);

  /* Outport: '<Root>/Regenerative_Enable' */
  Torque_Control_Y.Regenerative_Enable = Torque_Control_B.Merge1_a;

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/Accumulator_Current'
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  rtb_Merge1_h = Torque_Control_U.Accumulator_Voltage *
    Torque_Control_U.Accumulator_Current;

  /* Outport: '<Root>/Power' incorporates:
   *  Constant: '<S13>/0-100 to 0-2'
   *  Product: '<S13>/Divide5'
   */
  Torque_Control_Y.Power = rtb_Merge1_h / 1000.0;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* If: '<S12>/If' incorporates:
   *  DataStoreRead: '<S12>/Data Store Read30'
   *  If: '<S15>/If'
   *  SignalConversion generated from: '<S12>/Power'
   */
  if (rtb_Merge1_h >= 80000.0) {
    /* Outputs for IfAction SubSystem: '<S12>/LimitReached' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    Torque_Control_LimitReached(&rtb_Merge1_p);

    /* End of Outputs for SubSystem: '<S12>/LimitReached' */

    /* Outputs for IfAction SubSystem: '<S12>/OK_OrLatch' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
  } else if (Torque_Control_DW.A_i > 0.0) {
    /* Outputs for IfAction SubSystem: '<S15>/Latched Error' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* If: '<S15>/If' */
    Torque_Control_LimitReached(&rtb_Merge1_p);

    /* End of Outputs for SubSystem: '<S15>/Latched Error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S15>/OK' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* If: '<S15>/If' incorporates:
     *  Constant: '<S17>/Constant'
     *  Merge: '<S12>/Merge1'
     *  SignalConversion generated from: '<S17>/Out '
     */
    rtb_Merge1_p = 0.0;

    /* End of Outputs for SubSystem: '<S15>/OK' */

    /* End of Outputs for SubSystem: '<S12>/OK_OrLatch' */
  }

  /* End of If: '<S12>/If' */

  /* DataStoreWrite: '<S12>/Data Store Write20' */
  Torque_Control_DW.A_i = rtb_Merge1_p;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* Outport: '<Root>/PowerLimitReached' */
  Torque_Control_Y.PowerLimitReached = rtb_Merge1_p;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Outport: '<Root>/PowerMean500ms' incorporates:
   *  SignalConversion generated from: '<S12>/Power'
   */
  Torque_Control_Y.PowerMean500ms = rtb_Merge1_h;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */
}

/* Model update function */
static void Torque_Control_update(void)
{
  real_T *lastU;

  /* Update for If: '<Root>/If2' */
  if (Torque_Control_DW.If2_ActiveSubsystem == 0) {
    /* Update for IfAction SubSystem: '<Root>/Vehicle Dynamics Control Modes' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Update for If: '<S11>/FAILURE MODE' */
    switch (Torque_Control_DW.FAILUREMODE_ActiveSubsystem) {
     case 0:
      /* Update for IfAction SubSystem: '<S11>/VDC Complete' incorporates:
       *  ActionPort: '<S70>/Action Port'
       */
      /* Update for Derivative: '<S108>/Derivative' */
      if (Torque_Control_DW.TimeStampA_d == (rtInf)) {
        Torque_Control_DW.TimeStampA_d = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA_n;
      } else if (Torque_Control_DW.TimeStampB_c == (rtInf)) {
        Torque_Control_DW.TimeStampB_c = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB_b;
      } else if (Torque_Control_DW.TimeStampA_d < Torque_Control_DW.TimeStampB_c)
      {
        Torque_Control_DW.TimeStampA_d = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA_n;
      } else {
        Torque_Control_DW.TimeStampB_c = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB_b;
      }

      *lastU = Torque_Control_B.sf_MATLABFunction_h.w;

      /* End of Update for Derivative: '<S108>/Derivative' */
      /* End of Update for SubSystem: '<S11>/VDC Complete' */
      break;

     case 1:
      /* Update for IfAction SubSystem: '<S11>/VDC without Longitudinal' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      /* Update for Derivative: '<S165>/Derivative' */
      if (Torque_Control_DW.TimeStampA_p == (rtInf)) {
        Torque_Control_DW.TimeStampA_p = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA_o;
      } else if (Torque_Control_DW.TimeStampB_n == (rtInf)) {
        Torque_Control_DW.TimeStampB_n = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB_m;
      } else if (Torque_Control_DW.TimeStampA_p < Torque_Control_DW.TimeStampB_n)
      {
        Torque_Control_DW.TimeStampA_p = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA_o;
      } else {
        Torque_Control_DW.TimeStampB_n = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB_m;
      }

      *lastU = Torque_Control_B.sf_MATLABFunction_hu.w;

      /* End of Update for Derivative: '<S165>/Derivative' */
      /* End of Update for SubSystem: '<S11>/VDC without Longitudinal' */
      break;

     case 2:
      /* Update for IfAction SubSystem: '<S11>/Steering TV with TC' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      /* Update for Derivative: '<S79>/Derivative' */
      if (Torque_Control_DW.TimeStampA == (rtInf)) {
        Torque_Control_DW.TimeStampA = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA;
      } else if (Torque_Control_DW.TimeStampB == (rtInf)) {
        Torque_Control_DW.TimeStampB = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB;
      } else if (Torque_Control_DW.TimeStampA < Torque_Control_DW.TimeStampB) {
        Torque_Control_DW.TimeStampA = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA;
      } else {
        Torque_Control_DW.TimeStampB = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB;
      }

      *lastU = Torque_Control_B.wrads;

      /* End of Update for Derivative: '<S79>/Derivative' */
      /* End of Update for SubSystem: '<S11>/Steering TV with TC' */
      break;

     case 3:
      break;
    }

    /* End of Update for If: '<S11>/FAILURE MODE' */
    /* End of Update for SubSystem: '<Root>/Vehicle Dynamics Control Modes' */
  }

  /* End of Update for If: '<Root>/If2' */

  /* Update for If: '<Root>/If' */
  if (Torque_Control_DW.If_ActiveSubsystem_e == 1) {
    /* Update for IfAction SubSystem: '<Root>/Power Limitation Temperature' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S36>/Integrator' */
    Torque_Control_DW.Integrator_IC_LOADING = 0U;
    Torque_Control_DW.Integrator_DSTATE += 0.2 * Torque_Control_B.uT;
    Torque_Control_DW.Integrator_PrevResetState = (int8_T)
      Torque_Control_B.Compare;

    /* Update for DiscreteIntegrator: '<S44>/Integrator' */
    Torque_Control_DW.Integrator_IC_LOADING_k = 0U;
    Torque_Control_DW.Integrator_DSTATE_b += 0.2 * Torque_Control_B.uT_i;
    Torque_Control_DW.Integrator_PrevResetState_f = (int8_T)
      Torque_Control_B.Compare_n;

    /* Update for DiscreteIntegrator: '<S52>/Integrator' */
    Torque_Control_DW.Integrator_IC_LOADING_e = 0U;
    Torque_Control_DW.Integrator_DSTATE_j += 0.2 * Torque_Control_B.uT_m;
    Torque_Control_DW.Integrator_PrevResetState_j = (int8_T)
      Torque_Control_B.Compare_e;

    /* End of Update for SubSystem: '<Root>/Power Limitation Temperature' */
  }

  /* End of Update for If: '<Root>/If' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Torque_Control_M->Timing.clockTick0)) {
    ++Torque_Control_M->Timing.clockTickH0;
  }

  Torque_Control_M->Timing.t[0] = Torque_Control_M->Timing.clockTick0 *
    Torque_Control_M->Timing.stepSize0 + Torque_Control_M->Timing.clockTickH0 *
    Torque_Control_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Torque_Control_M->Timing.clockTick1)) {
      ++Torque_Control_M->Timing.clockTickH1;
    }

    Torque_Control_M->Timing.t[1] = Torque_Control_M->Timing.clockTick1 *
      Torque_Control_M->Timing.stepSize1 + Torque_Control_M->Timing.clockTickH1 *
      Torque_Control_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void Torque_Control_initialize(void)
{
  /* Start for If: '<S56>/If' */
  Torque_Control_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S56>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem = -1;

  /* Start for DataStoreMemory: '<S56>/Data Store Memory1' */
  Torque_Control_DW.ERROR_Counter = 0.0;

  /* Start for Atomic SubSystem: '<Root>/TEST_MODE_IN' */
  /* Start for If: '<S10>/If' */
  Torque_Control_DW.If_ActiveSubsystem_m = -1;

  /* End of Start for SubSystem: '<Root>/TEST_MODE_IN' */

  /* Start for Atomic SubSystem: '<Root>/Regeneration_Enable' */
  /* Start for If: '<S8>/If' */
  Torque_Control_DW.If_ActiveSubsystem_o = -1;

  /* End of Start for SubSystem: '<Root>/Regeneration_Enable' */

  /* Start for If: '<Root>/If2' */
  Torque_Control_DW.If2_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<Root>/Vehicle Dynamics Control Modes' */
  /* Start for If: '<S11>/FAILURE MODE' */
  Torque_Control_DW.FAILUREMODE_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S11>/VDC Complete' */
  /* Start for If: '<S143>/SKF or CKF' */
  Torque_Control_DW.SKForCKF_ActiveSubsystem_e = -1;

  /* Start for IfAction SubSystem: '<S143>/SKF' */
  /* Start for If: '<S146>/If' */
  Torque_Control_DW.If_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S143>/SKF' */

  /* Start for IfAction SubSystem: '<S143>/CKF' */
  /* Start for If: '<S144>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_pl = -1;

  /* End of Start for SubSystem: '<S143>/CKF' */

  /* Start for DataStoreMemory: '<S108>/Data Store Memory' */
  Torque_Control_DW.A_k = 0.0;

  /* Start for DataStoreMemory: '<S108>/Data Store Memory1' */
  Torque_Control_DW.B_p = 0.0;

  /* Start for If: '<S70>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
  Torque_Control_DW.Steer_angisinSteer_SatrangeLong = -1;

  /* Start for If: '<S101>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubs_f3 = -1;

  /* Start for If: '<S100>/If' */
  Torque_Control_DW.If_ActiveSubsystem_c = -1;

  /* Start for IfAction SubSystem: '<S100>/Acelerating and braking without Regenerative' */
  /* Start for If: '<S111>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S100>/Acelerating and braking without Regenerative' */
  /* End of Start for SubSystem: '<S11>/VDC Complete' */

  /* Start for IfAction SubSystem: '<S11>/VDC without Longitudinal' */
  /* Start for If: '<S191>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_p = -1;

  /* Start for DataStoreMemory: '<S165>/Data Store Memory1' */
  Torque_Control_DW.B_c = 0.0;

  /* Start for If: '<S160>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubsy_f = -1;

  /* Start for If: '<S159>/If' */
  Torque_Control_DW.If_ActiveSubsystem_l = -1;

  /* Start for IfAction SubSystem: '<S159>/Acelerating and braking without Regenerative' */
  /* Start for If: '<S167>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_oe = -1;

  /* End of Start for SubSystem: '<S159>/Acelerating and braking without Regenerative' */
  /* End of Start for SubSystem: '<S11>/VDC without Longitudinal' */

  /* Start for IfAction SubSystem: '<S11>/Steering TV with TC' */
  /* Start for If: '<S88>/SKF or CKF' */
  Torque_Control_DW.SKForCKF_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S88>/SKF' */
  /* Start for If: '<S91>/If' */
  Torque_Control_DW.If_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S88>/SKF' */

  /* Start for IfAction SubSystem: '<S88>/CKF' */
  /* Start for If: '<S89>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_o = -1;

  /* End of Start for SubSystem: '<S88>/CKF' */

  /* Start for DataStoreMemory: '<S79>/Data Store Memory' */
  Torque_Control_DW.A = 0.0;

  /* Start for DataStoreMemory: '<S79>/Data Store Memory1' */
  Torque_Control_DW.B = 0.0;

  /* Start for If: '<S69>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_g = -1;

  /* Start for If: '<S69>/If' */
  Torque_Control_DW.If_ActiveSubsystem_b = -1;

  /* Start for If: '<S73>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubsyst = -1;

  /* End of Start for SubSystem: '<S11>/Steering TV with TC' */
  /* End of Start for SubSystem: '<Root>/Vehicle Dynamics Control Modes' */

  /* Start for If: '<Root>/If' */
  Torque_Control_DW.If_ActiveSubsystem_e = -1;

  /* Start for IfAction SubSystem: '<Root>/Power Limitation Temperature' */
  /* Start for Probe: '<S31>/Probe' */
  Torque_Control_B.Probe[0] = 0.2;
  Torque_Control_B.Probe[1] = 0.0;

  /* Start for Probe: '<S39>/Probe' */
  Torque_Control_B.Probe_o[0] = 0.2;
  Torque_Control_B.Probe_o[1] = 0.0;

  /* Start for Probe: '<S47>/Probe' */
  Torque_Control_B.Probe_n[0] = 0.2;
  Torque_Control_B.Probe_n[1] = 0.0;

  /* End of Start for SubSystem: '<Root>/Power Limitation Temperature' */

  /* Start for If: '<Root>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_a = -1;

  /* Start for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Start for DataStoreMemory: '<S12>/Data Store Memory10' */
  Torque_Control_DW.A_i = 0.0;

  /* End of Start for SubSystem: '<S1>/PowerLimitDetection' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/Vehicle Dynamics Control Modes' */
  /* SystemInitialize for IfAction SubSystem: '<S11>/VDC Complete' */
  /* InitializeConditions for Derivative: '<S108>/Derivative' */
  Torque_Control_DW.TimeStampA_d = (rtInf);
  Torque_Control_DW.TimeStampB_c = (rtInf);

  /* SystemInitialize for IfAction SubSystem: '<S143>/SKF' */
  /* SystemInitialize for Merge: '<S146>/Merge' */
  Torque_Control_B.Merge_agp = 0.0;

  /* SystemInitialize for Saturate: '<S146>/Saturation' incorporates:
   *  Outport: '<S146>/SKF_act'
   */
  Torque_Control_B.Saturation_hh = 0.0;

  /* End of SystemInitialize for SubSystem: '<S143>/SKF' */

  /* SystemInitialize for IfAction SubSystem: '<S143>/CKF' */
  /* SystemInitialize for Merge: '<S144>/Merge' */
  Torque_Control_B.Merge_az = 0.0;

  /* SystemInitialize for Saturate: '<S144>/Saturation' incorporates:
   *  Outport: '<S144>/CKF_act '
   */
  Torque_Control_B.Saturation_h = 0.0;

  /* End of SystemInitialize for SubSystem: '<S143>/CKF' */

  /* SystemInitialize for Merge: '<S70>/Merge2' */
  Torque_Control_B.Merge2_i = 0.0;

  /* SystemInitialize for Merge: '<S70>/Merge3' */
  Torque_Control_B.Merge3_d = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S101>/Accelerating' */
  /* SystemInitialize for SignalConversion generated from: '<S121>/Throttle' incorporates:
   *  Outport: '<S121>/Out_Throttle'
   */
  Torque_Control_B.Throttle = 0.0;

  /* End of SystemInitialize for SubSystem: '<S101>/Accelerating' */

  /* SystemInitialize for Merge: '<S101>/Merge' */
  Torque_Control_B.Merge_dw = 0.0;

  /* SystemInitialize for Merge: '<S101>/Merge1' */
  Torque_Control_B.Merge1_j = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S100>/Acelerating and braking without Regenerative' */
  /* SystemInitialize for SignalConversion generated from: '<S111>/Flag_Power' */
  Torque_Control_B.OutportBufferForFlag_Power = Torque_Control_ConstB.Constant;

  /* End of SystemInitialize for SubSystem: '<S100>/Acelerating and braking without Regenerative' */

  /* SystemInitialize for Merge: '<S70>/Merge4' */
  Torque_Control_B.Merge4 = 0.0;

  /* SystemInitialize for Merge: '<S70>/Merge5' */
  Torque_Control_B.Merge5 = 0.0;

  /* SystemInitialize for Merge: '<S70>/Merge6' */
  Torque_Control_B.Merge6 = 0.0;

  /* SystemInitialize for Merge: '<S70>/Merge7' */
  Torque_Control_B.Merge7 = 0.0;

  /* SystemInitialize for Product: '<S156>/Divide' incorporates:
   *  Outport: '<S70>/MaxTq_RR [Nm] (0,inf)'
   */
  Torque_Control_B.Divide = 0.0;

  /* SystemInitialize for Product: '<S155>/Divide' incorporates:
   *  Outport: '<S70>/MaxTq_RL [Nm] (0,inf)'
   */
  Torque_Control_B.Divide_g = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S70>/Flags_[num5]' incorporates:
   *  Outport: '<S70>/Flags_[num5]'
   */
  Torque_Control_B.OutportBufferForFlags_num5[0] = 0.0;
  Torque_Control_B.OutportBufferForFlags_num5[1] = 0.0;
  Torque_Control_B.OutportBufferForFlags_num5[2] = 0.0;
  Torque_Control_B.OutportBufferForFlags_num5[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S11>/VDC Complete' */

  /* SystemInitialize for IfAction SubSystem: '<S11>/VDC without Longitudinal' */
  /* InitializeConditions for Derivative: '<S165>/Derivative' */
  Torque_Control_DW.TimeStampA_p = (rtInf);
  Torque_Control_DW.TimeStampB_n = (rtInf);

  /* SystemInitialize for Merge: '<S191>/Merge' */
  Torque_Control_B.Merge_n = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S160>/Accelerating' */
  /* SystemInitialize for Outport: '<S176>/Out_Throttle' */
  Torque_Control_B.sf_Acceleratorbehaviour_i.throttle = 0.0;

  /* End of SystemInitialize for SubSystem: '<S160>/Accelerating' */

  /* SystemInitialize for Merge: '<S160>/Merge' */
  Torque_Control_B.Merge_ag = 0.0;

  /* SystemInitialize for Merge: '<S160>/Merge1' */
  Torque_Control_B.Merge1_c = 0.0;

  /* SystemInitialize for Outport: '<S71>/MaxFx_RR [N] (0,inf)' */
  Torque_Control_B.sf_MATLABFunction2_a.value = 0.0;

  /* SystemInitialize for Outport: '<S71>/MaxFx_RL [N] (0,inf)' */
  Torque_Control_B.sf_MATLABFunction1_a.value = 0.0;

  /* End of SystemInitialize for SubSystem: '<S11>/VDC without Longitudinal' */

  /* SystemInitialize for IfAction SubSystem: '<S11>/Steering TV with TC' */
  /* InitializeConditions for Derivative: '<S79>/Derivative' */
  Torque_Control_DW.TimeStampA = (rtInf);
  Torque_Control_DW.TimeStampB = (rtInf);

  /* SystemInitialize for IfAction SubSystem: '<S88>/SKF' */
  /* SystemInitialize for Merge: '<S91>/Merge' */
  Torque_Control_B.Merge_d = 0.0;

  /* SystemInitialize for Saturate: '<S91>/Saturation' incorporates:
   *  Outport: '<S91>/SKF_act'
   */
  Torque_Control_B.Saturation_j = 0.0;

  /* End of SystemInitialize for SubSystem: '<S88>/SKF' */

  /* SystemInitialize for IfAction SubSystem: '<S88>/CKF' */
  /* SystemInitialize for Merge: '<S89>/Merge' */
  Torque_Control_B.Merge_j = 0.0;

  /* SystemInitialize for Saturate: '<S89>/Saturation' incorporates:
   *  Outport: '<S89>/CKF_act '
   */
  Torque_Control_B.Saturation_n = 0.0;

  /* End of SystemInitialize for SubSystem: '<S88>/CKF' */
  /* End of SystemInitialize for SubSystem: '<S11>/Steering TV with TC' */

  /* SystemInitialize for Merge: '<S11>/Merge Tq_RL' */
  Torque_Control_B.MergeTq_RL = 0.0;

  /* SystemInitialize for Merge: '<S11>/Merge Tq_RR' */
  Torque_Control_B.MergeTq_RR = 0.0;

  /* SystemInitialize for Merge: '<S11>/Merge2' */
  Torque_Control_B.Merge2_b = 0.0;

  /* SystemInitialize for Merge: '<S11>/Merge3' */
  Torque_Control_B.Merge3_i = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Vehicle Dynamics Control Modes' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/Power Limitation Temperature' */
  /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState = 0;
  Torque_Control_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState_f = 0;
  Torque_Control_DW.Integrator_IC_LOADING_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState_j = 0;
  Torque_Control_DW.Integrator_IC_LOADING_e = 1U;

  /* SystemInitialize for RelationalOperator: '<S23>/Compare' incorporates:
   *  Outport: '<S6>/Accu_Temperature_Limitation_Flag'
   */
  Torque_Control_B.Compare_f = false;

  /* SystemInitialize for RelationalOperator: '<S24>/Compare' incorporates:
   *  Outport: '<S6>/Inverters_Temperature_Limitation_Flag'
   */
  Torque_Control_B.Compare_d = false;

  /* SystemInitialize for RelationalOperator: '<S25>/Compare' incorporates:
   *  Outport: '<S6>/Motors_Temperature_Limitation_Flag'
   */
  Torque_Control_B.Compare_g = false;

  /* End of SystemInitialize for SubSystem: '<Root>/Power Limitation Temperature' */
}

/* Model terminate function */
static void Torque_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Torque_Control_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Torque_Control_update();
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
  Torque_Control_initialize();
}

void MdlTerminate(void)
{
  Torque_Control_terminate();
}

/* Registration function */
RT_MODEL_Torque_Control_T *Torque_Control(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Torque_Control_M, 0,
                sizeof(RT_MODEL_Torque_Control_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Torque_Control_M->solverInfo,
                          &Torque_Control_M->Timing.simTimeStep);
    rtsiSetTPtr(&Torque_Control_M->solverInfo, &rtmGetTPtr(Torque_Control_M));
    rtsiSetStepSizePtr(&Torque_Control_M->solverInfo,
                       &Torque_Control_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Torque_Control_M->solverInfo, (&rtmGetErrorStatus
      (Torque_Control_M)));
    rtsiSetRTModelPtr(&Torque_Control_M->solverInfo, Torque_Control_M);
  }

  rtsiSetSimTimeStep(&Torque_Control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Torque_Control_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Torque_Control_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Torque_Control_M points to
       static memory which is guaranteed to be non-NULL" */
    Torque_Control_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Torque_Control_M->Timing.sampleTimes =
      (&Torque_Control_M->Timing.sampleTimesArray[0]);
    Torque_Control_M->Timing.offsetTimes =
      (&Torque_Control_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Torque_Control_M->Timing.sampleTimes[0] = (0.0);
    Torque_Control_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    Torque_Control_M->Timing.offsetTimes[0] = (0.0);
    Torque_Control_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Torque_Control_M, &Torque_Control_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Torque_Control_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Torque_Control_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Torque_Control_M, 10.0);
  Torque_Control_M->Timing.stepSize0 = 0.2;
  Torque_Control_M->Timing.stepSize1 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Torque_Control_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Torque_Control_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Torque_Control_M->rtwLogInfo, (NULL));
    rtliSetLogT(Torque_Control_M->rtwLogInfo, "tout");
    rtliSetLogX(Torque_Control_M->rtwLogInfo, "");
    rtliSetLogXFinal(Torque_Control_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Torque_Control_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Torque_Control_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Torque_Control_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Torque_Control_M->rtwLogInfo, 1);
    rtliSetLogY(Torque_Control_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Torque_Control_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Torque_Control_M->rtwLogInfo, (NULL));
  }

  Torque_Control_M->solverInfoPtr = (&Torque_Control_M->solverInfo);
  Torque_Control_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Torque_Control_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Torque_Control_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Torque_Control_M->blockIO = ((void *) &Torque_Control_B);
  (void) memset(((void *) &Torque_Control_B), 0,
                sizeof(B_Torque_Control_T));

  /* states (dwork) */
  Torque_Control_M->dwork = ((void *) &Torque_Control_DW);
  (void) memset((void *)&Torque_Control_DW, 0,
                sizeof(DW_Torque_Control_T));

  /* external inputs */
  Torque_Control_M->inputs = (((void*)&Torque_Control_U));
  (void)memset(&Torque_Control_U, 0, sizeof(ExtU_Torque_Control_T));

  /* external outputs */
  Torque_Control_M->outputs = (&Torque_Control_Y);
  (void)memset(&Torque_Control_Y, 0, sizeof(ExtY_Torque_Control_T));

  /* Initialize Sizes */
  Torque_Control_M->Sizes.numContStates = (0);/* Number of continuous states */
  Torque_Control_M->Sizes.numY = (29); /* Number of model outputs */
  Torque_Control_M->Sizes.numU = (47); /* Number of model inputs */
  Torque_Control_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Torque_Control_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Torque_Control_M->Sizes.numBlocks = (652);/* Number of blocks */
  Torque_Control_M->Sizes.numBlockIO = (103);/* Number of block outputs */
  return Torque_Control_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
