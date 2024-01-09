/*
 * Torque_Control.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 10.2
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Tue Nov 21 18:27:38 2023
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

/* Continuous states */
X_Torque_Control_T Torque_Control_X;

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
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Torque_Control_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Torque_Control_output();
  Torque_Control_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Torque_Control_output();
  Torque_Control_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S15>/LimitReached'
 *    '<S17>/Latched Error'
 */
void Torque_Control_LimitReached(RT_MODEL_Torque_Control_T * const
  Torque_Control_M, real_T *rty_Out)
{
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* SignalConversion generated from: '<S16>/Out ' incorporates:
     *  Constant: '<S16>/Constant'
     */
    *rty_Out = 1.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S127>/MATLAB Function'
 *    '<S183>/MATLAB Function'
 *    '<S99>/MATLAB Function1'
 */
void Torque_Control_MATLABFunction(real_T rtu_MaxRegenTq, real_T rtu_Tq_RR,
  real_T rtu_Tq_RL, B_MATLABFunction_Torque_Contr_T *localB)
{
  localB->RegTq_RR = 0.0;
  localB->RegTq_RL = 0.0;
  if ((!(rtu_Tq_RR == 0.0)) || (!(rtu_Tq_RL == 0.0))) {
    if ((rtu_Tq_RR != 0.0) && (rtu_Tq_RL == 0.0)) {
      localB->RegTq_RL = rtu_Tq_RR;
    } else if ((rtu_Tq_RR == 0.0) && (rtu_Tq_RL != 0.0)) {
      localB->RegTq_RR = rtu_Tq_RL;
    } else if (rtu_Tq_RR == rtu_Tq_RL) {
      if (rtu_Tq_RR >= rtu_MaxRegenTq) {
        localB->RegTq_RR = rtu_MaxRegenTq;
        localB->RegTq_RL = rtu_MaxRegenTq;
      } else {
        localB->RegTq_RR = rtu_Tq_RR;
        localB->RegTq_RL = rtu_Tq_RL;
      }
    } else if (rtu_Tq_RR > rtu_Tq_RL) {
      if (rtu_Tq_RR < rtu_MaxRegenTq) {
        localB->RegTq_RR = rtu_Tq_RL * rtu_Tq_RL / rtu_Tq_RR;
        localB->RegTq_RL = rtu_Tq_RL;
      } else {
        localB->RegTq_RR = rtu_MaxRegenTq * rtu_Tq_RL / rtu_Tq_RR;
        localB->RegTq_RL = rtu_MaxRegenTq;
      }
    } else if (rtu_Tq_RR < rtu_Tq_RL) {
      if (rtu_Tq_RL < rtu_MaxRegenTq) {
        localB->RegTq_RR = rtu_Tq_RR;
        localB->RegTq_RL = rtu_Tq_RR * rtu_Tq_RR / rtu_Tq_RL;
      } else {
        localB->RegTq_RR = rtu_MaxRegenTq;
        localB->RegTq_RL = rtu_MaxRegenTq * rtu_Tq_RR / rtu_Tq_RL;
      }
    }
  }
}

/*
 * Output and update for action system:
 *    '<S115>/Braking with Regenerative'
 *    '<S174>/Braking with Regenerative'
 */
void Torque__BrakingwithRegenerative(real_T rtu_MaxRegTorque, real_T
  rtu_Tq_RR_wc, real_T rtu_Tq_RL_wc, real_T *rty_TQ_RR, real_T *rty_TQ_RL,
  B_BrakingwithRegenerative_Tor_T *localB)
{
  /* MATLAB Function: '<S127>/MATLAB Function' */
  Torque_Control_MATLABFunction(rtu_MaxRegTorque, rtu_Tq_RR_wc, rtu_Tq_RL_wc,
    &localB->sf_MATLABFunction);

  /* Gain: '<S127>/Gain' */
  *rty_TQ_RR = -localB->sf_MATLABFunction.RegTq_RR;

  /* Gain: '<S127>/Gain1' */
  *rty_TQ_RL = -localB->sf_MATLABFunction.RegTq_RL;
}

/*
 * Output and update for action system:
 *    '<S126>/If Action 1'
 *    '<S182>/If Action 1'
 */
void Torque_Control_IfAction1(RT_MODEL_Torque_Control_T * const Torque_Control_M,
  real_T rtu_Trans_max_dynamic, real_T *rty_Trans_limit)
{
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* SignalConversion generated from: '<S128>/Trans_max_dynamic' */
    *rty_Trans_limit = rtu_Trans_max_dynamic;
  }
}

/*
 * Output and update for action system:
 *    '<S126>/If Action 2'
 *    '<S182>/If Action 2'
 */
void Torque_Control_IfAction2(RT_MODEL_Torque_Control_T * const Torque_Control_M,
  real_T rtu_Trans_max_static, real_T *rty_Trans_limit)
{
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* SignalConversion generated from: '<S129>/Trans_max_static ' */
    *rty_Trans_limit = rtu_Trans_max_static;
  }
}

/*
 * Output and update for atomic system:
 *    '<S116>/Accelerator behaviour '
 *    '<S191>/Accelerator behaviour '
 *    '<S82>/Accelerator behaviour'
 *    '<S85>/Accelerator behaviour '
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
 *    '<S116>/Mech_Braking'
 *    '<S116>/Inertia Braking'
 *    '<S175>/Mech_Braking'
 *    '<S175>/Inertia Braking'
 *    '<S87>/Mech_Braking'
 *    '<S87>/Inertia Braking'
 */
void Torque_Control_Mech_Braking(RT_MODEL_Torque_Control_T * const
  Torque_Control_M, real_T *rty_Tq_RR, real_T *rty_Tq_RL)
{
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* SignalConversion generated from: '<S139>/Tq_RR  ' incorporates:
     *  Constant: '<S139>/Constant'
     */
    *rty_Tq_RR = 0.0;

    /* SignalConversion generated from: '<S139>/Tq_RL' incorporates:
     *  Constant: '<S139>/Constant1'
     */
    *rty_Tq_RL = 0.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S83>/MATLAB Function1'
 *    '<S83>/MATLAB Function2'
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
 *    '<S123>/MATLAB Function'
 *    '<S180>/MATLAB Function'
 *    '<S93>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_n(real_T rtu_RPM_INV1, real_T rtu_RPM_INV2,
  B_MATLABFunction_Torque_Con_d_T *localB)
{
  if (rtu_RPM_INV1 > rtu_RPM_INV2) {
    localB->RPM = rtu_RPM_INV1;
  } else {
    localB->RPM = rtu_RPM_INV2;
  }
}

/*
 * Output and update for atomic system:
 *    '<S166>/MATLAB Function'
 *    '<S111>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_e(real_T rtu_SKF_prev, real_T rtu_SKF_Initial,
  real_T rtu_Cte_SKF, B_MATLABFunction_Torque_Con_i_T *localB)
{
  localB->SKF_act0 = (2.0 - rtu_Cte_SKF) * rtu_SKF_prev;
  if (localB->SKF_act0 > rtu_SKF_Initial) {
    localB->SKF_act0 = rtu_SKF_Initial;
  }
}

/*
 * Output and update for atomic system:
 *    '<S163>/MATLAB Function'
 *    '<S208>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_m(real_T rtu_CKF_Initial, real_T rtu_CKF_prev,
  B_MATLABFunction_Torque_Con_k_T *localB)
{
  if (rtu_CKF_prev < rtu_CKF_Initial) {
    localB->CKF_act1 = rtu_CKF_prev;
  } else {
    localB->CKF_act1 = rtu_CKF_Initial;
  }
}

/*
 * Output and update for atomic system:
 *    '<S162>/MATLAB Function1'
 *    '<S207>/MATLAB Function'
 *    '<S107>/MATLAB Function'
 */
void Torque_Contro_MATLABFunction1_b(real_T rtu_CKF_prev, real_T rtu_CKF_Initial,
  real_T rtu_Cte_CKF, B_MATLABFunction1_Torque_Co_m_T *localB)
{
  localB->CKF_act0 = (2.0 - rtu_Cte_CKF) * rtu_CKF_prev;
  if (localB->CKF_act0 > rtu_CKF_Initial) {
    localB->CKF_act0 = rtu_CKF_Initial;
  }
}

/*
 * Output and update for atomic system:
 *    '<S120>/MATLAB Function'
 *    '<S120>/MATLAB Function1'
 *    '<S119>/MATLAB Function1'
 *    '<S119>/MATLAB Function2'
 *    '<S176>/MATLAB Function1'
 *    '<S176>/MATLAB Function2'
 *    '<S178>/MATLAB Function1'
 *    '<S178>/MATLAB Function2'
 */
void Torque_Control_MATLABFunction_d(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction_Torque_Con_h_T *localB)
{
  if ((rtu_v > 0.0) && (rtu_v < 60000.0)) {
    localB->value = rtu_v;
  } else {
    localB->value = rtu_cte;
  }
}

/*
 * Output and update for atomic system:
 *    '<S125>/MATLAB Function1'
 *    '<S125>/MATLAB Function2'
 */
void Torque_Contro_MATLABFunction1_m(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction1_Torque_Co_d_T *localB)
{
  if (rtu_v > 0.0) {
    localB->value = rtu_v;
  } else {
    localB->value = rtu_cte;
  }
}

/*
 * Output and update for action system:
 *    '<S72>/Automatic Failure Mode'
 *    '<S72>/Manual Failure Mode Selection'
 */
void Torque_Con_AutomaticFailureMode(real_T rtu_In1, real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S78>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S70>/Enabled '
 *    '<S70>/NotEnabled'
 */
void Torque_Control_Enabled(RT_MODEL_Torque_Control_T * const Torque_Control_M,
  real_T rtu_In1, real_T *rty_Out1)
{
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* SignalConversion generated from: '<S74>/In1' */
    *rty_Out1 = rtu_In1;
  }
}

