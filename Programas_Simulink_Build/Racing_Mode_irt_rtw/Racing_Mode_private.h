/*
 * Racing_Mode_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Racing_Mode".
 *
 * Model version              : 10.0
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Fri Nov 17 17:14:43 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Racing_Mode_private_h_
#define RTW_HEADER_Racing_Mode_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Racing_Mode.h"

extern void Racing_Mode_SKF_Initial_Init(B_SKF_Initial_Racing_Mode_T *localB);
extern void Racing_Mode_SKF_Initial(real_T rtu_In1, B_SKF_Initial_Racing_Mode_T *
  localB);
extern void Racing_Mode_Apps_Sat_Dwn_Init(B_Apps_Sat_Dwn_Racing_Mode_T *localB);
extern void Racing_Mode_Apps_Sat_Dwn(real_T rtu_In1,
  B_Apps_Sat_Dwn_Racing_Mode_T *localB);
extern void Ra_Max_Regenerative_Torque_Init(B_Max_Regenerative_Torque_Rac_T
  *localB);
extern void Racing__Max_Regenerative_Torque(real_T rtu_In1,
  B_Max_Regenerative_Torque_Rac_T *localB);
extern void Racing_Mo_Acceleration2Driver22(real_T rty_Params[10]);

#endif                                 /* RTW_HEADER_Racing_Mode_private_h_ */
