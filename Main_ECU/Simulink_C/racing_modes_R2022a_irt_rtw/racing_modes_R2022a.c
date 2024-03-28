/*
 * racing_modes_R2022a.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "racing_modes_R2022a".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Thu Mar 28 12:36:23 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "racing_modes_R2022a.h"
#include "rtwtypes.h"
#include "racing_modes_R2022a_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
B_racing_modes_R2022a_T racing_modes_R2022a_B;

/* External inputs (root inport signals with default storage) */
ExtU_racing_modes_R2022a_T racing_modes_R2022a_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_racing_modes_R2022a_T racing_modes_R2022a_Y;

/* Real-time model */
static RT_MODEL_racing_modes_R2022a_T racing_modes_R2022a_M_;
RT_MODEL_racing_modes_R2022a_T *const racing_modes_R2022a_M =
  &racing_modes_R2022a_M_;

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
void racing_modes_R20_WorkshopTest01(real_T *rty_Params)
{
  /* SignalConversion generated from: '<S5>/Params' incorporates:
   *  Constant: '<S5>/Max tyre slip'
   */
  *rty_Params = 1.0;
}

/* Model output function */
static void racing_modes_R2022a_output(void)
{
  /* SwitchCase: '<Root>/Selecció de Mode' incorporates:
   *  Inport: '<Root>/RacingMode'
   */
  switch (racing_modes_R2022a_U.RacingMode) {
   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Workshop Test (01)' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    racing_modes_R20_WorkshopTest01(&racing_modes_R2022a_B.Merge);

    /* End of Outputs for SubSystem: '<Root>/Workshop Test (01)' */
    break;

   case 2:
    {
      real_T tmp;

      /* Outputs for IfAction SubSystem: '<Root>/Custom Dash (11)' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* SwitchCase: '<S2>/Switch Case' incorporates:
       *  Inport: '<Root>/CustomMode_Identifier'
       */
      tmp = trunc(racing_modes_R2022a_U.CustomMode_Identifier);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      if ((tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) == 1)
      {
        /* Outputs for IfAction SubSystem: '<S2>/Max tyre slip' incorporates:
         *  ActionPort: '<S6>/Action Port'
         */
        /* Gain: '<S6>/Gain' incorporates:
         *  Inport: '<Root>/CustomMode_Data'
         */
        racing_modes_R2022a_B.Gain = 0.001 *
          racing_modes_R2022a_U.CustomMode_Data;

        /* End of Outputs for SubSystem: '<S2>/Max tyre slip' */
      }

      /* End of SwitchCase: '<S2>/Switch Case' */

      /* Merge: '<Root>/Merge' incorporates:
       *  SignalConversion generated from: '<S2>/Params'
       */
      racing_modes_R2022a_B.Merge = racing_modes_R2022a_B.Gain;

      /* End of Outputs for SubSystem: '<Root>/Custom Dash (11)' */
    }
    break;

   case 21:
   case 31:
   case 41:
   case 51:
    /* Outputs for IfAction SubSystem: '<Root>/Driver 1 Modes (21,31,41,51)' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* SwitchCase: '<S3>/Selecció de Mode' */
    switch (racing_modes_R2022a_U.RacingMode) {
     case 21:
      /* Outputs for IfAction SubSystem: '<S3>/Acceleration (2). Driver 1 (1) ' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      racing_modes_R20_WorkshopTest01(&racing_modes_R2022a_B.Merge);

      /* End of Outputs for SubSystem: '<S3>/Acceleration (2). Driver 1 (1) ' */
      break;

     case 31:
      /* Outputs for IfAction SubSystem: '<S3>/Skidpad (3). Driver 1 (1)' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      racing_modes_R20_WorkshopTest01(&racing_modes_R2022a_B.Merge);

      /* End of Outputs for SubSystem: '<S3>/Skidpad (3). Driver 1 (1)' */
      break;

     case 41:
      /* Outputs for IfAction SubSystem: '<S3>/AutoX (4). Driver 1 (1)' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      racing_modes_R20_WorkshopTest01(&racing_modes_R2022a_B.Merge);

      /* End of Outputs for SubSystem: '<S3>/AutoX (4). Driver 1 (1)' */
      break;

     case 51:
      /* Outputs for IfAction SubSystem: '<S3>/Endurance (5). Driver 1 (1)' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      racing_modes_R20_WorkshopTest01(&racing_modes_R2022a_B.Merge);

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
    switch (racing_modes_R2022a_U.RacingMode) {
     case 22:
      /* Outputs for IfAction SubSystem: '<S4>/Acceleration (2). Driver 2 (2) ' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      racing_modes_R20_WorkshopTest01(&racing_modes_R2022a_B.Merge);

      /* End of Outputs for SubSystem: '<S4>/Acceleration (2). Driver 2 (2) ' */
      break;

     case 32:
      /* Outputs for IfAction SubSystem: '<S4>/Skidpad (3). Driver 2 (2)' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      racing_modes_R20_WorkshopTest01(&racing_modes_R2022a_B.Merge);

      /* End of Outputs for SubSystem: '<S4>/Skidpad (3). Driver 2 (2)' */
      break;

     case 42:
      /* Outputs for IfAction SubSystem: '<S4>/AutoX (4). Driver 2 (2)' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      racing_modes_R20_WorkshopTest01(&racing_modes_R2022a_B.Merge);

      /* End of Outputs for SubSystem: '<S4>/AutoX (4). Driver 2 (2)' */
      break;

     case 52:
      /* Outputs for IfAction SubSystem: '<S4>/Endurance (5). Driver 2 (2)' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<S13>/Max tyre slip1'
       *  SignalConversion generated from: '<S13>/Params1'
       */
      racing_modes_R2022a_B.Merge = 1.0;

      /* End of Outputs for SubSystem: '<S4>/Endurance (5). Driver 2 (2)' */
      break;
    }

    /* End of SwitchCase: '<S4>/Selecció de Mode' */
    /* End of Outputs for SubSystem: '<Root>/Driver 2 Modes (22,32,42,52)' */
    break;
  }

  /* End of SwitchCase: '<Root>/Selecció de Mode' */

  /* Outport: '<Root>/VDC_Max_tire_slip' */
  racing_modes_R2022a_Y.VDC_Max_tire_slip = racing_modes_R2022a_B.Merge;

  /* Outport: '<Root>/Workshop_Mode_Enable' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/RacingMode'
   *  RelationalOperator: '<S1>/Compare'
   */
  racing_modes_R2022a_Y.Workshop_Mode_Enable = (racing_modes_R2022a_U.RacingMode
    == 1);
}

