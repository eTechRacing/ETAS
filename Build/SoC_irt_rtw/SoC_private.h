/*
 * SoC_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 13.0
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Apr 10 15:35:56 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SoC_private_h_
#define RTW_HEADER_SoC_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "SoC.h"
#include "SoC_types.h"

extern const real_T rtCP_pooled_uSMstfL7HqJ8[5];
extern const real_T rtCP_pooled_APSB2csM7gij[4];
extern const real_T rtCP_pooled_zeQjGgJAQ7eV[5];
extern const real_T rtCP_pooled_EdsT8Tjv7lqP[26];
extern const real_T rtCP_pooled_pnOlrjzZzxZ2[26];
extern const real_T rtCP_pooled_eGbGXldrMtNl[26];
extern const real_T rtCP_pooled_r7AaOepUOeVE[26];
extern const real_T rtCP_pooled_hR2h2voUnDxS[26];
extern const real_T rtCP_pooled_3QeDdWtAFELL[26];
extern const real_T rtCP_pooled_tT86VTMf2jBZ[26];
extern const real_T rtCP_pooled_m98KDp8d47S6[26];
extern const real_T rtCP_pooled_8oebaMKQEEf3[25];
extern const real_T rtCP_pooled_LIqzArrgGjnH[26];
extern const real_T rtCP_pooled_AOZKK8H4A7cg[26];
extern const real_T rtCP_pooled_h4JrfJfJVj21[26];
extern const real_T rtCP_pooled_p2mHo2nMnYmN[26];
extern const real_T rtCP_pooled_gQzxlYtQcuvQ[26];
extern const real_T rtCP_pooled_cUwhCMO9gSLX[4];
extern const real_T rtCP_pooled_amELkqglNv3q[26];
extern const real_T rtCP_pooled_g3ZH6wLdBrI2[26];
extern const real_T rtCP_pooled_hQWAy4uJ4xaH[26];
extern const real_T rtCP_pooled_os6pSZgArQ0S[26];
extern const real_T rtCP_pooled_LRnB1sHbUayW[26];
extern const real_T rtCP_pooled_bFeUxFDZCwO1[26];

#define rtCP_updatePy_Wc               rtCP_pooled_uSMstfL7HqJ8  /* Expression: Wc
                                                                  * Referenced by: '<S14>/updatePy'
                                                                  */
#define rtCP_updatePx_Q                rtCP_pooled_APSB2csM7gij  /* Expression: Q
                                                                  * Referenced by: '<S14>/updatePx'
                                                                  */
#define rtCP_updatePx_Wc               rtCP_pooled_uSMstfL7HqJ8  /* Expression: Wc
                                                                  * Referenced by: '<S14>/updatePx'
                                                                  */
#define rtCP_Constant_Value_n          rtCP_pooled_zeQjGgJAQ7eV  /* Expression: Wm
                                                                  * Referenced by: '<S20>/Constant'
                                                                  */
#define rtCP_R1_tableData              rtCP_pooled_EdsT8Tjv7lqP  /* Expression: R1_mat
                                                                  * Referenced by: '<S26>/R1'
                                                                  */
#define rtCP_R1_bp01Data               rtCP_pooled_pnOlrjzZzxZ2  /* Expression: SOC_vec
                                                                  * Referenced by: '<S26>/R1'
                                                                  */
#define rtCP_C1_tableData              rtCP_pooled_eGbGXldrMtNl  /* Expression: C1_mat
                                                                  * Referenced by: '<S26>/C1'
                                                                  */
#define rtCP_C1_bp01Data               rtCP_pooled_r7AaOepUOeVE  /* Expression: SOC_vec
                                                                  * Referenced by: '<S26>/C1'
                                                                  */
#define rtCP_Constant_Value_i          rtCP_pooled_zeQjGgJAQ7eV  /* Expression: Wm
                                                                  * Referenced by: '<S19>/Constant'
                                                                  */
#define rtCP_OCVTable_tableData        rtCP_pooled_hR2h2voUnDxS  /* Expression: V0_mat
                                                                  * Referenced by: '<S24>/OCV Table'
                                                                  */
#define rtCP_OCVTable_bp01Data         rtCP_pooled_3QeDdWtAFELL  /* Expression: SOC_vec
                                                                  * Referenced by: '<S24>/OCV Table'
                                                                  */
