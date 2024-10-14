/*
 * SoC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 13.20
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Oct 14 16:24:35 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SoC.h"
#include "rtwtypes.h"
#include "SoC_private.h"
#include <string.h>
#include <math.h>
#include "look2_binlxpw.h"
#include "look1_binlxpw.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_SoC_T SoC_B;

/* Block states (default storage) */
DW_SoC_T SoC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_SoC_T SoC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SoC_T SoC_Y;

/* Real-time model */
static RT_MODEL_SoC_T SoC_M_;
RT_MODEL_SoC_T *const SoC_M = &SoC_M_;

/*
 * System initialize for iterator system:
 *    '<Root>/3RC_Cell_H'
 *    '<Root>/3RC_Cell_L'
 */
void SoC_uRC_Cell_H_Init(int32_T NumIters, DW_uRC_Cell_H_SoC_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* InitializeConditions for Delay: '<S21>/Delay' */
    localDW[ForEach_itr].CoreSubsys.icLoad = true;

    /* InitializeConditions for UnitDelay: '<S23>/Unit Delay - P' */
    memcpy(&localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[0],
           &rtCP_UnitDelayP_InitialCondit_a[0], sizeof(real_T) << 4U);
  }
}

/*
 * Start for iterator system:
 *    '<Root>/3RC_Cell_H'
 *    '<Root>/3RC_Cell_L'
 */
void SoC_uRC_Cell_H_Start(int32_T NumIters, B_uRC_Cell_H_SoC_T localB[1],
  DW_uRC_Cell_H_SoC_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Start for SignalConversion generated from: '<S21>/Delay' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[0] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[0] = 0.0;

    /* Start for SignalConversion generated from: '<S21>/Delay' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[1] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[1] = 0.0;

    /* Start for SignalConversion generated from: '<S21>/Delay' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[2] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[2] = 0.0;

    /* Start for SignalConversion generated from: '<S21>/Delay' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[3] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[3] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Divide_DWORK4 = 0.0;
    memset(&localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[0], 0, sizeof
           (real_T) << 4U);

    /* Start for Product: '<S23>/Product8' */
    memset(&localB[ForEach_itr].CoreSubsys.Product8[0], 0, sizeof(real_T) << 4U);

    /* Start for Sum: '<S23>/Sum' */
    localB[ForEach_itr].CoreSubsys.Sum[0] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum[1] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum[2] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum[3] = 0.0;

    /* Start for Probe: '<S25>/Probe' */
    localB[ForEach_itr].CoreSubsys.Probe[0] = 0.025;
    localB[ForEach_itr].CoreSubsys.Probe[1] = 0.0;
  }
}

/*
 * Outputs for iterator system:
 *    '<Root>/3RC_Cell_H'
 *    '<Root>/3RC_Cell_L'
 */
