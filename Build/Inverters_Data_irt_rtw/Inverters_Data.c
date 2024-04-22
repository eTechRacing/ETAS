/*
 * Inverters_Data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Inverters_Data".
 *
 * Model version              : 13.0
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Apr 22 17:10:06 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Inverters_Data.h"
#include "rt_powd_snf.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"

/* External inputs (root inport signals with default storage) */
ExtU_Inverters_Data_T Inverters_Data_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Inverters_Data_T Inverters_Data_Y;

/* Real-time model */
static RT_MODEL_Inverters_Data_T Inverters_Data_M_;
RT_MODEL_Inverters_Data_T *const Inverters_Data_M = &Inverters_Data_M_;

/* Model output function */
static void Inverters_Data_output(void)
{
  real_T rtb_Abs;
  real_T rtb_Abs1;
  real_T rtb_RPMtorads;
  real_T rtb_RPMtorads_n;

  /* Sum: '<S14>/Add1' incorporates:
   *  Constant: '<S14>/A1'
   *  Constant: '<S14>/B1'
   *  Constant: '<S14>/C1'
   *  Constant: '<S14>/Constant1'
   *  Inport: '<Root>/Inv_L_RegID_M74_Inv_L_TempIGBT'
   *  Math: '<S14>/Math Function2'
   *  Math: '<S14>/Math Function3'
   *  Product: '<S14>/Product3'
   *  Product: '<S14>/Product4'
   *  Product: '<S14>/Product5'
   */
  rtb_Abs1 = ((Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT *
               Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT * -6.6188E-6 +
               rt_powd_snf(Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT, 3.0)
               * 9.69483E-11) + Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT *
              0.158535) - 1260.62;

  /* Sum: '<S15>/Add1' incorporates:
   *  Constant: '<S15>/A1'
   *  Constant: '<S15>/B1'
   *  Constant: '<S15>/C1'
   *  Constant: '<S15>/Constant1'
   *  Inport: '<Root>/Inv_R_RegID_M74_Inv_R_TempIGBT'
   *  Math: '<S15>/Math Function2'
   *  Math: '<S15>/Math Function3'
   *  Product: '<S15>/Product3'
   *  Product: '<S15>/Product4'
   *  Product: '<S15>/Product5'
   */
  rtb_RPMtorads_n = ((Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT *
                      Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT *
                      -6.6188E-6 + rt_powd_snf
                      (Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT, 3.0) *
                      9.69483E-11) +
                     Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT * 0.158535)
    - 1260.62;

  /* Outport: '<Root>/Max_Temp_IGBT' incorporates:
   *  MinMax: '<Root>/Max'
   */
  Inverters_Data_Y.Max_Temp_IGBT = fmax(rtb_Abs1, rtb_RPMtorads_n);

  /* Outport: '<Root>/Inv_R_TempIGBT' */
  Inverters_Data_Y.Inv_R_TempIGBT = rtb_RPMtorads_n;

  /* Outport: '<Root>/Inv_L_TempIGBT' */
  Inverters_Data_Y.Inv_L_TempIGBT = rtb_Abs1;

  /* Sum: '<S16>/Add1' incorporates:
   *  Constant: '<S16>/C1'
   *  Inport: '<Root>/Inv_L_RegID_M73_Inv_L_TempMotor'
   *  Product: '<S16>/Product5'
   */
  rtb_RPMtorads_n = Inverters_Data_U.Inv_L_RegID_M73_Inv_L_TempMotor * 0.03282 -
    114.92892;

  /* Sum: '<S17>/Add1' incorporates:
   *  Constant: '<S17>/C1'
   *  Inport: '<Root>/Inv_R_RegID_M73_Inv_R_TempMotor'
   *  Product: '<S17>/Product5'
   */
  rtb_Abs1 = Inverters_Data_U.Inv_R_RegID_M73_Inv_R_TempMotor * 0.03282 -
    114.92892;

  /* Outport: '<Root>/Max_Temp_Motors' incorporates:
   *  MinMax: '<Root>/Max1'
   */
  Inverters_Data_Y.Max_Temp_Motors = fmax(rtb_RPMtorads_n, rtb_Abs1);

  /* Outport: '<Root>/Inv_L_TempMotor' */
  Inverters_Data_Y.Inv_L_TempMotor = rtb_RPMtorads_n;

  /* Outport: '<Root>/Inv_R_TempMotor' */
  Inverters_Data_Y.Inv_R_TempMotor = rtb_Abs1;

  /* Gain: '<S12>/RPM to rad//s' incorporates:
   *  Inport: '<Root>/Inv_L_RegID_M48_Inv_L_Speed'
   */
  rtb_RPMtorads_n = 0.10471975511965977 *
    Inverters_Data_U.Inv_L_RegID_M48_Inv_L_Speed;

  /* Product: '<S12>/Divide' incorporates:
   *  Constant: '<Root>/Gear_Ratio'
   *  Constant: '<Root>/Wheel_Radius [m]'
   *  Product: '<S12>/Divide1'
   */
  rtb_Abs1 = rtb_RPMtorads_n / 11.3257 * 0.2285;

  /* Outport: '<Root>/RL_Vel_ms_Wheel' */
  Inverters_Data_Y.RL_Vel_ms_Wheel = rtb_Abs1;

  /* Gain: '<S11>/RPM to rad//s' incorporates:
   *  Inport: '<Root>/Inv_R_RegID_M48_Inv_R_Speed'
   */
  rtb_RPMtorads = 0.10471975511965977 *
    Inverters_Data_U.Inv_R_RegID_M48_Inv_R_Speed;

  /* Product: '<S11>/Divide' incorporates:
   *  Constant: '<Root>/Gear_Ratio'
   *  Constant: '<Root>/Wheel_Radius [m]'
   *  Product: '<S11>/Divide1'
   */
  rtb_Abs = rtb_RPMtorads / 11.3257 * 0.2285;

  /* Outport: '<Root>/RR_Vel_ms_Wheel' */
  Inverters_Data_Y.RR_Vel_ms_Wheel = rtb_Abs;

  /* Outport: '<Root>/Speed' incorporates:
   *  Abs: '<S1>/Abs'
   *  Abs: '<S1>/Abs1'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Sum: '<S1>/Sum'
   */
  Inverters_Data_Y.Speed = (fabs(3.6 * rtb_Abs1) + fabs(3.6 * rtb_Abs)) * 0.5;

  /* Outport: '<Root>/RL_rads_Motor' */
  Inverters_Data_Y.RL_rads_Motor = rtb_RPMtorads_n;

  /* Outport: '<Root>/RR_rads_Motor' */
  Inverters_Data_Y.RR_rads_Motor = rtb_RPMtorads;

  /* Outport: '<Root>/InvertersMinDCBus' incorporates:
   *  Inport: '<Root>/Inv_L_RegID_M235_Inv_L_DCBus'
   *  Inport: '<Root>/Inv_R_RegID_M235_Inv_R_DCBus'
   *  MinMax: '<Root>/MinMax'
   */
  Inverters_Data_Y.InvertersMinDCBus = fmin
    (Inverters_Data_U.Inv_L_RegID_M235_Inv_L_DCBus,
     Inverters_Data_U.Inv_R_RegID_M235_Inv_R_DCBus);

  /* Outport: '<Root>/Inv_L_Iq' incorporates:
   *  Gain: '<S6>/conversion ratio'
   *  Inport: '<Root>/Inv_L_RegID_M39_Inv_L_Iq'
   */
  Inverters_Data_Y.Inv_L_Iq = 0.37383177570093457 *
    Inverters_Data_U.Inv_L_RegID_M39_Inv_L_Iq;

  /* Outport: '<Root>/Inv_R_Iq' incorporates:
   *  Gain: '<S7>/conversion ratio'
   *  Inport: '<Root>/Inv_R_RegID_M39_Inv_R_Iq'
   */
  Inverters_Data_Y.Inv_R_Iq = 0.37383177570093457 *
    Inverters_Data_U.Inv_R_RegID_M39_Inv_R_Iq;

  /* Outport: '<Root>/Inv_L_Iactual' incorporates:
   *  Gain: '<S9>/conversion ratio1'
   *  Inport: '<Root>/Inv_L_RegID_M32_Inv_L_Iactual'
   */
  Inverters_Data_Y.Inv_L_Iactual = 0.37383177570093457 *
    Inverters_Data_U.Inv_L_RegID_M32_Inv_L_Iactual;

  /* Outport: '<Root>/Inv_R_Iactual' incorporates:
   *  Gain: '<S5>/conversion ratio'
   *  Inport: '<Root>/Inv_R_RegID_M32_Inv_R_Iactual'
   */
  Inverters_Data_Y.Inv_R_Iactual = 0.37383177570093457 *
    Inverters_Data_U.Inv_R_RegID_M32_Inv_R_Iactual;

  /* Outport: '<Root>/Inv_L_Icommand' incorporates:
   *  Gain: '<S3>/conversion ratio'
   *  Inport: '<Root>/Inv_L_RegID_M38_Inv_L_Icommand'
   */
  Inverters_Data_Y.Inv_L_Icommand = 0.37383177570093457 *
    Inverters_Data_U.Inv_L_RegID_M38_Inv_L_Icommand;

  /* Outport: '<Root>/Inv_R_Icommand' incorporates:
   *  Gain: '<S4>/conversion ratio'
   *  Inport: '<Root>/Inv_R_RegID_M38_Inv_R_Icommand'
   */
  Inverters_Data_Y.Inv_R_Icommand = 0.37383177570093457 *
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

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Inverters_Data_M points to
       static memory which is guaranteed to be non-NULL" */
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

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Inverters_Data_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Inverters_Data_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Inverters_Data_M->rtwLogInfo, (NULL));
    rtliSetLogT(Inverters_Data_M->rtwLogInfo, "tout");
    rtliSetLogX(Inverters_Data_M->rtwLogInfo, "");
    rtliSetLogXFinal(Inverters_Data_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Inverters_Data_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Inverters_Data_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Inverters_Data_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Inverters_Data_M->rtwLogInfo, 1);
    rtliSetLogY(Inverters_Data_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Inverters_Data_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Inverters_Data_M->rtwLogInfo, (NULL));
  }

  Inverters_Data_M->solverInfoPtr = (&Inverters_Data_M->solverInfo);
  Inverters_Data_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Inverters_Data_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Inverters_Data_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* external inputs */
  Inverters_Data_M->inputs = (((void*)&Inverters_Data_U));
  (void)memset(&Inverters_Data_U, 0, sizeof(ExtU_Inverters_Data_T));

  /* external outputs */
  Inverters_Data_M->outputs = (&Inverters_Data_Y);
  (void)memset(&Inverters_Data_Y, 0, sizeof(ExtY_Inverters_Data_T));

  /* Initialize Sizes */
  Inverters_Data_M->Sizes.numContStates = (0);/* Number of continuous states */
  Inverters_Data_M->Sizes.numY = (18); /* Number of model outputs */
  Inverters_Data_M->Sizes.numU = (14); /* Number of model inputs */
  Inverters_Data_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Inverters_Data_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Inverters_Data_M->Sizes.numBlocks = (71);/* Number of blocks */
  Inverters_Data_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  return Inverters_Data_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
