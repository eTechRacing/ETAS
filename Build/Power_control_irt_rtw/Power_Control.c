/*
 * Power_Control.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Power_Control".
 *
 * Model version              : 4.35
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Aug 14 01:48:02 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Power_Control.h"
#include "rtwtypes.h"
#include "Power_Control_private.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
B_Power_Control_T Power_Control_B;

/* Block states (default storage) */
DW_Power_Control_T Power_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Power_Control_T Power_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Power_Control_T Power_Control_Y;

/* Real-time model */
static RT_MODEL_Power_Control_T Power_Control_M_;
RT_MODEL_Power_Control_T *const Power_Control_M = &Power_Control_M_;

/*
 * Output and update for action system:
 *    '<S8>/LimitReached'
 *    '<S11>/Latched Error'
 */
void Power_Control_LimitReached(real_T *rty_Out)
{
  /* SignalConversion generated from: '<S10>/Out ' incorporates:
   *  Constant: '<S10>/Constant'
   */
  *rty_Out = 1.0;
}

/*
 * System initialize for atomic system:
 *    '<Root>/InverterL_Temp_Limitation'
 *    '<Root>/InverterR_Temp_Limitation'
 */
void InverterL_Temp_Limitation_Init(DW_InverterL_Temp_Limitation__T *localDW)
{
  localDW->AF_Value_not_empty = false;
  localDW->Last_Temp = 0.0;
  localDW->Times_Incremented = 1.0;
  localDW->Times_Decremented = 1.0;
}

/*
 * Output and update for atomic system:
 *    '<Root>/InverterL_Temp_Limitation'
 *    '<Root>/InverterR_Temp_Limitation'
 */
void Power_InverterL_Temp_Limitation(real_T rtu_Current_in, real_T
  rtu_Aggressive_Factor, real_T rtu_Max_Temp, real_T rtu_Tolerance, real_T
  rtu_Inv_Temp, real_T rtu_Change_Factor, B_InverterL_Temp_Limitation_P_T
  *localB, DW_InverterL_Temp_Limitation__T *localDW)
{
  real_T Temp_Change;
  if (!localDW->AF_Value_not_empty) {
    localDW->AF_Value = rtu_Aggressive_Factor;
    localDW->AF_Value_not_empty = true;
  }

  Temp_Change = rtu_Inv_Temp - localDW->Last_Temp;
  if (Temp_Change > rtu_Tolerance) {
    Temp_Change = (1.0 - localDW->AF_Value * Temp_Change / 100.0) *
      rtu_Current_in;
    localDW->AF_Value += rtu_Change_Factor * localDW->Times_Incremented;
    localDW->Times_Incremented++;
    localDW->Times_Decremented = 1.0;
  } else if (Temp_Change < -rtu_Tolerance) {
    Temp_Change = (1.0 - localDW->AF_Value * Temp_Change / 100.0) *
      rtu_Current_in;
    localDW->AF_Value -= rtu_Change_Factor * localDW->Times_Decremented;
    localDW->Times_Incremented = 1.0;
    localDW->Times_Decremented++;
  } else {
    Temp_Change = (1.0 - localDW->AF_Value / 10.0) * rtu_Current_in;
    localDW->Times_Incremented = 1.0;
    localDW->Times_Decremented = 1.0;
  }

  if (((Temp_Change > rtu_Current_in) && (rtu_Current_in >= 0.0)) ||
      ((Temp_Change < rtu_Current_in) && (rtu_Current_in < 0.0))) {
    Temp_Change = rtu_Current_in;
  } else {
    real_T tmp;
    real_T tmp_0;
    if (rtIsNaN(Temp_Change)) {
      tmp = (rtNaN);
    } else if (Temp_Change < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (Temp_Change > 0.0);
    }

    if (rtIsNaN(rtu_Current_in)) {
      tmp_0 = (rtNaN);
    } else if (rtu_Current_in < 0.0) {
      tmp_0 = -1.0;
    } else {
      tmp_0 = (rtu_Current_in > 0.0);
    }

    if (tmp != tmp_0) {
      Temp_Change = 0.0;
    }
  }

  if (rtu_Inv_Temp > rtu_Max_Temp) {
    localB->Current_out = Temp_Change;
  } else {
    localB->Current_out = rtu_Current_in;
    localDW->AF_Value = rtu_Aggressive_Factor;
  }

  localDW->Last_Temp = rtu_Inv_Temp;
}

/*
 * System initialize for atomic system:
 *    '<Root>/MotorL_Temp_Limitation'
 *    '<Root>/MotorR_Temp_Limitation'
 */
