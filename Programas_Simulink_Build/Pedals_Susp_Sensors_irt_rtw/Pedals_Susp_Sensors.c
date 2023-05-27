/*
 * Pedals_Susp_Sensors.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Pedals_Susp_Sensors".
 *
 * Model version              : 1.37
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 12:59:21 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pedals_Susp_Sensors.h"
#include "Pedals_Susp_Sensors_private.h"

/* Block signals (auto storage) */
B_Pedals_Susp_Sensors_T Pedals_Susp_Sensors_B;

/* Block states (auto storage) */
DW_Pedals_Susp_Sensors_T Pedals_Susp_Sensors_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Pedals_Susp_Sensors_T Pedals_Susp_Sensors_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Pedals_Susp_Sensors_T Pedals_Susp_Sensors_Y;

/* Real-time model */
RT_MODEL_Pedals_Susp_Sensors_T Pedals_Susp_Sensors_M_;
RT_MODEL_Pedals_Susp_Sensors_T *const Pedals_Susp_Sensors_M =
  &Pedals_Susp_Sensors_M_;

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function'
 *    '<S6>/MATLAB Function'
 *    '<S7>/MATLAB Function'
 *    '<S8>/MATLAB Function'
 */
void Pedals_Susp_Sens_MATLABFunction(real_T rtu_Suspe, real_T rtu_elapsed_time,
  real_T rtu_ZeroExperimental_ant, B_MATLABFunction_Pedals_Susp__T *localB)
{
  int32_T cont;
  real_T SuspeTotal;
  if (rtu_elapsed_time < 0.6) {
    SuspeTotal = rtu_Suspe;
    for (cont = 0; cont < 99; cont++) {
      SuspeTotal += rtu_Suspe;
    }

    localB->ZeroExperimental = SuspeTotal / 100.0;
  } else {
    localB->ZeroExperimental = rtu_ZeroExperimental_ant;
  }
}

