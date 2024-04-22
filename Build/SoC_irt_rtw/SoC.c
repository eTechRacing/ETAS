/*
 * SoC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 13.3
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Apr 22 17:11:45 2024
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
#include "qr_AN2ohs8Z.h"
#include "rotate_nRcnRDPx.h"
#include <emmintrin.h>
#include "xnrm2_cFB6ntui.h"
#include "rt_hypotd_snf.h"
#include "look1_binlxpw.h"
#include "look1_pbinlcpw.h"
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
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (SoC_M->Timing.TaskCounters.TID[1])++;
  if ((SoC_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [1.0s, 0.0s] */
    SoC_M->Timing.TaskCounters.TID[1] = 0;
  }

  SoC_M->Timing.sampleHits[1] = (SoC_M->Timing.TaskCounters.TID[1] == 0) ? 1 : 0;
}

/*
 * System initialize for iterator system:
 *    '<S2>/SOC Estimator (Coulomb Counting)'
 *    '<S3>/SOC Estimator (Coulomb Counting)'
 */
void SOCEstimatorCoulombCountin_Init(int32_T NumIters,
  DW_SOCEstimatorCoulombCountin_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* InitializeConditions for DiscreteIntegrator: '<S9>/Integrator' */
    localDW[ForEach_itr].CoreSubsys.Integrator_IC_LOADING = 1U;
  }
}

/*
 * Start for iterator system:
 *    '<S2>/SOC Estimator (Coulomb Counting)'
 *    '<S3>/SOC Estimator (Coulomb Counting)'
 */
void SOCEstimatorCoulombCounti_Start(int32_T NumIters,
  B_SOCEstimatorCoulombCounting_T localB[1], DW_SOCEstimatorCoulombCountin_T
  localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Start for Gain: '<S6>/Gain' */
    localB[ForEach_itr].CoreSubsys.Gain = 0.0;
    localDW[ForEach_itr].CoreSubsys.Integrator_DSTATE = 0.0;
  }
}

/*
 * Outputs for iterator system:
 *    '<S2>/SOC Estimator (Coulomb Counting)'
 *    '<S3>/SOC Estimator (Coulomb Counting)'
 */
void SoC_SOCEstimatorCoulombCounting(int32_T NumIters, RT_MODEL_SoC_T * const
  SoC_M, const real_T *rtu_Current, const real_T *rtu_InitialSOC, real_T
  *rty_SOC, real_T rtp_AH, B_SOCEstimatorCoulombCounting_T localB[1],
  DW_SOCEstimatorCoulombCountin_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Outputs for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' incorporates:
   *  ForEach: '<S6>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S6>/Gain' */
      localB[ForEach_itr].CoreSubsys.Gain = 1.0 / (rtp_AH * 3600.0) *
        rtu_Current[ForEach_itr];

      /* DiscreteIntegrator: '<S9>/Integrator' */
      if (localDW[ForEach_itr].CoreSubsys.Integrator_IC_LOADING != 0) {
        localDW[ForEach_itr].CoreSubsys.Integrator_DSTATE =
          rtu_InitialSOC[ForEach_itr];
      }

      /* ForEachSliceAssignment generated from: '<S6>/SOC' incorporates:
       *  DiscreteIntegrator: '<S9>/Integrator'
       */
      rty_SOC[ForEach_itr] = localDW[ForEach_itr].CoreSubsys.Integrator_DSTATE;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
}

/*
 * Update for iterator system:
 *    '<S2>/SOC Estimator (Coulomb Counting)'
 *    '<S3>/SOC Estimator (Coulomb Counting)'
 */
void SOCEstimatorCoulombCount_Update(int32_T NumIters, RT_MODEL_SoC_T * const
  SoC_M, B_SOCEstimatorCoulombCounting_T localB[1],
  DW_SOCEstimatorCoulombCountin_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for DiscreteIntegrator: '<S9>/Integrator' */
      localDW[ForEach_itr].CoreSubsys.Integrator_IC_LOADING = 0U;
      localDW[ForEach_itr].CoreSubsys.Integrator_DSTATE += localB[ForEach_itr].
        CoreSubsys.Gain;
    }
  }
}

