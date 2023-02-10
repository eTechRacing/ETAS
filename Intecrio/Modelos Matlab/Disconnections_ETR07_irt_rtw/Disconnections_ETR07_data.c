/*
 * Disconnections_ETR07_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Disconnections_ETR07".
 *
 * Model version              : 1.36
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Jun 18 14:33:36 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Disconnections_ETR07.h"
#include "Disconnections_ETR07_private.h"

/* Block parameters (auto storage) */
P_Disconnections_ETR07_T Disconnections_ETR07_P = {
  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S13>/Merge'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Data Store Memory'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_b
   * Referenced by: '<S14>/Merge'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Data Store Memory'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_l
   * Referenced by: '<S15>/Merge'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Data Store Memory'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_m
   * Referenced by: '<S11>/Merge'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Data Store Memory'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_a
   * Referenced by: '<S10>/Merge'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Data Store Memory'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_o
   * Referenced by: '<S16>/Merge'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/Data Store Memory'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_p
   * Referenced by: '<S12>/Merge'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S66>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S67>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S65>/Constant'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S64>/Constant'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 4
   * Referenced by: '<Root>/Constant'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S1>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S43>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S43>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S41>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S41>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S42>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S42>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S31>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S31>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S32>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S32>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S56>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S57>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S58>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S60>/Constant'
   */
  0.0,

  /* Start of '<S43>/Signal_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S55>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S43>/Signal_OK' */

  /* Start of '<S43>/Signal_Failure' */
  {
    /* Expression: 1
     * Referenced by: '<S54>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S43>/Signal_Failure' */

  /* Start of '<S43>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S52>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S43>/CAN_OK' */

  /* Start of '<S43>/Error_Counter' */
  {
    /* Expression: 1
     * Referenced by: '<S53>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S43>/Error_Counter' */

  /* Start of '<S42>/Signal_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S51>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S42>/Signal_OK' */

  /* Start of '<S42>/Signal_Failure' */
  {
    /* Expression: 1
     * Referenced by: '<S50>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S42>/Signal_Failure' */

  /* Start of '<S42>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S48>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S42>/CAN_OK' */

  /* Start of '<S42>/Error_Counter' */
  {
    /* Expression: 1
     * Referenced by: '<S49>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S42>/Error_Counter' */

  /* Start of '<S41>/Signal_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S47>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S41>/Signal_OK' */

  /* Start of '<S41>/Signal_Failure' */
  {
    /* Expression: 1
     * Referenced by: '<S46>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S41>/Signal_Failure' */

  /* Start of '<S41>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S44>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S41>/CAN_OK' */

  /* Start of '<S41>/Error_Counter' */
  {
    /* Expression: 1
     * Referenced by: '<S45>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S41>/Error_Counter' */

  /* Start of '<S16>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S29>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S16>/CAN_OK' */

  /* Start of '<S16>/CAN_failure' */
  {
    /* Expression: 1
     * Referenced by: '<S30>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S16>/CAN_failure' */

  /* Start of '<S15>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S27>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S15>/CAN_OK' */

  /* Start of '<S15>/CAN_failure' */
  {
    /* Expression: 1
     * Referenced by: '<S28>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S15>/CAN_failure' */

  /* Start of '<S14>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S25>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S14>/CAN_OK' */

  /* Start of '<S14>/CAN_failure' */
  {
    /* Expression: 1
     * Referenced by: '<S26>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S14>/CAN_failure' */

  /* Start of '<S13>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S23>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S13>/CAN_OK' */

  /* Start of '<S13>/CAN_failure' */
  {
    /* Expression: 1
     * Referenced by: '<S24>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S13>/CAN_failure' */

  /* Start of '<S12>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S21>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S12>/CAN_OK' */

  /* Start of '<S12>/CAN_failure' */
  {
    /* Expression: 1
     * Referenced by: '<S22>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S12>/CAN_failure' */

  /* Start of '<S11>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S19>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S11>/CAN_OK' */

  /* Start of '<S11>/CAN_failure' */
  {
    /* Expression: 1
     * Referenced by: '<S20>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S11>/CAN_failure' */

  /* Start of '<S10>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S17>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S10>/CAN_OK' */

  /* Start of '<S10>/CAN_failure' */
  {
    /* Expression: 1
     * Referenced by: '<S18>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S10>/CAN_failure' */

  /* Start of '<S32>/Signal_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S40>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S32>/Signal_OK' */

  /* Start of '<S32>/Signal_Failure' */
  {
    /* Expression: 1
     * Referenced by: '<S39>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S32>/Signal_Failure' */

  /* Start of '<S32>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S37>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S32>/CAN_OK' */

  /* Start of '<S32>/Error_Counter' */
  {
    /* Expression: 1
     * Referenced by: '<S38>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S32>/Error_Counter' */

  /* Start of '<S31>/Signal_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S36>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S31>/Signal_OK' */

  /* Start of '<S31>/Signal_Failure' */
  {
    /* Expression: 1
     * Referenced by: '<S35>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S31>/Signal_Failure' */

  /* Start of '<S31>/CAN_OK' */
  {
    /* Expression: 0
     * Referenced by: '<S33>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S31>/CAN_OK' */

  /* Start of '<S31>/Error_Counter' */
  {
    /* Expression: 1
     * Referenced by: '<S34>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S31>/Error_Counter' */

  /* Start of '<S1>/Reset_counter' */
  {
    /* Expression: 1
     * Referenced by: '<S8>/Constant'
     */
    1.0
  }
  /* End of '<S1>/Reset_counter' */
};
