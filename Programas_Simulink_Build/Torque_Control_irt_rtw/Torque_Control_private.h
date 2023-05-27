/*
 * Torque_Control_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 1.181
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 13:03:35 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torque_Control_private_h_
#define RTW_HEADER_Torque_Control_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Torque_Control.h"

extern void Torque_Control_LimitReached(real_T *rty_Out,
  P_LimitReached_Torque_Control_T *localP);
extern void Torque_Control_Imp(boolean_T *rty_Out1, P_Imp_Torque_Control_T
  *localP);
extern void Torque_Contr_IfActionSubsystem2(real_T *rty_Out1,
  P_IfActionSubsystem2_Torque_C_T *localP);
extern void Torque_Control_MATLABFunction(real_T rtu_MaxRegenTq, real_T
  rtu_Tq_RR, real_T rtu_Tq_RL, B_MATLABFunction_Torque_Contr_T *localB);
extern void Torque__BrakingwithRegenerative(real_T rtu_MaxRegTorque, real_T
  rtu_Tq_RR_wc, real_T rtu_Tq_RL_wc, real_T *rty_TQ_RR, real_T *rty_TQ_RL,
  B_BrakingwithRegenerative_Tor_T *localB, P_BrakingwithRegenerative_Tor_T
  *localP);
extern void Torque_Control_IfAction1(real_T rtu_Trans_max_dynamic, real_T
  *rty_Trans_limit);
extern void Torque_Control_IfAction2(real_T rtu_Trans_max_static, real_T
  *rty_Trans_limit);
extern void Torque_Con_Acceleratorbehaviour(real_T rtu_Ap, real_T rtu_Ap_Sat_up,
  real_T rtu_Ap_Sat_down, B_Acceleratorbehaviour_Torque_T *localB);
extern void Torque_Control_Mech_Braking(real_T *rty_Tq_RR, real_T *rty_Tq_RL,
  P_Mech_Braking_Torque_Control_T *localP);
extern void Torque_Control_MATLABFunction1(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction1_Torque_Cont_T *localB);
extern void Torque_Control_MATLABFunction_n(real_T rtu_RPM_INV1, real_T
  rtu_RPM_INV2, B_MATLABFunction_Torque_Con_d_T *localB);
extern void Torque_Control_MATLABFunction_e(real_T rtu_SKF_prev, real_T
  rtu_SKF_Initial, real_T rtu_Cte_SKF, B_MATLABFunction_Torque_Con_i_T *localB);
extern void Torque_Control_MATLABFunction_m(real_T rtu_CKF_Initial, real_T
  rtu_CKF_prev, B_MATLABFunction_Torque_Con_k_T *localB);
extern void Torque_Contro_MATLABFunction1_b(real_T rtu_CKF_prev, real_T
  rtu_CKF_Initial, real_T rtu_Cte_CKF, B_MATLABFunction1_Torque_Co_m_T *localB);
extern void Torque_Control_MATLABFunction_d(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction_Torque_Con_h_T *localB);
extern void Torque_Contro_MATLABFunction1_m(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction1_Torque_Co_d_T *localB);
extern void Torque_Con_AutomaticFailureMode(real_T rtu_In1, real_T *rty_Out1);

/* private model entry point functions */
extern void Torque_Control_derivatives(void);

#endif                                 /* RTW_HEADER_Torque_Control_private_h_ */
