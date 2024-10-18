/*
 * Inverters_Action.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Inverters_Action".
 *
 * Model version              : 13.40
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sat Oct 19 01:04:48 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Inverters_Action.h"
#include "rtwtypes.h"
#include "Inverters_Action_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
B_Inverters_Action_T Inverters_Action_B;

/* Block states (default storage) */
DW_Inverters_Action_T Inverters_Action_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Inverters_Action_T Inverters_Action_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Inverters_Action_T Inverters_Action_Y;

/* Real-time model */
static RT_MODEL_Inverters_Action_T Inverters_Action_M_;
RT_MODEL_Inverters_Action_T *const Inverters_Action_M = &Inverters_Action_M_;

/*
 * Output and update for action system:
 *    '<S12>/Register Enumerator '
 *    '<S37>/Register Enumerator '
 */
void Inverters_Ac_RegisterEnumerator(uint8_T *rty_Register, boolean_T
  *rty_MuxEnable1, boolean_T *rty_u00, real_T *rtd_EnumerationCounter)
{
  real_T rtb_Counter;

  /* DataStoreRead: '<S21>/Parameter Counter Read' */
  rtb_Counter = *rtd_EnumerationCounter;

  /* DataStoreWrite: '<S21>/Parameter Counter Write' incorporates:
   *  Constant: '<S21>/Constant'
   *  Sum: '<S21>/Add'
   */
  (*rtd_EnumerationCounter)++;

  /* SwitchCase: '<S21>/Switch Case' */
  rtb_Counter = trunc(rtb_Counter);
  if (rtIsNaN(rtb_Counter) || rtIsInf(rtb_Counter)) {
    rtb_Counter = 0.0;
  } else {
    rtb_Counter = fmod(rtb_Counter, 4.294967296E+9);
  }

  switch (rtb_Counter < 0.0 ? -(int32_T)(uint32_T)-rtb_Counter : (int32_T)
          (uint32_T)rtb_Counter) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S21>/I actual' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* SignalConversion generated from: '<S24>/I actual Register Address' incorporates:
     *  Constant: '<S24>/0x20'
     */
    *rty_Register = 32U;

    /* End of Outputs for SubSystem: '<S21>/I actual' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S21>/I cmd' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* SignalConversion generated from: '<S25>/I cmd Register Address' incorporates:
     *  Constant: '<S25>/0x26'
     */
    *rty_Register = 38U;

    /* End of Outputs for SubSystem: '<S21>/I cmd' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S21>/Iq actual' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* SignalConversion generated from: '<S26>/Iq actual Register Address' incorporates:
     *  Constant: '<S26>/0x27'
     */
    *rty_Register = 39U;

    /* End of Outputs for SubSystem: '<S21>/Iq actual' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S21>/N actual' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* SignalConversion generated from: '<S27>/N actual Register Address' incorporates:
     *  Constant: '<S27>/0x30'
     */
    *rty_Register = 48U;

    /* End of Outputs for SubSystem: '<S21>/N actual' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S21>/T-motor' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    /* SignalConversion generated from: '<S30>/T-motor Register Address' incorporates:
     *  Constant: '<S30>/0x49'
     */
    *rty_Register = 73U;

    /* End of Outputs for SubSystem: '<S21>/T-motor' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S21>/T-igbt' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* SignalConversion generated from: '<S29>/T-igbt Register Address' incorporates:
     *  Constant: '<S29>/0x4A'
     */
    *rty_Register = 74U;

    /* End of Outputs for SubSystem: '<S21>/T-igbt' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S21>/Vdc-Bus' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* SignalConversion generated from: '<S31>/Vdc-Bus Register Address' incorporates:
     *  Constant: '<S31>/0xEB'
     */
    *rty_Register = 235U;

    /* End of Outputs for SubSystem: '<S21>/Vdc-Bus' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S21>/Register to Read' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* SignalConversion generated from: '<S28>/[Param] Register Address' incorporates:
     *  Constant: '<S28>/ Register adress'
     */
    *rty_Register = 0U;

    /* End of Outputs for SubSystem: '<S21>/Register to Read' */
    break;
  }

  /* End of SwitchCase: '<S21>/Switch Case' */

  /* SignalConversion generated from: '<S21>/MuxEnable:1' incorporates:
   *  Constant: '<S21>/Constant1'
   */
  *rty_MuxEnable1 = true;

  /* SignalConversion generated from: '<S21>/100' incorporates:
   *  Constant: '<S21>/Constant2'
   */
  *rty_u00 = true;
}

