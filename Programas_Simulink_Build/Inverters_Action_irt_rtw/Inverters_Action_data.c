/*
 * Inverters_Action_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Inverters_Action".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 12:57:49 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Inverters_Action.h"
#include "Inverters_Action_private.h"

/* Block parameters (auto storage) */
P_Inverters_Action_T Inverters_Action_P = {
  /* Expression: 0.0
   * Referenced by: '<S10>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Data Store Memory2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S35>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Data Store Memory2'
   */
  0.0,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<S10>/Delay'
   */
  1U,

  /* Computed Parameter: Delay_DelayLength_h
   * Referenced by: '<S35>/Delay'
   */
  1U,

  /* Computed Parameter: TimeInterval_Value
   * Referenced by: '<S17>/Time Interval'
   */
  25U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S8>/Constant'
   */
  61U,

  /* Computed Parameter: TimeInterval_Value_d
   * Referenced by: '<S42>/Time Interval'
   */
  25U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S33>/Constant'
   */
  61U,

  /* Computed Parameter: _Value
   * Referenced by: '<S17>/ '
   */
  1,

  /* Computed Parameter: subscribed_InitialOutput
   * Referenced by: '<S8>/subscribed?'
   */
  0,

  /* Computed Parameter: u_Value
   * Referenced by: '<S42>/ 1'
   */
  1,

  /* Computed Parameter: subscribed_InitialOutput_k
   * Referenced by: '<S33>/subscribed?'
   */
  0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<Root>/Merge'
   */
  0,

  /* Start of '<S2>/Reset Enumeration' */
  {
    /* Expression: 0
     * Referenced by: '<S30>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S2>/Reset Enumeration' */

  /* Start of '<S2>/Torque Command 0' */
  {
    /* Expression: 32767
     * Referenced by: '<S32>/Bits_Max'
     */
    32767.0,

    /* Expression: 0
     * Referenced by: '<S32>/Constant'
     */
    0.0,

    /* Expression: 200
     * Referenced by: '<S32>/IMAX'
     */
    200.0,

    /* Expression: BitMask
     * Referenced by: '<S39>/Bitwise Operator'
     */
    255U,

    /* Expression: BitMask
     * Referenced by: '<S39>/Bitwise Operator1'
     */
    255U,

    /* Computed Parameter: ux90_Value
     * Referenced by: '<S32>/0x90'
     */
    144U
  }
  ,

  /* End of '<S2>/Torque Command 0' */

  /* Start of '<S2>/Action not Defined' */
  {
    /* Computed Parameter: u1_Value
     * Referenced by: '<S28>/0 1'
     */
    0U,

    /* Computed Parameter: u2_Value
     * Referenced by: '<S28>/0 2'
     */
    0U,

    /* Computed Parameter: u3_Value
     * Referenced by: '<S28>/0 3'
     */
    0U,

    /* Computed Parameter: u_Value
     * Referenced by: '<S28>/0 '
     */
    0
  }
  ,

  /* End of '<S2>/Action not Defined' */

  /* Start of '<S2>/Torque Command' */
  {
    /* Expression: 32767
     * Referenced by: '<S31>/Bits_Max'
     */
    32767.0,

    /* Expression: 200
     * Referenced by: '<S31>/IMAX'
     */
    200.0,

    /* Expression: BitMask
     * Referenced by: '<S38>/Bitwise Operator'
     */
    255U,

    /* Expression: BitMask
     * Referenced by: '<S38>/Bitwise Operator1'
     */
    255U,

    /* Computed Parameter: ux90_Value
     * Referenced by: '<S31>/0x90'
     */
    144U,

    /* Computed Parameter: AlwaysEnabledifactionistorqueco
     * Referenced by: '<S31>/Always Enabled if action is torquecommand'
     */
    1
  }
  ,

  /* End of '<S2>/Torque Command' */

  /* Start of '<S2>/DisableDrive//EnableDrive' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S36>/Constant'
     */
    0U,

    /* Computed Parameter: Constant_Value_g
     * Referenced by: '<S37>/Constant'
     */
    4U,

    /* Computed Parameter: ux51_Value
     * Referenced by: '<S29>/0x51'
     */
    81U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S29>/Constant'
     */
    0U,

    /* Computed Parameter: void1_Value
     * Referenced by: '<S29>/void1'
     */
    1
  }
  ,

  /* End of '<S2>/DisableDrive//EnableDrive' */

  /* Start of '<S33>/Unsubscribe' */
  {
    /* Computed Parameter: uXFF_Value
     * Referenced by: '<S43>/0XFF'
     */
    255U,

    /* Computed Parameter: _Value
     * Referenced by: '<S43>/ '
     */
    1
  }
  ,

  /* End of '<S33>/Unsubscribe' */

  /* Start of '<S33>/EnumerationDone' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S40>/Constant'
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S40>/Constant1'
     */
    0
  }
  ,

  /* End of '<S33>/EnumerationDone' */

  /* Start of '<S33>/Register Enumerator ' */
  {
    /* Expression: 1
     * Referenced by: '<S41>/Constant'
     */
    1.0,

    /* Computed Parameter: ux20_Value
     * Referenced by: '<S45>/0x20'
     */
    32U,

    /* Computed Parameter: ux26_Value
     * Referenced by: '<S46>/0x26'
     */
    38U,

    /* Computed Parameter: ux27_Value
     * Referenced by: '<S47>/0x27'
     */
    39U,

    /* Computed Parameter: ux30_Value
     * Referenced by: '<S48>/0x30'
     */
    48U,

    /* Computed Parameter: ux49_Value
     * Referenced by: '<S51>/0x49'
     */
    73U,

    /* Computed Parameter: ux4A_Value
     * Referenced by: '<S50>/0x4A'
     */
    74U,

    /* Computed Parameter: uxE8_Value
     * Referenced by: '<S44>/0xE8'
     */
    232U,

    /* Computed Parameter: uxEB_Value
     * Referenced by: '<S52>/0xEB'
     */
    235U,

    /* Computed Parameter: Registeradress_Value
     * Referenced by: '<S49>/ Register adress'
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S41>/Constant1'
     */
    1,

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S41>/Constant2'
     */
    1
  }
  ,

  /* End of '<S33>/Register Enumerator ' */

  /* Start of '<S1>/Reset Enumeration' */
  {
    /* Expression: 0
     * Referenced by: '<S5>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S1>/Reset Enumeration' */

  /* Start of '<S1>/Torque Command 0' */
  {
    /* Expression: 32767
     * Referenced by: '<S7>/Bits_Max'
     */
    32767.0,

    /* Expression: 0
     * Referenced by: '<S7>/Constant'
     */
    0.0,

    /* Expression: 200
     * Referenced by: '<S7>/IMAX'
     */
    200.0,

    /* Expression: BitMask
     * Referenced by: '<S14>/Bitwise Operator'
     */
    255U,

    /* Expression: BitMask
     * Referenced by: '<S14>/Bitwise Operator1'
     */
    255U,

    /* Computed Parameter: ux90_Value
     * Referenced by: '<S7>/0x90'
     */
    144U
  }
  ,

  /* End of '<S1>/Torque Command 0' */

  /* Start of '<S1>/Action not Defined' */
  {
    /* Computed Parameter: u1_Value
     * Referenced by: '<S3>/0 1'
     */
    0U,

    /* Computed Parameter: u2_Value
     * Referenced by: '<S3>/0 2'
     */
    0U,

    /* Computed Parameter: u3_Value
     * Referenced by: '<S3>/0 3'
     */
    0U,

    /* Computed Parameter: u_Value
     * Referenced by: '<S3>/0 '
     */
    0
  }
  ,

  /* End of '<S1>/Action not Defined' */

  /* Start of '<S1>/Torque Command' */
  {
    /* Expression: 32767
     * Referenced by: '<S6>/Bits_Max'
     */
    32767.0,

    /* Expression: 200
     * Referenced by: '<S6>/IMAX'
     */
    200.0,

    /* Expression: BitMask
     * Referenced by: '<S13>/Bitwise Operator'
     */
    255U,

    /* Expression: BitMask
     * Referenced by: '<S13>/Bitwise Operator1'
     */
    255U,

    /* Computed Parameter: ux90_Value
     * Referenced by: '<S6>/0x90'
     */
    144U,

    /* Computed Parameter: AlwaysEnabledifactionistorqueco
     * Referenced by: '<S6>/Always Enabled if action is torquecommand'
     */
    1
  }
  ,

  /* End of '<S1>/Torque Command' */

  /* Start of '<S1>/DisableDrive//EnableDrive' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S11>/Constant'
     */
    0U,

    /* Computed Parameter: Constant_Value_g
     * Referenced by: '<S12>/Constant'
     */
    4U,

    /* Computed Parameter: ux51_Value
     * Referenced by: '<S4>/0x51'
     */
    81U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S4>/Constant'
     */
    0U,

    /* Computed Parameter: void1_Value
     * Referenced by: '<S4>/void1'
     */
    1
  }
  ,

  /* End of '<S1>/DisableDrive//EnableDrive' */

  /* Start of '<S8>/Unsubscribe' */
  {
    /* Computed Parameter: uXFF_Value
     * Referenced by: '<S18>/0XFF'
     */
    255U,

    /* Computed Parameter: _Value
     * Referenced by: '<S18>/ '
     */
    0
  }
  ,

  /* End of '<S8>/Unsubscribe' */

  /* Start of '<S8>/EnumerationDone' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S15>/Constant'
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S15>/Constant1'
     */
    0
  }
  ,

  /* End of '<S8>/EnumerationDone' */

  /* Start of '<S8>/Register Enumerator ' */
  {
    /* Expression: 1
     * Referenced by: '<S16>/Constant'
     */
    1.0,

    /* Computed Parameter: ux20_Value
     * Referenced by: '<S20>/0x20'
     */
    32U,

    /* Computed Parameter: ux26_Value
     * Referenced by: '<S21>/0x26'
     */
    38U,

    /* Computed Parameter: ux27_Value
     * Referenced by: '<S22>/0x27'
     */
    39U,

    /* Computed Parameter: ux30_Value
     * Referenced by: '<S23>/0x30'
     */
    48U,

    /* Computed Parameter: ux49_Value
     * Referenced by: '<S26>/0x49'
     */
    73U,

    /* Computed Parameter: ux4A_Value
     * Referenced by: '<S25>/0x4A'
     */
    74U,

    /* Computed Parameter: uxE8_Value
     * Referenced by: '<S19>/0xE8'
     */
    232U,

    /* Computed Parameter: uxEB_Value
     * Referenced by: '<S27>/0xEB'
     */
    235U,

    /* Computed Parameter: Registeradress_Value
     * Referenced by: '<S24>/ Register adress'
     */
    0U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S16>/Constant1'
     */
    1,

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S16>/Constant2'
     */
    1
  }
  /* End of '<S8>/Register Enumerator ' */
};