void SoC_uRC_Cell_H(int32_T NumIters, const real_T *rtu_Current, const real_T
                    *rtu_CellVoltage, const real_T *rtu_CellTemperature, const
                    real_T *rtu_InitialSOC, real_T *rty_SOC, B_uRC_Cell_H_SoC_T
                    localB[1], DW_uRC_Cell_H_SoC_T localDW[1])
{
  /* local block i/o variables */
  real_T rtb_Delay_o[4];

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_Assignment_o[16];
  real_T rtb_Sum3_j[16];
  real_T tmp[16];
  real_T rtb_Kk1_l[4];
  real_T rtb_Transpose1_j[4];
  real_T rtb_Abs;
  real_T rtb_Assignment_h;
  real_T rtb_Assignment_h_0;
  real_T rtb_Assignment_h_1;
  real_T rtb_ImpSel_InsertedFor_CellVo_h;
  real_T rtb_Kk1_p;
  real_T rtb_Product6_i;
  real_T rtb_Sum2_m;
  real_T rtb_Sum3_m;
  real_T rtb_Sum_kl;
  real_T rtb_Transpose1_j_0;
  real_T rtb_tau_as;
  real_T rtb_tau_gh;
  int32_T i;
  int32_T i_0;
  int32_T rtb_Sum3_m_tmp;
  int32_T rtb_Sum3_m_tmp_0;

  /* Outputs for Iterator SubSystem: '<Root>/3RC_Cell_H' incorporates:
   *  ForEach: '<S2>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* ForEachSliceSelector generated from: '<S2>/CellVoltage' */
    rtb_ImpSel_InsertedFor_CellVo_h = rtu_CellVoltage[ForEach_itr];

    /* Abs: '<S2>/Abs' */
    rtb_Abs = fabs(rtu_Current[ForEach_itr]);

    /* SignalConversion generated from: '<S21>/Delay' incorporates:
     *  Constant: '<S21>/Constant1'
     *  Gain: '<S2>/Gain1'
     */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[0] = 0.01 *
      rtu_InitialSOC[ForEach_itr];
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[1] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[2] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[3] = 0.0;

    /* Delay: '<S21>/Delay' */
    if (localDW[ForEach_itr].CoreSubsys.icLoad) {
      localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[0] = localB[ForEach_itr].
        CoreSubsys.TmpSignalConversionAtDelayInpor[0];
      localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[1] = 0.0;
      localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[2] = 0.0;
      localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[3] = 0.0;
    }

    /* Delay: '<S21>/Delay' */
    rtb_Delay_o[0] = localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[0];
    rtb_Delay_o[1] = localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[1];
    rtb_Delay_o[2] = localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[2];
    rtb_Delay_o[3] = localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[3];

    /* Lookup_n-D: '<S22>/2-D Lookup Table OCV' */
    rtb_Sum_kl = look2_binlxpw(rtb_Delay_o[0], rtu_CellTemperature[ForEach_itr],
      rtCP_uDLookupTableOCV_bp01Data_, rtCP_uDLookupTableOCV_bp02Data_,
      rtCP_uDLookupTableOCV_tableDa_e, rtCP_uDLookupTableOCV_maxIndex_, 21U);

    /* Sum: '<S22>/Sum2' incorporates:
     *  Lookup_n-D: '<S22>/2-D Lookup Table R0'
     *  Product: '<S22>/Product6'
     *  Sum: '<S22>/Sum of Elements'
     */
    rtb_Sum_kl = (rtb_Sum_kl - look2_binlxpw(rtb_Delay_o[0],
      rtu_CellTemperature[ForEach_itr], rtCP_uDLookupTableR0_bp01Data_o,
      rtCP_uDLookupTableR0_bp02Data_f, rtCP_uDLookupTableR0_tableData_,
      rtCP_uDLookupTableR0_maxIndex_j, 21U) * rtb_Abs) - ((rtb_Delay_o[1] +
      rtb_Delay_o[2]) + rtb_Delay_o[3]);

    /* SignalConversion generated from: '<S28>/Assignment' incorporates:
     *  Assignment: '<S30>/Assignment'
     *  Constant: '<S22>/Constant'
     */
    memcpy(&rtb_Assignment_o[0], &rtCP_Constant_Value_o[0], sizeof(real_T) << 4U);

    /* Lookup_n-D: '<S28>/Lookup R1' */
    rtb_Product6_i = look2_binlxpw(rtb_Delay_o[0],
      rtu_CellTemperature[ForEach_itr], rtCP_LookupR1_bp01Data_l,
      rtCP_LookupR1_bp02Data_c, rtCP_LookupR1_tableData_p,
      rtCP_LookupR1_maxIndex_e, 21U);

    /* Math: '<S28>/Exp' incorporates:
     *  Gain: '<S25>/-Ts'
     *  Lookup_n-D: '<S28>/Lookup C1'
     *  Product: '<S28>/Divide'
     *  Product: '<S28>/Product'
     *
     * About '<S28>/Exp':
     *  Operator: exp
     */
    rtb_Sum2_m = exp(-localB[ForEach_itr].CoreSubsys.Probe[0] / (rtb_Product6_i *
      look2_binlxpw(rtb_Delay_o[0], rtu_CellTemperature[ForEach_itr],
                    rtCP_LookupC1_bp01Data_o, rtCP_LookupC1_bp02Data_o,
                    rtCP_LookupC1_tableData_h, rtCP_LookupC1_maxIndex_h, 21U)));

    /* Assignment: '<S28>/Assignment' incorporates:
     *  Assignment: '<S30>/Assignment'
     */
    rtb_Assignment_o[5] = rtb_Sum2_m;

    /* Product: '<S28>/Product1' incorporates:
     *  Constant: '<S28>/Constant1'
     *  Sum: '<S28>/Sum'
     */
    rtb_tau_as = (1.0 - rtb_Sum2_m) * rtb_Product6_i;

    /* Lookup_n-D: '<S29>/Lookup R2' */
    rtb_Sum2_m = look2_binlxpw(rtb_Delay_o[0], rtu_CellTemperature[ForEach_itr],
      rtCP_LookupR2_bp01Data_o, rtCP_LookupR2_bp02Data_j,
      rtCP_LookupR2_tableData_g, rtCP_LookupR2_maxIndex_a, 21U);

    /* Math: '<S29>/Exp' incorporates:
     *  Gain: '<S25>/-Ts'
     *  Lookup_n-D: '<S29>/Lookup C2'
     *  Product: '<S29>/Divide'
     *  Product: '<S29>/Product'
     *
     * About '<S29>/Exp':
     *  Operator: exp
     */
    rtb_Product6_i = exp(-localB[ForEach_itr].CoreSubsys.Probe[0] / (rtb_Sum2_m *
      look2_binlxpw(rtb_Delay_o[0], rtu_CellTemperature[ForEach_itr],
                    rtCP_LookupC2_bp01Data_m, rtCP_LookupC2_bp02Data_i,
                    rtCP_LookupC2_tableData_j, rtCP_LookupC2_maxIndex_m, 21U)));

    /* Assignment: '<S29>/Assignment' incorporates:
     *  Assignment: '<S30>/Assignment'
     */
    rtb_Assignment_o[10] = rtb_Product6_i;

    /* Product: '<S29>/Product1' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Sum: '<S29>/Sum'
     */
    rtb_tau_gh = (1.0 - rtb_Product6_i) * rtb_Sum2_m;

    /* Lookup_n-D: '<S30>/Lookup R3' */
    rtb_Sum2_m = look2_binlxpw(rtb_Delay_o[0], rtu_CellTemperature[ForEach_itr],
      rtCP_LookupR3_bp01Data_n, rtCP_LookupR3_bp02Data_b,
      rtCP_LookupR3_tableData_d, rtCP_LookupR3_maxIndex_a, 21U);

    /* Math: '<S30>/Exp' incorporates:
     *  Gain: '<S25>/-Ts'
     *  Lookup_n-D: '<S30>/Lookup C3'
     *  Product: '<S30>/Divide'
     *  Product: '<S30>/Product'
     *
     * About '<S30>/Exp':
     *  Operator: exp
     */
    rtb_Product6_i = exp(-localB[ForEach_itr].CoreSubsys.Probe[0] / (rtb_Sum2_m *
      look2_binlxpw(rtb_Delay_o[0], rtu_CellTemperature[ForEach_itr],
                    rtCP_LookupC3_bp01Data_h, rtCP_LookupC3_bp02Data_k,
                    rtCP_LookupC3_tableData_m, rtCP_LookupC3_maxIndex_p, 21U)));

    /* Assignment: '<S30>/Assignment' */
    rtb_Assignment_o[15] = rtb_Product6_i;

    /* Product: '<S30>/Product1' incorporates:
     *  Constant: '<S30>/Constant1'
     *  Sum: '<S30>/Sum'
     */
    rtb_Sum2_m *= 1.0 - rtb_Product6_i;

    /* SignalConversion generated from: '<S22>/Transpose1' incorporates:
     *  Constant: '<S22>/Constant4'
     *  Lookup_n-D: '<S22>/2-D Lookup Table OCV1'
     */
    rtb_Transpose1_j[0] = look2_binlxpw(rtb_Delay_o[0],
      rtu_CellTemperature[ForEach_itr], rtCP_uDLookupTableOCV1_bp01Da_k,
      rtCP_uDLookupTableOCV1_bp02Da_d, rtCP_uDLookupTableOCV1_tableD_a,
      rtCP_uDLookupTableOCV1_maxInd_m, 21U);
    rtb_Transpose1_j[1] = -1.0;
    rtb_Transpose1_j[2] = -1.0;
    rtb_Transpose1_j[3] = -1.0;

    /* Product: '<S23>/Product7' incorporates:
     *  Assignment: '<S30>/Assignment'
     *  Math: '<S23>/Transpose2'
     *  UnitDelay: '<S23>/Unit Delay - P'
     */
    for (i = 0; i < 4; i++) {
      for (i_0 = 0; i_0 < 4; i_0++) {
        tmp[i + (i_0 << 2)] = ((localDW[ForEach_itr].
          CoreSubsys.UnitDelayP_DSTATE[i + 4] * rtb_Assignment_o[i_0 + 4] +
          localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[i] *
          rtb_Assignment_o[i_0]) + localDW[ForEach_itr].
          CoreSubsys.UnitDelayP_DSTATE[i + 8] * rtb_Assignment_o[i_0 + 8]) +
          localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[i + 12] *
          rtb_Assignment_o[i_0 + 12];
      }
    }

    /* Product: '<S23>/Product4' */
    rtb_Transpose1_j_0 = 0.0;
    for (i = 0; i < 4; i++) {
      /* Sum: '<S23>/Sum3' incorporates:
       *  Assignment: '<S30>/Assignment'
       *  Product: '<S23>/Product7'
       */
      rtb_Product6_i = rtb_Assignment_o[i + 4];
      rtb_Assignment_h = rtb_Assignment_o[i];
      rtb_Assignment_h_0 = rtb_Assignment_o[i + 8];
      rtb_Assignment_h_1 = rtb_Assignment_o[i + 12];

      /* Product: '<S23>/Product4' */
      rtb_Kk1_p = 0.0;
      for (i_0 = 0; i_0 < 4; i_0++) {
        /* Product: '<S23>/Product7' incorporates:
         *  Constant: '<S23>/Constant4'
         *  Sum: '<S23>/Sum3'
         */
        rtb_Sum3_m_tmp = i_0 << 2;

        /* Sum: '<S23>/Sum3' incorporates:
         *  Constant: '<S23>/Constant4'
         *  Product: '<S23>/Product7'
         */
        rtb_Sum3_m_tmp_0 = rtb_Sum3_m_tmp + i;
        rtb_Sum3_m = (((tmp[rtb_Sum3_m_tmp + 1] * rtb_Product6_i +
                        tmp[rtb_Sum3_m_tmp] * rtb_Assignment_h) +
                       tmp[rtb_Sum3_m_tmp + 2] * rtb_Assignment_h_0) +
                      tmp[rtb_Sum3_m_tmp + 3] * rtb_Assignment_h_1) +
          rtCP_Constant4_Value_h[rtb_Sum3_m_tmp_0];
        rtb_Sum3_j[rtb_Sum3_m_tmp_0] = rtb_Sum3_m;

        /* Product: '<S23>/Product4' incorporates:
         *  Math: '<S22>/Transpose1'
         *  Math: '<S23>/Transpose1'
         *  Product: '<S23>/Product'
         */
        rtb_Kk1_p += rtb_Sum3_m * rtb_Transpose1_j[i_0];
      }

      /* Product: '<S23>/Product4' incorporates:
       *  Math: '<S22>/Transpose1'
       */
      rtb_Kk1_l[i] = rtb_Kk1_p;
      rtb_Transpose1_j_0 += rtb_Transpose1_j[i] * rtb_Kk1_p;
    }

    /* Product: '<S23>/Divide' incorporates:
     *  Constant: '<S23>/Constant'
     *  Constant: '<S23>/Constant1'
     *  Product: '<S23>/Product4'
     *  Sum: '<S23>/Sum2'
     */
    rtb_Product6_i = 1.0 / (rtb_Transpose1_j_0 + 0.1);

    /* Product: '<S23>/Product3' incorporates:
     *  Product: '<S23>/Product'
     */
    rtb_Kk1_l[0] *= rtb_Product6_i;
    rtb_Kk1_l[1] *= rtb_Product6_i;
    rtb_Kk1_l[2] *= rtb_Product6_i;
    rtb_Kk1_l[3] *= rtb_Product6_i;

    /* Sum: '<S20>/Sum' */
    rtb_Sum_kl = rtb_ImpSel_InsertedFor_CellVo_h - rtb_Sum_kl;

    /* Product: '<S23>/Product6' incorporates:
     *  Product: '<S23>/Product3'
     */
    rtb_Kk1_p = rtb_Kk1_l[0];
    rtb_Product6_i = rtb_Kk1_l[1];
    rtb_ImpSel_InsertedFor_CellVo_h = rtb_Kk1_l[2];
    rtb_Assignment_h = rtb_Kk1_l[3];

    /* Sum: '<S23>/Sum4' incorporates:
     *  Constant: '<S23>/Constant2'
     *  Math: '<S22>/Transpose1'
     *  Product: '<S23>/Product3'
     *  Product: '<S23>/Product6'
     */
    for (i = 0; i < 4; i++) {
      /* Product: '<S23>/Product6' incorporates:
       *  Math: '<S22>/Transpose1'
       */
      rtb_Transpose1_j_0 = rtb_Transpose1_j[i];
      i_0 = i << 2;
      tmp[i_0] = rtCP_Constant2_Value_e[i_0] - rtb_Kk1_p * rtb_Transpose1_j_0;
      tmp[i_0 + 1] = rtCP_Constant2_Value_e[i_0 + 1] - rtb_Product6_i *
        rtb_Transpose1_j_0;
      tmp[i_0 + 2] = rtCP_Constant2_Value_e[i_0 + 2] -
        rtb_ImpSel_InsertedFor_CellVo_h * rtb_Transpose1_j_0;
      tmp[i_0 + 3] = rtCP_Constant2_Value_e[i_0 + 3] - rtb_Assignment_h *
        rtb_Transpose1_j_0;
    }

    /* End of Sum: '<S23>/Sum4' */

    /* SignalConversion generated from: '<S23>/Product2' incorporates:
     *  Constant: '<S22>/Constant2'
     *  Gain: '<S25>/-Ts'
     *  Lookup_n-D: '<S22>/Capacity'
     *  Product: '<S22>/Product'
     *  Product: '<S22>/Product7'
     *  Product: '<S23>/Product2'
     */
    rtb_Transpose1_j[0] = -localB[ForEach_itr].CoreSubsys.Probe[0] *
      0.00027777777777777778 / look1_binlxpw(rtu_CellTemperature[ForEach_itr],
      rtCP_Capacity_bp01Data_p, rtCP_Capacity_tableData_f, 9U) * rtb_Abs;
    rtb_Transpose1_j[1] = rtb_tau_as * rtb_Abs;
    rtb_Transpose1_j[2] = rtb_tau_gh * rtb_Abs;
    rtb_Transpose1_j[3] = rtb_Sum2_m * rtb_Abs;
    for (i = 0; i < 4; i++) {
      /* Product: '<S23>/Product8' */
      rtb_Abs = tmp[i];
      rtb_Sum2_m = tmp[i + 4];
      rtb_tau_as = tmp[i + 8];
      rtb_tau_gh = tmp[i + 12];

      /* Product: '<S23>/Product1' */
      rtb_Product6_i = 0.0;
      for (i_0 = 0; i_0 < 4; i_0++) {
        /* Product: '<S23>/Product8' incorporates:
         *  Product: '<S23>/Product1'
         *  Sum: '<S23>/Sum3'
         */
        rtb_Sum3_m_tmp = i_0 << 2;
        rtb_Sum3_m_tmp_0 = i + rtb_Sum3_m_tmp;
        localB[ForEach_itr].CoreSubsys.Product8[rtb_Sum3_m_tmp_0] =
          ((rtb_Sum3_j[rtb_Sum3_m_tmp + 1] * rtb_Sum2_m +
            rtb_Sum3_j[rtb_Sum3_m_tmp] * rtb_Abs) + rtb_Sum3_j[rtb_Sum3_m_tmp +
           2] * rtb_tau_as) + rtb_Sum3_j[rtb_Sum3_m_tmp + 3] * rtb_tau_gh;

        /* Product: '<S23>/Product1' incorporates:
         *  Assignment: '<S30>/Assignment'
         */
        rtb_Product6_i += rtb_Assignment_o[rtb_Sum3_m_tmp_0] * rtb_Delay_o[i_0];
      }

      /* Sum: '<S23>/Sum' incorporates:
       *  Product: '<S23>/Product1'
       *  Product: '<S23>/Product3'
       *  Product: '<S23>/Product5'
       *  Sum: '<S23>/Sum1'
       */
      localB[ForEach_itr].CoreSubsys.Sum[i] = rtb_Kk1_l[i] * rtb_Sum_kl +
        (rtb_Product6_i + rtb_Transpose1_j[i]);
    }

    /* ForEachSliceAssignment generated from: '<S2>/SOC' incorporates:
     *  Gain: '<S2>/Gain2'
     */
    rty_SOC[ForEach_itr] = 100.0 * localB[ForEach_itr].CoreSubsys.Sum[0];
  }

  /* End of Outputs for SubSystem: '<Root>/3RC_Cell_H' */
}

