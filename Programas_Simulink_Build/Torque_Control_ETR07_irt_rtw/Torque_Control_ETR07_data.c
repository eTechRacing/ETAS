/*
 * Torque_Control_ETR07_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control_ETR07".
 *
 * Model version              : 1.21
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Jun 18 14:41:15 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_Control_ETR07.h"
#include "Torque_Control_ETR07_private.h"

/* Block parameters (auto storage) */
P_Torque_Control_ETR07_T Torque_Control_ETR07_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S31>/Constant'
   */
  15.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S25>/Constant'
   */
  15.0,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S24>/Constant'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S9>/Data Store Memory10'
   */
  0.0,

  /* Expression: 0.002359
   * Referenced by: '<S14>/A'
   */
  0.002359,

  /* Expression: 6.363
   * Referenced by: '<S14>/C'
   */
  6.363,

  /* Expression: 1.0396
   * Referenced by: '<S14>/B'
   */
  1.0396,

  /* Expression: 0
   * Referenced by: '<S14>/Zero'
   */
  0.0,

  /* Expression: 0.0030128
   * Referenced by: '<S15>/A1'
   */
  0.0030128,

  /* Expression: 6.5613
   * Referenced by: '<S15>/C1'
   */
  6.5613,

  /* Expression: 1.0388
   * Referenced by: '<S15>/B1'
   */
  1.0388,

  /* Expression: 0
   * Referenced by: '<S15>/Zero'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S28>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S27>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S41>/ct'
   */
  1.0,

  /* Expression: 0.905
   * Referenced by: '<S41>/exp(-tcycle//tau)1'
   */
  0.905,

  /* Expression: -1
   * Referenced by: '<S41>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S41>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S41>/Data Store Memory1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S108>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S108>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S115>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S115>/Constant1'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<S107>/rpm'
   */
  200.0,

  /* Expression: 3.141592/30
   * Referenced by: '<S107>/Gain'
   */
  0.10471973333333334,

  /* Computed Parameter: Merge3_InitialOutput
   * Referenced by: '<S107>/Merge3'
   */
  0.0,

  /* Computed Parameter: Merge4_InitialOutput
   * Referenced by: '<S107>/Merge4'
   */
  0.0,

  /* Computed Parameter: Out_Throttle_Y0
   * Referenced by: '<S120>/Out_Throttle'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S150>/Constant'
   */
  1.0,

  /* Expression: 0.9
   * Referenced by: '<S150>/Switch'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S149>/Switch'
   */
  0.0,

  /* Computed Parameter: SKF_act_Y0
   * Referenced by: '<S144>/SKF_act'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S144>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S144>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S144>/Saturation'
   */
  0.3,

  /* Computed Parameter: CKF_act_Y0
   * Referenced by: '<S142>/CKF_act '
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_j
   * Referenced by: '<S142>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S142>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S142>/Saturation'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S101>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S101>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S101>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S101>/Constant3'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S101>/Constant4'
   */
  -1.0,

  /* Expression: 1/9.81
   * Referenced by: '<S101>/Gain'
   */
  0.1019367991845056,

  /* Expression: 0
   * Referenced by: '<S101>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S101>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S100>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S100>/Constant2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S100>/Constant3'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S100>/Constant4'
   */
  -1.0,

  /* Expression: 3.72
   * Referenced by: '<S130>/Steering_Ratio [-]'
   */
  3.72,

  /* Expression: 0
   * Referenced by: '<S100>/Integrator'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S130>/Constant8'
   */
  360.0,

  /* Expression: 0.92
   * Referenced by: '<S130>/Constant7'
   */
  0.92,

  /* Expression: 1.53
   * Referenced by: '<S130>/Wheelbase [m]'
   */
  1.53,

  /* Expression: -700
   * Referenced by: '<S130>/Cornering_Stiffness_F[N//º]'
   */
  -700.0,

  /* Expression: 360/(2*pi)
   * Referenced by: '<S130>/360//(2*pi)'
   */
  57.295779513082323,

  /* Expression: -1000
   * Referenced by: '<S130>/Cornering_Stiffness_R[N//º]'
   */
  -1000.0,

  /* Expression: 360/(2*pi)
   * Referenced by: '<S130>/360//(2pi)'
   */
  57.295779513082323,

  /* Expression: 43.21
   * Referenced by: '<S100>/Yaw_Inertia [kg//m^3]'
   */
  43.21,

  /* Expression: 1.15
   * Referenced by: '<S100>/Rear_Trackwidth [m] '
   */
  1.15,

  /* Expression: 2
   * Referenced by: '<S132>/Constant'
   */
  2.0,

  /* Expression: 1/9.81
   * Referenced by: '<S100>/Gravity'
   */
  0.1019367991845056,

  /* Expression: 1/2
   * Referenced by: '<S100>/Fy per wheel'
   */
  0.5,

  /* Expression: 1/9.81
   * Referenced by: '<S100>/Gravity1'
   */
  0.1019367991845056,

  /* Expression: 1
   * Referenced by: '<S100>/Constant6'
   */
  1.0,

  /* Computed Parameter: MaxTq_RRNm0inf_Y0
   * Referenced by: '<S68>/MaxTq_RR [Nm] (0,inf)'
   */
  0.0,

  /* Computed Parameter: MaxTq_RLNm0inf_Y0
   * Referenced by: '<S68>/MaxTq_RL [Nm] (0,inf)'
   */
  0.0,

  /* Computed Parameter: Flags_num5_Y0
   * Referenced by: '<S68>/Flags_[num5]'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S141>/Steering Wheel Maximum Angle'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S104>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S104>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S68>/Constant'
   */
  0.0,

  /* Expression: 140
   * Referenced by: '<S99>/Maximum Torque per engine [Nm]'
   */
  140.0,

  /* Expression: 140
   * Referenced by: '<S99>/Maximum Transmission Torque Dynamic [Nm]'
   */
  140.0,

  /* Expression: 130
   * Referenced by: '<S99>/Maximum Transmission Torque Static [Nm]'
   */
  130.0,

  /* Expression: 0
   * Referenced by: '<S106>/Constant1'
   */
  0.0,

  /* Expression: 0.025
   * Referenced by: '<S99>/Constant1'
   */
  0.025,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S68>/Merge2'
   */
  0.0,

  /* Expression: 13
   * Referenced by: '<S99>/Effective Rolling Radius[inch]'
   */
  13.0,

  /* Expression: 0.0254
   * Referenced by: '<S99>/inch to m'
   */
  0.0254,

  /* Expression: 0.97
   * Referenced by: '<S99>/3% difference'
   */
  0.97,

  /* Expression: 4
   * Referenced by: '<S99>/Transmision Ratio[-]'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S106>/Constant'
   */
  0.0,

  /* Computed Parameter: Merge3_InitialOutput_j
   * Referenced by: '<S68>/Merge3'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S99>/Tq_diff_Max'
   */
  100.0,

  /* Computed Parameter: Merge_InitialOutput_i
   * Referenced by: '<S97>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S97>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge4_InitialOutput_d
   * Referenced by: '<S68>/Merge4'
   */
  0.0,

  /* Computed Parameter: Merge5_InitialOutput
   * Referenced by: '<S68>/Merge5'
   */
  0.0,

  /* Computed Parameter: Merge6_InitialOutput
   * Referenced by: '<S68>/Merge6'
   */
  0.0,

  /* Computed Parameter: Merge7_InitialOutput
   * Referenced by: '<S68>/Merge7'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S166>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S166>/Gain1'
   */
  -1.0,

  /* Expression: 200
   * Referenced by: '<S165>/rpm'
   */
  200.0,

  /* Expression: 3.141592/30
   * Referenced by: '<S165>/Gain'
   */
  0.10471973333333334,

  /* Computed Parameter: Out_Throttle_Y0_a
   * Referenced by: '<S177>/Out_Throttle'
   */
  0.0,

  /* Computed Parameter: MaxTq_RRNm0inf_Y0_o
   * Referenced by: '<S69>/MaxTq_RR [Nm] (0,inf)'
   */
  0.0,

  /* Computed Parameter: MaxTq_RLNm0inf_Y0_d
   * Referenced by: '<S69>/MaxTq_RL [Nm] (0,inf)'
   */
  0.0,

  /* Computed Parameter: MaxFx_RRN0inf_Y0
   * Referenced by: '<S69>/MaxFx_RR [N] (0,inf)'
   */
  0.0,

  /* Computed Parameter: MaxFx_RLN0inf_Y0
   * Referenced by: '<S69>/MaxFx_RL [N] (0,inf)'
   */
  0.0,

  /* Computed Parameter: Fy_RN0inf_Y0
   * Referenced by: '<S69>/Fy_R [N] (0,inf)'
   */
  0.0,

  /* Computed Parameter: Masskg0inf_Y0
   * Referenced by: '<S69>/Mass [kg] (0,inf)'
   */
  0.0,

  /* Computed Parameter: Handlinginfinf_Y0
   * Referenced by: '<S69>/Handling [-] (-inf,inf)'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_h
   * Referenced by: '<S187>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S187>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S187>/Saturation'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S162>/Data Store Memory1'
   */
  0.0,

  /* Expression: 140
   * Referenced by: '<S159>/Maximum Torque per engine [Nm]'
   */
  140.0,

  /* Expression: 140
   * Referenced by: '<S159>/Maximum Transmission Torque Dynamic [Nm]'
   */
  140.0,

  /* Expression: 130
   * Referenced by: '<S159>/Maximum Transmission Torque Static [Nm]'
   */
  130.0,

  /* Expression: 0
   * Referenced by: '<S164>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S160>/Constant1'
   */
  -1.0,

  /* Expression: 1/9.81
   * Referenced by: '<S161>/Gravity1'
   */
  0.1019367991845056,

  /* Expression: 1/2
   * Referenced by: '<S161>/Fy per wheel'
   */
  0.5,

  /* Expression: 13
   * Referenced by: '<S159>/Effective Rolling Radius[inch]'
   */
  13.0,

  /* Expression: 0.0254
   * Referenced by: '<S159>/inch to m'
   */
  0.0254,

  /* Expression: 0.97
   * Referenced by: '<S159>/3% difference'
   */
  0.97,

  /* Expression: 4
   * Referenced by: '<S159>/Transmision Ratio[-]'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S164>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S160>/Constant'
   */
  -1.0,

  /* Computed Parameter: Merge_InitialOutput_l
   * Referenced by: '<S158>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput_k
   * Referenced by: '<S158>/Merge1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S93>/Constant'
   */
  1.0,

  /* Expression: 0.9
   * Referenced by: '<S93>/Switch'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S92>/Switch'
   */
  0.0,

  /* Computed Parameter: SKF_act_Y0_l
   * Referenced by: '<S87>/SKF_act'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_p
   * Referenced by: '<S87>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S87>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S87>/Saturation'
   */
  0.3,

  /* Expression: 1
   * Referenced by: '<S89>/Constant'
   */
  1.0,

  /* Expression: 0.9
   * Referenced by: '<S89>/Switch'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S88>/Switch'
   */
  0.0,

  /* Computed Parameter: CKF_act_Y0_j
   * Referenced by: '<S85>/CKF_act '
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_a
   * Referenced by: '<S85>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S85>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S85>/Saturation'
   */
  0.3,

  /* Expression: 100
   * Referenced by: '<S84>/Steering Wheel Maximum Angle'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S77>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S77>/Data Store Memory1'
   */
  0.0,

  /* Expression: 140
   * Referenced by: '<S67>/Steering Wheel Maximum Angle'
   */
  140.0,

  /* Expression: 130
   * Referenced by: '<S67>/Tq_max [Nm]'
   */
  130.0,

  /* Expression: 100
   * Referenced by: '<S67>/Tq_diff_max [Nm]'
   */
  100.0,

  /* Expression: 60
   * Referenced by: '<S66>/Torque_RL [Nm]'
   */
  60.0,

  /* Expression: 60
   * Referenced by: '<S66>/Torque_RR [Nm]'
   */
  60.0,

  /* Expression: 60
   * Referenced by: '<S54>/Limit Temperature IGBT [ºC]'
   */
  60.0,

  /* Expression: 110
   * Referenced by: '<S54>/Limit Temperature Motor [ºC]'
   */
  110.0,

  /* Expression: 45
   * Referenced by: '<S54>/Limit Temperature Celdas[ºC]'
   */
  45.0,

  /* Expression: -1
   * Referenced by: '<S54>/Gain'
   */
  -1.0,

  /* Expression: 10
   * Referenced by: '<S54>/Steering Wheel Saturation (per site) [deg] '
   */
  10.0,

  /* Computed Parameter: Merge_InitialOutput_pp
   * Referenced by: '<S54>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput_f
   * Referenced by: '<S54>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge2_InitialOutput_o
   * Referenced by: '<S54>/Merge2'
   */
  0.0,

  /* Computed Parameter: Merge3_InitialOutput_n
   * Referenced by: '<S54>/Merge3'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S63>/TEMP_LIMIT_UPPER'
   */
  50.0,

  /* Expression: 45
   * Referenced by: '<S60>/TEMP_LIMIT_LOWER'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<S58>/Not_Braking'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_jq
   * Referenced by: '<S58>/Merge'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S52>/BRAKE_THRESHOLD'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<S52>/Zero '
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S52>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S52>/Data Store Memory'
   */
  0.0,

  /* Expression: 800
   * Referenced by: '<S65>/Constant'
   */
  800.0,

  /* Expression: 800
   * Referenced by: '<S65>/Constant1'
   */
  800.0,

  /* Expression: 800
   * Referenced by: '<S65>/Constant2'
   */
  800.0,

  /* Expression: 800
   * Referenced by: '<S65>/Constant3'
   */
  800.0,

  /* Expression: 15
   * Referenced by: '<S197>/Constant'
   */
  15.0,

  /* Expression: 10
   * Referenced by: '<S197>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S197>/Saturation'
   */
  -10.0,

  /* Expression: 10
   * Referenced by: '<S197>/Saturation1'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S197>/Saturation1'
   */
  -10.0,

  /* Expression: 145
   * Referenced by: '<S55>/Saturation'
   */
  145.0,

  /* Expression: -70
   * Referenced by: '<S55>/Saturation'
   */
  -70.0,

  /* Expression: 145
   * Referenced by: '<S55>/Saturation1'
   */
  145.0,

  /* Expression: -70
   * Referenced by: '<S55>/Saturation1'
   */
  -70.0,

  /* Expression: 570
   * Referenced by: '<S6>/zero'
   */
  570.0,

  /* Expression: 2
   * Referenced by: '<S6>/half range'
   */
  2.0,

  /* Expression: 1000
   * Referenced by: '<S6>/range'
   */
  1000.0,

  /* Expression: 115
   * Referenced by: '<S6>/Gain'
   */
  115.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S7>/Gain1'
   */
  100.0,

  /* Computed Parameter: DataStoreMemory1_InitialValu_fl
   * Referenced by: '<S30>/Data Store Memory1'
   */
  0,

  /* Start of '<S58>/Temp_OK' */
  {
    /* Expression: 1
     * Referenced by: '<S62>/TEMP_LIMIT'
     */
    1.0
  }
  ,

  /* End of '<S58>/Temp_OK' */

  /* Start of '<S58>/Temp_LIMIT' */
  {
    /* Expression: 0
     * Referenced by: '<S61>/TEMP_LIMIT'
     */
    0.0
  }
  ,

  /* End of '<S58>/Temp_LIMIT' */

  /* Start of '<S187>/No spin' */
  {
    /* Expression: 0
     * Referenced by: '<S188>/Switch'
     */
    0.0
  }
  ,

  /* End of '<S187>/No spin' */

  /* Start of '<S187>/Spin ' */
  {
    /* Expression: 1
     * Referenced by: '<S189>/Constant'
     */
    1.0,

    /* Expression: 0.9
     * Referenced by: '<S189>/Switch'
     */
    0.9
  }
  ,

  /* End of '<S187>/Spin ' */

  /* Start of '<S158>/Inertia Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S178>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S178>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S158>/Inertia Braking' */

  /* Start of '<S158>/Mech_Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S179>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S179>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S158>/Mech_Braking' */

  /* Start of '<S142>/No spin' */
  {
    /* Expression: 0
     * Referenced by: '<S145>/Switch'
     */
    0.0
  }
  ,

  /* End of '<S142>/No spin' */

  /* Start of '<S142>/Spin ' */
  {
    /* Expression: 1
     * Referenced by: '<S146>/Constant'
     */
    1.0,

    /* Expression: 0.9
     * Referenced by: '<S146>/Switch'
     */
    0.9
  }
  ,

  /* End of '<S142>/Spin ' */

  /* Start of '<S97>/Inertia Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S122>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S122>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S97>/Inertia Braking' */

  /* Start of '<S97>/Mech_Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S123>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S123>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S97>/Mech_Braking' */

  /* Start of '<S107>/Control de Potencia ' */
  {
    /* Expression: 0
     * Referenced by: '<S109>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S109>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S107>/Control de Potencia ' */

  /* Start of '<S107>/Control de Temperatura' */
  {
    /* Expression: 1
     * Referenced by: '<S110>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S110>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S107>/Control de Temperatura' */

  /* Start of '<S30>/Not Imp Memo1' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S39>/Constant'
     */
    1
  }
  ,

  /* End of '<S30>/Not Imp Memo1' */

  /* Start of '<S30>/Imp Memo1' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S37>/Constant'
     */
    0
  }
  ,

  /* End of '<S30>/Imp Memo1' */

  /* Start of '<S30>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S36>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S30>/If Action Subsystem3' */

  /* Start of '<S30>/If Action Subsystem2' */
  {
    /* Expression: 1
     * Referenced by: '<S35>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S30>/If Action Subsystem2' */

  /* Start of '<S30>/Not Imp1' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S40>/Constant'
     */
    1
  }
  ,

  /* End of '<S30>/Not Imp1' */

  /* Start of '<S30>/Imp1' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S38>/Constant'
     */
    0
  }
  ,

  /* End of '<S30>/Imp1' */

  /* Start of '<S29>/Not Imp' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S34>/Constant'
     */
    1
  }
  ,

  /* End of '<S29>/Not Imp' */

  /* Start of '<S29>/Imp' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S33>/Constant'
     */
    0
  }
  ,

  /* End of '<S29>/Imp' */

  /* Start of '<S15>/Negative' */
  {
    /* Expression: -1
     * Referenced by: '<S23>/Gain'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S23>/Gain1'
     */
    -1.0
  }
  ,

  /* End of '<S15>/Negative' */

  /* Start of '<S14>/Negative' */
  {
    /* Expression: -1
     * Referenced by: '<S19>/Gain'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S19>/Gain1'
     */
    -1.0
  }
  ,

  /* End of '<S14>/Negative' */

  /* Start of '<S11>/OK' */
  {
    /* Expression: 0
     * Referenced by: '<S13>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S11>/OK' */

  /* Start of '<S11>/Latched Error' */
  {
    /* Expression: 1
     * Referenced by: '<S12>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S11>/Latched Error' */

  /* Start of '<S9>/LimitReached' */
  {
    /* Expression: 1
     * Referenced by: '<S10>/Constant'
     */
    1.0
  }
  /* End of '<S9>/LimitReached' */
};