#define rtCP_R0Table_tableData         rtCP_pooled_tT86VTMf2jBZ  /* Expression: R0_mat
                                                                  * Referenced by: '<S24>/R0 Table'
                                                                  */
#define rtCP_R0Table_bp01Data          rtCP_pooled_m98KDp8d47S6  /* Expression: SOC_vec
                                                                  * Referenced by: '<S24>/R0 Table'
                                                                  */
#define rtCP_Constant_Value_f          rtCP_pooled_8oebaMKQEEf3  /* Expression: diag(Wc)
                                                                  * Referenced by: '<S14>/Constant'
                                                                  */
#define rtCP_OCVtoSoC_tableData        rtCP_pooled_LIqzArrgGjnH  /* Expression: [0.00364887820512694
                                                                    0.0406322115384605
                                                                    0.0806891025641018
                                                                    0.120744391025641
                                                                    0.160802083333333
                                                                    0.200854967948718
                                                                    0.240911057692307
                                                                    0.280964743589743
                                                                    0.321025641025641
                                                                    0.361079326923077
                                                                    0.401137019230769
                                                                    0.441193910256410
                                                                    0.481247596153846
                                                                    0.521301282051282
                                                                    0.561357371794872
                                                                    0.601413461538462
                                                                    0.641456730769231
                                                                    0.681509615384616
                                                                    0.721566506410257
                                                                    0.761620993589744
                                                                    0.801677884615385
                                                                    0.841734775641026
                                                                    0.881788461538462
                                                                    0.921837339743590
                                                                    0.961899038461539
                                                                    0.998685256410256]
                                                                  * Referenced by: '<S2>/OCV to SoC'
                                                                  */
#define rtCP_OCVtoSoC_bp01Data         rtCP_pooled_AOZKK8H4A7cg  /* Expression: [2.94959022892031
                                                                    3.21416977318498
                                                                    3.34338141328538
                                                                    3.38823547157865
                                                                    3.42107134634789
                                                                    3.48650481123582
                                                                    3.51335866761468
                                                                    3.54070339538832
                                                                    3.56968305677313
                                                                    3.63185877907628
                                                                    3.63255716896237
                                                                    3.64803371545993
                                                                    3.66548496788278
                                                                    3.66563518858557
                                                                    3.72681148156897
                                                                    3.76406010705888
                                                                    3.77075982343748
                                                                    3.84270466053206
                                                                    3.84295206305238
                                                                    3.90164564850831
                                                                    3.96498508551296
                                                                    3.96615700649565
                                                                    4.04797311953080
                                                                    4.07602027520885
                                                                    4.10936207844059
                                                                    4.18278376875771]
                                                                  * Referenced by: '<S2>/OCV to SoC'
                                                                  */
#define rtCP_uDLookupTableR1_tableData rtCP_pooled_h4JrfJfJVj21  /* Expression: R1_mat
                                                                  * Referenced by: '<S37>/2-D Lookup Table R1'
                                                                  */
#define rtCP_uDLookupTableR1_bp01Data  rtCP_pooled_p2mHo2nMnYmN  /* Expression: SOC_vec
                                                                  * Referenced by: '<S37>/2-D Lookup Table R1'
                                                                  */
#define rtCP_uDLookupTableC1_tableData rtCP_pooled_eGbGXldrMtNl  /* Expression: C1_mat
                                                                  * Referenced by: '<S37>/2-D Lookup Table C1'
                                                                  */
#define rtCP_uDLookupTableC1_bp01Data  rtCP_pooled_gQzxlYtQcuvQ  /* Expression: SOC_vec
                                                                  * Referenced by: '<S37>/2-D Lookup Table C1'
                                                                  */
#define rtCP_Constant_Value_a          rtCP_pooled_cUwhCMO9gSLX  /* Expression: Q
                                                                  * Referenced by: '<S38>/Constant'
                                                                  */
#define rtCP_uDLookupTabledV0_tableData rtCP_pooled_amELkqglNv3q /* Expression: dV0_mat
                                                                  * Referenced by: '<S37>/2-D Lookup Table dV0'
                                                                  */
#define rtCP_uDLookupTabledV0_bp01Data rtCP_pooled_g3ZH6wLdBrI2  /* Expression: SOC_vec
                                                                  * Referenced by: '<S37>/2-D Lookup Table dV0'
                                                                  */
