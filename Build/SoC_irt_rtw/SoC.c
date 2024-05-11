/*
 * SoC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 13.5
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Apr 23 14:25:50 2024
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
 *    '<S2>/SOC Estimator (Coulomb Counting)'
 *    '<S3>/SOC Estimator (Coulomb Counting)'
 */
void SOCEstimatorCoulombCountin_Init(int32_T NumIters,
  DW_SOCEstimatorCoulombCountin_T localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* InitializeConditions for DiscreteIntegrator: '<S8>/Integrator' */
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
void SoC_SOCEstimatorCoulombCounting(int32_T NumIters, const real_T *rtu_Current,
  const real_T *rtu_InitialSOC, real_T *rty_SOC, real_T rtp_AH,
  B_SOCEstimatorCoulombCounting_T localB[1], DW_SOCEstimatorCoulombCountin_T
  localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Outputs for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' incorporates:
   *  ForEach: '<S6>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Gain: '<S6>/Gain' */
    localB[ForEach_itr].CoreSubsys.Gain = 1.0 / (rtp_AH * 3600.0) *
      rtu_Current[ForEach_itr];

    /* DiscreteIntegrator: '<S8>/Integrator' */
    if (localDW[ForEach_itr].CoreSubsys.Integrator_IC_LOADING != 0) {
      localDW[ForEach_itr].CoreSubsys.Integrator_DSTATE =
        rtu_InitialSOC[ForEach_itr];
    }

    /* ForEachSliceAssignment generated from: '<S6>/SOC' incorporates:
     *  DiscreteIntegrator: '<S8>/Integrator'
     */
    rty_SOC[ForEach_itr] = localDW[ForEach_itr].CoreSubsys.Integrator_DSTATE;
  }

  /* End of Outputs for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
}

/*
 * Update for iterator system:
 *    '<S2>/SOC Estimator (Coulomb Counting)'
 *    '<S3>/SOC Estimator (Coulomb Counting)'
 */
void SOCEstimatorCoulombCount_Update(int32_T NumIters,
  B_SOCEstimatorCoulombCounting_T localB[1], DW_SOCEstimatorCoulombCountin_T
  localDW[1])
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Update for DiscreteIntegrator: '<S8>/Integrator' */
    localDW[ForEach_itr].CoreSubsys.Integrator_IC_LOADING = 0U;
    localDW[ForEach_itr].CoreSubsys.Integrator_DSTATE += localB[ForEach_itr].
      CoreSubsys.Gain;
  }
}

