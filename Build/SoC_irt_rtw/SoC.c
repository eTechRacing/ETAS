/*
 * SoC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 13.9
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Jul 25 00:36:46 2024
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
 *    '<S2>/3RC1'
 *    '<S3>/3RC1'
 */
void SoC_uRC1_Init(int32_T NumIters, DW_uRC1_SoC_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* InitializeConditions for Delay: '<S9>/Delay' */
    localDW[ForEach_itr].CoreSubsys.icLoad = true;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay - P' */
    memcpy(&localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[0],
           &rtCP_UnitDelayP_InitialConditio[0], sizeof(real_T) << 4U);
  }
}

/*
 * Start for iterator system:
 *    '<S2>/3RC1'
 *    '<S3>/3RC1'
 */
void SoC_uRC1_Start(int32_T NumIters, B_uRC1_SoC_T localB[1], DW_uRC1_SoC_T
                    localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Start for SignalConversion generated from: '<S9>/Delay' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[0] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[0] = 0.0;

    /* Start for SignalConversion generated from: '<S9>/Delay' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[1] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[1] = 0.0;

    /* Start for SignalConversion generated from: '<S9>/Delay' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[2] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[2] = 0.0;

    /* Start for SignalConversion generated from: '<S9>/Delay' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[3] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[3] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Divide_DWORK4 = 0.0;
    memset(&localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[0], 0, sizeof
           (real_T) << 4U);

    /* Start for Product: '<S8>/Product5' */
    memset(&localB[ForEach_itr].CoreSubsys.Product5[0], 0, sizeof(real_T) << 4U);

    /* Start for Sum: '<S8>/Sum' */
    localB[ForEach_itr].CoreSubsys.Sum[0] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum[1] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum[2] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum[3] = 0.0;

    /* Start for Probe: '<S10>/Probe' */
    localB[ForEach_itr].CoreSubsys.Probe[0] = 280.0;
    localB[ForEach_itr].CoreSubsys.Probe[1] = 0.0;
  }
}

/*
 * Outputs for iterator system:
 *    '<S2>/3RC1'
 *    '<S3>/3RC1'
 */