/* Model output function */
static void Pedals_Susp_Sensors_output(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T rtb_DataStoreRead;
  real_T rtb_Clock_a;
  real_T rtb_DataStoreRead_d;
  real_T rtb_Clock_k;
  real_T rtb_DataStoreRead_k;
  real_T rtb_Clock_j;
  real_T rtb_DataStoreRead_b;
  real_T rtb_Divide_lj;

  /* Clock: '<S5>/Clock' */
  rtb_Clock = Pedals_Susp_Sensors_M->Timing.t[0];

  /* DataStoreRead: '<S5>/Data Store Read' */
  rtb_DataStoreRead = Pedals_Susp_Sensors_DW.Z_E;

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Susp_F_L_Bits'
   */
  Pedals_Susp_Sens_MATLABFunction(Pedals_Susp_Sensors_U.Susp_F_L_Bits, rtb_Clock,
    rtb_DataStoreRead, &Pedals_Susp_Sensors_B.sf_MATLABFunction);

  /* DataStoreWrite: '<S5>/Data Store Write' */
  Pedals_Susp_Sensors_DW.Z_E =
    Pedals_Susp_Sensors_B.sf_MATLABFunction.ZeroExperimental;

  /* Constant: '<S5>/bitsmax ' */
  Pedals_Susp_Sensors_B.bitsmax = Pedals_Susp_Sensors_P.bitsmax_Value;

  /* Clock: '<S6>/Clock' */
  rtb_Clock_a = Pedals_Susp_Sensors_M->Timing.t[0];

  /* DataStoreRead: '<S6>/Data Store Read' */
  rtb_DataStoreRead_d = Pedals_Susp_Sensors_DW.Z_E_d;

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Susp_F_R_Bits'
   */
  Pedals_Susp_Sens_MATLABFunction(Pedals_Susp_Sensors_U.Susp_F_R_Bits,
    rtb_Clock_a, rtb_DataStoreRead_d, &Pedals_Susp_Sensors_B.sf_MATLABFunction_k);

  /* DataStoreWrite: '<S6>/Data Store Write' */
  Pedals_Susp_Sensors_DW.Z_E_d =
    Pedals_Susp_Sensors_B.sf_MATLABFunction_k.ZeroExperimental;

  /* Constant: '<S6>/bitsmax ' */
  Pedals_Susp_Sensors_B.bitsmax_p = Pedals_Susp_Sensors_P.bitsmax_Value_e;

  /* Clock: '<S7>/Clock' */
  rtb_Clock_k = Pedals_Susp_Sensors_M->Timing.t[0];

  /* DataStoreRead: '<S7>/Data Store Read' */
  rtb_DataStoreRead_k = Pedals_Susp_Sensors_DW.Z_E_h;

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Susp_R_L_Bits'
   */
  Pedals_Susp_Sens_MATLABFunction(Pedals_Susp_Sensors_U.Susp_R_L_Bits,
    rtb_Clock_k, rtb_DataStoreRead_k, &Pedals_Susp_Sensors_B.sf_MATLABFunction_b);

  /* DataStoreWrite: '<S7>/Data Store Write' */
  Pedals_Susp_Sensors_DW.Z_E_h =
    Pedals_Susp_Sensors_B.sf_MATLABFunction_b.ZeroExperimental;

  /* Constant: '<S7>/bitsmax' */
  Pedals_Susp_Sensors_B.bitsmax_o = Pedals_Susp_Sensors_P.bitsmax_Value_o;

  /* Clock: '<S8>/Clock' */
  rtb_Clock_j = Pedals_Susp_Sensors_M->Timing.t[0];

  /* DataStoreRead: '<S8>/Data Store Read' */
  rtb_DataStoreRead_b = Pedals_Susp_Sensors_DW.Z_E_p;

  /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Susp_R_R_Bits'
   */
  Pedals_Susp_Sens_MATLABFunction(Pedals_Susp_Sensors_U.Susp_R_R_Bits,
    rtb_Clock_j, rtb_DataStoreRead_b, &Pedals_Susp_Sensors_B.sf_MATLABFunction_h);

  /* DataStoreWrite: '<S8>/Data Store Write' */
  Pedals_Susp_Sensors_DW.Z_E_p =
    Pedals_Susp_Sensors_B.sf_MATLABFunction_h.ZeroExperimental;

  /* Constant: '<S8>/bitsmax' */
  Pedals_Susp_Sensors_B.bitsmax_n = Pedals_Susp_Sensors_P.bitsmax_Value_b;

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/max'
   *  Constant: '<S3>/min'
   *  Inport: '<Root>/BrakeSensor_Bits'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Divide_lj = (Pedals_Susp_Sensors_U.BrakeSensor_Bits -
                   Pedals_Susp_Sensors_P.min_Value) /
    (Pedals_Susp_Sensors_P.max_Value - Pedals_Susp_Sensors_P.min_Value);

  /* Outputs for Atomic SubSystem: '<Root>/Brake_Light' */
  /* If: '<S4>/If' incorporates:
   *  Constant: '<S4>/Brake_Light_Threshold'
   */
  if (rtb_Divide_lj > Pedals_Susp_Sensors_P.Brake_Light_Threshold_Value) {
    /* Outputs for IfAction SubSystem: '<S4>/Brake_Light_ON' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Outport: '<Root>/BrakeLight_Control' incorporates:
     *  Constant: '<S10>/ON'
     */
    Pedals_Susp_Sensors_Y.BrakeLight_Control = Pedals_Susp_Sensors_P.ON_Value;

    /* End of Outputs for SubSystem: '<S4>/Brake_Light_ON' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/Brake_Light_OFF' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Outport: '<Root>/BrakeLight_Control' incorporates:
     *  Constant: '<S9>/Off'
     */
    Pedals_Susp_Sensors_Y.BrakeLight_Control = Pedals_Susp_Sensors_P.Off_Value;

    /* End of Outputs for SubSystem: '<S4>/Brake_Light_OFF' */
  }

  /* End of If: '<S4>/If' */
  /* End of Outputs for SubSystem: '<Root>/Brake_Light' */

  /* Outport: '<Root>/BrakeSensor_Value' */
  Pedals_Susp_Sensors_Y.BrakeSensor_Value = rtb_Divide_lj;

  /* Outport: '<Root>/APPS1_Value' incorporates:
   *  Constant: '<S1>/max'
   *  Constant: '<S1>/min'
   *  Inport: '<Root>/APPS1_Bits'
   *  Product: '<S1>/Divide'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  Pedals_Susp_Sensors_Y.APPS1_Value = (Pedals_Susp_Sensors_U.APPS1_Bits -
    Pedals_Susp_Sensors_P.min_Value_a) / (Pedals_Susp_Sensors_P.max_Value_f -
    Pedals_Susp_Sensors_P.min_Value_a);

  /* Outport: '<Root>/APPS2_Value' incorporates:
   *  Constant: '<S2>/max'
   *  Constant: '<S2>/min'
   *  Inport: '<Root>/APPS2_Bits'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  Pedals_Susp_Sensors_Y.APPS2_Value = (Pedals_Susp_Sensors_U.APPS2_Bits -
    Pedals_Susp_Sensors_P.min_Value_g) / (Pedals_Susp_Sensors_P.max_Value_a -
    Pedals_Susp_Sensors_P.min_Value_g);

  /* Outport: '<Root>/SUSP_F_L' incorporates:
   *  Gain: '<S5>/Cte muelles'
   *  Gain: '<S5>/Ltotal'
   *  Inport: '<Root>/Susp_F_L_Bits'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Sum'
   */
  Pedals_Susp_Sensors_Y.SUSP_F_L = ((Pedals_Susp_Sensors_B.bitsmax -
    Pedals_Susp_Sensors_U.Susp_F_L_Bits) -
    Pedals_Susp_Sensors_B.sf_MATLABFunction.ZeroExperimental) /
    Pedals_Susp_Sensors_U.Susp_F_L_Bits * Pedals_Susp_Sensors_P.Ltotal_Gain *
    Pedals_Susp_Sensors_P.Ctemuelles_Gain;

  /* Outport: '<Root>/SUSP_F_R' incorporates:
   *  Gain: '<S6>/Cte muelles'
   *  Gain: '<S6>/Ltotal'
   *  Inport: '<Root>/Susp_F_R_Bits'
   *  Product: '<S6>/Divide'
   *  Sum: '<S6>/Sum'
   */
  Pedals_Susp_Sensors_Y.SUSP_F_R = ((Pedals_Susp_Sensors_B.bitsmax_p -
    Pedals_Susp_Sensors_U.Susp_F_R_Bits) -
    Pedals_Susp_Sensors_B.sf_MATLABFunction_k.ZeroExperimental) /
    Pedals_Susp_Sensors_U.Susp_F_R_Bits * Pedals_Susp_Sensors_P.Ltotal_Gain_c *
    Pedals_Susp_Sensors_P.Ctemuelles_Gain_e;

  /* Outport: '<Root>/SUSP_R_L' incorporates:
   *  Gain: '<S7>/Cte muelles'
   *  Gain: '<S7>/Ltotal'
   *  Inport: '<Root>/Susp_R_L_Bits'
   *  Product: '<S7>/Divide1'
   *  Sum: '<S7>/Sum1'
   */
  Pedals_Susp_Sensors_Y.SUSP_R_L = ((Pedals_Susp_Sensors_B.bitsmax_o -
    Pedals_Susp_Sensors_U.Susp_R_L_Bits) -
    Pedals_Susp_Sensors_B.sf_MATLABFunction_b.ZeroExperimental) /
    Pedals_Susp_Sensors_U.Susp_R_L_Bits * Pedals_Susp_Sensors_P.Ltotal_Gain_h *
    Pedals_Susp_Sensors_P.Ctemuelles_Gain_a;

  /* Outport: '<Root>/SUSP_R_R' incorporates:
   *  Gain: '<S8>/Cte muelles'
   *  Gain: '<S8>/Ltotal'
   *  Inport: '<Root>/Susp_R_R_Bits'
   *  Product: '<S8>/Divide1'
   *  Sum: '<S8>/Sum1'
   */
  Pedals_Susp_Sensors_Y.SUSP_R_R = ((Pedals_Susp_Sensors_B.bitsmax_n -
    Pedals_Susp_Sensors_U.Susp_R_R_Bits) -
    Pedals_Susp_Sensors_B.sf_MATLABFunction_h.ZeroExperimental) /
    Pedals_Susp_Sensors_U.Susp_R_R_Bits * Pedals_Susp_Sensors_P.Ltotal_Gain_j *
    Pedals_Susp_Sensors_P.Ctemuelles_Gain_g;
}

