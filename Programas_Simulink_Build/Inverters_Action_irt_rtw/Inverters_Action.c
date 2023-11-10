/*
 * Inverters_Action.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Inverters_Action".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Nov 10 02:57:02 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Inverters_Action.h"
#include "Inverters_Action_private.h"

/* Block signals (auto storage) */
B_Inverters_Action_T Inverters_Action_B;

/* Block states (auto storage) */
DW_Inverters_Action_T Inverters_Action_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Inverters_Action_T Inverters_Action_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Inverters_Action_T Inverters_Action_Y;

/* Real-time model */
RT_MODEL_Inverters_Action_T Inverters_Action_M_;
RT_MODEL_Inverters_Action_T *const Inverters_Action_M = &Inverters_Action_M_;

/*
 * Output and update for action system:
 *    '<S8>/Register Enumerator '
 *    '<S33>/Register Enumerator '
 */
void Inverters_Ac_RegisterEnumerator(uint8_T *rty_Register, boolean_T
  *rty_MuxEnable1, boolean_T *rty_u00, P_RegisterEnumerator_Inverter_T *localP,
  real_T *rtd_EnumerationCounter)
{
  real_T rtb_Counter;

  /* DataStoreRead: '<S16>/Parameter Counter Read' */
  rtb_Counter = *rtd_EnumerationCounter;

  /* DataStoreWrite: '<S16>/Parameter Counter Write' incorporates:
   *  Constant: '<S16>/Constant'
   *  Sum: '<S16>/Add'
   */
  *rtd_EnumerationCounter += localP->Constant_Value;

  /* SwitchCase: '<S16>/Switch Case' */
  rtb_Counter = trunc(rtb_Counter);
  if (rtIsNaN(rtb_Counter) || rtIsInf(rtb_Counter)) {
    rtb_Counter = 0.0;
  } else {
    rtb_Counter = fmod(rtb_Counter, 4.294967296E+9);
  }

  switch (rtb_Counter < 0.0 ? -(int32_T)(uint32_T)-rtb_Counter : (int32_T)
          (uint32_T)rtb_Counter) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S16>/I actual' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* SignalConversion: '<S20>/OutportBufferForI actual Register Address' incorporates:
     *  Constant: '<S20>/0x20'
     */
    *rty_Register = localP->ux20_Value;

    /* End of Outputs for SubSystem: '<S16>/I actual' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S16>/I cmd' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* SignalConversion: '<S21>/OutportBufferForI cmd Register Address' incorporates:
     *  Constant: '<S21>/0x26'
     */
    *rty_Register = localP->ux26_Value;

    /* End of Outputs for SubSystem: '<S16>/I cmd' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S16>/Iq actual' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* SignalConversion: '<S22>/OutportBufferForIq actual Register Address' incorporates:
     *  Constant: '<S22>/0x27'
     */
    *rty_Register = localP->ux27_Value;

    /* End of Outputs for SubSystem: '<S16>/Iq actual' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S16>/N actual' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* SignalConversion: '<S23>/OutportBufferForN actual Register Address' incorporates:
     *  Constant: '<S23>/0x30'
     */
    *rty_Register = localP->ux30_Value;

    /* End of Outputs for SubSystem: '<S16>/N actual' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S16>/T-motor' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* SignalConversion: '<S26>/OutportBufferForT-motor Register Address' incorporates:
     *  Constant: '<S26>/0x49'
     */
    *rty_Register = localP->ux49_Value;

    /* End of Outputs for SubSystem: '<S16>/T-motor' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S16>/T-igbt' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* SignalConversion: '<S25>/OutportBufferForT-igbt Register Address' incorporates:
     *  Constant: '<S25>/0x4A'
     */
    *rty_Register = localP->ux4A_Value;

    /* End of Outputs for SubSystem: '<S16>/T-igbt' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S16>/(in) Run (Frg)' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* SignalConversion: '<S19>/OutportBufferFor(in) Run (Frg) Register Address' incorporates:
     *  Constant: '<S19>/0xE8'
     */
    *rty_Register = localP->uxE8_Value;

    /* End of Outputs for SubSystem: '<S16>/(in) Run (Frg)' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S16>/Vdc-Bus' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* SignalConversion: '<S27>/OutportBufferForVdc-Bus Register Address' incorporates:
     *  Constant: '<S27>/0xEB'
     */
    *rty_Register = localP->uxEB_Value;

    /* End of Outputs for SubSystem: '<S16>/Vdc-Bus' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S16>/Register to Read' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* SignalConversion: '<S24>/OutportBufferFor[Param] Register Address' incorporates:
     *  Constant: '<S24>/ Register adress'
     */
    *rty_Register = localP->Registeradress_Value;

    /* End of Outputs for SubSystem: '<S16>/Register to Read' */
    break;
  }

  /* End of SwitchCase: '<S16>/Switch Case' */

  /* SignalConversion: '<S16>/OutportBufferForMuxEnable:1' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  *rty_MuxEnable1 = localP->Constant1_Value;

  /* SignalConversion: '<S16>/OutportBufferFor100' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  *rty_u00 = localP->Constant2_Value;
}

/*
 * Output and update for action system:
 *    '<S8>/EnumerationDone'
 *    '<S33>/EnumerationDone'
 */