void Pow_MotorL_Temp_Limitation_Init(DW_MotorL_Temp_Limitation_Pow_T *localDW)
{
  localDW->AF_Value_not_empty = false;
  localDW->Last_Temp = 0.0;
  localDW->Times_Incremented = 1.0;
  localDW->Times_Decremented = 1.0;
}

/*
 * Output and update for atomic system:
 *    '<Root>/MotorL_Temp_Limitation'
 *    '<Root>/MotorR_Temp_Limitation'
 */
void Power_Co_MotorL_Temp_Limitation(real_T rtu_Current_in, real_T
  rtu_Aggressive_Factor, real_T rtu_Max_Temp, real_T rtu_Tolerance, real_T
  rtu_Mot_Temp, real_T rtu_Change_Factor, B_MotorL_Temp_Limitation_Powe_T
  *localB, DW_MotorL_Temp_Limitation_Pow_T *localDW)
{
  real_T Temp_Change;
  if (!localDW->AF_Value_not_empty) {
    localDW->AF_Value = rtu_Aggressive_Factor;
    localDW->AF_Value_not_empty = true;
  }

  Temp_Change = rtu_Mot_Temp - localDW->Last_Temp;
  if (Temp_Change > rtu_Tolerance) {
    Temp_Change = (1.0 - localDW->AF_Value * Temp_Change / 100.0) *
      rtu_Current_in;
    localDW->AF_Value += rtu_Change_Factor * localDW->Times_Incremented;
    localDW->Times_Incremented++;
    localDW->Times_Decremented = 1.0;
  } else if (Temp_Change < -rtu_Tolerance) {
    Temp_Change = (1.0 - localDW->AF_Value * Temp_Change / 100.0) *
      rtu_Current_in;
    localDW->AF_Value -= rtu_Change_Factor * localDW->Times_Decremented;
    localDW->Times_Incremented = 1.0;
    localDW->Times_Decremented++;
  } else {
    Temp_Change = (1.0 - localDW->AF_Value / 10.0) * rtu_Current_in;
    localDW->Times_Incremented = 1.0;
    localDW->Times_Decremented = 1.0;
  }

  if (((Temp_Change > rtu_Current_in) && (rtu_Current_in >= 0.0)) ||
      ((Temp_Change < rtu_Current_in) && (rtu_Current_in < 0.0))) {
    Temp_Change = rtu_Current_in;
  } else {
    real_T tmp;
    real_T tmp_0;
    if (rtIsNaN(Temp_Change)) {
      tmp = (rtNaN);
    } else if (Temp_Change < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (Temp_Change > 0.0);
    }

    if (rtIsNaN(rtu_Current_in)) {
      tmp_0 = (rtNaN);
    } else if (rtu_Current_in < 0.0) {
      tmp_0 = -1.0;
    } else {
      tmp_0 = (rtu_Current_in > 0.0);
    }

    if (tmp != tmp_0) {
      Temp_Change = 0.0;
    }
  }

  if (rtu_Mot_Temp > rtu_Max_Temp) {
    localB->Current_out = Temp_Change;
  } else {
    localB->Current_out = rtu_Current_in;
    localDW->AF_Value = rtu_Aggressive_Factor;
  }

  localDW->Last_Temp = rtu_Mot_Temp;
}

