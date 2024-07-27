/*
 * Inverters_Action_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Inverters_Action".
 *
 * Model version              : 13.9
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sat Jul 27 11:10:06 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Inverters_Action_private_h_
#define RTW_HEADER_Inverters_Action_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Inverters_Action.h"
#include "Inverters_Action_types.h"

extern void Inverters_Ac_RegisterEnumerator(uint8_T *rty_Register, boolean_T
  *rty_MuxEnable1, boolean_T *rty_u00, real_T *rtd_EnumerationCounter);
extern void Inverters_Actio_EnumerationDone(boolean_T rtu_SubscribedIn, uint8_T *
  rty_DummyRegister, boolean_T *rty_MuxEnable0, boolean_T *rty_SubscribedOut);
extern void Inverters_Action_Unsubscribe(uint8_T *rty_uXFFStopTransmission,
  boolean_T *rty_u);
extern void Inverte_DisableDriveEnableDrive(real_T rtu_action, uint8_T
  *rty_RegID, uint8_T *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T
  *rty_MuxEnable);
extern void Inverters_Action_TorqueCommand(real_T rtu_IqCurrent, uint8_T
  *rty_RegID, uint8_T *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T
  *rty_MuxEnable, const ConstB_TorqueCommand_Inverter_T *localC);
extern void Inverters_Acti_ActionnotDefined(uint8_T *rty_RegID, uint8_T
  *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T *rty_MuxDisable);
extern void Inverters_Action_bypass(uint8_T rtu_InRegID, uint8_T rtu_Inb7tob0,
  uint8_T rtu_Inb15tob8, uint8_T *rty_OutRegID, uint8_T *rty_Outb7tob0, uint8_T *
  rty_Outb15tob8);
extern void Inverters_Action_TorqueCommand0(uint8_T *rty_RegID, uint8_T
  *rty_b7tob0, uint8_T *rty_b15tob8, const ConstB_TorqueCommand0_Inverte_T
  *localC);
extern void Inverters_Acti_ResetEnumeration(real_T *rtd_EnumerationCounter);

#endif                              /* RTW_HEADER_Inverters_Action_private_h_ */
