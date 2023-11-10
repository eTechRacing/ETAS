/*
 * Inverters_Data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Inverters_Data".
 *
 * Model version              : 1.51
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Nov 10 02:57:28 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Inverters_Data.h"
#include "Inverters_Data_private.h"
#include "rt_powd_snf.h"

/* External inputs (root inport signals with auto storage) */
ExtU_Inverters_Data_T Inverters_Data_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Inverters_Data_T Inverters_Data_Y;

/* Real-time model */
RT_MODEL_Inverters_Data_T Inverters_Data_M_;
RT_MODEL_Inverters_Data_T *const Inverters_Data_M = &Inverters_Data_M_;

/* Model output function */
static void Inverters_Data_output(void)
{
  real_T rtb_Gain_i;
  real_T rtb_Gain_jo;
  real_T rtb_ratio;
  real_T rtb_ratio_g;

  /* Math: '<S15>/Math Function2' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Inport: '<Root>/Inv_L_RegID_M74_Inv_L_TempIGBT'
   */
  if ((Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT < 0.0) &&
      (Inverters_Data_P.Constant1_Value > floor(Inverters_Data_P.Constant1_Value)))
  {
    rtb_Gain_jo = -rt_powd_snf(-Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT,
      Inverters_Data_P.Constant1_Value);
  } else {
    rtb_Gain_jo = rt_powd_snf(Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT,
      Inverters_Data_P.Constant1_Value);
  }

  /* End of Math: '<S15>/Math Function2' */

  /* Sum: '<S15>/Add1' incorporates:
   *  Constant: '<S15>/A1'
   *  Constant: '<S15>/B1'
   *  Constant: '<S15>/C1'
   *  Constant: '<S15>/D1'
   *  Inport: '<Root>/Inv_L_RegID_M74_Inv_L_TempIGBT'
   *  Math: '<S15>/Math Function3'
   *  Product: '<S15>/Product3'
   *  Product: '<S15>/Product4'
   *  Product: '<S15>/Product5'
   */
  rtb_Gain_i = ((Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT *
                 Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT *
                 Inverters_Data_P.B1_Value + rtb_Gain_jo *
                 Inverters_Data_P.A1_Value) +
                Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT *
                Inverters_Data_P.C1_Value) + Inverters_Data_P.D1_Value;

  /* Math: '<S16>/Math Function2' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Inport: '<Root>/Inv_R_RegID_M74_Inv_R_TempIGBT'
   */
  if ((Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT < 0.0) &&
      (Inverters_Data_P.Constant1_Value_e > floor
       (Inverters_Data_P.Constant1_Value_e))) {
    rtb_Gain_jo = -rt_powd_snf(-Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT,
      Inverters_Data_P.Constant1_Value_e);
  } else {
    rtb_Gain_jo = rt_powd_snf(Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT,
      Inverters_Data_P.Constant1_Value_e);
  }

  /* End of Math: '<S16>/Math Function2' */

  /* Sum: '<S16>/Add1' incorporates:
   *  Constant: '<S16>/A1'
   *  Constant: '<S16>/B1'
   *  Constant: '<S16>/C1'
   *  Constant: '<S16>/D1'
   *  Inport: '<Root>/Inv_R_RegID_M74_Inv_R_TempIGBT'
   *  Math: '<S16>/Math Function3'
   *  Product: '<S16>/Product3'
   *  Product: '<S16>/Product4'
   *  Product: '<S16>/Product5'
   */
  rtb_Gain_jo = ((Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT *
                  Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT *
                  Inverters_Data_P.B1_Value_i + rtb_Gain_jo *
                  Inverters_Data_P.A1_Value_e) +
                 Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT *
                 Inverters_Data_P.C1_Value_n) + Inverters_Data_P.D1_Value_f;

  /* Outport: '<Root>/Temp_IGBT' incorporates:
   *  MinMax: '<Root>/Max'
   */
  Inverters_Data_Y.Temp_IGBT = fmax(rtb_Gain_i, rtb_Gain_jo);

  /* Outport: '<Root>/Inv_R_TempIGBT' */
  Inverters_Data_Y.Inv_R_TempIGBT = rtb_Gain_jo;

  /* Outport: '<Root>/Inv_L_TempIGBT' */
  Inverters_Data_Y.Inv_L_TempIGBT = rtb_Gain_i;

  /* Sum: '<S17>/Add1' incorporates:
   *  Constant: '<S17>/C1'
   *  Constant: '<S17>/D1'
   *  Inport: '<Root>/Inv_L_RegID_M73_Inv_L_TempMotor'
   *  Product: '<S17>/Product5'
   */
  rtb_Gain_jo = Inverters_Data_U.Inv_L_RegID_M73_Inv_L_TempMotor *
    Inverters_Data_P.C1_Value_d + Inverters_Data_P.D1_Value_d;

  /* Sum: '<S18>/Add1' incorporates:
   *  Constant: '<S18>/C1'
   *  Constant: '<S18>/D1'
   *  Inport: '<Root>/Inv_R_RegID_M73_Inv_R_TempMotor'
   *  Product: '<S18>/Product5'
   */
  rtb_Gain_i = Inverters_Data_U.Inv_R_RegID_M73_Inv_R_TempMotor *
    Inverters_Data_P.C1_Value_n0 + Inverters_Data_P.D1_Value_j;

  /* Outport: '<Root>/Temp_Motors' incorporates:
   *  MinMax: '<Root>/Max1'
   */
  Inverters_Data_Y.Temp_Motors = fmax(rtb_Gain_jo, rtb_Gain_i);

  /* Outport: '<Root>/Inv_L_TempMotor' */
  Inverters_Data_Y.Inv_L_TempMotor = rtb_Gain_jo;

  /* Outport: '<Root>/Inv_R_TempMotor' */
  Inverters_Data_Y.Inv_R_TempMotor = rtb_Gain_i;

  /* Gain: '<S24>/2*pi//60' incorporates:
   *  Constant: '<S8>/Bit ct'
   *  Constant: '<S8>/Max RPM'
   *  Gain: '<S8>/direction'
   *  Inport: '<Root>/Inv_L_RegID_M48_Inv_L_Speed'
   *  Product: '<S8>/Divide'
   *  Product: '<S8>/Product'
   */
  rtb_Gain_jo = Inverters_Data_P.direction_Gain *
    Inverters_Data_U.Inv_L_RegID_M48_Inv_L_Speed *
    (Inverters_Data_P.MaxRPM_Value / Inverters_Data_P.Bitct_Value) *
    Inverters_Data_P.upi60_Gain;

  /* Gain: '<S20>/2*pi//60' incorporates:
   *  Constant: '<S2>/Bit ct'
   *  Constant: '<S2>/Max RPM'
   *  Gain: '<S2>/direction'
   *  Inport: '<Root>/Inv_R_RegID_M48_Inv_R_Speed'
   *  Product: '<S2>/Divide'
   *  Product: '<S2>/Product'
   */
  rtb_Gain_i = Inverters_Data_P.direction_Gain_f *
    Inverters_Data_U.Inv_R_RegID_M48_Inv_R_Speed *
    (Inverters_Data_P.MaxRPM_Value_m / Inverters_Data_P.Bitct_Value_h) *
    Inverters_Data_P.upi60_Gain_i;

  /* Outport: '<Root>/Mech_Power' incorporates:
   *  Inport: '<Root>/Torque_L'
   *  Inport: '<Root>/Torque_R'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product2'
   *  Sum: '<S10>/Add'
   */
  Inverters_Data_Y.Mech_Power = rtb_Gain_jo * Inverters_Data_U.Torque_L +
    rtb_Gain_i * Inverters_Data_U.Torque_R;

  /* Gain: '<S25>/Gain' */
  rtb_Gain_jo *= Inverters_Data_P.Gain_Gain;

  /* Gain: '<S27>/ratio' incorporates:
   *  Gain: '<S26>/Diameter [m]'
   */
  rtb_ratio = Inverters_Data_P.Diameterm_Gain * rtb_Gain_jo *
    Inverters_Data_P.ratio_Gain;

  /* Outport: '<Root>/Vel_RL_kmh' */
  Inverters_Data_Y.Vel_RL_kmh = rtb_ratio;

  /* Gain: '<S21>/Gain' */
  rtb_Gain_i *= Inverters_Data_P.Gain_Gain_a;

  /* Gain: '<S23>/ratio' incorporates:
   *  Gain: '<S22>/Diameter [m]'
   */
  rtb_ratio_g = Inverters_Data_P.Diameterm_Gain_p * rtb_Gain_i *
    Inverters_Data_P.ratio_Gain_k;

  /* Outport: '<Root>/Vel_RR_kmh' */
  Inverters_Data_Y.Vel_RR_kmh = rtb_ratio_g;

  /* Outport: '<Root>/Speed' incorporates:
   *  Abs: '<S1>/Abs'
   *  Abs: '<S1>/Abs1'
   *  Gain: '<S1>/Gain'
   *  Sum: '<S1>/Sum'
   */
  Inverters_Data_Y.Speed = (fabs(rtb_ratio) + fabs(rtb_ratio_g)) *
    Inverters_Data_P.Gain_Gain_m;

  /* Outport: '<Root>/RL_rads' */
  Inverters_Data_Y.RL_rads = rtb_Gain_jo;

  /* Outport: '<Root>/RR_rads' */
  Inverters_Data_Y.RR_rads = rtb_Gain_i;

  /* Outport: '<Root>/Inv_R_Speed' */
  Inverters_Data_Y.Inv_R_Speed = rtb_ratio_g;

  /* Outport: '<Root>/Inv_L_Speed' */
  Inverters_Data_Y.Inv_L_Speed = rtb_ratio;

  /* Gain: '<S11>/Gain' incorporates:
   *  Inport: '<Root>/Inv_L_RegID_M235_Inv_L_DCBus'
   */
  rtb_Gain_i = Inverters_Data_P.Gain_Gain_e *
    Inverters_Data_U.Inv_L_RegID_M235_Inv_L_DCBus;

  /* Gain: '<S14>/Gain' incorporates:
   *  Inport: '<Root>/Inv_R_RegID_M235_Inv_R_DCBus'
   */
  rtb_Gain_jo = Inverters_Data_P.Gain_Gain_f *
    Inverters_Data_U.Inv_R_RegID_M235_Inv_R_DCBus;

  /* Outport: '<Root>/InvertersMinDCBus' incorporates:
   *  MinMax: '<Root>/MinMax'
   */
  Inverters_Data_Y.InvertersMinDCBus = fmin(rtb_Gain_i, rtb_Gain_jo);

  /* Outport: '<Root>/Inv_L_VdcBus' */
  Inverters_Data_Y.Inv_L_VdcBus = rtb_Gain_jo;

  /* Outport: '<Root>/Inv_R_VdcBus' */
  Inverters_Data_Y.Inv_R_VdcBus = rtb_Gain_i;

  /* Outport: '<Root>/Inv_L_Iq' incorporates:
   *  Gain: '<S6>/conversion ratio'
   *  Inport: '<Root>/Inv_L_RegID_M39_Inv_L_Iq'
   */
  Inverters_Data_Y.Inv_L_Iq = Inverters_Data_P.conversionratio_Gain *
    Inverters_Data_U.Inv_L_RegID_M39_Inv_L_Iq;

  /* Outport: '<Root>/Inv_R_Iq' incorporates:
   *  Gain: '<S7>/conversion ratio'
   *  Inport: '<Root>/Inv_R_RegID_M39_Inv_R_Iq'
   */
  Inverters_Data_Y.Inv_R_Iq = Inverters_Data_P.conversionratio_Gain_o *
    Inverters_Data_U.Inv_R_RegID_M39_Inv_R_Iq;

  /* Outport: '<Root>/Inv_L_Iactual' incorporates:
   *  Gain: '<S9>/conversion ratio1'
   *  Inport: '<Root>/Inv_L_RegID_M32_Inv_L_Iactual'
   */
  Inverters_Data_Y.Inv_L_Iactual = Inverters_Data_P.conversionratio1_Gain *
    Inverters_Data_U.Inv_L_RegID_M32_Inv_L_Iactual;

  /* Outport: '<Root>/Inv_R_Iactual' incorporates:
   *  Gain: '<S5>/conversion ratio'
   *  Inport: '<Root>/Inv_R_RegID_M32_Inv_R_Iactual'
   */
  Inverters_Data_Y.Inv_R_Iactual = Inverters_Data_P.conversionratio_Gain_k *
    Inverters_Data_U.Inv_R_RegID_M32_Inv_R_Iactual;

  /* Outport: '<Root>/Inv_L_Icommand' incorporates:
   *  Gain: '<S3>/conversion ratio'
   *  Inport: '<Root>/Inv_L_RegID_M38_Inv_L_Icommand'
   */
  Inverters_Data_Y.Inv_L_Icommand = Inverters_Data_P.conversionratio_Gain_j *
    Inverters_Data_U.Inv_L_RegID_M38_Inv_L_Icommand;

  /* Outport: '<Root>/Inv_R_Icommand' incorporates:
   *  Gain: '<S4>/conversion ratio'
   *  Inport: '<Root>/Inv_R_RegID_M38_Inv_R_Icommand'
   */
  Inverters_Data_Y.Inv_R_Icommand = Inverters_Data_P.conversionratio_Gain_c *
    Inverters_Data_U.Inv_R_RegID_M38_Inv_R_Icommand;
}