#define rtCP_uDLookupTableV0_tableData rtCP_pooled_hQWAy4uJ4xaH  /* Expression: V0_mat
                                                                  * Referenced by: '<S37>/2-D Lookup Table V0'
                                                                  */
#define rtCP_uDLookupTableV0_bp01Data  rtCP_pooled_os6pSZgArQ0S  /* Expression: SOC_vec
                                                                  * Referenced by: '<S37>/2-D Lookup Table V0'
                                                                  */
#define rtCP_uDLookupTableR0_tableData rtCP_pooled_LRnB1sHbUayW  /* Expression: R0_mat
                                                                  * Referenced by: '<S37>/2-D Lookup Table R0'
                                                                  */
#define rtCP_uDLookupTableR0_bp01Data  rtCP_pooled_bFeUxFDZCwO1  /* Expression: SOC_vec
                                                                  * Referenced by: '<S37>/2-D Lookup Table R0'
                                                                  */
#define rtCP_OCVtoSoC_tableData_k      rtCP_pooled_LIqzArrgGjnH  /* Expression: [0.00364887820512694
                                                                    0.0406322115384605
                                                                    0.0806891025641018
                                                                    0.120744391025641
                                                                    0.160802083333333
                                                                    0.200854967948718
                                                                    0.240911057692307
                                                                    0.280964743589743
                                                                    0.321025641025641
                                                                    0.361079326923077
                                                                    0.401137019230769
                                                                    0.441193910256410
                                                                    0.481247596153846
                                                                    0.521301282051282
                                                                    0.561357371794872
                                                                    0.601413461538462
                                                                    0.641456730769231
                                                                    0.681509615384616
                                                                    0.721566506410257
                                                                    0.761620993589744
                                                                    0.801677884615385
                                                                    0.841734775641026
                                                                    0.881788461538462
                                                                    0.921837339743590
                                                                    0.961899038461539
                                                                    0.998685256410256]
                                                                  * Referenced by: '<S3>/OCV to SoC'
                                                                  */
#define rtCP_OCVtoSoC_bp01Data_n       rtCP_pooled_AOZKK8H4A7cg  /* Expression: [2.94959022892031
                                                                    3.21416977318498
                                                                    3.34338141328538
                                                                    3.38823547157865
                                                                    3.42107134634789
                                                                    3.48650481123582
                                                                    3.51335866761468
                                                                    3.54070339538832
                                                                    3.56968305677313
                                                                    3.63185877907628
                                                                    3.63255716896237
                                                                    3.64803371545993
                                                                    3.66548496788278
                                                                    3.66563518858557
                                                                    3.72681148156897
                                                                    3.76406010705888
                                                                    3.77075982343748
                                                                    3.84270466053206
                                                                    3.84295206305238
                                                                    3.90164564850831
                                                                    3.96498508551296
                                                                    3.96615700649565
                                                                    4.04797311953080
                                                                    4.07602027520885
                                                                    4.10936207844059
                                                                    4.18278376875771]
                                                                  * Referenced by: '<S3>/OCV to SoC'
                                                                  */

extern void SOCEstimatorCoulombCountin_Init(int32_T NumIters,
  DW_SOCEstimatorCoulombCountin_T localDW[1]);
extern void SOCEstimatorCoulombCounti_Start(int32_T NumIters,
  B_SOCEstimatorCoulombCounting_T localB[1], DW_SOCEstimatorCoulombCountin_T
  localDW[1]);
extern void SOCEstimatorCoulombCount_Update(int32_T NumIters, RT_MODEL_SoC_T *
  const SoC_M, B_SOCEstimatorCoulombCounting_T localB[1],
  DW_SOCEstimatorCoulombCountin_T localDW[1]);
extern void SoC_SOCEstimatorCoulombCounting(int32_T NumIters, RT_MODEL_SoC_T *
  const SoC_M, const real_T *rtu_Current, const real_T *rtu_InitialSOC, real_T
  *rty_SOC, real_T rtp_AH, B_SOCEstimatorCoulombCounting_T localB[1],
  DW_SOCEstimatorCoulombCountin_T localDW[1]);

#endif                                 /* RTW_HEADER_SoC_private_h_ */