/* Model output function */
void Torque_Control_output(void)
{
  /* local block i/o variables */
  real_T rtb_Abs3;
  real_T rtb_TransmissionGearRatio;
  real_T rtb_Switch;
  real_T rtb_Switch_b;
  real_T rtb_Tq_regen_RR;
  real_T rtb_Tq_regen_RL;
  real_T rtb_Product_c;
  real_T rtb_Product1;
  real_T rtb_Switch1;
  real_T rtb_Product_iv;
  real_T rtb_TomotorTqRT;
  real_T rtb_Product1_h;
  real_T rtb_Product2;
  real_T rtb_Product_a;
  real_T rtb_Product1_f;
  real_T rtb_Switch1_p;
  real_T rtb_Product_lj;
  real_T rtb_Switch1_c;
  real_T rtb_Merge1_j;
  real_T rtb_Merge2;
  real_T rtb_Integrator_k;
  real_T rtb_Integrator_d;
  real_T rtb_Integrator_j;
  real_T tmp[12];
  real_T A[9];
  real_T kamm_data_1[4];
  real_T a[3];
  real_T b_a[2];
  real_T kamm_data[2];
  real_T kamm_data_0[2];
  real_T Mz;
  real_T X_idx_1;
  real_T k;
  real_T mz;
  real_T p;
  real_T rtb_Abs1;
  real_T rtb_Abs4;
  real_T rtb_Lookup_Temp_SoP_chg;
  real_T rtb_Max_m;
  real_T rtb_Product5;
  real_T rtb_Saturation1_au;
  real_T rtb_Saturation1_g;
  real_T rtb_alpha_j;
  real_T rtb_value_k;
  real_T *lastU;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T rtb_Compare_c;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* set solver stop time */
    if (!(Torque_Control_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Torque_Control_M->solverInfo,
                            ((Torque_Control_M->Timing.clockTickH0 + 1) *
        Torque_Control_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Torque_Control_M->solverInfo,
                            ((Torque_Control_M->Timing.clockTick0 + 1) *
        Torque_Control_M->Timing.stepSize0 +
        Torque_Control_M->Timing.clockTickH0 *
        Torque_Control_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Torque_Control_M)) {
    Torque_Control_M->Timing.t[0] = rtsiGetT(&Torque_Control_M->solverInfo);
  }

  /* If: '<S56>/If' incorporates:
   *  Abs: '<S56>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S56>/Sum'
   */
  if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
    rtAction = (int8_T)!(fabs(Torque_Control_U.APPS1_Value -
      Torque_Control_U.APPS2_Value) > 0.1);
    Torque_Control_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S56>/Imp' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    /* Merge: '<S56>/Merge' incorporates:
     *  SignalConversion generated from: '<S58>/Out1'
     */
    Torque_Control_B.Merge_j = ((!rtmIsMajorTimeStep(Torque_Control_M)) &&
      Torque_Control_B.Merge_j);

    /* End of Outputs for SubSystem: '<S56>/Imp' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S56>/Not Imp' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    /* Merge: '<S56>/Merge' incorporates:
     *  SignalConversion generated from: '<S59>/Out1'
     */
    Torque_Control_B.Merge_j = (rtmIsMajorTimeStep(Torque_Control_M) ||
      Torque_Control_B.Merge_j);

    /* End of Outputs for SubSystem: '<S56>/Not Imp' */
    break;
  }

  /* End of If: '<S56>/If' */

  /* Logic: '<S10>/Logical Operator' incorporates:
   *  Constant: '<S57>/Constant'
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S10>/NOT'
   *  Logic: '<S10>/NOT1'
   *  RelationalOperator: '<S57>/Compare'
   */
  Torque_Control_B.LogicalOperator = ((!Torque_Control_U.Shutdown_PackageIntck) &&
    Torque_Control_U.TorqueEnable && (!Torque_Control_U.CriticalDisconnection) &&
    (Torque_Control_U.Car_State == 15.0) && Torque_Control_B.Merge_j);

  /* Abs: '<S12>/Abs1' incorporates:
   *  Inport: '<Root>/ACCEL_F_Y_SI'
   */
  rtb_Abs1 = fabs(Torque_Control_U.ACCEL_F_Y_SI);

  /* Abs: '<S12>/Abs4' incorporates:
   *  Inport: '<Root>/ACCEL_R_Y_SI'
   */
  rtb_Abs4 = fabs(Torque_Control_U.ACCEL_R_Y_SI);

  /* Outputs for Atomic SubSystem: '<S12>/TEST_MODE_IN' */
  /* If: '<S71>/If' incorporates:
   *  Inport: '<Root>/Workshop_Mode_Enable'
   */
  if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
    rtAction = (int8_T)!(Torque_Control_U.Workshop_Mode_Enable == 1.0);
    Torque_Control_DW.If_ActiveSubsystem_a = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_a;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S71>/TEST_CONSTANTS' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      /* Merge: '<S71>/Merge' incorporates:
       *  Constant: '<S77>/Constant'
       *  SignalConversion generated from: '<S77>/Out1'
       */
      Torque_Control_B.Merge_b = 800.0;

      /* Merge: '<S71>/Merge1' incorporates:
       *  Constant: '<S77>/Constant1'
       *  SignalConversion generated from: '<S77>/Out2'
       */
      Torque_Control_B.Merge1 = 800.0;

      /* Merge: '<S71>/Merge2' incorporates:
       *  Constant: '<S77>/Constant2'
       *  SignalConversion generated from: '<S77>/Out3'
       */
      Torque_Control_B.Merge2 = 800.0;

      /* Merge: '<S71>/Merge3' incorporates:
       *  Constant: '<S77>/Constant3'
       *  SignalConversion generated from: '<S77>/Out4'
       */
      Torque_Control_B.Merge3_b = 800.0;
    }

    /* End of Outputs for SubSystem: '<S71>/TEST_CONSTANTS' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S71>/BYPASS' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    /* Merge: '<S71>/Merge' incorporates:
     *  Inport: '<Root>/Susp_F_R'
     *  SignalConversion generated from: '<S76>/In1'
     */
    Torque_Control_B.Merge_b = Torque_Control_U.Susp_F_R;

    /* Merge: '<S71>/Merge1' incorporates:
     *  Inport: '<Root>/Susp_F_L'
     *  SignalConversion generated from: '<S76>/In2'
     */
    Torque_Control_B.Merge1 = Torque_Control_U.Susp_F_L;

    /* Merge: '<S71>/Merge2' incorporates:
     *  Inport: '<Root>/Susp_R_L'
     *  SignalConversion generated from: '<S76>/In3'
     */
    Torque_Control_B.Merge2 = Torque_Control_U.Susp_R_L;

    /* Merge: '<S71>/Merge3' incorporates:
     *  Inport: '<Root>/Susp_R_R'
     *  SignalConversion generated from: '<S76>/In4'
     */
    Torque_Control_B.Merge3_b = Torque_Control_U.Susp_R_R;

    /* End of Outputs for SubSystem: '<S71>/BYPASS' */
    break;
  }

  /* End of If: '<S71>/If' */
  /* End of Outputs for SubSystem: '<S12>/TEST_MODE_IN' */

  /* Outputs for Atomic SubSystem: '<S12>/Regeneration_Enable' */
  /* If: '<S70>/If' incorporates:
   *  Abs: '<Root>/Abs'
   *  Abs: '<Root>/Abs1'
   *  Constant: '<S70>/Enabled'
   *  Constant: '<S70>/Zero '
   *  Inport: '<Root>/Vel_RL_kmh'
   *  Inport: '<Root>/Vel_RR_kmh'
   */
  if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
    rtAction = (int8_T)((!(fabs(Torque_Control_U.Vel_RR_kmh) > 2.0)) || (!(fabs
      (Torque_Control_U.Vel_RL_kmh) > 2.0)));
    Torque_Control_DW.If_ActiveSubsystem_o = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_o;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S70>/Enabled ' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    Torque_Control_Enabled(Torque_Control_M, 1.0, &Torque_Control_B.Merge1_a);

    /* End of Outputs for SubSystem: '<S70>/Enabled ' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S70>/NotEnabled' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    Torque_Control_Enabled(Torque_Control_M, 0.0, &Torque_Control_B.Merge1_a);

    /* End of Outputs for SubSystem: '<S70>/NotEnabled' */
    break;
  }

  /* End of If: '<S70>/If' */
  /* End of Outputs for SubSystem: '<S12>/Regeneration_Enable' */

  /* Abs: '<Root>/Abs3' incorporates:
   *  Inport: '<Root>/RR_rads'
   */
  rtb_Abs3 = fabs(Torque_Control_U.RR_rads);

  /* Abs: '<Root>/Abs2' incorporates:
   *  Inport: '<Root>/RL_rads'
   */
  Torque_Control_B.Abs2 = fabs(Torque_Control_U.RL_rads);

  /* Gain: '<Root>/Transmission Gear Ratio' incorporates:
   *  Inport: '<Root>/VDC_Max_Regenerative_Torque'
   */
  rtb_TransmissionGearRatio = 4.0 * Torque_Control_U.VDC_Max_Regenerative_Torque;

  /* If: '<S12>/If' */
  rtPrevAction = Torque_Control_DW.If_ActiveSubsystem_k;
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
    if (Torque_Control_B.LogicalOperator) {
      rtAction = 0;
    }

    Torque_Control_DW.If_ActiveSubsystem_k = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_k;
  }

  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S72>/If' */
    Torque_Control_DW.If_ActiveSubsystem_j = -1;

    /* Disable for If: '<S72>/FAILURE MODE' */
    switch (Torque_Control_DW.FAILUREMODE_ActiveSubsystem) {
     case 0:
      /* Disable for If: '<S158>/SKF or CKF' */
      Torque_Control_DW.SKForCKF_ActiveSubsystem_o = -1;

      /* Disable for If: '<S83>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
      Torque_Control_DW.Steer_angisinSteer_SatrangeLong = -1;

      /* Disable for If: '<S116>/Braking Conditions' */
      Torque_Control_DW.BrakingConditions_ActiveSubsy_b = -1;

      /* Disable for If: '<S115>/If' */
      Torque_Control_DW.If_ActiveSubsystem_aq = -1;
      break;

     case 1:
     case 3:
     case 4:
      break;

     case 2:
      /* Disable for If: '<S103>/SKF or CKF' */
      if (Torque_Control_DW.SKForCKF_ActiveSubsystem == 1) {
        /* Disable for If: '<S104>/If1' */
        Torque_Control_DW.If1_ActiveSubsystem_ca = -1;
      }

      Torque_Control_DW.SKForCKF_ActiveSubsystem = -1;

      /* Disable for If: '<S82>/If1' */
      Torque_Control_DW.If1_ActiveSubsystem_c = -1;

      /* Disable for If: '<S82>/If' */
      Torque_Control_DW.If_ActiveSubsystem_d = -1;

      /* Disable for If: '<S87>/Braking Conditions' */
      Torque_Control_DW.BrakingConditions_ActiveSubsyst = -1;
      break;
    }

    Torque_Control_DW.FAILUREMODE_ActiveSubsystem = -1;

    /* End of Disable for If: '<S72>/FAILURE MODE' */
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S12>/Vehicle Dynamics Control Modes' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      /* If: '<S72>/If' incorporates:
       *  Constant: '<Root>/Constant'
       *  Constant: '<S72>/Constant'
       */
      if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
        Torque_Control_DW.If_ActiveSubsystem_j = 0;
      } else {
        rtAction = Torque_Control_DW.If_ActiveSubsystem_j;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S72>/Automatic Failure Mode' incorporates:
         *  ActionPort: '<S78>/Action Port'
         */
        Torque_Con_AutomaticFailureMode(3.0, &Torque_Control_B.Merge_l);

        /* End of Outputs for SubSystem: '<S72>/Automatic Failure Mode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S72>/Manual Failure Mode Selection' incorporates:
         *  ActionPort: '<S80>/Action Port'
         */
        Torque_Con_AutomaticFailureMode(5.0, &Torque_Control_B.Merge_l);

        /* End of Outputs for SubSystem: '<S72>/Manual Failure Mode Selection' */
        break;
      }

      /* End of If: '<S72>/If' */
    }

    /* Gain: '<S72>/Gain' incorporates:
     *  Inport: '<Root>/SteeringSensor_Value'
     */
    Torque_Control_B.Gain_n = -Torque_Control_U.SteeringSensor_Value;

    /* If: '<S72>/FAILURE MODE' */
    rtPrevAction = Torque_Control_DW.FAILUREMODE_ActiveSubsystem;
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
      if (Torque_Control_B.Merge_l == 1.0) {
        rtAction = 0;
      } else if (Torque_Control_B.Merge_l == 2.0) {
        rtAction = 1;
      } else if (Torque_Control_B.Merge_l == 3.0) {
        rtAction = 2;
      } else if (Torque_Control_B.Merge_l == 4.0) {
        rtAction = 3;
      } else if (Torque_Control_B.Merge_l == 0.0) {
        rtAction = 4;
      }

      Torque_Control_DW.FAILUREMODE_ActiveSubsystem = rtAction;
    } else {
      rtAction = Torque_Control_DW.FAILUREMODE_ActiveSubsystem;
    }

    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for If: '<S158>/SKF or CKF' */
        Torque_Control_DW.SKForCKF_ActiveSubsystem_o = -1;

        /* Disable for If: '<S83>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
        Torque_Control_DW.Steer_angisinSteer_SatrangeLong = -1;

        /* Disable for If: '<S116>/Braking Conditions' */
        Torque_Control_DW.BrakingConditions_ActiveSubsy_b = -1;

        /* Disable for If: '<S115>/If' */
        Torque_Control_DW.If_ActiveSubsystem_aq = -1;
        break;

       case 1:
       case 3:
       case 4:
        break;

       case 2:
        /* Disable for If: '<S103>/SKF or CKF' */
        if (Torque_Control_DW.SKForCKF_ActiveSubsystem == 1) {
          /* Disable for If: '<S104>/If1' */
          Torque_Control_DW.If1_ActiveSubsystem_ca = -1;
        }

        Torque_Control_DW.SKForCKF_ActiveSubsystem = -1;

        /* Disable for If: '<S82>/If1' */
        Torque_Control_DW.If1_ActiveSubsystem_c = -1;

        /* Disable for If: '<S82>/If' */
        Torque_Control_DW.If_ActiveSubsystem_d = -1;

        /* Disable for If: '<S87>/Braking Conditions' */
        Torque_Control_DW.BrakingConditions_ActiveSubsyst = -1;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      {
        real_T tmp_0;

        /* Outputs for IfAction SubSystem: '<S72>/VDC Complete' incorporates:
         *  ActionPort: '<S83>/Action Port'
         */
        /* MATLAB Function: '<S158>/MATLAB Function1' incorporates:
         *  Constant: '<S158>/Steering Wheel Maximum Angle'
         */
        if (Torque_Control_B.Gain_n > 100.0) {
          rtb_value_k = 100.0;
        } else if (Torque_Control_B.Gain_n < -100.0) {
          rtb_value_k = -100.0;
        } else {
          rtb_value_k = Torque_Control_B.Gain_n;
        }

        /* End of MATLAB Function: '<S158>/MATLAB Function1' */

        /* MATLAB Function: '<S123>/MATLAB Function' */
        Torque_Control_MATLABFunction_n(Torque_Control_B.Abs2, rtb_Abs3,
          &Torque_Control_B.sf_MATLABFunction_n);

        /* Derivative: '<S123>/Derivative' */
        k = Torque_Control_M->Timing.t[0];
        if ((Torque_Control_DW.TimeStampA_g >= k) &&
            (Torque_Control_DW.TimeStampB_c >= k)) {
          rtb_alpha_j = 0.0;
        } else {
          p = Torque_Control_DW.TimeStampA_g;
          lastU = &Torque_Control_DW.LastUAtTimeA_c;
          if (Torque_Control_DW.TimeStampA_g < Torque_Control_DW.TimeStampB_c) {
            if (Torque_Control_DW.TimeStampB_c < k) {
              p = Torque_Control_DW.TimeStampB_c;
              lastU = &Torque_Control_DW.LastUAtTimeB_f;
            }
          } else if (Torque_Control_DW.TimeStampA_g >= k) {
            p = Torque_Control_DW.TimeStampB_c;
            lastU = &Torque_Control_DW.LastUAtTimeB_f;
          }

          rtb_alpha_j = (Torque_Control_B.sf_MATLABFunction_n.RPM - *lastU) / (k
            - p);
        }

        /* End of Derivative: '<S123>/Derivative' */

        /* If: '<S158>/SKF or CKF' */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          rtAction = (int8_T)((!(rtb_value_k > -10.0)) || (!(rtb_value_k < 10.0)));
          Torque_Control_DW.SKForCKF_ActiveSubsystem_o = rtAction;
        } else {
          rtAction = Torque_Control_DW.SKForCKF_ActiveSubsystem_o;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S158>/SKF' incorporates:
           *  ActionPort: '<S161>/Action Port'
           */
          /* If: '<S161>/If' */
          rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
            if (rtb_alpha_j >= 900.0) {
              rtAction = 0;
            } else if (rtb_alpha_j < 900.0) {
              rtAction = 1;
            }

            Torque_Control_DW.If_ActiveSubsystem_ha = rtAction;
          } else {
            rtAction = Torque_Control_DW.If_ActiveSubsystem_ha;
          }

          switch (rtAction) {
           case 0:
            /* Outputs for IfAction SubSystem: '<S161>/Spin' incorporates:
             *  ActionPort: '<S167>/Action Port'
             */
            /* Switch: '<S167>/Switch1' incorporates:
             *  DataStoreRead: '<S123>/SKF_prev '
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            if (Torque_Control_DW.A_b > 0.0) {
              p = Torque_Control_DW.A_b;
            } else {
              p = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of Switch: '<S167>/Switch1' */

            /* Switch: '<S167>/Switch' incorporates:
             *  Constant: '<S167>/Constant'
             *  Inport: '<Root>/VDC_Cte_CKF'
             */
            if (Torque_Control_U.VDC_Cte_CKF >= 0.9) {
              tmp_0 = Torque_Control_U.VDC_Cte_CKF;
            } else {
              tmp_0 = 1.0;
            }

            /* End of Switch: '<S167>/Switch' */

            /* Product: '<S167>/Product' */
            rtb_value_k = p * tmp_0;

            /* MATLAB Function: '<S167>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            if (rtb_value_k < Torque_Control_U.VDC_SKF_Initial) {
              /* Merge: '<S161>/Merge' incorporates:
               *  SignalConversion generated from: '<S167>/SKF_act1'
               */
              Torque_Control_B.Merge_i = rtb_value_k;
            } else {
              /* Merge: '<S161>/Merge' incorporates:
               *  SignalConversion generated from: '<S167>/SKF_act1'
               */
              Torque_Control_B.Merge_i = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of MATLAB Function: '<S167>/MATLAB Function' */
            /* End of Outputs for SubSystem: '<S161>/Spin' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S161>/No spin' incorporates:
             *  ActionPort: '<S166>/Action Port'
             */
            /* Switch: '<S166>/Switch1' incorporates:
             *  DataStoreRead: '<S123>/SKF_prev '
             */
            if (Torque_Control_DW.A_b > 0.0) {
              /* Switch: '<S166>/Switch1' */
              rtb_Switch1_c = Torque_Control_DW.A_b;
            } else {
              /* Switch: '<S166>/Switch1' incorporates:
               *  Inport: '<Root>/VDC_SKF_Initial'
               */
              rtb_Switch1_c = Torque_Control_U.VDC_SKF_Initial;
            }

            /* End of Switch: '<S166>/Switch1' */

            /* MATLAB Function: '<S166>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_Cte_CKF'
             *  Inport: '<Root>/VDC_SKF_Initial'
             */
            Torque_Control_MATLABFunction_e(rtb_Switch1_c,
              Torque_Control_U.VDC_SKF_Initial, Torque_Control_U.VDC_Cte_CKF,
              &Torque_Control_B.sf_MATLABFunction_ed);

            /* Merge: '<S161>/Merge' incorporates:
             *  SignalConversion generated from: '<S166>/SKF_act0'
             */
            Torque_Control_B.Merge_i =
              Torque_Control_B.sf_MATLABFunction_ed.SKF_act0;

            /* End of Outputs for SubSystem: '<S161>/No spin' */
            break;
          }

          /* End of If: '<S161>/If' */

          /* Saturate: '<S161>/Saturation' */
          if (Torque_Control_B.Merge_i > 1.0) {
            /* Saturate: '<S161>/Saturation' */
            Torque_Control_B.Saturation_f = 1.0;
          } else if (Torque_Control_B.Merge_i < 0.3) {
            /* Saturate: '<S161>/Saturation' */
            Torque_Control_B.Saturation_f = 0.3;
          } else {
            /* Saturate: '<S161>/Saturation' */
            Torque_Control_B.Saturation_f = Torque_Control_B.Merge_i;
          }

          /* End of Saturate: '<S161>/Saturation' */
          /* End of Outputs for SubSystem: '<S158>/SKF' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S158>/CKF' incorporates:
           *  ActionPort: '<S159>/Action Port'
           */
          /* If: '<S159>/If1' */
          rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
            if (rtb_alpha_j >= 900.0) {
              rtAction = 0;
            } else if (rtb_alpha_j < 900.0) {
              rtAction = 1;
            }

            Torque_Control_DW.If1_ActiveSubsystem_o = rtAction;
          } else {
            rtAction = Torque_Control_DW.If1_ActiveSubsystem_o;
          }

          switch (rtAction) {
           case 0:
            /* Outputs for IfAction SubSystem: '<S159>/Spin ' incorporates:
             *  ActionPort: '<S163>/Action Port'
             */
            /* Switch: '<S163>/Switch1' incorporates:
             *  DataStoreRead: '<S123>/CKF_prev'
             *  Inport: '<Root>/VDC_CKF_Initial'
             */
            if (Torque_Control_DW.B_i > 0.0) {
              p = Torque_Control_DW.B_i;
            } else {
              p = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of Switch: '<S163>/Switch1' */

            /* Switch: '<S163>/Switch' incorporates:
             *  Constant: '<S163>/Constant'
             *  Inport: '<Root>/VDC_Cte_SKF'
             */
            if (Torque_Control_U.VDC_Cte_SKF > 0.9) {
              tmp_0 = Torque_Control_U.VDC_Cte_SKF;
            } else {
              tmp_0 = 1.0;
            }

            /* End of Switch: '<S163>/Switch' */

            /* Product: '<S163>/Product' */
            rtb_Product_lj = p * tmp_0;

            /* MATLAB Function: '<S163>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             */
            Torque_Control_MATLABFunction_m(Torque_Control_U.VDC_CKF_Initial,
              rtb_Product_lj, &Torque_Control_B.sf_MATLABFunction_mt);

            /* Merge: '<S159>/Merge' incorporates:
             *  SignalConversion generated from: '<S163>/CKF_act1 '
             */
            Torque_Control_B.Merge_c =
              Torque_Control_B.sf_MATLABFunction_mt.CKF_act1;

            /* End of Outputs for SubSystem: '<S159>/Spin ' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S159>/No spin' incorporates:
             *  ActionPort: '<S162>/Action Port'
             */
            /* Switch: '<S162>/Switch1' incorporates:
             *  DataStoreRead: '<S123>/CKF_prev'
             */
            if (Torque_Control_DW.B_i > 0.0) {
              /* Switch: '<S162>/Switch1' */
              rtb_Switch1_p = Torque_Control_DW.B_i;
            } else {
              /* Switch: '<S162>/Switch1' incorporates:
               *  Inport: '<Root>/VDC_CKF_Initial'
               */
              rtb_Switch1_p = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of Switch: '<S162>/Switch1' */

            /* MATLAB Function: '<S162>/MATLAB Function1' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             *  Inport: '<Root>/VDC_Cte_SKF'
             */
            Torque_Contro_MATLABFunction1_b(rtb_Switch1_p,
              Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_SKF,
              &Torque_Control_B.sf_MATLABFunction1_b);

            /* Merge: '<S159>/Merge' incorporates:
             *  SignalConversion generated from: '<S162>/CKF_act0'
             */
            Torque_Control_B.Merge_c =
              Torque_Control_B.sf_MATLABFunction1_b.CKF_act0;

            /* End of Outputs for SubSystem: '<S159>/No spin' */
            break;
          }

          /* End of If: '<S159>/If1' */

          /* Saturate: '<S159>/Saturation' */
          if (Torque_Control_B.Merge_c > 1.0) {
            /* Saturate: '<S159>/Saturation' */
            Torque_Control_B.Saturation_i = 1.0;
          } else if (Torque_Control_B.Merge_c < 0.3) {
            /* Saturate: '<S159>/Saturation' */
            Torque_Control_B.Saturation_i = 0.3;
          } else {
            /* Saturate: '<S159>/Saturation' */
            Torque_Control_B.Saturation_i = Torque_Control_B.Merge_c;
          }

          /* End of Saturate: '<S159>/Saturation' */
          /* End of Outputs for SubSystem: '<S158>/CKF' */
          break;
        }

        /* End of If: '<S158>/SKF or CKF' */

        /* DataStoreWrite: '<S123>/Data Store Write' */
        Torque_Control_DW.A_b = Torque_Control_B.Saturation_f;

        /* DataStoreWrite: '<S123>/Data Store Write1' */
        Torque_Control_DW.B_i = Torque_Control_B.Saturation_i;

        /* Saturate: '<S123>/Saturation' */
        if (rtb_alpha_j > 6000.0) {
          /* Saturate: '<S123>/Saturation' */
          Torque_Control_B.Saturation_j = 6000.0;
        } else if (rtb_alpha_j < 0.0) {
          /* Saturate: '<S123>/Saturation' */
          Torque_Control_B.Saturation_j = 0.0;
        } else {
          /* Saturate: '<S123>/Saturation' */
          Torque_Control_B.Saturation_j = rtb_alpha_j;
        }

        /* End of Saturate: '<S123>/Saturation' */

        /* Switch: '<S123>/Switch' */
        if (rtb_alpha_j >= 900.0) {
          /* Switch: '<S123>/Switch' */
          Torque_Control_B.Switch_p = rtb_alpha_j;
        } else {
          /* Switch: '<S123>/Switch' incorporates:
           *  Constant: '<S123>/Constant'
           */
          Torque_Control_B.Switch_p = 0.0;
        }

        /* End of Switch: '<S123>/Switch' */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
        }

        /* Gain: '<S118>/To motor Tq (RT)' */
        rtb_TomotorTqRT = 0.25 * rtb_TransmissionGearRatio;

        /* If: '<S83>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' incorporates:
         *  Constant: '<S72>/Steering Wheel Saturation (per site) [deg] '
         */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          rtAction = (int8_T)((!(Torque_Control_B.Gain_n >= -10.0)) ||
                              (!(Torque_Control_B.Gain_n <= 10.0)));
          Torque_Control_DW.Steer_angisinSteer_SatrangeLong = rtAction;
        } else {
          rtAction = Torque_Control_DW.Steer_angisinSteer_SatrangeLong;
        }

        switch (rtAction) {
         case 0:
          {
            real_T My;
            real_T my;
            int32_T r1;
            int32_T r2;

            /* Outputs for IfAction SubSystem: '<S83>/Longitudinal Dynamics' incorporates:
             *  ActionPort: '<S120>/Action Port'
             */
            if (rtmIsMajorTimeStep(Torque_Control_M)) {
              /* Merge: '<S83>/Merge' incorporates:
               *  Constant: '<S120>/Constant1'
               *  SignalConversion generated from: '<S120>/Fx_FR'
               */
              Torque_Control_B.Merge_m = 0.0;

              /* Merge: '<S83>/Merge1' incorporates:
               *  Constant: '<S120>/Constant2'
               *  SignalConversion generated from: '<S120>/Fx_FL'
               */
              Torque_Control_B.Merge1_n = 0.0;
            }

            /* Merge: '<S83>/Merge4' incorporates:
             *  Gain: '<S120>/Gain'
             *  Sum: '<S120>/Add'
             */
            Torque_Control_B.Merge4 = (((Torque_Control_B.Merge_b +
              Torque_Control_B.Merge1) + Torque_Control_B.Merge2) +
              Torque_Control_B.Merge3_b) * 0.1019367991845056;

            /* MATLAB Function: '<S120>/minimum value' */
            rtb_value_k = Torque_Control_B.Merge2;
            if (Torque_Control_B.Merge3_b < Torque_Control_B.Merge2) {
              rtb_value_k = Torque_Control_B.Merge3_b;
            }

            /* End of MATLAB Function: '<S120>/minimum value' */

            /* MATLAB Function: '<S152>/Kamm_Circle LatD' incorporates:
             *  Constant: '<S120>/Constant'
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
              if (rtb_value_k > p) {
                mz = k;
              } else if (rtb_value_k < p) {
                Mz = k;
              }

              k = floor((Mz + mz) / 2.0);
              p = Mz - mz;
              if (rtb_value_k == Torque_Control_B.kamm_data[(int32_T)Mz]) {
                p = 1.0;
                mz = Mz;
              } else if (rtb_value_k == Torque_Control_B.kamm_data[(int32_T)mz])
              {
                p = 1.0;
                Mz = mz;
              } else if (rtb_value_k == Torque_Control_B.kamm_data[(int32_T)k])
              {
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
              rtb_alpha_j = b_a[0] * 0.0 + b_a[1];
            } else if ((Mz != mz) && (My == my)) {
              kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
              kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
              kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)mz];
              kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)Mz];
              polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
              rtb_alpha_j = b_a[0] * rtb_value_k + b_a[1];
            } else if ((Mz == mz) && (My == my)) {
              rtb_alpha_j = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)Mz];
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
              tmp_0 = Torque_Control_B.kamm_data[17 * (int32_T)My];
              tmp[9] = tmp_0;
              tmp[10] = p;
              tmp[11] = tmp_0;
              kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)mz];
              kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)mz];
              kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)Mz];
              kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)Mz];
              mldivide_8ZFDevWm(tmp, kamm_data_1, a);
              rtb_alpha_j = (a[1] * rtb_value_k + a[0]) + a[2] * 0.0;
            }

            mz = 1.0;
            Mz = 16.0;
            k = 8.0;
            p = 15.0;
            while (p != 1.0) {
              p = Torque_Control_B.kamm_data[(int32_T)k];
              if (rtb_value_k > p) {
                mz = k;
              } else if (rtb_value_k < p) {
                Mz = k;
              }

              k = floor((Mz + mz) / 2.0);
              p = Mz - mz;
              if (rtb_value_k == Torque_Control_B.kamm_data[(int32_T)Mz]) {
                p = 1.0;
                mz = Mz;
              } else if (rtb_value_k == Torque_Control_B.kamm_data[(int32_T)mz])
              {
                p = 1.0;
                Mz = mz;
              } else if (rtb_value_k == Torque_Control_B.kamm_data[(int32_T)k])
              {
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
              mz = b_a[0] * rtb_value_k + b_a[1];
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
              tmp_0 = Torque_Control_B.kamm_data[17 * (int32_T)My];
              tmp[9] = tmp_0;
              tmp[10] = p;
              tmp[11] = tmp_0;
              kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)mz];
              kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)mz];
              kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)Mz];
              kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)Mz];
              mldivide_8ZFDevWm(tmp, kamm_data_1, a);
              mz = (a[1] * rtb_value_k + a[0]) + a[2] * 0.0;
            }

            /* Product: '<S152>/Product' incorporates:
             *  MATLAB Function: '<S152>/Kamm_Circle LatD'
             */
            rtb_Product_a = rtb_alpha_j * Torque_Control_B.Saturation_f;

            /* Product: '<S152>/Product1' incorporates:
             *  MATLAB Function: '<S152>/Kamm_Circle LatD'
             */
            rtb_Product1_f = mz * Torque_Control_B.Saturation_f;

            /* MATLAB Function: '<S120>/MATLAB Function' incorporates:
             *  Constant: '<S120>/Constant4'
             */
            Torque_Control_MATLABFunction_d(-1.0, rtb_Product_a,
              &Torque_Control_B.sf_MATLABFunction_d);

            /* MATLAB Function: '<S120>/MATLAB Function1' incorporates:
             *  Constant: '<S120>/Constant3'
             */
            Torque_Control_MATLABFunction_d(-1.0, rtb_Product1_f,
              &Torque_Control_B.sf_MATLABFunction1_g);

            /* Merge: '<S83>/Merge3' incorporates:
             *  SignalConversion generated from: '<S120>/Fx_RL '
             */
            Torque_Control_B.Merge3_e =
              Torque_Control_B.sf_MATLABFunction1_g.value;

            /* Merge: '<S83>/Merge2' incorporates:
             *  SignalConversion generated from: '<S120>/Fx_RR '
             */
            Torque_Control_B.Merge2_lx =
              Torque_Control_B.sf_MATLABFunction_d.value;
            if (rtmIsMajorTimeStep(Torque_Control_M)) {
              /* Merge: '<S83>/Merge6' incorporates:
               *  Constant: '<S120>/Constant5'
               *  SignalConversion generated from: '<S120>/Fy_R'
               */
              Torque_Control_B.Merge6 = 0.0;

              /* Merge: '<S83>/Merge7' incorporates:
               *  Constant: '<S120>/Constant6'
               *  SignalConversion generated from: '<S120>/Flag CarBehavior'
               */
              Torque_Control_B.Merge7 = 0.0;
            }

            /* Merge: '<S83>/Merge5' incorporates:
             *  Sum: '<S120>/Add1'
             */
            Torque_Control_B.Merge5 = rtb_Abs4 - rtb_Abs1;

            /* End of Outputs for SubSystem: '<S83>/Longitudinal Dynamics' */
          }
          break;

         case 1:
          {
            real_T My;
            real_T X_idx_0;
            real_T b_idx_0;
            real_T my;
            real_T rtb_Divide_oh;
            real_T rtb_Sum;
            int32_T r1;
            int32_T r2;
            int32_T r3;

            /* Outputs for IfAction SubSystem: '<S83>/Lateral Dynamics' incorporates:
             *  ActionPort: '<S119>/Action Port'
             */
            if (rtmIsMajorTimeStep(Torque_Control_M)) {
              /* Merge: '<S83>/Merge' incorporates:
               *  Constant: '<S119>/Constant1'
               *  SignalConversion generated from: '<S119>/Fx_FR'
               */
              Torque_Control_B.Merge_m = 0.0;

              /* Merge: '<S83>/Merge1' incorporates:
               *  Constant: '<S119>/Constant2'
               *  SignalConversion generated from: '<S119>/Fx_FL'
               */
              Torque_Control_B.Merge1_n = 0.0;
            }

            /* Merge: '<S83>/Merge5' incorporates:
             *  Sum: '<S119>/Add'
             */
            Torque_Control_B.Merge5 = rtb_Abs4 - rtb_Abs1;

            /* Product: '<S147>/Divide' incorporates:
             *  Constant: '<S147>/Steering_Ratio [-]'
             */
            rtb_Abs1 = Torque_Control_B.Gain_n / 3.72;

            /* MATLAB Function: '<S147>/Bicycle Model' incorporates:
             *  Constant: '<S147>/Constant7'
             *  Constant: '<S147>/Constant8'
             *  Constant: '<S147>/Wheelbase [m]'
             *  Integrator: '<S119>/Integrator'
             */
            rtb_value_k = rtb_Abs1 * 2.0 * 3.1415926535897931 / 360.0;
            A[0] = Torque_Control_ConstB.u602pi;
            A[3] = Torque_Control_ConstB.u602pi_e;
            A[6] = -360.0 * Torque_Control_X.Integrator_CSTATE;
            A[1] = 0.92 * Torque_Control_ConstB.u602pi;
            A[4] = -0.61 * Torque_Control_ConstB.u602pi_e;
            A[7] = 0.0;
            A[2] = -1.0;
            A[5] = 1.0;
            A[8] = 1.53 / Torque_Control_X.Integrator_CSTATE;
            a[0] = 0.0;
            a[1] = 0.0;
            a[2] = rtb_value_k;
            r1 = 0;
            r2 = 1;
            r3 = 2;
            mz = fabs(Torque_Control_ConstB.u602pi);
            Mz = fabs(A[1]);
            if (Mz > mz) {
              mz = Mz;
              r1 = 1;
              r2 = 0;
            }

            if (mz < 1.0) {
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
            mz = ((a[r3] - a[r1] * A[r3]) - A[r3 + 3] * X_idx_1) / A[r3 + 6];
            X_idx_1 = (X_idx_1 - A[r2 + 6] * mz) / A[r2 + 3];
            X_idx_0 = ((a[r1] - A[r1 + 6] * mz) - A[r1 + 3] * X_idx_1) / A[r1];
            rtb_alpha_j = atan((Torque_Control_X.Integrator_CSTATE * tan(X_idx_1)
                                + mz * 0.61) /
                               Torque_Control_X.Integrator_CSTATE);
            b_idx_0 = rtb_alpha_j;
            r1 = 0;
            if (rtIsNaN(rtb_alpha_j)) {
              r1 = 1;
            }

            if (r1 - 1 >= 0) {
              b_idx_0 = 0.0;
            }

            Torque_Control_B.radius = Torque_Control_X.Integrator_CSTATE / mz;
            Torque_Control_B.yf = Torque_Control_ConstB.u602pi * X_idx_0;
            Torque_Control_B.yr = Torque_Control_ConstB.u602pi_e * X_idx_1;

            /* Sum: '<S119>/Sum3' incorporates:
             *  Inport: '<Root>/Gyro_F_Z_Deg'
             *  MATLAB Function: '<S147>/Bicycle Model'
             */
            Torque_Control_B.Sum3 = mz - Torque_Control_U.Gyro_F_Z_Deg;

            /* Product: '<S150>/Divide' incorporates:
             *  Constant: '<S118>/Constant1'
             *  Constant: '<S119>/Yaw_Inertia [kg//m^3]'
             *  Product: '<S150>/Product'
             */
            Torque_Control_B.Divide_a = Torque_Control_B.Sum3 * 43.21 / 0.025;

            /* Product: '<S149>/Divide' */
            rtb_Divide_oh = Torque_Control_B.Divide_a /
              Torque_Control_ConstB.Divide1;

            /* Sum: '<S119>/Sum' */
            rtb_Sum = Torque_Control_B.Merge2 + Torque_Control_B.Merge3_b;

            /* Gain: '<S119>/Fy per wheel' incorporates:
             *  Gain: '<S119>/Gravity'
             *  Product: '<S119>/Product'
             */
            rtb_Abs4 = 0.1019367991845056 * rtb_Sum * rtb_Abs4 * 0.5;

            /* MATLAB Function: '<S143>/Kamm_Circle LatD' */
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
              if (rtb_Abs4 > p) {
                my = k;
              } else if (rtb_Abs4 < p) {
                My = k;
              }

              k = floor((My + my) / 2.0);
              p = My - my;
              if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_Abs4) {
                p = 1.0;
                my = My;
              } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] ==
                         rtb_Abs4) {
                p = 1.0;
                My = my;
              } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_Abs4)
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
              rtb_alpha_j = b_a[0] * rtb_Abs4 + b_a[1];
            } else if ((Mz != mz) && (My == my)) {
              kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
              kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
              kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)mz];
              kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)Mz];
              polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
              rtb_alpha_j = b_a[0] * Torque_Control_B.Merge2 + b_a[1];
            } else if ((Mz == mz) && (My == my)) {
              rtb_alpha_j = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)Mz];
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
              tmp_0 = Torque_Control_B.kamm_data[17 * (int32_T)My];
              tmp[9] = tmp_0;
              tmp[10] = p;
              tmp[11] = tmp_0;
              kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)mz];
              kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)mz];
              kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)Mz];
              kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)Mz];
              mldivide_8ZFDevWm(tmp, kamm_data_1, a);
              rtb_alpha_j = (a[1] * Torque_Control_B.Merge2 + a[0]) + a[2] *
                rtb_Abs4;
            }

            mz = 1.0;
            Mz = 16.0;
            k = 8.0;
            p = 15.0;
            while (p != 1.0) {
              p = Torque_Control_B.kamm_data[(int32_T)k];
              if (Torque_Control_B.Merge3_b > p) {
                mz = k;
              } else if (Torque_Control_B.Merge3_b < p) {
                Mz = k;
              }

              k = floor((Mz + mz) / 2.0);
              p = Mz - mz;
              if (Torque_Control_B.Merge3_b == Torque_Control_B.kamm_data
                  [(int32_T)Mz]) {
                p = 1.0;
                mz = Mz;
              } else if (Torque_Control_B.Merge3_b ==
                         Torque_Control_B.kamm_data[(int32_T)mz]) {
                p = 1.0;
                Mz = mz;
              } else if (Torque_Control_B.Merge3_b ==
                         Torque_Control_B.kamm_data[(int32_T)k]) {
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
              if (rtb_Abs4 > p) {
                my = k;
              } else if (rtb_Abs4 < p) {
                My = k;
              }

              k = floor((My + my) / 2.0);
              p = My - my;
              if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_Abs4) {
                p = 1.0;
                my = My;
              } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] ==
                         rtb_Abs4) {
                p = 1.0;
                My = my;
              } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_Abs4)
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
              mz = b_a[0] * rtb_Abs4 + b_a[1];
            } else if ((Mz != mz) && (My == my)) {
              kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
              kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
              kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)mz];
              kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)Mz];
              polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
              mz = b_a[0] * Torque_Control_B.Merge3_b + b_a[1];
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
              tmp_0 = Torque_Control_B.kamm_data[17 * (int32_T)My];
              tmp[9] = tmp_0;
              tmp[10] = p;
              tmp[11] = tmp_0;
              kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)mz];
              kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)mz];
              kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
                (int32_T)Mz];
              kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
                (int32_T)Mz];
              mldivide_8ZFDevWm(tmp, kamm_data_1, a);
              mz = (a[1] * Torque_Control_B.Merge3_b + a[0]) + a[2] * rtb_Abs4;
            }

            /* Product: '<S143>/Product1' incorporates:
             *  MATLAB Function: '<S143>/Kamm_Circle LatD'
             */
            rtb_Product1_h = rtb_alpha_j * Torque_Control_B.Saturation_i;

            /* MATLAB Function: '<S119>/MATLAB Function2' incorporates:
             *  Constant: '<S119>/Constant4'
             */
            Torque_Control_MATLABFunction_d(-1.0, rtb_Product1_h,
              &Torque_Control_B.sf_MATLABFunction2_e);

            /* Product: '<S143>/Product2' incorporates:
             *  MATLAB Function: '<S143>/Kamm_Circle LatD'
             */
            rtb_Product2 = mz * Torque_Control_B.Saturation_i;

            /* MATLAB Function: '<S119>/MATLAB Function1' incorporates:
             *  Constant: '<S119>/Constant3'
             */
            Torque_Control_MATLABFunction_d(-1.0, rtb_Product2,
              &Torque_Control_B.sf_MATLABFunction1_mk);

            /* MATLAB Function: '<S119>/Force Difference with  Max. Tire Forces' */
            if (rtb_Divide_oh > 0.0) {
              mz = Torque_Control_B.sf_MATLABFunction1_mk.value;
              rtb_alpha_j = Torque_Control_B.sf_MATLABFunction1_mk.value -
                rtb_Divide_oh;
              if (rtb_alpha_j > Torque_Control_B.sf_MATLABFunction2_e.value) {
                rtb_alpha_j = Torque_Control_B.sf_MATLABFunction2_e.value;
                mz = Torque_Control_B.sf_MATLABFunction2_e.value + rtb_Divide_oh;
              }
            } else if (rtb_Divide_oh < 0.0) {
              rtb_alpha_j = Torque_Control_B.sf_MATLABFunction2_e.value;
              Mz = fabs(rtb_Divide_oh);
              mz = Torque_Control_B.sf_MATLABFunction2_e.value - Mz;
              if (mz > Torque_Control_B.sf_MATLABFunction1_mk.value) {
                mz = Torque_Control_B.sf_MATLABFunction1_mk.value;
                rtb_alpha_j = Torque_Control_B.sf_MATLABFunction1_mk.value - Mz;
              }
            } else if (Torque_Control_B.sf_MATLABFunction2_e.value >
                       Torque_Control_B.sf_MATLABFunction1_mk.value) {
              mz = Torque_Control_B.sf_MATLABFunction1_mk.value;
              rtb_alpha_j = Torque_Control_B.sf_MATLABFunction1_mk.value;
            } else {
              rtb_alpha_j = Torque_Control_B.sf_MATLABFunction2_e.value;
              mz = Torque_Control_B.sf_MATLABFunction2_e.value;
            }

            /* Merge: '<S83>/Merge4' incorporates:
             *  Gain: '<S119>/Gravity1'
             *  Sum: '<S119>/Sum1'
             *  Sum: '<S119>/Sum2'
             */
            Torque_Control_B.Merge4 = ((Torque_Control_B.Merge_b +
              Torque_Control_B.Merge1) + rtb_Sum) * 0.1019367991845056;

            /* Merge: '<S83>/Merge3' incorporates:
             *  MATLAB Function: '<S119>/Force Difference with  Max. Tire Forces'
             *  SignalConversion generated from: '<S119>/Fx_RL '
             */
            Torque_Control_B.Merge3_e = mz;

            /* Merge: '<S83>/Merge2' incorporates:
             *  MATLAB Function: '<S119>/Force Difference with  Max. Tire Forces'
             *  SignalConversion generated from: '<S119>/Fx_RR '
             */
            Torque_Control_B.Merge2_lx = rtb_alpha_j;

            /* Merge: '<S83>/Merge6' incorporates:
             *  MATLAB Function: '<S143>/Kamm_Circle LatD'
             *  SignalConversion generated from: '<S119>/Fy_R [N] (0,inf)'
             */
            Torque_Control_B.Merge6 = rtb_Abs4;
            if (rtmIsMajorTimeStep(Torque_Control_M)) {
            }

            /* Gain: '<S147>/Gain1' */
            Torque_Control_B.Gain1_c = 57.295779513082323 * rtb_Abs1;

            /* Gain: '<S147>/Gain4' incorporates:
             *  MATLAB Function: '<S147>/Bicycle Model'
             */
            Torque_Control_B.Gain4 = 57.295779513082323 * X_idx_0;

            /* Gain: '<S147>/Gain3' incorporates:
             *  MATLAB Function: '<S147>/Bicycle Model'
             */
            Torque_Control_B.Gain3 = 57.295779513082323 * X_idx_1;

            /* Gain: '<S147>/Gain2' incorporates:
             *  MATLAB Function: '<S147>/Bicycle Model'
             */
            Torque_Control_B.Gain2 = 57.295779513082323 * b_idx_0;

            /* Gain: '<S147>/Gain' incorporates:
             *  MATLAB Function: '<S147>/Bicycle Model'
             */
            Torque_Control_B.Gain_p = (X_idx_0 + rtb_value_k) *
              57.295779513082323;
            if (rtmIsMajorTimeStep(Torque_Control_M)) {
              /* Merge: '<S83>/Merge7' incorporates:
               *  Constant: '<S119>/Constant6'
               *  SignalConversion generated from: '<S119>/Flag CarBehavior'
               */
              Torque_Control_B.Merge7 = 1.0;
            }

            /* End of Outputs for SubSystem: '<S83>/Lateral Dynamics' */
          }
          break;
        }

        /* End of If: '<S83>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */

        /* MATLAB Function: '<S125>/MATLAB Function1' incorporates:
         *  Constant: '<S125>/Constant1'
         */
        Torque_Contro_MATLABFunction1_m(0.0, Torque_Control_B.Merge2_lx,
          &Torque_Control_B.sf_MATLABFunction1_m);

        /* Product: '<S171>/Divide' incorporates:
         *  Constant: '<S118>/Transmision Ratio[-]'
         *  Product: '<S171>/Product'
         */
        Torque_Control_B.Divide = Torque_Control_B.sf_MATLABFunction1_m.value *
          Torque_Control_ConstB.udifference1 / 4.0;

        /* MATLAB Function: '<S125>/MATLAB Function2' incorporates:
         *  Constant: '<S125>/Constant'
         */
        Torque_Contro_MATLABFunction1_m(0.0, Torque_Control_B.Merge3_e,
          &Torque_Control_B.sf_MATLABFunction2_k);

        /* Product: '<S170>/Divide' incorporates:
         *  Constant: '<S118>/Transmision Ratio[-]'
         *  Product: '<S170>/Product'
         */
        Torque_Control_B.Divide_i = Torque_Control_B.sf_MATLABFunction2_k.value *
          Torque_Control_ConstB.udifference1 / 4.0;

        /* Sum: '<S125>/Add' */
        rtb_Abs1 = Torque_Control_B.Divide - Torque_Control_B.Divide_i;

        /* MATLAB Function: '<S116>/Accelerator behaviour ' incorporates:
         *  Inport: '<Root>/APPS1_Value'
         *  Inport: '<Root>/VDC_Apps_Sat_Down'
         *  Inport: '<Root>/VDC_Apps_Sat_Up'
         */
        Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
          Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
          &Torque_Control_B.sf_Acceleratorbehaviour);

        /* If: '<S116>/Braking Conditions' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
              (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1) &&
              (Torque_Control_B.Merge1_a == 1.0)) {
            rtAction = 0;
          } else if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
                     (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1) &&
                     (Torque_Control_B.Merge1_a == 0.0)) {
            rtAction = 1;
          } else if ((Torque_Control_U.BrakeSensor_Value < 0.1) &&
                     (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1))
          {
            rtAction = 2;
          } else {
            rtAction = 3;
          }

          Torque_Control_DW.BrakingConditions_ActiveSubsy_b = rtAction;
        } else {
          rtAction = Torque_Control_DW.BrakingConditions_ActiveSubsy_b;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S116>/Regenerative+Mech Braking' incorporates:
           *  ActionPort: '<S140>/Action Port'
           */
          /* MATLAB Function: '<S140>/MATLAB Function' incorporates:
           *  Inport: '<Root>/BrakeSensor_Value'
           */
          if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
            rtb_Abs4 = 0.0;
          } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
            rtb_Abs4 = 1.0;
          } else {
            rtb_Abs4 = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
          }

          /* Merge: '<S116>/Merge1' incorporates:
           *  MATLAB Function: '<S140>/MATLAB Function'
           *  SignalConversion generated from: '<S140>/Tq_RL'
           */
          Torque_Control_B.Merge1_b = rtb_Abs4 * Torque_Control_B.Divide_i;

          /* Merge: '<S116>/Merge' incorporates:
           *  MATLAB Function: '<S140>/MATLAB Function'
           *  SignalConversion generated from: '<S140>/Tq_RR  '
           */
          Torque_Control_B.Merge_kt = rtb_Abs4 * Torque_Control_B.Divide;

          /* End of Outputs for SubSystem: '<S116>/Regenerative+Mech Braking' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S116>/Mech_Braking' incorporates:
           *  ActionPort: '<S139>/Action Port'
           */
          Torque_Control_Mech_Braking(Torque_Control_M,
            &Torque_Control_B.Merge_kt, &Torque_Control_B.Merge1_b);

          /* End of Outputs for SubSystem: '<S116>/Mech_Braking' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S116>/Inertia Braking' incorporates:
           *  ActionPort: '<S138>/Action Port'
           */
          Torque_Control_Mech_Braking(Torque_Control_M,
            &Torque_Control_B.Merge_kt, &Torque_Control_B.Merge1_b);

          /* End of Outputs for SubSystem: '<S116>/Inertia Braking' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S116>/Accelerating' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          /* SignalConversion generated from: '<S136>/Throttle' */
          Torque_Control_B.Throttle =
            Torque_Control_B.sf_Acceleratorbehaviour.throttle;

          /* Merge: '<S116>/Merge1' incorporates:
           *  Product: '<S136>/Product'
           */
          Torque_Control_B.Merge1_b = Torque_Control_B.Throttle *
            Torque_Control_B.Divide_i;

          /* Merge: '<S116>/Merge' incorporates:
           *  Product: '<S136>/Product1'
           */
          Torque_Control_B.Merge_kt = Torque_Control_B.Throttle *
            Torque_Control_B.Divide;

          /* End of Outputs for SubSystem: '<S116>/Accelerating' */
          break;
        }

        /* End of If: '<S116>/Braking Conditions' */

        /* If: '<S115>/If' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          rtAction = (int8_T)((!(Torque_Control_B.Merge1_a == 1.0)) ||
                              (!(Torque_Control_U.BrakeSensor_Value > 0.0)));
          Torque_Control_DW.If_ActiveSubsystem_aq = rtAction;
        } else {
          rtAction = Torque_Control_DW.If_ActiveSubsystem_aq;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S115>/Braking with Regenerative' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          Torque__BrakingwithRegenerative(rtb_TomotorTqRT,
            Torque_Control_B.Merge_kt, Torque_Control_B.Merge1_b, &rtb_Merge1_j,
            &rtb_Merge2, &Torque_Control_B.BrakingwithRegenerative);

          /* End of Outputs for SubSystem: '<S115>/Braking with Regenerative' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S115>/Acelerating and braking without Regenerative' incorporates:
           *  ActionPort: '<S126>/Action Port'
           */
          /* If: '<S126>/If1' incorporates:
           *  Constant: '<S118>/Maximum Transmission Torque Dynamic [Nm]'
           *  Constant: '<S118>/Maximum Transmission Torque Static [Nm]'
           */
          if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
            rtAction = (int8_T)((!(rtb_Abs3 > Torque_Control_ConstB.approx2095_h))
                                || (!(Torque_Control_B.Abs2 >
              Torque_Control_ConstB.approx2095_h)));
            Torque_Control_DW.If1_ActiveSubsystem_bn = rtAction;
          } else {
            rtAction = Torque_Control_DW.If1_ActiveSubsystem_bn;
          }

          switch (rtAction) {
           case 0:
            /* Outputs for IfAction SubSystem: '<S126>/If Action 1' incorporates:
             *  ActionPort: '<S128>/Action Port'
             */
            Torque_Control_IfAction1(Torque_Control_M, 140.0,
              &Torque_Control_B.Merge2_j);

            /* End of Outputs for SubSystem: '<S126>/If Action 1' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S126>/If Action 2' incorporates:
             *  ActionPort: '<S129>/Action Port'
             */
            Torque_Control_IfAction2(Torque_Control_M, 130.0,
              &Torque_Control_B.Merge2_j);

            /* End of Outputs for SubSystem: '<S126>/If Action 2' */
            break;
          }

          /* End of If: '<S126>/If1' */

          /* MATLAB Function: '<S126>/MATLAB Function' incorporates:
           *  Constant: '<S118>/Tq_diff_Max'
           */
          if (rtb_Abs1 < -100.0) {
            rtb_Abs4 = -100.0;
          } else if (rtb_Abs1 > 100.0) {
            rtb_Abs4 = 100.0;
          } else {
            rtb_Abs4 = rtb_Abs1;
          }

          /* End of MATLAB Function: '<S126>/MATLAB Function' */

          /* MATLAB Function: '<S126>/minimum value' incorporates:
           *  Constant: '<S118>/Maximum Torque per engine [Nm]'
           */
          rtb_Abs1 = Torque_Control_B.Merge2_j;
          if (Torque_Control_B.Merge2_j > 120.0) {
            rtb_Abs1 = 120.0;
          }

          if (Torque_Control_B.Merge_kt < rtb_Abs1) {
            rtb_Abs1 = Torque_Control_B.Merge_kt;
          }

          /* End of MATLAB Function: '<S126>/minimum value' */

          /* MATLAB Function: '<S126>/minimum value1' incorporates:
           *  Constant: '<S118>/Maximum Torque per engine [Nm]'
           */
          rtb_value_k = Torque_Control_B.Merge2_j;
          if (Torque_Control_B.Merge2_j > 120.0) {
            rtb_value_k = 120.0;
          }

          if (Torque_Control_B.Merge1_b < rtb_value_k) {
            rtb_value_k = Torque_Control_B.Merge1_b;
          }

          /* End of MATLAB Function: '<S126>/minimum value1' */

          /* MATLAB Function: '<S131>/MATLAB Function' */
          if ((!(rtb_Abs1 == Torque_Control_B.Merge_kt)) || (!(rtb_value_k ==
                Torque_Control_B.Merge1_b))) {
            if (Torque_Control_B.Merge_kt > Torque_Control_B.Merge1_b) {
              rtb_value_k = rtb_Abs1 - fabs(rtb_Abs4);
              if (rtb_value_k < 0.0) {
                rtb_value_k = 0.0;
              }
            } else if (Torque_Control_B.Merge_kt < Torque_Control_B.Merge1_b) {
              rtb_Abs1 = rtb_value_k - fabs(rtb_Abs4);
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = 0.0;
              }
            }
          }

          /* Merge: '<S115>/Merge2' incorporates:
           *  MATLAB Function: '<S131>/MATLAB Function'
           *  SignalConversion generated from: '<S126>/TQ_RL'
           */
          rtb_Merge2 = rtb_value_k;

          /* Merge: '<S115>/Merge1' incorporates:
           *  MATLAB Function: '<S131>/MATLAB Function'
           *  SignalConversion generated from: '<S126>/TQ_RR'
           */
          rtb_Merge1_j = rtb_Abs1;
          if (rtmIsMajorTimeStep(Torque_Control_M)) {
            /* SignalConversion generated from: '<S126>/Flag_Power' */
            Torque_Control_B.OutportBufferForFlag_Power =
              Torque_Control_ConstB.Constant;
          }

          /* End of Outputs for SubSystem: '<S115>/Acelerating and braking without Regenerative' */
          break;
        }

        /* End of If: '<S115>/If' */

        /* Merge: '<S72>/Merge Tq_RR' incorporates:
         *  Constant: '<S118>/Transmision Ratio[-]'
         *  Product: '<S115>/To wheel Tq'
         */
        Torque_Control_B.MergeTq_RR = rtb_Merge1_j * 4.0;

        /* Merge: '<S72>/Merge Tq_RL' incorporates:
         *  Constant: '<S118>/Transmision Ratio[-]'
         *  Product: '<S115>/To wheel Tq1'
         */
        Torque_Control_B.MergeTq_RL = 4.0 * rtb_Merge2;

        /* MATLAB Function: '<S83>/MATLAB Function1' incorporates:
         *  Constant: '<S83>/Constant'
         */
        Torque_Control_MATLABFunction1(0.0, Torque_Control_B.Divide_i,
          &Torque_Control_B.sf_MATLABFunction1_n);

        /* MATLAB Function: '<S83>/MATLAB Function2' incorporates:
         *  Constant: '<S83>/Constant'
         */
        Torque_Control_MATLABFunction1(0.0, Torque_Control_B.Divide,
          &Torque_Control_B.sf_MATLABFunction2);

        /* Merge: '<S72>/Merge3' incorporates:
         *  SignalConversion generated from: '<S83>/CKF_act'
         */
        Torque_Control_B.Merge3_c = Torque_Control_B.Saturation_i;

        /* SignalConversion generated from: '<S83>/Flags_[num5]' */
        Torque_Control_B.OutportBufferForFlags_num5[0] = Torque_Control_B.Merge7;
        Torque_Control_B.OutportBufferForFlags_num5[1] =
          Torque_Control_B.sf_MATLABFunction1_n.value;
        Torque_Control_B.OutportBufferForFlags_num5[2] =
          Torque_Control_B.sf_MATLABFunction2.value;
        Torque_Control_B.OutportBufferForFlags_num5[3] =
          Torque_Control_B.OutportBufferForFlag_Power;

        /* Merge: '<S72>/Merge2' incorporates:
         *  SignalConversion generated from: '<S83>/SKF_act'
         */
        Torque_Control_B.Merge2_l = Torque_Control_B.Saturation_f;

        /* End of Outputs for SubSystem: '<S72>/VDC Complete' */
      }
      break;

     case 1:
      {
        real_T My;
        real_T my;
        real_T tmp_0;
        int32_T r1;
        int32_T r2;

        /* Outputs for IfAction SubSystem: '<S72>/VDC without Longitudinal' incorporates:
         *  ActionPort: '<S84>/Action Port'
         */
        /* MATLAB Function: '<S180>/MATLAB Function' */
        Torque_Control_MATLABFunction_n(Torque_Control_B.Abs2, rtb_Abs3,
          &Torque_Control_B.sf_MATLABFunction_fa);

        /* Derivative: '<S180>/Derivative' */
        k = Torque_Control_M->Timing.t[0];
        if ((Torque_Control_DW.TimeStampA_b >= k) &&
            (Torque_Control_DW.TimeStampB_e >= k)) {
          rtb_Abs1 = 0.0;
        } else {
          p = Torque_Control_DW.TimeStampA_b;
          lastU = &Torque_Control_DW.LastUAtTimeA_e;
          if (Torque_Control_DW.TimeStampA_b < Torque_Control_DW.TimeStampB_e) {
            if (Torque_Control_DW.TimeStampB_e < k) {
              p = Torque_Control_DW.TimeStampB_e;
              lastU = &Torque_Control_DW.LastUAtTimeB_o;
            }
          } else if (Torque_Control_DW.TimeStampA_b >= k) {
            p = Torque_Control_DW.TimeStampB_e;
            lastU = &Torque_Control_DW.LastUAtTimeB_o;
          }

          rtb_Abs1 = (Torque_Control_B.sf_MATLABFunction_fa.RPM - *lastU) / (k -
            p);
        }

        /* End of Derivative: '<S180>/Derivative' */

        /* If: '<S206>/If1' */
        rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          if (rtb_Abs1 >= 900.0) {
            rtAction = 0;
          } else if (rtb_Abs1 < 900.0) {
            rtAction = 1;
          }

          Torque_Control_DW.If1_ActiveSubsystem_a = rtAction;
        } else {
          rtAction = Torque_Control_DW.If1_ActiveSubsystem_a;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S206>/Spin ' incorporates:
           *  ActionPort: '<S208>/Action Port'
           */
          /* Switch: '<S208>/Switch1' incorporates:
           *  DataStoreRead: '<S180>/CKF_prev'
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          if (Torque_Control_DW.B_k > 0.0) {
            p = Torque_Control_DW.B_k;
          } else {
            p = Torque_Control_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S208>/Switch1' */

          /* Switch: '<S208>/Switch' incorporates:
           *  Constant: '<S208>/Constant'
           *  Inport: '<Root>/VDC_Cte_SKF'
           */
          if (Torque_Control_U.VDC_Cte_SKF >= 0.9) {
            tmp_0 = Torque_Control_U.VDC_Cte_SKF;
          } else {
            tmp_0 = 1.0;
          }

          /* End of Switch: '<S208>/Switch' */

          /* Product: '<S208>/Product' */
          rtb_Product_iv = p * tmp_0;

          /* MATLAB Function: '<S208>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          Torque_Control_MATLABFunction_m(Torque_Control_U.VDC_CKF_Initial,
            rtb_Product_iv, &Torque_Control_B.sf_MATLABFunction_i);

          /* Merge: '<S206>/Merge' incorporates:
           *  SignalConversion generated from: '<S208>/CKF_act1 '
           */
          Torque_Control_B.Merge_g =
            Torque_Control_B.sf_MATLABFunction_i.CKF_act1;

          /* End of Outputs for SubSystem: '<S206>/Spin ' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S206>/No spin' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          /* Switch: '<S207>/Switch1' incorporates:
           *  DataStoreRead: '<S180>/CKF_prev'
           */
          if (Torque_Control_DW.B_k > 0.0) {
            /* Switch: '<S207>/Switch1' */
            rtb_Switch1 = Torque_Control_DW.B_k;
          } else {
            /* Switch: '<S207>/Switch1' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             */
            rtb_Switch1 = Torque_Control_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S207>/Switch1' */

          /* MATLAB Function: '<S207>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           *  Inport: '<Root>/VDC_Cte_SKF'
           */
          Torque_Contro_MATLABFunction1_b(rtb_Switch1,
            Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_SKF,
            &Torque_Control_B.sf_MATLABFunction_a);

          /* Merge: '<S206>/Merge' incorporates:
           *  SignalConversion generated from: '<S207>/CKF_act0'
           */
          Torque_Control_B.Merge_g =
            Torque_Control_B.sf_MATLABFunction_a.CKF_act0;

          /* End of Outputs for SubSystem: '<S206>/No spin' */
          break;
        }

        /* End of If: '<S206>/If1' */

        /* Saturate: '<S206>/Saturation' */
        if (Torque_Control_B.Merge_g > 1.0) {
          rtb_Abs1 = 1.0;
        } else if (Torque_Control_B.Merge_g < 0.3) {
          rtb_Abs1 = 0.3;
        } else {
          rtb_Abs1 = Torque_Control_B.Merge_g;
        }

        /* End of Saturate: '<S206>/Saturation' */

        /* DataStoreWrite: '<S180>/Data Store Write1' */
        Torque_Control_DW.B_k = rtb_Abs1;

        /* Gain: '<S179>/Fy per wheel' incorporates:
         *  Gain: '<S179>/Gravity1'
         *  Product: '<S179>/Product'
         *  Sum: '<S179>/Sum1'
         */
        rtb_Abs4 = (Torque_Control_B.Merge2 + Torque_Control_B.Merge3_b) *
          0.1019367991845056 * rtb_Abs4 * 0.5;

        /* MATLAB Function: '<S178>/Kamm_Circle LatD' */
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
          if (rtb_Abs4 > p) {
            my = k;
          } else if (rtb_Abs4 < p) {
            My = k;
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_Abs4) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == rtb_Abs4) {
            p = 1.0;
            My = my;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_Abs4) {
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
          rtb_alpha_j = b_a[0] * rtb_Abs4 + b_a[1];
        } else if ((Mz != mz) && (My == my)) {
          kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
          kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
          kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)mz];
          kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
          rtb_alpha_j = b_a[0] * Torque_Control_B.Merge2 + b_a[1];
        } else if ((Mz == mz) && (My == my)) {
          rtb_alpha_j = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
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
          tmp_0 = Torque_Control_B.kamm_data[17 * (int32_T)My];
          tmp[9] = tmp_0;
          tmp[10] = p;
          tmp[11] = tmp_0;
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)mz];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)mz];
          kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)Mz];
          mldivide_8ZFDevWm(tmp, kamm_data_1, a);
          rtb_alpha_j = (a[1] * Torque_Control_B.Merge2 + a[0]) + a[2] *
            rtb_Abs4;
        }

        mz = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          p = Torque_Control_B.kamm_data[(int32_T)k];
          if (Torque_Control_B.Merge3_b > p) {
            mz = k;
          } else if (Torque_Control_B.Merge3_b < p) {
            Mz = k;
          }

          k = floor((Mz + mz) / 2.0);
          p = Mz - mz;
          if (Torque_Control_B.Merge3_b == Torque_Control_B.kamm_data[(int32_T)
              Mz]) {
            p = 1.0;
            mz = Mz;
          } else if (Torque_Control_B.Merge3_b == Torque_Control_B.kamm_data
                     [(int32_T)mz]) {
            p = 1.0;
            Mz = mz;
          } else if (Torque_Control_B.Merge3_b == Torque_Control_B.kamm_data
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
          if (rtb_Abs4 > p) {
            my = k;
          } else if (rtb_Abs4 < p) {
            My = k;
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_Abs4) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == rtb_Abs4) {
            p = 1.0;
            My = my;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_Abs4) {
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
          mz = b_a[0] * rtb_Abs4 + b_a[1];
        } else if ((Mz != mz) && (My == my)) {
          kamm_data[0] = Torque_Control_B.kamm_data[(int32_T)mz];
          kamm_data[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
          kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)mz];
          kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_qSahpz3o(kamm_data, kamm_data_0, b_a);
          mz = b_a[0] * Torque_Control_B.Merge3_b + b_a[1];
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
          tmp_0 = Torque_Control_B.kamm_data[17 * (int32_T)My];
          tmp[9] = tmp_0;
          tmp[10] = p;
          tmp[11] = tmp_0;
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)mz];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)mz];
          kamm_data_1[2] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          kamm_data_1[3] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)Mz];
          mldivide_8ZFDevWm(tmp, kamm_data_1, a);
          mz = (a[1] * Torque_Control_B.Merge3_b + a[0]) + a[2] * rtb_Abs4;
        }

        /* Product: '<S178>/Product' incorporates:
         *  MATLAB Function: '<S178>/Kamm_Circle LatD'
         */
        rtb_Product_c = rtb_alpha_j * rtb_Abs1;

        /* MATLAB Function: '<S178>/MATLAB Function2' incorporates:
         *  Constant: '<S178>/Constant1'
         */
        Torque_Control_MATLABFunction_d(-1.0, rtb_Product_c,
          &Torque_Control_B.sf_MATLABFunction2_b);

        /* MATLAB Function: '<S176>/MATLAB Function2' incorporates:
         *  Constant: '<S176>/Constant'
         */
        Torque_Control_MATLABFunction_d(0.0,
          Torque_Control_B.sf_MATLABFunction2_b.value,
          &Torque_Control_B.sf_MATLABFunction2_m);

        /* Product: '<S178>/Product1' incorporates:
         *  MATLAB Function: '<S178>/Kamm_Circle LatD'
         */
        rtb_Product1 = mz * rtb_Abs1;

        /* MATLAB Function: '<S178>/MATLAB Function1' incorporates:
         *  Constant: '<S178>/Constant'
         */
        Torque_Control_MATLABFunction_d(-1.0, rtb_Product1,
          &Torque_Control_B.sf_MATLABFunction1_f);

        /* MATLAB Function: '<S176>/MATLAB Function1' incorporates:
         *  Constant: '<S176>/Constant1'
         */
        Torque_Control_MATLABFunction_d(0.0,
          Torque_Control_B.sf_MATLABFunction1_f.value,
          &Torque_Control_B.sf_MATLABFunction1_gm);

        /* If: '<S175>/Braking Conditions' incorporates:
         *  Inport: '<Root>/APPS1_Value'
         *  Inport: '<Root>/BrakeSensor_Value'
         *  Inport: '<Root>/VDC_Apps_Sat_Down'
         */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
              (Torque_Control_U.APPS1_Value <=
               Torque_Control_U.VDC_Apps_Sat_Down) && (Torque_Control_B.Merge1_a
               == 1.0)) {
            rtAction = 0;
          } else if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
                     (Torque_Control_U.APPS1_Value <=
                      Torque_Control_U.VDC_Apps_Sat_Down) &&
                     (Torque_Control_B.Merge1_a == 0.0)) {
            rtAction = 1;
          } else if ((Torque_Control_U.BrakeSensor_Value == 0.0) &&
                     (Torque_Control_U.APPS1_Value == 0.0)) {
            rtAction = 2;
          } else {
            rtAction = 3;
          }

          Torque_Control_DW.BrakingConditions_ActiveSubsy_c = rtAction;
        } else {
          rtAction = Torque_Control_DW.BrakingConditions_ActiveSubsy_c;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S175>/Regenerative+Mech Braking' incorporates:
           *  ActionPort: '<S194>/Action Port'
           */
          /* MATLAB Function: '<S194>/MATLAB Function' incorporates:
           *  Inport: '<Root>/BrakeSensor_Value'
           */
          if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
            rtb_Abs4 = 0.0;
          } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
            rtb_Abs4 = 1.0;
          } else {
            rtb_Abs4 = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
          }

          /* Merge: '<S175>/Merge1' incorporates:
           *  MATLAB Function: '<S194>/MATLAB Function'
           *  Product: '<S197>/Product'
           *  SignalConversion generated from: '<S194>/Tq_RL'
           */
          Torque_Control_B.Merge1_l =
            Torque_Control_B.sf_MATLABFunction1_gm.value *
            Torque_Control_ConstB.udifference * rtb_Abs4;

          /* Merge: '<S175>/Merge' incorporates:
           *  MATLAB Function: '<S194>/MATLAB Function'
           *  Product: '<S198>/Product'
           *  SignalConversion generated from: '<S194>/Tq_RR  '
           */
          Torque_Control_B.Merge_li =
            Torque_Control_B.sf_MATLABFunction2_m.value *
            Torque_Control_ConstB.udifference * rtb_Abs4;

          /* End of Outputs for SubSystem: '<S175>/Regenerative+Mech Braking' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S175>/Mech_Braking' incorporates:
           *  ActionPort: '<S193>/Action Port'
           */
          Torque_Control_Mech_Braking(Torque_Control_M,
            &Torque_Control_B.Merge_li, &Torque_Control_B.Merge1_l);

          /* End of Outputs for SubSystem: '<S175>/Mech_Braking' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S175>/Inertia Braking' incorporates:
           *  ActionPort: '<S192>/Action Port'
           */
          Torque_Control_Mech_Braking(Torque_Control_M,
            &Torque_Control_B.Merge_li, &Torque_Control_B.Merge1_l);

          /* End of Outputs for SubSystem: '<S175>/Inertia Braking' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S175>/Accelerating' incorporates:
           *  ActionPort: '<S191>/Action Port'
           */
          /* MATLAB Function: '<S191>/Accelerator behaviour ' incorporates:
           *  Inport: '<Root>/APPS1_Value'
           *  Inport: '<Root>/VDC_Apps_Sat_Down'
           *  Inport: '<Root>/VDC_Apps_Sat_Up'
           */
          Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
            Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
            &Torque_Control_B.sf_Acceleratorbehaviour_b);

          /* Merge: '<S175>/Merge1' incorporates:
           *  Product: '<S191>/Product'
           *  Product: '<S197>/Product'
           */
          Torque_Control_B.Merge1_l =
            Torque_Control_B.sf_MATLABFunction1_gm.value *
            Torque_Control_ConstB.udifference *
            Torque_Control_B.sf_Acceleratorbehaviour_b.throttle;

          /* Merge: '<S175>/Merge' incorporates:
           *  Product: '<S191>/Product1'
           *  Product: '<S198>/Product'
           */
          Torque_Control_B.Merge_li =
            Torque_Control_B.sf_MATLABFunction2_m.value *
            Torque_Control_ConstB.udifference *
            Torque_Control_B.sf_Acceleratorbehaviour_b.throttle;

          /* End of Outputs for SubSystem: '<S175>/Accelerating' */
          break;
        }

        /* End of If: '<S175>/Braking Conditions' */

        /* If: '<S174>/If' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          rtAction = (int8_T)((!(Torque_Control_B.Merge1_a == 1.0)) ||
                              (!(Torque_Control_U.BrakeSensor_Value > 0.0)));
          Torque_Control_DW.If_ActiveSubsystem_h = rtAction;
        } else {
          rtAction = Torque_Control_DW.If_ActiveSubsystem_h;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S174>/Braking with Regenerative' incorporates:
           *  ActionPort: '<S183>/Action Port'
           */
          Torque__BrakingwithRegenerative(rtb_TransmissionGearRatio,
            Torque_Control_B.Merge_li, Torque_Control_B.Merge1_l,
            &Torque_Control_B.MergeTq_RR, &Torque_Control_B.MergeTq_RL,
            &Torque_Control_B.BrakingwithRegenerative_b);

          /* End of Outputs for SubSystem: '<S174>/Braking with Regenerative' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S174>/Acelerating and braking without Regenerative' incorporates:
           *  ActionPort: '<S182>/Action Port'
           */
          /* If: '<S182>/If1' */
          if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
            rtAction = (int8_T)((!(rtb_Abs3 > Torque_Control_ConstB.approx2095))
                                || (!(Torque_Control_B.Abs2 >
              Torque_Control_ConstB.approx2095)));
            Torque_Control_DW.If1_ActiveSubsystem_b = rtAction;
          } else {
            rtAction = Torque_Control_DW.If1_ActiveSubsystem_b;
          }

          switch (rtAction) {
           case 0:
            /* Outputs for IfAction SubSystem: '<S182>/If Action 1' incorporates:
             *  ActionPort: '<S184>/Action Port'
             */
            Torque_Control_IfAction1(Torque_Control_M,
              Torque_Control_ConstB.TowheelTqdynamic, &Torque_Control_B.Merge2_o);

            /* End of Outputs for SubSystem: '<S182>/If Action 1' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S182>/If Action 2' incorporates:
             *  ActionPort: '<S185>/Action Port'
             */
            Torque_Control_IfAction2(Torque_Control_M,
              Torque_Control_ConstB.TowheelTqstatic, &Torque_Control_B.Merge2_o);

            /* End of Outputs for SubSystem: '<S182>/If Action 2' */
            break;
          }

          /* End of If: '<S182>/If1' */

          /* MATLAB Function: '<S182>/minimum value' */
          rtb_Abs4 = Torque_Control_B.Merge2_o;
          if (Torque_Control_ConstB.Product < Torque_Control_B.Merge2_o) {
            rtb_Abs4 = Torque_Control_ConstB.Product;
          }

          if (Torque_Control_B.Merge_li < rtb_Abs4) {
            rtb_Abs4 = Torque_Control_B.Merge_li;
          }

          /* End of MATLAB Function: '<S182>/minimum value' */

          /* MATLAB Function: '<S182>/minimum value1' */
          rtb_value_k = Torque_Control_B.Merge2_o;
          if (Torque_Control_ConstB.Product < Torque_Control_B.Merge2_o) {
            rtb_value_k = Torque_Control_ConstB.Product;
          }

          if (Torque_Control_B.Merge1_l < rtb_value_k) {
            rtb_value_k = Torque_Control_B.Merge1_l;
          }

          /* End of MATLAB Function: '<S182>/minimum value1' */

          /* MATLAB Function: '<S186>/MATLAB Function' */
          if ((rtb_Abs4 == Torque_Control_B.Merge_li) && (rtb_value_k ==
               Torque_Control_B.Merge1_l)) {
            /* Merge: '<S72>/Merge Tq_RR' */
            Torque_Control_B.MergeTq_RR = rtb_Abs4;

            /* Merge: '<S72>/Merge Tq_RL' */
            Torque_Control_B.MergeTq_RL = rtb_value_k;
          } else if (Torque_Control_B.Merge_li > Torque_Control_B.Merge1_l) {
            /* Merge: '<S72>/Merge Tq_RR' */
            Torque_Control_B.MergeTq_RR = rtb_Abs4;

            /* Merge: '<S72>/Merge Tq_RL' */
            Torque_Control_B.MergeTq_RL = Torque_Control_B.Merge1_l /
              Torque_Control_B.Merge_li * rtb_Abs4;
          } else if (Torque_Control_B.Merge_li < Torque_Control_B.Merge1_l) {
            /* Merge: '<S72>/Merge Tq_RR' */
            Torque_Control_B.MergeTq_RR = Torque_Control_B.Merge_li /
              Torque_Control_B.Merge1_l * rtb_value_k;

            /* Merge: '<S72>/Merge Tq_RL' */
            Torque_Control_B.MergeTq_RL = rtb_value_k;
          } else {
            /* Merge: '<S72>/Merge Tq_RR' */
            Torque_Control_B.MergeTq_RR = rtb_Abs4;

            /* Merge: '<S72>/Merge Tq_RL' */
            Torque_Control_B.MergeTq_RL = rtb_value_k;
          }

          /* End of MATLAB Function: '<S186>/MATLAB Function' */
          /* End of Outputs for SubSystem: '<S174>/Acelerating and braking without Regenerative' */
          break;
        }

        /* End of If: '<S174>/If' */

        /* Merge: '<S72>/Merge3' incorporates:
         *  SignalConversion generated from: '<S84>/CKF_act'
         */
        Torque_Control_B.Merge3_c = rtb_Abs1;

        /* End of Outputs for SubSystem: '<S72>/VDC without Longitudinal' */
      }
      break;

     case 2:
      {
        /* Outputs for IfAction SubSystem: '<S72>/Steering TV with TC' incorporates:
         *  ActionPort: '<S82>/Action Port'
         */
        /* MATLAB Function: '<S103>/MATLAB Function1' incorporates:
         *  Constant: '<S103>/Steering Wheel Maximum Angle'
         */
        if ((Torque_Control_B.Gain_n > 100.0) || (Torque_Control_B.Gain_n <
             -100.0)) {
          rtb_Abs1 = 100.0;
        } else {
          rtb_Abs1 = Torque_Control_B.Gain_n;
        }

        /* End of MATLAB Function: '<S103>/MATLAB Function1' */

        /* MATLAB Function: '<S93>/MATLAB Function' */
        Torque_Control_MATLABFunction_n(Torque_Control_B.Abs2, rtb_Abs3,
          &Torque_Control_B.sf_MATLABFunction_ab);

        /* Derivative: '<S93>/Derivative' incorporates:
         *  SignalGenerator: '<S93>/Signal Generator'
         */
        k = Torque_Control_M->Timing.t[0];
        if ((Torque_Control_DW.TimeStampA >= k) && (Torque_Control_DW.TimeStampB
             >= k)) {
          rtb_Abs4 = 0.0;
        } else {
          p = Torque_Control_DW.TimeStampA;
          lastU = &Torque_Control_DW.LastUAtTimeA;
          if (Torque_Control_DW.TimeStampA < Torque_Control_DW.TimeStampB) {
            if (Torque_Control_DW.TimeStampB < k) {
              p = Torque_Control_DW.TimeStampB;
              lastU = &Torque_Control_DW.LastUAtTimeB;
            }
          } else if (Torque_Control_DW.TimeStampA >= k) {
            p = Torque_Control_DW.TimeStampB;
            lastU = &Torque_Control_DW.LastUAtTimeB;
          }

          rtb_Abs4 = (Torque_Control_B.sf_MATLABFunction_ab.RPM - *lastU) / (k -
            p);
        }

        /* End of Derivative: '<S93>/Derivative' */

        /* If: '<S103>/SKF or CKF' */
        rtPrevAction = Torque_Control_DW.SKForCKF_ActiveSubsystem;
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          rtAction = (int8_T)((!(rtb_Abs1 > -10.0)) || (!(rtb_Abs1 < 10.0)));
          Torque_Control_DW.SKForCKF_ActiveSubsystem = rtAction;
        } else {
          rtAction = Torque_Control_DW.SKForCKF_ActiveSubsystem;
        }

        if ((rtPrevAction != rtAction) && (rtPrevAction == 1)) {
          /* Disable for If: '<S104>/If1' */
          Torque_Control_DW.If1_ActiveSubsystem_ca = -1;
        }

        switch (rtAction) {
         case 0:
          {
            /* Outputs for IfAction SubSystem: '<S103>/SKF' incorporates:
             *  ActionPort: '<S106>/Action Port'
             */
            /* If: '<S106>/If' */
            rtAction = -1;
            if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
              if (rtb_Abs4 >= 900.0) {
                rtAction = 0;
              } else if (rtb_Abs4 < 900.0) {
                rtAction = 1;
              }

              Torque_Control_DW.If_ActiveSubsystem_jm = rtAction;
            } else {
              rtAction = Torque_Control_DW.If_ActiveSubsystem_jm;
            }

            switch (rtAction) {
             case 0:
              {
                real_T tmp_0;

                /* Outputs for IfAction SubSystem: '<S106>/Spin' incorporates:
                 *  ActionPort: '<S112>/Action Port'
                 */
                /* Switch: '<S112>/Switch1' incorporates:
                 *  DataStoreRead: '<S93>/SKF_prev '
                 *  Inport: '<Root>/VDC_SKF_Initial'
                 */
                if (Torque_Control_DW.A > 0.0) {
                  p = Torque_Control_DW.A;
                } else {
                  p = Torque_Control_U.VDC_SKF_Initial;
                }

                /* End of Switch: '<S112>/Switch1' */

                /* Switch: '<S112>/Switch' incorporates:
                 *  Constant: '<S112>/Constant'
                 *  Inport: '<Root>/VDC_Cte_CKF'
                 */
                if (Torque_Control_U.VDC_Cte_CKF >= 0.9) {
                  tmp_0 = Torque_Control_U.VDC_Cte_CKF;
                } else {
                  tmp_0 = 1.0;
                }

                /* End of Switch: '<S112>/Switch' */

                /* Product: '<S112>/Product' */
                rtb_Abs1 = p * tmp_0;

                /* MATLAB Function: '<S112>/MATLAB Function' incorporates:
                 *  Inport: '<Root>/VDC_SKF_Initial'
                 */
                if (rtb_Abs1 < Torque_Control_U.VDC_SKF_Initial) {
                  /* Merge: '<S106>/Merge' incorporates:
                   *  SignalConversion generated from: '<S112>/SKF_act1'
                   */
                  Torque_Control_B.Merge_kj = rtb_Abs1;
                } else {
                  /* Merge: '<S106>/Merge' incorporates:
                   *  SignalConversion generated from: '<S112>/SKF_act1'
                   */
                  Torque_Control_B.Merge_kj = Torque_Control_U.VDC_SKF_Initial;
                }

                /* End of MATLAB Function: '<S112>/MATLAB Function' */
                /* End of Outputs for SubSystem: '<S106>/Spin' */
              }
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S106>/No spin' incorporates:
               *  ActionPort: '<S111>/Action Port'
               */
              /* Switch: '<S111>/Switch' incorporates:
               *  DataStoreRead: '<S93>/SKF_prev '
               */
              if (Torque_Control_DW.A > 0.0) {
                /* Switch: '<S111>/Switch' */
                rtb_Switch_b = Torque_Control_DW.A;
              } else {
                /* Switch: '<S111>/Switch' incorporates:
                 *  Inport: '<Root>/VDC_SKF_Initial'
                 */
                rtb_Switch_b = Torque_Control_U.VDC_SKF_Initial;
              }

              /* End of Switch: '<S111>/Switch' */

              /* MATLAB Function: '<S111>/MATLAB Function' incorporates:
               *  Inport: '<Root>/VDC_Cte_CKF'
               *  Inport: '<Root>/VDC_SKF_Initial'
               */
              Torque_Control_MATLABFunction_e(rtb_Switch_b,
                Torque_Control_U.VDC_SKF_Initial, Torque_Control_U.VDC_Cte_CKF,
                &Torque_Control_B.sf_MATLABFunction_fq);

              /* Merge: '<S106>/Merge' incorporates:
               *  SignalConversion generated from: '<S111>/SKF_act0'
               */
              Torque_Control_B.Merge_kj =
                Torque_Control_B.sf_MATLABFunction_fq.SKF_act0;

              /* End of Outputs for SubSystem: '<S106>/No spin' */
              break;
            }

            /* End of If: '<S106>/If' */

            /* Saturate: '<S106>/Saturation' */
            if (Torque_Control_B.Merge_kj > 1.0) {
              /* Saturate: '<S106>/Saturation' */
              Torque_Control_B.Saturation_k = 1.0;
            } else if (Torque_Control_B.Merge_kj < 0.3) {
              /* Saturate: '<S106>/Saturation' */
              Torque_Control_B.Saturation_k = 0.3;
            } else {
              /* Saturate: '<S106>/Saturation' */
              Torque_Control_B.Saturation_k = Torque_Control_B.Merge_kj;
            }

            /* End of Saturate: '<S106>/Saturation' */
            /* End of Outputs for SubSystem: '<S103>/SKF' */
          }
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S103>/CKF' incorporates:
           *  ActionPort: '<S104>/Action Port'
           */
          /* If: '<S104>/If1' */
          rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
            if (rtb_Abs4 >= 900.0) {
              rtAction = 0;
            } else if (rtb_Abs4 < 900.0) {
              rtAction = 1;
            }

            Torque_Control_DW.If1_ActiveSubsystem_ca = rtAction;
          } else {
            rtAction = Torque_Control_DW.If1_ActiveSubsystem_ca;
          }

          switch (rtAction) {
           case 0:
            /* Outputs for IfAction SubSystem: '<S104>/Spin ' incorporates:
             *  ActionPort: '<S108>/Action Port'
             */
            /* Switch: '<S108>/Switch1' incorporates:
             *  DataStoreRead: '<S93>/CKF_prev'
             */
            if (Torque_Control_DW.B > 0.0) {
              /* Switch: '<S108>/Switch1' */
              Torque_Control_B.Switch1 = Torque_Control_DW.B;
            } else {
              /* Switch: '<S108>/Switch1' incorporates:
               *  Inport: '<Root>/VDC_CKF_Initial'
               */
              Torque_Control_B.Switch1 = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of Switch: '<S108>/Switch1' */
            if (rtmIsMajorTimeStep(Torque_Control_M)) {
            }

            /* Switch: '<S108>/Switch' incorporates:
             *  Constant: '<S108>/Constant'
             *  Inport: '<Root>/VDC_Cte_SKF'
             */
            if (Torque_Control_U.VDC_Cte_SKF >= 0.9) {
              p = Torque_Control_U.VDC_Cte_SKF;
            } else {
              p = 1.0;
            }

            /* End of Switch: '<S108>/Switch' */

            /* Product: '<S108>/Product' */
            rtb_Abs1 = Torque_Control_B.Switch1 * p;

            /* MATLAB Function: '<S108>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             */
            if (rtb_Abs1 < Torque_Control_U.VDC_CKF_Initial) {
              /* Merge: '<S104>/Merge' incorporates:
               *  SignalConversion generated from: '<S108>/CKF_act1 '
               */
              Torque_Control_B.Merge_k = rtb_Abs1;
            } else {
              /* Merge: '<S104>/Merge' incorporates:
               *  SignalConversion generated from: '<S108>/CKF_act1 '
               */
              Torque_Control_B.Merge_k = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of MATLAB Function: '<S108>/MATLAB Function' */
            /* End of Outputs for SubSystem: '<S104>/Spin ' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S104>/No spin' incorporates:
             *  ActionPort: '<S107>/Action Port'
             */
            /* Switch: '<S107>/Switch' incorporates:
             *  DataStoreRead: '<S93>/CKF_prev'
             */
            if (Torque_Control_DW.B > 0.0) {
              /* Switch: '<S107>/Switch' */
              rtb_Switch = Torque_Control_DW.B;
            } else {
              /* Switch: '<S107>/Switch' incorporates:
               *  Inport: '<Root>/VDC_CKF_Initial'
               */
              rtb_Switch = Torque_Control_U.VDC_CKF_Initial;
            }

            /* End of Switch: '<S107>/Switch' */

            /* MATLAB Function: '<S107>/MATLAB Function' incorporates:
             *  Inport: '<Root>/VDC_CKF_Initial'
             *  Inport: '<Root>/VDC_Cte_SKF'
             */
            Torque_Contro_MATLABFunction1_b(rtb_Switch,
              Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_SKF,
              &Torque_Control_B.sf_MATLABFunction_k2);

            /* Merge: '<S104>/Merge' incorporates:
             *  SignalConversion generated from: '<S107>/CKF_act0'
             */
            Torque_Control_B.Merge_k =
              Torque_Control_B.sf_MATLABFunction_k2.CKF_act0;

            /* End of Outputs for SubSystem: '<S104>/No spin' */
            break;
          }

          /* End of If: '<S104>/If1' */

          /* Saturate: '<S104>/Saturation' */
          if (Torque_Control_B.Merge_k > 1.0) {
            /* Saturate: '<S104>/Saturation' */
            Torque_Control_B.Saturation_c = 1.0;
          } else if (Torque_Control_B.Merge_k < 0.3) {
            /* Saturate: '<S104>/Saturation' */
            Torque_Control_B.Saturation_c = 0.3;
          } else {
            /* Saturate: '<S104>/Saturation' */
            Torque_Control_B.Saturation_c = Torque_Control_B.Merge_k;
          }

          /* End of Saturate: '<S104>/Saturation' */
          /* End of Outputs for SubSystem: '<S103>/CKF' */
          break;
        }

        /* End of If: '<S103>/SKF or CKF' */

        /* DataStoreWrite: '<S93>/Data Store Write' */
        Torque_Control_DW.A = Torque_Control_B.Saturation_k;

        /* DataStoreWrite: '<S93>/Data Store Write1' */
        Torque_Control_DW.B = Torque_Control_B.Saturation_c;

        /* Saturate: '<S93>/Saturation' */
        if (rtb_Abs4 > 6000.0) {
          /* Saturate: '<S93>/Saturation' */
          Torque_Control_B.Saturation = 6000.0;
        } else if (rtb_Abs4 < 0.0) {
          /* Saturate: '<S93>/Saturation' */
          Torque_Control_B.Saturation = 0.0;
        } else {
          /* Saturate: '<S93>/Saturation' */
          Torque_Control_B.Saturation = rtb_Abs4;
        }

        /* End of Saturate: '<S93>/Saturation' */

        /* Switch: '<S93>/Switch' */
        if (rtb_Abs4 >= 900.0) {
          /* Switch: '<S93>/Switch' */
          Torque_Control_B.Switch = rtb_Abs4;
        } else {
          /* Switch: '<S93>/Switch' incorporates:
           *  Constant: '<S93>/Constant'
           */
          Torque_Control_B.Switch = 0.0;
        }

        /* End of Switch: '<S93>/Switch' */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
        }

        /* SignalGenerator: '<S93>/Signal Generator' */
        rtb_Abs4 = 0.15915494309189535 * k;
        if (rtb_Abs4 - floor(rtb_Abs4) >= 0.5) {
          /* SignalGenerator: '<S93>/Signal Generator' */
          Torque_Control_B.SignalGenerator = 1.0;
        } else {
          /* SignalGenerator: '<S93>/Signal Generator' */
          Torque_Control_B.SignalGenerator = -1.0;
        }

        if (rtmIsMajorTimeStep(Torque_Control_M)) {
        }

        /* Sin: '<S93>/Sine Wave' */
        Torque_Control_B.SineWave = sin(Torque_Control_M->Timing.t[0]);
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
        }

        /* MATLAB Function: '<S82>/Accelerator behaviour' incorporates:
         *  Inport: '<Root>/APPS1_Value'
         *  Inport: '<Root>/VDC_Apps_Sat_Down'
         *  Inport: '<Root>/VDC_Apps_Sat_Up'
         */
        Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
          Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
          &Torque_Control_B.sf_Acceleratorbehaviour_br);

        /* MATLAB Function: '<S82>/MATLAB Function1' incorporates:
         *  Constant: '<S82>/Steering Wheel Maximum Angle'
         */
        if (Torque_Control_B.Gain_n > 140.0) {
          rtb_Abs4 = 140.0;
        } else if (Torque_Control_B.Gain_n < -140.0) {
          rtb_Abs4 = -140.0;
        } else {
          rtb_Abs4 = Torque_Control_B.Gain_n;
        }

        /* End of MATLAB Function: '<S82>/MATLAB Function1' */

        /* MATLAB Function: '<S82>/Steering TV 2017 (without TC)' incorporates:
         *  Constant: '<S72>/Steering Wheel Saturation (per site) [deg] '
         *  Constant: '<S82>/Steering Wheel Maximum Angle'
         *  Constant: '<S82>/Tq_diff_max [Nm]'
         *  Constant: '<S82>/Tq_max_motor [Nm]'
         */
        rtb_Abs1 = 0.0;
        k = 0.0;
        if ((rtb_Abs4 >= -10.0) && (rtb_Abs4 <= 10.0)) {
          rtb_Abs1 = 120.0;
          k = 120.0;
        } else if (rtb_Abs4 > 10.0) {
          rtb_Abs1 = 120.0;
          k = 120.0 - (rtb_Abs4 - 10.0) * 0.76923076923076927;
        } else if (rtb_Abs4 < -10.0) {
          k = 120.0;
          rtb_Abs1 = 120.0 - (fabs(rtb_Abs4) - 10.0) * 0.76923076923076927;
        }

        /* End of MATLAB Function: '<S82>/Steering TV 2017 (without TC)' */

        /* If: '<S82>/If1' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          rtAction = (int8_T)((!(Torque_Control_U.BrakeSensor_Value > 0.2)) || (
            !(Torque_Control_B.sf_Acceleratorbehaviour_br.throttle <= 0.0)) || (
            !(Torque_Control_B.Merge1_a == 1.0)));
          Torque_Control_DW.If1_ActiveSubsystem_c = rtAction;
        } else {
          rtAction = Torque_Control_DW.If1_ActiveSubsystem_c;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S82>/Regenerating' incorporates:
           *  ActionPort: '<S94>/Action Port'
           */
          /* SignalConversion generated from: '<S94>/Tq_RR_calculated' */
          mz = rtb_Abs1;

          /* SignalConversion generated from: '<S94>/Tq_RL_calculated' */
          Mz = k;

          /* End of Outputs for SubSystem: '<S82>/Regenerating' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S82>/Accelerating, Inertia or Braking without Regen' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          /* SignalConversion generated from: '<S88>/Tq_RR_calculated' */
          Mz = rtb_Abs1;

          /* SignalConversion generated from: '<S88>/Tq_RL_calculated' */
          mz = k;

          /* End of Outputs for SubSystem: '<S82>/Accelerating, Inertia or Braking without Regen' */
          break;
        }

        /* End of If: '<S82>/If1' */

        /* If: '<S82>/If' incorporates:
         *  Constant: '<S72>/Steering Wheel Saturation (per site) [deg] '
         */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          rtAction = (int8_T)((!(rtb_Abs4 >= -10.0)) || (!(rtb_Abs4 <= 10.0)));
          Torque_Control_DW.If_ActiveSubsystem_d = rtAction;
        } else {
          rtAction = Torque_Control_DW.If_ActiveSubsystem_d;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S82>/Longitudinal Dynamics' incorporates:
           *  ActionPort: '<S91>/Action Port'
           */
          /* Product: '<S91>/Product' incorporates:
           *  Gain: '<S82>/Transmission Ratio'
           */
          rtb_value_k = 4.0 * Mz * Torque_Control_B.Saturation_k;

          /* Product: '<S91>/Product1' incorporates:
           *  Gain: '<S82>/Transmission Ratio1'
           */
          rtb_alpha_j = 4.0 * mz * Torque_Control_B.Saturation_k;

          /* End of Outputs for SubSystem: '<S82>/Longitudinal Dynamics' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S82>/Lateral Dynamics' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          /* Product: '<S90>/Product' incorporates:
           *  Gain: '<S82>/Transmission Ratio'
           */
          rtb_value_k = 4.0 * Mz * Torque_Control_B.Saturation_c;

          /* Product: '<S90>/Product1' incorporates:
           *  Gain: '<S82>/Transmission Ratio1'
           */
          rtb_alpha_j = 4.0 * mz * Torque_Control_B.Saturation_c;

          /* End of Outputs for SubSystem: '<S82>/Lateral Dynamics' */
          break;
        }

        /* End of If: '<S82>/If' */

        /* If: '<S87>/Braking Conditions' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
          if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
              (Torque_Control_B.sf_Acceleratorbehaviour_br.throttle <= 0.0) &&
              (Torque_Control_B.Merge1_a == 1.0)) {
            rtAction = 0;
          } else if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
                     (Torque_Control_B.sf_Acceleratorbehaviour_br.throttle <=
                      0.0) && (Torque_Control_B.Merge1_a == 0.0)) {
            rtAction = 1;
          } else if ((Torque_Control_U.BrakeSensor_Value <= 0.2) &&
                     (Torque_Control_B.sf_Acceleratorbehaviour_br.throttle <=
                      0.0)) {
            rtAction = 2;
          } else {
            rtAction = 3;
          }

          Torque_Control_DW.BrakingConditions_ActiveSubsyst = rtAction;
        } else {
          rtAction = Torque_Control_DW.BrakingConditions_ActiveSubsyst;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S87>/Regenerative+Mech Braking' incorporates:
           *  ActionPort: '<S99>/Action Port'
           */
          /* MATLAB Function: '<S99>/MATLAB Function' incorporates:
           *  Inport: '<Root>/BrakeSensor_Value'
           */
          if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
            rtb_Abs4 = 0.0;
          } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
            rtb_Abs4 = 1.0;
          } else {
            rtb_Abs4 = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
          }

          rtb_Tq_regen_RR = rtb_Abs4 * rtb_value_k;
          rtb_Tq_regen_RL = rtb_Abs4 * rtb_alpha_j;

          /* End of MATLAB Function: '<S99>/MATLAB Function' */

          /* MATLAB Function: '<S99>/MATLAB Function1' */
          Torque_Control_MATLABFunction(rtb_TransmissionGearRatio,
            rtb_Tq_regen_RR, rtb_Tq_regen_RL,
            &Torque_Control_B.sf_MATLABFunction1_h);

          /* Merge: '<S87>/Merge' incorporates:
           *  Gain: '<S99>/Gain'
           */
          Torque_Control_B.Merge_d =
            -Torque_Control_B.sf_MATLABFunction1_h.RegTq_RR;

          /* Merge: '<S87>/Merge1' incorporates:
           *  Gain: '<S99>/Gain1'
           */
          Torque_Control_B.Merge1_p =
            -Torque_Control_B.sf_MATLABFunction1_h.RegTq_RL;

          /* End of Outputs for SubSystem: '<S87>/Regenerative+Mech Braking' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S87>/Mech_Braking' incorporates:
           *  ActionPort: '<S98>/Action Port'
           */
          Torque_Control_Mech_Braking(Torque_Control_M,
            &Torque_Control_B.Merge_d, &Torque_Control_B.Merge1_p);

          /* End of Outputs for SubSystem: '<S87>/Mech_Braking' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S87>/Inertia Braking' incorporates:
           *  ActionPort: '<S97>/Action Port'
           */
          Torque_Control_Mech_Braking(Torque_Control_M,
            &Torque_Control_B.Merge_d, &Torque_Control_B.Merge1_p);

          /* End of Outputs for SubSystem: '<S87>/Inertia Braking' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S87>/Accelerating' incorporates:
           *  ActionPort: '<S96>/Action Port'
           */
          /* Merge: '<S87>/Merge1' incorporates:
           *  Product: '<S96>/Product'
           */
          Torque_Control_B.Merge1_p =
            Torque_Control_B.sf_Acceleratorbehaviour_br.throttle * rtb_alpha_j;

          /* Merge: '<S87>/Merge' incorporates:
           *  Product: '<S96>/Product1'
           */
          Torque_Control_B.Merge_d =
            Torque_Control_B.sf_Acceleratorbehaviour_br.throttle * rtb_value_k;

          /* End of Outputs for SubSystem: '<S87>/Accelerating' */
          break;
        }

        /* End of If: '<S87>/Braking Conditions' */

        /* Merge: '<S72>/Merge3' incorporates:
         *  SignalConversion generated from: '<S82>/CKF_act'
         */
        Torque_Control_B.Merge3_c = Torque_Control_B.Saturation_c;

        /* Merge: '<S72>/Merge2' incorporates:
         *  SignalConversion generated from: '<S82>/SKF_act'
         */
        Torque_Control_B.Merge2_l = Torque_Control_B.Saturation_k;

        /* Merge: '<S72>/Merge Tq_RL' incorporates:
         *  SignalConversion generated from: '<S82>/Tq_RL_E2 [Nm] (0,inf)'
         */
        Torque_Control_B.MergeTq_RL = Torque_Control_B.Merge1_p;

        /* Merge: '<S72>/Merge Tq_RR' incorporates:
         *  SignalConversion generated from: '<S82>/Tq_RR_E2 [Nm] (0,inf)'
         */
        Torque_Control_B.MergeTq_RR = Torque_Control_B.Merge_d;

        /* End of Outputs for SubSystem: '<S72>/Steering TV with TC' */
      }
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S72>/Rigid Axle' incorporates:
       *  ActionPort: '<S81>/Action Port'
       */
      /* MATLAB Function: '<S85>/Accelerator behaviour ' incorporates:
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       *  Inport: '<Root>/VDC_Apps_Sat_Up'
       */
      Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
        Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
        &Torque_Control_B.sf_Acceleratorbehaviour_o);

      /* Merge: '<S72>/Merge Tq_RL' incorporates:
       *  Product: '<S85>/Product'
       */
      Torque_Control_B.MergeTq_RL =
        Torque_Control_B.sf_Acceleratorbehaviour_o.throttle *
        Torque_Control_ConstB.RT_L;

      /* Merge: '<S72>/Merge Tq_RR' incorporates:
       *  Product: '<S85>/Product1'
       */
      Torque_Control_B.MergeTq_RR =
        Torque_Control_B.sf_Acceleratorbehaviour_o.throttle *
        Torque_Control_ConstB.RT_R;

      /* End of Outputs for SubSystem: '<S72>/Rigid Axle' */
      break;

     case 4:
      break;
    }

    /* End of If: '<S72>/FAILURE MODE' */
    /* End of Outputs for SubSystem: '<S12>/Vehicle Dynamics Control Modes' */
  }

  /* End of If: '<S12>/If' */

  /* Outport: '<Root>/Torque_RRwc' */
  Torque_Control_Y.Torque_RRwc = Torque_Control_B.Merge_kt;

  /* Outport: '<Root>/Torque_RLwc' */
  Torque_Control_Y.Torque_RLwc = Torque_Control_B.Merge1_b;

  /* Outport: '<Root>/Max_Torque_RR' */
  Torque_Control_Y.Max_Torque_RR = Torque_Control_B.Divide;

  /* Outport: '<Root>/Max_Torque_RL' */
  Torque_Control_Y.Max_Torque_RL = Torque_Control_B.Divide_i;

  /* Outport: '<Root>/Max_Fx_RR' */
  Torque_Control_Y.Max_Fx_RR = Torque_Control_B.Merge2_lx;

  /* Outport: '<Root>/Max_Fx_RL' */
  Torque_Control_Y.Max_Fx_RL = Torque_Control_B.Merge3_e;

  /* Outport: '<Root>/Throttle' incorporates:
   *  Gain: '<S12>/Gain1'
   */
  Torque_Control_Y.Throttle = 100.0 * Torque_Control_B.Throttle;

  /* Outport: '<Root>/Fy_R' */
  Torque_Control_Y.Fy_R = Torque_Control_B.Merge6;

  /* Outport: '<Root>/Mass' */
  Torque_Control_Y.Mass = Torque_Control_B.Merge4;

  /* Outport: '<Root>/Handling' */
  Torque_Control_Y.Handling = Torque_Control_B.Merge5;

  /* Outport: '<Root>/SKF_actual' */
  Torque_Control_Y.SKF_actual = Torque_Control_B.Merge2_l;

  /* Outport: '<Root>/CKF_actual' */
  Torque_Control_Y.CKF_actual = Torque_Control_B.Merge3_c;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Outport: '<Root>/APPS_Implausibility' incorporates:
     *  Logic: '<S10>/Logical Operator1'
     */
    Torque_Control_Y.APPS_Implausibility = !Torque_Control_B.Merge_j;
  }

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

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/Accumulator_Current'
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  rtb_Abs4 = Torque_Control_U.Accumulator_Voltage *
    Torque_Control_U.Accumulator_Current;

  /* Outport: '<Root>/Power' */
  Torque_Control_Y.Power = rtb_Abs4;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* If: '<S15>/If' incorporates:
   *  SignalConversion generated from: '<S15>/Power'
   */
  if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
    rtAction = (int8_T)!(rtb_Abs4 >= 80000.0);
    Torque_Control_DW.If_ActiveSubsystem_kl = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_kl;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S15>/LimitReached' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    Torque_Control_LimitReached(Torque_Control_M, &Torque_Control_B.Merge1_pg);

    /* End of Outputs for SubSystem: '<S15>/LimitReached' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S15>/OK_OrLatch' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* If: '<S17>/If' incorporates:
     *  DataStoreRead: '<S15>/Data Store Read30'
     */
    if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
      rtAction = (int8_T)!(Torque_Control_DW.A_i > 0.0);
      Torque_Control_DW.If_ActiveSubsystem_c = rtAction;
    } else {
      rtAction = Torque_Control_DW.If_ActiveSubsystem_c;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S17>/Latched Error' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      Torque_Control_LimitReached(Torque_Control_M, &Torque_Control_B.Merge1_pg);

      /* End of Outputs for SubSystem: '<S17>/Latched Error' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S17>/OK' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        /* Merge: '<S15>/Merge1' incorporates:
         *  Constant: '<S19>/Constant'
         *  SignalConversion generated from: '<S19>/Out '
         */
        Torque_Control_B.Merge1_pg = 0.0;
      }

      /* End of Outputs for SubSystem: '<S17>/OK' */
      break;
    }

    /* End of If: '<S17>/If' */
    /* End of Outputs for SubSystem: '<S15>/OK_OrLatch' */
    break;
  }

  /* End of If: '<S15>/If' */

  /* DataStoreWrite: '<S15>/Data Store Write20' */
  Torque_Control_DW.A_i = Torque_Control_B.Merge1_pg;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* Outport: '<Root>/PowerLimitReached' */
  Torque_Control_Y.PowerLimitReached = Torque_Control_B.Merge1_pg;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Outport: '<Root>/PowerMean500ms' incorporates:
   *  SignalConversion generated from: '<S15>/Power'
   */
  Torque_Control_Y.PowerMean500ms = rtb_Abs4;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* Outport: '<Root>/Torque_OK' */
  Torque_Control_Y.Torque_OK = Torque_Control_B.LogicalOperator;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Outport: '<Root>/Regenerative_Enable' */
    Torque_Control_Y.Regenerative_Enable = Torque_Control_B.Merge1_a;
  }

  /* Outputs for Atomic SubSystem: '<S12>/WORKSHOP_MODE_RESTRICTIONS' */
  /* If: '<S73>/If' incorporates:
   *  Inport: '<Root>/Workshop_Mode_Enable'
   */
  if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
    rtAction = (int8_T)!(Torque_Control_U.Workshop_Mode_Enable == 1.0);
    Torque_Control_DW.If_ActiveSubsystem_ed = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_ed;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S73>/Torque_Reduction ' incorporates:
     *  ActionPort: '<S212>/Action Port'
     */
    /* Product: '<S212>/Divide' incorporates:
     *  Constant: '<S212>/Constant'
     */
    rtb_Product5 = Torque_Control_B.MergeTq_RR / 15.0;

    /* Saturate: '<S212>/Saturation' */
    if (rtb_Product5 > 10.0) {
      rtb_Product5 = 10.0;
    } else if (rtb_Product5 < -10.0) {
      rtb_Product5 = -10.0;
    }

    /* End of Saturate: '<S212>/Saturation' */

    /* Product: '<S212>/Divide1' incorporates:
     *  Constant: '<S212>/Constant'
     */
    rtb_Lookup_Temp_SoP_chg = Torque_Control_B.MergeTq_RL / 15.0;

    /* Saturate: '<S212>/Saturation1' */
    if (rtb_Lookup_Temp_SoP_chg > 10.0) {
      rtb_Lookup_Temp_SoP_chg = 10.0;
    } else if (rtb_Lookup_Temp_SoP_chg < -10.0) {
      rtb_Lookup_Temp_SoP_chg = -10.0;
    }

    /* End of Saturate: '<S212>/Saturation1' */
    /* End of Outputs for SubSystem: '<S73>/Torque_Reduction ' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S73>/BYPASS' incorporates:
     *  ActionPort: '<S211>/Action Port'
     */
    /* SignalConversion generated from: '<S211>/In1' */
    rtb_Product5 = Torque_Control_B.MergeTq_RR;

    /* SignalConversion generated from: '<S211>/In2' */
    rtb_Lookup_Temp_SoP_chg = Torque_Control_B.MergeTq_RL;

    /* End of Outputs for SubSystem: '<S73>/BYPASS' */
    break;
  }

  /* End of If: '<S73>/If' */

  /* Saturate: '<S73>/Saturation' */
  if (rtb_Product5 > 580.0) {
    rtb_Product5 = 580.0;
  } else if (rtb_Product5 < -580.0) {
    rtb_Product5 = -580.0;
  }

  /* End of Saturate: '<S73>/Saturation' */

  /* Saturate: '<S73>/Saturation1' */
  if (rtb_Lookup_Temp_SoP_chg > 580.0) {
    rtb_Lookup_Temp_SoP_chg = 580.0;
  } else if (rtb_Lookup_Temp_SoP_chg < -580.0) {
    rtb_Lookup_Temp_SoP_chg = -580.0;
  }

  /* End of Saturate: '<S73>/Saturation1' */
  /* End of Outputs for SubSystem: '<S12>/WORKSHOP_MODE_RESTRICTIONS' */

  /* Gain: '<Root>/Gain1' */
  Torque_Control_B.Gain1 = 0.25 * rtb_Product5;

  /* Gain: '<Root>/Gain' */
  Torque_Control_B.Gain = 0.25 * rtb_Lookup_Temp_SoP_chg;

  /* RelationalOperator: '<S222>/Compare' incorporates:
   *  Constant: '<S222>/Constant'
   *  Inport: '<Root>/Highest_CellTemp'
   */
  rtb_Compare_c = (Torque_Control_U.Highest_CellTemp >= 50.0);

  /* Outputs for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' incorporates:
   *  ActionPort: '<S3>/Action Port'
   */
  /* If: '<Root>/If' incorporates:
   *  Constant: '<S14>/initial_limitation'
   *  Constant: '<S218>/Constant1'
   *  Constant: '<S218>/Constant2'
   *  Inport: '<Root>/Highest_CellTemp'
   *  Product: '<S218>/Divide'
   *  Sum: '<S218>/Add1'
   *  Sum: '<S218>/Add3'
   *  Sum: '<S28>/Add3'
   */
  rtb_Abs4 = 45.0 / (Torque_Control_U.Highest_CellTemp - 5.0) - 0.4;

  /* End of Outputs for SubSystem: '<Root>/Controls Temperature by limiting Torque' */

  /* Sum: '<S218>/Add2' incorporates:
   *  Constant: '<S218>/Constant3'
   *  Product: '<S218>/Product4'
   *  Sum: '<S218>/Add3'
   */
  Torque_Control_B.Add2 = (rtb_Abs4 * (real_T)rtb_Compare_c - (real_T)
    rtb_Compare_c) + 1.0;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Sum: '<S223>/Sum1' incorporates:
     *  Constant: '<S223>/Time constant'
     */
    rtb_Saturation1_au = 100.0 - Torque_Control_B.Probe[0];

    /* RelationalOperator: '<S226>/Compare' incorporates:
     *  Constant: '<S223>/Time constant'
     *  Constant: '<S226>/Constant'
     *  Sum: '<S223>/Sum1'
     */
    Torque_Control_B.Compare = (100.0 - Torque_Control_B.Probe[0] <= 0.0);
  }

  /* RelationalOperator: '<S230>/Compare' incorporates:
   *  Constant: '<S230>/Constant'
   *  Inport: '<Root>/Temp_IGBT'
   */
  rtb_Compare_c = (Torque_Control_U.Temp_IGBT >= 50.0);

  /* Outputs for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' incorporates:
   *  ActionPort: '<S3>/Action Port'
   */
  /* If: '<Root>/If' incorporates:
   *  Constant: '<S14>/initial_limitation'
   *  Constant: '<S219>/Constant1'
   *  Constant: '<S219>/Constant2'
   *  Inport: '<Root>/Temp_IGBT'
   *  Product: '<S219>/Divide'
   *  Sum: '<S219>/Add1'
   *  Sum: '<S219>/Add3'
   *  Sum: '<S29>/Add3'
   */
  rtb_Abs1 = 45.0 / (Torque_Control_U.Temp_IGBT - 5.0) - 0.4;

  /* End of Outputs for SubSystem: '<Root>/Controls Temperature by limiting Torque' */

  /* Sum: '<S219>/Add2' incorporates:
   *  Constant: '<S219>/Constant3'
   *  Product: '<S219>/Product4'
   *  Sum: '<S219>/Add3'
   */
  Torque_Control_B.Add2_c = (rtb_Abs1 * (real_T)rtb_Compare_c - (real_T)
    rtb_Compare_c) + 1.0;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* DiscreteIntegrator: '<S228>/Integrator' */
    if (Torque_Control_DW.Integrator_IC_LOADING != 0) {
      Torque_Control_DW.Integrator_DSTATE = Torque_Control_B.Add2;
    }

    if (Torque_Control_B.Compare || (Torque_Control_DW.Integrator_PrevResetState
         != 0)) {
      Torque_Control_DW.Integrator_DSTATE = Torque_Control_B.Add2;
    }

    /* DiscreteIntegrator: '<S228>/Integrator' */
    Torque_Control_B.Integrator = Torque_Control_DW.Integrator_DSTATE;

    /* Saturate: '<S218>/Saturation1' */
    if (Torque_Control_B.Integrator > 1.0) {
      rtb_Saturation1_au = 1.0;
    } else if (Torque_Control_B.Integrator < 0.0) {
      rtb_Saturation1_au = 0.0;
    } else {
      rtb_Saturation1_au = Torque_Control_B.Integrator;
    }

    /* End of Saturate: '<S218>/Saturation1' */

    /* Sum: '<S231>/Sum1' incorporates:
     *  Constant: '<S231>/Time constant'
     */
    rtb_Saturation1_g = 100.0 - Torque_Control_B.Probe_d[0];

    /* RelationalOperator: '<S234>/Compare' incorporates:
     *  Constant: '<S231>/Time constant'
     *  Constant: '<S234>/Constant'
     *  Sum: '<S231>/Sum1'
     */
    Torque_Control_B.Compare_c = (100.0 - Torque_Control_B.Probe_d[0] <= 0.0);
  }

  /* RelationalOperator: '<S238>/Compare' incorporates:
   *  Constant: '<S238>/Constant'
   *  Inport: '<Root>/Temp_Motors'
   */
  rtb_Compare_c = (Torque_Control_U.Temp_Motors >= 110.0);

  /* Outputs for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' incorporates:
   *  ActionPort: '<S3>/Action Port'
   */
  /* If: '<Root>/If' incorporates:
   *  Constant: '<S14>/initial_limitation'
   *  Constant: '<S220>/Constant1'
   *  Constant: '<S220>/Constant2'
   *  Inport: '<Root>/Temp_Motors'
   *  Product: '<S220>/Divide'
   *  Sum: '<S220>/Add1'
   *  Sum: '<S220>/Add3'
   *  Sum: '<S30>/Add3'
   */
  rtb_value_k = 105.0 / (Torque_Control_U.Temp_Motors - 5.0) - 0.4;

  /* End of Outputs for SubSystem: '<Root>/Controls Temperature by limiting Torque' */

  /* Sum: '<S220>/Add2' incorporates:
   *  Constant: '<S220>/Constant3'
   *  Product: '<S220>/Product4'
   *  Sum: '<S220>/Add3'
   */
  Torque_Control_B.Add2_e = (rtb_value_k * (real_T)rtb_Compare_c - (real_T)
    rtb_Compare_c) + 1.0;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* DiscreteIntegrator: '<S236>/Integrator' */
    if (Torque_Control_DW.Integrator_IC_LOADING_m != 0) {
      Torque_Control_DW.Integrator_DSTATE_p = Torque_Control_B.Add2_c;
    }

    if (Torque_Control_B.Compare_c ||
        (Torque_Control_DW.Integrator_PrevResetState_h != 0)) {
      Torque_Control_DW.Integrator_DSTATE_p = Torque_Control_B.Add2_c;
    }

    /* DiscreteIntegrator: '<S236>/Integrator' */
    Torque_Control_B.Integrator_k = Torque_Control_DW.Integrator_DSTATE_p;

    /* Saturate: '<S219>/Saturation1' */
    if (Torque_Control_B.Integrator_k > 1.0) {
      rtb_Saturation1_g = 1.0;
    } else if (Torque_Control_B.Integrator_k < 0.0) {
      rtb_Saturation1_g = 0.0;
    } else {
      rtb_Saturation1_g = Torque_Control_B.Integrator_k;
    }

    /* End of Saturate: '<S219>/Saturation1' */

    /* Sum: '<S239>/Sum1' incorporates:
     *  Constant: '<S239>/Time constant'
     */
    rtb_Max_m = 100.0 - Torque_Control_B.Probe_j[0];

    /* RelationalOperator: '<S242>/Compare' incorporates:
     *  Constant: '<S239>/Time constant'
     *  Constant: '<S242>/Constant'
     *  Sum: '<S239>/Sum1'
     */
    Torque_Control_B.Compare_i = (100.0 - Torque_Control_B.Probe_j[0] <= 0.0);
  }

  /* MATLAB Function: '<Root>/SoP selection and sum of max WHEEL Tq available' incorporates:
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/BrakeSensor_Value'
   *  Inport: '<Root>/VDC_Apps_Sat_Down'
   */
  if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
      (Torque_Control_U.APPS1_Value < Torque_Control_U.VDC_Apps_Sat_Down)) {
    Torque_Control_B.Braking = 1.0;
  } else {
    Torque_Control_B.Braking = 0.0;
  }

  /* End of MATLAB Function: '<Root>/SoP selection and sum of max WHEEL Tq available' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* DiscreteIntegrator: '<S244>/Integrator' */
    if (Torque_Control_DW.Integrator_IC_LOADING_b != 0) {
      Torque_Control_DW.Integrator_DSTATE_n = Torque_Control_B.Add2_e;
    }

    if (Torque_Control_B.Compare_i ||
        (Torque_Control_DW.Integrator_PrevResetState_c != 0)) {
      Torque_Control_DW.Integrator_DSTATE_n = Torque_Control_B.Add2_e;
    }

    /* DiscreteIntegrator: '<S244>/Integrator' */
    Torque_Control_B.Integrator_a = Torque_Control_DW.Integrator_DSTATE_n;

    /* Saturate: '<S220>/Saturation1' */
    if (Torque_Control_B.Integrator_a > 1.0) {
      rtb_Max_m = 1.0;
    } else if (Torque_Control_B.Integrator_a < 0.0) {
      rtb_Max_m = 0.0;
    } else {
      rtb_Max_m = Torque_Control_B.Integrator_a;
    }

    /* End of Saturate: '<S220>/Saturation1' */

    /* MinMax: '<S214>/Min' */
    Torque_Control_B.Min = fmin(fmin(rtb_Saturation1_au, rtb_Saturation1_g),
      rtb_Max_m);

    /* If: '<Root>/If' */
    if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
      rtAction = 1;
      Torque_Control_DW.If_ActiveSubsystem_e = 1;
    } else {
      rtAction = Torque_Control_DW.If_ActiveSubsystem_e;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  SignalConversion generated from: '<S6>/In1'
       */
      Torque_Control_B.Merge = Torque_Control_B.Gain1;

      /* Merge: '<Root>/Merge3' incorporates:
       *  SignalConversion generated from: '<S6>/In2'
       */
      Torque_Control_B.Merge3 = Torque_Control_B.Gain;

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* RelationalOperator: '<S36>/Compare' incorporates:
       *  Constant: '<S33>/Time constant'
       *  Constant: '<S36>/Constant'
       *  Sum: '<S33>/Sum1'
       */
      Torque_Control_B.Compare_b = (100.0 - Torque_Control_B.Probe_a[0] <= 0.0);

      /* RelationalOperator: '<S32>/Compare' incorporates:
       *  Constant: '<S32>/Constant'
       *  Inport: '<Root>/Highest_CellTemp'
       */
      rtb_Compare_c = (Torque_Control_U.Highest_CellTemp >= 50.0);

      /* Sum: '<S28>/Add2' incorporates:
       *  Constant: '<S28>/Constant3'
       *  Product: '<S28>/Product4'
       */
      rtb_Abs4 = (rtb_Abs4 * (real_T)rtb_Compare_c - (real_T)rtb_Compare_c) +
        1.0;

      /* DiscreteIntegrator: '<S38>/Integrator' */
      if (Torque_Control_DW.Integrator_IC_LOADING_g != 0) {
        Torque_Control_DW.Integrator_DSTATE_k = rtb_Abs4;
      }

      if (Torque_Control_B.Compare_b ||
          (Torque_Control_DW.Integrator_PrevResetState_b != 0)) {
        Torque_Control_DW.Integrator_DSTATE_k = rtb_Abs4;
      }

      /* DiscreteIntegrator: '<S38>/Integrator' */
      rtb_Integrator_k = Torque_Control_DW.Integrator_DSTATE_k;

      /* Saturate: '<S28>/Saturation1' */
      if (rtb_Integrator_k > 1.0) {
        rtb_alpha_j = 1.0;
      } else if (rtb_Integrator_k < 0.0) {
        rtb_alpha_j = 0.0;
      } else {
        rtb_alpha_j = rtb_Integrator_k;
      }

      /* End of Saturate: '<S28>/Saturation1' */

      /* RelationalOperator: '<S44>/Compare' incorporates:
       *  Constant: '<S41>/Time constant'
       *  Constant: '<S44>/Constant'
       *  Sum: '<S41>/Sum1'
       */
      Torque_Control_B.Compare_n = (100.0 - Torque_Control_B.Probe_o[0] <= 0.0);

      /* RelationalOperator: '<S40>/Compare' incorporates:
       *  Constant: '<S40>/Constant'
       *  Inport: '<Root>/Temp_IGBT'
       */
      rtb_Compare_c = (Torque_Control_U.Temp_IGBT >= 50.0);

      /* Sum: '<S29>/Add2' incorporates:
       *  Constant: '<S29>/Constant3'
       *  Product: '<S29>/Product4'
       */
      rtb_Abs1 = (rtb_Abs1 * (real_T)rtb_Compare_c - (real_T)rtb_Compare_c) +
        1.0;

      /* DiscreteIntegrator: '<S46>/Integrator' */
      if (Torque_Control_DW.Integrator_IC_LOADING_k != 0) {
        Torque_Control_DW.Integrator_DSTATE_b = rtb_Abs1;
      }

      if (Torque_Control_B.Compare_n ||
          (Torque_Control_DW.Integrator_PrevResetState_f != 0)) {
        Torque_Control_DW.Integrator_DSTATE_b = rtb_Abs1;
      }

      /* DiscreteIntegrator: '<S46>/Integrator' */
      rtb_Integrator_d = Torque_Control_DW.Integrator_DSTATE_b;

      /* Saturate: '<S29>/Saturation1' */
      if (rtb_Integrator_d > 1.0) {
        mz = 1.0;
      } else if (rtb_Integrator_d < 0.0) {
        mz = 0.0;
      } else {
        mz = rtb_Integrator_d;
      }

      /* End of Saturate: '<S29>/Saturation1' */

      /* RelationalOperator: '<S52>/Compare' incorporates:
       *  Constant: '<S49>/Time constant'
       *  Constant: '<S52>/Constant'
       *  Sum: '<S49>/Sum1'
       */
      Torque_Control_B.Compare_e = (100.0 - Torque_Control_B.Probe_n[0] <= 0.0);

      /* RelationalOperator: '<S48>/Compare' incorporates:
       *  Constant: '<S48>/Constant'
       *  Inport: '<Root>/Temp_Motors'
       */
      rtb_Compare_c = (Torque_Control_U.Temp_Motors >= 110.0);

      /* Sum: '<S30>/Add2' incorporates:
       *  Constant: '<S30>/Constant3'
       *  Product: '<S30>/Product4'
       */
      rtb_value_k = (rtb_value_k * (real_T)rtb_Compare_c - (real_T)rtb_Compare_c)
        + 1.0;

      /* DiscreteIntegrator: '<S54>/Integrator' */
      if (Torque_Control_DW.Integrator_IC_LOADING_e != 0) {
        Torque_Control_DW.Integrator_DSTATE_j = rtb_value_k;
      }

      if (Torque_Control_B.Compare_e ||
          (Torque_Control_DW.Integrator_PrevResetState_j != 0)) {
        Torque_Control_DW.Integrator_DSTATE_j = rtb_value_k;
      }

      /* DiscreteIntegrator: '<S54>/Integrator' */
      rtb_Integrator_j = Torque_Control_DW.Integrator_DSTATE_j;

      /* Saturate: '<S30>/Saturation1' */
      if (rtb_Integrator_j > 1.0) {
        Mz = 1.0;
      } else if (rtb_Integrator_j < 0.0) {
        Mz = 0.0;
      } else {
        Mz = rtb_Integrator_j;
      }

      /* End of Saturate: '<S30>/Saturation1' */

      /* MATLAB Function: '<S3>/Tq_limitation because of Temp' incorporates:
       *  Constant: '<S3>/Max_Tq_per_motor'
       */
      if (Torque_Control_B.Braking == 1.0) {
        /* Product: '<S22>/Product5' incorporates:
         *  Gain: '<S22>/Gain5'
         *  Inport: '<Root>/Highest_CellTemp'
         *  Inport: '<Root>/SoC_High'
         *  Lookup_n-D: '<S22>/Lookup_SoC_SoP_chg'
         *  Lookup_n-D: '<S22>/Lookup_Temp_SoP_chg'
         *  MinMax: '<S24>/Min'
         *  Product: '<S22>/Product'
         */
        X_idx_1 = look1_binlxpw(0.01 * Torque_Control_U.SoC_High,
          rtCP_Lookup_SoC_SoP_chg_bp01Dat, rtCP_Lookup_SoC_SoP_chg_tableDa, 7U) *
          look1_binlxpw(Torque_Control_U.Highest_CellTemp,
                        rtCP_Lookup_Temp_SoP_chg_bp01Da,
                        rtCP_Lookup_Temp_SoP_chg_tableD, 4U) * fmin(fmin
          (rtb_alpha_j, mz), Mz);

        /* Saturate: '<S3>/Saturation1' */
        if (X_idx_1 > 1.0) {
          X_idx_1 = -1.0;
        } else if (X_idx_1 < 0.0) {
          X_idx_1 = -0.0;
        } else {
          X_idx_1 = -X_idx_1;
        }

        /* End of Saturate: '<S3>/Saturation1' */
      } else {
        /* Product: '<S22>/Product4' incorporates:
         *  Gain: '<S22>/Gain6'
         *  Inport: '<Root>/SoC_Low'
         *  Lookup_n-D: '<S22>/Lookup_SoC_SoP_dischg'
         *  MinMax: '<S24>/Min'
         */
        X_idx_1 = look1_binlxpw(0.01 * Torque_Control_U.SoC_Low,
          rtCP_Lookup_SoC_SoP_dischg_bp01, rtCP_Lookup_SoC_SoP_dischg_tabl, 7U) *
          fmin(fmin(rtb_alpha_j, mz), Mz);

        /* Saturate: '<S3>/Saturation' */
        if (X_idx_1 > 1.0) {
          X_idx_1 = 1.0;
        } else if (X_idx_1 < 0.0) {
          X_idx_1 = 0.0;
        }

        /* End of Saturate: '<S3>/Saturation' */
      }

      k = X_idx_1 * 2.0 * 120.0;
      p = Torque_Control_B.Gain1 + Torque_Control_B.Gain;
      if (p > k) {
        p = Torque_Control_B.Gain1 / p * k;

        /* Merge: '<Root>/Merge3' */
        Torque_Control_B.Merge3 = k - p;
      } else {
        p = Torque_Control_B.Gain1;

        /* Merge: '<Root>/Merge3' */
        Torque_Control_B.Merge3 = Torque_Control_B.Gain;
      }

      /* Merge: '<Root>/Merge' incorporates:
       *  MATLAB Function: '<S3>/Tq_limitation because of Temp'
       *  SignalConversion generated from: '<S3>/Tq_R'
       */
      Torque_Control_B.Merge = p;

      /* RelationalOperator: '<S25>/Compare' incorporates:
       *  Constant: '<S25>/Constant'
       */
      Torque_Control_B.Compare_f = (rtb_alpha_j < 1.0);

      /* RelationalOperator: '<S26>/Compare' incorporates:
       *  Constant: '<S26>/Constant'
       */
      Torque_Control_B.Compare_d = (mz < 1.0);

      /* RelationalOperator: '<S27>/Compare' incorporates:
       *  Constant: '<S27>/Constant'
       */
      Torque_Control_B.Compare_g = (Mz < 1.0);

      /* Product: '<S31>/1//T' incorporates:
       *  Constant: '<S33>/Time constant'
       *  MinMax: '<S33>/Max'
       *  Sum: '<S31>/Sum1'
       */
      Torque_Control_B.uT_l = 1.0 / fmax(Torque_Control_B.Probe_a[0], 100.0) *
        (rtb_Abs4 - rtb_Integrator_k);

      /* Product: '<S39>/1//T' incorporates:
       *  Constant: '<S41>/Time constant'
       *  MinMax: '<S41>/Max'
       *  Sum: '<S39>/Sum1'
       */
      Torque_Control_B.uT_io = 1.0 / fmax(Torque_Control_B.Probe_o[0], 100.0) *
        (rtb_Abs1 - rtb_Integrator_d);

      /* Product: '<S47>/1//T' incorporates:
       *  Constant: '<S49>/Time constant'
       *  MinMax: '<S49>/Max'
       *  Sum: '<S47>/Sum1'
       */
      Torque_Control_B.uT_m = 1.0 / fmax(Torque_Control_B.Probe_n[0], 100.0) *
        (rtb_value_k - rtb_Integrator_j);

      /* End of Outputs for SubSystem: '<Root>/Controls Temperature by limiting Torque' */
      break;
    }

    /* Outport: '<Root>/Meas VDC Torque_L' */
    Torque_Control_Y.MeasVDCTorque_L = Torque_Control_B.Merge3;

    /* Outport: '<Root>/Meas VDC Torque_R' */
    Torque_Control_Y.MeasVDCTorque_R = Torque_Control_B.Merge;
  }

  /* Outport: '<Root>/Torque_L' */
  Torque_Control_Y.Torque_L = rtb_Lookup_Temp_SoP_chg;

  /* Outport: '<Root>/Torque_R' */
  Torque_Control_Y.Torque_R = rtb_Product5;

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  Constant: '<S9>/Max_Power_charge [kW]'
   *  Constant: '<S9>/Max_Power_discharge [kW]'
   */
  if (Torque_Control_B.Braking == 1.0) {
    rtb_Lookup_Temp_SoP_chg = -60000.0;
  } else {
    rtb_Lookup_Temp_SoP_chg = 80000.0;
  }

  if (Torque_Control_B.Merge * rtb_Abs3 + Torque_Control_B.Merge3 *
      Torque_Control_B.Abs2 > rtb_Lookup_Temp_SoP_chg) {
    rtb_Product5 = Torque_Control_B.Merge / (Torque_Control_B.Merge +
      Torque_Control_B.Merge3);
    rtb_Product5 = rtb_Product5 * rtb_Lookup_Temp_SoP_chg / ((rtb_Abs3 -
      Torque_Control_B.Abs2) * rtb_Product5 + Torque_Control_B.Abs2);
    rtb_Lookup_Temp_SoP_chg = (rtb_Lookup_Temp_SoP_chg - rtb_Product5 * rtb_Abs3)
      / Torque_Control_B.Abs2;
  } else {
    rtb_Product5 = Torque_Control_B.Merge;
    rtb_Lookup_Temp_SoP_chg = Torque_Control_B.Merge3;
  }

  /* If: '<Root>/If1' */
  if (rtsiIsModeUpdateTimeStep(&Torque_Control_M->solverInfo)) {
    rtAction = (int8_T)!Torque_Control_B.LogicalOperator;
    Torque_Control_DW.If1_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_DW.If1_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/Calculate Current Conversion' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S2>/KT_R_EMY' */
    /* Merge: '<Root>/Merge2' incorporates:
     *  Gain: '<S21>/A//Nm'
     *  MATLAB Function: '<S9>/MATLAB Function'
     */
    Torque_Control_B.Merge2_e = 0.2 * rtb_Product5;

    /* End of Outputs for SubSystem: '<S2>/KT_R_EMY' */

    /* Outputs for Atomic SubSystem: '<S2>/KT_L_TORKY' */
    /* Merge: '<Root>/Merge1' incorporates:
     *  Gain: '<S20>/A//Nm'
     *  Gain: '<S2>/Gain'
     */
    Torque_Control_B.Merge1_a0 = -(0.2 * rtb_Lookup_Temp_SoP_chg);

    /* End of Outputs for SubSystem: '<S2>/KT_L_TORKY' */
    /* End of Outputs for SubSystem: '<Root>/Calculate Current Conversion' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Current 0' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
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
    }

    /* End of Outputs for SubSystem: '<Root>/Current 0' */
    break;
  }

  /* End of If: '<Root>/If1' */

  /* Outport: '<Root>/current_L' */
  Torque_Control_Y.current_L = Torque_Control_B.Merge1_a0;

  /* Outport: '<Root>/current_R' */
  Torque_Control_Y.current_R = Torque_Control_B.Merge2_e;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Outport: '<Root>/TV_Flag_Temperature' incorporates:
     *  Constant: '<S215>/Constant'
     *  Constant: '<S216>/Constant'
     *  Constant: '<S217>/Constant'
     *  MATLAB Function: '<Root>/Flag_Temp merged'
     *  MATLAB Function: '<Root>/MATLAB Function'
     *  MATLAB Function: '<Root>/MATLAB Function1'
     *  RelationalOperator: '<S215>/Compare'
     *  RelationalOperator: '<S216>/Compare'
     *  RelationalOperator: '<S217>/Compare'
     */
    Torque_Control_Y.TV_Flag_Temperature = ((rtb_Saturation1_au < 1.0) ||
      (rtb_Saturation1_g < 1.0) || (rtb_Max_m < 1.0) ||
      (Torque_Control_B.Compare_f || Torque_Control_B.Compare_d ||
       Torque_Control_B.Compare_g));

    /* Fcn: '<S223>/Avoid Divide by Zero' incorporates:
     *  Constant: '<S223>/Time constant'
     *  MinMax: '<S223>/Max'
     */
    Torque_Control_B.AvoidDividebyZero = fmax(Torque_Control_B.Probe[0], 100.0);
  }

  /* Abs: '<S12>/Abs' incorporates:
   *  Inport: '<Root>/ACCEL_F_X_SI'
   */
  Torque_Control_B.Abs = fabs(Torque_Control_U.ACCEL_F_X_SI);

  /* Product: '<S221>/1//T' incorporates:
   *  Sum: '<S221>/Sum1'
   */
  Torque_Control_B.uT = 1.0 / Torque_Control_B.AvoidDividebyZero *
    (Torque_Control_B.Add2 - Torque_Control_B.Integrator);
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Fcn: '<S231>/Avoid Divide by Zero' incorporates:
     *  Constant: '<S231>/Time constant'
     *  MinMax: '<S231>/Max'
     */
    Torque_Control_B.AvoidDividebyZero_l = fmax(Torque_Control_B.Probe_d[0],
      100.0);

    /* Fcn: '<S239>/Avoid Divide by Zero' incorporates:
     *  Constant: '<S239>/Time constant'
     *  MinMax: '<S239>/Max'
     */
    Torque_Control_B.AvoidDividebyZero_f = fmax(Torque_Control_B.Probe_j[0],
      100.0);
  }

  /* Product: '<S229>/1//T' incorporates:
   *  Sum: '<S229>/Sum1'
   */
  Torque_Control_B.uT_i = 1.0 / Torque_Control_B.AvoidDividebyZero_l *
    (Torque_Control_B.Add2_c - Torque_Control_B.Integrator_k);

  /* Product: '<S237>/1//T' incorporates:
   *  Sum: '<S237>/Sum1'
   */
  Torque_Control_B.uT_p = 1.0 / Torque_Control_B.AvoidDividebyZero_f *
    (Torque_Control_B.Add2_e - Torque_Control_B.Integrator_a);
}