/* Model output function */
static void SoC_output(void)
{
  /* local block i/o variables */
  real_T rtb_ImpAsg_InsertedFor_SOC_at_i;
  real_T rtb_ImpAsg_InsertedFor_SOC_a_ia;
  real_T rtb_Saturation1;
  real_T rtb_Saturation1_d;
  boolean_T tmp;

  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/Car_State'
   *  Logic: '<S2>/NOT'
   *  Logic: '<S3>/NOT'
   */
  tmp = ((!(SoC_U.Car_State >= 12.0)) || (!(SoC_U.Car_State <= 15.0)));

  /* Switch: '<S3>/Switch' incorporates:
   *  Logic: '<S3>/NOT'
   */
  if (tmp) {
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
  SoC_SOCEstimatorCoulombCounting(1, &SoC_U.Accumulator_Current, &SoC_B.Switch,
    &rtb_ImpAsg_InsertedFor_SOC_at_i, 13.0, SoC_B.SOCEstimatorCoulombCounting_p,
    SoC_DW.SOCEstimatorCoulombCounting_p);

  /* End of Outputs for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_ImpAsg_InsertedFor_SOC_at_i > 100.0) {
    rtb_Saturation1 = 100.0;
  } else if (rtb_ImpAsg_InsertedFor_SOC_at_i < 0.0) {
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtb_ImpAsg_InsertedFor_SOC_at_i;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* Switch: '<S2>/Switch' */
  if (tmp) {
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
  SoC_SOCEstimatorCoulombCounting(1, &SoC_U.Accumulator_Current, &SoC_B.Switch_d,
    &rtb_ImpAsg_InsertedFor_SOC_a_ia, 13.0, SoC_B.SOCEstimatorCoulombCounting,
    SoC_DW.SOCEstimatorCoulombCounting);

  /* End of Outputs for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

  /* Saturate: '<S2>/Saturation1' */
  if (rtb_ImpAsg_InsertedFor_SOC_a_ia > 100.0) {
    rtb_Saturation1_d = 100.0;
  } else if (rtb_ImpAsg_InsertedFor_SOC_a_ia < 0.0) {
    rtb_Saturation1_d = 0.0;
  } else {
    rtb_Saturation1_d = rtb_ImpAsg_InsertedFor_SOC_a_ia;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Outport: '<Root>/SoC_Avg' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Sum: '<Root>/Add'
   */
  SoC_Y.SoC_Avg = (rtb_Saturation1 + rtb_Saturation1_d) * 0.5;

  /* Outport: '<Root>/CSoC_L' */
  SoC_Y.CSoC_L = rtb_Saturation1;

  /* Outport: '<Root>/CSoC_H' */
  SoC_Y.CSoC_H = rtb_Saturation1_d;

  /* Outport: '<Root>/SoC_Low' */
  SoC_Y.SoC_Low = rtb_Saturation1;

  /* Outport: '<Root>/SoC_High' */
  SoC_Y.SoC_High = rtb_Saturation1_d;
}

/* Model update function */
static void SoC_update(void)
{
  /* Update for Memory: '<S3>/Memory' */
  SoC_DW.Memory_PreviousInput = SoC_B.Switch;

  /* Update for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
  SOCEstimatorCoulombCount_Update(1, SoC_B.SOCEstimatorCoulombCounting_p,
    SoC_DW.SOCEstimatorCoulombCounting_p);

  /* End of Update for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

  /* Update for Memory: '<S2>/Memory' */
  SoC_DW.Memory_PreviousInput_p = SoC_B.Switch_d;

  /* Update for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
  SOCEstimatorCoulombCount_Update(1, SoC_B.SOCEstimatorCoulombCounting,
    SoC_DW.SOCEstimatorCoulombCounting);

  /* End of Update for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

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
  /* Start for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
  SOCEstimatorCoulombCounti_Start(1, SoC_B.SOCEstimatorCoulombCounting_p,
    SoC_DW.SOCEstimatorCoulombCounting_p);

  /* End of Start for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

  /* Start for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
  SOCEstimatorCoulombCounti_Start(1, SoC_B.SOCEstimatorCoulombCounting,
    SoC_DW.SOCEstimatorCoulombCounting);

  /* End of Start for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */

  /* ConstCode for Outport: '<Root>/KFSoC_L' */
  SoC_Y.KFSoC_L = SoC_ConstB.Saturation;

  /* ConstCode for Outport: '<Root>/KFSoC_H' */
  SoC_Y.KFSoC_H = SoC_ConstB.Saturation_c;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  SoC_DW.Memory_PreviousInput = 0.0;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  SoC_DW.Memory_PreviousInput_p = 0.0;

  /* SystemInitialize for Iterator SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */
  SOCEstimatorCoulombCountin_Init(1, SoC_DW.SOCEstimatorCoulombCounting_p);

  /* End of SystemInitialize for SubSystem: '<S3>/SOC Estimator (Coulomb Counting)' */

  /* SystemInitialize for Iterator SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
  SOCEstimatorCoulombCountin_Init(1, SoC_DW.SOCEstimatorCoulombCounting);

  /* End of SystemInitialize for SubSystem: '<S2>/SOC Estimator (Coulomb Counting)' */
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
    SoC_M->Timing.sampleTimes[0] = (1.0);

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
  SoC_M->Timing.stepSize0 = 1.0;

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
  SoC_M->Timing.stepSize = (1.0);
  rtsiSetFixedStepSize(&SoC_M->solverInfo, 1.0);
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
  SoC_M->Sizes.numSampTimes = (1);     /* Number of sample times */
  SoC_M->Sizes.numBlocks = (43);       /* Number of blocks */
  SoC_M->Sizes.numBlockIO = (4);       /* Number of block outputs */
  return SoC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
