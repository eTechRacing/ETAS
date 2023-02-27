/*
 * inverters_action_ETR07_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "inverters_action_ETR07".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Jun 17 18:50:15 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_inverters_action_ETR07_private_h_
#define RTW_HEADER_inverters_action_ETR07_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "inverters_action_ETR07.h"

extern void inverters_ac_RegisterEnumerator(uint8_T *rty_Register, boolean_T
  *rty_MuxEnable1, boolean_T *rty_u00, P_RegisterEnumerator_inverter_T *localP,
  real_T *rtd_EnumerationCounter);
extern void inverters_actio_EnumerationDone(boolean_T rtu_SubscribedIn, uint8_T *
  rty_DummyRegister, boolean_T *rty_MuxEnable0, boolean_T *rty_SubscribedOut,
  P_EnumerationDone_inverters_a_T *localP);
extern void inverters_action_ET_Unsubscribe(uint8_T *rty_uXFFStopTransmission,
  boolean_T *rty_u, P_Unsubscribe_inverters_actio_T *localP);
extern void inverte_DisableDriveEnableDrive(real_T rtu_action, uint8_T
  *rty_RegID, uint8_T *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T
  *rty_MuxEnable, P_DisableDriveEnableDrive_inv_T *localP);
extern void inverters_action__TorqueCommand(real_T rtu_IqCurrent, uint8_T
  *rty_RegID, uint8_T *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T
  *rty_MuxEnable, P_TorqueCommand_inverters_act_T *localP);
extern void inverters_acti_ActionnotDefined(uint8_T *rty_RegID, uint8_T
  *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T *rty_MuxDisable,
  P_ActionnotDefined_inverters__T *localP);
extern void inverters_action_ETR07_bypass(uint8_T rtu_InRegID, uint8_T
  rtu_Inb7tob0, uint8_T rtu_Inb15tob8, uint8_T *rty_OutRegID, uint8_T
  *rty_Outb7tob0, uint8_T *rty_Outb15tob8);
extern void inverters_action_TorqueCommand0(uint8_T *rty_RegID, uint8_T
  *rty_b7tob0, uint8_T *rty_b15tob8, P_TorqueCommand0_inverters_ac_T *localP);
extern void inverters_acti_ResetEnumeration(P_ResetEnumeration_inverters__T
  *localP, real_T *rtd_EnumerationCounter);

#endif                                 /* RTW_HEADER_inverters_action_ETR07_private_h_ */