/*
 * Output and update for action system:
 *    '<S12>/EnumerationDone'
 *    '<S37>/EnumerationDone'
 */
void Inverters_Actio_EnumerationDone(boolean_T rtu_SubscribedIn, uint8_T
  *rty_DummyRegister, boolean_T *rty_MuxEnable0, boolean_T *rty_SubscribedOut)
{
  /* SignalConversion generated from: '<S20>/DummyRegister' incorporates:
   *  Constant: '<S20>/Constant'
   */
  *rty_DummyRegister = 0U;

  /* SignalConversion generated from: '<S20>/MuxEnable: 0' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  *rty_MuxEnable0 = false;

  /* SignalConversion generated from: '<S20>/Subscribed In' */
  *rty_SubscribedOut = rtu_SubscribedIn;
}

/*
 * Output and update for action system:
 *    '<S12>/Unsubscribe'
 *    '<S37>/Unsubscribe'
 */
void Inverters_Action_Unsubscribe(uint8_T *rty_uXFFStopTransmission, boolean_T
  *rty_u)
{
  /* SignalConversion generated from: '<S23>/0XFF Stop Transmission' incorporates:
   *  Constant: '<S23>/0XFF'
   */
  *rty_uXFFStopTransmission = MAX_uint8_T;

  /* SignalConversion generated from: '<S23>/0' incorporates:
   *  Constant: '<S23>/ '
   */
  *rty_u = false;
}

/*
 * Output and update for action system:
 *    '<S3>/DisableDrive//EnableDrive'
 *    '<S4>/DisableDrive//EnableDrive'
 */
void Inverte_DisableDriveEnableDrive(real_T rtu_action, uint8_T *rty_RegID,
  uint8_T *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T *rty_MuxEnable)
{
  /* SignalConversion generated from: '<S8>/RegID' incorporates:
   *  Constant: '<S8>/0x51'
   */
  *rty_RegID = 81U;

  /* If: '<S8>/If' incorporates:
   *  Constant: '<S15>/Constant'
   */
  if (rtu_action == 21.0) {
    /* Outputs for IfAction SubSystem: '<S8>/Enable' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    *rty_b7tob0 = 0U;

    /* End of Outputs for SubSystem: '<S8>/Enable' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* SignalConversion generated from: '<S16>/Out1' incorporates:
     *  Constant: '<S16>/Constant'
     */
    *rty_b7tob0 = 4U;

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem1' */
  }

  /* End of If: '<S8>/If' */

  /* SignalConversion generated from: '<S8>/b15 to b8' incorporates:
   *  Constant: '<S8>/Constant'
   */
  *rty_b15tob8 = 0U;

  /* SignalConversion generated from: '<S8>/MuxEnable' incorporates:
   *  Constant: '<S8>/void1'
   */
  *rty_MuxEnable = true;
}

/*
 * Output and update for action system:
 *    '<S3>/Torque Command'
 *    '<S4>/Torque Command'
 */