/* Model update function */
void Torque_Control_update(void)
{
  real_T *lastU;

  /* Update for If: '<S12>/If' */
  if (Torque_Control_DW.If_ActiveSubsystem_k == 0) {
    /* Update for IfAction SubSystem: '<S12>/Vehicle Dynamics Control Modes' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    /* Update for If: '<S72>/FAILURE MODE' */
    switch (Torque_Control_DW.FAILUREMODE_ActiveSubsystem) {
     case 0:
      /* Update for IfAction SubSystem: '<S72>/VDC Complete' incorporates:
       *  ActionPort: '<S83>/Action Port'
       */
      /* Update for Derivative: '<S123>/Derivative' */
      if (Torque_Control_DW.TimeStampA_g == (rtInf)) {
        Torque_Control_DW.TimeStampA_g = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA_c;
      } else if (Torque_Control_DW.TimeStampB_c == (rtInf)) {
        Torque_Control_DW.TimeStampB_c = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB_f;
      } else if (Torque_Control_DW.TimeStampA_g < Torque_Control_DW.TimeStampB_c)
      {
        Torque_Control_DW.TimeStampA_g = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA_c;
      } else {
        Torque_Control_DW.TimeStampB_c = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB_f;
      }

      *lastU = Torque_Control_B.sf_MATLABFunction_n.RPM;

      /* End of Update for Derivative: '<S123>/Derivative' */
      /* End of Update for SubSystem: '<S72>/VDC Complete' */
      break;

     case 1:
      /* Update for IfAction SubSystem: '<S72>/VDC without Longitudinal' incorporates:
       *  ActionPort: '<S84>/Action Port'
       */
      /* Update for Derivative: '<S180>/Derivative' */
      if (Torque_Control_DW.TimeStampA_b == (rtInf)) {
        Torque_Control_DW.TimeStampA_b = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA_e;
      } else if (Torque_Control_DW.TimeStampB_e == (rtInf)) {
        Torque_Control_DW.TimeStampB_e = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB_o;
      } else if (Torque_Control_DW.TimeStampA_b < Torque_Control_DW.TimeStampB_e)
      {
        Torque_Control_DW.TimeStampA_b = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeA_e;
      } else {
        Torque_Control_DW.TimeStampB_e = Torque_Control_M->Timing.t[0];
        lastU = &Torque_Control_DW.LastUAtTimeB_o;
      }

      *lastU = Torque_Control_B.sf_MATLABFunction_fa.RPM;

      /* End of Update for Derivative: '<S180>/Derivative' */
      /* End of Update for SubSystem: '<S72>/VDC without Longitudinal' */
      break;

     case 2:
      /* Update for IfAction SubSystem: '<S72>/Steering TV with TC' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      /* Update for Derivative: '<S93>/Derivative' */
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

      *lastU = Torque_Control_B.sf_MATLABFunction_ab.RPM;

      /* End of Update for Derivative: '<S93>/Derivative' */
      /* End of Update for SubSystem: '<S72>/Steering TV with TC' */
      break;

     case 3:
     case 4:
      break;
    }

    /* End of Update for If: '<S72>/FAILURE MODE' */
    /* End of Update for SubSystem: '<S12>/Vehicle Dynamics Control Modes' */
  }

  /* End of Update for If: '<S12>/If' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Update for DiscreteIntegrator: '<S228>/Integrator' */
    Torque_Control_DW.Integrator_IC_LOADING = 0U;
    Torque_Control_DW.Integrator_DSTATE += 0.2 * Torque_Control_B.uT;
    Torque_Control_DW.Integrator_PrevResetState = (int8_T)
      Torque_Control_B.Compare;

    /* Update for DiscreteIntegrator: '<S236>/Integrator' */
    Torque_Control_DW.Integrator_IC_LOADING_m = 0U;
    Torque_Control_DW.Integrator_DSTATE_p += 0.2 * Torque_Control_B.uT_i;
    Torque_Control_DW.Integrator_PrevResetState_h = (int8_T)
      Torque_Control_B.Compare_c;

    /* Update for DiscreteIntegrator: '<S244>/Integrator' */
    Torque_Control_DW.Integrator_IC_LOADING_b = 0U;
    Torque_Control_DW.Integrator_DSTATE_n += 0.2 * Torque_Control_B.uT_p;
    Torque_Control_DW.Integrator_PrevResetState_c = (int8_T)
      Torque_Control_B.Compare_i;

    /* Update for If: '<Root>/If' */
    if (Torque_Control_DW.If_ActiveSubsystem_e == 1) {
      /* Update for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* Update for DiscreteIntegrator: '<S38>/Integrator' */
      Torque_Control_DW.Integrator_IC_LOADING_g = 0U;
      Torque_Control_DW.Integrator_DSTATE_k += 0.2 * Torque_Control_B.uT_l;
      Torque_Control_DW.Integrator_PrevResetState_b = (int8_T)
        Torque_Control_B.Compare_b;

      /* Update for DiscreteIntegrator: '<S46>/Integrator' */
      Torque_Control_DW.Integrator_IC_LOADING_k = 0U;
      Torque_Control_DW.Integrator_DSTATE_b += 0.2 * Torque_Control_B.uT_io;
      Torque_Control_DW.Integrator_PrevResetState_f = (int8_T)
        Torque_Control_B.Compare_n;

      /* Update for DiscreteIntegrator: '<S54>/Integrator' */
      Torque_Control_DW.Integrator_IC_LOADING_e = 0U;
      Torque_Control_DW.Integrator_DSTATE_j += 0.2 * Torque_Control_B.uT_m;
      Torque_Control_DW.Integrator_PrevResetState_j = (int8_T)
        Torque_Control_B.Compare_e;

      /* End of Update for SubSystem: '<Root>/Controls Temperature by limiting Torque' */
    }

    /* End of Update for If: '<Root>/If' */
  }

  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rt_ertODEUpdateContinuousStates(&Torque_Control_M->solverInfo);
  }

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

  Torque_Control_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Torque_Control_M->solverInfo);

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

