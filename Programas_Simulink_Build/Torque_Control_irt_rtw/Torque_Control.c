/*
 * Torque_Control.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 1.182
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Jun 10 14:35:54 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_Control.h"
#include "Torque_Control_private.h"
#include "look1_binlxpw.h"
#include "mldivide_u4svSR16.h"
#include "polyfit_vYlRX3XP.h"

/* Block signals (auto storage) */
B_Torque_Control_T Torque_Control_B;

/* Continuous states */
X_Torque_Control_T Torque_Control_X;

/* Block states (auto storage) */
DW_Torque_Control_T Torque_Control_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Torque_Control_T Torque_Control_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Torque_Control_T Torque_Control_Y;

/* Real-time model */
RT_MODEL_Torque_Control_T Torque_Control_M_;
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
 *    '<S17>/LimitReached'
 *    '<S19>/Latched Error'
 *    '<S19>/OK'
 */
void Torque_Control_LimitReached(real_T *rty_Out,
  P_LimitReached_Torque_Control_T *localP)
{
  if (1) {
    /* SignalConversion: '<S18>/OutportBufferForOut ' incorporates:
     *  Constant: '<S18>/Constant'
     */
    *rty_Out = localP->Constant_Value;
  }
}

/*
 * Output and update for action system:
 *    '<S42>/Imp'
 *    '<S42>/Not Imp'
 *    '<S43>/Imp1'
 *    '<S43>/Not Imp1'
 *    '<S43>/Imp Memo1'
 *    '<S43>/Not Imp Memo1'
 */
void Torque_Control_Imp(boolean_T *rty_Out1, P_Imp_Torque_Control_T *localP)
{
  if (1) {
    /* SignalConversion: '<S46>/OutportBufferForOut1' incorporates:
     *  Constant: '<S46>/Constant'
     */
    *rty_Out1 = localP->Constant_Value;
  }
}

/*
 * Output and update for action system:
 *    '<S43>/If Action Subsystem2'
 *    '<S43>/If Action Subsystem3'
 */
void Torque_Contr_IfActionSubsystem2(real_T *rty_Out1,
  P_IfActionSubsystem2_Torque_C_T *localP)
{
  if (1) {
    /* SignalConversion: '<S48>/OutportBufferForOut1' incorporates:
     *  Constant: '<S48>/Constant'
     */
    *rty_Out1 = localP->Constant_Value;
  }
}

/*
 * Output and update for atomic system:
 *    '<S122>/MATLAB Function'
 *    '<S178>/MATLAB Function'
 *    '<S94>/MATLAB Function1'
 */