void Inverters_Action_TorqueCommand(real_T rtu_IqCurrent, uint8_T *rty_RegID,
  uint8_T *rty_b7tob0, uint8_T *rty_b15tob8, boolean_T *rty_MuxEnable, const
  ConstB_TorqueCommand_Inverter_T *localC)
{
  real_T tmp;
  uint16_T rtb_BitwiseOperator1;

  /* SignalConversion generated from: '<S10>/RegID' incorporates:
   *  Constant: '<S10>/0x90'
   */
  *rty_RegID = 144U;

  /* Product: '<S10>/Product' */
  tmp = floor(localC->Divide * rtu_IqCurrent);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_BitwiseOperator1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* End of Product: '<S10>/Product' */

  /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
   *  S-Function (sfix_bitop): '<S18>/Bitwise Operator'
   */
  *rty_b7tob0 = (uint8_T)(rtb_BitwiseOperator1 & 255);

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S18>/Shift Arithmetic'
   *  S-Function (sfix_bitop): '<S18>/Bitwise Operator1'
   */
  *rty_b15tob8 = (uint8_T)((uint32_T)rtb_BitwiseOperator1 >> 8);

  /* SignalConversion generated from: '<S10>/MuxEnable' incorporates:
   *  Constant: '<S10>/Always Enabled if action is torquecommand'
   */
  *rty_MuxEnable = true;
}

/*
 * Output and update for action system:
 *    '<S3>/Action not Defined'
 *    '<S4>/Action not Defined'
 */
void Inverters_Acti_ActionnotDefined(uint8_T *rty_RegID, uint8_T *rty_b7tob0,
  uint8_T *rty_b15tob8, boolean_T *rty_MuxDisable)
{
  /* SignalConversion generated from: '<S7>/RegID' incorporates:
   *  Constant: '<S7>/0 1'
   */
  *rty_RegID = 0U;

  /* SignalConversion generated from: '<S7>/b7 to b0' incorporates:
   *  Constant: '<S7>/0 2'
   */
  *rty_b7tob0 = 0U;

  /* SignalConversion generated from: '<S7>/b15 to b8' incorporates:
   *  Constant: '<S7>/0 3'
   */
  *rty_b15tob8 = 0U;

  /* SignalConversion generated from: '<S7>/MuxDisable' incorporates:
   *  Constant: '<S7>/0 '
   */
  *rty_MuxDisable = false;
}

/*
 * Output and update for action system:
 *    '<S3>/bypass'
 *    '<S4>/bypass'
 */
void Inverters_Action_bypass(uint8_T rtu_InRegID, uint8_T rtu_Inb7tob0, uint8_T
  rtu_Inb15tob8, uint8_T *rty_OutRegID, uint8_T *rty_Outb7tob0, uint8_T
  *rty_Outb15tob8)
{
  /* SignalConversion generated from: '<S13>/In RegID' */
  *rty_OutRegID = rtu_InRegID;

  /* SignalConversion generated from: '<S13>/In b7 to b0' */
  *rty_Outb7tob0 = rtu_Inb7tob0;

  /* SignalConversion generated from: '<S13>/In b15 to b8' */
  *rty_Outb15tob8 = rtu_Inb15tob8;
}

/*
 * Output and update for action system:
 *    '<S3>/Torque Command 0'
 *    '<S4>/Torque Command 0'
 */
void Inverters_Action_TorqueCommand0(uint8_T *rty_RegID, uint8_T *rty_b7tob0,
  uint8_T *rty_b15tob8, const ConstB_TorqueCommand0_Inverte_T *localC)
{
  /* SignalConversion generated from: '<S11>/RegID' incorporates:
   *  Constant: '<S11>/0x90'
   */
  *rty_RegID = 144U;

  /* DataTypeConversion: '<S19>/Data Type Conversion' */
  *rty_b7tob0 = (uint8_T)localC->b7tob0;

  /* DataTypeConversion: '<S19>/Data Type Conversion1' */
  *rty_b15tob8 = (uint8_T)localC->BitwiseOperator1;
}

/*
 * Output and update for action system:
 *    '<S3>/Reset Enumeration'
 *    '<S4>/Reset Enumeration'
 */
