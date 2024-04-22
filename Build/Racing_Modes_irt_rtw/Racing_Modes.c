/*
 * Racing_Modes.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Racing_Modes".
 *
 * Model version              : 4.0
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Apr 22 17:10:27 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Racing_Modes.h"
#include "rtwtypes.h"
#include "Racing_Modes_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
B_Racing_Modes_T Racing_Modes_B;

/* External inputs (root inport signals with default storage) */
ExtU_Racing_Modes_T Racing_Modes_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Racing_Modes_T Racing_Modes_Y;

/* Real-time model */
static RT_MODEL_Racing_Modes_T Racing_Modes_M_;
RT_MODEL_Racing_Modes_T *const Racing_Modes_M = &Racing_Modes_M_;

/*
 * Output and update for action system:
 *    '<Root>/Workshop Test (01)'
 *    '<S3>/Acceleration (2). Driver 1 (1) '
 *    '<S3>/Skidpad (3). Driver 1 (1)'
 *    '<S3>/AutoX (4). Driver 1 (1)'
 *    '<S3>/Endurance (5). Driver 1 (1)'
 *    '<S4>/Acceleration (2). Driver 2 (2) '
 *    '<S4>/Skidpad (3). Driver 2 (2)'
 *    '<S4>/AutoX (4). Driver 2 (2)'
 */
void Racing_Modes_WorkshopTest01(real_T *rty_Params)
{
  /* SignalConversion generated from: '<S5>/Params' incorporates:
   *  Constant: '<S5>/Max tyre slip'
   */
  *rty_Params = 1.0;
}

/* Model output function */
static void Racing_Modes_output(void)
{
  real_T tmp;

  /* SwitchCase: '<Root>/Mode Selection' incorporates:
   *  Inport: '<Root>/RacingMode'
   */
  switch (Racing_Modes_U.RacingMode) {
   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Workshop Test (01)' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    Racing_Modes_WorkshopTest01(&Racing_Modes_B.Merge);

    /* End of Outputs for SubSystem: '<Root>/Workshop Test (01)' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<Root>/Custom Dash (11)' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SwitchCase: '<S2>/Switch Case' incorporates:
     *  Inport: '<Root>/CustomMode_Identifier'
     */
    tmp = trunc(Racing_Modes_U.CustomMode_Identifier);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    if ((tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) == 1) {
      /* Outputs for IfAction SubSystem: '<S2>/Max tyre slip' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* Gain: '<S6>/Gain' incorporates:
       *  Inport: '<Root>/CustomMode_Data'
       */
      Racing_Modes_B.Gain = 0.001 * Racing_Modes_U.CustomMode_Data;

      /* End of Outputs for SubSystem: '<S2>/Max tyre slip' */
    }

    /* End of SwitchCase: '<S2>/Switch Case' */

    /* Merge: '<Root>/Merge' incorporates:
     *  SignalConversion generated from: '<S2>/Params'
     */
    Racing_Modes_B.Merge = Racing_Modes_B.Gain;

    /* End of Outputs for SubSystem: '<Root>/Custom Dash (11)' */
    break;

   case 21:
   case 31:
   case 41:
   case 51:
    /* Outputs for IfAction SubSystem: '<Root>/Driver 1 Modes (21,31,41,51)' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* SwitchCase: '<S3>/Selecció de Mode' */
    switch (Racing_Modes_U.RacingMode) {
     case 21:
      /* Outputs for IfAction SubSystem: '<S3>/Acceleration (2). Driver 1 (1) ' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      Racing_Modes_WorkshopTest01(&Racing_Modes_B.Merge);

      /* End of Outputs for SubSystem: '<S3>/Acceleration (2). Driver 1 (1) ' */
      break;

     case 31:
      /* Outputs for IfAction SubSystem: '<S3>/Skidpad (3). Driver 1 (1)' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      Racing_Modes_WorkshopTest01(&Racing_Modes_B.Merge);

      /* End of Outputs for SubSystem: '<S3>/Skidpad (3). Driver 1 (1)' */
      break;

     case 41:
      /* Outputs for IfAction SubSystem: '<S3>/AutoX (4). Driver 1 (1)' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      Racing_Modes_WorkshopTest01(&Racing_Modes_B.Merge);

      /* End of Outputs for SubSystem: '<S3>/AutoX (4). Driver 1 (1)' */
      break;

     case 51:
      /* Outputs for IfAction SubSystem: '<S3>/Endurance (5). Driver 1 (1)' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      Racing_Modes_WorkshopTest01(&Racing_Modes_B.Merge);

      /* End of Outputs for SubSystem: '<S3>/Endurance (5). Driver 1 (1)' */
      break;
    }

    /* End of SwitchCase: '<S3>/Selecció de Mode' */
    /* End of Outputs for SubSystem: '<Root>/Driver 1 Modes (21,31,41,51)' */
    break;

   case 22:
   case 32:
   case 42:
   case 52:
    /* Outputs for IfAction SubSystem: '<Root>/Driver 2 Modes (22,32,42,52)' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* SwitchCase: '<S4>/Selecció de Mode' */
    switch (Racing_Modes_U.RacingMode) {
     case 22:
      /* Outputs for IfAction SubSystem: '<S4>/Acceleration (2). Driver 2 (2) ' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      Racing_Modes_WorkshopTest01(&Racing_Modes_B.Merge);

      /* End of Outputs for SubSystem: '<S4>/Acceleration (2). Driver 2 (2) ' */
      break;

     case 32:
      /* Outputs for IfAction SubSystem: '<S4>/Skidpad (3). Driver 2 (2)' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      Racing_Modes_WorkshopTest01(&Racing_Modes_B.Merge);

      /* End of Outputs for SubSystem: '<S4>/Skidpad (3). Driver 2 (2)' */
      break;

     case 42:
      /* Outputs for IfAction SubSystem: '<S4>/AutoX (4). Driver 2 (2)' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      Racing_Modes_WorkshopTest01(&Racing_Modes_B.Merge);

      /* End of Outputs for SubSystem: '<S4>/AutoX (4). Driver 2 (2)' */
      break;

     case 52:
      /* Outputs for IfAction SubSystem: '<S4>/Endurance (5). Driver 2 (2)' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<S13>/Max tyre slip'
       *  SignalConversion generated from: '<S13>/Params1'
       */
      Racing_Modes_B.Merge = 1.0;

      /* End of Outputs for SubSystem: '<S4>/Endurance (5). Driver 2 (2)' */
      break;
    }

    /* End of SwitchCase: '<S4>/Selecció de Mode' */
    /* End of Outputs for SubSystem: '<Root>/Driver 2 Modes (22,32,42,52)' */
    break;
  }

  /* End of SwitchCase: '<Root>/Mode Selection' */

  /* Outport: '<Root>/VDC_Max_Tyre_Slip' */
  Racing_Modes_Y.VDC_Max_Tyre_Slip = Racing_Modes_B.Merge;

  /* Outport: '<Root>/Workshop_Mode_Enable' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/RacingMode'
   *  RelationalOperator: '<S1>/Compare'
   */
  Racing_Modes_Y.Workshop_Mode_Enable = (Racing_Modes_U.RacingMode == 1);
}