/* Model update function */
static void Pedals_Susp_Sensors_update(void)
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
  if (!(++Pedals_Susp_Sensors_M->Timing.clockTick0)) {
    ++Pedals_Susp_Sensors_M->Timing.clockTickH0;
  }

  Pedals_Susp_Sensors_M->Timing.t[0] = Pedals_Susp_Sensors_M->Timing.clockTick0 *
    Pedals_Susp_Sensors_M->Timing.stepSize0 +
    Pedals_Susp_Sensors_M->Timing.clockTickH0 *
    Pedals_Susp_Sensors_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++Pedals_Susp_Sensors_M->Timing.clockTick1)) {
      ++Pedals_Susp_Sensors_M->Timing.clockTickH1;
    }

    Pedals_Susp_Sensors_M->Timing.t[1] =
      Pedals_Susp_Sensors_M->Timing.clockTick1 *
      Pedals_Susp_Sensors_M->Timing.stepSize1 +
      Pedals_Susp_Sensors_M->Timing.clockTickH1 *
      Pedals_Susp_Sensors_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void Pedals_Susp_Sensors_initialize(void)
{
  /* Start for DataStoreMemory: '<S5>/Data Store Memory' */
  Pedals_Susp_Sensors_DW.Z_E =
    Pedals_Susp_Sensors_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<S6>/Data Store Memory' */
  Pedals_Susp_Sensors_DW.Z_E_d =
    Pedals_Susp_Sensors_P.DataStoreMemory_InitialValue_m;

  /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
  Pedals_Susp_Sensors_DW.Z_E_h =
    Pedals_Susp_Sensors_P.DataStoreMemory_InitialValue_b;

  /* Start for DataStoreMemory: '<S8>/Data Store Memory' */
  Pedals_Susp_Sensors_DW.Z_E_p =
    Pedals_Susp_Sensors_P.DataStoreMemory_InitialValue_l;
}

