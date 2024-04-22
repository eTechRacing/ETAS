/*
 * Disconnections.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Disconnections".
 *
 * Model version              : 13.0
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Apr 22 17:08:56 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Disconnections.h"
#include "rtwtypes.h"
#include "Disconnections_private.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Disconnections_T Disconnections_B;

/* Block states (default storage) */
DW_Disconnections_T Disconnections_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Disconnections_T Disconnections_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Disconnections_T Disconnections_Y;

/* Real-time model */
static RT_MODEL_Disconnections_T Disconnections_M_;
RT_MODEL_Disconnections_T *const Disconnections_M = &Disconnections_M_;

/*
 * Output and update for action system:
 *    '<S1>/Reset_counter'
 *    '<S9>/CAN_failure'
 *    '<S10>/CAN_failure'
 *    '<S11>/CAN_failure'
 *    '<S12>/CAN_failure'
 *    '<S13>/CAN_failure'
 *    '<S25>/Signal_Failure'
 *    '<S26>/Signal_Failure'
 *    '<S27>/Signal_Failure'
 */
void Disconnections_Reset_counter(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S7>/Out1' incorporates:
   *  Constant: '<S7>/Constant'
   */
  *rty_Out1 = 1.0;
}

/*
 * Output and update for action system:
 *    '<S9>/CAN_OK'
 *    '<S10>/CAN_OK'
 *    '<S11>/CAN_OK'
 *    '<S12>/CAN_OK'
 *    '<S13>/CAN_OK'
 *    '<S25>/CAN_OK'
 *    '<S26>/CAN_OK'
 *    '<S27>/CAN_OK'
 */
