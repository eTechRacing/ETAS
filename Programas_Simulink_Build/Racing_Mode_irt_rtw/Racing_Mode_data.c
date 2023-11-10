/*
 * Racing_Mode_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Racing_Mode".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Nov 10 02:58:26 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Racing_Mode.h"
#include "Racing_Mode_private.h"

/* Block parameters (auto storage) */
P_Racing_Mode_T Racing_Mode_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S1>/Constant'
   */
  1U,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_SKF_Initial'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_CKF_Initial'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_Cte_SKF'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_Cte_CKF'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_Apps_Sat_Dwn'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_Apps_Sat_Up'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_Max_Regenerative_Torque'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_Power_Limit'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_K_Reduction_P'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/CEE_K_Reduction_Temperature'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<Root>/Merge'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<Root>/SKF_Initial Saturation'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/SKF_Initial Saturation'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<Root>/CKF_Initial Saturation'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/CKF_Initial Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Cte_SKF Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Cte_SKF Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Cte_CKF Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Cte_CKF Saturation'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Apps_Sat_Dwn Saturation'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<Root>/Apps_Sat_Dwn Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Apps_Sat_Up Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Apps_Sat_Up Saturation'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/Max_Regenerative_Torque Saturation'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Max_Regenerative_Torque Saturation'
   */
  0.0,

  /* Expression: 77
   * Referenced by: '<Root>/Power_Limit Saturation'
   */
  77.0,

  /* Expression: 0
   * Referenced by: '<Root>/Power_Limit Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/K_Reduction_P Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/K_Reduction_P Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/K_Reduction_Temperature Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/K_Reduction_Temperature Saturation'
   */
  0.0,

  /* Start of '<S5>/Endurance (5). Driver 2 (2)' */
  {
    /* Expression: 0
     * Referenced by: '<S24>/Apps_Sat_Dwn'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S24>/Apps_Sat_Up'
     */
    1.0,

    /* Expression: 0.4
     * Referenced by: '<S24>/CKF_Initial'
     */
    0.4,

    /* Expression: 0.98
     * Referenced by: '<S24>/Cte_CKF'
     */
    0.98,

    /* Expression: 0.98
     * Referenced by: '<S24>/Cte_SKF'
     */
    0.98,

    /* Expression: 0.2
     * Referenced by: '<S24>/K_Reduction_P'
     */
    0.2,

    /* Expression: 0.6
     * Referenced by: '<S24>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 1000
     * Referenced by: '<S24>/Max_Regenerative_Torque'
     */
    1000.0,

    /* Expression: 0.5
     * Referenced by: '<S24>/SKF_Initial'
     */
    0.5,

    /* Expression: 80
     * Referenced by: '<S24>/Power_Limit'
     */
    80.0
  }
  ,

  /* End of '<S5>/Endurance (5). Driver 2 (2)' */

  /* Start of '<S5>/AutoX (4). Driver 2 (2)' */
  {
    /* Expression: 0
     * Referenced by: '<S23>/Apps_Sat_Dwn'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S23>/Apps_Sat_Up'
     */
    1.0,

    /* Expression: 0.4
     * Referenced by: '<S23>/CKF_Initial'
     */
    0.4,

    /* Expression: 0.98
     * Referenced by: '<S23>/Cte_CKF'
     */
    0.98,

    /* Expression: 0.98
     * Referenced by: '<S23>/Cte_SKF'
     */
    0.98,

    /* Expression: 0.2
     * Referenced by: '<S23>/K_Reduction_P'
     */
    0.2,

    /* Expression: 0.6
     * Referenced by: '<S23>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 1000
     * Referenced by: '<S23>/Max_Regenerative_Torque'
     */
    1000.0,

    /* Expression: 0.5
     * Referenced by: '<S23>/SKF_Initial'
     */
    0.5,

    /* Expression: 80
     * Referenced by: '<S23>/Power_Limit'
     */
    80.0
  }
  ,

  /* End of '<S5>/AutoX (4). Driver 2 (2)' */

  /* Start of '<S5>/Skidpad (3). Driver 2 (2)' */
  {
    /* Expression: 0
     * Referenced by: '<S25>/Apps_Sat_Dwn'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S25>/Apps_Sat_Up'
     */
    1.0,

    /* Expression: 0.4
     * Referenced by: '<S25>/CKF_Initial'
     */
    0.4,

    /* Expression: 0.98
     * Referenced by: '<S25>/Cte_CKF'
     */
    0.98,

    /* Expression: 0.98
     * Referenced by: '<S25>/Cte_SKF'
     */
    0.98,

    /* Expression: 0.2
     * Referenced by: '<S25>/K_Reduction_P'
     */
    0.2,

    /* Expression: 0.6
     * Referenced by: '<S25>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 1000
     * Referenced by: '<S25>/Max_Regenerative_Torque'
     */
    1000.0,

    /* Expression: 0.5
     * Referenced by: '<S25>/SKF_Initial'
     */
    0.5,

    /* Expression: 80
     * Referenced by: '<S25>/Power_Limit'
     */
    80.0
  }
  ,

  /* End of '<S5>/Skidpad (3). Driver 2 (2)' */

  /* Start of '<S5>/Acceleration (2). Driver 2 (2) ' */
  {
    /* Expression: 0
     * Referenced by: '<S22>/Apps_Sat_Dwn'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S22>/Apps_Sat_Up'
     */
    1.0,

    /* Expression: 0.4
     * Referenced by: '<S22>/CKF_Initial'
     */
    0.4,

    /* Expression: 0.98
     * Referenced by: '<S22>/Cte_CKF'
     */
    0.98,

    /* Expression: 0.98
     * Referenced by: '<S22>/Cte_SKF'
     */
    0.98,

    /* Expression: 0.2
     * Referenced by: '<S22>/K_Reduction_P'
     */
    0.2,

    /* Expression: 0.6
     * Referenced by: '<S22>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 1000
     * Referenced by: '<S22>/Max_Regenerative_Torque'
     */
    1000.0,

    /* Expression: 0.5
     * Referenced by: '<S22>/SKF_Initial'
     */
    0.5,

    /* Expression: 80
     * Referenced by: '<S22>/Power_Limit'
     */
    80.0
  }
  ,

  /* End of '<S5>/Acceleration (2). Driver 2 (2) ' */

  /* Start of '<S4>/Endurance (5). Driver 1 (1)' */
  {
    /* Expression: 0
     * Referenced by: '<S20>/Apps_Sat_Dwn'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S20>/Apps_Sat_Up'
     */
    1.0,

    /* Expression: 0.4
     * Referenced by: '<S20>/CKF_Initial'
     */
    0.4,

    /* Expression: 0.98
     * Referenced by: '<S20>/Cte_CKF'
     */
    0.98,

    /* Expression: 0.98
     * Referenced by: '<S20>/Cte_SKF'
     */
    0.98,

    /* Expression: 0.2
     * Referenced by: '<S20>/K_Reduction_P'
     */
    0.2,

    /* Expression: 0.6
     * Referenced by: '<S20>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 1000
     * Referenced by: '<S20>/Max_Regenerative_Torque'
     */
    1000.0,

    /* Expression: 0.4
     * Referenced by: '<S20>/SKF_Initial'
     */
    0.4,

    /* Expression: 80
     * Referenced by: '<S20>/Power_Limit'
     */
    80.0
  }
  ,

  /* End of '<S4>/Endurance (5). Driver 1 (1)' */

  /* Start of '<S4>/AutoX (4). Driver 1 (1)' */
  {
    /* Expression: 0
     * Referenced by: '<S19>/Apps_Sat_Dwn'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S19>/Apps_Sat_Up'
     */
    1.0,

    /* Expression: 0.6
     * Referenced by: '<S19>/CKF_Initial'
     */
    0.6,

    /* Expression: 0.98
     * Referenced by: '<S19>/Cte_CKF'
     */
    0.98,

    /* Expression: 0.98
     * Referenced by: '<S19>/Cte_SKF'
     */
    0.98,

    /* Expression: 0.2
     * Referenced by: '<S19>/K_Reduction_P'
     */
    0.2,

    /* Expression: 0.6
     * Referenced by: '<S19>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 1000
     * Referenced by: '<S19>/Max_Regenerative_Torque'
     */
    1000.0,

    /* Expression: 0.6
     * Referenced by: '<S19>/SKF_Initial'
     */
    0.6,

    /* Expression: 80
     * Referenced by: '<S19>/Power_Limit'
     */
    80.0
  }
  ,

  /* End of '<S4>/AutoX (4). Driver 1 (1)' */

  /* Start of '<S4>/Skidpad (3). Driver 1 (1)' */
  {
    /* Expression: 0
     * Referenced by: '<S21>/Apps_Sat_Dwn'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S21>/Apps_Sat_Up'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S21>/CKF_Initial'
     */
    1.0,

    /* Expression: 0.97
     * Referenced by: '<S21>/Cte_CKF'
     */
    0.97,

    /* Expression: 0.97
     * Referenced by: '<S21>/Cte_SKF'
     */
    0.97,

    /* Expression: 0.2
     * Referenced by: '<S21>/K_Reduction_P'
     */
    0.2,

    /* Expression: 0.6
     * Referenced by: '<S21>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 140
     * Referenced by: '<S21>/Max_Regenerative_Torque'
     */
    140.0,

    /* Expression: 1
     * Referenced by: '<S21>/SKF_Initial'
     */
    1.0,

    /* Expression: 80
     * Referenced by: '<S21>/Power_Limit'
     */
    80.0
  }
  ,

  /* End of '<S4>/Skidpad (3). Driver 1 (1)' */

  /* Start of '<S4>/Acceleration (2). Driver 1 (1) ' */
  {
    /* Expression: 0
     * Referenced by: '<S18>/Apps_Sat_Dwn'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S18>/Apps_Sat_Up'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S18>/CKF_Initial'
     */
    1.0,

    /* Expression: 0.93
     * Referenced by: '<S18>/Cte_CKF'
     */
    0.93,

    /* Expression: 0.93
     * Referenced by: '<S18>/Cte_SKF'
     */
    0.93,

    /* Expression: 0.2
     * Referenced by: '<S18>/K_Reduction_P'
     */
    0.2,

    /* Expression: 0.6
     * Referenced by: '<S18>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 140
     * Referenced by: '<S18>/Max_Regenerative_Torque'
     */
    140.0,

    /* Expression: 1
     * Referenced by: '<S18>/SKF_Initial'
     */
    1.0,

    /* Expression: 80
     * Referenced by: '<S18>/Power_Limit'
     */
    80.0
  }
  ,

  /* End of '<S4>/Acceleration (2). Driver 1 (1) ' */

  /* Start of '<S2>/K_Reduction_Temperature' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S14>/Out1'
     */
    0.0,

    /* Expression: 1/100
     * Referenced by: '<S14>/Gain'
     */
    0.01
  }
  ,

  /* End of '<S2>/K_Reduction_Temperature' */

  /* Start of '<S2>/K_Reduction_P' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S13>/Out1'
     */
    0.0,

    /* Expression: 1/100
     * Referenced by: '<S13>/Gain'
     */
    0.01
  }
  ,

  /* End of '<S2>/K_Reduction_P' */

  /* Start of '<S2>/Power_Limit' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S16>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S2>/Power_Limit' */

  /* Start of '<S2>/Max_Regenerative_Torque' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S15>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S2>/Max_Regenerative_Torque' */

  /* Start of '<S2>/Apps_Sat_Up' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S9>/Out1'
     */
    0.0,

    /* Expression: 1/100
     * Referenced by: '<S9>/Gain'
     */
    0.01
  }
  ,

  /* End of '<S2>/Apps_Sat_Up' */

  /* Start of '<S2>/Apps_Sat_Dwn' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S8>/Out1'
     */
    0.0,

    /* Expression: 1/100
     * Referenced by: '<S8>/Gain'
     */
    0.01
  }
  ,

  /* End of '<S2>/Apps_Sat_Dwn' */

  /* Start of '<S2>/Cte_CKF' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S11>/Out1'
     */
    0.0,

    /* Expression: 1/1000
     * Referenced by: '<S11>/Gain'
     */
    0.001
  }
  ,

  /* End of '<S2>/Cte_CKF' */

  /* Start of '<S2>/Cte_SKF' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S12>/Out1'
     */
    0.0,

    /* Expression: 1/1000
     * Referenced by: '<S12>/Gain'
     */
    0.001
  }
  ,

  /* End of '<S2>/Cte_SKF' */

  /* Start of '<S2>/CKF_Initial' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S10>/Out1'
     */
    0.0,

    /* Expression: 1/1000
     * Referenced by: '<S10>/Gain'
     */
    0.001
  }
  ,

  /* End of '<S2>/CKF_Initial' */

  /* Start of '<S2>/SKF_Initial' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S17>/Out1'
     */
    0.0,

    /* Expression: 1/1000
     * Referenced by: '<S17>/Gain'
     */
    0.001
  }
  ,

  /* End of '<S2>/SKF_Initial' */

  /* Start of '<Root>/Workshop Test (01)' */
  {
    /* Expression: 0.2
     * Referenced by: '<S7>/Apps_Sat_Dwn'
     */
    0.2,

    /* Expression: 0.8
     * Referenced by: '<S7>/Apps_Sat_Up'
     */
    0.8,

    /* Expression: 0.9
     * Referenced by: '<S7>/CKF_Initial'
     */
    0.9,

    /* Expression: 0.98
     * Referenced by: '<S7>/Cte_CKF'
     */
    0.98,

    /* Expression: 0.98
     * Referenced by: '<S7>/Cte_SKF'
     */
    0.98,

    /* Expression: 0.5
     * Referenced by: '<S7>/K_Reduction_P'
     */
    0.5,

    /* Expression: 0.6
     * Referenced by: '<S7>/K_Reduction_Temperature'
     */
    0.6,

    /* Expression: 10
     * Referenced by: '<S7>/Max_Regenerative_Torque'
     */
    10.0,

    /* Expression: 0.9
     * Referenced by: '<S7>/SKF_Initial'
     */
    0.9,

    /* Expression: 1
     * Referenced by: '<S7>/Power_Limit'
     */
    1.0
  }
  /* End of '<Root>/Workshop Test (01)' */
};
