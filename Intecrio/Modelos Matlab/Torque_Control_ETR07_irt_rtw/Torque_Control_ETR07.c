/*
 * Torque_Control_ETR07.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control_ETR07".
 *
 * Model version              : 1.21
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Jun 18 14:41:15 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_Control_ETR07.h"
#include "Torque_Control_ETR07_private.h"
#include "mldivide_u4svSR16.h"
#include "polyfit_vYlRX3XP.h"

/* Block signals (auto storage) */
B_Torque_Control_ETR07_T Torque_Control_ETR07_B;

/* Continuous states */
X_Torque_Control_ETR07_T Torque_Control_ETR07_X;

/* Block states (auto storage) */
DW_Torque_Control_ETR07_T Torque_Control_ETR07_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Torque_Control_ETR07_T Torque_Control_ETR07_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Torque_Control_ETR07_T Torque_Control_ETR07_Y;

/* Real-time model */
RT_MODEL_Torque_Control_ETR07_T Torque_Control_ETR07_M_;
RT_MODEL_Torque_Control_ETR07_T *const Torque_Control_ETR07_M =
  &Torque_Control_ETR07_M_;

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
  Torque_Control_ETR07_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Torque_Control_ETR07_output();
  Torque_Control_ETR07_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Torque_Control_ETR07_output();
  Torque_Control_ETR07_derivatives();

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
 *    '<S9>/LimitReached'
 *    '<S11>/Latched Error'
 *    '<S11>/OK'
 */
void Torque_Control_ETR_LimitReached(real_T *rty_Out,
  P_LimitReached_Torque_Control_T *localP)
{
  /* SignalConversion: '<S10>/OutportBufferForOut ' incorporates:
   *  Constant: '<S10>/Constant'
   */
  *rty_Out = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S14>/Is_Zero'
 *    '<S14>/Bypass_Torque'
 *    '<S15>/Is_Zero'
 *    '<S15>/Bypass_Torque'
 *    '<S52>/BypassDecision '
 *    '<S52>/NotEnabled'
 */
void Torque_Control_ETR07_Is_Zero(real_T rtu_In1, real_T *rty_Out1)
{
  if (1) {
    /* Inport: '<S18>/In1' */
    *rty_Out1 = rtu_In1;
  }
}

/*
 * Output and update for action system:
 *    '<S14>/Bypass'
 *    '<S15>/Bypass'
 *    '<S55>/BYPASS'
 */
void Torque_Control_ETR07_Bypass(real_T rtu_In1, real_T rtu_In2, real_T
  *rty_Out1, real_T *rty_Out2)
{
  if (1) {
    /* Inport: '<S16>/In1' */
    *rty_Out1 = rtu_In1;

    /* Inport: '<S16>/In2' */
    *rty_Out2 = rtu_In2;
  }
}

/*
 * Output and update for action system:
 *    '<S14>/Negative'
 *    '<S15>/Negative'
 */
void Torque_Control_ETR07_Negative(real_T rtu_In1, real_T rtu_In2, real_T
  *rty_Out1, real_T *rty_Out2, P_Negative_Torque_Control_ETR_T *localP)
{
  if (1) {
    /* Gain: '<S19>/Gain' */
    *rty_Out1 = localP->Gain_Gain * rtu_In1;

    /* Gain: '<S19>/Gain1' */
    *rty_Out2 = localP->Gain1_Gain * rtu_In2;
  }
}

/*
 * Output and update for action system:
 *    '<S29>/Imp'
 *    '<S29>/Not Imp'
 *    '<S30>/Imp1'
 *    '<S30>/Not Imp1'
 *    '<S30>/Imp Memo1'
 *    '<S30>/Not Imp Memo1'
 */
void Torque_Control_ETR07_Imp(boolean_T *rty_Out1, P_Imp_Torque_Control_ETR07_T *
  localP)
{
  if (1) {
    /* SignalConversion: '<S33>/OutportBufferForOut1' incorporates:
     *  Constant: '<S33>/Constant'
     */
    *rty_Out1 = localP->Constant_Value;
  }
}

/*
 * Output and update for action system:
 *    '<S30>/If Action Subsystem2'
 *    '<S30>/If Action Subsystem3'
 */
void Torque_Contr_IfActionSubsystem2(real_T *rty_Out1,
  P_IfActionSubsystem2_Torque_C_T *localP)
{
  if (1) {
    /* SignalConversion: '<S35>/OutportBufferForOut1' incorporates:
     *  Constant: '<S35>/Constant'
     */
    *rty_Out1 = localP->Constant_Value;
  }
}

/*
 * Output and update for action system:
 *    '<S107>/Control de Temperatura'
 *    '<S107>/Control de Potencia '
 */
void Torque_Con_ControldeTemperatura(RT_MODEL_Torque_Control_ETR07_T * const
  Torque_Control_ETR07_M, real_T rtu_Tq_RR, real_T rtu_Tq_RL, real_T
  rtu_ReductionCte, real_T *rty_Tq_RR_out, real_T *rty_Tq_RL_out, real_T
  *rty_Flag_Temperature, real_T *rty_Flag_Power, P_ControldeTemperatura_Torque_T
  *localP)
{
  /* Sum: '<S110>/Add' incorporates:
   *  Product: '<S110>/Product'
   */
  *rty_Tq_RR_out = rtu_Tq_RR - rtu_Tq_RR * rtu_ReductionCte;

  /* Sum: '<S110>/Add1' incorporates:
   *  Product: '<S110>/Product1'
   */
  *rty_Tq_RL_out = rtu_Tq_RL - rtu_Tq_RL * rtu_ReductionCte;
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* SignalConversion: '<S110>/OutportBufferForFlag_Temperature' incorporates:
     *  Constant: '<S110>/Constant'
     */
    *rty_Flag_Temperature = localP->Constant_Value;

    /* SignalConversion: '<S110>/OutportBufferForFlag_Power' incorporates:
     *  Constant: '<S110>/Constant1'
     */
    *rty_Flag_Power = localP->Constant1_Value;
  }
}

/*
 * Output and update for action system:
 *    '<S107>/If Action 1'
 *    '<S165>/If Action 1'
 */
void Torque_Control_ETR07_IfAction1(real_T rtu_Trans_max_dynamic, real_T
  *rty_Trans_limit)
{
  if (1) {
    /* Inport: '<S111>/Trans_max_dynamic' */
    *rty_Trans_limit = rtu_Trans_max_dynamic;
  }
}

/*
 * Output and update for action system:
 *    '<S107>/If Action 2'
 *    '<S165>/If Action 2'
 */
void Torque_Control_ETR07_IfAction2(real_T rtu_Trans_max_static, real_T
  *rty_Trans_limit)
{
  if (1) {
    /* Inport: '<S112>/Trans_max_static ' */
    *rty_Trans_limit = rtu_Trans_max_static;
  }
}

/*
 * Output and update for atomic system:
 *    '<S107>/minimum value'
 *    '<S165>/minimum value'
 */
void Torque_Control_ETR_minimumvalue(real_T rtu_a, real_T rtu_b, real_T rtu_c,
  B_minimumvalue_Torque_Control_T *localB)
{
  localB->min = rtu_a;
  if (rtu_b < rtu_a) {
    localB->min = rtu_b;
  }

  if (rtu_c < localB->min) {
    localB->min = rtu_c;
  }
}

/*
 * Output and update for atomic system:
 *    '<S107>/minimum value1'
 *    '<S165>/minimum value1'
 */
void Torque_Control_ET_minimumvalue1(real_T rtu_a, real_T rtu_b, real_T rtu_c,
  B_minimumvalue1_Torque_Contro_T *localB)
{
  localB->min = rtu_a;
  if (rtu_b < rtu_a) {
    localB->min = rtu_b;
  }

  if (rtu_c < localB->min) {
    localB->min = rtu_c;
  }
}

/*
 * Output and update for atomic system:
 *    '<S97>/Accelerator behaviour '
 *    '<S177>/Accelerator behaviour '
 *    '<S72>/Accelerator behaviour '
 *    '<S70>/Accelerator behaviour '
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
 *    '<S97>/Regenerative+Mech Braking'
 *    '<S158>/Regenerative+Mech Braking'
 */
void Torque__RegenerativeMechBraking(real_T rtu_RegTq_RR, real_T rtu_RegTq_RL,
  real_T *rty_Tq_RR, real_T *rty_Tq_RL)
{
  /* Inport: '<S124>/RegTq_RR' */
  *rty_Tq_RR = rtu_RegTq_RR;

  /* Inport: '<S124>/RegTq_RL' */
  *rty_Tq_RL = rtu_RegTq_RL;
}

/*
 * Output and update for action system:
 *    '<S97>/Mech_Braking'
 *    '<S97>/Inertia Braking'
 *    '<S158>/Mech_Braking'
 *    '<S158>/Inertia Braking'
 */
void Torque_Control_ETR_Mech_Braking(real_T *rty_Tq_RR, real_T *rty_Tq_RL,
  P_Mech_Braking_Torque_Control_T *localP)
{
  if (1) {
    /* SignalConversion: '<S123>/OutportBufferForTq_RR  ' incorporates:
     *  Constant: '<S123>/Constant'
     */
    *rty_Tq_RR = localP->Constant_Value;

    /* SignalConversion: '<S123>/OutportBufferForTq_RL' incorporates:
     *  Constant: '<S123>/Constant1'
     */
    *rty_Tq_RL = localP->Constant1_Value;
  }
}

/*
 * Output and update for atomic system:
 *    '<S68>/MATLAB Function1'
 *    '<S68>/MATLAB Function2'
 */
void Torque_Control__MATLABFunction1(real_T rtu_cte, real_T rtu_v,
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
 *    '<S104>/MATLAB Function'
 *    '<S162>/MATLAB Function'
 *    '<S77>/MATLAB Function'
 */
void Torque_Control_E_MATLABFunction(real_T rtu_RPM_INV1, real_T rtu_RPM_INV2,
  B_MATLABFunction_Torque_Contr_T *localB)
{
  localB->RPM = fmax(rtu_RPM_INV1, rtu_RPM_INV2);
}

/*
 * Output and update for atomic system:
 *    '<S150>/MATLAB Function'
 *    '<S93>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_m(real_T rtu_SKF_Initial, real_T rtu_SKF_prev,
  B_MATLABFunction_Torque_Con_d_T *localB)
{
  localB->SKF_act1 = fmin(rtu_SKF_prev, rtu_SKF_Initial);
}

/*
 * Output and update for atomic system:
 *    '<S149>/MATLAB Function'
 *    '<S92>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_d(real_T rtu_SKF_prev, real_T rtu_SKF_Initial,
  B_MATLABFunction_Torque_Co_ds_T *localB)
{
  localB->SKF_act0 = fmin(rtu_SKF_prev, rtu_SKF_Initial);
}

/*
 * Output and update for atomic system:
 *    '<S146>/MATLAB Function'
 *    '<S189>/MATLAB Function'
 *    '<S89>/MATLAB Function'
 */
void Torque_Contro_MATLABFunction_mt(real_T rtu_CKF_Initial, real_T rtu_CKF_prev,
  B_MATLABFunction_Torque_Con_k_T *localB)
{
  localB->CKF_act1 = fmin(rtu_CKF_prev, rtu_CKF_Initial);
}

/*
 * Output and update for action system:
 *    '<S142>/Spin '
 *    '<S187>/Spin '
 */
void Torque_Control_ETR07_Spin(RT_MODEL_Torque_Control_ETR07_T * const
  Torque_Control_ETR07_M, real_T rtu_CKF_prev, real_T rtu_CKF_Initial, real_T
  rtu_Cte_CKF, real_T *rty_CKF_act1, B_Spin_Torque_Control_ETR07_T *localB,
  P_Spin_Torque_Control_ETR07_T *localP)
{
  /* local block i/o variables */
  real_T rtb_Product_lj;
  real_T rtu_Cte_CKF_0;
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Constant: '<S146>/Constant' */
    localB->Constant = localP->Constant_Value;
  }

  /* Switch: '<S146>/Switch' */
  if (rtu_Cte_CKF > localP->Switch_Threshold) {
    rtu_Cte_CKF_0 = rtu_Cte_CKF;
  } else {
    rtu_Cte_CKF_0 = localB->Constant;
  }

  /* End of Switch: '<S146>/Switch' */

  /* Product: '<S146>/Product' */
  rtb_Product_lj = rtu_CKF_prev * rtu_Cte_CKF_0;

  /* MATLAB Function: '<S146>/MATLAB Function' */
  Torque_Contro_MATLABFunction_mt(rtu_CKF_Initial, rtb_Product_lj,
    &localB->sf_MATLABFunction);

  /* SignalConversion: '<S146>/OutportBufferForCKF_act1 ' */
  *rty_CKF_act1 = localB->sf_MATLABFunction.CKF_act1;
}

/*
 * Output and update for atomic system:
 *    '<S145>/MATLAB Function'
 *    '<S188>/MATLAB Function'
 *    '<S88>/MATLAB Function'
 */
void Torque_Control_MATLABFunction_b(real_T rtu_CKF_prev, real_T rtu_CKF_Initial,
  B_MATLABFunction_Torque_Con_n_T *localB)
{
  localB->CKF_act0 = fmin(rtu_CKF_prev, rtu_CKF_Initial);
}

/*
 * Output and update for action system:
 *    '<S142>/No spin'
 *    '<S187>/No spin'
 */
void Torque_Control_ETR07_Nospin(real_T rtu_CKF_Initial, real_T rtu_CKF_prev,
  real_T *rty_CKF_act0, B_Nospin_Torque_Control_ETR07_T *localB,
  P_Nospin_Torque_Control_ETR07_T *localP)
{
  /* local block i/o variables */
  real_T rtb_Switch_o;

  /* Switch: '<S145>/Switch' */
  if (rtu_CKF_prev > localP->Switch_Threshold) {
    rtb_Switch_o = rtu_CKF_prev;
  } else {
    rtb_Switch_o = rtu_CKF_Initial;
  }

  /* End of Switch: '<S145>/Switch' */

  /* MATLAB Function: '<S145>/MATLAB Function' */
  Torque_Control_MATLABFunction_b(rtb_Switch_o, rtu_CKF_Initial,
    &localB->sf_MATLABFunction);

  /* SignalConversion: '<S145>/OutportBufferForCKF_act0' */
  *rty_CKF_act0 = localB->sf_MATLABFunction.CKF_act0;
}

/*
 * Output and update for atomic system:
 *    '<S101>/MATLAB Function'
 *    '<S101>/MATLAB Function1'
 *    '<S100>/MATLAB Function1'
 *    '<S100>/MATLAB Function2'
 *    '<S160>/MATLAB Function1'
 *    '<S160>/MATLAB Function2'
 *    '<S164>/MATLAB Function1'
 *    '<S164>/MATLAB Function2'
 */
