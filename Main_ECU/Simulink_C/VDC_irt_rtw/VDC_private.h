/*
 * VDC_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VDC".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Sat Mar 30 17:29:17 2024
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

extern void VDC_LimitReached(real_T *rty_Out);
extern void VDC_AutomaticFailureMode(real_T rtu_In1, real_T *rty_Out1);

#endif                                 /* RTW_HEADER_VDC_private_h_ */