/* Derivatives for root system: '<Root>' */
void Torque_Control_derivatives(void)
{
  XDot_Torque_Control_T *_rtXdot;
  _rtXdot = ((XDot_Torque_Control_T *) Torque_Control_M->derivs);

  /* Derivatives for If: '<S12>/If' */
  ((XDot_Torque_Control_T *) Torque_Control_M->derivs)->Integrator_CSTATE = 0.0;
  if (Torque_Control_DW.If_ActiveSubsystem_k == 0) {
    /* Derivatives for IfAction SubSystem: '<S12>/Vehicle Dynamics Control Modes' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    /* Derivatives for If: '<S72>/FAILURE MODE' */
    ((XDot_Torque_Control_T *) Torque_Control_M->derivs)->Integrator_CSTATE =
      0.0;
    if (Torque_Control_DW.FAILUREMODE_ActiveSubsystem == 0) {
      /* Derivatives for IfAction SubSystem: '<S72>/VDC Complete' incorporates:
       *  ActionPort: '<S83>/Action Port'
       */
      /* Derivatives for If: '<S83>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
      ((XDot_Torque_Control_T *) Torque_Control_M->derivs)->Integrator_CSTATE =
        0.0;
      if (Torque_Control_DW.Steer_angisinSteer_SatrangeLong == 1) {
        /* Derivatives for IfAction SubSystem: '<S83>/Lateral Dynamics' incorporates:
         *  ActionPort: '<S119>/Action Port'
         */
        /* Derivatives for Integrator: '<S119>/Integrator' */
        _rtXdot->Integrator_CSTATE = Torque_Control_B.Abs;

        /* End of Derivatives for SubSystem: '<S83>/Lateral Dynamics' */
      }

      /* End of Derivatives for If: '<S83>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
      /* End of Derivatives for SubSystem: '<S72>/VDC Complete' */
    }

    /* End of Derivatives for If: '<S72>/FAILURE MODE' */
    /* End of Derivatives for SubSystem: '<S12>/Vehicle Dynamics Control Modes' */
  }

  /* End of Derivatives for If: '<S12>/If' */
}

