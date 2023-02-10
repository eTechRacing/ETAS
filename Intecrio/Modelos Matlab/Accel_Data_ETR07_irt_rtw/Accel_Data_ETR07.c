/*
 * Accel_Data_ETR07.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Accel_Data_ETR07".
 *
 * Model version              : 1.31
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue Apr 12 15:32:09 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Accel_Data_ETR07.h"
#include "Accel_Data_ETR07_private.h"

/* Block signals (auto storage) */
B_Accel_Data_ETR07_T Accel_Data_ETR07_B;

/* Block states (auto storage) */
DW_Accel_Data_ETR07_T Accel_Data_ETR07_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Accel_Data_ETR07_T Accel_Data_ETR07_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Accel_Data_ETR07_T Accel_Data_ETR07_Y;

/* Real-time model */
RT_MODEL_Accel_Data_ETR07_T Accel_Data_ETR07_M_;
RT_MODEL_Accel_Data_ETR07_T *const Accel_Data_ETR07_M = &Accel_Data_ETR07_M_;

/*
 * Output and update for atomic system:
 *    '<Root>/Acc Data Conversion F X'
 *    '<Root>/Acc Data Conversion F Y'
 *    '<Root>/Acc Data Conversion F Z'
 *    '<Root>/Acc Data Conversion R X'
 *    '<Root>/Acc Data Conversion R Y'
 *    '<Root>/Acc Data Conversion R Z'
 */
void Accel_Data__AccDataConversionFX(real_T rtu_Bits,
  B_AccDataConversionFX_Accel_D_T *localB, P_AccDataConversionFX_Accel_D_T
  *localP)
{
  /* Gain: '<S1>/Gain' incorporates:
   *  Constant: '<S1>/Experimental Offset'
   *  Constant: '<S1>/g//bit'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add'
   */
  localB->Gain = (rtu_Bits - localP->ExperimentalOffset_Value) *
    localP->gbit_Value * localP->Gain_Gain;
}

/*
 * Start for atomic system:
 *    '<Root>/Low Pass'
 *    '<Root>/Low Pass1'
 *    '<Root>/Low Pass2'
 */
void Accel_Data_ETR07_LowPass_Start(DW_LowPass_Accel_Data_ETR07_T *localDW,
  P_LowPass_Accel_Data_ETR07_T *localP)
{
  /* Start for DataStoreMemory: '<S9>/Data Store Memory' */
  localDW->Previous_IN = localP->DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<S9>/Data Store Memory1' */
  localDW->Previous_OUT = localP->DataStoreMemory1_InitialValue;
}

/*
 * Output and update for atomic system:
 *    '<Root>/Low Pass'
 *    '<Root>/Low Pass1'
 *    '<Root>/Low Pass2'
 */
void Accel_Data_ETR07_LowPass(real_T rtu_IN, B_LowPass_Accel_Data_ETR07_T
  *localB, DW_LowPass_Accel_Data_ETR07_T *localDW, P_LowPass_Accel_Data_ETR07_T *
  localP)
{
  real_T rtb_Subtract1;

  /* Sum: '<S9>/Subtract1' incorporates:
   *  Constant: '<S9>/ct'
   *  Constant: '<S9>/exp(-tcycle//tau)1'
   *  DataStoreRead: '<S9>/Data Store Read'
   *  DataStoreRead: '<S9>/Data Store Read1'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Sum: '<S9>/Subtract'
   */
  rtb_Subtract1 = (localP->exptcycletau1_Value - localP->ct_Value) *
    localDW->Previous_IN + localP->exptcycletau1_Value * localDW->Previous_OUT;

  /* DataStoreWrite: '<S9>/Data Store Write1' */
  localDW->Previous_OUT = rtb_Subtract1;

  /* DataStoreWrite: '<S9>/Data Store Write' */
  localDW->Previous_IN = rtu_IN;

  /* Gain: '<S9>/Gain' */
  localB->Gain = localP->Gain_Gain * rtb_Subtract1;
}

