/*
 * SoC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SoC".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Nov 10 02:58:46 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SoC.h"
#include "SoC_private.h"
#include "look1_binlxpw.h"

/* Block signals (auto storage) */
B_SoC_T SoC_B;

/* Continuous states */
X_SoC_T SoC_X;

/* Block states (auto storage) */
DW_SoC_T SoC_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_SoC_T SoC_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_SoC_T SoC_Y;

/* Real-time model */
RT_MODEL_SoC_T SoC_M_;
RT_MODEL_SoC_T *const SoC_M = &SoC_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SoC_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  SoC_output();
  SoC_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  SoC_output();
  SoC_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void SoC_output(void)
{
  int8_T rtAction;
  real_T rtb_Merge;
  real_T rtb_Saturation1;
  if (rtmIsMajorTimeStep(SoC_M)) {
    /* set solver stop time */
    if (!(SoC_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&SoC_M->solverInfo, ((SoC_M->Timing.clockTickH0 + 1)
        * SoC_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&SoC_M->solverInfo, ((SoC_M->Timing.clockTick0 + 1) *
        SoC_M->Timing.stepSize0 + SoC_M->Timing.clockTickH0 *
        SoC_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SoC_M)) {
    SoC_M->Timing.t[0] = rtsiGetT(&SoC_M->solverInfo);
  }

  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/Car_State'
   */
  if (rtmIsMajorTimeStep(SoC_M)) {
    rtAction = (int8_T)!((SoC_U.Car_State >= 12.0) && (SoC_U.Car_State <= 18.0));
    SoC_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = SoC_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Latches OCV SoC' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    if (rtmIsMajorTimeStep(SoC_M)) {
      /* SignalConversion: '<S4>/OutportBufferForOut1' incorporates:
       *  Constant: '<S4>/Constant'
       */
      rtb_Merge = SoC_P.Constant_Value;
    }

    /* End of Outputs for SubSystem: '<S1>/Latches OCV SoC' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Measures OCV SoC' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    if (rtmIsMajorTimeStep(SoC_M)) {
      /* SignalConversion: '<S5>/OutportBufferForOut0' incorporates:
       *  Constant: '<S5>/Constant'
       */
      rtb_Merge = SoC_P.Constant_Value_j;
    }

    /* End of Outputs for SubSystem: '<S1>/Measures OCV SoC' */
    break;
  }

  /* End of If: '<S1>/If' */
  if (rtmIsMajorTimeStep(SoC_M)) {
    /* Logic: '<S3>/NOT' */
    SoC_B.NOT = !(rtb_Merge != 0.0);

    /* Memory: '<S3>/Memory' */
    SoC_B.Memory = SoC_DW.Memory_PreviousInput;
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Inport: '<Root>/Lowest_CellVoltage'
   *  Lookup_n-D: '<S3>/OCV to SoC'
   */
  if (SoC_B.NOT) {
    SoC_B.Switch = look1_binlxpw(SoC_U.Lowest_CellVoltage,
      SoC_P.OCVtoSoC_bp01Data_n, SoC_P.OCVtoSoC_tableData_k, 25U);
  } else {
    SoC_B.Switch = SoC_B.Memory;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Add' incorporates:
   *  Gain: '<S3>/Gain'
   *  Integrator: '<S3>/Integrator'
   */
  rtb_Saturation1 = SoC_B.Switch - SoC_P.Gain_Gain * SoC_X.Integrator_CSTATE;

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_Saturation1 > SoC_P.Saturation1_UpperSat) {
    rtb_Saturation1 = SoC_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation1 < SoC_P.Saturation1_LowerSat) {
      rtb_Saturation1 = SoC_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<S3>/Saturation1' */
  if (rtmIsMajorTimeStep(SoC_M)) {
    /* Logic: '<S2>/NOT' */
    SoC_B.NOT_p = !(rtb_Merge != 0.0);

    /* Memory: '<S2>/Memory' */
    SoC_B.Memory_p = SoC_DW.Memory_PreviousInput_p;
  }

  /* Switch: '<S2>/Switch' incorporates:
   *  Inport: '<Root>/Highest_CellVoltage'
   *  Lookup_n-D: '<S2>/OCV to SoC'
   */
  if (SoC_B.NOT_p) {
    SoC_B.Switch_d = look1_binlxpw(SoC_U.Highest_CellVoltage,
      SoC_P.OCVtoSoC_bp01Data, SoC_P.OCVtoSoC_tableData, 25U);
  } else {
    SoC_B.Switch_d = SoC_B.Memory_p;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Sum: '<S2>/Add' incorporates:
   *  Gain: '<S2>/Gain'
   *  Integrator: '<S2>/Integrator'
   */
  rtb_Merge = SoC_B.Switch_d - SoC_P.Gain_Gain_e * SoC_X.Integrator_CSTATE_b;

  /* Saturate: '<S2>/Saturation1' */
  if (rtb_Merge > SoC_P.Saturation1_UpperSat_m) {
    rtb_Merge = SoC_P.Saturation1_UpperSat_m;
  } else {
    if (rtb_Merge < SoC_P.Saturation1_LowerSat_e) {
      rtb_Merge = SoC_P.Saturation1_LowerSat_e;
    }
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Outport: '<Root>/SoC_Avg' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Sum: '<Root>/Add'
   */
  SoC_Y.SoC_Avg = (rtb_Saturation1 + rtb_Merge) * SoC_P.Gain1_Gain;

  /* Outport: '<Root>/SoC_Low' */
  SoC_Y.SoC_Low = rtb_Saturation1;

  /* Outport: '<Root>/SoC_High' */
  SoC_Y.SoC_High = rtb_Merge;
}

/* Model update function */
void SoC_update(void)
{
  if (rtmIsMajorTimeStep(SoC_M)) {
    /* Update for Memory: '<S3>/Memory' */
    SoC_DW.Memory_PreviousInput = SoC_B.Switch;

    /* Update for Memory: '<S2>/Memory' */
    SoC_DW.Memory_PreviousInput_p = SoC_B.Switch_d;
  }

  if (rtmIsMajorTimeStep(SoC_M)) {
    rt_ertODEUpdateContinuousStates(&SoC_M->solverInfo);
  }

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

  SoC_M->Timing.t[0] = rtsiGetSolverStopTime(&SoC_M->solverInfo);

  {
    /* Update absolute timer for sample time: [280.0s, 0.0s] */
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
}

/* Derivatives for root system: '<Root>' */
void SoC_derivatives(void)
{
  XDot_SoC_T *_rtXdot;
  _rtXdot = ((XDot_SoC_T *) SoC_M->derivs);

  /* Derivatives for Integrator: '<S3>/Integrator' incorporates:
   *  Inport: '<Root>/Accumulator_Current'
   */
  _rtXdot->Integrator_CSTATE = SoC_U.Accumulator_Current;

  /* Derivatives for Integrator: '<S2>/Integrator' incorporates:
   *  Inport: '<Root>/Accumulator_Current'
   */
  _rtXdot->Integrator_CSTATE_b = SoC_U.Accumulator_Current;
}

/* Model initialize function */
void SoC_initialize(void)
{
  /* Start for If: '<S1>/If' */
  SoC_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  SoC_DW.Memory_PreviousInput = SoC_P.Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  SoC_X.Integrator_CSTATE = SoC_P.Integrator_IC;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  SoC_DW.Memory_PreviousInput_p = SoC_P.Memory_InitialCondition_o;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  SoC_X.Integrator_CSTATE_b = SoC_P.Integrator_IC_d;
}

/* Model terminate function */
void SoC_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

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

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SoC_M->solverInfo, &SoC_M->Timing.simTimeStep);
    rtsiSetTPtr(&SoC_M->solverInfo, &rtmGetTPtr(SoC_M));
    rtsiSetStepSizePtr(&SoC_M->solverInfo, &SoC_M->Timing.stepSize0);
    rtsiSetdXPtr(&SoC_M->solverInfo, &SoC_M->derivs);
    rtsiSetContStatesPtr(&SoC_M->solverInfo, (real_T **) &SoC_M->contStates);
    rtsiSetNumContStatesPtr(&SoC_M->solverInfo, &SoC_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&SoC_M->solverInfo,
      &SoC_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&SoC_M->solverInfo,
      &SoC_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&SoC_M->solverInfo,
      &SoC_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&SoC_M->solverInfo, (&rtmGetErrorStatus(SoC_M)));
    rtsiSetRTModelPtr(&SoC_M->solverInfo, SoC_M);
  }

  rtsiSetSimTimeStep(&SoC_M->solverInfo, MAJOR_TIME_STEP);
  SoC_M->intgData.y = SoC_M->odeY;
  SoC_M->intgData.f[0] = SoC_M->odeF[0];
  SoC_M->intgData.f[1] = SoC_M->odeF[1];
  SoC_M->intgData.f[2] = SoC_M->odeF[2];
  SoC_M->contStates = ((real_T *) &SoC_X);
  rtsiSetSolverData(&SoC_M->solverInfo, (void *)&SoC_M->intgData);
  rtsiSetSolverName(&SoC_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = SoC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    SoC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SoC_M->Timing.sampleTimes = (&SoC_M->Timing.sampleTimesArray[0]);
    SoC_M->Timing.offsetTimes = (&SoC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SoC_M->Timing.sampleTimes[0] = (0.0);
    SoC_M->Timing.sampleTimes[1] = (280.0);

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
  SoC_M->Timing.stepSize0 = 280.0;
  SoC_M->Timing.stepSize1 = 280.0;
  SoC_M->solverInfoPtr = (&SoC_M->solverInfo);
  SoC_M->Timing.stepSize = (280.0);
  rtsiSetFixedStepSize(&SoC_M->solverInfo, 280.0);
  rtsiSetSolverMode(&SoC_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  SoC_M->blockIO = ((void *) &SoC_B);
  (void) memset(((void *) &SoC_B), 0,
                sizeof(B_SoC_T));

  /* parameters */
  SoC_M->defaultParam = ((real_T *)&SoC_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &SoC_X;
    SoC_M->contStates = (x);
    (void) memset((void *)&SoC_X, 0,
                  sizeof(X_SoC_T));
  }

  /* states (dwork) */
  SoC_M->dwork = ((void *) &SoC_DW);
  (void) memset((void *)&SoC_DW, 0,
                sizeof(DW_SoC_T));

  /* external inputs */
  SoC_M->inputs = (((void*)&SoC_U));
  (void)memset((void *)&SoC_U, 0, sizeof(ExtU_SoC_T));

  /* external outputs */
  SoC_M->outputs = (&SoC_Y);
  (void) memset((void *)&SoC_Y, 0,
                sizeof(ExtY_SoC_T));

  /* Initialize Sizes */
  SoC_M->Sizes.numContStates = (2);    /* Number of continuous states */
  SoC_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  SoC_M->Sizes.numY = (3);             /* Number of model outputs */
  SoC_M->Sizes.numU = (4);             /* Number of model inputs */
  SoC_M->Sizes.sysDirFeedThru = (1);   /* The model is direct feedthrough */
  SoC_M->Sizes.numSampTimes = (2);     /* Number of sample times */
  SoC_M->Sizes.numBlocks = (31);       /* Number of blocks */
  SoC_M->Sizes.numBlockIO = (6);       /* Number of block outputs */
  SoC_M->Sizes.numBlockPrms = (117);   /* Sum of parameter "widths" */
  return SoC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