/* Model terminate function */
static void Pedals_Susp_Sensors_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Pedals_Susp_Sensors_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Pedals_Susp_Sensors_update();
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
  Pedals_Susp_Sensors_initialize();
}

void MdlTerminate(void)
{
  Pedals_Susp_Sensors_terminate();
}

/* Registration function */
RT_MODEL_Pedals_Susp_Sensors_T *Pedals_Susp_Sensors(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Pedals_Susp_Sensors_M, 0,
                sizeof(RT_MODEL_Pedals_Susp_Sensors_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Pedals_Susp_Sensors_M->solverInfo,
                          &Pedals_Susp_Sensors_M->Timing.simTimeStep);
    rtsiSetTPtr(&Pedals_Susp_Sensors_M->solverInfo, &rtmGetTPtr
                (Pedals_Susp_Sensors_M));
    rtsiSetStepSizePtr(&Pedals_Susp_Sensors_M->solverInfo,
                       &Pedals_Susp_Sensors_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Pedals_Susp_Sensors_M->solverInfo,
                          (&rtmGetErrorStatus(Pedals_Susp_Sensors_M)));
    rtsiSetRTModelPtr(&Pedals_Susp_Sensors_M->solverInfo, Pedals_Susp_Sensors_M);
  }

  rtsiSetSimTimeStep(&Pedals_Susp_Sensors_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Pedals_Susp_Sensors_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Pedals_Susp_Sensors_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Pedals_Susp_Sensors_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Pedals_Susp_Sensors_M->Timing.sampleTimes =
      (&Pedals_Susp_Sensors_M->Timing.sampleTimesArray[0]);
    Pedals_Susp_Sensors_M->Timing.offsetTimes =
      (&Pedals_Susp_Sensors_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Pedals_Susp_Sensors_M->Timing.sampleTimes[0] = (0.0);
    Pedals_Susp_Sensors_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    Pedals_Susp_Sensors_M->Timing.offsetTimes[0] = (0.0);
    Pedals_Susp_Sensors_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Pedals_Susp_Sensors_M, &Pedals_Susp_Sensors_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Pedals_Susp_Sensors_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Pedals_Susp_Sensors_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Pedals_Susp_Sensors_M, 10.0);
  Pedals_Susp_Sensors_M->Timing.stepSize0 = 0.2;
  Pedals_Susp_Sensors_M->Timing.stepSize1 = 0.2;
  Pedals_Susp_Sensors_M->solverInfoPtr = (&Pedals_Susp_Sensors_M->solverInfo);
  Pedals_Susp_Sensors_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Pedals_Susp_Sensors_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Pedals_Susp_Sensors_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Pedals_Susp_Sensors_M->blockIO = ((void *) &Pedals_Susp_Sensors_B);
  (void) memset(((void *) &Pedals_Susp_Sensors_B), 0,
                sizeof(B_Pedals_Susp_Sensors_T));

  /* parameters */
  Pedals_Susp_Sensors_M->defaultParam = ((real_T *)&Pedals_Susp_Sensors_P);

  /* states (dwork) */
  Pedals_Susp_Sensors_M->dwork = ((void *) &Pedals_Susp_Sensors_DW);
  (void) memset((void *)&Pedals_Susp_Sensors_DW, 0,
                sizeof(DW_Pedals_Susp_Sensors_T));

  /* external inputs */
  Pedals_Susp_Sensors_M->inputs = (((void*)&Pedals_Susp_Sensors_U));
  (void)memset((void *)&Pedals_Susp_Sensors_U, 0, sizeof
               (ExtU_Pedals_Susp_Sensors_T));

  /* external outputs */
  Pedals_Susp_Sensors_M->outputs = (&Pedals_Susp_Sensors_Y);
  (void) memset((void *)&Pedals_Susp_Sensors_Y, 0,
                sizeof(ExtY_Pedals_Susp_Sensors_T));

  /* Initialize Sizes */
  Pedals_Susp_Sensors_M->Sizes.numContStates = (0);/* Number of continuous states */
  Pedals_Susp_Sensors_M->Sizes.numY = (8);/* Number of model outputs */
  Pedals_Susp_Sensors_M->Sizes.numU = (7);/* Number of model inputs */
  Pedals_Susp_Sensors_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Pedals_Susp_Sensors_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Pedals_Susp_Sensors_M->Sizes.numBlocks = (74);/* Number of blocks */
  Pedals_Susp_Sensors_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  Pedals_Susp_Sensors_M->Sizes.numBlockPrms = (25);/* Sum of parameter "widths" */
  return Pedals_Susp_Sensors_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