void Torque_Control_MATLABFunction(real_T rtu_MaxRegenTq, real_T rtu_Tq_RR,
  real_T rtu_Tq_RL, B_MATLABFunction_Torque_Contr_T *localB)
{
  localB->RegTq_RR = 0.0;
  localB->RegTq_RL = 0.0;
  if ((rtu_Tq_RR == 0.0) && (rtu_Tq_RL == 0.0)) {
    localB->RegTq_RR = 0.0;
    localB->RegTq_RL = 0.0;
  } else if ((rtu_Tq_RR != 0.0) && (rtu_Tq_RL == 0.0)) {
    localB->RegTq_RR = 0.0;
    localB->RegTq_RL = rtu_Tq_RR;
  } else if ((rtu_Tq_RR == 0.0) && (rtu_Tq_RL != 0.0)) {
    localB->RegTq_RR = rtu_Tq_RL;
    localB->RegTq_RL = 0.0;
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
  } else {
    if (rtu_Tq_RR < rtu_Tq_RL) {
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
 *    '<S110>/Braking with Regenerative'
 *    '<S169>/Braking with Regenerative'
 */
void Torque__BrakingwithRegenerative(real_T rtu_MaxRegTorque, real_T
  rtu_Tq_RR_wc, real_T rtu_Tq_RL_wc, real_T *rty_TQ_RR, real_T *rty_TQ_RL,
  B_BrakingwithRegenerative_Tor_T *localB, P_BrakingwithRegenerative_Tor_T
  *localP)
{
  /* MATLAB Function: '<S122>/MATLAB Function' */
  Torque_Control_MATLABFunction(rtu_MaxRegTorque, rtu_Tq_RR_wc, rtu_Tq_RL_wc,
    &localB->sf_MATLABFunction);

  /* Gain: '<S122>/Gain' */
  *rty_TQ_RR = localP->Gain_Gain * localB->sf_MATLABFunction.RegTq_RR;

  /* Gain: '<S122>/Gain1' */
  *rty_TQ_RL = localP->Gain1_Gain * localB->sf_MATLABFunction.RegTq_RL;
}

/*
 * Output and update for action system:
 *    '<S121>/If Action 1'
 *    '<S177>/If Action 1'
 */
void Torque_Control_IfAction1(real_T rtu_Trans_max_dynamic, real_T
  *rty_Trans_limit)
{
  if (1) {
    /* Inport: '<S123>/Trans_max_dynamic' */
    *rty_Trans_limit = rtu_Trans_max_dynamic;
  }
}

/*
 * Output and update for action system:
 *    '<S121>/If Action 2'
 *    '<S177>/If Action 2'
 */
void Torque_Control_IfAction2(real_T rtu_Trans_max_static, real_T
  *rty_Trans_limit)
{
  if (1) {
    /* Inport: '<S124>/Trans_max_static ' */
    *rty_Trans_limit = rtu_Trans_max_static;
  }
}

/*
 * Output and update for atomic system:
 *    '<S111>/Accelerator behaviour '
 *    '<S186>/Accelerator behaviour '
 *    '<S77>/Accelerator behaviour'
 *    '<S80>/Accelerator behaviour '
 */
void Torque_Con_Acceleratorbehaviour(real_T rtu_Ap, real_T rtu_Ap_Sat_up, real_T
  rtu_Ap_Sat_down, B_Acceleratorbehaviour_Torque_T *localB)
{
  real_T throttle_tmp;
  if (rtu_Ap <= rtu_Ap_Sat_down) {
    localB->throttle = 0.0;
  } else if (rtu_Ap >= rtu_Ap_Sat_up) {
    localB->throttle = 1.0;
  } else {
    throttle_tmp = rtu_Ap_Sat_up - rtu_Ap_Sat_down;
    localB->throttle = 1.0 / throttle_tmp * rtu_Ap + (1.0 - rtu_Ap_Sat_up /
      throttle_tmp);
  }
}

/*
 * Output and update for action system:
 *    '<S111>/Mech_Braking'
 *    '<S111>/Inertia Braking'
 *    '<S170>/Mech_Braking'
 *    '<S170>/Inertia Braking'
 *    '<S82>/Mech_Braking'
 *    '<S82>/Inertia Braking'
 */
void Torque_Control_Mech_Braking(real_T *rty_Tq_RR, real_T *rty_Tq_RL,
  P_Mech_Braking_Torque_Control_T *localP)
{
  if (1) {
    /* SignalConversion: '<S134>/OutportBufferForTq_RR  ' incorporates:
     *  Constant: '<S134>/Constant'
     */
    *rty_Tq_RR = localP->Constant_Value;

    /* SignalConversion: '<S134>/OutportBufferForTq_RL' incorporates:
     *  Constant: '<S134>/Constant1'
     */
    *rty_Tq_RL = localP->Constant1_Value;
  }
}

/*
 * Output and update for atomic system:
 *    '<S78>/MATLAB Function1'
 *    '<S78>/MATLAB Function2'
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
 *    '<S118>/MATLAB Function'
 *    '<S175>/MATLAB Function'
 *    '<S88>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_n(real_T rtu_RPM_INV1, real_T rtu_RPM_INV2,
  B_MATLABFunction_Torque_Con_d_T *localB)
{
  localB->RPM = fmax(rtu_RPM_INV1, rtu_RPM_INV2);
}

/*
 * Output and update for atomic system:
 *    '<S161>/MATLAB Function'
 *    '<S106>/MATLAB Function'
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
 *    '<S158>/MATLAB Function'
 *    '<S203>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_m(real_T rtu_CKF_Initial, real_T rtu_CKF_prev,
  B_MATLABFunction_Torque_Con_k_T *localB)
{
  localB->CKF_act1 = fmin(rtu_CKF_prev, rtu_CKF_Initial);
}

/*
 * Output and update for atomic system:
 *    '<S157>/MATLAB Function1'
 *    '<S202>/MATLAB Function'
 *    '<S102>/MATLAB Function'
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
 *    '<S115>/MATLAB Function'
 *    '<S115>/MATLAB Function1'
 *    '<S114>/MATLAB Function1'
 *    '<S114>/MATLAB Function2'
 *    '<S171>/MATLAB Function1'
 *    '<S171>/MATLAB Function2'
 *    '<S173>/MATLAB Function1'
 *    '<S173>/MATLAB Function2'
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
 *    '<S120>/MATLAB Function1'
 *    '<S120>/MATLAB Function2'
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
 *    '<S67>/Automatic Failure Mode'
 *    '<S67>/Manual Failure Mode Selection'
 *    '<S65>/Enabled '
 *    '<S65>/NotEnabled'
 */
void Torque_Con_AutomaticFailureMode(real_T rtu_In1, real_T *rty_Out1)
{
  if (1) {
    /* Inport: '<S73>/In1' */
    *rty_Out1 = rtu_In1;
  }
}

/* Model output function */
void Torque_Control_output(void)
{
  /* local block i/o variables */
  real_T rtb_Abs3;
  real_T rtb_Abs2;
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
  boolean_T rtb_Merge3_d;
  boolean_T rtb_Merge4;
  real_T *lastU;
  real_T Mz;
  real_T k;
  real_T p;
  real_T my;
  real_T My;
  real_T a[3];
  real_T b_a[2];
  real_T A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  int8_T rtAction;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator2;
  real_T rtb_Gain;
  real_T rtb_Abs1;
  real_T rtb_Abs4;
  real_T rtb_Gain_f;
  real_T rtb_Merge_d;
  real_T rtb_Merge3;
  real_T rtb_Merge;
  real_T rtb_Subtract1;
  real_T rtb_Merge_n;
  real_T rtb_Merge1_l;
  real_T rtb_alpha_j;
  real_T rtb_value_g;
  real_T rtb_min_f;
  real_T tmp[12];
  real_T kamm_data[4];
  real_T kamm_data_0[2];
  real_T kamm_data_1[2];
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

  /* If: '<S43>/If2' incorporates:
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Inport: '<Root>/BrakeSensor_Value'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!(((Torque_Control_U.APPS1_Value > 0.25) &&
                          (Torque_Control_U.BrakeSensor_Value > 0.25)) ||
                         ((Torque_Control_U.APPS2_Value > 0.25) &&
                          (Torque_Control_U.BrakeSensor_Value > 0.25)));
    Torque_Control_DW.If2_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_DW.If2_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S43>/Imp1' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    Torque_Control_Imp(&rtb_Merge3_d, &Torque_Control_P.Imp1);

    /* End of Outputs for SubSystem: '<S43>/Imp1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S43>/Not Imp1' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    Torque_Control_Imp(&rtb_Merge3_d, &Torque_Control_P.NotImp1);

    /* End of Outputs for SubSystem: '<S43>/Not Imp1' */
    break;
  }

  /* End of If: '<S43>/If2' */

  /* If: '<S43>/If3' incorporates:
   *  DataStoreRead: '<S43>/Data Store Read1'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!Torque_Control_DW.AA;
    Torque_Control_DW.If3_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_DW.If3_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    Torque_Contr_IfActionSubsystem2(&Torque_Control_B.Merge5,
      &Torque_Control_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem2' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S43>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    Torque_Contr_IfActionSubsystem2(&Torque_Control_B.Merge5,
      &Torque_Control_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S43>/If Action Subsystem3' */
    break;
  }

  /* End of If: '<S43>/If3' */

  /* If: '<S43>/MEMO1' incorporates:
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!(((Torque_Control_B.Merge5 == 0.0) &&
                          (Torque_Control_U.APPS1_Value > 0.05)) ||
                         ((Torque_Control_B.Merge5 == 0.0) &&
                          (Torque_Control_U.APPS2_Value > 0.05)));
    Torque_Control_DW.MEMO1_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_DW.MEMO1_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S43>/Imp Memo1' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    Torque_Control_Imp(&rtb_Merge4, &Torque_Control_P.ImpMemo1);

    /* End of Outputs for SubSystem: '<S43>/Imp Memo1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S43>/Not Imp Memo1' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    Torque_Control_Imp(&rtb_Merge4, &Torque_Control_P.NotImpMemo1);

    /* End of Outputs for SubSystem: '<S43>/Not Imp Memo1' */
    break;
  }

  /* End of If: '<S43>/MEMO1' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Logic: '<S43>/Logical Operator1' */
    Torque_Control_B.LogicalOperator1 = (rtb_Merge3_d && rtb_Merge4);

    /* DataStoreWrite: '<S43>/Data Store Write1' */
    Torque_Control_DW.AA = Torque_Control_B.LogicalOperator1;
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&Torque_Control_M->solverInfo,
        true);
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&Torque_Control_M->solverInfo, true);
    }

    /* End of DataStoreWrite: '<S43>/Data Store Write1' */
  }

  /* If: '<S42>/If' incorporates:
   *  Abs: '<S42>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S42>/Sum'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!(fabs(Torque_Control_U.APPS1_Value -
      Torque_Control_U.APPS2_Value) > 0.25);
    Torque_Control_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S42>/Imp' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    Torque_Control_Imp(&Torque_Control_B.Merge_j, &Torque_Control_P.Imp);

    /* End of Outputs for SubSystem: '<S42>/Imp' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S42>/Not Imp' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    Torque_Control_Imp(&Torque_Control_B.Merge_j, &Torque_Control_P.NotImp);

    /* End of Outputs for SubSystem: '<S42>/Not Imp' */
    break;
  }

  /* End of If: '<S42>/If' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Constant: '<S44>/Constant' */
    Torque_Control_B.Constant = Torque_Control_P.CompareToConstant_const;
  }

  /* Logic: '<S11>/Logical Operator' incorporates:
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/ShutdownClosed'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S11>/NOT'
   *  RelationalOperator: '<S44>/Compare'
   */
  Torque_Control_B.LogicalOperator = (Torque_Control_U.ShutdownClosed &&
    Torque_Control_U.TorqueEnable && (!Torque_Control_U.CriticalDisconnection) &&
    (Torque_Control_U.Car_State == Torque_Control_B.Constant) &&
    Torque_Control_B.Merge_j && Torque_Control_B.LogicalOperator1);
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Logic: '<S11>/Logical Operator1' */
    rtb_LogicalOperator1 = !Torque_Control_B.Merge_j;

    /* Logic: '<S11>/Logical Operator2' */
    rtb_LogicalOperator2 = !Torque_Control_B.LogicalOperator1;

    /* Constant: '<Root>/Constant14' */
    Torque_Control_B.Constant14 = Torque_Control_P.Constant14_Value;

    /* Gain: '<S13>/Gain' incorporates:
     *  Constant: '<S13>/half range'
     *  Constant: '<S13>/range'
     *  Constant: '<S13>/zero'
     *  Inport: '<Root>/SteeringSensor_Bits'
     *  Product: '<S13>/Divide'
     *  Sum: '<S13>/Sum'
     */
    rtb_Gain = (Torque_Control_U.SteeringSensor_Bits -
                Torque_Control_P.zero_Value) * Torque_Control_P.halfrange_Value /
      Torque_Control_P.range_Value * Torque_Control_P.Gain_Gain_o;
  }

  /* Outputs for Atomic SubSystem: '<S13>/Low Pass' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Constant: '<S54>/exp(-tcycle//tau)1' */
    Torque_Control_B.exptcycletau1 = Torque_Control_P.exptcycletau1_Value;

    /* Sum: '<S54>/Subtract' incorporates:
     *  Constant: '<S54>/ct'
     */
    Torque_Control_B.Subtract = Torque_Control_B.exptcycletau1 -
      Torque_Control_P.ct_Value;
  }

  /* Sum: '<S54>/Subtract1' incorporates:
   *  DataStoreRead: '<S54>/Data Store Read'
   *  DataStoreRead: '<S54>/Data Store Read1'
   *  Product: '<S54>/Product'
   *  Product: '<S54>/Product1'
   */
  rtb_Subtract1 = Torque_Control_DW.Previous_IN * Torque_Control_B.Subtract +
    Torque_Control_B.exptcycletau1 * Torque_Control_DW.Previous_OUT;

  /* DataStoreWrite: '<S54>/Data Store Write1' */
  Torque_Control_DW.Previous_OUT = rtb_Subtract1;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* DataStoreWrite: '<S54>/Data Store Write' */
    Torque_Control_DW.Previous_IN = rtb_Gain;
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&Torque_Control_M->solverInfo,
        true);
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&Torque_Control_M->solverInfo, true);
    }

    /* End of DataStoreWrite: '<S54>/Data Store Write' */
  }

  /* Gain: '<S54>/Gain' */
  rtb_Gain_f = Torque_Control_P.Gain_Gain_c * rtb_Subtract1;

  /* End of Outputs for SubSystem: '<S13>/Low Pass' */

  /* Abs: '<S14>/Abs1' incorporates:
   *  Inport: '<Root>/ACCEL_F_Y_SI'
   */
  rtb_Abs1 = fabs(Torque_Control_U.ACCEL_F_Y_SI);

  /* Abs: '<S14>/Abs4' incorporates:
   *  Inport: '<Root>/ACCEL_R_Y_SI'
   */
  rtb_Abs4 = fabs(Torque_Control_U.ACCEL_R_Y_SI);

  /* Outputs for Atomic SubSystem: '<S14>/TEST_MODE_IN' */
  /* If: '<S66>/If' incorporates:
   *  Inport: '<Root>/Susp_F_L'
   *  Inport: '<Root>/Susp_F_R'
   *  Inport: '<Root>/Susp_R_L'
   *  Inport: '<Root>/Susp_R_R'
   *  Inport: '<Root>/Workshop_Mode_Enable'
   *  Inport: '<S71>/In1'
   *  Inport: '<S71>/In2'
   *  Inport: '<S71>/In3'
   *  Inport: '<S71>/In4'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!(Torque_Control_U.Workshop_Mode_Enable == 1.0);
    Torque_Control_DW.If_ActiveSubsystem_a = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_a;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S66>/TEST_CONSTANTS' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      /* SignalConversion: '<S72>/OutportBufferForOut1' incorporates:
       *  Constant: '<S72>/Constant'
       */
      Torque_Control_B.Merge = Torque_Control_P.Constant_Value_k4;

      /* SignalConversion: '<S72>/OutportBufferForOut2' incorporates:
       *  Constant: '<S72>/Constant1'
       */
      Torque_Control_B.Merge1 = Torque_Control_P.Constant1_Value_ln;

      /* SignalConversion: '<S72>/OutportBufferForOut3' incorporates:
       *  Constant: '<S72>/Constant2'
       */
      Torque_Control_B.Merge2 = Torque_Control_P.Constant2_Value_g1;

      /* SignalConversion: '<S72>/OutportBufferForOut4' incorporates:
       *  Constant: '<S72>/Constant3'
       */
      Torque_Control_B.Merge3 = Torque_Control_P.Constant3_Value_n;
    }

    /* End of Outputs for SubSystem: '<S66>/TEST_CONSTANTS' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S66>/BYPASS' incorporates:
     *  ActionPort: '<S71>/Action Port'
     */
    Torque_Control_B.Merge = Torque_Control_U.Susp_F_R;
    Torque_Control_B.Merge1 = Torque_Control_U.Susp_F_L;
    Torque_Control_B.Merge2 = Torque_Control_U.Susp_R_L;
    Torque_Control_B.Merge3 = Torque_Control_U.Susp_R_R;

    /* End of Outputs for SubSystem: '<S66>/BYPASS' */
    break;
  }

  /* End of If: '<S66>/If' */
  /* End of Outputs for SubSystem: '<S14>/TEST_MODE_IN' */

  /* Abs: '<Root>/Abs' incorporates:
   *  Inport: '<Root>/Vel_RR_kmh'
   */
  rtb_Gain = fabs(Torque_Control_U.Vel_RR_kmh);

  /* Abs: '<Root>/Abs1' incorporates:
   *  Inport: '<Root>/Vel_RL_kmh'
   */
  rtb_Subtract1 = fabs(Torque_Control_U.Vel_RL_kmh);

  /* Outputs for Atomic SubSystem: '<S14>/Regeneration_Enable' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Constant: '<S65>/Constant' */
    Torque_Control_B.Constant_o = Torque_Control_P.Constant_Value_m;

    /* Constant: '<S65>/Enabled' */
    Torque_Control_B.Enabled_a = Torque_Control_P.Enabled_Value;

    /* Constant: '<S65>/Zero ' */
    Torque_Control_B.Zero = Torque_Control_P.Zero_Value;
  }

  /* If: '<S65>/If' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!((rtb_Gain > 2.0) && (rtb_Subtract1 > 2.0));
    Torque_Control_DW.If_ActiveSubsystem_o = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_o;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S65>/Enabled ' incorporates:
     *  ActionPort: '<S69>/Action Port'
     */
    Torque_Con_AutomaticFailureMode(Torque_Control_B.Enabled_a,
      &Torque_Control_B.Merge1_a);

    /* End of Outputs for SubSystem: '<S65>/Enabled ' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S65>/NotEnabled' incorporates:
     *  ActionPort: '<S70>/Action Port'
     */
    Torque_Con_AutomaticFailureMode(Torque_Control_B.Zero,
      &Torque_Control_B.Merge1_a);

    /* End of Outputs for SubSystem: '<S65>/NotEnabled' */
    break;
  }

  /* End of If: '<S65>/If' */
  /* End of Outputs for SubSystem: '<S14>/Regeneration_Enable' */

  /* Abs: '<Root>/Abs3' incorporates:
   *  Inport: '<Root>/RR_rads'
   */
  rtb_Abs3 = fabs(Torque_Control_U.RR_rads);

  /* Abs: '<Root>/Abs2' incorporates:
   *  Inport: '<Root>/RL_rads'
   */
  rtb_Abs2 = fabs(Torque_Control_U.RL_rads);

  /* Gain: '<Root>/Transmission Gear Ratio' incorporates:
   *  Inport: '<Root>/VDC_Max_Regenerative_Torque'
   */
  rtb_TransmissionGearRatio = Torque_Control_P.TransmissionGearRatio_Gain *
    Torque_Control_U.VDC_Max_Regenerative_Torque;

  /* If: '<S14>/If' incorporates:
   *  Constant: '<S67>/Constant'
   *  Constant: '<S67>/Steering Wheel Saturation (per site) [deg] '
   */
  rtAction = -1;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    if (Torque_Control_B.LogicalOperator) {
      rtAction = 0;
    }

    Torque_Control_DW.If_ActiveSubsystem_k = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_k;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S14>/Vehicle Dynamics Control Modes' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      Torque_Control_B.Constant_aq = Torque_Control_P.Constant_Value_k;
    }

    /* If: '<S67>/If' incorporates:
     *  Constant: '<S67>/Constant'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      rtAction = (int8_T)!(Torque_Control_B.Constant_aq == 5.0);
      Torque_Control_DW.If_ActiveSubsystem_j = rtAction;
    } else {
      rtAction = Torque_Control_DW.If_ActiveSubsystem_j;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S67>/Automatic Failure Mode' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      Torque_Con_AutomaticFailureMode(Torque_Control_B.Constant14,
        &Torque_Control_B.Merge_l);

      /* End of Outputs for SubSystem: '<S67>/Automatic Failure Mode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S67>/Manual Failure Mode Selection' incorporates:
       *  ActionPort: '<S75>/Action Port'
       */
      Torque_Con_AutomaticFailureMode(Torque_Control_B.Constant_aq,
        &Torque_Control_B.Merge_l);

      /* End of Outputs for SubSystem: '<S67>/Manual Failure Mode Selection' */
      break;
    }

    /* End of If: '<S67>/If' */

    /* Gain: '<S67>/Gain' */
    Torque_Control_B.Gain = Torque_Control_P.Gain_Gain_f * rtb_Gain_f;
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      Torque_Control_B.SteeringWheelSaturationpersited =
        Torque_Control_P.SteeringWheelSaturationpersited;
    }

    /* If: '<S67>/FAILURE MODE' incorporates:
     *  Constant: '<S113>/Constant1'
     *  Constant: '<S113>/Maximum Torque per engine [Nm]'
     *  Constant: '<S113>/Maximum Transmission Torque Dynamic [Nm]'
     *  Constant: '<S113>/Maximum Transmission Torque Static [Nm]'
     *  Constant: '<S113>/Tq_diff_Max'
     *  Constant: '<S113>/Transmision Ratio[-]'
     *  Constant: '<S120>/Constant'
     *  Constant: '<S120>/Constant1'
     *  Constant: '<S153>/Steering Wheel Maximum Angle'
     *  Constant: '<S171>/Constant'
     *  Constant: '<S171>/Constant1'
     *  Constant: '<S173>/Constant'
     *  Constant: '<S173>/Constant1'
     *  Constant: '<S67>/Steering Wheel Saturation (per site) [deg] '
     *  Constant: '<S77>/Steering Wheel Maximum Angle'
     *  Constant: '<S77>/Tq_diff_max [Nm]'
     *  Constant: '<S77>/Tq_max_motor [Nm]'
     *  Constant: '<S78>/Constant'
     *  Constant: '<S98>/Steering Wheel Maximum Angle'
     */
    rtAction = -1;
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      if (Torque_Control_B.Merge_l == 1.0) {
        rtAction = 0;
      } else if (Torque_Control_B.Merge_l == 2.0) {
        rtAction = 1;
      } else if (Torque_Control_B.Merge_l == 3.0) {
        rtAction = 2;
      } else if (Torque_Control_B.Merge_l == 4.0) {
        rtAction = 3;
      } else {
        if (Torque_Control_B.Merge_l == 0.0) {
          rtAction = 4;
        }
      }

      Torque_Control_DW.FAILUREMODE_ActiveSubsystem = rtAction;
    } else {
      rtAction = Torque_Control_DW.FAILUREMODE_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S67>/VDC Complete' incorporates:
       *  ActionPort: '<S78>/Action Port'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        Torque_Control_B.SteeringWheelMaximumAngle_p =
          Torque_Control_P.SteeringWheelMaximumAngle_Value;
      }

      /* MATLAB Function: '<S153>/MATLAB Function1' incorporates:
       *  Constant: '<S153>/Steering Wheel Maximum Angle'
       */
      if (Torque_Control_B.Gain > Torque_Control_B.SteeringWheelMaximumAngle_p)
      {
        rtb_value_g = Torque_Control_B.SteeringWheelMaximumAngle_p;
      } else if (Torque_Control_B.Gain <
                 -Torque_Control_B.SteeringWheelMaximumAngle_p) {
        rtb_value_g = -Torque_Control_B.SteeringWheelMaximumAngle_p;
      } else {
        rtb_value_g = Torque_Control_B.Gain;
      }

      /* End of MATLAB Function: '<S153>/MATLAB Function1' */

      /* MATLAB Function: '<S118>/MATLAB Function' */
      Torque_Control_MATLABFunction_n(rtb_Abs2, rtb_Abs3,
        &Torque_Control_B.sf_MATLABFunction_n);

      /* Derivative: '<S118>/Derivative' */
      if ((Torque_Control_DW.TimeStampA_g >= Torque_Control_M->Timing.t[0]) &&
          (Torque_Control_DW.TimeStampB_c >= Torque_Control_M->Timing.t[0])) {
        rtb_alpha_j = 0.0;
      } else {
        p = Torque_Control_DW.TimeStampA_g;
        lastU = &Torque_Control_DW.LastUAtTimeA_c;
        if (Torque_Control_DW.TimeStampA_g < Torque_Control_DW.TimeStampB_c) {
          if (Torque_Control_DW.TimeStampB_c < Torque_Control_M->Timing.t[0]) {
            p = Torque_Control_DW.TimeStampB_c;
            lastU = &Torque_Control_DW.LastUAtTimeB_f;
          }
        } else {
          if (Torque_Control_DW.TimeStampA_g >= Torque_Control_M->Timing.t[0]) {
            p = Torque_Control_DW.TimeStampB_c;
            lastU = &Torque_Control_DW.LastUAtTimeB_f;
          }
        }

        rtb_alpha_j = (Torque_Control_B.sf_MATLABFunction_n.RPM - *lastU) /
          (Torque_Control_M->Timing.t[0] - p);
      }

      /* End of Derivative: '<S118>/Derivative' */

      /* If: '<S153>/SKF or CKF' */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        rtAction = (int8_T)!((-10.0 < rtb_value_g) && (rtb_value_g < 10.0));
        Torque_Control_DW.SKForCKF_ActiveSubsystem_o = rtAction;
      } else {
        rtAction = Torque_Control_DW.SKForCKF_ActiveSubsystem_o;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S153>/SKF' incorporates:
         *  ActionPort: '<S156>/Action Port'
         */
        /* If: '<S156>/If' incorporates:
         *  Constant: '<S162>/Constant'
         */
        rtAction = -1;
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          if (rtb_alpha_j >= 900.0) {
            rtAction = 0;
          } else {
            if (rtb_alpha_j < 900.0) {
              rtAction = 1;
            }
          }

          Torque_Control_DW.If_ActiveSubsystem_ha = rtAction;
        } else {
          rtAction = Torque_Control_DW.If_ActiveSubsystem_ha;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S156>/Spin' incorporates:
           *  ActionPort: '<S162>/Action Port'
           */
          if (rtmIsMajorTimeStep(Torque_Control_M)) {
            Torque_Control_B.Constant_k = Torque_Control_P.Constant_Value_a;
          }

          /* Switch: '<S162>/Switch1' incorporates:
           *  Constant: '<S162>/Constant'
           *  DataStoreRead: '<S118>/SKF_prev '
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          if (Torque_Control_DW.A_b > Torque_Control_P.Switch1_Threshold) {
            p = Torque_Control_DW.A_b;
          } else {
            p = Torque_Control_U.VDC_SKF_Initial;
          }

          /* End of Switch: '<S162>/Switch1' */

          /* Switch: '<S162>/Switch' incorporates:
           *  Inport: '<Root>/VDC_Cte_CKF'
           */
          if (Torque_Control_U.VDC_Cte_CKF >= Torque_Control_P.Switch_Threshold)
          {
            my = Torque_Control_U.VDC_Cte_CKF;
          } else {
            my = Torque_Control_B.Constant_k;
          }

          /* End of Switch: '<S162>/Switch' */

          /* SignalConversion: '<S162>/OutportBufferForSKF_act1' incorporates:
           *  Inport: '<Root>/VDC_SKF_Initial'
           *  MATLAB Function: '<S162>/MATLAB Function'
           *  Product: '<S162>/Product'
           */
          Torque_Control_B.Merge_i = fmin(p * my,
            Torque_Control_U.VDC_SKF_Initial);

          /* End of Outputs for SubSystem: '<S156>/Spin' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S156>/No spin' incorporates:
           *  ActionPort: '<S161>/Action Port'
           */
          /* Switch: '<S161>/Switch1' incorporates:
           *  DataStoreRead: '<S118>/SKF_prev '
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          if (Torque_Control_DW.A_b > Torque_Control_P.Switch1_Threshold_f) {
            rtb_Switch1_c = Torque_Control_DW.A_b;
          } else {
            rtb_Switch1_c = Torque_Control_U.VDC_SKF_Initial;
          }

          /* End of Switch: '<S161>/Switch1' */

          /* MATLAB Function: '<S161>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_Cte_CKF'
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          Torque_Control_MATLABFunction_e(rtb_Switch1_c,
            Torque_Control_U.VDC_SKF_Initial, Torque_Control_U.VDC_Cte_CKF,
            &Torque_Control_B.sf_MATLABFunction_e);

          /* SignalConversion: '<S161>/OutportBufferForSKF_act0' */
          Torque_Control_B.Merge_i =
            Torque_Control_B.sf_MATLABFunction_e.SKF_act0;

          /* End of Outputs for SubSystem: '<S156>/No spin' */
          break;
        }

        /* End of If: '<S156>/If' */

        /* Saturate: '<S156>/Saturation' */
        if (Torque_Control_B.Merge_i > Torque_Control_P.Saturation_UpperSat_d) {
          Torque_Control_B.Saturation_f = Torque_Control_P.Saturation_UpperSat_d;
        } else if (Torque_Control_B.Merge_i <
                   Torque_Control_P.Saturation_LowerSat_h) {
          Torque_Control_B.Saturation_f = Torque_Control_P.Saturation_LowerSat_h;
        } else {
          Torque_Control_B.Saturation_f = Torque_Control_B.Merge_i;
        }

        /* End of Saturate: '<S156>/Saturation' */
        /* End of Outputs for SubSystem: '<S153>/SKF' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S153>/CKF' incorporates:
         *  ActionPort: '<S154>/Action Port'
         */
        /* If: '<S154>/If1' incorporates:
         *  Constant: '<S158>/Constant'
         */
        rtAction = -1;
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          if (rtb_alpha_j >= 900.0) {
            rtAction = 0;
          } else {
            if (rtb_alpha_j < 900.0) {
              rtAction = 1;
            }
          }

          Torque_Control_DW.If1_ActiveSubsystem_o = rtAction;
        } else {
          rtAction = Torque_Control_DW.If1_ActiveSubsystem_o;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S154>/Spin ' incorporates:
           *  ActionPort: '<S158>/Action Port'
           */
          if (rtmIsMajorTimeStep(Torque_Control_M)) {
            Torque_Control_B.Constant_dw = Torque_Control_P.Constant_Value_f;
          }

          /* Switch: '<S158>/Switch1' incorporates:
           *  Constant: '<S158>/Constant'
           *  DataStoreRead: '<S118>/CKF_prev'
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          if (Torque_Control_DW.B_i > Torque_Control_P.Switch1_Threshold_j) {
            p = Torque_Control_DW.B_i;
          } else {
            p = Torque_Control_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S158>/Switch1' */

          /* Switch: '<S158>/Switch' incorporates:
           *  Inport: '<Root>/VDC_Cte_SKF'
           */
          if (Torque_Control_U.VDC_Cte_SKF > Torque_Control_P.Switch_Threshold_d)
          {
            my = Torque_Control_U.VDC_Cte_SKF;
          } else {
            my = Torque_Control_B.Constant_dw;
          }

          /* End of Switch: '<S158>/Switch' */

          /* Product: '<S158>/Product' */
          rtb_Product_lj = p * my;

          /* MATLAB Function: '<S158>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          Torque_Control_MATLABFunction_m(Torque_Control_U.VDC_CKF_Initial,
            rtb_Product_lj, &Torque_Control_B.sf_MATLABFunction_mt);

          /* SignalConversion: '<S158>/OutportBufferForCKF_act1 ' */
          Torque_Control_B.Merge_c =
            Torque_Control_B.sf_MATLABFunction_mt.CKF_act1;

          /* End of Outputs for SubSystem: '<S154>/Spin ' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S154>/No spin' incorporates:
           *  ActionPort: '<S157>/Action Port'
           */
          /* Switch: '<S157>/Switch1' incorporates:
           *  DataStoreRead: '<S118>/CKF_prev'
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          if (Torque_Control_DW.B_i > Torque_Control_P.Switch1_Threshold_h) {
            rtb_Switch1_p = Torque_Control_DW.B_i;
          } else {
            rtb_Switch1_p = Torque_Control_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S157>/Switch1' */

          /* MATLAB Function: '<S157>/MATLAB Function1' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           *  Inport: '<Root>/VDC_Cte_SKF'
           */
          Torque_Contro_MATLABFunction1_b(rtb_Switch1_p,
            Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_SKF,
            &Torque_Control_B.sf_MATLABFunction1_b);

          /* SignalConversion: '<S157>/OutportBufferForCKF_act0' */
          Torque_Control_B.Merge_c =
            Torque_Control_B.sf_MATLABFunction1_b.CKF_act0;

          /* End of Outputs for SubSystem: '<S154>/No spin' */
          break;
        }

        /* End of If: '<S154>/If1' */

        /* Saturate: '<S154>/Saturation' */
        if (Torque_Control_B.Merge_c > Torque_Control_P.Saturation_UpperSat_f) {
          Torque_Control_B.Saturation_i = Torque_Control_P.Saturation_UpperSat_f;
        } else if (Torque_Control_B.Merge_c <
                   Torque_Control_P.Saturation_LowerSat_f) {
          Torque_Control_B.Saturation_i = Torque_Control_P.Saturation_LowerSat_f;
        } else {
          Torque_Control_B.Saturation_i = Torque_Control_B.Merge_c;
        }

        /* End of Saturate: '<S154>/Saturation' */
        /* End of Outputs for SubSystem: '<S153>/CKF' */
        break;
      }

      /* End of If: '<S153>/SKF or CKF' */

      /* DataStoreWrite: '<S118>/Data Store Write' */
      Torque_Control_DW.A_b = Torque_Control_B.Saturation_f;

      /* DataStoreWrite: '<S118>/Data Store Write1' */
      Torque_Control_DW.B_i = Torque_Control_B.Saturation_i;
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        Torque_Control_B.Constant_p = Torque_Control_P.Constant_Value_b;
        Torque_Control_B.MaximumTorqueperengineNm =
          Torque_Control_P.MaximumTorqueperengineNm_Value;
        Torque_Control_B.MaximumTransmissionTorqueDynami =
          Torque_Control_P.MaximumTransmissionTorqueDynami;
        Torque_Control_B.MaximumTransmissionTorqueStatic =
          Torque_Control_P.MaximumTransmissionTorqueStatic;
        Torque_Control_B.Constant1_i = Torque_Control_P.Constant1_Value_ab;
        Torque_Control_B.Constant1_j = Torque_Control_P.Constant1_Value_b;
      }

      /* Gain: '<S113>/To motor Tq (RT)' incorporates:
       *  Constant: '<S113>/Constant1'
       *  Constant: '<S113>/Maximum Torque per engine [Nm]'
       *  Constant: '<S113>/Maximum Transmission Torque Dynamic [Nm]'
       *  Constant: '<S113>/Maximum Transmission Torque Static [Nm]'
       *  Constant: '<S120>/Constant1'
       *  Constant: '<S78>/Constant'
       */
      rtb_TomotorTqRT = Torque_Control_P.TomotorTqRT_Gain *
        rtb_TransmissionGearRatio;

      /* If: '<S78>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' incorporates:
       *  Constant: '<S114>/Constant3'
       *  Constant: '<S114>/Constant4'
       *  Constant: '<S114>/Yaw_Inertia [kg//m^3]'
       *  Constant: '<S115>/Constant'
       *  Constant: '<S115>/Constant3'
       *  Constant: '<S115>/Constant4'
       *  Constant: '<S142>/Constant7'
       *  Constant: '<S142>/Constant8'
       *  Constant: '<S142>/Steering_Ratio [-]'
       *  Constant: '<S142>/Wheelbase [m]'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        rtAction = (int8_T)!((Torque_Control_B.Gain >=
                              -Torque_Control_B.SteeringWheelSaturationpersited)
                             && (Torque_Control_B.Gain <=
          Torque_Control_B.SteeringWheelSaturationpersited));
        Torque_Control_DW.Steer_angisinSteer_SatrangeLong = rtAction;
      } else {
        rtAction = Torque_Control_DW.Steer_angisinSteer_SatrangeLong;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S78>/Longitudinal Dynamics' incorporates:
         *  ActionPort: '<S115>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          /* SignalConversion: '<S115>/OutportBufferForFx_FR' incorporates:
           *  Constant: '<S115>/Constant1'
           */
          Torque_Control_B.Merge_m = Torque_Control_P.Constant1_Value_f;

          /* SignalConversion: '<S115>/OutportBufferForFx_FL' incorporates:
           *  Constant: '<S115>/Constant2'
           */
          Torque_Control_B.Merge1_n = Torque_Control_P.Constant2_Value_d;
          Torque_Control_B.Constant_mf = Torque_Control_P.Constant_Value_f0;
          Torque_Control_B.Constant3_e = Torque_Control_P.Constant3_Value_k;
          Torque_Control_B.Constant4_m = Torque_Control_P.Constant4_Value;
        }

        /* Gain: '<S115>/Gain' incorporates:
         *  Constant: '<S115>/Constant'
         *  Constant: '<S115>/Constant3'
         *  Constant: '<S115>/Constant4'
         *  Sum: '<S115>/Add'
         */
        Torque_Control_B.Merge4 = (((Torque_Control_B.Merge +
          Torque_Control_B.Merge1) + Torque_Control_B.Merge2) +
          Torque_Control_B.Merge3) * Torque_Control_P.Gain_Gain_k;

        /* MATLAB Function: '<S115>/minimum value' */
        rtb_min_f = Torque_Control_B.Merge2;
        if (Torque_Control_B.Merge3 < Torque_Control_B.Merge2) {
          rtb_min_f = Torque_Control_B.Merge3;
        }

        /* End of MATLAB Function: '<S115>/minimum value' */

        /* MATLAB Function: '<S147>/Kamm_Circle LatD' */
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
        rtb_alpha_j = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          if (rtb_min_f > Torque_Control_B.kamm_data[(int32_T)k]) {
            rtb_alpha_j = k;
          } else {
            if (rtb_min_f < Torque_Control_B.kamm_data[(int32_T)k]) {
              Mz = k;
            }
          }

          k = floor((Mz + rtb_alpha_j) / 2.0);
          p = Mz - rtb_alpha_j;
          if (rtb_min_f == Torque_Control_B.kamm_data[(int32_T)Mz]) {
            p = 1.0;
            rtb_alpha_j = Mz;
          } else if (rtb_min_f == Torque_Control_B.kamm_data[(int32_T)
                     rtb_alpha_j]) {
            p = 1.0;
            Mz = rtb_alpha_j;
          } else {
            if (rtb_min_f == Torque_Control_B.kamm_data[(int32_T)k]) {
              p = 1.0;
              Mz = k;
              rtb_alpha_j = k;
            }
          }
        }

        my = 1.0;
        My = 31.0;
        k = 16.0;
        p = 30.0;
        while (p != 1.0) {
          if (Torque_Control_B.Constant_mf > Torque_Control_B.kamm_data[17 *
              (int32_T)k]) {
            my = k;
          } else {
            if (Torque_Control_B.Constant_mf < Torque_Control_B.kamm_data[17 *
                (int32_T)k]) {
              My = k;
            }
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_B.kamm_data[17 * (int32_T)My] ==
              Torque_Control_B.Constant_mf) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] ==
                     Torque_Control_B.Constant_mf) {
            p = 1.0;
            My = my;
          } else {
            if (Torque_Control_B.kamm_data[17 * (int32_T)k] ==
                Torque_Control_B.Constant_mf) {
              p = 1.0;
              My = k;
              my = k;
            }
          }
        }

        if ((Mz == rtb_alpha_j) && (My != my)) {
          kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my];
          kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)My];
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)rtb_alpha_j];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_value_g = b_a[0] * Torque_Control_B.Constant_mf + b_a[1];
        } else if ((Mz != rtb_alpha_j) && (My == my)) {
          kamm_data_0[0] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          kamm_data_0[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_value_g = b_a[0] * rtb_min_f + b_a[1];
        } else if ((Mz == rtb_alpha_j) && (My == my)) {
          rtb_value_g = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
            Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          tmp[4] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[5] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[6] = Torque_Control_B.kamm_data[(int32_T)Mz];
          tmp[7] = Torque_Control_B.kamm_data[(int32_T)Mz];
          r1 = 17 * (int32_T)my;
          tmp[8] = Torque_Control_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          tmp[9] = Torque_Control_B.kamm_data[r2];
          tmp[10] = Torque_Control_B.kamm_data[17 * (int32_T)my];
          tmp[11] = Torque_Control_B.kamm_data[17 * (int32_T)My];
          kamm_data[0] = Torque_Control_B.kamm_data[r1 + (int32_T)rtb_alpha_j];
          kamm_data[1] = Torque_Control_B.kamm_data[r2 + (int32_T)rtb_alpha_j];
          kamm_data[2] = Torque_Control_B.kamm_data[r1 + (int32_T)Mz];
          kamm_data[3] = Torque_Control_B.kamm_data[r2 + (int32_T)Mz];
          mldivide_u4svSR16(tmp, kamm_data, a);
          rtb_value_g = (a[1] * rtb_min_f + a[0]) + a[2] *
            Torque_Control_B.Constant_mf;
        }

        rtb_alpha_j = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          if (rtb_min_f > Torque_Control_B.kamm_data[(int32_T)k]) {
            rtb_alpha_j = k;
          } else {
            if (rtb_min_f < Torque_Control_B.kamm_data[(int32_T)k]) {
              Mz = k;
            }
          }

          k = floor((Mz + rtb_alpha_j) / 2.0);
          p = Mz - rtb_alpha_j;
          if (rtb_min_f == Torque_Control_B.kamm_data[(int32_T)Mz]) {
            p = 1.0;
            rtb_alpha_j = Mz;
          } else if (rtb_min_f == Torque_Control_B.kamm_data[(int32_T)
                     rtb_alpha_j]) {
            p = 1.0;
            Mz = rtb_alpha_j;
          } else {
            if (rtb_min_f == Torque_Control_B.kamm_data[(int32_T)k]) {
              p = 1.0;
              Mz = k;
              rtb_alpha_j = k;
            }
          }
        }

        my = 1.0;
        My = 31.0;
        k = 16.0;
        p = 30.0;
        while (p != 1.0) {
          if (Torque_Control_B.Constant_mf > Torque_Control_B.kamm_data[17 *
              (int32_T)k]) {
            my = k;
          } else {
            if (Torque_Control_B.Constant_mf < Torque_Control_B.kamm_data[17 *
                (int32_T)k]) {
              My = k;
            }
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_B.kamm_data[17 * (int32_T)My] ==
              Torque_Control_B.Constant_mf) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] ==
                     Torque_Control_B.Constant_mf) {
            p = 1.0;
            My = my;
          } else {
            if (Torque_Control_B.kamm_data[17 * (int32_T)k] ==
                Torque_Control_B.Constant_mf) {
              p = 1.0;
              My = k;
              my = k;
            }
          }
        }

        if ((Mz == rtb_alpha_j) && (My != my)) {
          kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my];
          kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)My];
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)rtb_alpha_j];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_alpha_j = b_a[0] * Torque_Control_B.Constant_mf + b_a[1];
        } else if ((Mz != rtb_alpha_j) && (My == my)) {
          kamm_data_0[0] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          kamm_data_0[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_alpha_j = b_a[0] * rtb_min_f + b_a[1];
        } else if ((Mz == rtb_alpha_j) && (My == my)) {
          rtb_alpha_j = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
            Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          tmp[4] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[5] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[6] = Torque_Control_B.kamm_data[(int32_T)Mz];
          tmp[7] = Torque_Control_B.kamm_data[(int32_T)Mz];
          r1 = 17 * (int32_T)my;
          tmp[8] = Torque_Control_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          tmp[9] = Torque_Control_B.kamm_data[r2];
          tmp[10] = Torque_Control_B.kamm_data[17 * (int32_T)my];
          tmp[11] = Torque_Control_B.kamm_data[17 * (int32_T)My];
          kamm_data[0] = Torque_Control_B.kamm_data[r1 + (int32_T)rtb_alpha_j];
          kamm_data[1] = Torque_Control_B.kamm_data[r2 + (int32_T)rtb_alpha_j];
          kamm_data[2] = Torque_Control_B.kamm_data[r1 + (int32_T)Mz];
          kamm_data[3] = Torque_Control_B.kamm_data[r2 + (int32_T)Mz];
          mldivide_u4svSR16(tmp, kamm_data, a);
          rtb_alpha_j = (a[1] * rtb_min_f + a[0]) + a[2] *
            Torque_Control_B.Constant_mf;
        }

        /* Product: '<S147>/Product' incorporates:
         *  MATLAB Function: '<S147>/Kamm_Circle LatD'
         */
        rtb_Product_a = rtb_value_g * Torque_Control_B.Saturation_f;

        /* Product: '<S147>/Product1' incorporates:
         *  MATLAB Function: '<S147>/Kamm_Circle LatD'
         */
        rtb_Product1_f = rtb_alpha_j * Torque_Control_B.Saturation_f;

        /* MATLAB Function: '<S115>/MATLAB Function' */
        Torque_Control_MATLABFunction_d(Torque_Control_B.Constant4_m,
          rtb_Product_a, &Torque_Control_B.sf_MATLABFunction_d);

        /* MATLAB Function: '<S115>/MATLAB Function1' */
        Torque_Control_MATLABFunction_d(Torque_Control_B.Constant3_e,
          rtb_Product1_f, &Torque_Control_B.sf_MATLABFunction1_g);

        /* SignalConversion: '<S115>/OutportBufferForFx_RL ' */
        Torque_Control_B.Merge3_e = Torque_Control_B.sf_MATLABFunction1_g.value;

        /* SignalConversion: '<S115>/OutportBufferForFx_RR ' */
        Torque_Control_B.Merge2_lx = Torque_Control_B.sf_MATLABFunction_d.value;
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          /* SignalConversion: '<S115>/OutportBufferForFy_R' incorporates:
           *  Constant: '<S115>/Constant5'
           */
          Torque_Control_B.Merge6 = Torque_Control_P.Constant5_Value;

          /* SignalConversion: '<S115>/OutportBufferForFlag CarBehavior' incorporates:
           *  Constant: '<S115>/Constant6'
           */
          Torque_Control_B.Merge7 = Torque_Control_P.Constant6_Value;
        }

        /* Sum: '<S115>/Add1' */
        Torque_Control_B.Merge5_e = rtb_Abs4 - rtb_Abs1;

        /* End of Outputs for SubSystem: '<S78>/Longitudinal Dynamics' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S78>/Lateral Dynamics' incorporates:
         *  ActionPort: '<S114>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          /* SignalConversion: '<S114>/OutportBufferForFx_FR' incorporates:
           *  Constant: '<S114>/Constant1'
           */
          Torque_Control_B.Merge_m = Torque_Control_P.Constant1_Value_a;

          /* SignalConversion: '<S114>/OutportBufferForFx_FL' incorporates:
           *  Constant: '<S114>/Constant2'
           */
          Torque_Control_B.Merge1_n = Torque_Control_P.Constant2_Value_g;
          Torque_Control_B.Constant3_b = Torque_Control_P.Constant3_Value_o;
          Torque_Control_B.Constant4 = Torque_Control_P.Constant4_Value_p;
          Torque_Control_B.Steering_Ratio =
            Torque_Control_P.Steering_Ratio_Value;
          Torque_Control_B.Constant8 = Torque_Control_P.Constant8_Value;
          Torque_Control_B.Constant7 = Torque_Control_P.Constant7_Value;
          Torque_Control_B.Wheelbasem = Torque_Control_P.Wheelbasem_Value;

          /* Gain: '<S142>/360//(2*pi)' incorporates:
           *  Constant: '<S114>/Constant3'
           *  Constant: '<S114>/Constant4'
           *  Constant: '<S142>/Constant7'
           *  Constant: '<S142>/Constant8'
           *  Constant: '<S142>/Cornering_Stiffness_F[N//º]'
           *  Constant: '<S142>/Steering_Ratio [-]'
           *  Constant: '<S142>/Wheelbase [m]'
           */
          Torque_Control_B.u602pi = Torque_Control_P.u602pi_Gain *
            Torque_Control_P.Cornering_Stiffness_FN_Value;

          /* Gain: '<S142>/360//(2pi)' incorporates:
           *  Constant: '<S142>/Cornering_Stiffness_R[N//º]'
           */
          Torque_Control_B.u602pi_e = Torque_Control_P.u602pi_Gain_g *
            Torque_Control_P.Cornering_Stiffness_RN_Value;
        }

        /* Sum: '<S114>/Add' incorporates:
         *  Constant: '<S114>/Constant3'
         *  Constant: '<S114>/Constant4'
         *  Constant: '<S142>/Constant7'
         *  Constant: '<S142>/Constant8'
         *  Constant: '<S142>/Steering_Ratio [-]'
         *  Constant: '<S142>/Wheelbase [m]'
         */
        Torque_Control_B.Merge5_e = rtb_Abs4 - rtb_Abs1;

        /* MATLAB Function: '<S142>/Bicycle Model' incorporates:
         *  Integrator: '<S114>/Integrator'
         *  Product: '<S142>/Divide'
         */
        A[0] = Torque_Control_B.u602pi;
        A[3] = Torque_Control_B.u602pi_e;
        A[6] = -Torque_Control_B.Constant8 * Torque_Control_X.Integrator_CSTATE;
        A[1] = Torque_Control_B.Constant7 * Torque_Control_B.u602pi;
        A[4] = -(Torque_Control_B.Wheelbasem - Torque_Control_B.Constant7) *
          Torque_Control_B.u602pi_e;
        A[7] = 0.0;
        A[2] = -1.0;
        A[5] = 1.0;
        A[8] = Torque_Control_B.Wheelbasem / Torque_Control_X.Integrator_CSTATE;
        a[0] = 0.0;
        a[1] = 0.0;
        a[2] = Torque_Control_B.Gain / Torque_Control_B.Steering_Ratio * 2.0 *
          3.1415926535897931 / 360.0;
        r1 = 0;
        r2 = 1;
        r3 = 2;
        rtb_Abs1 = fabs(Torque_Control_B.u602pi);
        rtb_value_g = fabs(A[1]);
        if (rtb_value_g > rtb_Abs1) {
          rtb_Abs1 = rtb_value_g;
          r1 = 1;
          r2 = 0;
        }

        if (1.0 > rtb_Abs1) {
          r1 = 2;
          r2 = 1;
          r3 = 0;
        }

        A[r2] /= A[r1];
        A[r3] /= A[r1];
        A[3 + r2] -= A[3 + r1] * A[r2];
        A[3 + r3] -= A[3 + r1] * A[r3];
        A[6 + r2] -= A[6 + r1] * A[r2];
        A[6 + r3] -= A[6 + r1] * A[r3];
        if (fabs(A[3 + r3]) > fabs(A[3 + r2])) {
          rtemp = r2;
          r2 = r3;
          r3 = rtemp;
        }

        A[3 + r3] /= A[3 + r2];
        A[6 + r3] -= A[3 + r3] * A[6 + r2];
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          Torque_Control_B.Yaw_Inertiakgm3 =
            Torque_Control_P.Yaw_Inertiakgm3_Value;

          /* Product: '<S144>/Divide1' incorporates:
           *  Constant: '<S114>/Rear_Trackwidth [m] '
           *  Constant: '<S114>/Yaw_Inertia [kg//m^3]'
           *  Constant: '<S144>/Constant'
           */
          Torque_Control_B.Divide1 = Torque_Control_P.Rear_Trackwidthm_Value /
            Torque_Control_P.Constant_Value_ad;
        }

        /* Product: '<S144>/Divide' incorporates:
         *  Constant: '<S114>/Yaw_Inertia [kg//m^3]'
         *  Inport: '<Root>/Gyro_F_Z_Deg'
         *  MATLAB Function: '<S142>/Bicycle Model'
         *  Product: '<S145>/Divide'
         *  Product: '<S145>/Product'
         *  Sum: '<S114>/Sum3'
         */
        rtb_Abs1 = (((a[r3] - a[r1] * A[r3]) - (a[r2] - a[r1] * A[r2]) * A[3 +
                     r3]) / A[6 + r3] - Torque_Control_U.Gyro_F_Z_Deg) *
          Torque_Control_B.Yaw_Inertiakgm3 / Torque_Control_B.Constant1_j /
          Torque_Control_B.Divide1;

        /* Sum: '<S114>/Sum' */
        rtb_min_f = Torque_Control_B.Merge2 + Torque_Control_B.Merge3;

        /* Gain: '<S114>/Fy per wheel' incorporates:
         *  Gain: '<S114>/Gravity'
         *  Product: '<S114>/Product'
         *  Sum: '<S114>/Sum'
         */
        rtb_Abs4 = Torque_Control_P.Gravity_Gain * rtb_min_f * rtb_Abs4 *
          Torque_Control_P.Fyperwheel_Gain;

        /* MATLAB Function: '<S138>/Kamm_Circle LatD' */
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
        rtb_alpha_j = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          if (Torque_Control_B.Merge2 > Torque_Control_B.kamm_data[(int32_T)k])
          {
            rtb_alpha_j = k;
          } else {
            if (Torque_Control_B.Merge2 < Torque_Control_B.kamm_data[(int32_T)k])
            {
              Mz = k;
            }
          }

          k = floor((Mz + rtb_alpha_j) / 2.0);
          p = Mz - rtb_alpha_j;
          if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data[(int32_T)Mz])
          {
            p = 1.0;
            rtb_alpha_j = Mz;
          } else if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data
                     [(int32_T)rtb_alpha_j]) {
            p = 1.0;
            Mz = rtb_alpha_j;
          } else {
            if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data[(int32_T)k])
            {
              p = 1.0;
              Mz = k;
              rtb_alpha_j = k;
            }
          }
        }

        my = 1.0;
        My = 31.0;
        k = 16.0;
        p = 30.0;
        while (p != 1.0) {
          if (rtb_Abs4 > Torque_Control_B.kamm_data[17 * (int32_T)k]) {
            my = k;
          } else {
            if (rtb_Abs4 < Torque_Control_B.kamm_data[17 * (int32_T)k]) {
              My = k;
            }
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_Abs4) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == rtb_Abs4) {
            p = 1.0;
            My = my;
          } else {
            if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_Abs4) {
              p = 1.0;
              My = k;
              my = k;
            }
          }
        }

        if ((Mz == rtb_alpha_j) && (My != my)) {
          kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my];
          kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)My];
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)rtb_alpha_j];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_value_g = b_a[0] * rtb_Abs4 + b_a[1];
        } else if ((Mz != rtb_alpha_j) && (My == my)) {
          kamm_data_0[0] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          kamm_data_0[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_value_g = b_a[0] * Torque_Control_B.Merge2 + b_a[1];
        } else if ((Mz == rtb_alpha_j) && (My == my)) {
          rtb_value_g = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
            Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          tmp[4] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[5] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[6] = Torque_Control_B.kamm_data[(int32_T)Mz];
          tmp[7] = Torque_Control_B.kamm_data[(int32_T)Mz];
          r1 = 17 * (int32_T)my;
          tmp[8] = Torque_Control_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          tmp[9] = Torque_Control_B.kamm_data[r2];
          tmp[10] = Torque_Control_B.kamm_data[17 * (int32_T)my];
          tmp[11] = Torque_Control_B.kamm_data[17 * (int32_T)My];
          kamm_data[0] = Torque_Control_B.kamm_data[r1 + (int32_T)rtb_alpha_j];
          kamm_data[1] = Torque_Control_B.kamm_data[r2 + (int32_T)rtb_alpha_j];
          kamm_data[2] = Torque_Control_B.kamm_data[r1 + (int32_T)Mz];
          kamm_data[3] = Torque_Control_B.kamm_data[r2 + (int32_T)Mz];
          mldivide_u4svSR16(tmp, kamm_data, a);
          rtb_value_g = (a[1] * Torque_Control_B.Merge2 + a[0]) + a[2] *
            rtb_Abs4;
        }

        rtb_alpha_j = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          if (Torque_Control_B.Merge3 > Torque_Control_B.kamm_data[(int32_T)k])
          {
            rtb_alpha_j = k;
          } else {
            if (Torque_Control_B.Merge3 < Torque_Control_B.kamm_data[(int32_T)k])
            {
              Mz = k;
            }
          }

          k = floor((Mz + rtb_alpha_j) / 2.0);
          p = Mz - rtb_alpha_j;
          if (Torque_Control_B.Merge3 == Torque_Control_B.kamm_data[(int32_T)Mz])
          {
            p = 1.0;
            rtb_alpha_j = Mz;
          } else if (Torque_Control_B.Merge3 == Torque_Control_B.kamm_data
                     [(int32_T)rtb_alpha_j]) {
            p = 1.0;
            Mz = rtb_alpha_j;
          } else {
            if (Torque_Control_B.Merge3 == Torque_Control_B.kamm_data[(int32_T)k])
            {
              p = 1.0;
              Mz = k;
              rtb_alpha_j = k;
            }
          }
        }

        my = 1.0;
        My = 31.0;
        k = 16.0;
        p = 30.0;
        while (p != 1.0) {
          if (rtb_Abs4 > Torque_Control_B.kamm_data[17 * (int32_T)k]) {
            my = k;
          } else {
            if (rtb_Abs4 < Torque_Control_B.kamm_data[17 * (int32_T)k]) {
              My = k;
            }
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_Abs4) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == rtb_Abs4) {
            p = 1.0;
            My = my;
          } else {
            if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_Abs4) {
              p = 1.0;
              My = k;
              my = k;
            }
          }
        }

        if ((Mz == rtb_alpha_j) && (My != my)) {
          kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my];
          kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)My];
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My +
            (int32_T)rtb_alpha_j];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_alpha_j = b_a[0] * rtb_Abs4 + b_a[1];
        } else if ((Mz != rtb_alpha_j) && (My == my)) {
          kamm_data_0[0] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          kamm_data_0[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
          kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_alpha_j = b_a[0] * Torque_Control_B.Merge3 + b_a[1];
        } else if ((Mz == rtb_alpha_j) && (My == my)) {
          rtb_alpha_j = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
            Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          tmp[4] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[5] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[6] = Torque_Control_B.kamm_data[(int32_T)Mz];
          tmp[7] = Torque_Control_B.kamm_data[(int32_T)Mz];
          r1 = 17 * (int32_T)my;
          tmp[8] = Torque_Control_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          tmp[9] = Torque_Control_B.kamm_data[r2];
          tmp[10] = Torque_Control_B.kamm_data[17 * (int32_T)my];
          tmp[11] = Torque_Control_B.kamm_data[17 * (int32_T)My];
          kamm_data[0] = Torque_Control_B.kamm_data[r1 + (int32_T)rtb_alpha_j];
          kamm_data[1] = Torque_Control_B.kamm_data[r2 + (int32_T)rtb_alpha_j];
          kamm_data[2] = Torque_Control_B.kamm_data[r1 + (int32_T)Mz];
          kamm_data[3] = Torque_Control_B.kamm_data[r2 + (int32_T)Mz];
          mldivide_u4svSR16(tmp, kamm_data, a);
          rtb_alpha_j = (a[1] * Torque_Control_B.Merge3 + a[0]) + a[2] *
            rtb_Abs4;
        }

        /* Product: '<S138>/Product1' incorporates:
         *  MATLAB Function: '<S138>/Kamm_Circle LatD'
         */
        rtb_Product1_h = rtb_value_g * Torque_Control_B.Saturation_i;

        /* MATLAB Function: '<S114>/MATLAB Function2' */
        Torque_Control_MATLABFunction_d(Torque_Control_B.Constant4,
          rtb_Product1_h, &Torque_Control_B.sf_MATLABFunction2_e);

        /* Product: '<S138>/Product2' incorporates:
         *  MATLAB Function: '<S138>/Kamm_Circle LatD'
         */
        rtb_Product2 = rtb_alpha_j * Torque_Control_B.Saturation_i;

        /* MATLAB Function: '<S114>/MATLAB Function1' */
        Torque_Control_MATLABFunction_d(Torque_Control_B.Constant3_b,
          rtb_Product2, &Torque_Control_B.sf_MATLABFunction1_mk);

        /* MATLAB Function: '<S114>/Force Difference with  Max. Tire Forces' */
        if (rtb_Abs1 > 0.0) {
          rtb_alpha_j = Torque_Control_B.sf_MATLABFunction1_mk.value;
          rtb_value_g = Torque_Control_B.sf_MATLABFunction1_mk.value - rtb_Abs1;
          if (rtb_value_g > Torque_Control_B.sf_MATLABFunction2_e.value) {
            rtb_value_g = Torque_Control_B.sf_MATLABFunction2_e.value;
            rtb_alpha_j = Torque_Control_B.sf_MATLABFunction2_e.value + rtb_Abs1;
          }
        } else if (rtb_Abs1 < 0.0) {
          rtb_value_g = Torque_Control_B.sf_MATLABFunction2_e.value;
          rtb_Abs1 = fabs(rtb_Abs1);
          rtb_alpha_j = Torque_Control_B.sf_MATLABFunction2_e.value - rtb_Abs1;
          if (rtb_alpha_j > Torque_Control_B.sf_MATLABFunction1_mk.value) {
            rtb_alpha_j = Torque_Control_B.sf_MATLABFunction1_mk.value;
            rtb_value_g = Torque_Control_B.sf_MATLABFunction1_mk.value -
              rtb_Abs1;
          }
        } else if (Torque_Control_B.sf_MATLABFunction2_e.value >
                   Torque_Control_B.sf_MATLABFunction1_mk.value) {
          rtb_alpha_j = Torque_Control_B.sf_MATLABFunction1_mk.value;
          rtb_value_g = Torque_Control_B.sf_MATLABFunction1_mk.value;
        } else {
          rtb_value_g = Torque_Control_B.sf_MATLABFunction2_e.value;
          rtb_alpha_j = Torque_Control_B.sf_MATLABFunction2_e.value;
        }

        /* Gain: '<S114>/Gravity1' incorporates:
         *  Sum: '<S114>/Sum'
         *  Sum: '<S114>/Sum1'
         *  Sum: '<S114>/Sum2'
         */
        Torque_Control_B.Merge4 = ((Torque_Control_B.Merge +
          Torque_Control_B.Merge1) + rtb_min_f) * Torque_Control_P.Gravity1_Gain;

        /* SignalConversion: '<S114>/OutportBufferForFx_RL ' incorporates:
         *  MATLAB Function: '<S114>/Force Difference with  Max. Tire Forces'
         */
        Torque_Control_B.Merge3_e = rtb_alpha_j;

        /* SignalConversion: '<S114>/OutportBufferForFx_RR ' incorporates:
         *  MATLAB Function: '<S114>/Force Difference with  Max. Tire Forces'
         */
        Torque_Control_B.Merge2_lx = rtb_value_g;

        /* SignalConversion: '<S114>/OutportBufferForFy_R [N] (0,inf)' incorporates:
         *  MATLAB Function: '<S138>/Kamm_Circle LatD'
         */
        Torque_Control_B.Merge6 = rtb_Abs4;
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          /* SignalConversion: '<S114>/OutportBufferForFlag CarBehavior' incorporates:
           *  Constant: '<S114>/Constant6'
           */
          Torque_Control_B.Merge7 = Torque_Control_P.Constant6_Value_p;
        }

        /* End of Outputs for SubSystem: '<S78>/Lateral Dynamics' */
        break;
      }

      /* End of If: '<S78>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */

      /* MATLAB Function: '<S120>/MATLAB Function1' */
      Torque_Contro_MATLABFunction1_m(Torque_Control_B.Constant1_i,
        Torque_Control_B.Merge2_lx, &Torque_Control_B.sf_MATLABFunction1_m);
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        /* Gain: '<S113>/3% difference1' incorporates:
         *  Constant: '<S113>/Effective Rolling Diameter[inch]'
         *  Gain: '<S113>/Diameter to Radius'
         *  Gain: '<S113>/inch to m1'
         */
        Torque_Control_B.udifference1 = Torque_Control_P.DiametertoRadius_Gain *
          Torque_Control_P.EffectiveRollingDiameterinch_Va *
          Torque_Control_P.inchtom1_Gain * Torque_Control_P.udifference1_Gain;
        Torque_Control_B.TransmisionRatio =
          Torque_Control_P.TransmisionRatio_Value;
        Torque_Control_B.Constant_bb = Torque_Control_P.Constant_Value_l;
      }

      /* Product: '<S166>/Divide' incorporates:
       *  Constant: '<S113>/Transmision Ratio[-]'
       *  Constant: '<S120>/Constant'
       *  Product: '<S166>/Product'
       */
      Torque_Control_B.Divide = Torque_Control_B.sf_MATLABFunction1_m.value *
        Torque_Control_B.udifference1 / Torque_Control_B.TransmisionRatio;

      /* MATLAB Function: '<S120>/MATLAB Function2' */
      Torque_Contro_MATLABFunction1_m(Torque_Control_B.Constant_bb,
        Torque_Control_B.Merge3_e, &Torque_Control_B.sf_MATLABFunction2);

      /* Product: '<S165>/Divide' incorporates:
       *  Product: '<S165>/Product'
       */
      Torque_Control_B.Divide_i = Torque_Control_B.sf_MATLABFunction2.value *
        Torque_Control_B.udifference1 / Torque_Control_B.TransmisionRatio;

      /* Sum: '<S120>/Add' */
      rtb_Abs1 = Torque_Control_B.Divide - Torque_Control_B.Divide_i;
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        Torque_Control_B.Tq_diff_Max = Torque_Control_P.Tq_diff_Max_Value;
      }

      /* MATLAB Function: '<S111>/Accelerator behaviour ' incorporates:
       *  Constant: '<S113>/Tq_diff_Max'
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       *  Inport: '<Root>/VDC_Apps_Sat_Up'
       */
      Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
        Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
        &Torque_Control_B.sf_Acceleratorbehaviour);

      /* If: '<S111>/Braking Conditions' incorporates:
       *  Inport: '<Root>/BrakeSensor_Value'
       *  Inport: '<S131>/Throttle'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
            (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1) &&
            (Torque_Control_B.Merge1_a == 1.0)) {
          rtAction = 0;
        } else if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
                   (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1) &&
                   (Torque_Control_B.Merge1_a == 0.0)) {
          rtAction = 1;
        } else if ((Torque_Control_U.BrakeSensor_Value < 0.1) &&
                   (Torque_Control_B.sf_Acceleratorbehaviour.throttle < 0.1)) {
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
        /* Outputs for IfAction SubSystem: '<S111>/Regenerative+Mech Braking' incorporates:
         *  ActionPort: '<S135>/Action Port'
         */
        /* MATLAB Function: '<S135>/MATLAB Function' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
          rtb_Abs4 = 0.0;
        } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
          rtb_Abs4 = 1.0;
        } else {
          rtb_Abs4 = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
        }

        /* SignalConversion: '<S135>/OutportBufferForTq_RL' incorporates:
         *  MATLAB Function: '<S135>/MATLAB Function'
         */
        Torque_Control_B.Merge1_b = rtb_Abs4 * Torque_Control_B.Divide_i;

        /* SignalConversion: '<S135>/OutportBufferForTq_RR  ' incorporates:
         *  MATLAB Function: '<S135>/MATLAB Function'
         */
        Torque_Control_B.Merge_kt = rtb_Abs4 * Torque_Control_B.Divide;

        /* End of Outputs for SubSystem: '<S111>/Regenerative+Mech Braking' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S111>/Mech_Braking' incorporates:
         *  ActionPort: '<S134>/Action Port'
         */
        Torque_Control_Mech_Braking(&Torque_Control_B.Merge_kt,
          &Torque_Control_B.Merge1_b, &Torque_Control_P.Mech_Braking);

        /* End of Outputs for SubSystem: '<S111>/Mech_Braking' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S111>/Inertia Braking' incorporates:
         *  ActionPort: '<S133>/Action Port'
         */
        Torque_Control_Mech_Braking(&Torque_Control_B.Merge_kt,
          &Torque_Control_B.Merge1_b, &Torque_Control_P.InertiaBraking);

        /* End of Outputs for SubSystem: '<S111>/Inertia Braking' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S111>/Accelerating' incorporates:
         *  ActionPort: '<S131>/Action Port'
         */
        Torque_Control_B.Throttle =
          Torque_Control_B.sf_Acceleratorbehaviour.throttle;

        /* Product: '<S131>/Product' incorporates:
         *  Inport: '<S131>/Throttle'
         */
        Torque_Control_B.Merge1_b = Torque_Control_B.Throttle *
          Torque_Control_B.Divide_i;

        /* Product: '<S131>/Product1' */
        Torque_Control_B.Merge_kt = Torque_Control_B.Throttle *
          Torque_Control_B.Divide;

        /* End of Outputs for SubSystem: '<S111>/Accelerating' */
        break;
      }

      /* End of If: '<S111>/Braking Conditions' */

      /* If: '<S110>/If' incorporates:
       *  Constant: '<S121>/Constant'
       *  Inport: '<Root>/BrakeSensor_Value'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        rtAction = (int8_T)!((Torque_Control_B.Merge1_a == 1.0) &&
                             (Torque_Control_U.BrakeSensor_Value > 0.0));
        Torque_Control_DW.If_ActiveSubsystem_aq = rtAction;
      } else {
        rtAction = Torque_Control_DW.If_ActiveSubsystem_aq;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S110>/Braking with Regenerative' incorporates:
         *  ActionPort: '<S122>/Action Port'
         */
        Torque__BrakingwithRegenerative(rtb_TomotorTqRT,
          Torque_Control_B.Merge_kt, Torque_Control_B.Merge1_b, &rtb_Merge1_j,
          &rtb_Merge2, &Torque_Control_B.BrakingwithRegenerative,
          &Torque_Control_P.BrakingwithRegenerative);

        /* End of Outputs for SubSystem: '<S110>/Braking with Regenerative' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S110>/Acelerating and braking without Regenerative' incorporates:
         *  ActionPort: '<S121>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          /* Gain: '<S121>/Gain' incorporates:
           *  Constant: '<S121>/rpm'
           */
          Torque_Control_B.approx2095_h = Torque_Control_P.Gain_Gain_co *
            Torque_Control_P.rpm_Value;
        }

        /* If: '<S121>/If1' */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          rtAction = (int8_T)!((rtb_Abs3 > Torque_Control_B.approx2095_h) &&
                               (rtb_Abs2 > Torque_Control_B.approx2095_h));
          Torque_Control_DW.If1_ActiveSubsystem_bn = rtAction;
        } else {
          rtAction = Torque_Control_DW.If1_ActiveSubsystem_bn;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S121>/If Action 1' incorporates:
           *  ActionPort: '<S123>/Action Port'
           */
          Torque_Control_IfAction1
            (Torque_Control_B.MaximumTransmissionTorqueDynami,
             &Torque_Control_B.Merge2_j);

          /* End of Outputs for SubSystem: '<S121>/If Action 1' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S121>/If Action 2' incorporates:
           *  ActionPort: '<S124>/Action Port'
           */
          Torque_Control_IfAction2
            (Torque_Control_B.MaximumTransmissionTorqueStatic,
             &Torque_Control_B.Merge2_j);

          /* End of Outputs for SubSystem: '<S121>/If Action 2' */
          break;
        }

        /* End of If: '<S121>/If1' */

        /* MATLAB Function: '<S121>/MATLAB Function' */
        if (rtb_Abs1 < -Torque_Control_B.Tq_diff_Max) {
          rtb_Abs4 = -Torque_Control_B.Tq_diff_Max;
        } else if (rtb_Abs1 > Torque_Control_B.Tq_diff_Max) {
          rtb_Abs4 = Torque_Control_B.Tq_diff_Max;
        } else {
          rtb_Abs4 = rtb_Abs1;
        }

        /* End of MATLAB Function: '<S121>/MATLAB Function' */

        /* MATLAB Function: '<S121>/minimum value' */
        rtb_Abs1 = Torque_Control_B.Merge2_j;
        if (Torque_Control_B.MaximumTorqueperengineNm <
            Torque_Control_B.Merge2_j) {
          rtb_Abs1 = Torque_Control_B.MaximumTorqueperengineNm;
        }

        if (Torque_Control_B.Merge_kt < rtb_Abs1) {
          rtb_Abs1 = Torque_Control_B.Merge_kt;
        }

        /* End of MATLAB Function: '<S121>/minimum value' */

        /* MATLAB Function: '<S121>/minimum value1' */
        rtb_value_g = Torque_Control_B.Merge2_j;
        if (Torque_Control_B.MaximumTorqueperengineNm <
            Torque_Control_B.Merge2_j) {
          rtb_value_g = Torque_Control_B.MaximumTorqueperengineNm;
        }

        if (Torque_Control_B.Merge1_b < rtb_value_g) {
          rtb_value_g = Torque_Control_B.Merge1_b;
        }

        /* End of MATLAB Function: '<S121>/minimum value1' */

        /* MATLAB Function: '<S126>/MATLAB Function' */
        if (!((rtb_Abs1 == Torque_Control_B.Merge_kt) && (rtb_value_g ==
              Torque_Control_B.Merge1_b))) {
          if (Torque_Control_B.Merge_kt > Torque_Control_B.Merge1_b) {
            rtb_value_g = rtb_Abs1 - fabs(rtb_Abs4);
            if (rtb_value_g < 0.0) {
              rtb_value_g = 0.0;
            }
          } else {
            if (Torque_Control_B.Merge_kt < Torque_Control_B.Merge1_b) {
              rtb_Abs1 = rtb_value_g - fabs(rtb_Abs4);
              if (rtb_Abs1 < 0.0) {
                rtb_Abs1 = 0.0;
              }
            }
          }
        }

        /* SignalConversion: '<S121>/OutportBufferForTQ_RL' incorporates:
         *  MATLAB Function: '<S126>/MATLAB Function'
         */
        rtb_Merge2 = rtb_value_g;

        /* SignalConversion: '<S121>/OutportBufferForTQ_RR' incorporates:
         *  MATLAB Function: '<S126>/MATLAB Function'
         */
        rtb_Merge1_j = rtb_Abs1;
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          Torque_Control_B.Constant_c = Torque_Control_P.Constant_Value_h;

          /* SignalConversion: '<S121>/OutportBufferForFlag_Power' incorporates:
           *  Constant: '<S121>/Constant'
           */
          Torque_Control_B.OutportBufferForFlag_Power =
            Torque_Control_B.Constant_c;
        }

        /* End of Outputs for SubSystem: '<S110>/Acelerating and braking without Regenerative' */
        break;
      }

      /* End of If: '<S110>/If' */

      /* Product: '<S110>/To wheel Tq' */
      Torque_Control_B.MergeTq_RR = rtb_Merge1_j *
        Torque_Control_B.TransmisionRatio;

      /* Product: '<S110>/To wheel Tq1' */
      Torque_Control_B.MergeTq_RL = Torque_Control_B.TransmisionRatio *
        rtb_Merge2;

      /* MATLAB Function: '<S78>/MATLAB Function1' */
      Torque_Control_MATLABFunction1(Torque_Control_B.Constant_p,
        Torque_Control_B.Divide_i, &Torque_Control_B.sf_MATLABFunction1_ny);

      /* MATLAB Function: '<S78>/MATLAB Function2' */
      Torque_Control_MATLABFunction1(Torque_Control_B.Constant_p,
        Torque_Control_B.Divide, &Torque_Control_B.sf_MATLABFunction2_l);

      /* SignalConversion: '<S78>/OutportBufferForCKF_act' */
      Torque_Control_B.Merge3_c = Torque_Control_B.Saturation_i;

      /* SignalConversion: '<S78>/OutportBufferForFlags_[num5]' */
      Torque_Control_B.OutportBufferForFlags_num5[0] = Torque_Control_B.Merge7;
      Torque_Control_B.OutportBufferForFlags_num5[1] =
        Torque_Control_B.sf_MATLABFunction1_ny.value;
      Torque_Control_B.OutportBufferForFlags_num5[2] =
        Torque_Control_B.sf_MATLABFunction2_l.value;
      Torque_Control_B.OutportBufferForFlags_num5[3] =
        Torque_Control_B.OutportBufferForFlag_Power;

      /* SignalConversion: '<S78>/OutportBufferForSKF_act' */
      Torque_Control_B.Merge2_l = Torque_Control_B.Saturation_f;

      /* End of Outputs for SubSystem: '<S67>/VDC Complete' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S67>/VDC without Longitudinal' incorporates:
       *  ActionPort: '<S79>/Action Port'
       */
      /* MATLAB Function: '<S175>/MATLAB Function' */
      Torque_Control_MATLABFunction_n(rtb_Abs2, rtb_Abs3,
        &Torque_Control_B.sf_MATLABFunction_fa);

      /* Derivative: '<S175>/Derivative' */
      if ((Torque_Control_DW.TimeStampA_b >= Torque_Control_M->Timing.t[0]) &&
          (Torque_Control_DW.TimeStampB_e >= Torque_Control_M->Timing.t[0])) {
        rtb_Abs1 = 0.0;
      } else {
        p = Torque_Control_DW.TimeStampA_b;
        lastU = &Torque_Control_DW.LastUAtTimeA_e;
        if (Torque_Control_DW.TimeStampA_b < Torque_Control_DW.TimeStampB_e) {
          if (Torque_Control_DW.TimeStampB_e < Torque_Control_M->Timing.t[0]) {
            p = Torque_Control_DW.TimeStampB_e;
            lastU = &Torque_Control_DW.LastUAtTimeB_o;
          }
        } else {
          if (Torque_Control_DW.TimeStampA_b >= Torque_Control_M->Timing.t[0]) {
            p = Torque_Control_DW.TimeStampB_e;
            lastU = &Torque_Control_DW.LastUAtTimeB_o;
          }
        }

        rtb_Abs1 = (Torque_Control_B.sf_MATLABFunction_fa.RPM - *lastU) /
          (Torque_Control_M->Timing.t[0] - p);
      }

      /* End of Derivative: '<S175>/Derivative' */

      /* If: '<S201>/If1' incorporates:
       *  Constant: '<S203>/Constant'
       */
      rtAction = -1;
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        if (rtb_Abs1 >= 900.0) {
          rtAction = 0;
        } else {
          if (rtb_Abs1 < 900.0) {
            rtAction = 1;
          }
        }

        Torque_Control_DW.If1_ActiveSubsystem_a = rtAction;
      } else {
        rtAction = Torque_Control_DW.If1_ActiveSubsystem_a;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S201>/Spin ' incorporates:
         *  ActionPort: '<S203>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          Torque_Control_B.Constant_f = Torque_Control_P.Constant_Value_d;
        }

        /* Switch: '<S203>/Switch1' incorporates:
         *  Constant: '<S203>/Constant'
         *  DataStoreRead: '<S175>/CKF_prev'
         *  Inport: '<Root>/VDC_CKF_Initial'
         */
        if (Torque_Control_DW.B_k > Torque_Control_P.Switch1_Threshold_c) {
          p = Torque_Control_DW.B_k;
        } else {
          p = Torque_Control_U.VDC_CKF_Initial;
        }

        /* End of Switch: '<S203>/Switch1' */

        /* Switch: '<S203>/Switch' incorporates:
         *  Inport: '<Root>/VDC_Cte_SKF'
         */
        if (Torque_Control_U.VDC_Cte_SKF >= Torque_Control_P.Switch_Threshold_i)
        {
          my = Torque_Control_U.VDC_Cte_SKF;
        } else {
          my = Torque_Control_B.Constant_f;
        }

        /* End of Switch: '<S203>/Switch' */

        /* Product: '<S203>/Product' */
        rtb_Product_iv = p * my;

        /* MATLAB Function: '<S203>/MATLAB Function' incorporates:
         *  Inport: '<Root>/VDC_CKF_Initial'
         */
        Torque_Control_MATLABFunction_m(Torque_Control_U.VDC_CKF_Initial,
          rtb_Product_iv, &Torque_Control_B.sf_MATLABFunction_i1);

        /* SignalConversion: '<S203>/OutportBufferForCKF_act1 ' */
        Torque_Control_B.Merge_g =
          Torque_Control_B.sf_MATLABFunction_i1.CKF_act1;

        /* End of Outputs for SubSystem: '<S201>/Spin ' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S201>/No spin' incorporates:
         *  ActionPort: '<S202>/Action Port'
         */
        /* Switch: '<S202>/Switch1' incorporates:
         *  DataStoreRead: '<S175>/CKF_prev'
         *  Inport: '<Root>/VDC_CKF_Initial'
         */
        if (Torque_Control_DW.B_k > Torque_Control_P.Switch1_Threshold_b) {
          rtb_Switch1 = Torque_Control_DW.B_k;
        } else {
          rtb_Switch1 = Torque_Control_U.VDC_CKF_Initial;
        }

        /* End of Switch: '<S202>/Switch1' */

        /* MATLAB Function: '<S202>/MATLAB Function' incorporates:
         *  Inport: '<Root>/VDC_CKF_Initial'
         *  Inport: '<Root>/VDC_Cte_SKF'
         */
        Torque_Contro_MATLABFunction1_b(rtb_Switch1,
          Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_SKF,
          &Torque_Control_B.sf_MATLABFunction_a);

        /* SignalConversion: '<S202>/OutportBufferForCKF_act0' */
        Torque_Control_B.Merge_g = Torque_Control_B.sf_MATLABFunction_a.CKF_act0;

        /* End of Outputs for SubSystem: '<S201>/No spin' */
        break;
      }

      /* End of If: '<S201>/If1' */

      /* Saturate: '<S201>/Saturation' */
      if (Torque_Control_B.Merge_g > Torque_Control_P.Saturation_UpperSat_i) {
        rtb_Abs1 = Torque_Control_P.Saturation_UpperSat_i;
      } else if (Torque_Control_B.Merge_g <
                 Torque_Control_P.Saturation_LowerSat_c) {
        rtb_Abs1 = Torque_Control_P.Saturation_LowerSat_c;
      } else {
        rtb_Abs1 = Torque_Control_B.Merge_g;
      }

      /* End of Saturate: '<S201>/Saturation' */

      /* DataStoreWrite: '<S175>/Data Store Write1' */
      Torque_Control_DW.B_k = rtb_Abs1;
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        /* Product: '<S172>/Product' incorporates:
         *  Constant: '<S172>/Maximum Torque per motor [Nm]'
         *  Constant: '<S172>/Transmision Ratio[-]'
         */
        Torque_Control_B.Product =
          Torque_Control_P.MaximumTorquepermotorNm_Value *
          Torque_Control_P.TransmisionRatio_Value_j;
        Torque_Control_B.Constant_e = Torque_Control_P.Constant_Value_ib;
        Torque_Control_B.Constant1_b = Torque_Control_P.Constant1_Value_c;
      }

      /* Gain: '<S174>/Fy per wheel' incorporates:
       *  Constant: '<S171>/Constant'
       *  Constant: '<S173>/Constant1'
       *  Gain: '<S174>/Gravity1'
       *  Product: '<S174>/Product'
       *  Sum: '<S174>/Sum1'
       */
      rtb_Abs4 = (Torque_Control_B.Merge2 + Torque_Control_B.Merge3) *
        Torque_Control_P.Gravity1_Gain_g * rtb_Abs4 *
        Torque_Control_P.Fyperwheel_Gain_e;

      /* MATLAB Function: '<S173>/Kamm_Circle LatD' */
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
      rtb_alpha_j = 1.0;
      Mz = 16.0;
      k = 8.0;
      p = 15.0;
      while (p != 1.0) {
        if (Torque_Control_B.Merge2 > Torque_Control_B.kamm_data[(int32_T)k]) {
          rtb_alpha_j = k;
        } else {
          if (Torque_Control_B.Merge2 < Torque_Control_B.kamm_data[(int32_T)k])
          {
            Mz = k;
          }
        }

        k = floor((Mz + rtb_alpha_j) / 2.0);
        p = Mz - rtb_alpha_j;
        if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data[(int32_T)Mz])
        {
          p = 1.0;
          rtb_alpha_j = Mz;
        } else if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data
                   [(int32_T)rtb_alpha_j]) {
          p = 1.0;
          Mz = rtb_alpha_j;
        } else {
          if (Torque_Control_B.Merge2 == Torque_Control_B.kamm_data[(int32_T)k])
          {
            p = 1.0;
            Mz = k;
            rtb_alpha_j = k;
          }
        }
      }

      my = 1.0;
      My = 31.0;
      k = 16.0;
      p = 30.0;
      while (p != 1.0) {
        if (rtb_Abs4 > Torque_Control_B.kamm_data[17 * (int32_T)k]) {
          my = k;
        } else {
          if (rtb_Abs4 < Torque_Control_B.kamm_data[17 * (int32_T)k]) {
            My = k;
          }
        }

        k = floor((My + my) / 2.0);
        p = My - my;
        if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_Abs4) {
          p = 1.0;
          my = My;
        } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == rtb_Abs4) {
          p = 1.0;
          My = my;
        } else {
          if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_Abs4) {
            p = 1.0;
            My = k;
            my = k;
          }
        }
      }

      if ((Mz == rtb_alpha_j) && (My != my)) {
        kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my];
        kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)My];
        kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my + (int32_T)
          rtb_alpha_j];
        kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
          rtb_alpha_j];
        polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
        rtb_value_g = b_a[0] * rtb_Abs4 + b_a[1];
      } else if ((Mz != rtb_alpha_j) && (My == my)) {
        kamm_data_0[0] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
        kamm_data_0[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
        kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my + (int32_T)
          rtb_alpha_j];
        kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)my + (int32_T)
          Mz];
        polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
        rtb_value_g = b_a[0] * Torque_Control_B.Merge2 + b_a[1];
      } else if ((Mz == rtb_alpha_j) && (My == my)) {
        rtb_value_g = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)Mz];
      } else {
        tmp[0] = 1.0;
        tmp[1] = 1.0;
        tmp[2] = 1.0;
        tmp[3] = 1.0;
        tmp[4] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
        tmp[5] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
        tmp[6] = Torque_Control_B.kamm_data[(int32_T)Mz];
        tmp[7] = Torque_Control_B.kamm_data[(int32_T)Mz];
        r1 = 17 * (int32_T)my;
        tmp[8] = Torque_Control_B.kamm_data[r1];
        r2 = 17 * (int32_T)My;
        tmp[9] = Torque_Control_B.kamm_data[r2];
        tmp[10] = Torque_Control_B.kamm_data[17 * (int32_T)my];
        tmp[11] = Torque_Control_B.kamm_data[17 * (int32_T)My];
        kamm_data[0] = Torque_Control_B.kamm_data[r1 + (int32_T)rtb_alpha_j];
        kamm_data[1] = Torque_Control_B.kamm_data[r2 + (int32_T)rtb_alpha_j];
        kamm_data[2] = Torque_Control_B.kamm_data[r1 + (int32_T)Mz];
        kamm_data[3] = Torque_Control_B.kamm_data[r2 + (int32_T)Mz];
        mldivide_u4svSR16(tmp, kamm_data, a);
        rtb_value_g = (a[1] * Torque_Control_B.Merge2 + a[0]) + a[2] * rtb_Abs4;
      }

      rtb_alpha_j = 1.0;
      Mz = 16.0;
      k = 8.0;
      p = 15.0;
      while (p != 1.0) {
        if (Torque_Control_B.Merge3 > Torque_Control_B.kamm_data[(int32_T)k]) {
          rtb_alpha_j = k;
        } else {
          if (Torque_Control_B.Merge3 < Torque_Control_B.kamm_data[(int32_T)k])
          {
            Mz = k;
          }
        }

        k = floor((Mz + rtb_alpha_j) / 2.0);
        p = Mz - rtb_alpha_j;
        if (Torque_Control_B.Merge3 == Torque_Control_B.kamm_data[(int32_T)Mz])
        {
          p = 1.0;
          rtb_alpha_j = Mz;
        } else if (Torque_Control_B.Merge3 == Torque_Control_B.kamm_data
                   [(int32_T)rtb_alpha_j]) {
          p = 1.0;
          Mz = rtb_alpha_j;
        } else {
          if (Torque_Control_B.Merge3 == Torque_Control_B.kamm_data[(int32_T)k])
          {
            p = 1.0;
            Mz = k;
            rtb_alpha_j = k;
          }
        }
      }

      my = 1.0;
      My = 31.0;
      k = 16.0;
      p = 30.0;
      while (p != 1.0) {
        if (rtb_Abs4 > Torque_Control_B.kamm_data[17 * (int32_T)k]) {
          my = k;
        } else {
          if (rtb_Abs4 < Torque_Control_B.kamm_data[17 * (int32_T)k]) {
            My = k;
          }
        }

        k = floor((My + my) / 2.0);
        p = My - my;
        if (Torque_Control_B.kamm_data[17 * (int32_T)My] == rtb_Abs4) {
          p = 1.0;
          my = My;
        } else if (Torque_Control_B.kamm_data[17 * (int32_T)my] == rtb_Abs4) {
          p = 1.0;
          My = my;
        } else {
          if (Torque_Control_B.kamm_data[17 * (int32_T)k] == rtb_Abs4) {
            p = 1.0;
            My = k;
            my = k;
          }
        }
      }

      if ((Mz == rtb_alpha_j) && (My != my)) {
        kamm_data_0[0] = Torque_Control_B.kamm_data[17 * (int32_T)my];
        kamm_data_0[1] = Torque_Control_B.kamm_data[17 * (int32_T)My];
        kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my + (int32_T)
          rtb_alpha_j];
        kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)
          rtb_alpha_j];
        polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
        rtb_alpha_j = b_a[0] * rtb_Abs4 + b_a[1];
      } else if ((Mz != rtb_alpha_j) && (My == my)) {
        kamm_data_0[0] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
        kamm_data_0[1] = Torque_Control_B.kamm_data[(int32_T)Mz];
        kamm_data_1[0] = Torque_Control_B.kamm_data[17 * (int32_T)my + (int32_T)
          rtb_alpha_j];
        kamm_data_1[1] = Torque_Control_B.kamm_data[17 * (int32_T)my + (int32_T)
          Mz];
        polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
        rtb_alpha_j = b_a[0] * Torque_Control_B.Merge3 + b_a[1];
      } else if ((Mz == rtb_alpha_j) && (My == my)) {
        rtb_alpha_j = Torque_Control_B.kamm_data[17 * (int32_T)My + (int32_T)Mz];
      } else {
        tmp[0] = 1.0;
        tmp[1] = 1.0;
        tmp[2] = 1.0;
        tmp[3] = 1.0;
        tmp[4] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
        tmp[5] = Torque_Control_B.kamm_data[(int32_T)rtb_alpha_j];
        tmp[6] = Torque_Control_B.kamm_data[(int32_T)Mz];
        tmp[7] = Torque_Control_B.kamm_data[(int32_T)Mz];
        r1 = 17 * (int32_T)my;
        tmp[8] = Torque_Control_B.kamm_data[r1];
        r2 = 17 * (int32_T)My;
        tmp[9] = Torque_Control_B.kamm_data[r2];
        tmp[10] = Torque_Control_B.kamm_data[17 * (int32_T)my];
        tmp[11] = Torque_Control_B.kamm_data[17 * (int32_T)My];
        kamm_data[0] = Torque_Control_B.kamm_data[r1 + (int32_T)rtb_alpha_j];
        kamm_data[1] = Torque_Control_B.kamm_data[r2 + (int32_T)rtb_alpha_j];
        kamm_data[2] = Torque_Control_B.kamm_data[r1 + (int32_T)Mz];
        kamm_data[3] = Torque_Control_B.kamm_data[r2 + (int32_T)Mz];
        mldivide_u4svSR16(tmp, kamm_data, a);
        rtb_alpha_j = (a[1] * Torque_Control_B.Merge3 + a[0]) + a[2] * rtb_Abs4;
      }

      /* Product: '<S173>/Product' incorporates:
       *  MATLAB Function: '<S173>/Kamm_Circle LatD'
       */
      rtb_Product_c = rtb_value_g * rtb_Abs1;

      /* MATLAB Function: '<S173>/MATLAB Function2' */
      Torque_Control_MATLABFunction_d(Torque_Control_B.Constant1_b,
        rtb_Product_c, &Torque_Control_B.sf_MATLABFunction2_b);

      /* MATLAB Function: '<S171>/MATLAB Function2' */
      Torque_Control_MATLABFunction_d(Torque_Control_B.Constant_e,
        Torque_Control_B.sf_MATLABFunction2_b.value,
        &Torque_Control_B.sf_MATLABFunction2_m);
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        /* Gain: '<S172>/3% difference' incorporates:
         *  Constant: '<S172>/Effective Rolling Diameter[inch]'
         *  Gain: '<S172>/Diameter to Radius'
         *  Gain: '<S172>/inch to m'
         */
        Torque_Control_B.udifference = Torque_Control_P.DiametertoRadius_Gain_h *
          Torque_Control_P.EffectiveRollingDiameterinch__b *
          Torque_Control_P.inchtom_Gain * Torque_Control_P.udifference_Gain;
        Torque_Control_B.Constant1_k = Torque_Control_P.Constant1_Value_l;
        Torque_Control_B.Constant_dd = Torque_Control_P.Constant_Value_ae;
      }

      /* Product: '<S173>/Product1' incorporates:
       *  Constant: '<S171>/Constant1'
       *  Constant: '<S173>/Constant'
       *  MATLAB Function: '<S173>/Kamm_Circle LatD'
       */
      rtb_Product1 = rtb_alpha_j * rtb_Abs1;

      /* MATLAB Function: '<S173>/MATLAB Function1' */
      Torque_Control_MATLABFunction_d(Torque_Control_B.Constant_dd, rtb_Product1,
        &Torque_Control_B.sf_MATLABFunction1_f);

      /* MATLAB Function: '<S171>/MATLAB Function1' */
      Torque_Control_MATLABFunction_d(Torque_Control_B.Constant1_k,
        Torque_Control_B.sf_MATLABFunction1_f.value,
        &Torque_Control_B.sf_MATLABFunction1_gm);

      /* If: '<S170>/Braking Conditions' incorporates:
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/BrakeSensor_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
            (Torque_Control_U.APPS1_Value <= Torque_Control_U.VDC_Apps_Sat_Down)
            && (Torque_Control_B.Merge1_a == 1.0)) {
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
        /* Outputs for IfAction SubSystem: '<S170>/Regenerative+Mech Braking' incorporates:
         *  ActionPort: '<S189>/Action Port'
         */
        /* MATLAB Function: '<S189>/MATLAB Function' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
          rtb_Abs4 = 0.0;
        } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
          rtb_Abs4 = 1.0;
        } else {
          rtb_Abs4 = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
        }

        /* SignalConversion: '<S189>/OutportBufferForTq_RL' incorporates:
         *  MATLAB Function: '<S189>/MATLAB Function'
         *  Product: '<S192>/Product'
         */
        Torque_Control_B.Merge1_l = Torque_Control_B.sf_MATLABFunction1_gm.value
          * Torque_Control_B.udifference * rtb_Abs4;

        /* SignalConversion: '<S189>/OutportBufferForTq_RR  ' incorporates:
         *  MATLAB Function: '<S189>/MATLAB Function'
         *  Product: '<S193>/Product'
         */
        Torque_Control_B.Merge_li = Torque_Control_B.sf_MATLABFunction2_m.value *
          Torque_Control_B.udifference * rtb_Abs4;

        /* End of Outputs for SubSystem: '<S170>/Regenerative+Mech Braking' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S170>/Mech_Braking' incorporates:
         *  ActionPort: '<S188>/Action Port'
         */
        Torque_Control_Mech_Braking(&Torque_Control_B.Merge_li,
          &Torque_Control_B.Merge1_l, &Torque_Control_P.Mech_Braking_h);

        /* End of Outputs for SubSystem: '<S170>/Mech_Braking' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S170>/Inertia Braking' incorporates:
         *  ActionPort: '<S187>/Action Port'
         */
        Torque_Control_Mech_Braking(&Torque_Control_B.Merge_li,
          &Torque_Control_B.Merge1_l, &Torque_Control_P.InertiaBraking_b);

        /* End of Outputs for SubSystem: '<S170>/Inertia Braking' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S170>/Accelerating' incorporates:
         *  ActionPort: '<S186>/Action Port'
         */
        /* MATLAB Function: '<S186>/Accelerator behaviour ' incorporates:
         *  Inport: '<Root>/APPS1_Value'
         *  Inport: '<Root>/VDC_Apps_Sat_Down'
         *  Inport: '<Root>/VDC_Apps_Sat_Up'
         */
        Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
          Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
          &Torque_Control_B.sf_Acceleratorbehaviour_b);

        /* Product: '<S186>/Product' incorporates:
         *  Product: '<S192>/Product'
         */
        Torque_Control_B.Merge1_l = Torque_Control_B.sf_MATLABFunction1_gm.value
          * Torque_Control_B.udifference *
          Torque_Control_B.sf_Acceleratorbehaviour_b.throttle;

        /* Product: '<S186>/Product1' incorporates:
         *  Product: '<S193>/Product'
         */
        Torque_Control_B.Merge_li = Torque_Control_B.sf_MATLABFunction2_m.value *
          Torque_Control_B.udifference *
          Torque_Control_B.sf_Acceleratorbehaviour_b.throttle;

        /* End of Outputs for SubSystem: '<S170>/Accelerating' */
        break;
      }

      /* End of If: '<S170>/Braking Conditions' */

      /* If: '<S169>/If' incorporates:
       *  Inport: '<Root>/BrakeSensor_Value'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        rtAction = (int8_T)!((Torque_Control_B.Merge1_a == 1.0) &&
                             (Torque_Control_U.BrakeSensor_Value > 0.0));
        Torque_Control_DW.If_ActiveSubsystem_h = rtAction;
      } else {
        rtAction = Torque_Control_DW.If_ActiveSubsystem_h;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S169>/Braking with Regenerative' incorporates:
         *  ActionPort: '<S178>/Action Port'
         */
        Torque__BrakingwithRegenerative(rtb_TransmissionGearRatio,
          Torque_Control_B.Merge_li, Torque_Control_B.Merge1_l,
          &Torque_Control_B.MergeTq_RR, &Torque_Control_B.MergeTq_RL,
          &Torque_Control_B.BrakingwithRegenerative_b,
          &Torque_Control_P.BrakingwithRegenerative_b);

        /* End of Outputs for SubSystem: '<S169>/Braking with Regenerative' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S169>/Acelerating and braking without Regenerative' incorporates:
         *  ActionPort: '<S177>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          /* Gain: '<S177>/Gain' incorporates:
           *  Constant: '<S177>/rpm'
           */
          Torque_Control_B.approx2095 = Torque_Control_P.Gain_Gain_cv *
            Torque_Control_P.rpm_Value_k;

          /* Product: '<S177>/To wheel Tq (static)' incorporates:
           *  Constant: '<S172>/Maximum Transmission Torque Static [Nm]'
           *  Constant: '<S172>/Transmision Ratio[-]'
           */
          Torque_Control_B.TowheelTqstatic =
            Torque_Control_P.TransmisionRatio_Value_j *
            Torque_Control_P.MaximumTransmissionTorqueStat_n;

          /* Product: '<S177>/To wheel Tq (dynamic)' incorporates:
           *  Constant: '<S172>/Maximum Transmission Torque Dynamic [Nm]'
           *  Constant: '<S172>/Transmision Ratio[-]'
           */
          Torque_Control_B.TowheelTqdynamic =
            Torque_Control_P.MaximumTransmissionTorqueDyna_a *
            Torque_Control_P.TransmisionRatio_Value_j;
        }

        /* If: '<S177>/If1' */
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          rtAction = (int8_T)!((rtb_Abs3 > Torque_Control_B.approx2095) &&
                               (rtb_Abs2 > Torque_Control_B.approx2095));
          Torque_Control_DW.If1_ActiveSubsystem_b = rtAction;
        } else {
          rtAction = Torque_Control_DW.If1_ActiveSubsystem_b;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S177>/If Action 1' incorporates:
           *  ActionPort: '<S179>/Action Port'
           */
          Torque_Control_IfAction1(Torque_Control_B.TowheelTqdynamic,
            &Torque_Control_B.Merge2_o);

          /* End of Outputs for SubSystem: '<S177>/If Action 1' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S177>/If Action 2' incorporates:
           *  ActionPort: '<S180>/Action Port'
           */
          Torque_Control_IfAction2(Torque_Control_B.TowheelTqstatic,
            &Torque_Control_B.Merge2_o);

          /* End of Outputs for SubSystem: '<S177>/If Action 2' */
          break;
        }

        /* End of If: '<S177>/If1' */

        /* MATLAB Function: '<S177>/minimum value' */
        rtb_Abs4 = Torque_Control_B.Merge2_o;
        if (Torque_Control_B.Product < Torque_Control_B.Merge2_o) {
          rtb_Abs4 = Torque_Control_B.Product;
        }

        if (Torque_Control_B.Merge_li < rtb_Abs4) {
          rtb_Abs4 = Torque_Control_B.Merge_li;
        }

        /* End of MATLAB Function: '<S177>/minimum value' */

        /* MATLAB Function: '<S177>/minimum value1' */
        rtb_value_g = Torque_Control_B.Merge2_o;
        if (Torque_Control_B.Product < Torque_Control_B.Merge2_o) {
          rtb_value_g = Torque_Control_B.Product;
        }

        if (Torque_Control_B.Merge1_l < rtb_value_g) {
          rtb_value_g = Torque_Control_B.Merge1_l;
        }

        /* End of MATLAB Function: '<S177>/minimum value1' */

        /* MATLAB Function: '<S181>/MATLAB Function' */
        if ((rtb_Abs4 == Torque_Control_B.Merge_li) && (rtb_value_g ==
             Torque_Control_B.Merge1_l)) {
          /* SignalConversion: '<S177>/OutportBufferForTQ_RR' */
          Torque_Control_B.MergeTq_RR = rtb_Abs4;

          /* SignalConversion: '<S177>/OutportBufferForTQ_RL' */
          Torque_Control_B.MergeTq_RL = rtb_value_g;
        } else if (Torque_Control_B.Merge_li > Torque_Control_B.Merge1_l) {
          /* SignalConversion: '<S177>/OutportBufferForTQ_RR' */
          Torque_Control_B.MergeTq_RR = rtb_Abs4;

          /* SignalConversion: '<S177>/OutportBufferForTQ_RL' */
          Torque_Control_B.MergeTq_RL = Torque_Control_B.Merge1_l /
            Torque_Control_B.Merge_li * rtb_Abs4;
        } else if (Torque_Control_B.Merge_li < Torque_Control_B.Merge1_l) {
          /* SignalConversion: '<S177>/OutportBufferForTQ_RR' */
          Torque_Control_B.MergeTq_RR = Torque_Control_B.Merge_li /
            Torque_Control_B.Merge1_l * rtb_value_g;

          /* SignalConversion: '<S177>/OutportBufferForTQ_RL' */
          Torque_Control_B.MergeTq_RL = rtb_value_g;
        } else {
          /* SignalConversion: '<S177>/OutportBufferForTQ_RR' */
          Torque_Control_B.MergeTq_RR = rtb_Abs4;

          /* SignalConversion: '<S177>/OutportBufferForTQ_RL' */
          Torque_Control_B.MergeTq_RL = rtb_value_g;
        }

        /* End of MATLAB Function: '<S181>/MATLAB Function' */
        /* End of Outputs for SubSystem: '<S169>/Acelerating and braking without Regenerative' */
        break;
      }

      /* End of If: '<S169>/If' */

      /* SignalConversion: '<S79>/OutportBufferForCKF_act' */
      Torque_Control_B.Merge3_c = rtb_Abs1;

      /* End of Outputs for SubSystem: '<S67>/VDC without Longitudinal' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S67>/Steering TV with TC' incorporates:
       *  ActionPort: '<S77>/Action Port'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        Torque_Control_B.SteeringWheelMaximumAngle =
          Torque_Control_P.SteeringWheelMaximumAngle_Val_o;
      }

      /* MATLAB Function: '<S98>/MATLAB Function1' incorporates:
       *  Constant: '<S98>/Steering Wheel Maximum Angle'
       */
      if ((Torque_Control_B.Gain > Torque_Control_B.SteeringWheelMaximumAngle) ||
          (Torque_Control_B.Gain < -Torque_Control_B.SteeringWheelMaximumAngle))
      {
        rtb_Abs4 = Torque_Control_B.SteeringWheelMaximumAngle;
      } else {
        rtb_Abs4 = Torque_Control_B.Gain;
      }

      /* End of MATLAB Function: '<S98>/MATLAB Function1' */

      /* MATLAB Function: '<S88>/MATLAB Function' */
      Torque_Control_MATLABFunction_n(rtb_Abs2, rtb_Abs3,
        &Torque_Control_B.sf_MATLABFunction_ab);

      /* Derivative: '<S88>/Derivative' */
      if ((Torque_Control_DW.TimeStampA >= Torque_Control_M->Timing.t[0]) &&
          (Torque_Control_DW.TimeStampB >= Torque_Control_M->Timing.t[0])) {
        rtb_Abs1 = 0.0;
      } else {
        p = Torque_Control_DW.TimeStampA;
        lastU = &Torque_Control_DW.LastUAtTimeA;
        if (Torque_Control_DW.TimeStampA < Torque_Control_DW.TimeStampB) {
          if (Torque_Control_DW.TimeStampB < Torque_Control_M->Timing.t[0]) {
            p = Torque_Control_DW.TimeStampB;
            lastU = &Torque_Control_DW.LastUAtTimeB;
          }
        } else {
          if (Torque_Control_DW.TimeStampA >= Torque_Control_M->Timing.t[0]) {
            p = Torque_Control_DW.TimeStampB;
            lastU = &Torque_Control_DW.LastUAtTimeB;
          }
        }

        rtb_Abs1 = (Torque_Control_B.sf_MATLABFunction_ab.RPM - *lastU) /
          (Torque_Control_M->Timing.t[0] - p);
      }

      /* End of Derivative: '<S88>/Derivative' */

      /* If: '<S98>/SKF or CKF' */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        rtAction = (int8_T)!((-10.0 < rtb_Abs4) && (rtb_Abs4 < 10.0));
        Torque_Control_DW.SKForCKF_ActiveSubsystem = rtAction;
      } else {
        rtAction = Torque_Control_DW.SKForCKF_ActiveSubsystem;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S98>/SKF' incorporates:
         *  ActionPort: '<S101>/Action Port'
         */
        /* If: '<S101>/If' incorporates:
         *  Constant: '<S107>/Constant'
         */
        rtAction = -1;
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          if (rtb_Abs1 >= 900.0) {
            rtAction = 0;
          } else {
            if (rtb_Abs1 < 900.0) {
              rtAction = 1;
            }
          }

          Torque_Control_DW.If_ActiveSubsystem_jm = rtAction;
        } else {
          rtAction = Torque_Control_DW.If_ActiveSubsystem_jm;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S101>/Spin' incorporates:
           *  ActionPort: '<S107>/Action Port'
           */
          if (rtmIsMajorTimeStep(Torque_Control_M)) {
            Torque_Control_B.Constant_du = Torque_Control_P.Constant_Value_n5;
          }

          /* Switch: '<S107>/Switch1' incorporates:
           *  Constant: '<S107>/Constant'
           *  DataStoreRead: '<S88>/SKF_prev '
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          if (Torque_Control_DW.A > Torque_Control_P.Switch1_Threshold_k) {
            p = Torque_Control_DW.A;
          } else {
            p = Torque_Control_U.VDC_SKF_Initial;
          }

          /* End of Switch: '<S107>/Switch1' */

          /* Switch: '<S107>/Switch' incorporates:
           *  Inport: '<Root>/VDC_Cte_CKF'
           */
          if (Torque_Control_U.VDC_Cte_CKF >=
              Torque_Control_P.Switch_Threshold_a) {
            my = Torque_Control_U.VDC_Cte_CKF;
          } else {
            my = Torque_Control_B.Constant_du;
          }

          /* End of Switch: '<S107>/Switch' */

          /* SignalConversion: '<S107>/OutportBufferForSKF_act1' incorporates:
           *  Inport: '<Root>/VDC_SKF_Initial'
           *  MATLAB Function: '<S107>/MATLAB Function'
           *  Product: '<S107>/Product'
           */
          Torque_Control_B.Merge_kj = fmin(p * my,
            Torque_Control_U.VDC_SKF_Initial);

          /* End of Outputs for SubSystem: '<S101>/Spin' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S101>/No spin' incorporates:
           *  ActionPort: '<S106>/Action Port'
           */
          /* Switch: '<S106>/Switch' incorporates:
           *  DataStoreRead: '<S88>/SKF_prev '
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          if (Torque_Control_DW.A > Torque_Control_P.Switch_Threshold_f) {
            rtb_Switch_b = Torque_Control_DW.A;
          } else {
            rtb_Switch_b = Torque_Control_U.VDC_SKF_Initial;
          }

          /* End of Switch: '<S106>/Switch' */

          /* MATLAB Function: '<S106>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_Cte_CKF'
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          Torque_Control_MATLABFunction_e(rtb_Switch_b,
            Torque_Control_U.VDC_SKF_Initial, Torque_Control_U.VDC_Cte_CKF,
            &Torque_Control_B.sf_MATLABFunction_fq);

          /* SignalConversion: '<S106>/OutportBufferForSKF_act0' */
          Torque_Control_B.Merge_kj =
            Torque_Control_B.sf_MATLABFunction_fq.SKF_act0;

          /* End of Outputs for SubSystem: '<S101>/No spin' */
          break;
        }

        /* End of If: '<S101>/If' */

        /* Saturate: '<S101>/Saturation' */
        if (Torque_Control_B.Merge_kj > Torque_Control_P.Saturation_UpperSat_k)
        {
          Torque_Control_B.Saturation_k = Torque_Control_P.Saturation_UpperSat_k;
        } else if (Torque_Control_B.Merge_kj <
                   Torque_Control_P.Saturation_LowerSat_f3) {
          Torque_Control_B.Saturation_k =
            Torque_Control_P.Saturation_LowerSat_f3;
        } else {
          Torque_Control_B.Saturation_k = Torque_Control_B.Merge_kj;
        }

        /* End of Saturate: '<S101>/Saturation' */
        /* End of Outputs for SubSystem: '<S98>/SKF' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S98>/CKF' incorporates:
         *  ActionPort: '<S99>/Action Port'
         */
        /* If: '<S99>/If1' incorporates:
         *  Constant: '<S103>/Constant'
         */
        rtAction = -1;
        if (rtmIsMajorTimeStep(Torque_Control_M)) {
          if (rtb_Abs1 >= 900.0) {
            rtAction = 0;
          } else {
            if (rtb_Abs1 < 900.0) {
              rtAction = 1;
            }
          }

          Torque_Control_DW.If1_ActiveSubsystem_ca = rtAction;
        } else {
          rtAction = Torque_Control_DW.If1_ActiveSubsystem_ca;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S99>/Spin ' incorporates:
           *  ActionPort: '<S103>/Action Port'
           */
          if (rtmIsMajorTimeStep(Torque_Control_M)) {
            Torque_Control_B.Constant_ob = Torque_Control_P.Constant_Value_dl;
          }

          /* Switch: '<S103>/Switch1' incorporates:
           *  Constant: '<S103>/Constant'
           *  DataStoreRead: '<S88>/CKF_prev'
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          if (Torque_Control_DW.B > Torque_Control_P.Switch1_Threshold_p) {
            p = Torque_Control_DW.B;
          } else {
            p = Torque_Control_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S103>/Switch1' */

          /* Switch: '<S103>/Switch' incorporates:
           *  Inport: '<Root>/VDC_Cte_SKF'
           */
          if (Torque_Control_U.VDC_Cte_SKF >=
              Torque_Control_P.Switch_Threshold_b) {
            my = Torque_Control_U.VDC_Cte_SKF;
          } else {
            my = Torque_Control_B.Constant_ob;
          }

          /* End of Switch: '<S103>/Switch' */

          /* SignalConversion: '<S103>/OutportBufferForCKF_act1 ' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           *  MATLAB Function: '<S103>/MATLAB Function'
           *  Product: '<S103>/Product'
           */
          Torque_Control_B.Merge_k = fmin(p * my,
            Torque_Control_U.VDC_CKF_Initial);

          /* End of Outputs for SubSystem: '<S99>/Spin ' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S99>/No spin' incorporates:
           *  ActionPort: '<S102>/Action Port'
           */
          /* Switch: '<S102>/Switch' incorporates:
           *  DataStoreRead: '<S88>/CKF_prev'
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          if (Torque_Control_DW.B > Torque_Control_P.Switch_Threshold_e) {
            rtb_Switch = Torque_Control_DW.B;
          } else {
            rtb_Switch = Torque_Control_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S102>/Switch' */

          /* MATLAB Function: '<S102>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           *  Inport: '<Root>/VDC_Cte_SKF'
           */
          Torque_Contro_MATLABFunction1_b(rtb_Switch,
            Torque_Control_U.VDC_CKF_Initial, Torque_Control_U.VDC_Cte_SKF,
            &Torque_Control_B.sf_MATLABFunction_k2);

          /* SignalConversion: '<S102>/OutportBufferForCKF_act0' */
          Torque_Control_B.Merge_k =
            Torque_Control_B.sf_MATLABFunction_k2.CKF_act0;

          /* End of Outputs for SubSystem: '<S99>/No spin' */
          break;
        }

        /* End of If: '<S99>/If1' */

        /* Saturate: '<S99>/Saturation' */
        if (Torque_Control_B.Merge_k > Torque_Control_P.Saturation_UpperSat_c) {
          Torque_Control_B.Saturation = Torque_Control_P.Saturation_UpperSat_c;
        } else if (Torque_Control_B.Merge_k <
                   Torque_Control_P.Saturation_LowerSat_e) {
          Torque_Control_B.Saturation = Torque_Control_P.Saturation_LowerSat_e;
        } else {
          Torque_Control_B.Saturation = Torque_Control_B.Merge_k;
        }

        /* End of Saturate: '<S99>/Saturation' */
        /* End of Outputs for SubSystem: '<S98>/CKF' */
        break;
      }

      /* End of If: '<S98>/SKF or CKF' */

      /* DataStoreWrite: '<S88>/Data Store Write' */
      Torque_Control_DW.A = Torque_Control_B.Saturation_k;

      /* DataStoreWrite: '<S88>/Data Store Write1' */
      Torque_Control_DW.B = Torque_Control_B.Saturation;

      /* MATLAB Function: '<S77>/Accelerator behaviour' incorporates:
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       *  Inport: '<Root>/VDC_Apps_Sat_Up'
       */
      Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
        Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
        &Torque_Control_B.sf_Acceleratorbehaviour_br);
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        Torque_Control_B.SteeringWheelMaximumAngle_m =
          Torque_Control_P.SteeringWheelMaximumAngle_Val_i;
        Torque_Control_B.Tq_max_motorNm = Torque_Control_P.Tq_max_motorNm_Value;
        Torque_Control_B.Tq_diff_maxNm = Torque_Control_P.Tq_diff_maxNm_Value;
      }

      /* MATLAB Function: '<S77>/MATLAB Function1' incorporates:
       *  Constant: '<S77>/Steering Wheel Maximum Angle'
       *  Constant: '<S77>/Tq_diff_max [Nm]'
       *  Constant: '<S77>/Tq_max_motor [Nm]'
       */
      if (Torque_Control_B.Gain > Torque_Control_B.SteeringWheelMaximumAngle_m)
      {
        rtb_Abs4 = Torque_Control_B.SteeringWheelMaximumAngle_m;
      } else if (Torque_Control_B.Gain <
                 -Torque_Control_B.SteeringWheelMaximumAngle_m) {
        rtb_Abs4 = -Torque_Control_B.SteeringWheelMaximumAngle_m;
      } else {
        rtb_Abs4 = Torque_Control_B.Gain;
      }

      /* End of MATLAB Function: '<S77>/MATLAB Function1' */

      /* MATLAB Function: '<S77>/Steering TV 2017 (without TC)' */
      rtb_Abs1 = 0.0;
      p = 0.0;
      if ((rtb_Abs4 >= -Torque_Control_B.SteeringWheelSaturationpersited) &&
          (rtb_Abs4 <= Torque_Control_B.SteeringWheelSaturationpersited)) {
        rtb_Abs1 = Torque_Control_B.Tq_max_motorNm;
        p = Torque_Control_B.Tq_max_motorNm;
      } else if (rtb_Abs4 > Torque_Control_B.SteeringWheelSaturationpersited) {
        rtb_Abs1 = Torque_Control_B.Tq_max_motorNm;
        p = Torque_Control_B.Tq_max_motorNm - Torque_Control_B.Tq_diff_maxNm /
          (Torque_Control_B.SteeringWheelMaximumAngle_m -
           Torque_Control_B.SteeringWheelSaturationpersited) * (fabs(rtb_Abs4) -
          Torque_Control_B.SteeringWheelSaturationpersited);
      } else {
        if (rtb_Abs4 < -Torque_Control_B.SteeringWheelSaturationpersited) {
          p = Torque_Control_B.Tq_max_motorNm;
          rtb_Abs1 = Torque_Control_B.Tq_max_motorNm -
            Torque_Control_B.Tq_diff_maxNm /
            (Torque_Control_B.SteeringWheelMaximumAngle_m -
             Torque_Control_B.SteeringWheelSaturationpersited) * (fabs(rtb_Abs4)
            - Torque_Control_B.SteeringWheelSaturationpersited);
        }
      }

      /* End of MATLAB Function: '<S77>/Steering TV 2017 (without TC)' */

      /* If: '<S77>/If1' incorporates:
       *  Inport: '<Root>/BrakeSensor_Value'
       *  Inport: '<S83>/Tq_RL_calculated'
       *  Inport: '<S83>/Tq_RR_calculated'
       *  Inport: '<S89>/Tq_RL_calculated'
       *  Inport: '<S89>/Tq_RR_calculated'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        rtAction = (int8_T)!((Torque_Control_U.BrakeSensor_Value > 0.2) &&
                             (Torque_Control_B.sf_Acceleratorbehaviour_br.throttle
                              <= 0.0) && (Torque_Control_B.Merge1_a == 1.0));
        Torque_Control_DW.If1_ActiveSubsystem_c = rtAction;
      } else {
        rtAction = Torque_Control_DW.If1_ActiveSubsystem_c;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S77>/Regenerating' incorporates:
         *  ActionPort: '<S89>/Action Port'
         */
        Mz = rtb_Abs1;
        k = p;

        /* End of Outputs for SubSystem: '<S77>/Regenerating' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S77>/Accelerating, Inertia or Braking without Regen' incorporates:
         *  ActionPort: '<S83>/Action Port'
         */
        k = rtb_Abs1;
        Mz = p;

        /* End of Outputs for SubSystem: '<S77>/Accelerating, Inertia or Braking without Regen' */
        break;
      }

      /* End of If: '<S77>/If1' */

      /* If: '<S77>/If' */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        rtAction = (int8_T)!((-Torque_Control_B.SteeringWheelSaturationpersited <=
                              rtb_Abs4) && (rtb_Abs4 <=
          Torque_Control_B.SteeringWheelSaturationpersited));
        Torque_Control_DW.If_ActiveSubsystem_ds = rtAction;
      } else {
        rtAction = Torque_Control_DW.If_ActiveSubsystem_ds;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S77>/Longitudinal Dynamics' incorporates:
         *  ActionPort: '<S86>/Action Port'
         */
        /* Product: '<S86>/Product' incorporates:
         *  Gain: '<S77>/Transmission Ratio'
         */
        rtb_value_g = Torque_Control_P.TransmissionRatio_Gain * k *
          Torque_Control_B.Saturation_k;

        /* Product: '<S86>/Product1' incorporates:
         *  Gain: '<S77>/Transmission Ratio1'
         */
        rtb_alpha_j = Torque_Control_P.TransmissionRatio1_Gain * Mz *
          Torque_Control_B.Saturation_k;

        /* End of Outputs for SubSystem: '<S77>/Longitudinal Dynamics' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S77>/Lateral Dynamics' incorporates:
         *  ActionPort: '<S85>/Action Port'
         */
        /* Product: '<S85>/Product' incorporates:
         *  Gain: '<S77>/Transmission Ratio'
         */
        rtb_value_g = Torque_Control_P.TransmissionRatio_Gain * k *
          Torque_Control_B.Saturation;

        /* Product: '<S85>/Product1' incorporates:
         *  Gain: '<S77>/Transmission Ratio1'
         */
        rtb_alpha_j = Torque_Control_P.TransmissionRatio1_Gain * Mz *
          Torque_Control_B.Saturation;

        /* End of Outputs for SubSystem: '<S77>/Lateral Dynamics' */
        break;
      }

      /* End of If: '<S77>/If' */

      /* If: '<S82>/Braking Conditions' incorporates:
       *  Inport: '<Root>/BrakeSensor_Value'
       */
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
            (Torque_Control_B.sf_Acceleratorbehaviour_br.throttle <= 0.0) &&
            (Torque_Control_B.Merge1_a == 1.0)) {
          rtAction = 0;
        } else if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
                   (Torque_Control_B.sf_Acceleratorbehaviour_br.throttle <= 0.0)
                   && (Torque_Control_B.Merge1_a == 0.0)) {
          rtAction = 1;
        } else if ((Torque_Control_U.BrakeSensor_Value <= 0.2) &&
                   (Torque_Control_B.sf_Acceleratorbehaviour_br.throttle <= 0.0))
        {
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
        /* Outputs for IfAction SubSystem: '<S82>/Regenerative+Mech Braking' incorporates:
         *  ActionPort: '<S94>/Action Port'
         */
        /* MATLAB Function: '<S94>/MATLAB Function' incorporates:
         *  Inport: '<Root>/BrakeSensor_Value'
         */
        if (Torque_Control_U.BrakeSensor_Value <= 0.2) {
          rtb_Abs4 = 0.0;
        } else if (Torque_Control_U.BrakeSensor_Value >= 0.6) {
          rtb_Abs4 = 1.0;
        } else {
          rtb_Abs4 = 2.5 * Torque_Control_U.BrakeSensor_Value + -0.5;
        }

        rtb_Tq_regen_RR = rtb_Abs4 * rtb_value_g;
        rtb_Tq_regen_RL = rtb_Abs4 * rtb_alpha_j;

        /* End of MATLAB Function: '<S94>/MATLAB Function' */

        /* MATLAB Function: '<S94>/MATLAB Function1' */
        Torque_Control_MATLABFunction(rtb_TransmissionGearRatio, rtb_Tq_regen_RR,
          rtb_Tq_regen_RL, &Torque_Control_B.sf_MATLABFunction1_h);

        /* Gain: '<S94>/Gain' */
        Torque_Control_B.Merge_d = Torque_Control_P.Gain_Gain_b *
          Torque_Control_B.sf_MATLABFunction1_h.RegTq_RR;

        /* Gain: '<S94>/Gain1' */
        Torque_Control_B.Merge1_p = Torque_Control_P.Gain1_Gain *
          Torque_Control_B.sf_MATLABFunction1_h.RegTq_RL;

        /* End of Outputs for SubSystem: '<S82>/Regenerative+Mech Braking' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S82>/Mech_Braking' incorporates:
         *  ActionPort: '<S93>/Action Port'
         */
        Torque_Control_Mech_Braking(&Torque_Control_B.Merge_d,
          &Torque_Control_B.Merge1_p, &Torque_Control_P.Mech_Braking_l);

        /* End of Outputs for SubSystem: '<S82>/Mech_Braking' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S82>/Inertia Braking' incorporates:
         *  ActionPort: '<S92>/Action Port'
         */
        Torque_Control_Mech_Braking(&Torque_Control_B.Merge_d,
          &Torque_Control_B.Merge1_p, &Torque_Control_P.InertiaBraking_e);

        /* End of Outputs for SubSystem: '<S82>/Inertia Braking' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S82>/Accelerating' incorporates:
         *  ActionPort: '<S91>/Action Port'
         */
        /* Product: '<S91>/Product' */
        Torque_Control_B.Merge1_p =
          Torque_Control_B.sf_Acceleratorbehaviour_br.throttle * rtb_alpha_j;

        /* Product: '<S91>/Product1' */
        Torque_Control_B.Merge_d =
          Torque_Control_B.sf_Acceleratorbehaviour_br.throttle * rtb_value_g;

        /* End of Outputs for SubSystem: '<S82>/Accelerating' */
        break;
      }

      /* End of If: '<S82>/Braking Conditions' */

      /* SignalConversion: '<S77>/OutportBufferForCKF_act' */
      Torque_Control_B.Merge3_c = Torque_Control_B.Saturation;

      /* SignalConversion: '<S77>/OutportBufferForSKF_act' */
      Torque_Control_B.Merge2_l = Torque_Control_B.Saturation_k;

      /* SignalConversion: '<S77>/OutportBufferForTq_RL_E2 [Nm] (0,inf)' */
      Torque_Control_B.MergeTq_RL = Torque_Control_B.Merge1_p;

      /* SignalConversion: '<S77>/OutportBufferForTq_RR_E2 [Nm] (0,inf)' */
      Torque_Control_B.MergeTq_RR = Torque_Control_B.Merge_d;

      /* End of Outputs for SubSystem: '<S67>/Steering TV with TC' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S67>/Rigid Axle' incorporates:
       *  ActionPort: '<S76>/Action Port'
       */
      /* MATLAB Function: '<S80>/Accelerator behaviour ' incorporates:
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       *  Inport: '<Root>/VDC_Apps_Sat_Up'
       */
      Torque_Con_Acceleratorbehaviour(Torque_Control_U.APPS1_Value,
        Torque_Control_U.VDC_Apps_Sat_Up, Torque_Control_U.VDC_Apps_Sat_Down,
        &Torque_Control_B.sf_Acceleratorbehaviour_o);
      if (rtmIsMajorTimeStep(Torque_Control_M)) {
        /* Gain: '<S76>/RT_L' incorporates:
         *  Constant: '<S76>/Torque_RL [Nm]'
         */
        Torque_Control_B.RT_L = Torque_Control_P.RT_L_Gain *
          Torque_Control_P.Torque_RLNm_Value;

        /* Gain: '<S76>/RT_R' incorporates:
         *  Constant: '<S76>/Torque_RR [Nm]'
         */
        Torque_Control_B.RT_R = Torque_Control_P.RT_R_Gain *
          Torque_Control_P.Torque_RRNm_Value;
      }

      /* Product: '<S80>/Product' */
      Torque_Control_B.MergeTq_RL =
        Torque_Control_B.sf_Acceleratorbehaviour_o.throttle *
        Torque_Control_B.RT_L;

      /* Product: '<S80>/Product1' */
      Torque_Control_B.MergeTq_RR =
        Torque_Control_B.sf_Acceleratorbehaviour_o.throttle *
        Torque_Control_B.RT_R;

      /* End of Outputs for SubSystem: '<S67>/Rigid Axle' */
      break;

     case 4:
      break;
    }

    /* End of If: '<S67>/FAILURE MODE' */
    /* End of Outputs for SubSystem: '<S14>/Vehicle Dynamics Control Modes' */
  }

  /* End of If: '<S14>/If' */

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
   *  Gain: '<S14>/Gain1'
   */
  Torque_Control_Y.Throttle = Torque_Control_P.Gain1_Gain_o *
    Torque_Control_B.Throttle;

  /* Outport: '<Root>/Fy_R' */
  Torque_Control_Y.Fy_R = Torque_Control_B.Merge6;

  /* Outport: '<Root>/Mass' */
  Torque_Control_Y.Mass = Torque_Control_B.Merge4;

  /* Outport: '<Root>/Handling' */
  Torque_Control_Y.Handling = Torque_Control_B.Merge5_e;

  /* Outport: '<Root>/SKF_actual' */
  Torque_Control_Y.SKF_actual = Torque_Control_B.Merge2_l;

  /* Outport: '<Root>/CKF_actual' */
  Torque_Control_Y.CKF_actual = Torque_Control_B.Merge3_c;

  /* Outport: '<Root>/SteeringSensor_Value' */
  Torque_Control_Y.SteeringSensor_Value = rtb_Gain_f;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Outport: '<Root>/APPS_Implausibility' */
    Torque_Control_Y.APPS_Implausibility = rtb_LogicalOperator1;

    /* Outport: '<Root>/Brake_Implausibility' */
    Torque_Control_Y.Brake_Implausibility = rtb_LogicalOperator2;
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
  rtb_Gain_f = Torque_Control_U.Accumulator_Voltage *
    Torque_Control_U.Accumulator_Current;

  /* Outport: '<Root>/Power' */
  Torque_Control_Y.Power = rtb_Gain_f;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* If: '<S17>/If' incorporates:
   *  Inport: '<S17>/Power'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!(rtb_Gain_f >= 80000.0);
    Torque_Control_DW.If_ActiveSubsystem_kl = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_kl;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S17>/LimitReached' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    Torque_Control_LimitReached(&Torque_Control_B.Merge1_pg,
      &Torque_Control_P.LimitReached);

    /* End of Outputs for SubSystem: '<S17>/LimitReached' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S17>/OK_OrLatch' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* If: '<S19>/If' incorporates:
     *  DataStoreRead: '<S17>/Data Store Read30'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      rtAction = (int8_T)!(Torque_Control_DW.A_i > 0.0);
      Torque_Control_DW.If_ActiveSubsystem_c = rtAction;
    } else {
      rtAction = Torque_Control_DW.If_ActiveSubsystem_c;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S19>/Latched Error' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      Torque_Control_LimitReached(&Torque_Control_B.Merge1_pg,
        &Torque_Control_P.LatchedError);

      /* End of Outputs for SubSystem: '<S19>/Latched Error' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S19>/OK' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      Torque_Control_LimitReached(&Torque_Control_B.Merge1_pg,
        &Torque_Control_P.OK);

      /* End of Outputs for SubSystem: '<S19>/OK' */
      break;
    }

    /* End of If: '<S19>/If' */
    /* End of Outputs for SubSystem: '<S17>/OK_OrLatch' */
    break;
  }

  /* End of If: '<S17>/If' */

  /* DataStoreWrite: '<S17>/Data Store Write20' */
  Torque_Control_DW.A_i = Torque_Control_B.Merge1_pg;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* Outport: '<Root>/PowerLimitReached' */
  Torque_Control_Y.PowerLimitReached = Torque_Control_B.Merge1_pg;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Outport: '<Root>/PowerMean500ms' incorporates:
   *  Inport: '<S17>/Power'
   */
  Torque_Control_Y.PowerMean500ms = rtb_Gain_f;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* Outport: '<Root>/Torque_OK' */
  Torque_Control_Y.Torque_OK = Torque_Control_B.LogicalOperator;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Outport: '<Root>/Regenerative_Enable' */
    Torque_Control_Y.Regenerative_Enable = Torque_Control_B.Merge1_a;

    /* Constant: '<S38>/Constant' */
    Torque_Control_B.Constant_n = Torque_Control_P.CompareToConstant1_const;

    /* Constant: '<S37>/Constant' */
    Torque_Control_B.Constant_i = Torque_Control_P.CompareToConstant_const_p;
  }

  /* Outputs for Atomic SubSystem: '<S14>/Regeneration_Enable' */
  /* Outport: '<Root>/Dash_Speed' incorporates:
   *  Product: '<S65>/Divide'
   *  Sum: '<S65>/Add'
   */
  Torque_Control_Y.Dash_Speed = (rtb_Gain + rtb_Subtract1) /
    Torque_Control_B.Constant_o;

  /* End of Outputs for SubSystem: '<S14>/Regeneration_Enable' */

  /* If: '<S10>/If' incorporates:
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/Temp_IGBT'
   *  Logic: '<S10>/Logical Operator'
   *  RelationalOperator: '<S37>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!((Torque_Control_U.Car_State ==
                          Torque_Control_B.Constant_n) ||
                         (Torque_Control_U.Temp_IGBT >
                          Torque_Control_B.Constant_i));
    Torque_Control_DW.If_ActiveSubsystem_d = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_d;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S10>/Pumps_Control_ON' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      /* SignalConversion: '<S41>/OutportBufferFor1' incorporates:
       *  Constant: '<S41>/Constant'
       */
      rtb_Merge_d = Torque_Control_P.Constant_Value_i;
    }

    /* End of Outputs for SubSystem: '<S10>/Pumps_Control_ON' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S10>/Pumps_Control_OFF' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      /* SignalConversion: '<S40>/OutportBufferFor0' incorporates:
       *  Constant: '<S40>/Constant'
       */
      rtb_Merge_d = Torque_Control_P.Constant_Value_n;
    }

    /* End of Outputs for SubSystem: '<S10>/Pumps_Control_OFF' */
    break;
  }

  /* End of If: '<S10>/If' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Outport: '<Root>/Pumps_Control' */
    Torque_Control_Y.Pumps_Control = rtb_Merge_d;
  }

  /* Outputs for Atomic SubSystem: '<S14>/WORKSHOP_MODE_RESTRICTIONS' */
  /* If: '<S68>/If' incorporates:
   *  Constant: '<S207>/Constant'
   *  Inport: '<Root>/Workshop_Mode_Enable'
   *  Inport: '<S206>/In1'
   *  Inport: '<S206>/In2'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!(Torque_Control_U.Workshop_Mode_Enable == 1.0);
    Torque_Control_DW.If_ActiveSubsystem_ed = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_ed;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S68>/Torque_Reduction ' incorporates:
     *  ActionPort: '<S207>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      Torque_Control_B.Constant_m = Torque_Control_P.Constant_Value_dm;
    }

    /* Product: '<S207>/Divide' incorporates:
     *  Constant: '<S207>/Constant'
     */
    rtb_Merge_n = Torque_Control_B.MergeTq_RR / Torque_Control_B.Constant_m;

    /* Saturate: '<S207>/Saturation' */
    if (rtb_Merge_n > Torque_Control_P.Saturation_UpperSat_h) {
      rtb_Merge_n = Torque_Control_P.Saturation_UpperSat_h;
    } else {
      if (rtb_Merge_n < Torque_Control_P.Saturation_LowerSat_j) {
        rtb_Merge_n = Torque_Control_P.Saturation_LowerSat_j;
      }
    }

    /* End of Saturate: '<S207>/Saturation' */

    /* Product: '<S207>/Divide1' */
    rtb_Merge1_l = Torque_Control_B.MergeTq_RL / Torque_Control_B.Constant_m;

    /* Saturate: '<S207>/Saturation1' */
    if (rtb_Merge1_l > Torque_Control_P.Saturation1_UpperSat_k) {
      rtb_Merge1_l = Torque_Control_P.Saturation1_UpperSat_k;
    } else {
      if (rtb_Merge1_l < Torque_Control_P.Saturation1_LowerSat_k) {
        rtb_Merge1_l = Torque_Control_P.Saturation1_LowerSat_k;
      }
    }

    /* End of Saturate: '<S207>/Saturation1' */
    /* End of Outputs for SubSystem: '<S68>/Torque_Reduction ' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S68>/BYPASS' incorporates:
     *  ActionPort: '<S206>/Action Port'
     */
    rtb_Merge_n = Torque_Control_B.MergeTq_RR;
    rtb_Merge1_l = Torque_Control_B.MergeTq_RL;

    /* End of Outputs for SubSystem: '<S68>/BYPASS' */
    break;
  }

  /* End of If: '<S68>/If' */

  /* Saturate: '<S68>/Saturation' */
  if (rtb_Merge_n > Torque_Control_P.Saturation_UpperSat_g) {
    rtb_Merge_n = Torque_Control_P.Saturation_UpperSat_g;
  } else {
    if (rtb_Merge_n < Torque_Control_P.Saturation_LowerSat_fi) {
      rtb_Merge_n = Torque_Control_P.Saturation_LowerSat_fi;
    }
  }

  /* End of Saturate: '<S68>/Saturation' */

  /* Saturate: '<S68>/Saturation1' */
  if (rtb_Merge1_l > Torque_Control_P.Saturation1_UpperSat_m) {
    rtb_Gain = Torque_Control_P.Saturation1_UpperSat_m;
  } else if (rtb_Merge1_l < Torque_Control_P.Saturation1_LowerSat_lw) {
    rtb_Gain = Torque_Control_P.Saturation1_LowerSat_lw;
  } else {
    rtb_Gain = rtb_Merge1_l;
  }

  /* End of Saturate: '<S68>/Saturation1' */
  /* End of Outputs for SubSystem: '<S14>/WORKSHOP_MODE_RESTRICTIONS' */

  /* Gain: '<Root>/Gain1' */
  rtb_Subtract1 = Torque_Control_P.Gain1_Gain_m * rtb_Merge_n;

  /* Gain: '<Root>/Gain' */
  rtb_Gain_f = Torque_Control_P.Gain_Gain_g * rtb_Gain;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Constant: '<S216>/Constant' */
    Torque_Control_B.Constant_b = Torque_Control_P.Temphigherthan50_const_l;

    /* Constant: '<S213>/Constant1' */
    Torque_Control_B.Constant1 = Torque_Control_P.Constant1_Value_e;

    /* Constant: '<S213>/Constant2' */
    Torque_Control_B.Constant2 = Torque_Control_P.Constant2_Value_mw;

    /* Constant: '<S16>/initial_limitation' */
    Torque_Control_B.initial_limitation =
      Torque_Control_P.initial_limitation_Value_k;

    /* Constant: '<S213>/Constant3' */
    Torque_Control_B.Constant3 = Torque_Control_P.Constant3_Value_h;
  }

  /* RelationalOperator: '<S216>/Compare' incorporates:
   *  Inport: '<Root>/Highest_CellTemp'
   */
  rtb_LogicalOperator1 = (Torque_Control_U.Highest_CellTemp >=
    Torque_Control_B.Constant_b);

  /* Sum: '<S213>/Add2' incorporates:
   *  Inport: '<Root>/Highest_CellTemp'
   *  Product: '<S213>/Divide'
   *  Product: '<S213>/Product4'
   *  Sum: '<S213>/Add1'
   *  Sum: '<S213>/Add3'
   */
  rtb_Merge_d = ((Torque_Control_B.Constant1 /
                  (Torque_Control_U.Highest_CellTemp -
                   Torque_Control_B.Constant2) -
                  Torque_Control_B.initial_limitation) * (real_T)
                 rtb_LogicalOperator1 - (real_T)rtb_LogicalOperator1) +
    Torque_Control_B.Constant3;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Constant: '<S217>/Constant' */
    Torque_Control_B.Constant_a = Torque_Control_P.Temphigherthan50_const_g;

    /* Constant: '<S214>/Constant1' */
    Torque_Control_B.Constant1_a = Torque_Control_P.Constant1_Value_fp;

    /* Constant: '<S214>/Constant2' */
    Torque_Control_B.Constant2_p = Torque_Control_P.Constant2_Value_b;

    /* Constant: '<S214>/Constant3' */
    Torque_Control_B.Constant3_i = Torque_Control_P.Constant3_Value_c;
  }

  /* RelationalOperator: '<S217>/Compare' incorporates:
   *  Inport: '<Root>/Temp_IGBT'
   */
  rtb_LogicalOperator1 = (Torque_Control_U.Temp_IGBT >=
    Torque_Control_B.Constant_a);

  /* Sum: '<S214>/Add2' incorporates:
   *  Inport: '<Root>/Temp_IGBT'
   *  Product: '<S214>/Divide'
   *  Product: '<S214>/Product4'
   *  Sum: '<S214>/Add1'
   *  Sum: '<S214>/Add3'
   */
  rtb_Merge1_l = ((Torque_Control_B.Constant1_a / (Torque_Control_U.Temp_IGBT -
    Torque_Control_B.Constant2_p) - Torque_Control_B.initial_limitation) *
                  (real_T)rtb_LogicalOperator1 - (real_T)rtb_LogicalOperator1) +
    Torque_Control_B.Constant3_i;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Constant: '<S218>/Constant' */
    Torque_Control_B.Constant_d = Torque_Control_P.Temphigherthan110_const_c;

    /* Constant: '<S215>/Constant1' */
    Torque_Control_B.Constant1_h = Torque_Control_P.Constant1_Value_p2;

    /* Constant: '<S215>/Constant2' */
    Torque_Control_B.Constant2_pf = Torque_Control_P.Constant2_Value_hv;

    /* Constant: '<S215>/Constant3' */
    Torque_Control_B.Constant3_f = Torque_Control_P.Constant3_Value_i;

    /* Constant: '<Root>/Gear Ratio' */
    Torque_Control_B.GearRatio = Torque_Control_P.GearRatio_Value;

    /* Constant: '<Root>/Max Tq per motor [Nm]' */
    Torque_Control_B.MaxTqpermotorNm = Torque_Control_P.MaxTqpermotorNm_Value;
  }

  /* RelationalOperator: '<S218>/Compare' incorporates:
   *  Inport: '<Root>/Temp_Motors'
   */
  rtb_LogicalOperator1 = (Torque_Control_U.Temp_Motors >=
    Torque_Control_B.Constant_d);

  /* MATLAB Function: '<Root>/SoP selection and sum of max WHEEL Tq available' incorporates:
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/BrakeSensor_Value'
   *  Inport: '<Root>/VDC_Apps_Sat_Down'
   */
  if ((Torque_Control_U.BrakeSensor_Value > 0.2) &&
      (Torque_Control_U.APPS1_Value < Torque_Control_U.VDC_Apps_Sat_Down)) {
    rtb_Abs4 = 1.0;
  } else {
    rtb_Abs4 = 0.0;
  }

  /* End of MATLAB Function: '<Root>/SoP selection and sum of max WHEEL Tq available' */

  /* If: '<Root>/If' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S30>/Constant3'
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S31>/Constant2'
   *  Constant: '<S31>/Constant3'
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S32>/Constant2'
   *  Constant: '<S32>/Constant3'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S3>/Max_Tq_per_motor'
   *  Constant: '<S3>/initial_limitation'
   *  Inport: '<S6>/In1'
   *  Inport: '<S6>/In2'
   */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    rtAction = (int8_T)!(Torque_Control_B.Constant14 == 0.0);
    Torque_Control_DW.If_ActiveSubsystem_e = rtAction;
  } else {
    rtAction = Torque_Control_DW.If_ActiveSubsystem_e;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    rtb_Merge = rtb_Subtract1;
    rtb_Merge3 = rtb_Gain_f;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      Torque_Control_B.Max_Tq_per_motor =
        Torque_Control_P.Max_Tq_per_motor_Value;
      Torque_Control_B.Constant_g = Torque_Control_P.Temphigherthan50_const;
      Torque_Control_B.Constant1_l = Torque_Control_P.Constant1_Value;
      Torque_Control_B.Constant2_n = Torque_Control_P.Constant2_Value;
      Torque_Control_B.initial_limitation_m =
        Torque_Control_P.initial_limitation_Value;
      Torque_Control_B.Constant3_o = Torque_Control_P.Constant3_Value;
    }

    /* RelationalOperator: '<S33>/Compare' incorporates:
     *  Constant: '<S30>/Constant1'
     *  Constant: '<S30>/Constant2'
     *  Constant: '<S30>/Constant3'
     *  Constant: '<S33>/Constant'
     *  Constant: '<S3>/Max_Tq_per_motor'
     *  Constant: '<S3>/initial_limitation'
     *  Inport: '<Root>/Highest_CellTemp'
     */
    rtb_LogicalOperator2 = (Torque_Control_U.Highest_CellTemp >=
      Torque_Control_B.Constant_g);

    /* Sum: '<S30>/Add2' incorporates:
     *  Inport: '<Root>/Highest_CellTemp'
     *  Product: '<S30>/Divide'
     *  Product: '<S30>/Product4'
     *  Sum: '<S30>/Add1'
     *  Sum: '<S30>/Add3'
     */
    rtb_Abs1 = ((Torque_Control_B.Constant1_l /
                 (Torque_Control_U.Highest_CellTemp -
                  Torque_Control_B.Constant2_n) -
                 Torque_Control_B.initial_limitation_m) * (real_T)
                rtb_LogicalOperator2 - (real_T)rtb_LogicalOperator2) +
      Torque_Control_B.Constant3_o;

    /* Saturate: '<S30>/Saturation1' */
    if (rtb_Abs1 > Torque_Control_P.Saturation1_UpperSat) {
      rtb_Abs1 = Torque_Control_P.Saturation1_UpperSat;
    } else {
      if (rtb_Abs1 < Torque_Control_P.Saturation1_LowerSat) {
        rtb_Abs1 = Torque_Control_P.Saturation1_LowerSat;
      }
    }

    /* End of Saturate: '<S30>/Saturation1' */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      Torque_Control_B.Constant_j3 = Torque_Control_P.Temphigherthan50_const_k;
      Torque_Control_B.Constant1_d = Torque_Control_P.Constant1_Value_o;
      Torque_Control_B.Constant2_k = Torque_Control_P.Constant2_Value_h;
      Torque_Control_B.Constant3_n = Torque_Control_P.Constant3_Value_d;
    }

    /* RelationalOperator: '<S34>/Compare' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant2'
     *  Constant: '<S31>/Constant3'
     *  Constant: '<S34>/Constant'
     *  Inport: '<Root>/Temp_IGBT'
     */
    rtb_LogicalOperator2 = (Torque_Control_U.Temp_IGBT >=
      Torque_Control_B.Constant_j3);

    /* Sum: '<S31>/Add2' incorporates:
     *  Inport: '<Root>/Temp_IGBT'
     *  Product: '<S31>/Divide'
     *  Product: '<S31>/Product4'
     *  Sum: '<S31>/Add1'
     *  Sum: '<S31>/Add3'
     */
    rtb_value_g = ((Torque_Control_B.Constant1_d / (Torque_Control_U.Temp_IGBT -
      Torque_Control_B.Constant2_k) - Torque_Control_B.initial_limitation_m) *
                   (real_T)rtb_LogicalOperator2 - (real_T)rtb_LogicalOperator2)
      + Torque_Control_B.Constant3_n;

    /* Saturate: '<S31>/Saturation1' */
    if (rtb_value_g > Torque_Control_P.Saturation1_UpperSat_a) {
      rtb_value_g = Torque_Control_P.Saturation1_UpperSat_a;
    } else {
      if (rtb_value_g < Torque_Control_P.Saturation1_LowerSat_a) {
        rtb_value_g = Torque_Control_P.Saturation1_LowerSat_a;
      }
    }

    /* End of Saturate: '<S31>/Saturation1' */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      Torque_Control_B.Constant_mu = Torque_Control_P.Temphigherthan110_const;
      Torque_Control_B.Constant1_c = Torque_Control_P.Constant1_Value_p;
      Torque_Control_B.Constant2_m = Torque_Control_P.Constant2_Value_m;
      Torque_Control_B.Constant3_it = Torque_Control_P.Constant3_Value_e;
    }

    /* RelationalOperator: '<S35>/Compare' incorporates:
     *  Constant: '<S32>/Constant1'
     *  Constant: '<S32>/Constant2'
     *  Constant: '<S32>/Constant3'
     *  Constant: '<S35>/Constant'
     *  Inport: '<Root>/Temp_Motors'
     */
    rtb_LogicalOperator2 = (Torque_Control_U.Temp_Motors >=
      Torque_Control_B.Constant_mu);

    /* Sum: '<S32>/Add2' incorporates:
     *  Inport: '<Root>/Temp_Motors'
     *  Product: '<S32>/Divide'
     *  Product: '<S32>/Product4'
     *  Sum: '<S32>/Add1'
     *  Sum: '<S32>/Add3'
     */
    rtb_alpha_j = ((Torque_Control_B.Constant1_c / (Torque_Control_U.Temp_Motors
      - Torque_Control_B.Constant2_m) - Torque_Control_B.initial_limitation_m) *
                   (real_T)rtb_LogicalOperator2 - (real_T)rtb_LogicalOperator2)
      + Torque_Control_B.Constant3_it;

    /* Saturate: '<S32>/Saturation1' */
    if (rtb_alpha_j > Torque_Control_P.Saturation1_UpperSat_g) {
      rtb_alpha_j = Torque_Control_P.Saturation1_UpperSat_g;
    } else {
      if (rtb_alpha_j < Torque_Control_P.Saturation1_LowerSat_l) {
        rtb_alpha_j = Torque_Control_P.Saturation1_LowerSat_l;
      }
    }

    /* End of Saturate: '<S32>/Saturation1' */

    /* MinMax: '<S26>/Min' */
    rtb_Merge = fmin(fmin(rtb_Abs1, rtb_value_g), rtb_alpha_j);

    /* Product: '<S24>/Product4' incorporates:
     *  Gain: '<S24>/Gain6'
     *  Inport: '<Root>/SoC_Low'
     *  Lookup_n-D: '<S24>/Lookup_SoC_SoP_dischg'
     */
    rtb_Merge3 = look1_binlxpw(Torque_Control_P.Gain6_Gain *
      Torque_Control_U.SoC_Low, Torque_Control_P.Lookup_SoC_SoP_dischg_bp01Data,
      Torque_Control_P.Lookup_SoC_SoP_dischg_tableData, 7U) * rtb_Merge;

    /* Product: '<S24>/Product5' incorporates:
     *  Gain: '<S24>/Gain5'
     *  Inport: '<Root>/Highest_CellTemp'
     *  Inport: '<Root>/SoC_High'
     *  Lookup_n-D: '<S24>/Lookup_SoC_SoP_chg'
     *  Lookup_n-D: '<S24>/Lookup_Temp_SoP_chg'
     *  Product: '<S24>/Product'
     */
    rtb_Merge *= look1_binlxpw(Torque_Control_P.Gain5_Gain *
      Torque_Control_U.SoC_High, Torque_Control_P.Lookup_SoC_SoP_chg_bp01Data,
      Torque_Control_P.Lookup_SoC_SoP_chg_tableData, 7U) * look1_binlxpw
      (Torque_Control_U.Highest_CellTemp,
       Torque_Control_P.Lookup_Temp_SoP_chg_bp01Data,
       Torque_Control_P.Lookup_Temp_SoP_chg_tableData, 4U);

    /* MATLAB Function: '<S3>/Tq_limitation because of Temp' incorporates:
     *  Saturate: '<S3>/Saturation'
     */
    if (rtb_Abs4 == 1.0) {
      /* Saturate: '<S3>/Saturation1' */
      if (rtb_Merge > Torque_Control_P.Saturation1_UpperSat_e) {
        rtb_Merge3 = -Torque_Control_P.Saturation1_UpperSat_e;
      } else if (rtb_Merge < Torque_Control_P.Saturation1_LowerSat_o) {
        rtb_Merge3 = -Torque_Control_P.Saturation1_LowerSat_o;
      } else {
        rtb_Merge3 = -rtb_Merge;
      }

      /* End of Saturate: '<S3>/Saturation1' */
    } else if (rtb_Merge3 > Torque_Control_P.Saturation_UpperSat) {
      /* Saturate: '<S3>/Saturation' */
      rtb_Merge3 = Torque_Control_P.Saturation_UpperSat;
    } else {
      if (rtb_Merge3 < Torque_Control_P.Saturation_LowerSat) {
        /* Saturate: '<S3>/Saturation' */
        rtb_Merge3 = Torque_Control_P.Saturation_LowerSat;
      }
    }

    rtb_Merge = rtb_Merge3 * 2.0 * Torque_Control_B.Max_Tq_per_motor;
    p = rtb_Subtract1 + rtb_Gain_f;
    if (p > rtb_Merge) {
      rtb_Subtract1 = rtb_Subtract1 / p * rtb_Merge;
      rtb_Gain_f = rtb_Merge - rtb_Subtract1;
    }

    /* SignalConversion: '<S3>/OutportBufferForTq_L' */
    rtb_Merge3 = rtb_Gain_f;

    /* SignalConversion: '<S3>/OutportBufferForTq_R' incorporates:
     *  MATLAB Function: '<S3>/Tq_limitation because of Temp'
     */
    rtb_Merge = rtb_Subtract1;
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      Torque_Control_B.Constant_jv = Torque_Control_P.Flag_Accu_const;
      Torque_Control_B.Constant_o4 = Torque_Control_P.Flag_Inv_const;
    }

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     *  Constant: '<S28>/Constant'
     */
    Torque_Control_B.Compare = (rtb_Abs1 < Torque_Control_B.Constant_jv);

    /* RelationalOperator: '<S28>/Compare' */
    Torque_Control_B.Compare_d = (rtb_value_g < Torque_Control_B.Constant_o4);
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      Torque_Control_B.Constant_kc = Torque_Control_P.Flag_Mot_const;
    }

    /* RelationalOperator: '<S29>/Compare' incorporates:
     *  Constant: '<S29>/Constant'
     */
    Torque_Control_B.Compare_g = (rtb_alpha_j < Torque_Control_B.Constant_kc);

    /* End of Outputs for SubSystem: '<Root>/Controls Temperature by limiting Torque' */
    break;
  }

  /* End of If: '<Root>/If' */

  /* Outport: '<Root>/Meas VDC Torque_L' */
  Torque_Control_Y.MeasVDCTorque_L = rtb_Merge3;

  /* Outport: '<Root>/Meas VDC Torque_R' */
  Torque_Control_Y.MeasVDCTorque_R = rtb_Merge;

  /* Outport: '<Root>/Torque_L' */
  Torque_Control_Y.Torque_L = rtb_Gain;

  /* Outport: '<Root>/Torque_R' */
  Torque_Control_Y.Torque_R = rtb_Merge_n;
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    /* Constant: '<S9>/Max_Power_discharge [kW]' */
    Torque_Control_B.Max_Power_dischargekW =
      Torque_Control_P.Max_Power_dischargekW_Value;

    /* Constant: '<S9>/Max_Power_charge [kW]' */
    Torque_Control_B.Max_Power_chargekW =
      Torque_Control_P.Max_Power_chargekW_Value;
  }

  /* MATLAB Function: '<S9>/MATLAB Function' */
  if (rtb_Abs4 == 1.0) {
    rtb_Merge_n = -Torque_Control_B.Max_Power_chargekW * 1000.0;
  } else {
    rtb_Merge_n = Torque_Control_B.Max_Power_dischargekW * 1000.0;
  }

  if (rtb_Merge * rtb_Abs3 + rtb_Merge3 * rtb_Abs2 > rtb_Merge_n) {
    rtb_Merge /= rtb_Merge + rtb_Merge3;
    rtb_Merge = rtb_Merge * rtb_Merge_n / ((rtb_Abs3 - rtb_Abs2) * rtb_Merge +
      rtb_Abs2);
    rtb_Merge3 = (rtb_Merge_n - rtb_Merge * rtb_Abs3) / rtb_Abs2;
  }

  /* If: '<Root>/If1' */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
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
    /* Gain: '<S23>/A//Nm' incorporates:
     *  MATLAB Function: '<S9>/MATLAB Function'
     */
    Torque_Control_B.Merge2_e = Torque_Control_P.ANm_Gain_b * rtb_Merge;

    /* End of Outputs for SubSystem: '<S2>/KT_R_EMY' */

    /* Outputs for Atomic SubSystem: '<S2>/KT_L_TORKY' */
    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<S22>/A//Nm'
     */
    Torque_Control_B.Merge1_a0 = Torque_Control_P.ANm_Gain * rtb_Merge3 *
      Torque_Control_P.Gain_Gain;

    /* End of Outputs for SubSystem: '<S2>/KT_L_TORKY' */
    /* End of Outputs for SubSystem: '<Root>/Calculate Current Conversion' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Current 0' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_M)) {
      /* SignalConversion: '<S4>/OutportBufferForCurrent L' incorporates:
       *  Constant: '<S4>/Constant'
       */
      Torque_Control_B.Merge1_a0 = Torque_Control_P.Constant_Value;

      /* SignalConversion: '<S4>/OutportBufferForCurrent R' incorporates:
       *  Constant: '<S4>/Constant'
       */
      Torque_Control_B.Merge2_e = Torque_Control_P.Constant_Value;
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
    /* Constant: '<S210>/Constant' */
    Torque_Control_B.Constant_j = Torque_Control_P.Flag_Accu_const_h;

    /* Constant: '<S211>/Constant' */
    Torque_Control_B.Constant_do = Torque_Control_P.Flag_Inv_const_e;

    /* Constant: '<S212>/Constant' */
    Torque_Control_B.Constant_bc = Torque_Control_P.Flag_Mot_const_n;
  }

  /* Sum: '<S215>/Add2' incorporates:
   *  Inport: '<Root>/Temp_Motors'
   *  Product: '<S215>/Divide'
   *  Product: '<S215>/Product4'
   *  Sum: '<S215>/Add1'
   *  Sum: '<S215>/Add3'
   */
  rtb_Gain = ((Torque_Control_B.Constant1_h / (Torque_Control_U.Temp_Motors -
    Torque_Control_B.Constant2_pf) - Torque_Control_B.initial_limitation) *
              (real_T)rtb_LogicalOperator1 - (real_T)rtb_LogicalOperator1) +
    Torque_Control_B.Constant3_f;

  /* Saturate: '<S213>/Saturation1' */
  if (rtb_Merge_d > Torque_Control_P.Saturation1_UpperSat_d) {
    rtb_Merge_d = Torque_Control_P.Saturation1_UpperSat_d;
  } else {
    if (rtb_Merge_d < Torque_Control_P.Saturation1_LowerSat_m) {
      rtb_Merge_d = Torque_Control_P.Saturation1_LowerSat_m;
    }
  }

  /* End of Saturate: '<S213>/Saturation1' */

  /* Saturate: '<S214>/Saturation1' */
  if (rtb_Merge1_l > Torque_Control_P.Saturation1_UpperSat_i) {
    rtb_Merge1_l = Torque_Control_P.Saturation1_UpperSat_i;
  } else {
    if (rtb_Merge1_l < Torque_Control_P.Saturation1_LowerSat_ko) {
      rtb_Merge1_l = Torque_Control_P.Saturation1_LowerSat_ko;
    }
  }

  /* End of Saturate: '<S214>/Saturation1' */

  /* Saturate: '<S215>/Saturation1' */
  if (rtb_Gain > Torque_Control_P.Saturation1_UpperSat_b) {
    rtb_Gain = Torque_Control_P.Saturation1_UpperSat_b;
  } else {
    if (rtb_Gain < Torque_Control_P.Saturation1_LowerSat_b) {
      rtb_Gain = Torque_Control_P.Saturation1_LowerSat_b;
    }
  }

  /* End of Saturate: '<S215>/Saturation1' */

  /* Outport: '<Root>/TV_Flag_Temperature' incorporates:
   *  MATLAB Function: '<Root>/Flag_Temp merged'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   *  RelationalOperator: '<S210>/Compare'
   *  RelationalOperator: '<S211>/Compare'
   *  RelationalOperator: '<S212>/Compare'
   */
  Torque_Control_Y.TV_Flag_Temperature = ((rtb_Merge_d <
    Torque_Control_B.Constant_j) || (rtb_Merge1_l < Torque_Control_B.Constant_do)
    || (rtb_Gain < Torque_Control_B.Constant_bc) || (Torque_Control_B.Compare ||
    Torque_Control_B.Compare_d || Torque_Control_B.Compare_g));

  /* Abs: '<S14>/Abs' incorporates:
   *  Inport: '<Root>/ACCEL_F_X_SI'
   */
  Torque_Control_B.Abs = fabs(Torque_Control_U.ACCEL_F_X_SI);
}