/* Model output function */
static void Power_Control_output(void)
{
  real_T rtb_Merge1;
  real_T rtb_Product;

  /* MATLAB Function: '<Root>/InverterL_Temp_Limitation' incorporates:
   *  Constant: '<Root>/Aggresive_Factor'
   *  Constant: '<Root>/Change_Factor'
   *  Constant: '<Root>/Inv_MaxTemp'
   *  Constant: '<Root>/Tolerance_Temp'
   *  Gain: '<S7>/Fluxy'
   *  Inport: '<Root>/Inv_L_TempIGBT'
   *  Inport: '<Root>/Torque_L'
   */
  Power_InverterL_Temp_Limitation(3.29 * Power_Control_U.Torque_L, 1.4, 67.0,
    0.4, Power_Control_U.Inv_L_TempIGBT, 0.9,
    &Power_Control_B.sf_InverterL_Temp_Limitation,
    &Power_Control_DW.sf_InverterL_Temp_Limitation);

  /* MATLAB Function: '<Root>/MotorL_Temp_Limitation' incorporates:
   *  Constant: '<Root>/Aggresive_Factor'
   *  Constant: '<Root>/Change_Factor'
   *  Constant: '<Root>/Mot_MaxTemp'
   *  Constant: '<Root>/Tolerance_Temp'
   *  Inport: '<Root>/Inv_L_TempMotor'
   */
  Power_Co_MotorL_Temp_Limitation
    (Power_Control_B.sf_InverterL_Temp_Limitation.Current_out, 1.4, 110.0, 0.4,
     Power_Control_U.Inv_L_TempMotor, 0.9,
     &Power_Control_B.sf_MotorL_Temp_Limitation,
     &Power_Control_DW.sf_MotorL_Temp_Limitation);

  /* Outport: '<Root>/current_L' */
  Power_Control_Y.current_L =
    Power_Control_B.sf_MotorL_Temp_Limitation.Current_out;

  /* MATLAB Function: '<Root>/InverterR_Temp_Limitation' incorporates:
   *  Constant: '<Root>/Aggresive_Factor'
   *  Constant: '<Root>/Change_Factor'
   *  Constant: '<Root>/Inv_MaxTemp'
   *  Constant: '<Root>/Tolerance_Temp'
   *  Gain: '<S7>/Saly'
   *  Inport: '<Root>/Inv_R_TempIGBT'
   *  Inport: '<Root>/Torque_R'
   */
  Power_InverterL_Temp_Limitation(3.29 * Power_Control_U.Torque_R, 1.4, 67.0,
    0.4, Power_Control_U.Inv_R_TempIGBT, 0.9,
    &Power_Control_B.sf_InverterR_Temp_Limitation,
    &Power_Control_DW.sf_InverterR_Temp_Limitation);

  /* MATLAB Function: '<Root>/MotorR_Temp_Limitation' incorporates:
   *  Constant: '<Root>/Aggresive_Factor'
   *  Constant: '<Root>/Change_Factor'
   *  Constant: '<Root>/Mot_MaxTemp'
   *  Constant: '<Root>/Tolerance_Temp'
   *  Inport: '<Root>/Inv_R_TempMotor'
   */
  Power_Co_MotorL_Temp_Limitation
    (Power_Control_B.sf_InverterR_Temp_Limitation.Current_out, 1.4, 110.0, 0.4,
     Power_Control_U.Inv_R_TempMotor, 0.9,
     &Power_Control_B.sf_MotorR_Temp_Limitation,
     &Power_Control_DW.sf_MotorR_Temp_Limitation);

  /* Outport: '<Root>/current_R' */
  Power_Control_Y.current_R =
    Power_Control_B.sf_MotorR_Temp_Limitation.Current_out;

  /* Product: '<S1>/Product' incorporates:
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/Accumulator_Current'
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  rtb_Product = Power_Control_U.Accumulator_Voltage *
    -Power_Control_U.Accumulator_Current;

  /* Outport: '<Root>/Power' incorporates:
   *  Constant: '<S9>/0-100 to 0-2'
   *  Product: '<S9>/Divide5'
   */
  Power_Control_Y.Power = rtb_Product / 1000.0;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* If: '<S8>/If' incorporates:
   *  DataStoreRead: '<S8>/Data Store Read30'
   *  If: '<S11>/If'
   *  SignalConversion generated from: '<S8>/Power'
   */
  if (rtb_Product >= 80000.0) {
    /* Outputs for IfAction SubSystem: '<S8>/LimitReached' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    Power_Control_LimitReached(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S8>/LimitReached' */

    /* Outputs for IfAction SubSystem: '<S8>/OK_OrLatch' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
  } else if (Power_Control_DW.A > 0.0) {
    /* Outputs for IfAction SubSystem: '<S11>/Latched Error' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* If: '<S11>/If' */
    Power_Control_LimitReached(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S11>/Latched Error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/OK' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* If: '<S11>/If' incorporates:
     *  Constant: '<S13>/Constant'
     *  SignalConversion generated from: '<S13>/Out '
     */
    rtb_Merge1 = 0.0;

    /* End of Outputs for SubSystem: '<S11>/OK' */

    /* End of Outputs for SubSystem: '<S8>/OK_OrLatch' */
  }

  /* End of If: '<S8>/If' */

  /* DataStoreWrite: '<S8>/Data Store Write20' */
  Power_Control_DW.A = rtb_Merge1;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */

  /* Outport: '<Root>/PowerLimitReached' */
  Power_Control_Y.PowerLimitReached = rtb_Merge1;

  /* Outputs for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Outport: '<Root>/PowerMean500ms' incorporates:
   *  SignalConversion generated from: '<S8>/Power'
   */
  Power_Control_Y.PowerMean500ms = rtb_Product;

  /* End of Outputs for SubSystem: '<S1>/PowerLimitDetection' */
}

/* Model update function */
static void Power_Control_update(void)
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
  if (!(++Power_Control_M->Timing.clockTick0)) {
    ++Power_Control_M->Timing.clockTickH0;
  }

  Power_Control_M->Timing.t[0] = Power_Control_M->Timing.clockTick0 *
    Power_Control_M->Timing.stepSize0 + Power_Control_M->Timing.clockTickH0 *
    Power_Control_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Power_Control_initialize(void)
{
  /* Start for Atomic SubSystem: '<S1>/PowerLimitDetection' */
  /* Start for DataStoreMemory: '<S8>/Data Store Memory10' */
  Power_Control_DW.A = 0.0;

  /* End of Start for SubSystem: '<S1>/PowerLimitDetection' */

  /* SystemInitialize for MATLAB Function: '<Root>/InverterL_Temp_Limitation' */
  InverterL_Temp_Limitation_Init(&Power_Control_DW.sf_InverterL_Temp_Limitation);

  /* SystemInitialize for MATLAB Function: '<Root>/MotorL_Temp_Limitation' */
  Pow_MotorL_Temp_Limitation_Init(&Power_Control_DW.sf_MotorL_Temp_Limitation);

  /* SystemInitialize for MATLAB Function: '<Root>/InverterR_Temp_Limitation' */
  InverterL_Temp_Limitation_Init(&Power_Control_DW.sf_InverterR_Temp_Limitation);

  /* SystemInitialize for MATLAB Function: '<Root>/MotorR_Temp_Limitation' */
  Pow_MotorL_Temp_Limitation_Init(&Power_Control_DW.sf_MotorR_Temp_Limitation);
}

/* Model terminate function */
static void Power_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Power_Control_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Power_Control_update();
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
  Power_Control_initialize();
}