/* Model output function */
static void Accel_Data_ETR07_output(void)
{
  real_T rtb_Product1;
  real_T rtb_Add1;

  /* Outputs for Atomic SubSystem: '<Root>/Gyro Data Conversion R Z' */
  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S8>/Experimental Offset'
   *  Constant: '<S8>/Rps//LSB'
   *  Gain: '<Root>/Gain4'
   *  Inport: '<Root>/Gyroscope_R'
   *  Sum: '<S8>/Add2'
   */
  rtb_Product1 = (Accel_Data_ETR07_P.Gain4_Gain * Accel_Data_ETR07_U.Gyroscope_R
                  - Accel_Data_ETR07_P.ExperimentalOffset_Value_e) *
    Accel_Data_ETR07_P.RpsLSB_Value;

  /* Sum: '<S8>/Add1' incorporates:
   *  DataStoreRead: '<S8>/Data Store Read'
   */
  rtb_Add1 = rtb_Product1 + Accel_Data_ETR07_DW.A;

  /* DataStoreWrite: '<S8>/Data Store Write' */
  Accel_Data_ETR07_DW.A = rtb_Add1;

  /* Outport: '<Root>/Gyro_R_Z_Deg' incorporates:
   *  Gain: '<S8>/Cycle Time'
   */
  Accel_Data_ETR07_Y.Gyro_R_Z_Deg = Accel_Data_ETR07_P.CycleTime_Gain_h *
    rtb_Add1;

  /* End of Outputs for SubSystem: '<Root>/Gyro Data Conversion R Z' */

  /* Outport: '<Root>/Rate_R_Z_Deg//s' */
  Accel_Data_ETR07_Y.Rate_R_Z_Degs = rtb_Product1;

  /* Outputs for Atomic SubSystem: '<Root>/Acc Data Conversion F X' */

  /* Inport: '<Root>/ACCEL_F_X' */
  Accel_Data__AccDataConversionFX(Accel_Data_ETR07_U.ACCEL_F_X,
    &Accel_Data_ETR07_B.AccDataConversionFX,
    &Accel_Data_ETR07_P.AccDataConversionFX);

  /* End of Outputs for SubSystem: '<Root>/Acc Data Conversion F X' */

  /* Outport: '<Root>/Accel_F_X_SI' */
  Accel_Data_ETR07_Y.Accel_F_X_SI = Accel_Data_ETR07_B.AccDataConversionFX.Gain;

  /* Outputs for Atomic SubSystem: '<Root>/Acc Data Conversion F Y' */

  /* Inport: '<Root>/ACCEL_F_Y' */
  Accel_Data__AccDataConversionFX(Accel_Data_ETR07_U.ACCEL_F_Y,
    &Accel_Data_ETR07_B.AccDataConversionFY,
    &Accel_Data_ETR07_P.AccDataConversionFY);

  /* End of Outputs for SubSystem: '<Root>/Acc Data Conversion F Y' */

  /* Outport: '<Root>/Accel_F_Y_SI' */
  Accel_Data_ETR07_Y.Accel_F_Y_SI = Accel_Data_ETR07_B.AccDataConversionFY.Gain;

  /* Outputs for Atomic SubSystem: '<Root>/Acc Data Conversion F Z' */

  /* Inport: '<Root>/ACCEL_F_Z' */
  Accel_Data__AccDataConversionFX(Accel_Data_ETR07_U.ACCEL_F_Z,
    &Accel_Data_ETR07_B.AccDataConversionFZ,
    &Accel_Data_ETR07_P.AccDataConversionFZ);

  /* End of Outputs for SubSystem: '<Root>/Acc Data Conversion F Z' */

  /* Outport: '<Root>/Accel_F_Z_SI' */
  Accel_Data_ETR07_Y.Accel_F_Z_SI = Accel_Data_ETR07_B.AccDataConversionFZ.Gain;

  /* Outputs for Atomic SubSystem: '<Root>/Gyro Data Conversion F Z' */
  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/(º//s)//bit'
   *  Constant: '<S7>/Experimental Offset'
   *  Gain: '<Root>/Gain2'
   *  Inport: '<Root>/Gyroscope_F'
   *  Sum: '<S7>/Add'
   */
  rtb_Product1 = (Accel_Data_ETR07_P.Gain2_Gain * Accel_Data_ETR07_U.Gyroscope_F
                  - Accel_Data_ETR07_P.ExperimentalOffset_Value) *
    Accel_Data_ETR07_P.sbit_Value;

  /* Sum: '<S7>/Add1' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read'
   */
  rtb_Add1 = rtb_Product1 + Accel_Data_ETR07_DW.A_f;

  /* DataStoreWrite: '<S7>/Data Store Write' */
  Accel_Data_ETR07_DW.A_f = rtb_Add1;

  /* Outport: '<Root>/Gyro_F_Z_Deg' incorporates:
   *  Gain: '<S7>/Cycle Time'
   */
  Accel_Data_ETR07_Y.Gyro_F_Z_Deg = Accel_Data_ETR07_P.CycleTime_Gain * rtb_Add1;

  /* End of Outputs for SubSystem: '<Root>/Gyro Data Conversion F Z' */

  /* Outport: '<Root>/Rate_F_Z_Deg//s2' */
  Accel_Data_ETR07_Y.Rate_F_Z_Degs2 = rtb_Product1;

  /* Outputs for Atomic SubSystem: '<Root>/Acc Data Conversion R X' */

  /* Inport: '<Root>/ACCEL_R_X' */
  Accel_Data__AccDataConversionFX(Accel_Data_ETR07_U.ACCEL_R_X,
    &Accel_Data_ETR07_B.AccDataConversionRX,
    &Accel_Data_ETR07_P.AccDataConversionRX);

  /* End of Outputs for SubSystem: '<Root>/Acc Data Conversion R X' */

  /* Outputs for Atomic SubSystem: '<Root>/Low Pass2' */
  Accel_Data_ETR07_LowPass(Accel_Data_ETR07_B.AccDataConversionRX.Gain,
    &Accel_Data_ETR07_B.LowPass2, &Accel_Data_ETR07_DW.LowPass2,
    &Accel_Data_ETR07_P.LowPass2);

  /* End of Outputs for SubSystem: '<Root>/Low Pass2' */

  /* Outport: '<Root>/Accel_R_X_SI' */
  Accel_Data_ETR07_Y.Accel_R_X_SI = Accel_Data_ETR07_B.LowPass2.Gain;

  /* Outputs for Atomic SubSystem: '<Root>/Acc Data Conversion R Y' */

  /* Inport: '<Root>/ACCEL_R_Y' */
  Accel_Data__AccDataConversionFX(Accel_Data_ETR07_U.ACCEL_R_Y,
    &Accel_Data_ETR07_B.AccDataConversionRY,
    &Accel_Data_ETR07_P.AccDataConversionRY);

  /* End of Outputs for SubSystem: '<Root>/Acc Data Conversion R Y' */

  /* Outputs for Atomic SubSystem: '<Root>/Low Pass1' */
  Accel_Data_ETR07_LowPass(Accel_Data_ETR07_B.AccDataConversionRY.Gain,
    &Accel_Data_ETR07_B.LowPass1, &Accel_Data_ETR07_DW.LowPass1,
    &Accel_Data_ETR07_P.LowPass1);

  /* End of Outputs for SubSystem: '<Root>/Low Pass1' */

  /* Outport: '<Root>/Accel_R_Y_SI' */
  Accel_Data_ETR07_Y.Accel_R_Y_SI = Accel_Data_ETR07_B.LowPass1.Gain;

  /* Outputs for Atomic SubSystem: '<Root>/Acc Data Conversion R Z' */

  /* Inport: '<Root>/ACCEL_R_Z' */
  Accel_Data__AccDataConversionFX(Accel_Data_ETR07_U.ACCEL_R_Z,
    &Accel_Data_ETR07_B.AccDataConversionRZ,
    &Accel_Data_ETR07_P.AccDataConversionRZ);

  /* End of Outputs for SubSystem: '<Root>/Acc Data Conversion R Z' */

  /* Outputs for Atomic SubSystem: '<Root>/Low Pass' */
  Accel_Data_ETR07_LowPass(Accel_Data_ETR07_B.AccDataConversionRZ.Gain,
    &Accel_Data_ETR07_B.LowPass, &Accel_Data_ETR07_DW.LowPass,
    &Accel_Data_ETR07_P.LowPass);

  /* End of Outputs for SubSystem: '<Root>/Low Pass' */

  /* Outport: '<Root>/Accel_R_Z_SI' */
  Accel_Data_ETR07_Y.Accel_R_Z_SI = Accel_Data_ETR07_B.LowPass.Gain;
}

/* Model update function */
static void Accel_Data_ETR07_update(void)
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
  if (!(++Accel_Data_ETR07_M->Timing.clockTick0)) {
    ++Accel_Data_ETR07_M->Timing.clockTickH0;
  }

  Accel_Data_ETR07_M->Timing.t[0] = Accel_Data_ETR07_M->Timing.clockTick0 *
    Accel_Data_ETR07_M->Timing.stepSize0 +
    Accel_Data_ETR07_M->Timing.clockTickH0 *
    Accel_Data_ETR07_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Accel_Data_ETR07_initialize(void)
{
  /* Start for Atomic SubSystem: '<Root>/Gyro Data Conversion R Z' */
  /* Start for DataStoreMemory: '<S8>/Data Store Memory' */
  Accel_Data_ETR07_DW.A = Accel_Data_ETR07_P.DataStoreMemory_InitialValue_m;

  /* End of Start for SubSystem: '<Root>/Gyro Data Conversion R Z' */

  /* Start for Atomic SubSystem: '<Root>/Gyro Data Conversion F Z' */
  /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
  Accel_Data_ETR07_DW.A_f = Accel_Data_ETR07_P.DataStoreMemory_InitialValue;

  /* End of Start for SubSystem: '<Root>/Gyro Data Conversion F Z' */

  /* Start for Atomic SubSystem: '<Root>/Low Pass2' */
  Accel_Data_ETR07_LowPass_Start(&Accel_Data_ETR07_DW.LowPass2,
    &Accel_Data_ETR07_P.LowPass2);

  /* End of Start for SubSystem: '<Root>/Low Pass2' */

  /* Start for Atomic SubSystem: '<Root>/Low Pass1' */
  Accel_Data_ETR07_LowPass_Start(&Accel_Data_ETR07_DW.LowPass1,
    &Accel_Data_ETR07_P.LowPass1);

  /* End of Start for SubSystem: '<Root>/Low Pass1' */

  /* Start for Atomic SubSystem: '<Root>/Low Pass' */
  Accel_Data_ETR07_LowPass_Start(&Accel_Data_ETR07_DW.LowPass,
    &Accel_Data_ETR07_P.LowPass);

  /* End of Start for SubSystem: '<Root>/Low Pass' */
}

/* Model terminate function */
static void Accel_Data_ETR07_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Accel_Data_ETR07_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Accel_Data_ETR07_update();
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
  Accel_Data_ETR07_initialize();
}