void Inverters_Actio_EnumerationDone(boolean_T rtu_SubscribedIn, uint8_T
  *rty_DummyRegister, boolean_T *rty_MuxEnable0, boolean_T *rty_SubscribedOut,
  P_EnumerationDone_Inverters_A_T *localP)
{
  /* SignalConversion: '<S15>/OutportBufferForDummyRegister' incorporates:
   *  Constant: '<S15>/Constant'
   */
  *rty_DummyRegister = localP->Constant_Value;

  /* SignalConversion: '<S15>/OutportBufferForMuxEnable: 0' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  *rty_MuxEnable0 = localP->Constant1_Value;

  /* Inport: '<S15>/Subscribed In' */
  *rty_SubscribedOut = rtu_SubscribedIn;
}

/*
 * Output and update for action system:
 *    '<S8>/Unsubscribe'
 *    '<S33>/Unsubscribe'
 */
void Inverters_Action_Unsubscribe(uint8_T *rty_uXFFStopTransmission, boolean_T
  *rty_u, P_Unsubscribe_Inverters_Actio_T *localP)
{
  /* SignalConversion: '<S18>/OutportBufferFor0XFF Stop Transmission' incorporates:
   *  Constant: '<S18>/0XFF'
   */
  *rty_uXFFStopTransmission = localP->uXFF_Value;

  /* SignalConversion: '<S18>/OutportBufferFor0' incorporates:
   *  Constant: '<S18>/ '
   */
  *rty_u = localP->_Value;
}

/*
 * Output and update for action system:
 *    '<S1>/DisableDrive//EnableDrive'
 *    '<S2>/DisableDrive//EnableDrive'
 */
void Inverte_DisableDriveEnableDrive(real_T rtu_action, uint8_T *rty_RegID,
  uint8_T *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T *rty_MuxEnable,
  P_DisableDriveEnableDrive_Inv_T *localP)
{
  /* SignalConversion: '<S4>/OutportBufferForRegID' incorporates:
   *  Constant: '<S4>/0x51'
   */
  *rty_RegID = localP->ux51_Value;

  /* If: '<S4>/If' incorporates:
   *  Constant: '<S11>/Constant'
   */
  if (rtu_action == 21.0) {
    /* Outputs for IfAction SubSystem: '<S4>/Enable' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    *rty_b7tob0 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S4>/Enable' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* SignalConversion: '<S12>/OutportBufferForOut1' incorporates:
     *  Constant: '<S12>/Constant'
     */
    *rty_b7tob0 = localP->Constant_Value_g;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
  }

  /* End of If: '<S4>/If' */

  /* SignalConversion: '<S4>/OutportBufferForb15 to b8' incorporates:
   *  Constant: '<S4>/Constant'
   */
  *rty_b15tob8 = localP->Constant_Value_k;

  /* SignalConversion: '<S4>/OutportBufferForMuxEnable' incorporates:
   *  Constant: '<S4>/void1'
   */
  *rty_MuxEnable = localP->void1_Value;
}

