/*
 * SoC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 13.18
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sun Sep  1 18:45:04 2024
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
#include "look2_binlxpw.h"
#include "look1_binlxpw.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_SoC_T SoC_B;

/* Continuous states */
X_SoC_T SoC_X;

/* Disabled State Vector */
XDis_SoC_T SoC_XDis;

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
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 60;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SoC_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  SoC_output();
  SoC_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  SoC_output();
  SoC_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for iterator system:
 *    '<Root>/3RC_Cell_H'
 *    '<Root>/3RC_Cell_L'
 */
void SoC_uRC_Cell_H_Init(int32_T NumIters, RT_MODEL_SoC_T * const SoC_M,
  DW_uRC_Cell_H_SoC_T localDW[1], X_uRC_Cell_H_SoC_T localX[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* InitializeConditions for Integrator: '<S12>/Integrator1' */
    if (rtmIsFirstInitCond(SoC_M)) {
      localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[0] = 0.0;
      localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[1] = 0.0;
      localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[2] = 0.0;
      localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[3] = 0.0;
    }

    localDW[ForEach_itr].CoreSubsys.Integrator1_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S12>/Integrator1' */

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    memcpy(&localX[ForEach_itr].CoreSubsys.Integrator_CSTATE[0],
           &rtCP_Integrator_IC_o[0], sizeof(real_T) << 4U);
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
    /* Start for SignalConversion generated from: '<S12>/Integrator1' */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtIntegrator[0] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtIntegrator[1] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtIntegrator[2] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtIntegrator[3] = 0.0;

    /* Start for Sum: '<S11>/Sum2' */
    localB[ForEach_itr].CoreSubsys.Sum2 = 0.0;

    /* Start for Sum: '<S12>/Sum' */
    memset(&localB[ForEach_itr].CoreSubsys.Pdot[0], 0, sizeof(real_T) << 4U);

    /* Start for Sum: '<S12>/Sum2' */
    localB[ForEach_itr].CoreSubsys.Sum2_h[0] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum2_h[1] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum2_h[2] = 0.0;
    localB[ForEach_itr].CoreSubsys.Sum2_h[3] = 0.0;
    localDW[ForEach_itr].CoreSubsys.Divide_DWORK4 = 0.0;
  }
}

/*
 * Outputs for iterator system:
 *    '<Root>/3RC_Cell_H'
 *    '<Root>/3RC_Cell_L'
 */
