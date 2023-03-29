/*
 * Torque_Control_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 1.181
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 13:03:35 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_Control.h"
#include "Torque_Control_private.h"

/* Block parameters (auto storage) */
P_Torque_Control_T Torque_Control_P = {
  /* Mask Parameter: Temphigherthan50_const
   * Referenced by: '<S33>/Constant'
   */
  50.0,

  /* Mask Parameter: Temphigherthan50_const_k
   * Referenced by: '<S34>/Constant'
   */
  50.0,

  /* Mask Parameter: Temphigherthan110_const
   * Referenced by: '<S35>/Constant'
   */
  110.0,

  /* Mask Parameter: Flag_Accu_const
   * Referenced by: '<S27>/Constant'
   */
  1.0,

  /* Mask Parameter: Flag_Inv_const
   * Referenced by: '<S28>/Constant'
   */
  1.0,

  /* Mask Parameter: Flag_Mot_const
   * Referenced by: '<S29>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S44>/Constant'
   */
  15.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S38>/Constant'
   */
  15.0,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S37>/Constant'
   */
  50.0,

  /* Mask Parameter: Temphigherthan50_const_l
   * Referenced by: '<S216>/Constant'
   */
  50.0,

  /* Mask Parameter: Temphigherthan50_const_g
   * Referenced by: '<S217>/Constant'
   */
  50.0,

  /* Mask Parameter: Temphigherthan110_const_c
   * Referenced by: '<S218>/Constant'
   */
  110.0,

  /* Mask Parameter: Flag_Accu_const_h
   * Referenced by: '<S210>/Constant'
   */
  1.0,

  /* Mask Parameter: Flag_Inv_const_e
   * Referenced by: '<S211>/Constant'
   */
  1.0,

  /* Mask Parameter: Flag_Mot_const_n
   * Referenced by: '<S212>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Data Store Memory10'
   */
  0.0,

  /* Expression: 120
   * Referenced by: '<S3>/Max_Tq_per_motor'
   */
  120.0,

  /* Expression: 1/100
   * Referenced by: '<S24>/Gain6'
   */
  0.01,

  /* Expression: [0.4 0.6 0.8 0.95 1 1 0.98 0.95]
   * Referenced by: '<S24>/Lookup_SoC_SoP_dischg'
   */
  { 0.4, 0.6, 0.8, 0.95, 1.0, 1.0, 0.98, 0.95 },

  /* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.9 1]
   * Referenced by: '<S24>/Lookup_SoC_SoP_dischg'
   */
  { 0.02, 0.1, 0.2, 0.3, 0.5, 0.8, 0.9, 1.0 },

  /* Expression: 45
   * Referenced by: '<S30>/Constant1'
   */
  45.0,

  /* Expression: 5
   * Referenced by: '<S30>/Constant2'
   */
  5.0,

  /* Expression: 0.4
   * Referenced by: '<S3>/initial_limitation'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<S30>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S30>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S30>/Saturation1'
   */
  0.0,

  /* Expression: 45
   * Referenced by: '<S31>/Constant1'
   */
  45.0,

  /* Expression: 5
   * Referenced by: '<S31>/Constant2'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<S31>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S31>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S31>/Saturation1'
   */
  0.0,

  /* Expression: 105
   * Referenced by: '<S32>/Constant1'
   */
  105.0,

  /* Expression: 5
   * Referenced by: '<S32>/Constant2'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<S32>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S32>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S32>/Saturation1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Saturation'
   */
  0.0,

  /* Expression: 1/100
   * Referenced by: '<S24>/Gain5'
   */
  0.01,

  /* Expression: [0.95 1 1 1 1 0.9 0.75 0.02]
   * Referenced by: '<S24>/Lookup_SoC_SoP_chg'
   */
  { 0.95, 1.0, 1.0, 1.0, 1.0, 0.9, 0.75, 0.02 },

  /* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.95 1]
   * Referenced by: '<S24>/Lookup_SoC_SoP_chg'
   */
  { 0.02, 0.1, 0.2, 0.3, 0.5, 0.8, 0.95, 1.0 },

  /* Expression: [1 0.75 0.5 0 0]
   * Referenced by: '<S24>/Lookup_Temp_SoP_chg'
   */
  { 1.0, 0.75, 0.5, 0.0, 0.0 },

  /* Expression: [45 48 49 50 51]
   * Referenced by: '<S24>/Lookup_Temp_SoP_chg'
   */
  { 45.0, 48.0, 49.0, 50.0, 51.0 },

  /* Expression: 1
   * Referenced by: '<S3>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Saturation1'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S22>/A//Nm'
   */
  0.2,

  /* Expression: 0.2
   * Referenced by: '<S23>/A//Nm'
   */
  0.2,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S41>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S40>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S54>/ct'
   */
  1.0,

  /* Expression: 0.905
   * Referenced by: '<S54>/exp(-tcycle//tau)1'
   */
  0.905,

  /* Expression: -1
   * Referenced by: '<S54>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S54>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S54>/Data Store Memory1'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<S121>/rpm'
   */
  200.0,

  /* Expression: 3.141592/30
   * Referenced by: '<S121>/Gain'
   */
  0.10471973333333334,

  /* Expression: 0
   * Referenced by: '<S121>/Constant'
   */
  0.0,

  /* Computed Parameter: Out_Throttle_Y0
   * Referenced by: '<S131>/Out_Throttle'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S162>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S162>/Switch1'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<S162>/Switch'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S161>/Switch1'
   */
  0.0,

  /* Computed Parameter: SKF_act_Y0
   * Referenced by: '<S156>/SKF_act'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S156>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S156>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S156>/Saturation'
   */
  0.3,

  /* Expression: 1
   * Referenced by: '<S158>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S158>/Switch1'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<S158>/Switch'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S157>/Switch1'
   */
  0.0,

  /* Computed Parameter: CKF_act_Y0
   * Referenced by: '<S154>/CKF_act '
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_j
   * Referenced by: '<S154>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S154>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S154>/Saturation'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S115>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S115>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S115>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S115>/Constant3'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S115>/Constant4'
   */
  -1.0,

  /* Expression: 1/9.81
   * Referenced by: '<S115>/Gain'
   */
  0.1019367991845056,

  /* Expression: 0
   * Referenced by: '<S115>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S115>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S114>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S114>/Constant2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S114>/Constant3'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S114>/Constant4'
   */
  -1.0,

  /* Expression: 3.72
   * Referenced by: '<S142>/Steering_Ratio [-]'
   */
  3.72,

  /* Expression: 0
   * Referenced by: '<S114>/Integrator'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S142>/Constant8'
   */
  360.0,

  /* Expression: 0.92
   * Referenced by: '<S142>/Constant7'
   */
  0.92,

  /* Expression: 1.53
   * Referenced by: '<S142>/Wheelbase [m]'
   */
  1.53,

  /* Expression: -700
   * Referenced by: '<S142>/Cornering_Stiffness_F[N//º]'
   */
  -700.0,

  /* Expression: 360/(2*pi)
   * Referenced by: '<S142>/360//(2*pi)'
   */
  57.295779513082323,

  /* Expression: -1000
   * Referenced by: '<S142>/Cornering_Stiffness_R[N//º]'
   */
  -1000.0,

  /* Expression: 360/(2*pi)
   * Referenced by: '<S142>/360//(2pi)'
   */
  57.295779513082323,

  /* Expression: 43.21
   * Referenced by: '<S114>/Yaw_Inertia [kg//m^3]'
   */
  43.21,

  /* Expression: 1.15
   * Referenced by: '<S114>/Rear_Trackwidth [m] '
   */
  1.15,

  /* Expression: 2
   * Referenced by: '<S144>/Constant'
   */
  2.0,

  /* Expression: 1/9.81
   * Referenced by: '<S114>/Gravity'
   */
  0.1019367991845056,

  /* Expression: 1/2
   * Referenced by: '<S114>/Fy per wheel'
   */
  0.5,

  /* Expression: 1/9.81
   * Referenced by: '<S114>/Gravity1'
   */
  0.1019367991845056,

  /* Expression: 1
   * Referenced by: '<S114>/Constant6'
   */
  1.0,

  /* Computed Parameter: MaxTq_RRNm0inf_Y0
   * Referenced by: '<S78>/MaxTq_RR [Nm] (0,inf)'
   */
  0.0,

  /* Computed Parameter: MaxTq_RLNm0inf_Y0
   * Referenced by: '<S78>/MaxTq_RL [Nm] (0,inf)'
   */
  0.0,

  /* Computed Parameter: Flags_num5_Y0
   * Referenced by: '<S78>/Flags_[num5]'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S153>/Steering Wheel Maximum Angle'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S118>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S118>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S78>/Constant'
   */
  0.0,

  /* Expression: 1/4
   * Referenced by: '<S113>/To motor Tq (RT)'
   */
  0.25,

  /* Expression: 120
   * Referenced by: '<S113>/Maximum Torque per engine [Nm]'
   */
  120.0,

  /* Expression: 140
   * Referenced by: '<S113>/Maximum Transmission Torque Dynamic [Nm]'
   */
  140.0,

  /* Expression: 130
   * Referenced by: '<S113>/Maximum Transmission Torque Static [Nm]'
   */
  130.0,

  /* Expression: 0
   * Referenced by: '<S120>/Constant1'
   */
  0.0,

  /* Expression: 0.025
   * Referenced by: '<S113>/Constant1'
   */
  0.025,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S78>/Merge2'
   */
  0.0,

  /* Expression: 18
   * Referenced by: '<S113>/Effective Rolling Diameter[inch]'
   */
  18.0,

  /* Expression: 1/2
   * Referenced by: '<S113>/Diameter to Radius'
   */
  0.5,

  /* Expression: 0.0254
   * Referenced by: '<S113>/inch to m1'
   */
  0.0254,

  /* Expression: 0.97
   * Referenced by: '<S113>/3% difference1'
   */
  0.97,

  /* Expression: 4
   * Referenced by: '<S113>/Transmision Ratio[-]'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S120>/Constant'
   */
  0.0,

  /* Computed Parameter: Merge3_InitialOutput
   * Referenced by: '<S78>/Merge3'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S113>/Tq_diff_Max'
   */
  100.0,

  /* Computed Parameter: Merge_InitialOutput_i
   * Referenced by: '<S111>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S111>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge4_InitialOutput
   * Referenced by: '<S78>/Merge4'
   */
  0.0,

  /* Computed Parameter: Merge5_InitialOutput
   * Referenced by: '<S78>/Merge5'
   */
  0.0,

  /* Computed Parameter: Merge6_InitialOutput
   * Referenced by: '<S78>/Merge6'
   */
  0.0,

  /* Computed Parameter: Merge7_InitialOutput
   * Referenced by: '<S78>/Merge7'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<S177>/rpm'
   */
  200.0,

  /* Expression: 3.141592/30
   * Referenced by: '<S177>/Gain'
   */
  0.10471973333333334,

  /* Computed Parameter: Out_Throttle_Y0_a
   * Referenced by: '<S186>/Out_Throttle'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S203>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S203>/Switch1'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<S203>/Switch'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S202>/Switch1'
   */
  0.0,

  /* Computed Parameter: MaxTq_RRNm0inf_Y0_o
   * Referenced by: '<S79>/MaxTq_RR [Nm] (0,inf)'
   */
  0.0,

  /* Computed Parameter: MaxTq_RLNm0inf_Y0_d
   * Referenced by: '<S79>/MaxTq_RL [Nm] (0,inf)'
   */
  0.0,

  /* Computed Parameter: MaxFx_RRN0inf_Y0
   * Referenced by: '<S79>/MaxFx_RR [N] (0,inf)'
   */
  0.0,

  /* Computed Parameter: MaxFx_RLN0inf_Y0
   * Referenced by: '<S79>/MaxFx_RL [N] (0,inf)'
   */
  0.0,

  /* Computed Parameter: Fy_RN0inf_Y0
   * Referenced by: '<S79>/Fy_R [N] (0,inf)'
   */
  0.0,

  /* Computed Parameter: Masskg0inf_Y0
   * Referenced by: '<S79>/Mass [kg] (0,inf)'
   */
  0.0,

  /* Computed Parameter: Handlinginfinf_Y0
   * Referenced by: '<S79>/Handling [-] (-inf,inf)'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_h
   * Referenced by: '<S201>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S201>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S201>/Saturation'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S175>/Data Store Memory1'
   */
  0.0,

  /* Expression: 4
   * Referenced by: '<S172>/Transmision Ratio[-]'
   */
  4.0,

  /* Expression: 120
   * Referenced by: '<S172>/Maximum Torque per motor [Nm]'
   */
  120.0,

  /* Expression: 140
   * Referenced by: '<S172>/Maximum Transmission Torque Dynamic [Nm]'
   */
  140.0,

  /* Expression: 130
   * Referenced by: '<S172>/Maximum Transmission Torque Static [Nm]'
   */
  130.0,

  /* Expression: 0
   * Referenced by: '<S171>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S173>/Constant1'
   */
  -1.0,

  /* Expression: 1/9.81
   * Referenced by: '<S174>/Gravity1'
   */
  0.1019367991845056,

  /* Expression: 1/2
   * Referenced by: '<S174>/Fy per wheel'
   */
  0.5,

  /* Expression: 18
   * Referenced by: '<S172>/Effective Rolling Diameter[inch]'
   */
  18.0,

  /* Expression: 1/2
   * Referenced by: '<S172>/Diameter to Radius'
   */
  0.5,

  /* Expression: 0.0254
   * Referenced by: '<S172>/inch to m'
   */
  0.0254,

  /* Expression: 0.97
   * Referenced by: '<S172>/3% difference'
   */
  0.97,

  /* Expression: 0
   * Referenced by: '<S171>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S173>/Constant'
   */
  -1.0,

  /* Computed Parameter: Merge_InitialOutput_l
   * Referenced by: '<S170>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput_k
   * Referenced by: '<S170>/Merge1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S94>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S94>/Gain1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S107>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S107>/Switch1'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<S107>/Switch'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S106>/Switch'
   */
  0.0,

  /* Computed Parameter: SKF_act_Y0_l
   * Referenced by: '<S101>/SKF_act'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_p
   * Referenced by: '<S101>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S101>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S101>/Saturation'
   */
  0.3,

  /* Expression: 1
   * Referenced by: '<S103>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S103>/Switch1'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<S103>/Switch'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S102>/Switch'
   */
  0.0,

  /* Computed Parameter: CKF_act_Y0_j
   * Referenced by: '<S99>/CKF_act '
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_a
   * Referenced by: '<S99>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S99>/Saturation'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S99>/Saturation'
   */
  0.3,

  /* Expression: 100
   * Referenced by: '<S98>/Steering Wheel Maximum Angle'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S88>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S88>/Data Store Memory1'
   */
  0.0,

  /* Expression: 140
   * Referenced by: '<S77>/Steering Wheel Maximum Angle'
   */
  140.0,

  /* Expression: 120
   * Referenced by: '<S77>/Tq_max_motor [Nm]'
   */
  120.0,

  /* Expression: 100
   * Referenced by: '<S77>/Tq_diff_max [Nm]'
   */
  100.0,

  /* Expression: 4
   * Referenced by: '<S77>/Transmission Ratio'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S77>/Transmission Ratio1'
   */
  4.0,

  /* Computed Parameter: Merge_InitialOutput_e
   * Referenced by: '<S82>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput_e
   * Referenced by: '<S82>/Merge1'
   */
  0.0,

  /* Expression: 60
   * Referenced by: '<S76>/Torque_RL [Nm]'
   */
  60.0,

  /* Expression: 4
   * Referenced by: '<S76>/RT_L'
   */
  4.0,

  /* Expression: 60
   * Referenced by: '<S76>/Torque_RR [Nm]'
   */
  60.0,

  /* Expression: 4
   * Referenced by: '<S76>/RT_R'
   */
  4.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S74>/Out1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S67>/Constant'
   */
  5.0,

  /* Expression: -1
   * Referenced by: '<S67>/Gain'
   */
  -1.0,

  /* Expression: 10
   * Referenced by: '<S67>/Steering Wheel Saturation (per site) [deg] '
   */
  10.0,

  /* Computed Parameter: MergeTq_RL_InitialOutput
   * Referenced by: '<S67>/Merge Tq_RL'
   */
  0.0,

  /* Computed Parameter: MergeTq_RR_InitialOutput
   * Referenced by: '<S67>/Merge Tq_RR'
   */
  0.0,

  /* Computed Parameter: Merge2_InitialOutput_o
   * Referenced by: '<S67>/Merge2'
   */
  0.0,

  /* Computed Parameter: Merge3_InitialOutput_n
   * Referenced by: '<S67>/Merge3'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S65>/Constant'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S65>/Enabled'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S65>/Zero '
   */
  0.0,

  /* Expression: 800
   * Referenced by: '<S72>/Constant'
   */
  800.0,

  /* Expression: 800
   * Referenced by: '<S72>/Constant1'
   */
  800.0,

  /* Expression: 800
   * Referenced by: '<S72>/Constant2'
   */
  800.0,

  /* Expression: 800
   * Referenced by: '<S72>/Constant3'
   */
  800.0,

  /* Expression: 15
   * Referenced by: '<S207>/Constant'
   */
  15.0,

  /* Expression: 10
   * Referenced by: '<S207>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S207>/Saturation'
   */
  -10.0,

  /* Expression: 10
   * Referenced by: '<S207>/Saturation1'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S207>/Saturation1'
   */
  -10.0,

  /* Expression: 580
   * Referenced by: '<S68>/Saturation'
   */
  580.0,

  /* Expression: -580
   * Referenced by: '<S68>/Saturation'
   */
  -580.0,

  /* Expression: 580
   * Referenced by: '<S68>/Saturation1'
   */
  580.0,

  /* Expression: -580
   * Referenced by: '<S68>/Saturation1'
   */
  -580.0,

  /* Expression: 3
   * Referenced by: '<Root>/Constant14'
   */
  3.0,

  /* Expression: 570
   * Referenced by: '<S13>/zero'
   */
  570.0,

  /* Expression: 2
   * Referenced by: '<S13>/half range'
   */
  2.0,

  /* Expression: 1000
   * Referenced by: '<S13>/range'
   */
  1000.0,

  /* Expression: 115
   * Referenced by: '<S13>/Gain'
   */
  115.0,

  /* Expression: 4
   * Referenced by: '<Root>/Transmission Gear Ratio'
   */
  4.0,

  /* Expression: 100
   * Referenced by: '<S14>/Gain1'
   */
  100.0,

  /* Expression: 1/4
   * Referenced by: '<Root>/Gain1'
   */
  0.25,

  /* Expression: 1/4
   * Referenced by: '<Root>/Gain'
   */
  0.25,

  /* Expression: 50
   * Referenced by: '<Root>/Constant17'
   */
  50.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant13'
   */
  50.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant'
   */
  50.0,

  /* Expression: 1/100
   * Referenced by: '<S208>/Gain6'
   */
  0.01,

  /* Expression: [0.4 0.6 0.8 0.95 1 1 0.98 0.95]
   * Referenced by: '<S208>/Lookup_SoC_SoP_dischg'
   */
  { 0.4, 0.6, 0.8, 0.95, 1.0, 1.0, 0.98, 0.95 },

  /* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.9 1]
   * Referenced by: '<S208>/Lookup_SoC_SoP_dischg'
   */
  { 0.02, 0.1, 0.2, 0.3, 0.5, 0.8, 0.9, 1.0 },

  /* Expression: 45
   * Referenced by: '<S213>/Constant1'
   */
  45.0,

  /* Expression: 5
   * Referenced by: '<S213>/Constant2'
   */
  5.0,

  /* Expression: 0.4
   * Referenced by: '<S16>/initial_limitation'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<S213>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S213>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S213>/Saturation1'
   */
  0.0,

  /* Expression: 45
   * Referenced by: '<S214>/Constant1'
   */
  45.0,

  /* Expression: 5
   * Referenced by: '<S214>/Constant2'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<S214>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S214>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S214>/Saturation1'
   */
  0.0,

  /* Expression: 105
   * Referenced by: '<S215>/Constant1'
   */
  105.0,

  /* Expression: 5
   * Referenced by: '<S215>/Constant2'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<S215>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S215>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S215>/Saturation1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S16>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S16>/Saturation'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant12'
   */
  50.0,

  /* Expression: 1/100
   * Referenced by: '<S208>/Gain5'
   */
  0.01,

  /* Expression: [0.95 1 1 1 1 0.9 0.75 0.02]
   * Referenced by: '<S208>/Lookup_SoC_SoP_chg'
   */
  { 0.95, 1.0, 1.0, 1.0, 1.0, 0.9, 0.75, 0.02 },

  /* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.95 1]
   * Referenced by: '<S208>/Lookup_SoC_SoP_chg'
   */
  { 0.02, 0.1, 0.2, 0.3, 0.5, 0.8, 0.95, 1.0 },

  /* Expression: [1 0.75 0.5 0 0]
   * Referenced by: '<S208>/Lookup_Temp_SoP_chg'
   */
  { 1.0, 0.75, 0.5, 0.0, 0.0 },

  /* Expression: [45 48 49 50 51]
   * Referenced by: '<S208>/Lookup_Temp_SoP_chg'
   */
  { 45.0, 48.0, 49.0, 50.0, 51.0 },

  /* Expression: 1
   * Referenced by: '<S16>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S16>/Saturation1'
   */
  0.0,

  /* Expression: 4
   * Referenced by: '<Root>/Gear Ratio'
   */
  4.0,

  /* Expression: 120
   * Referenced by: '<Root>/Max Tq per motor [Nm]'
   */
  120.0,

  /* Expression: 80
   * Referenced by: '<S9>/Max_Power_discharge [kW]'
   */
  80.0,

  /* Expression: 60
   * Referenced by: '<S9>/Max_Power_charge [kW]'
   */
  60.0,

  /* Computed Parameter: Accu_Temperature_Limitation_Fla
   * Referenced by: '<S3>/Accu_Temperature_Limitation_Flag'
   */
  0,

  /* Computed Parameter: Inverters_Temperature_Limitatio
   * Referenced by: '<S3>/Inverters_Temperature_Limitation_Flag'
   */
  0,

  /* Computed Parameter: Motors_Temperature_Limitation_F
   * Referenced by: '<S3>/Motors_Temperature_Limitation_Flag'
   */
  0,

  /* Computed Parameter: DataStoreMemory1_InitialValu_fl
   * Referenced by: '<S43>/Data Store Memory1'
   */
  0,

  /* Start of '<S82>/Inertia Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S92>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S92>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S82>/Inertia Braking' */

  /* Start of '<S82>/Mech_Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S93>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S93>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S82>/Mech_Braking' */

  /* Start of '<S170>/Inertia Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S187>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S187>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S170>/Inertia Braking' */

  /* Start of '<S170>/Mech_Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S188>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S188>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S170>/Mech_Braking' */

  /* Start of '<S169>/Braking with Regenerative' */
  {
    /* Expression: -1
     * Referenced by: '<S178>/Gain'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S178>/Gain1'
     */
    -1.0
  }
  ,

  /* End of '<S169>/Braking with Regenerative' */

  /* Start of '<S111>/Inertia Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S133>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S133>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S111>/Inertia Braking' */

  /* Start of '<S111>/Mech_Braking' */
  {
    /* Expression: 0
     * Referenced by: '<S134>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S134>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S111>/Mech_Braking' */

  /* Start of '<S110>/Braking with Regenerative' */
  {
    /* Expression: -1
     * Referenced by: '<S122>/Gain'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S122>/Gain1'
     */
    -1.0
  }
  ,

  /* End of '<S110>/Braking with Regenerative' */

  /* Start of '<S43>/Not Imp Memo1' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S52>/Constant'
     */
    1
  }
  ,

  /* End of '<S43>/Not Imp Memo1' */

  /* Start of '<S43>/Imp Memo1' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S50>/Constant'
     */
    0
  }
  ,

  /* End of '<S43>/Imp Memo1' */

  /* Start of '<S43>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S49>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S43>/If Action Subsystem3' */

  /* Start of '<S43>/If Action Subsystem2' */
  {
    /* Expression: 1
     * Referenced by: '<S48>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S43>/If Action Subsystem2' */

  /* Start of '<S43>/Not Imp1' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S53>/Constant'
     */
    1
  }
  ,

  /* End of '<S43>/Not Imp1' */

  /* Start of '<S43>/Imp1' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S51>/Constant'
     */
    0
  }
  ,

  /* End of '<S43>/Imp1' */

  /* Start of '<S42>/Not Imp' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S47>/Constant'
     */
    1
  }
  ,

  /* End of '<S42>/Not Imp' */

  /* Start of '<S42>/Imp' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S46>/Constant'
     */
    0
  }
  ,

  /* End of '<S42>/Imp' */

  /* Start of '<S19>/OK' */
  {
    /* Expression: 0
     * Referenced by: '<S21>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S19>/OK' */

  /* Start of '<S19>/Latched Error' */
  {
    /* Expression: 1
     * Referenced by: '<S20>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S19>/Latched Error' */

  /* Start of '<S17>/LimitReached' */
  {
    /* Expression: 1
     * Referenced by: '<S18>/Constant'
     */
    1.0
  }
  /* End of '<S17>/LimitReached' */
};