void Torque_Contro_MATLABFunction_d1(real_T rtu_cte, real_T rtu_v,
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
 *    '<S106>/MATLAB Function1'
 *    '<S106>/MATLAB Function2'
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
 *    '<S165>/Control de Temperatura1'
 *    '<S165>/Control de Potencia 1'
 *    '<S73>/Control de Temperatura'
 *    '<S73>/Control de Potencia '
 */
void Torque_Co_ControldeTemperatura1(real_T rtu_Tq_RR, real_T rtu_Tq_RL, real_T
  rtu_ReductionCte, real_T *rty_Tq_RR_out, real_T *rty_Tq_RL_out)
{
  /* Sum: '<S168>/Add' incorporates:
   *  Product: '<S168>/Product'
   */
  *rty_Tq_RR_out = rtu_Tq_RR - rtu_Tq_RR * rtu_ReductionCte;

  /* Sum: '<S168>/Add1' incorporates:
   *  Product: '<S168>/Product1'
   */
  *rty_Tq_RL_out = rtu_Tq_RL - rtu_Tq_RL * rtu_ReductionCte;
}

/*
 * Output and update for action system:
 *    '<S165>/else1'
 *    '<S73>/else'
 */
void Torque_Control_ETR07_else1(real_T rtu_Tq_RR, real_T rtu_Tq_RL, real_T
  *rty_Tq_RR_out, real_T *rty_Tq_RL_out)
{
  /* Inport: '<S172>/Tq_RR' */
  *rty_Tq_RR_out = rtu_Tq_RR;

  /* Inport: '<S172>/Tq_RL' */
  *rty_Tq_RL_out = rtu_Tq_RL;
}

/*
 * Output and update for action system:
 *    '<S58>/Temp_LIMIT'
 *    '<S58>/Temp_OK'
 */
void Torque_Control_ETR07_Temp_LIMIT(real_T *rty_Out1,
  P_Temp_LIMIT_Torque_Control_E_T *localP)
{
  if (1) {
    /* SignalConversion: '<S61>/OutportBufferForOut1' incorporates:
     *  Constant: '<S61>/TEMP_LIMIT'
     */
    *rty_Out1 = localP->TEMP_LIMIT_Value;
  }
}

/* Model output function */
void Torque_Control_ETR07_output(void)
{
  /* local block i/o variables */
  real_T rtb_Product_g;
  real_T rtb_Product1;
  real_T rtb_Switch;
  real_T rtb_Product_d;
  real_T rtb_Switch_b;
  real_T rtb_Product_i;
  real_T rtb_CKF_prev_b;
  real_T rtb_Product_c;
  real_T rtb_Divide_a;
  real_T rtb_Product1_l;
  real_T rtb_Divide_l;
  real_T rtb_Merge3;
  real_T rtb_Merge4;
  real_T rtb_CKF_prev_p;
  real_T rtb_Product1_h;
  real_T rtb_Product2;
  real_T rtb_Product_a;
  real_T rtb_Product1_f;
  real_T rtb_Switch_l;
  real_T rtb_Product_o;
  real_T rtb_Merge;
  real_T rtb_Merge1;
  real_T rtb_Add_a;
  real_T rtb_Add_j;
  real_T rtb_Merge_i;
  real_T rtb_Merge1_a;
  real_T rtb_Merge1_p;
  boolean_T rtb_Merge3_d;
  boolean_T rtb_Merge4_n;
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
  real_T rtb_Merge_d;
  real_T rtb_Subtract1;
  real_T rtb_alpha_j;
  real_T rtb_value_g;
  real_T rtb_min;
  real_T tmp[12];
  real_T kamm_data[4];
  real_T kamm_data_0[2];
  real_T kamm_data_1[2];
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* set solver stop time */
    if (!(Torque_Control_ETR07_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Torque_Control_ETR07_M->solverInfo,
                            ((Torque_Control_ETR07_M->Timing.clockTickH0 + 1) *
        Torque_Control_ETR07_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Torque_Control_ETR07_M->solverInfo,
                            ((Torque_Control_ETR07_M->Timing.clockTick0 + 1) *
        Torque_Control_ETR07_M->Timing.stepSize0 +
        Torque_Control_ETR07_M->Timing.clockTickH0 *
        Torque_Control_ETR07_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Torque_Control_ETR07_M)) {
    Torque_Control_ETR07_M->Timing.t[0] = rtsiGetT
      (&Torque_Control_ETR07_M->solverInfo);
  }

  /* If: '<S30>/If2' incorporates:
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Inport: '<Root>/BrakeSensor_Value'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!(((Torque_Control_ETR07_U.APPS1_Value > 0.25) &&
                          (Torque_Control_ETR07_U.BrakeSensor_Value > 0.25)) ||
                         ((Torque_Control_ETR07_U.APPS2_Value > 0.25) &&
                          (Torque_Control_ETR07_U.BrakeSensor_Value > 0.25)));
    Torque_Control_ETR07_DW.If2_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If2_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S30>/Imp1' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    Torque_Control_ETR07_Imp(&rtb_Merge3_d, &Torque_Control_ETR07_P.Imp1);

    /* End of Outputs for SubSystem: '<S30>/Imp1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S30>/Not Imp1' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    Torque_Control_ETR07_Imp(&rtb_Merge3_d, &Torque_Control_ETR07_P.NotImp1);

    /* End of Outputs for SubSystem: '<S30>/Not Imp1' */
    break;
  }

  /* End of If: '<S30>/If2' */

  /* If: '<S30>/If3' incorporates:
   *  DataStoreRead: '<S30>/Data Store Read1'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!Torque_Control_ETR07_DW.AA;
    Torque_Control_ETR07_DW.If3_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If3_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    Torque_Contr_IfActionSubsystem2(&Torque_Control_ETR07_B.Merge5,
      &Torque_Control_ETR07_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem2' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    Torque_Contr_IfActionSubsystem2(&Torque_Control_ETR07_B.Merge5,
      &Torque_Control_ETR07_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem3' */
    break;
  }

  /* End of If: '<S30>/If3' */

  /* If: '<S30>/MEMO1' incorporates:
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!(((Torque_Control_ETR07_B.Merge5 == 0.0) &&
                          (Torque_Control_ETR07_U.APPS1_Value > 0.05)) ||
                         ((Torque_Control_ETR07_B.Merge5 == 0.0) &&
                          (Torque_Control_ETR07_U.APPS2_Value > 0.05)));
    Torque_Control_ETR07_DW.MEMO1_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.MEMO1_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S30>/Imp Memo1' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    Torque_Control_ETR07_Imp(&rtb_Merge4_n, &Torque_Control_ETR07_P.ImpMemo1);

    /* End of Outputs for SubSystem: '<S30>/Imp Memo1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S30>/Not Imp Memo1' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    Torque_Control_ETR07_Imp(&rtb_Merge4_n, &Torque_Control_ETR07_P.NotImpMemo1);

    /* End of Outputs for SubSystem: '<S30>/Not Imp Memo1' */
    break;
  }

  /* End of If: '<S30>/MEMO1' */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Logic: '<S30>/Logical Operator1' */
    Torque_Control_ETR07_B.LogicalOperator1 = (rtb_Merge3_d && rtb_Merge4_n);

    /* DataStoreWrite: '<S30>/Data Store Write1' */
    Torque_Control_ETR07_DW.AA = Torque_Control_ETR07_B.LogicalOperator1;
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      rtsiSetBlockStateForSolverChangedAtMajorStep
        (&Torque_Control_ETR07_M->solverInfo, true);
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&Torque_Control_ETR07_M->solverInfo, true);
    }

    /* End of DataStoreWrite: '<S30>/Data Store Write1' */
  }

  /* If: '<S29>/If' incorporates:
   *  Abs: '<S29>/Ab'
   *  Inport: '<Root>/APPS1_Value'
   *  Inport: '<Root>/APPS2_Value'
   *  Sum: '<S29>/Sum'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!(fabs(Torque_Control_ETR07_U.APPS1_Value -
      Torque_Control_ETR07_U.APPS2_Value) > 0.25);
    Torque_Control_ETR07_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S29>/Imp' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    Torque_Control_ETR07_Imp(&Torque_Control_ETR07_B.Merge_j,
      &Torque_Control_ETR07_P.Imp);

    /* End of Outputs for SubSystem: '<S29>/Imp' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S29>/Not Imp' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    Torque_Control_ETR07_Imp(&Torque_Control_ETR07_B.Merge_j,
      &Torque_Control_ETR07_P.NotImp);

    /* End of Outputs for SubSystem: '<S29>/Not Imp' */
    break;
  }

  /* End of If: '<S29>/If' */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Constant: '<S31>/Constant' */
    Torque_Control_ETR07_B.Constant =
      Torque_Control_ETR07_P.CompareToConstant_const;
  }

  /* Logic: '<S5>/Logical Operator' incorporates:
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/CriticalDisconnection'
   *  Inport: '<Root>/ShutdownClosed'
   *  Inport: '<Root>/TorqueEnable'
   *  Logic: '<S5>/NOT'
   *  RelationalOperator: '<S31>/Compare'
   */
  Torque_Control_ETR07_B.LogicalOperator =
    (Torque_Control_ETR07_U.ShutdownClosed &&
     Torque_Control_ETR07_U.TorqueEnable &&
     (!Torque_Control_ETR07_U.CriticalDisconnection) &&
     (Torque_Control_ETR07_U.Car_State == Torque_Control_ETR07_B.Constant) &&
     Torque_Control_ETR07_B.Merge_j && Torque_Control_ETR07_B.LogicalOperator1);
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Logic: '<S5>/Logical Operator1' */
    rtb_LogicalOperator1 = !Torque_Control_ETR07_B.Merge_j;

    /* Logic: '<S5>/Logical Operator2' */
    rtb_LogicalOperator2 = !Torque_Control_ETR07_B.LogicalOperator1;

    /* Gain: '<S6>/Gain' incorporates:
     *  Constant: '<S6>/half range'
     *  Constant: '<S6>/range'
     *  Constant: '<S6>/zero'
     *  Inport: '<Root>/SteeringSensor_Bits'
     *  Product: '<S6>/Divide'
     *  Sum: '<S6>/Sum'
     */
    rtb_Gain = (Torque_Control_ETR07_U.SteeringSensor_Bits -
                Torque_Control_ETR07_P.zero_Value) *
      Torque_Control_ETR07_P.halfrange_Value /
      Torque_Control_ETR07_P.range_Value * Torque_Control_ETR07_P.Gain_Gain_o;
  }

  /* Outputs for Atomic SubSystem: '<S6>/Low Pass' */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Constant: '<S41>/exp(-tcycle//tau)1' */
    Torque_Control_ETR07_B.exptcycletau1 =
      Torque_Control_ETR07_P.exptcycletau1_Value;

    /* Sum: '<S41>/Subtract' incorporates:
     *  Constant: '<S41>/ct'
     */
    Torque_Control_ETR07_B.Subtract = Torque_Control_ETR07_B.exptcycletau1 -
      Torque_Control_ETR07_P.ct_Value;
  }

  /* Sum: '<S41>/Subtract1' incorporates:
   *  DataStoreRead: '<S41>/Data Store Read'
   *  DataStoreRead: '<S41>/Data Store Read1'
   *  Product: '<S41>/Product'
   *  Product: '<S41>/Product1'
   */
  rtb_Subtract1 = Torque_Control_ETR07_DW.Previous_IN *
    Torque_Control_ETR07_B.Subtract + Torque_Control_ETR07_B.exptcycletau1 *
    Torque_Control_ETR07_DW.Previous_OUT;

  /* DataStoreWrite: '<S41>/Data Store Write1' */
  Torque_Control_ETR07_DW.Previous_OUT = rtb_Subtract1;
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* DataStoreWrite: '<S41>/Data Store Write' */
    Torque_Control_ETR07_DW.Previous_IN = rtb_Gain;
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      rtsiSetBlockStateForSolverChangedAtMajorStep
        (&Torque_Control_ETR07_M->solverInfo, true);
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&Torque_Control_ETR07_M->solverInfo, true);
    }

    /* End of DataStoreWrite: '<S41>/Data Store Write' */
  }

  /* Gain: '<S41>/Gain' */
  rtb_Gain = Torque_Control_ETR07_P.Gain_Gain_c * rtb_Subtract1;

  /* End of Outputs for SubSystem: '<S6>/Low Pass' */

  /* Abs: '<S7>/Abs1' incorporates:
   *  Inport: '<Root>/ACCEL_F_Y_SI'
   */
  rtb_Abs1 = fabs(Torque_Control_ETR07_U.ACCEL_F_Y_SI);

  /* Abs: '<S7>/Abs4' incorporates:
   *  Inport: '<Root>/ACCEL_R_Y_SI'
   */
  rtb_Subtract1 = fabs(Torque_Control_ETR07_U.ACCEL_R_Y_SI);

  /* Outputs for Atomic SubSystem: '<S7>/TEST_MODE_IN' */
  /* If: '<S53>/If' incorporates:
   *  Inport: '<Root>/Susp_F_L'
   *  Inport: '<Root>/Susp_F_R'
   *  Inport: '<Root>/Susp_R_L'
   *  Inport: '<Root>/Susp_R_R'
   *  Inport: '<Root>/Workshop_Mode_Enable'
   *  Inport: '<S64>/In1'
   *  Inport: '<S64>/In2'
   *  Inport: '<S64>/In3'
   *  Inport: '<S64>/In4'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!(Torque_Control_ETR07_U.Workshop_Mode_Enable == 1.0);
    Torque_Control_ETR07_DW.If_ActiveSubsystem_a = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_a;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S53>/TEST_CONSTANTS' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      /* SignalConversion: '<S65>/OutportBufferForOut1' incorporates:
       *  Constant: '<S65>/Constant'
       */
      Torque_Control_ETR07_B.Merge = Torque_Control_ETR07_P.Constant_Value_k;

      /* SignalConversion: '<S65>/OutportBufferForOut2' incorporates:
       *  Constant: '<S65>/Constant1'
       */
      Torque_Control_ETR07_B.Merge1 = Torque_Control_ETR07_P.Constant1_Value_ln;

      /* SignalConversion: '<S65>/OutportBufferForOut3' incorporates:
       *  Constant: '<S65>/Constant2'
       */
      Torque_Control_ETR07_B.Merge2 = Torque_Control_ETR07_P.Constant2_Value_g1;

      /* SignalConversion: '<S65>/OutportBufferForOut4' incorporates:
       *  Constant: '<S65>/Constant3'
       */
      Torque_Control_ETR07_B.Merge3 = Torque_Control_ETR07_P.Constant3_Value_n;
    }

    /* End of Outputs for SubSystem: '<S53>/TEST_CONSTANTS' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S53>/BYPASS' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    Torque_Control_ETR07_B.Merge = Torque_Control_ETR07_U.Susp_F_R;
    Torque_Control_ETR07_B.Merge1 = Torque_Control_ETR07_U.Susp_F_L;
    Torque_Control_ETR07_B.Merge2 = Torque_Control_ETR07_U.Susp_R_L;
    Torque_Control_ETR07_B.Merge3 = Torque_Control_ETR07_U.Susp_R_R;

    /* End of Outputs for SubSystem: '<S53>/BYPASS' */
    break;
  }

  /* End of If: '<S53>/If' */
  /* End of Outputs for SubSystem: '<S7>/TEST_MODE_IN' */

  /* Outputs for Atomic SubSystem: '<S7>/Regeneration_Enable' */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Constant: '<S52>/BRAKE_THRESHOLD' */
    Torque_Control_ETR07_B.BRAKE_THRESHOLD =
      Torque_Control_ETR07_P.BRAKE_THRESHOLD_Value;
  }

  /* If: '<S52>/If1' incorporates:
   *  DataStoreRead: '<S52>/Data Store Read'
   *  Inport: '<Root>/BrakeSensor_Value'
   *  Inport: '<S56>/Latched'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!(Torque_Control_ETR07_U.BrakeSensor_Value >
                         Torque_Control_ETR07_B.BRAKE_THRESHOLD);
    Torque_Control_ETR07_DW.If1_ActiveSubsystem_b = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_b;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S52>/Braking' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    Torque_Control_ETR07_B.Merge_d = Torque_Control_ETR07_DW.R;

    /* End of Outputs for SubSystem: '<S52>/Braking' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S52>/Not-Braking' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      /* SignalConversion: '<S58>/OutportBufferForEnable' incorporates:
       *  Constant: '<S58>/Not_Braking'
       */
      Torque_Control_ETR07_B.Merge_d = Torque_Control_ETR07_P.Not_Braking_Value;
    }

    /* If: '<S58>/If1' incorporates:
     *  DataStoreRead: '<S52>/Data Store Read'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      rtAction = (int8_T)!(Torque_Control_ETR07_DW.R == 1.0);
      Torque_Control_ETR07_DW.If1_ActiveSubsystem_i = rtAction;
    } else {
      rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_i;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S58>/Upper_Threshold' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        /* SignalConversion: '<S63>/OutportBufferForOut1' incorporates:
         *  Constant: '<S63>/TEMP_LIMIT_UPPER'
         */
        Torque_Control_ETR07_B.Merge1_k =
          Torque_Control_ETR07_P.TEMP_LIMIT_UPPER_Value;
      }

      /* End of Outputs for SubSystem: '<S58>/Upper_Threshold' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S58>/Low_Threshold' incorporates:
       *  ActionPort: '<S60>/Action Port'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        /* SignalConversion: '<S60>/OutportBufferForOut1' incorporates:
         *  Constant: '<S60>/TEMP_LIMIT_LOWER'
         */
        Torque_Control_ETR07_B.Merge1_k =
          Torque_Control_ETR07_P.TEMP_LIMIT_LOWER_Value;
      }

      /* End of Outputs for SubSystem: '<S58>/Low_Threshold' */
      break;
    }

    /* End of If: '<S58>/If1' */

    /* If: '<S58>/If' incorporates:
     *  Inport: '<Root>/Highest_CellTemp'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      rtAction = (int8_T)!(Torque_Control_ETR07_U.Highest_CellTemp >
                           Torque_Control_ETR07_B.Merge1_k);
      Torque_Control_ETR07_DW.If_ActiveSubsystem_i = rtAction;
    } else {
      rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_i;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S58>/Temp_LIMIT' incorporates:
       *  ActionPort: '<S61>/Action Port'
       */
      Torque_Control_ETR07_Temp_LIMIT(&Torque_Control_ETR07_B.Merge_h,
        &Torque_Control_ETR07_P.Temp_LIMIT);

      /* End of Outputs for SubSystem: '<S58>/Temp_LIMIT' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S58>/Temp_OK' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      Torque_Control_ETR07_Temp_LIMIT(&Torque_Control_ETR07_B.Merge_h,
        &Torque_Control_ETR07_P.Temp_OK);

      /* End of Outputs for SubSystem: '<S58>/Temp_OK' */
      break;
    }

    /* End of If: '<S58>/If' */
    /* End of Outputs for SubSystem: '<S52>/Not-Braking' */
    break;
  }

  /* End of If: '<S52>/If1' */

  /* DataStoreWrite: '<S52>/Data Store Write' */
  Torque_Control_ETR07_DW.R = Torque_Control_ETR07_B.Merge_h;
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Constant: '<S52>/Zero ' */
    Torque_Control_ETR07_B.Zero = Torque_Control_ETR07_P.Zero_Value_c;
  }

  /* If: '<S52>/If' incorporates:
   *  Inport: '<Root>/Vel_RL_kmh'
   *  Inport: '<Root>/Vel_RR_kmh'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!((Torque_Control_ETR07_U.Vel_RR_kmh > 0.0) &&
                         (Torque_Control_ETR07_U.Vel_RL_kmh > 0.0));
    Torque_Control_ETR07_DW.If_ActiveSubsystem_o = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_o;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S52>/BypassDecision ' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    Torque_Control_ETR07_Is_Zero(Torque_Control_ETR07_B.Merge_d,
      &Torque_Control_ETR07_B.Merge1_a);

    /* End of Outputs for SubSystem: '<S52>/BypassDecision ' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S52>/NotEnabled' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    Torque_Control_ETR07_Is_Zero(Torque_Control_ETR07_B.Zero,
      &Torque_Control_ETR07_B.Merge1_a);

    /* End of Outputs for SubSystem: '<S52>/NotEnabled' */
    break;
  }

  /* End of If: '<S52>/If' */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Constant: '<S52>/Constant' */
    Torque_Control_ETR07_B.Constant_o = Torque_Control_ETR07_P.Constant_Value_m;
  }

  /* End of Outputs for SubSystem: '<S7>/Regeneration_Enable' */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Constant: '<Root>/Constant' */
    Torque_Control_ETR07_B.Constant_h = Torque_Control_ETR07_P.Constant_Value_h;

    /* Constant: '<S7>/Constant' */
    Torque_Control_ETR07_B.Constant_l = Torque_Control_ETR07_P.Constant_Value_f3;
  }

  /* If: '<S7>/If' incorporates:
   *  Constant: '<S54>/Limit Temperature Celdas[ºC]'
   *  Constant: '<S54>/Limit Temperature IGBT [ºC]'
   *  Constant: '<S54>/Limit Temperature Motor [ºC]'
   *  Constant: '<S54>/Steering Wheel Saturation (per site) [deg] '
   */
  rtAction = -1;
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    if (Torque_Control_ETR07_B.LogicalOperator) {
      rtAction = 0;
    }

    Torque_Control_ETR07_DW.If_ActiveSubsystem_k = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_k;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S7>/Vehicle Dynamics Control 2018' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      Torque_Control_ETR07_B.LimitTemperatureIGBTC =
        Torque_Control_ETR07_P.LimitTemperatureIGBTC_Value;
      Torque_Control_ETR07_B.LimitTemperatureMotorC =
        Torque_Control_ETR07_P.LimitTemperatureMotorC_Value;
      Torque_Control_ETR07_B.LimitTemperatureCeldasC =
        Torque_Control_ETR07_P.LimitTemperatureCeldasC_Value;
      Torque_Control_ETR07_B.SteeringWheelSaturationpersited =
        Torque_Control_ETR07_P.SteeringWheelSaturationpersited;
    }

    /* Gain: '<S54>/Gain' incorporates:
     *  Constant: '<S54>/Limit Temperature Celdas[ºC]'
     *  Constant: '<S54>/Limit Temperature IGBT [ºC]'
     *  Constant: '<S54>/Limit Temperature Motor [ºC]'
     *  Constant: '<S54>/Steering Wheel Saturation (per site) [deg] '
     */
    Torque_Control_ETR07_B.Gain = Torque_Control_ETR07_P.Gain_Gain_f * rtb_Gain;

    /* If: '<S54>/FAILURE MODE' incorporates:
     *  Constant: '<S106>/Constant'
     *  Constant: '<S106>/Constant1'
     *  Constant: '<S141>/Steering Wheel Maximum Angle'
     *  Constant: '<S159>/Maximum Torque per engine [Nm]'
     *  Constant: '<S159>/Maximum Transmission Torque Dynamic [Nm]'
     *  Constant: '<S159>/Maximum Transmission Torque Static [Nm]'
     *  Constant: '<S159>/Transmision Ratio[-]'
     *  Constant: '<S160>/Constant'
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S164>/Constant'
     *  Constant: '<S164>/Constant1'
     *  Constant: '<S66>/Torque_RL [Nm]'
     *  Constant: '<S66>/Torque_RR [Nm]'
     *  Constant: '<S67>/Steering Wheel Maximum Angle'
     *  Constant: '<S67>/Tq_diff_max [Nm]'
     *  Constant: '<S67>/Tq_max [Nm]'
     *  Constant: '<S68>/Constant'
     *  Constant: '<S84>/Steering Wheel Maximum Angle'
     *  Constant: '<S99>/Constant1'
     *  Constant: '<S99>/Maximum Torque per engine [Nm]'
     *  Constant: '<S99>/Maximum Transmission Torque Dynamic [Nm]'
     *  Constant: '<S99>/Maximum Transmission Torque Static [Nm]'
     *  Constant: '<S99>/Tq_diff_Max'
     *  Constant: '<S99>/Transmision Ratio[-]'
     *  Inport: '<Root>/TV_Mode'
     */
    rtAction = -1;
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      if (Torque_Control_ETR07_U.TV_Mode == 0.0) {
        rtAction = 0;
      } else if (Torque_Control_ETR07_U.TV_Mode == 1.0) {
        rtAction = 1;
      } else if (Torque_Control_ETR07_U.TV_Mode == 2.0) {
        rtAction = 2;
      } else {
        if (Torque_Control_ETR07_U.TV_Mode == 3.0) {
          rtAction = 3;
        }
      }

      Torque_Control_ETR07_DW.FAILUREMODE_ActiveSubsystem = rtAction;
    } else {
      rtAction = Torque_Control_ETR07_DW.FAILUREMODE_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S54>/VDC 2018 Complete' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        Torque_Control_ETR07_B.SteeringWheelMaximumAngle_p =
          Torque_Control_ETR07_P.SteeringWheelMaximumAngle_Value;
      }

      /* MATLAB Function: '<S141>/MATLAB Function1' incorporates:
       *  Constant: '<S141>/Steering Wheel Maximum Angle'
       */
      if (Torque_Control_ETR07_B.Gain >
          Torque_Control_ETR07_B.SteeringWheelMaximumAngle_p) {
        rtb_value_g = Torque_Control_ETR07_B.SteeringWheelMaximumAngle_p;
      } else if (Torque_Control_ETR07_B.Gain <
                 -Torque_Control_ETR07_B.SteeringWheelMaximumAngle_p) {
        rtb_value_g = -Torque_Control_ETR07_B.SteeringWheelMaximumAngle_p;
      } else {
        rtb_value_g = Torque_Control_ETR07_B.Gain;
      }

      /* End of MATLAB Function: '<S141>/MATLAB Function1' */

      /* MATLAB Function: '<S104>/MATLAB Function' incorporates:
       *  Inport: '<Root>/RL_rads'
       *  Inport: '<Root>/RR_rads'
       */
      Torque_Control_E_MATLABFunction(Torque_Control_ETR07_U.RL_rads,
        Torque_Control_ETR07_U.RR_rads,
        &Torque_Control_ETR07_B.sf_MATLABFunction);

      /* Derivative: '<S104>/Derivative' */
      if ((Torque_Control_ETR07_DW.TimeStampA_g >=
           Torque_Control_ETR07_M->Timing.t[0]) &&
          (Torque_Control_ETR07_DW.TimeStampB_c >=
           Torque_Control_ETR07_M->Timing.t[0])) {
        rtb_alpha_j = 0.0;
      } else {
        Mz = Torque_Control_ETR07_DW.TimeStampA_g;
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA_c;
        if (Torque_Control_ETR07_DW.TimeStampA_g <
            Torque_Control_ETR07_DW.TimeStampB_c) {
          if (Torque_Control_ETR07_DW.TimeStampB_c <
              Torque_Control_ETR07_M->Timing.t[0]) {
            Mz = Torque_Control_ETR07_DW.TimeStampB_c;
            lastU = &Torque_Control_ETR07_DW.LastUAtTimeB_f;
          }
        } else {
          if (Torque_Control_ETR07_DW.TimeStampA_g >=
              Torque_Control_ETR07_M->Timing.t[0]) {
            Mz = Torque_Control_ETR07_DW.TimeStampB_c;
            lastU = &Torque_Control_ETR07_DW.LastUAtTimeB_f;
          }
        }

        rtb_alpha_j = (Torque_Control_ETR07_B.sf_MATLABFunction.RPM - *lastU) /
          (Torque_Control_ETR07_M->Timing.t[0] - Mz);
      }

      /* End of Derivative: '<S104>/Derivative' */

      /* DataStoreRead: '<S104>/CKF_prev' */
      rtb_CKF_prev_p = Torque_Control_ETR07_DW.B_i;

      /* If: '<S141>/SKF or CKF' */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        rtAction = (int8_T)!((-10.0 < rtb_value_g) && (rtb_value_g < 10.0));
        Torque_Control_ETR07_DW.SKForCKF_ActiveSubsystem_o = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.SKForCKF_ActiveSubsystem_o;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S141>/SKF' incorporates:
         *  ActionPort: '<S144>/Action Port'
         */
        /* If: '<S144>/If' incorporates:
         *  Constant: '<S150>/Constant'
         */
        rtAction = -1;
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          if (rtb_alpha_j >= 900.0) {
            rtAction = 0;
          } else {
            if (rtb_alpha_j < 900.0) {
              rtAction = 1;
            }
          }

          Torque_Control_ETR07_DW.If_ActiveSubsystem_ha = rtAction;
        } else {
          rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_ha;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S144>/Spin' incorporates:
           *  ActionPort: '<S150>/Action Port'
           */
          if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
            Torque_Control_ETR07_B.Constant_k =
              Torque_Control_ETR07_P.Constant_Value_a;
          }

          /* Switch: '<S150>/Switch' incorporates:
           *  Constant: '<S150>/Constant'
           *  Inport: '<Root>/VDC_Cte_CKF'
           */
          if (Torque_Control_ETR07_U.VDC_Cte_CKF >
              Torque_Control_ETR07_P.Switch_Threshold) {
            Mz = Torque_Control_ETR07_U.VDC_Cte_CKF;
          } else {
            Mz = Torque_Control_ETR07_B.Constant_k;
          }

          /* End of Switch: '<S150>/Switch' */

          /* Product: '<S150>/Product' incorporates:
           *  DataStoreRead: '<S104>/SKF_prev '
           */
          rtb_Product_o = Torque_Control_ETR07_DW.A_b * Mz;

          /* MATLAB Function: '<S150>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          Torque_Control_MATLABFunction_m(Torque_Control_ETR07_U.VDC_SKF_Initial,
            rtb_Product_o, &Torque_Control_ETR07_B.sf_MATLABFunction_m);

          /* SignalConversion: '<S150>/OutportBufferForSKF_act1' */
          Torque_Control_ETR07_B.Merge_i =
            Torque_Control_ETR07_B.sf_MATLABFunction_m.SKF_act1;

          /* End of Outputs for SubSystem: '<S144>/Spin' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S144>/No spin' incorporates:
           *  ActionPort: '<S149>/Action Port'
           */
          /* Switch: '<S149>/Switch' incorporates:
           *  DataStoreRead: '<S104>/SKF_prev '
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          if (Torque_Control_ETR07_DW.A_b >
              Torque_Control_ETR07_P.Switch_Threshold_g) {
            rtb_Switch_l = Torque_Control_ETR07_DW.A_b;
          } else {
            rtb_Switch_l = Torque_Control_ETR07_U.VDC_SKF_Initial;
          }

          /* End of Switch: '<S149>/Switch' */

          /* MATLAB Function: '<S149>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          Torque_Control_MATLABFunction_d(rtb_Switch_l,
            Torque_Control_ETR07_U.VDC_SKF_Initial,
            &Torque_Control_ETR07_B.sf_MATLABFunction_d);

          /* SignalConversion: '<S149>/OutportBufferForSKF_act0' */
          Torque_Control_ETR07_B.Merge_i =
            Torque_Control_ETR07_B.sf_MATLABFunction_d.SKF_act0;

          /* End of Outputs for SubSystem: '<S144>/No spin' */
          break;
        }

        /* End of If: '<S144>/If' */

        /* Saturate: '<S144>/Saturation' */
        if (Torque_Control_ETR07_B.Merge_i >
            Torque_Control_ETR07_P.Saturation_UpperSat) {
          Torque_Control_ETR07_B.Saturation_f =
            Torque_Control_ETR07_P.Saturation_UpperSat;
        } else if (Torque_Control_ETR07_B.Merge_i <
                   Torque_Control_ETR07_P.Saturation_LowerSat) {
          Torque_Control_ETR07_B.Saturation_f =
            Torque_Control_ETR07_P.Saturation_LowerSat;
        } else {
          Torque_Control_ETR07_B.Saturation_f = Torque_Control_ETR07_B.Merge_i;
        }

        /* End of Saturate: '<S144>/Saturation' */
        /* End of Outputs for SubSystem: '<S141>/SKF' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S141>/CKF' incorporates:
         *  ActionPort: '<S142>/Action Port'
         */
        /* If: '<S142>/If1' incorporates:
         *  Inport: '<Root>/VDC_CKF_Initial'
         *  Inport: '<Root>/VDC_Cte_SKF'
         */
        rtAction = -1;
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          if (rtb_alpha_j >= 900.0) {
            rtAction = 0;
          } else {
            if (rtb_alpha_j < 900.0) {
              rtAction = 1;
            }
          }

          Torque_Control_ETR07_DW.If1_ActiveSubsystem_o = rtAction;
        } else {
          rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_o;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S142>/Spin ' incorporates:
           *  ActionPort: '<S146>/Action Port'
           */
          Torque_Control_ETR07_Spin(Torque_Control_ETR07_M, rtb_CKF_prev_p,
            Torque_Control_ETR07_U.VDC_CKF_Initial,
            Torque_Control_ETR07_U.VDC_Cte_SKF, &Torque_Control_ETR07_B.Merge_cu,
            &Torque_Control_ETR07_B.Spin_n, &Torque_Control_ETR07_P.Spin_n);

          /* End of Outputs for SubSystem: '<S142>/Spin ' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S142>/No spin' incorporates:
           *  ActionPort: '<S145>/Action Port'
           */
          Torque_Control_ETR07_Nospin(Torque_Control_ETR07_U.VDC_CKF_Initial,
            rtb_CKF_prev_p, &Torque_Control_ETR07_B.Merge_cu,
            &Torque_Control_ETR07_B.Nospin_k, &Torque_Control_ETR07_P.Nospin_k);

          /* End of Outputs for SubSystem: '<S142>/No spin' */
          break;
        }

        /* End of If: '<S142>/If1' */

        /* Saturate: '<S142>/Saturation' */
        if (Torque_Control_ETR07_B.Merge_cu >
            Torque_Control_ETR07_P.Saturation_UpperSat_f) {
          Torque_Control_ETR07_B.Saturation_i =
            Torque_Control_ETR07_P.Saturation_UpperSat_f;
        } else if (Torque_Control_ETR07_B.Merge_cu <
                   Torque_Control_ETR07_P.Saturation_LowerSat_f) {
          Torque_Control_ETR07_B.Saturation_i =
            Torque_Control_ETR07_P.Saturation_LowerSat_f;
        } else {
          Torque_Control_ETR07_B.Saturation_i = Torque_Control_ETR07_B.Merge_cu;
        }

        /* End of Saturate: '<S142>/Saturation' */
        /* End of Outputs for SubSystem: '<S141>/CKF' */
        break;
      }

      /* End of If: '<S141>/SKF or CKF' */

      /* DataStoreWrite: '<S104>/Data Store Write' */
      Torque_Control_ETR07_DW.A_b = Torque_Control_ETR07_B.Saturation_f;

      /* DataStoreWrite: '<S104>/Data Store Write1' */
      Torque_Control_ETR07_DW.B_i = Torque_Control_ETR07_B.Saturation_i;
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        Torque_Control_ETR07_B.Constant_p =
          Torque_Control_ETR07_P.Constant_Value_b;
        Torque_Control_ETR07_B.MaximumTorqueperengineNm_m =
          Torque_Control_ETR07_P.MaximumTorqueperengineNm_Value;
        Torque_Control_ETR07_B.MaximumTransmissionTorqueDyna_b =
          Torque_Control_ETR07_P.MaximumTransmissionTorqueDynami;
        Torque_Control_ETR07_B.MaximumTransmissionTorqueStat_b =
          Torque_Control_ETR07_P.MaximumTransmissionTorqueStatic;
        Torque_Control_ETR07_B.Constant1_i =
          Torque_Control_ETR07_P.Constant1_Value_ab;
        Torque_Control_ETR07_B.Constant1_j =
          Torque_Control_ETR07_P.Constant1_Value_b;
      }

      /* If: '<S68>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' incorporates:
       *  Constant: '<S100>/Constant3'
       *  Constant: '<S100>/Constant4'
       *  Constant: '<S100>/Yaw_Inertia [kg//m^3]'
       *  Constant: '<S101>/Constant'
       *  Constant: '<S101>/Constant3'
       *  Constant: '<S101>/Constant4'
       *  Constant: '<S106>/Constant1'
       *  Constant: '<S130>/Constant7'
       *  Constant: '<S130>/Constant8'
       *  Constant: '<S130>/Steering_Ratio [-]'
       *  Constant: '<S130>/Wheelbase [m]'
       *  Constant: '<S68>/Constant'
       *  Constant: '<S99>/Constant1'
       *  Constant: '<S99>/Maximum Torque per engine [Nm]'
       *  Constant: '<S99>/Maximum Transmission Torque Dynamic [Nm]'
       *  Constant: '<S99>/Maximum Transmission Torque Static [Nm]'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        rtAction = (int8_T)!((Torque_Control_ETR07_B.Gain >=
                              -Torque_Control_ETR07_B.SteeringWheelSaturationpersited)
                             && (Torque_Control_ETR07_B.Gain <=
          Torque_Control_ETR07_B.SteeringWheelSaturationpersited));
        Torque_Control_ETR07_DW.Steer_angisinSteer_SatrangeLong = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.Steer_angisinSteer_SatrangeLong;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S68>/Longitudinal Dynamics' incorporates:
         *  ActionPort: '<S101>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          /* SignalConversion: '<S101>/OutportBufferForFx_FR' incorporates:
           *  Constant: '<S101>/Constant1'
           */
          Torque_Control_ETR07_B.Merge_m =
            Torque_Control_ETR07_P.Constant1_Value_f;

          /* SignalConversion: '<S101>/OutportBufferForFx_FL' incorporates:
           *  Constant: '<S101>/Constant2'
           */
          Torque_Control_ETR07_B.Merge1_n =
            Torque_Control_ETR07_P.Constant2_Value;
          Torque_Control_ETR07_B.Constant_mf =
            Torque_Control_ETR07_P.Constant_Value_f;
          Torque_Control_ETR07_B.Constant3_e =
            Torque_Control_ETR07_P.Constant3_Value;
          Torque_Control_ETR07_B.Constant4_m =
            Torque_Control_ETR07_P.Constant4_Value;
        }

        /* Gain: '<S101>/Gain' incorporates:
         *  Constant: '<S101>/Constant'
         *  Constant: '<S101>/Constant3'
         *  Constant: '<S101>/Constant4'
         *  Sum: '<S101>/Add'
         */
        Torque_Control_ETR07_B.Merge4 = (((Torque_Control_ETR07_B.Merge +
          Torque_Control_ETR07_B.Merge1) + Torque_Control_ETR07_B.Merge2) +
          Torque_Control_ETR07_B.Merge3) * Torque_Control_ETR07_P.Gain_Gain_k;

        /* MATLAB Function: '<S101>/minimum value' */
        rtb_min = Torque_Control_ETR07_B.Merge2;
        if (Torque_Control_ETR07_B.Merge3 < Torque_Control_ETR07_B.Merge2) {
          rtb_min = Torque_Control_ETR07_B.Merge3;
        }

        /* End of MATLAB Function: '<S101>/minimum value' */

        /* MATLAB Function: '<S135>/Kamm_Circle LatD' */
        Torque_Control_ETR07_B.kamm_data[0] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[17] = 0.0;
        Torque_Control_ETR07_B.kamm_data[34] = 100.0;
        Torque_Control_ETR07_B.kamm_data[51] = 200.0;
        Torque_Control_ETR07_B.kamm_data[68] = 300.0;
        Torque_Control_ETR07_B.kamm_data[85] = 400.0;
        Torque_Control_ETR07_B.kamm_data[102] = 500.0;
        Torque_Control_ETR07_B.kamm_data[119] = 600.0;
        Torque_Control_ETR07_B.kamm_data[136] = 700.0;
        Torque_Control_ETR07_B.kamm_data[153] = 800.0;
        Torque_Control_ETR07_B.kamm_data[170] = 900.0;
        Torque_Control_ETR07_B.kamm_data[187] = 1000.0;
        Torque_Control_ETR07_B.kamm_data[204] = 1100.0;
        Torque_Control_ETR07_B.kamm_data[221] = 1200.0;
        Torque_Control_ETR07_B.kamm_data[238] = 1300.0;
        Torque_Control_ETR07_B.kamm_data[255] = 1400.0;
        Torque_Control_ETR07_B.kamm_data[272] = 1500.0;
        Torque_Control_ETR07_B.kamm_data[289] = 1600.0;
        Torque_Control_ETR07_B.kamm_data[306] = 1700.0;
        Torque_Control_ETR07_B.kamm_data[323] = 1800.0;
        Torque_Control_ETR07_B.kamm_data[340] = 1900.0;
        Torque_Control_ETR07_B.kamm_data[357] = 2000.0;
        Torque_Control_ETR07_B.kamm_data[374] = 2100.0;
        Torque_Control_ETR07_B.kamm_data[391] = 2200.0;
        Torque_Control_ETR07_B.kamm_data[408] = 2300.0;
        Torque_Control_ETR07_B.kamm_data[425] = 2400.0;
        Torque_Control_ETR07_B.kamm_data[442] = 2500.0;
        Torque_Control_ETR07_B.kamm_data[459] = 2600.0;
        Torque_Control_ETR07_B.kamm_data[476] = 2700.0;
        Torque_Control_ETR07_B.kamm_data[493] = 2800.0;
        Torque_Control_ETR07_B.kamm_data[510] = 2900.0;
        Torque_Control_ETR07_B.kamm_data[527] = 3000.0;
        Torque_Control_ETR07_B.kamm_data[1] = 0.0;
        Torque_Control_ETR07_B.kamm_data[18] = 0.0;
        Torque_Control_ETR07_B.kamm_data[35] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[52] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[69] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[86] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[103] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[120] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[137] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[154] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[171] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[188] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[205] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[222] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[239] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[256] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[273] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[290] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[307] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[324] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[341] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[358] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[375] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[392] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[409] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[426] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[443] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[460] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[477] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[494] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[511] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[528] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[2] = 100.0;
        Torque_Control_ETR07_B.kamm_data[19] = 350.0;
        Torque_Control_ETR07_B.kamm_data[36] = 340.0;
        Torque_Control_ETR07_B.kamm_data[53] = 156.0;
        Torque_Control_ETR07_B.kamm_data[70] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[87] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[104] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[121] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[138] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[155] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[172] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[189] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[206] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[223] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[240] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[257] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[274] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[291] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[308] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[325] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[342] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[359] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[376] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[393] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[410] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[427] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[444] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[461] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[478] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[495] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[512] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[529] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[3] = 200.0;
        Torque_Control_ETR07_B.kamm_data[20] = 688.0;
        Torque_Control_ETR07_B.kamm_data[37] = 676.0;
        Torque_Control_ETR07_B.kamm_data[54] = 654.0;
        Torque_Control_ETR07_B.kamm_data[71] = 573.0;
        Torque_Control_ETR07_B.kamm_data[88] = 269.0;
        Torque_Control_ETR07_B.kamm_data[105] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[122] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[139] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[156] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[173] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[190] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[207] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[224] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[241] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[258] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[275] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[292] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[309] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[326] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[343] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[360] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[377] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[394] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[411] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[428] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[445] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[462] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[479] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[496] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[513] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[530] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[4] = 300.0;
        Torque_Control_ETR07_B.kamm_data[21] = 1002.0;
        Torque_Control_ETR07_B.kamm_data[38] = 994.0;
        Torque_Control_ETR07_B.kamm_data[55] = 982.0;
        Torque_Control_ETR07_B.kamm_data[72] = 959.0;
        Torque_Control_ETR07_B.kamm_data[89] = 888.0;
        Torque_Control_ETR07_B.kamm_data[106] = 694.0;
        Torque_Control_ETR07_B.kamm_data[123] = 345.0;
        Torque_Control_ETR07_B.kamm_data[140] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[157] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[174] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[191] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[208] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[225] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[242] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[259] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[276] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[293] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[310] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[327] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[344] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[361] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[378] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[395] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[412] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[429] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[446] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[463] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[480] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[497] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[514] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[531] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[5] = 400.0;
        Torque_Control_ETR07_B.kamm_data[22] = 1295.0;
        Torque_Control_ETR07_B.kamm_data[39] = 1288.0;
        Torque_Control_ETR07_B.kamm_data[56] = 1280.0;
        Torque_Control_ETR07_B.kamm_data[73] = 1263.0;
        Torque_Control_ETR07_B.kamm_data[90] = 1235.0;
        Torque_Control_ETR07_B.kamm_data[107] = 1168.0;
        Torque_Control_ETR07_B.kamm_data[124] = 1001.0;
        Torque_Control_ETR07_B.kamm_data[141] = 740.0;
        Torque_Control_ETR07_B.kamm_data[158] = 389.0;
        Torque_Control_ETR07_B.kamm_data[175] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[192] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[209] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[226] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[243] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[260] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[277] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[294] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[311] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[328] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[345] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[362] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[379] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[396] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[413] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[430] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[447] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[464] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[481] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[498] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[515] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[532] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[6] = 500.0;
        Torque_Control_ETR07_B.kamm_data[23] = 1536.0;
        Torque_Control_ETR07_B.kamm_data[40] = 1529.0;
        Torque_Control_ETR07_B.kamm_data[57] = 1521.0;
        Torque_Control_ETR07_B.kamm_data[74] = 1509.0;
        Torque_Control_ETR07_B.kamm_data[91] = 1491.0;
        Torque_Control_ETR07_B.kamm_data[108] = 1459.0;
        Torque_Control_ETR07_B.kamm_data[125] = 1395.0;
        Torque_Control_ETR07_B.kamm_data[142] = 1230.0;
        Torque_Control_ETR07_B.kamm_data[159] = 1032.0;
        Torque_Control_ETR07_B.kamm_data[176] = 760.0;
        Torque_Control_ETR07_B.kamm_data[193] = 411.0;
        Torque_Control_ETR07_B.kamm_data[210] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[227] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[244] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[261] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[278] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[295] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[312] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[329] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[346] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[363] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[380] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[397] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[414] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[431] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[448] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[465] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[482] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[499] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[516] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[533] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[7] = 600.0;
        Torque_Control_ETR07_B.kamm_data[24] = 1745.0;
        Torque_Control_ETR07_B.kamm_data[41] = 1737.0;
        Torque_Control_ETR07_B.kamm_data[58] = 1729.0;
        Torque_Control_ETR07_B.kamm_data[75] = 1721.0;
        Torque_Control_ETR07_B.kamm_data[92] = 1704.0;
        Torque_Control_ETR07_B.kamm_data[109] = 1686.0;
        Torque_Control_ETR07_B.kamm_data[126] = 1649.0;
        Torque_Control_ETR07_B.kamm_data[143] = 1585.0;
        Torque_Control_ETR07_B.kamm_data[160] = 1455.0;
        Torque_Control_ETR07_B.kamm_data[177] = 1270.0;
        Torque_Control_ETR07_B.kamm_data[194] = 1038.0;
        Torque_Control_ETR07_B.kamm_data[211] = 756.0;
        Torque_Control_ETR07_B.kamm_data[228] = 419.0;
        Torque_Control_ETR07_B.kamm_data[245] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[262] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[279] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[296] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[313] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[330] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[347] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[364] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[381] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[398] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[415] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[432] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[449] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[466] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[483] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[500] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[517] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[534] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[8] = 700.0;
        Torque_Control_ETR07_B.kamm_data[25] = 1964.0;
        Torque_Control_ETR07_B.kamm_data[42] = 1956.0;
        Torque_Control_ETR07_B.kamm_data[59] = 1948.0;
        Torque_Control_ETR07_B.kamm_data[76] = 1940.0;
        Torque_Control_ETR07_B.kamm_data[93] = 1926.0;
        Torque_Control_ETR07_B.kamm_data[110] = 1909.0;
        Torque_Control_ETR07_B.kamm_data[127] = 1884.0;
        Torque_Control_ETR07_B.kamm_data[144] = 1848.0;
        Torque_Control_ETR07_B.kamm_data[161] = 1777.0;
        Torque_Control_ETR07_B.kamm_data[178] = 1656.0;
        Torque_Control_ETR07_B.kamm_data[195] = 1484.0;
        Torque_Control_ETR07_B.kamm_data[212] = 1278.0;
        Torque_Control_ETR07_B.kamm_data[229] = 1029.0;
        Torque_Control_ETR07_B.kamm_data[246] = 742.0;
        Torque_Control_ETR07_B.kamm_data[263] = 416.0;
        Torque_Control_ETR07_B.kamm_data[280] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[297] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[314] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[331] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[348] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[365] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[382] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[399] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[416] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[433] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[450] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[467] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[484] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[501] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[518] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[535] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[9] = 800.0;
        Torque_Control_ETR07_B.kamm_data[26] = 2212.0;
        Torque_Control_ETR07_B.kamm_data[43] = 2204.0;
        Torque_Control_ETR07_B.kamm_data[60] = 2195.0;
        Torque_Control_ETR07_B.kamm_data[77] = 2187.0;
        Torque_Control_ETR07_B.kamm_data[94] = 2175.0;
        Torque_Control_ETR07_B.kamm_data[111] = 2158.0;
        Torque_Control_ETR07_B.kamm_data[128] = 2141.0;
        Torque_Control_ETR07_B.kamm_data[145] = 2107.0;
        Torque_Control_ETR07_B.kamm_data[162] = 2063.0;
        Torque_Control_ETR07_B.kamm_data[179] = 1990.0;
        Torque_Control_ETR07_B.kamm_data[196] = 1868.0;
        Torque_Control_ETR07_B.kamm_data[213] = 1704.0;
        Torque_Control_ETR07_B.kamm_data[230] = 1505.0;
        Torque_Control_ETR07_B.kamm_data[247] = 1275.0;
        Torque_Control_ETR07_B.kamm_data[264] = 1018.0;
        Torque_Control_ETR07_B.kamm_data[281] = 730.0;
        Torque_Control_ETR07_B.kamm_data[298] = 404.0;
        Torque_Control_ETR07_B.kamm_data[315] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[332] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[349] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[366] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[383] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[400] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[417] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[434] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[451] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[468] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[485] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[502] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[519] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[536] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[10] = 900.0;
        Torque_Control_ETR07_B.kamm_data[27] = 2465.0;
        Torque_Control_ETR07_B.kamm_data[44] = 2456.0;
        Torque_Control_ETR07_B.kamm_data[61] = 2448.0;
        Torque_Control_ETR07_B.kamm_data[78] = 2439.0;
        Torque_Control_ETR07_B.kamm_data[95] = 2428.0;
        Torque_Control_ETR07_B.kamm_data[112] = 2411.0;
        Torque_Control_ETR07_B.kamm_data[129] = 2394.0;
        Torque_Control_ETR07_B.kamm_data[146] = 2367.0;
        Torque_Control_ETR07_B.kamm_data[163] = 2333.0;
        Torque_Control_ETR07_B.kamm_data[180] = 2279.0;
        Torque_Control_ETR07_B.kamm_data[197] = 2200.0;
        Torque_Control_ETR07_B.kamm_data[214] = 2081.0;
        Torque_Control_ETR07_B.kamm_data[231] = 1921.0;
        Torque_Control_ETR07_B.kamm_data[248] = 1729.0;
        Torque_Control_ETR07_B.kamm_data[265] = 1512.0;
        Torque_Control_ETR07_B.kamm_data[282] = 1268.0;
        Torque_Control_ETR07_B.kamm_data[299] = 1002.0;
        Torque_Control_ETR07_B.kamm_data[316] = 711.0;
        Torque_Control_ETR07_B.kamm_data[333] = 345.0;
        Torque_Control_ETR07_B.kamm_data[350] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[367] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[384] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[401] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[418] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[435] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[452] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[469] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[486] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[503] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[520] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[537] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[11] = 1000.0;
        Torque_Control_ETR07_B.kamm_data[28] = 2684.0;
        Torque_Control_ETR07_B.kamm_data[45] = 2675.0;
        Torque_Control_ETR07_B.kamm_data[62] = 2666.0;
        Torque_Control_ETR07_B.kamm_data[79] = 2657.0;
        Torque_Control_ETR07_B.kamm_data[96] = 2647.0;
        Torque_Control_ETR07_B.kamm_data[113] = 2629.0;
        Torque_Control_ETR07_B.kamm_data[130] = 2612.0;
        Torque_Control_ETR07_B.kamm_data[147] = 2592.0;
        Torque_Control_ETR07_B.kamm_data[164] = 2558.0;
        Torque_Control_ETR07_B.kamm_data[181] = 2520.0;
        Torque_Control_ETR07_B.kamm_data[198] = 2462.0;
        Torque_Control_ETR07_B.kamm_data[215] = 2378.0;
        Torque_Control_ETR07_B.kamm_data[232] = 2262.0;
        Torque_Control_ETR07_B.kamm_data[249] = 2119.0;
        Torque_Control_ETR07_B.kamm_data[266] = 1940.0;
        Torque_Control_ETR07_B.kamm_data[283] = 1737.0;
        Torque_Control_ETR07_B.kamm_data[300] = 1508.0;
        Torque_Control_ETR07_B.kamm_data[317] = 1259.0;
        Torque_Control_ETR07_B.kamm_data[334] = 989.0;
        Torque_Control_ETR07_B.kamm_data[351] = 680.0;
        Torque_Control_ETR07_B.kamm_data[368] = 240.0;
        Torque_Control_ETR07_B.kamm_data[385] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[402] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[419] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[436] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[453] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[470] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[487] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[504] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[521] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[538] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[12] = 1100.0;
        Torque_Control_ETR07_B.kamm_data[29] = 2853.0;
        Torque_Control_ETR07_B.kamm_data[46] = 2843.0;
        Torque_Control_ETR07_B.kamm_data[63] = 2833.0;
        Torque_Control_ETR07_B.kamm_data[80] = 2822.0;
        Torque_Control_ETR07_B.kamm_data[97] = 2811.0;
        Torque_Control_ETR07_B.kamm_data[114] = 2795.0;
        Torque_Control_ETR07_B.kamm_data[131] = 2775.0;
        Torque_Control_ETR07_B.kamm_data[148] = 2755.0;
        Torque_Control_ETR07_B.kamm_data[165] = 2728.0;
        Torque_Control_ETR07_B.kamm_data[182] = 2693.0;
        Torque_Control_ETR07_B.kamm_data[199] = 2651.0;
        Torque_Control_ETR07_B.kamm_data[216] = 2591.0;
        Torque_Control_ETR07_B.kamm_data[233] = 2510.0;
        Torque_Control_ETR07_B.kamm_data[250] = 2412.0;
        Torque_Control_ETR07_B.kamm_data[267] = 2282.0;
        Torque_Control_ETR07_B.kamm_data[284] = 2124.0;
        Torque_Control_ETR07_B.kamm_data[301] = 1940.0;
        Torque_Control_ETR07_B.kamm_data[318] = 1735.0;
        Torque_Control_ETR07_B.kamm_data[335] = 1504.0;
        Torque_Control_ETR07_B.kamm_data[352] = 1250.0;
        Torque_Control_ETR07_B.kamm_data[369] = 962.0;
        Torque_Control_ETR07_B.kamm_data[386] = 608.0;
        Torque_Control_ETR07_B.kamm_data[403] = 108.0;
        Torque_Control_ETR07_B.kamm_data[420] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[437] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[454] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[471] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[488] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[505] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[522] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[539] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[13] = 1200.0;
        Torque_Control_ETR07_B.kamm_data[30] = 2999.0;
        Torque_Control_ETR07_B.kamm_data[47] = 2988.0;
        Torque_Control_ETR07_B.kamm_data[64] = 2976.0;
        Torque_Control_ETR07_B.kamm_data[81] = 2964.0;
        Torque_Control_ETR07_B.kamm_data[98] = 2952.0;
        Torque_Control_ETR07_B.kamm_data[115] = 2936.0;
        Torque_Control_ETR07_B.kamm_data[132] = 2914.0;
        Torque_Control_ETR07_B.kamm_data[149] = 2893.0;
        Torque_Control_ETR07_B.kamm_data[166] = 2872.0;
        Torque_Control_ETR07_B.kamm_data[183] = 2837.0;
        Torque_Control_ETR07_B.kamm_data[200] = 2799.0;
        Torque_Control_ETR07_B.kamm_data[217] = 2755.0;
        Torque_Control_ETR07_B.kamm_data[234] = 2694.0;
        Torque_Control_ETR07_B.kamm_data[251] = 2619.0;
        Torque_Control_ETR07_B.kamm_data[268] = 2527.0;
        Torque_Control_ETR07_B.kamm_data[285] = 2412.0;
        Torque_Control_ETR07_B.kamm_data[302] = 2275.0;
        Torque_Control_ETR07_B.kamm_data[319] = 2114.0;
        Torque_Control_ETR07_B.kamm_data[336] = 1936.0;
        Torque_Control_ETR07_B.kamm_data[353] = 1729.0;
        Torque_Control_ETR07_B.kamm_data[370] = 1507.0;
        Torque_Control_ETR07_B.kamm_data[387] = 1233.0;
        Torque_Control_ETR07_B.kamm_data[404] = 896.0;
        Torque_Control_ETR07_B.kamm_data[421] = 461.0;
        Torque_Control_ETR07_B.kamm_data[438] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[455] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[472] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[489] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[506] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[523] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[540] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[14] = 1300.0;
        Torque_Control_ETR07_B.kamm_data[31] = 3128.0;
        Torque_Control_ETR07_B.kamm_data[48] = 3115.0;
        Torque_Control_ETR07_B.kamm_data[65] = 3101.0;
        Torque_Control_ETR07_B.kamm_data[82] = 3087.0;
        Torque_Control_ETR07_B.kamm_data[99] = 3074.0;
        Torque_Control_ETR07_B.kamm_data[116] = 3059.0;
        Torque_Control_ETR07_B.kamm_data[133] = 3035.0;
        Torque_Control_ETR07_B.kamm_data[150] = 3012.0;
        Torque_Control_ETR07_B.kamm_data[167] = 2988.0;
        Torque_Control_ETR07_B.kamm_data[184] = 2962.0;
        Torque_Control_ETR07_B.kamm_data[201] = 2923.0;
        Torque_Control_ETR07_B.kamm_data[218] = 2884.0;
        Torque_Control_ETR07_B.kamm_data[235] = 2838.0;
        Torque_Control_ETR07_B.kamm_data[252] = 2778.0;
        Torque_Control_ETR07_B.kamm_data[269] = 2709.0;
        Torque_Control_ETR07_B.kamm_data[286] = 2625.0;
        Torque_Control_ETR07_B.kamm_data[303] = 2517.0;
        Torque_Control_ETR07_B.kamm_data[320] = 2396.0;
        Torque_Control_ETR07_B.kamm_data[337] = 2259.0;
        Torque_Control_ETR07_B.kamm_data[354] = 2104.0;
        Torque_Control_ETR07_B.kamm_data[371] = 1924.0;
        Torque_Control_ETR07_B.kamm_data[388] = 1730.0;
        Torque_Control_ETR07_B.kamm_data[405] = 1484.0;
        Torque_Control_ETR07_B.kamm_data[422] = 1169.0;
        Torque_Control_ETR07_B.kamm_data[439] = 772.0;
        Torque_Control_ETR07_B.kamm_data[456] = 213.0;
        Torque_Control_ETR07_B.kamm_data[473] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[490] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[507] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[524] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[541] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[15] = 1400.0;
        Torque_Control_ETR07_B.kamm_data[32] = 3228.0;
        Torque_Control_ETR07_B.kamm_data[49] = 3215.0;
        Torque_Control_ETR07_B.kamm_data[66] = 3201.0;
        Torque_Control_ETR07_B.kamm_data[83] = 3187.0;
        Torque_Control_ETR07_B.kamm_data[100] = 3172.0;
        Torque_Control_ETR07_B.kamm_data[117] = 3157.0;
        Torque_Control_ETR07_B.kamm_data[134] = 3134.0;
        Torque_Control_ETR07_B.kamm_data[151] = 3111.0;
        Torque_Control_ETR07_B.kamm_data[168] = 3087.0;
        Torque_Control_ETR07_B.kamm_data[185] = 3063.0;
        Torque_Control_ETR07_B.kamm_data[202] = 3026.0;
        Torque_Control_ETR07_B.kamm_data[219] = 2989.0;
        Torque_Control_ETR07_B.kamm_data[236] = 2952.0;
        Torque_Control_ETR07_B.kamm_data[253] = 2896.0;
        Torque_Control_ETR07_B.kamm_data[270] = 2841.0;
        Torque_Control_ETR07_B.kamm_data[287] = 2772.0;
        Torque_Control_ETR07_B.kamm_data[304] = 2691.0;
        Torque_Control_ETR07_B.kamm_data[321] = 2603.0;
        Torque_Control_ETR07_B.kamm_data[338] = 2500.0;
        Torque_Control_ETR07_B.kamm_data[355] = 2379.0;
        Torque_Control_ETR07_B.kamm_data[372] = 2243.0;
        Torque_Control_ETR07_B.kamm_data[389] = 2091.0;
        Torque_Control_ETR07_B.kamm_data[406] = 1927.0;
        Torque_Control_ETR07_B.kamm_data[423] = 1713.0;
        Torque_Control_ETR07_B.kamm_data[440] = 1414.0;
        Torque_Control_ETR07_B.kamm_data[457] = 1030.0;
        Torque_Control_ETR07_B.kamm_data[474] = 553.0;
        Torque_Control_ETR07_B.kamm_data[491] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[508] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[525] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[542] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[16] = 1500.0;
        Torque_Control_ETR07_B.kamm_data[33] = 3327.0;
        Torque_Control_ETR07_B.kamm_data[50] = 3312.0;
        Torque_Control_ETR07_B.kamm_data[67] = 3296.0;
        Torque_Control_ETR07_B.kamm_data[84] = 3280.0;
        Torque_Control_ETR07_B.kamm_data[101] = 3263.0;
        Torque_Control_ETR07_B.kamm_data[118] = 3247.0;
        Torque_Control_ETR07_B.kamm_data[135] = 3223.0;
        Torque_Control_ETR07_B.kamm_data[152] = 3198.0;
        Torque_Control_ETR07_B.kamm_data[169] = 3173.0;
        Torque_Control_ETR07_B.kamm_data[186] = 3147.0;
        Torque_Control_ETR07_B.kamm_data[203] = 3116.0;
        Torque_Control_ETR07_B.kamm_data[220] = 3078.0;
        Torque_Control_ETR07_B.kamm_data[237] = 3040.0;
        Torque_Control_ETR07_B.kamm_data[254] = 3001.0;
        Torque_Control_ETR07_B.kamm_data[271] = 2947.0;
        Torque_Control_ETR07_B.kamm_data[288] = 2893.0;
        Torque_Control_ETR07_B.kamm_data[305] = 2828.0;
        Torque_Control_ETR07_B.kamm_data[322] = 2756.0;
        Torque_Control_ETR07_B.kamm_data[339] = 2670.0;
        Torque_Control_ETR07_B.kamm_data[356] = 2576.0;
        Torque_Control_ETR07_B.kamm_data[373] = 2471.0;
        Torque_Control_ETR07_B.kamm_data[390] = 2353.0;
        Torque_Control_ETR07_B.kamm_data[407] = 2228.0;
        Torque_Control_ETR07_B.kamm_data[424] = 2100.0;
        Torque_Control_ETR07_B.kamm_data[441] = 1921.0;
        Torque_Control_ETR07_B.kamm_data[458] = 1649.0;
        Torque_Control_ETR07_B.kamm_data[475] = 1278.0;
        Torque_Control_ETR07_B.kamm_data[492] = 814.0;
        Torque_Control_ETR07_B.kamm_data[509] = 217.0;
        Torque_Control_ETR07_B.kamm_data[526] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[543] = (rtNaN);
        rtb_alpha_j = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          if (rtb_min > Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
            rtb_alpha_j = k;
          } else {
            if (rtb_min < Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
              Mz = k;
            }
          }

          k = floor((Mz + rtb_alpha_j) / 2.0);
          p = Mz - rtb_alpha_j;
          if (rtb_min == Torque_Control_ETR07_B.kamm_data[(int32_T)Mz]) {
            p = 1.0;
            rtb_alpha_j = Mz;
          } else if (rtb_min == Torque_Control_ETR07_B.kamm_data[(int32_T)
                     rtb_alpha_j]) {
            p = 1.0;
            Mz = rtb_alpha_j;
          } else {
            if (rtb_min == Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
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
          if (Torque_Control_ETR07_B.Constant_mf >
              Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k]) {
            my = k;
          } else {
            if (Torque_Control_ETR07_B.Constant_mf <
                Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k]) {
              My = k;
            }
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My] ==
              Torque_Control_ETR07_B.Constant_mf) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my] ==
                     Torque_Control_ETR07_B.Constant_mf) {
            p = 1.0;
            My = my;
          } else {
            if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k] ==
                Torque_Control_ETR07_B.Constant_mf) {
              p = 1.0;
              My = k;
              my = k;
            }
          }
        }

        if ((Mz == rtb_alpha_j) && (My != my)) {
          kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
          kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
          kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
            (int32_T)rtb_alpha_j];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_value_g = b_a[0] * Torque_Control_ETR07_B.Constant_mf + b_a[1];
        } else if ((Mz != rtb_alpha_j) && (My == my)) {
          kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_value_g = b_a[0] * rtb_min + b_a[1];
        } else if ((Mz == rtb_alpha_j) && (My == my)) {
          rtb_value_g = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
            (int32_T)Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          tmp[4] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[5] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[6] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          tmp[7] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          r1 = 17 * (int32_T)my;
          tmp[8] = Torque_Control_ETR07_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          tmp[9] = Torque_Control_ETR07_B.kamm_data[r2];
          tmp[10] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
          tmp[11] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
          kamm_data[0] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)
            rtb_alpha_j];
          kamm_data[1] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)
            rtb_alpha_j];
          kamm_data[2] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)Mz];
          kamm_data[3] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)Mz];
          mldivide_u4svSR16(tmp, kamm_data, a);
          rtb_value_g = (a[1] * rtb_min + a[0]) + a[2] *
            Torque_Control_ETR07_B.Constant_mf;
        }

        rtb_alpha_j = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          if (rtb_min > Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
            rtb_alpha_j = k;
          } else {
            if (rtb_min < Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
              Mz = k;
            }
          }

          k = floor((Mz + rtb_alpha_j) / 2.0);
          p = Mz - rtb_alpha_j;
          if (rtb_min == Torque_Control_ETR07_B.kamm_data[(int32_T)Mz]) {
            p = 1.0;
            rtb_alpha_j = Mz;
          } else if (rtb_min == Torque_Control_ETR07_B.kamm_data[(int32_T)
                     rtb_alpha_j]) {
            p = 1.0;
            Mz = rtb_alpha_j;
          } else {
            if (rtb_min == Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
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
          if (Torque_Control_ETR07_B.Constant_mf >
              Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k]) {
            my = k;
          } else {
            if (Torque_Control_ETR07_B.Constant_mf <
                Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k]) {
              My = k;
            }
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My] ==
              Torque_Control_ETR07_B.Constant_mf) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my] ==
                     Torque_Control_ETR07_B.Constant_mf) {
            p = 1.0;
            My = my;
          } else {
            if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k] ==
                Torque_Control_ETR07_B.Constant_mf) {
              p = 1.0;
              My = k;
              my = k;
            }
          }
        }

        if ((Mz == rtb_alpha_j) && (My != my)) {
          kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
          kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
          kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
            (int32_T)rtb_alpha_j];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_alpha_j = b_a[0] * Torque_Control_ETR07_B.Constant_mf + b_a[1];
        } else if ((Mz != rtb_alpha_j) && (My == my)) {
          kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_alpha_j = b_a[0] * rtb_min + b_a[1];
        } else if ((Mz == rtb_alpha_j) && (My == my)) {
          rtb_alpha_j = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
            (int32_T)Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          tmp[4] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[5] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[6] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          tmp[7] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          r1 = 17 * (int32_T)my;
          tmp[8] = Torque_Control_ETR07_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          tmp[9] = Torque_Control_ETR07_B.kamm_data[r2];
          tmp[10] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
          tmp[11] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
          kamm_data[0] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)
            rtb_alpha_j];
          kamm_data[1] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)
            rtb_alpha_j];
          kamm_data[2] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)Mz];
          kamm_data[3] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)Mz];
          mldivide_u4svSR16(tmp, kamm_data, a);
          rtb_alpha_j = (a[1] * rtb_min + a[0]) + a[2] *
            Torque_Control_ETR07_B.Constant_mf;
        }

        /* Product: '<S135>/Product' incorporates:
         *  MATLAB Function: '<S135>/Kamm_Circle LatD'
         */
        rtb_Product_a = rtb_value_g * Torque_Control_ETR07_B.Saturation_f;

        /* Product: '<S135>/Product1' incorporates:
         *  MATLAB Function: '<S135>/Kamm_Circle LatD'
         */
        rtb_Product1_f = rtb_alpha_j * Torque_Control_ETR07_B.Saturation_f;

        /* MATLAB Function: '<S101>/MATLAB Function' */
        Torque_Contro_MATLABFunction_d1(Torque_Control_ETR07_B.Constant4_m,
          rtb_Product_a, &Torque_Control_ETR07_B.sf_MATLABFunction_d1);

        /* MATLAB Function: '<S101>/MATLAB Function1' */
        Torque_Contro_MATLABFunction_d1(Torque_Control_ETR07_B.Constant3_e,
          rtb_Product1_f, &Torque_Control_ETR07_B.sf_MATLABFunction1_g);

        /* SignalConversion: '<S101>/OutportBufferForFx_RL ' */
        Torque_Control_ETR07_B.Merge3_e =
          Torque_Control_ETR07_B.sf_MATLABFunction1_g.value;

        /* SignalConversion: '<S101>/OutportBufferForFx_RR ' */
        Torque_Control_ETR07_B.Merge2_lx =
          Torque_Control_ETR07_B.sf_MATLABFunction_d1.value;
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          /* SignalConversion: '<S101>/OutportBufferForFy_R' incorporates:
           *  Constant: '<S101>/Constant5'
           */
          Torque_Control_ETR07_B.Merge6 = Torque_Control_ETR07_P.Constant5_Value;

          /* SignalConversion: '<S101>/OutportBufferForFlag CarBehavior' incorporates:
           *  Constant: '<S101>/Constant6'
           */
          Torque_Control_ETR07_B.Merge7 = Torque_Control_ETR07_P.Constant6_Value;
        }

        /* Sum: '<S101>/Add1' */
        Torque_Control_ETR07_B.Merge5_e = rtb_Subtract1 - rtb_Abs1;

        /* End of Outputs for SubSystem: '<S68>/Longitudinal Dynamics' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S68>/Lateral Dynamics' incorporates:
         *  ActionPort: '<S100>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          /* SignalConversion: '<S100>/OutportBufferForFx_FR' incorporates:
           *  Constant: '<S100>/Constant1'
           */
          Torque_Control_ETR07_B.Merge_m =
            Torque_Control_ETR07_P.Constant1_Value_a;

          /* SignalConversion: '<S100>/OutportBufferForFx_FL' incorporates:
           *  Constant: '<S100>/Constant2'
           */
          Torque_Control_ETR07_B.Merge1_n =
            Torque_Control_ETR07_P.Constant2_Value_g;
          Torque_Control_ETR07_B.Constant3 =
            Torque_Control_ETR07_P.Constant3_Value_o;
          Torque_Control_ETR07_B.Constant4 =
            Torque_Control_ETR07_P.Constant4_Value_p;
          Torque_Control_ETR07_B.Steering_Ratio =
            Torque_Control_ETR07_P.Steering_Ratio_Value;
          Torque_Control_ETR07_B.Constant8 =
            Torque_Control_ETR07_P.Constant8_Value;
          Torque_Control_ETR07_B.Constant7 =
            Torque_Control_ETR07_P.Constant7_Value;
          Torque_Control_ETR07_B.Wheelbasem =
            Torque_Control_ETR07_P.Wheelbasem_Value;

          /* Gain: '<S130>/360//(2*pi)' incorporates:
           *  Constant: '<S100>/Constant3'
           *  Constant: '<S100>/Constant4'
           *  Constant: '<S130>/Constant7'
           *  Constant: '<S130>/Constant8'
           *  Constant: '<S130>/Cornering_Stiffness_F[N//º]'
           *  Constant: '<S130>/Steering_Ratio [-]'
           *  Constant: '<S130>/Wheelbase [m]'
           */
          Torque_Control_ETR07_B.u602pi = Torque_Control_ETR07_P.u602pi_Gain *
            Torque_Control_ETR07_P.Cornering_Stiffness_FN_Value;

          /* Gain: '<S130>/360//(2pi)' incorporates:
           *  Constant: '<S130>/Cornering_Stiffness_R[N//º]'
           */
          Torque_Control_ETR07_B.u602pi_e = Torque_Control_ETR07_P.u602pi_Gain_g
            * Torque_Control_ETR07_P.Cornering_Stiffness_RN_Value;
        }

        /* Sum: '<S100>/Add' incorporates:
         *  Constant: '<S100>/Constant3'
         *  Constant: '<S100>/Constant4'
         *  Constant: '<S130>/Constant7'
         *  Constant: '<S130>/Constant8'
         *  Constant: '<S130>/Steering_Ratio [-]'
         *  Constant: '<S130>/Wheelbase [m]'
         */
        Torque_Control_ETR07_B.Merge5_e = rtb_Subtract1 - rtb_Abs1;

        /* MATLAB Function: '<S130>/Bicycle Model' incorporates:
         *  Integrator: '<S100>/Integrator'
         *  Product: '<S130>/Divide'
         */
        A[0] = Torque_Control_ETR07_B.u602pi;
        A[3] = Torque_Control_ETR07_B.u602pi_e;
        A[6] = -Torque_Control_ETR07_B.Constant8 *
          Torque_Control_ETR07_X.Integrator_CSTATE;
        A[1] = Torque_Control_ETR07_B.Constant7 * Torque_Control_ETR07_B.u602pi;
        A[4] = -(Torque_Control_ETR07_B.Wheelbasem -
                 Torque_Control_ETR07_B.Constant7) *
          Torque_Control_ETR07_B.u602pi_e;
        A[7] = 0.0;
        A[2] = -1.0;
        A[5] = 1.0;
        A[8] = Torque_Control_ETR07_B.Wheelbasem /
          Torque_Control_ETR07_X.Integrator_CSTATE;
        a[0] = 0.0;
        a[1] = 0.0;
        a[2] = Torque_Control_ETR07_B.Gain /
          Torque_Control_ETR07_B.Steering_Ratio * 2.0 * 3.1415926535897931 /
          360.0;
        r1 = 0;
        r2 = 1;
        r3 = 2;
        rtb_Abs1 = fabs(Torque_Control_ETR07_B.u602pi);
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
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          Torque_Control_ETR07_B.Yaw_Inertiakgm3 =
            Torque_Control_ETR07_P.Yaw_Inertiakgm3_Value;

          /* Product: '<S132>/Divide1' incorporates:
           *  Constant: '<S100>/Rear_Trackwidth [m] '
           *  Constant: '<S100>/Yaw_Inertia [kg//m^3]'
           *  Constant: '<S132>/Constant'
           */
          Torque_Control_ETR07_B.Divide1 =
            Torque_Control_ETR07_P.Rear_Trackwidthm_Value /
            Torque_Control_ETR07_P.Constant_Value_ad;
        }

        /* Product: '<S132>/Divide' incorporates:
         *  Constant: '<S100>/Yaw_Inertia [kg//m^3]'
         *  Inport: '<Root>/Gyro_F_Z_Deg'
         *  MATLAB Function: '<S130>/Bicycle Model'
         *  Product: '<S133>/Divide'
         *  Product: '<S133>/Product'
         *  Sum: '<S100>/Sum3'
         */
        rtb_Abs1 = (((a[r3] - a[r1] * A[r3]) - (a[r2] - a[r1] * A[r2]) * A[3 +
                     r3]) / A[6 + r3] - Torque_Control_ETR07_U.Gyro_F_Z_Deg) *
          Torque_Control_ETR07_B.Yaw_Inertiakgm3 /
          Torque_Control_ETR07_B.Constant1_j / Torque_Control_ETR07_B.Divide1;

        /* Sum: '<S100>/Sum' */
        rtb_min = Torque_Control_ETR07_B.Merge2 + Torque_Control_ETR07_B.Merge3;

        /* Gain: '<S100>/Fy per wheel' incorporates:
         *  Gain: '<S100>/Gravity'
         *  Product: '<S100>/Product'
         *  Sum: '<S100>/Sum'
         */
        rtb_Subtract1 = Torque_Control_ETR07_P.Gravity_Gain * rtb_min *
          rtb_Subtract1 * Torque_Control_ETR07_P.Fyperwheel_Gain;

        /* MATLAB Function: '<S126>/Kamm_Circle LatD' */
        Torque_Control_ETR07_B.kamm_data[0] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[17] = 0.0;
        Torque_Control_ETR07_B.kamm_data[34] = 100.0;
        Torque_Control_ETR07_B.kamm_data[51] = 200.0;
        Torque_Control_ETR07_B.kamm_data[68] = 300.0;
        Torque_Control_ETR07_B.kamm_data[85] = 400.0;
        Torque_Control_ETR07_B.kamm_data[102] = 500.0;
        Torque_Control_ETR07_B.kamm_data[119] = 600.0;
        Torque_Control_ETR07_B.kamm_data[136] = 700.0;
        Torque_Control_ETR07_B.kamm_data[153] = 800.0;
        Torque_Control_ETR07_B.kamm_data[170] = 900.0;
        Torque_Control_ETR07_B.kamm_data[187] = 1000.0;
        Torque_Control_ETR07_B.kamm_data[204] = 1100.0;
        Torque_Control_ETR07_B.kamm_data[221] = 1200.0;
        Torque_Control_ETR07_B.kamm_data[238] = 1300.0;
        Torque_Control_ETR07_B.kamm_data[255] = 1400.0;
        Torque_Control_ETR07_B.kamm_data[272] = 1500.0;
        Torque_Control_ETR07_B.kamm_data[289] = 1600.0;
        Torque_Control_ETR07_B.kamm_data[306] = 1700.0;
        Torque_Control_ETR07_B.kamm_data[323] = 1800.0;
        Torque_Control_ETR07_B.kamm_data[340] = 1900.0;
        Torque_Control_ETR07_B.kamm_data[357] = 2000.0;
        Torque_Control_ETR07_B.kamm_data[374] = 2100.0;
        Torque_Control_ETR07_B.kamm_data[391] = 2200.0;
        Torque_Control_ETR07_B.kamm_data[408] = 2300.0;
        Torque_Control_ETR07_B.kamm_data[425] = 2400.0;
        Torque_Control_ETR07_B.kamm_data[442] = 2500.0;
        Torque_Control_ETR07_B.kamm_data[459] = 2600.0;
        Torque_Control_ETR07_B.kamm_data[476] = 2700.0;
        Torque_Control_ETR07_B.kamm_data[493] = 2800.0;
        Torque_Control_ETR07_B.kamm_data[510] = 2900.0;
        Torque_Control_ETR07_B.kamm_data[527] = 3000.0;
        Torque_Control_ETR07_B.kamm_data[1] = 0.0;
        Torque_Control_ETR07_B.kamm_data[18] = 0.0;
        Torque_Control_ETR07_B.kamm_data[35] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[52] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[69] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[86] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[103] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[120] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[137] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[154] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[171] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[188] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[205] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[222] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[239] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[256] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[273] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[290] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[307] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[324] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[341] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[358] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[375] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[392] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[409] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[426] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[443] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[460] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[477] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[494] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[511] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[528] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[2] = 100.0;
        Torque_Control_ETR07_B.kamm_data[19] = 350.0;
        Torque_Control_ETR07_B.kamm_data[36] = 340.0;
        Torque_Control_ETR07_B.kamm_data[53] = 156.0;
        Torque_Control_ETR07_B.kamm_data[70] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[87] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[104] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[121] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[138] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[155] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[172] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[189] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[206] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[223] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[240] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[257] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[274] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[291] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[308] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[325] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[342] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[359] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[376] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[393] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[410] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[427] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[444] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[461] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[478] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[495] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[512] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[529] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[3] = 200.0;
        Torque_Control_ETR07_B.kamm_data[20] = 688.0;
        Torque_Control_ETR07_B.kamm_data[37] = 676.0;
        Torque_Control_ETR07_B.kamm_data[54] = 654.0;
        Torque_Control_ETR07_B.kamm_data[71] = 573.0;
        Torque_Control_ETR07_B.kamm_data[88] = 269.0;
        Torque_Control_ETR07_B.kamm_data[105] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[122] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[139] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[156] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[173] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[190] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[207] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[224] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[241] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[258] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[275] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[292] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[309] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[326] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[343] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[360] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[377] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[394] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[411] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[428] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[445] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[462] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[479] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[496] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[513] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[530] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[4] = 300.0;
        Torque_Control_ETR07_B.kamm_data[21] = 1002.0;
        Torque_Control_ETR07_B.kamm_data[38] = 994.0;
        Torque_Control_ETR07_B.kamm_data[55] = 982.0;
        Torque_Control_ETR07_B.kamm_data[72] = 959.0;
        Torque_Control_ETR07_B.kamm_data[89] = 888.0;
        Torque_Control_ETR07_B.kamm_data[106] = 694.0;
        Torque_Control_ETR07_B.kamm_data[123] = 345.0;
        Torque_Control_ETR07_B.kamm_data[140] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[157] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[174] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[191] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[208] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[225] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[242] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[259] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[276] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[293] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[310] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[327] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[344] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[361] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[378] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[395] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[412] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[429] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[446] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[463] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[480] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[497] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[514] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[531] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[5] = 400.0;
        Torque_Control_ETR07_B.kamm_data[22] = 1295.0;
        Torque_Control_ETR07_B.kamm_data[39] = 1288.0;
        Torque_Control_ETR07_B.kamm_data[56] = 1280.0;
        Torque_Control_ETR07_B.kamm_data[73] = 1263.0;
        Torque_Control_ETR07_B.kamm_data[90] = 1235.0;
        Torque_Control_ETR07_B.kamm_data[107] = 1168.0;
        Torque_Control_ETR07_B.kamm_data[124] = 1001.0;
        Torque_Control_ETR07_B.kamm_data[141] = 740.0;
        Torque_Control_ETR07_B.kamm_data[158] = 389.0;
        Torque_Control_ETR07_B.kamm_data[175] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[192] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[209] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[226] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[243] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[260] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[277] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[294] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[311] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[328] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[345] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[362] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[379] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[396] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[413] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[430] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[447] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[464] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[481] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[498] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[515] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[532] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[6] = 500.0;
        Torque_Control_ETR07_B.kamm_data[23] = 1536.0;
        Torque_Control_ETR07_B.kamm_data[40] = 1529.0;
        Torque_Control_ETR07_B.kamm_data[57] = 1521.0;
        Torque_Control_ETR07_B.kamm_data[74] = 1509.0;
        Torque_Control_ETR07_B.kamm_data[91] = 1491.0;
        Torque_Control_ETR07_B.kamm_data[108] = 1459.0;
        Torque_Control_ETR07_B.kamm_data[125] = 1395.0;
        Torque_Control_ETR07_B.kamm_data[142] = 1230.0;
        Torque_Control_ETR07_B.kamm_data[159] = 1032.0;
        Torque_Control_ETR07_B.kamm_data[176] = 760.0;
        Torque_Control_ETR07_B.kamm_data[193] = 411.0;
        Torque_Control_ETR07_B.kamm_data[210] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[227] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[244] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[261] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[278] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[295] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[312] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[329] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[346] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[363] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[380] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[397] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[414] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[431] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[448] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[465] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[482] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[499] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[516] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[533] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[7] = 600.0;
        Torque_Control_ETR07_B.kamm_data[24] = 1745.0;
        Torque_Control_ETR07_B.kamm_data[41] = 1737.0;
        Torque_Control_ETR07_B.kamm_data[58] = 1729.0;
        Torque_Control_ETR07_B.kamm_data[75] = 1721.0;
        Torque_Control_ETR07_B.kamm_data[92] = 1704.0;
        Torque_Control_ETR07_B.kamm_data[109] = 1686.0;
        Torque_Control_ETR07_B.kamm_data[126] = 1649.0;
        Torque_Control_ETR07_B.kamm_data[143] = 1585.0;
        Torque_Control_ETR07_B.kamm_data[160] = 1455.0;
        Torque_Control_ETR07_B.kamm_data[177] = 1270.0;
        Torque_Control_ETR07_B.kamm_data[194] = 1038.0;
        Torque_Control_ETR07_B.kamm_data[211] = 756.0;
        Torque_Control_ETR07_B.kamm_data[228] = 419.0;
        Torque_Control_ETR07_B.kamm_data[245] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[262] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[279] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[296] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[313] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[330] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[347] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[364] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[381] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[398] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[415] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[432] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[449] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[466] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[483] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[500] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[517] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[534] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[8] = 700.0;
        Torque_Control_ETR07_B.kamm_data[25] = 1964.0;
        Torque_Control_ETR07_B.kamm_data[42] = 1956.0;
        Torque_Control_ETR07_B.kamm_data[59] = 1948.0;
        Torque_Control_ETR07_B.kamm_data[76] = 1940.0;
        Torque_Control_ETR07_B.kamm_data[93] = 1926.0;
        Torque_Control_ETR07_B.kamm_data[110] = 1909.0;
        Torque_Control_ETR07_B.kamm_data[127] = 1884.0;
        Torque_Control_ETR07_B.kamm_data[144] = 1848.0;
        Torque_Control_ETR07_B.kamm_data[161] = 1777.0;
        Torque_Control_ETR07_B.kamm_data[178] = 1656.0;
        Torque_Control_ETR07_B.kamm_data[195] = 1484.0;
        Torque_Control_ETR07_B.kamm_data[212] = 1278.0;
        Torque_Control_ETR07_B.kamm_data[229] = 1029.0;
        Torque_Control_ETR07_B.kamm_data[246] = 742.0;
        Torque_Control_ETR07_B.kamm_data[263] = 416.0;
        Torque_Control_ETR07_B.kamm_data[280] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[297] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[314] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[331] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[348] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[365] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[382] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[399] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[416] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[433] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[450] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[467] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[484] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[501] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[518] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[535] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[9] = 800.0;
        Torque_Control_ETR07_B.kamm_data[26] = 2212.0;
        Torque_Control_ETR07_B.kamm_data[43] = 2204.0;
        Torque_Control_ETR07_B.kamm_data[60] = 2195.0;
        Torque_Control_ETR07_B.kamm_data[77] = 2187.0;
        Torque_Control_ETR07_B.kamm_data[94] = 2175.0;
        Torque_Control_ETR07_B.kamm_data[111] = 2158.0;
        Torque_Control_ETR07_B.kamm_data[128] = 2141.0;
        Torque_Control_ETR07_B.kamm_data[145] = 2107.0;
        Torque_Control_ETR07_B.kamm_data[162] = 2063.0;
        Torque_Control_ETR07_B.kamm_data[179] = 1990.0;
        Torque_Control_ETR07_B.kamm_data[196] = 1868.0;
        Torque_Control_ETR07_B.kamm_data[213] = 1704.0;
        Torque_Control_ETR07_B.kamm_data[230] = 1505.0;
        Torque_Control_ETR07_B.kamm_data[247] = 1275.0;
        Torque_Control_ETR07_B.kamm_data[264] = 1018.0;
        Torque_Control_ETR07_B.kamm_data[281] = 730.0;
        Torque_Control_ETR07_B.kamm_data[298] = 404.0;
        Torque_Control_ETR07_B.kamm_data[315] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[332] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[349] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[366] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[383] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[400] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[417] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[434] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[451] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[468] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[485] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[502] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[519] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[536] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[10] = 900.0;
        Torque_Control_ETR07_B.kamm_data[27] = 2465.0;
        Torque_Control_ETR07_B.kamm_data[44] = 2456.0;
        Torque_Control_ETR07_B.kamm_data[61] = 2448.0;
        Torque_Control_ETR07_B.kamm_data[78] = 2439.0;
        Torque_Control_ETR07_B.kamm_data[95] = 2428.0;
        Torque_Control_ETR07_B.kamm_data[112] = 2411.0;
        Torque_Control_ETR07_B.kamm_data[129] = 2394.0;
        Torque_Control_ETR07_B.kamm_data[146] = 2367.0;
        Torque_Control_ETR07_B.kamm_data[163] = 2333.0;
        Torque_Control_ETR07_B.kamm_data[180] = 2279.0;
        Torque_Control_ETR07_B.kamm_data[197] = 2200.0;
        Torque_Control_ETR07_B.kamm_data[214] = 2081.0;
        Torque_Control_ETR07_B.kamm_data[231] = 1921.0;
        Torque_Control_ETR07_B.kamm_data[248] = 1729.0;
        Torque_Control_ETR07_B.kamm_data[265] = 1512.0;
        Torque_Control_ETR07_B.kamm_data[282] = 1268.0;
        Torque_Control_ETR07_B.kamm_data[299] = 1002.0;
        Torque_Control_ETR07_B.kamm_data[316] = 711.0;
        Torque_Control_ETR07_B.kamm_data[333] = 345.0;
        Torque_Control_ETR07_B.kamm_data[350] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[367] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[384] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[401] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[418] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[435] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[452] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[469] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[486] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[503] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[520] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[537] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[11] = 1000.0;
        Torque_Control_ETR07_B.kamm_data[28] = 2684.0;
        Torque_Control_ETR07_B.kamm_data[45] = 2675.0;
        Torque_Control_ETR07_B.kamm_data[62] = 2666.0;
        Torque_Control_ETR07_B.kamm_data[79] = 2657.0;
        Torque_Control_ETR07_B.kamm_data[96] = 2647.0;
        Torque_Control_ETR07_B.kamm_data[113] = 2629.0;
        Torque_Control_ETR07_B.kamm_data[130] = 2612.0;
        Torque_Control_ETR07_B.kamm_data[147] = 2592.0;
        Torque_Control_ETR07_B.kamm_data[164] = 2558.0;
        Torque_Control_ETR07_B.kamm_data[181] = 2520.0;
        Torque_Control_ETR07_B.kamm_data[198] = 2462.0;
        Torque_Control_ETR07_B.kamm_data[215] = 2378.0;
        Torque_Control_ETR07_B.kamm_data[232] = 2262.0;
        Torque_Control_ETR07_B.kamm_data[249] = 2119.0;
        Torque_Control_ETR07_B.kamm_data[266] = 1940.0;
        Torque_Control_ETR07_B.kamm_data[283] = 1737.0;
        Torque_Control_ETR07_B.kamm_data[300] = 1508.0;
        Torque_Control_ETR07_B.kamm_data[317] = 1259.0;
        Torque_Control_ETR07_B.kamm_data[334] = 989.0;
        Torque_Control_ETR07_B.kamm_data[351] = 680.0;
        Torque_Control_ETR07_B.kamm_data[368] = 240.0;
        Torque_Control_ETR07_B.kamm_data[385] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[402] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[419] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[436] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[453] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[470] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[487] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[504] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[521] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[538] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[12] = 1100.0;
        Torque_Control_ETR07_B.kamm_data[29] = 2853.0;
        Torque_Control_ETR07_B.kamm_data[46] = 2843.0;
        Torque_Control_ETR07_B.kamm_data[63] = 2833.0;
        Torque_Control_ETR07_B.kamm_data[80] = 2822.0;
        Torque_Control_ETR07_B.kamm_data[97] = 2811.0;
        Torque_Control_ETR07_B.kamm_data[114] = 2795.0;
        Torque_Control_ETR07_B.kamm_data[131] = 2775.0;
        Torque_Control_ETR07_B.kamm_data[148] = 2755.0;
        Torque_Control_ETR07_B.kamm_data[165] = 2728.0;
        Torque_Control_ETR07_B.kamm_data[182] = 2693.0;
        Torque_Control_ETR07_B.kamm_data[199] = 2651.0;
        Torque_Control_ETR07_B.kamm_data[216] = 2591.0;
        Torque_Control_ETR07_B.kamm_data[233] = 2510.0;
        Torque_Control_ETR07_B.kamm_data[250] = 2412.0;
        Torque_Control_ETR07_B.kamm_data[267] = 2282.0;
        Torque_Control_ETR07_B.kamm_data[284] = 2124.0;
        Torque_Control_ETR07_B.kamm_data[301] = 1940.0;
        Torque_Control_ETR07_B.kamm_data[318] = 1735.0;
        Torque_Control_ETR07_B.kamm_data[335] = 1504.0;
        Torque_Control_ETR07_B.kamm_data[352] = 1250.0;
        Torque_Control_ETR07_B.kamm_data[369] = 962.0;
        Torque_Control_ETR07_B.kamm_data[386] = 608.0;
        Torque_Control_ETR07_B.kamm_data[403] = 108.0;
        Torque_Control_ETR07_B.kamm_data[420] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[437] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[454] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[471] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[488] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[505] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[522] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[539] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[13] = 1200.0;
        Torque_Control_ETR07_B.kamm_data[30] = 2999.0;
        Torque_Control_ETR07_B.kamm_data[47] = 2988.0;
        Torque_Control_ETR07_B.kamm_data[64] = 2976.0;
        Torque_Control_ETR07_B.kamm_data[81] = 2964.0;
        Torque_Control_ETR07_B.kamm_data[98] = 2952.0;
        Torque_Control_ETR07_B.kamm_data[115] = 2936.0;
        Torque_Control_ETR07_B.kamm_data[132] = 2914.0;
        Torque_Control_ETR07_B.kamm_data[149] = 2893.0;
        Torque_Control_ETR07_B.kamm_data[166] = 2872.0;
        Torque_Control_ETR07_B.kamm_data[183] = 2837.0;
        Torque_Control_ETR07_B.kamm_data[200] = 2799.0;
        Torque_Control_ETR07_B.kamm_data[217] = 2755.0;
        Torque_Control_ETR07_B.kamm_data[234] = 2694.0;
        Torque_Control_ETR07_B.kamm_data[251] = 2619.0;
        Torque_Control_ETR07_B.kamm_data[268] = 2527.0;
        Torque_Control_ETR07_B.kamm_data[285] = 2412.0;
        Torque_Control_ETR07_B.kamm_data[302] = 2275.0;
        Torque_Control_ETR07_B.kamm_data[319] = 2114.0;
        Torque_Control_ETR07_B.kamm_data[336] = 1936.0;
        Torque_Control_ETR07_B.kamm_data[353] = 1729.0;
        Torque_Control_ETR07_B.kamm_data[370] = 1507.0;
        Torque_Control_ETR07_B.kamm_data[387] = 1233.0;
        Torque_Control_ETR07_B.kamm_data[404] = 896.0;
        Torque_Control_ETR07_B.kamm_data[421] = 461.0;
        Torque_Control_ETR07_B.kamm_data[438] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[455] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[472] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[489] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[506] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[523] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[540] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[14] = 1300.0;
        Torque_Control_ETR07_B.kamm_data[31] = 3128.0;
        Torque_Control_ETR07_B.kamm_data[48] = 3115.0;
        Torque_Control_ETR07_B.kamm_data[65] = 3101.0;
        Torque_Control_ETR07_B.kamm_data[82] = 3087.0;
        Torque_Control_ETR07_B.kamm_data[99] = 3074.0;
        Torque_Control_ETR07_B.kamm_data[116] = 3059.0;
        Torque_Control_ETR07_B.kamm_data[133] = 3035.0;
        Torque_Control_ETR07_B.kamm_data[150] = 3012.0;
        Torque_Control_ETR07_B.kamm_data[167] = 2988.0;
        Torque_Control_ETR07_B.kamm_data[184] = 2962.0;
        Torque_Control_ETR07_B.kamm_data[201] = 2923.0;
        Torque_Control_ETR07_B.kamm_data[218] = 2884.0;
        Torque_Control_ETR07_B.kamm_data[235] = 2838.0;
        Torque_Control_ETR07_B.kamm_data[252] = 2778.0;
        Torque_Control_ETR07_B.kamm_data[269] = 2709.0;
        Torque_Control_ETR07_B.kamm_data[286] = 2625.0;
        Torque_Control_ETR07_B.kamm_data[303] = 2517.0;
        Torque_Control_ETR07_B.kamm_data[320] = 2396.0;
        Torque_Control_ETR07_B.kamm_data[337] = 2259.0;
        Torque_Control_ETR07_B.kamm_data[354] = 2104.0;
        Torque_Control_ETR07_B.kamm_data[371] = 1924.0;
        Torque_Control_ETR07_B.kamm_data[388] = 1730.0;
        Torque_Control_ETR07_B.kamm_data[405] = 1484.0;
        Torque_Control_ETR07_B.kamm_data[422] = 1169.0;
        Torque_Control_ETR07_B.kamm_data[439] = 772.0;
        Torque_Control_ETR07_B.kamm_data[456] = 213.0;
        Torque_Control_ETR07_B.kamm_data[473] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[490] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[507] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[524] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[541] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[15] = 1400.0;
        Torque_Control_ETR07_B.kamm_data[32] = 3228.0;
        Torque_Control_ETR07_B.kamm_data[49] = 3215.0;
        Torque_Control_ETR07_B.kamm_data[66] = 3201.0;
        Torque_Control_ETR07_B.kamm_data[83] = 3187.0;
        Torque_Control_ETR07_B.kamm_data[100] = 3172.0;
        Torque_Control_ETR07_B.kamm_data[117] = 3157.0;
        Torque_Control_ETR07_B.kamm_data[134] = 3134.0;
        Torque_Control_ETR07_B.kamm_data[151] = 3111.0;
        Torque_Control_ETR07_B.kamm_data[168] = 3087.0;
        Torque_Control_ETR07_B.kamm_data[185] = 3063.0;
        Torque_Control_ETR07_B.kamm_data[202] = 3026.0;
        Torque_Control_ETR07_B.kamm_data[219] = 2989.0;
        Torque_Control_ETR07_B.kamm_data[236] = 2952.0;
        Torque_Control_ETR07_B.kamm_data[253] = 2896.0;
        Torque_Control_ETR07_B.kamm_data[270] = 2841.0;
        Torque_Control_ETR07_B.kamm_data[287] = 2772.0;
        Torque_Control_ETR07_B.kamm_data[304] = 2691.0;
        Torque_Control_ETR07_B.kamm_data[321] = 2603.0;
        Torque_Control_ETR07_B.kamm_data[338] = 2500.0;
        Torque_Control_ETR07_B.kamm_data[355] = 2379.0;
        Torque_Control_ETR07_B.kamm_data[372] = 2243.0;
        Torque_Control_ETR07_B.kamm_data[389] = 2091.0;
        Torque_Control_ETR07_B.kamm_data[406] = 1927.0;
        Torque_Control_ETR07_B.kamm_data[423] = 1713.0;
        Torque_Control_ETR07_B.kamm_data[440] = 1414.0;
        Torque_Control_ETR07_B.kamm_data[457] = 1030.0;
        Torque_Control_ETR07_B.kamm_data[474] = 553.0;
        Torque_Control_ETR07_B.kamm_data[491] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[508] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[525] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[542] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[16] = 1500.0;
        Torque_Control_ETR07_B.kamm_data[33] = 3327.0;
        Torque_Control_ETR07_B.kamm_data[50] = 3312.0;
        Torque_Control_ETR07_B.kamm_data[67] = 3296.0;
        Torque_Control_ETR07_B.kamm_data[84] = 3280.0;
        Torque_Control_ETR07_B.kamm_data[101] = 3263.0;
        Torque_Control_ETR07_B.kamm_data[118] = 3247.0;
        Torque_Control_ETR07_B.kamm_data[135] = 3223.0;
        Torque_Control_ETR07_B.kamm_data[152] = 3198.0;
        Torque_Control_ETR07_B.kamm_data[169] = 3173.0;
        Torque_Control_ETR07_B.kamm_data[186] = 3147.0;
        Torque_Control_ETR07_B.kamm_data[203] = 3116.0;
        Torque_Control_ETR07_B.kamm_data[220] = 3078.0;
        Torque_Control_ETR07_B.kamm_data[237] = 3040.0;
        Torque_Control_ETR07_B.kamm_data[254] = 3001.0;
        Torque_Control_ETR07_B.kamm_data[271] = 2947.0;
        Torque_Control_ETR07_B.kamm_data[288] = 2893.0;
        Torque_Control_ETR07_B.kamm_data[305] = 2828.0;
        Torque_Control_ETR07_B.kamm_data[322] = 2756.0;
        Torque_Control_ETR07_B.kamm_data[339] = 2670.0;
        Torque_Control_ETR07_B.kamm_data[356] = 2576.0;
        Torque_Control_ETR07_B.kamm_data[373] = 2471.0;
        Torque_Control_ETR07_B.kamm_data[390] = 2353.0;
        Torque_Control_ETR07_B.kamm_data[407] = 2228.0;
        Torque_Control_ETR07_B.kamm_data[424] = 2100.0;
        Torque_Control_ETR07_B.kamm_data[441] = 1921.0;
        Torque_Control_ETR07_B.kamm_data[458] = 1649.0;
        Torque_Control_ETR07_B.kamm_data[475] = 1278.0;
        Torque_Control_ETR07_B.kamm_data[492] = 814.0;
        Torque_Control_ETR07_B.kamm_data[509] = 217.0;
        Torque_Control_ETR07_B.kamm_data[526] = (rtNaN);
        Torque_Control_ETR07_B.kamm_data[543] = (rtNaN);
        rtb_alpha_j = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          if (Torque_Control_ETR07_B.Merge2 > Torque_Control_ETR07_B.kamm_data
              [(int32_T)k]) {
            rtb_alpha_j = k;
          } else {
            if (Torque_Control_ETR07_B.Merge2 <
                Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
              Mz = k;
            }
          }

          k = floor((Mz + rtb_alpha_j) / 2.0);
          p = Mz - rtb_alpha_j;
          if (Torque_Control_ETR07_B.Merge2 == Torque_Control_ETR07_B.kamm_data
              [(int32_T)Mz]) {
            p = 1.0;
            rtb_alpha_j = Mz;
          } else if (Torque_Control_ETR07_B.Merge2 ==
                     Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j]) {
            p = 1.0;
            Mz = rtb_alpha_j;
          } else {
            if (Torque_Control_ETR07_B.Merge2 ==
                Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
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
          if (rtb_Subtract1 > Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k])
          {
            my = k;
          } else {
            if (rtb_Subtract1 < Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k])
            {
              My = k;
            }
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My] ==
              rtb_Subtract1) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my] ==
                     rtb_Subtract1) {
            p = 1.0;
            My = my;
          } else {
            if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k] ==
                rtb_Subtract1) {
              p = 1.0;
              My = k;
              my = k;
            }
          }
        }

        if ((Mz == rtb_alpha_j) && (My != my)) {
          kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
          kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
          kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
            (int32_T)rtb_alpha_j];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_value_g = b_a[0] * rtb_Subtract1 + b_a[1];
        } else if ((Mz != rtb_alpha_j) && (My == my)) {
          kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_value_g = b_a[0] * Torque_Control_ETR07_B.Merge2 + b_a[1];
        } else if ((Mz == rtb_alpha_j) && (My == my)) {
          rtb_value_g = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
            (int32_T)Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          tmp[4] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[5] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[6] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          tmp[7] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          r1 = 17 * (int32_T)my;
          tmp[8] = Torque_Control_ETR07_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          tmp[9] = Torque_Control_ETR07_B.kamm_data[r2];
          tmp[10] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
          tmp[11] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
          kamm_data[0] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)
            rtb_alpha_j];
          kamm_data[1] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)
            rtb_alpha_j];
          kamm_data[2] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)Mz];
          kamm_data[3] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)Mz];
          mldivide_u4svSR16(tmp, kamm_data, a);
          rtb_value_g = (a[1] * Torque_Control_ETR07_B.Merge2 + a[0]) + a[2] *
            rtb_Subtract1;
        }

        rtb_alpha_j = 1.0;
        Mz = 16.0;
        k = 8.0;
        p = 15.0;
        while (p != 1.0) {
          if (Torque_Control_ETR07_B.Merge3 > Torque_Control_ETR07_B.kamm_data
              [(int32_T)k]) {
            rtb_alpha_j = k;
          } else {
            if (Torque_Control_ETR07_B.Merge3 <
                Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
              Mz = k;
            }
          }

          k = floor((Mz + rtb_alpha_j) / 2.0);
          p = Mz - rtb_alpha_j;
          if (Torque_Control_ETR07_B.Merge3 == Torque_Control_ETR07_B.kamm_data
              [(int32_T)Mz]) {
            p = 1.0;
            rtb_alpha_j = Mz;
          } else if (Torque_Control_ETR07_B.Merge3 ==
                     Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j]) {
            p = 1.0;
            Mz = rtb_alpha_j;
          } else {
            if (Torque_Control_ETR07_B.Merge3 ==
                Torque_Control_ETR07_B.kamm_data[(int32_T)k]) {
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
          if (rtb_Subtract1 > Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k])
          {
            my = k;
          } else {
            if (rtb_Subtract1 < Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k])
            {
              My = k;
            }
          }

          k = floor((My + my) / 2.0);
          p = My - my;
          if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My] ==
              rtb_Subtract1) {
            p = 1.0;
            my = My;
          } else if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my] ==
                     rtb_Subtract1) {
            p = 1.0;
            My = my;
          } else {
            if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k] ==
                rtb_Subtract1) {
              p = 1.0;
              My = k;
              my = k;
            }
          }
        }

        if ((Mz == rtb_alpha_j) && (My != my)) {
          kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
          kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
          kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
            (int32_T)rtb_alpha_j];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_alpha_j = b_a[0] * rtb_Subtract1 + b_a[1];
        } else if ((Mz != rtb_alpha_j) && (My == my)) {
          kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)rtb_alpha_j];
          kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
            (int32_T)Mz];
          polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
          rtb_alpha_j = b_a[0] * Torque_Control_ETR07_B.Merge3 + b_a[1];
        } else if ((Mz == rtb_alpha_j) && (My == my)) {
          rtb_alpha_j = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
            (int32_T)Mz];
        } else {
          tmp[0] = 1.0;
          tmp[1] = 1.0;
          tmp[2] = 1.0;
          tmp[3] = 1.0;
          tmp[4] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[5] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
          tmp[6] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          tmp[7] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
          r1 = 17 * (int32_T)my;
          tmp[8] = Torque_Control_ETR07_B.kamm_data[r1];
          r2 = 17 * (int32_T)My;
          tmp[9] = Torque_Control_ETR07_B.kamm_data[r2];
          tmp[10] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
          tmp[11] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
          kamm_data[0] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)
            rtb_alpha_j];
          kamm_data[1] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)
            rtb_alpha_j];
          kamm_data[2] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)Mz];
          kamm_data[3] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)Mz];
          mldivide_u4svSR16(tmp, kamm_data, a);
          rtb_alpha_j = (a[1] * Torque_Control_ETR07_B.Merge3 + a[0]) + a[2] *
            rtb_Subtract1;
        }

        /* Product: '<S126>/Product1' incorporates:
         *  MATLAB Function: '<S126>/Kamm_Circle LatD'
         */
        rtb_Product1_h = rtb_value_g * Torque_Control_ETR07_B.Saturation_i;

        /* MATLAB Function: '<S100>/MATLAB Function2' */
        Torque_Contro_MATLABFunction_d1(Torque_Control_ETR07_B.Constant4,
          rtb_Product1_h, &Torque_Control_ETR07_B.sf_MATLABFunction2_e);

        /* Product: '<S126>/Product2' incorporates:
         *  MATLAB Function: '<S126>/Kamm_Circle LatD'
         */
        rtb_Product2 = rtb_alpha_j * Torque_Control_ETR07_B.Saturation_i;

        /* MATLAB Function: '<S100>/MATLAB Function1' */
        Torque_Contro_MATLABFunction_d1(Torque_Control_ETR07_B.Constant3,
          rtb_Product2, &Torque_Control_ETR07_B.sf_MATLABFunction1_mk);

        /* MATLAB Function: '<S100>/Force Difference with  Max. Tire Forces' */
        if (rtb_Abs1 > 0.0) {
          rtb_alpha_j = Torque_Control_ETR07_B.sf_MATLABFunction1_mk.value;
          rtb_value_g = Torque_Control_ETR07_B.sf_MATLABFunction1_mk.value -
            rtb_Abs1;
          if (rtb_value_g > Torque_Control_ETR07_B.sf_MATLABFunction2_e.value) {
            rtb_value_g = Torque_Control_ETR07_B.sf_MATLABFunction2_e.value;
            rtb_alpha_j = Torque_Control_ETR07_B.sf_MATLABFunction2_e.value +
              rtb_Abs1;
          }
        } else if (rtb_Abs1 < 0.0) {
          rtb_value_g = Torque_Control_ETR07_B.sf_MATLABFunction2_e.value;
          rtb_Abs1 = fabs(rtb_Abs1);
          rtb_alpha_j = Torque_Control_ETR07_B.sf_MATLABFunction2_e.value -
            rtb_Abs1;
          if (rtb_alpha_j > Torque_Control_ETR07_B.sf_MATLABFunction1_mk.value)
          {
            rtb_alpha_j = Torque_Control_ETR07_B.sf_MATLABFunction1_mk.value;
            rtb_value_g = Torque_Control_ETR07_B.sf_MATLABFunction1_mk.value -
              rtb_Abs1;
          }
        } else if (Torque_Control_ETR07_B.sf_MATLABFunction2_e.value >
                   Torque_Control_ETR07_B.sf_MATLABFunction1_mk.value) {
          rtb_alpha_j = Torque_Control_ETR07_B.sf_MATLABFunction1_mk.value;
          rtb_value_g = Torque_Control_ETR07_B.sf_MATLABFunction1_mk.value;
        } else {
          rtb_value_g = Torque_Control_ETR07_B.sf_MATLABFunction2_e.value;
          rtb_alpha_j = Torque_Control_ETR07_B.sf_MATLABFunction2_e.value;
        }

        /* Gain: '<S100>/Gravity1' incorporates:
         *  Sum: '<S100>/Sum'
         *  Sum: '<S100>/Sum1'
         *  Sum: '<S100>/Sum2'
         */
        Torque_Control_ETR07_B.Merge4 = ((Torque_Control_ETR07_B.Merge +
          Torque_Control_ETR07_B.Merge1) + rtb_min) *
          Torque_Control_ETR07_P.Gravity1_Gain;

        /* SignalConversion: '<S100>/OutportBufferForFx_RL ' incorporates:
         *  MATLAB Function: '<S100>/Force Difference with  Max. Tire Forces'
         */
        Torque_Control_ETR07_B.Merge3_e = rtb_alpha_j;

        /* SignalConversion: '<S100>/OutportBufferForFx_RR ' incorporates:
         *  MATLAB Function: '<S100>/Force Difference with  Max. Tire Forces'
         */
        Torque_Control_ETR07_B.Merge2_lx = rtb_value_g;

        /* SignalConversion: '<S100>/OutportBufferForFy_R [N] (0,inf)' incorporates:
         *  MATLAB Function: '<S126>/Kamm_Circle LatD'
         */
        Torque_Control_ETR07_B.Merge6 = rtb_Subtract1;
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          /* SignalConversion: '<S100>/OutportBufferForFlag CarBehavior' incorporates:
           *  Constant: '<S100>/Constant6'
           */
          Torque_Control_ETR07_B.Merge7 =
            Torque_Control_ETR07_P.Constant6_Value_p;
        }

        /* End of Outputs for SubSystem: '<S68>/Lateral Dynamics' */
        break;
      }

      /* End of If: '<S68>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */

      /* MATLAB Function: '<S106>/MATLAB Function1' */
      Torque_Contro_MATLABFunction1_m(Torque_Control_ETR07_B.Constant1_i,
        Torque_Control_ETR07_B.Merge2_lx,
        &Torque_Control_ETR07_B.sf_MATLABFunction1_m);
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        /* Gain: '<S99>/3% difference' incorporates:
         *  Constant: '<S99>/Effective Rolling Radius[inch]'
         *  Gain: '<S99>/inch to m'
         */
        Torque_Control_ETR07_B.udifference_l =
          Torque_Control_ETR07_P.inchtom_Gain *
          Torque_Control_ETR07_P.EffectiveRollingRadiusinch_Valu *
          Torque_Control_ETR07_P.udifference_Gain;
        Torque_Control_ETR07_B.TransmisionRatio_b =
          Torque_Control_ETR07_P.TransmisionRatio_Value;
        Torque_Control_ETR07_B.Constant_b =
          Torque_Control_ETR07_P.Constant_Value_l;
      }

      /* Product: '<S154>/Divide' incorporates:
       *  Constant: '<S106>/Constant'
       *  Constant: '<S99>/Transmision Ratio[-]'
       *  Product: '<S154>/Product'
       */
      Torque_Control_ETR07_B.Divide =
        Torque_Control_ETR07_B.sf_MATLABFunction1_m.value *
        Torque_Control_ETR07_B.udifference_l /
        Torque_Control_ETR07_B.TransmisionRatio_b;

      /* MATLAB Function: '<S106>/MATLAB Function2' */
      Torque_Contro_MATLABFunction1_m(Torque_Control_ETR07_B.Constant_b,
        Torque_Control_ETR07_B.Merge3_e,
        &Torque_Control_ETR07_B.sf_MATLABFunction2);

      /* Product: '<S153>/Divide' incorporates:
       *  Product: '<S153>/Product'
       */
      Torque_Control_ETR07_B.Divide_i =
        Torque_Control_ETR07_B.sf_MATLABFunction2.value *
        Torque_Control_ETR07_B.udifference_l /
        Torque_Control_ETR07_B.TransmisionRatio_b;

      /* Sum: '<S106>/Add' */
      rtb_Subtract1 = Torque_Control_ETR07_B.Divide -
        Torque_Control_ETR07_B.Divide_i;
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        Torque_Control_ETR07_B.Tq_diff_Max =
          Torque_Control_ETR07_P.Tq_diff_Max_Value;
      }

      /* MATLAB Function: '<S97>/Accelerator behaviour ' incorporates:
       *  Constant: '<S99>/Tq_diff_Max'
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       *  Inport: '<Root>/VDC_Apps_Sat_Up'
       */
      Torque_Con_Acceleratorbehaviour(Torque_Control_ETR07_U.APPS1_Value,
        Torque_Control_ETR07_U.VDC_Apps_Sat_Up,
        Torque_Control_ETR07_U.VDC_Apps_Sat_Down,
        &Torque_Control_ETR07_B.sf_Acceleratorbehaviour);

      /* If: '<S97>/Braking Conditions' incorporates:
       *  Inport: '<Root>/BrakeSensor_Value'
       *  Inport: '<S120>/Throttle'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        if ((Torque_Control_ETR07_U.BrakeSensor_Value > 0.0) &&
            (Torque_Control_ETR07_B.sf_Acceleratorbehaviour.throttle < 0.1) &&
            (Torque_Control_ETR07_B.Merge1_a == 1.0)) {
          rtAction = 0;
        } else if ((Torque_Control_ETR07_U.BrakeSensor_Value > 0.0) &&
                   (Torque_Control_ETR07_B.sf_Acceleratorbehaviour.throttle <
                    0.1) && (Torque_Control_ETR07_B.Merge1_a == 0.0)) {
          rtAction = 1;
        } else if ((Torque_Control_ETR07_U.BrakeSensor_Value < 0.1) &&
                   (Torque_Control_ETR07_B.sf_Acceleratorbehaviour.throttle <
                    0.1)) {
          rtAction = 2;
        } else {
          rtAction = 3;
        }

        Torque_Control_ETR07_DW.BrakingConditions_ActiveSubsy_b = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.BrakingConditions_ActiveSubsy_b;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S97>/Regenerative+Mech Braking' incorporates:
         *  ActionPort: '<S124>/Action Port'
         */
        Torque__RegenerativeMechBraking(Torque_Control_ETR07_B.Divide,
          Torque_Control_ETR07_B.Divide_i, &Torque_Control_ETR07_B.Merge_kt,
          &Torque_Control_ETR07_B.Merge1_b);

        /* End of Outputs for SubSystem: '<S97>/Regenerative+Mech Braking' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S97>/Mech_Braking' incorporates:
         *  ActionPort: '<S123>/Action Port'
         */
        Torque_Control_ETR_Mech_Braking(&Torque_Control_ETR07_B.Merge_kt,
          &Torque_Control_ETR07_B.Merge1_b, &Torque_Control_ETR07_P.Mech_Braking);

        /* End of Outputs for SubSystem: '<S97>/Mech_Braking' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S97>/Inertia Braking' incorporates:
         *  ActionPort: '<S122>/Action Port'
         */
        Torque_Control_ETR_Mech_Braking(&Torque_Control_ETR07_B.Merge_kt,
          &Torque_Control_ETR07_B.Merge1_b,
          &Torque_Control_ETR07_P.InertiaBraking);

        /* End of Outputs for SubSystem: '<S97>/Inertia Braking' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S97>/Accelerating' incorporates:
         *  ActionPort: '<S120>/Action Port'
         */
        Torque_Control_ETR07_B.Throttle =
          Torque_Control_ETR07_B.sf_Acceleratorbehaviour.throttle;

        /* Product: '<S120>/Product' incorporates:
         *  Inport: '<S120>/Throttle'
         */
        Torque_Control_ETR07_B.Merge1_b = Torque_Control_ETR07_B.Throttle *
          Torque_Control_ETR07_B.Divide_i;

        /* Product: '<S120>/Product1' */
        Torque_Control_ETR07_B.Merge_kt = Torque_Control_ETR07_B.Throttle *
          Torque_Control_ETR07_B.Divide;

        /* End of Outputs for SubSystem: '<S97>/Accelerating' */
        break;
      }

      /* End of If: '<S97>/Braking Conditions' */

      /* If: '<S96>/If' incorporates:
       *  Inport: '<Root>/BrakeSensor_Value'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        rtAction = (int8_T)!((Torque_Control_ETR07_B.Merge1_a == 1.0) &&
                             (Torque_Control_ETR07_U.BrakeSensor_Value > 0.0));
        Torque_Control_ETR07_DW.If_ActiveSubsystem_aq = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_aq;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S96>/Braking with Regenerative' incorporates:
         *  ActionPort: '<S108>/Action Port'
         */
        /* MATLAB Function: '<S108>/MATLAB Function' incorporates:
         *  Inport: '<Root>/VDC_Max_Regenerative_Torque'
         */
        rtb_Subtract1 = 0.0;
        rtb_Abs1 = 0.0;
        if (!((Torque_Control_ETR07_B.Merge_kt == 0.0) &&
              (Torque_Control_ETR07_B.Merge1_b == 0.0))) {
          if ((Torque_Control_ETR07_B.Merge_kt != 0.0) &&
              (Torque_Control_ETR07_B.Merge1_b == 0.0)) {
            rtb_Abs1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
          } else if ((Torque_Control_ETR07_B.Merge_kt == 0.0) &&
                     (Torque_Control_ETR07_B.Merge1_b != 0.0)) {
            rtb_Subtract1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
          } else if (Torque_Control_ETR07_B.Merge_kt ==
                     Torque_Control_ETR07_B.Merge1_b) {
            if (Torque_Control_ETR07_B.Merge_kt >=
                Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque) {
              rtb_Subtract1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
              rtb_Abs1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
            } else {
              rtb_Subtract1 = Torque_Control_ETR07_B.Merge_kt;
              rtb_Abs1 = Torque_Control_ETR07_B.Merge1_b;
            }
          } else if (Torque_Control_ETR07_B.Merge_kt >
                     Torque_Control_ETR07_B.Merge1_b) {
            if (Torque_Control_ETR07_B.Merge_kt <
                Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque) {
              rtb_Subtract1 = Torque_Control_ETR07_B.Merge1_b *
                Torque_Control_ETR07_B.Merge1_b /
                Torque_Control_ETR07_B.Merge_kt;
              rtb_Abs1 = Torque_Control_ETR07_B.Merge1_b;
            } else {
              rtb_Subtract1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque
                * Torque_Control_ETR07_B.Merge1_b /
                Torque_Control_ETR07_B.Merge_kt;
              rtb_Abs1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
            }
          } else {
            if (Torque_Control_ETR07_B.Merge_kt <
                Torque_Control_ETR07_B.Merge1_b) {
              if (Torque_Control_ETR07_B.Merge1_b <
                  Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque) {
                rtb_Subtract1 = Torque_Control_ETR07_B.Merge_kt;
                rtb_Abs1 = Torque_Control_ETR07_B.Merge_kt *
                  Torque_Control_ETR07_B.Merge_kt /
                  Torque_Control_ETR07_B.Merge1_b;
              } else {
                rtb_Subtract1 =
                  Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
                rtb_Abs1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque *
                  Torque_Control_ETR07_B.Merge_kt /
                  Torque_Control_ETR07_B.Merge1_b;
              }
            }
          }
        }

        /* End of MATLAB Function: '<S108>/MATLAB Function' */

        /* Gain: '<S108>/Gain' */
        Torque_Control_ETR07_B.Merge_c = Torque_Control_ETR07_P.Gain_Gain_l *
          rtb_Subtract1;

        /* Gain: '<S108>/Gain1' */
        Torque_Control_ETR07_B.Merge1_m = Torque_Control_ETR07_P.Gain1_Gain *
          rtb_Abs1;

        /* End of Outputs for SubSystem: '<S96>/Braking with Regenerative' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S96>/Acelerating and braking without Regenerative' incorporates:
         *  ActionPort: '<S107>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          /* Gain: '<S107>/Gain' incorporates:
           *  Constant: '<S107>/rpm'
           */
          Torque_Control_ETR07_B.approx2095_h =
            Torque_Control_ETR07_P.Gain_Gain_co *
            Torque_Control_ETR07_P.rpm_Value;
        }

        /* If: '<S107>/If1' incorporates:
         *  Inport: '<Root>/RL_rads'
         *  Inport: '<Root>/RR_rads'
         */
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          rtAction = (int8_T)!((Torque_Control_ETR07_U.RR_rads >
                                Torque_Control_ETR07_B.approx2095_h) &&
                               (Torque_Control_ETR07_U.RL_rads >
                                Torque_Control_ETR07_B.approx2095_h));
          Torque_Control_ETR07_DW.If1_ActiveSubsystem_bn = rtAction;
        } else {
          rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_bn;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S107>/If Action 1' incorporates:
           *  ActionPort: '<S111>/Action Port'
           */
          Torque_Control_ETR07_IfAction1
            (Torque_Control_ETR07_B.MaximumTransmissionTorqueDyna_b,
             &Torque_Control_ETR07_B.Merge2_j);

          /* End of Outputs for SubSystem: '<S107>/If Action 1' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S107>/If Action 2' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          Torque_Control_ETR07_IfAction2
            (Torque_Control_ETR07_B.MaximumTransmissionTorqueStat_b,
             &Torque_Control_ETR07_B.Merge2_j);

          /* End of Outputs for SubSystem: '<S107>/If Action 2' */
          break;
        }

        /* End of If: '<S107>/If1' */

        /* MATLAB Function: '<S107>/minimum value' */
        Torque_Control_ETR_minimumvalue(Torque_Control_ETR07_B.Merge2_j,
          Torque_Control_ETR07_B.MaximumTorqueperengineNm_m,
          Torque_Control_ETR07_B.Merge_kt,
          &Torque_Control_ETR07_B.sf_minimumvalue);

        /* MATLAB Function: '<S107>/minimum value1' */
        Torque_Control_ET_minimumvalue1(Torque_Control_ETR07_B.Merge2_j,
          Torque_Control_ETR07_B.MaximumTorqueperengineNm_m,
          Torque_Control_ETR07_B.Merge1_b,
          &Torque_Control_ETR07_B.sf_minimumvalue1);

        /* If: '<S107>/If' incorporates:
         *  Inport: '<Root>/Temp_IGBT'
         *  Inport: '<Root>/Temp_Motors'
         *  Inport: '<Root>/VDC_K_Reduction_P'
         *  Inport: '<Root>/VDC_K_Reduction_Temperature'
         *  Inport: '<Root>/VDC_Power_Limit'
         *  Inport: '<S115>/Tq_RL'
         *  Inport: '<S115>/Tq_RR'
         */
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          if ((Torque_Control_ETR07_U.Temp_IGBT >=
               Torque_Control_ETR07_B.LimitTemperatureIGBTC) ||
              (Torque_Control_ETR07_U.Temp_Motors >=
               Torque_Control_ETR07_B.LimitTemperatureMotorC) ||
              (Torque_Control_ETR07_B.Constant_l >=
               Torque_Control_ETR07_B.LimitTemperatureCeldasC)) {
            rtAction = 0;
          } else if (Torque_Control_ETR07_B.Constant_h >=
                     Torque_Control_ETR07_U.VDC_Power_Limit) {
            rtAction = 1;
          } else {
            rtAction = 2;
          }

          Torque_Control_ETR07_DW.If_ActiveSubsystem_f = rtAction;
        } else {
          rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_f;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S107>/Control de Temperatura' incorporates:
           *  ActionPort: '<S110>/Action Port'
           */
          Torque_Con_ControldeTemperatura(Torque_Control_ETR07_M,
            Torque_Control_ETR07_B.sf_minimumvalue.min,
            Torque_Control_ETR07_B.sf_minimumvalue1.min,
            Torque_Control_ETR07_U.VDC_K_Reduction_Temperature, &rtb_Merge,
            &rtb_Merge1, &Torque_Control_ETR07_B.Merge3_h,
            &Torque_Control_ETR07_B.Merge4_b,
            &Torque_Control_ETR07_P.ControldeTemperatura);

          /* End of Outputs for SubSystem: '<S107>/Control de Temperatura' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S107>/Control de Potencia ' incorporates:
           *  ActionPort: '<S109>/Action Port'
           */
          Torque_Con_ControldeTemperatura(Torque_Control_ETR07_M,
            Torque_Control_ETR07_B.sf_minimumvalue.min,
            Torque_Control_ETR07_B.sf_minimumvalue1.min,
            Torque_Control_ETR07_U.VDC_K_Reduction_P, &rtb_Merge, &rtb_Merge1,
            &Torque_Control_ETR07_B.Merge3_h, &Torque_Control_ETR07_B.Merge4_b,
            &Torque_Control_ETR07_P.ControldePotencia);

          /* End of Outputs for SubSystem: '<S107>/Control de Potencia ' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S107>/else' incorporates:
           *  ActionPort: '<S115>/Action Port'
           */
          rtb_Merge = Torque_Control_ETR07_B.sf_minimumvalue.min;
          rtb_Merge1 = Torque_Control_ETR07_B.sf_minimumvalue1.min;
          if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
            /* SignalConversion: '<S115>/OutportBufferForFlag_Temperature' incorporates:
             *  Constant: '<S115>/Constant'
             */
            Torque_Control_ETR07_B.Merge3_h =
              Torque_Control_ETR07_P.Constant_Value_g;

            /* SignalConversion: '<S115>/OutportBufferForFlag_Power' incorporates:
             *  Constant: '<S115>/Constant1'
             */
            Torque_Control_ETR07_B.Merge4_b =
              Torque_Control_ETR07_P.Constant1_Value;
          }

          /* End of Outputs for SubSystem: '<S107>/else' */
          break;
        }

        /* End of If: '<S107>/If' */

        /* MATLAB Function: '<S107>/MATLAB Function' */
        if (rtb_Subtract1 < -Torque_Control_ETR07_B.Tq_diff_Max) {
          rtb_Subtract1 = -Torque_Control_ETR07_B.Tq_diff_Max;
        } else {
          if (rtb_Subtract1 > Torque_Control_ETR07_B.Tq_diff_Max) {
            rtb_Subtract1 = Torque_Control_ETR07_B.Tq_diff_Max;
          }
        }

        /* End of MATLAB Function: '<S107>/MATLAB Function' */

        /* MATLAB Function: '<S114>/MATLAB Function' */
        if ((rtb_Merge == Torque_Control_ETR07_B.Merge_kt) && (rtb_Merge1 ==
             Torque_Control_ETR07_B.Merge1_b)) {
          rtb_Abs1 = rtb_Merge;
          rtb_value_g = rtb_Merge1;
        } else if (Torque_Control_ETR07_B.Merge_kt >
                   Torque_Control_ETR07_B.Merge1_b) {
          rtb_Abs1 = rtb_Merge;
          rtb_value_g = rtb_Merge - fabs(rtb_Subtract1);
          if (rtb_value_g < 0.0) {
            rtb_value_g = 0.0;
          }
        } else if (Torque_Control_ETR07_B.Merge_kt <
                   Torque_Control_ETR07_B.Merge1_b) {
          rtb_value_g = rtb_Merge1;
          rtb_Abs1 = rtb_Merge1 - fabs(rtb_Subtract1);
          if (rtb_Abs1 < 0.0) {
            rtb_Abs1 = 0.0;
          }
        } else {
          rtb_Abs1 = rtb_Merge;
          rtb_value_g = rtb_Merge1;
        }

        /* SignalConversion: '<S107>/OutportBufferForTQ_RL' incorporates:
         *  MATLAB Function: '<S114>/MATLAB Function'
         */
        Torque_Control_ETR07_B.Merge1_m = rtb_value_g;

        /* SignalConversion: '<S107>/OutportBufferForTQ_RR' incorporates:
         *  MATLAB Function: '<S114>/MATLAB Function'
         */
        Torque_Control_ETR07_B.Merge_c = rtb_Abs1;

        /* End of Outputs for SubSystem: '<S96>/Acelerating and braking without Regenerative' */
        break;
      }

      /* End of If: '<S96>/If' */

      /* MATLAB Function: '<S68>/MATLAB Function1' */
      Torque_Control__MATLABFunction1(Torque_Control_ETR07_B.Constant_p,
        Torque_Control_ETR07_B.Divide_i,
        &Torque_Control_ETR07_B.sf_MATLABFunction1_n);

      /* MATLAB Function: '<S68>/MATLAB Function2' */
      Torque_Control__MATLABFunction1(Torque_Control_ETR07_B.Constant_p,
        Torque_Control_ETR07_B.Divide,
        &Torque_Control_ETR07_B.sf_MATLABFunction2_l);

      /* SignalConversion: '<S68>/OutportBufferForCKF_act' */
      Torque_Control_ETR07_B.Merge3_c = Torque_Control_ETR07_B.Saturation_i;

      /* SignalConversion: '<S68>/OutportBufferForFlags_[num5]' */
      Torque_Control_ETR07_B.OutportBufferForFlags_num5[0] =
        Torque_Control_ETR07_B.Merge7;
      Torque_Control_ETR07_B.OutportBufferForFlags_num5[1] =
        Torque_Control_ETR07_B.sf_MATLABFunction1_n.value;
      Torque_Control_ETR07_B.OutportBufferForFlags_num5[2] =
        Torque_Control_ETR07_B.sf_MATLABFunction2_l.value;
      Torque_Control_ETR07_B.OutportBufferForFlags_num5[3] =
        Torque_Control_ETR07_B.Merge3_h;
      Torque_Control_ETR07_B.OutportBufferForFlags_num5[4] =
        Torque_Control_ETR07_B.Merge4_b;

      /* SignalConversion: '<S68>/OutportBufferForSKF_act' */
      Torque_Control_ETR07_B.Merge2_l = Torque_Control_ETR07_B.Saturation_f;

      /* End of Outputs for SubSystem: '<S54>/VDC 2018 Complete' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S54>/VDC 2018 without Longitudinal' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      /* MATLAB Function: '<S162>/MATLAB Function' incorporates:
       *  Inport: '<Root>/RL_rads'
       *  Inport: '<Root>/RR_rads'
       */
      Torque_Control_E_MATLABFunction(Torque_Control_ETR07_U.RL_rads,
        Torque_Control_ETR07_U.RR_rads,
        &Torque_Control_ETR07_B.sf_MATLABFunction_fa);

      /* Derivative: '<S162>/Derivative' */
      if ((Torque_Control_ETR07_DW.TimeStampA_b >=
           Torque_Control_ETR07_M->Timing.t[0]) &&
          (Torque_Control_ETR07_DW.TimeStampB_e >=
           Torque_Control_ETR07_M->Timing.t[0])) {
        rtb_Abs1 = 0.0;
      } else {
        Mz = Torque_Control_ETR07_DW.TimeStampA_b;
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA_e;
        if (Torque_Control_ETR07_DW.TimeStampA_b <
            Torque_Control_ETR07_DW.TimeStampB_e) {
          if (Torque_Control_ETR07_DW.TimeStampB_e <
              Torque_Control_ETR07_M->Timing.t[0]) {
            Mz = Torque_Control_ETR07_DW.TimeStampB_e;
            lastU = &Torque_Control_ETR07_DW.LastUAtTimeB_o;
          }
        } else {
          if (Torque_Control_ETR07_DW.TimeStampA_b >=
              Torque_Control_ETR07_M->Timing.t[0]) {
            Mz = Torque_Control_ETR07_DW.TimeStampB_e;
            lastU = &Torque_Control_ETR07_DW.LastUAtTimeB_o;
          }
        }

        rtb_Abs1 = (Torque_Control_ETR07_B.sf_MATLABFunction_fa.RPM - *lastU) /
          (Torque_Control_ETR07_M->Timing.t[0] - Mz);
      }

      /* End of Derivative: '<S162>/Derivative' */

      /* DataStoreRead: '<S162>/CKF_prev' */
      rtb_CKF_prev_b = Torque_Control_ETR07_DW.B_k;

      /* If: '<S187>/If1' incorporates:
       *  Inport: '<Root>/VDC_CKF_Initial'
       *  Inport: '<Root>/VDC_Cte_SKF'
       */
      rtAction = -1;
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        if (rtb_Abs1 >= 900.0) {
          rtAction = 0;
        } else {
          if (rtb_Abs1 < 900.0) {
            rtAction = 1;
          }
        }

        Torque_Control_ETR07_DW.If1_ActiveSubsystem_a = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_a;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S187>/Spin ' incorporates:
         *  ActionPort: '<S189>/Action Port'
         */
        Torque_Control_ETR07_Spin(Torque_Control_ETR07_M, rtb_CKF_prev_b,
          Torque_Control_ETR07_U.VDC_CKF_Initial,
          Torque_Control_ETR07_U.VDC_Cte_SKF, &Torque_Control_ETR07_B.Merge_g,
          &Torque_Control_ETR07_B.Spin_nb, &Torque_Control_ETR07_P.Spin_nb);

        /* End of Outputs for SubSystem: '<S187>/Spin ' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S187>/No spin' incorporates:
         *  ActionPort: '<S188>/Action Port'
         */
        Torque_Control_ETR07_Nospin(Torque_Control_ETR07_U.VDC_CKF_Initial,
          rtb_CKF_prev_b, &Torque_Control_ETR07_B.Merge_g,
          &Torque_Control_ETR07_B.Nospin_m, &Torque_Control_ETR07_P.Nospin_m);

        /* End of Outputs for SubSystem: '<S187>/No spin' */
        break;
      }

      /* End of If: '<S187>/If1' */

      /* Saturate: '<S187>/Saturation' */
      if (Torque_Control_ETR07_B.Merge_g >
          Torque_Control_ETR07_P.Saturation_UpperSat_i) {
        rtb_Abs1 = Torque_Control_ETR07_P.Saturation_UpperSat_i;
      } else if (Torque_Control_ETR07_B.Merge_g <
                 Torque_Control_ETR07_P.Saturation_LowerSat_c) {
        rtb_Abs1 = Torque_Control_ETR07_P.Saturation_LowerSat_c;
      } else {
        rtb_Abs1 = Torque_Control_ETR07_B.Merge_g;
      }

      /* End of Saturate: '<S187>/Saturation' */

      /* DataStoreWrite: '<S162>/Data Store Write1' */
      Torque_Control_ETR07_DW.B_k = rtb_Abs1;
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        Torque_Control_ETR07_B.MaximumTorqueperengineNm =
          Torque_Control_ETR07_P.MaximumTorqueperengineNm_Valu_b;
        Torque_Control_ETR07_B.MaximumTransmissionTorqueDynami =
          Torque_Control_ETR07_P.MaximumTransmissionTorqueDyna_a;
        Torque_Control_ETR07_B.MaximumTransmissionTorqueStatic =
          Torque_Control_ETR07_P.MaximumTransmissionTorqueStat_n;
        Torque_Control_ETR07_B.Constant_e =
          Torque_Control_ETR07_P.Constant_Value_ib;
        Torque_Control_ETR07_B.Constant1 =
          Torque_Control_ETR07_P.Constant1_Value_c;
      }

      /* Gain: '<S161>/Fy per wheel' incorporates:
       *  Constant: '<S159>/Maximum Torque per engine [Nm]'
       *  Constant: '<S159>/Maximum Transmission Torque Dynamic [Nm]'
       *  Constant: '<S159>/Maximum Transmission Torque Static [Nm]'
       *  Constant: '<S160>/Constant1'
       *  Constant: '<S164>/Constant'
       *  Gain: '<S161>/Gravity1'
       *  Product: '<S161>/Product'
       *  Sum: '<S161>/Sum1'
       */
      rtb_Subtract1 = (Torque_Control_ETR07_B.Merge2 +
                       Torque_Control_ETR07_B.Merge3) *
        Torque_Control_ETR07_P.Gravity1_Gain_g * rtb_Subtract1 *
        Torque_Control_ETR07_P.Fyperwheel_Gain_e;

      /* MATLAB Function: '<S160>/Kamm_Circle LatD' */
      Torque_Control_ETR07_B.kamm_data[0] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[17] = 0.0;
      Torque_Control_ETR07_B.kamm_data[34] = 100.0;
      Torque_Control_ETR07_B.kamm_data[51] = 200.0;
      Torque_Control_ETR07_B.kamm_data[68] = 300.0;
      Torque_Control_ETR07_B.kamm_data[85] = 400.0;
      Torque_Control_ETR07_B.kamm_data[102] = 500.0;
      Torque_Control_ETR07_B.kamm_data[119] = 600.0;
      Torque_Control_ETR07_B.kamm_data[136] = 700.0;
      Torque_Control_ETR07_B.kamm_data[153] = 800.0;
      Torque_Control_ETR07_B.kamm_data[170] = 900.0;
      Torque_Control_ETR07_B.kamm_data[187] = 1000.0;
      Torque_Control_ETR07_B.kamm_data[204] = 1100.0;
      Torque_Control_ETR07_B.kamm_data[221] = 1200.0;
      Torque_Control_ETR07_B.kamm_data[238] = 1300.0;
      Torque_Control_ETR07_B.kamm_data[255] = 1400.0;
      Torque_Control_ETR07_B.kamm_data[272] = 1500.0;
      Torque_Control_ETR07_B.kamm_data[289] = 1600.0;
      Torque_Control_ETR07_B.kamm_data[306] = 1700.0;
      Torque_Control_ETR07_B.kamm_data[323] = 1800.0;
      Torque_Control_ETR07_B.kamm_data[340] = 1900.0;
      Torque_Control_ETR07_B.kamm_data[357] = 2000.0;
      Torque_Control_ETR07_B.kamm_data[374] = 2100.0;
      Torque_Control_ETR07_B.kamm_data[391] = 2200.0;
      Torque_Control_ETR07_B.kamm_data[408] = 2300.0;
      Torque_Control_ETR07_B.kamm_data[425] = 2400.0;
      Torque_Control_ETR07_B.kamm_data[442] = 2500.0;
      Torque_Control_ETR07_B.kamm_data[459] = 2600.0;
      Torque_Control_ETR07_B.kamm_data[476] = 2700.0;
      Torque_Control_ETR07_B.kamm_data[493] = 2800.0;
      Torque_Control_ETR07_B.kamm_data[510] = 2900.0;
      Torque_Control_ETR07_B.kamm_data[527] = 3000.0;
      Torque_Control_ETR07_B.kamm_data[1] = 0.0;
      Torque_Control_ETR07_B.kamm_data[18] = 0.0;
      Torque_Control_ETR07_B.kamm_data[35] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[52] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[69] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[86] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[103] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[120] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[137] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[154] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[171] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[188] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[205] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[222] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[239] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[256] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[273] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[290] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[307] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[324] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[341] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[358] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[375] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[392] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[409] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[426] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[443] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[460] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[477] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[494] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[511] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[528] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[2] = 100.0;
      Torque_Control_ETR07_B.kamm_data[19] = 350.0;
      Torque_Control_ETR07_B.kamm_data[36] = 340.0;
      Torque_Control_ETR07_B.kamm_data[53] = 156.0;
      Torque_Control_ETR07_B.kamm_data[70] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[87] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[104] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[121] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[138] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[155] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[172] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[189] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[206] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[223] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[240] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[257] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[274] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[291] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[308] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[325] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[342] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[359] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[376] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[393] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[410] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[427] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[444] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[461] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[478] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[495] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[512] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[529] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[3] = 200.0;
      Torque_Control_ETR07_B.kamm_data[20] = 688.0;
      Torque_Control_ETR07_B.kamm_data[37] = 676.0;
      Torque_Control_ETR07_B.kamm_data[54] = 654.0;
      Torque_Control_ETR07_B.kamm_data[71] = 573.0;
      Torque_Control_ETR07_B.kamm_data[88] = 269.0;
      Torque_Control_ETR07_B.kamm_data[105] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[122] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[139] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[156] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[173] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[190] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[207] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[224] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[241] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[258] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[275] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[292] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[309] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[326] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[343] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[360] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[377] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[394] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[411] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[428] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[445] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[462] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[479] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[496] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[513] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[530] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[4] = 300.0;
      Torque_Control_ETR07_B.kamm_data[21] = 1002.0;
      Torque_Control_ETR07_B.kamm_data[38] = 994.0;
      Torque_Control_ETR07_B.kamm_data[55] = 982.0;
      Torque_Control_ETR07_B.kamm_data[72] = 959.0;
      Torque_Control_ETR07_B.kamm_data[89] = 888.0;
      Torque_Control_ETR07_B.kamm_data[106] = 694.0;
      Torque_Control_ETR07_B.kamm_data[123] = 345.0;
      Torque_Control_ETR07_B.kamm_data[140] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[157] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[174] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[191] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[208] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[225] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[242] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[259] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[276] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[293] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[310] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[327] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[344] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[361] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[378] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[395] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[412] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[429] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[446] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[463] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[480] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[497] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[514] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[531] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[5] = 400.0;
      Torque_Control_ETR07_B.kamm_data[22] = 1295.0;
      Torque_Control_ETR07_B.kamm_data[39] = 1288.0;
      Torque_Control_ETR07_B.kamm_data[56] = 1280.0;
      Torque_Control_ETR07_B.kamm_data[73] = 1263.0;
      Torque_Control_ETR07_B.kamm_data[90] = 1235.0;
      Torque_Control_ETR07_B.kamm_data[107] = 1168.0;
      Torque_Control_ETR07_B.kamm_data[124] = 1001.0;
      Torque_Control_ETR07_B.kamm_data[141] = 740.0;
      Torque_Control_ETR07_B.kamm_data[158] = 389.0;
      Torque_Control_ETR07_B.kamm_data[175] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[192] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[209] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[226] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[243] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[260] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[277] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[294] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[311] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[328] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[345] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[362] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[379] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[396] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[413] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[430] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[447] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[464] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[481] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[498] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[515] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[532] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[6] = 500.0;
      Torque_Control_ETR07_B.kamm_data[23] = 1536.0;
      Torque_Control_ETR07_B.kamm_data[40] = 1529.0;
      Torque_Control_ETR07_B.kamm_data[57] = 1521.0;
      Torque_Control_ETR07_B.kamm_data[74] = 1509.0;
      Torque_Control_ETR07_B.kamm_data[91] = 1491.0;
      Torque_Control_ETR07_B.kamm_data[108] = 1459.0;
      Torque_Control_ETR07_B.kamm_data[125] = 1395.0;
      Torque_Control_ETR07_B.kamm_data[142] = 1230.0;
      Torque_Control_ETR07_B.kamm_data[159] = 1032.0;
      Torque_Control_ETR07_B.kamm_data[176] = 760.0;
      Torque_Control_ETR07_B.kamm_data[193] = 411.0;
      Torque_Control_ETR07_B.kamm_data[210] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[227] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[244] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[261] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[278] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[295] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[312] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[329] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[346] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[363] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[380] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[397] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[414] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[431] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[448] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[465] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[482] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[499] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[516] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[533] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[7] = 600.0;
      Torque_Control_ETR07_B.kamm_data[24] = 1745.0;
      Torque_Control_ETR07_B.kamm_data[41] = 1737.0;
      Torque_Control_ETR07_B.kamm_data[58] = 1729.0;
      Torque_Control_ETR07_B.kamm_data[75] = 1721.0;
      Torque_Control_ETR07_B.kamm_data[92] = 1704.0;
      Torque_Control_ETR07_B.kamm_data[109] = 1686.0;
      Torque_Control_ETR07_B.kamm_data[126] = 1649.0;
      Torque_Control_ETR07_B.kamm_data[143] = 1585.0;
      Torque_Control_ETR07_B.kamm_data[160] = 1455.0;
      Torque_Control_ETR07_B.kamm_data[177] = 1270.0;
      Torque_Control_ETR07_B.kamm_data[194] = 1038.0;
      Torque_Control_ETR07_B.kamm_data[211] = 756.0;
      Torque_Control_ETR07_B.kamm_data[228] = 419.0;
      Torque_Control_ETR07_B.kamm_data[245] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[262] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[279] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[296] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[313] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[330] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[347] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[364] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[381] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[398] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[415] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[432] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[449] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[466] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[483] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[500] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[517] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[534] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[8] = 700.0;
      Torque_Control_ETR07_B.kamm_data[25] = 1964.0;
      Torque_Control_ETR07_B.kamm_data[42] = 1956.0;
      Torque_Control_ETR07_B.kamm_data[59] = 1948.0;
      Torque_Control_ETR07_B.kamm_data[76] = 1940.0;
      Torque_Control_ETR07_B.kamm_data[93] = 1926.0;
      Torque_Control_ETR07_B.kamm_data[110] = 1909.0;
      Torque_Control_ETR07_B.kamm_data[127] = 1884.0;
      Torque_Control_ETR07_B.kamm_data[144] = 1848.0;
      Torque_Control_ETR07_B.kamm_data[161] = 1777.0;
      Torque_Control_ETR07_B.kamm_data[178] = 1656.0;
      Torque_Control_ETR07_B.kamm_data[195] = 1484.0;
      Torque_Control_ETR07_B.kamm_data[212] = 1278.0;
      Torque_Control_ETR07_B.kamm_data[229] = 1029.0;
      Torque_Control_ETR07_B.kamm_data[246] = 742.0;
      Torque_Control_ETR07_B.kamm_data[263] = 416.0;
      Torque_Control_ETR07_B.kamm_data[280] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[297] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[314] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[331] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[348] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[365] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[382] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[399] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[416] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[433] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[450] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[467] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[484] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[501] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[518] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[535] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[9] = 800.0;
      Torque_Control_ETR07_B.kamm_data[26] = 2212.0;
      Torque_Control_ETR07_B.kamm_data[43] = 2204.0;
      Torque_Control_ETR07_B.kamm_data[60] = 2195.0;
      Torque_Control_ETR07_B.kamm_data[77] = 2187.0;
      Torque_Control_ETR07_B.kamm_data[94] = 2175.0;
      Torque_Control_ETR07_B.kamm_data[111] = 2158.0;
      Torque_Control_ETR07_B.kamm_data[128] = 2141.0;
      Torque_Control_ETR07_B.kamm_data[145] = 2107.0;
      Torque_Control_ETR07_B.kamm_data[162] = 2063.0;
      Torque_Control_ETR07_B.kamm_data[179] = 1990.0;
      Torque_Control_ETR07_B.kamm_data[196] = 1868.0;
      Torque_Control_ETR07_B.kamm_data[213] = 1704.0;
      Torque_Control_ETR07_B.kamm_data[230] = 1505.0;
      Torque_Control_ETR07_B.kamm_data[247] = 1275.0;
      Torque_Control_ETR07_B.kamm_data[264] = 1018.0;
      Torque_Control_ETR07_B.kamm_data[281] = 730.0;
      Torque_Control_ETR07_B.kamm_data[298] = 404.0;
      Torque_Control_ETR07_B.kamm_data[315] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[332] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[349] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[366] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[383] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[400] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[417] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[434] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[451] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[468] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[485] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[502] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[519] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[536] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[10] = 900.0;
      Torque_Control_ETR07_B.kamm_data[27] = 2465.0;
      Torque_Control_ETR07_B.kamm_data[44] = 2456.0;
      Torque_Control_ETR07_B.kamm_data[61] = 2448.0;
      Torque_Control_ETR07_B.kamm_data[78] = 2439.0;
      Torque_Control_ETR07_B.kamm_data[95] = 2428.0;
      Torque_Control_ETR07_B.kamm_data[112] = 2411.0;
      Torque_Control_ETR07_B.kamm_data[129] = 2394.0;
      Torque_Control_ETR07_B.kamm_data[146] = 2367.0;
      Torque_Control_ETR07_B.kamm_data[163] = 2333.0;
      Torque_Control_ETR07_B.kamm_data[180] = 2279.0;
      Torque_Control_ETR07_B.kamm_data[197] = 2200.0;
      Torque_Control_ETR07_B.kamm_data[214] = 2081.0;
      Torque_Control_ETR07_B.kamm_data[231] = 1921.0;
      Torque_Control_ETR07_B.kamm_data[248] = 1729.0;
      Torque_Control_ETR07_B.kamm_data[265] = 1512.0;
      Torque_Control_ETR07_B.kamm_data[282] = 1268.0;
      Torque_Control_ETR07_B.kamm_data[299] = 1002.0;
      Torque_Control_ETR07_B.kamm_data[316] = 711.0;
      Torque_Control_ETR07_B.kamm_data[333] = 345.0;
      Torque_Control_ETR07_B.kamm_data[350] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[367] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[384] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[401] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[418] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[435] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[452] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[469] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[486] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[503] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[520] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[537] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[11] = 1000.0;
      Torque_Control_ETR07_B.kamm_data[28] = 2684.0;
      Torque_Control_ETR07_B.kamm_data[45] = 2675.0;
      Torque_Control_ETR07_B.kamm_data[62] = 2666.0;
      Torque_Control_ETR07_B.kamm_data[79] = 2657.0;
      Torque_Control_ETR07_B.kamm_data[96] = 2647.0;
      Torque_Control_ETR07_B.kamm_data[113] = 2629.0;
      Torque_Control_ETR07_B.kamm_data[130] = 2612.0;
      Torque_Control_ETR07_B.kamm_data[147] = 2592.0;
      Torque_Control_ETR07_B.kamm_data[164] = 2558.0;
      Torque_Control_ETR07_B.kamm_data[181] = 2520.0;
      Torque_Control_ETR07_B.kamm_data[198] = 2462.0;
      Torque_Control_ETR07_B.kamm_data[215] = 2378.0;
      Torque_Control_ETR07_B.kamm_data[232] = 2262.0;
      Torque_Control_ETR07_B.kamm_data[249] = 2119.0;
      Torque_Control_ETR07_B.kamm_data[266] = 1940.0;
      Torque_Control_ETR07_B.kamm_data[283] = 1737.0;
      Torque_Control_ETR07_B.kamm_data[300] = 1508.0;
      Torque_Control_ETR07_B.kamm_data[317] = 1259.0;
      Torque_Control_ETR07_B.kamm_data[334] = 989.0;
      Torque_Control_ETR07_B.kamm_data[351] = 680.0;
      Torque_Control_ETR07_B.kamm_data[368] = 240.0;
      Torque_Control_ETR07_B.kamm_data[385] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[402] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[419] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[436] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[453] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[470] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[487] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[504] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[521] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[538] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[12] = 1100.0;
      Torque_Control_ETR07_B.kamm_data[29] = 2853.0;
      Torque_Control_ETR07_B.kamm_data[46] = 2843.0;
      Torque_Control_ETR07_B.kamm_data[63] = 2833.0;
      Torque_Control_ETR07_B.kamm_data[80] = 2822.0;
      Torque_Control_ETR07_B.kamm_data[97] = 2811.0;
      Torque_Control_ETR07_B.kamm_data[114] = 2795.0;
      Torque_Control_ETR07_B.kamm_data[131] = 2775.0;
      Torque_Control_ETR07_B.kamm_data[148] = 2755.0;
      Torque_Control_ETR07_B.kamm_data[165] = 2728.0;
      Torque_Control_ETR07_B.kamm_data[182] = 2693.0;
      Torque_Control_ETR07_B.kamm_data[199] = 2651.0;
      Torque_Control_ETR07_B.kamm_data[216] = 2591.0;
      Torque_Control_ETR07_B.kamm_data[233] = 2510.0;
      Torque_Control_ETR07_B.kamm_data[250] = 2412.0;
      Torque_Control_ETR07_B.kamm_data[267] = 2282.0;
      Torque_Control_ETR07_B.kamm_data[284] = 2124.0;
      Torque_Control_ETR07_B.kamm_data[301] = 1940.0;
      Torque_Control_ETR07_B.kamm_data[318] = 1735.0;
      Torque_Control_ETR07_B.kamm_data[335] = 1504.0;
      Torque_Control_ETR07_B.kamm_data[352] = 1250.0;
      Torque_Control_ETR07_B.kamm_data[369] = 962.0;
      Torque_Control_ETR07_B.kamm_data[386] = 608.0;
      Torque_Control_ETR07_B.kamm_data[403] = 108.0;
      Torque_Control_ETR07_B.kamm_data[420] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[437] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[454] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[471] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[488] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[505] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[522] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[539] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[13] = 1200.0;
      Torque_Control_ETR07_B.kamm_data[30] = 2999.0;
      Torque_Control_ETR07_B.kamm_data[47] = 2988.0;
      Torque_Control_ETR07_B.kamm_data[64] = 2976.0;
      Torque_Control_ETR07_B.kamm_data[81] = 2964.0;
      Torque_Control_ETR07_B.kamm_data[98] = 2952.0;
      Torque_Control_ETR07_B.kamm_data[115] = 2936.0;
      Torque_Control_ETR07_B.kamm_data[132] = 2914.0;
      Torque_Control_ETR07_B.kamm_data[149] = 2893.0;
      Torque_Control_ETR07_B.kamm_data[166] = 2872.0;
      Torque_Control_ETR07_B.kamm_data[183] = 2837.0;
      Torque_Control_ETR07_B.kamm_data[200] = 2799.0;
      Torque_Control_ETR07_B.kamm_data[217] = 2755.0;
      Torque_Control_ETR07_B.kamm_data[234] = 2694.0;
      Torque_Control_ETR07_B.kamm_data[251] = 2619.0;
      Torque_Control_ETR07_B.kamm_data[268] = 2527.0;
      Torque_Control_ETR07_B.kamm_data[285] = 2412.0;
      Torque_Control_ETR07_B.kamm_data[302] = 2275.0;
      Torque_Control_ETR07_B.kamm_data[319] = 2114.0;
      Torque_Control_ETR07_B.kamm_data[336] = 1936.0;
      Torque_Control_ETR07_B.kamm_data[353] = 1729.0;
      Torque_Control_ETR07_B.kamm_data[370] = 1507.0;
      Torque_Control_ETR07_B.kamm_data[387] = 1233.0;
      Torque_Control_ETR07_B.kamm_data[404] = 896.0;
      Torque_Control_ETR07_B.kamm_data[421] = 461.0;
      Torque_Control_ETR07_B.kamm_data[438] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[455] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[472] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[489] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[506] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[523] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[540] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[14] = 1300.0;
      Torque_Control_ETR07_B.kamm_data[31] = 3128.0;
      Torque_Control_ETR07_B.kamm_data[48] = 3115.0;
      Torque_Control_ETR07_B.kamm_data[65] = 3101.0;
      Torque_Control_ETR07_B.kamm_data[82] = 3087.0;
      Torque_Control_ETR07_B.kamm_data[99] = 3074.0;
      Torque_Control_ETR07_B.kamm_data[116] = 3059.0;
      Torque_Control_ETR07_B.kamm_data[133] = 3035.0;
      Torque_Control_ETR07_B.kamm_data[150] = 3012.0;
      Torque_Control_ETR07_B.kamm_data[167] = 2988.0;
      Torque_Control_ETR07_B.kamm_data[184] = 2962.0;
      Torque_Control_ETR07_B.kamm_data[201] = 2923.0;
      Torque_Control_ETR07_B.kamm_data[218] = 2884.0;
      Torque_Control_ETR07_B.kamm_data[235] = 2838.0;
      Torque_Control_ETR07_B.kamm_data[252] = 2778.0;
      Torque_Control_ETR07_B.kamm_data[269] = 2709.0;
      Torque_Control_ETR07_B.kamm_data[286] = 2625.0;
      Torque_Control_ETR07_B.kamm_data[303] = 2517.0;
      Torque_Control_ETR07_B.kamm_data[320] = 2396.0;
      Torque_Control_ETR07_B.kamm_data[337] = 2259.0;
      Torque_Control_ETR07_B.kamm_data[354] = 2104.0;
      Torque_Control_ETR07_B.kamm_data[371] = 1924.0;
      Torque_Control_ETR07_B.kamm_data[388] = 1730.0;
      Torque_Control_ETR07_B.kamm_data[405] = 1484.0;
      Torque_Control_ETR07_B.kamm_data[422] = 1169.0;
      Torque_Control_ETR07_B.kamm_data[439] = 772.0;
      Torque_Control_ETR07_B.kamm_data[456] = 213.0;
      Torque_Control_ETR07_B.kamm_data[473] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[490] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[507] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[524] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[541] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[15] = 1400.0;
      Torque_Control_ETR07_B.kamm_data[32] = 3228.0;
      Torque_Control_ETR07_B.kamm_data[49] = 3215.0;
      Torque_Control_ETR07_B.kamm_data[66] = 3201.0;
      Torque_Control_ETR07_B.kamm_data[83] = 3187.0;
      Torque_Control_ETR07_B.kamm_data[100] = 3172.0;
      Torque_Control_ETR07_B.kamm_data[117] = 3157.0;
      Torque_Control_ETR07_B.kamm_data[134] = 3134.0;
      Torque_Control_ETR07_B.kamm_data[151] = 3111.0;
      Torque_Control_ETR07_B.kamm_data[168] = 3087.0;
      Torque_Control_ETR07_B.kamm_data[185] = 3063.0;
      Torque_Control_ETR07_B.kamm_data[202] = 3026.0;
      Torque_Control_ETR07_B.kamm_data[219] = 2989.0;
      Torque_Control_ETR07_B.kamm_data[236] = 2952.0;
      Torque_Control_ETR07_B.kamm_data[253] = 2896.0;
      Torque_Control_ETR07_B.kamm_data[270] = 2841.0;
      Torque_Control_ETR07_B.kamm_data[287] = 2772.0;
      Torque_Control_ETR07_B.kamm_data[304] = 2691.0;
      Torque_Control_ETR07_B.kamm_data[321] = 2603.0;
      Torque_Control_ETR07_B.kamm_data[338] = 2500.0;
      Torque_Control_ETR07_B.kamm_data[355] = 2379.0;
      Torque_Control_ETR07_B.kamm_data[372] = 2243.0;
      Torque_Control_ETR07_B.kamm_data[389] = 2091.0;
      Torque_Control_ETR07_B.kamm_data[406] = 1927.0;
      Torque_Control_ETR07_B.kamm_data[423] = 1713.0;
      Torque_Control_ETR07_B.kamm_data[440] = 1414.0;
      Torque_Control_ETR07_B.kamm_data[457] = 1030.0;
      Torque_Control_ETR07_B.kamm_data[474] = 553.0;
      Torque_Control_ETR07_B.kamm_data[491] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[508] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[525] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[542] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[16] = 1500.0;
      Torque_Control_ETR07_B.kamm_data[33] = 3327.0;
      Torque_Control_ETR07_B.kamm_data[50] = 3312.0;
      Torque_Control_ETR07_B.kamm_data[67] = 3296.0;
      Torque_Control_ETR07_B.kamm_data[84] = 3280.0;
      Torque_Control_ETR07_B.kamm_data[101] = 3263.0;
      Torque_Control_ETR07_B.kamm_data[118] = 3247.0;
      Torque_Control_ETR07_B.kamm_data[135] = 3223.0;
      Torque_Control_ETR07_B.kamm_data[152] = 3198.0;
      Torque_Control_ETR07_B.kamm_data[169] = 3173.0;
      Torque_Control_ETR07_B.kamm_data[186] = 3147.0;
      Torque_Control_ETR07_B.kamm_data[203] = 3116.0;
      Torque_Control_ETR07_B.kamm_data[220] = 3078.0;
      Torque_Control_ETR07_B.kamm_data[237] = 3040.0;
      Torque_Control_ETR07_B.kamm_data[254] = 3001.0;
      Torque_Control_ETR07_B.kamm_data[271] = 2947.0;
      Torque_Control_ETR07_B.kamm_data[288] = 2893.0;
      Torque_Control_ETR07_B.kamm_data[305] = 2828.0;
      Torque_Control_ETR07_B.kamm_data[322] = 2756.0;
      Torque_Control_ETR07_B.kamm_data[339] = 2670.0;
      Torque_Control_ETR07_B.kamm_data[356] = 2576.0;
      Torque_Control_ETR07_B.kamm_data[373] = 2471.0;
      Torque_Control_ETR07_B.kamm_data[390] = 2353.0;
      Torque_Control_ETR07_B.kamm_data[407] = 2228.0;
      Torque_Control_ETR07_B.kamm_data[424] = 2100.0;
      Torque_Control_ETR07_B.kamm_data[441] = 1921.0;
      Torque_Control_ETR07_B.kamm_data[458] = 1649.0;
      Torque_Control_ETR07_B.kamm_data[475] = 1278.0;
      Torque_Control_ETR07_B.kamm_data[492] = 814.0;
      Torque_Control_ETR07_B.kamm_data[509] = 217.0;
      Torque_Control_ETR07_B.kamm_data[526] = (rtNaN);
      Torque_Control_ETR07_B.kamm_data[543] = (rtNaN);
      rtb_alpha_j = 1.0;
      Mz = 16.0;
      k = 8.0;
      p = 15.0;
      while (p != 1.0) {
        if (Torque_Control_ETR07_B.Merge2 > Torque_Control_ETR07_B.kamm_data
            [(int32_T)k]) {
          rtb_alpha_j = k;
        } else {
          if (Torque_Control_ETR07_B.Merge2 < Torque_Control_ETR07_B.kamm_data
              [(int32_T)k]) {
            Mz = k;
          }
        }

        k = floor((Mz + rtb_alpha_j) / 2.0);
        p = Mz - rtb_alpha_j;
        if (Torque_Control_ETR07_B.Merge2 == Torque_Control_ETR07_B.kamm_data
            [(int32_T)Mz]) {
          p = 1.0;
          rtb_alpha_j = Mz;
        } else if (Torque_Control_ETR07_B.Merge2 ==
                   Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j]) {
          p = 1.0;
          Mz = rtb_alpha_j;
        } else {
          if (Torque_Control_ETR07_B.Merge2 == Torque_Control_ETR07_B.kamm_data
              [(int32_T)k]) {
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
        if (rtb_Subtract1 > Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k]) {
          my = k;
        } else {
          if (rtb_Subtract1 < Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k])
          {
            My = k;
          }
        }

        k = floor((My + my) / 2.0);
        p = My - my;
        if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My] == rtb_Subtract1)
        {
          p = 1.0;
          my = My;
        } else if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my] ==
                   rtb_Subtract1) {
          p = 1.0;
          My = my;
        } else {
          if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k] == rtb_Subtract1)
          {
            p = 1.0;
            My = k;
            my = k;
          }
        }
      }

      if ((Mz == rtb_alpha_j) && (My != my)) {
        kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
        kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
        kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
          (int32_T)rtb_alpha_j];
        kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
          (int32_T)rtb_alpha_j];
        polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
        rtb_value_g = b_a[0] * rtb_Subtract1 + b_a[1];
      } else if ((Mz != rtb_alpha_j) && (My == my)) {
        kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
        kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
        kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
          (int32_T)rtb_alpha_j];
        kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
          (int32_T)Mz];
        polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
        rtb_value_g = b_a[0] * Torque_Control_ETR07_B.Merge2 + b_a[1];
      } else if ((Mz == rtb_alpha_j) && (My == my)) {
        rtb_value_g = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
          (int32_T)Mz];
      } else {
        tmp[0] = 1.0;
        tmp[1] = 1.0;
        tmp[2] = 1.0;
        tmp[3] = 1.0;
        tmp[4] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
        tmp[5] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
        tmp[6] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
        tmp[7] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
        r1 = 17 * (int32_T)my;
        tmp[8] = Torque_Control_ETR07_B.kamm_data[r1];
        r2 = 17 * (int32_T)My;
        tmp[9] = Torque_Control_ETR07_B.kamm_data[r2];
        tmp[10] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
        tmp[11] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
        kamm_data[0] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)
          rtb_alpha_j];
        kamm_data[1] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)
          rtb_alpha_j];
        kamm_data[2] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)Mz];
        kamm_data[3] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)Mz];
        mldivide_u4svSR16(tmp, kamm_data, a);
        rtb_value_g = (a[1] * Torque_Control_ETR07_B.Merge2 + a[0]) + a[2] *
          rtb_Subtract1;
      }

      rtb_alpha_j = 1.0;
      Mz = 16.0;
      k = 8.0;
      p = 15.0;
      while (p != 1.0) {
        if (Torque_Control_ETR07_B.Merge3 > Torque_Control_ETR07_B.kamm_data
            [(int32_T)k]) {
          rtb_alpha_j = k;
        } else {
          if (Torque_Control_ETR07_B.Merge3 < Torque_Control_ETR07_B.kamm_data
              [(int32_T)k]) {
            Mz = k;
          }
        }

        k = floor((Mz + rtb_alpha_j) / 2.0);
        p = Mz - rtb_alpha_j;
        if (Torque_Control_ETR07_B.Merge3 == Torque_Control_ETR07_B.kamm_data
            [(int32_T)Mz]) {
          p = 1.0;
          rtb_alpha_j = Mz;
        } else if (Torque_Control_ETR07_B.Merge3 ==
                   Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j]) {
          p = 1.0;
          Mz = rtb_alpha_j;
        } else {
          if (Torque_Control_ETR07_B.Merge3 == Torque_Control_ETR07_B.kamm_data
              [(int32_T)k]) {
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
        if (rtb_Subtract1 > Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k]) {
          my = k;
        } else {
          if (rtb_Subtract1 < Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k])
          {
            My = k;
          }
        }

        k = floor((My + my) / 2.0);
        p = My - my;
        if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My] == rtb_Subtract1)
        {
          p = 1.0;
          my = My;
        } else if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my] ==
                   rtb_Subtract1) {
          p = 1.0;
          My = my;
        } else {
          if (Torque_Control_ETR07_B.kamm_data[17 * (int32_T)k] == rtb_Subtract1)
          {
            p = 1.0;
            My = k;
            my = k;
          }
        }
      }

      if ((Mz == rtb_alpha_j) && (My != my)) {
        kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
        kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
        kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
          (int32_T)rtb_alpha_j];
        kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
          (int32_T)rtb_alpha_j];
        polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
        rtb_alpha_j = b_a[0] * rtb_Subtract1 + b_a[1];
      } else if ((Mz != rtb_alpha_j) && (My == my)) {
        kamm_data_0[0] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
        kamm_data_0[1] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
        kamm_data_1[0] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
          (int32_T)rtb_alpha_j];
        kamm_data_1[1] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my +
          (int32_T)Mz];
        polyfit_vYlRX3XP(kamm_data_0, kamm_data_1, b_a);
        rtb_alpha_j = b_a[0] * Torque_Control_ETR07_B.Merge3 + b_a[1];
      } else if ((Mz == rtb_alpha_j) && (My == my)) {
        rtb_alpha_j = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My +
          (int32_T)Mz];
      } else {
        tmp[0] = 1.0;
        tmp[1] = 1.0;
        tmp[2] = 1.0;
        tmp[3] = 1.0;
        tmp[4] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
        tmp[5] = Torque_Control_ETR07_B.kamm_data[(int32_T)rtb_alpha_j];
        tmp[6] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
        tmp[7] = Torque_Control_ETR07_B.kamm_data[(int32_T)Mz];
        r1 = 17 * (int32_T)my;
        tmp[8] = Torque_Control_ETR07_B.kamm_data[r1];
        r2 = 17 * (int32_T)My;
        tmp[9] = Torque_Control_ETR07_B.kamm_data[r2];
        tmp[10] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)my];
        tmp[11] = Torque_Control_ETR07_B.kamm_data[17 * (int32_T)My];
        kamm_data[0] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)
          rtb_alpha_j];
        kamm_data[1] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)
          rtb_alpha_j];
        kamm_data[2] = Torque_Control_ETR07_B.kamm_data[r1 + (int32_T)Mz];
        kamm_data[3] = Torque_Control_ETR07_B.kamm_data[r2 + (int32_T)Mz];
        mldivide_u4svSR16(tmp, kamm_data, a);
        rtb_alpha_j = (a[1] * Torque_Control_ETR07_B.Merge3 + a[0]) + a[2] *
          rtb_Subtract1;
      }

      /* Product: '<S160>/Product' incorporates:
       *  MATLAB Function: '<S160>/Kamm_Circle LatD'
       */
      rtb_Product_c = rtb_value_g * rtb_Abs1;

      /* MATLAB Function: '<S160>/MATLAB Function2' */
      Torque_Contro_MATLABFunction_d1(Torque_Control_ETR07_B.Constant1,
        rtb_Product_c, &Torque_Control_ETR07_B.sf_MATLABFunction2_b);

      /* MATLAB Function: '<S164>/MATLAB Function2' */
      Torque_Contro_MATLABFunction_d1(Torque_Control_ETR07_B.Constant_e,
        Torque_Control_ETR07_B.sf_MATLABFunction2_b.value,
        &Torque_Control_ETR07_B.sf_MATLABFunction2_m);
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        /* Gain: '<S159>/3% difference' incorporates:
         *  Constant: '<S159>/Effective Rolling Radius[inch]'
         *  Gain: '<S159>/inch to m'
         */
        Torque_Control_ETR07_B.udifference =
          Torque_Control_ETR07_P.inchtom_Gain_g *
          Torque_Control_ETR07_P.EffectiveRollingRadiusinch_Va_b *
          Torque_Control_ETR07_P.udifference_Gain_d;
        Torque_Control_ETR07_B.TransmisionRatio =
          Torque_Control_ETR07_P.TransmisionRatio_Value_j;
        Torque_Control_ETR07_B.Constant1_k =
          Torque_Control_ETR07_P.Constant1_Value_l;
        Torque_Control_ETR07_B.Constant_dd =
          Torque_Control_ETR07_P.Constant_Value_ae;
      }

      /* Product: '<S193>/Divide' incorporates:
       *  Constant: '<S159>/Transmision Ratio[-]'
       *  Constant: '<S160>/Constant'
       *  Constant: '<S164>/Constant1'
       *  Product: '<S193>/Product'
       */
      rtb_Divide_a = Torque_Control_ETR07_B.sf_MATLABFunction2_m.value *
        Torque_Control_ETR07_B.udifference /
        Torque_Control_ETR07_B.TransmisionRatio;

      /* Product: '<S160>/Product1' incorporates:
       *  MATLAB Function: '<S160>/Kamm_Circle LatD'
       */
      rtb_Product1_l = rtb_alpha_j * rtb_Abs1;

      /* MATLAB Function: '<S160>/MATLAB Function1' */
      Torque_Contro_MATLABFunction_d1(Torque_Control_ETR07_B.Constant_dd,
        rtb_Product1_l, &Torque_Control_ETR07_B.sf_MATLABFunction1_f);

      /* MATLAB Function: '<S164>/MATLAB Function1' */
      Torque_Contro_MATLABFunction_d1(Torque_Control_ETR07_B.Constant1_k,
        Torque_Control_ETR07_B.sf_MATLABFunction1_f.value,
        &Torque_Control_ETR07_B.sf_MATLABFunction1_gm);

      /* Product: '<S192>/Divide' incorporates:
       *  Product: '<S192>/Product'
       */
      rtb_Divide_l = Torque_Control_ETR07_B.sf_MATLABFunction1_gm.value *
        Torque_Control_ETR07_B.udifference /
        Torque_Control_ETR07_B.TransmisionRatio;

      /* If: '<S158>/Braking Conditions' incorporates:
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/BrakeSensor_Value'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        if ((Torque_Control_ETR07_U.BrakeSensor_Value > 0.0) &&
            (Torque_Control_ETR07_U.APPS1_Value == 0.0) &&
            (Torque_Control_ETR07_B.Merge1_a == 1.0)) {
          rtAction = 0;
        } else if ((Torque_Control_ETR07_U.BrakeSensor_Value > 0.0) &&
                   (Torque_Control_ETR07_U.APPS1_Value == 0.0) &&
                   (Torque_Control_ETR07_B.Merge1_a == 0.0)) {
          rtAction = 1;
        } else if ((Torque_Control_ETR07_U.BrakeSensor_Value == 0.0) &&
                   (Torque_Control_ETR07_U.APPS1_Value == 0.0)) {
          rtAction = 2;
        } else {
          rtAction = 3;
        }

        Torque_Control_ETR07_DW.BrakingConditions_ActiveSubsyst = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.BrakingConditions_ActiveSubsyst;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S158>/Regenerative+Mech Braking' incorporates:
         *  ActionPort: '<S180>/Action Port'
         */
        Torque__RegenerativeMechBraking(rtb_Divide_a, rtb_Divide_l,
          &Torque_Control_ETR07_B.Merge_l, &Torque_Control_ETR07_B.Merge1_l);

        /* End of Outputs for SubSystem: '<S158>/Regenerative+Mech Braking' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S158>/Mech_Braking' incorporates:
         *  ActionPort: '<S179>/Action Port'
         */
        Torque_Control_ETR_Mech_Braking(&Torque_Control_ETR07_B.Merge_l,
          &Torque_Control_ETR07_B.Merge1_l,
          &Torque_Control_ETR07_P.Mech_Braking_h);

        /* End of Outputs for SubSystem: '<S158>/Mech_Braking' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S158>/Inertia Braking' incorporates:
         *  ActionPort: '<S178>/Action Port'
         */
        Torque_Control_ETR_Mech_Braking(&Torque_Control_ETR07_B.Merge_l,
          &Torque_Control_ETR07_B.Merge1_l,
          &Torque_Control_ETR07_P.InertiaBraking_b);

        /* End of Outputs for SubSystem: '<S158>/Inertia Braking' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S158>/Accelerating' incorporates:
         *  ActionPort: '<S177>/Action Port'
         */
        /* MATLAB Function: '<S177>/Accelerator behaviour ' incorporates:
         *  Inport: '<Root>/APPS1_Value'
         *  Inport: '<Root>/VDC_Apps_Sat_Down'
         *  Inport: '<Root>/VDC_Apps_Sat_Up'
         */
        Torque_Con_Acceleratorbehaviour(Torque_Control_ETR07_U.APPS1_Value,
          Torque_Control_ETR07_U.VDC_Apps_Sat_Up,
          Torque_Control_ETR07_U.VDC_Apps_Sat_Down,
          &Torque_Control_ETR07_B.sf_Acceleratorbehaviour_b);

        /* Product: '<S177>/Product' */
        Torque_Control_ETR07_B.Merge1_l =
          Torque_Control_ETR07_B.sf_Acceleratorbehaviour_b.throttle *
          rtb_Divide_l;

        /* Product: '<S177>/Product1' */
        Torque_Control_ETR07_B.Merge_l =
          Torque_Control_ETR07_B.sf_Acceleratorbehaviour_b.throttle *
          rtb_Divide_a;

        /* End of Outputs for SubSystem: '<S158>/Accelerating' */
        break;
      }

      /* End of If: '<S158>/Braking Conditions' */

      /* If: '<S157>/If' incorporates:
       *  Inport: '<Root>/BrakeSensor_Value'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        rtAction = (int8_T)!((Torque_Control_ETR07_B.Merge1_a == 1.0) &&
                             (Torque_Control_ETR07_U.BrakeSensor_Value > 0.0));
        Torque_Control_ETR07_DW.If_ActiveSubsystem_h = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_h;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S157>/Braking with Regenerative' incorporates:
         *  ActionPort: '<S166>/Action Port'
         */
        /* MATLAB Function: '<S166>/MATLAB Function' incorporates:
         *  Inport: '<Root>/VDC_Max_Regenerative_Torque'
         */
        rtb_Subtract1 = 0.0;
        rtb_value_g = 0.0;
        if (!((Torque_Control_ETR07_B.Merge_l == 0.0) &&
              (Torque_Control_ETR07_B.Merge1_l == 0.0))) {
          if ((Torque_Control_ETR07_B.Merge_l != 0.0) &&
              (Torque_Control_ETR07_B.Merge1_l == 0.0)) {
            rtb_value_g = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
          } else if ((Torque_Control_ETR07_B.Merge_l == 0.0) &&
                     (Torque_Control_ETR07_B.Merge1_l != 0.0)) {
            rtb_Subtract1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
          } else if (Torque_Control_ETR07_B.Merge_l ==
                     Torque_Control_ETR07_B.Merge1_l) {
            if (Torque_Control_ETR07_B.Merge_l >=
                Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque) {
              rtb_Subtract1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
              rtb_value_g = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
            } else {
              rtb_Subtract1 = Torque_Control_ETR07_B.Merge_l;
              rtb_value_g = Torque_Control_ETR07_B.Merge1_l;
            }
          } else if (Torque_Control_ETR07_B.Merge_l >
                     Torque_Control_ETR07_B.Merge1_l) {
            if (Torque_Control_ETR07_B.Merge_l <
                Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque) {
              rtb_Subtract1 = Torque_Control_ETR07_B.Merge1_l *
                Torque_Control_ETR07_B.Merge1_l / Torque_Control_ETR07_B.Merge_l;
              rtb_value_g = Torque_Control_ETR07_B.Merge1_l;
            } else {
              rtb_Subtract1 = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque
                * Torque_Control_ETR07_B.Merge1_l /
                Torque_Control_ETR07_B.Merge_l;
              rtb_value_g = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
            }
          } else {
            if (Torque_Control_ETR07_B.Merge_l < Torque_Control_ETR07_B.Merge1_l)
            {
              if (Torque_Control_ETR07_B.Merge1_l <
                  Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque) {
                rtb_Subtract1 = Torque_Control_ETR07_B.Merge_l;
                rtb_value_g = Torque_Control_ETR07_B.Merge_l *
                  Torque_Control_ETR07_B.Merge_l /
                  Torque_Control_ETR07_B.Merge1_l;
              } else {
                rtb_Subtract1 =
                  Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque;
                rtb_value_g = Torque_Control_ETR07_U.VDC_Max_Regenerative_Torque
                  * Torque_Control_ETR07_B.Merge_l /
                  Torque_Control_ETR07_B.Merge1_l;
              }
            }
          }
        }

        /* End of MATLAB Function: '<S166>/MATLAB Function' */

        /* Gain: '<S166>/Gain' */
        Torque_Control_ETR07_B.Merge_c = Torque_Control_ETR07_P.Gain_Gain_a *
          rtb_Subtract1;

        /* Gain: '<S166>/Gain1' */
        Torque_Control_ETR07_B.Merge1_m = Torque_Control_ETR07_P.Gain1_Gain_i *
          rtb_value_g;

        /* End of Outputs for SubSystem: '<S157>/Braking with Regenerative' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S157>/Acelerating and braking without Regenerative' incorporates:
         *  ActionPort: '<S165>/Action Port'
         */
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          /* Gain: '<S165>/Gain' incorporates:
           *  Constant: '<S165>/rpm'
           */
          Torque_Control_ETR07_B.approx2095 =
            Torque_Control_ETR07_P.Gain_Gain_cv *
            Torque_Control_ETR07_P.rpm_Value_k;
        }

        /* If: '<S165>/If1' incorporates:
         *  Inport: '<Root>/RL_rads'
         *  Inport: '<Root>/RR_rads'
         */
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          rtAction = (int8_T)!((Torque_Control_ETR07_U.RR_rads >
                                Torque_Control_ETR07_B.approx2095) &&
                               (Torque_Control_ETR07_U.RL_rads >
                                Torque_Control_ETR07_B.approx2095));
          Torque_Control_ETR07_DW.If1_ActiveSubsystem_bf = rtAction;
        } else {
          rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_bf;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S165>/If Action 1' incorporates:
           *  ActionPort: '<S169>/Action Port'
           */
          Torque_Control_ETR07_IfAction1
            (Torque_Control_ETR07_B.MaximumTransmissionTorqueDynami,
             &Torque_Control_ETR07_B.Merge2_o);

          /* End of Outputs for SubSystem: '<S165>/If Action 1' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S165>/If Action 2' incorporates:
           *  ActionPort: '<S170>/Action Port'
           */
          Torque_Control_ETR07_IfAction2
            (Torque_Control_ETR07_B.MaximumTransmissionTorqueStatic,
             &Torque_Control_ETR07_B.Merge2_o);

          /* End of Outputs for SubSystem: '<S165>/If Action 2' */
          break;
        }

        /* End of If: '<S165>/If1' */

        /* MATLAB Function: '<S165>/minimum value' */
        Torque_Control_ETR_minimumvalue(Torque_Control_ETR07_B.Merge2_o,
          Torque_Control_ETR07_B.MaximumTorqueperengineNm,
          Torque_Control_ETR07_B.Merge_l,
          &Torque_Control_ETR07_B.sf_minimumvalue_o);

        /* MATLAB Function: '<S165>/minimum value1' */
        Torque_Control_ET_minimumvalue1(Torque_Control_ETR07_B.Merge2_o,
          Torque_Control_ETR07_B.MaximumTorqueperengineNm,
          Torque_Control_ETR07_B.Merge1_l,
          &Torque_Control_ETR07_B.sf_minimumvalue1_k);

        /* If: '<S165>/If2' incorporates:
         *  Inport: '<Root>/Temp_IGBT'
         *  Inport: '<Root>/Temp_Motors'
         *  Inport: '<Root>/VDC_K_Reduction_P'
         *  Inport: '<Root>/VDC_K_Reduction_Temperature'
         *  Inport: '<Root>/VDC_Power_Limit'
         */
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          if ((Torque_Control_ETR07_U.Temp_IGBT >=
               Torque_Control_ETR07_B.LimitTemperatureIGBTC) ||
              (Torque_Control_ETR07_U.Temp_Motors >=
               Torque_Control_ETR07_B.LimitTemperatureMotorC) ||
              (Torque_Control_ETR07_B.Constant_l >=
               Torque_Control_ETR07_B.LimitTemperatureCeldasC)) {
            rtAction = 0;
          } else if (Torque_Control_ETR07_B.Constant_h >=
                     Torque_Control_ETR07_U.VDC_Power_Limit) {
            rtAction = 1;
          } else {
            rtAction = 2;
          }

          Torque_Control_ETR07_DW.If2_ActiveSubsystem_i = rtAction;
        } else {
          rtAction = Torque_Control_ETR07_DW.If2_ActiveSubsystem_i;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S165>/Control de Temperatura1' incorporates:
           *  ActionPort: '<S168>/Action Port'
           */
          Torque_Co_ControldeTemperatura1
            (Torque_Control_ETR07_B.sf_minimumvalue_o.min,
             Torque_Control_ETR07_B.sf_minimumvalue1_k.min,
             Torque_Control_ETR07_U.VDC_K_Reduction_Temperature, &rtb_Merge3,
             &rtb_Merge4);

          /* End of Outputs for SubSystem: '<S165>/Control de Temperatura1' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S165>/Control de Potencia 1' incorporates:
           *  ActionPort: '<S167>/Action Port'
           */
          Torque_Co_ControldeTemperatura1
            (Torque_Control_ETR07_B.sf_minimumvalue_o.min,
             Torque_Control_ETR07_B.sf_minimumvalue1_k.min,
             Torque_Control_ETR07_U.VDC_K_Reduction_P, &rtb_Merge3, &rtb_Merge4);

          /* End of Outputs for SubSystem: '<S165>/Control de Potencia 1' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S165>/else1' incorporates:
           *  ActionPort: '<S172>/Action Port'
           */
          Torque_Control_ETR07_else1
            (Torque_Control_ETR07_B.sf_minimumvalue_o.min,
             Torque_Control_ETR07_B.sf_minimumvalue1_k.min, &rtb_Merge3,
             &rtb_Merge4);

          /* End of Outputs for SubSystem: '<S165>/else1' */
          break;
        }

        /* End of If: '<S165>/If2' */

        /* MATLAB Function: '<S171>/MATLAB Function' */
        if ((rtb_Merge3 == Torque_Control_ETR07_B.Merge_l) && (rtb_Merge4 ==
             Torque_Control_ETR07_B.Merge1_l)) {
          /* SignalConversion: '<S165>/OutportBufferForTQ_RR' */
          Torque_Control_ETR07_B.Merge_c = rtb_Merge3;

          /* SignalConversion: '<S165>/OutportBufferForTQ_RL' */
          Torque_Control_ETR07_B.Merge1_m = rtb_Merge4;
        } else if (Torque_Control_ETR07_B.Merge_l >
                   Torque_Control_ETR07_B.Merge1_l) {
          /* SignalConversion: '<S165>/OutportBufferForTQ_RR' */
          Torque_Control_ETR07_B.Merge_c = rtb_Merge3;

          /* SignalConversion: '<S165>/OutportBufferForTQ_RL' */
          Torque_Control_ETR07_B.Merge1_m = Torque_Control_ETR07_B.Merge1_l /
            Torque_Control_ETR07_B.Merge_l * rtb_Merge3;
        } else if (Torque_Control_ETR07_B.Merge_l <
                   Torque_Control_ETR07_B.Merge1_l) {
          /* SignalConversion: '<S165>/OutportBufferForTQ_RR' */
          Torque_Control_ETR07_B.Merge_c = Torque_Control_ETR07_B.Merge_l /
            Torque_Control_ETR07_B.Merge1_l * rtb_Merge4;

          /* SignalConversion: '<S165>/OutportBufferForTQ_RL' */
          Torque_Control_ETR07_B.Merge1_m = rtb_Merge4;
        } else {
          /* SignalConversion: '<S165>/OutportBufferForTQ_RR' */
          Torque_Control_ETR07_B.Merge_c = rtb_Merge3;

          /* SignalConversion: '<S165>/OutportBufferForTQ_RL' */
          Torque_Control_ETR07_B.Merge1_m = rtb_Merge4;
        }

        /* End of MATLAB Function: '<S171>/MATLAB Function' */
        /* End of Outputs for SubSystem: '<S157>/Acelerating and braking without Regenerative' */
        break;
      }

      /* End of If: '<S157>/If' */

      /* SignalConversion: '<S69>/OutportBufferForCKF_act' */
      Torque_Control_ETR07_B.Merge3_c = rtb_Abs1;

      /* End of Outputs for SubSystem: '<S54>/VDC 2018 without Longitudinal' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S54>/Steering TV 2017 with TC' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        Torque_Control_ETR07_B.SteeringWheelMaximumAngle =
          Torque_Control_ETR07_P.SteeringWheelMaximumAngle_Val_o;
      }

      /* MATLAB Function: '<S84>/MATLAB Function1' incorporates:
       *  Constant: '<S84>/Steering Wheel Maximum Angle'
       */
      if ((Torque_Control_ETR07_B.Gain >
           Torque_Control_ETR07_B.SteeringWheelMaximumAngle) ||
          (Torque_Control_ETR07_B.Gain <
           -Torque_Control_ETR07_B.SteeringWheelMaximumAngle)) {
        rtb_Subtract1 = Torque_Control_ETR07_B.SteeringWheelMaximumAngle;
      } else {
        rtb_Subtract1 = Torque_Control_ETR07_B.Gain;
      }

      /* End of MATLAB Function: '<S84>/MATLAB Function1' */

      /* MATLAB Function: '<S77>/MATLAB Function' incorporates:
       *  Inport: '<Root>/RL_rads'
       *  Inport: '<Root>/RR_rads'
       */
      Torque_Control_E_MATLABFunction(Torque_Control_ETR07_U.RL_rads,
        Torque_Control_ETR07_U.RR_rads,
        &Torque_Control_ETR07_B.sf_MATLABFunction_a);

      /* Derivative: '<S77>/Derivative' */
      if ((Torque_Control_ETR07_DW.TimeStampA >=
           Torque_Control_ETR07_M->Timing.t[0]) &&
          (Torque_Control_ETR07_DW.TimeStampB >=
           Torque_Control_ETR07_M->Timing.t[0])) {
        rtb_Abs1 = 0.0;
      } else {
        Mz = Torque_Control_ETR07_DW.TimeStampA;
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA;
        if (Torque_Control_ETR07_DW.TimeStampA <
            Torque_Control_ETR07_DW.TimeStampB) {
          if (Torque_Control_ETR07_DW.TimeStampB <
              Torque_Control_ETR07_M->Timing.t[0]) {
            Mz = Torque_Control_ETR07_DW.TimeStampB;
            lastU = &Torque_Control_ETR07_DW.LastUAtTimeB;
          }
        } else {
          if (Torque_Control_ETR07_DW.TimeStampA >=
              Torque_Control_ETR07_M->Timing.t[0]) {
            Mz = Torque_Control_ETR07_DW.TimeStampB;
            lastU = &Torque_Control_ETR07_DW.LastUAtTimeB;
          }
        }

        rtb_Abs1 = (Torque_Control_ETR07_B.sf_MATLABFunction_a.RPM - *lastU) /
          (Torque_Control_ETR07_M->Timing.t[0] - Mz);
      }

      /* End of Derivative: '<S77>/Derivative' */

      /* If: '<S84>/SKF or CKF' */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        rtAction = (int8_T)!((-10.0 < rtb_Subtract1) && (rtb_Subtract1 < 10.0));
        Torque_Control_ETR07_DW.SKForCKF_ActiveSubsystem = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.SKForCKF_ActiveSubsystem;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S84>/SKF' incorporates:
         *  ActionPort: '<S87>/Action Port'
         */
        /* If: '<S87>/If' incorporates:
         *  Constant: '<S93>/Constant'
         */
        rtAction = -1;
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          if (rtb_Abs1 >= 900.0) {
            rtAction = 0;
          } else {
            if (rtb_Abs1 < 900.0) {
              rtAction = 1;
            }
          }

          Torque_Control_ETR07_DW.If_ActiveSubsystem_j = rtAction;
        } else {
          rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_j;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S87>/Spin' incorporates:
           *  ActionPort: '<S93>/Action Port'
           */
          if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
            Torque_Control_ETR07_B.Constant_d =
              Torque_Control_ETR07_P.Constant_Value_n5;
          }

          /* Switch: '<S93>/Switch' incorporates:
           *  Constant: '<S93>/Constant'
           *  Inport: '<Root>/VDC_Cte_CKF'
           */
          if (Torque_Control_ETR07_U.VDC_Cte_CKF >
              Torque_Control_ETR07_P.Switch_Threshold_a) {
            Mz = Torque_Control_ETR07_U.VDC_Cte_CKF;
          } else {
            Mz = Torque_Control_ETR07_B.Constant_d;
          }

          /* End of Switch: '<S93>/Switch' */

          /* Product: '<S93>/Product' incorporates:
           *  DataStoreRead: '<S77>/SKF_prev '
           */
          rtb_Product_i = Torque_Control_ETR07_DW.A * Mz;

          /* MATLAB Function: '<S93>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          Torque_Control_MATLABFunction_m(Torque_Control_ETR07_U.VDC_SKF_Initial,
            rtb_Product_i, &Torque_Control_ETR07_B.sf_MATLABFunction_p);

          /* SignalConversion: '<S93>/OutportBufferForSKF_act1' */
          Torque_Control_ETR07_B.Merge_kj =
            Torque_Control_ETR07_B.sf_MATLABFunction_p.SKF_act1;

          /* End of Outputs for SubSystem: '<S87>/Spin' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S87>/No spin' incorporates:
           *  ActionPort: '<S92>/Action Port'
           */
          /* Switch: '<S92>/Switch' incorporates:
           *  DataStoreRead: '<S77>/SKF_prev '
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          if (Torque_Control_ETR07_DW.A >
              Torque_Control_ETR07_P.Switch_Threshold_f) {
            rtb_Switch_b = Torque_Control_ETR07_DW.A;
          } else {
            rtb_Switch_b = Torque_Control_ETR07_U.VDC_SKF_Initial;
          }

          /* End of Switch: '<S92>/Switch' */

          /* MATLAB Function: '<S92>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_SKF_Initial'
           */
          Torque_Control_MATLABFunction_d(rtb_Switch_b,
            Torque_Control_ETR07_U.VDC_SKF_Initial,
            &Torque_Control_ETR07_B.sf_MATLABFunction_fq);

          /* SignalConversion: '<S92>/OutportBufferForSKF_act0' */
          Torque_Control_ETR07_B.Merge_kj =
            Torque_Control_ETR07_B.sf_MATLABFunction_fq.SKF_act0;

          /* End of Outputs for SubSystem: '<S87>/No spin' */
          break;
        }

        /* End of If: '<S87>/If' */

        /* Saturate: '<S87>/Saturation' */
        if (Torque_Control_ETR07_B.Merge_kj >
            Torque_Control_ETR07_P.Saturation_UpperSat_k) {
          Torque_Control_ETR07_B.Saturation_k =
            Torque_Control_ETR07_P.Saturation_UpperSat_k;
        } else if (Torque_Control_ETR07_B.Merge_kj <
                   Torque_Control_ETR07_P.Saturation_LowerSat_f3) {
          Torque_Control_ETR07_B.Saturation_k =
            Torque_Control_ETR07_P.Saturation_LowerSat_f3;
        } else {
          Torque_Control_ETR07_B.Saturation_k = Torque_Control_ETR07_B.Merge_kj;
        }

        /* End of Saturate: '<S87>/Saturation' */
        /* End of Outputs for SubSystem: '<S84>/SKF' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S84>/CKF' incorporates:
         *  ActionPort: '<S85>/Action Port'
         */
        /* If: '<S85>/If1' incorporates:
         *  Constant: '<S89>/Constant'
         */
        rtAction = -1;
        if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
          if (rtb_Abs1 >= 900.0) {
            rtAction = 0;
          } else {
            if (rtb_Abs1 < 900.0) {
              rtAction = 1;
            }
          }

          Torque_Control_ETR07_DW.If1_ActiveSubsystem_c = rtAction;
        } else {
          rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_c;
        }

        switch (rtAction) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S85>/Spin ' incorporates:
           *  ActionPort: '<S89>/Action Port'
           */
          if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
            Torque_Control_ETR07_B.Constant_ob =
              Torque_Control_ETR07_P.Constant_Value_d;
          }

          /* Switch: '<S89>/Switch' incorporates:
           *  Constant: '<S89>/Constant'
           *  Inport: '<Root>/VDC_Cte_SKF'
           */
          if (Torque_Control_ETR07_U.VDC_Cte_SKF >
              Torque_Control_ETR07_P.Switch_Threshold_b) {
            Mz = Torque_Control_ETR07_U.VDC_Cte_SKF;
          } else {
            Mz = Torque_Control_ETR07_B.Constant_ob;
          }

          /* End of Switch: '<S89>/Switch' */

          /* Product: '<S89>/Product' incorporates:
           *  DataStoreRead: '<S77>/CKF_prev'
           */
          rtb_Product_d = Torque_Control_ETR07_DW.B * Mz;

          /* MATLAB Function: '<S89>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          Torque_Contro_MATLABFunction_mt(Torque_Control_ETR07_U.VDC_CKF_Initial,
            rtb_Product_d, &Torque_Control_ETR07_B.sf_MATLABFunction_k);

          /* SignalConversion: '<S89>/OutportBufferForCKF_act1 ' */
          Torque_Control_ETR07_B.Merge_k =
            Torque_Control_ETR07_B.sf_MATLABFunction_k.CKF_act1;

          /* End of Outputs for SubSystem: '<S85>/Spin ' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S85>/No spin' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          /* Switch: '<S88>/Switch' incorporates:
           *  DataStoreRead: '<S77>/CKF_prev'
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          if (Torque_Control_ETR07_DW.B >
              Torque_Control_ETR07_P.Switch_Threshold_e) {
            rtb_Switch = Torque_Control_ETR07_DW.B;
          } else {
            rtb_Switch = Torque_Control_ETR07_U.VDC_CKF_Initial;
          }

          /* End of Switch: '<S88>/Switch' */

          /* MATLAB Function: '<S88>/MATLAB Function' incorporates:
           *  Inport: '<Root>/VDC_CKF_Initial'
           */
          Torque_Control_MATLABFunction_b(rtb_Switch,
            Torque_Control_ETR07_U.VDC_CKF_Initial,
            &Torque_Control_ETR07_B.sf_MATLABFunction_k2);

          /* SignalConversion: '<S88>/OutportBufferForCKF_act0' */
          Torque_Control_ETR07_B.Merge_k =
            Torque_Control_ETR07_B.sf_MATLABFunction_k2.CKF_act0;

          /* End of Outputs for SubSystem: '<S85>/No spin' */
          break;
        }

        /* End of If: '<S85>/If1' */

        /* Saturate: '<S85>/Saturation' */
        if (Torque_Control_ETR07_B.Merge_k >
            Torque_Control_ETR07_P.Saturation_UpperSat_c) {
          Torque_Control_ETR07_B.Saturation =
            Torque_Control_ETR07_P.Saturation_UpperSat_c;
        } else if (Torque_Control_ETR07_B.Merge_k <
                   Torque_Control_ETR07_P.Saturation_LowerSat_e) {
          Torque_Control_ETR07_B.Saturation =
            Torque_Control_ETR07_P.Saturation_LowerSat_e;
        } else {
          Torque_Control_ETR07_B.Saturation = Torque_Control_ETR07_B.Merge_k;
        }

        /* End of Saturate: '<S85>/Saturation' */
        /* End of Outputs for SubSystem: '<S84>/CKF' */
        break;
      }

      /* End of If: '<S84>/SKF or CKF' */

      /* DataStoreWrite: '<S77>/Data Store Write' */
      Torque_Control_ETR07_DW.A = Torque_Control_ETR07_B.Saturation_k;

      /* DataStoreWrite: '<S77>/Data Store Write1' */
      Torque_Control_ETR07_DW.B = Torque_Control_ETR07_B.Saturation;

      /* MATLAB Function: '<S72>/Accelerator behaviour ' incorporates:
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       *  Inport: '<Root>/VDC_Apps_Sat_Up'
       */
      Torque_Con_Acceleratorbehaviour(Torque_Control_ETR07_U.APPS1_Value,
        Torque_Control_ETR07_U.VDC_Apps_Sat_Up,
        Torque_Control_ETR07_U.VDC_Apps_Sat_Down,
        &Torque_Control_ETR07_B.sf_Acceleratorbehaviour_f);
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        Torque_Control_ETR07_B.SteeringWheelMaximumAngle_m =
          Torque_Control_ETR07_P.SteeringWheelMaximumAngle_Val_i;
        Torque_Control_ETR07_B.Tq_maxNm = Torque_Control_ETR07_P.Tq_maxNm_Value;
        Torque_Control_ETR07_B.Tq_diff_maxNm =
          Torque_Control_ETR07_P.Tq_diff_maxNm_Value;
      }

      /* MATLAB Function: '<S67>/MATLAB Function1' incorporates:
       *  Constant: '<S67>/Steering Wheel Maximum Angle'
       *  Constant: '<S67>/Tq_diff_max [Nm]'
       *  Constant: '<S67>/Tq_max [Nm]'
       */
      if (Torque_Control_ETR07_B.Gain >
          Torque_Control_ETR07_B.SteeringWheelMaximumAngle_m) {
        rtb_Subtract1 = Torque_Control_ETR07_B.SteeringWheelMaximumAngle_m;
      } else if (Torque_Control_ETR07_B.Gain <
                 -Torque_Control_ETR07_B.SteeringWheelMaximumAngle_m) {
        rtb_Subtract1 = -Torque_Control_ETR07_B.SteeringWheelMaximumAngle_m;
      } else {
        rtb_Subtract1 = Torque_Control_ETR07_B.Gain;
      }

      /* End of MATLAB Function: '<S67>/MATLAB Function1' */

      /* MATLAB Function: '<S67>/Steering TV 2017 without TC' */
      rtb_Abs1 = 0.0;
      Mz = 0.0;
      if ((rtb_Subtract1 >=
           -Torque_Control_ETR07_B.SteeringWheelSaturationpersited) &&
          (rtb_Subtract1 <=
           Torque_Control_ETR07_B.SteeringWheelSaturationpersited)) {
        rtb_Abs1 = Torque_Control_ETR07_B.Tq_maxNm;
        Mz = Torque_Control_ETR07_B.Tq_maxNm;
      } else if (rtb_Subtract1 >
                 Torque_Control_ETR07_B.SteeringWheelSaturationpersited) {
        rtb_Abs1 = Torque_Control_ETR07_B.Tq_maxNm;
        Mz = Torque_Control_ETR07_B.Tq_maxNm -
          Torque_Control_ETR07_B.Tq_diff_maxNm /
          (Torque_Control_ETR07_B.SteeringWheelMaximumAngle_m -
           Torque_Control_ETR07_B.SteeringWheelSaturationpersited) * (fabs
          (rtb_Subtract1) -
          Torque_Control_ETR07_B.SteeringWheelSaturationpersited);
      } else {
        if (rtb_Subtract1 <
            -Torque_Control_ETR07_B.SteeringWheelSaturationpersited) {
          Mz = Torque_Control_ETR07_B.Tq_maxNm;
          rtb_Abs1 = Torque_Control_ETR07_B.Tq_maxNm -
            Torque_Control_ETR07_B.Tq_diff_maxNm /
            (Torque_Control_ETR07_B.SteeringWheelMaximumAngle_m -
             Torque_Control_ETR07_B.SteeringWheelSaturationpersited) * (fabs
            (rtb_Subtract1) -
            Torque_Control_ETR07_B.SteeringWheelSaturationpersited);
        }
      }

      /* End of MATLAB Function: '<S67>/Steering TV 2017 without TC' */

      /* If: '<S67>/If' */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        rtAction = (int8_T)
          !((-Torque_Control_ETR07_B.SteeringWheelSaturationpersited <=
             rtb_Subtract1) && (rtb_Subtract1 <=
             Torque_Control_ETR07_B.SteeringWheelSaturationpersited));
        Torque_Control_ETR07_DW.If_ActiveSubsystem_ds = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_ds;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S67>/Longitudinal Dynamics' incorporates:
         *  ActionPort: '<S75>/Action Port'
         */
        /* Product: '<S75>/Product' */
        rtb_value_g = rtb_Abs1 * Torque_Control_ETR07_B.Saturation_k;

        /* Product: '<S75>/Product1' */
        rtb_alpha_j = Mz * Torque_Control_ETR07_B.Saturation_k;

        /* End of Outputs for SubSystem: '<S67>/Longitudinal Dynamics' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S67>/Lateral Dynamics' incorporates:
         *  ActionPort: '<S74>/Action Port'
         */
        /* Product: '<S74>/Product' */
        rtb_value_g = rtb_Abs1 * Torque_Control_ETR07_B.Saturation;

        /* Product: '<S74>/Product1' */
        rtb_alpha_j = Mz * Torque_Control_ETR07_B.Saturation;

        /* End of Outputs for SubSystem: '<S67>/Lateral Dynamics' */
        break;
      }

      /* End of If: '<S67>/If' */

      /* Product: '<S72>/Product' */
      rtb_Product_g = Torque_Control_ETR07_B.sf_Acceleratorbehaviour_f.throttle *
        rtb_alpha_j;

      /* Product: '<S72>/Product1' */
      rtb_Product1 = Torque_Control_ETR07_B.sf_Acceleratorbehaviour_f.throttle *
        rtb_value_g;

      /* If: '<S73>/If' incorporates:
       *  Inport: '<Root>/Temp_IGBT'
       *  Inport: '<Root>/Temp_Motors'
       *  Inport: '<Root>/VDC_K_Reduction_P'
       *  Inport: '<Root>/VDC_K_Reduction_Temperature'
       *  Inport: '<Root>/VDC_Power_Limit'
       */
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        if ((Torque_Control_ETR07_U.Temp_IGBT >=
             Torque_Control_ETR07_B.LimitTemperatureIGBTC) ||
            (Torque_Control_ETR07_U.Temp_Motors >=
             Torque_Control_ETR07_B.LimitTemperatureMotorC) ||
            (Torque_Control_ETR07_B.Constant_l >=
             Torque_Control_ETR07_B.LimitTemperatureCeldasC)) {
          rtAction = 0;
        } else if (Torque_Control_ETR07_B.Constant_h >=
                   Torque_Control_ETR07_U.VDC_Power_Limit) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }

        Torque_Control_ETR07_DW.If_ActiveSubsystem_b = rtAction;
      } else {
        rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_b;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S73>/Control de Temperatura' incorporates:
         *  ActionPort: '<S81>/Action Port'
         */
        Torque_Co_ControldeTemperatura1(rtb_Product1, rtb_Product_g,
          Torque_Control_ETR07_U.VDC_K_Reduction_Temperature,
          &Torque_Control_ETR07_B.Merge_c, &Torque_Control_ETR07_B.Merge1_m);

        /* End of Outputs for SubSystem: '<S73>/Control de Temperatura' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S73>/Control de Potencia ' incorporates:
         *  ActionPort: '<S80>/Action Port'
         */
        Torque_Co_ControldeTemperatura1(rtb_Product1, rtb_Product_g,
          Torque_Control_ETR07_U.VDC_K_Reduction_P,
          &Torque_Control_ETR07_B.Merge_c, &Torque_Control_ETR07_B.Merge1_m);

        /* End of Outputs for SubSystem: '<S73>/Control de Potencia ' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S73>/else' incorporates:
         *  ActionPort: '<S82>/Action Port'
         */
        Torque_Control_ETR07_else1(rtb_Product1, rtb_Product_g,
          &Torque_Control_ETR07_B.Merge_c, &Torque_Control_ETR07_B.Merge1_m);

        /* End of Outputs for SubSystem: '<S73>/else' */
        break;
      }

      /* End of If: '<S73>/If' */

      /* SignalConversion: '<S67>/OutportBufferForCKF_act' */
      Torque_Control_ETR07_B.Merge3_c = Torque_Control_ETR07_B.Saturation;

      /* SignalConversion: '<S67>/OutportBufferForSKF_act' */
      Torque_Control_ETR07_B.Merge2_l = Torque_Control_ETR07_B.Saturation_k;

      /* End of Outputs for SubSystem: '<S54>/Steering TV 2017 with TC' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S54>/Rigid Axle' incorporates:
       *  ActionPort: '<S66>/Action Port'
       */
      /* MATLAB Function: '<S70>/Accelerator behaviour ' incorporates:
       *  Inport: '<Root>/APPS1_Value'
       *  Inport: '<Root>/VDC_Apps_Sat_Down'
       *  Inport: '<Root>/VDC_Apps_Sat_Up'
       */
      Torque_Con_Acceleratorbehaviour(Torque_Control_ETR07_U.APPS1_Value,
        Torque_Control_ETR07_U.VDC_Apps_Sat_Up,
        Torque_Control_ETR07_U.VDC_Apps_Sat_Down,
        &Torque_Control_ETR07_B.sf_Acceleratorbehaviour_o);
      if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
        Torque_Control_ETR07_B.Torque_RLNm =
          Torque_Control_ETR07_P.Torque_RLNm_Value;
        Torque_Control_ETR07_B.Torque_RRNm =
          Torque_Control_ETR07_P.Torque_RRNm_Value;
      }

      /* Product: '<S70>/Product' incorporates:
       *  Constant: '<S66>/Torque_RL [Nm]'
       *  Constant: '<S66>/Torque_RR [Nm]'
       */
      Torque_Control_ETR07_B.Merge1_m =
        Torque_Control_ETR07_B.sf_Acceleratorbehaviour_o.throttle *
        Torque_Control_ETR07_B.Torque_RLNm;

      /* Product: '<S70>/Product1' */
      Torque_Control_ETR07_B.Merge_c =
        Torque_Control_ETR07_B.sf_Acceleratorbehaviour_o.throttle *
        Torque_Control_ETR07_B.Torque_RRNm;

      /* End of Outputs for SubSystem: '<S54>/Rigid Axle' */
      break;
    }

    /* End of If: '<S54>/FAILURE MODE' */
    /* End of Outputs for SubSystem: '<S7>/Vehicle Dynamics Control 2018' */
  }

  /* End of If: '<S7>/If' */

  /* Outport: '<Root>/Torque_RRwc' */
  Torque_Control_ETR07_Y.Torque_RRwc = Torque_Control_ETR07_B.Merge_kt;

  /* Outport: '<Root>/Torque_RLwc' */
  Torque_Control_ETR07_Y.Torque_RLwc = Torque_Control_ETR07_B.Merge1_b;

  /* Outport: '<Root>/Max_Torque_RR' */
  Torque_Control_ETR07_Y.Max_Torque_RR = Torque_Control_ETR07_B.Divide;

  /* Outport: '<Root>/Max_Torque_RL' */
  Torque_Control_ETR07_Y.Max_Torque_RL = Torque_Control_ETR07_B.Divide_i;

  /* Outport: '<Root>/Max_Fx_RR' */
  Torque_Control_ETR07_Y.Max_Fx_RR = Torque_Control_ETR07_B.Merge2_lx;

  /* Outport: '<Root>/Max_Fx_RL' */
  Torque_Control_ETR07_Y.Max_Fx_RL = Torque_Control_ETR07_B.Merge3_e;

  /* Outport: '<Root>/Throttle' incorporates:
   *  Gain: '<S7>/Gain1'
   */
  Torque_Control_ETR07_Y.Throttle = Torque_Control_ETR07_P.Gain1_Gain_o *
    Torque_Control_ETR07_B.Throttle;

  /* Outport: '<Root>/Fy_R' */
  Torque_Control_ETR07_Y.Fy_R = Torque_Control_ETR07_B.Merge6;

  /* Outport: '<Root>/Mass' */
  Torque_Control_ETR07_Y.Mass = Torque_Control_ETR07_B.Merge4;

  /* Outport: '<Root>/Handling' */
  Torque_Control_ETR07_Y.Handling = Torque_Control_ETR07_B.Merge5_e;

  /* Outport: '<Root>/SKF_actual' */
  Torque_Control_ETR07_Y.SKF_actual = Torque_Control_ETR07_B.Merge2_l;

  /* Outport: '<Root>/CKF_actual' */
  Torque_Control_ETR07_Y.CKF_actual = Torque_Control_ETR07_B.Merge3_c;

  /* Outport: '<Root>/SteeringSensor_Value' */
  Torque_Control_ETR07_Y.SteeringSensor_Value = rtb_Gain;

  /* Outport: '<Root>/TV_Flag_WheelSpinRR' */
  Torque_Control_ETR07_Y.TV_Flag_WheelSpinRR =
    Torque_Control_ETR07_B.OutportBufferForFlags_num5[1];

  /* Outport: '<Root>/TV_Flag_WheelSpinRL' */
  Torque_Control_ETR07_Y.TV_Flag_WheelSpinRL =
    Torque_Control_ETR07_B.OutportBufferForFlags_num5[2];

  /* Outport: '<Root>/TV_Flag_Temperature' */
  Torque_Control_ETR07_Y.TV_Flag_Temperature =
    Torque_Control_ETR07_B.OutportBufferForFlags_num5[3];

  /* Outport: '<Root>/TV_Flag_Power' */
  Torque_Control_ETR07_Y.TV_Flag_Power =
    Torque_Control_ETR07_B.OutportBufferForFlags_num5[4];

  /* Outport: '<Root>/TV_Flag_CarBehaviour' */
  Torque_Control_ETR07_Y.TV_Flag_CarBehaviour =
    Torque_Control_ETR07_B.OutportBufferForFlags_num5[0];
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Outport: '<Root>/APPS_Implausibility' */
    Torque_Control_ETR07_Y.APPS_Implausibility = rtb_LogicalOperator1;

    /* Outport: '<Root>/Brake_Implausibility' */
    Torque_Control_ETR07_Y.Brake_Implausibility = rtb_LogicalOperator2;

    /* Product: '<S1>/Product' incorporates:
     *  Inport: '<Root>/Accumulator_Current'
     *  Inport: '<Root>/Accumulator_Voltage'
     */
    rtb_Gain = Torque_Control_ETR07_U.Accumulator_Voltage *
      Torque_Control_ETR07_U.Accumulator_Current;

    /* Outport: '<Root>/Power' */
    Torque_Control_ETR07_Y.Power = rtb_Gain;

    /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
    /* If: '<S9>/If' incorporates:
     *  DataStoreRead: '<S9>/Data Store Read30'
     *  If: '<S11>/If'
     *  Inport: '<S9>/Power'
     */
    if (rtb_Gain >= 80000.0) {
      /* Outputs for IfAction SubSystem: '<S9>/LimitReached' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      Torque_Control_ETR_LimitReached(&rtb_Merge1_p,
        &Torque_Control_ETR07_P.LimitReached);

      /* End of Outputs for SubSystem: '<S9>/LimitReached' */
    } else {
      /* Outputs for IfAction SubSystem: '<S9>/OK_OrLatch' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      if (Torque_Control_ETR07_DW.A_i > 0.0) {
        /* Outputs for IfAction SubSystem: '<S11>/Latched Error' incorporates:
         *  ActionPort: '<S12>/Action Port'
         */

        /* If: '<S11>/If' */
        Torque_Control_ETR_LimitReached(&rtb_Merge1_p,
          &Torque_Control_ETR07_P.LatchedError);

        /* End of Outputs for SubSystem: '<S11>/Latched Error' */
      } else {
        /* Outputs for IfAction SubSystem: '<S11>/OK' incorporates:
         *  ActionPort: '<S13>/Action Port'
         */

        /* If: '<S11>/If' */
        Torque_Control_ETR_LimitReached(&rtb_Merge1_p,
          &Torque_Control_ETR07_P.OK);

        /* End of Outputs for SubSystem: '<S11>/OK' */
      }

      /* End of Outputs for SubSystem: '<S9>/OK_OrLatch' */
    }

    /* End of If: '<S9>/If' */

    /* DataStoreWrite: '<S9>/Data Store Write20' */
    Torque_Control_ETR07_DW.A_i = rtb_Merge1_p;

    /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

    /* Outport: '<Root>/PowerLimitReached' */
    Torque_Control_ETR07_Y.PowerLimitReached = rtb_Merge1_p;

    /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
    /* Outport: '<Root>/PowerMean500ms' incorporates:
     *  Inport: '<S9>/Power'
     */
    Torque_Control_ETR07_Y.PowerMean500ms = rtb_Gain;

    /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

    /* Constant: '<S25>/Constant' */
    Torque_Control_ETR07_B.Constant_n =
      Torque_Control_ETR07_P.CompareToConstant1_const;

    /* Constant: '<S24>/Constant' */
    Torque_Control_ETR07_B.Constant_i =
      Torque_Control_ETR07_P.CompareToConstant_const_p;
  }

  /* Outport: '<Root>/Torque_OK' */
  Torque_Control_ETR07_Y.Torque_OK = Torque_Control_ETR07_B.LogicalOperator;

  /* Outport: '<Root>/Regenerative_Enable' */
  Torque_Control_ETR07_Y.Regenerative_Enable = Torque_Control_ETR07_B.Merge_h;

  /* Outputs for Atomic SubSystem: '<S7>/Regeneration_Enable' */
  /* Outport: '<Root>/Dash_Speed' incorporates:
   *  Inport: '<Root>/Vel_RL_kmh'
   *  Inport: '<Root>/Vel_RR_kmh'
   *  Product: '<S52>/Divide'
   *  Sum: '<S52>/Add'
   */
  Torque_Control_ETR07_Y.Dash_Speed = (Torque_Control_ETR07_U.Vel_RR_kmh +
    Torque_Control_ETR07_U.Vel_RL_kmh) / Torque_Control_ETR07_B.Constant_o;

  /* End of Outputs for SubSystem: '<S7>/Regeneration_Enable' */

  /* If: '<S4>/If' incorporates:
   *  Inport: '<Root>/Car_State'
   *  Inport: '<Root>/Temp_IGBT'
   *  Logic: '<S4>/Logical Operator'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S25>/Compare'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!((Torque_Control_ETR07_U.Car_State ==
                          Torque_Control_ETR07_B.Constant_n) ||
                         (Torque_Control_ETR07_U.Temp_IGBT >
                          Torque_Control_ETR07_B.Constant_i));
    Torque_Control_ETR07_DW.If_ActiveSubsystem_d = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_d;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S4>/Pumps_Control_ON' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      /* SignalConversion: '<S28>/OutportBufferFor1' incorporates:
       *  Constant: '<S28>/Constant'
       */
      rtb_Merge_d = Torque_Control_ETR07_P.Constant_Value_i;
    }

    /* End of Outputs for SubSystem: '<S4>/Pumps_Control_ON' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S4>/Pumps_Control_OFF' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      /* SignalConversion: '<S27>/OutportBufferFor0' incorporates:
       *  Constant: '<S27>/Constant'
       */
      rtb_Merge_d = Torque_Control_ETR07_P.Constant_Value_n;
    }

    /* End of Outputs for SubSystem: '<S4>/Pumps_Control_OFF' */
    break;
  }

  /* End of If: '<S4>/If' */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    /* Outport: '<Root>/Pumps_Control' */
    Torque_Control_ETR07_Y.Pumps_Control = rtb_Merge_d;
  }

  /* Outputs for Atomic SubSystem: '<S7>/WORKSHOP_MODE_RESTRICTIONS' */
  /* If: '<S55>/If' incorporates:
   *  Constant: '<S197>/Constant'
   *  Inport: '<Root>/Workshop_Mode_Enable'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!(Torque_Control_ETR07_U.Workshop_Mode_Enable == 1.0);
    Torque_Control_ETR07_DW.If_ActiveSubsystem_e = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_e;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S55>/Torque_Reduction ' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      Torque_Control_ETR07_B.Constant_m =
        Torque_Control_ETR07_P.Constant_Value_dm;
    }

    /* Product: '<S197>/Divide' incorporates:
     *  Constant: '<S197>/Constant'
     */
    rtb_Gain = Torque_Control_ETR07_B.Merge_c /
      Torque_Control_ETR07_B.Constant_m;

    /* Saturate: '<S197>/Saturation' */
    if (rtb_Gain > Torque_Control_ETR07_P.Saturation_UpperSat_h) {
      rtb_Merge_i = Torque_Control_ETR07_P.Saturation_UpperSat_h;
    } else if (rtb_Gain < Torque_Control_ETR07_P.Saturation_LowerSat_j) {
      rtb_Merge_i = Torque_Control_ETR07_P.Saturation_LowerSat_j;
    } else {
      rtb_Merge_i = rtb_Gain;
    }

    /* End of Saturate: '<S197>/Saturation' */

    /* Product: '<S197>/Divide1' */
    rtb_Gain = Torque_Control_ETR07_B.Merge1_m /
      Torque_Control_ETR07_B.Constant_m;

    /* Saturate: '<S197>/Saturation1' */
    if (rtb_Gain > Torque_Control_ETR07_P.Saturation1_UpperSat) {
      rtb_Merge1_a = Torque_Control_ETR07_P.Saturation1_UpperSat;
    } else if (rtb_Gain < Torque_Control_ETR07_P.Saturation1_LowerSat) {
      rtb_Merge1_a = Torque_Control_ETR07_P.Saturation1_LowerSat;
    } else {
      rtb_Merge1_a = rtb_Gain;
    }

    /* End of Saturate: '<S197>/Saturation1' */
    /* End of Outputs for SubSystem: '<S55>/Torque_Reduction ' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S55>/BYPASS' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    Torque_Control_ETR07_Bypass(Torque_Control_ETR07_B.Merge_c,
      Torque_Control_ETR07_B.Merge1_m, &rtb_Merge_i, &rtb_Merge1_a);

    /* End of Outputs for SubSystem: '<S55>/BYPASS' */
    break;
  }

  /* End of If: '<S55>/If' */

  /* Saturate: '<S55>/Saturation' */
  if (rtb_Merge_i > Torque_Control_ETR07_P.Saturation_UpperSat_g) {
    rtb_Merge_d = Torque_Control_ETR07_P.Saturation_UpperSat_g;
  } else if (rtb_Merge_i < Torque_Control_ETR07_P.Saturation_LowerSat_fi) {
    rtb_Merge_d = Torque_Control_ETR07_P.Saturation_LowerSat_fi;
  } else {
    rtb_Merge_d = rtb_Merge_i;
  }

  /* End of Saturate: '<S55>/Saturation' */

  /* Saturate: '<S55>/Saturation1' */
  if (rtb_Merge1_a > Torque_Control_ETR07_P.Saturation1_UpperSat_m) {
    rtb_Gain = Torque_Control_ETR07_P.Saturation1_UpperSat_m;
  } else if (rtb_Merge1_a < Torque_Control_ETR07_P.Saturation1_LowerSat_l) {
    rtb_Gain = Torque_Control_ETR07_P.Saturation1_LowerSat_l;
  } else {
    rtb_Gain = rtb_Merge1_a;
  }

  /* End of Saturate: '<S55>/Saturation1' */
  /* End of Outputs for SubSystem: '<S7>/WORKSHOP_MODE_RESTRICTIONS' */

  /* Outport: '<Root>/Meas VDC Torque_L' */
  Torque_Control_ETR07_Y.MeasVDCTorque_L = rtb_Gain;

  /* Outport: '<Root>/Meas VDC Torque_R' */
  Torque_Control_ETR07_Y.MeasVDCTorque_R = rtb_Merge_d;

  /* Outport: '<Root>/Torque_L' */
  Torque_Control_ETR07_Y.Torque_L = rtb_Gain;

  /* Outport: '<Root>/Torque_R' */
  Torque_Control_ETR07_Y.Torque_R = rtb_Merge_d;

  /* If: '<Root>/If1' incorporates:
   *  Constant: '<S14>/A'
   *  Constant: '<S14>/B'
   *  Constant: '<S14>/C'
   *  Constant: '<S14>/Zero'
   *  Constant: '<S15>/A1'
   *  Constant: '<S15>/B1'
   *  Constant: '<S15>/C1'
   *  Constant: '<S15>/Zero'
   */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rtAction = (int8_T)!Torque_Control_ETR07_B.LogicalOperator;
    Torque_Control_ETR07_DW.If1_ActiveSubsystem = rtAction;
  } else {
    rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/Calculate Current Conversion' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S2>/KT_L_TORKY' */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      Torque_Control_ETR07_B.A = Torque_Control_ETR07_P.A_Value;
      Torque_Control_ETR07_B.C = Torque_Control_ETR07_P.C_Value;
    }

    /* If: '<S14>/If1' incorporates:
     *  Constant: '<S14>/A'
     *  Constant: '<S14>/C'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      rtAction = (int8_T)!(rtb_Gain >= 0.0);
      Torque_Control_ETR07_DW.If1_ActiveSubsystem_n = rtAction;
    } else {
      rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_n;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S14>/Bypass' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      Torque_Control_ETR07_Bypass(Torque_Control_ETR07_B.A,
        Torque_Control_ETR07_B.C, &Torque_Control_ETR07_B.Merge1_lz,
        &Torque_Control_ETR07_B.Merge2_b);

      /* End of Outputs for SubSystem: '<S14>/Bypass' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S14>/Negative' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      Torque_Control_ETR07_Negative(Torque_Control_ETR07_B.A,
        Torque_Control_ETR07_B.C, &Torque_Control_ETR07_B.Merge1_lz,
        &Torque_Control_ETR07_B.Merge2_b, &Torque_Control_ETR07_P.Negative);

      /* End of Outputs for SubSystem: '<S14>/Negative' */
      break;
    }

    /* End of If: '<S14>/If1' */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      Torque_Control_ETR07_B.B = Torque_Control_ETR07_P.B_Value;
      Torque_Control_ETR07_B.Zero_m = Torque_Control_ETR07_P.Zero_Value;
    }

    /* Sum: '<S14>/Add' incorporates:
     *  Constant: '<S14>/B'
     *  Constant: '<S14>/Zero'
     *  Math: '<S14>/Math Function'
     *  Product: '<S14>/Product'
     *  Product: '<S14>/Product1'
     */
    rtb_Add_j = (rtb_Gain * rtb_Gain * Torque_Control_ETR07_B.Merge1_lz +
                 rtb_Gain * Torque_Control_ETR07_B.B) +
      Torque_Control_ETR07_B.Merge2_b;

    /* If: '<S14>/If' */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      rtAction = (int8_T)!(rtb_Gain == 0.0);
      Torque_Control_ETR07_DW.If_ActiveSubsystem_k2 = rtAction;
    } else {
      rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_k2;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S14>/Is_Zero' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      Torque_Control_ETR07_Is_Zero(Torque_Control_ETR07_B.Zero_m,
        &Torque_Control_ETR07_B.Merge_a);

      /* End of Outputs for SubSystem: '<S14>/Is_Zero' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S14>/Bypass_Torque' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      Torque_Control_ETR07_Is_Zero(rtb_Add_j, &Torque_Control_ETR07_B.Merge_a);

      /* End of Outputs for SubSystem: '<S14>/Bypass_Torque' */
      break;
    }

    /* End of If: '<S14>/If' */
    /* End of Outputs for SubSystem: '<S2>/KT_L_TORKY' */

    /* Gain: '<S2>/Gain' */
    Torque_Control_ETR07_B.Merge1_a0 = Torque_Control_ETR07_P.Gain_Gain *
      Torque_Control_ETR07_B.Merge_a;

    /* Outputs for Atomic SubSystem: '<S2>/KT_R_EMY' */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      Torque_Control_ETR07_B.A1 = Torque_Control_ETR07_P.A1_Value;
      Torque_Control_ETR07_B.C1 = Torque_Control_ETR07_P.C1_Value;
    }

    /* If: '<S15>/If1' incorporates:
     *  Constant: '<S15>/A1'
     *  Constant: '<S15>/C1'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      rtAction = (int8_T)!(rtb_Merge_d >= 0.0);
      Torque_Control_ETR07_DW.If1_ActiveSubsystem_k = rtAction;
    } else {
      rtAction = Torque_Control_ETR07_DW.If1_ActiveSubsystem_k;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S15>/Bypass' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      Torque_Control_ETR07_Bypass(Torque_Control_ETR07_B.A1,
        Torque_Control_ETR07_B.C1, &Torque_Control_ETR07_B.Merge1_i,
        &Torque_Control_ETR07_B.Merge2_g);

      /* End of Outputs for SubSystem: '<S15>/Bypass' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S15>/Negative' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      Torque_Control_ETR07_Negative(Torque_Control_ETR07_B.A1,
        Torque_Control_ETR07_B.C1, &Torque_Control_ETR07_B.Merge1_i,
        &Torque_Control_ETR07_B.Merge2_g, &Torque_Control_ETR07_P.Negative_k);

      /* End of Outputs for SubSystem: '<S15>/Negative' */
      break;
    }

    /* End of If: '<S15>/If1' */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      Torque_Control_ETR07_B.B1 = Torque_Control_ETR07_P.B1_Value;
      Torque_Control_ETR07_B.Zero_p = Torque_Control_ETR07_P.Zero_Value_p;
    }

    /* Sum: '<S15>/Add' incorporates:
     *  Constant: '<S15>/B1'
     *  Constant: '<S15>/Zero'
     *  Math: '<S15>/Math Function'
     *  Product: '<S15>/Product'
     *  Product: '<S15>/Product1'
     */
    rtb_Add_a = (rtb_Merge_d * rtb_Merge_d * Torque_Control_ETR07_B.Merge1_i +
                 rtb_Merge_d * Torque_Control_ETR07_B.B1) +
      Torque_Control_ETR07_B.Merge2_g;

    /* If: '<S15>/If' */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      rtAction = (int8_T)!(rtb_Merge_d == 0.0);
      Torque_Control_ETR07_DW.If_ActiveSubsystem_p = rtAction;
    } else {
      rtAction = Torque_Control_ETR07_DW.If_ActiveSubsystem_p;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S15>/Is_Zero' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      Torque_Control_ETR07_Is_Zero(Torque_Control_ETR07_B.Zero_p,
        &Torque_Control_ETR07_B.Merge2_e);

      /* End of Outputs for SubSystem: '<S15>/Is_Zero' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S15>/Bypass_Torque' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      Torque_Control_ETR07_Is_Zero(rtb_Add_a, &Torque_Control_ETR07_B.Merge2_e);

      /* End of Outputs for SubSystem: '<S15>/Bypass_Torque' */
      break;
    }

    /* End of If: '<S15>/If' */
    /* End of Outputs for SubSystem: '<S2>/KT_R_EMY' */
    /* End of Outputs for SubSystem: '<Root>/Calculate Current Conversion' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Current 0' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
      /* SignalConversion: '<S3>/OutportBufferForCurrent L' incorporates:
       *  Constant: '<S3>/Constant'
       */
      Torque_Control_ETR07_B.Merge1_a0 = Torque_Control_ETR07_P.Constant_Value;

      /* SignalConversion: '<S3>/OutportBufferForCurrent R' incorporates:
       *  Constant: '<S3>/Constant'
       */
      Torque_Control_ETR07_B.Merge2_e = Torque_Control_ETR07_P.Constant_Value;
    }

    /* End of Outputs for SubSystem: '<Root>/Current 0' */
    break;
  }

  /* End of If: '<Root>/If1' */

  /* Outport: '<Root>/current_L' */
  Torque_Control_ETR07_Y.current_L = Torque_Control_ETR07_B.Merge1_a0;

  /* Outport: '<Root>/current_R' */
  Torque_Control_ETR07_Y.current_R = Torque_Control_ETR07_B.Merge2_e;

  /* Abs: '<S7>/Abs' incorporates:
   *  Inport: '<Root>/ACCEL_F_X_SI'
   */
  Torque_Control_ETR07_B.Abs = fabs(Torque_Control_ETR07_U.ACCEL_F_X_SI);
}

