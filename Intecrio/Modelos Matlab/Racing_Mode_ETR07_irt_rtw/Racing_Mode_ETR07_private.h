/*
 * Racing_Mode_ETR07_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Racing_Mode_ETR07".
 *
 * Model version              : 1.6
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue Apr 12 15:33:24 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Racing_Mode_ETR07_private_h_
#define RTW_HEADER_Racing_Mode_ETR07_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Racing_Mode_ETR07.h"

extern void Racing_Mode_ETR0_WorkshopTest01(real_T rty_Params[10],
  P_WorkshopTest01_Racing_Mode__T *localP);
extern void Racing_Mode_ET_SKF_Initial_Init(B_SKF_Initial_Racing_Mode_ETR_T
  *localB, P_SKF_Initial_Racing_Mode_ETR_T *localP);
extern void Racing_Mode_ETR07_SKF_Initial(real_T rtu_In1,
  B_SKF_Initial_Racing_Mode_ETR_T *localB, P_SKF_Initial_Racing_Mode_ETR_T
  *localP);
extern void Ra_Max_Regenerative_Torque_Init(B_Max_Regenerative_Torque_Rac_T
  *localB, P_Max_Regenerative_Torque_Rac_T *localP);
extern void Racing__Max_Regenerative_Torque(real_T rtu_In1,
  B_Max_Regenerative_Torque_Rac_T *localB);

#endif                                 /* RTW_HEADER_Racing_Mode_ETR07_private_h_ */
