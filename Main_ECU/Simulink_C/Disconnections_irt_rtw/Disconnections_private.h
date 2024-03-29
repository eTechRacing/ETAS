/*
 * Disconnections_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Disconnections".
 *
 * Model version              : 10.4
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Fri Mar 29 00:59:06 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Disconnections_private_h_
#define RTW_HEADER_Disconnections_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Disconnections.h"

extern void Disconnections_Reset_counter(real_T *rty_Out1);
extern void Disconnections_CAN_OK(real_T rtu_Alive_signal, real_T *rty_Out1,
  real_T *rtd_Last_alive_n);
extern void Disconnections_Error_Counter(real_T *rty_Out1, const real_T
  *rtd_Tot_Errors);
extern void Disconnections_Signal_OK(real_T *rty_Out1);

#endif                                /* RTW_HEADER_Disconnections_private_h_ */