void SoC_uRC1(int32_T NumIters, const real_T *rtu_Current, const real_T
              *rtu_CellVoltage, const real_T *rtu_CellTemperature, const real_T *
              rtu_InitialSOC, real_T *rty_SOC, B_uRC1_SoC_T localB[1],
              DW_uRC1_SoC_T localDW[1])
{
  /* local block i/o variables */
  real_T rtb_Delay[4];

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_Assignment[16];
  real_T rtb_Sum1[16];
  real_T tmp[16];
  real_T rtb_Product[4];
  real_T rtb_TmpSignalConversionAtProduc[4];
  int32_T i;
  int32_T i_0;

  /* Outputs for Iterator SubSystem: '<S2>/3RC1' incorporates:
   *  ForEach: '<S6>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    real_T rtb_Assignment_0;
    real_T rtb_Assignment_1;
    real_T rtb_MathFunction2;
    real_T rtb_MathFunction2_jv;
    real_T rtb_MathFunction2_p;
    real_T rtb_Product_0;
    real_T rtb_SumofElements;
    real_T rtb_TmpSignalConversionAtProd_0;
    real_T rtb_uDLookupTable;
    real_T rtb_uDLookupTableR1;
    real_T rtb_uDLookupTableR2;
    real_T rtb_uDLookupTableR3;
    int32_T rtb_Sum1_tmp;
    int32_T rtb_Sum1_tmp_0;

    /* SignalConversion generated from: '<S9>/Delay' incorporates:
     *  Constant: '<S9>/Constant1'
     *  Gain: '<S6>/Gain1'
     */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[0] = 0.01 *
      rtu_InitialSOC[ForEach_itr];
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[1] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[2] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtDelayInpor[3] = 0.0;

    /* Delay: '<S9>/Delay' */
    if (localDW[ForEach_itr].CoreSubsys.icLoad) {
      localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[0] = localB[ForEach_itr].
        CoreSubsys.TmpSignalConversionAtDelayInpor[0];
      localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[1] = 0.0;
      localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[2] = 0.0;
      localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[3] = 0.0;
    }

    /* Delay: '<S9>/Delay' */
    rtb_Delay[0] = localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[0];
    rtb_Delay[1] = localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[1];
    rtb_Delay[2] = localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[2];
    rtb_Delay[3] = localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[3];

    /* Gain: '<S10>/Gain' */
    rtb_SumofElements = 100.0 * rtb_Delay[0];

    /* SignalConversion generated from: '<S10>/Transpose1' incorporates:
     *  Constant: '<S10>/Constant4'
     *  Lookup_n-D: '<S10>/2-D Lookup Table OCV1'
     *  Sum: '<S10>/Sum of Elements'
     */
    rtb_TmpSignalConversionAtProduc[0] = look2_binlxpw(rtb_SumofElements,
      rtu_CellTemperature[ForEach_itr], rtCP_uDLookupTableOCV1_bp01Data,
      rtCP_uDLookupTableOCV1_bp02Data, rtCP_uDLookupTableOCV1_tableDat,
      rtCP_uDLookupTableOCV1_maxIndex, 21U);
    rtb_TmpSignalConversionAtProduc[1] = -1.0;
    rtb_TmpSignalConversionAtProduc[2] = -1.0;
    rtb_TmpSignalConversionAtProduc[3] = -1.0;

    /* SignalConversion generated from: '<S19>/Assignment' incorporates:
     *  Assignment: '<S21>/Assignment'
     *  Constant: '<S10>/Constant'
     */
    memcpy(&rtb_Assignment[0], &rtCP_Constant_Value_m[0], sizeof(real_T) << 4U);

    /* Lookup_n-D: '<S19>/2-D Lookup Table R1' incorporates:
     *  Sum: '<S10>/Sum of Elements'
     */
    rtb_uDLookupTableR1 = look2_binlxpw(rtb_SumofElements,
      rtu_CellTemperature[ForEach_itr], rtCP_uDLookupTableR1_bp01Data,
      rtCP_uDLookupTableR1_bp02Data, rtCP_uDLookupTableR1_tableData,
      rtCP_uDLookupTableR1_maxIndex, 21U);

    /* Math: '<S19>/Math Function2' incorporates:
     *  Gain: '<S10>/Gain1'
     *  Lookup_n-D: '<S19>/2-D Lookup Table C1'
     *  Product: '<S19>/Product10'
     *  Product: '<S19>/Product9'
     *  Sum: '<S10>/Sum of Elements'
     *
     * About '<S19>/Math Function2':
     *  Operator: exp
     */
    rtb_MathFunction2 = exp(-localB[ForEach_itr].CoreSubsys.Probe[0] /
      (look2_binlxpw(rtb_SumofElements, rtu_CellTemperature[ForEach_itr],
                     rtCP_uDLookupTableC1_bp01Data,
                     rtCP_uDLookupTableC1_bp02Data,
                     rtCP_uDLookupTableC1_tableData,
                     rtCP_uDLookupTableC1_maxIndex, 21U) * rtb_uDLookupTableR1));

    /* Assignment: '<S19>/Assignment' incorporates:
     *  Assignment: '<S21>/Assignment'
     */
    rtb_Assignment[5] = rtb_MathFunction2;

    /* Lookup_n-D: '<S20>/2-D Lookup Table R2' incorporates:
     *  Sum: '<S10>/Sum of Elements'
     */
    rtb_uDLookupTableR2 = look2_binlxpw(rtb_SumofElements,
      rtu_CellTemperature[ForEach_itr], rtCP_uDLookupTableR2_bp01Data,
      rtCP_uDLookupTableR2_bp02Data, rtCP_uDLookupTableR2_tableData,
      rtCP_uDLookupTableR2_maxIndex, 21U);

    /* Math: '<S20>/Math Function2' incorporates:
     *  Gain: '<S10>/Gain1'
     *  Lookup_n-D: '<S20>/2-D Lookup Table C2'
     *  Product: '<S20>/Product10'
     *  Product: '<S20>/Product9'
     *  Sum: '<S10>/Sum of Elements'
     *
     * About '<S20>/Math Function2':
     *  Operator: exp
     */
    rtb_MathFunction2_p = exp(-localB[ForEach_itr].CoreSubsys.Probe[0] /
      (look2_binlxpw(rtb_SumofElements, rtu_CellTemperature[ForEach_itr],
                     rtCP_uDLookupTableC2_bp01Data,
                     rtCP_uDLookupTableC2_bp02Data,
                     rtCP_uDLookupTableC2_tableData,
                     rtCP_uDLookupTableC2_maxIndex, 21U) * rtb_uDLookupTableR2));

    /* Assignment: '<S20>/Assignment' incorporates:
     *  Assignment: '<S21>/Assignment'
     */
    rtb_Assignment[10] = rtb_MathFunction2_p;

    /* Lookup_n-D: '<S21>/2-D Lookup Table R3' incorporates:
     *  Sum: '<S10>/Sum of Elements'
     */
    rtb_uDLookupTableR3 = look2_binlxpw(rtb_SumofElements,
      rtu_CellTemperature[ForEach_itr], rtCP_uDLookupTableR3_bp01Data,
      rtCP_uDLookupTableR3_bp02Data, rtCP_uDLookupTableR3_tableData,
      rtCP_uDLookupTableR3_maxIndex, 21U);

    /* Math: '<S21>/Math Function2' incorporates:
     *  Gain: '<S10>/Gain1'
     *  Lookup_n-D: '<S21>/2-D Lookup Table C3'
     *  Product: '<S21>/Product10'
     *  Product: '<S21>/Product9'
     *  Sum: '<S10>/Sum of Elements'
     *
     * About '<S21>/Math Function2':
     *  Operator: exp
     */
    rtb_MathFunction2_jv = exp(-localB[ForEach_itr].CoreSubsys.Probe[0] /
      (look2_binlxpw(rtb_SumofElements, rtu_CellTemperature[ForEach_itr],
                     rtCP_uDLookupTableC3_bp01Data,
                     rtCP_uDLookupTableC3_bp02Data,
                     rtCP_uDLookupTableC3_tableData,
                     rtCP_uDLookupTableC3_maxIndex, 21U) * rtb_uDLookupTableR3));

    /* Assignment: '<S21>/Assignment' */
    rtb_Assignment[15] = rtb_MathFunction2_jv;

    /* Product: '<S11>/Product2' incorporates:
     *  Assignment: '<S21>/Assignment'
     *  Math: '<S11>/Transpose'
     *  UnitDelay: '<S7>/Unit Delay - P'
     */
    for (i = 0; i < 4; i++) {
      for (i_0 = 0; i_0 < 4; i_0++) {
        tmp[i + (i_0 << 2)] = ((localDW[ForEach_itr].
          CoreSubsys.UnitDelayP_DSTATE[i + 4] * rtb_Assignment[i_0 + 4] +
          localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[i] *
          rtb_Assignment[i_0]) + localDW[ForEach_itr].
          CoreSubsys.UnitDelayP_DSTATE[i + 8] * rtb_Assignment[i_0 + 8]) +
          localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[i + 12] *
          rtb_Assignment[i_0 + 12];
      }
    }

    /* Product: '<S8>/Product2' */
    rtb_TmpSignalConversionAtProd_0 = 0.0;
    for (i = 0; i < 4; i++) {
      real_T rtb_Assignment_2;

      /* Sum: '<S11>/Sum1' incorporates:
       *  Assignment: '<S21>/Assignment'
       *  Product: '<S11>/Product2'
       */
      rtb_Assignment_0 = rtb_Assignment[i + 4];
      rtb_uDLookupTable = rtb_Assignment[i];
      rtb_Assignment_1 = rtb_Assignment[i + 8];
      rtb_Assignment_2 = rtb_Assignment[i + 12];

      /* Product: '<S8>/Product2' */
      rtb_Product_0 = 0.0;
      for (i_0 = 0; i_0 < 4; i_0++) {
        real_T rtb_Sum1_0;

        /* Product: '<S11>/Product2' incorporates:
         *  Constant: '<S11>/Constant1'
         *  Sum: '<S11>/Sum1'
         */
        rtb_Sum1_tmp = i_0 << 2;

        /* Sum: '<S11>/Sum1' incorporates:
         *  Constant: '<S11>/Constant1'
         *  Product: '<S11>/Product2'
         */
        rtb_Sum1_tmp_0 = rtb_Sum1_tmp + i;
        rtb_Sum1_0 = (((tmp[rtb_Sum1_tmp + 1] * rtb_Assignment_0 +
                        tmp[rtb_Sum1_tmp] * rtb_uDLookupTable) +
                       tmp[rtb_Sum1_tmp + 2] * rtb_Assignment_1) +
                      tmp[rtb_Sum1_tmp + 3] * rtb_Assignment_2) +
          rtCP_Constant1_Value_d[rtb_Sum1_tmp_0];
        rtb_Sum1[rtb_Sum1_tmp_0] = rtb_Sum1_0;

        /* Product: '<S8>/Product2' incorporates:
         *  Math: '<S8>/Transpose'
         *  Product: '<S8>/Product'
         *  SignalConversion generated from: '<S11>/Product1'
         */
        rtb_Product_0 += rtb_Sum1_0 * rtb_TmpSignalConversionAtProduc[i_0];
      }

      /* Product: '<S8>/Product2' incorporates:
       *  SignalConversion generated from: '<S11>/Product1'
       */
      rtb_Product[i] = rtb_Product_0;
      rtb_TmpSignalConversionAtProd_0 += rtb_TmpSignalConversionAtProduc[i] *
        rtb_Product_0;
    }

    /* Product: '<S8>/Divide' incorporates:
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  Product: '<S8>/Product2'
     *  Sum: '<S8>/Sum2'
     */
    rtb_uDLookupTable = 1.0 / (rtb_TmpSignalConversionAtProd_0 + 5.0);

    /* Product: '<S8>/Product1' incorporates:
     *  Product: '<S11>/Product'
     *  Product: '<S8>/Product'
     */
    rtb_Product[0] *= rtb_uDLookupTable;
    rtb_Product[1] *= rtb_uDLookupTable;
    rtb_Product[2] *= rtb_uDLookupTable;
    rtb_Product[3] *= rtb_uDLookupTable;

    /* Sum: '<S7>/Sum' incorporates:
     *  Gain: '<S6>/Gain'
     *  Lookup_n-D: '<S10>/2-D Lookup Table OCV'
     *  Lookup_n-D: '<S10>/2-D Lookup Table R0'
     *  Product: '<S10>/Product6'
     *  Sum: '<S10>/Sum of Elements'
     *  Sum: '<S10>/Sum2'
     */
    rtb_uDLookupTable = rtu_CellVoltage[ForEach_itr] - ((look2_binlxpw
      (rtb_SumofElements, rtu_CellTemperature[ForEach_itr],
       rtCP_uDLookupTableOCV_bp01Data, rtCP_uDLookupTableOCV_bp02Data,
       rtCP_uDLookupTableOCV_tableData, rtCP_uDLookupTableOCV_maxIndex, 21U) -
      look2_binlxpw(rtb_SumofElements, rtu_CellTemperature[ForEach_itr],
                    rtCP_uDLookupTableR0_bp01Data, rtCP_uDLookupTableR0_bp02Data,
                    rtCP_uDLookupTableR0_tableData,
                    rtCP_uDLookupTableR0_maxIndex, 21U) *
      -rtu_Current[ForEach_itr]) - ((rtb_Delay[1] + rtb_Delay[2]) + rtb_Delay[3]));

    /* Product: '<S8>/Product4' incorporates:
     *  Product: '<S11>/Product'
     */
    rtb_Product_0 = rtb_Product[0];
    rtb_Assignment_0 = rtb_Product[1];
    rtb_SumofElements = rtb_Product[2];
    rtb_Assignment_1 = rtb_Product[3];

    /* Sum: '<S8>/Sum3' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Product: '<S11>/Product'
     *  Product: '<S8>/Product4'
     *  SignalConversion generated from: '<S11>/Product1'
     */
    for (i = 0; i < 4; i++) {
      /* Product: '<S8>/Product4' incorporates:
       *  SignalConversion generated from: '<S11>/Product1'
       */
      rtb_TmpSignalConversionAtProd_0 = rtb_TmpSignalConversionAtProduc[i];
      i_0 = i << 2;
      tmp[i_0] = rtCP_Constant2_Value[i_0] - rtb_Product_0 *
        rtb_TmpSignalConversionAtProd_0;
      tmp[i_0 + 1] = rtCP_Constant2_Value[i_0 + 1] - rtb_Assignment_0 *
        rtb_TmpSignalConversionAtProd_0;
      tmp[i_0 + 2] = rtCP_Constant2_Value[i_0 + 2] - rtb_SumofElements *
        rtb_TmpSignalConversionAtProd_0;
      tmp[i_0 + 3] = rtCP_Constant2_Value[i_0 + 3] - rtb_Assignment_1 *
        rtb_TmpSignalConversionAtProd_0;
    }

    /* End of Sum: '<S8>/Sum3' */

    /* SignalConversion generated from: '<S11>/Product1' incorporates:
     *  Constant: '<S10>/Constant2'
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S20>/Constant1'
     *  Constant: '<S21>/Constant1'
     *  Gain: '<S10>/Gain1'
     *  Gain: '<S6>/Gain'
     *  Lookup_n-D: '<S10>/1-D Lookup Table'
     *  Product: '<S10>/Product7'
     *  Product: '<S10>/Product8'
     *  Product: '<S11>/Product1'
     *  Product: '<S19>/Product11'
     *  Product: '<S20>/Product11'
     *  Product: '<S21>/Product11'
     *  Sum: '<S19>/Sum'
     *  Sum: '<S20>/Sum'
     *  Sum: '<S21>/Sum'
     */
    rtb_TmpSignalConversionAtProduc[0] = -localB[ForEach_itr].CoreSubsys.Probe[0]
      * 0.00027777777777777778 / look1_binlxpw(rtu_CellTemperature[ForEach_itr],
      rtCP_uDLookupTable_bp01Data, rtCP_uDLookupTable_tableData, 9U) *
      -rtu_Current[ForEach_itr];
    rtb_TmpSignalConversionAtProduc[1] = (1.0 - rtb_MathFunction2) *
      rtb_uDLookupTableR1 * -rtu_Current[ForEach_itr];
    rtb_TmpSignalConversionAtProduc[2] = (1.0 - rtb_MathFunction2_p) *
      rtb_uDLookupTableR2 * -rtu_Current[ForEach_itr];
    rtb_TmpSignalConversionAtProduc[3] = (1.0 - rtb_MathFunction2_jv) *
      rtb_uDLookupTableR3 * -rtu_Current[ForEach_itr];
    for (i = 0; i < 4; i++) {
      /* Product: '<S8>/Product5' */
      rtb_uDLookupTableR1 = tmp[i];
      rtb_MathFunction2 = tmp[i + 4];
      rtb_uDLookupTableR2 = tmp[i + 8];
      rtb_MathFunction2_p = tmp[i + 12];

      /* Product: '<S11>/Product' */
      rtb_Assignment_0 = 0.0;
      for (i_0 = 0; i_0 < 4; i_0++) {
        /* Product: '<S8>/Product5' incorporates:
         *  Product: '<S11>/Product'
         *  Sum: '<S11>/Sum1'
         */
        rtb_Sum1_tmp = i_0 << 2;
        rtb_Sum1_tmp_0 = i + rtb_Sum1_tmp;
        localB[ForEach_itr].CoreSubsys.Product5[rtb_Sum1_tmp_0] =
          ((rtb_Sum1[rtb_Sum1_tmp + 1] * rtb_MathFunction2 +
            rtb_Sum1[rtb_Sum1_tmp] * rtb_uDLookupTableR1) +
           rtb_Sum1[rtb_Sum1_tmp + 2] * rtb_uDLookupTableR2) +
          rtb_Sum1[rtb_Sum1_tmp + 3] * rtb_MathFunction2_p;

        /* Product: '<S11>/Product' incorporates:
         *  Assignment: '<S21>/Assignment'
         */
        rtb_Assignment_0 += rtb_Assignment[rtb_Sum1_tmp_0] * rtb_Delay[i_0];
      }

      /* Sum: '<S8>/Sum' incorporates:
       *  Product: '<S11>/Product'
       *  Product: '<S8>/Product3'
       *  Sum: '<S11>/Sum'
       */
      localB[ForEach_itr].CoreSubsys.Sum[i] = rtb_Product[i] * rtb_uDLookupTable
        + (rtb_Assignment_0 + rtb_TmpSignalConversionAtProduc[i]);
    }

    /* ForEachSliceAssignment generated from: '<S6>/SOC' incorporates:
     *  Gain: '<S6>/Gain2'
     */
    rty_SOC[ForEach_itr] = 100.0 * localB[ForEach_itr].CoreSubsys.Sum[0];
  }

  /* End of Outputs for SubSystem: '<S2>/3RC1' */
}