void Inverters_Acti_ResetEnumeration(real_T *rtd_EnumerationCounter)
{
  /* DataStoreWrite: '<S9>/Parameter Counter Write' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  *rtd_EnumerationCounter = 0.0;
}

/* Model output function */
static void Inverters_Action_output(void)
{
  real_T rtb_Merge1;
  real_T rtb_Merge2;
  real_T tmp;
  real_T tmp_0;
  uint8_T rtb_Merge;
  uint8_T rtb_Merge1_c;
  boolean_T rtb_MergeMuxEnable;
  boolean_T tmp_1;
  boolean_T tmp_2;

  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/RacingMode'
   */
  if (Inverters_Action_U.RacingMode == 2.0) {
    /* Outputs for IfAction SubSystem: '<Root>/Accel PP' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* SignalConversion generated from: '<S1>/current_L' incorporates:
     *  Inport: '<Root>/current_L'
     */
    rtb_Merge1 = Inverters_Action_U.current_L;

    /* SignalConversion generated from: '<S1>/current_R' incorporates:
     *  Inport: '<Root>/current_R'
     */
    rtb_Merge2 = Inverters_Action_U.current_R;

    /* End of Outputs for SubSystem: '<Root>/Accel PP' */
  } else if (Inverters_Action_U.RacingMode == 3.0) {
    /* Outputs for IfAction SubSystem: '<Root>/SkidPad NP' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Gain: '<S6>/Gain' incorporates:
     *  Inport: '<Root>/current_L'
     */
    rtb_Merge1 = -Inverters_Action_U.current_L;

    /* SignalConversion generated from: '<S6>/current_R' incorporates:
     *  Inport: '<Root>/current_R'
     */
    rtb_Merge2 = Inverters_Action_U.current_R;

    /* End of Outputs for SubSystem: '<Root>/SkidPad NP' */
  } else if (Inverters_Action_U.RacingMode == 4.0) {
    /* Outputs for IfAction SubSystem: '<Root>/AutoX PN' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/current_L' incorporates:
     *  Inport: '<Root>/current_L'
     */
    rtb_Merge1 = Inverters_Action_U.current_L;

    /* Gain: '<S2>/Gain' incorporates:
     *  Inport: '<Root>/current_R'
     */
    rtb_Merge2 = -Inverters_Action_U.current_R;

    /* End of Outputs for SubSystem: '<Root>/AutoX PN' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/Endurance NN' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Gain: '<S5>/Gain' incorporates:
     *  Inport: '<Root>/current_L'
     */
    rtb_Merge1 = -Inverters_Action_U.current_L;

    /* Gain: '<S5>/Gain1' incorporates:
     *  Inport: '<Root>/current_R'
     */
    rtb_Merge2 = -Inverters_Action_U.current_R;

    /* End of Outputs for SubSystem: '<Root>/Endurance NN' */
  }

  /* End of If: '<Root>/If' */

  /* Outputs for IfAction SubSystem: '<S4>/Unsubscribe//Subscribe' incorporates:
   *  ActionPort: '<S37>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S3>/Unsubscribe//Subscribe' incorporates:
   *  ActionPort: '<S12>/Action Port'
   */
  /* SwitchCase: '<S37>/Unsubscribe//Subscribe' incorporates:
   *  Inport: '<Root>/InvertersAction'
   *  SwitchCase: '<S12>/Unsubscribe//Subscribe'
   *  SwitchCase: '<S3>/Action Selector'
   *  SwitchCase: '<S4>/Action Selector'
   */
  tmp_0 = trunc(Inverters_Action_U.InvertersAction);
  tmp_1 = rtIsNaN(tmp_0);
  tmp_2 = rtIsInf(tmp_0);

  /* End of Outputs for SubSystem: '<S3>/Unsubscribe//Subscribe' */
  /* End of Outputs for SubSystem: '<S4>/Unsubscribe//Subscribe' */

  /* SwitchCase: '<S3>/Action Selector' incorporates:
   *  Inport: '<Root>/InvertersAction'
   */
  if (tmp_1 || tmp_2) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp_0, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 10:
   case 11:
    /* Outputs for IfAction SubSystem: '<S3>/Unsubscribe//Subscribe' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* SwitchCase: '<S12>/Unsubscribe//Subscribe' */
    if (tmp_1 || tmp_2) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp_0, 4.294967296E+9);
    }

    switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
     case 10:
      /* Outputs for IfAction SubSystem: '<S12>/Unsubscribe' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      Inverters_Action_Unsubscribe(&Inverters_Action_B.Merge2,
        &Inverters_Action_B.subscribed_k);

      /* End of Outputs for SubSystem: '<S12>/Unsubscribe' */
      break;

     case 11:
      /* Outputs for IfAction SubSystem: '<S12>/Subscribe' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S22>/Time Interval'
       *  SignalConversion generated from: '<S22>/ms'
       */
      Inverters_Action_B.Merge2 = 21U;

      /* Merge: '<S12>/subscribed?' incorporates:
       *  Constant: '<S22>/ 1'
       *  SignalConversion generated from: '<S22>/1'
       */
      Inverters_Action_B.subscribed_k = true;

      /* End of Outputs for SubSystem: '<S12>/Subscribe' */
      break;
    }

    /* If: '<S12>/If' incorporates:
     *  DataStoreRead: '<S12>/Data Store Read1'
     */
    if (Inverters_Action_DW.EnumerationCounter < 7.0) {
      /* Outputs for IfAction SubSystem: '<S12>/Register Enumerator ' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      Inverters_Ac_RegisterEnumerator(&rtb_Merge1_c, &rtb_MergeMuxEnable,
        &Inverters_Action_B.Merge, &Inverters_Action_DW.EnumerationCounter);

      /* End of Outputs for SubSystem: '<S12>/Register Enumerator ' */
    } else {
      /* Outputs for IfAction SubSystem: '<S12>/EnumerationDone' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      Inverters_Actio_EnumerationDone(Inverters_Action_B.subscribed_k,
        &rtb_Merge1_c, &rtb_MergeMuxEnable, &Inverters_Action_B.Merge);

      /* End of Outputs for SubSystem: '<S12>/EnumerationDone' */
    }

    /* End of If: '<S12>/If' */

    /* SignalConversion generated from: '<S12>/RegID' incorporates:
     *  Constant: '<S12>/Constant'
     */
    rtb_Merge = 61U;

    /* End of Outputs for SubSystem: '<S3>/Unsubscribe//Subscribe' */
    break;

   case 20:
   case 21:
    /* Outputs for IfAction SubSystem: '<S3>/DisableDrive//EnableDrive' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    Inverte_DisableDriveEnableDrive(Inverters_Action_U.InvertersAction,
      &rtb_Merge, &rtb_Merge1_c, &Inverters_Action_B.Merge2, &rtb_MergeMuxEnable);

    /* End of Outputs for SubSystem: '<S3>/DisableDrive//EnableDrive' */
    break;

   case 30:
    /* Outputs for IfAction SubSystem: '<S3>/Torque Command' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    Inverters_Action_TorqueCommand(rtb_Merge1, &rtb_Merge, &rtb_Merge1_c,
      &Inverters_Action_B.Merge2, &rtb_MergeMuxEnable,
      &Inverters_Action_ConstB.TorqueCommand);

    /* End of Outputs for SubSystem: '<S3>/Torque Command' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S3>/Action not Defined' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    Inverters_Acti_ActionnotDefined(&rtb_Merge, &rtb_Merge1_c,
      &Inverters_Action_B.Merge2, &rtb_MergeMuxEnable);

    /* End of Outputs for SubSystem: '<S3>/Action not Defined' */
    break;
  }

  /* If: '<S3>/If1' */
  if (rtb_MergeMuxEnable) {
    /* Outputs for IfAction SubSystem: '<S3>/bypass' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Outport: '<Root>/Inverter_L_b7tob0' incorporates:
     *  Outport: '<Root>/Inverter_L_RegID'
     *  Outport: '<Root>/Inverter_L_b15tob8'
     */
    Inverters_Action_bypass(rtb_Merge, rtb_Merge1_c, Inverters_Action_B.Merge2,
      &Inverters_Action_Y.Inverter_L_RegID,
      &Inverters_Action_Y.Inverter_L_b7tob0,
      &Inverters_Action_Y.Inverter_L_b15tob8);

    /* End of Outputs for SubSystem: '<S3>/bypass' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/Torque Command 0' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Outport: '<Root>/Inverter_L_b7tob0' incorporates:
     *  Outport: '<Root>/Inverter_L_RegID'
     *  Outport: '<Root>/Inverter_L_b15tob8'
     */
    Inverters_Action_TorqueCommand0(&Inverters_Action_Y.Inverter_L_RegID,
      &Inverters_Action_Y.Inverter_L_b7tob0,
      &Inverters_Action_Y.Inverter_L_b15tob8,
      &Inverters_Action_ConstB.TorqueCommand0);

    /* End of Outputs for SubSystem: '<S3>/Torque Command 0' */
  }

  /* End of If: '<S3>/If1' */

  /* SwitchCase: '<S4>/Action Selector' incorporates:
   *  Inport: '<Root>/InvertersAction'
   */
  if (tmp_1 || tmp_2) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp_0, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 10:
   case 11:
    /* Outputs for IfAction SubSystem: '<S4>/Unsubscribe//Subscribe' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* SwitchCase: '<S37>/Unsubscribe//Subscribe' */
    if (tmp_1 || tmp_2) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 4.294967296E+9);
    }

    switch (tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0)
    {
     case 10:
      /* Outputs for IfAction SubSystem: '<S37>/Unsubscribe' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      Inverters_Action_Unsubscribe(&Inverters_Action_B.Merge2_p,
        &Inverters_Action_B.subscribed);

      /* End of Outputs for SubSystem: '<S37>/Unsubscribe' */
      break;

     case 11:
      /* Outputs for IfAction SubSystem: '<S37>/Subscribe' incorporates:
       *  ActionPort: '<S47>/Action Port'
       */
      /* Merge: '<S4>/Merge2' incorporates:
       *  Constant: '<S47>/Time Interval'
       *  SignalConversion generated from: '<S47>/ms'
       */
      Inverters_Action_B.Merge2_p = 21U;

      /* Merge: '<S37>/subscribed?' incorporates:
       *  Constant: '<S47>/ '
       *  SignalConversion generated from: '<S47>/1'
       */
      Inverters_Action_B.subscribed = true;

      /* End of Outputs for SubSystem: '<S37>/Subscribe' */
      break;
    }

    /* If: '<S37>/If' incorporates:
     *  DataStoreRead: '<S37>/Data Store Read1'
     */
    if (Inverters_Action_DW.EnumerationCounter_g < 7.0) {
      /* Outputs for IfAction SubSystem: '<S37>/Register Enumerator ' incorporates:
       *  ActionPort: '<S46>/Action Port'
       */
      Inverters_Ac_RegisterEnumerator(&rtb_Merge1_c, &rtb_MergeMuxEnable,
        &Inverters_Action_B.Merge, &Inverters_Action_DW.EnumerationCounter_g);

      /* End of Outputs for SubSystem: '<S37>/Register Enumerator ' */
    } else {
      /* Outputs for IfAction SubSystem: '<S37>/EnumerationDone' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      Inverters_Actio_EnumerationDone(Inverters_Action_B.subscribed,
        &rtb_Merge1_c, &rtb_MergeMuxEnable, &Inverters_Action_B.Merge);

      /* End of Outputs for SubSystem: '<S37>/EnumerationDone' */
    }

    /* End of If: '<S37>/If' */

    /* SignalConversion generated from: '<S37>/RegID' incorporates:
     *  Constant: '<S37>/Constant'
     */
    rtb_Merge = 61U;

    /* End of Outputs for SubSystem: '<S4>/Unsubscribe//Subscribe' */
    break;

   case 20:
   case 21:
    /* Outputs for IfAction SubSystem: '<S4>/DisableDrive//EnableDrive' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    Inverte_DisableDriveEnableDrive(Inverters_Action_U.InvertersAction,
      &rtb_Merge, &rtb_Merge1_c, &Inverters_Action_B.Merge2_p,
      &rtb_MergeMuxEnable);

    /* End of Outputs for SubSystem: '<S4>/DisableDrive//EnableDrive' */
    break;

   case 30:
    /* Outputs for IfAction SubSystem: '<S4>/Torque Command' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    Inverters_Action_TorqueCommand(rtb_Merge2, &rtb_Merge, &rtb_Merge1_c,
      &Inverters_Action_B.Merge2_p, &rtb_MergeMuxEnable,
      &Inverters_Action_ConstB.TorqueCommand_k);

    /* End of Outputs for SubSystem: '<S4>/Torque Command' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S4>/Action not Defined' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    Inverters_Acti_ActionnotDefined(&rtb_Merge, &rtb_Merge1_c,
      &Inverters_Action_B.Merge2_p, &rtb_MergeMuxEnable);

    /* End of Outputs for SubSystem: '<S4>/Action not Defined' */
    break;
  }

  /* If: '<S4>/If1' */
  if (rtb_MergeMuxEnable) {
    /* Outputs for IfAction SubSystem: '<S4>/bypass' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    /* Outport: '<Root>/Inverter_R_b7tob0' incorporates:
     *  Outport: '<Root>/Inverter_R_RegID'
     *  Outport: '<Root>/Inverter_R_b15tob8'
     */
    Inverters_Action_bypass(rtb_Merge, rtb_Merge1_c, Inverters_Action_B.Merge2_p,
      &Inverters_Action_Y.Inverter_R_RegID,
      &Inverters_Action_Y.Inverter_R_b7tob0,
      &Inverters_Action_Y.Inverter_R_b15tob8);

    /* End of Outputs for SubSystem: '<S4>/bypass' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/Torque Command 0' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* Outport: '<Root>/Inverter_R_b7tob0' incorporates:
     *  Outport: '<Root>/Inverter_R_RegID'
     *  Outport: '<Root>/Inverter_R_b15tob8'
     */
    Inverters_Action_TorqueCommand0(&Inverters_Action_Y.Inverter_R_RegID,
      &Inverters_Action_Y.Inverter_R_b7tob0,
      &Inverters_Action_Y.Inverter_R_b15tob8,
      &Inverters_Action_ConstB.TorqueCommand0_a);

    /* End of Outputs for SubSystem: '<S4>/Torque Command 0' */
  }

  /* End of If: '<S4>/If1' */

  /* Outport: '<Root>/InvertersSubscribed' */
  Inverters_Action_Y.InvertersSubscribed = Inverters_Action_B.Merge;

  /* If: '<S14>/If2' incorporates:
   *  Delay: '<S14>/Delay'
   *  Inport: '<Root>/InvertersAction'
   */
  if (Inverters_Action_U.InvertersAction != Inverters_Action_DW.Delay_DSTATE) {
    /* Outputs for IfAction SubSystem: '<S3>/Reset Enumeration' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    Inverters_Acti_ResetEnumeration(&Inverters_Action_DW.EnumerationCounter);

    /* End of Outputs for SubSystem: '<S3>/Reset Enumeration' */
  }

  /* End of If: '<S14>/If2' */

  /* If: '<S39>/If2' incorporates:
   *  Delay: '<S39>/Delay'
   *  Inport: '<Root>/InvertersAction'
   */
  if (Inverters_Action_U.InvertersAction != Inverters_Action_DW.Delay_DSTATE_f)
  {
    /* Outputs for IfAction SubSystem: '<S4>/Reset Enumeration' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    Inverters_Acti_ResetEnumeration(&Inverters_Action_DW.EnumerationCounter_g);

    /* End of Outputs for SubSystem: '<S4>/Reset Enumeration' */
  }

  /* End of If: '<S39>/If2' */
}

