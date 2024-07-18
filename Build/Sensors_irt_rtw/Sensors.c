/*
 * Sensors.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Sensors".
 *
 * Model version              : 13.4
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Jul 18 16:07:28 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Sensors.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_Sensors_T Sensors_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Sensors_T Sensors_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Sensors_T Sensors_Y;

/* Real-time model */
static RT_MODEL_Sensors_T Sensors_M_;
RT_MODEL_Sensors_T *const Sensors_M = &Sensors_M_;

/* Model output function */
static void Sensors_output(void)
{
  real_T rtb_Subtract1_lm;

  /* Outport: '<Root>/APPS1_Value' incorporates:
   *  Constant: '<S1>/min'
   *  Inport: '<Root>/APPS1_Bits'
   *  Product: '<S1>/Divide'
   *  Sum: '<S1>/Sum'
   */
  Sensors_Y.APPS1_Value = (Sensors_U.APPS1_Bits - 200.0) / Sensors_ConstB.Sum1;

  /* Outport: '<Root>/APPS2_Value' incorporates:
   *  Constant: '<S2>/min'
   *  Inport: '<Root>/APPS2_Bits'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Sum'
   */
  Sensors_Y.APPS2_Value = (Sensors_U.APPS2_Bits - 200.0) / Sensors_ConstB.Sum1_f;

  /* Outport: '<Root>/BrakePedal_Value' incorporates:
   *  Constant: '<S3>/min'
   *  Inport: '<Root>/BrakePedal_Bits'
   *  Product: '<S3>/Divide'
   *  Sum: '<S3>/Sum'
   */
  Sensors_Y.BrakePedal_Value = (Sensors_U.BrakePedal_Bits - 350.0) /
    Sensors_ConstB.Sum1_c;

  /* Outport: '<Root>/SUSP_F_L' incorporates:
   *  Constant: '<Root>/Zero_Bits_Experimental'
   *  Gain: '<S5>/Cte muelles'
   *  Gain: '<S5>/Ltotal'
   *  Inport: '<Root>/Susp_F_L_Bits'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Subtract1'
   */
  Sensors_Y.SUSP_F_L = (Sensors_U.Susp_F_L_Bits - 1.0) / Sensors_ConstB.Subtract
    * 57.0 * 30.0;

  /* Outport: '<Root>/SUSP_F_R' incorporates:
   *  Constant: '<Root>/Zero_Bits_Experimental'
   *  Gain: '<S6>/Cte muelles'
   *  Gain: '<S6>/Ltotal'
   *  Inport: '<Root>/Susp_F_R_Bits'
   *  Product: '<S6>/Divide'
   *  Sum: '<S6>/Subtract1'
   */
  Sensors_Y.SUSP_F_R = (Sensors_U.Susp_F_R_Bits - 1.0) /
    Sensors_ConstB.Subtract_a * 57.0 * 30.0;

  /* Outport: '<Root>/SUSP_R_L' incorporates:
   *  Constant: '<Root>/Zero_Bits_Experimental'
   *  Gain: '<S7>/Cte muelles'
   *  Gain: '<S7>/Ltotal'
   *  Inport: '<Root>/Susp_R_L_Bits'
   *  Product: '<S7>/Divide'
   *  Sum: '<S7>/Subtract1'
   */
  Sensors_Y.SUSP_R_L = (Sensors_U.Susp_R_L_Bits - 1.0) /
    Sensors_ConstB.Subtract_e * 57.0 * 30.0;

  /* Outport: '<Root>/SUSP_R_R' incorporates:
   *  Constant: '<Root>/Zero_Bits_Experimental'
   *  Gain: '<S8>/Cte muelles'
   *  Gain: '<S8>/Ltotal'
   *  Inport: '<Root>/Susp_R_R_Bits'
   *  Product: '<S8>/Divide'
   *  Sum: '<S8>/Subtract1'
   */
  Sensors_Y.SUSP_R_R = (Sensors_U.Susp_R_R_Bits - 1.0) /
    Sensors_ConstB.Subtract_n * 57.0 * 30.0;

  /* Outputs for Atomic SubSystem: '<S4>/Low Pass' */
  /* Sum: '<S9>/Subtract1' incorporates:
   *  Constant: '<S9>/exp(-tcycle//tau)1'
   *  DataStoreRead: '<S9>/Data Store Read'
   *  DataStoreRead: '<S9>/Data Store Read1'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   */
  rtb_Subtract1_lm = Sensors_DW.Previous_IN * Sensors_ConstB.Subtract_p + 0.905 *
    Sensors_DW.Previous_OUT;

  /* DataStoreWrite: '<S9>/Data Store Write1' */
  Sensors_DW.Previous_OUT = rtb_Subtract1_lm;

  /* DataStoreWrite: '<S9>/Data Store Write' incorporates:
   *  Constant: '<S4>/half range'
   *  Constant: '<S4>/range'
   *  Constant: '<S4>/zero'
   *  Gain: '<S4>/Gain'
   *  Inport: '<Root>/SteeringSensor_Bits'
   *  Product: '<S4>/Divide'
   *  Sum: '<S4>/Sum'
   */
  Sensors_DW.Previous_IN = (Sensors_U.SteeringSensor_Bits - 250.0) * 2.0 / 500.0
    * 115.0;

  /* Outport: '<Root>/SteeringSensor_Value' incorporates:
   *  Gain: '<S9>/Gain'
   */
  Sensors_Y.SteeringSensor_Value = -rtb_Subtract1_lm;

  /* End of Outputs for SubSystem: '<S4>/Low Pass' */
}

