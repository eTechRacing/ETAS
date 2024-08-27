/*
 * Disconnections_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Disconnections".
 *
 * Model version              : 13.34
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Aug 27 10:09:38 2024
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
#include "Disconnections_types.h"
#include "Disconnections.h"

extern void Disconnections_Reset_counter(real_T *rty_Out1);
extern void Disconnections_Counting(real_T rtu_In1, real_T *rty_Out1);
extern void Disconnections_CAN_OK(real_T rtu_Alive_signal, real_T *rty_Out1,
  real_T *rtd_Last_alive_n);
extern void Disconnection_IfActionSubsystem(real_T *rty_disc);
extern void Disconnectio_IfActionSubsystem3(real_T *rty_disc);
extern void Disconnections_RigidAxle2024(real_T *rty_u);

#endif                                /* RTW_HEADER_Disconnections_private_h_ */