/* Model output function */
static void SoC_output(void)
{
  /* local block i/o variables */
  real_T rtb_Delay[2];
  real_T rtb_ImpAsg_InsertedFor_SOC_at_k;
  real_T rtb_ImpAsg_InsertedFor_SOC_a_ia;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_m;
  int32_T ForEach_itr_l;
  int32_T ForEach_itr_f;
  __m128d tmp_4;
  real_T b[25];
  real_T a__1[12];
  real_T residual_1[12];
  real_T residual[10];
  real_T rtb_ImpAsg_InsertedFor_Wm_ixk1_[10];
  real_T rtb_X1[10];
  real_T A[5];
  real_T residual_0[5];
  real_T rtb_ImpAsg_InsertedFor_Wm_iy_i_[5];
  real_T rtb_ImpAsg_InsertedFor_y_at_inp[5];
  real_T rtb_Y1[5];
  real_T rtb_Gain_b[4];
  real_T rtb_MatrixMultiply[4];
  real_T tmp[4];
  real_T rtb_Add_i[2];
  real_T rtb_Kk1_p[2];
  real_T rtb_SumofElements[2];
  real_T s[2];
  real_T tmp_5[2];
  real_T absxk;
  real_T b_c_idx_0;
  real_T rtb_Gain_i;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_h;
  real_T rtb_Kk1_l;
  real_T rtb_ManualSwitch1;
  real_T rtb_MatrixMultiply_0;
  real_T rtb_Saturation_m;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  int32_T i;
  int32_T iAcol;
  int32_T knt;
  int32_T rtb_X1_tmp;
  boolean_T errorCondition;

  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/Car_State'
   *  Logic: '<S2>/NOT'
   *  Logic: '<S3>/NOT'
   */
  errorCondition = ((!(SoC_U.Car_State >= 12.0)) || (!(SoC_U.Car_State <= 15.0)));

  /* Switch: '<S3>/Switch' incorporates:
   *  Logic: '<S3>/NOT'
   */
  if (errorCondition) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Inport: '<Root>/Lowest_Cell_Voltage'
     *  Lookup_n-D: '<S3>/OCV to SoC'
     */
    SoC_B.Switch = look1_binlxpw(SoC_U.Lowest_Cell_Voltage,
      rtCP_OCVtoSoC_bp01Data_n, rtCP_OCVtoSoC_tableData_k, 25U);
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Memory: '<S3>/Memory'
     */
    SoC_B.Switch = SoC_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Outputs for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
  /* Inport: '<Root>/Accumulator_Current' */
  SoC_SOCEstimatorCoulombCounting(1, SoC_M, &SoC_U.Accumulator_Current,
    &SoC_B.Switch, &rtb_ImpAsg_InsertedFor_SOC_at_k, 13.0,
    SoC_B.SOCEstimatorCoulombCounting_p, SoC_DW.SOCEstimatorCoulombCounting_p);

  /* End of Outputs for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
  if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Saturate: '<S3>/Saturation1' */
    if (rtb_ImpAsg_InsertedFor_SOC_at_k > 100.0) {
      /* Saturate: '<S3>/Saturation1' */
      SoC_B.Saturation1 = 100.0;
    } else if (rtb_ImpAsg_InsertedFor_SOC_at_k < 0.0) {
      /* Saturate: '<S3>/Saturation1' */
      SoC_B.Saturation1 = 0.0;
    } else {
      /* Saturate: '<S3>/Saturation1' */
      SoC_B.Saturation1 = rtb_ImpAsg_InsertedFor_SOC_at_k;
    }

    /* End of Saturate: '<S3>/Saturation1' */
  }

  /* Outputs for Iterator SubSystem: '<S3>/SOC Estimator (Kalman Filter)' incorporates:
   *  ForEach: '<S30>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S30>/Gain' incorporates:
       *  Inport: '<Root>/Accumulator_Current'
       */
      SoC_B.CoreSubsys_g[ForEach_itr].Gain = -SoC_U.Accumulator_Current;
    }

    /* SignalConversion generated from: '<S37>/Assignment' incorporates:
     *  Assignment: '<S37>/Assignment'
     *  Constant: '<S37>/Constant'
     */
    rtb_Gain_b[0] = 1.0;
    rtb_Gain_b[1] = 0.0;
    rtb_Gain_b[2] = 0.0;

    /* SignalConversion generated from: '<S36>/Delay' incorporates:
     *  Constant: '<S36>/Constant1'
     */
    SoC_B.CoreSubsys_g[ForEach_itr].TmpSignalConversionAtDelayInpor[0] =
      SoC_B.Switch;
    SoC_B.CoreSubsys_g[ForEach_itr].TmpSignalConversionAtDelayInpor[1] = 0.0;

    /* Delay: '<S36>/Delay' */
    if (SoC_DW.CoreSubsys_g[ForEach_itr].icLoad) {
      SoC_DW.CoreSubsys_g[ForEach_itr].Delay_DSTATE[0] =
        SoC_B.CoreSubsys_g[ForEach_itr].TmpSignalConversionAtDelayInpor[0];
      SoC_DW.CoreSubsys_g[ForEach_itr].Delay_DSTATE[1] = 0.0;
    }

    /* Delay: '<S36>/Delay' */
    rtb_Delay[0] = SoC_DW.CoreSubsys_g[ForEach_itr].Delay_DSTATE[0];
    rtb_Delay[1] = SoC_DW.CoreSubsys_g[ForEach_itr].Delay_DSTATE[1];

    /* Lookup_n-D: '<S37>/2-D Lookup Table R1' */
    rtb_ManualSwitch1 = look1_binlxpw(rtb_Delay[0],
      rtCP_uDLookupTableR1_bp01Data, rtCP_uDLookupTableR1_tableData, 25U);

    /* Math: '<S37>/Math Function' incorporates:
     *  Gain: '<S37>/-Ts'
     *  Lookup_n-D: '<S37>/2-D Lookup Table C1'
     *  Product: '<S37>/Product'
     *  Product: '<S37>/Product2'
     *
     * About '<S37>/Math Function':
     *  Operator: exp
     */
    rtb_Saturation_m = exp(1.0 / (rtb_ManualSwitch1 * look1_binlxpw(rtb_Delay[0],
      rtCP_uDLookupTableC1_bp01Data, rtCP_uDLookupTableC1_tableData, 25U)) *
      -SoC_B.CoreSubsys_g[ForEach_itr].Probe[0]);

    /* Assignment: '<S37>/Assignment' */
    rtb_Gain_b[3] = rtb_Saturation_m;

    /* Product: '<S38>/Product2' incorporates:
     *  Assignment: '<S37>/Assignment'
     *  Math: '<S38>/Transpose'
     *  UnitDelay: '<S34>/Unit Delay - P'
     */
    for (iAcol = 0; iAcol < 2; iAcol++) {
      b_c_idx_0 = SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[iAcol + 2];
      absxk = SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[iAcol];
      tmp[iAcol] = b_c_idx_0 * 0.0 + absxk;
      tmp[iAcol + 2] = b_c_idx_0 * rtb_Saturation_m + absxk * 0.0;
    }

    /* Lookup_n-D: '<S37>/2-D Lookup Table dV0' */
    b_c_idx_0 = look1_binlxpw(rtb_Delay[0], rtCP_uDLookupTabledV0_bp01Data,
      rtCP_uDLookupTabledV0_tableData, 25U);

    /* SignalConversion generated from: '<S37>/Transpose1' incorporates:
     *  Constant: '<S37>/Constant4'
     */
    rtb_Add_i[0] = b_c_idx_0;
    rtb_Add_i[1] = -1.0;

    /* Product: '<S35>/Product2' */
    absxk = 0.0;

    /* Product: '<S38>/Product2' */
    tmp_0 = tmp[1];
    tmp_1 = tmp[0];
    tmp_2 = tmp[3];
    tmp_3 = tmp[2];
    for (iAcol = 0; iAcol < 2; iAcol++) {
      /* Sum: '<S38>/Sum1' incorporates:
       *  Assignment: '<S37>/Assignment'
       *  Constant: '<S38>/Constant'
       *  Product: '<S15>/Matrix Multiply'
       *  Product: '<S38>/Product2'
       */
      rtb_Gain_i = rtb_Gain_b[iAcol + 2];
      rtb_X1_tmp = (int32_T)rtb_Gain_b[iAcol];
      rtb_MatrixMultiply_0 = (rtb_Gain_i * tmp_0 + (real_T)rtb_X1_tmp * tmp_1) +
        rtCP_Constant_Value_a[iAcol];
      rtb_MatrixMultiply[iAcol] = rtb_MatrixMultiply_0;

      /* Product: '<S35>/Product2' incorporates:
       *  Lookup_n-D: '<S37>/2-D Lookup Table dV0'
       *  Product: '<S35>/Product'
       */
      rtb_Kk1_l = rtb_MatrixMultiply_0 * b_c_idx_0;

      /* Sum: '<S38>/Sum1' incorporates:
       *  Constant: '<S38>/Constant'
       *  Product: '<S15>/Matrix Multiply'
       *  Product: '<S38>/Product2'
       */
      rtb_MatrixMultiply_0 = (rtb_Gain_i * tmp_2 + (real_T)rtb_X1_tmp * tmp_3) +
        rtCP_Constant_Value_a[iAcol + 2];
      rtb_MatrixMultiply[iAcol + 2] = rtb_MatrixMultiply_0;

      /* Product: '<S35>/Product2' incorporates:
       *  Math: '<S37>/Transpose1'
       *  Product: '<S35>/Product'
       */
      rtb_Kk1_l -= rtb_MatrixMultiply_0;
      rtb_Kk1_p[iAcol] = rtb_Kk1_l;
      absxk += rtb_Add_i[iAcol] * rtb_Kk1_l;
    }

    /* Product: '<S35>/Divide' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     *  Product: '<S35>/Product2'
     *  Sum: '<S35>/Sum2'
     */
    absxk = 1.0 / (absxk + 0.001);

    /* Product: '<S35>/Product1' incorporates:
     *  Product: '<S35>/Product'
     */
    rtb_Kk1_p[0] *= absxk;
    rtb_Kk1_p[1] *= absxk;

    /* RateTransition: '<S34>/Rate Transition1' */
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      /* RateTransition: '<S34>/Rate Transition1' */
      SoC_B.CoreSubsys_g[ForEach_itr].RateTransition1 =
        SoC_DW.CoreSubsys_g[ForEach_itr].RateTransition1_Buffer0;
    }

    /* End of RateTransition: '<S34>/Rate Transition1' */

    /* Sum: '<S34>/Sum' incorporates:
     *  Inport: '<Root>/Lowest_Cell_Voltage'
     *  Lookup_n-D: '<S37>/2-D Lookup Table R0'
     *  Lookup_n-D: '<S37>/2-D Lookup Table V0'
     *  Product: '<S37>/Product6'
     *  Sum: '<S37>/Sum2'
     */
    absxk = SoC_U.Lowest_Cell_Voltage - ((look1_binlxpw(rtb_Delay[0],
      rtCP_uDLookupTableV0_bp01Data, rtCP_uDLookupTableV0_tableData, 25U) -
      look1_binlxpw(rtb_Delay[0], rtCP_uDLookupTableR0_bp01Data,
                    rtCP_uDLookupTableR0_tableData, 25U) *
      SoC_B.CoreSubsys_g[ForEach_itr].RateTransition1) - rtb_Delay[1]);

    /* Sum: '<S35>/Sum3' incorporates:
     *  Constant: '<S35>/Constant2'
     *  Product: '<S35>/Product1'
     *  Product: '<S35>/Product4'
     */
    tmp[0] = 1.0 - rtb_Kk1_p[0] * b_c_idx_0;
    tmp[1] = 0.0 - b_c_idx_0 * rtb_Kk1_p[1];

    /* Sum: '<S35>/Sum' incorporates:
     *  Gain: '<S37>/-Ts'
     *  Gain: '<S37>/Gain'
     *  Product: '<S35>/Product1'
     *  Product: '<S35>/Product3'
     *  Product: '<S38>/Product'
     *  Product: '<S38>/Product1'
     *  Sum: '<S38>/Sum'
     */
    SoC_B.CoreSubsys_g[ForEach_itr].Sum[0] = ((rtb_Delay[1] * 0.0 + rtb_Delay[0])
      + 2.2222222222222223E-5 * -SoC_B.CoreSubsys_g[ForEach_itr].Probe[0] *
      SoC_B.CoreSubsys_g[ForEach_itr].RateTransition1) + rtb_Kk1_p[0] * absxk;

    /* Sum: '<S35>/Sum3' incorporates:
     *  Constant: '<S35>/Constant2'
     *  Product: '<S35>/Product1'
     *  Product: '<S35>/Product4'
     */
    tmp[2] = 0.0 - (-rtb_Kk1_p[0]);
    tmp[3] = 1.0 - (-rtb_Kk1_p[1]);

    /* Sum: '<S35>/Sum' incorporates:
     *  Assignment: '<S37>/Assignment'
     *  Constant: '<S37>/Constant1'
     *  Product: '<S35>/Product1'
     *  Product: '<S35>/Product3'
     *  Product: '<S37>/Product4'
     *  Product: '<S38>/Product'
     *  Product: '<S38>/Product1'
     *  Sum: '<S37>/Sum'
     *  Sum: '<S38>/Sum'
     */
    SoC_B.CoreSubsys_g[ForEach_itr].Sum[1] = ((1.0 - rtb_Saturation_m) *
      rtb_ManualSwitch1 * SoC_B.CoreSubsys_g[ForEach_itr].RateTransition1 +
      (rtb_Delay[0] * 0.0 + rtb_Delay[1] * rtb_Saturation_m)) + rtb_Kk1_p[1] *
      absxk;

    /* Product: '<S35>/Product5' incorporates:
     *  Product: '<S15>/Matrix Multiply'
     */
    rtb_MatrixMultiply_0 = rtb_MatrixMultiply[0];
    rtb_ManualSwitch1 = rtb_MatrixMultiply[1];
    absxk = rtb_MatrixMultiply[2];
    rtb_Saturation_m = rtb_MatrixMultiply[3];
    for (iAcol = 0; iAcol < 2; iAcol++) {
      /* Product: '<S35>/Product5' */
      b_c_idx_0 = tmp[iAcol];
      tmp_0 = tmp[iAcol + 2];
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[iAcol] = tmp_0 *
        rtb_ManualSwitch1 + b_c_idx_0 * rtb_MatrixMultiply_0;
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[iAcol + 2] = tmp_0 *
        rtb_Saturation_m + b_c_idx_0 * absxk;
    }

    /* ForEachSliceAssignment generated from: '<S30>/SOC' */
    rtb_Saturation_m = SoC_B.CoreSubsys_g[ForEach_itr].Sum[0];
  }

  /* End of Outputs for SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Saturation_m > 100.0) {
    /* Outport: '<Root>/KFSoC_L' */
    SoC_Y.KFSoC_L = 100.0;
  } else if (rtb_Saturation_m < 0.0) {
    /* Outport: '<Root>/KFSoC_L' */
    SoC_Y.KFSoC_L = 0.0;
  } else {
    /* Outport: '<Root>/KFSoC_L' */
    SoC_Y.KFSoC_L = rtb_Saturation_m;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Switch: '<S2>/Switch' */
  if (errorCondition) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Inport: '<Root>/Highest_Cell_Voltage'
     *  Lookup_n-D: '<S2>/OCV to SoC'
     */
    SoC_B.Switch_d = look1_binlxpw(SoC_U.Highest_Cell_Voltage,
      rtCP_OCVtoSoC_bp01Data, rtCP_OCVtoSoC_tableData, 25U);
  } else {
    /* Switch: '<S2>/Switch' incorporates:
     *  Memory: '<S2>/Memory'
     */
    SoC_B.Switch_d = SoC_DW.Memory_PreviousInput_p;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Outputs for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
  /* Inport: '<Root>/Accumulator_Current' */
  SoC_SOCEstimatorCoulombCounting(1, SoC_M, &SoC_U.Accumulator_Current,
    &SoC_B.Switch_d, &rtb_ImpAsg_InsertedFor_SOC_a_ia, 13.0,
    SoC_B.SOCEstimatorCoulombCounting, SoC_DW.SOCEstimatorCoulombCounting);

  /* End of Outputs for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
  if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Saturate: '<S2>/Saturation1' */
    if (rtb_ImpAsg_InsertedFor_SOC_a_ia > 100.0) {
      /* Saturate: '<S2>/Saturation1' */
      SoC_B.Saturation1_i = 100.0;
    } else if (rtb_ImpAsg_InsertedFor_SOC_a_ia < 0.0) {
      /* Saturate: '<S2>/Saturation1' */
      SoC_B.Saturation1_i = 0.0;
    } else {
      /* Saturate: '<S2>/Saturation1' */
      SoC_B.Saturation1_i = rtb_ImpAsg_InsertedFor_SOC_a_ia;
    }

    /* End of Saturate: '<S2>/Saturation1' */
  }

  /* Outputs for Iterator SubSystem: '<S2>/SOC Estimator (Kalman Filter)' incorporates:
   *  ForEach: '<S7>/For Each'
   */
  for (ForEach_itr_m = 0; ForEach_itr_m < 1; ForEach_itr_m++) {
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S7>/Gain' incorporates:
       *  Inport: '<Root>/Accumulator_Current'
       */
      SoC_B.CoreSubsys[ForEach_itr_m].Gain = -SoC_U.Accumulator_Current;

      /* RateTransition: '<S11>/Rate Transition1' */
      SoC_B.CoreSubsys[ForEach_itr_m].RateTransition1 =
        SoC_DW.CoreSubsys[ForEach_itr_m].RateTransition1_Buffer0;
    }

    /* Reshape: '<S13>/Reshape' incorporates:
     *  Constant: '<S13>/Constant1'
     *  ForEachSliceSelector generated from: '<S7>/InitialSOC'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Reshape[0] = SoC_B.Switch_d;
    SoC_B.CoreSubsys[ForEach_itr_m].Reshape[1] = 0.0;

    /* Delay: '<S13>/Delay' incorporates:
     *  Reshape: '<S13>/Reshape'
     */
    if (SoC_DW.CoreSubsys[ForEach_itr_m].icLoad) {
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[0] =
        SoC_B.CoreSubsys[ForEach_itr_m].Reshape[0];
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[1] = 0.0;
    }

    /* Assignment: '<S15>/Assignment' incorporates:
     *  Assignment: '<S15>/Assignment2'
     *  Delay: '<S13>/Delay'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[0] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[0];
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[1] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[1];

    /* Gain: '<S15>/Gain' incorporates:
     *  UnitDelay: '<S11>/Unit Delay - P'
     */
    rtb_Gain_b[0] = 1.4142135623730951 * SoC_DW.CoreSubsys[ForEach_itr_m].
      UnitDelayP_DSTATE[0];
    rtb_Gain_b[1] = 1.4142135623730951 * SoC_DW.CoreSubsys[ForEach_itr_m].
      UnitDelayP_DSTATE[1];
    rtb_Gain_b[2] = 1.4142135623730951 * SoC_DW.CoreSubsys[ForEach_itr_m].
      UnitDelayP_DSTATE[2];
    rtb_Gain_b[3] = 1.4142135623730951 * SoC_DW.CoreSubsys[ForEach_itr_m].
      UnitDelayP_DSTATE[3];

    /* Assignment: '<S15>/Assignment1' incorporates:
     *  Assignment: '<S15>/Assignment2'
     *  Delay: '<S13>/Delay'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Matrix Multiply'
     *  Sum: '<S15>/Sum'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[2] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[0] + rtb_Gain_b[0];

    /* Assignment: '<S15>/Assignment2' incorporates:
     *  Delay: '<S13>/Delay'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Matrix Multiply'
     *  Sum: '<S15>/Sum'
     *  Sum: '<S15>/Sum1'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[6] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[0] - rtb_Gain_b[0];

    /* Assignment: '<S15>/Assignment1' incorporates:
     *  Assignment: '<S15>/Assignment2'
     *  Delay: '<S13>/Delay'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Matrix Multiply'
     *  Sum: '<S15>/Sum'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[3] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[1] + rtb_Gain_b[1];

    /* Assignment: '<S15>/Assignment2' incorporates:
     *  Delay: '<S13>/Delay'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Matrix Multiply'
     *  Sum: '<S15>/Sum'
     *  Sum: '<S15>/Sum1'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[7] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[1] - rtb_Gain_b[1];

    /* Assignment: '<S15>/Assignment1' incorporates:
     *  Assignment: '<S15>/Assignment2'
     *  Delay: '<S13>/Delay'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Matrix Multiply'
     *  Sum: '<S15>/Sum'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[4] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[0] + rtb_Gain_b[2];

    /* Assignment: '<S15>/Assignment2' incorporates:
     *  Delay: '<S13>/Delay'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Matrix Multiply'
     *  Sum: '<S15>/Sum'
     *  Sum: '<S15>/Sum1'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[8] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[0] - rtb_Gain_b[2];

    /* Assignment: '<S15>/Assignment1' incorporates:
     *  Assignment: '<S15>/Assignment2'
     *  Delay: '<S13>/Delay'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Matrix Multiply'
     *  Sum: '<S15>/Sum'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[5] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[1] + rtb_Gain_b[3];

    /* Assignment: '<S15>/Assignment2' incorporates:
     *  Delay: '<S13>/Delay'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Matrix Multiply'
     *  Sum: '<S15>/Sum'
     *  Sum: '<S15>/Sum1'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[9] =
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[1] - rtb_Gain_b[3];

    /* Outputs for Iterator SubSystem: '<S14>/State function' incorporates:
     *  ForEach: '<S20>/For Each'
     */
    for (ForEach_itr_f = 0; ForEach_itr_f < 5; ForEach_itr_f++) {
      /* Lookup_n-D: '<S26>/R1' incorporates:
       *  Assignment: '<S15>/Assignment2'
       *  ForEachSliceSelector generated from: '<S20>/X'
       */
      rtb_Saturation_m = look1_pbinlcpw(SoC_B.CoreSubsys[ForEach_itr_m].
        Assignment2[ForEach_itr_f << 1], rtCP_R1_bp01Data, rtCP_R1_tableData,
        &SoC_DW.CoreSubsys[ForEach_itr_m].CoreSubsys[ForEach_itr_f].m_bpIndex,
        25U);

      /* Lookup_n-D: '<S26>/C1' incorporates:
       *  Assignment: '<S15>/Assignment2'
       *  ForEachSliceSelector generated from: '<S20>/X'
       */
      rtb_ManualSwitch1 = look1_pbinlcpw(SoC_B.CoreSubsys[ForEach_itr_m].
        Assignment2[ForEach_itr_f << 1], rtCP_C1_bp01Data, rtCP_C1_tableData,
        &SoC_DW.CoreSubsys[ForEach_itr_m].CoreSubsys[ForEach_itr_f].m_bpIndex_n,
        25U);

      /* Selector: '<S20>/Selector' incorporates:
       *  Constant: '<S20>/Constant'
       */
      b_c_idx_0 = rtCP_Constant_Value_n[ForEach_itr_f];

      /* ForEachSliceSelector generated from: '<S20>/X' incorporates:
       *  Product: '<S26>/Divide2'
       *  Sum: '<S26>/Add'
       */
      rtb_X1_tmp = ForEach_itr_f << 1;

      /* Sum: '<S26>/Add' incorporates:
       *  Assignment: '<S15>/Assignment2'
       *  ForEachSliceSelector generated from: '<S20>/X'
       *  Gain: '<S26>/Gain'
       *  Product: '<S26>/Product'
       */
      absxk = (real32_T)(-2.2222222222222223E-5 * SoC_B.CoreSubsys[ForEach_itr_m]
                         .RateTransition1 * SoC_B.CoreSubsys[ForEach_itr_m].
                         CoreSubsys[ForEach_itr_f].Probe[0]) +
        SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[rtb_X1_tmp];
      rtb_Add_i[0] = absxk;

      /* ForEachSliceAssignment generated from: '<S20>/xk1' incorporates:
       *  Sum: '<S26>/Add'
       */
      SoC_B.CoreSubsys[ForEach_itr_m].ImpAsg_InsertedFor_xk1_at_inpor[rtb_X1_tmp]
        = absxk;

      /* ForEachSliceAssignment generated from: '<S20>/Wm_i*xk1_i' incorporates:
       *  Product: '<S20>/Product'
       *  Sum: '<S26>/Add'
       */
      rtb_ImpAsg_InsertedFor_Wm_ixk1_[rtb_X1_tmp] = b_c_idx_0 * absxk;

      /* Sum: '<S26>/Add' incorporates:
       *  Assignment: '<S15>/Assignment2'
       *  ForEachSliceSelector generated from: '<S20>/X'
       *  Product: '<S26>/Divide1'
       *  Product: '<S26>/Divide2'
       *  Product: '<S26>/Product'
       *  Product: '<S26>/Product1'
       *  Sum: '<S26>/Add1'
       */
      rtb_ImpAsg_InsertedFor_SOC_at_h = SoC_B.CoreSubsys[ForEach_itr_m].
        Assignment2[rtb_X1_tmp + 1];
      absxk = (real32_T)((SoC_B.CoreSubsys[ForEach_itr_m].RateTransition1 /
                          rtb_ManualSwitch1 - rtb_ImpAsg_InsertedFor_SOC_at_h /
                          (rtb_Saturation_m * rtb_ManualSwitch1)) *
                         SoC_B.CoreSubsys[ForEach_itr_m]
                         .CoreSubsys[ForEach_itr_f].Probe[0]) +
        rtb_ImpAsg_InsertedFor_SOC_at_h;
      rtb_Add_i[1] = absxk;

      /* ForEachSliceAssignment generated from: '<S20>/xk1' incorporates:
       *  Product: '<S26>/Divide2'
       *  Sum: '<S26>/Add'
       */
      SoC_B.CoreSubsys[ForEach_itr_m].ImpAsg_InsertedFor_xk1_at_inpor[rtb_X1_tmp
        + 1] = absxk;

      /* ForEachSliceAssignment generated from: '<S20>/Wm_i*xk1_i' incorporates:
       *  Product: '<S20>/Product'
       *  Product: '<S26>/Divide2'
       *  Sum: '<S26>/Add'
       */
      rtb_ImpAsg_InsertedFor_Wm_ixk1_[rtb_X1_tmp + 1] = b_c_idx_0 * absxk;
    }

    /* End of Outputs for SubSystem: '<S14>/State function' */

    /* Sum: '<S14>/Sum of Elements' incorporates:
     *  ForEachSliceAssignment generated from: '<S20>/Wm_i*xk1_i'
     */
    for (iAcol = 0; iAcol < 2; iAcol++) {
      rtb_Saturation_m = -0.0;
      for (knt = 0; knt < 5; knt++) {
        rtb_Saturation_m += rtb_ImpAsg_InsertedFor_Wm_ixk1_[(knt << 1) + iAcol];
      }

      rtb_SumofElements[iAcol] = rtb_Saturation_m;
    }

    /* End of Sum: '<S14>/Sum of Elements' */

    /* MATLAB Function: '<S14>/updatePx' incorporates:
     *  ForEachSliceAssignment generated from: '<S20>/xk1'
     *  Sum: '<S14>/Sum of Elements'
     */
    rtb_ImpAsg_InsertedFor_SOC_at_h = rtb_SumofElements[0];
    rtb_ManualSwitch1 = rtb_SumofElements[1];
    for (knt = 0; knt < 5; knt++) {
      rtb_X1_tmp = knt << 1;
      rtb_X1[rtb_X1_tmp] = SoC_B.CoreSubsys[ForEach_itr_m].
        ImpAsg_InsertedFor_xk1_at_inpor[rtb_X1_tmp] -
        rtb_ImpAsg_InsertedFor_SOC_at_h;
      rtb_X1[rtb_X1_tmp + 1] = SoC_B.CoreSubsys[ForEach_itr_m].
        ImpAsg_InsertedFor_xk1_at_inpor[rtb_X1_tmp + 1] - rtb_ManualSwitch1;
      rtb_Y1[knt] = sqrt(fabs(rtCP_updatePx_Wc[knt]));
    }

    memset(&b[0], 0, 25U * sizeof(real_T));
    for (iAcol = 0; iAcol < 5; iAcol++) {
      b[iAcol + 5 * iAcol] = rtb_Y1[iAcol];
    }

    for (iAcol = 0; iAcol < 2; iAcol++) {
      for (knt = 0; knt < 5; knt++) {
        rtb_ImpAsg_InsertedFor_SOC_at_h = 0.0;
        for (rtb_X1_tmp = 0; rtb_X1_tmp < 5; rtb_X1_tmp++) {
          rtb_ImpAsg_InsertedFor_SOC_at_h += rtb_X1[(rtb_X1_tmp << 1) + iAcol] *
            b[5 * knt + rtb_X1_tmp];
        }

        residual[iAcol + (knt << 1)] = rtb_ImpAsg_InsertedFor_SOC_at_h;
      }

      residual_1[6 * iAcol] = residual[iAcol + 2];
      residual_1[6 * iAcol + 1] = residual[iAcol + 4];
      residual_1[6 * iAcol + 2] = residual[iAcol + 6];
      residual_1[6 * iAcol + 3] = residual[iAcol + 8];
      residual_1[6 * iAcol + 4] = rtCP_updatePx_Q[iAcol];
      residual_1[6 * iAcol + 5] = rtCP_updatePx_Q[iAcol + 2];
    }

    qr_AN2ohs8Z(residual_1, a__1, rtb_MatrixMultiply);
    for (iAcol = 0; iAcol < 2; iAcol++) {
      if (-iAcol >= 0) {
        rtb_MatrixMultiply[(iAcol + (iAcol << 1)) + 1] = 0.0;
      }
    }

    rotate_nRcnRDPx(rtb_MatrixMultiply[0], residual[0], &b_c_idx_0,
                    &rtb_Saturation_m, &rtb_MatrixMultiply[0]);
    rtb_ImpAsg_InsertedFor_SOC_at_h = b_c_idx_0 * residual[1] - rtb_Saturation_m
      * rtb_MatrixMultiply[2];
    rtb_MatrixMultiply[2] = b_c_idx_0 * rtb_MatrixMultiply[2] + rtb_Saturation_m
      * residual[1];
    rotate_nRcnRDPx(rtb_MatrixMultiply[3], rtb_ImpAsg_InsertedFor_SOC_at_h,
                    &absxk, &rtb_Saturation_m, &rtb_MatrixMultiply[3]);

    /* End of MATLAB Function: '<S14>/updatePx' */

    /* Outputs for Iterator SubSystem: '<S14>/Measurement function' incorporates:
     *  ForEach: '<S19>/For Each'
     */
    for (ForEach_itr_l = 0; ForEach_itr_l < 5; ForEach_itr_l++) {
      /* Lookup_n-D: '<S24>/OCV Table' incorporates:
       *  ForEachSliceAssignment generated from: '<S20>/xk1'
       *  ForEachSliceSelector generated from: '<S19>/X'
       */
      absxk = look1_pbinlcpw(SoC_B.CoreSubsys[ForEach_itr_m].
        ImpAsg_InsertedFor_xk1_at_inpor[ForEach_itr_l << 1],
        rtCP_OCVTable_bp01Data, rtCP_OCVTable_tableData,
        &SoC_DW.CoreSubsys[ForEach_itr_m].CoreSubsys_m[ForEach_itr_l].m_bpIndex,
        25U);

      /* Lookup_n-D: '<S24>/R0 Table' incorporates:
       *  ForEachSliceAssignment generated from: '<S20>/xk1'
       *  ForEachSliceSelector generated from: '<S19>/X'
       */
      rtb_Saturation_m = look1_pbinlcpw(SoC_B.CoreSubsys[ForEach_itr_m].
        ImpAsg_InsertedFor_xk1_at_inpor[ForEach_itr_l << 1],
        rtCP_R0Table_bp01Data, rtCP_R0Table_tableData,
        &SoC_DW.CoreSubsys[ForEach_itr_m].CoreSubsys_m[ForEach_itr_l].
        m_bpIndex_d, 25U);

      /* Sum: '<S24>/Add2' incorporates:
       *  ForEachSliceAssignment generated from: '<S20>/xk1'
       *  ForEachSliceSelector generated from: '<S19>/X'
       *  Product: '<S24>/Product2'
       */
      rtb_Saturation_m = (absxk - rtb_Saturation_m *
                          SoC_B.CoreSubsys[ForEach_itr_m].RateTransition1) -
        SoC_B.CoreSubsys[ForEach_itr_m].ImpAsg_InsertedFor_xk1_at_inpor
        [(ForEach_itr_l << 1) + 1];

      /* ForEachSliceAssignment generated from: '<S19>/y' */
      rtb_ImpAsg_InsertedFor_y_at_inp[ForEach_itr_l] = rtb_Saturation_m;

      /* ForEachSliceAssignment generated from: '<S19>/Wm_i*y_i' incorporates:
       *  Constant: '<S19>/Constant'
       *  Product: '<S19>/Product'
       *  Selector: '<S19>/Selector'
       */
      rtb_ImpAsg_InsertedFor_Wm_iy_i_[ForEach_itr_l] =
        rtCP_Constant_Value_i[ForEach_itr_l] * rtb_Saturation_m;
    }

    /* End of Outputs for SubSystem: '<S14>/Measurement function' */

    /* Sum: '<S14>/Sum of Elements1' incorporates:
     *  ForEachSliceAssignment generated from: '<S19>/Wm_i*y_i'
     */
    b_c_idx_0 = -0.0;
    for (iAcol = 0; iAcol < 5; iAcol++) {
      b_c_idx_0 += rtb_ImpAsg_InsertedFor_Wm_iy_i_[iAcol];
    }

    /* End of Sum: '<S14>/Sum of Elements1' */
    for (knt = 0; knt <= 2; knt += 2) {
      /* MATLAB Function: '<S14>/updatePy' incorporates:
       *  ForEachSliceAssignment generated from: '<S19>/y'
       */
      tmp_4 = _mm_loadu_pd(&rtb_ImpAsg_InsertedFor_y_at_inp[knt]);
      _mm_storeu_pd(&rtb_Y1[knt], _mm_sub_pd(tmp_4, _mm_set1_pd(b_c_idx_0)));
      tmp_5[0] = fabs(rtCP_updatePy_Wc[knt]);
      tmp_5[1] = fabs(rtCP_updatePy_Wc[knt + 1]);
      tmp_4 = _mm_loadu_pd(&tmp_5[0]);

      /* MATLAB Function: '<S14>/updatePy' */
      _mm_storeu_pd(&residual_0[knt], _mm_sqrt_pd(tmp_4));
    }

    /* MATLAB Function: '<S14>/updatePy' incorporates:
     *  ForEachSliceAssignment generated from: '<S19>/y'
     */
    for (knt = 4; knt < 5; knt++) {
      rtb_Y1[knt] = rtb_ImpAsg_InsertedFor_y_at_inp[knt] - b_c_idx_0;
      residual_0[knt] = sqrt(fabs(rtCP_updatePy_Wc[knt]));
    }

    memset(&b[0], 0, 25U * sizeof(real_T));
    for (iAcol = 0; iAcol < 5; iAcol++) {
      b[iAcol + 5 * iAcol] = residual_0[iAcol];
    }

    for (iAcol = 0; iAcol < 5; iAcol++) {
      rtb_ImpAsg_InsertedFor_SOC_at_h = 0.0;
      for (knt = 0; knt < 5; knt++) {
        rtb_ImpAsg_InsertedFor_SOC_at_h += b[5 * iAcol + knt] * rtb_Y1[knt];
      }

      residual_0[iAcol] = rtb_ImpAsg_InsertedFor_SOC_at_h;
    }

    A[0] = residual_0[1];
    A[1] = residual_0[2];
    A[2] = residual_0[3];
    A[3] = residual_0[4];
    A[4] = 0.001;
    for (rtb_X1_tmp = 0; rtb_X1_tmp < 1; rtb_X1_tmp++) {
      rtb_ImpAsg_InsertedFor_SOC_at_h = A[0];
      rtb_Saturation_m = xnrm2_cFB6ntui(4, A, 2);
      if (rtb_Saturation_m != 0.0) {
        rtb_Saturation_m = rt_hypotd_snf(A[0], rtb_Saturation_m);
        if (A[0] >= 0.0) {
          rtb_Saturation_m = -rtb_Saturation_m;
        }

        if (fabs(rtb_Saturation_m) < 1.0020841800044864E-292) {
          knt = 0;
          do {
            knt++;
            A[1] *= 9.9792015476736E+291;
            A[2] *= 9.9792015476736E+291;
            A[3] *= 9.9792015476736E+291;
            A[4] *= 9.9792015476736E+291;
            rtb_Saturation_m *= 9.9792015476736E+291;
            rtb_ImpAsg_InsertedFor_SOC_at_h *= 9.9792015476736E+291;
          } while ((fabs(rtb_Saturation_m) < 1.0020841800044864E-292) && (knt <
                    20));

          rtb_Saturation_m = rt_hypotd_snf(rtb_ImpAsg_InsertedFor_SOC_at_h,
            xnrm2_cFB6ntui(4, A, 2));
          if (rtb_ImpAsg_InsertedFor_SOC_at_h >= 0.0) {
            rtb_Saturation_m = -rtb_Saturation_m;
          }

          rtb_ImpAsg_InsertedFor_SOC_at_h = 1.0 /
            (rtb_ImpAsg_InsertedFor_SOC_at_h - rtb_Saturation_m);
          A[1] *= rtb_ImpAsg_InsertedFor_SOC_at_h;
          A[2] *= rtb_ImpAsg_InsertedFor_SOC_at_h;
          A[3] *= rtb_ImpAsg_InsertedFor_SOC_at_h;
          A[4] *= rtb_ImpAsg_InsertedFor_SOC_at_h;
          for (iAcol = 0; iAcol < knt; iAcol++) {
            rtb_Saturation_m *= 1.0020841800044864E-292;
          }

          rtb_ImpAsg_InsertedFor_SOC_at_h = rtb_Saturation_m;
        } else {
          rtb_ImpAsg_InsertedFor_SOC_at_h = 1.0 / (A[0] - rtb_Saturation_m);
          A[1] *= rtb_ImpAsg_InsertedFor_SOC_at_h;
          A[2] *= rtb_ImpAsg_InsertedFor_SOC_at_h;
          A[3] *= rtb_ImpAsg_InsertedFor_SOC_at_h;
          A[4] *= rtb_ImpAsg_InsertedFor_SOC_at_h;
          rtb_ImpAsg_InsertedFor_SOC_at_h = rtb_Saturation_m;
        }
      }

      A[0] = rtb_ImpAsg_InsertedFor_SOC_at_h;
    }

    rotate_nRcnRDPx(A[0], residual_0[0], &rtb_Saturation_m, &rtb_ManualSwitch1,
                    &rtb_ImpAsg_InsertedFor_SOC_at_h);

    /* Sum: '<S11>/Sum' incorporates:
     *  Inport: '<Root>/Highest_Cell_Voltage'
     */
    rtb_Saturation_m = SoC_U.Highest_Cell_Voltage - b_c_idx_0;
    for (rtb_X1_tmp = 0; rtb_X1_tmp < 2; rtb_X1_tmp++) {
      /* Product: '<S12>/Product1' */
      b_c_idx_0 = 0.0;
      for (iAcol = 0; iAcol < 5; iAcol++) {
        /* Product: '<S14>/Product5' incorporates:
         *  Constant: '<S14>/Constant'
         */
        rtb_ManualSwitch1 = 0.0;
        for (knt = 0; knt < 5; knt++) {
          rtb_ManualSwitch1 += rtb_X1[(knt << 1) + rtb_X1_tmp] *
            rtCP_Constant_Value_f[5 * iAcol + knt];
        }

        /* Product: '<S12>/Product1' incorporates:
         *  Math: '<S14>/Math Function'
         *  Product: '<S14>/Product1'
         *  Product: '<S14>/Product5'
         */
        b_c_idx_0 += rtb_ManualSwitch1 * rtb_Y1[iAcol];
      }

      /* Product: '<S12>/Product1' incorporates:
       *  MATLAB Function: '<S14>/updatePy'
       *  Product: '<S12>/Product6'
       *  Product: '<S14>/Product1'
       */
      rtb_Kk1_l = b_c_idx_0 / rtb_ImpAsg_InsertedFor_SOC_at_h /
        rtb_ImpAsg_InsertedFor_SOC_at_h;

      /* Sum: '<S12>/Sum' incorporates:
       *  Product: '<S12>/Product1'
       *  Product: '<S12>/Product3'
       *  Sum: '<S14>/Sum of Elements'
       */
      SoC_B.CoreSubsys[ForEach_itr_m].Sum[rtb_X1_tmp] = rtb_Kk1_l *
        rtb_Saturation_m + rtb_SumofElements[rtb_X1_tmp];

      /* Product: '<S12>/Product5' incorporates:
       *  MATLAB Function: '<S14>/updatePy'
       *  Product: '<S12>/Product1'
       */
      rtb_Kk1_p[rtb_X1_tmp] = rtb_Kk1_l * rtb_ImpAsg_InsertedFor_SOC_at_h;
    }

    /* MATLAB Function: '<S12>/updatePk' incorporates:
     *  Product: '<S12>/Product5'
     */
    SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[0] = rtb_MatrixMultiply[0];
    SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[1] = rtb_MatrixMultiply[1];
    SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[2] = rtb_MatrixMultiply[2];
    SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[3] = rtb_MatrixMultiply[3];
    for (rtb_X1_tmp = 0; rtb_X1_tmp < 1; rtb_X1_tmp++) {
      errorCondition = false;
      for (iAcol = 0; iAcol < 2; iAcol++) {
        if (-iAcol >= 0) {
          SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[(iAcol + (iAcol << 1)) + 1] =
            0.0;
        }

        if (errorCondition || (SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[(iAcol <<
              1) + iAcol] == 0.0)) {
          errorCondition = true;
        }
      }

      if (!errorCondition) {
        for (i = 0; i < 2; i++) {
          rtb_Saturation_m = rtb_Kk1_p[i];
          rtb_Add_i[i] = rtb_Saturation_m;
          iAcol = i << 1;
          for (knt = 0; knt < i; knt++) {
            rtb_Saturation_m -= SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[iAcol] *
              rtb_Add_i[0];
          }

          rtb_Add_i[i] = rtb_Saturation_m / SoC_B.CoreSubsys[ForEach_itr_m].
            Pk1_k1[i + iAcol];
        }

        rtb_ManualSwitch1 = 3.3121686421112381E-170;
        b_c_idx_0 = fabs(rtb_Add_i[0]);
        if (b_c_idx_0 > 3.3121686421112381E-170) {
          rtb_Saturation_m = 1.0;
          rtb_ManualSwitch1 = b_c_idx_0;
        } else {
          rtb_ImpAsg_InsertedFor_SOC_at_h = b_c_idx_0 / 3.3121686421112381E-170;
          rtb_Saturation_m = rtb_ImpAsg_InsertedFor_SOC_at_h *
            rtb_ImpAsg_InsertedFor_SOC_at_h;
        }

        absxk = fabs(rtb_Add_i[1]);
        if (absxk > rtb_ManualSwitch1) {
          rtb_ImpAsg_InsertedFor_SOC_at_h = rtb_ManualSwitch1 / absxk;
          rtb_Saturation_m = rtb_Saturation_m * rtb_ImpAsg_InsertedFor_SOC_at_h *
            rtb_ImpAsg_InsertedFor_SOC_at_h + 1.0;
          rtb_ManualSwitch1 = absxk;
        } else {
          rtb_ImpAsg_InsertedFor_SOC_at_h = absxk / rtb_ManualSwitch1;
          rtb_Saturation_m += rtb_ImpAsg_InsertedFor_SOC_at_h *
            rtb_ImpAsg_InsertedFor_SOC_at_h;
        }

        rtb_Saturation_m = rtb_ManualSwitch1 * sqrt(rtb_Saturation_m);
        if (!(rtb_Saturation_m >= 1.0)) {
          rtb_ManualSwitch1 = sqrt(1.0 - rtb_Saturation_m * rtb_Saturation_m);
          if (absxk == 0.0) {
            rtb_SumofElements[1] = 1.0;
            s[1] = 0.0;
          } else {
            rtb_ImpAsg_InsertedFor_SOC_at_h = rtb_ManualSwitch1 + absxk;
            rtb_ManualSwitch1 /= rtb_ImpAsg_InsertedFor_SOC_at_h;
            absxk = rtb_Add_i[1] / rtb_ImpAsg_InsertedFor_SOC_at_h;
            rtb_Saturation_m = rt_hypotd_snf(rtb_ManualSwitch1, fabs(absxk));
            rtb_SumofElements[1] = rtb_ManualSwitch1 / rtb_Saturation_m;
            rtb_ManualSwitch1 /= rtb_ManualSwitch1;
            s[1] = rtb_ManualSwitch1 * absxk / rtb_Saturation_m;
            rtb_ManualSwitch1 *= rtb_Saturation_m *
              rtb_ImpAsg_InsertedFor_SOC_at_h;
          }

          rtb_Add_i[1] = 0.0;
          if (b_c_idx_0 == 0.0) {
            rtb_SumofElements[0] = 1.0;
            s[0] = 0.0;
          } else if (rtb_ManualSwitch1 == 0.0) {
            rtb_SumofElements[0] = 0.0;
            s[0] = 1.0;
          } else {
            rtb_ImpAsg_InsertedFor_SOC_at_h = rtb_ManualSwitch1 + b_c_idx_0;
            rtb_ManualSwitch1 /= rtb_ImpAsg_InsertedFor_SOC_at_h;
            absxk = rtb_Add_i[0] / rtb_ImpAsg_InsertedFor_SOC_at_h;
            rtb_Saturation_m = rt_hypotd_snf(rtb_ManualSwitch1, fabs(absxk));
            rtb_SumofElements[0] = rtb_ManualSwitch1 / rtb_Saturation_m;
            s[0] = rtb_ManualSwitch1 / rtb_ManualSwitch1 * absxk /
              rtb_Saturation_m;
          }

          rtb_Add_i[0] = 0.0;
          for (iAcol = 0; iAcol < 2; iAcol++) {
            for (knt = iAcol + 1; knt >= 1; knt--) {
              rtb_ImpAsg_InsertedFor_SOC_at_h = s[knt - 1];
              i = ((iAcol << 1) + knt) - 1;
              rtb_ManualSwitch1 = SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[i];
              b_c_idx_0 = rtb_SumofElements[knt - 1];
              absxk = rtb_Add_i[iAcol];
              SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[i] = b_c_idx_0 *
                rtb_ManualSwitch1 - rtb_ImpAsg_InsertedFor_SOC_at_h * absxk;
              rtb_Add_i[iAcol] = b_c_idx_0 * absxk +
                rtb_ImpAsg_InsertedFor_SOC_at_h * rtb_ManualSwitch1;
            }
          }
        }
      }
    }

    /* End of MATLAB Function: '<S12>/updatePk' */

    /* ForEachSliceAssignment generated from: '<S7>/SOC' */
    rtb_ImpAsg_InsertedFor_SOC_at_h = SoC_B.CoreSubsys[ForEach_itr_m].Sum[0];
  }

  /* End of Outputs for SubSystem: '<S2>/SOC Estimator (Kalman Filter)' */

  /* Outport: '<Root>/SoC_Avg' incorporates:
   *  Gain: '<Root>/Gain1'
   *  ManualSwitch: '<Root>/Manual Switch'
   *  ManualSwitch: '<Root>/Manual Switch1'
   *  Sum: '<Root>/Add'
   */
  SoC_Y.SoC_Avg = (SoC_B.Saturation1 + SoC_B.Saturation1_i) * 0.5;
  if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/CSoC_L' */
    SoC_Y.CSoC_L = SoC_B.Saturation1;

    /* Outport: '<Root>/CSoC_H' */
    SoC_Y.CSoC_H = SoC_B.Saturation1_i;
  }

  /* Saturate: '<S2>/Saturation' */
  if (rtb_ImpAsg_InsertedFor_SOC_at_h > 100.0) {
    /* Outport: '<Root>/KFSoC_H' */
    SoC_Y.KFSoC_H = 100.0;
  } else if (rtb_ImpAsg_InsertedFor_SOC_at_h < 0.0) {
    /* Outport: '<Root>/KFSoC_H' */
    SoC_Y.KFSoC_H = 0.0;
  } else {
    /* Outport: '<Root>/KFSoC_H' */
    SoC_Y.KFSoC_H = rtb_ImpAsg_InsertedFor_SOC_at_h;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Outport: '<Root>/SoC_Low' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch'
   */
  SoC_Y.SoC_Low = SoC_B.Saturation1;

  /* Outport: '<Root>/SoC_High' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch1'
   */
  SoC_Y.SoC_High = SoC_B.Saturation1_i;
}