/* Model update function */
static void Inverters_Data_update(void)
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
  if (!(++Inverters_Data_M->Timing.clockTick0)) {
    ++Inverters_Data_M->Timing.clockTickH0;
  }

  Inverters_Data_M->Timing.t[0] = Inverters_Data_M->Timing.clockTick0 *
    Inverters_Data_M->Timing.stepSize0 + Inverters_Data_M->Timing.clockTickH0 *
    Inverters_Data_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Inverters_Data_initialize(void)
{
}

/* Model terminate function */
static void Inverters_Data_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Inverters_Data_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Inverters_Data_update();
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
  Inverters_Data_initialize();
}

void MdlTerminate(void)
{
  Inverters_Data_terminate();
}

/* Registration function */
RT_MODEL_Inverters_Data_T *Inverters_Data(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Inverters_Data_M, 0,
                sizeof(RT_MODEL_Inverters_Data_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Inverters_Data_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Inverters_Data_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Inverters_Data_M->Timing.sampleTimes =
      (&Inverters_Data_M->Timing.sampleTimesArray[0]);
    Inverters_Data_M->Timing.offsetTimes =
      (&Inverters_Data_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Inverters_Data_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Inverters_Data_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Inverters_Data_M, &Inverters_Data_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Inverters_Data_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Inverters_Data_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Inverters_Data_M, 10.0);
  Inverters_Data_M->Timing.stepSize0 = 0.2;
  Inverters_Data_M->solverInfoPtr = (&Inverters_Data_M->solverInfo);
  Inverters_Data_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Inverters_Data_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Inverters_Data_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  Inverters_Data_M->defaultParam = ((real_T *)&Inverters_Data_P);

  /* external inputs */
  Inverters_Data_M->inputs = (((void*)&Inverters_Data_U));
  (void)memset((void *)&Inverters_Data_U, 0, sizeof(ExtU_Inverters_Data_T));

  /* external outputs */
  Inverters_Data_M->outputs = (&Inverters_Data_Y);
  (void) memset((void *)&Inverters_Data_Y, 0,
                sizeof(ExtY_Inverters_Data_T));

  /* Initialize Sizes */
  Inverters_Data_M->Sizes.numContStates = (0);/* Number of continuous states */
  Inverters_Data_M->Sizes.numY = (23); /* Number of model outputs */
  Inverters_Data_M->Sizes.numU = (16); /* Number of model inputs */
  Inverters_Data_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Inverters_Data_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Inverters_Data_M->Sizes.numBlocks = (89);/* Number of blocks */
  Inverters_Data_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  Inverters_Data_M->Sizes.numBlockPrms = (37);/* Sum of parameter "widths" */
  return Inverters_Data_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
