/*
 * Synchronism_ETR07.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Synchronism_ETR07".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue Apr 12 15:35:12 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Synchronism_ETR07.h"
#include "Synchronism_ETR07_private.h"

/* Block states (auto storage) */
DW_Synchronism_ETR07_T Synchronism_ETR07_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Synchronism_ETR07_T Synchronism_ETR07_Y;

/* Real-time model */
RT_MODEL_Synchronism_ETR07_T Synchronism_ETR07_M_;
RT_MODEL_Synchronism_ETR07_T *const Synchronism_ETR07_M = &Synchronism_ETR07_M_;

/* Model output function */
static void Synchronism_ETR07_output(void)
{
  real_T rtb_Add;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read'
   */
  rtb_Add = Synchronism_ETR07_DW.counter + Synchronism_ETR07_P.Constant_Value_e;

  /* If: '<S1>/If' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (Synchronism_ETR07_P.Constant1_Value < rtb_Add) {
    /* Outputs for IfAction SubSystem: '<S1>/Reset_counter' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* SignalConversion: '<S4>/OutportBufferFor1' incorporates:
     *  Constant: '<S4>/Constant'
     */
    rtb_Add = Synchronism_ETR07_P.Constant_Value;

    /* End of Outputs for SubSystem: '<S1>/Reset_counter' */
  }

  /* End of If: '<S1>/If' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  Synchronism_ETR07_DW.counter = rtb_Add;

  /* Outport: '<Root>/Sync_CAN1' */
  Synchronism_ETR07_Y.Sync_CAN1 = rtb_Add;

  /* Outport: '<Root>/Sync_CAN2' */
  Synchronism_ETR07_Y.Sync_CAN2 = rtb_Add;
}

/* Model update function */
static void Synchronism_ETR07_update(void)
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
  if (!(++Synchronism_ETR07_M->Timing.clockTick0)) {
    ++Synchronism_ETR07_M->Timing.clockTickH0;
  }

  Synchronism_ETR07_M->Timing.t[0] = Synchronism_ETR07_M->Timing.clockTick0 *
    Synchronism_ETR07_M->Timing.stepSize0 +
    Synchronism_ETR07_M->Timing.clockTickH0 *
    Synchronism_ETR07_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Synchronism_ETR07_initialize(void)
{
  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  Synchronism_ETR07_DW.counter =
    Synchronism_ETR07_P.DataStoreMemory_InitialValue;
}

/* Model terminate function */
static void Synchronism_ETR07_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Synchronism_ETR07_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Synchronism_ETR07_update();
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
  Synchronism_ETR07_initialize();
}

void MdlTerminate(void)
{
  Synchronism_ETR07_terminate();
}

/* Registration function */
RT_MODEL_Synchronism_ETR07_T *Synchronism_ETR07(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Synchronism_ETR07_M, 0,
                sizeof(RT_MODEL_Synchronism_ETR07_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Synchronism_ETR07_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Synchronism_ETR07_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Synchronism_ETR07_M->Timing.sampleTimes =
      (&Synchronism_ETR07_M->Timing.sampleTimesArray[0]);
    Synchronism_ETR07_M->Timing.offsetTimes =
      (&Synchronism_ETR07_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Synchronism_ETR07_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Synchronism_ETR07_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Synchronism_ETR07_M, &Synchronism_ETR07_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Synchronism_ETR07_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Synchronism_ETR07_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Synchronism_ETR07_M, 10.0);
  Synchronism_ETR07_M->Timing.stepSize0 = 0.2;
  Synchronism_ETR07_M->solverInfoPtr = (&Synchronism_ETR07_M->solverInfo);
  Synchronism_ETR07_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Synchronism_ETR07_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Synchronism_ETR07_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  Synchronism_ETR07_M->defaultParam = ((real_T *)&Synchronism_ETR07_P);

  /* states (dwork) */
  Synchronism_ETR07_M->dwork = ((void *) &Synchronism_ETR07_DW);
  (void) memset((void *)&Synchronism_ETR07_DW, 0,
                sizeof(DW_Synchronism_ETR07_T));

  /* external outputs */
  Synchronism_ETR07_M->outputs = (&Synchronism_ETR07_Y);
  (void) memset((void *)&Synchronism_ETR07_Y, 0,
                sizeof(ExtY_Synchronism_ETR07_T));

  /* Initialize Sizes */
  Synchronism_ETR07_M->Sizes.numContStates = (0);/* Number of continuous states */
  Synchronism_ETR07_M->Sizes.numY = (2);/* Number of model outputs */
  Synchronism_ETR07_M->Sizes.numU = (0);/* Number of model inputs */
  Synchronism_ETR07_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Synchronism_ETR07_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Synchronism_ETR07_M->Sizes.numBlocks = (15);/* Number of blocks */
  Synchronism_ETR07_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  Synchronism_ETR07_M->Sizes.numBlockPrms = (4);/* Sum of parameter "widths" */
  return Synchronism_ETR07_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