void MdlTerminate(void)
{
  Accel_Data_ETR07_terminate();
}

/* Registration function */
RT_MODEL_Accel_Data_ETR07_T *Accel_Data_ETR07(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Accel_Data_ETR07_M, 0,
                sizeof(RT_MODEL_Accel_Data_ETR07_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Accel_Data_ETR07_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Accel_Data_ETR07_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Accel_Data_ETR07_M->Timing.sampleTimes =
      (&Accel_Data_ETR07_M->Timing.sampleTimesArray[0]);
    Accel_Data_ETR07_M->Timing.offsetTimes =
      (&Accel_Data_ETR07_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Accel_Data_ETR07_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Accel_Data_ETR07_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Accel_Data_ETR07_M, &Accel_Data_ETR07_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Accel_Data_ETR07_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Accel_Data_ETR07_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Accel_Data_ETR07_M, 10.0);
  Accel_Data_ETR07_M->Timing.stepSize0 = 0.2;
  Accel_Data_ETR07_M->solverInfoPtr = (&Accel_Data_ETR07_M->solverInfo);
  Accel_Data_ETR07_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Accel_Data_ETR07_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Accel_Data_ETR07_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Accel_Data_ETR07_M->blockIO = ((void *) &Accel_Data_ETR07_B);
  (void) memset(((void *) &Accel_Data_ETR07_B), 0,
                sizeof(B_Accel_Data_ETR07_T));

  /* parameters */
  Accel_Data_ETR07_M->defaultParam = ((real_T *)&Accel_Data_ETR07_P);

  /* states (dwork) */
  Accel_Data_ETR07_M->dwork = ((void *) &Accel_Data_ETR07_DW);
  (void) memset((void *)&Accel_Data_ETR07_DW, 0,
                sizeof(DW_Accel_Data_ETR07_T));

  /* external inputs */
  Accel_Data_ETR07_M->inputs = (((void*)&Accel_Data_ETR07_U));
  (void)memset((void *)&Accel_Data_ETR07_U, 0, sizeof(ExtU_Accel_Data_ETR07_T));

  /* external outputs */
  Accel_Data_ETR07_M->outputs = (&Accel_Data_ETR07_Y);
  (void) memset((void *)&Accel_Data_ETR07_Y, 0,
                sizeof(ExtY_Accel_Data_ETR07_T));

  /* Initialize Sizes */
  Accel_Data_ETR07_M->Sizes.numContStates = (0);/* Number of continuous states */
  Accel_Data_ETR07_M->Sizes.numY = (10);/* Number of model outputs */
  Accel_Data_ETR07_M->Sizes.numU = (8);/* Number of model inputs */
  Accel_Data_ETR07_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Accel_Data_ETR07_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Accel_Data_ETR07_M->Sizes.numBlocks = (59);/* Number of blocks */
  Accel_Data_ETR07_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  Accel_Data_ETR07_M->Sizes.numBlockPrms = (43);/* Sum of parameter "widths" */
  return Accel_Data_ETR07_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