void SoC_uRC_Cell_H(int32_T NumIters, RT_MODEL_SoC_T * const SoC_M, const real_T
                    *rtu_Current, const real_T *rtu_CellVoltage, const real_T
                    *rtu_CellTemperature, const real_T *rtu_InitialSOC, real_T
                    *rty_SOC, B_uRC_Cell_H_SoC_T localB[1], const
                    ConstB_uRC_Cell_H_SoC_T *localC, DW_uRC_Cell_H_SoC_T
                    localDW[1], X_uRC_Cell_H_SoC_T localX[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_Product4_g[16];
  real_T rtb_Product4_k[16];
  real_T tmp[16];
  real_T rtb_Product5_o[4];
  real_T rtb_Product6_df[4];
  real_T rtb_Transpose1_f[4];
  real_T rtb_Transpose1_j[4];
  real_T rtb_Add1_d;
  real_T rtb_Add1_j;
  real_T rtb_Divide5_b;
  real_T rtb_Divide5_bc;
  real_T rtb_Divide5_e;
  real_T rtb_ImpSel_InsertedFor_CellVolt;
  real_T rtb_Product5_j;
  real_T rtb_Product6_p;
  real_T rtb_Sum_k;
  real_T rtb_Transpose1_f_0;
  real_T rtb_Transpose1_f_1;
  int32_T i;
  int32_T i_0;
  int32_T rtb_Product5_j_tmp;
  int32_T rtb_Product5_j_tmp_tmp;

  /* Outputs for Iterator SubSystem: '<Root>/3RC_Cell_H' incorporates:
   *  ForEach: '<S2>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* ForEachSliceSelector generated from: '<S2>/CellVoltage' */
    rtb_ImpSel_InsertedFor_CellVolt = rtu_CellVoltage[ForEach_itr];

    /* SignalConversion generated from: '<S12>/Integrator1' incorporates:
     *  Constant: '<S12>/Constant3'
     *  Gain: '<S2>/Gain1'
     */
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtIntegrator[0] = 0.01 *
      rtu_InitialSOC[ForEach_itr];
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtIntegrator[1] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtIntegrator[2] = 0.0;
    localB[ForEach_itr].CoreSubsys.TmpSignalConversionAtIntegrator[3] = 0.0;

    /* Integrator: '<S12>/Integrator1' */
    if (localDW[ForEach_itr].CoreSubsys.Integrator1_IWORK != 0) {
      localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[0] = localB[ForEach_itr]
        .CoreSubsys.TmpSignalConversionAtIntegrator[0];
      localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[1] = 0.0;
      localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[2] = 0.0;
      localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[3] = 0.0;
    }

    /* Sum: '<S11>/Sum2' incorporates:
     *  Gain: '<S2>/Gain'
     *  Integrator: '<S12>/Integrator1'
     *  Lookup_n-D: '<S11>/2-D Lookup Table OCV'
     *  Lookup_n-D: '<S11>/2-D Lookup Table R0'
     *  Product: '<S11>/Product6'
     *  Sum: '<S11>/Sum of Elements'
     */
    localB[ForEach_itr].CoreSubsys.Sum2 = (look2_binlxpw(localX[ForEach_itr].
      CoreSubsys.Integrator1_CSTATE[0], rtu_CellTemperature[ForEach_itr],
      rtCP_uDLookupTableOCV_bp01Data_, rtCP_uDLookupTableOCV_bp02Data_,
      rtCP_uDLookupTableOCV_tableDa_c, rtCP_uDLookupTableOCV_maxIndex_, 21U) -
      look2_binlxpw(localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[0],
                    rtu_CellTemperature[ForEach_itr],
                    rtCP_uDLookupTableR0_bp01Data_e,
                    rtCP_uDLookupTableR0_bp02Data_l,
                    rtCP_uDLookupTableR0_tableData_,
                    rtCP_uDLookupTableR0_maxIndex_g, 21U) *
      -rtu_Current[ForEach_itr]) - ((localX[ForEach_itr].
      CoreSubsys.Integrator1_CSTATE[1] + localX[ForEach_itr].
      CoreSubsys.Integrator1_CSTATE[2]) + localX[ForEach_itr].
      CoreSubsys.Integrator1_CSTATE[3]);
    if (rtmIsMajorTimeStep(SoC_M)) {
    }

    /* Lookup_n-D: '<S13>/Lookup C1' incorporates:
     *  Integrator: '<S12>/Integrator1'
     */
    rtb_Product6_p = look2_binlxpw(localX[ForEach_itr].
      CoreSubsys.Integrator1_CSTATE[0], rtu_CellTemperature[ForEach_itr],
      rtCP_LookupC1_bp01Data_i, rtCP_LookupC1_bp02Data_l,
      rtCP_LookupC1_tableData_c, rtCP_LookupC1_maxIndex_c, 21U);

    /* Product: '<S13>/Divide5' incorporates:
     *  Gain: '<S2>/Gain'
     */
    rtb_Divide5_bc = -rtu_Current[ForEach_itr] / rtb_Product6_p;

    /* Product: '<S13>/Product' incorporates:
     *  Integrator: '<S12>/Integrator1'
     *  Lookup_n-D: '<S13>/Lookup R1'
     */
    rtb_Add1_j = look2_binlxpw(localX[ForEach_itr]
      .CoreSubsys.Integrator1_CSTATE[0], rtu_CellTemperature[ForEach_itr],
      rtCP_LookupR1_bp01Data_l, rtCP_LookupR1_bp02Data_f,
      rtCP_LookupR1_tableData_p, rtCP_LookupR1_maxIndex_l, 21U) * rtb_Product6_p;

    /* Product: '<S13>/Divide1' incorporates:
     *  Integrator: '<S12>/Integrator1'
     */
    rtb_Product6_p = localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[1] /
      rtb_Add1_j;

    /* SignalConversion generated from: '<S13>/Assignment' incorporates:
     *  Product: '<S12>/Product4'
     */
    memset(&rtb_Product4_k[0], 0, sizeof(real_T) << 4U);

    /* Product: '<S13>/Divide' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rtb_Product4_k[5] = -1.0 / rtb_Add1_j;

    /* Lookup_n-D: '<S14>/Lookup C2' incorporates:
     *  Integrator: '<S12>/Integrator1'
     */
    rtb_Add1_j = look2_binlxpw(localX[ForEach_itr]
      .CoreSubsys.Integrator1_CSTATE[0], rtu_CellTemperature[ForEach_itr],
      rtCP_LookupC2_bp01Data_p, rtCP_LookupC2_bp02Data_e,
      rtCP_LookupC2_tableData_d, rtCP_LookupC2_maxIndex_f, 21U);

    /* Product: '<S14>/Divide5' incorporates:
     *  Gain: '<S2>/Gain'
     */
    rtb_Divide5_b = -rtu_Current[ForEach_itr] / rtb_Add1_j;

    /* Product: '<S14>/Product' incorporates:
     *  Integrator: '<S12>/Integrator1'
     *  Lookup_n-D: '<S14>/Lookup R2'
     */
    rtb_Add1_d = look2_binlxpw(localX[ForEach_itr]
      .CoreSubsys.Integrator1_CSTATE[0], rtu_CellTemperature[ForEach_itr],
      rtCP_LookupR2_bp01Data_h, rtCP_LookupR2_bp02Data_e,
      rtCP_LookupR2_tableData_d, rtCP_LookupR2_maxIndex_l, 21U) * rtb_Add1_j;

    /* Product: '<S14>/Divide1' incorporates:
     *  Integrator: '<S12>/Integrator1'
     */
    rtb_Add1_j = localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[2] /
      rtb_Add1_d;

    /* Product: '<S14>/Divide' incorporates:
     *  Constant: '<S14>/Constant'
     */
    rtb_Product4_k[10] = -1.0 / rtb_Add1_d;

    /* Lookup_n-D: '<S15>/Lookup C3' incorporates:
     *  Integrator: '<S12>/Integrator1'
     */
    rtb_Add1_d = look2_binlxpw(localX[ForEach_itr]
      .CoreSubsys.Integrator1_CSTATE[0], rtu_CellTemperature[ForEach_itr],
      rtCP_LookupC3_bp01Data_d, rtCP_LookupC3_bp02Data_h,
      rtCP_LookupC3_tableData_a, rtCP_LookupC3_maxIndex_c, 21U);

    /* Product: '<S15>/Divide5' incorporates:
     *  Gain: '<S2>/Gain'
     */
    rtb_Divide5_e = -rtu_Current[ForEach_itr] / rtb_Add1_d;

    /* Product: '<S15>/Product' incorporates:
     *  Integrator: '<S12>/Integrator1'
     *  Lookup_n-D: '<S15>/Lookup R3'
     */
    rtb_Sum_k = look2_binlxpw(localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE
      [0], rtu_CellTemperature[ForEach_itr], rtCP_LookupR3_bp01Data_a,
      rtCP_LookupR3_bp02Data_p, rtCP_LookupR3_tableData_h,
      rtCP_LookupR3_maxIndex_l, 21U) * rtb_Add1_d;

    /* Product: '<S15>/Divide1' incorporates:
     *  Integrator: '<S12>/Integrator1'
     */
    rtb_Add1_d = localX[ForEach_itr].CoreSubsys.Integrator1_CSTATE[3] /
      rtb_Sum_k;

    /* Product: '<S15>/Divide' incorporates:
     *  Constant: '<S15>/Constant'
     */
    rtb_Product4_k[15] = -1.0 / rtb_Sum_k;

    /* SignalConversion generated from: '<S11>/Transpose1' incorporates:
     *  Constant: '<S11>/Constant4'
     *  Integrator: '<S12>/Integrator1'
     *  Lookup_n-D: '<S11>/2-D Lookup Table OCV1'
     */
    rtb_Transpose1_j[0] = look2_binlxpw(localX[ForEach_itr].
      CoreSubsys.Integrator1_CSTATE[0], rtu_CellTemperature[ForEach_itr],
      rtCP_uDLookupTableOCV1_bp01Da_l, rtCP_uDLookupTableOCV1_bp02Da_l,
      rtCP_uDLookupTableOCV1_tableD_j, rtCP_uDLookupTableOCV1_maxInd_h, 21U);
    rtb_Transpose1_j[1] = -1.0;
    rtb_Transpose1_j[2] = -1.0;
    rtb_Transpose1_j[3] = -1.0;

    /* Sum: '<S10>/Sum' */
    rtb_Sum_k = rtb_ImpSel_InsertedFor_CellVolt - localB[ForEach_itr].
      CoreSubsys.Sum2;
    for (i = 0; i < 4; i++) {
      /* Product: '<S12>/Product5' */
      rtb_ImpSel_InsertedFor_CellVolt = 0.0;

      /* Product: '<S12>/Product4' */
      rtb_Transpose1_f_1 = 0.0;
      for (i_0 = 0; i_0 < 4; i_0++) {
        /* Math: '<S12>/Transpose1' incorporates:
         *  Math: '<S11>/Transpose1'
         *  Product: '<S12>/Product5'
         */
        rtb_Transpose1_f_0 = rtb_Transpose1_j[i_0];

        /* Product: '<S12>/Product5' incorporates:
         *  Integrator: '<S12>/Integrator'
         *  Math: '<S11>/Transpose1'
         *  Math: '<S12>/Transpose1'
         *  Product: '<S12>/Divide'
         *  Product: '<S12>/Product'
         *  Product: '<S12>/Product3'
         */
        rtb_Product5_j_tmp_tmp = i_0 << 2;
        rtb_Product5_j_tmp = rtb_Product5_j_tmp_tmp + i;
        rtb_ImpSel_InsertedFor_CellVolt += rtb_Transpose1_f_0 *
          localC->CoreSubsys.Divide * localX[ForEach_itr].
          CoreSubsys.Integrator_CSTATE[rtb_Product5_j_tmp];

        /* Product: '<S12>/Product3' incorporates:
         *  Integrator: '<S12>/Integrator'
         *  Math: '<S12>/Transpose'
         *  Product: '<S12>/Product4'
         */
        tmp[rtb_Product5_j_tmp] = ((localX[ForEach_itr].
          CoreSubsys.Integrator_CSTATE[i + 4] * rtb_Product4_k[i_0 + 4] +
          localX[ForEach_itr].CoreSubsys.Integrator_CSTATE[i] *
          rtb_Product4_k[i_0]) + localX[ForEach_itr].
          CoreSubsys.Integrator_CSTATE[i + 8] * rtb_Product4_k[i_0 + 8]) +
          localX[ForEach_itr].CoreSubsys.Integrator_CSTATE[i + 12] *
          rtb_Product4_k[i_0 + 12];

        /* Product: '<S12>/Product' incorporates:
         *  Integrator: '<S12>/Integrator'
         *  Product: '<S12>/Product4'
         */
        rtb_Product4_g[rtb_Product5_j_tmp] = ((localX[ForEach_itr].
          CoreSubsys.Integrator_CSTATE[rtb_Product5_j_tmp_tmp + 1] *
          rtb_Product4_k[i + 4] + localX[ForEach_itr].
          CoreSubsys.Integrator_CSTATE[rtb_Product5_j_tmp_tmp] *
          rtb_Product4_k[i]) + localX[ForEach_itr]
          .CoreSubsys.Integrator_CSTATE[rtb_Product5_j_tmp_tmp + 2] *
          rtb_Product4_k[i + 8]) + localX[ForEach_itr].
          CoreSubsys.Integrator_CSTATE[rtb_Product5_j_tmp_tmp + 3] *
          rtb_Product4_k[i + 12];

        /* Product: '<S12>/Product4' incorporates:
         *  Integrator: '<S12>/Integrator'
         *  Math: '<S11>/Transpose1'
         */
        rtb_Transpose1_f_1 += localX[ForEach_itr].CoreSubsys.Integrator_CSTATE
          [(i << 2) + i_0] * rtb_Transpose1_f_0;
      }

      /* Product: '<S12>/Product4' */
      rtb_Transpose1_f[i] = rtb_Transpose1_f_1;

      /* Product: '<S12>/Product5' */
      rtb_Product5_o[i] = rtb_ImpSel_InsertedFor_CellVolt;

      /* Product: '<S12>/Product6' incorporates:
       *  Product: '<S12>/Product5'
       */
      rtb_Product6_df[i] = rtb_ImpSel_InsertedFor_CellVolt * rtb_Sum_k;
    }

    /* Product: '<S12>/Product4' */
    rtb_ImpSel_InsertedFor_CellVolt = rtb_Product5_o[0];
    rtb_Sum_k = rtb_Product5_o[1];
    rtb_Transpose1_f_0 = rtb_Product5_o[2];
    rtb_Product5_j = rtb_Product5_o[3];
    for (i_0 = 0; i_0 < 4; i_0++) {
      /* Product: '<S12>/Product4' */
      rtb_Transpose1_f_1 = rtb_Transpose1_f[i_0];

      /* Sum: '<S12>/Sum' incorporates:
       *  Constant: '<S12>/Constant'
       *  Product: '<S12>/Product4'
       */
      i = i_0 << 2;

      /* Sum: '<S12>/Sum' incorporates:
       *  Constant: '<S12>/Constant'
       *  Product: '<S12>/Product4'
       */
      localB[ForEach_itr].CoreSubsys.Pdot[i] = ((rtb_Product4_g[i] + tmp[i]) -
        rtb_ImpSel_InsertedFor_CellVolt * rtb_Transpose1_f_1) +
        rtCP_Constant_Value_nc[i];
      localB[ForEach_itr].CoreSubsys.Pdot[i + 1] = ((rtb_Product4_g[i + 1] +
        tmp[i + 1]) - rtb_Sum_k * rtb_Transpose1_f_1) + rtCP_Constant_Value_nc[i
        + 1];
      localB[ForEach_itr].CoreSubsys.Pdot[i + 2] = ((rtb_Product4_g[i + 2] +
        tmp[i + 2]) - rtb_Transpose1_f_0 * rtb_Transpose1_f_1) +
        rtCP_Constant_Value_nc[i + 2];
      localB[ForEach_itr].CoreSubsys.Pdot[i + 3] = ((rtb_Product4_g[i + 3] +
        tmp[i + 3]) - rtb_Product5_j * rtb_Transpose1_f_1) +
        rtCP_Constant_Value_nc[i + 3];
    }

    /* Sum: '<S12>/Sum2' incorporates:
     *  Gain: '<S11>/Gain'
     *  Gain: '<S2>/Gain'
     *  Lookup_n-D: '<S11>/Capacity'
     *  Product: '<S11>/Product7'
     *  Sum: '<S13>/Add1'
     *  Sum: '<S14>/Add1'
     *  Sum: '<S15>/Add1'
     */
    localB[ForEach_itr].CoreSubsys.Sum2_h[0] = -0.00027777777777777778 *
      -rtu_Current[ForEach_itr] / look1_binlxpw(rtu_CellTemperature[ForEach_itr],
      rtCP_Capacity_bp01Data_f, rtCP_Capacity_tableData_b, 9U) +
      rtb_Product6_df[0];
    localB[ForEach_itr].CoreSubsys.Sum2_h[1] = (rtb_Divide5_bc - rtb_Product6_p)
      + rtb_Product6_df[1];
    localB[ForEach_itr].CoreSubsys.Sum2_h[2] = (rtb_Divide5_b - rtb_Add1_j) +
      rtb_Product6_df[2];
    localB[ForEach_itr].CoreSubsys.Sum2_h[3] = (rtb_Divide5_e - rtb_Add1_d) +
      rtb_Product6_df[3];

    /* ForEachSliceAssignment generated from: '<S2>/SOC' incorporates:
     *  Gain: '<S2>/Gain2'
     *  Integrator: '<S12>/Integrator1'
     */
    rty_SOC[ForEach_itr] = 100.0 * localX[ForEach_itr].
      CoreSubsys.Integrator1_CSTATE[0];
  }

  /* End of Outputs for SubSystem: '<Root>/3RC_Cell_H' */
}