/*
 * Output and update for action system:
 *    '<S1>/Torque Command'
 *    '<S2>/Torque Command'
 */
void Inverters_Action_TorqueCommand(real_T rtu_IqCurrent, uint8_T *rty_RegID,
  uint8_T *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T *rty_MuxEnable,
  P_TorqueCommand_Inverters_Act_T *localP)
{
  uint16_T rtb_BitwiseOperator1;
  real_T tmp;

  /* SignalConversion: '<S6>/OutportBufferForRegID' incorporates:
   *  Constant: '<S6>/0x90'
   */
  *rty_RegID = localP->ux90_Value;

  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S6>/Bits_Max'
   *  Constant: '<S6>/IMAX'
   *  Product: '<S6>/Divide'
   */
  tmp = floor(localP->Bits_Max_Value / localP->IMAX_Value * rtu_IqCurrent);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_BitwiseOperator1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* End of Product: '<S6>/Product' */

  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  S-Function (sfix_bitop): '<S13>/Bitwise Operator'
   */
  *rty_b7tob0 = (uint8_T)(rtb_BitwiseOperator1 & localP->BitwiseOperator_BitMask);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S13>/Shift Arithmetic'
   *  S-Function (sfix_bitop): '<S13>/Bitwise Operator1'
   */
  *rty_b15tob8 = (uint8_T)((int32_T)((uint32_T)rtb_BitwiseOperator1 >> 8) &
    localP->BitwiseOperator1_BitMask);

  /* SignalConversion: '<S6>/OutportBufferForMuxEnable' incorporates:
   *  Constant: '<S6>/Always Enabled if action is torquecommand'
   */
  *rty_MuxEnable = localP->AlwaysEnabledifactionistorqueco;
}

/*
 * Output and update for action system:
 *    '<S1>/Action not Defined'
 *    '<S2>/Action not Defined'
 */
void Inverters_Acti_ActionnotDefined(uint8_T *rty_RegID, uint8_T *rty_b7tob0,
  uint8_T *rty_b15tob8, boolean_T *rty_MuxDisable,
  P_ActionnotDefined_Inverters__T *localP)
{
  /* SignalConversion: '<S3>/OutportBufferForRegID' incorporates:
   *  Constant: '<S3>/0 1'
   */
  *rty_RegID = localP->u1_Value;

  /* SignalConversion: '<S3>/OutportBufferForb7 to b0' incorporates:
   *  Constant: '<S3>/0 2'
   */
  *rty_b7tob0 = localP->u2_Value;

  /* SignalConversion: '<S3>/OutportBufferForb15 to b8' incorporates:
   *  Constant: '<S3>/0 3'
   */
  *rty_b15tob8 = localP->u3_Value;

  /* SignalConversion: '<S3>/OutportBufferForMuxDisable' incorporates:
   *  Constant: '<S3>/0 '
   */
  *rty_MuxDisable = localP->u_Value;
}

/*
 * Output and update for action system:
 *    '<S1>/bypass'
 *    '<S2>/bypass'
 */
void Inverters_Action_bypass(uint8_T rtu_InRegID, uint8_T rtu_Inb7tob0, uint8_T
  rtu_Inb15tob8, uint8_T *rty_OutRegID, uint8_T *rty_Outb7tob0, uint8_T
  *rty_Outb15tob8)
{
  /* Inport: '<S9>/In RegID' */
  *rty_OutRegID = rtu_InRegID;

  /* Inport: '<S9>/In b7 to b0' */
  *rty_Outb7tob0 = rtu_Inb7tob0;

  /* Inport: '<S9>/In b15 to b8' */
  *rty_Outb15tob8 = rtu_Inb15tob8;
}

/*
 * Output and update for action system:
 *    '<S1>/Torque Command 0'
 *    '<S2>/Torque Command 0'
 */