/* Model update function */
static void racing_modes_R2022a_update(void)
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
  if (!(++racing_modes_R2022a_M->Timing.clockTick0)) {
    ++racing_modes_R2022a_M->Timing.clockTickH0;
  }

  racing_modes_R2022a_M->Timing.t[0] = racing_modes_R2022a_M->Timing.clockTick0 *
    racing_modes_R2022a_M->Timing.stepSize0 +
    racing_modes_R2022a_M->Timing.clockTickH0 *
    racing_modes_R2022a_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void racing_modes_R2022a_initialize(void)
{
  /* SystemInitialize for IfAction SubSystem: '<Root>/Custom Dash (11)' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/Max tyre slip' */
  /* SystemInitialize for Gain: '<S6>/Gain' incorporates:
   *  Outport: '<S6>/Params'
   */
  racing_modes_R2022a_B.Gain = 0.0;

  /* End of SystemInitialize for SubSystem: '<S2>/Max tyre slip' */
  /* End of SystemInitialize for SubSystem: '<Root>/Custom Dash (11)' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  racing_modes_R2022a_B.Merge = 0.0;
}

/* Model terminate function */
static void racing_modes_R2022a_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  racing_modes_R2022a_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  racing_modes_R2022a_update();
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
  racing_modes_R2022a_initialize();
}

void MdlTerminate(void)
{
  racing_modes_R2022a_terminate();
}

/* Registration function */
RT_MODEL_racing_modes_R2022a_T *racing_modes_R2022a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)racing_modes_R2022a_M, 0,
                sizeof(RT_MODEL_racing_modes_R2022a_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = racing_modes_R2022a_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "racing_modes_R2022a_M points to
       static memory which is guaranteed to be non-NULL" */
    racing_modes_R2022a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    racing_modes_R2022a_M->Timing.sampleTimes =
      (&racing_modes_R2022a_M->Timing.sampleTimesArray[0]);
    racing_modes_R2022a_M->Timing.offsetTimes =
      (&racing_modes_R2022a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    racing_modes_R2022a_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    racing_modes_R2022a_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(racing_modes_R2022a_M, &racing_modes_R2022a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = racing_modes_R2022a_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    racing_modes_R2022a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(racing_modes_R2022a_M, 10.0);
  racing_modes_R2022a_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    racing_modes_R2022a_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(racing_modes_R2022a_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(racing_modes_R2022a_M->rtwLogInfo, (NULL));
    rtliSetLogT(racing_modes_R2022a_M->rtwLogInfo, "tout");
    rtliSetLogX(racing_modes_R2022a_M->rtwLogInfo, "");
    rtliSetLogXFinal(racing_modes_R2022a_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(racing_modes_R2022a_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(racing_modes_R2022a_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(racing_modes_R2022a_M->rtwLogInfo, 0);
    rtliSetLogDecimation(racing_modes_R2022a_M->rtwLogInfo, 1);
    rtliSetLogY(racing_modes_R2022a_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(racing_modes_R2022a_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(racing_modes_R2022a_M->rtwLogInfo, (NULL));
  }

  racing_modes_R2022a_M->solverInfoPtr = (&racing_modes_R2022a_M->solverInfo);
  racing_modes_R2022a_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&racing_modes_R2022a_M->solverInfo, 0.2);
  rtsiSetSolverMode(&racing_modes_R2022a_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  racing_modes_R2022a_M->blockIO = ((void *) &racing_modes_R2022a_B);
  (void) memset(((void *) &racing_modes_R2022a_B), 0,
                sizeof(B_racing_modes_R2022a_T));

  /* external inputs */
  racing_modes_R2022a_M->inputs = (((void*)&racing_modes_R2022a_U));
  (void)memset(&racing_modes_R2022a_U, 0, sizeof(ExtU_racing_modes_R2022a_T));

  /* external outputs */
  racing_modes_R2022a_M->outputs = (&racing_modes_R2022a_Y);
  (void)memset(&racing_modes_R2022a_Y, 0, sizeof(ExtY_racing_modes_R2022a_T));

  /* Initialize Sizes */
  racing_modes_R2022a_M->Sizes.numContStates = (0);/* Number of continuous states */
  racing_modes_R2022a_M->Sizes.numY = (2);/* Number of model outputs */
  racing_modes_R2022a_M->Sizes.numU = (3);/* Number of model inputs */
  racing_modes_R2022a_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  racing_modes_R2022a_M->Sizes.numSampTimes = (1);/* Number of sample times */
  racing_modes_R2022a_M->Sizes.numBlocks = (30);/* Number of blocks */
  racing_modes_R2022a_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  return racing_modes_R2022a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