/*
 * Update for iterator system:
 *    '<Root>/3RC_Cell_H'
 *    '<Root>/3RC_Cell_L'
 */
void SoC_uRC_Cell_H_Update(int32_T NumIters, B_uRC_Cell_H_SoC_T localB[1],
  DW_uRC_Cell_H_SoC_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Update for Delay: '<S21>/Delay' */
    localDW[ForEach_itr].CoreSubsys.icLoad = false;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[0] = localB[ForEach_itr].
      CoreSubsys.Sum[0];
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[1] = localB[ForEach_itr].
      CoreSubsys.Sum[1];
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[2] = localB[ForEach_itr].
      CoreSubsys.Sum[2];
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[3] = localB[ForEach_itr].
      CoreSubsys.Sum[3];

    /* Update for UnitDelay: '<S23>/Unit Delay - P' incorporates:
     *  Product: '<S23>/Product8'
     */
    memcpy(&localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[0],
           &localB[ForEach_itr].CoreSubsys.Product8[0], sizeof(real_T) << 4U);
  }
}

/* Model output function */
static void SoC_output(void)
{
  /* local block i/o variables */
  real_T rtb_ImpAsg_InsertedFor_SOC_at_i;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_o;
  real_T rtb_Delay[4];

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_Assignment[16];
  real_T rtb_Sum3[16];
  real_T tmp[16];
  real_T rtb_Kk1[4];
  real_T rtb_Transpose1[4];
  real_T rtb_Assignment_0;
  real_T rtb_Assignment_1;
  real_T rtb_Divide_d;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_p;
  real_T rtb_Kk1_0;
  real_T rtb_Saturation;
  real_T rtb_Sum3_0;
  real_T rtb_Sum_g;
  real_T rtb_Transpose1_0;
  real_T rtb_Ts;
  real_T rtb_tau_c;
  real_T rtb_tau_m;
  int32_T i;
  int32_T i_0;
  int32_T rtb_Sum3_tmp;
  int32_T rtb_Sum3_tmp_0;

  /* Lookup_n-D: '<Root>/Cell OCV to SOC 2024 L' incorporates:
   *  Inport: '<Root>/Lowest_CellVoltage'
   */
  SoC_B.CellOCVtoSOC2024L = look1_binlxpw(SoC_U.Lowest_CellVoltage,
    rtCP_CellOCVtoSOC2024L_bp01Data, rtCP_CellOCVtoSOC2024L_tableDat, 599U);

  /* Outputs for Iterator SubSystem: '<Root>/3RC_Cell_L' */
  /* Inport: '<Root>/Accumulator_Current' incorporates:
   *  Inport: '<Root>/Average_CellTemp'
   *  Inport: '<Root>/Lowest_CellVoltage'
   */
  SoC_uRC_Cell_H(1, &SoC_U.Accumulator_Current, &SoC_U.Lowest_CellVoltage,
                 &SoC_U.Average_CellTemp, &SoC_B.CellOCVtoSOC2024L,
                 &rtb_ImpAsg_InsertedFor_SOC_at_i, SoC_B.uRC_Cell_L,
                 SoC_DW.uRC_Cell_L);

  /* End of Outputs for SubSystem: '<Root>/3RC_Cell_L' */

  /* Saturate: '<Root>/Saturation' */
  if (rtb_ImpAsg_InsertedFor_SOC_at_i > 100.0) {
    rtb_Saturation = 100.0;
  } else if (rtb_ImpAsg_InsertedFor_SOC_at_i < 0.0) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = rtb_ImpAsg_InsertedFor_SOC_at_i;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Outport: '<Root>/SoC_KF' */
  SoC_Y.SoC_KF = rtb_Saturation;

  /* Lookup_n-D: '<Root>/Accu OCV to SOC 2024' incorporates:
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  SoC_B.AccuOCVtoSOC2024 = look1_binlxpw(SoC_U.Accumulator_Voltage,
    rtCP_AccuOCVtoSOC2024_bp01Data, rtCP_AccuOCVtoSOC2024_tableData, 599U);

  /* Outputs for Iterator SubSystem: '<Root>/3RCAccu' incorporates:
   *  ForEach: '<S1>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* Abs: '<S1>/Abs' incorporates:
     *  Inport: '<Root>/Accumulator_Current'
     */
    rtb_ImpAsg_InsertedFor_SOC_at_p = fabs(SoC_U.Accumulator_Current);

    /* SignalConversion generated from: '<S5>/Delay' incorporates:
     *  Constant: '<S5>/Constant1'
     *  ForEachSliceSelector generated from: '<S1>/InitialSOC'
     *  Gain: '<S1>/Gain1'
     */
    SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[0] = 0.01 *
      SoC_B.AccuOCVtoSOC2024;
    SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[1] = 0.0;
    SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[2] = 0.0;
    SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[3] = 0.0;

    /* Delay: '<S5>/Delay' */
    if (SoC_DW.CoreSubsys[ForEach_itr].icLoad) {
      SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[0] =
        SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[0];
      SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[2] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[3] = 0.0;
    }

    /* Delay: '<S5>/Delay' */
    rtb_Delay[0] = SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[0];
    rtb_Delay[1] = SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[1];
    rtb_Delay[2] = SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[2];
    rtb_Delay[3] = SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[3];

    /* SignalConversion generated from: '<S12>/Assignment' incorporates:
     *  Assignment: '<S14>/Assignment'
     *  Constant: '<S6>/Constant'
     */
    memcpy(&rtb_Assignment[0], &rtCP_Constant_Value[0], sizeof(real_T) << 4U);

    /* Lookup_n-D: '<S12>/Lookup R1' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     */
    rtb_Sum_g = look2_binlxpw(rtb_Delay[0], SoC_U.Average_CellTemp,
      rtCP_LookupR1_bp01Data, rtCP_LookupR1_bp02Data, rtCP_LookupR1_tableData,
      rtCP_LookupR1_maxIndex, 21U);

    /* Math: '<S12>/Exp' incorporates:
     *  Gain: '<S9>/-Ts'
     *  Inport: '<Root>/Average_CellTemp'
     *  Lookup_n-D: '<S12>/Lookup C1'
     *  Product: '<S12>/Divide'
     *  Product: '<S12>/Product'
     *
     * About '<S12>/Exp':
     *  Operator: exp
     */
    rtb_Divide_d = exp(-SoC_B.CoreSubsys[ForEach_itr].Probe[0] / (rtb_Sum_g *
      look2_binlxpw(rtb_Delay[0], SoC_U.Average_CellTemp, rtCP_LookupC1_bp01Data,
                    rtCP_LookupC1_bp02Data, rtCP_LookupC1_tableData,
                    rtCP_LookupC1_maxIndex, 21U)));

    /* Assignment: '<S12>/Assignment' incorporates:
     *  Assignment: '<S14>/Assignment'
     */
    rtb_Assignment[5] = rtb_Divide_d;

    /* Product: '<S12>/Product1' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Sum: '<S12>/Sum'
     */
    rtb_tau_m = (1.0 - rtb_Divide_d) * rtb_Sum_g;

    /* Lookup_n-D: '<S13>/Lookup R2' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     */
    rtb_Sum_g = look2_binlxpw(rtb_Delay[0], SoC_U.Average_CellTemp,
      rtCP_LookupR2_bp01Data, rtCP_LookupR2_bp02Data, rtCP_LookupR2_tableData,
      rtCP_LookupR2_maxIndex, 21U);

    /* Math: '<S13>/Exp' incorporates:
     *  Gain: '<S9>/-Ts'
     *  Inport: '<Root>/Average_CellTemp'
     *  Lookup_n-D: '<S13>/Lookup C2'
     *  Product: '<S13>/Divide'
     *  Product: '<S13>/Product'
     *
     * About '<S13>/Exp':
     *  Operator: exp
     */
    rtb_Divide_d = exp(-SoC_B.CoreSubsys[ForEach_itr].Probe[0] / (rtb_Sum_g *
      look2_binlxpw(rtb_Delay[0], SoC_U.Average_CellTemp, rtCP_LookupC2_bp01Data,
                    rtCP_LookupC2_bp02Data, rtCP_LookupC2_tableData,
                    rtCP_LookupC2_maxIndex, 21U)));

    /* Assignment: '<S13>/Assignment' incorporates:
     *  Assignment: '<S14>/Assignment'
     */
    rtb_Assignment[10] = rtb_Divide_d;

    /* Product: '<S13>/Product1' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Sum: '<S13>/Sum'
     */
    rtb_tau_c = (1.0 - rtb_Divide_d) * rtb_Sum_g;

    /* Lookup_n-D: '<S14>/Lookup R3' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     */
    rtb_Sum_g = look2_binlxpw(rtb_Delay[0], SoC_U.Average_CellTemp,
      rtCP_LookupR3_bp01Data, rtCP_LookupR3_bp02Data, rtCP_LookupR3_tableData,
      rtCP_LookupR3_maxIndex, 21U);

    /* Math: '<S14>/Exp' incorporates:
     *  Gain: '<S9>/-Ts'
     *  Inport: '<Root>/Average_CellTemp'
     *  Lookup_n-D: '<S14>/Lookup C3'
     *  Product: '<S14>/Divide'
     *  Product: '<S14>/Product'
     *
     * About '<S14>/Exp':
     *  Operator: exp
     */
    rtb_Divide_d = exp(-SoC_B.CoreSubsys[ForEach_itr].Probe[0] / (rtb_Sum_g *
      look2_binlxpw(rtb_Delay[0], SoC_U.Average_CellTemp, rtCP_LookupC3_bp01Data,
                    rtCP_LookupC3_bp02Data, rtCP_LookupC3_tableData,
                    rtCP_LookupC3_maxIndex, 21U)));

    /* Assignment: '<S14>/Assignment' */
    rtb_Assignment[15] = rtb_Divide_d;

    /* Product: '<S14>/Product1' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Sum: '<S14>/Sum'
     */
    rtb_Ts = (1.0 - rtb_Divide_d) * rtb_Sum_g;

    /* SignalConversion generated from: '<S6>/Transpose1' incorporates:
     *  Constant: '<S6>/Constant4'
     *  Inport: '<Root>/Average_CellTemp'
     *  Lookup_n-D: '<S6>/2-D Lookup Table OCV1'
     */
    rtb_Transpose1[0] = look2_binlxpw(rtb_Delay[0], SoC_U.Average_CellTemp,
      rtCP_uDLookupTableOCV1_bp01Data, rtCP_uDLookupTableOCV1_bp02Data,
      rtCP_uDLookupTableOCV1_tableDat, rtCP_uDLookupTableOCV1_maxIndex, 21U);
    rtb_Transpose1[1] = -1.0;
    rtb_Transpose1[2] = -1.0;
    rtb_Transpose1[3] = -1.0;

    /* Product: '<S7>/Product7' incorporates:
     *  Assignment: '<S14>/Assignment'
     *  Math: '<S7>/Transpose2'
     *  UnitDelay: '<S7>/Unit Delay - P'
     */
    for (i = 0; i < 4; i++) {
      for (i_0 = 0; i_0 < 4; i_0++) {
        tmp[i + (i_0 << 2)] = ((SoC_DW.CoreSubsys[ForEach_itr]
          .UnitDelayP_DSTATE[i + 4] * rtb_Assignment[i_0 + 4] +
          SoC_DW.CoreSubsys[ForEach_itr].UnitDelayP_DSTATE[i] *
          rtb_Assignment[i_0]) + SoC_DW.CoreSubsys[ForEach_itr].
          UnitDelayP_DSTATE[i + 8] * rtb_Assignment[i_0 + 8]) +
          SoC_DW.CoreSubsys[ForEach_itr].UnitDelayP_DSTATE[i + 12] *
          rtb_Assignment[i_0 + 12];
      }
    }

    /* Product: '<S7>/Product4' */
    rtb_Transpose1_0 = 0.0;
    for (i = 0; i < 4; i++) {
      /* Sum: '<S7>/Sum3' incorporates:
       *  Assignment: '<S14>/Assignment'
       *  Product: '<S7>/Product7'
       */
      rtb_Divide_d = rtb_Assignment[i + 4];
      rtb_Sum_g = rtb_Assignment[i];
      rtb_Assignment_0 = rtb_Assignment[i + 8];
      rtb_Assignment_1 = rtb_Assignment[i + 12];

      /* Product: '<S7>/Product4' */
      rtb_Kk1_0 = 0.0;
      for (i_0 = 0; i_0 < 4; i_0++) {
        /* Product: '<S7>/Product7' incorporates:
         *  Constant: '<S7>/Constant4'
         *  Sum: '<S7>/Sum3'
         */
        rtb_Sum3_tmp = i_0 << 2;

        /* Sum: '<S7>/Sum3' incorporates:
         *  Constant: '<S7>/Constant4'
         *  Product: '<S7>/Product7'
         */
        rtb_Sum3_tmp_0 = rtb_Sum3_tmp + i;
        rtb_Sum3_0 = (((tmp[rtb_Sum3_tmp + 1] * rtb_Divide_d + tmp[rtb_Sum3_tmp]
                        * rtb_Sum_g) + tmp[rtb_Sum3_tmp + 2] * rtb_Assignment_0)
                      + tmp[rtb_Sum3_tmp + 3] * rtb_Assignment_1) +
          rtCP_Constant4_Value_d[rtb_Sum3_tmp_0];
        rtb_Sum3[rtb_Sum3_tmp_0] = rtb_Sum3_0;

        /* Product: '<S7>/Product4' incorporates:
         *  Math: '<S6>/Transpose1'
         *  Math: '<S7>/Transpose1'
         *  Product: '<S7>/Product'
         */
        rtb_Kk1_0 += rtb_Sum3_0 * rtb_Transpose1[i_0];
      }

      /* Product: '<S7>/Product4' incorporates:
       *  Math: '<S6>/Transpose1'
       */
      rtb_Kk1[i] = rtb_Kk1_0;
      rtb_Transpose1_0 += rtb_Transpose1[i] * rtb_Kk1_0;
    }

    /* Product: '<S7>/Divide' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     *  Product: '<S7>/Product4'
     *  Sum: '<S7>/Sum2'
     */
    rtb_Divide_d = 1.0 / (rtb_Transpose1_0 + 0.1);

    /* Product: '<S7>/Product3' incorporates:
     *  Product: '<S7>/Product'
     */
    rtb_Kk1[0] *= rtb_Divide_d;
    rtb_Kk1[1] *= rtb_Divide_d;
    rtb_Kk1[2] *= rtb_Divide_d;
    rtb_Kk1[3] *= rtb_Divide_d;

    /* Sum: '<S4>/Sum' incorporates:
     *  Inport: '<Root>/Accumulator_Voltage'
     *  Inport: '<Root>/Average_CellTemp'
     *  Lookup_n-D: '<S6>/2-D Lookup Table OCV'
     *  Lookup_n-D: '<S6>/2-D Lookup Table R0'
     *  Product: '<S6>/Product6'
     *  Sum: '<S6>/Sum of Elements'
     *  Sum: '<S6>/Sum2'
     */
    rtb_Sum_g = SoC_U.Accumulator_Voltage - ((look2_binlxpw(rtb_Delay[0],
      SoC_U.Average_CellTemp, rtCP_uDLookupTableOCV_bp01Data,
      rtCP_uDLookupTableOCV_bp02Data, rtCP_uDLookupTableOCV_tableData,
      rtCP_uDLookupTableOCV_maxIndex, 21U) - look2_binlxpw(rtb_Delay[0],
      SoC_U.Average_CellTemp, rtCP_uDLookupTableR0_bp01Data,
      rtCP_uDLookupTableR0_bp02Data, rtCP_uDLookupTableR0_tableData,
      rtCP_uDLookupTableR0_maxIndex, 21U) * rtb_ImpAsg_InsertedFor_SOC_at_p) -
      ((rtb_Delay[1] + rtb_Delay[2]) + rtb_Delay[3]));

    /* Product: '<S7>/Product6' incorporates:
     *  Product: '<S7>/Product3'
     */
    rtb_Kk1_0 = rtb_Kk1[0];
    rtb_Divide_d = rtb_Kk1[1];
    rtb_Assignment_0 = rtb_Kk1[2];
    rtb_Assignment_1 = rtb_Kk1[3];

    /* Sum: '<S7>/Sum4' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Math: '<S6>/Transpose1'
     *  Product: '<S7>/Product3'
     *  Product: '<S7>/Product6'
     */
    for (i = 0; i < 4; i++) {
      /* Product: '<S7>/Product6' incorporates:
       *  Math: '<S6>/Transpose1'
       */
      rtb_Transpose1_0 = rtb_Transpose1[i];
      i_0 = i << 2;
      tmp[i_0] = rtCP_Constant2_Value_c[i_0] - rtb_Kk1_0 * rtb_Transpose1_0;
      tmp[i_0 + 1] = rtCP_Constant2_Value_c[i_0 + 1] - rtb_Divide_d *
        rtb_Transpose1_0;
      tmp[i_0 + 2] = rtCP_Constant2_Value_c[i_0 + 2] - rtb_Assignment_0 *
        rtb_Transpose1_0;
      tmp[i_0 + 3] = rtCP_Constant2_Value_c[i_0 + 3] - rtb_Assignment_1 *
        rtb_Transpose1_0;
    }

    /* End of Sum: '<S7>/Sum4' */

    /* SignalConversion generated from: '<S7>/Product2' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Gain: '<S9>/-Ts'
     *  Inport: '<Root>/Average_CellTemp'
     *  Lookup_n-D: '<S6>/Capacity'
     *  Product: '<S6>/Product'
     *  Product: '<S6>/Product7'
     *  Product: '<S7>/Product2'
     */
    rtb_Transpose1[0] = -SoC_B.CoreSubsys[ForEach_itr].Probe[0] *
      0.00027777777777777778 / look1_binlxpw(SoC_U.Average_CellTemp,
      rtCP_Capacity_bp01Data, rtCP_Capacity_tableData, 9U) *
      rtb_ImpAsg_InsertedFor_SOC_at_p;
    rtb_Transpose1[1] = rtb_tau_m * rtb_ImpAsg_InsertedFor_SOC_at_p;
    rtb_Transpose1[2] = rtb_tau_c * rtb_ImpAsg_InsertedFor_SOC_at_p;
    rtb_Transpose1[3] = rtb_Ts * rtb_ImpAsg_InsertedFor_SOC_at_p;
    for (i = 0; i < 4; i++) {
      /* Product: '<S7>/Product8' */
      rtb_ImpAsg_InsertedFor_SOC_at_p = tmp[i];
      rtb_tau_m = tmp[i + 4];
      rtb_tau_c = tmp[i + 8];
      rtb_Ts = tmp[i + 12];

      /* Product: '<S7>/Product1' */
      rtb_Divide_d = 0.0;
      for (i_0 = 0; i_0 < 4; i_0++) {
        /* Product: '<S7>/Product8' incorporates:
         *  Product: '<S7>/Product1'
         *  Sum: '<S7>/Sum3'
         */
        rtb_Sum3_tmp = i_0 << 2;
        rtb_Sum3_tmp_0 = i + rtb_Sum3_tmp;
        SoC_B.CoreSubsys[ForEach_itr].Product8[rtb_Sum3_tmp_0] =
          ((rtb_Sum3[rtb_Sum3_tmp + 1] * rtb_tau_m + rtb_Sum3[rtb_Sum3_tmp] *
            rtb_ImpAsg_InsertedFor_SOC_at_p) + rtb_Sum3[rtb_Sum3_tmp + 2] *
           rtb_tau_c) + rtb_Sum3[rtb_Sum3_tmp + 3] * rtb_Ts;

        /* Product: '<S7>/Product1' incorporates:
         *  Assignment: '<S14>/Assignment'
         */
        rtb_Divide_d += rtb_Assignment[rtb_Sum3_tmp_0] * rtb_Delay[i_0];
      }

      /* Sum: '<S7>/Sum' incorporates:
       *  Product: '<S7>/Product1'
       *  Product: '<S7>/Product3'
       *  Product: '<S7>/Product5'
       *  Sum: '<S7>/Sum1'
       */
      SoC_B.CoreSubsys[ForEach_itr].Sum[i] = rtb_Kk1[i] * rtb_Sum_g +
        (rtb_Divide_d + rtb_Transpose1[i]);
    }

    /* ForEachSliceAssignment generated from: '<S1>/SOC' incorporates:
     *  Gain: '<S1>/Gain2'
     */
    rtb_ImpAsg_InsertedFor_SOC_at_p = 100.0 * SoC_B.CoreSubsys[ForEach_itr].Sum
      [0];
  }

  /* End of Outputs for SubSystem: '<Root>/3RCAccu' */

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_ImpAsg_InsertedFor_SOC_at_p > 100.0) {
    /* Outport: '<Root>/SoC_Avg' */
    SoC_Y.SoC_Avg = 100.0;
  } else if (rtb_ImpAsg_InsertedFor_SOC_at_p < 0.0) {
    /* Outport: '<Root>/SoC_Avg' */
    SoC_Y.SoC_Avg = 0.0;
  } else {
    /* Outport: '<Root>/SoC_Avg' */
    SoC_Y.SoC_Avg = rtb_ImpAsg_InsertedFor_SOC_at_p;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Outport: '<Root>/SoC_Low' */
  SoC_Y.SoC_Low = rtb_Saturation;

  /* Lookup_n-D: '<Root>/Cell OCV to SOC 2024 H' incorporates:
   *  Inport: '<Root>/Highest_CellVoltage'
   */
  SoC_B.CellOCVtoSOC2024H = look1_binlxpw(SoC_U.Highest_CellVoltage,
    rtCP_CellOCVtoSOC2024H_bp01Data, rtCP_CellOCVtoSOC2024H_tableDat, 599U);

  /* Outputs for Iterator SubSystem: '<Root>/3RC_Cell_H' */
  /* Inport: '<Root>/Accumulator_Current' incorporates:
   *  Inport: '<Root>/Average_CellTemp'
   *  Inport: '<Root>/Highest_CellVoltage'
   */
  SoC_uRC_Cell_H(1, &SoC_U.Accumulator_Current, &SoC_U.Highest_CellVoltage,
                 &SoC_U.Average_CellTemp, &SoC_B.CellOCVtoSOC2024H,
                 &rtb_ImpAsg_InsertedFor_SOC_at_o, SoC_B.uRC_Cell_H,
                 SoC_DW.uRC_Cell_H);

  /* End of Outputs for SubSystem: '<Root>/3RC_Cell_H' */

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_ImpAsg_InsertedFor_SOC_at_o > 100.0) {
    /* Outport: '<Root>/SoC_High' */
    SoC_Y.SoC_High = 100.0;
  } else if (rtb_ImpAsg_InsertedFor_SOC_at_o < 0.0) {
    /* Outport: '<Root>/SoC_High' */
    SoC_Y.SoC_High = 0.0;
  } else {
    /* Outport: '<Root>/SoC_High' */
    SoC_Y.SoC_High = rtb_ImpAsg_InsertedFor_SOC_at_o;
  }

  /* End of Saturate: '<Root>/Saturation2' */
}

