/*
 * Disconnections_ETR07_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Disconnections_ETR07".
 *
 * Model version              : 1.36
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Jun 18 14:33:36 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Disconnections_ETR07_private_h_
#define RTW_HEADER_Disconnections_ETR07_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Disconnections_ETR07.h"

extern void Disconnections_ET_Reset_counter(real_T *rty_Out1,
  P_Reset_counter_Disconnection_T *localP);
extern void Disconnections_ET_Error_Counter(real_T *rty_Out1,
  P_Error_Counter_Disconnection_T *localP, real_T *rtd_Tot_Errors_h);
extern void Disconnections_ETR07_CAN_OK(real_T rtu_Alive_signal, real_T
  *rty_Out1, P_CAN_OK_Disconnections_ETR07_T *localP, real_T *rtd_Last_alive_l);
extern void Disconnections_ETR07_Others(real_T rtu_In1, real_T *rty_others);

#endif                                 /* RTW_HEADER_Disconnections_ETR07_private_h_ */
