/*
 * Car_State.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Car_State".
 *
 * Model version              : 13.23
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Fri Aug 30 16:50:29 2024
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
#define Car_State_IN_Init              ((uint8_T)2U)
#define Car_State_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define Car_State_IN_OpenAirs          ((uint8_T)3U)
#define Car_State_IN_PrechargeDONE     ((uint8_T)4U)
#define Car_State_IN_PrechargeINIT     ((uint8_T)5U)
#define Car_State_IN_RTD               ((uint8_T)6U)
#define Car_State_IN_Standby           ((uint8_T)7U)
#define Car_State_IN_TSActive          ((uint8_T)8U)

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
 *    '<S4>/TRUE'
 *    '<S12>/TRUE'
 */
void Car_State_TRUE(real_T *rty_u)
{
  /* SignalConversion generated from: '<S14>/1' incorporates:
   *  Constant: '<S14>/Constant'
   */
  *rty_u = 1.0;
}

/*
 * Output and update for action system:
 *    '<S1>/FALSE'
 *    '<S2>/FALSE'
 *    '<S3>/FALSE'
 *    '<S4>/FALSE'
 *    '<S5>/Obrir AIRs'
 *    '<S12>/FALSE'
 */
void Car_State_FALSE(real_T *rty_u)
{
  /* SignalConversion generated from: '<S13>/0' incorporates:
   *  Constant: '<S13>/Constant'
   */
  *rty_u = 0.0;
}

/*
 * Output and update for action system:
 *    '<S10>/TqEnable'
 *    '<S10>/TqEnable1'
 */
void Car_State_TqEnable(real_T *rty_u0)
{
  /* SignalConversion generated from: '<S39>/30' incorporates:
   *  Constant: '<S39>/Constant'
   */
  *rty_u0 = 30.0;
}

