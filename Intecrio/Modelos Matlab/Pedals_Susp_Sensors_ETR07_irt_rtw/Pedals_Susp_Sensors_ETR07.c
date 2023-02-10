/*
 * Pedals_Susp_Sensors_ETR07.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Pedals_Susp_Sensors_ETR07".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Jun 18 14:26:23 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pedals_Susp_Sensors_ETR07.h"
#include "Pedals_Susp_Sensors_ETR07_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Pedals_Susp_Sensors_ETR0_T Pedals_Susp_Sensors_ETR07_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Pedals_Susp_Sensors_ETR0_T Pedals_Susp_Sensors_ETR07_Y;

/* Real-time model */
RT_MODEL_Pedals_Susp_Sensors__T Pedals_Susp_Sensors_ETR07_M_;
RT_MODEL_Pedals_Susp_Sensors__T *const Pedals_Susp_Sensors_ETR07_M =
  &Pedals_Susp_Sensors_ETR07_M_;

/* Model output function */
static void Pedals_Susp_Sensors_ETR07_output(void)
{
  real_T rtb_Divide;

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/max'
   *  Constant: '<S3>/min'
   *  Inport: '<Root>/BrakeSensor_Bits'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Divide = (Pedals_Susp_Sensors_ETR07_U.BrakeSensor_Bits -
                Pedals_Susp_Sensors_ETR07_P.min_Value) /
    (Pedals_Susp_Sensors_ETR07_P.max_Value -
     Pedals_Susp_Sensors_ETR07_P.min_Value);

  /* Outputs for Atomic SubSystem: '<Root>/Brake_Light' */
  /* If: '<S4>/If' incorporates:
   *  Constant: '<S4>/Brake_Light_Threshold'
   */
  if (rtb_Divide > Pedals_Susp_Sensors_ETR07_P.Brake_Light_Threshold_Value) {
    /* Outputs for IfAction SubSystem: '<S4>/Brake_Light_ON' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Outport: '<Root>/BrakeLight_Control' incorporates:
     *  Constant: '<S10>/ON'
     */
    Pedals_Susp_Sensors_ETR07_Y.BrakeLight_Control =
      Pedals_Susp_Sensors_ETR07_P.ON_Value;

    /* End of Outputs for SubSystem: '<S4>/Brake_Light_ON' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/Brake_Light_OFF' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Outport: '<Root>/BrakeLight_Control' incorporates:
     *  Constant: '<S9>/Off'
     */
    Pedals_Susp_Sensors_ETR07_Y.BrakeLight_Control =
      Pedals_Susp_Sensors_ETR07_P.Off_Value;

    /* End of Outputs for SubSystem: '<S4>/Brake_Light_OFF' */
  }

  /* End of If: '<S4>/If' */
  /* End of Outputs for SubSystem: '<Root>/Brake_Light' */

  /* Outport: '<Root>/BrakeSensor_Value' */
  Pedals_Susp_Sensors_ETR07_Y.BrakeSensor_Value = rtb_Divide;

  /* Outport: '<Root>/APPS1_Value' incorporates:
   *  Constant: '<S1>/max'
   *  Constant: '<S1>/min'
   *  Inport: '<Root>/APPS1_Bits'
   *  Product: '<S1>/Divide'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  Pedals_Susp_Sensors_ETR07_Y.APPS1_Value =
    (Pedals_Susp_Sensors_ETR07_U.APPS1_Bits -
     Pedals_Susp_Sensors_ETR07_P.min_Value_a) /
    (Pedals_Susp_Sensors_ETR07_P.max_Value_f -
     Pedals_Susp_Sensors_ETR07_P.min_Value_a);

  /* Outport: '<Root>/APPS2_Value' incorporates:
   *  Constant: '<S2>/max'
   *  Constant: '<S2>/min'
   *  Inport: '<Root>/APPS2_Bits'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  Pedals_Susp_Sensors_ETR07_Y.APPS2_Value =
    (Pedals_Susp_Sensors_ETR07_U.APPS2_Bits -
     Pedals_Susp_Sensors_ETR07_P.min_Value_g) /
    (Pedals_Susp_Sensors_ETR07_P.max_Value_a -
     Pedals_Susp_Sensors_ETR07_P.min_Value_g);

  /* Outport: '<Root>/SUSP_F_L' incorporates:
   *  Constant: '<S5>/Experimental_Zero'
   *  Constant: '<S5>/bitsmax '
   *  Gain: '<S5>/Cte muelles'
   *  Gain: '<S5>/Ltotal'
   *  Inport: '<Root>/Susp_F_L_Bits'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Sum'
   */
  Pedals_Susp_Sensors_ETR07_Y.SUSP_F_L =
    ((Pedals_Susp_Sensors_ETR07_P.bitsmax_Value -
      Pedals_Susp_Sensors_ETR07_U.Susp_F_L_Bits) -
     Pedals_Susp_Sensors_ETR07_P.Experimental_Zero_Value) /
    Pedals_Susp_Sensors_ETR07_U.Susp_F_L_Bits *
    Pedals_Susp_Sensors_ETR07_P.Ltotal_Gain *
    Pedals_Susp_Sensors_ETR07_P.Ctemuelles_Gain;

  /* Outport: '<Root>/SUSP_F_R' incorporates:
   *  Constant: '<S6>/Experimental_Zero'
   *  Constant: '<S6>/bitsmax '
   *  Gain: '<S6>/Cte muelles'
   *  Gain: '<S6>/Ltotal'
   *  Inport: '<Root>/Susp_F_R_Bits'
   *  Product: '<S6>/Divide'
   *  Sum: '<S6>/Sum'
   */
  Pedals_Susp_Sensors_ETR07_Y.SUSP_F_R =
    ((Pedals_Susp_Sensors_ETR07_P.bitsmax_Value_e -
      Pedals_Susp_Sensors_ETR07_U.Susp_F_R_Bits) -
     Pedals_Susp_Sensors_ETR07_P.Experimental_Zero_Value_e) /
    Pedals_Susp_Sensors_ETR07_U.Susp_F_R_Bits *
    Pedals_Susp_Sensors_ETR07_P.Ltotal_Gain_c *
    Pedals_Susp_Sensors_ETR07_P.Ctemuelles_Gain_e;

  /* Outport: '<Root>/SUSP_R_L' incorporates:
   *  Constant: '<S7>/Experimental_Zero'
   *  Constant: '<S7>/bitsmax '
   *  Gain: '<S7>/Cte muelles'
   *  Gain: '<S7>/Ltotal'
   *  Inport: '<Root>/Susp_R_L_Bits'
   *  Product: '<S7>/Divide'
   *  Sum: '<S7>/Sum'
   */
  Pedals_Susp_Sensors_ETR07_Y.SUSP_R_L =
    ((Pedals_Susp_Sensors_ETR07_P.bitsmax_Value_g -
      Pedals_Susp_Sensors_ETR07_U.Susp_R_L_Bits) -
     Pedals_Susp_Sensors_ETR07_P.Experimental_Zero_Value_f) /
    Pedals_Susp_Sensors_ETR07_U.Susp_R_L_Bits *
    Pedals_Susp_Sensors_ETR07_P.Ltotal_Gain_d *
    Pedals_Susp_Sensors_ETR07_P.Ctemuelles_Gain_j;

  /* Outport: '<Root>/SUSP_R_R' incorporates:
   *  Constant: '<S8>/Experimental_Zero'
   *  Constant: '<S8>/bitsmax '
   *  Gain: '<S8>/Cte muelles'
   *  Gain: '<S8>/Ltotal'
   *  Inport: '<Root>/Susp_R_R_Bits'
   *  Product: '<S8>/Divide'
   *  Sum: '<S8>/Sum'
   */
  Pedals_Susp_Sensors_ETR07_Y.SUSP_R_R =
    ((Pedals_Susp_Sensors_ETR07_P.bitsmax_Value_n -
      Pedals_Susp_Sensors_ETR07_U.Susp_R_R_Bits) -
     Pedals_Susp_Sensors_ETR07_P.Experimental_Zero_Value_a) /
    Pedals_Susp_Sensors_ETR07_U.Susp_R_R_Bits *
    Pedals_Susp_Sensors_ETR07_P.Ltotal_Gain_e *
    Pedals_Susp_Sensors_ETR07_P.Ctemuelles_Gain_f;
}

