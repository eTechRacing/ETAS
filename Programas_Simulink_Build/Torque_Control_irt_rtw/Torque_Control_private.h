/*
 * Torque_Control_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 10.1
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Fri Nov 17 17:17:31 2023
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
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Torque_Control.h"

extern const real_T rtCP_pooled_fFBPNM5D93Ka[8];
extern const real_T rtCP_pooled_8oEGUoNOK7a6[8];
extern const real_T rtCP_pooled_jAHddqT0PSxE[8];
extern const real_T rtCP_pooled_NnEYGkkOrFx5[8];
extern const real_T rtCP_pooled_pHAQwZ36IjIp[5];
extern const real_T rtCP_pooled_0L8nz406VW9z[5];

#define rtCP_Lookup_SoC_SoP_dischg_tabl rtCP_pooled_fFBPNM5D93Ka /* Expression: [0.4 0.6 0.8 0.95 1 1 0.98 0.95]
                                                                  * Referenced by: '<S22>/Lookup_SoC_SoP_dischg'
                                                                  */
#define rtCP_Lookup_SoC_SoP_dischg_bp01 rtCP_pooled_8oEGUoNOK7a6 /* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.9 1]
                                                                  * Referenced by: '<S22>/Lookup_SoC_SoP_dischg'
                                                                  */
#define rtCP_Lookup_SoC_SoP_chg_tableDa rtCP_pooled_jAHddqT0PSxE /* Expression: [0.95 1 1 1 1 0.9 0.75 0.02]
                                                                  * Referenced by: '<S22>/Lookup_SoC_SoP_chg'
                                                                  */
#define rtCP_Lookup_SoC_SoP_chg_bp01Dat rtCP_pooled_NnEYGkkOrFx5 /* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.95 1]
                                                                  * Referenced by: '<S22>/Lookup_SoC_SoP_chg'
                                                                  */
#define rtCP_Lookup_Temp_SoP_chg_tableD rtCP_pooled_pHAQwZ36IjIp /* Expression: [1 0.75 0.5 0 0]
                                                                  * Referenced by: '<S22>/Lookup_Temp_SoP_chg'
                                                                  */
#define rtCP_Lookup_Temp_SoP_chg_bp01Da rtCP_pooled_0L8nz406VW9z /* Expression: [45 48 49 50 51]
                                                                  * Referenced by: '<S22>/Lookup_Temp_SoP_chg'
                                                                  */

extern void Torque_Control_LimitReached(RT_MODEL_Torque_Control_T * const
  Torque_Control_M, real_T *rty_Out);
extern void Torque_Control_MATLABFunction(real_T rtu_MaxRegenTq, real_T
  rtu_Tq_RR, real_T rtu_Tq_RL, B_MATLABFunction_Torque_Contr_T *localB);
extern void Torque__BrakingwithRegenerative(real_T rtu_MaxRegTorque, real_T
  rtu_Tq_RR_wc, real_T rtu_Tq_RL_wc, real_T *rty_TQ_RR, real_T *rty_TQ_RL,
  B_BrakingwithRegenerative_Tor_T *localB);
extern void Torque_Control_IfAction1(RT_MODEL_Torque_Control_T * const
  Torque_Control_M, real_T rtu_Trans_max_dynamic, real_T *rty_Trans_limit);
extern void Torque_Control_IfAction2(RT_MODEL_Torque_Control_T * const
  Torque_Control_M, real_T rtu_Trans_max_static, real_T *rty_Trans_limit);
extern void Torque_Con_Acceleratorbehaviour(real_T rtu_Ap, real_T rtu_Ap_Sat_up,
  real_T rtu_Ap_Sat_down, B_Acceleratorbehaviour_Torque_T *localB);
extern void Torque_Control_Mech_Braking(RT_MODEL_Torque_Control_T * const
  Torque_Control_M, real_T *rty_Tq_RR, real_T *rty_Tq_RL);
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
extern void Torque_Control_Enabled(RT_MODEL_Torque_Control_T * const
  Torque_Control_M, real_T rtu_In1, real_T *rty_Out1);

/* private model entry point functions */
extern void Torque_Control_derivatives(void);

#endif                                /* RTW_HEADER_Torque_Control_private_h_ */
