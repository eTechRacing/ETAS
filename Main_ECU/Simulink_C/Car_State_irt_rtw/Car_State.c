/*
 * Car_State.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Car_State".
 *
 * Model version              : 10.13
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Thu Mar 28 11:14:28 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Car_State.h"
#include "rtwtypes.h"
#include "Car_State_private.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<Root>/Car State Manager' */
#define Car_State_IN_EnableInverters   ((uint8_T)1U)
#define Car_State_IN_Init              ((uint8_T)7U)
#define Car_State_IN_Locked            ((uint8_T)2U)
#define Car_State_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define Car_State_IN_OpenAirs          ((uint8_T)9U)
#define Car_State_IN_PrechargeDONE     ((uint8_T)5U)
#define Car_State_IN_PrechargeINIT     ((uint8_T)6U)
#define Car_State_IN_RTD               ((uint8_T)3U)
#define Car_State_IN_Standby           ((uint8_T)8U)
#define Car_State_IN_TSActive          ((uint8_T)4U)

/* Block signals (default storage) */
B_Car_State_T Car_State_B;

/* Block states (default storage) */
DW_Car_State_T Car_State_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Car_State_T Car_State_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Car_State_T Car_State_Y;

/* Real-time model */
static RT_MODEL_Car_State_T Car_State_M_;
RT_MODEL_Car_State_T *const Car_State_M = &Car_State_M_;

/*
 * Output and update for action system:
 *    '<S1>/TRUE'
 *    '<S2>/TRUE'
 *    '<S3>/TRUE'
 *    '<S9>/TRUE'
 */
void Car_State_TRUE(real_T *rty_u)
{
  /* SignalConversion generated from: '<S11>/1' incorporates:
   *  Constant: '<S11>/Constant'
   */
  *rty_u = 1.0;
}

/*
 * Output and update for action system:
 *    '<S1>/FALSE'
 *    '<S2>/FALSE'
 *    '<S3>/FALSE'
 *    '<S4>/Obrir AIRs'
 *    '<S9>/FALSE'
 */
void Car_State_FALSE(real_T *rty_u)
{
  /* SignalConversion generated from: '<S10>/0' incorporates:
   *  Constant: '<S10>/Constant'
   */
  *rty_u = 0.0;
}

/*
 * Output and update for action system:
 *    '<S7>/Failure'
 *    '<S24>/Latched Error'
 */
void Car_State_Failure(real_T *rty_u)
{
  /* SignalConversion generated from: '<S23>/1 ' incorporates:
   *  Constant: '<S23>/Constant'
   */
  *rty_u = 1.0;
}

