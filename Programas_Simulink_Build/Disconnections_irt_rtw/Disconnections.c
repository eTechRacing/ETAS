/*
 * Disconnections.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Disconnections".
 *
 * Model version              : 1.40
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 12:57:20 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Disconnections.h"
#include "Disconnections_private.h"

/* Block signals (auto storage) */
B_Disconnections_T Disconnections_B;

/* Block states (auto storage) */
DW_Disconnections_T Disconnections_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Disconnections_T Disconnections_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Disconnections_T Disconnections_Y;

/* Real-time model */
RT_MODEL_Disconnections_T Disconnections_M_;
RT_MODEL_Disconnections_T *const Disconnections_M = &Disconnections_M_;

/*
 * Output and update for action system:
 *    '<S1>/Reset_counter'
 *    '<S31>/Signal_Failure'
 *    '<S31>/Signal_OK'
 *    '<S32>/Signal_Failure'
 *    '<S32>/Signal_OK'
 *    '<S10>/CAN_failure'
 *    '<S11>/CAN_failure'
 *    '<S12>/CAN_failure'
 *    '<S13>/CAN_failure'
 *    '<S14>/CAN_failure'
 *    ...
 */
void Disconnections_Reset_counter(real_T *rty_Out1,
  P_Reset_counter_Disconnection_T *localP)
{
  /* SignalConversion: '<S8>/OutportBufferForOut1' incorporates:
   *  Constant: '<S8>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S31>/Error_Counter'
 *    '<S32>/Error_Counter'
 *    '<S41>/Error_Counter'
 *    '<S42>/Error_Counter'
 *    '<S43>/Error_Counter'
 */
void Disconnections_Error_Counter(real_T *rty_Out1,
  P_Error_Counter_Disconnection_T *localP, real_T *rtd_Tot_Errors_h)
{
  /* Sum: '<S34>/Add' incorporates:
   *  Constant: '<S34>/Constant'
   */
  *rty_Out1 = *rtd_Tot_Errors_h + localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S31>/CAN_OK'
 *    '<S32>/CAN_OK'
 *    '<S10>/CAN_OK'
 *    '<S11>/CAN_OK'
 *    '<S12>/CAN_OK'
 *    '<S13>/CAN_OK'
 *    '<S14>/CAN_OK'
 *    '<S15>/CAN_OK'
 *    '<S16>/CAN_OK'
 *    '<S41>/CAN_OK'
 *    ...
 */
void Disconnections_CAN_OK(real_T rtu_Alive_signal, real_T *rty_Out1,
  P_CAN_OK_Disconnections_T *localP, real_T *rtd_Last_alive_l)
{
  /* DataStoreWrite: '<S33>/Data Store Write' */
  *rtd_Last_alive_l = rtu_Alive_signal;

  /* SignalConversion: '<S33>/OutportBufferForOut1' incorporates:
   *  Constant: '<S33>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S6>/Others'
 *    '<S6>/Others '
 */
void Disconnections_Others(real_T rtu_In1, real_T *rty_others)
{
  /* Inport: '<S62>/In1' */
  *rty_others = rtu_In1;
}

/* Model output function */
static void Disconnections_output(void)
{
  real_T rtb_Add;
  real_T rtb_Merge1;
  real_T rtb_Merge1_c;
  real_T rtb_Merge1_l;
  real_T rtb_Merge1_o;
  real_T rtb_Merge1_e;
  boolean_T rtb_OR4;
  boolean_T rtb_OR3;
  uint8_T rtb_Compare_k;
  uint8_T rtb_Compare_o;
  uint8_T rtb_Compare_i2;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read'
   */
  rtb_Add = Disconnections_DW.A + Disconnections_P.Constant_Value_c;

  /* If: '<S1>/If' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (rtb_Add > Disconnections_P.Constant_Value_i) {
    /* Outputs for IfAction SubSystem: '<S1>/Reset_counter' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Add, &Disconnections_P.Reset_counter);

    /* End of Outputs for SubSystem: '<S1>/Reset_counter' */
  }

  /* End of If: '<S1>/If' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  Disconnections_DW.A = rtb_Add;

  /* If: '<S43>/If' incorporates:
   *  DataStoreRead: '<S43>/Data Store Read'
   *  Inport: '<Root>/APPS1_Bits'
   */
  if (Disconnections_U.APPS1_Bits == Disconnections_DW.Last_alive) {
    /* Outputs for IfAction SubSystem: '<S43>/Error_Counter' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    Disconnections_Error_Counter(&rtb_Merge1, &Disconnections_P.Error_Counter,
      &Disconnections_DW.Tot_Errors);

    /* End of Outputs for SubSystem: '<S43>/Error_Counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S43>/CAN_OK' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    Disconnections_CAN_OK(Disconnections_U.APPS1_Bits, &rtb_Merge1,
                          &Disconnections_P.CAN_OK,
                          &Disconnections_DW.Last_alive);

    /* End of Outputs for SubSystem: '<S43>/CAN_OK' */
  }

  /* End of If: '<S43>/If' */

  /* DataStoreWrite: '<S43>/Data Store Write' */
  Disconnections_DW.Tot_Errors = rtb_Merge1;

  /* If: '<S43>/If1' */
  if (rtb_Merge1 > 4800.0) {
    /* Outputs for IfAction SubSystem: '<S43>/Signal_Failure' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1, &Disconnections_P.Signal_Failure);

    /* End of Outputs for SubSystem: '<S43>/Signal_Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S43>/Signal_OK' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1, &Disconnections_P.Signal_OK);

    /* End of Outputs for SubSystem: '<S43>/Signal_OK' */
  }

  /* End of If: '<S43>/If1' */

  /* If: '<S41>/If' incorporates:
   *  DataStoreRead: '<S41>/Data Store Read'
   *  Inport: '<Root>/APPS2_Bits'
   */
  if (Disconnections_U.APPS2_Bits == Disconnections_DW.Last_alive_g) {
    /* Outputs for IfAction SubSystem: '<S41>/Error_Counter' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    Disconnections_Error_Counter(&rtb_Merge1_c,
      &Disconnections_P.Error_Counter_i, &Disconnections_DW.Tot_Errors_k);

    /* End of Outputs for SubSystem: '<S41>/Error_Counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S41>/CAN_OK' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    Disconnections_CAN_OK(Disconnections_U.APPS2_Bits, &rtb_Merge1_c,
                          &Disconnections_P.CAN_OK_b,
                          &Disconnections_DW.Last_alive_g);

    /* End of Outputs for SubSystem: '<S41>/CAN_OK' */
  }

  /* End of If: '<S41>/If' */

  /* DataStoreWrite: '<S41>/Data Store Write' */
  Disconnections_DW.Tot_Errors_k = rtb_Merge1_c;

  /* If: '<S41>/If1' */
  if (rtb_Merge1_c > 4800.0) {
    /* Outputs for IfAction SubSystem: '<S41>/Signal_Failure' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_c,
      &Disconnections_P.Signal_Failure_j);

    /* End of Outputs for SubSystem: '<S41>/Signal_Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S41>/Signal_OK' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_c, &Disconnections_P.Signal_OK_b);

    /* End of Outputs for SubSystem: '<S41>/Signal_OK' */
  }

  /* End of If: '<S41>/If1' */

  /* If: '<S42>/If' incorporates:
   *  DataStoreRead: '<S42>/Data Store Read'
   *  Inport: '<Root>/BrakeSensor_Bits'
   */
  if (Disconnections_U.BrakeSensor_Bits == Disconnections_DW.Last_alive_c) {
    /* Outputs for IfAction SubSystem: '<S42>/Error_Counter' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    Disconnections_Error_Counter(&rtb_Merge1_l,
      &Disconnections_P.Error_Counter_d, &Disconnections_DW.Tot_Errors_j);

    /* End of Outputs for SubSystem: '<S42>/Error_Counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S42>/CAN_OK' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    Disconnections_CAN_OK(Disconnections_U.BrakeSensor_Bits, &rtb_Merge1_l,
                          &Disconnections_P.CAN_OK_p,
                          &Disconnections_DW.Last_alive_c);

    /* End of Outputs for SubSystem: '<S42>/CAN_OK' */
  }

  /* End of If: '<S42>/If' */

  /* DataStoreWrite: '<S42>/Data Store Write' */
  Disconnections_DW.Tot_Errors_j = rtb_Merge1_l;

  /* If: '<S42>/If1' */
  if (rtb_Merge1_l > 4800.0) {
    /* Outputs for IfAction SubSystem: '<S42>/Signal_Failure' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_l,
      &Disconnections_P.Signal_Failure_h);

    /* End of Outputs for SubSystem: '<S42>/Signal_Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S42>/Signal_OK' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_l, &Disconnections_P.Signal_OK_c);

    /* End of Outputs for SubSystem: '<S42>/Signal_OK' */
  }

  /* End of If: '<S42>/If1' */

  /* If: '<S31>/If' incorporates:
   *  DataStoreRead: '<S31>/Data Store Read'
   *  Inport: '<Root>/Gyroscope_F'
   */
  if (Disconnections_U.Gyroscope_F == Disconnections_DW.Last_alive_l) {
    /* Outputs for IfAction SubSystem: '<S31>/Error_Counter' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    Disconnections_Error_Counter(&rtb_Merge1_o,
      &Disconnections_P.Error_Counter_a, &Disconnections_DW.Tot_Errors_h);

    /* End of Outputs for SubSystem: '<S31>/Error_Counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S31>/CAN_OK' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    Disconnections_CAN_OK(Disconnections_U.Gyroscope_F, &rtb_Merge1_o,
                          &Disconnections_P.CAN_OK_h,
                          &Disconnections_DW.Last_alive_l);

    /* End of Outputs for SubSystem: '<S31>/CAN_OK' */
  }

  /* End of If: '<S31>/If' */

  /* DataStoreWrite: '<S31>/Data Store Write' */
  Disconnections_DW.Tot_Errors_h = rtb_Merge1_o;

  /* If: '<S31>/If1' */
  if (rtb_Merge1_o > 200.0) {
    /* Outputs for IfAction SubSystem: '<S31>/Signal_Failure' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_o,
      &Disconnections_P.Signal_Failure_m);

    /* End of Outputs for SubSystem: '<S31>/Signal_Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S31>/Signal_OK' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_o, &Disconnections_P.Signal_OK_a);

    /* End of Outputs for SubSystem: '<S31>/Signal_OK' */
  }

  /* End of If: '<S31>/If1' */

  /* If: '<S32>/If' incorporates:
   *  DataStoreRead: '<S32>/Data Store Read'
   *  Inport: '<Root>/Gyroscope_R'
   */
  if (Disconnections_U.Gyroscope_R == Disconnections_DW.Last_alive_m) {
    /* Outputs for IfAction SubSystem: '<S32>/Error_Counter' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    Disconnections_Error_Counter(&rtb_Merge1_e,
      &Disconnections_P.Error_Counter_e, &Disconnections_DW.Tot_Errors_m);

    /* End of Outputs for SubSystem: '<S32>/Error_Counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S32>/CAN_OK' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    Disconnections_CAN_OK(Disconnections_U.Gyroscope_R, &rtb_Merge1_e,
                          &Disconnections_P.CAN_OK_l,
                          &Disconnections_DW.Last_alive_m);

    /* End of Outputs for SubSystem: '<S32>/CAN_OK' */
  }

  /* End of If: '<S32>/If' */

  /* DataStoreWrite: '<S32>/Data Store Write' */
  Disconnections_DW.Tot_Errors_m = rtb_Merge1_e;

  /* If: '<S32>/If1' */
  if (rtb_Merge1_e > 200.0) {
    /* Outputs for IfAction SubSystem: '<S32>/Signal_Failure' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_e,
      &Disconnections_P.Signal_Failure_hx);

    /* End of Outputs for SubSystem: '<S32>/Signal_Failure' */
  } else {
    /* Outputs for IfAction SubSystem: '<S32>/Signal_OK' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge1_e, &Disconnections_P.Signal_OK_be);

    /* End of Outputs for SubSystem: '<S32>/Signal_OK' */
  }

  /* End of If: '<S32>/If1' */

  /* If: '<Root>/If' */
  if (rtb_Add == 1.0) {
    /* Outputs for IfAction SubSystem: '<Root>/ECU Disconections' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* If: '<S13>/If' incorporates:
     *  DataStoreRead: '<S13>/Data Store Read'
     *  Inport: '<Root>/BMS_Alive'
     */
    if (Disconnections_U.BMS_Alive == Disconnections_DW.Last_alive_c0) {
      /* Outputs for IfAction SubSystem: '<S13>/CAN_failure' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge,
        &Disconnections_P.CAN_failure);

      /* End of Outputs for SubSystem: '<S13>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S13>/CAN_OK' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.BMS_Alive, &Disconnections_B.Merge,
                            &Disconnections_P.CAN_OK_pt,
                            &Disconnections_DW.Last_alive_c0);

      /* End of Outputs for SubSystem: '<S13>/CAN_OK' */
    }

    /* End of If: '<S13>/If' */

    /* If: '<S14>/If' incorporates:
     *  DataStoreRead: '<S14>/Data Store Read'
     *  Inport: '<Root>/Dash_Alive'
     */
    if (Disconnections_U.Dash_Alive == Disconnections_DW.Last_alive_o) {
      /* Outputs for IfAction SubSystem: '<S14>/CAN_failure' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_h,
        &Disconnections_P.CAN_failure_p);

      /* End of Outputs for SubSystem: '<S14>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S14>/CAN_OK' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Dash_Alive,
                            &Disconnections_B.Merge_h,
                            &Disconnections_P.CAN_OK_m,
                            &Disconnections_DW.Last_alive_o);

      /* End of Outputs for SubSystem: '<S14>/CAN_OK' */
    }

    /* End of If: '<S14>/If' */

    /* If: '<S15>/If' incorporates:
     *  DataStoreRead: '<S15>/Data Store Read'
     *  Inport: '<Root>/Shutdown_Alive'
     */
    if (Disconnections_U.Shutdown_Alive == Disconnections_DW.Last_alive_j) {
      /* Outputs for IfAction SubSystem: '<S15>/CAN_failure' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_j,
        &Disconnections_P.CAN_failure_o);

      /* End of Outputs for SubSystem: '<S15>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S15>/CAN_OK' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Shutdown_Alive,
                            &Disconnections_B.Merge_j,
                            &Disconnections_P.CAN_OK_k,
                            &Disconnections_DW.Last_alive_j);

      /* End of Outputs for SubSystem: '<S15>/CAN_OK' */
    }

    /* End of If: '<S15>/If' */

    /* If: '<S11>/If' incorporates:
     *  DataStoreRead: '<S11>/Data Store Read'
     *  Inport: '<Root>/Accel_F_Alive'
     */
    if (Disconnections_U.Accel_F_Alive == Disconnections_DW.Last_alive_a) {
      /* Outputs for IfAction SubSystem: '<S11>/CAN_failure' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_b,
        &Disconnections_P.CAN_failure_h);

      /* End of Outputs for SubSystem: '<S11>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S11>/CAN_OK' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Accel_F_Alive,
                            &Disconnections_B.Merge_b,
                            &Disconnections_P.CAN_OK_lx,
                            &Disconnections_DW.Last_alive_a);

      /* End of Outputs for SubSystem: '<S11>/CAN_OK' */
    }

    /* End of If: '<S11>/If' */

    /* If: '<S10>/If' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read'
     *  Inport: '<Root>/ADCAN_Alive'
     */
    if (Disconnections_U.ADCAN_Alive == Disconnections_DW.Last_alive_ar) {
      /* Outputs for IfAction SubSystem: '<S10>/CAN_failure' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_he,
        &Disconnections_P.CAN_failure_m);

      /* End of Outputs for SubSystem: '<S10>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S10>/CAN_OK' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.ADCAN_Alive,
                            &Disconnections_B.Merge_he,
                            &Disconnections_P.CAN_OK_j,
                            &Disconnections_DW.Last_alive_ar);

      /* End of Outputs for SubSystem: '<S10>/CAN_OK' */
    }

    /* End of If: '<S10>/If' */

    /* If: '<S16>/If' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read'
     *  Inport: '<Root>/LV_Derivation_Alive'
     */
    if (Disconnections_U.LV_Derivation_Alive == Disconnections_DW.Last_alive_je)
    {
      /* Outputs for IfAction SubSystem: '<S16>/CAN_failure' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_f,
        &Disconnections_P.CAN_failure_i);

      /* End of Outputs for SubSystem: '<S16>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S16>/CAN_OK' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.LV_Derivation_Alive,
                            &Disconnections_B.Merge_f,
                            &Disconnections_P.CAN_OK_n,
                            &Disconnections_DW.Last_alive_je);

      /* End of Outputs for SubSystem: '<S16>/CAN_OK' */
    }

    /* End of If: '<S16>/If' */

    /* If: '<S12>/If' incorporates:
     *  DataStoreRead: '<S12>/Data Store Read'
     *  Inport: '<Root>/Accel_R_Alive'
     */
    if (Disconnections_U.Accel_R_Alive == Disconnections_DW.Last_alive_gx) {
      /* Outputs for IfAction SubSystem: '<S12>/CAN_failure' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_d,
        &Disconnections_P.CAN_failure_mc);

      /* End of Outputs for SubSystem: '<S12>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S12>/CAN_OK' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Accel_R_Alive,
                            &Disconnections_B.Merge_d,
                            &Disconnections_P.CAN_OK_i,
                            &Disconnections_DW.Last_alive_gx);

      /* End of Outputs for SubSystem: '<S12>/CAN_OK' */
    }

    /* End of If: '<S12>/If' */
    /* End of Outputs for SubSystem: '<Root>/ECU Disconections' */
  }

  /* End of If: '<Root>/If' */

  /* Outport: '<Root>/Disconnection_BMS' */
  Disconnections_Y.Disconnection_BMS = Disconnections_B.Merge;

  /* Outport: '<Root>/Disconnection_DashBoard' */
  Disconnections_Y.Disconnection_DashBoard = Disconnections_B.Merge_h;

  /* Outport: '<Root>/Disconnection_Shutdown' */
  Disconnections_Y.Disconnection_Shutdown = Disconnections_B.Merge_j;

  /* Outport: '<Root>/Disconnection_Accel_F' */
  Disconnections_Y.Disconnection_Accel_F = Disconnections_B.Merge_b;

  /* Outport: '<Root>/Disconnection_ADCAN' */
  Disconnections_Y.Disconnection_ADCAN = Disconnections_B.Merge_he;

  /* Outport: '<Root>/CounterOut' */
  Disconnections_Y.CounterOut = rtb_Add;

  /* Outport: '<Root>/Disconnection_Accel_R' */
  Disconnections_Y.Disconnection_Accel_R = Disconnections_B.Merge_d;

  /* Outport: '<Root>/Disconnection_LV_Derivation' */
  Disconnections_Y.Disconnection_LV_Derivation = Disconnections_B.Merge_f;

  /* Logic: '<Root>/OR4' */
  rtb_OR4 = ((Disconnections_B.Merge != 0.0) || (Disconnections_B.Merge_h != 0.0)
             || (Disconnections_B.Merge_j != 0.0) || (Disconnections_B.Merge_he
              != 0.0));

  /* Outport: '<Root>/Critical_CAN_Disconnection' */
  Disconnections_Y.Critical_CAN_Disconnection = rtb_OR4;

  /* Logic: '<Root>/OR3' */
  rtb_OR3 = ((rtb_Merge1_l != 0.0) || (rtb_Merge1 != 0.0) || (rtb_Merge1_c !=
              0.0));

  /* Outport: '<Root>/Critical_Signal_Disconnection' */
  Disconnections_Y.Critical_Signal_Disconnection = rtb_OR3;

  /* Outport: '<Root>/CriticalDisconnection' incorporates:
   *  Sum: '<Root>/Add'
   */
  Disconnections_Y.CriticalDisconnection = (uint8_T)((uint32_T)rtb_OR4 + rtb_OR3);

  /* Outport: '<Root>/Disconnection_APPS1' */
  Disconnections_Y.Disconnection_APPS1 = rtb_Merge1;

  /* Outport: '<Root>/Disconnection_APPS2' */
  Disconnections_Y.Disconnection_APPS2 = rtb_Merge1_c;

  /* Outport: '<Root>/Disconnection_Brake_Sensor' */
  Disconnections_Y.Disconnection_Brake_Sensor = rtb_Merge1_l;

  /* RelationalOperator: '<S56>/Compare' incorporates:
   *  Constant: '<S56>/Constant'
   *  Inport: '<Root>/SteeringSensor_Bits'
   */
  rtb_Compare_k = (uint8_T)(Disconnections_U.SteeringSensor_Bits ==
    Disconnections_P.Constant_Value_ic);

  /* Outport: '<Root>/Disconnection_SteeringSensor' */
  Disconnections_Y.Disconnection_SteeringSensor = rtb_Compare_k;

  /* Outport: '<Root>/Disconnection_Susp_F_L' incorporates:
   *  Constant: '<S57>/Constant'
   *  Inport: '<Root>/Susp_F_L_Bits'
   *  RelationalOperator: '<S57>/Compare'
   */
  Disconnections_Y.Disconnection_Susp_F_L = (uint8_T)
    (Disconnections_U.Susp_F_L_Bits == Disconnections_P.Constant_Value_l);

  /* Outport: '<Root>/Disconnection_Susp_F_R' incorporates:
   *  Constant: '<S58>/Constant'
   *  Inport: '<Root>/Susp_F_R_Bits'
   *  RelationalOperator: '<S58>/Compare'
   */
  Disconnections_Y.Disconnection_Susp_F_R = (uint8_T)
    (Disconnections_U.Susp_F_R_Bits == Disconnections_P.Constant_Value_d);

  /* RelationalOperator: '<S59>/Compare' incorporates:
   *  Constant: '<S59>/Constant'
   *  Inport: '<Root>/Susp_R_L_Bits'
   */
  rtb_Compare_o = (uint8_T)(Disconnections_U.Susp_R_L_Bits ==
    Disconnections_P.Constant_Value_j);

  /* Outport: '<Root>/Disconnection_Susp_R_L' */
  Disconnections_Y.Disconnection_Susp_R_L = rtb_Compare_o;

  /* RelationalOperator: '<S60>/Compare' incorporates:
   *  Constant: '<S60>/Constant'
   *  Inport: '<Root>/Susp_R_R_Bits'
   */
  rtb_Compare_i2 = (uint8_T)(Disconnections_U.Susp_R_R_Bits ==
    Disconnections_P.Constant_Value_o);

  /* Outport: '<Root>/Disconnection_Susp_R_R' */
  Disconnections_Y.Disconnection_Susp_R_R = rtb_Compare_i2;

  /* If: '<S6>/If2' incorporates:
   *  If: '<S6>/If3'
   *  Logic: '<Root>/OR2'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator2'
   */
  if (!((Disconnections_B.Merge_d != 0.0) || (rtb_Compare_i2 != 0) ||
        (rtb_Compare_o != 0))) {
    /* Outputs for IfAction SubSystem: '<S6>/VDC without Longitudinal ' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    /* SignalConversion: '<S67>/OutportBufferFor1' incorporates:
     *  Constant: '<S67>/Constant'
     */
    rtb_Add = Disconnections_P.Constant_Value_h;

    /* End of Outputs for SubSystem: '<S6>/VDC without Longitudinal ' */
  } else {
    if (!(rtb_Compare_k != 0)) {
      /* Outputs for IfAction SubSystem: '<S6>/Steering TV 2017 without TC' incorporates:
       *  ActionPort: '<S65>/Action Port'
       */
      /* If: '<S6>/If3' incorporates:
       *  Constant: '<S65>/Constant'
       */
      rtb_Merge1 = Disconnections_P.Constant_Value_m;

      /* End of Outputs for SubSystem: '<S6>/Steering TV 2017 without TC' */
    } else {
      /* Outputs for IfAction SubSystem: '<S6>/Rigid Axle' incorporates:
       *  ActionPort: '<S64>/Action Port'
       */
      /* If: '<S6>/If3' incorporates:
       *  Constant: '<S64>/Constant'
       */
      rtb_Merge1 = Disconnections_P.Constant_Value_e;

      /* End of Outputs for SubSystem: '<S6>/Rigid Axle' */
    }

    /* Outputs for IfAction SubSystem: '<S6>/Others ' incorporates:
     *  ActionPort: '<S63>/Action Port'
     */
    Disconnections_Others(rtb_Merge1, &rtb_Add);

    /* End of Outputs for SubSystem: '<S6>/Others ' */
  }

  /* End of If: '<S6>/If2' */

  /* If: '<S6>/If1' incorporates:
   *  Logic: '<Root>/OR1'
   *  Logic: '<S6>/Logical Operator'
   */
  if (!((Disconnections_B.Merge_d != 0.0) || (rtb_Compare_o != 0) ||
        (rtb_Compare_i2 != 0) || (rtb_Compare_k != 0))) {
    /* Outputs for IfAction SubSystem: '<S6>/VDC 2018 Complete' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    /* SignalConversion: '<S66>/OutportBufferFor0' incorporates:
     *  Constant: '<S66>/Constant'
     */
    rtb_Merge1_l = Disconnections_P.Constant_Value;

    /* End of Outputs for SubSystem: '<S6>/VDC 2018 Complete' */
  } else {
    /* Outputs for IfAction SubSystem: '<S6>/Others' incorporates:
     *  ActionPort: '<S62>/Action Port'
     */
    Disconnections_Others(rtb_Add, &rtb_Merge1_l);

    /* End of Outputs for SubSystem: '<S6>/Others' */
  }

  /* End of If: '<S6>/If1' */

  /* Outport: '<Root>/TV_mode' */
  Disconnections_Y.TV_mode = rtb_Merge1_l;

  /* Outport: '<Root>/Disconnection_Gyroscope_F' */
  Disconnections_Y.Disconnection_Gyroscope_F = rtb_Merge1_o;

  /* Outport: '<Root>/Disconnection_Gyroscope_R' */
  Disconnections_Y.Disconnection_Gyroscope_R = rtb_Merge1_e;
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
  Disconnections_DW.A = Disconnections_P.DataStoreMemory_InitialValue_j;

  /* Start for DataStoreMemory: '<S43>/Data Store Memory' */
  Disconnections_DW.Last_alive = Disconnections_P.DataStoreMemory_InitialValue_c;

  /* Start for DataStoreMemory: '<S43>/Data Store Memory1' */
  Disconnections_DW.Tot_Errors = Disconnections_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<S41>/Data Store Memory' */
  Disconnections_DW.Last_alive_g =
    Disconnections_P.DataStoreMemory_InitialValue_jc;

  /* Start for DataStoreMemory: '<S41>/Data Store Memory1' */
  Disconnections_DW.Tot_Errors_k =
    Disconnections_P.DataStoreMemory1_InitialValue_b;

  /* Start for DataStoreMemory: '<S42>/Data Store Memory' */
  Disconnections_DW.Last_alive_c =
    Disconnections_P.DataStoreMemory_InitialValue_kg;

  /* Start for DataStoreMemory: '<S42>/Data Store Memory1' */
  Disconnections_DW.Tot_Errors_j =
    Disconnections_P.DataStoreMemory1_InitialValue_d;

  /* Start for DataStoreMemory: '<S31>/Data Store Memory' */
  Disconnections_DW.Last_alive_l =
    Disconnections_P.DataStoreMemory_InitialValue_m;

  /* Start for DataStoreMemory: '<S31>/Data Store Memory1' */
  Disconnections_DW.Tot_Errors_h =
    Disconnections_P.DataStoreMemory1_InitialValue_m;

  /* Start for DataStoreMemory: '<S32>/Data Store Memory' */
  Disconnections_DW.Last_alive_m =
    Disconnections_P.DataStoreMemory_InitialValue_ba;

  /* Start for DataStoreMemory: '<S32>/Data Store Memory1' */
  Disconnections_DW.Tot_Errors_m =
    Disconnections_P.DataStoreMemory1_InitialValue_c;

  /* Start for IfAction SubSystem: '<Root>/ECU Disconections' */
  /* Start for DataStoreMemory: '<S13>/Data Store Memory' */
  Disconnections_DW.Last_alive_c0 =
    Disconnections_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<S14>/Data Store Memory' */
  Disconnections_DW.Last_alive_o =
    Disconnections_P.DataStoreMemory_InitialValue_k;

  /* Start for DataStoreMemory: '<S15>/Data Store Memory' */
  Disconnections_DW.Last_alive_j =
    Disconnections_P.DataStoreMemory_InitialValue_o;

  /* Start for DataStoreMemory: '<S11>/Data Store Memory' */
  Disconnections_DW.Last_alive_a =
    Disconnections_P.DataStoreMemory_InitialValue_d;

  /* Start for DataStoreMemory: '<S10>/Data Store Memory' */
  Disconnections_DW.Last_alive_ar =
    Disconnections_P.DataStoreMemory_InitialValue_b;

  /* Start for DataStoreMemory: '<S16>/Data Store Memory' */
  Disconnections_DW.Last_alive_je =
    Disconnections_P.DataStoreMemory_InitialValue_ks;

  /* Start for DataStoreMemory: '<S12>/Data Store Memory' */
  Disconnections_DW.Last_alive_gx =
    Disconnections_P.DataStoreMemory_InitialValue_f;

  /* End of Start for SubSystem: '<Root>/ECU Disconections' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ECU Disconections' */
  /* SystemInitialize for Merge: '<S13>/Merge' */
  Disconnections_B.Merge = Disconnections_P.Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S14>/Merge' */
  Disconnections_B.Merge_h = Disconnections_P.Merge_InitialOutput_b;

  /* SystemInitialize for Merge: '<S15>/Merge' */
  Disconnections_B.Merge_j = Disconnections_P.Merge_InitialOutput_l;

  /* SystemInitialize for Merge: '<S11>/Merge' */
  Disconnections_B.Merge_b = Disconnections_P.Merge_InitialOutput_m;

  /* SystemInitialize for Merge: '<S10>/Merge' */
  Disconnections_B.Merge_he = Disconnections_P.Merge_InitialOutput_a;

  /* SystemInitialize for Merge: '<S16>/Merge' */
  Disconnections_B.Merge_f = Disconnections_P.Merge_InitialOutput_o;

  /* SystemInitialize for Merge: '<S12>/Merge' */
  Disconnections_B.Merge_d = Disconnections_P.Merge_InitialOutput_p;

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
  Disconnections_M->solverInfoPtr = (&Disconnections_M->solverInfo);
  Disconnections_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Disconnections_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Disconnections_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Disconnections_M->blockIO = ((void *) &Disconnections_B);
  (void) memset(((void *) &Disconnections_B), 0,
                sizeof(B_Disconnections_T));

  /* parameters */
  Disconnections_M->defaultParam = ((real_T *)&Disconnections_P);

  /* states (dwork) */
  Disconnections_M->dwork = ((void *) &Disconnections_DW);
  (void) memset((void *)&Disconnections_DW, 0,
                sizeof(DW_Disconnections_T));

  /* external inputs */
  Disconnections_M->inputs = (((void*)&Disconnections_U));
  (void)memset((void *)&Disconnections_U, 0, sizeof(ExtU_Disconnections_T));

  /* external outputs */
  Disconnections_M->outputs = (&Disconnections_Y);
  (void) memset((void *)&Disconnections_Y, 0,
                sizeof(ExtY_Disconnections_T));

  /* Initialize Sizes */
  Disconnections_M->Sizes.numContStates = (0);/* Number of continuous states */
  Disconnections_M->Sizes.numY = (22); /* Number of model outputs */
  Disconnections_M->Sizes.numU = (17); /* Number of model inputs */
  Disconnections_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Disconnections_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Disconnections_M->Sizes.numBlocks = (184);/* Number of blocks */
  Disconnections_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  Disconnections_M->Sizes.numBlockPrms = (71);/* Sum of parameter "widths" */
  return Disconnections_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