void MdlTerminate(void)
{
  Power_Control_terminate();
}

/* Registration function */
RT_MODEL_Power_Control_T *Power_Control(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Power_Control_M, 0,
                sizeof(RT_MODEL_Power_Control_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Power_Control_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Power_Control_M points to
       static memory which is guaranteed to be non-NULL" */
    Power_Control_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Power_Control_M->Timing.sampleTimes =
      (&Power_Control_M->Timing.sampleTimesArray[0]);
    Power_Control_M->Timing.offsetTimes =
      (&Power_Control_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Power_Control_M->Timing.sampleTimes[0] = (0.0045000000000000005);

    /* task offsets */
    Power_Control_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Power_Control_M, &Power_Control_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Power_Control_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Power_Control_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Power_Control_M, 0.22500000000000003);
  Power_Control_M->Timing.stepSize0 = 0.0045000000000000005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Power_Control_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Power_Control_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Power_Control_M->rtwLogInfo, (NULL));
    rtliSetLogT(Power_Control_M->rtwLogInfo, "tout");
    rtliSetLogX(Power_Control_M->rtwLogInfo, "");
    rtliSetLogXFinal(Power_Control_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Power_Control_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Power_Control_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Power_Control_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Power_Control_M->rtwLogInfo, 1);
    rtliSetLogY(Power_Control_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Power_Control_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Power_Control_M->rtwLogInfo, (NULL));
  }

  Power_Control_M->solverInfoPtr = (&Power_Control_M->solverInfo);
  Power_Control_M->Timing.stepSize = (0.0045000000000000005);
  rtsiSetFixedStepSize(&Power_Control_M->solverInfo, 0.0045000000000000005);
  rtsiSetSolverMode(&Power_Control_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Power_Control_M->blockIO = ((void *) &Power_Control_B);
  (void) memset(((void *) &Power_Control_B), 0,
                sizeof(B_Power_Control_T));

  /* states (dwork) */
  Power_Control_M->dwork = ((void *) &Power_Control_DW);
  (void) memset((void *)&Power_Control_DW, 0,
                sizeof(DW_Power_Control_T));

  /* external inputs */
  Power_Control_M->inputs = (((void*)&Power_Control_U));
  (void)memset(&Power_Control_U, 0, sizeof(ExtU_Power_Control_T));

  /* external outputs */
  Power_Control_M->outputs = (&Power_Control_Y);
  (void)memset(&Power_Control_Y, 0, sizeof(ExtY_Power_Control_T));

  /* Initialize Sizes */
  Power_Control_M->Sizes.numContStates = (0);/* Number of continuous states */
  Power_Control_M->Sizes.numY = (5);   /* Number of model outputs */
  Power_Control_M->Sizes.numU = (8);   /* Number of model inputs */
  Power_Control_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Power_Control_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Power_Control_M->Sizes.numBlocks = (39);/* Number of blocks */
  Power_Control_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  return Power_Control_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