/* Model update function */
static void SoC_update(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_m;

  /* Update for Memory: '<S3>/Memory' */
  SoC_DW.Memory_PreviousInput = SoC_B.Switch;

  /* Update for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
  SOCEstimatorCoulombCount_Update(1, SoC_M, SoC_B.SOCEstimatorCoulombCounting_p,
    SoC_DW.SOCEstimatorCoulombCounting_p);

  /* End of Update for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

  /* Update for Iterator SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* Update for Delay: '<S36>/Delay' */
    SoC_DW.CoreSubsys_g[ForEach_itr].icLoad = false;
    SoC_DW.CoreSubsys_g[ForEach_itr].Delay_DSTATE[0] =
      SoC_B.CoreSubsys_g[ForEach_itr].Sum[0];
    SoC_DW.CoreSubsys_g[ForEach_itr].Delay_DSTATE[1] =
      SoC_B.CoreSubsys_g[ForEach_itr].Sum[1];

    /* Update for UnitDelay: '<S34>/Unit Delay - P' incorporates:
     *  Product: '<S35>/Product5'
     */
    SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[0] =
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[0];
    SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[1] =
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[1];
    SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[2] =
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[2];
    SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[3] =
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[3];

    /* Update for RateTransition: '<S34>/Rate Transition1' */
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      SoC_DW.CoreSubsys_g[ForEach_itr].RateTransition1_Buffer0 =
        SoC_B.CoreSubsys_g[ForEach_itr].Gain;
    }

    /* End of Update for RateTransition: '<S34>/Rate Transition1' */
  }

  /* End of Update for SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */

  /* Update for Memory: '<S2>/Memory' */
  SoC_DW.Memory_PreviousInput_p = SoC_B.Switch_d;

  /* Update for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
  SOCEstimatorCoulombCount_Update(1, SoC_M, SoC_B.SOCEstimatorCoulombCounting,
    SoC_DW.SOCEstimatorCoulombCounting);

  /* End of Update for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

  /* Update for Iterator SubSystem: '<S2>/SOC Estimator (Kalman Filter)' */
  for (ForEach_itr_m = 0; ForEach_itr_m < 1; ForEach_itr_m++) {
    /* Update for RateTransition: '<S11>/Rate Transition1' */
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      SoC_DW.CoreSubsys[ForEach_itr_m].RateTransition1_Buffer0 =
        SoC_B.CoreSubsys[ForEach_itr_m].Gain;
    }

    /* End of Update for RateTransition: '<S11>/Rate Transition1' */

    /* Update for Delay: '<S13>/Delay' incorporates:
     *  Sum: '<S12>/Sum'
     */
    SoC_DW.CoreSubsys[ForEach_itr_m].icLoad = false;
    SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[0] =
      SoC_B.CoreSubsys[ForEach_itr_m].Sum[0];
    SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[1] =
      SoC_B.CoreSubsys[ForEach_itr_m].Sum[1];

    /* Update for UnitDelay: '<S11>/Unit Delay - P' */
    SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[0] =
      SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[0];
    SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[1] =
      SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[1];
    SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[2] =
      SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[2];
    SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[3] =
      SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[3];
  }

  /* End of Update for SubSystem: '<S2>/SOC Estimator (Kalman Filter)' */

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
  if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
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

  rate_scheduler();
}