/* Model update function */
static void Inverters_Action_update(void)
{
  /* Update for Delay: '<S14>/Delay' incorporates:
   *  Inport: '<Root>/InvertersAction'
   */
  Inverters_Action_DW.Delay_DSTATE = Inverters_Action_U.InvertersAction;

  /* Update for Delay: '<S39>/Delay' incorporates:
   *  Inport: '<Root>/InvertersAction'
   */
  Inverters_Action_DW.Delay_DSTATE_f = Inverters_Action_U.InvertersAction;

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
  /* Start for DataStoreMemory: '<S3>/Data Store Memory1' */
  Inverters_Action_DW.LastAction = 0.0;

  /* Start for DataStoreMemory: '<S4>/Data Store Memory1' */
  Inverters_Action_DW.LastAction_l = 0.0;

  /* Start for DataStoreMemory: '<S3>/Data Store Memory2' */
  Inverters_Action_DW.EnumerationCounter = 0.0;

  /* Start for DataStoreMemory: '<S4>/Data Store Memory2' */
  Inverters_Action_DW.EnumerationCounter_g = 0.0;

  /* InitializeConditions for Delay: '<S14>/Delay' */
  Inverters_Action_DW.Delay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S39>/Delay' */
  Inverters_Action_DW.Delay_DSTATE_f = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Unsubscribe//Subscribe' */
  /* SystemInitialize for Merge: '<S12>/subscribed?' */
  Inverters_Action_B.subscribed_k = false;

  /* End of SystemInitialize for SubSystem: '<S3>/Unsubscribe//Subscribe' */

  /* SystemInitialize for IfAction SubSystem: '<S4>/Unsubscribe//Subscribe' */
  /* SystemInitialize for Merge: '<S37>/subscribed?' */
  Inverters_Action_B.subscribed = false;

  /* End of SystemInitialize for SubSystem: '<S4>/Unsubscribe//Subscribe' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  Inverters_Action_B.Merge = false;
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

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Inverters_Action_M points to
       static memory which is guaranteed to be non-NULL" */
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

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Inverters_Action_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Inverters_Action_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Inverters_Action_M->rtwLogInfo, (NULL));
    rtliSetLogT(Inverters_Action_M->rtwLogInfo, "tout");
    rtliSetLogX(Inverters_Action_M->rtwLogInfo, "");
    rtliSetLogXFinal(Inverters_Action_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Inverters_Action_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Inverters_Action_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Inverters_Action_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Inverters_Action_M->rtwLogInfo, 1);
    rtliSetLogY(Inverters_Action_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Inverters_Action_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Inverters_Action_M->rtwLogInfo, (NULL));
  }

  Inverters_Action_M->solverInfoPtr = (&Inverters_Action_M->solverInfo);
  Inverters_Action_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Inverters_Action_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Inverters_Action_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Inverters_Action_M->blockIO = ((void *) &Inverters_Action_B);
  (void) memset(((void *) &Inverters_Action_B), 0,
                sizeof(B_Inverters_Action_T));

  /* states (dwork) */
  Inverters_Action_M->dwork = ((void *) &Inverters_Action_DW);
  (void) memset((void *)&Inverters_Action_DW, 0,
                sizeof(DW_Inverters_Action_T));

  /* external inputs */
  Inverters_Action_M->inputs = (((void*)&Inverters_Action_U));
  (void)memset(&Inverters_Action_U, 0, sizeof(ExtU_Inverters_Action_T));

  /* external outputs */
  Inverters_Action_M->outputs = (&Inverters_Action_Y);
  (void)memset(&Inverters_Action_Y, 0, sizeof(ExtY_Inverters_Action_T));

  /* Initialize Sizes */
  Inverters_Action_M->Sizes.numContStates = (0);/* Number of continuous states */
  Inverters_Action_M->Sizes.numY = (7);/* Number of model outputs */
  Inverters_Action_M->Sizes.numU = (4);/* Number of model inputs */
  Inverters_Action_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Inverters_Action_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Inverters_Action_M->Sizes.numBlocks = (193);/* Number of blocks */
  Inverters_Action_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  return Inverters_Action_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