void Inverters_Action_TorqueCommand0(uint8_T *rty_RegID, uint8_T *rty_b7tob0,
  uint8_T *rty_b15tob8, P_TorqueCommand0_Inverters_Ac_T *localP)
{
  uint16_T rtb_BitwiseOperator1;
  real_T tmp;

  /* SignalConversion: '<S7>/OutportBufferForRegID' incorporates:
   *  Constant: '<S7>/0x90'
   */
  *rty_RegID = localP->ux90_Value;

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Bits_Max'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/IMAX'
   *  Product: '<S7>/Divide'
   */
  tmp = floor(localP->Bits_Max_Value / localP->IMAX_Value *
              localP->Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_BitwiseOperator1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* End of Product: '<S7>/Product' */

  /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
   *  S-Function (sfix_bitop): '<S14>/Bitwise Operator'
   */
  *rty_b7tob0 = (uint8_T)(rtb_BitwiseOperator1 & localP->BitwiseOperator_BitMask);

  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S14>/Shift Arithmetic'
   *  S-Function (sfix_bitop): '<S14>/Bitwise Operator1'
   */
  *rty_b15tob8 = (uint8_T)((int32_T)((uint32_T)rtb_BitwiseOperator1 >> 8) &
    localP->BitwiseOperator1_BitMask);
}

/*
 * Output and update for action system:
 *    '<S1>/Reset Enumeration'
 *    '<S2>/Reset Enumeration'
 */
void Inverters_Acti_ResetEnumeration(P_ResetEnumeration_Inverters__T *localP,
  real_T *rtd_EnumerationCounter)
{
  /* DataStoreWrite: '<S5>/Parameter Counter Write' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  *rtd_EnumerationCounter = localP->Constant1_Value;
}

/* Model output function */
static void Inverters_Action_output(void)
{
  boolean_T rtb_MergeMuxEnable;
  uint8_T rtb_Merge4;
  uint8_T rtb_Merge5;
  uint8_T rtb_Merge3;
  uint8_T rtb_Merge;
  uint8_T rtb_Merge1;
  real_T tmp;
  real_T tmp_0;

  /* Outputs for IfAction SubSystem: '<S1>/Unsubscribe//Subscribe' incorporates:
   *  ActionPort: '<S8>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S2>/Unsubscribe//Subscribe' incorporates:
   *  ActionPort: '<S33>/Action Port'
   */
  /* SwitchCase: '<S8>/Unsubscribe//Subscribe' incorporates:
   *  Inport: '<Root>/InvertersAction'
   *  SwitchCase: '<S1>/Action Selector'
   *  SwitchCase: '<S2>/Action Selector'
   *  SwitchCase: '<S33>/Unsubscribe//Subscribe'
   */
  tmp_0 = trunc(Inverters_Action_U.InvertersAction);

  /* End of Outputs for SubSystem: '<S2>/Unsubscribe//Subscribe' */
  /* End of Outputs for SubSystem: '<S1>/Unsubscribe//Subscribe' */

  /* SwitchCase: '<S2>/Action Selector' incorporates:
   *  Inport: '<Root>/InvertersAction'
   *  Inport: '<Root>/current_L'
   */
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp_0, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 10:
   case 11:
    /* Outputs for IfAction SubSystem: '<S2>/Unsubscribe//Subscribe' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* SwitchCase: '<S33>/Unsubscribe//Subscribe' */
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp_0, 4.294967296E+9);
    }

    switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
     case 10:
      /* Outputs for IfAction SubSystem: '<S33>/Unsubscribe' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      Inverters_Action_Unsubscribe(&Inverters_Action_B.Merge2,
        &Inverters_Action_B.subscribed, &Inverters_Action_P.Unsubscribe_a);

      /* End of Outputs for SubSystem: '<S33>/Unsubscribe' */
      break;

     case 11:
      /* Outputs for IfAction SubSystem: '<S33>/Subscribe' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* SignalConversion: '<S42>/OutportBufferFor15ms' incorporates:
       *  Constant: '<S42>/Time Interval'
       */
      Inverters_Action_B.Merge2 = Inverters_Action_P.TimeInterval_Value_d;

      /* SignalConversion: '<S42>/OutportBufferFor1' incorporates:
       *  Constant: '<S42>/ 1'
       */
      Inverters_Action_B.subscribed = Inverters_Action_P.u_Value;

      /* End of Outputs for SubSystem: '<S33>/Subscribe' */
      break;
    }

    /* If: '<S33>/If' incorporates:
     *  DataStoreRead: '<S33>/Data Store Read1'
     */
    if (Inverters_Action_DW.EnumerationCounter_m < 8.0) {
      /* Outputs for IfAction SubSystem: '<S33>/Register Enumerator ' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      Inverters_Ac_RegisterEnumerator(&rtb_Merge1, &rtb_MergeMuxEnable,
        &Inverters_Action_B.Merge, &Inverters_Action_P.RegisterEnumerator_n,
        &Inverters_Action_DW.EnumerationCounter_m);

      /* End of Outputs for SubSystem: '<S33>/Register Enumerator ' */
    } else {
      /* Outputs for IfAction SubSystem: '<S33>/EnumerationDone' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      Inverters_Actio_EnumerationDone(Inverters_Action_B.subscribed, &rtb_Merge1,
        &rtb_MergeMuxEnable, &Inverters_Action_B.Merge,
        &Inverters_Action_P.EnumerationDone_f);

      /* End of Outputs for SubSystem: '<S33>/EnumerationDone' */
    }

    /* End of If: '<S33>/If' */

    /* SignalConversion: '<S33>/OutportBufferForRegID' incorporates:
     *  Constant: '<S33>/Constant'
     */
    rtb_Merge = Inverters_Action_P.Constant_Value_m;

    /* End of Outputs for SubSystem: '<S2>/Unsubscribe//Subscribe' */
    break;

   case 20:
   case 21:
    /* Outputs for IfAction SubSystem: '<S2>/DisableDrive//EnableDrive' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    Inverte_DisableDriveEnableDrive(Inverters_Action_U.InvertersAction,
      &rtb_Merge, &rtb_Merge1, &Inverters_Action_B.Merge2, &rtb_MergeMuxEnable,
      &Inverters_Action_P.DisableDriveEnableDrive);

    /* End of Outputs for SubSystem: '<S2>/DisableDrive//EnableDrive' */
    break;

   case 30:
    /* Outputs for IfAction SubSystem: '<S2>/Torque Command' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    Inverters_Action_TorqueCommand(Inverters_Action_U.current_L, &rtb_Merge,
      &rtb_Merge1, &Inverters_Action_B.Merge2, &rtb_MergeMuxEnable,
      &Inverters_Action_P.TorqueCommand);

    /* End of Outputs for SubSystem: '<S2>/Torque Command' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/Action not Defined' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    Inverters_Acti_ActionnotDefined(&rtb_Merge, &rtb_Merge1,
      &Inverters_Action_B.Merge2, &rtb_MergeMuxEnable,
      &Inverters_Action_P.ActionnotDefined);

    /* End of Outputs for SubSystem: '<S2>/Action not Defined' */
    break;
  }

  /* If: '<S2>/If1' */
  if (rtb_MergeMuxEnable) {
    /* Outputs for IfAction SubSystem: '<S2>/bypass' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    Inverters_Action_bypass(rtb_Merge, rtb_Merge1, Inverters_Action_B.Merge2,
      &rtb_Merge4, &rtb_Merge3, &rtb_Merge5);

    /* End of Outputs for SubSystem: '<S2>/bypass' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/Torque Command 0' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    Inverters_Action_TorqueCommand0(&rtb_Merge4, &rtb_Merge3, &rtb_Merge5,
      &Inverters_Action_P.TorqueCommand0);

    /* End of Outputs for SubSystem: '<S2>/Torque Command 0' */
  }

  /* End of If: '<S2>/If1' */

  /* Outport: '<Root>/Inverter_L_RegID' */
  Inverters_Action_Y.Inverter_L_RegID = rtb_Merge4;

  /* Outport: '<Root>/Inverter_L_b15tob8' */
  Inverters_Action_Y.Inverter_L_b15tob8 = rtb_Merge5;

  /* Outport: '<Root>/Inverter_L_b7tob0' */
  Inverters_Action_Y.Inverter_L_b7tob0 = rtb_Merge3;

  /* SwitchCase: '<S1>/Action Selector' incorporates:
   *  Inport: '<Root>/InvertersAction'
   *  Inport: '<Root>/current_R'
   */
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp_0, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 10:
   case 11:
    /* Outputs for IfAction SubSystem: '<S1>/Unsubscribe//Subscribe' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* SwitchCase: '<S8>/Unsubscribe//Subscribe' */
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 4.294967296E+9);
    }

    switch (tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0)
    {
     case 10:
      /* Outputs for IfAction SubSystem: '<S8>/Unsubscribe' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      Inverters_Action_Unsubscribe(&Inverters_Action_B.Merge2_p,
        &Inverters_Action_B.subscribed_b, &Inverters_Action_P.Unsubscribe);

      /* End of Outputs for SubSystem: '<S8>/Unsubscribe' */
      break;

     case 11:
      /* Outputs for IfAction SubSystem: '<S8>/Subscribe' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      /* SignalConversion: '<S17>/OutportBufferFor15ms' incorporates:
       *  Constant: '<S17>/Time Interval'
       */
      Inverters_Action_B.Merge2_p = Inverters_Action_P.TimeInterval_Value;

      /* SignalConversion: '<S17>/OutportBufferFor1' incorporates:
       *  Constant: '<S17>/ '
       */
      Inverters_Action_B.subscribed_b = Inverters_Action_P._Value;

      /* End of Outputs for SubSystem: '<S8>/Subscribe' */
      break;
    }

    /* If: '<S8>/If' incorporates:
     *  DataStoreRead: '<S8>/Data Store Read1'
     */
    if (Inverters_Action_DW.EnumerationCounter < 8.0) {
      /* Outputs for IfAction SubSystem: '<S8>/Register Enumerator ' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      Inverters_Ac_RegisterEnumerator(&rtb_Merge1, &rtb_MergeMuxEnable,
        &Inverters_Action_B.Merge, &Inverters_Action_P.RegisterEnumerator,
        &Inverters_Action_DW.EnumerationCounter);

      /* End of Outputs for SubSystem: '<S8>/Register Enumerator ' */
    } else {
      /* Outputs for IfAction SubSystem: '<S8>/EnumerationDone' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      Inverters_Actio_EnumerationDone(Inverters_Action_B.subscribed_b,
        &rtb_Merge1, &rtb_MergeMuxEnable, &Inverters_Action_B.Merge,
        &Inverters_Action_P.EnumerationDone);

      /* End of Outputs for SubSystem: '<S8>/EnumerationDone' */
    }

    /* End of If: '<S8>/If' */

    /* SignalConversion: '<S8>/OutportBufferForRegID' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Merge = Inverters_Action_P.Constant_Value;

    /* End of Outputs for SubSystem: '<S1>/Unsubscribe//Subscribe' */
    break;

   case 20:
   case 21:
    /* Outputs for IfAction SubSystem: '<S1>/DisableDrive//EnableDrive' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    Inverte_DisableDriveEnableDrive(Inverters_Action_U.InvertersAction,
      &rtb_Merge, &rtb_Merge1, &Inverters_Action_B.Merge2_p, &rtb_MergeMuxEnable,
      &Inverters_Action_P.DisableDriveEnableDrive_p);

    /* End of Outputs for SubSystem: '<S1>/DisableDrive//EnableDrive' */
    break;

   case 30:
    /* Outputs for IfAction SubSystem: '<S1>/Torque Command' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    Inverters_Action_TorqueCommand(Inverters_Action_U.current_R, &rtb_Merge,
      &rtb_Merge1, &Inverters_Action_B.Merge2_p, &rtb_MergeMuxEnable,
      &Inverters_Action_P.TorqueCommand_k);

    /* End of Outputs for SubSystem: '<S1>/Torque Command' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Action not Defined' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    Inverters_Acti_ActionnotDefined(&rtb_Merge, &rtb_Merge1,
      &Inverters_Action_B.Merge2_p, &rtb_MergeMuxEnable,
      &Inverters_Action_P.ActionnotDefined_g);

    /* End of Outputs for SubSystem: '<S1>/Action not Defined' */
    break;
  }

  /* If: '<S1>/If1' */
  if (rtb_MergeMuxEnable) {
    /* Outputs for IfAction SubSystem: '<S1>/bypass' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    Inverters_Action_bypass(rtb_Merge, rtb_Merge1, Inverters_Action_B.Merge2_p,
      &rtb_Merge3, &rtb_Merge4, &rtb_Merge5);

    /* End of Outputs for SubSystem: '<S1>/bypass' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/Torque Command 0' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    Inverters_Action_TorqueCommand0(&rtb_Merge3, &rtb_Merge4, &rtb_Merge5,
      &Inverters_Action_P.TorqueCommand0_a);

    /* End of Outputs for SubSystem: '<S1>/Torque Command 0' */
  }

  /* End of If: '<S1>/If1' */

  /* Outport: '<Root>/Inverter_R_RegID' */
  Inverters_Action_Y.Inverter_R_RegID = rtb_Merge3;

  /* Outport: '<Root>/Inverter_R_b15tob8' */
  Inverters_Action_Y.Inverter_R_b15tob8 = rtb_Merge5;

  /* Outport: '<Root>/Inverter_R_b7tob0' */
  Inverters_Action_Y.Inverter_R_b7tob0 = rtb_Merge4;

  /* Outport: '<Root>/InvertersSubscribed' */
  Inverters_Action_Y.InvertersSubscribed = Inverters_Action_B.Merge;

  /* If: '<S10>/If2' incorporates:
   *  Delay: '<S10>/Delay'
   *  Inport: '<Root>/InvertersAction'
   */
  if (Inverters_Action_U.InvertersAction != Inverters_Action_DW.Delay_DSTATE) {
    /* Outputs for IfAction SubSystem: '<S1>/Reset Enumeration' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    Inverters_Acti_ResetEnumeration(&Inverters_Action_P.ResetEnumeration,
      &Inverters_Action_DW.EnumerationCounter);

    /* End of Outputs for SubSystem: '<S1>/Reset Enumeration' */
  }

  /* End of If: '<S10>/If2' */

  /* If: '<S35>/If2' incorporates:
   *  Delay: '<S35>/Delay'
   *  Inport: '<Root>/InvertersAction'
   */
  if (Inverters_Action_U.InvertersAction != Inverters_Action_DW.Delay_DSTATE_h)
  {
    /* Outputs for IfAction SubSystem: '<S2>/Reset Enumeration' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    Inverters_Acti_ResetEnumeration(&Inverters_Action_P.ResetEnumeration_p,
      &Inverters_Action_DW.EnumerationCounter_m);

    /* End of Outputs for SubSystem: '<S2>/Reset Enumeration' */
  }

  /* End of If: '<S35>/If2' */
}