/* Model output function */
static void Car_State_output(void)
{
  real_T rtb_Memory;
  real_T rtb_Merge;
  real_T rtb_Merge_c;
  real_T rtb_Merge_n;
  int32_T rtb_CarState;
  boolean_T guard1;
  boolean_T rtb_Compare_k;
  boolean_T rtb_LogicalOperator1;
  boolean_T tmp;

  /* If: '<S2>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 0.0) {
    /* Outputs for IfAction SubSystem: '<S2>/TRUE' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S2>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/FALSE' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S2>/FALSE' */
  }

  /* End of If: '<S2>/If' */

  /* If: '<S9>/If' incorporates:
   *  If: '<S31>/If'
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  if ((Car_State_U.InvertersMinDCBus > 60.0) && (rtb_Merge == 1.0)) {
    /* Outputs for IfAction SubSystem: '<S31>/Error counter' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Sum: '<S32>/Sum' incorporates:
     *  Constant: '<S32>/Constant'
     *  DataStoreRead: '<S32>/Data Store Read'
     */
    rtb_Memory = Car_State_DW.A + 1.0;

    /* End of Outputs for SubSystem: '<S31>/Error counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S31>/OK' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* SignalConversion generated from: '<S33>/0 ' incorporates:
     *  Constant: '<S33>/Constant'
     */
    rtb_Memory = 0.0;

    /* End of Outputs for SubSystem: '<S31>/OK' */
  }

  /* End of If: '<S9>/If' */

  /* DataStoreWrite: '<S31>/Data Store Write' */
  Car_State_DW.A = rtb_Memory;

  /* Outputs for IfAction SubSystem: '<S31>/Signal_OK' incorporates:
   *  ActionPort: '<S35>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S31>/Signal_Failure' incorporates:
   *  ActionPort: '<S34>/Action Port'
   */
  /* If: '<S31>/If1' incorporates:
   *  Constant: '<S9>/Number_of_Periods'
   *  Outport: '<Root>/Relay_Error'
   *  SignalConversion generated from: '<S34>/Out1'
   *  SignalConversion generated from: '<S35>/Out1'
   */
  Car_State_Y.Relay_Error = (rtb_Memory > 400.0);

  /* End of Outputs for SubSystem: '<S31>/Signal_Failure' */
  /* End of Outputs for SubSystem: '<S31>/Signal_OK' */

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant'
   *  Inport: '<Root>/Accumulator_Voltage'
   *  Inport: '<Root>/Critical_CAN_Disconnection'
   *  Inport: '<Root>/PrechargeRequest'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  RelationalOperator: '<S25>/Compare'
   *  RelationalOperator: '<S26>/Compare'
   *  RelationalOperator: '<S27>/Compare'
   */
  rtb_LogicalOperator1 = (Car_State_U.Shutdown_PackageIntck &&
    (Car_State_U.Accumulator_Voltage > 69.0) && (Car_State_U.PrechargeRequest ==
    0.0) && (Car_State_U.Critical_CAN_Disconnection == 0.0));

  /* If: '<S3>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 6.0) {
    /* Outputs for IfAction SubSystem: '<S3>/TRUE' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    Car_State_TRUE(&rtb_Memory);

    /* End of Outputs for SubSystem: '<S3>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/FALSE' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    Car_State_FALSE(&rtb_Memory);

    /* End of Outputs for SubSystem: '<S3>/FALSE' */
  }

  /* End of If: '<S3>/If' */

  /* If: '<S12>/If' incorporates:
   *  Gain: '<S12>/Gain'
   *  Inport: '<Root>/Accumulator_Voltage'
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  if ((rtb_Memory == 1.0) && (Car_State_U.InvertersMinDCBus > 0.9 *
       Car_State_U.Accumulator_Voltage)) {
    /* Outputs for IfAction SubSystem: '<S12>/TRUE' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    Car_State_TRUE(&rtb_Memory);

    /* End of Outputs for SubSystem: '<S12>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/FALSE' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    Car_State_FALSE(&rtb_Memory);

    /* End of Outputs for SubSystem: '<S12>/FALSE' */
  }

  /* End of If: '<S12>/If' */

  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 3.0) {
    /* Outputs for IfAction SubSystem: '<S1>/TRUE' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge_c);

    /* End of Outputs for SubSystem: '<S1>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/FALSE' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge_c);

    /* End of Outputs for SubSystem: '<S1>/FALSE' */
  }

  /* End of If: '<S1>/If' */

  /* If: '<S4>/If' incorporates:
   *  Constant: '<S19>/Constant'
   *  Inport: '<Root>/BrakePedal_Value'
   *  Inport: '<Root>/EnableDrive_Order'
   *  RelationalOperator: '<S19>/Compare'
   */
  if (Car_State_U.EnableDrive_Order && (Car_State_U.BrakePedal_Value > 0.5)) {
    /* Outputs for IfAction SubSystem: '<S4>/TRUE' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge_n);

    /* End of Outputs for SubSystem: '<S4>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/FALSE' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge_n);

    /* End of Outputs for SubSystem: '<S4>/FALSE' */
  }

  /* End of If: '<S4>/If' */

  /* Chart: '<Root>/Car State Manager' incorporates:
   *  Inport: '<Root>/InvertersSubscribed'
   *  Inport: '<Root>/PrechargeRequest'
   */
  if (Car_State_DW.temporalCounter_i1 < 511U) {
    Car_State_DW.temporalCounter_i1++;
  }

  if (Car_State_DW.is_active_c1_Car_State == 0U) {
    Car_State_DW.is_active_c1_Car_State = 1U;

    /* Outport: '<Root>/errors' */
    Car_State_Y.errors = 0.0;
    Car_State_DW.temporalCounter_i1 = 0U;
    Car_State_DW.is_c1_Car_State = Car_State_IN_Init;
    rtb_CarState = 0;

    /* Outport: '<Root>/TorqueEnable' */
    Car_State_Y.TorqueEnable = 0.0;
    Car_State_B.InvertersAction = 20.0;
  } else {
    guard1 = false;
    switch (Car_State_DW.is_c1_Car_State) {
     case Car_State_IN_EnableInverters:
      rtb_CarState = 14;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      Car_State_B.InvertersAction = 20.0;
      if (Car_State_DW.temporalCounter_i1 >= 80U) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_RTD;
        rtb_CarState = 15;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 1.0;
      } else if (!rtb_LogicalOperator1) {
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        rtb_CarState = 21;
      }
      break;

     case Car_State_IN_Init:
      rtb_CarState = 0;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      Car_State_B.InvertersAction = 20.0;
      if (((Car_State_DW.temporalCounter_i1 >= 40U) & rtb_LogicalOperator1) != 0)
      {
        Car_State_DW.is_c1_Car_State = Car_State_IN_Standby;
        rtb_CarState = 3;
        Car_State_B.InvertersAction = 11.0;
      }
      break;

     case Car_State_IN_OpenAirs:
      rtb_CarState = 21;
      Car_State_B.InvertersAction = 20.0;
      if (((rtb_Merge == 1.0) & (Car_State_DW.temporalCounter_i1 >= 40U)) != 0)
      {
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_Init;
        rtb_CarState = 0;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
      }
      break;

     case Car_State_IN_PrechargeDONE:
      rtb_CarState = 9;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      Car_State_B.InvertersAction = 20.0;
      if (Car_State_DW.temporalCounter_i1 >= 80U) {
        /* Outport: '<Root>/errors' */
        Car_State_Y.errors = 9.0;
        guard1 = true;
      } else if (((rtb_Merge_c == 1.0) & (Car_State_DW.temporalCounter_i1 >= 4U))
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
      Car_State_B.InvertersAction = 20.0;
      if (((rtb_Memory == 1.0) & (Car_State_DW.temporalCounter_i1 >= 100U)) != 0)
      {
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_PrechargeDONE;
        rtb_CarState = 9;
      } else if (Car_State_DW.temporalCounter_i1 >= 400U) {
        /* Outport: '<Root>/errors' */
        Car_State_Y.errors = 6.0;
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        rtb_CarState = 21;
      }
      break;

     case Car_State_IN_RTD:
      rtb_CarState = 15;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 1.0;
      if (!rtb_LogicalOperator1) {
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        rtb_CarState = 21;
        Car_State_B.InvertersAction = 20.0;
      }
      break;

     case Car_State_IN_Standby:
      rtb_CarState = 3;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      Car_State_B.InvertersAction = 11.0;
      if (((Car_State_U.PrechargeRequest == 1.0) &
           (Car_State_U.InvertersSubscribed == 1.0)) != 0) {
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_PrechargeINIT;
        rtb_CarState = 6;
        Car_State_B.InvertersAction = 20.0;
      } else if (!rtb_LogicalOperator1) {
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_Init;
        rtb_CarState = 0;
        Car_State_B.InvertersAction = 20.0;
      }
      break;

     default:
      /* case IN_TSActive: */
      rtb_CarState = 12;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      Car_State_B.InvertersAction = 20.0;
      if (rtb_Merge_n == 1.0) {
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_EnableInverters;
        rtb_CarState = 14;
      } else if (!rtb_LogicalOperator1) {
        Car_State_DW.temporalCounter_i1 = 0U;
        Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
        rtb_CarState = 21;
      }
      break;
    }

    if (guard1) {
      Car_State_DW.temporalCounter_i1 = 0U;
      Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
      rtb_CarState = 21;
    }
  }

  /* End of Chart: '<Root>/Car State Manager' */

  /* SwitchCase: '<S5>/Switch Case' */
  switch (rtb_CarState) {
   case 6:
    /* Outputs for IfAction SubSystem: '<S5>/Precharge' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Merge: '<S5>/Merge' incorporates:
     *  Constant: '<S23>/Constant'
     *  SignalConversion generated from: '<S23>/6'
     */
    Car_State_B.Merge = 6.0;

    /* End of Outputs for SubSystem: '<S5>/Precharge' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S5>/Tancar Airs' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* Merge: '<S5>/Merge' incorporates:
     *  Constant: '<S24>/Constant'
     *  SignalConversion generated from: '<S24>/3'
     */
    Car_State_B.Merge = 3.0;

    /* End of Outputs for SubSystem: '<S5>/Tancar Airs' */
    break;

   case 21:
    /* Outputs for IfAction SubSystem: '<S5>/Obrir AIRs' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    Car_State_FALSE(&Car_State_B.Merge);

    /* End of Outputs for SubSystem: '<S5>/Obrir AIRs' */
    break;
  }

  /* End of SwitchCase: '<S5>/Switch Case' */

  /* Outport: '<Root>/AIRs_Request' */
  Car_State_Y.AIRs_Request = Car_State_B.Merge;

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/APPS1_Value'
   */
  rtb_Compare_k = (Car_State_U.APPS1_Value > 0.05);

  /* If: '<S10>/If' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion1'
   *  Memory: '<S10>/Memory'
   */
  tmp = ((rtb_CarState == 15) && rtb_Compare_k);
  if (tmp && (Car_State_DW.Memory_PreviousInput == 20.0)) {
    /* Outputs for IfAction SubSystem: '<S10>/EnableDrive_Up' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  Constant: '<S37>/Constant'
     *  SignalConversion generated from: '<S37>/21'
     */
    Car_State_B.Merge_b = 21.0;

    /* End of Outputs for SubSystem: '<S10>/EnableDrive_Up' */
  } else if (tmp && (Car_State_DW.Memory_PreviousInput == 21.0)) {
    /* Outputs for IfAction SubSystem: '<S10>/TqEnable' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    Car_State_TqEnable(&Car_State_B.Merge_b);

    /* End of Outputs for SubSystem: '<S10>/TqEnable' */
  } else if (tmp && (Car_State_DW.Memory_PreviousInput == 30.0)) {
    /* Outputs for IfAction SubSystem: '<S10>/TqEnable1' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    Car_State_TqEnable(&Car_State_B.Merge_b);

    /* End of Outputs for SubSystem: '<S10>/TqEnable1' */
  } else if ((rtb_CarState == 15) && (!rtb_Compare_k)) {
    /* Outputs for IfAction SubSystem: '<S10>/DisableDrive' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  Constant: '<S36>/Constant'
     *  SignalConversion generated from: '<S36>/20'
     */
    Car_State_B.Merge_b = 20.0;

    /* End of Outputs for SubSystem: '<S10>/DisableDrive' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/NoRTD' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    /* Merge: '<S10>/Merge' incorporates:
     *  SignalConversion generated from: '<S38>/InvAction'
     */
    Car_State_B.Merge_b = Car_State_B.InvertersAction;

    /* End of Outputs for SubSystem: '<S10>/NoRTD' */
  }

  /* End of If: '<S10>/If' */

  /* Outport: '<Root>/InvertersAction' */
  Car_State_Y.InvertersAction = Car_State_B.Merge_b;

  /* Outport: '<Root>/Car_OK' */
  Car_State_Y.Car_OK = rtb_LogicalOperator1;

  /* Outport: '<Root>/PrechargeAssert' */
  Car_State_Y.PrechargeAssert = rtb_Memory;

  /* Outport: '<Root>/Precharge_Percentage' incorporates:
   *  Gain: '<S11>/0to100'
   *  Inport: '<Root>/Accumulator_Voltage'
   *  Inport: '<Root>/InvertersMinDCBus'
   *  Product: '<S11>/Divide'
   */
  Car_State_Y.Precharge_Percentage = Car_State_U.InvertersMinDCBus /
    Car_State_U.Accumulator_Voltage * 100.0;

  /* Outport: '<Root>/Precharge_Voltage' incorporates:
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  Car_State_Y.Precharge_Voltage = Car_State_U.InvertersMinDCBus;

  /* Outport: '<Root>/Car_State' */
  Car_State_Y.Car_State_b = rtb_CarState;
}

/* Model update function */
static void Car_State_update(void)
{
  /* Update for Memory: '<S10>/Memory' */
  Car_State_DW.Memory_PreviousInput = Car_State_B.Merge_b;

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
  /* Start for DataStoreMemory: '<S31>/Data Store Memory' */
  Car_State_DW.A = 0.0;

  /* InitializeConditions for Memory: '<S10>/Memory' */
  Car_State_DW.Memory_PreviousInput = 20.0;

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

  /* SystemInitialize for Chart: '<Root>/Car State Manager' */
  Car_State_B.InvertersAction = 0.0;

  /* SystemInitialize for Merge: '<S5>/Merge' */
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
  Car_State_M->Sizes.numU = (10);      /* Number of model inputs */
  Car_State_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Car_State_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Car_State_M->Sizes.numBlocks = (103);/* Number of blocks */
  Car_State_M->Sizes.numBlockIO = (5); /* Number of block outputs */
  return Car_State_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
