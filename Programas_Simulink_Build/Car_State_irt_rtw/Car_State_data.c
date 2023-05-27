/*
 * Car_State_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Car_State".
 *
 * Model version              : 1.57
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 12:56:28 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Car_State.h"
#include "Car_State_private.h"

/* Block parameters (auto storage) */
P_Car_State_T Car_State_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S21>/Constant'
   */
  420.0,

  /* Expression: 6
   * Referenced by: '<S19>/Constant'
   */
  6.0,

  /* Expression: 3
   * Referenced by: '<S20>/Constant'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S28>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<S10>/Gain'
   */
  0.9,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S4>/Merge'
   */
  0.0,

  /* Expression: 600
   * Referenced by: '<S9>/Saturation'
   */
  600.0,

  /* Expression: 400
   * Referenced by: '<S9>/Saturation'
   */
  400.0,

  /* Expression: 1/100
   * Referenced by: '<S9>/If DC BUS not bits'
   */
  0.01,

  /* Start of '<S11>/OK' */
  {
    /* Expression: 1
     * Referenced by: '<S32>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S11>/OK' */

  /* Start of '<S11>/ERROR' */
  {
    /* Expression: 0
     * Referenced by: '<S31>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S11>/ERROR' */

  /* Start of '<S10>/FALSE' */
  {
    /* Expression: 0
     * Referenced by: '<S29>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S10>/FALSE' */

  /* Start of '<S10>/TRUE' */
  {
    /* Expression: 1
     * Referenced by: '<S30>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S10>/TRUE' */

  /* Start of '<S26>/Latched Error' */
  {
    /* Expression: 1
     * Referenced by: '<S27>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S26>/Latched Error' */

  /* Start of '<S7>/Failure' */
  {
    /* Expression: 1
     * Referenced by: '<S25>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S7>/Failure' */

  /* Start of '<S4>/Obrir AIRs' */
  {
    /* Expression: 0
     * Referenced by: '<S18>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S4>/Obrir AIRs' */

  /* Start of '<S3>/FALSE' */
  {
    /* Expression: 0
     * Referenced by: '<S16>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S3>/FALSE' */

  /* Start of '<S3>/TRUE' */
  {
    /* Expression: 1
     * Referenced by: '<S17>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S3>/TRUE' */

  /* Start of '<S2>/FALSE' */
  {
    /* Expression: 0
     * Referenced by: '<S14>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S2>/FALSE' */

  /* Start of '<S2>/TRUE' */
  {
    /* Expression: 1
     * Referenced by: '<S15>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S2>/TRUE' */

  /* Start of '<S1>/FALSE' */
  {
    /* Expression: 0
     * Referenced by: '<S12>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S1>/FALSE' */

  /* Start of '<S1>/TRUE' */
  {
    /* Expression: 1
     * Referenced by: '<S13>/Constant'
     */
    1.0
  }
  /* End of '<S1>/TRUE' */
};