/* Model update function */
static void Racing_Modes_update(void)
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
  if (!(++Racing_Modes_M->Timing.clockTick0)) {
    ++Racing_Modes_M->Timing.clockTickH0;
  }

  Racing_Modes_M->Timing.t[0] = Racing_Modes_M->Timing.clockTick0 *
    Racing_Modes_M->Timing.stepSize0 + Racing_Modes_M->Timing.clockTickH0 *
    Racing_Modes_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Racing_Modes_initialize(void)
{
  /* SystemInitialize for IfAction SubSystem: '<Root>/Custom Dash (11)' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/Max tyre slip' */
  /* SystemInitialize for Gain: '<S6>/Gain' incorporates:
   *  Outport: '<S6>/Params'
   */
  Racing_Modes_B.Gain = 0.0;

  /* End of SystemInitialize for SubSystem: '<S2>/Max tyre slip' */
  /* End of SystemInitialize for SubSystem: '<Root>/Custom Dash (11)' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  Racing_Modes_B.Merge = 0.0;
}

/* Model terminate function */
static void Racing_Modes_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Racing_Modes_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Racing_Modes_update();
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
  Racing_Modes_initialize();
}

void MdlTerminate(void)
{
  Racing_Modes_terminate();
}

/* Registration function */
RT_MODEL_Racing_Modes_T *Racing_Modes(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Racing_Modes_M, 0,
                sizeof(RT_MODEL_Racing_Modes_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Racing_Modes_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Racing_Modes_M points to
       static memory which is guaranteed to be non-NULL" */
    Racing_Modes_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Racing_Modes_M->Timing.sampleTimes =
      (&Racing_Modes_M->Timing.sampleTimesArray[0]);
    Racing_Modes_M->Timing.offsetTimes =
      (&Racing_Modes_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Racing_Modes_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Racing_Modes_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Racing_Modes_M, &Racing_Modes_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Racing_Modes_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Racing_Modes_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Racing_Modes_M, 10.0);
  Racing_Modes_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Racing_Modes_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Racing_Modes_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Racing_Modes_M->rtwLogInfo, (NULL));
    rtliSetLogT(Racing_Modes_M->rtwLogInfo, "tout");
    rtliSetLogX(Racing_Modes_M->rtwLogInfo, "");
    rtliSetLogXFinal(Racing_Modes_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Racing_Modes_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Racing_Modes_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Racing_Modes_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Racing_Modes_M->rtwLogInfo, 1);
    rtliSetLogY(Racing_Modes_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Racing_Modes_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Racing_Modes_M->rtwLogInfo, (NULL));
  }

  Racing_Modes_M->solverInfoPtr = (&Racing_Modes_M->solverInfo);
  Racing_Modes_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Racing_Modes_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Racing_Modes_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Racing_Modes_M->blockIO = ((void *) &Racing_Modes_B);
  (void) memset(((void *) &Racing_Modes_B), 0,
                sizeof(B_Racing_Modes_T));

  /* external inputs */
  Racing_Modes_M->inputs = (((void*)&Racing_Modes_U));
  (void)memset(&Racing_Modes_U, 0, sizeof(ExtU_Racing_Modes_T));

  /* external outputs */
  Racing_Modes_M->outputs = (&Racing_Modes_Y);
  (void)memset(&Racing_Modes_Y, 0, sizeof(ExtY_Racing_Modes_T));

  /* Initialize Sizes */
  Racing_Modes_M->Sizes.numContStates = (0);/* Number of continuous states */
  Racing_Modes_M->Sizes.numY = (2);    /* Number of model outputs */
  Racing_Modes_M->Sizes.numU = (3);    /* Number of model inputs */
  Racing_Modes_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Racing_Modes_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Racing_Modes_M->Sizes.numBlocks = (30);/* Number of blocks */
  Racing_Modes_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  return Racing_Modes_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