/* Model update function */
static void Inverters_Action_update(void)
{
  /* Update for Delay: '<S10>/Delay' incorporates:
   *  Inport: '<Root>/InvertersAction'
   */
  Inverters_Action_DW.Delay_DSTATE = Inverters_Action_U.InvertersAction;

  /* Update for Delay: '<S35>/Delay' incorporates:
   *  Inport: '<Root>/InvertersAction'
   */
  Inverters_Action_DW.Delay_DSTATE_h = Inverters_Action_U.InvertersAction;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Inverters_Action_M->Timing.clockTick0)) {
    ++Inverters_Action_M->Timing.clockTickH0;
  }

  Inverters_Action_M->Timing.t[0] = Inverters_Action_M->Timing.clockTick0 *
    Inverters_Action_M->Timing.stepSize0 +
    Inverters_Action_M->Timing.clockTickH0 *
    Inverters_Action_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Inverters_Action_initialize(void)
{
  /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
  Inverters_Action_DW.LastAction =
    Inverters_Action_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
  Inverters_Action_DW.EnumerationCounter =
    Inverters_Action_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory1' */
  Inverters_Action_DW.LastAction_k =
    Inverters_Action_P.DataStoreMemory1_InitialValue_m;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory2' */
  Inverters_Action_DW.EnumerationCounter_m =
    Inverters_Action_P.DataStoreMemory2_InitialValue_c;

  /* InitializeConditions for Delay: '<S10>/Delay' */
  Inverters_Action_DW.Delay_DSTATE = Inverters_Action_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S35>/Delay' */
  Inverters_Action_DW.Delay_DSTATE_h =
    Inverters_Action_P.Delay_InitialCondition_o;

  /* SystemInitialize for IfAction SubSystem: '<S2>/Unsubscribe//Subscribe' */
  /* SystemInitialize for Merge: '<S33>/subscribed?' */
  Inverters_Action_B.subscribed = Inverters_Action_P.subscribed_InitialOutput_k;

  /* End of SystemInitialize for SubSystem: '<S2>/Unsubscribe//Subscribe' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Unsubscribe//Subscribe' */
  /* SystemInitialize for Merge: '<S8>/subscribed?' */
  Inverters_Action_B.subscribed_b = Inverters_Action_P.subscribed_InitialOutput;

  /* End of SystemInitialize for SubSystem: '<S1>/Unsubscribe//Subscribe' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  Inverters_Action_B.Merge = Inverters_Action_P.Merge_InitialOutput;
}

/* Model terminate function */
static void Inverters_Action_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Inverters_Action_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Inverters_Action_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Inverters_Action_initialize();
}

