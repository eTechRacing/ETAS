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
 * C source code generated on : Fri Apr 12 20:16:22 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SoC.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "look1_binlxpw.h"
#include "look2_binlxpw.h"
#include "SoC_private.h"
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

/* Model output function */
static void SoC_output(void)
{
  /* local block i/o variables */
  real_T rtb_Delay[2];

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_n;
  int32_T ForEach_itr_o;
  real_T rtb_Assignment[4];
  real_T rtb_Sum1[4];
  real_T tmp[4];
  real_T rtb_Product3[2];
  real_T rtb_TmpSignalConversionAtProduc[2];
  real_T UnitDelayP_DSTATE;
  real_T rtb_Assignment_0;
  real_T rtb_Delay_0;
  real_T rtb_Delay_1;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_g;
  real_T rtb_ImpAsg_InsertedFor_SOC_at_i;
  real_T rtb_MathFunction;
  real_T rtb_Saturation;
  real_T rtb_Sum1_0;
  real_T rtb_Sum_b;
  real_T rtb_TmpSignalConversionAtProd_0;
  int32_T rtb_Assignment_1;
  int32_T rtb_Merge;

  /* Outputs for IfAction SubSystem: '<S1>/Measures OCV SoC' incorporates:
   *  ActionPort: '<S5>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S1>/Latches OCV SoC' incorporates:
   *  ActionPort: '<S4>/Action Port'
   */
  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/Car_State'
   *  SignalConversion generated from: '<S4>/Out1'
   *  SignalConversion generated from: '<S5>/Out0'
   */
  rtb_Merge = ((SoC_U.Car_State >= 12.0) && (SoC_U.Car_State <= 15.0));

  /* End of Outputs for SubSystem: '<S1>/Latches OCV SoC' */
  /* End of Outputs for SubSystem: '<S1>/Measures OCV SoC' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Logic: '<S3>/NOT'
   */
  if (rtb_Merge == 0) {
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

  /* Outputs for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' incorporates:
   *  ForEach: '<S9>/For Each'
   */
  for (ForEach_itr_n = 0; ForEach_itr_n < 1; ForEach_itr_n++) {
    /* Gain: '<S9>/Gain' incorporates:
     *  Inport: '<Root>/Accumulator_Current'
     */
    SoC_B.CoreSubsys_l[ForEach_itr_n].Gain = 1.02880658436214E-5 *
      SoC_U.Accumulator_Current;
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      /* DiscreteIntegrator: '<S12>/Integrator' incorporates:
       *  ForEachSliceSelector generated from: '<S9>/InitialSOC'
       */
      if (SoC_DW.CoreSubsys_l[ForEach_itr_n].Integrator_IC_LOADING != 0) {
        SoC_DW.CoreSubsys_l[ForEach_itr_n].Integrator_DSTATE = SoC_B.Switch;
      }

      /* ForEachSliceAssignment generated from: '<S9>/SOC' incorporates:
       *  DiscreteIntegrator: '<S12>/Integrator'
       */
      rtb_ImpAsg_InsertedFor_SOC_at_g = SoC_DW.CoreSubsys_l[ForEach_itr_n].
        Integrator_DSTATE;
    }
  }

  /* End of Outputs for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
  if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Saturate: '<S3>/Saturation1' */
    if (rtb_ImpAsg_InsertedFor_SOC_at_g > 100.0) {
      /* Saturate: '<S3>/Saturation1' */
      SoC_B.Saturation1 = 100.0;
    } else if (rtb_ImpAsg_InsertedFor_SOC_at_g < 0.0) {
      /* Saturate: '<S3>/Saturation1' */
      SoC_B.Saturation1 = 0.0;
    } else {
      /* Saturate: '<S3>/Saturation1' */
      SoC_B.Saturation1 = rtb_ImpAsg_InsertedFor_SOC_at_g;
    }

    /* End of Saturate: '<S3>/Saturation1' */
  }

  /* Switch: '<S2>/Switch' incorporates:
   *  Logic: '<S2>/NOT'
   */
  if (rtb_Merge == 0) {
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

  /* Outputs for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' incorporates:
   *  ForEach: '<S6>/For Each'
   */
  for (ForEach_itr_o = 0; ForEach_itr_o < 1; ForEach_itr_o++) {
    /* Gain: '<S6>/Gain' incorporates:
     *  Inport: '<Root>/Accumulator_Current'
     */
    SoC_B.CoreSubsys[ForEach_itr_o].Gain = 1.02880658436214E-5 *
      SoC_U.Accumulator_Current;

    /* DiscreteIntegrator: '<S8>/Integrator' incorporates:
     *  ForEachSliceSelector generated from: '<S6>/InitialSOC'
     */
    if (SoC_DW.CoreSubsys[ForEach_itr_o].Integrator_IC_LOADING != 0) {
      SoC_DW.CoreSubsys[ForEach_itr_o].Integrator_DSTATE = SoC_B.Switch_d;
    }

    /* ForEachSliceAssignment generated from: '<S6>/SOC' incorporates:
     *  DiscreteIntegrator: '<S8>/Integrator'
     */
    SoC_Y.CSoC_H = SoC_DW.CoreSubsys[ForEach_itr_o].Integrator_DSTATE;
  }

  /* End of Outputs for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

  /* Saturate: '<S2>/Saturation1' */
  if (SoC_Y.CSoC_H > 100.0) {
    /* ForEachSliceAssignment generated from: '<S6>/SOC' */
    SoC_Y.CSoC_H = 100.0;
  } else if (SoC_Y.CSoC_H < 0.0) {
    /* ForEachSliceAssignment generated from: '<S6>/SOC' */
    SoC_Y.CSoC_H = 0.0;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Outport: '<Root>/SoC_Avg' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Sum: '<Root>/Add'
   */
  SoC_Y.SoC_Avg = (SoC_B.Saturation1 + SoC_Y.CSoC_H) * 0.5;

  /* Outport: '<Root>/SoC_High' */
  SoC_Y.SoC_High = SoC_Y.CSoC_H;
  if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/CSoC_L' */
    SoC_Y.CSoC_L = SoC_B.Saturation1;

    /* Outport: '<Root>/SoC_Low' */
    SoC_Y.SoC_Low = SoC_B.Saturation1;
  }

  /* Outputs for Iterator SubSystem: '<S3>/SOC Estimator (Kalman Filter)' incorporates:
   *  ForEach: '<S10>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* RateTransition: '<S14>/Rate Transition3' incorporates:
     *  ForEachSliceSelector generated from: '<S10>/InitialSOC'
     *  Gain: '<S10>/Gain'
     *  Inport: '<Root>/Accumulator_Current'
     *  RateTransition: '<S14>/Rate Transition1'
     */
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition3_Buffer = SoC_B.Switch;

      /* SignalConversion generated from: '<S16>/Delay' incorporates:
       *  Constant: '<S16>/Constant1'
       *  ForEachSliceSelector generated from: '<S10>/InitialSOC'
       */
      SoC_B.CoreSubsys_j[ForEach_itr].TmpSignalConversionAtDelayInpor[0] =
        SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition3_Buffer;
      SoC_B.CoreSubsys_j[ForEach_itr].TmpSignalConversionAtDelayInpor[1] = 0.0;

      /* Delay: '<S16>/Delay' */
      if (SoC_DW.CoreSubsys_j[ForEach_itr].icLoad) {
        SoC_DW.CoreSubsys_j[ForEach_itr].Delay_DSTATE[0] =
          SoC_B.CoreSubsys_j[ForEach_itr].TmpSignalConversionAtDelayInpor[0];
        SoC_DW.CoreSubsys_j[ForEach_itr].Delay_DSTATE[1] = 0.0;
      }

      /* Delay: '<S16>/Delay' */
      rtb_Delay[0] = SoC_DW.CoreSubsys_j[ForEach_itr].Delay_DSTATE[0];
      rtb_Delay[1] = SoC_DW.CoreSubsys_j[ForEach_itr].Delay_DSTATE[1];

      /* RateTransition: '<S14>/Rate Transition2' incorporates:
       *  Constant: '<S3>/Constant2'
       *  ForEachSliceSelector generated from: '<S10>/CellTemperature'
       */
      SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition2_Buffer = 40.0;

      /* Lookup_n-D: '<S17>/2-D Lookup Table dV0' incorporates:
       *  RateTransition: '<S14>/Rate Transition2'
       */
      rtb_ImpAsg_InsertedFor_SOC_at_i = look2_binlxpw(rtb_Delay[0],
        SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition2_Buffer,
        rtCP_uDLookupTabledV0_bp01Data, rtCP_uDLookupTabledV0_bp02Data,
        rtCP_uDLookupTabledV0_tableData, rtCP_uDLookupTabledV0_maxIndex, 7U);

      /* SignalConversion generated from: '<S17>/Transpose1' incorporates:
       *  Constant: '<S17>/Constant4'
       */
      rtb_Product3[0] = rtb_ImpAsg_InsertedFor_SOC_at_i;
      rtb_Product3[1] = -1.0;

      /* Lookup_n-D: '<S17>/2-D Lookup Table R1' incorporates:
       *  RateTransition: '<S14>/Rate Transition2'
       */
      rtb_Saturation = look2_binlxpw(rtb_Delay[0],
        SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition2_Buffer,
        rtCP_uDLookupTableR1_bp01Data, rtCP_uDLookupTableR1_bp02Data,
        rtCP_uDLookupTableR1_tableData, rtCP_uDLookupTableR1_maxIndex, 7U);

      /* Math: '<S17>/Math Function' incorporates:
       *  Gain: '<S17>/-Ts'
       *  Lookup_n-D: '<S17>/2-D Lookup Table C1'
       *  Product: '<S17>/Product'
       *  Product: '<S17>/Product2'
       *  RateTransition: '<S14>/Rate Transition2'
       *
       * About '<S17>/Math Function':
       *  Operator: exp
       */
      rtb_MathFunction = exp(1.0 / (rtb_Saturation * look2_binlxpw(rtb_Delay[0],
        SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition2_Buffer,
        rtCP_uDLookupTableC1_bp01Data, rtCP_uDLookupTableC1_bp02Data,
        rtCP_uDLookupTableC1_tableData, rtCP_uDLookupTableC1_maxIndex, 7U)) *
        -SoC_B.CoreSubsys_j[ForEach_itr].Probe[0]);

      /* SignalConversion generated from: '<S17>/Assignment' incorporates:
       *  Assignment: '<S17>/Assignment'
       *  Constant: '<S17>/Constant'
       */
      rtb_Assignment[0] = 1.0;
      rtb_Assignment[1] = 0.0;
      rtb_Assignment[2] = 0.0;

      /* Assignment: '<S17>/Assignment' */
      rtb_Assignment[3] = rtb_MathFunction;

      /* Product: '<S18>/Product2' incorporates:
       *  Assignment: '<S17>/Assignment'
       *  Math: '<S18>/Transpose'
       *  UnitDelay: '<S14>/Unit Delay - P'
       */
      for (rtb_Merge = 0; rtb_Merge < 2; rtb_Merge++) {
        rtb_ImpAsg_InsertedFor_SOC_at_g = SoC_DW.CoreSubsys_j[ForEach_itr].
          UnitDelayP_DSTATE[rtb_Merge + 2];
        UnitDelayP_DSTATE = SoC_DW.CoreSubsys_j[ForEach_itr]
          .UnitDelayP_DSTATE[rtb_Merge];
        tmp[rtb_Merge] = rtb_ImpAsg_InsertedFor_SOC_at_g * 0.0 +
          UnitDelayP_DSTATE;
        tmp[rtb_Merge + 2] = rtb_ImpAsg_InsertedFor_SOC_at_g * rtb_MathFunction
          + UnitDelayP_DSTATE * 0.0;
      }

      /* Product: '<S15>/Product2' */
      rtb_Sum_b = 0.0;

      /* Product: '<S18>/Product2' */
      rtb_ImpAsg_InsertedFor_SOC_at_g = tmp[1];
      rtb_Sum1_0 = tmp[0];
      rtb_Delay_0 = tmp[3];
      rtb_Delay_1 = tmp[2];
      for (rtb_Merge = 0; rtb_Merge < 2; rtb_Merge++) {
        /* Sum: '<S18>/Sum1' incorporates:
         *  Assignment: '<S17>/Assignment'
         *  Constant: '<S18>/Constant'
         *  Product: '<S18>/Product2'
         */
        rtb_Assignment_0 = rtb_Assignment[rtb_Merge + 2];
        rtb_Assignment_1 = (int32_T)rtb_Assignment[rtb_Merge];
        UnitDelayP_DSTATE = (rtb_Assignment_0 * rtb_ImpAsg_InsertedFor_SOC_at_g
                             + (real_T)rtb_Assignment_1 * rtb_Sum1_0) +
          rtCP_Constant_Value_j2w[rtb_Merge];
        rtb_Sum1[rtb_Merge] = UnitDelayP_DSTATE;

        /* Product: '<S15>/Product2' incorporates:
         *  Lookup_n-D: '<S17>/2-D Lookup Table dV0'
         *  Product: '<S15>/Product'
         */
        rtb_TmpSignalConversionAtProd_0 = UnitDelayP_DSTATE *
          rtb_ImpAsg_InsertedFor_SOC_at_i;

        /* Sum: '<S18>/Sum1' incorporates:
         *  Constant: '<S18>/Constant'
         *  Product: '<S18>/Product2'
         */
        UnitDelayP_DSTATE = (rtb_Assignment_0 * rtb_Delay_0 + (real_T)
                             rtb_Assignment_1 * rtb_Delay_1) +
          rtCP_Constant_Value_j2w[rtb_Merge + 2];
        rtb_Sum1[rtb_Merge + 2] = UnitDelayP_DSTATE;

        /* Product: '<S15>/Product2' incorporates:
         *  Product: '<S15>/Product'
         */
        rtb_TmpSignalConversionAtProd_0 -= UnitDelayP_DSTATE;
        rtb_TmpSignalConversionAtProduc[rtb_Merge] =
          rtb_TmpSignalConversionAtProd_0;

        /* Product: '<S15>/Product2' incorporates:
         *  Product: '<S15>/Product3'
         */
        rtb_Sum_b += rtb_Product3[rtb_Merge] * rtb_TmpSignalConversionAtProd_0;
      }

      /* Product: '<S15>/Divide' incorporates:
       *  Constant: '<S15>/Constant'
       *  Constant: '<S15>/Constant1'
       *  Product: '<S15>/Product2'
       *  Sum: '<S15>/Sum2'
       */
      rtb_Sum_b = 1.0 / (rtb_Sum_b + 0.1);

      /* Product: '<S15>/Product1' incorporates:
       *  Product: '<S15>/Product'
       *  SignalConversion generated from: '<S18>/Product1'
       */
      rtb_TmpSignalConversionAtProduc[0] *= rtb_Sum_b;
      rtb_TmpSignalConversionAtProduc[1] *= rtb_Sum_b;

      /* Sum: '<S15>/Sum3' incorporates:
       *  Constant: '<S15>/Constant2'
       *  Product: '<S15>/Product4'
       *  SignalConversion generated from: '<S18>/Product1'
       */
      tmp[0] = 1.0 - rtb_TmpSignalConversionAtProduc[0] *
        rtb_ImpAsg_InsertedFor_SOC_at_i;
      tmp[1] = 0.0 - rtb_ImpAsg_InsertedFor_SOC_at_i *
        rtb_TmpSignalConversionAtProduc[1];
      tmp[2] = 0.0 - (-rtb_TmpSignalConversionAtProduc[0]);
      tmp[3] = 1.0 - (-rtb_TmpSignalConversionAtProduc[1]);

      /* RateTransition: '<S14>/Rate Transition' incorporates:
       *  Inport: '<Root>/Lowest_Cell_Voltage'
       */
      SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition_Buffer =
        SoC_U.Lowest_Cell_Voltage;
      SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition1_Buffer =
        -SoC_U.Accumulator_Current;

      /* Sum: '<S14>/Sum' incorporates:
       *  Gain: '<S10>/Gain'
       *  Inport: '<Root>/Accumulator_Current'
       *  Lookup_n-D: '<S17>/2-D Lookup Table R0'
       *  Lookup_n-D: '<S17>/2-D Lookup Table V0'
       *  Product: '<S17>/Product6'
       *  RateTransition: '<S14>/Rate Transition'
       *  RateTransition: '<S14>/Rate Transition2'
       *  Sum: '<S17>/Sum2'
       */
      rtb_Sum_b = SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition_Buffer -
        ((look2_binlxpw(rtb_Delay[0], SoC_DW.CoreSubsys_j[ForEach_itr].
                        RateTransition2_Buffer, rtCP_uDLookupTableV0_bp01Data,
                        rtCP_uDLookupTableV0_bp02Data,
                        rtCP_uDLookupTableV0_tableData,
                        rtCP_uDLookupTableV0_maxIndex, 7U) - look2_binlxpw
          (rtb_Delay[0], SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition2_Buffer,
           rtCP_uDLookupTableR0_bp01Data, rtCP_uDLookupTableR0_bp02Data,
           rtCP_uDLookupTableR0_tableData, rtCP_uDLookupTableR0_maxIndex, 7U) *
          SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition1_Buffer) - rtb_Delay[1]);

      /* SignalConversion generated from: '<S18>/Product1' incorporates:
       *  Constant: '<S17>/Constant1'
       *  Gain: '<S17>/-Ts'
       *  Gain: '<S17>/Gain'
       *  Product: '<S17>/Product4'
       *  Product: '<S18>/Product1'
       *  Sum: '<S17>/Sum'
       */
      rtb_Product3[0] = 1.02880658436214E-5 * -SoC_B.CoreSubsys_j[ForEach_itr].
        Probe[0] * SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition1_Buffer;
      rtb_Product3[1] = (1.0 - rtb_MathFunction) * rtb_Saturation *
        SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition1_Buffer;

      /* Product: '<S15>/Product5' incorporates:
       *  Sum: '<S18>/Sum1'
       */
      UnitDelayP_DSTATE = rtb_Sum1[0];
      rtb_Saturation = rtb_Sum1[1];
      rtb_MathFunction = rtb_Sum1[2];
      rtb_Sum1_0 = rtb_Sum1[3];

      /* Product: '<S18>/Product' */
      rtb_Delay_0 = rtb_Delay[0];
      rtb_Delay_1 = rtb_Delay[1];
      for (rtb_Merge = 0; rtb_Merge < 2; rtb_Merge++) {
        /* Product: '<S15>/Product5' */
        rtb_ImpAsg_InsertedFor_SOC_at_i = tmp[rtb_Merge];
        rtb_ImpAsg_InsertedFor_SOC_at_g = tmp[rtb_Merge + 2];
        SoC_B.CoreSubsys_j[ForEach_itr].Product5[rtb_Merge] =
          rtb_ImpAsg_InsertedFor_SOC_at_g * rtb_Saturation +
          rtb_ImpAsg_InsertedFor_SOC_at_i * UnitDelayP_DSTATE;
        SoC_B.CoreSubsys_j[ForEach_itr].Product5[rtb_Merge + 2] =
          rtb_ImpAsg_InsertedFor_SOC_at_g * rtb_Sum1_0 +
          rtb_ImpAsg_InsertedFor_SOC_at_i * rtb_MathFunction;

        /* Sum: '<S15>/Sum' incorporates:
         *  Assignment: '<S17>/Assignment'
         *  Product: '<S15>/Product3'
         *  Product: '<S18>/Product'
         *  SignalConversion generated from: '<S18>/Product1'
         *  Sum: '<S18>/Sum'
         */
        SoC_B.CoreSubsys_j[ForEach_itr].Sum[rtb_Merge] =
          ((rtb_Assignment[rtb_Merge + 2] * rtb_Delay_1 +
            rtb_Assignment[rtb_Merge] * rtb_Delay_0) + rtb_Product3[rtb_Merge])
          + rtb_TmpSignalConversionAtProduc[rtb_Merge] * rtb_Sum_b;
      }

      /* ForEachSliceAssignment generated from: '<S10>/SOC' */
      rtb_ImpAsg_InsertedFor_SOC_at_i = SoC_B.CoreSubsys_j[ForEach_itr].Sum[0];
    }

    /* End of RateTransition: '<S14>/Rate Transition3' */
  }

  /* End of Outputs for SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */
  if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Saturate: '<S3>/Saturation' */
    if (rtb_ImpAsg_InsertedFor_SOC_at_i > 100.0) {
      /* Outport: '<Root>/KFSoC_L' */
      SoC_Y.KFSoC_L = 100.0;
    } else if (rtb_ImpAsg_InsertedFor_SOC_at_i < 0.0) {
      /* Outport: '<Root>/KFSoC_L' */
      SoC_Y.KFSoC_L = 0.0;
    } else {
      /* Outport: '<Root>/KFSoC_L' */
      SoC_Y.KFSoC_L = rtb_ImpAsg_InsertedFor_SOC_at_i;
    }

    /* End of Saturate: '<S3>/Saturation' */
  }
}