/*
 * Update for iterator system:
 *    '<Root>/3RC_Cell_H'
 *    '<Root>/3RC_Cell_L'
 */
void SoC_uRC_Cell_H_Update(int32_T NumIters, DW_uRC_Cell_H_SoC_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Update for Integrator: '<S12>/Integrator1' */
    localDW[ForEach_itr].CoreSubsys.Integrator1_IWORK = 0;
  }
}

/*
 * Derivatives for iterator system:
 *    '<Root>/3RC_Cell_H'
 *    '<Root>/3RC_Cell_L'
 */
void SoC_uRC_Cell_H_Deriv(int32_T NumIters, B_uRC_Cell_H_SoC_T localB[1],
  XDot_uRC_Cell_H_SoC_T localXdot[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Derivatives for Integrator: '<S12>/Integrator1' */
    localXdot[ForEach_itr].CoreSubsys.Integrator1_CSTATE[0] = localB[ForEach_itr]
      .CoreSubsys.Sum2_h[0];
    localXdot[ForEach_itr].CoreSubsys.Integrator1_CSTATE[1] = localB[ForEach_itr]
      .CoreSubsys.Sum2_h[1];
    localXdot[ForEach_itr].CoreSubsys.Integrator1_CSTATE[2] = localB[ForEach_itr]
      .CoreSubsys.Sum2_h[2];
    localXdot[ForEach_itr].CoreSubsys.Integrator1_CSTATE[3] = localB[ForEach_itr]
      .CoreSubsys.Sum2_h[3];

    /* Derivatives for Integrator: '<S12>/Integrator' incorporates:
     *  Sum: '<S12>/Sum'
     */
    memcpy(&localXdot[ForEach_itr].CoreSubsys.Integrator_CSTATE[0],
           &localB[ForEach_itr].CoreSubsys.Pdot[0], sizeof(real_T) << 4U);
  }
}

