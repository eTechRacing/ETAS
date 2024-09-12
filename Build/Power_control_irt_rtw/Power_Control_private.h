/*
 * Power_Control_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Power_Control".
 *
 * Model version              : 4.35
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sat Sep  7 16:34:51 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Power_Control_private_h_
#define RTW_HEADER_Power_Control_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Power_Control.h"
#include "Power_Control_types.h"

extern void Power_Control_LimitReached(real_T *rty_Out);
extern void InverterL_Temp_Limitation_Init(DW_InverterL_Temp_Limitation__T
  *localDW);
extern void Power_InverterL_Temp_Limitation(real_T rtu_Current_in, real_T
  rtu_Aggressive_Factor, real_T rtu_Max_Temp, real_T rtu_Tolerance, real_T
  rtu_Inv_Temp, real_T rtu_Change_Factor, B_InverterL_Temp_Limitation_P_T
  *localB, DW_InverterL_Temp_Limitation__T *localDW);
extern void Pow_MotorL_Temp_Limitation_Init(DW_MotorL_Temp_Limitation_Pow_T
  *localDW);
extern void Power_Co_MotorL_Temp_Limitation(real_T rtu_Current_in, real_T
  rtu_Aggressive_Factor, real_T rtu_Max_Temp, real_T rtu_Tolerance, real_T
  rtu_Mot_Temp, real_T rtu_Change_Factor, B_MotorL_Temp_Limitation_Powe_T
  *localB, DW_MotorL_Temp_Limitation_Pow_T *localDW);

#endif                                 /* RTW_HEADER_Power_Control_private_h_ */