/* Model update function */
static void SoC_update(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Update for Iterator SubSystem: '<Root>/3RC_Cell_L' */
  SoC_uRC_Cell_H_Update(1, SoC_B.uRC_Cell_L, SoC_DW.uRC_Cell_L);

  /* End of Update for SubSystem: '<Root>/3RC_Cell_L' */

  /* Update for Iterator SubSystem: '<Root>/3RCAccu' */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* Update for Delay: '<S5>/Delay' */
    SoC_DW.CoreSubsys[ForEach_itr].icLoad = false;
    SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[0] =
      SoC_B.CoreSubsys[ForEach_itr].Sum[0];
    SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[1] =
      SoC_B.CoreSubsys[ForEach_itr].Sum[1];
    SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[2] =
      SoC_B.CoreSubsys[ForEach_itr].Sum[2];
    SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[3] =
      SoC_B.CoreSubsys[ForEach_itr].Sum[3];

    /* Update for UnitDelay: '<S7>/Unit Delay - P' incorporates:
     *  Product: '<S7>/Product8'
     */
    memcpy(&SoC_DW.CoreSubsys[ForEach_itr].UnitDelayP_DSTATE[0],
           &SoC_B.CoreSubsys[ForEach_itr].Product8[0], sizeof(real_T) << 4U);
  }

  /* End of Update for SubSystem: '<Root>/3RCAccu' */

  /* Update for Iterator SubSystem: '<Root>/3RC_Cell_H' */
  SoC_uRC_Cell_H_Update(1, SoC_B.uRC_Cell_H, SoC_DW.uRC_Cell_H);

  /* End of Update for SubSystem: '<Root>/3RC_Cell_H' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++SoC_M->Timing.clockTick0)) {
    ++SoC_M->Timing.clockTickH0;
  }

  SoC_M->Timing.t[0] = SoC_M->Timing.clockTick0 * SoC_M->Timing.stepSize0 +
    SoC_M->Timing.clockTickH0 * SoC_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void SoC_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;

    /* Start for Iterator SubSystem: '<Root>/3RC_Cell_L' */
    SoC_uRC_Cell_H_Start(1, SoC_B.uRC_Cell_L, SoC_DW.uRC_Cell_L);

    /* End of Start for SubSystem: '<Root>/3RC_Cell_L' */

    /* Start for Iterator SubSystem: '<Root>/3RCAccu' */
    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      /* Start for SignalConversion generated from: '<S5>/Delay' */
      SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[0] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[0] = 0.0;

      /* Start for SignalConversion generated from: '<S5>/Delay' */
      SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[1] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[1] = 0.0;

      /* Start for SignalConversion generated from: '<S5>/Delay' */
      SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[2] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[2] = 0.0;

      /* Start for SignalConversion generated from: '<S5>/Delay' */
      SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtDelayInpor[3] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr].Delay_DSTATE[3] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr].Divide_DWORK4 = 0.0;
      memset(&SoC_DW.CoreSubsys[ForEach_itr].UnitDelayP_DSTATE[0], 0, sizeof
             (real_T) << 4U);

      /* Start for Product: '<S7>/Product8' */
      memset(&SoC_B.CoreSubsys[ForEach_itr].Product8[0], 0, sizeof(real_T) << 4U);

      /* Start for Sum: '<S7>/Sum' */
      SoC_B.CoreSubsys[ForEach_itr].Sum[0] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].Sum[1] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].Sum[2] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].Sum[3] = 0.0;

      /* Start for Probe: '<S9>/Probe' */
      SoC_B.CoreSubsys[ForEach_itr].Probe[0] = 0.025;
      SoC_B.CoreSubsys[ForEach_itr].Probe[1] = 0.0;
    }

    /* End of Start for SubSystem: '<Root>/3RCAccu' */

    /* Start for Iterator SubSystem: '<Root>/3RC_Cell_H' */
    SoC_uRC_Cell_H_Start(1, SoC_B.uRC_Cell_H, SoC_DW.uRC_Cell_H);

    /* End of Start for SubSystem: '<Root>/3RC_Cell_H' */
  }

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;

    /* SystemInitialize for Iterator SubSystem: '<Root>/3RC_Cell_L' */
    SoC_uRC_Cell_H_Init(1, SoC_DW.uRC_Cell_L);

    /* End of SystemInitialize for SubSystem: '<Root>/3RC_Cell_L' */

    /* SystemInitialize for Iterator SubSystem: '<Root>/3RCAccu' */
    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      /* InitializeConditions for Delay: '<S5>/Delay' */
      SoC_DW.CoreSubsys[ForEach_itr].icLoad = true;

      /* InitializeConditions for UnitDelay: '<S7>/Unit Delay - P' */
      memcpy(&SoC_DW.CoreSubsys[ForEach_itr].UnitDelayP_DSTATE[0],
             &rtCP_UnitDelayP_InitialConditio[0], sizeof(real_T) << 4U);
    }

    /* End of SystemInitialize for SubSystem: '<Root>/3RCAccu' */

    /* SystemInitialize for Iterator SubSystem: '<Root>/3RC_Cell_H' */
    SoC_uRC_Cell_H_Init(1, SoC_DW.uRC_Cell_H);

    /* End of SystemInitialize for SubSystem: '<Root>/3RC_Cell_H' */
  }
}

