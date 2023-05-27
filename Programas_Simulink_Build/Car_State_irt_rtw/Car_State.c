/*
 * Car_State.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Car_State".
 *
 * Model version              : 1.57
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 12:56:28 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Car_State.h"
#include "Car_State_private.h"

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

/* Block signals (auto storage) */
B_Car_State_T Car_State_B;

/* Block states (auto storage) */
DW_Car_State_T Car_State_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Car_State_T Car_State_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Car_State_T Car_State_Y;

/* Real-time model */
RT_MODEL_Car_State_T Car_State_M_;
RT_MODEL_Car_State_T *const Car_State_M = &Car_State_M_;

/*
 * Output and update for action system:
 *    '<S1>/TRUE'
 *    '<S2>/TRUE'
 *    '<S3>/TRUE'
 *    '<S10>/TRUE'
 *    '<S11>/OK'
 */
void Car_State_TRUE(real_T *rty_u, P_TRUE_Car_State_T *localP)
{
  /* SignalConversion: '<S13>/OutportBufferFor1' incorporates:
   *  Constant: '<S13>/Constant'
   */
  *rty_u = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S1>/FALSE'
 *    '<S2>/FALSE'
 *    '<S3>/FALSE'
 *    '<S4>/Obrir AIRs'
 *    '<S10>/FALSE'
 *    '<S11>/ERROR'
 */
void Car_State_FALSE(real_T *rty_u, P_FALSE_Car_State_T *localP)
{
  /* SignalConversion: '<S12>/OutportBufferFor0' incorporates:
   *  Constant: '<S12>/Constant'
   */
  *rty_u = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S7>/Failure'
 *    '<S26>/Latched Error'
 */
void Car_State_Failure(real_T *rty_u, P_Failure_Car_State_T *localP)
{
  /* SignalConversion: '<S25>/OutportBufferFor1 ' incorporates:
   *  Constant: '<S25>/Constant'
   */
  *rty_u = localP->Constant_Value;
}

/* Model output function */
static void Car_State_output(void)
{
  real_T rtb_Merge;
  real_T rtb_Merge_p;
  real_T rtb_Merge_a;
  boolean_T rtb_LogicalOperator1;
  real_T rtb_Merge_b;
  int32_T rtb_CarState;
  int32_T rtb_InvertersAction;
  real_T rtb_Merge_c;
  boolean_T guard1 = false;

  /* If: '<S2>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 3.0) {
    /* Outputs for IfAction SubSystem: '<S2>/TRUE' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge, &Car_State_P.TRUE);

    /* End of Outputs for SubSystem: '<S2>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/FALSE' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge, &Car_State_P.FALSE);

    /* End of Outputs for SubSystem: '<S2>/FALSE' */
  }

  /* End of If: '<S2>/If' */

  /* If: '<S7>/If' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read'
   *  If: '<S26>/If'
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  if ((Car_State_U.InvertersMinDCBus < 60.0) && (rtb_Merge == 1.0)) {
    /* Outputs for IfAction SubSystem: '<S7>/Failure' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    Car_State_Failure(&rtb_Merge_p, &Car_State_P.Failure);

    /* End of Outputs for SubSystem: '<S7>/Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S7>/OK or latch' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    if (Car_State_DW.A > 0.0) {
      /* Outputs for IfAction SubSystem: '<S26>/Latched Error' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */

      /* If: '<S26>/If' */
      Car_State_Failure(&rtb_Merge_p, &Car_State_P.LatchedError);

      /* End of Outputs for SubSystem: '<S26>/Latched Error' */
    } else {
      /* Outputs for IfAction SubSystem: '<S26>/OK' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* If: '<S26>/If' incorporates:
       *  Constant: '<S28>/Constant'
       *  SignalConversion: '<S28>/OutportBufferFor0 '
       */
      rtb_Merge_p = Car_State_P.Constant_Value_f;

      /* End of Outputs for SubSystem: '<S26>/OK' */
    }

    /* End of Outputs for SubSystem: '<S7>/OK or latch' */
  }

  /* End of If: '<S7>/If' */

  /* DataStoreWrite: '<S7>/Data Store Write' */
  Car_State_DW.A = rtb_Merge_p;

  /* If: '<S11>/If' incorporates:
   *  Inport: '<Root>/Shutdown_BMS'
   *  Inport: '<Root>/Shutdown_BOTS'
   *  Inport: '<Root>/Shutdown_BSPD'
   *  Inport: '<Root>/Shutdown_HVBOX'
   *  Inport: '<Root>/Shutdown_HVD'
   *  Inport: '<Root>/Shutdown_Inertia'
   *  Inport: '<Root>/Shutdown_InverterLIntck'
   *  Inport: '<Root>/Shutdown_InverterRIntck'
   *  Inport: '<Root>/Shutdown_PackageIntck'
   *  Inport: '<Root>/Shutdown_SetaCockpit'
   *  Inport: '<Root>/Shutdown_SetaLeft'
   *  Inport: '<Root>/Shutdown_SetaRight'
   *  Inport: '<Root>/Shutdown_TSMPIntck'
   *  Inport: '<Root>/Shutdown_TSMS'
   *  Sum: '<S11>/Sum'
   */
  if (((((((((((((Car_State_U.Shutdown_BMS + Car_State_U.Shutdown_BOTS) +
                 Car_State_U.Shutdown_BSPD) + Car_State_U.Shutdown_HVBOX) +
               Car_State_U.Shutdown_HVD) + Car_State_U.Shutdown_Inertia) +
             Car_State_U.Shutdown_InverterLIntck) +
            Car_State_U.Shutdown_InverterRIntck) +
           Car_State_U.Shutdown_PackageIntck) + Car_State_U.Shutdown_SetaCockpit)
         + Car_State_U.Shutdown_SetaLeft) + Car_State_U.Shutdown_SetaRight) +
       Car_State_U.Shutdown_TSMPIntck) + Car_State_U.Shutdown_TSMS > 0.0) {
    /* Outputs for IfAction SubSystem: '<S11>/ERROR' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge_a, &Car_State_P.ERROR);

    /* End of Outputs for SubSystem: '<S11>/ERROR' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/OK' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge_a, &Car_State_P.OK);

    /* End of Outputs for SubSystem: '<S11>/OK' */
  }

  /* End of If: '<S11>/If' */

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/Accumulator_Voltage'
   *  Inport: '<Root>/Critical_CAN_Disconnection'
   *  Inport: '<Root>/PrechargeRequest'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   */
  rtb_LogicalOperator1 = ((rtb_Merge_a != 0.0) &&
    (Car_State_U.Accumulator_Voltage > Car_State_P.CompareToConstant_const) &&
    (Car_State_U.DashPrechargeRequest == Car_State_P.Constant_Value_kb) &&
    (Car_State_U.Critical_CAN_Disconnection == Car_State_P.Constant_Value_fl));

  /* If: '<S3>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 6.0) {
    /* Outputs for IfAction SubSystem: '<S3>/TRUE' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge_b, &Car_State_P.TRUE_p);

    /* End of Outputs for SubSystem: '<S3>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/FALSE' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge_b, &Car_State_P.FALSE_n);

    /* End of Outputs for SubSystem: '<S3>/FALSE' */
  }

  /* End of If: '<S3>/If' */

  /* If: '<S10>/If' incorporates:
   *  Gain: '<S10>/Gain'
   *  Inport: '<Root>/Accumulator_Voltage'
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  if ((rtb_Merge_b == 1.0) && (Car_State_U.InvertersMinDCBus >
       Car_State_P.Gain_Gain * Car_State_U.Accumulator_Voltage)) {
    /* Outputs for IfAction SubSystem: '<S10>/TRUE' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge_b, &Car_State_P.TRUE_f);

    /* End of Outputs for SubSystem: '<S10>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/FALSE' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge_b, &Car_State_P.FALSE_m);

    /* End of Outputs for SubSystem: '<S10>/FALSE' */
  }

  /* End of If: '<S10>/If' */

  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/AIRs_State'
   */
  if (Car_State_U.AIRs_State == 0.0) {
    /* Outputs for IfAction SubSystem: '<S1>/TRUE' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    Car_State_TRUE(&rtb_Merge_c, &Car_State_P.TRUE_i);

    /* End of Outputs for SubSystem: '<S1>/TRUE' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/FALSE' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    Car_State_FALSE(&rtb_Merge_c, &Car_State_P.FALSE_h);

    /* End of Outputs for SubSystem: '<S1>/FALSE' */
  }

  /* End of If: '<S1>/If' */

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
    rtb_InvertersAction = 20;
  } else {
    guard1 = false;
    switch (Car_State_DW.is_c1_Car_State) {
     case Car_State_IN_EnableInverters:
      rtb_CarState = 14;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      rtb_InvertersAction = 21;
      if (Car_State_DW.temporalCounter_i1 >= 80U) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_RTD;
        rtb_CarState = 15;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 1.0;
        rtb_InvertersAction = 30;
      } else {
        if (!rtb_LogicalOperator1) {
          Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
          Car_State_DW.temporalCounter_i1 = 0U;
          rtb_CarState = 21;
          rtb_InvertersAction = 20;
        }
      }
      break;

     case Car_State_IN_Locked:
      rtb_CarState = 18;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      rtb_InvertersAction = 20;
      if (Car_State_U.Lock == 0.0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_EnableInverters;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 14;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
        rtb_InvertersAction = 21;
      } else {
        if (!rtb_LogicalOperator1) {
          Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
          Car_State_DW.temporalCounter_i1 = 0U;
          rtb_CarState = 21;
        }
      }
      break;

     case Car_State_IN_RTD:
      rtb_CarState = 15;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 1.0;
      rtb_InvertersAction = 30;
      if (Car_State_U.Lock == 1.0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_Locked;
        rtb_CarState = 18;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
        rtb_InvertersAction = 20;
      } else {
        if (!rtb_LogicalOperator1) {
          Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
          Car_State_DW.temporalCounter_i1 = 0U;
          rtb_CarState = 21;
          rtb_InvertersAction = 20;
        }
      }
      break;

     case Car_State_IN_TSActive:
      rtb_CarState = 12;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      rtb_InvertersAction = 20;
      if (Car_State_U.EnableDrive == 1.0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_EnableInverters;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 14;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
        rtb_InvertersAction = 21;
      } else {
        if (!rtb_LogicalOperator1) {
          Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
          Car_State_DW.temporalCounter_i1 = 0U;
          rtb_CarState = 21;
        }
      }
      break;

     case Car_State_IN_PrechargeDONE:
      rtb_CarState = 9;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      rtb_InvertersAction = 20;
      if (Car_State_DW.temporalCounter_i1 >= 80U) {
        /* Outport: '<Root>/errors' */
        Car_State_Y.errors = 9.0;
        guard1 = true;
      } else if (((rtb_Merge == 1.0) & (Car_State_DW.temporalCounter_i1 >= 4U))
                 != 0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_TSActive;
        rtb_CarState = 12;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
      } else {
        if (!rtb_LogicalOperator1) {
          guard1 = true;
        }
      }
      break;

     case Car_State_IN_PrechargeINIT:
      rtb_CarState = 6;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      rtb_InvertersAction = 20;
      if (((rtb_Merge_b == 1.0) & (Car_State_DW.temporalCounter_i1 >= 100U)) !=
          0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_PrechargeDONE;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 9;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
      } else {
        if (Car_State_DW.temporalCounter_i1 >= 400U) {
          /* Outport: '<Root>/errors' */
          Car_State_Y.errors = 6.0;
          Car_State_DW.is_c1_Car_State = Car_State_IN_OpenAirs;
          Car_State_DW.temporalCounter_i1 = 0U;
          rtb_CarState = 21;
        }
      }
      break;

     case Car_State_IN_Init:
      rtb_CarState = 0;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      rtb_InvertersAction = 20;
      if (((Car_State_DW.temporalCounter_i1 >= 40U) & rtb_LogicalOperator1) != 0)
      {
        Car_State_DW.is_c1_Car_State = Car_State_IN_Standby;
        rtb_CarState = 3;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
        rtb_InvertersAction = 11;
      }
      break;

     case Car_State_IN_Standby:
      rtb_CarState = 3;

      /* Outport: '<Root>/TorqueEnable' */
      Car_State_Y.TorqueEnable = 0.0;
      rtb_InvertersAction = 11;
      if (((Car_State_U.DashPrechargeRequest == 1.0) &
           (Car_State_U.InvertersSubscribed == 1.0)) != 0) {
        Car_State_DW.is_c1_Car_State = Car_State_IN_PrechargeINIT;
        Car_State_DW.temporalCounter_i1 = 0U;
        rtb_CarState = 6;

        /* Outport: '<Root>/TorqueEnable' */
        Car_State_Y.TorqueEnable = 0.0;
        rtb_InvertersAction = 20;
      } else {
        if (!rtb_LogicalOperator1) {
          Car_State_DW.is_c1_Car_State = Car_State_IN_Init;
          Car_State_DW.temporalCounter_i1 = 0U;
          rtb_CarState = 0;

          /* Outport: '<Root>/TorqueEnable' */
          Car_State_Y.TorqueEnable = 0.0;
          rtb_InvertersAction = 20;
        }
      }
      break;

     default:
      rtb_CarState = 21;
      rtb_InvertersAction = 20;
      if (((rtb_Merge_c == 1.0) & (Car_State_DW.temporalCounter_i1 >= 40U)) != 0)
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
  switch ((int32_T)fmod(rtb_CarState, 4.294967296E+9)) {
   case 6:
    /* Outputs for IfAction SubSystem: '<S4>/Precharge' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* SignalConversion: '<S19>/OutportBufferFor6' incorporates:
     *  Constant: '<S19>/Constant'
     */
    Car_State_B.Merge = Car_State_P.Constant_Value;

    /* End of Outputs for SubSystem: '<S4>/Precharge' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S4>/Tancar Airs' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* SignalConversion: '<S20>/OutportBufferFor3' incorporates:
     *  Constant: '<S20>/Constant'
     */
    Car_State_B.Merge = Car_State_P.Constant_Value_k;

    /* End of Outputs for SubSystem: '<S4>/Tancar Airs' */
    break;

   case 21:
    /* Outputs for IfAction SubSystem: '<S4>/Obrir AIRs' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    Car_State_FALSE(&Car_State_B.Merge, &Car_State_P.ObrirAIRs);

    /* End of Outputs for SubSystem: '<S4>/Obrir AIRs' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* Outport: '<Root>/AIRs_Request' */
  Car_State_Y.AIRs_Request = Car_State_B.Merge;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Accumulator_Voltage'
   */
  if (Car_State_U.Accumulator_Voltage > Car_State_P.Saturation_UpperSat) {
    rtb_Merge = Car_State_P.Saturation_UpperSat;
  } else if (Car_State_U.Accumulator_Voltage < Car_State_P.Saturation_LowerSat)
  {
    rtb_Merge = Car_State_P.Saturation_LowerSat;
  } else {
    rtb_Merge = Car_State_U.Accumulator_Voltage;
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* Outport: '<Root>/Precharge_Percentage' incorporates:
   *  Gain: '<S9>/If DC BUS not bits'
   *  Inport: '<Root>/InvertersMinDCBus'
   *  Product: '<S9>/Divide'
   */
  Car_State_Y.Precharge_Percentage = Car_State_U.InvertersMinDCBus /
    (Car_State_P.IfDCBUSnotbits_Gain * rtb_Merge);

  /* Outport: '<Root>/Precharge_Voltage' incorporates:
   *  Inport: '<Root>/InvertersMinDCBus'
   */
  Car_State_Y.Precharge_Voltage = Car_State_U.InvertersMinDCBus;

  /* Outport: '<Root>/CurrentPathDisconnectionFlag' */
  Car_State_Y.CurrentPathDisconnectionFlag = rtb_Merge_p;

  /* Outport: '<Root>/InvertersAction' */
  Car_State_Y.InvertersAction = rtb_InvertersAction;

  /* Outport: '<Root>/Car_OK' */
  Car_State_Y.Car_OK = rtb_LogicalOperator1;

  /* Outport: '<Root>/PrechargeAssert' */
  Car_State_Y.PrechargeAssert = rtb_Merge_b;

  /* Outport: '<Root>/ShutdownClosed' */
  Car_State_Y.ShutdownClosed = rtb_Merge_a;
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
  Car_State_DW.A = Car_State_P.DataStoreMemory_InitialValue;

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
  Car_State_B.Merge = Car_State_P.Merge_InitialOutput;
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
  Car_State_M->solverInfoPtr = (&Car_State_M->solverInfo);
  Car_State_M->Timing.stepSize = (0.025);
  rtsiSetFixedStepSize(&Car_State_M->solverInfo, 0.025);
  rtsiSetSolverMode(&Car_State_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Car_State_M->blockIO = ((void *) &Car_State_B);
  (void) memset(((void *) &Car_State_B), 0,
                sizeof(B_Car_State_T));

  /* parameters */
  Car_State_M->defaultParam = ((real_T *)&Car_State_P);

  /* states (dwork) */
  Car_State_M->dwork = ((void *) &Car_State_DW);
  (void) memset((void *)&Car_State_DW, 0,
                sizeof(DW_Car_State_T));

  /* external inputs */
  Car_State_M->inputs = (((void*)&Car_State_U));
  (void)memset((void *)&Car_State_U, 0, sizeof(ExtU_Car_State_T));

  /* external outputs */
  Car_State_M->outputs = (&Car_State_Y);
  (void) memset((void *)&Car_State_Y, 0,
                sizeof(ExtY_Car_State_T));

  /* Initialize Sizes */
  Car_State_M->Sizes.numContStates = (0);/* Number of continuous states */
  Car_State_M->Sizes.numY = (11);      /* Number of model outputs */
  Car_State_M->Sizes.numU = (29);      /* Number of model inputs */
  Car_State_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Car_State_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Car_State_M->Sizes.numBlocks = (73); /* Number of blocks */
  Car_State_M->Sizes.numBlockIO = (3); /* Number of block outputs */
  Car_State_M->Sizes.numBlockPrms = (25);/* Sum of parameter "widths" */
  return Car_State_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
