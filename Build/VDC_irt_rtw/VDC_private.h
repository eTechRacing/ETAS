/*
 * VDC_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VDC".
 *
 * Model version              : 4.204
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sun Aug 25 00:55:43 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VDC_private_h_
#define RTW_HEADER_VDC_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "VDC.h"
#include "VDC_types.h"

extern void VDC_MATLABFunction(real_T rtu_steering_max_angle, real_T
  rtu_steering, real_T rtu_steering_deadzone, real_T rtu_Throttle_Torque,
  B_MATLABFunction_VDC_T *localB);
extern void VDC_RIGIDAXLE(real_T rtu_Throttle_TorqueNm, real_T
  *rty_Tq_RR_SM4Nm027, real_T *rty_Tq_RL_SM4Nm027, real_T *rty_sensorics_mode);
extern void VDC_Torquedemandedbythedriver(real_T rtu_AP, real_T
  rtu_pedal_sat_down, real_T rtu_pedal_sat_up, real_T rtu_max_torque,
  B_Torquedemandedbythedriver_V_T *localB);
extern void VDC_RIGIDAXLEWITHTC_Init(DW_RIGIDAXLEWITHTC_VDC_T *localDW);
extern void VDC_RIGIDAXLEWITHTC(real_T rtu_RR_Vel_ms_Wheelms, real_T
  rtu_RL_Vel_ms_Wheelms, real_T rtu_Throttle_TorqueNm, real_T rtu_MAX_SLR,
  real_T rtu_el_Vel_Xms, real_T *rty_Tq_RR_SM2Nm027, real_T *rty_Tq_RL_SM2Nm027,
  real_T *rty_sensorics_mode, DW_RIGIDAXLEWITHTC_VDC_T *localDW);
extern void VDC_IfActionSubsystem(real_T rtu_Tq_RR, real_T rtu_Tq_RL, real_T
  *rty_TQ_RR, real_T *rty_TQ_RL);
extern void VDC_IfActionSubsystem1(real_T rtu_Tq_RR, real_T rtu_Tq_RL, real_T
  *rty_TQ_RL, real_T *rty_TQ_RR);

#endif                                 /* RTW_HEADER_VDC_private_h_ */