/* Model update function */
void Torque_Control_update(void)
{
  real_T *lastU;

  /* Update for If: '<S14>/If' */
  if (Torque_Control_DW.If_ActiveSubsystem_k == 0) {
    /* Update for IfAction SubSystem: '<S14>/Vehicle Dynamics Control Modes' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    /* Update for If: '<S67>/FAILURE MODE' */
    switch (Torque_Control_DW.FAILUREMODE_ActiveSubsystem) {
     case 0:
      /* Update for IfAction SubSystem: '<S67>/VDC Complete' incorporates:
       *  ActionPort: '<S78>/Action Port'
       */
      /* Update for Derivative: '<S118>/Derivative' */
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

      /* End of Update for Derivative: '<S118>/Derivative' */
      /* End of Update for SubSystem: '<S67>/VDC Complete' */
      break;

     case 1:
      /* Update for IfAction SubSystem: '<S67>/VDC without Longitudinal' incorporates:
       *  ActionPort: '<S79>/Action Port'
       */
      /* Update for Derivative: '<S175>/Derivative' */
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

      /* End of Update for Derivative: '<S175>/Derivative' */
      /* End of Update for SubSystem: '<S67>/VDC without Longitudinal' */
      break;

     case 2:
      /* Update for IfAction SubSystem: '<S67>/Steering TV with TC' incorporates:
       *  ActionPort: '<S77>/Action Port'
       */
      /* Update for Derivative: '<S88>/Derivative' */
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

      /* End of Update for Derivative: '<S88>/Derivative' */
      /* End of Update for SubSystem: '<S67>/Steering TV with TC' */
      break;

     case 3:
     case 4:
      break;
    }

    /* End of Update for If: '<S67>/FAILURE MODE' */
    /* End of Update for SubSystem: '<S14>/Vehicle Dynamics Control Modes' */
  }

  /* End of Update for If: '<S14>/If' */

  /* ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output */
  if (rtmIsMajorTimeStep(Torque_Control_M)) {
    if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
        (&Torque_Control_M->solverInfo)) {
      rtsiSetSimTimeStep(&Torque_Control_M->solverInfo,MINOR_TIME_STEP);
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&Torque_Control_M->solverInfo, false);
      Torque_Control_output();
      rtsiSetSimTimeStep(&Torque_Control_M->solverInfo, MAJOR_TIME_STEP);
    }
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

  /* Derivatives for If: '<S14>/If' */
  ((XDot_Torque_Control_T *) Torque_Control_M->derivs)->Integrator_CSTATE = 0.0;
  if (Torque_Control_DW.If_ActiveSubsystem_k == 0) {
    /* Derivatives for IfAction SubSystem: '<S14>/Vehicle Dynamics Control Modes' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    /* Derivatives for If: '<S67>/FAILURE MODE' */
    ((XDot_Torque_Control_T *) Torque_Control_M->derivs)->Integrator_CSTATE =
      0.0;
    if (Torque_Control_DW.FAILUREMODE_ActiveSubsystem == 0) {
      /* Derivatives for IfAction SubSystem: '<S67>/VDC Complete' incorporates:
       *  ActionPort: '<S78>/Action Port'
       */
      /* Derivatives for If: '<S78>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
      ((XDot_Torque_Control_T *) Torque_Control_M->derivs)->Integrator_CSTATE =
        0.0;
      if (Torque_Control_DW.Steer_angisinSteer_SatrangeLong == 1) {
        /* Derivatives for IfAction SubSystem: '<S78>/Lateral Dynamics' incorporates:
         *  ActionPort: '<S114>/Action Port'
         */
        /* Derivatives for Integrator: '<S114>/Integrator' */
        _rtXdot->Integrator_CSTATE = Torque_Control_B.Abs;

        /* End of Derivatives for SubSystem: '<S78>/Lateral Dynamics' */
      }

      /* End of Derivatives for If: '<S78>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
      /* End of Derivatives for SubSystem: '<S67>/VDC Complete' */
    }

    /* End of Derivatives for If: '<S67>/FAILURE MODE' */
    /* End of Derivatives for SubSystem: '<S14>/Vehicle Dynamics Control Modes' */
  }

  /* End of Derivatives for If: '<S14>/If' */
}

