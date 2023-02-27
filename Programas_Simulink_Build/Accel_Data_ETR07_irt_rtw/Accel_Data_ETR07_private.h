/*
 * Accel_Data_ETR07_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Accel_Data_ETR07".
 *
 * Model version              : 1.31
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue Apr 12 15:32:09 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Accel_Data_ETR07_private_h_
#define RTW_HEADER_Accel_Data_ETR07_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Accel_Data_ETR07.h"

extern void Accel_Data__AccDataConversionFX(real_T rtu_Bits,
  B_AccDataConversionFX_Accel_D_T *localB, P_AccDataConversionFX_Accel_D_T
  *localP);
extern void Accel_Data_ETR07_LowPass_Start(DW_LowPass_Accel_Data_ETR07_T
  *localDW, P_LowPass_Accel_Data_ETR07_T *localP);
extern void Accel_Data_ETR07_LowPass(real_T rtu_IN, B_LowPass_Accel_Data_ETR07_T
  *localB, DW_LowPass_Accel_Data_ETR07_T *localDW, P_LowPass_Accel_Data_ETR07_T *
  localP);

#endif                                 /* RTW_HEADER_Accel_Data_ETR07_private_h_ */