void Disconnections_CAN_OK(real_T rtu_Alive_signal, real_T *rty_Out1, real_T
  *rtd_Last_alive_n)
{
  /* DataStoreWrite: '<S14>/Data Store Write' */
  *rtd_Last_alive_n = rtu_Alive_signal;

  /* SignalConversion generated from: '<S14>/Out1' incorporates:
   *  Constant: '<S14>/Constant'
   */
  *rty_Out1 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S25>/Error_Counter'
 *    '<S26>/Error_Counter'
 *    '<S27>/Error_Counter'
 */
void Disconnections_Error_Counter(real_T *rty_Out1, const real_T *rtd_Tot_Errors)
{
  /* Sum: '<S29>/Add' incorporates:
   *  Constant: '<S29>/Constant'
   */
  *rty_Out1 = *rtd_Tot_Errors + 1.0;
}

/*
 * Output and update for action system:
 *    '<S25>/Signal_OK'
 *    '<S26>/Signal_OK'
 *    '<S27>/Signal_OK'
 */
void Disconnections_Signal_OK(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S31>/Out1' incorporates:
   *  Constant: '<S31>/Constant'
   */
  *rty_Out1 = 0.0;
}

/* Model output function */
static void Disconnections_output(void)
{
  real_T rtb_Add;
  real_T rtb_Merge1_l;
  real_T rtb_Merge1_o;
  real_T rtb_Merge1_p;
  uint8_T rtb_Compare_k;
  boolean_T rtb_OR3;
  boolean_T rtb_OR4;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read'
   */
  rtb_Add = Disconnections_DW.A + 1.0;

  /* If: '<S1>/If' incorporates:
   *  Constant: '<Root>/Periods'
   */
  if (rtb_Add > 4.0) {
    /* Outputs for IfAction SubSystem: '<S1>/Reset_counter' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Add);

    /* End of Outputs for SubSystem: '<S1>/Reset_counter' */
  }

  /* End of If: '<S1>/If' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  Disconnections_DW.A = rtb_Add;

  /* If: '<S25>/If' incorporates:
   *  DataStoreRead: '<S25>/Data Store Read'
   *  Inport: '<Root>/APPS2_Bits'
   */
  if (Disconnections_U.APPS2_Bits == Disconnections_DW.Last_alive) {
    /* Outputs for IfAction SubSystem: '<S25>/Error_Counter' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    Disconnections_Error_Counter(&rtb_Merge1_l, &Disconnections_DW.Tot_Errors);

    /* End of Outputs for SubSystem: '<S25>/Error_Counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/CAN_OK' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    Disconnections_CAN_OK(Disconnections_U.APPS2_Bits, &rtb_Merge1_l,
                          &Disconnections_DW.Last_alive);

    /* End of Outputs for SubSystem: '<S25>/CAN_OK' */
  }

  /* End of If: '<S25>/If' */

  /* DataStoreWrite: '<S25>/Data Store Write' */
  Disconnections_DW.Tot_Errors = rtb_Merge1_l;

  /* If: '<S25>/If2' incorporates:
   *  Constant: '<S3>/Number_of_periods'
   */
  if (rtb_Merge1_l > 4800.0) {
    /* Outputs for IfAction SubSystem: '<S25>/Signal_Failure' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_l);

    /* End of Outputs for SubSystem: '<S25>/Signal_Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/Signal_OK' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    Disconnections_Signal_OK(&rtb_Merge1_l);

    /* End of Outputs for SubSystem: '<S25>/Signal_OK' */
  }

  /* End of If: '<S25>/If2' */

  /* If: '<S26>/If' incorporates:
   *  DataStoreRead: '<S26>/Data Store Read'
   *  Inport: '<Root>/BrakePedal_Bits'
   */
  if (Disconnections_U.BrakePedal_Bits == Disconnections_DW.Last_alive_e) {
    /* Outputs for IfAction SubSystem: '<S26>/Error_Counter' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    Disconnections_Error_Counter(&rtb_Merge1_o, &Disconnections_DW.Tot_Errors_h);

    /* End of Outputs for SubSystem: '<S26>/Error_Counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/CAN_OK' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    Disconnections_CAN_OK(Disconnections_U.BrakePedal_Bits, &rtb_Merge1_o,
                          &Disconnections_DW.Last_alive_e);

    /* End of Outputs for SubSystem: '<S26>/CAN_OK' */
  }

  /* End of If: '<S26>/If' */

  /* DataStoreWrite: '<S26>/Data Store Write' */
  Disconnections_DW.Tot_Errors_h = rtb_Merge1_o;

  /* If: '<S26>/If1' incorporates:
   *  Constant: '<S3>/Number_of_periods'
   */
  if (rtb_Merge1_o > 4800.0) {
    /* Outputs for IfAction SubSystem: '<S26>/Signal_Failure' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_o);

    /* End of Outputs for SubSystem: '<S26>/Signal_Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/Signal_OK' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    Disconnections_Signal_OK(&rtb_Merge1_o);

    /* End of Outputs for SubSystem: '<S26>/Signal_OK' */
  }

  /* End of If: '<S26>/If1' */

  /* If: '<S27>/If' incorporates:
   *  DataStoreRead: '<S27>/Data Store Read'
   *  Inport: '<Root>/APPS1_Bits'
   */
  if (Disconnections_U.APPS1_Bits == Disconnections_DW.Last_alive_o) {
    /* Outputs for IfAction SubSystem: '<S27>/Error_Counter' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    Disconnections_Error_Counter(&rtb_Merge1_p, &Disconnections_DW.Tot_Errors_f);

    /* End of Outputs for SubSystem: '<S27>/Error_Counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S27>/CAN_OK' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    Disconnections_CAN_OK(Disconnections_U.APPS1_Bits, &rtb_Merge1_p,
                          &Disconnections_DW.Last_alive_o);

    /* End of Outputs for SubSystem: '<S27>/CAN_OK' */
  }

  /* End of If: '<S27>/If' */

  /* DataStoreWrite: '<S27>/Data Store Write' */
  Disconnections_DW.Tot_Errors_f = rtb_Merge1_p;

  /* If: '<S27>/If1' incorporates:
   *  Constant: '<S3>/Number_of_periods'
   */
  if (rtb_Merge1_p > 4800.0) {
    /* Outputs for IfAction SubSystem: '<S27>/Signal_Failure' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_p);

    /* End of Outputs for SubSystem: '<S27>/Signal_Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S27>/Signal_OK' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    Disconnections_Signal_OK(&rtb_Merge1_p);

    /* End of Outputs for SubSystem: '<S27>/Signal_OK' */
  }

  /* End of If: '<S27>/If1' */

  /* If: '<Root>/If' */
  if (rtb_Add == 1.0) {
    /* Outputs for IfAction SubSystem: '<Root>/ECU Disconections' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* If: '<S11>/If' incorporates:
     *  DataStoreRead: '<S11>/Data Store Read'
     *  Inport: '<Root>/BMS_Alive'
     */
    if (Disconnections_U.BMS_Alive == Disconnections_DW.Last_alive_g) {
      /* Outputs for IfAction SubSystem: '<S11>/CAN_failure' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge);

      /* End of Outputs for SubSystem: '<S11>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S11>/CAN_OK' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.BMS_Alive, &Disconnections_B.Merge,
                            &Disconnections_DW.Last_alive_g);

      /* End of Outputs for SubSystem: '<S11>/CAN_OK' */
    }

    /* End of If: '<S11>/If' */

    /* If: '<S12>/If' incorporates:
     *  DataStoreRead: '<S12>/Data Store Read'
     *  Inport: '<Root>/Dash_Alive'
     */
    if (Disconnections_U.Dash_Alive == Disconnections_DW.Last_alive_p) {
      /* Outputs for IfAction SubSystem: '<S12>/CAN_failure' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_j);

      /* End of Outputs for SubSystem: '<S12>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S12>/CAN_OK' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Dash_Alive,
                            &Disconnections_B.Merge_j,
                            &Disconnections_DW.Last_alive_p);

      /* End of Outputs for SubSystem: '<S12>/CAN_OK' */
    }

    /* End of If: '<S12>/If' */

    /* If: '<S9>/If' incorporates:
     *  DataStoreRead: '<S9>/Data Store Read'
     *  Inport: '<Root>/Front_Alive'
     */
    if (Disconnections_U.Front_Alive == Disconnections_DW.Last_alive_n) {
      /* Outputs for IfAction SubSystem: '<S9>/CAN_failure' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_g);

      /* End of Outputs for SubSystem: '<S9>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S9>/CAN_OK' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Front_Alive,
                            &Disconnections_B.Merge_g,
                            &Disconnections_DW.Last_alive_n);

      /* End of Outputs for SubSystem: '<S9>/CAN_OK' */
    }

    /* End of If: '<S9>/If' */

    /* If: '<S13>/If' incorporates:
     *  DataStoreRead: '<S13>/Data Store Read'
     *  Inport: '<Root>/Ellipse_Alive'
     */
    if (Disconnections_U.Ellipse_Alive == Disconnections_DW.Last_alive_pb) {
      /* Outputs for IfAction SubSystem: '<S13>/CAN_failure' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_d);

      /* End of Outputs for SubSystem: '<S13>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S13>/CAN_OK' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Ellipse_Alive,
                            &Disconnections_B.Merge_d,
                            &Disconnections_DW.Last_alive_pb);

      /* End of Outputs for SubSystem: '<S13>/CAN_OK' */
    }

    /* End of If: '<S13>/If' */

    /* If: '<S10>/If' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read'
     *  Inport: '<Root>/Rear_Alive'
     */
    if (Disconnections_U.Rear_Alive == Disconnections_DW.Last_alive_n0) {
      /* Outputs for IfAction SubSystem: '<S10>/CAN_failure' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_m);

      /* End of Outputs for SubSystem: '<S10>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S10>/CAN_OK' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Rear_Alive,
                            &Disconnections_B.Merge_m,
                            &Disconnections_DW.Last_alive_n0);

      /* End of Outputs for SubSystem: '<S10>/CAN_OK' */
    }

    /* End of If: '<S10>/If' */
    /* End of Outputs for SubSystem: '<Root>/ECU Disconections' */
  }

  /* End of If: '<Root>/If' */

  /* Logic: '<Root>/OR4' */
  rtb_OR4 = ((Disconnections_B.Merge != 0.0) || (Disconnections_B.Merge_j != 0.0)
             || (Disconnections_B.Merge_g != 0.0));

  /* Outport: '<Root>/Critical_CAN_Disconnection' */
  Disconnections_Y.Critical_CAN_Disconnection = rtb_OR4;

  /* Logic: '<Root>/OR3' */
  rtb_OR3 = ((rtb_Merge1_o != 0.0) || (rtb_Merge1_p != 0.0) || (rtb_Merge1_l !=
              0.0));

  /* Outport: '<Root>/Critical_Signal_Disconnection' */
  Disconnections_Y.Critical_Signal_Disconnection = rtb_OR3;

  /* Outport: '<Root>/CriticalDisconnection' incorporates:
   *  Logic: '<Root>/OR'
   */
  Disconnections_Y.CriticalDisconnection = (rtb_OR4 || rtb_OR3);

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   *  Inport: '<Root>/SteeringSensor_Bits'
   */
  rtb_Compare_k = (uint8_T)(Disconnections_U.SteeringSensor_Bits == 0.0);

  /* Outport: '<Root>/Disconnection_SteeringSensor' */
  Disconnections_Y.Disconnection_SteeringSensor = rtb_Compare_k;

  /* Outport: '<Root>/Disconnection_Susp_F_L' incorporates:
   *  Constant: '<S41>/Constant'
   *  Inport: '<Root>/Susp_F_L_Bits'
   *  RelationalOperator: '<S41>/Compare'
   */
  Disconnections_Y.Disconnection_Susp_F_L = (uint8_T)
    (Disconnections_U.Susp_F_L_Bits == 0.0);

  /* Outport: '<Root>/Disconnection_Susp_F_R' incorporates:
   *  Constant: '<S42>/Constant'
   *  Inport: '<Root>/Susp_F_R_Bits'
   *  RelationalOperator: '<S42>/Compare'
   */
  Disconnections_Y.Disconnection_Susp_F_R = (uint8_T)
    (Disconnections_U.Susp_F_R_Bits == 0.0);

  /* Outport: '<Root>/Disconnection_Susp_R_L' incorporates:
   *  Constant: '<S43>/Constant'
   *  Inport: '<Root>/Susp_R_L_Bits'
   *  RelationalOperator: '<S43>/Compare'
   */
  Disconnections_Y.Disconnection_Susp_R_L = (uint8_T)
    (Disconnections_U.Susp_R_L_Bits == 0.0);

  /* Outport: '<Root>/Disconnection_Susp_R_R' incorporates:
   *  Constant: '<S44>/Constant'
   *  Inport: '<Root>/Susp_R_R_Bits'
   *  RelationalOperator: '<S44>/Compare'
   */
  Disconnections_Y.Disconnection_Susp_R_R = (uint8_T)
    (Disconnections_U.Susp_R_R_Bits == 0.0);

  /* If: '<S5>/If1' incorporates:
   *  If: '<S5>/If2'
   *  If: '<S5>/If3'
   *  Logic: '<Root>/OR2'
   *  Logic: '<S5>/Logical Operator1'
   *  Logic: '<S5>/Logical Operator2'
   *  Logic: '<S5>/Logical Operator3'
   */
  if ((!(Disconnections_B.Merge_d != 0.0)) && (rtb_Compare_k == 0)) {
    /* Outputs for IfAction SubSystem: '<S5>/Rigid Axle with TC 1' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* Outport: '<Root>/TV_mode' incorporates:
     *  Constant: '<S49>/Constant'
     *  SignalConversion generated from: '<S49>/1'
     */
    Disconnections_Y.TV_mode = 1.0;

    /* End of Outputs for SubSystem: '<S5>/Rigid Axle with TC 1' */
  } else if (!(Disconnections_B.Merge_d != 0.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/Others FM2+' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S5>/Rigid Axle with TC 2024' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    /* If: '<S5>/If2' incorporates:
     *  Constant: '<S50>/Constant'
     *  Outport: '<Root>/TV_mode'
     *  SignalConversion generated from: '<S46>/4, 3 or 2'
     *  SignalConversion generated from: '<S50>/2'
     */
    Disconnections_Y.TV_mode = 2.0;

    /* End of Outputs for SubSystem: '<S5>/Rigid Axle with TC 2024' */
    /* End of Outputs for SubSystem: '<S5>/Others FM2+' */
  } else if (rtb_Compare_k == 0) {
    /* Outputs for IfAction SubSystem: '<S5>/Others FM2+' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S5>/Steering TV without TC 2024' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* If: '<S5>/If3' incorporates:
     *  Constant: '<S51>/Constant'
     *  Outport: '<Root>/TV_mode'
     *  SignalConversion generated from: '<S46>/4, 3 or 2'
     *  SignalConversion generated from: '<S51>/3'
     */
    Disconnections_Y.TV_mode = 3.0;

    /* End of Outputs for SubSystem: '<S5>/Steering TV without TC 2024' */
    /* End of Outputs for SubSystem: '<S5>/Others FM2+' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/Others FM2+' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S5>/Rigid Axle 2024' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* If: '<S5>/If3' incorporates:
     *  Constant: '<S48>/Constant'
     *  Outport: '<Root>/TV_mode'
     *  SignalConversion generated from: '<S46>/4, 3 or 2'
     *  SignalConversion generated from: '<S48>/4'
     */
    Disconnections_Y.TV_mode = 4.0;

    /* End of Outputs for SubSystem: '<S5>/Rigid Axle 2024' */
    /* End of Outputs for SubSystem: '<S5>/Others FM2+' */
  }

  /* End of If: '<S5>/If1' */

  /* Outport: '<Root>/Disconnection_APPS1' */
  Disconnections_Y.Disconnection_APPS1 = rtb_Merge1_p;

  /* Outport: '<Root>/Disconnection_APPS2' */
  Disconnections_Y.Disconnection_APPS2 = rtb_Merge1_l;

  /* Outport: '<Root>/Disconnection_BrakePedal' */
  Disconnections_Y.Disconnection_BrakePedal = rtb_Merge1_o;

  /* Outport: '<Root>/Disconnection_BMS' */
  Disconnections_Y.Disconnection_BMS = Disconnections_B.Merge;

  /* Outport: '<Root>/Disconnection_DashBoard' */
  Disconnections_Y.Disconnection_DashBoard = Disconnections_B.Merge_j;

  /* Outport: '<Root>/Disconnection_Front' */
  Disconnections_Y.Disconnection_Front = Disconnections_B.Merge_g;

  /* Outport: '<Root>/Disconnection_Rear' */
  Disconnections_Y.Disconnection_Rear = Disconnections_B.Merge_m;

  /* Outport: '<Root>/Disconnection_Ellipse' */
  Disconnections_Y.Disconnection_Ellipse = Disconnections_B.Merge_d;
}

/* Model update function */
static void Disconnections_update(void)
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
  if (!(++Disconnections_M->Timing.clockTick0)) {
    ++Disconnections_M->Timing.clockTickH0;
  }

  Disconnections_M->Timing.t[0] = Disconnections_M->Timing.clockTick0 *
    Disconnections_M->Timing.stepSize0 + Disconnections_M->Timing.clockTickH0 *
    Disconnections_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Disconnections_initialize(void)
{
  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  Disconnections_DW.A = 0.0;

  /* Start for DataStoreMemory: '<S25>/Data Store Memory' */
  Disconnections_DW.Last_alive = 0.0;

  /* Start for DataStoreMemory: '<S25>/Data Store Memory1' */
  Disconnections_DW.Tot_Errors = 0.0;

  /* Start for DataStoreMemory: '<S26>/Data Store Memory' */
  Disconnections_DW.Last_alive_e = 0.0;

  /* Start for DataStoreMemory: '<S26>/Data Store Memory1' */
  Disconnections_DW.Tot_Errors_h = 0.0;

  /* Start for DataStoreMemory: '<S27>/Data Store Memory' */
  Disconnections_DW.Last_alive_o = 0.0;

  /* Start for DataStoreMemory: '<S27>/Data Store Memory1' */
  Disconnections_DW.Tot_Errors_f = 0.0;

  /* Start for IfAction SubSystem: '<Root>/ECU Disconections' */
  /* Start for DataStoreMemory: '<S11>/Data Store Memory' */
  Disconnections_DW.Last_alive_g = 0.0;

  /* Start for DataStoreMemory: '<S12>/Data Store Memory' */
  Disconnections_DW.Last_alive_p = 0.0;

  /* Start for DataStoreMemory: '<S9>/Data Store Memory' */
  Disconnections_DW.Last_alive_n = 0.0;

  /* Start for DataStoreMemory: '<S13>/Data Store Memory' */
  Disconnections_DW.Last_alive_pb = 0.0;

  /* Start for DataStoreMemory: '<S10>/Data Store Memory' */
  Disconnections_DW.Last_alive_n0 = 0.0;

  /* End of Start for SubSystem: '<Root>/ECU Disconections' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ECU Disconections' */
  /* SystemInitialize for Merge: '<S11>/Merge' */
  Disconnections_B.Merge = 0.0;

  /* SystemInitialize for Merge: '<S12>/Merge' */
  Disconnections_B.Merge_j = 0.0;

  /* SystemInitialize for Merge: '<S9>/Merge' */
  Disconnections_B.Merge_g = 0.0;

  /* SystemInitialize for Merge: '<S13>/Merge' */
  Disconnections_B.Merge_d = 0.0;

  /* SystemInitialize for Merge: '<S10>/Merge' */
  Disconnections_B.Merge_m = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/ECU Disconections' */
}

/* Model terminate function */
static void Disconnections_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Disconnections_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Disconnections_update();
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
  Disconnections_initialize();
}

void MdlTerminate(void)
{
  Disconnections_terminate();
}

/* Registration function */
RT_MODEL_Disconnections_T *Disconnections(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Disconnections_M, 0,
                sizeof(RT_MODEL_Disconnections_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Disconnections_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Disconnections_M points to
       static memory which is guaranteed to be non-NULL" */
    Disconnections_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Disconnections_M->Timing.sampleTimes =
      (&Disconnections_M->Timing.sampleTimesArray[0]);
    Disconnections_M->Timing.offsetTimes =
      (&Disconnections_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Disconnections_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Disconnections_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Disconnections_M, &Disconnections_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Disconnections_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Disconnections_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Disconnections_M, 10.0);
  Disconnections_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Disconnections_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Disconnections_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Disconnections_M->rtwLogInfo, (NULL));
    rtliSetLogT(Disconnections_M->rtwLogInfo, "tout");
    rtliSetLogX(Disconnections_M->rtwLogInfo, "");
    rtliSetLogXFinal(Disconnections_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Disconnections_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Disconnections_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Disconnections_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Disconnections_M->rtwLogInfo, 1);
    rtliSetLogY(Disconnections_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Disconnections_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Disconnections_M->rtwLogInfo, (NULL));
  }

  Disconnections_M->solverInfoPtr = (&Disconnections_M->solverInfo);
  Disconnections_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Disconnections_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Disconnections_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Disconnections_M->blockIO = ((void *) &Disconnections_B);
  (void) memset(((void *) &Disconnections_B), 0,
                sizeof(B_Disconnections_T));

  /* states (dwork) */
  Disconnections_M->dwork = ((void *) &Disconnections_DW);
  (void) memset((void *)&Disconnections_DW, 0,
                sizeof(DW_Disconnections_T));

  /* external inputs */
  Disconnections_M->inputs = (((void*)&Disconnections_U));
  (void)memset(&Disconnections_U, 0, sizeof(ExtU_Disconnections_T));

  /* external outputs */
  Disconnections_M->outputs = (&Disconnections_Y);
  (void)memset(&Disconnections_Y, 0, sizeof(ExtY_Disconnections_T));

  /* Initialize Sizes */
  Disconnections_M->Sizes.numContStates = (0);/* Number of continuous states */
  Disconnections_M->Sizes.numY = (17); /* Number of model outputs */
  Disconnections_M->Sizes.numU = (13); /* Number of model inputs */
  Disconnections_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Disconnections_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Disconnections_M->Sizes.numBlocks = (147);/* Number of blocks */
  Disconnections_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  return Disconnections_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