/* Model update function */
static void Sensors_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Sensors_M->Timing.clockTick0)) {
    ++Sensors_M->Timing.clockTickH0;
  }

  Sensors_M->Timing.t[0] = Sensors_M->Timing.clockTick0 *
    Sensors_M->Timing.stepSize0 + Sensors_M->Timing.clockTickH0 *
    Sensors_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Sensors_initialize(void)
{
  /* Start for Atomic SubSystem: '<S4>/Low Pass' */
  /* Start for DataStoreMemory: '<S9>/Data Store Memory' */
  Sensors_DW.Previous_IN = 0.0;

  /* Start for DataStoreMemory: '<S9>/Data Store Memory1' */
  Sensors_DW.Previous_OUT = 0.0;

  /* End of Start for SubSystem: '<S4>/Low Pass' */
}

/* Model terminate function */
static void Sensors_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Sensors_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Sensors_update();
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
  Sensors_initialize();
}

void MdlTerminate(void)
{
  Sensors_terminate();
}

/* Registration function */
RT_MODEL_Sensors_T *Sensors(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Sensors_M, 0,
                sizeof(RT_MODEL_Sensors_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Sensors_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Sensors_M points to
       static memory which is guaranteed to be non-NULL" */
    Sensors_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Sensors_M->Timing.sampleTimes = (&Sensors_M->Timing.sampleTimesArray[0]);
    Sensors_M->Timing.offsetTimes = (&Sensors_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Sensors_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Sensors_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Sensors_M, &Sensors_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Sensors_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Sensors_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Sensors_M, 10.0);
  Sensors_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Sensors_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Sensors_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Sensors_M->rtwLogInfo, (NULL));
    rtliSetLogT(Sensors_M->rtwLogInfo, "tout");
    rtliSetLogX(Sensors_M->rtwLogInfo, "");
    rtliSetLogXFinal(Sensors_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Sensors_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Sensors_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Sensors_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Sensors_M->rtwLogInfo, 1);
    rtliSetLogY(Sensors_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Sensors_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Sensors_M->rtwLogInfo, (NULL));
  }

  Sensors_M->solverInfoPtr = (&Sensors_M->solverInfo);
  Sensors_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Sensors_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Sensors_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* states (dwork) */
  Sensors_M->dwork = ((void *) &Sensors_DW);
  (void) memset((void *)&Sensors_DW, 0,
                sizeof(DW_Sensors_T));

  /* external inputs */
  Sensors_M->inputs = (((void*)&Sensors_U));
  (void)memset(&Sensors_U, 0, sizeof(ExtU_Sensors_T));

  /* external outputs */
  Sensors_M->outputs = (&Sensors_Y);
  (void)memset(&Sensors_Y, 0, sizeof(ExtY_Sensors_T));

  /* Initialize Sizes */
  Sensors_M->Sizes.numContStates = (0);/* Number of continuous states */
  Sensors_M->Sizes.numY = (8);         /* Number of model outputs */
  Sensors_M->Sizes.numU = (8);         /* Number of model inputs */
  Sensors_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Sensors_M->Sizes.numSampTimes = (1); /* Number of sample times */
  Sensors_M->Sizes.numBlocks = (68);   /* Number of blocks */
  Sensors_M->Sizes.numBlockIO = (0);   /* Number of block outputs */
  return Sensors_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
