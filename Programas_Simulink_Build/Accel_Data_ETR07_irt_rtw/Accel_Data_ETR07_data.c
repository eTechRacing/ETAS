/*
 * Accel_Data_ETR07_data.c
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

#include "Accel_Data_ETR07.h"
#include "Accel_Data_ETR07_private.h"

/* Block parameters (auto storage) */
P_Accel_Data_ETR07_T Accel_Data_ETR07_P = {
  /* Expression: 1/50
   * Referenced by: '<S7>/(º//s)//bit'
   */
  0.02,

  /* Expression: 5
   * Referenced by: '<S7>/Experimental Offset'
   */
  5.0,

  /* Expression: 0.025
   * Referenced by: '<S7>/Cycle Time'
   */
  0.025,

  /* Expression: 0
   * Referenced by: '<S7>/Data Store Memory'
   */
  0.0,

  /* Expression: 1/50
   * Referenced by: '<S8>/Rps//LSB'
   */
  0.02,

  /* Expression: 5
   * Referenced by: '<S8>/Experimental Offset'
   */
  5.0,

  /* Expression: 0.025
   * Referenced by: '<S8>/Cycle Time'
   */
  0.025,

  /* Expression: 0
   * Referenced by: '<S8>/Data Store Memory'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain4'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain2'
   */
  -1.0,

  /* Start of '<Root>/Low Pass2' */
  {
    /* Expression: 1
     * Referenced by: '<S11>/ct'
     */
    1.0,

    /* Expression: 0.905
     * Referenced by: '<S11>/exp(-tcycle//tau)1'
     */
    0.905,

    /* Expression: -1
     * Referenced by: '<S11>/Gain'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S11>/Data Store Memory'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S11>/Data Store Memory1'
     */
    0.0
  }
  ,

  /* End of '<Root>/Low Pass2' */

  /* Start of '<Root>/Low Pass1' */
  {
    /* Expression: 1
     * Referenced by: '<S10>/ct'
     */
    1.0,

    /* Expression: 0.905
     * Referenced by: '<S10>/exp(-tcycle//tau)1'
     */
    0.905,

    /* Expression: -1
     * Referenced by: '<S10>/Gain'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S10>/Data Store Memory'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S10>/Data Store Memory1'
     */
    0.0
  }
  ,

  /* End of '<Root>/Low Pass1' */

  /* Start of '<Root>/Low Pass' */
  {
    /* Expression: 1
     * Referenced by: '<S9>/ct'
     */
    1.0,

    /* Expression: 0.905
     * Referenced by: '<S9>/exp(-tcycle//tau)1'
     */
    0.905,

    /* Expression: -1
     * Referenced by: '<S9>/Gain'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S9>/Data Store Memory'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S9>/Data Store Memory1'
     */
    0.0
  }
  ,

  /* End of '<Root>/Low Pass' */

  /* Start of '<Root>/Acc Data Conversion R Z' */
  {
    /* Expression: -25
     * Referenced by: '<S6>/Experimental Offset'
     */
    -25.0,

    /* Expression: 1/1962
     * Referenced by: '<S6>/g//bit'
     */
    0.00050968399592252807,

    /* Expression: 9.81
     * Referenced by: '<S6>/Gain'
     */
    9.81
  }
  ,

  /* End of '<Root>/Acc Data Conversion R Z' */

  /* Start of '<Root>/Acc Data Conversion R Y' */
  {
    /* Expression: 41
     * Referenced by: '<S5>/Experimental Offset'
     */
    41.0,

    /* Expression: 1/1962
     * Referenced by: '<S5>/g//bit'
     */
    0.00050968399592252807,

    /* Expression: 9.81
     * Referenced by: '<S5>/Gain'
     */
    9.81
  }
  ,

  /* End of '<Root>/Acc Data Conversion R Y' */

  /* Start of '<Root>/Acc Data Conversion R X' */
  {
    /* Expression: -5
     * Referenced by: '<S4>/Experimental Offset'
     */
    -5.0,

    /* Expression: 1/1962
     * Referenced by: '<S4>/g//bit'
     */
    0.00050968399592252807,

    /* Expression: 9.81
     * Referenced by: '<S4>/Gain'
     */
    9.81
  }
  ,

  /* End of '<Root>/Acc Data Conversion R X' */

  /* Start of '<Root>/Acc Data Conversion F Z' */
  {
    /* Expression: -5
     * Referenced by: '<S3>/Experimental Offset'
     */
    -5.0,

    /* Expression: 1/1962
     * Referenced by: '<S3>/g//bit'
     */
    0.00050968399592252807,

    /* Expression: 9.81
     * Referenced by: '<S3>/Gain'
     */
    9.81
  }
  ,

  /* End of '<Root>/Acc Data Conversion F Z' */

  /* Start of '<Root>/Acc Data Conversion F Y' */
  {
    /* Expression: 41
     * Referenced by: '<S2>/Experimental Offset'
     */
    41.0,

    /* Expression: 1/1962
     * Referenced by: '<S2>/g//bit'
     */
    0.00050968399592252807,

    /* Expression: 9.81
     * Referenced by: '<S2>/Gain'
     */
    9.81
  }
  ,

  /* End of '<Root>/Acc Data Conversion F Y' */

  /* Start of '<Root>/Acc Data Conversion F X' */
  {
    /* Expression: -5
     * Referenced by: '<S1>/Experimental Offset'
     */
    -5.0,

    /* Expression: 1/1962
     * Referenced by: '<S1>/g//bit'
     */
    0.00050968399592252807,

    /* Expression: 9.81
     * Referenced by: '<S1>/Gain'
     */
    9.81
  }
  /* End of '<Root>/Acc Data Conversion F X' */
};