/* Model update function */
static void Pedals_Susp_Sensors_ETR07_update(void)
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
  if (!(++Pedals_Susp_Sensors_ETR07_M->Timing.clockTick0)) {
    ++Pedals_Susp_Sensors_ETR07_M->Timing.clockTickH0;
  }

  Pedals_Susp_Sensors_ETR07_M->Timing.t[0] =
    Pedals_Susp_Sensors_ETR07_M->Timing.clockTick0 *
    Pedals_Susp_Sensors_ETR07_M->Timing.stepSize0 +
    Pedals_Susp_Sensors_ETR07_M->Timing.clockTickH0 *
    Pedals_Susp_Sensors_ETR07_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Pedals_Susp_Sensors_ETR07_initialize(void)
{
}

/* Model terminate function */
static void Pedals_Susp_Sensors_ETR07_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Pedals_Susp_Sensors_ETR07_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Pedals_Susp_Sensors_ETR07_update();
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
  Pedals_Susp_Sensors_ETR07_initialize();
}

void MdlTerminate(void)
{
  Pedals_Susp_Sensors_ETR07_terminate();
}

/* Registration function */
RT_MODEL_Pedals_Susp_Sensors__T *Pedals_Susp_Sensors_ETR07(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Pedals_Susp_Sensors_ETR07_M, 0,
                sizeof(RT_MODEL_Pedals_Susp_Sensors__T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Pedals_Susp_Sensors_ETR07_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Pedals_Susp_Sensors_ETR07_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Pedals_Susp_Sensors_ETR07_M->Timing.sampleTimes =
      (&Pedals_Susp_Sensors_ETR07_M->Timing.sampleTimesArray[0]);
    Pedals_Susp_Sensors_ETR07_M->Timing.offsetTimes =
      (&Pedals_Susp_Sensors_ETR07_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Pedals_Susp_Sensors_ETR07_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Pedals_Susp_Sensors_ETR07_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Pedals_Susp_Sensors_ETR07_M,
             &Pedals_Susp_Sensors_ETR07_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Pedals_Susp_Sensors_ETR07_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Pedals_Susp_Sensors_ETR07_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Pedals_Susp_Sensors_ETR07_M, 10.0);
  Pedals_Susp_Sensors_ETR07_M->Timing.stepSize0 = 0.2;
  Pedals_Susp_Sensors_ETR07_M->solverInfoPtr =
    (&Pedals_Susp_Sensors_ETR07_M->solverInfo);
  Pedals_Susp_Sensors_ETR07_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Pedals_Susp_Sensors_ETR07_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Pedals_Susp_Sensors_ETR07_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* parameters */
  Pedals_Susp_Sensors_ETR07_M->defaultParam = ((real_T *)
    &Pedals_Susp_Sensors_ETR07_P);

  /* external inputs */
  Pedals_Susp_Sensors_ETR07_M->inputs = (((void*)&Pedals_Susp_Sensors_ETR07_U));
  (void)memset((void *)&Pedals_Susp_Sensors_ETR07_U, 0, sizeof
               (ExtU_Pedals_Susp_Sensors_ETR0_T));

  /* external outputs */
  Pedals_Susp_Sensors_ETR07_M->outputs = (&Pedals_Susp_Sensors_ETR07_Y);
  (void) memset((void *)&Pedals_Susp_Sensors_ETR07_Y, 0,
                sizeof(ExtY_Pedals_Susp_Sensors_ETR0_T));

  /* Initialize Sizes */
  Pedals_Susp_Sensors_ETR07_M->Sizes.numContStates = (0);/* Number of continuous states */
  Pedals_Susp_Sensors_ETR07_M->Sizes.numY = (8);/* Number of model outputs */
  Pedals_Susp_Sensors_ETR07_M->Sizes.numU = (7);/* Number of model inputs */
  Pedals_Susp_Sensors_ETR07_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Pedals_Susp_Sensors_ETR07_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Pedals_Susp_Sensors_ETR07_M->Sizes.numBlocks = (57);/* Number of blocks */
  Pedals_Susp_Sensors_ETR07_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  Pedals_Susp_Sensors_ETR07_M->Sizes.numBlockPrms = (25);/* Sum of parameter "widths" */
  return Pedals_Susp_Sensors_ETR07_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