/* Model initialize function */
void Torque_Control_initialize(void)
{
  /* Start for If: '<S56>/If' */
  Torque_Control_DW.If_ActiveSubsystem = -1;

  /* Start for Atomic SubSystem: '<S12>/TEST_MODE_IN' */
  /* Start for If: '<S71>/If' */
  Torque_Control_DW.If_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S12>/TEST_MODE_IN' */

  /* Start for Atomic SubSystem: '<S12>/Regeneration_Enable' */
  /* Start for If: '<S70>/If' */
  Torque_Control_DW.If_ActiveSubsystem_o = -1;

  /* End of Start for SubSystem: '<S12>/Regeneration_Enable' */

  /* Start for If: '<S12>/If' */
  Torque_Control_DW.If_ActiveSubsystem_k = -1;

  /* Start for IfAction SubSystem: '<S12>/Vehicle Dynamics Control Modes' */
  /* Start for If: '<S72>/If' */
  Torque_Control_DW.If_ActiveSubsystem_j = -1;

  /* Start for If: '<S72>/FAILURE MODE' */
  Torque_Control_DW.FAILUREMODE_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S72>/VDC Complete' */
  /* Start for If: '<S158>/SKF or CKF' */
  Torque_Control_DW.SKForCKF_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S158>/SKF' */
  /* Start for If: '<S161>/If' */
  Torque_Control_DW.If_ActiveSubsystem_ha = -1;

  /* End of Start for SubSystem: '<S158>/SKF' */

  /* Start for IfAction SubSystem: '<S158>/CKF' */
  /* Start for If: '<S159>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_o = -1;

  /* End of Start for SubSystem: '<S158>/CKF' */

  /* Start for DataStoreMemory: '<S123>/Data Store Memory' */
  Torque_Control_DW.A_b = 0.0;

  /* Start for DataStoreMemory: '<S123>/Data Store Memory1' */
  Torque_Control_DW.B_i = 0.0;

  /* Start for If: '<S83>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
  Torque_Control_DW.Steer_angisinSteer_SatrangeLong = -1;

  /* Start for If: '<S116>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubsy_b = -1;

  /* Start for If: '<S115>/If' */
  Torque_Control_DW.If_ActiveSubsystem_aq = -1;

  /* Start for IfAction SubSystem: '<S115>/Acelerating and braking without Regenerative' */
  /* Start for If: '<S126>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S115>/Acelerating and braking without Regenerative' */
  /* End of Start for SubSystem: '<S72>/VDC Complete' */

  /* Start for IfAction SubSystem: '<S72>/VDC without Longitudinal' */
  /* Start for If: '<S206>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_a = -1;

  /* Start for DataStoreMemory: '<S180>/Data Store Memory1' */
  Torque_Control_DW.B_k = 0.0;

  /* Start for If: '<S175>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubsy_c = -1;

  /* Start for If: '<S174>/If' */
  Torque_Control_DW.If_ActiveSubsystem_h = -1;

  /* Start for IfAction SubSystem: '<S174>/Acelerating and braking without Regenerative' */
  /* Start for If: '<S182>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_b = -1;

  /* End of Start for SubSystem: '<S174>/Acelerating and braking without Regenerative' */
  /* End of Start for SubSystem: '<S72>/VDC without Longitudinal' */

  /* Start for IfAction SubSystem: '<S72>/Steering TV with TC' */
  /* Start for If: '<S103>/SKF or CKF' */
  Torque_Control_DW.SKForCKF_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S103>/SKF' */
  /* Start for If: '<S106>/If' */
  Torque_Control_DW.If_ActiveSubsystem_jm = -1;

  /* End of Start for SubSystem: '<S103>/SKF' */

  /* Start for IfAction SubSystem: '<S103>/CKF' */
  /* Start for If: '<S104>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_ca = -1;

  /* End of Start for SubSystem: '<S103>/CKF' */

  /* Start for DataStoreMemory: '<S93>/Data Store Memory' */
  Torque_Control_DW.A = 0.0;

  /* Start for DataStoreMemory: '<S93>/Data Store Memory1' */
  Torque_Control_DW.B = 0.0;

  /* Start for If: '<S82>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_c = -1;

  /* Start for If: '<S82>/If' */
  Torque_Control_DW.If_ActiveSubsystem_d = -1;

  /* Start for If: '<S87>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubsyst = -1;

  /* End of Start for SubSystem: '<S72>/Steering TV with TC' */
  /* End of Start for SubSystem: '<S12>/Vehicle Dynamics Control Modes' */

  /* Start for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Start for If: '<S15>/If' */
  Torque_Control_DW.If_ActiveSubsystem_kl = -1;

  /* Start for IfAction SubSystem: '<S15>/OK_OrLatch' */
  /* Start for If: '<S17>/If' */
  Torque_Control_DW.If_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S15>/OK_OrLatch' */

  /* Start for DataStoreMemory: '<S15>/Data Store Memory10' */
  Torque_Control_DW.A_i = 0.0;

  /* End of Start for SubSystem: '<S1>/PowerLimitDetection' */

  /* Start for Atomic SubSystem: '<S12>/WORKSHOP_MODE_RESTRICTIONS' */
  /* Start for If: '<S73>/If' */
  Torque_Control_DW.If_ActiveSubsystem_ed = -1;

  /* End of Start for SubSystem: '<S12>/WORKSHOP_MODE_RESTRICTIONS' */

  /* Start for Probe: '<S223>/Probe' */
  Torque_Control_B.Probe[0] = 0.2;
  Torque_Control_B.Probe[1] = 0.0;

  /* Start for Probe: '<S231>/Probe' */
  Torque_Control_B.Probe_d[0] = 0.2;
  Torque_Control_B.Probe_d[1] = 0.0;

  /* Start for Probe: '<S239>/Probe' */
  Torque_Control_B.Probe_j[0] = 0.2;
  Torque_Control_B.Probe_j[1] = 0.0;

  /* Start for If: '<Root>/If' */
  Torque_Control_DW.If_ActiveSubsystem_e = -1;

  /* Start for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' */
  /* Start for Probe: '<S33>/Probe' */
  Torque_Control_B.Probe_a[0] = 0.2;
  Torque_Control_B.Probe_a[1] = 0.0;

  /* Start for Probe: '<S41>/Probe' */
  Torque_Control_B.Probe_o[0] = 0.2;
  Torque_Control_B.Probe_o[1] = 0.0;

  /* Start for Probe: '<S49>/Probe' */
  Torque_Control_B.Probe_n[0] = 0.2;
  Torque_Control_B.Probe_n[1] = 0.0;

  /* End of Start for SubSystem: '<Root>/Controls Temperature by limiting Torque' */

  /* Start for If: '<Root>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem = -1;

  /* InitializeConditions for DiscreteIntegrator: '<S228>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState = 0;
  Torque_Control_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S236>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState_h = 0;
  Torque_Control_DW.Integrator_IC_LOADING_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S244>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState_c = 0;
  Torque_Control_DW.Integrator_IC_LOADING_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S12>/Vehicle Dynamics Control Modes' */
  /* SystemInitialize for IfAction SubSystem: '<S72>/VDC Complete' */
  /* InitializeConditions for Derivative: '<S123>/Derivative' */
  Torque_Control_DW.TimeStampA_g = (rtInf);
  Torque_Control_DW.TimeStampB_c = (rtInf);

  /* SystemInitialize for IfAction SubSystem: '<S158>/SKF' */
  /* SystemInitialize for Merge: '<S161>/Merge' */
  Torque_Control_B.Merge_i = 0.0;

  /* SystemInitialize for Saturate: '<S161>/Saturation' incorporates:
   *  Outport: '<S161>/SKF_act'
   */
  Torque_Control_B.Saturation_f = 0.0;

  /* End of SystemInitialize for SubSystem: '<S158>/SKF' */

  /* SystemInitialize for IfAction SubSystem: '<S158>/CKF' */
  /* SystemInitialize for Merge: '<S159>/Merge' */
  Torque_Control_B.Merge_c = 0.0;

  /* SystemInitialize for Saturate: '<S159>/Saturation' incorporates:
   *  Outport: '<S159>/CKF_act '
   */
  Torque_Control_B.Saturation_i = 0.0;

  /* End of SystemInitialize for SubSystem: '<S158>/CKF' */

  /* SystemInitialize for IfAction SubSystem: '<S83>/Lateral Dynamics' */
  /* InitializeConditions for Integrator: '<S119>/Integrator' */
  Torque_Control_X.Integrator_CSTATE = 0.0;

  /* End of SystemInitialize for SubSystem: '<S83>/Lateral Dynamics' */

  /* SystemInitialize for Merge: '<S83>/Merge2' */
  Torque_Control_B.Merge2_lx = 0.0;

  /* SystemInitialize for Merge: '<S83>/Merge3' */
  Torque_Control_B.Merge3_e = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S116>/Accelerating' */
  /* SystemInitialize for SignalConversion generated from: '<S136>/Throttle' incorporates:
   *  Outport: '<S136>/Out_Throttle'
   */
  Torque_Control_B.Throttle = 0.0;

  /* End of SystemInitialize for SubSystem: '<S116>/Accelerating' */

  /* SystemInitialize for Merge: '<S116>/Merge' */
  Torque_Control_B.Merge_kt = 0.0;

  /* SystemInitialize for Merge: '<S116>/Merge1' */
  Torque_Control_B.Merge1_b = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S115>/Acelerating and braking without Regenerative' */
  /* SystemInitialize for SignalConversion generated from: '<S126>/Flag_Power' */
  Torque_Control_B.OutportBufferForFlag_Power = Torque_Control_ConstB.Constant;

  /* End of SystemInitialize for SubSystem: '<S115>/Acelerating and braking without Regenerative' */

  /* SystemInitialize for Merge: '<S83>/Merge4' */
  Torque_Control_B.Merge4 = 0.0;

  /* SystemInitialize for Merge: '<S83>/Merge5' */
  Torque_Control_B.Merge5 = 0.0;

  /* SystemInitialize for Merge: '<S83>/Merge6' */
  Torque_Control_B.Merge6 = 0.0;

  /* SystemInitialize for Merge: '<S83>/Merge7' */
  Torque_Control_B.Merge7 = 0.0;

  /* SystemInitialize for Product: '<S171>/Divide' incorporates:
   *  Outport: '<S83>/MaxTq_RR [Nm] (0,inf)'
   */
  Torque_Control_B.Divide = 0.0;

  /* SystemInitialize for Product: '<S170>/Divide' incorporates:
   *  Outport: '<S83>/MaxTq_RL [Nm] (0,inf)'
   */
  Torque_Control_B.Divide_i = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S83>/Flags_[num5]' incorporates:
   *  Outport: '<S83>/Flags_[num5]'
   */
  Torque_Control_B.OutportBufferForFlags_num5[0] = 0.0;
  Torque_Control_B.OutportBufferForFlags_num5[1] = 0.0;
  Torque_Control_B.OutportBufferForFlags_num5[2] = 0.0;
  Torque_Control_B.OutportBufferForFlags_num5[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S72>/VDC Complete' */

  /* SystemInitialize for IfAction SubSystem: '<S72>/VDC without Longitudinal' */
  /* InitializeConditions for Derivative: '<S180>/Derivative' */
  Torque_Control_DW.TimeStampA_b = (rtInf);
  Torque_Control_DW.TimeStampB_e = (rtInf);

  /* SystemInitialize for Merge: '<S206>/Merge' */
  Torque_Control_B.Merge_g = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S175>/Accelerating' */
  /* SystemInitialize for Outport: '<S191>/Out_Throttle' */
  Torque_Control_B.sf_Acceleratorbehaviour_b.throttle = 0.0;

  /* End of SystemInitialize for SubSystem: '<S175>/Accelerating' */

  /* SystemInitialize for Merge: '<S175>/Merge' */
  Torque_Control_B.Merge_li = 0.0;

  /* SystemInitialize for Merge: '<S175>/Merge1' */
  Torque_Control_B.Merge1_l = 0.0;

  /* SystemInitialize for Outport: '<S84>/MaxFx_RR [N] (0,inf)' */
  Torque_Control_B.sf_MATLABFunction2_b.value = 0.0;

  /* SystemInitialize for Outport: '<S84>/MaxFx_RL [N] (0,inf)' */
  Torque_Control_B.sf_MATLABFunction1_f.value = 0.0;

  /* End of SystemInitialize for SubSystem: '<S72>/VDC without Longitudinal' */

  /* SystemInitialize for IfAction SubSystem: '<S72>/Steering TV with TC' */
  /* InitializeConditions for Derivative: '<S93>/Derivative' */
  Torque_Control_DW.TimeStampA = (rtInf);
  Torque_Control_DW.TimeStampB = (rtInf);

  /* SystemInitialize for IfAction SubSystem: '<S103>/SKF' */
  /* SystemInitialize for Merge: '<S106>/Merge' */
  Torque_Control_B.Merge_kj = 0.0;

  /* SystemInitialize for Saturate: '<S106>/Saturation' incorporates:
   *  Outport: '<S106>/SKF_act'
   */
  Torque_Control_B.Saturation_k = 0.0;

  /* End of SystemInitialize for SubSystem: '<S103>/SKF' */

  /* SystemInitialize for IfAction SubSystem: '<S103>/CKF' */
  /* SystemInitialize for Merge: '<S104>/Merge' */
  Torque_Control_B.Merge_k = 0.0;

  /* SystemInitialize for Saturate: '<S104>/Saturation' incorporates:
   *  Outport: '<S104>/CKF_act '
   */
  Torque_Control_B.Saturation_c = 0.0;

  /* End of SystemInitialize for SubSystem: '<S103>/CKF' */

  /* SystemInitialize for Merge: '<S87>/Merge' */
  Torque_Control_B.Merge_d = 0.0;

  /* SystemInitialize for Merge: '<S87>/Merge1' */
  Torque_Control_B.Merge1_p = 0.0;

  /* End of SystemInitialize for SubSystem: '<S72>/Steering TV with TC' */

  /* SystemInitialize for Merge: '<S72>/Merge Tq_RL' */
  Torque_Control_B.MergeTq_RL = 0.0;

  /* SystemInitialize for Merge: '<S72>/Merge Tq_RR' */
  Torque_Control_B.MergeTq_RR = 0.0;

  /* SystemInitialize for Merge: '<S72>/Merge2' */
  Torque_Control_B.Merge2_l = 0.0;

  /* SystemInitialize for Merge: '<S72>/Merge3' */
  Torque_Control_B.Merge3_c = 0.0;

  /* End of SystemInitialize for SubSystem: '<S12>/Vehicle Dynamics Control Modes' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' */
  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState_b = 0;
  Torque_Control_DW.Integrator_IC_LOADING_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState_f = 0;
  Torque_Control_DW.Integrator_IC_LOADING_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Integrator' */
  Torque_Control_DW.Integrator_PrevResetState_j = 0;
  Torque_Control_DW.Integrator_IC_LOADING_e = 1U;

  /* SystemInitialize for RelationalOperator: '<S25>/Compare' incorporates:
   *  Outport: '<S3>/Accu_Temperature_Limitation_Flag'
   */
  Torque_Control_B.Compare_f = false;

  /* SystemInitialize for RelationalOperator: '<S26>/Compare' incorporates:
   *  Outport: '<S3>/Inverters_Temperature_Limitation_Flag'
   */
  Torque_Control_B.Compare_d = false;

  /* SystemInitialize for RelationalOperator: '<S27>/Compare' incorporates:
   *  Outport: '<S3>/Motors_Temperature_Limitation_Flag'
   */
  Torque_Control_B.Compare_g = false;

  /* End of SystemInitialize for SubSystem: '<Root>/Controls Temperature by limiting Torque' */
}

/* Model terminate function */
void Torque_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

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
    rtsiSetdXPtr(&Torque_Control_M->solverInfo, &Torque_Control_M->derivs);
    rtsiSetContStatesPtr(&Torque_Control_M->solverInfo, (real_T **)
                         &Torque_Control_M->contStates);
    rtsiSetNumContStatesPtr(&Torque_Control_M->solverInfo,
      &Torque_Control_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Torque_Control_M->solverInfo,
      &Torque_Control_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Torque_Control_M->solverInfo,
      &Torque_Control_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Torque_Control_M->solverInfo,
      &Torque_Control_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Torque_Control_M->solverInfo, (&rtmGetErrorStatus
      (Torque_Control_M)));
    rtsiSetRTModelPtr(&Torque_Control_M->solverInfo, Torque_Control_M);
  }

  rtsiSetSimTimeStep(&Torque_Control_M->solverInfo, MAJOR_TIME_STEP);
  Torque_Control_M->intgData.y = Torque_Control_M->odeY;
  Torque_Control_M->intgData.f[0] = Torque_Control_M->odeF[0];
  Torque_Control_M->intgData.f[1] = Torque_Control_M->odeF[1];
  Torque_Control_M->intgData.f[2] = Torque_Control_M->odeF[2];
  Torque_Control_M->contStates = ((real_T *) &Torque_Control_X);
  rtsiSetSolverData(&Torque_Control_M->solverInfo, (void *)
                    &Torque_Control_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Torque_Control_M->solverInfo, false);
  rtsiSetSolverName(&Torque_Control_M->solverInfo,"ode3");

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

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Torque_Control_X;
    Torque_Control_M->contStates = (x);
    (void) memset((void *)&Torque_Control_X, 0,
                  sizeof(X_Torque_Control_T));
  }

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
  Torque_Control_M->Sizes.numContStates = (1);/* Number of continuous states */
  Torque_Control_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Torque_Control_M->Sizes.numY = (29); /* Number of model outputs */
  Torque_Control_M->Sizes.numU = (42); /* Number of model inputs */
  Torque_Control_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Torque_Control_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Torque_Control_M->Sizes.numBlocks = (752);/* Number of blocks */
  Torque_Control_M->Sizes.numBlockIO = (136);/* Number of block outputs */
  return Torque_Control_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
