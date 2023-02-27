/*
 * LVD_Data_ETR07.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LVD_Data_ETR07".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue Apr 12 15:33:16 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LVD_Data_ETR07.h"
#include "LVD_Data_ETR07_private.h"

/* Block states (auto storage) */
DW_LVD_Data_ETR07_T LVD_Data_ETR07_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_LVD_Data_ETR07_T LVD_Data_ETR07_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_LVD_Data_ETR07_T LVD_Data_ETR07_Y;

/* Real-time model */
RT_MODEL_LVD_Data_ETR07_T LVD_Data_ETR07_M_;
RT_MODEL_LVD_Data_ETR07_T *const LVD_Data_ETR07_M = &LVD_Data_ETR07_M_;

/* Model output function */
static void LVD_Data_ETR07_output(void)
{
  real_T rtb_Subtract1;

  /* Outputs for Atomic SubSystem: '<Root>/Low Pass' */
  /* Sum: '<S1>/Subtract1' incorporates:
   *  Constant: '<S1>/ct'
   *  Constant: '<S1>/exp(-tcycle//tau)1'
   *  DataStoreRead: '<S1>/Data Store Read'
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Subtract'
   */
  rtb_Subtract1 = (LVD_Data_ETR07_P.ct_Value -
                   LVD_Data_ETR07_P.exptcycletau1_Value) *
    LVD_Data_ETR07_DW.Previous_IN + LVD_Data_ETR07_P.exptcycletau1_Value *
    LVD_Data_ETR07_DW.Previous_OUT;

  /* DataStoreWrite: '<S1>/Data Store Write1' */
  LVD_Data_ETR07_DW.Previous_OUT = rtb_Subtract1;

  /* DataStoreWrite: '<S1>/Data Store Write' incorporates:
   *  Constant: '<Root>/MaxBits'
   *  Constant: '<Root>/MaxBits2'
   *  Constant: '<Root>/Vmax'
   *  Constant: '<Root>/Vmin'
   *  Inport: '<Root>/LVBattery_Voltage_Bits'
   *  Product: '<Root>/Divide'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Add'
   *  Sum: '<Root>/Add1'
   *  Sum: '<Root>/Add7'
   */
  LVD_Data_ETR07_DW.Previous_IN = (LVD_Data_ETR07_P.Vmax_Value -
    LVD_Data_ETR07_P.Vmin_Value) / LVD_Data_ETR07_P.MaxBits_Value *
    (LVD_Data_ETR07_U.LVBattery_Voltage_Bits - LVD_Data_ETR07_P.MaxBits2_Value)
    + LVD_Data_ETR07_P.Vmin_Value;

  /* End of Outputs for SubSystem: '<Root>/Low Pass' */

  /* Outport: '<Root>/LVbattery_Voltage' */
  LVD_Data_ETR07_Y.LVbattery_Voltage = rtb_Subtract1;
}

/* Model update function */
static void LVD_Data_ETR07_update(void)
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
  if (!(++LVD_Data_ETR07_M->Timing.clockTick0)) {
    ++LVD_Data_ETR07_M->Timing.clockTickH0;
  }

  LVD_Data_ETR07_M->Timing.t[0] = LVD_Data_ETR07_M->Timing.clockTick0 *
    LVD_Data_ETR07_M->Timing.stepSize0 + LVD_Data_ETR07_M->Timing.clockTickH0 *
    LVD_Data_ETR07_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void LVD_Data_ETR07_initialize(void)
{
  /* Start for Atomic SubSystem: '<Root>/Low Pass' */
  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  LVD_Data_ETR07_DW.Previous_IN = LVD_Data_ETR07_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
  LVD_Data_ETR07_DW.Previous_OUT =
    LVD_Data_ETR07_P.DataStoreMemory1_InitialValue;

  /* End of Start for SubSystem: '<Root>/Low Pass' */
}

/* Model terminate function */
static void LVD_Data_ETR07_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  LVD_Data_ETR07_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  LVD_Data_ETR07_update();
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
  LVD_Data_ETR07_initialize();
}

void MdlTerminate(void)
{
  LVD_Data_ETR07_terminate();
}

/* Registration function */
RT_MODEL_LVD_Data_ETR07_T *LVD_Data_ETR07(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LVD_Data_ETR07_M, 0,
                sizeof(RT_MODEL_LVD_Data_ETR07_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = LVD_Data_ETR07_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    LVD_Data_ETR07_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    LVD_Data_ETR07_M->Timing.sampleTimes =
      (&LVD_Data_ETR07_M->Timing.sampleTimesArray[0]);
    LVD_Data_ETR07_M->Timing.offsetTimes =
      (&LVD_Data_ETR07_M->Timing.offsetTimesArray[0]);

    /* task periods */
    LVD_Data_ETR07_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    LVD_Data_ETR07_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(LVD_Data_ETR07_M, &LVD_Data_ETR07_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = LVD_Data_ETR07_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    LVD_Data_ETR07_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(LVD_Data_ETR07_M, 10.0);
  LVD_Data_ETR07_M->Timing.stepSize0 = 0.2;
  LVD_Data_ETR07_M->solverInfoPtr = (&LVD_Data_ETR07_M->solverInfo);
  LVD_Data_ETR07_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&LVD_Data_ETR07_M->solverInfo, 0.2);
  rtsiSetSolverMode(&LVD_Data_ETR07_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  LVD_Data_ETR07_M->defaultParam = ((real_T *)&LVD_Data_ETR07_P);

  /* states (dwork) */
  LVD_Data_ETR07_M->dwork = ((void *) &LVD_Data_ETR07_DW);
  (void) memset((void *)&LVD_Data_ETR07_DW, 0,
                sizeof(DW_LVD_Data_ETR07_T));

  /* external inputs */
  LVD_Data_ETR07_M->inputs = (((void*)&LVD_Data_ETR07_U));
  LVD_Data_ETR07_U.LVBattery_Voltage_Bits = 0.0;

  /* external outputs */
  LVD_Data_ETR07_M->outputs = (&LVD_Data_ETR07_Y);
  LVD_Data_ETR07_Y.LVbattery_Voltage = 0.0;

  /* Initialize Sizes */
  LVD_Data_ETR07_M->Sizes.numContStates = (0);/* Number of continuous states */
  LVD_Data_ETR07_M->Sizes.numY = (1);  /* Number of model outputs */
  LVD_Data_ETR07_M->Sizes.numU = (1);  /* Number of model inputs */
  LVD_Data_ETR07_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  LVD_Data_ETR07_M->Sizes.numSampTimes = (1);/* Number of sample times */
  LVD_Data_ETR07_M->Sizes.numBlocks = (23);/* Number of blocks */
  LVD_Data_ETR07_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  LVD_Data_ETR07_M->Sizes.numBlockPrms = (8);/* Sum of parameter "widths" */
  return LVD_Data_ETR07_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