/* Model terminate function */
static void SoC_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  SoC_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  SoC_update();
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
  SoC_initialize();
}

void MdlTerminate(void)
{
  SoC_terminate();
}

/* Registration function */
RT_MODEL_SoC_T *SoC(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SoC_M, 0,
                sizeof(RT_MODEL_SoC_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = SoC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "SoC_M points to
       static memory which is guaranteed to be non-NULL" */
    SoC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SoC_M->Timing.sampleTimes = (&SoC_M->Timing.sampleTimesArray[0]);
    SoC_M->Timing.offsetTimes = (&SoC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SoC_M->Timing.sampleTimes[0] = (0.025);

    /* task offsets */
    SoC_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(SoC_M, &SoC_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = SoC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    SoC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SoC_M, 10.0);
  SoC_M->Timing.stepSize0 = 0.025;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    SoC_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(SoC_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(SoC_M->rtwLogInfo, (NULL));
    rtliSetLogT(SoC_M->rtwLogInfo, "tout");
    rtliSetLogX(SoC_M->rtwLogInfo, "");
    rtliSetLogXFinal(SoC_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(SoC_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(SoC_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(SoC_M->rtwLogInfo, 0);
    rtliSetLogDecimation(SoC_M->rtwLogInfo, 1);
    rtliSetLogY(SoC_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(SoC_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(SoC_M->rtwLogInfo, (NULL));
  }

  SoC_M->solverInfoPtr = (&SoC_M->solverInfo);
  SoC_M->Timing.stepSize = (0.025);
  rtsiSetFixedStepSize(&SoC_M->solverInfo, 0.025);
  rtsiSetSolverMode(&SoC_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  SoC_M->blockIO = ((void *) &SoC_B);
  (void) memset(((void *) &SoC_B), 0,
                sizeof(B_SoC_T));

  /* states (dwork) */
  SoC_M->dwork = ((void *) &SoC_DW);
  (void) memset((void *)&SoC_DW, 0,
                sizeof(DW_SoC_T));

  /* external inputs */
  SoC_M->inputs = (((void*)&SoC_U));
  (void)memset(&SoC_U, 0, sizeof(ExtU_SoC_T));

  /* external outputs */
  SoC_M->outputs = (&SoC_Y);
  (void)memset(&SoC_Y, 0, sizeof(ExtY_SoC_T));

  /* Initialize Sizes */
  SoC_M->Sizes.numContStates = (0);    /* Number of continuous states */
  SoC_M->Sizes.numY = (4);             /* Number of model outputs */
  SoC_M->Sizes.numU = (5);             /* Number of model inputs */
  SoC_M->Sizes.sysDirFeedThru = (1);   /* The model is direct feedthrough */
  SoC_M->Sizes.numSampTimes = (1);     /* Number of sample times */
  SoC_M->Sizes.numBlocks = (178);      /* Number of blocks */
  SoC_M->Sizes.numBlockIO = (15);      /* Number of block outputs */
  return SoC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