/* Model initialize function */
static void SoC_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T ForEach_itr_m;
    int32_T ForEach_itr_f;

    /* Start for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
    SOCEstimatorCoulombCounti_Start(1, SoC_B.SOCEstimatorCoulombCounting_p,
      SoC_DW.SOCEstimatorCoulombCounting_p);

    /* End of Start for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

    /* Start for Iterator SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */
    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      /* Start for Gain: '<S30>/Gain' */
      SoC_B.CoreSubsys_g[ForEach_itr].Gain = 0.0;

      /* Start for SignalConversion generated from: '<S36>/Delay' */
      SoC_B.CoreSubsys_g[ForEach_itr].TmpSignalConversionAtDelayInpor[0] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].Delay_DSTATE[0] = 0.0;

      /* Start for SignalConversion generated from: '<S36>/Delay' */
      SoC_B.CoreSubsys_g[ForEach_itr].TmpSignalConversionAtDelayInpor[1] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].Delay_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[0] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[2] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[3] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].Divide_DWORK4 = 0.0;

      /* Start for RateTransition: '<S34>/Rate Transition1' */
      SoC_B.CoreSubsys_g[ForEach_itr].RateTransition1 = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].RateTransition1_Buffer0 = 0.0;

      /* Start for Sum: '<S35>/Sum' */
      SoC_B.CoreSubsys_g[ForEach_itr].Sum[0] = 0.0;
      SoC_B.CoreSubsys_g[ForEach_itr].Sum[1] = 0.0;

      /* Start for Product: '<S35>/Product5' */
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[0] = 0.0;
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[1] = 0.0;
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[2] = 0.0;
      SoC_B.CoreSubsys_g[ForEach_itr].Product5[3] = 0.0;

      /* Start for Probe: '<S37>/Probe' */
      SoC_B.CoreSubsys_g[ForEach_itr].Probe[0] = 0.025;
      SoC_B.CoreSubsys_g[ForEach_itr].Probe[1] = 0.0;

      /* Start for RateTransition: '<S34>/Rate Transition1' */
      SoC_B.CoreSubsys_g[ForEach_itr].RateTransition1 = 0.0;
    }

    /* End of Start for SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */

    /* Start for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
    SOCEstimatorCoulombCounti_Start(1, SoC_B.SOCEstimatorCoulombCounting,
      SoC_DW.SOCEstimatorCoulombCounting);

    /* End of Start for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

    /* Start for Iterator SubSystem: '<S2>/SOC Estimator (Kalman Filter)' */
    for (ForEach_itr_m = 0; ForEach_itr_m < 1; ForEach_itr_m++) {
      /* Start for Gain: '<S7>/Gain' */
      SoC_B.CoreSubsys[ForEach_itr_m].Gain = 0.0;

      /* Start for RateTransition: '<S11>/Rate Transition1' */
      SoC_B.CoreSubsys[ForEach_itr_m].RateTransition1 = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].RateTransition1_Buffer0 = 0.0;

      /* Start for Reshape: '<S13>/Reshape' */
      SoC_B.CoreSubsys[ForEach_itr_m].Reshape[0] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[0] = 0.0;

      /* Start for Reshape: '<S13>/Reshape' */
      SoC_B.CoreSubsys[ForEach_itr_m].Reshape[1] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].Delay_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[0] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[2] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[3] = 0.0;

      /* Start for Assignment: '<S15>/Assignment2' */
      memset(&SoC_B.CoreSubsys[ForEach_itr_m].Assignment2[0], 0, 10U * sizeof
             (real_T));

      /* Start for Sum: '<S12>/Sum' */
      SoC_B.CoreSubsys[ForEach_itr_m].Sum[0] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr_m].Sum[1] = 0.0;

      /* Start for RateTransition: '<S11>/Rate Transition1' */
      SoC_B.CoreSubsys[ForEach_itr_m].RateTransition1 = 0.0;

      /* Start for Iterator SubSystem: '<S14>/State function' */
      for (ForEach_itr_f = 0; ForEach_itr_f < 5; ForEach_itr_f++) {
        /* Start for Probe: '<S26>/Probe' */
        SoC_B.CoreSubsys[ForEach_itr_m].CoreSubsys[ForEach_itr_f].Probe[0] =
          0.025;
        SoC_B.CoreSubsys[ForEach_itr_m].CoreSubsys[ForEach_itr_f].Probe[1] = 0.0;
      }

      /* End of Start for SubSystem: '<S14>/State function' */

      /* Start for MATLAB Function: '<S12>/updatePk' */
      SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[0] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[1] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[2] = 0.0;
      SoC_B.CoreSubsys[ForEach_itr_m].Pk1_k1[3] = 0.0;
    }

    /* End of Start for SubSystem: '<S2>/SOC Estimator (Kalman Filter)' */
  }

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T ForEach_itr_m;

    /* InitializeConditions for Memory: '<S3>/Memory' */
    SoC_DW.Memory_PreviousInput = 0.0;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    SoC_DW.Memory_PreviousInput_p = 0.0;

    /* SystemInitialize for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
    SOCEstimatorCoulombCountin_Init(1, SoC_DW.SOCEstimatorCoulombCounting_p);

    /* End of SystemInitialize for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

    /* SystemInitialize for Iterator SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */
    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      /* InitializeConditions for Delay: '<S36>/Delay' */
      SoC_DW.CoreSubsys_g[ForEach_itr].icLoad = true;

      /* InitializeConditions for UnitDelay: '<S34>/Unit Delay - P' */
      SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[0] = 1.0E-8;
      SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[2] = 0.0;
      SoC_DW.CoreSubsys_g[ForEach_itr].UnitDelayP_DSTATE[3] = 1.0;

      /* InitializeConditions for RateTransition: '<S34>/Rate Transition1' */
      SoC_DW.CoreSubsys_g[ForEach_itr].RateTransition1_Buffer0 = 0.0;
    }

    /* End of SystemInitialize for SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */

    /* SystemInitialize for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
    SOCEstimatorCoulombCountin_Init(1, SoC_DW.SOCEstimatorCoulombCounting);

    /* End of SystemInitialize for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

    /* SystemInitialize for Iterator SubSystem: '<S2>/SOC Estimator (Kalman Filter)' */
    for (ForEach_itr_m = 0; ForEach_itr_m < 1; ForEach_itr_m++) {
      /* InitializeConditions for RateTransition: '<S11>/Rate Transition1' */
      SoC_DW.CoreSubsys[ForEach_itr_m].RateTransition1_Buffer0 = 0.0;

      /* InitializeConditions for Delay: '<S13>/Delay' */
      SoC_DW.CoreSubsys[ForEach_itr_m].icLoad = true;

      /* InitializeConditions for UnitDelay: '<S11>/Unit Delay - P' */
      SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[0] = 0.0001;
      SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[2] = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_m].UnitDelayP_DSTATE[3] = 1.0;
    }

    /* End of SystemInitialize for SubSystem: '<S2>/SOC Estimator (Kalman Filter)' */
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
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "SoC_M points to
       static memory which is guaranteed to be non-NULL" */
    SoC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SoC_M->Timing.sampleTimes = (&SoC_M->Timing.sampleTimesArray[0]);
    SoC_M->Timing.offsetTimes = (&SoC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SoC_M->Timing.sampleTimes[0] = (0.025);
    SoC_M->Timing.sampleTimes[1] = (1.0);

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

  rtmSetTFinal(SoC_M, 14000.0);
  SoC_M->Timing.stepSize0 = 0.025;
  SoC_M->Timing.stepSize1 = 1.0;

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
  SoC_M->Sizes.numY = (7);             /* Number of model outputs */
  SoC_M->Sizes.numU = (4);             /* Number of model inputs */
  SoC_M->Sizes.sysDirFeedThru = (1);   /* The model is direct feedthrough */
  SoC_M->Sizes.numSampTimes = (2);     /* Number of sample times */
  SoC_M->Sizes.numBlocks = (173);      /* Number of blocks */
  SoC_M->Sizes.numBlockIO = (20);      /* Number of block outputs */
  return SoC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