/*
 * Update for iterator system:
 *    '<S2>/3RC1'
 *    '<S3>/3RC1'
 */
void SoC_uRC1_Update(int32_T NumIters, B_uRC1_SoC_T localB[1], DW_uRC1_SoC_T
                     localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Update for Delay: '<S9>/Delay' */
    localDW[ForEach_itr].CoreSubsys.icLoad = false;
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[0] = localB[ForEach_itr].
      CoreSubsys.Sum[0];
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[1] = localB[ForEach_itr].
      CoreSubsys.Sum[1];
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[2] = localB[ForEach_itr].
      CoreSubsys.Sum[2];
    localDW[ForEach_itr].CoreSubsys.Delay_DSTATE[3] = localB[ForEach_itr].
      CoreSubsys.Sum[3];

    /* Update for UnitDelay: '<S7>/Unit Delay - P' incorporates:
     *  Product: '<S8>/Product5'
     */
    memcpy(&localDW[ForEach_itr].CoreSubsys.UnitDelayP_DSTATE[0],
           &localB[ForEach_itr].CoreSubsys.Product5[0], sizeof(real_T) << 4U);
  }
}

/* Model output function */
static void SoC_output(void)
{
  /* local block i/o variables */
  real_T rtb_ImpAsg_InsertedFor_SOC_at_i;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_o;
  real_T rtb_Saturation;
  real_T rtb_Saturation_m;
  boolean_T tmp;

  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/Car_State'
   *  Logic: '<S2>/NOT'
   *  Logic: '<S3>/NOT'
   */
  tmp = ((!(SoC_U.Car_State >= 12.0)) || (!(SoC_U.Car_State <= 15.0)));

  /* Switch: '<S2>/Switch' incorporates:
   *  Logic: '<S2>/NOT'
   */
  if (tmp) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Inport: '<Root>/Highest_CellVoltage'
     *  Lookup_n-D: '<S2>/OCV to SOC 2024'
     */
    SoC_B.Switch = look1_binlxpw(SoC_U.Highest_CellVoltage,
      rtCP_OCVtoSOC2024_bp01Data, rtCP_OCVtoSOC2024_tableData, 724U);
  } else {
    /* Switch: '<S2>/Switch' incorporates:
     *  Memory: '<S2>/Memory'
     */
    SoC_B.Switch = SoC_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Outputs for Iterator SubSystem: '<S2>/3RC1' */
  /* Inport: '<Root>/Accumulator_Current' incorporates:
   *  Inport: '<Root>/Highest_CellTemp'
   *  Inport: '<Root>/Highest_CellVoltage'
   */
  SoC_uRC1(1, &SoC_U.Accumulator_Current, &SoC_U.Highest_CellVoltage,
           &SoC_U.Highest_CellTemp, &SoC_B.Switch,
           &rtb_ImpAsg_InsertedFor_SOC_at_o, SoC_B.uRC1, SoC_DW.uRC1);

  /* End of Outputs for SubSystem: '<S2>/3RC1' */

  /* Saturate: '<S2>/Saturation' */
  if (rtb_ImpAsg_InsertedFor_SOC_at_o > 100.0) {
    rtb_Saturation = 100.0;
  } else if (rtb_ImpAsg_InsertedFor_SOC_at_o < 0.0) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = rtb_ImpAsg_InsertedFor_SOC_at_o;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Switch: '<S3>/Switch' */
  if (tmp) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Inport: '<Root>/Lowest_CellVoltage'
     *  Lookup_n-D: '<S3>/OCV to SOC 2024'
     */
    SoC_B.Switch_d = look1_binlxpw(SoC_U.Lowest_CellVoltage,
      rtCP_OCVtoSOC2024_bp01Data_b, rtCP_OCVtoSOC2024_tableData_p, 724U);
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Memory: '<S3>/Memory'
     */
    SoC_B.Switch_d = SoC_DW.Memory_PreviousInput_p;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Outputs for Iterator SubSystem: '<S3>/3RC1' */
  /* Inport: '<Root>/Accumulator_Current' incorporates:
   *  Inport: '<Root>/Lowest_CellTemp'
   *  Inport: '<Root>/Lowest_CellVoltage'
   */
  SoC_uRC1(1, &SoC_U.Accumulator_Current, &SoC_U.Lowest_CellVoltage,
           &SoC_U.Lowest_CellTemp, &SoC_B.Switch_d,
           &rtb_ImpAsg_InsertedFor_SOC_at_i, SoC_B.uRC1_p, SoC_DW.uRC1_p);

  /* End of Outputs for SubSystem: '<S3>/3RC1' */

  /* Saturate: '<S3>/Saturation' */
  if (rtb_ImpAsg_InsertedFor_SOC_at_i > 100.0) {
    rtb_Saturation_m = 100.0;
  } else if (rtb_ImpAsg_InsertedFor_SOC_at_i < 0.0) {
    rtb_Saturation_m = 0.0;
  } else {
    rtb_Saturation_m = rtb_ImpAsg_InsertedFor_SOC_at_i;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Outport: '<Root>/SoC_Avg' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Sum: '<Root>/Add'
   */
  SoC_Y.SoC_Avg = (rtb_Saturation + rtb_Saturation_m) * 0.5;

  /* Outport: '<Root>/SoC_High' */
  SoC_Y.SoC_High = rtb_Saturation;

  /* Outport: '<Root>/SoC_Low' */
  SoC_Y.SoC_Low = rtb_Saturation_m;
}

/* Model update function */
static void SoC_update(void)
{
  /* Update for Memory: '<S2>/Memory' */
  SoC_DW.Memory_PreviousInput = SoC_B.Switch;

  /* Update for Iterator SubSystem: '<S2>/3RC1' */
  SoC_uRC1_Update(1, SoC_B.uRC1, SoC_DW.uRC1);

  /* End of Update for SubSystem: '<S2>/3RC1' */

  /* Update for Memory: '<S3>/Memory' */
  SoC_DW.Memory_PreviousInput_p = SoC_B.Switch_d;

  /* Update for Iterator SubSystem: '<S3>/3RC1' */
  SoC_uRC1_Update(1, SoC_B.uRC1_p, SoC_DW.uRC1_p);

  /* End of Update for SubSystem: '<S3>/3RC1' */

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
  /* Start for Iterator SubSystem: '<S2>/3RC1' */
  SoC_uRC1_Start(1, SoC_B.uRC1, SoC_DW.uRC1);

  /* End of Start for SubSystem: '<S2>/3RC1' */

  /* Start for Iterator SubSystem: '<S3>/3RC1' */
  SoC_uRC1_Start(1, SoC_B.uRC1_p, SoC_DW.uRC1_p);

  /* End of Start for SubSystem: '<S3>/3RC1' */

  /* InitializeConditions for Memory: '<S2>/Memory' */
  SoC_DW.Memory_PreviousInput = 0.0;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  SoC_DW.Memory_PreviousInput_p = 0.0;

  /* SystemInitialize for Iterator SubSystem: '<S2>/3RC1' */
  SoC_uRC1_Init(1, SoC_DW.uRC1);

  /* End of SystemInitialize for SubSystem: '<S2>/3RC1' */

  /* SystemInitialize for Iterator SubSystem: '<S3>/3RC1' */
  SoC_uRC1_Init(1, SoC_DW.uRC1_p);

  /* End of SystemInitialize for SubSystem: '<S3>/3RC1' */
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
    SoC_M->Timing.sampleTimes[0] = (280.0);

    /* task offsets */
    SoC_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(SoC_M, &SoC_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = SoC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    SoC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SoC_M, 14000.0);
  SoC_M->Timing.stepSize0 = 280.0;

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
  SoC_M->Timing.stepSize = (280.0);
  rtsiSetFixedStepSize(&SoC_M->solverInfo, 280.0);
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
  SoC_M->Sizes.numY = (3);             /* Number of model outputs */
  SoC_M->Sizes.numU = (6);             /* Number of model inputs */
  SoC_M->Sizes.sysDirFeedThru = (1);   /* The model is direct feedthrough */
  SoC_M->Sizes.numSampTimes = (1);     /* Number of sample times */
  SoC_M->Sizes.numBlocks = (110);      /* Number of blocks */
  SoC_M->Sizes.numBlockIO = (10);      /* Number of block outputs */
  return SoC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
