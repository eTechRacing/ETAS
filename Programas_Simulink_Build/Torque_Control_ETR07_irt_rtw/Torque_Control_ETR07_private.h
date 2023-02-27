/*
 * Torque_Control_ETR07_private.h
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

#ifndef RTW_HEADER_Torque_Control_ETR07_private_h_
#define RTW_HEADER_Torque_Control_ETR07_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Torque_Control_ETR07.h"

extern void Torque_Control_ETR_LimitReached(real_T *rty_Out,
  P_LimitReached_Torque_Control_T *localP);
extern void Torque_Control_ETR07_Is_Zero(real_T rtu_In1, real_T *rty_Out1);
extern void Torque_Control_ETR07_Bypass(real_T rtu_In1, real_T rtu_In2, real_T
  *rty_Out1, real_T *rty_Out2);
extern void Torque_Control_ETR07_Negative(real_T rtu_In1, real_T rtu_In2, real_T
  *rty_Out1, real_T *rty_Out2, P_Negative_Torque_Control_ETR_T *localP);
extern void Torque_Control_ETR07_Imp(boolean_T *rty_Out1,
  P_Imp_Torque_Control_ETR07_T *localP);
extern void Torque_Contr_IfActionSubsystem2(real_T *rty_Out1,
  P_IfActionSubsystem2_Torque_C_T *localP);
extern void Torque_Con_ControldeTemperatura(RT_MODEL_Torque_Control_ETR07_T *
  const Torque_Control_ETR07_M, real_T rtu_Tq_RR, real_T rtu_Tq_RL, real_T
  rtu_ReductionCte, real_T *rty_Tq_RR_out, real_T *rty_Tq_RL_out, real_T
  *rty_Flag_Temperature, real_T *rty_Flag_Power, P_ControldeTemperatura_Torque_T
  *localP);
extern void Torque_Control_ETR07_IfAction1(real_T rtu_Trans_max_dynamic, real_T *
  rty_Trans_limit);
extern void Torque_Control_ETR07_IfAction2(real_T rtu_Trans_max_static, real_T
  *rty_Trans_limit);
extern void Torque_Control_ETR_minimumvalue(real_T rtu_a, real_T rtu_b, real_T
  rtu_c, B_minimumvalue_Torque_Control_T *localB);
extern void Torque_Control_ET_minimumvalue1(real_T rtu_a, real_T rtu_b, real_T
  rtu_c, B_minimumvalue1_Torque_Contro_T *localB);
extern void Torque_Con_Acceleratorbehaviour(real_T rtu_Ap, real_T rtu_Ap_Sat_up,
  real_T rtu_Ap_Sat_down, B_Acceleratorbehaviour_Torque_T *localB);
extern void Torque__RegenerativeMechBraking(real_T rtu_RegTq_RR, real_T
  rtu_RegTq_RL, real_T *rty_Tq_RR, real_T *rty_Tq_RL);
extern void Torque_Control_ETR_Mech_Braking(real_T *rty_Tq_RR, real_T *rty_Tq_RL,
  P_Mech_Braking_Torque_Control_T *localP);
extern void Torque_Control__MATLABFunction1(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction1_Torque_Cont_T *localB);
extern void Torque_Control_E_MATLABFunction(real_T rtu_RPM_INV1, real_T
  rtu_RPM_INV2, B_MATLABFunction_Torque_Contr_T *localB);
extern void Torque_Control_MATLABFunction_m(real_T rtu_SKF_Initial, real_T
  rtu_SKF_prev, B_MATLABFunction_Torque_Con_d_T *localB);
extern void Torque_Control_MATLABFunction_d(real_T rtu_SKF_prev, real_T
  rtu_SKF_Initial, B_MATLABFunction_Torque_Co_ds_T *localB);
extern void Torque_Contro_MATLABFunction_mt(real_T rtu_CKF_Initial, real_T
  rtu_CKF_prev, B_MATLABFunction_Torque_Con_k_T *localB);
extern void Torque_Control_ETR07_Spin(RT_MODEL_Torque_Control_ETR07_T * const
  Torque_Control_ETR07_M, real_T rtu_CKF_prev, real_T rtu_CKF_Initial, real_T
  rtu_Cte_CKF, real_T *rty_CKF_act1, B_Spin_Torque_Control_ETR07_T *localB,
  P_Spin_Torque_Control_ETR07_T *localP);
extern void Torque_Control_MATLABFunction_b(real_T rtu_CKF_prev, real_T
  rtu_CKF_Initial, B_MATLABFunction_Torque_Con_n_T *localB);
extern void Torque_Control_ETR07_Nospin(real_T rtu_CKF_Initial, real_T
  rtu_CKF_prev, real_T *rty_CKF_act0, B_Nospin_Torque_Control_ETR07_T *localB,
  P_Nospin_Torque_Control_ETR07_T *localP);
extern void Torque_Contro_MATLABFunction_d1(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction_Torque_Con_h_T *localB);
extern void Torque_Contro_MATLABFunction1_m(real_T rtu_cte, real_T rtu_v,
  B_MATLABFunction1_Torque_Co_d_T *localB);
extern void Torque_Co_ControldeTemperatura1(real_T rtu_Tq_RR, real_T rtu_Tq_RL,
  real_T rtu_ReductionCte, real_T *rty_Tq_RR_out, real_T *rty_Tq_RL_out);
extern void Torque_Control_ETR07_else1(real_T rtu_Tq_RR, real_T rtu_Tq_RL,
  real_T *rty_Tq_RR_out, real_T *rty_Tq_RL_out);
extern void Torque_Control_ETR07_Temp_LIMIT(real_T *rty_Out1,
  P_Temp_LIMIT_Torque_Control_E_T *localP);

/* private model entry point functions */
extern void Torque_Control_ETR07_derivatives(void);

#endif                                 /* RTW_HEADER_Torque_Control_ETR07_private_h_ */