/* Model update function */
void Torque_Control_ETR07_update(void)
{
  real_T *lastU;

  /* Update for If: '<S7>/If' */
  if (Torque_Control_ETR07_DW.If_ActiveSubsystem_k == 0) {
    /* Update for IfAction SubSystem: '<S7>/Vehicle Dynamics Control 2018' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    /* Update for If: '<S54>/FAILURE MODE' */
    switch (Torque_Control_ETR07_DW.FAILUREMODE_ActiveSubsystem) {
     case 0:
      /* Update for IfAction SubSystem: '<S54>/VDC 2018 Complete' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      /* Update for Derivative: '<S104>/Derivative' */
      if (Torque_Control_ETR07_DW.TimeStampA_g == (rtInf)) {
        Torque_Control_ETR07_DW.TimeStampA_g = Torque_Control_ETR07_M->Timing.t
          [0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA_c;
      } else if (Torque_Control_ETR07_DW.TimeStampB_c == (rtInf)) {
        Torque_Control_ETR07_DW.TimeStampB_c = Torque_Control_ETR07_M->Timing.t
          [0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeB_f;
      } else if (Torque_Control_ETR07_DW.TimeStampA_g <
                 Torque_Control_ETR07_DW.TimeStampB_c) {
        Torque_Control_ETR07_DW.TimeStampA_g = Torque_Control_ETR07_M->Timing.t
          [0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA_c;
      } else {
        Torque_Control_ETR07_DW.TimeStampB_c = Torque_Control_ETR07_M->Timing.t
          [0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeB_f;
      }

      *lastU = Torque_Control_ETR07_B.sf_MATLABFunction.RPM;

      /* End of Update for Derivative: '<S104>/Derivative' */
      /* End of Update for SubSystem: '<S54>/VDC 2018 Complete' */
      break;

     case 1:
      /* Update for IfAction SubSystem: '<S54>/VDC 2018 without Longitudinal' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      /* Update for Derivative: '<S162>/Derivative' */
      if (Torque_Control_ETR07_DW.TimeStampA_b == (rtInf)) {
        Torque_Control_ETR07_DW.TimeStampA_b = Torque_Control_ETR07_M->Timing.t
          [0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA_e;
      } else if (Torque_Control_ETR07_DW.TimeStampB_e == (rtInf)) {
        Torque_Control_ETR07_DW.TimeStampB_e = Torque_Control_ETR07_M->Timing.t
          [0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeB_o;
      } else if (Torque_Control_ETR07_DW.TimeStampA_b <
                 Torque_Control_ETR07_DW.TimeStampB_e) {
        Torque_Control_ETR07_DW.TimeStampA_b = Torque_Control_ETR07_M->Timing.t
          [0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA_e;
      } else {
        Torque_Control_ETR07_DW.TimeStampB_e = Torque_Control_ETR07_M->Timing.t
          [0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeB_o;
      }

      *lastU = Torque_Control_ETR07_B.sf_MATLABFunction_fa.RPM;

      /* End of Update for Derivative: '<S162>/Derivative' */
      /* End of Update for SubSystem: '<S54>/VDC 2018 without Longitudinal' */
      break;

     case 2:
      /* Update for IfAction SubSystem: '<S54>/Steering TV 2017 with TC' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      /* Update for Derivative: '<S77>/Derivative' */
      if (Torque_Control_ETR07_DW.TimeStampA == (rtInf)) {
        Torque_Control_ETR07_DW.TimeStampA = Torque_Control_ETR07_M->Timing.t[0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA;
      } else if (Torque_Control_ETR07_DW.TimeStampB == (rtInf)) {
        Torque_Control_ETR07_DW.TimeStampB = Torque_Control_ETR07_M->Timing.t[0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeB;
      } else if (Torque_Control_ETR07_DW.TimeStampA <
                 Torque_Control_ETR07_DW.TimeStampB) {
        Torque_Control_ETR07_DW.TimeStampA = Torque_Control_ETR07_M->Timing.t[0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeA;
      } else {
        Torque_Control_ETR07_DW.TimeStampB = Torque_Control_ETR07_M->Timing.t[0];
        lastU = &Torque_Control_ETR07_DW.LastUAtTimeB;
      }

      *lastU = Torque_Control_ETR07_B.sf_MATLABFunction_a.RPM;

      /* End of Update for Derivative: '<S77>/Derivative' */
      /* End of Update for SubSystem: '<S54>/Steering TV 2017 with TC' */
      break;

     case 3:
      break;
    }

    /* End of Update for If: '<S54>/FAILURE MODE' */
    /* End of Update for SubSystem: '<S7>/Vehicle Dynamics Control 2018' */
  }

  /* End of Update for If: '<S7>/If' */

  /* ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output */
  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
        (&Torque_Control_ETR07_M->solverInfo)) {
      rtsiSetSimTimeStep(&Torque_Control_ETR07_M->solverInfo,MINOR_TIME_STEP);
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&Torque_Control_ETR07_M->solverInfo, false);
      Torque_Control_ETR07_output();
      rtsiSetSimTimeStep(&Torque_Control_ETR07_M->solverInfo, MAJOR_TIME_STEP);
    }
  }

  if (rtmIsMajorTimeStep(Torque_Control_ETR07_M)) {
    rt_ertODEUpdateContinuousStates(&Torque_Control_ETR07_M->solverInfo);
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
  if (!(++Torque_Control_ETR07_M->Timing.clockTick0)) {
    ++Torque_Control_ETR07_M->Timing.clockTickH0;
  }

  Torque_Control_ETR07_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Torque_Control_ETR07_M->solverInfo);

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
    if (!(++Torque_Control_ETR07_M->Timing.clockTick1)) {
      ++Torque_Control_ETR07_M->Timing.clockTickH1;
    }

    Torque_Control_ETR07_M->Timing.t[1] =
      Torque_Control_ETR07_M->Timing.clockTick1 *
      Torque_Control_ETR07_M->Timing.stepSize1 +
      Torque_Control_ETR07_M->Timing.clockTickH1 *
      Torque_Control_ETR07_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Torque_Control_ETR07_derivatives(void)
{
  XDot_Torque_Control_ETR07_T *_rtXdot;
  _rtXdot = ((XDot_Torque_Control_ETR07_T *) Torque_Control_ETR07_M->derivs);

  /* Derivatives for If: '<S7>/If' */
  ((XDot_Torque_Control_ETR07_T *) Torque_Control_ETR07_M->derivs)
    ->Integrator_CSTATE = 0.0;
  if (Torque_Control_ETR07_DW.If_ActiveSubsystem_k == 0) {
    /* Derivatives for IfAction SubSystem: '<S7>/Vehicle Dynamics Control 2018' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    /* Derivatives for If: '<S54>/FAILURE MODE' */
    ((XDot_Torque_Control_ETR07_T *) Torque_Control_ETR07_M->derivs)
      ->Integrator_CSTATE = 0.0;
    if (Torque_Control_ETR07_DW.FAILUREMODE_ActiveSubsystem == 0) {
      /* Derivatives for IfAction SubSystem: '<S54>/VDC 2018 Complete' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      /* Derivatives for If: '<S68>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
      ((XDot_Torque_Control_ETR07_T *) Torque_Control_ETR07_M->derivs)
        ->Integrator_CSTATE = 0.0;
      if (Torque_Control_ETR07_DW.Steer_angisinSteer_SatrangeLong == 1) {
        /* Derivatives for IfAction SubSystem: '<S68>/Lateral Dynamics' incorporates:
         *  ActionPort: '<S100>/Action Port'
         */
        /* Derivatives for Integrator: '<S100>/Integrator' */
        _rtXdot->Integrator_CSTATE = Torque_Control_ETR07_B.Abs;

        /* End of Derivatives for SubSystem: '<S68>/Lateral Dynamics' */
      }

      /* End of Derivatives for If: '<S68>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
      /* End of Derivatives for SubSystem: '<S54>/VDC 2018 Complete' */
    }

    /* End of Derivatives for If: '<S54>/FAILURE MODE' */
    /* End of Derivatives for SubSystem: '<S7>/Vehicle Dynamics Control 2018' */
  }

  /* End of Derivatives for If: '<S7>/If' */
}

/* Model initialize function */
void Torque_Control_ETR07_initialize(void)
{
  /* Start for If: '<S30>/If2' */
  Torque_Control_ETR07_DW.If2_ActiveSubsystem = -1;

  /* Start for If: '<S30>/If3' */
  Torque_Control_ETR07_DW.If3_ActiveSubsystem = -1;

  /* Start for If: '<S30>/MEMO1' */
  Torque_Control_ETR07_DW.MEMO1_ActiveSubsystem = -1;

  /* Start for DataStoreMemory: '<S30>/Data Store Memory1' */
  Torque_Control_ETR07_DW.AA =
    Torque_Control_ETR07_P.DataStoreMemory1_InitialValu_fl;

  /* Start for If: '<S29>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem = -1;

  /* Start for Atomic SubSystem: '<S6>/Low Pass' */
  /* Start for DataStoreMemory: '<S41>/Data Store Memory' */
  Torque_Control_ETR07_DW.Previous_IN =
    Torque_Control_ETR07_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<S41>/Data Store Memory1' */
  Torque_Control_ETR07_DW.Previous_OUT =
    Torque_Control_ETR07_P.DataStoreMemory1_InitialValue;

  /* End of Start for SubSystem: '<S6>/Low Pass' */

  /* Start for Atomic SubSystem: '<S7>/TEST_MODE_IN' */
  /* Start for If: '<S53>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S7>/TEST_MODE_IN' */

  /* Start for Atomic SubSystem: '<S7>/Regeneration_Enable' */
  /* Start for If: '<S52>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S52>/Not-Braking' */
  /* Start for If: '<S58>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_i = -1;

  /* Start for If: '<S58>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S52>/Not-Braking' */

  /* Start for If: '<S52>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_o = -1;

  /* Start for DataStoreMemory: '<S52>/Data Store Memory' */
  Torque_Control_ETR07_DW.R =
    Torque_Control_ETR07_P.DataStoreMemory_InitialValue_j;

  /* End of Start for SubSystem: '<S7>/Regeneration_Enable' */

  /* Start for If: '<S7>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_k = -1;

  /* Start for IfAction SubSystem: '<S7>/Vehicle Dynamics Control 2018' */
  /* Start for Constant: '<S54>/Steering Wheel Saturation (per site) [deg] ' */
  Torque_Control_ETR07_B.SteeringWheelSaturationpersited =
    Torque_Control_ETR07_P.SteeringWheelSaturationpersited;

  /* Start for If: '<S54>/FAILURE MODE' */
  Torque_Control_ETR07_DW.FAILUREMODE_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S54>/VDC 2018 Complete' */
  /* Start for Constant: '<S141>/Steering Wheel Maximum Angle' */
  Torque_Control_ETR07_B.SteeringWheelMaximumAngle_p =
    Torque_Control_ETR07_P.SteeringWheelMaximumAngle_Value;

  /* Start for If: '<S141>/SKF or CKF' */
  Torque_Control_ETR07_DW.SKForCKF_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S141>/SKF' */
  /* Start for If: '<S144>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_ha = -1;

  /* End of Start for SubSystem: '<S141>/SKF' */

  /* Start for IfAction SubSystem: '<S141>/CKF' */
  /* Start for If: '<S142>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_o = -1;

  /* End of Start for SubSystem: '<S141>/CKF' */

  /* Start for DataStoreMemory: '<S104>/Data Store Memory' */
  Torque_Control_ETR07_DW.A_b =
    Torque_Control_ETR07_P.DataStoreMemory_InitialValue_c;

  /* Start for DataStoreMemory: '<S104>/Data Store Memory1' */
  Torque_Control_ETR07_DW.B_i =
    Torque_Control_ETR07_P.DataStoreMemory1_InitialValue_i;

  /* Start for Constant: '<S68>/Constant' */
  Torque_Control_ETR07_B.Constant_p = Torque_Control_ETR07_P.Constant_Value_b;

  /* Start for Constant: '<S99>/Maximum Torque per engine [Nm]' */
  Torque_Control_ETR07_B.MaximumTorqueperengineNm_m =
    Torque_Control_ETR07_P.MaximumTorqueperengineNm_Value;

  /* Start for Constant: '<S106>/Constant1' */
  Torque_Control_ETR07_B.Constant1_i = Torque_Control_ETR07_P.Constant1_Value_ab;

  /* Start for If: '<S68>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
  Torque_Control_ETR07_DW.Steer_angisinSteer_SatrangeLong = -1;

  /* Start for IfAction SubSystem: '<S68>/Longitudinal Dynamics' */
  /* Start for Constant: '<S101>/Constant' */
  Torque_Control_ETR07_B.Constant_mf = Torque_Control_ETR07_P.Constant_Value_f;

  /* Start for Constant: '<S101>/Constant3' */
  Torque_Control_ETR07_B.Constant3_e = Torque_Control_ETR07_P.Constant3_Value;

  /* Start for Constant: '<S101>/Constant4' */
  Torque_Control_ETR07_B.Constant4_m = Torque_Control_ETR07_P.Constant4_Value;

  /* End of Start for SubSystem: '<S68>/Longitudinal Dynamics' */

  /* Start for IfAction SubSystem: '<S68>/Lateral Dynamics' */
  /* Start for Constant: '<S100>/Constant3' */
  Torque_Control_ETR07_B.Constant3 = Torque_Control_ETR07_P.Constant3_Value_o;

  /* Start for Constant: '<S100>/Constant4' */
  Torque_Control_ETR07_B.Constant4 = Torque_Control_ETR07_P.Constant4_Value_p;

  /* Start for Constant: '<S130>/Constant8' */
  Torque_Control_ETR07_B.Constant8 = Torque_Control_ETR07_P.Constant8_Value;

  /* Start for Constant: '<S130>/Constant7' */
  Torque_Control_ETR07_B.Constant7 = Torque_Control_ETR07_P.Constant7_Value;

  /* Start for Constant: '<S130>/Wheelbase [m]' */
  Torque_Control_ETR07_B.Wheelbasem = Torque_Control_ETR07_P.Wheelbasem_Value;

  /* End of Start for SubSystem: '<S68>/Lateral Dynamics' */

  /* Start for Constant: '<S106>/Constant' */
  Torque_Control_ETR07_B.Constant_b = Torque_Control_ETR07_P.Constant_Value_l;

  /* Start for Constant: '<S99>/Tq_diff_Max' */
  Torque_Control_ETR07_B.Tq_diff_Max = Torque_Control_ETR07_P.Tq_diff_Max_Value;

  /* Start for If: '<S97>/Braking Conditions' */
  Torque_Control_ETR07_DW.BrakingConditions_ActiveSubsy_b = -1;

  /* Start for If: '<S96>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_aq = -1;

  /* Start for IfAction SubSystem: '<S96>/Acelerating and braking without Regenerative' */
  /* Start for If: '<S107>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_bn = -1;

  /* Start for If: '<S107>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_f = -1;

  /* End of Start for SubSystem: '<S96>/Acelerating and braking without Regenerative' */
  /* End of Start for SubSystem: '<S54>/VDC 2018 Complete' */

  /* Start for IfAction SubSystem: '<S54>/VDC 2018 without Longitudinal' */
  /* Start for If: '<S187>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_a = -1;

  /* Start for DataStoreMemory: '<S162>/Data Store Memory1' */
  Torque_Control_ETR07_DW.B_k =
    Torque_Control_ETR07_P.DataStoreMemory1_InitialValue_m;

  /* Start for Constant: '<S159>/Maximum Torque per engine [Nm]' */
  Torque_Control_ETR07_B.MaximumTorqueperengineNm =
    Torque_Control_ETR07_P.MaximumTorqueperengineNm_Valu_b;

  /* Start for Constant: '<S164>/Constant' */
  Torque_Control_ETR07_B.Constant_e = Torque_Control_ETR07_P.Constant_Value_ib;

  /* Start for Constant: '<S160>/Constant1' */
  Torque_Control_ETR07_B.Constant1 = Torque_Control_ETR07_P.Constant1_Value_c;

  /* Start for Constant: '<S164>/Constant1' */
  Torque_Control_ETR07_B.Constant1_k = Torque_Control_ETR07_P.Constant1_Value_l;

  /* Start for Constant: '<S160>/Constant' */
  Torque_Control_ETR07_B.Constant_dd = Torque_Control_ETR07_P.Constant_Value_ae;

  /* Start for If: '<S158>/Braking Conditions' */
  Torque_Control_ETR07_DW.BrakingConditions_ActiveSubsyst = -1;

  /* Start for If: '<S157>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_h = -1;

  /* Start for IfAction SubSystem: '<S157>/Acelerating and braking without Regenerative' */
  /* Start for If: '<S165>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_bf = -1;

  /* Start for If: '<S165>/If2' */
  Torque_Control_ETR07_DW.If2_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S157>/Acelerating and braking without Regenerative' */
  /* End of Start for SubSystem: '<S54>/VDC 2018 without Longitudinal' */

  /* Start for IfAction SubSystem: '<S54>/Steering TV 2017 with TC' */
  /* Start for Constant: '<S84>/Steering Wheel Maximum Angle' */
  Torque_Control_ETR07_B.SteeringWheelMaximumAngle =
    Torque_Control_ETR07_P.SteeringWheelMaximumAngle_Val_o;

  /* Start for If: '<S84>/SKF or CKF' */
  Torque_Control_ETR07_DW.SKForCKF_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S84>/SKF' */
  /* Start for If: '<S87>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S84>/SKF' */

  /* Start for IfAction SubSystem: '<S84>/CKF' */
  /* Start for If: '<S85>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S84>/CKF' */

  /* Start for DataStoreMemory: '<S77>/Data Store Memory' */
  Torque_Control_ETR07_DW.A =
    Torque_Control_ETR07_P.DataStoreMemory_InitialValue_m;

  /* Start for DataStoreMemory: '<S77>/Data Store Memory1' */
  Torque_Control_ETR07_DW.B =
    Torque_Control_ETR07_P.DataStoreMemory1_InitialValue_f;

  /* Start for Constant: '<S67>/Steering Wheel Maximum Angle' */
  Torque_Control_ETR07_B.SteeringWheelMaximumAngle_m =
    Torque_Control_ETR07_P.SteeringWheelMaximumAngle_Val_i;

  /* Start for Constant: '<S67>/Tq_max [Nm]' */
  Torque_Control_ETR07_B.Tq_maxNm = Torque_Control_ETR07_P.Tq_maxNm_Value;

  /* Start for Constant: '<S67>/Tq_diff_max [Nm]' */
  Torque_Control_ETR07_B.Tq_diff_maxNm =
    Torque_Control_ETR07_P.Tq_diff_maxNm_Value;

  /* Start for If: '<S67>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_ds = -1;

  /* Start for If: '<S73>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_b = -1;

  /* End of Start for SubSystem: '<S54>/Steering TV 2017 with TC' */
  /* End of Start for SubSystem: '<S7>/Vehicle Dynamics Control 2018' */

  /* Start for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Start for DataStoreMemory: '<S9>/Data Store Memory10' */
  Torque_Control_ETR07_DW.A_i =
    Torque_Control_ETR07_P.DataStoreMemory10_InitialValue;

  /* End of Start for SubSystem: '<S1>/PowerLimitDetection' */

  /* Start for If: '<S4>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_d = -1;

  /* Start for Atomic SubSystem: '<S7>/WORKSHOP_MODE_RESTRICTIONS' */
  /* Start for If: '<S55>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S7>/WORKSHOP_MODE_RESTRICTIONS' */

  /* Start for If: '<Root>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<Root>/Calculate Current Conversion' */
  /* Start for Atomic SubSystem: '<S2>/KT_L_TORKY' */
  /* Start for If: '<S14>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_n = -1;

  /* Start for If: '<S14>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_k2 = -1;

  /* End of Start for SubSystem: '<S2>/KT_L_TORKY' */

  /* Start for Atomic SubSystem: '<S2>/KT_R_EMY' */
  /* Start for If: '<S15>/If1' */
  Torque_Control_ETR07_DW.If1_ActiveSubsystem_k = -1;

  /* Start for If: '<S15>/If' */
  Torque_Control_ETR07_DW.If_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S2>/KT_R_EMY' */
  /* End of Start for SubSystem: '<Root>/Calculate Current Conversion' */
  {
    int32_T i;

    /* SystemInitialize for Atomic SubSystem: '<S7>/Regeneration_Enable' */
    /* SystemInitialize for IfAction SubSystem: '<S52>/Not-Braking' */
    /* SystemInitialize for Merge: '<S58>/Merge' */
    Torque_Control_ETR07_B.Merge_h =
      Torque_Control_ETR07_P.Merge_InitialOutput_jq;

    /* End of SystemInitialize for SubSystem: '<S52>/Not-Braking' */
    /* End of SystemInitialize for SubSystem: '<S7>/Regeneration_Enable' */

    /* SystemInitialize for IfAction SubSystem: '<S7>/Vehicle Dynamics Control 2018' */
    /* SystemInitialize for IfAction SubSystem: '<S54>/VDC 2018 Complete' */
    /* InitializeConditions for Derivative: '<S104>/Derivative' */
    Torque_Control_ETR07_DW.TimeStampA_g = (rtInf);
    Torque_Control_ETR07_DW.TimeStampB_c = (rtInf);

    /* SystemInitialize for IfAction SubSystem: '<S141>/SKF' */
    /* SystemInitialize for Merge: '<S144>/Merge' */
    Torque_Control_ETR07_B.Merge_i = Torque_Control_ETR07_P.Merge_InitialOutput;

    /* SystemInitialize for Outport: '<S144>/SKF_act' */
    Torque_Control_ETR07_B.Saturation_f = Torque_Control_ETR07_P.SKF_act_Y0;

    /* End of SystemInitialize for SubSystem: '<S141>/SKF' */

    /* SystemInitialize for IfAction SubSystem: '<S141>/CKF' */
    /* SystemInitialize for Merge: '<S142>/Merge' */
    Torque_Control_ETR07_B.Merge_cu =
      Torque_Control_ETR07_P.Merge_InitialOutput_j;

    /* SystemInitialize for Outport: '<S142>/CKF_act ' */
    Torque_Control_ETR07_B.Saturation_i = Torque_Control_ETR07_P.CKF_act_Y0;

    /* End of SystemInitialize for SubSystem: '<S141>/CKF' */

    /* SystemInitialize for IfAction SubSystem: '<S68>/Lateral Dynamics' */
    /* InitializeConditions for Integrator: '<S100>/Integrator' */
    Torque_Control_ETR07_X.Integrator_CSTATE =
      Torque_Control_ETR07_P.Integrator_IC;

    /* End of SystemInitialize for SubSystem: '<S68>/Lateral Dynamics' */

    /* SystemInitialize for Merge: '<S68>/Merge2' */
    Torque_Control_ETR07_B.Merge2_lx =
      Torque_Control_ETR07_P.Merge2_InitialOutput;

    /* SystemInitialize for Merge: '<S68>/Merge3' */
    Torque_Control_ETR07_B.Merge3_e =
      Torque_Control_ETR07_P.Merge3_InitialOutput_j;

    /* SystemInitialize for IfAction SubSystem: '<S97>/Accelerating' */
    /* SystemInitialize for Outport: '<S120>/Out_Throttle' */
    Torque_Control_ETR07_B.Throttle = Torque_Control_ETR07_P.Out_Throttle_Y0;

    /* End of SystemInitialize for SubSystem: '<S97>/Accelerating' */

    /* SystemInitialize for Merge: '<S97>/Merge' */
    Torque_Control_ETR07_B.Merge_kt =
      Torque_Control_ETR07_P.Merge_InitialOutput_i;

    /* SystemInitialize for Merge: '<S97>/Merge1' */
    Torque_Control_ETR07_B.Merge1_b =
      Torque_Control_ETR07_P.Merge1_InitialOutput;

    /* SystemInitialize for IfAction SubSystem: '<S96>/Acelerating and braking without Regenerative' */
    /* SystemInitialize for Merge: '<S107>/Merge3' */
    Torque_Control_ETR07_B.Merge3_h =
      Torque_Control_ETR07_P.Merge3_InitialOutput;

    /* SystemInitialize for Merge: '<S107>/Merge4' */
    Torque_Control_ETR07_B.Merge4_b =
      Torque_Control_ETR07_P.Merge4_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S96>/Acelerating and braking without Regenerative' */

    /* SystemInitialize for Merge: '<S68>/Merge4' */
    Torque_Control_ETR07_B.Merge4 =
      Torque_Control_ETR07_P.Merge4_InitialOutput_d;

    /* SystemInitialize for Merge: '<S68>/Merge5' */
    Torque_Control_ETR07_B.Merge5_e =
      Torque_Control_ETR07_P.Merge5_InitialOutput;

    /* SystemInitialize for Merge: '<S68>/Merge6' */
    Torque_Control_ETR07_B.Merge6 = Torque_Control_ETR07_P.Merge6_InitialOutput;

    /* SystemInitialize for Merge: '<S68>/Merge7' */
    Torque_Control_ETR07_B.Merge7 = Torque_Control_ETR07_P.Merge7_InitialOutput;

    /* SystemInitialize for Outport: '<S68>/MaxTq_RR [Nm] (0,inf)' */
    Torque_Control_ETR07_B.Divide = Torque_Control_ETR07_P.MaxTq_RRNm0inf_Y0;

    /* SystemInitialize for Outport: '<S68>/MaxTq_RL [Nm] (0,inf)' */
    Torque_Control_ETR07_B.Divide_i = Torque_Control_ETR07_P.MaxTq_RLNm0inf_Y0;

    /* SystemInitialize for Outport: '<S68>/Flags_[num5]' */
    for (i = 0; i < 5; i++) {
      Torque_Control_ETR07_B.OutportBufferForFlags_num5[i] =
        Torque_Control_ETR07_P.Flags_num5_Y0;
    }

    /* End of SystemInitialize for Outport: '<S68>/Flags_[num5]' */
    /* End of SystemInitialize for SubSystem: '<S54>/VDC 2018 Complete' */

    /* SystemInitialize for IfAction SubSystem: '<S54>/VDC 2018 without Longitudinal' */
    /* InitializeConditions for Derivative: '<S162>/Derivative' */
    Torque_Control_ETR07_DW.TimeStampA_b = (rtInf);
    Torque_Control_ETR07_DW.TimeStampB_e = (rtInf);

    /* SystemInitialize for Merge: '<S187>/Merge' */
    Torque_Control_ETR07_B.Merge_g =
      Torque_Control_ETR07_P.Merge_InitialOutput_h;

    /* SystemInitialize for IfAction SubSystem: '<S158>/Accelerating' */
    /* SystemInitialize for Outport: '<S177>/Out_Throttle' */
    Torque_Control_ETR07_B.sf_Acceleratorbehaviour_b.throttle =
      Torque_Control_ETR07_P.Out_Throttle_Y0_a;

    /* End of SystemInitialize for SubSystem: '<S158>/Accelerating' */

    /* SystemInitialize for Merge: '<S158>/Merge' */
    Torque_Control_ETR07_B.Merge_l =
      Torque_Control_ETR07_P.Merge_InitialOutput_l;

    /* SystemInitialize for Merge: '<S158>/Merge1' */
    Torque_Control_ETR07_B.Merge1_l =
      Torque_Control_ETR07_P.Merge1_InitialOutput_k;

    /* SystemInitialize for Outport: '<S69>/MaxFx_RR [N] (0,inf)' */
    Torque_Control_ETR07_B.sf_MATLABFunction2_b.value =
      Torque_Control_ETR07_P.MaxFx_RRN0inf_Y0;

    /* SystemInitialize for Outport: '<S69>/MaxFx_RL [N] (0,inf)' */
    Torque_Control_ETR07_B.sf_MATLABFunction1_f.value =
      Torque_Control_ETR07_P.MaxFx_RLN0inf_Y0;

    /* End of SystemInitialize for SubSystem: '<S54>/VDC 2018 without Longitudinal' */

    /* SystemInitialize for IfAction SubSystem: '<S54>/Steering TV 2017 with TC' */
    /* InitializeConditions for Derivative: '<S77>/Derivative' */
    Torque_Control_ETR07_DW.TimeStampA = (rtInf);
    Torque_Control_ETR07_DW.TimeStampB = (rtInf);

    /* SystemInitialize for IfAction SubSystem: '<S84>/SKF' */
    /* SystemInitialize for Merge: '<S87>/Merge' */
    Torque_Control_ETR07_B.Merge_kj =
      Torque_Control_ETR07_P.Merge_InitialOutput_p;

    /* SystemInitialize for Outport: '<S87>/SKF_act' */
    Torque_Control_ETR07_B.Saturation_k = Torque_Control_ETR07_P.SKF_act_Y0_l;

    /* End of SystemInitialize for SubSystem: '<S84>/SKF' */

    /* SystemInitialize for IfAction SubSystem: '<S84>/CKF' */
    /* SystemInitialize for Merge: '<S85>/Merge' */
    Torque_Control_ETR07_B.Merge_k =
      Torque_Control_ETR07_P.Merge_InitialOutput_a;

    /* SystemInitialize for Outport: '<S85>/CKF_act ' */
    Torque_Control_ETR07_B.Saturation = Torque_Control_ETR07_P.CKF_act_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S84>/CKF' */
    /* End of SystemInitialize for SubSystem: '<S54>/Steering TV 2017 with TC' */

    /* SystemInitialize for Merge: '<S54>/Merge' */
    Torque_Control_ETR07_B.Merge_c =
      Torque_Control_ETR07_P.Merge_InitialOutput_pp;

    /* SystemInitialize for Merge: '<S54>/Merge1' */
    Torque_Control_ETR07_B.Merge1_m =
      Torque_Control_ETR07_P.Merge1_InitialOutput_f;

    /* SystemInitialize for Merge: '<S54>/Merge2' */
    Torque_Control_ETR07_B.Merge2_l =
      Torque_Control_ETR07_P.Merge2_InitialOutput_o;

    /* SystemInitialize for Merge: '<S54>/Merge3' */
    Torque_Control_ETR07_B.Merge3_c =
      Torque_Control_ETR07_P.Merge3_InitialOutput_n;

    /* End of SystemInitialize for SubSystem: '<S7>/Vehicle Dynamics Control 2018' */
  }
}

/* Model terminate function */
void Torque_Control_ETR07_terminate(void)
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
  Torque_Control_ETR07_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Torque_Control_ETR07_update();
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
  Torque_Control_ETR07_initialize();
}

void MdlTerminate(void)
{
  Torque_Control_ETR07_terminate();
}

/* Registration function */
RT_MODEL_Torque_Control_ETR07_T *Torque_Control_ETR07(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Torque_Control_ETR07_M, 0,
                sizeof(RT_MODEL_Torque_Control_ETR07_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Torque_Control_ETR07_M->solverInfo,
                          &Torque_Control_ETR07_M->Timing.simTimeStep);
    rtsiSetTPtr(&Torque_Control_ETR07_M->solverInfo, &rtmGetTPtr
                (Torque_Control_ETR07_M));
    rtsiSetStepSizePtr(&Torque_Control_ETR07_M->solverInfo,
                       &Torque_Control_ETR07_M->Timing.stepSize0);
    rtsiSetdXPtr(&Torque_Control_ETR07_M->solverInfo,
                 &Torque_Control_ETR07_M->derivs);
    rtsiSetContStatesPtr(&Torque_Control_ETR07_M->solverInfo, (real_T **)
                         &Torque_Control_ETR07_M->contStates);
    rtsiSetNumContStatesPtr(&Torque_Control_ETR07_M->solverInfo,
      &Torque_Control_ETR07_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Torque_Control_ETR07_M->solverInfo,
      &Torque_Control_ETR07_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Torque_Control_ETR07_M->solverInfo,
      &Torque_Control_ETR07_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Torque_Control_ETR07_M->solverInfo,
      &Torque_Control_ETR07_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Torque_Control_ETR07_M->solverInfo,
                          (&rtmGetErrorStatus(Torque_Control_ETR07_M)));
    rtsiSetRTModelPtr(&Torque_Control_ETR07_M->solverInfo,
                      Torque_Control_ETR07_M);
  }

  rtsiSetSimTimeStep(&Torque_Control_ETR07_M->solverInfo, MAJOR_TIME_STEP);
  Torque_Control_ETR07_M->intgData.y = Torque_Control_ETR07_M->odeY;
  Torque_Control_ETR07_M->intgData.f[0] = Torque_Control_ETR07_M->odeF[0];
  Torque_Control_ETR07_M->intgData.f[1] = Torque_Control_ETR07_M->odeF[1];
  Torque_Control_ETR07_M->intgData.f[2] = Torque_Control_ETR07_M->odeF[2];
  Torque_Control_ETR07_M->contStates = ((real_T *) &Torque_Control_ETR07_X);
  rtsiSetSolverData(&Torque_Control_ETR07_M->solverInfo, (void *)
                    &Torque_Control_ETR07_M->intgData);
  rtsiSetSolverName(&Torque_Control_ETR07_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Torque_Control_ETR07_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Torque_Control_ETR07_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Torque_Control_ETR07_M->Timing.sampleTimes =
      (&Torque_Control_ETR07_M->Timing.sampleTimesArray[0]);
    Torque_Control_ETR07_M->Timing.offsetTimes =
      (&Torque_Control_ETR07_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Torque_Control_ETR07_M->Timing.sampleTimes[0] = (0.0);
    Torque_Control_ETR07_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    Torque_Control_ETR07_M->Timing.offsetTimes[0] = (0.0);
    Torque_Control_ETR07_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Torque_Control_ETR07_M, &Torque_Control_ETR07_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Torque_Control_ETR07_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Torque_Control_ETR07_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Torque_Control_ETR07_M, 10.0);
  Torque_Control_ETR07_M->Timing.stepSize0 = 0.2;
  Torque_Control_ETR07_M->Timing.stepSize1 = 0.2;
  Torque_Control_ETR07_M->solverInfoPtr = (&Torque_Control_ETR07_M->solverInfo);
  Torque_Control_ETR07_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Torque_Control_ETR07_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Torque_Control_ETR07_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Torque_Control_ETR07_M->blockIO = ((void *) &Torque_Control_ETR07_B);
  (void) memset(((void *) &Torque_Control_ETR07_B), 0,
                sizeof(B_Torque_Control_ETR07_T));

  /* parameters */
  Torque_Control_ETR07_M->defaultParam = ((real_T *)&Torque_Control_ETR07_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Torque_Control_ETR07_X;
    Torque_Control_ETR07_M->contStates = (x);
    (void) memset((void *)&Torque_Control_ETR07_X, 0,
                  sizeof(X_Torque_Control_ETR07_T));
  }

  /* states (dwork) */
  Torque_Control_ETR07_M->dwork = ((void *) &Torque_Control_ETR07_DW);
  (void) memset((void *)&Torque_Control_ETR07_DW, 0,
                sizeof(DW_Torque_Control_ETR07_T));

  /* external inputs */
  Torque_Control_ETR07_M->inputs = (((void*)&Torque_Control_ETR07_U));
  (void)memset((void *)&Torque_Control_ETR07_U, 0, sizeof
               (ExtU_Torque_Control_ETR07_T));

  /* external outputs */
  Torque_Control_ETR07_M->outputs = (&Torque_Control_ETR07_Y);
  (void) memset((void *)&Torque_Control_ETR07_Y, 0,
                sizeof(ExtY_Torque_Control_ETR07_T));

  /* Initialize Sizes */
  Torque_Control_ETR07_M->Sizes.numContStates = (1);/* Number of continuous states */
  Torque_Control_ETR07_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Torque_Control_ETR07_M->Sizes.numY = (33);/* Number of model outputs */
  Torque_Control_ETR07_M->Sizes.numU = (40);/* Number of model inputs */
  Torque_Control_ETR07_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Torque_Control_ETR07_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Torque_Control_ETR07_M->Sizes.numBlocks = (627);/* Number of blocks */
  Torque_Control_ETR07_M->Sizes.numBlockIO = (156);/* Number of block outputs */
  Torque_Control_ETR07_M->Sizes.numBlockPrms = (221);/* Sum of parameter "widths" */
  return Torque_Control_ETR07_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