/* Model update function */
static void SoC_update(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_n;
  int32_T ForEach_itr_o;

  /* Update for Memory: '<S3>/Memory' */
  SoC_DW.Memory_PreviousInput = SoC_B.Switch;

  /* Update for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
  for (ForEach_itr_n = 0; ForEach_itr_n < 1; ForEach_itr_n++) {
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for DiscreteIntegrator: '<S12>/Integrator' */
      SoC_DW.CoreSubsys_l[ForEach_itr_n].Integrator_IC_LOADING = 0U;
      SoC_DW.CoreSubsys_l[ForEach_itr_n].Integrator_DSTATE +=
        SoC_B.CoreSubsys_l[ForEach_itr_n].Gain;
    }
  }

  /* End of Update for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

  /* Update for Memory: '<S2>/Memory' */
  SoC_DW.Memory_PreviousInput_p = SoC_B.Switch_d;

  /* Update for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
  for (ForEach_itr_o = 0; ForEach_itr_o < 1; ForEach_itr_o++) {
    /* Update for DiscreteIntegrator: '<S8>/Integrator' */
    SoC_DW.CoreSubsys[ForEach_itr_o].Integrator_IC_LOADING = 0U;
    SoC_DW.CoreSubsys[ForEach_itr_o].Integrator_DSTATE += 0.025 *
      SoC_B.CoreSubsys[ForEach_itr_o].Gain;
  }

  /* End of Update for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

  /* Update for Iterator SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    if (SoC_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Delay: '<S16>/Delay' */
      SoC_DW.CoreSubsys_j[ForEach_itr].icLoad = false;
      SoC_DW.CoreSubsys_j[ForEach_itr].Delay_DSTATE[0] =
        SoC_B.CoreSubsys_j[ForEach_itr].Sum[0];
      SoC_DW.CoreSubsys_j[ForEach_itr].Delay_DSTATE[1] =
        SoC_B.CoreSubsys_j[ForEach_itr].Sum[1];

      /* Update for UnitDelay: '<S14>/Unit Delay - P' incorporates:
       *  Product: '<S15>/Product5'
       */
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[0] =
        SoC_B.CoreSubsys_j[ForEach_itr].Product5[0];
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[1] =
        SoC_B.CoreSubsys_j[ForEach_itr].Product5[1];
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[2] =
        SoC_B.CoreSubsys_j[ForEach_itr].Product5[2];
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[3] =
        SoC_B.CoreSubsys_j[ForEach_itr].Product5[3];
    }
  }

  /* End of Update for SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */

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
    int32_T ForEach_itr_n;
    int32_T ForEach_itr_o;

    /* Start for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
    for (ForEach_itr_n = 0; ForEach_itr_n < 1; ForEach_itr_n++) {
      /* Start for Gain: '<S9>/Gain' */
      SoC_B.CoreSubsys_l[ForEach_itr_n].Gain = 0.0;
      SoC_DW.CoreSubsys_l[ForEach_itr_n].Integrator_DSTATE = 0.0;
    }

    /* End of Start for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

    /* Start for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
    for (ForEach_itr_o = 0; ForEach_itr_o < 1; ForEach_itr_o++) {
      /* Start for Gain: '<S6>/Gain' */
      SoC_B.CoreSubsys[ForEach_itr_o].Gain = 0.0;
      SoC_DW.CoreSubsys[ForEach_itr_o].Integrator_DSTATE = 0.0;
    }

    /* End of Start for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

    /* Start for Iterator SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */
    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition3_Buffer = 0.0;

      /* Start for SignalConversion generated from: '<S16>/Delay' */
      SoC_B.CoreSubsys_j[ForEach_itr].TmpSignalConversionAtDelayInpor[0] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].Delay_DSTATE[0] = 0.0;

      /* Start for SignalConversion generated from: '<S16>/Delay' */
      SoC_B.CoreSubsys_j[ForEach_itr].TmpSignalConversionAtDelayInpor[1] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].Delay_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition2_Buffer = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].Divide_DWORK4 = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[0] = 0.0;

      /* Start for Product: '<S15>/Product5' */
      SoC_B.CoreSubsys_j[ForEach_itr].Product5[0] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[1] = 0.0;

      /* Start for Product: '<S15>/Product5' */
      SoC_B.CoreSubsys_j[ForEach_itr].Product5[1] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[2] = 0.0;

      /* Start for Product: '<S15>/Product5' */
      SoC_B.CoreSubsys_j[ForEach_itr].Product5[2] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[3] = 0.0;

      /* Start for Product: '<S15>/Product5' */
      SoC_B.CoreSubsys_j[ForEach_itr].Product5[3] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition_Buffer = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].RateTransition1_Buffer = 0.0;

      /* Start for Sum: '<S15>/Sum' */
      SoC_B.CoreSubsys_j[ForEach_itr].Sum[0] = 0.0;
      SoC_B.CoreSubsys_j[ForEach_itr].Sum[1] = 0.0;

      /* Start for Probe: '<S17>/Probe' */
      SoC_B.CoreSubsys_j[ForEach_itr].Probe[0] = 1.0;
      SoC_B.CoreSubsys_j[ForEach_itr].Probe[1] = 0.0;
    }

    /* End of Start for SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */

    /* ConstCode for Outport: '<Root>/KFSoC_H' */
    SoC_Y.KFSoC_H = SoC_ConstB.Saturation;
  }

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T ForEach_itr_n;
    int32_T ForEach_itr_o;

    /* InitializeConditions for Memory: '<S3>/Memory' */
    SoC_DW.Memory_PreviousInput = 0.0;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    SoC_DW.Memory_PreviousInput_p = 0.0;

    /* SystemInitialize for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
    for (ForEach_itr_n = 0; ForEach_itr_n < 1; ForEach_itr_n++) {
      /* InitializeConditions for DiscreteIntegrator: '<S12>/Integrator' */
      SoC_DW.CoreSubsys_l[ForEach_itr_n].Integrator_IC_LOADING = 1U;
    }

    /* End of SystemInitialize for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

    /* SystemInitialize for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
    for (ForEach_itr_o = 0; ForEach_itr_o < 1; ForEach_itr_o++) {
      /* InitializeConditions for DiscreteIntegrator: '<S8>/Integrator' */
      SoC_DW.CoreSubsys[ForEach_itr_o].Integrator_IC_LOADING = 1U;
    }

    /* End of SystemInitialize for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

    /* SystemInitialize for Iterator SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */
    for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
      /* InitializeConditions for Delay: '<S16>/Delay' */
      SoC_DW.CoreSubsys_j[ForEach_itr].icLoad = true;

      /* InitializeConditions for UnitDelay: '<S14>/Unit Delay - P' */
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[0] = 1.0E-5;
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[1] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[2] = 0.0;
      SoC_DW.CoreSubsys_j[ForEach_itr].UnitDelayP_DSTATE[3] = 1.0;
    }

    /* End of SystemInitialize for SubSystem: '<S3>/SOC Estimator (Kalman Filter)' */
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
  SoC_M->Sizes.numBlocks = (112);      /* Number of blocks */
  SoC_M->Sizes.numBlockIO = (9);       /* Number of block outputs */
  return SoC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