/* Model initialize function */
void Torque_Control_initialize(void)
{
  /* Start for If: '<S43>/If2' */
  Torque_Control_DW.If2_ActiveSubsystem = -1;

  /* Start for If: '<S43>/If3' */
  Torque_Control_DW.If3_ActiveSubsystem = -1;

  /* Start for If: '<S43>/MEMO1' */
  Torque_Control_DW.MEMO1_ActiveSubsystem = -1;

  /* Start for DataStoreMemory: '<S43>/Data Store Memory1' */
  Torque_Control_DW.AA = Torque_Control_P.DataStoreMemory1_InitialValu_fl;

  /* Start for If: '<S42>/If' */
  Torque_Control_DW.If_ActiveSubsystem = -1;

  /* Start for Atomic SubSystem: '<S13>/Low Pass' */
  /* Start for DataStoreMemory: '<S54>/Data Store Memory' */
  Torque_Control_DW.Previous_IN = Torque_Control_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<S54>/Data Store Memory1' */
  Torque_Control_DW.Previous_OUT =
    Torque_Control_P.DataStoreMemory1_InitialValue;

  /* End of Start for SubSystem: '<S13>/Low Pass' */

  /* Start for Atomic SubSystem: '<S14>/TEST_MODE_IN' */
  /* Start for If: '<S66>/If' */
  Torque_Control_DW.If_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S14>/TEST_MODE_IN' */

  /* Start for Atomic SubSystem: '<S14>/Regeneration_Enable' */
  /* Start for If: '<S65>/If' */
  Torque_Control_DW.If_ActiveSubsystem_o = -1;

  /* End of Start for SubSystem: '<S14>/Regeneration_Enable' */

  /* Start for If: '<S14>/If' */
  Torque_Control_DW.If_ActiveSubsystem_k = -1;

  /* Start for IfAction SubSystem: '<S14>/Vehicle Dynamics Control Modes' */
  /* Start for If: '<S67>/If' */
  Torque_Control_DW.If_ActiveSubsystem_j = -1;

  /* Start for Constant: '<S67>/Steering Wheel Saturation (per site) [deg] ' */
  Torque_Control_B.SteeringWheelSaturationpersited =
    Torque_Control_P.SteeringWheelSaturationpersited;

  /* Start for If: '<S67>/FAILURE MODE' */
  Torque_Control_DW.FAILUREMODE_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S67>/VDC Complete' */
  /* Start for Constant: '<S153>/Steering Wheel Maximum Angle' */
  Torque_Control_B.SteeringWheelMaximumAngle_p =
    Torque_Control_P.SteeringWheelMaximumAngle_Value;

  /* Start for If: '<S153>/SKF or CKF' */
  Torque_Control_DW.SKForCKF_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S153>/SKF' */
  /* Start for If: '<S156>/If' */
  Torque_Control_DW.If_ActiveSubsystem_ha = -1;

  /* End of Start for SubSystem: '<S153>/SKF' */

  /* Start for IfAction SubSystem: '<S153>/CKF' */
  /* Start for If: '<S154>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_o = -1;

  /* End of Start for SubSystem: '<S153>/CKF' */

  /* Start for DataStoreMemory: '<S118>/Data Store Memory' */
  Torque_Control_DW.A_b = Torque_Control_P.DataStoreMemory_InitialValue_c;

  /* Start for DataStoreMemory: '<S118>/Data Store Memory1' */
  Torque_Control_DW.B_i = Torque_Control_P.DataStoreMemory1_InitialValue_i;

  /* Start for Constant: '<S78>/Constant' */
  Torque_Control_B.Constant_p = Torque_Control_P.Constant_Value_b;

  /* Start for Constant: '<S113>/Maximum Torque per engine [Nm]' */
  Torque_Control_B.MaximumTorqueperengineNm =
    Torque_Control_P.MaximumTorqueperengineNm_Value;

  /* Start for Constant: '<S120>/Constant1' */
  Torque_Control_B.Constant1_i = Torque_Control_P.Constant1_Value_ab;

  /* Start for If: '<S78>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
  Torque_Control_DW.Steer_angisinSteer_SatrangeLong = -1;

  /* Start for IfAction SubSystem: '<S78>/Longitudinal Dynamics' */
  /* Start for Constant: '<S115>/Constant' */
  Torque_Control_B.Constant_mf = Torque_Control_P.Constant_Value_f0;

  /* Start for Constant: '<S115>/Constant3' */
  Torque_Control_B.Constant3_e = Torque_Control_P.Constant3_Value_k;

  /* Start for Constant: '<S115>/Constant4' */
  Torque_Control_B.Constant4_m = Torque_Control_P.Constant4_Value;

  /* End of Start for SubSystem: '<S78>/Longitudinal Dynamics' */

  /* Start for IfAction SubSystem: '<S78>/Lateral Dynamics' */
  /* Start for Constant: '<S114>/Constant3' */
  Torque_Control_B.Constant3_b = Torque_Control_P.Constant3_Value_o;

  /* Start for Constant: '<S114>/Constant4' */
  Torque_Control_B.Constant4 = Torque_Control_P.Constant4_Value_p;

  /* Start for Constant: '<S142>/Constant8' */
  Torque_Control_B.Constant8 = Torque_Control_P.Constant8_Value;

  /* Start for Constant: '<S142>/Constant7' */
  Torque_Control_B.Constant7 = Torque_Control_P.Constant7_Value;

  /* Start for Constant: '<S142>/Wheelbase [m]' */
  Torque_Control_B.Wheelbasem = Torque_Control_P.Wheelbasem_Value;

  /* End of Start for SubSystem: '<S78>/Lateral Dynamics' */

  /* Start for Constant: '<S120>/Constant' */
  Torque_Control_B.Constant_bb = Torque_Control_P.Constant_Value_l;

  /* Start for Constant: '<S113>/Tq_diff_Max' */
  Torque_Control_B.Tq_diff_Max = Torque_Control_P.Tq_diff_Max_Value;

  /* Start for If: '<S111>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubsy_b = -1;

  /* Start for If: '<S110>/If' */
  Torque_Control_DW.If_ActiveSubsystem_aq = -1;

  /* Start for IfAction SubSystem: '<S110>/Acelerating and braking without Regenerative' */
  /* Start for If: '<S121>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_bn = -1;

  /* Start for Constant: '<S121>/Constant' */
  Torque_Control_B.Constant_c = Torque_Control_P.Constant_Value_h;

  /* End of Start for SubSystem: '<S110>/Acelerating and braking without Regenerative' */
  /* End of Start for SubSystem: '<S67>/VDC Complete' */

  /* Start for IfAction SubSystem: '<S67>/VDC without Longitudinal' */
  /* Start for If: '<S201>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_a = -1;

  /* Start for DataStoreMemory: '<S175>/Data Store Memory1' */
  Torque_Control_DW.B_k = Torque_Control_P.DataStoreMemory1_InitialValue_m;

  /* Start for Constant: '<S171>/Constant' */
  Torque_Control_B.Constant_e = Torque_Control_P.Constant_Value_ib;

  /* Start for Constant: '<S173>/Constant1' */
  Torque_Control_B.Constant1_b = Torque_Control_P.Constant1_Value_c;

  /* Start for Constant: '<S171>/Constant1' */
  Torque_Control_B.Constant1_k = Torque_Control_P.Constant1_Value_l;

  /* Start for Constant: '<S173>/Constant' */
  Torque_Control_B.Constant_dd = Torque_Control_P.Constant_Value_ae;

  /* Start for If: '<S170>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubsy_c = -1;

  /* Start for If: '<S169>/If' */
  Torque_Control_DW.If_ActiveSubsystem_h = -1;

  /* Start for IfAction SubSystem: '<S169>/Acelerating and braking without Regenerative' */
  /* Start for If: '<S177>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_b = -1;

  /* End of Start for SubSystem: '<S169>/Acelerating and braking without Regenerative' */
  /* End of Start for SubSystem: '<S67>/VDC without Longitudinal' */

  /* Start for IfAction SubSystem: '<S67>/Steering TV with TC' */
  /* Start for Constant: '<S98>/Steering Wheel Maximum Angle' */
  Torque_Control_B.SteeringWheelMaximumAngle =
    Torque_Control_P.SteeringWheelMaximumAngle_Val_o;

  /* Start for If: '<S98>/SKF or CKF' */
  Torque_Control_DW.SKForCKF_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S98>/SKF' */
  /* Start for If: '<S101>/If' */
  Torque_Control_DW.If_ActiveSubsystem_jm = -1;

  /* End of Start for SubSystem: '<S98>/SKF' */

  /* Start for IfAction SubSystem: '<S98>/CKF' */
  /* Start for If: '<S99>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_ca = -1;

  /* End of Start for SubSystem: '<S98>/CKF' */

  /* Start for DataStoreMemory: '<S88>/Data Store Memory' */
  Torque_Control_DW.A = Torque_Control_P.DataStoreMemory_InitialValue_m;

  /* Start for DataStoreMemory: '<S88>/Data Store Memory1' */
  Torque_Control_DW.B = Torque_Control_P.DataStoreMemory1_InitialValue_f;

  /* Start for Constant: '<S77>/Steering Wheel Maximum Angle' */
  Torque_Control_B.SteeringWheelMaximumAngle_m =
    Torque_Control_P.SteeringWheelMaximumAngle_Val_i;

  /* Start for Constant: '<S77>/Tq_max_motor [Nm]' */
  Torque_Control_B.Tq_max_motorNm = Torque_Control_P.Tq_max_motorNm_Value;

  /* Start for Constant: '<S77>/Tq_diff_max [Nm]' */
  Torque_Control_B.Tq_diff_maxNm = Torque_Control_P.Tq_diff_maxNm_Value;

  /* Start for If: '<S77>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem_c = -1;

  /* Start for If: '<S77>/If' */
  Torque_Control_DW.If_ActiveSubsystem_ds = -1;

  /* Start for If: '<S82>/Braking Conditions' */
  Torque_Control_DW.BrakingConditions_ActiveSubsyst = -1;

  /* End of Start for SubSystem: '<S67>/Steering TV with TC' */
  /* End of Start for SubSystem: '<S14>/Vehicle Dynamics Control Modes' */

  /* Start for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Start for If: '<S17>/If' */
  Torque_Control_DW.If_ActiveSubsystem_kl = -1;

  /* Start for IfAction SubSystem: '<S17>/OK_OrLatch' */
  /* Start for If: '<S19>/If' */
  Torque_Control_DW.If_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S17>/OK_OrLatch' */

  /* Start for DataStoreMemory: '<S17>/Data Store Memory10' */
  Torque_Control_DW.A_i = Torque_Control_P.DataStoreMemory10_InitialValue;

  /* End of Start for SubSystem: '<S1>/PowerLimitDetection' */

  /* Start for If: '<S10>/If' */
  Torque_Control_DW.If_ActiveSubsystem_d = -1;

  /* Start for Atomic SubSystem: '<S14>/WORKSHOP_MODE_RESTRICTIONS' */
  /* Start for If: '<S68>/If' */
  Torque_Control_DW.If_ActiveSubsystem_ed = -1;

  /* End of Start for SubSystem: '<S14>/WORKSHOP_MODE_RESTRICTIONS' */

  /* Start for Constant: '<Root>/Gear Ratio' */
  Torque_Control_B.GearRatio = Torque_Control_P.GearRatio_Value;

  /* Start for Constant: '<Root>/Max Tq per motor [Nm]' */
  Torque_Control_B.MaxTqpermotorNm = Torque_Control_P.MaxTqpermotorNm_Value;

  /* Start for If: '<Root>/If' */
  Torque_Control_DW.If_ActiveSubsystem_e = -1;

  /* Start for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' */
  /* Start for Constant: '<S3>/Max_Tq_per_motor' */
  Torque_Control_B.Max_Tq_per_motor = Torque_Control_P.Max_Tq_per_motor_Value;

  /* End of Start for SubSystem: '<Root>/Controls Temperature by limiting Torque' */

  /* Start for Constant: '<S9>/Max_Power_discharge [kW]' */
  Torque_Control_B.Max_Power_dischargekW =
    Torque_Control_P.Max_Power_dischargekW_Value;

  /* Start for Constant: '<S9>/Max_Power_charge [kW]' */
  Torque_Control_B.Max_Power_chargekW =
    Torque_Control_P.Max_Power_chargekW_Value;

  /* Start for If: '<Root>/If1' */
  Torque_Control_DW.If1_ActiveSubsystem = -1;

  /* SystemInitialize for IfAction SubSystem: '<S14>/Vehicle Dynamics Control Modes' */
  /* SystemInitialize for IfAction SubSystem: '<S67>/VDC Complete' */
  /* InitializeConditions for Derivative: '<S118>/Derivative' */
  Torque_Control_DW.TimeStampA_g = (rtInf);
  Torque_Control_DW.TimeStampB_c = (rtInf);

  /* SystemInitialize for IfAction SubSystem: '<S153>/SKF' */
  /* SystemInitialize for Merge: '<S156>/Merge' */
  Torque_Control_B.Merge_i = Torque_Control_P.Merge_InitialOutput;

  /* SystemInitialize for Outport: '<S156>/SKF_act' */
  Torque_Control_B.Saturation_f = Torque_Control_P.SKF_act_Y0;

  /* End of SystemInitialize for SubSystem: '<S153>/SKF' */

  /* SystemInitialize for IfAction SubSystem: '<S153>/CKF' */
  /* SystemInitialize for Merge: '<S154>/Merge' */
  Torque_Control_B.Merge_c = Torque_Control_P.Merge_InitialOutput_j;

  /* SystemInitialize for Outport: '<S154>/CKF_act ' */
  Torque_Control_B.Saturation_i = Torque_Control_P.CKF_act_Y0;

  /* End of SystemInitialize for SubSystem: '<S153>/CKF' */

  /* SystemInitialize for IfAction SubSystem: '<S78>/Lateral Dynamics' */
  /* InitializeConditions for Integrator: '<S114>/Integrator' */
  Torque_Control_X.Integrator_CSTATE = Torque_Control_P.Integrator_IC;

  /* End of SystemInitialize for SubSystem: '<S78>/Lateral Dynamics' */

  /* SystemInitialize for Merge: '<S78>/Merge2' */
  Torque_Control_B.Merge2_lx = Torque_Control_P.Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S78>/Merge3' */
  Torque_Control_B.Merge3_e = Torque_Control_P.Merge3_InitialOutput;

  /* SystemInitialize for IfAction SubSystem: '<S111>/Accelerating' */
  /* SystemInitialize for Outport: '<S131>/Out_Throttle' */
  Torque_Control_B.Throttle = Torque_Control_P.Out_Throttle_Y0;

  /* End of SystemInitialize for SubSystem: '<S111>/Accelerating' */

  /* SystemInitialize for Merge: '<S111>/Merge' */
  Torque_Control_B.Merge_kt = Torque_Control_P.Merge_InitialOutput_i;

  /* SystemInitialize for Merge: '<S111>/Merge1' */
  Torque_Control_B.Merge1_b = Torque_Control_P.Merge1_InitialOutput;

  /* SystemInitialize for IfAction SubSystem: '<S110>/Acelerating and braking without Regenerative' */
  /* SystemInitialize for SignalConversion: '<S121>/OutportBufferForFlag_Power' */
  Torque_Control_B.OutportBufferForFlag_Power = Torque_Control_B.Constant_c;

  /* End of SystemInitialize for SubSystem: '<S110>/Acelerating and braking without Regenerative' */

  /* SystemInitialize for Merge: '<S78>/Merge4' */
  Torque_Control_B.Merge4 = Torque_Control_P.Merge4_InitialOutput;

  /* SystemInitialize for Merge: '<S78>/Merge5' */
  Torque_Control_B.Merge5_e = Torque_Control_P.Merge5_InitialOutput;

  /* SystemInitialize for Merge: '<S78>/Merge6' */
  Torque_Control_B.Merge6 = Torque_Control_P.Merge6_InitialOutput;

  /* SystemInitialize for Merge: '<S78>/Merge7' */
  Torque_Control_B.Merge7 = Torque_Control_P.Merge7_InitialOutput;

  /* SystemInitialize for Outport: '<S78>/MaxTq_RR [Nm] (0,inf)' */
  Torque_Control_B.Divide = Torque_Control_P.MaxTq_RRNm0inf_Y0;

  /* SystemInitialize for Outport: '<S78>/MaxTq_RL [Nm] (0,inf)' */
  Torque_Control_B.Divide_i = Torque_Control_P.MaxTq_RLNm0inf_Y0;

  /* SystemInitialize for Outport: '<S78>/Flags_[num5]' */
  Torque_Control_B.OutportBufferForFlags_num5[0] =
    Torque_Control_P.Flags_num5_Y0;
  Torque_Control_B.OutportBufferForFlags_num5[1] =
    Torque_Control_P.Flags_num5_Y0;
  Torque_Control_B.OutportBufferForFlags_num5[2] =
    Torque_Control_P.Flags_num5_Y0;
  Torque_Control_B.OutportBufferForFlags_num5[3] =
    Torque_Control_P.Flags_num5_Y0;

  /* End of SystemInitialize for SubSystem: '<S67>/VDC Complete' */

  /* SystemInitialize for IfAction SubSystem: '<S67>/VDC without Longitudinal' */
  /* InitializeConditions for Derivative: '<S175>/Derivative' */
  Torque_Control_DW.TimeStampA_b = (rtInf);
  Torque_Control_DW.TimeStampB_e = (rtInf);

  /* SystemInitialize for Merge: '<S201>/Merge' */
  Torque_Control_B.Merge_g = Torque_Control_P.Merge_InitialOutput_h;

  /* SystemInitialize for IfAction SubSystem: '<S170>/Accelerating' */
  /* SystemInitialize for Outport: '<S186>/Out_Throttle' */
  Torque_Control_B.sf_Acceleratorbehaviour_b.throttle =
    Torque_Control_P.Out_Throttle_Y0_a;

  /* End of SystemInitialize for SubSystem: '<S170>/Accelerating' */

  /* SystemInitialize for Merge: '<S170>/Merge' */
  Torque_Control_B.Merge_li = Torque_Control_P.Merge_InitialOutput_l;

  /* SystemInitialize for Merge: '<S170>/Merge1' */
  Torque_Control_B.Merge1_l = Torque_Control_P.Merge1_InitialOutput_k;

  /* SystemInitialize for Outport: '<S79>/MaxFx_RR [N] (0,inf)' */
  Torque_Control_B.sf_MATLABFunction2_b.value =
    Torque_Control_P.MaxFx_RRN0inf_Y0;

  /* SystemInitialize for Outport: '<S79>/MaxFx_RL [N] (0,inf)' */
  Torque_Control_B.sf_MATLABFunction1_f.value =
    Torque_Control_P.MaxFx_RLN0inf_Y0;

  /* End of SystemInitialize for SubSystem: '<S67>/VDC without Longitudinal' */

  /* SystemInitialize for IfAction SubSystem: '<S67>/Steering TV with TC' */
  /* InitializeConditions for Derivative: '<S88>/Derivative' */
  Torque_Control_DW.TimeStampA = (rtInf);
  Torque_Control_DW.TimeStampB = (rtInf);

  /* SystemInitialize for IfAction SubSystem: '<S98>/SKF' */
  /* SystemInitialize for Merge: '<S101>/Merge' */
  Torque_Control_B.Merge_kj = Torque_Control_P.Merge_InitialOutput_p;

  /* SystemInitialize for Outport: '<S101>/SKF_act' */
  Torque_Control_B.Saturation_k = Torque_Control_P.SKF_act_Y0_l;

  /* End of SystemInitialize for SubSystem: '<S98>/SKF' */

  /* SystemInitialize for IfAction SubSystem: '<S98>/CKF' */
  /* SystemInitialize for Merge: '<S99>/Merge' */
  Torque_Control_B.Merge_k = Torque_Control_P.Merge_InitialOutput_a;

  /* SystemInitialize for Outport: '<S99>/CKF_act ' */
  Torque_Control_B.Saturation = Torque_Control_P.CKF_act_Y0_j;

  /* End of SystemInitialize for SubSystem: '<S98>/CKF' */

  /* SystemInitialize for Merge: '<S82>/Merge' */
  Torque_Control_B.Merge_d = Torque_Control_P.Merge_InitialOutput_e;

  /* SystemInitialize for Merge: '<S82>/Merge1' */
  Torque_Control_B.Merge1_p = Torque_Control_P.Merge1_InitialOutput_e;

  /* End of SystemInitialize for SubSystem: '<S67>/Steering TV with TC' */

  /* SystemInitialize for Merge: '<S67>/Merge Tq_RL' */
  Torque_Control_B.MergeTq_RL = Torque_Control_P.MergeTq_RL_InitialOutput;

  /* SystemInitialize for Merge: '<S67>/Merge Tq_RR' */
  Torque_Control_B.MergeTq_RR = Torque_Control_P.MergeTq_RR_InitialOutput;

  /* SystemInitialize for Merge: '<S67>/Merge2' */
  Torque_Control_B.Merge2_l = Torque_Control_P.Merge2_InitialOutput_o;

  /* SystemInitialize for Merge: '<S67>/Merge3' */
  Torque_Control_B.Merge3_c = Torque_Control_P.Merge3_InitialOutput_n;

  /* End of SystemInitialize for SubSystem: '<S14>/Vehicle Dynamics Control Modes' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/Controls Temperature by limiting Torque' */
  /* SystemInitialize for Outport: '<S3>/Accu_Temperature_Limitation_Flag' */
  Torque_Control_B.Compare = Torque_Control_P.Accu_Temperature_Limitation_Fla;

  /* SystemInitialize for Outport: '<S3>/Inverters_Temperature_Limitation_Flag' */
  Torque_Control_B.Compare_d = Torque_Control_P.Inverters_Temperature_Limitatio;

  /* SystemInitialize for Outport: '<S3>/Motors_Temperature_Limitation_Flag' */
  Torque_Control_B.Compare_g = Torque_Control_P.Motors_Temperature_Limitation_F;

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
  rtsiSetSolverName(&Torque_Control_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Torque_Control_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
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
  Torque_Control_M->solverInfoPtr = (&Torque_Control_M->solverInfo);
  Torque_Control_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Torque_Control_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Torque_Control_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Torque_Control_M->blockIO = ((void *) &Torque_Control_B);
  (void) memset(((void *) &Torque_Control_B), 0,
                sizeof(B_Torque_Control_T));

  /* parameters */
  Torque_Control_M->defaultParam = ((real_T *)&Torque_Control_P);

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
  (void)memset((void *)&Torque_Control_U, 0, sizeof(ExtU_Torque_Control_T));

  /* external outputs */
  Torque_Control_M->outputs = (&Torque_Control_Y);
  (void) memset((void *)&Torque_Control_Y, 0,
                sizeof(ExtY_Torque_Control_T));

  /* Initialize Sizes */
  Torque_Control_M->Sizes.numContStates = (1);/* Number of continuous states */
  Torque_Control_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Torque_Control_M->Sizes.numY = (33); /* Number of model outputs */
  Torque_Control_M->Sizes.numU = (42); /* Number of model inputs */
  Torque_Control_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Torque_Control_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Torque_Control_M->Sizes.numBlocks = (721);/* Number of blocks */
  Torque_Control_M->Sizes.numBlockIO = (181);/* Number of block outputs */
  Torque_Control_M->Sizes.numBlockPrms = (366);/* Sum of parameter "widths" */
  return Torque_Control_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