void MdlTerminate(void)
{
  Inverters_Action_terminate();
}

/* Registration function */
RT_MODEL_Inverters_Action_T *Inverters_Action(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Inverters_Action_M, 0,
                sizeof(RT_MODEL_Inverters_Action_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Inverters_Action_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Inverters_Action_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Inverters_Action_M->Timing.sampleTimes =
      (&Inverters_Action_M->Timing.sampleTimesArray[0]);
    Inverters_Action_M->Timing.offsetTimes =
      (&Inverters_Action_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Inverters_Action_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Inverters_Action_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Inverters_Action_M, &Inverters_Action_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Inverters_Action_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Inverters_Action_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Inverters_Action_M, 10.0);
  Inverters_Action_M->Timing.stepSize0 = 0.2;
  Inverters_Action_M->solverInfoPtr = (&Inverters_Action_M->solverInfo);
  Inverters_Action_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Inverters_Action_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Inverters_Action_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Inverters_Action_M->blockIO = ((void *) &Inverters_Action_B);
  (void) memset(((void *) &Inverters_Action_B), 0,
                sizeof(B_Inverters_Action_T));

  /* parameters */
  Inverters_Action_M->defaultParam = ((real_T *)&Inverters_Action_P);

  /* states (dwork) */
  Inverters_Action_M->dwork = ((void *) &Inverters_Action_DW);
  (void) memset((void *)&Inverters_Action_DW, 0,
                sizeof(DW_Inverters_Action_T));

  /* external inputs */
  Inverters_Action_M->inputs = (((void*)&Inverters_Action_U));
  (void)memset((void *)&Inverters_Action_U, 0, sizeof(ExtU_Inverters_Action_T));

  /* external outputs */
  Inverters_Action_M->outputs = (&Inverters_Action_Y);
  (void) memset((void *)&Inverters_Action_Y, 0,
                sizeof(ExtY_Inverters_Action_T));

  /* Initialize Sizes */
  Inverters_Action_M->Sizes.numContStates = (0);/* Number of continuous states */
  Inverters_Action_M->Sizes.numY = (7);/* Number of model outputs */
  Inverters_Action_M->Sizes.numU = (3);/* Number of model inputs */
  Inverters_Action_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Inverters_Action_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Inverters_Action_M->Sizes.numBlocks = (181);/* Number of blocks */
  Inverters_Action_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  Inverters_Action_M->Sizes.numBlockPrms = (93);/* Sum of parameter "widths" */
  return Inverters_Action_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