/* Model output function */
static void Car_State_output(void)
{
  real_T rtb_Merge;
  real_T rtb_Merge_g;
  real_T rtb_Merge_p;
  real_T rtb_Saturation;
  int32_T rtb_CarState;
  boolean_T rtb_LogicalOperator1;

  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 3.0) {
    /* Outputs for IfAction SubSystem: '<S1>/TRUE' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S1>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/FALSE' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S1>/FALSE' */
  }

  /* End of If: '<S1>/If' */

  /* If: '<S7>/If' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read'
   *  If: '<S24>/If'
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  if ((Car_State_U.InvertersMinDCBus < 60.0) && (rtb_Merge == 1.0)) {
    /* Outputs for IfAction SubSystem: '<S7>/Failure' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    Car_State_Failure(&rtb_Merge_p);

    /* End of Outputs for SubSystem: '<S7>/Failure' */

    /* Outputs for IfAction SubSystem: '<S7>/OK or latch' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
  } else if (Car_State_DW.A > 0.0) {
    /* Outputs for IfAction SubSystem: '<S24>/Latched Error' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* If: '<S24>/If' */
    Car_State_Failure(&rtb_Merge_p);

    /* End of Outputs for SubSystem: '<S24>/Latched Error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S24>/OK' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* If: '<S24>/If' incorporates:
     *  Constant: '<S26>/Constant'
     *  SignalConversion generated from: '<S26>/0 '
     */
    rtb_Merge_p = 0.0;

    /* End of Outputs for SubSystem: '<S24>/OK' */

    /* End of Outputs for SubSystem: '<S7>/OK or latch' */
  }

  /* End of If: '<S7>/If' */

  /* DataStoreWrite: '<S7>/Data Store Write' */
  Car_State_DW.A = rtb_Merge_p;

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/Accumulator_Voltage'
   *  Inport: '<Root>/Critical_CAN_Disconnection'
   *  Inport: '<Root>/PrechargeRequest'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   */
  rtb_LogicalOperator1 = (Car_State_U.Shutdown_PackageIntck &&
    (Car_State_U.Accumulator_Voltage > 420.0) && (Car_State_U.PrechargeRequest ==
    0.0) && (Car_State_U.Critical_CAN_Disconnection == 0.0));

  /* If: '<S3>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 6.0) {
    /* Outputs for IfAction SubSystem: '<S3>/TRUE' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    Car_State_TRUE(&rtb_Saturation);

    /* End of Outputs for SubSystem: '<S3>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/FALSE' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    Car_State_FALSE(&rtb_Saturation);

    /* End of Outputs for SubSystem: '<S3>/FALSE' */
  }

  /* End of If: '<S3>/If' */

  /* If: '<S9>/If' incorporates:
   *  Gain: '<S9>/Gain'
   *  Inport: '<Root>/Accumulator_Voltage'
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  if ((rtb_Saturation == 1.0) && (Car_State_U.InvertersMinDCBus > 0.9 *
       Car_State_U.Accumulator_Voltage)) {
    /* Outputs for IfAction SubSystem: '<S9>/TRUE' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    Car_State_TRUE(&rtb_Saturation);

    /* End of Outputs for SubSystem: '<S9>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/FALSE' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    Car_State_FALSE(&rtb_Saturation);

    /* End of Outputs for SubSystem: '<S9>/FALSE' */
  }

  /* End of If: '<S9>/If' */

  /* If: '<S2>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 0.0) {
    /* Outputs for IfAction SubSystem: '<S2>/TRUE' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge_g);

    /* End of Outputs for SubSystem: '<S2>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/FALSE' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge_g);

    /* End of Outputs for SubSystem: '<S2>/FALSE' */
  }

  /* End of If: '<S2>/If' */

  /* Chart: '<Root>/Car State Manager' incorporates:
   *  Inport: '<Root>/EnableDrive_Order'
   *  Inport: '<Root>/InvertersSubscribed'
   *  Inport: '<Root>/PrechargeRequest'
   *  Inport: '<Root>/Torque_LockON'
   */
  if (Car_State_DW.temporalCounter_i1 < 511U) {
    Car_State_DW.temporalCounter_i1++;
  }

  if (Car_State_DW.is_active_c1_Car_State == 0U) {
    Car_State_DW.is_active_c1_Car_State = 1U;

    /* Outport: '<Root>/errors' */
    Car_State_Y.errors = 0.0;
    Car_State_DW.is_c1_Car_State = Car_State_IN_Init;
    Car_State_DW.temporalCounter_i1 = 0U;
    rtb_CarState = 0;

    /* Outport: '<Root>/TorqueEnable' */
    Car_State_Y.TorqueEnable = 0.0;

    /* Outport: '<Root>/InvertersAction' */
    Car_State_Y.InvertersAction = 20.0;
  } else {
    boolean_T guard1;
    guard1 = false;
    switch (Car_State_DW.is_c1_Car_State) {
     case Car_State_IN_EnableInverters:
      rtb_CarState = 14;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 21.0;
      if (Car_State_DW.temporalCounter_i1 >= 80U) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_RTD;
        rtb_CarState = 15;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 1.0;

        /* Outport: '<Root>/InvertersAction' */
        Car_State_Y.InvertersAction = 30.0;
      } else if (!rtb_LogicalOperator1) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 21;

        /* Outport: '<Root>/InvertersAction' */
        Car_State_Y.InvertersAction = 20.0;
      }
      break;

     case Car_State_IN_Locked:
      rtb_CarState = 13;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 20.0;
      if (((Car_State_U.EnableDrive_Order == 1.0) & (Car_State_U.Torque_LockON ==
            0.0)) != 0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_EnableInverters;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 14;

        /* Outport: '<Root>/InvertersAction' */
        Car_State_Y.InvertersAction = 21.0;
      } else if (!rtb_LogicalOperator1) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 21;
      }
      break;

     case Car_State_IN_RTD:
      rtb_CarState = 15;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 1.0;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 30.0;
      if (!rtb_LogicalOperator1) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 21;

        /* Outport: '<Root>/InvertersAction' */
        Car_State_Y.InvertersAction = 20.0;
      }
      break;

     case Car_State_IN_TSActive:
      rtb_CarState = 12;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 20.0;
      if (Car_State_U.EnableDrive_Order == 1.0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_EnableInverters;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 14;

        /* Outport: '<Root>/InvertersAction' */
        Car_State_Y.InvertersAction = 21.0;
      } else if (!rtb_LogicalOperator1) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 21;
      } else if (Car_State_U.Torque_LockON == 1.0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_Locked;
        rtb_CarState = 13;
      }
      break;

     case Car_State_IN_PrechargeDONE:
      rtb_CarState = 9;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 20.0;
      if (Car_State_DW.temporalCounter_i1 >= 80U) {
        /* Outport: '<Root>/errors' */
        Car_State_Y.errors = 9.0;
        guard1 = true;
      } else if (((rtb_Merge == 1.0) & (Car_State_DW.temporalCounter_i1 >= 4U))
                 != 0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_TSActive;
        rtb_CarState = 12;
      } else if (!rtb_LogicalOperator1) {
        guard1 = true;
      }
      break;

     case Car_State_IN_PrechargeINIT:
      rtb_CarState = 6;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 20.0;
      if (((rtb_Saturation == 1.0) & (Car_State_DW.temporalCounter_i1 >= 100U))
          != 0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_PrechargeDONE;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 9;
      } else if (Car_State_DW.temporalCounter_i1 >= 400U) {
        /* Outport: '<Root>/errors' */
        Car_State_Y.errors = 6.0;
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 21;
      }
      break;

     case Car_State_IN_Init:
      rtb_CarState = 0;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 20.0;
      if (((Car_State_DW.temporalCounter_i1 >= 40U) & rtb_LogicalOperator1) != 0)
      {
        Car_State_DW.is_c1_Car_State = Car_State_IN_Standby;
        rtb_CarState = 3;

        /* Outport: '<Root>/InvertersAction' */
        Car_State_Y.InvertersAction = 11.0;
      }
      break;

     case Car_State_IN_Standby:
      rtb_CarState = 3;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 11.0;
      if (((Car_State_U.PrechargeRequest == 1.0) &
           (Car_State_U.InvertersSubscribed == 1.0)) != 0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_PrechargeINIT;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 6;

        /* Outport: '<Root>/InvertersAction' */
        Car_State_Y.InvertersAction = 20.0;
      } else if (!rtb_LogicalOperator1) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_Init;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 0;

        /* Outport: '<Root>/InvertersAction' */
        Car_State_Y.InvertersAction = 20.0;
      }
      break;

     default:
      /* case IN_OpenAirs: */
      rtb_CarState = 21;

      /* Outport: '<Root>/InvertersAction' */
      Car_State_Y.InvertersAction = 20.0;
      if (((rtb_Merge_g == 1.0) & (Car_State_DW.temporalCounter_i1 >= 40U)) != 0)
      {
        Car_State_DW.is_c1_Car_State = Car_State_IN_Init;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 0;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
      }
      break;
    }

    if (guard1) {
      Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
      Car_State_DW.temporalCounter_i1 = 0U;
      rtb_CarState = 21;
    }
  }

  /* End of Chart: '<Root>/Car State Manager' */

  /* Outport: '<Root>/Car_State' */
  Car_State_Y.Car_State_f = rtb_CarState;

  /* SwitchCase: '<S4>/Switch Case' */
  switch (rtb_CarState) {
   case 6:
    /* Outputs for IfAction SubSystem: '<S4>/Precharge' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Merge: '<S4>/Merge' incorporates:
     *  Constant: '<S17>/Constant'
     *  SignalConversion generated from: '<S17>/6'
     */
    Car_State_B.Merge = 6.0;

    /* End of Outputs for SubSystem: '<S4>/Precharge' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S4>/Tancar Airs' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Merge: '<S4>/Merge' incorporates:
     *  Constant: '<S18>/Constant'
     *  SignalConversion generated from: '<S18>/3'
     */
    Car_State_B.Merge = 3.0;

    /* End of Outputs for SubSystem: '<S4>/Tancar Airs' */
    break;

   case 21:
    /* Outputs for IfAction SubSystem: '<S4>/Obrir AIRs' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    Car_State_FALSE(&Car_State_B.Merge);

    /* End of Outputs for SubSystem: '<S4>/Obrir AIRs' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* Outport: '<Root>/AIRs_Request' */
  Car_State_Y.AIRs_Request = Car_State_B.Merge;

  /* Outport: '<Root>/CurrentPathDisconnectionFlag' */
  Car_State_Y.CurrentPathDisconnectionFlag = rtb_Merge_p;

  /* Outport: '<Root>/Car_OK' */
  Car_State_Y.Car_OK = rtb_LogicalOperator1;

  /* Outport: '<Root>/PrechargeAssert' */
  Car_State_Y.PrechargeAssert = rtb_Saturation;

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  if (Car_State_U.Accumulator_Voltage > 600.0) {
    rtb_Merge = 600.0;
  } else if (Car_State_U.Accumulator_Voltage < 400.0) {
    rtb_Merge = 400.0;
  } else {
    rtb_Merge = Car_State_U.Accumulator_Voltage;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Outport: '<Root>/Precharge_Percentage' incorporates:
   *  Gain: '<S8>/If DC BUS not bits'
   *  Inport: '<Root>/InvertersMinDCBus'
   *  Product: '<S8>/Divide'
   */
  Car_State_Y.Precharge_Percentage = Car_State_U.InvertersMinDCBus / (0.01 *
    rtb_Merge);

  /* Outport: '<Root>/Precharge_Voltage' incorporates:
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  Car_State_Y.Precharge_Voltage = Car_State_U.InvertersMinDCBus;
}

/* Model update function */
static void Car_State_update(void)
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
  if (!(++Car_State_M->Timing.clockTick0)) {
    ++Car_State_M->Timing.clockTickH0;
  }

  Car_State_M->Timing.t[0] = Car_State_M->Timing.clockTick0 *
    Car_State_M->Timing.stepSize0 + Car_State_M->Timing.clockTickH0 *
    Car_State_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Car_State_initialize(void)
{
  /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
  Car_State_DW.A = 0.0;

  /* SystemInitialize for Chart: '<Root>/Car State Manager' */
  Car_State_DW.temporalCounter_i1 = 0U;
  Car_State_DW.is_active_c1_Car_State = 0U;
  Car_State_DW.is_c1_Car_State = Car_State_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Outport: '<Root>/TorqueEnable' incorporates:
   *  Chart: '<Root>/Car State Manager'
   */
  Car_State_Y.TorqueEnable = 0.0;

  /* SystemInitialize for Outport: '<Root>/errors' incorporates:
   *  Chart: '<Root>/Car State Manager'
   */
  Car_State_Y.errors = 0.0;

  /* SystemInitialize for Merge: '<S4>/Merge' */
  Car_State_B.Merge = 0.0;
}

/* Model terminate function */
static void Car_State_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Car_State_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Car_State_update();
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
  Car_State_initialize();
}

void MdlTerminate(void)
{
  Car_State_terminate();
}

/* Registration function */
RT_MODEL_Car_State_T *Car_State(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Car_State_M, 0,
                sizeof(RT_MODEL_Car_State_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Car_State_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Car_State_M points to
       static memory which is guaranteed to be non-NULL" */
    Car_State_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Car_State_M->Timing.sampleTimes = (&Car_State_M->Timing.sampleTimesArray[0]);
    Car_State_M->Timing.offsetTimes = (&Car_State_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Car_State_M->Timing.sampleTimes[0] = (0.025);

    /* task offsets */
    Car_State_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Car_State_M, &Car_State_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Car_State_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Car_State_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Car_State_M, 10.0);
  Car_State_M->Timing.stepSize0 = 0.025;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Car_State_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Car_State_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Car_State_M->rtwLogInfo, (NULL));
    rtliSetLogT(Car_State_M->rtwLogInfo, "tout");
    rtliSetLogX(Car_State_M->rtwLogInfo, "");
    rtliSetLogXFinal(Car_State_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Car_State_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Car_State_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Car_State_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Car_State_M->rtwLogInfo, 1);
    rtliSetLogY(Car_State_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Car_State_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Car_State_M->rtwLogInfo, (NULL));
  }

  Car_State_M->solverInfoPtr = (&Car_State_M->solverInfo);
  Car_State_M->Timing.stepSize = (0.025);
  rtsiSetFixedStepSize(&Car_State_M->solverInfo, 0.025);
  rtsiSetSolverMode(&Car_State_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Car_State_M->blockIO = ((void *) &Car_State_B);
  (void) memset(((void *) &Car_State_B), 0,
                sizeof(B_Car_State_T));

  /* states (dwork) */
  Car_State_M->dwork = ((void *) &Car_State_DW);
  (void) memset((void *)&Car_State_DW, 0,
                sizeof(DW_Car_State_T));

  /* external inputs */
  Car_State_M->inputs = (((void*)&Car_State_U));
  (void)memset(&Car_State_U, 0, sizeof(ExtU_Car_State_T));

  /* external outputs */
  Car_State_M->outputs = (&Car_State_Y);
  (void)memset(&Car_State_Y, 0, sizeof(ExtY_Car_State_T));

  /* Initialize Sizes */
  Car_State_M->Sizes.numContStates = (0);/* Number of continuous states */
  Car_State_M->Sizes.numY = (10);      /* Number of model outputs */
  Car_State_M->Sizes.numU = (9);       /* Number of model inputs */
  Car_State_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Car_State_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Car_State_M->Sizes.numBlocks = (67); /* Number of blocks */
  Car_State_M->Sizes.numBlockIO = (3); /* Number of block outputs */
  return Car_State_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