/* Model output function */
void SoC_output(void)
{
  /* local block i/o variables */
  real_T rtb_ImpAsg_InsertedFor_SOC_at_i;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_o;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_Product4[16];
  real_T rtb_Product4_0[16];
  real_T tmp[16];
  real_T rtb_Product5[4];
  real_T rtb_Product6_d[4];
  real_T rtb_Transpose1[4];
  real_T rtb_Transpose1_0[4];
  real_T rtb_Add1_cd;
  real_T rtb_Divide5;
  real_T rtb_Divide5_d;
  real_T rtb_Divide5_g;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_p;
  real_T rtb_Product5_0;
  real_T rtb_Product5_1;
  real_T rtb_Saturation;
  real_T rtb_Saturation2;
  real_T rtb_Sum;
  real_T rtb_Transpose1_1;
  real_T rtb_Transpose1_2;
  int32_T i;
  int32_T i_0;
  int32_T rtb_Product5_tmp;
  int32_T rtb_Product5_tmp_tmp;
  if (rtmIsMajorTimeStep(SoC_M)) {
    /* set solver stop time */
    if (!(SoC_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&SoC_M->solverInfo, ((SoC_M->Timing.clockTickH0 + 1)
        * SoC_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&SoC_M->solverInfo, ((SoC_M->Timing.clockTick0 + 1) *
        SoC_M->Timing.stepSize0 + SoC_M->Timing.clockTickH0 *
        SoC_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SoC_M)) {
    SoC_M->Timing.t[0] = rtsiGetT(&SoC_M->solverInfo);
  }

  /* Lookup_n-D: '<Root>/Cell OCV to SOC 2024' incorporates:
   *  Inport: '<Root>/Lowest_CellVoltage'
   */
  SoC_B.CellOCVtoSOC2024 = look1_binlxpw(SoC_U.Lowest_CellVoltage,
    rtCP_CellOCVtoSOC2024_bp01Data, rtCP_CellOCVtoSOC2024_tableData, 599U);

  /* Outputs for Iterator SubSystem: '<Root>/3RC_Cell_L' */
  /* Inport: '<Root>/Accumulator_Current' incorporates:
   *  Inport: '<Root>/Average_CellTemp'
   *  Inport: '<Root>/Lowest_CellVoltage'
   */
  SoC_uRC_Cell_H(1, SoC_M, &SoC_U.Accumulator_Current, &SoC_U.Lowest_CellVoltage,
                 &SoC_U.Average_CellTemp, &SoC_B.CellOCVtoSOC2024,
                 &rtb_ImpAsg_InsertedFor_SOC_at_i, SoC_B.uRC_Cell_L,
                 &SoC_ConstB.uRC_Cell_L, SoC_DW.uRC_Cell_L, SoC_X.uRC_Cell_L);

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

  /* Outputs for Iterator SubSystem: '<Root>/3RC_Accu' incorporates:
   *  ForEach: '<S1>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* SignalConversion generated from: '<S6>/Integrator1' incorporates:
     *  Constant: '<S6>/Constant3'
     *  ForEachSliceSelector generated from: '<S1>/InitialSOC'
     */
    SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[0] =
      SoC_B.AccuOCVtoSOC2024;
    SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[1] = 0.0;
    SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[2] = 0.0;
    SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[3] = 0.0;

    /* Integrator: '<S6>/Integrator1' */
    if (SoC_DW.CoreSubsys[ForEach_itr].Integrator1_IWORK != 0) {
      SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[0] =
        SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[0];
      SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[1] = 0.0;
      SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[2] = 0.0;
      SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[3] = 0.0;
    }

    /* Lookup_n-D: '<S7>/Lookup C1' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     *  Integrator: '<S6>/Integrator1'
     */
    rtb_ImpAsg_InsertedFor_SOC_at_p = look2_binlxpw(SoC_X.CoreSubsys[ForEach_itr]
      .Integrator1_CSTATE_g[0], SoC_U.Average_CellTemp, rtCP_LookupC1_bp01Data,
      rtCP_LookupC1_bp02Data, rtCP_LookupC1_tableData, rtCP_LookupC1_maxIndex,
      21U);

    /* Product: '<S7>/Divide5' incorporates:
     *  Gain: '<S1>/Gain'
     *  Inport: '<Root>/Accumulator_Current'
     */
    rtb_Divide5 = -SoC_U.Accumulator_Current / rtb_ImpAsg_InsertedFor_SOC_at_p;

    /* Product: '<S7>/Product' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     *  Integrator: '<S6>/Integrator1'
     *  Lookup_n-D: '<S7>/Lookup R1'
     */
    rtb_Saturation2 = look2_binlxpw(SoC_X.CoreSubsys[ForEach_itr].
      Integrator1_CSTATE_g[0], SoC_U.Average_CellTemp, rtCP_LookupR1_bp01Data,
      rtCP_LookupR1_bp02Data, rtCP_LookupR1_tableData, rtCP_LookupR1_maxIndex,
      21U) * rtb_ImpAsg_InsertedFor_SOC_at_p;

    /* Product: '<S7>/Divide1' incorporates:
     *  Integrator: '<S6>/Integrator1'
     */
    rtb_ImpAsg_InsertedFor_SOC_at_p = SoC_X.CoreSubsys[ForEach_itr].
      Integrator1_CSTATE_g[1] / rtb_Saturation2;

    /* SignalConversion generated from: '<S7>/Assignment' incorporates:
     *  Product: '<S6>/Product4'
     */
    memset(&rtb_Product4[0], 0, sizeof(real_T) << 4U);

    /* Product: '<S7>/Divide' incorporates:
     *  Constant: '<S7>/Constant'
     */
    rtb_Product4[5] = -1.0 / rtb_Saturation2;

    /* Lookup_n-D: '<S8>/Lookup C2' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     *  Integrator: '<S6>/Integrator1'
     */
    rtb_Saturation2 = look2_binlxpw(SoC_X.CoreSubsys[ForEach_itr].
      Integrator1_CSTATE_g[0], SoC_U.Average_CellTemp, rtCP_LookupC2_bp01Data,
      rtCP_LookupC2_bp02Data, rtCP_LookupC2_tableData, rtCP_LookupC2_maxIndex,
      21U);

    /* Product: '<S8>/Divide5' incorporates:
     *  Gain: '<S1>/Gain'
     *  Inport: '<Root>/Accumulator_Current'
     */
    rtb_Divide5_g = -SoC_U.Accumulator_Current / rtb_Saturation2;

    /* Product: '<S8>/Product' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     *  Integrator: '<S6>/Integrator1'
     *  Lookup_n-D: '<S8>/Lookup R2'
     */
    rtb_Add1_cd = look2_binlxpw(SoC_X.CoreSubsys[ForEach_itr].
      Integrator1_CSTATE_g[0], SoC_U.Average_CellTemp, rtCP_LookupR2_bp01Data,
      rtCP_LookupR2_bp02Data, rtCP_LookupR2_tableData, rtCP_LookupR2_maxIndex,
      21U) * rtb_Saturation2;

    /* Product: '<S8>/Divide1' incorporates:
     *  Integrator: '<S6>/Integrator1'
     */
    rtb_Saturation2 = SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[2] /
      rtb_Add1_cd;

    /* Product: '<S8>/Divide' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Product4[10] = -1.0 / rtb_Add1_cd;

    /* Lookup_n-D: '<S9>/Lookup C3' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     *  Integrator: '<S6>/Integrator1'
     */
    rtb_Add1_cd = look2_binlxpw(SoC_X.CoreSubsys[ForEach_itr].
      Integrator1_CSTATE_g[0], SoC_U.Average_CellTemp, rtCP_LookupC3_bp01Data,
      rtCP_LookupC3_bp02Data, rtCP_LookupC3_tableData, rtCP_LookupC3_maxIndex,
      21U);

    /* Product: '<S9>/Divide5' incorporates:
     *  Gain: '<S1>/Gain'
     *  Inport: '<Root>/Accumulator_Current'
     */
    rtb_Divide5_d = -SoC_U.Accumulator_Current / rtb_Add1_cd;

    /* Product: '<S9>/Product' incorporates:
     *  Inport: '<Root>/Average_CellTemp'
     *  Integrator: '<S6>/Integrator1'
     *  Lookup_n-D: '<S9>/Lookup R3'
     */
    rtb_Sum = look2_binlxpw(SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[0],
      SoC_U.Average_CellTemp, rtCP_LookupR3_bp01Data, rtCP_LookupR3_bp02Data,
      rtCP_LookupR3_tableData, rtCP_LookupR3_maxIndex, 21U) * rtb_Add1_cd;

    /* Product: '<S9>/Divide1' incorporates:
     *  Integrator: '<S6>/Integrator1'
     */
    rtb_Add1_cd = SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[3] /
      rtb_Sum;

    /* Product: '<S9>/Divide' incorporates:
     *  Constant: '<S9>/Constant'
     */
    rtb_Product4[15] = -1.0 / rtb_Sum;

    /* SignalConversion generated from: '<S5>/Transpose1' incorporates:
     *  Constant: '<S5>/Constant4'
     *  Inport: '<Root>/Average_CellTemp'
     *  Integrator: '<S6>/Integrator1'
     *  Lookup_n-D: '<S5>/2-D Lookup Table OCV1'
     */
    rtb_Transpose1[0] = look2_binlxpw(SoC_X.CoreSubsys[ForEach_itr].
      Integrator1_CSTATE_g[0], SoC_U.Average_CellTemp,
      rtCP_uDLookupTableOCV1_bp01Data, rtCP_uDLookupTableOCV1_bp02Data,
      rtCP_uDLookupTableOCV1_tableDat, rtCP_uDLookupTableOCV1_maxIndex, 21U);
    rtb_Transpose1[1] = -1.0;
    rtb_Transpose1[2] = -1.0;
    rtb_Transpose1[3] = -1.0;

    /* Sum: '<S4>/Sum' incorporates:
     *  Gain: '<S1>/Gain'
     *  Inport: '<Root>/Accumulator_Current'
     *  Inport: '<Root>/Accumulator_Voltage'
     *  Inport: '<Root>/Average_CellTemp'
     *  Integrator: '<S6>/Integrator1'
     *  Lookup_n-D: '<S5>/2-D Lookup Table OCV'
     *  Lookup_n-D: '<S5>/2-D Lookup Table R0'
     *  Product: '<S5>/Product6'
     *  Sum: '<S5>/Sum of Elements'
     *  Sum: '<S5>/Sum2'
     */
    rtb_Sum = SoC_U.Accumulator_Voltage - ((look2_binlxpw
      (SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[0],
       SoC_U.Average_CellTemp, rtCP_uDLookupTableOCV_bp01Data,
       rtCP_uDLookupTableOCV_bp02Data, rtCP_uDLookupTableOCV_tableData,
       rtCP_uDLookupTableOCV_maxIndex, 21U) - look2_binlxpw
      (SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[0],
       SoC_U.Average_CellTemp, rtCP_uDLookupTableR0_bp01Data,
       rtCP_uDLookupTableR0_bp02Data, rtCP_uDLookupTableR0_tableData,
       rtCP_uDLookupTableR0_maxIndex, 21U) * -SoC_U.Accumulator_Current) -
      ((SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[1] +
        SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[2]) +
       SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[3]));
    for (i = 0; i < 4; i++) {
      /* Product: '<S6>/Product5' */
      rtb_Product5_1 = 0.0;

      /* Product: '<S6>/Product4' */
      rtb_Transpose1_2 = 0.0;
      for (i_0 = 0; i_0 < 4; i_0++) {
        /* Math: '<S6>/Transpose1' incorporates:
         *  Math: '<S5>/Transpose1'
         *  Product: '<S6>/Product5'
         */
        rtb_Transpose1_1 = rtb_Transpose1[i_0];

        /* Product: '<S6>/Product5' incorporates:
         *  Integrator: '<S6>/Integrator'
         *  Math: '<S5>/Transpose1'
         *  Math: '<S6>/Transpose1'
         *  Product: '<S6>/Divide'
         *  Product: '<S6>/Product'
         *  Product: '<S6>/Product3'
         */
        rtb_Product5_tmp_tmp = i_0 << 2;
        rtb_Product5_tmp = rtb_Product5_tmp_tmp + i;
        rtb_Product5_1 += rtb_Transpose1_1 * SoC_ConstB.CoreSubsys.Divide *
          SoC_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_k[rtb_Product5_tmp];

        /* Product: '<S6>/Product3' incorporates:
         *  Integrator: '<S6>/Integrator'
         *  Math: '<S6>/Transpose'
         *  Product: '<S6>/Product4'
         */
        tmp[rtb_Product5_tmp] = ((SoC_X.CoreSubsys[ForEach_itr].
          Integrator_CSTATE_k[i + 4] * rtb_Product4[i_0 + 4] +
          SoC_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_k[i] *
          rtb_Product4[i_0]) + SoC_X.CoreSubsys[ForEach_itr]
          .Integrator_CSTATE_k[i + 8] * rtb_Product4[i_0 + 8]) +
          SoC_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_k[i + 12] *
          rtb_Product4[i_0 + 12];

        /* Product: '<S6>/Product' incorporates:
         *  Integrator: '<S6>/Integrator'
         *  Product: '<S6>/Product4'
         */
        rtb_Product4_0[rtb_Product5_tmp] = ((SoC_X.CoreSubsys[ForEach_itr].
          Integrator_CSTATE_k[rtb_Product5_tmp_tmp + 1] * rtb_Product4[i + 4] +
          SoC_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_k[rtb_Product5_tmp_tmp]
          * rtb_Product4[i]) + SoC_X.CoreSubsys[ForEach_itr]
          .Integrator_CSTATE_k[rtb_Product5_tmp_tmp + 2] * rtb_Product4[i + 8])
          + SoC_X.CoreSubsys[ForEach_itr]
          .Integrator_CSTATE_k[rtb_Product5_tmp_tmp + 3] * rtb_Product4[i + 12];

        /* Product: '<S6>/Product4' incorporates:
         *  Integrator: '<S6>/Integrator'
         *  Math: '<S5>/Transpose1'
         */
        rtb_Transpose1_2 += SoC_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_k[(i
          << 2) + i_0] * rtb_Transpose1_1;
      }

      /* Product: '<S6>/Product4' */
      rtb_Transpose1_0[i] = rtb_Transpose1_2;

      /* Product: '<S6>/Product5' */
      rtb_Product5[i] = rtb_Product5_1;

      /* Product: '<S6>/Product6' incorporates:
       *  Product: '<S6>/Product5'
       */
      rtb_Product6_d[i] = rtb_Product5_1 * rtb_Sum;
    }

    /* Product: '<S6>/Product4' */
    rtb_Product5_1 = rtb_Product5[0];
    rtb_Sum = rtb_Product5[1];
    rtb_Transpose1_1 = rtb_Product5[2];
    rtb_Product5_0 = rtb_Product5[3];
    for (i_0 = 0; i_0 < 4; i_0++) {
      /* Product: '<S6>/Product4' */
      rtb_Transpose1_2 = rtb_Transpose1_0[i_0];

      /* Sum: '<S6>/Sum' incorporates:
       *  Constant: '<S6>/Constant'
       *  Product: '<S6>/Product4'
       */
      i = i_0 << 2;

      /* Sum: '<S6>/Sum' incorporates:
       *  Constant: '<S6>/Constant'
       *  Product: '<S6>/Product4'
       */
      SoC_B.CoreSubsys[ForEach_itr].Pdot[i] = ((rtb_Product4_0[i] + tmp[i]) -
        rtb_Product5_1 * rtb_Transpose1_2) + rtCP_Constant_Value_b[i];
      SoC_B.CoreSubsys[ForEach_itr].Pdot[i + 1] = ((rtb_Product4_0[i + 1] +
        tmp[i + 1]) - rtb_Sum * rtb_Transpose1_2) + rtCP_Constant_Value_b[i + 1];
      SoC_B.CoreSubsys[ForEach_itr].Pdot[i + 2] = ((rtb_Product4_0[i + 2] +
        tmp[i + 2]) - rtb_Transpose1_1 * rtb_Transpose1_2) +
        rtCP_Constant_Value_b[i + 2];
      SoC_B.CoreSubsys[ForEach_itr].Pdot[i + 3] = ((rtb_Product4_0[i + 3] +
        tmp[i + 3]) - rtb_Product5_0 * rtb_Transpose1_2) +
        rtCP_Constant_Value_b[i + 3];
    }

    /* Sum: '<S6>/Sum2' incorporates:
     *  Gain: '<S1>/Gain'
     *  Gain: '<S5>/Gain'
     *  Inport: '<Root>/Accumulator_Current'
     *  Inport: '<Root>/Average_CellTemp'
     *  Lookup_n-D: '<S5>/Capacity'
     *  Product: '<S5>/Product7'
     *  Sum: '<S7>/Add1'
     *  Sum: '<S8>/Add1'
     *  Sum: '<S9>/Add1'
     */
    SoC_B.CoreSubsys[ForEach_itr].Sum2[0] = -0.00027777777777777778 *
      -SoC_U.Accumulator_Current / look1_binlxpw(SoC_U.Average_CellTemp,
      rtCP_Capacity_bp01Data, rtCP_Capacity_tableData, 9U) + rtb_Product6_d[0];
    SoC_B.CoreSubsys[ForEach_itr].Sum2[1] = (rtb_Divide5 -
      rtb_ImpAsg_InsertedFor_SOC_at_p) + rtb_Product6_d[1];
    SoC_B.CoreSubsys[ForEach_itr].Sum2[2] = (rtb_Divide5_g - rtb_Saturation2) +
      rtb_Product6_d[2];
    SoC_B.CoreSubsys[ForEach_itr].Sum2[3] = (rtb_Divide5_d - rtb_Add1_cd) +
      rtb_Product6_d[3];

    /* ForEachSliceAssignment generated from: '<S1>/SOC' incorporates:
     *  Integrator: '<S6>/Integrator1'
     */
    rtb_ImpAsg_InsertedFor_SOC_at_p = SoC_X.CoreSubsys[ForEach_itr].
      Integrator1_CSTATE_g[0];
  }

  /* End of Outputs for SubSystem: '<Root>/3RC_Accu' */

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

  /* Lookup_n-D: '<Root>/Cell OCV to SOC 1' incorporates:
   *  Inport: '<Root>/Highest_CellVoltage'
   */
  SoC_B.CellOCVtoSOC1 = look1_binlxpw(SoC_U.Highest_CellVoltage,
    rtCP_CellOCVtoSOC1_bp01Data, rtCP_CellOCVtoSOC1_tableData, 599U);

  /* Outputs for Iterator SubSystem: '<Root>/3RC_Cell_H' */
  /* Inport: '<Root>/Accumulator_Current' incorporates:
   *  Inport: '<Root>/Average_CellTemp'
   *  Inport: '<Root>/Highest_CellVoltage'
   */
  SoC_uRC_Cell_H(1, SoC_M, &SoC_U.Accumulator_Current,
                 &SoC_U.Highest_CellVoltage, &SoC_U.Average_CellTemp,
                 &SoC_B.CellOCVtoSOC1, &rtb_ImpAsg_InsertedFor_SOC_at_o,
                 SoC_B.uRC_Cell_H, &SoC_ConstB.uRC_Cell_H, SoC_DW.uRC_Cell_H,
                 SoC_X.uRC_Cell_H);

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
void SoC_update(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Update for Iterator SubSystem: '<Root>/3RC_Cell_L' */
  SoC_uRC_Cell_H_Update(1, SoC_DW.uRC_Cell_L);

  /* End of Update for SubSystem: '<Root>/3RC_Cell_L' */

  /* Update for Iterator SubSystem: '<Root>/3RC_Accu' */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* Update for Integrator: '<S6>/Integrator1' */
    SoC_DW.CoreSubsys[ForEach_itr].Integrator1_IWORK = 0;
  }

  /* End of Update for SubSystem: '<Root>/3RC_Accu' */

  /* Update for Iterator SubSystem: '<Root>/3RC_Cell_H' */
  SoC_uRC_Cell_H_Update(1, SoC_DW.uRC_Cell_H);

  /* End of Update for SubSystem: '<Root>/3RC_Cell_H' */
  if (rtmIsMajorTimeStep(SoC_M)) {
    rt_ertODEUpdateContinuousStates(&SoC_M->solverInfo);
  }

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

  SoC_M->Timing.t[0] = rtsiGetSolverStopTime(&SoC_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++SoC_M->Timing.clockTick1)) {
      ++SoC_M->Timing.clockTickH1;
    }

    SoC_M->Timing.t[1] = SoC_M->Timing.clockTick1 * SoC_M->Timing.stepSize1 +
      SoC_M->Timing.clockTickH1 * SoC_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void SoC_derivatives(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  XDot_SoC_T *_rtXdot;
  _rtXdot = ((XDot_SoC_T *) SoC_M->derivs);

  /* Derivatives for Iterator SubSystem: '<Root>/3RC_Cell_L' */
  SoC_uRC_Cell_H_Deriv(1, SoC_B.uRC_Cell_L, _rtXdot->uRC_Cell_L);

  /* End of Derivatives for SubSystem: '<Root>/3RC_Cell_L' */

  /* Derivatives for Iterator SubSystem: '<Root>/3RC_Accu' */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* Derivatives for Integrator: '<S6>/Integrator1' */
    _rtXdot->CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[0] =
      SoC_B.CoreSubsys[ForEach_itr].Sum2[0];
    _rtXdot->CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[1] =
      SoC_B.CoreSubsys[ForEach_itr].Sum2[1];
    _rtXdot->CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[2] =
      SoC_B.CoreSubsys[ForEach_itr].Sum2[2];
    _rtXdot->CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[3] =
      SoC_B.CoreSubsys[ForEach_itr].Sum2[3];

    /* Derivatives for Integrator: '<S6>/Integrator' incorporates:
     *  Sum: '<S6>/Sum'
     */
    memcpy(&_rtXdot->CoreSubsys[ForEach_itr].Integrator_CSTATE_k[0],
           &SoC_B.CoreSubsys[ForEach_itr].Pdot[0], sizeof(real_T) << 4U);
  }

  /* End of Derivatives for SubSystem: '<Root>/3RC_Accu' */

  /* Derivatives for Iterator SubSystem: '<Root>/3RC_Cell_H' */
  SoC_uRC_Cell_H_Deriv(1, SoC_B.uRC_Cell_H, _rtXdot->uRC_Cell_H);

  /* End of Derivatives for SubSystem: '<Root>/3RC_Cell_H' */
}

/* Model initialize function */
void SoC_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;

    /* Start for Iterator SubSystem: '<Root>/3RC_Cell_L' */
    SoC_uRC_Cell_H_Start(1, SoC_B.uRC_Cell_L, SoC_DW.uRC_Cell_L);

    /* End of Start for SubSystem: '<Root>/3RC_Cell_L' */

    /* Start for Iterator SubSystem: '<Root>/3RC_Accu' */
    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      /* Start for SignalConversion generated from: '<S6>/Integrator1' */
      SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[0] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[1] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[2] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].TmpSignalConversionAtIntegrator[3] = 0.0;

      /* Start for Sum: '<S6>/Sum' */
      memset(&SoC_B.CoreSubsys[ForEach_itr].Pdot[0], 0, sizeof(real_T) << 4U);

      /* Start for Sum: '<S6>/Sum2' */
      SoC_B.CoreSubsys[ForEach_itr].Sum2[0] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].Sum2[1] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].Sum2[2] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr].Sum2[3] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr].Divide_DWORK4 = 0.0;
    }

    /* End of Start for SubSystem: '<Root>/3RC_Accu' */

    /* Start for Iterator SubSystem: '<Root>/3RC_Cell_H' */
    SoC_uRC_Cell_H_Start(1, SoC_B.uRC_Cell_H, SoC_DW.uRC_Cell_H);

    /* End of Start for SubSystem: '<Root>/3RC_Cell_H' */
  }

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;

    /* SystemInitialize for Iterator SubSystem: '<Root>/3RC_Cell_L' */
    SoC_uRC_Cell_H_Init(1, SoC_M, SoC_DW.uRC_Cell_L, SoC_X.uRC_Cell_L);

    /* End of SystemInitialize for SubSystem: '<Root>/3RC_Cell_L' */

    /* SystemInitialize for Iterator SubSystem: '<Root>/3RC_Accu' */
    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      /* InitializeConditions for Integrator: '<S6>/Integrator1' */
      if (rtmIsFirstInitCond(SoC_M)) {
        SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[0] = 0.0;
        SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[1] = 0.0;
        SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[2] = 0.0;
        SoC_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_g[3] = 0.0;
      }

      SoC_DW.CoreSubsys[ForEach_itr].Integrator1_IWORK = 1;

      /* End of InitializeConditions for Integrator: '<S6>/Integrator1' */

      /* InitializeConditions for Integrator: '<S6>/Integrator' */
      memcpy(&SoC_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_k[0],
             &rtCP_Integrator_IC[0], sizeof(real_T) << 4U);
    }

    /* End of SystemInitialize for SubSystem: '<Root>/3RC_Accu' */

    /* SystemInitialize for Iterator SubSystem: '<Root>/3RC_Cell_H' */
    SoC_uRC_Cell_H_Init(1, SoC_M, SoC_DW.uRC_Cell_H, SoC_X.uRC_Cell_H);

    /* End of SystemInitialize for SubSystem: '<Root>/3RC_Cell_H' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(SoC_M)) {
      rtmSetFirstInitCond(SoC_M, 0);
    }
  }
}

/* Model terminate function */
void SoC_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

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

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SoC_M->solverInfo, &SoC_M->Timing.simTimeStep);
    rtsiSetTPtr(&SoC_M->solverInfo, &rtmGetTPtr(SoC_M));
    rtsiSetStepSizePtr(&SoC_M->solverInfo, &SoC_M->Timing.stepSize0);
    rtsiSetdXPtr(&SoC_M->solverInfo, &SoC_M->derivs);
    rtsiSetContStatesPtr(&SoC_M->solverInfo, (real_T **) &SoC_M->contStates);
    rtsiSetNumContStatesPtr(&SoC_M->solverInfo, &SoC_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&SoC_M->solverInfo,
      &SoC_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&SoC_M->solverInfo,
      &SoC_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&SoC_M->solverInfo,
      &SoC_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&SoC_M->solverInfo, (boolean_T**)
      &SoC_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&SoC_M->solverInfo, (&rtmGetErrorStatus(SoC_M)));
    rtsiSetRTModelPtr(&SoC_M->solverInfo, SoC_M);
  }

  rtsiSetSimTimeStep(&SoC_M->solverInfo, MAJOR_TIME_STEP);
  SoC_M->intgData.y = SoC_M->odeY;
  SoC_M->intgData.f[0] = SoC_M->odeF[0];
  SoC_M->intgData.f[1] = SoC_M->odeF[1];
  SoC_M->intgData.f[2] = SoC_M->odeF[2];
  SoC_M->contStates = ((real_T *) &SoC_X);
  SoC_M->contStateDisabled = ((boolean_T *) &SoC_XDis);
  SoC_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&SoC_M->solverInfo, (void *)&SoC_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&SoC_M->solverInfo, false);
  rtsiSetSolverName(&SoC_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = SoC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "SoC_M points to
       static memory which is guaranteed to be non-NULL" */
    SoC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SoC_M->Timing.sampleTimes = (&SoC_M->Timing.sampleTimesArray[0]);
    SoC_M->Timing.offsetTimes = (&SoC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SoC_M->Timing.sampleTimes[0] = (0.0);
    SoC_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    SoC_M->Timing.offsetTimes[0] = (0.0);
    SoC_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(SoC_M, &SoC_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = SoC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    SoC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SoC_M, 10.0);
  SoC_M->Timing.stepSize0 = 0.2;
  SoC_M->Timing.stepSize1 = 0.2;
  rtmSetFirstInitCond(SoC_M, 1);

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
  SoC_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&SoC_M->solverInfo, 0.2);
  rtsiSetSolverMode(&SoC_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  SoC_M->blockIO = ((void *) &SoC_B);
  (void) memset(((void *) &SoC_B), 0,
                sizeof(B_SoC_T));

  /* states (continuous) */
  {
    real_T *x = (real_T *) &SoC_X;
    SoC_M->contStates = (x);
    (void) memset((void *)&SoC_X, 0,
                  sizeof(X_SoC_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &SoC_XDis;
    SoC_M->contStateDisabled = (xdis);
    (void) memset((void *)&SoC_XDis, 0,
                  sizeof(XDis_SoC_T));
  }

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
  SoC_M->Sizes.numContStates = (60);   /* Number of continuous states */
  SoC_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  SoC_M->Sizes.numY = (4);             /* Number of model outputs */
  SoC_M->Sizes.numU = (5);             /* Number of model inputs */
  SoC_M->Sizes.sysDirFeedThru = (1);   /* The model is direct feedthrough */
  SoC_M->Sizes.numSampTimes = (2);     /* Number of sample times */
  SoC_M->Sizes.numBlocks = (151);      /* Number of blocks */
  SoC_M->Sizes.numBlockIO = (14);      /* Number of block outputs */
  return SoC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
