/*
 * Disconnections.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Disconnections".
 *
 * Model version              : 13.29
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Jul 31 13:39:45 2024
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
 *    '<S2>/Reset_counter'
 *    '<S12>/CAN_failure'
 *    '<S13>/CAN_failure'
 *    '<S14>/CAN_failure'
 *    '<S15>/CAN_failure'
 *    '<S16>/CAN_failure'
 */
void Disconnections_Reset_counter(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S8>/Out1' incorporates:
   *  Constant: '<S8>/Constant'
   */
  *rty_Out1 = 1.0;
}

/*
 * Output and update for action system:
 *    '<S1>/Counting'
 *    '<S2>/Counting'
 */
void Disconnections_Counting(real_T rtu_In1, real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S7>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S12>/CAN_OK'
 *    '<S13>/CAN_OK'
 *    '<S14>/CAN_OK'
 *    '<S15>/CAN_OK'
 *    '<S16>/CAN_OK'
 */
void Disconnections_CAN_OK(real_T rtu_Alive_signal, real_T *rty_Out1, real_T
  *rtd_Last_alive_n)
{
  /* DataStoreWrite: '<S17>/Data Store Write' */
  *rtd_Last_alive_n = rtu_Alive_signal;

  /* SignalConversion generated from: '<S17>/Out1' incorporates:
   *  Constant: '<S17>/Constant'
   */
  *rty_Out1 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S30>/If Action Subsystem'
 *    '<S30>/If Action Subsystem1'
 *    '<S30>/If Action Subsystem2'
 *    '<S31>/If Action Subsystem'
 *    '<S31>/If Action Subsystem1'
 *    '<S31>/If Action Subsystem2'
 *    '<S32>/If Action Subsystem'
 *    '<S32>/If Action Subsystem1'
 *    '<S32>/If Action Subsystem2'
 *    '<S33>/If Action Subsystem'
 *    ...
 */
void Disconnection_IfActionSubsystem(real_T *rty_disc)
{
  /* SignalConversion generated from: '<S38>/disc' incorporates:
   *  Constant: '<S38>/Constant'
   */
  *rty_disc = 1.0;
}

/*
 * Output and update for action system:
 *    '<S30>/If Action Subsystem3'
 *    '<S31>/If Action Subsystem3'
 *    '<S32>/If Action Subsystem3'
 *    '<S33>/If Action Subsystem3'
 *    '<S34>/If Action Subsystem3'
 *    '<S35>/If Action Subsystem3'
 *    '<S36>/If Action Subsystem3'
 *    '<S37>/If Action Subsystem3'
 */
void Disconnectio_IfActionSubsystem3(real_T *rty_disc)
{
  /* SignalConversion generated from: '<S41>/disc' incorporates:
   *  Constant: '<S41>/Constant'
   */
  *rty_disc = 0.0;
}

/*
 * Output and update for action system:
 *    '<S6>/Rigid Axle 2024'
 *    '<S6>/Rigid Axle One Inverter'
 */
void Disconnections_RigidAxle2024(real_T *rty_u)
{
  /* SignalConversion generated from: '<S74>/4' incorporates:
   *  Constant: '<S74>/Constant'
   */
  *rty_u = 4.0;
}

/* Model output function */
static void Disconnections_output(void)
{
  /* local block i/o variables */
  real_T rtb_Merge3;
  real_T rtb_Add;
  real_T rtb_Add_d;
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
     *  ActionPort: '<S8>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Merge3);

    /* End of Outputs for SubSystem: '<S1>/Reset_counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/Counting' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    Disconnections_Counting(rtb_Add, &rtb_Merge3);

    /* End of Outputs for SubSystem: '<S1>/Counting' */
  }

  /* End of If: '<S1>/If' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  Disconnections_DW.A = rtb_Merge3;

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataStoreRead: '<S2>/Data Store Read'
   */
  rtb_Add_d = Disconnections_DW.A_o + 1.0;

  /* If: '<S2>/If' incorporates:
   *  Constant: '<Root>/Periods1'
   *  Constant: '<S2>/Constant'
   *  DataStoreRead: '<S2>/Data Store Read'
   *  Sum: '<S2>/Add'
   */
  if (Disconnections_DW.A_o + 1.0 > 4.0) {
    /* Outputs for IfAction SubSystem: '<S2>/Reset_counter' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    Disconnections_Reset_counter(&rtb_Add);

    /* End of Outputs for SubSystem: '<S2>/Reset_counter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/Counting' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    Disconnections_Counting(Disconnections_DW.A_o + 1.0, &rtb_Add);

    /* End of Outputs for SubSystem: '<S2>/Counting' */
  }

  /* End of If: '<S2>/If' */

  /* DataStoreWrite: '<S2>/Data Store Write' */
  Disconnections_DW.A_o = rtb_Add;

  /* If: '<Root>/If' */
  if (rtb_Merge3 == 1.0) {
    /* Outputs for IfAction SubSystem: '<Root>/ECU Disconections' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* If: '<S14>/If' incorporates:
     *  DataStoreRead: '<S14>/Data Store Read'
     *  Inport: '<Root>/BMS_Alive'
     */
    if (Disconnections_U.BMS_Alive == Disconnections_DW.Last_alive) {
      /* Outputs for IfAction SubSystem: '<S14>/CAN_failure' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_g);

      /* End of Outputs for SubSystem: '<S14>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S14>/CAN_OK' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.BMS_Alive,
                            &Disconnections_B.Merge_g,
                            &Disconnections_DW.Last_alive);

      /* End of Outputs for SubSystem: '<S14>/CAN_OK' */
    }

    /* End of If: '<S14>/If' */

    /* If: '<S15>/If' incorporates:
     *  DataStoreRead: '<S15>/Data Store Read'
     *  Inport: '<Root>/Dash_Alive'
     */
    if (Disconnections_U.Dash_Alive == Disconnections_DW.Last_alive_p) {
      /* Outputs for IfAction SubSystem: '<S15>/CAN_failure' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_j);

      /* End of Outputs for SubSystem: '<S15>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S15>/CAN_OK' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Dash_Alive,
                            &Disconnections_B.Merge_j,
                            &Disconnections_DW.Last_alive_p);

      /* End of Outputs for SubSystem: '<S15>/CAN_OK' */
    }

    /* End of If: '<S15>/If' */

    /* If: '<S12>/If' incorporates:
     *  DataStoreRead: '<S12>/Data Store Read'
     *  Inport: '<Root>/Front_Alive'
     */
    if (Disconnections_U.Front_Alive == Disconnections_DW.Last_alive_n) {
      /* Outputs for IfAction SubSystem: '<S12>/CAN_failure' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_go);

      /* End of Outputs for SubSystem: '<S12>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S12>/CAN_OK' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Front_Alive,
                            &Disconnections_B.Merge_go,
                            &Disconnections_DW.Last_alive_n);

      /* End of Outputs for SubSystem: '<S12>/CAN_OK' */
    }

    /* End of If: '<S12>/If' */

    /* If: '<S16>/If' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read'
     *  Inport: '<Root>/Ellipse_Alive'
     */
    if (Disconnections_U.Ellipse_Alive == Disconnections_DW.Last_alive_pb) {
      /* Outputs for IfAction SubSystem: '<S16>/CAN_failure' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_dt);

      /* End of Outputs for SubSystem: '<S16>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S16>/CAN_OK' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Ellipse_Alive,
                            &Disconnections_B.Merge_dt,
                            &Disconnections_DW.Last_alive_pb);

      /* End of Outputs for SubSystem: '<S16>/CAN_OK' */
    }

    /* End of If: '<S16>/If' */

    /* If: '<S13>/If' incorporates:
     *  DataStoreRead: '<S13>/Data Store Read'
     *  Inport: '<Root>/Rear_Alive'
     */
    if (Disconnections_U.Rear_Alive == Disconnections_DW.Last_alive_n0) {
      /* Outputs for IfAction SubSystem: '<S13>/CAN_failure' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      Disconnections_Reset_counter(&Disconnections_B.Merge_m);

      /* End of Outputs for SubSystem: '<S13>/CAN_failure' */
    } else {
      /* Outputs for IfAction SubSystem: '<S13>/CAN_OK' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      Disconnections_CAN_OK(Disconnections_U.Rear_Alive,
                            &Disconnections_B.Merge_m,
                            &Disconnections_DW.Last_alive_n0);

      /* End of Outputs for SubSystem: '<S13>/CAN_OK' */
    }

    /* End of If: '<S13>/If' */
    /* End of Outputs for SubSystem: '<Root>/ECU Disconections' */
  }

  /* End of If: '<Root>/If' */

  /* Logic: '<Root>/OR4' */
  rtb_OR4 = ((Disconnections_B.Merge_g != 0.0) || (Disconnections_B.Merge_go !=
              0.0));

  /* Outport: '<Root>/Critical_CAN_Disconnection' */
  Disconnections_Y.Critical_CAN_Disconnection = rtb_OR4;

  /* If: '<Root>/If1' */
  if (rtb_Add == 1.0) {
    /* Outputs for IfAction SubSystem: '<Root>/Sensor Disconnections (Noise)' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* If: '<S30>/If' incorporates:
     *  Constant: '<S30>/threshold high'
     *  Constant: '<S30>/threshold low'
     *  Inport: '<Root>/APPS1_Bits'
     */
    if (Disconnections_U.APPS1_Bits < 8.0) {
      /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge);

      /* End of Outputs for SubSystem: '<S30>/If Action Subsystem' */
    } else if (Disconnections_U.APPS1_Bits > 4030.0) {
      /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge);

      /* End of Outputs for SubSystem: '<S30>/If Action Subsystem1' */
    } else if (Disconnections_B.Merge_go == 1.0) {
      /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge);

      /* End of Outputs for SubSystem: '<S30>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      Disconnectio_IfActionSubsystem3(&Disconnections_B.Merge);

      /* End of Outputs for SubSystem: '<S30>/If Action Subsystem3' */
    }

    /* End of If: '<S30>/If' */

    /* If: '<S31>/If' incorporates:
     *  Constant: '<S31>/threshold high'
     *  Constant: '<S31>/threshold low'
     *  Inport: '<Root>/APPS2_Bits'
     */
    if (Disconnections_U.APPS2_Bits < 10.0) {
      /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_e);

      /* End of Outputs for SubSystem: '<S31>/If Action Subsystem' */
    } else if (Disconnections_U.APPS2_Bits > 3680.0) {
      /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_e);

      /* End of Outputs for SubSystem: '<S31>/If Action Subsystem1' */
    } else if (Disconnections_B.Merge_go == 1.0) {
      /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_e);

      /* End of Outputs for SubSystem: '<S31>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      Disconnectio_IfActionSubsystem3(&Disconnections_B.Merge_e);

      /* End of Outputs for SubSystem: '<S31>/If Action Subsystem3' */
    }

    /* End of If: '<S31>/If' */

    /* If: '<S32>/If' incorporates:
     *  Constant: '<S32>/threshold high'
     *  Constant: '<S32>/threshold low'
     *  Inport: '<Root>/BrakePedal_Bits'
     */
    if (Disconnections_U.BrakePedal_Bits < 10.0) {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem' incorporates:
       *  ActionPort: '<S46>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_ed);

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem' */
    } else if (Disconnections_U.BrakePedal_Bits > 4020.0) {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S47>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_ed);

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem1' */
    } else if (Disconnections_B.Merge_go == 1.0) {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_ed);

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      Disconnectio_IfActionSubsystem3(&Disconnections_B.Merge_ed);

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem3' */
    }

    /* End of If: '<S32>/If' */

    /* If: '<S33>/If' incorporates:
     *  Constant: '<S33>/threshold high'
     *  Constant: '<S33>/threshold low'
     *  Inport: '<Root>/SteeringSensor_Bits'
     */
    if (Disconnections_U.SteeringSensor_Bits < 10.0) {
      /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem' incorporates:
       *  ActionPort: '<S50>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_d);

      /* End of Outputs for SubSystem: '<S33>/If Action Subsystem' */
    } else if (Disconnections_U.SteeringSensor_Bits > 4050.0) {
      /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S51>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_d);

      /* End of Outputs for SubSystem: '<S33>/If Action Subsystem1' */
    } else if (Disconnections_B.Merge_go == 1.0) {
      /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_d);

      /* End of Outputs for SubSystem: '<S33>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S53>/Action Port'
       */
      Disconnectio_IfActionSubsystem3(&Disconnections_B.Merge_d);

      /* End of Outputs for SubSystem: '<S33>/If Action Subsystem3' */
    }

    /* End of If: '<S33>/If' */

    /* If: '<S34>/If' incorporates:
     *  Constant: '<S34>/threshold high'
     *  Constant: '<S34>/threshold low'
     *  Inport: '<Root>/Susp_F_L_Bits'
     */
    if (Disconnections_U.Susp_F_L_Bits < 5.0) {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
       *  ActionPort: '<S54>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_n);

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */
    } else if (Disconnections_U.Susp_F_L_Bits > 4050.0) {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S55>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_n);

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem1' */
    } else if (Disconnections_B.Merge_go == 1.0) {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S56>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_n);

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S57>/Action Port'
       */
      Disconnectio_IfActionSubsystem3(&Disconnections_B.Merge_n);

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem3' */
    }

    /* End of If: '<S34>/If' */

    /* If: '<S35>/If' incorporates:
     *  Constant: '<S35>/threshold high'
     *  Constant: '<S35>/threshold low'
     *  Inport: '<Root>/Susp_F_R_Bits'
     */
    if (Disconnections_U.Susp_F_R_Bits < 5.0) {
      /* Outputs for IfAction SubSystem: '<S35>/If Action Subsystem' incorporates:
       *  ActionPort: '<S58>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_k);

      /* End of Outputs for SubSystem: '<S35>/If Action Subsystem' */
    } else if (Disconnections_U.Susp_F_R_Bits > 4010.0) {
      /* Outputs for IfAction SubSystem: '<S35>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S59>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_k);

      /* End of Outputs for SubSystem: '<S35>/If Action Subsystem1' */
    } else if (Disconnections_B.Merge_go == 1.0) {
      /* Outputs for IfAction SubSystem: '<S35>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S60>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_k);

      /* End of Outputs for SubSystem: '<S35>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S35>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S61>/Action Port'
       */
      Disconnectio_IfActionSubsystem3(&Disconnections_B.Merge_k);

      /* End of Outputs for SubSystem: '<S35>/If Action Subsystem3' */
    }

    /* End of If: '<S35>/If' */

    /* If: '<S36>/If' incorporates:
     *  Constant: '<S36>/threshold high'
     *  Constant: '<S36>/threshold low'
     *  Inport: '<Root>/Susp_R_L_Bits'
     */
    if (Disconnections_U.Susp_R_L_Bits < 13.0) {
      /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_p);

      /* End of Outputs for SubSystem: '<S36>/If Action Subsystem' */
    } else if (Disconnections_U.Susp_R_L_Bits > 4110.0) {
      /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_p);

      /* End of Outputs for SubSystem: '<S36>/If Action Subsystem1' */
    } else if (Disconnections_B.Merge_m == 1.0) {
      /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S64>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_p);

      /* End of Outputs for SubSystem: '<S36>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S65>/Action Port'
       */
      Disconnectio_IfActionSubsystem3(&Disconnections_B.Merge_p);

      /* End of Outputs for SubSystem: '<S36>/If Action Subsystem3' */
    }

    /* End of If: '<S36>/If' */

    /* If: '<S37>/If' incorporates:
     *  Constant: '<S37>/threshold high'
     *  Constant: '<S37>/threshold low'
     *  Inport: '<Root>/Susp_R_R_Bits'
     */
    if (Disconnections_U.Susp_R_R_Bits < 13.0) {
      /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem' incorporates:
       *  ActionPort: '<S66>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_kw);

      /* End of Outputs for SubSystem: '<S37>/If Action Subsystem' */
    } else if (Disconnections_U.Susp_R_R_Bits > 4110.0) {
      /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_kw);

      /* End of Outputs for SubSystem: '<S37>/If Action Subsystem1' */
    } else if (Disconnections_B.Merge_m == 1.0) {
      /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      Disconnection_IfActionSubsystem(&Disconnections_B.Merge_kw);

      /* End of Outputs for SubSystem: '<S37>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      Disconnectio_IfActionSubsystem3(&Disconnections_B.Merge_kw);

      /* End of Outputs for SubSystem: '<S37>/If Action Subsystem3' */
    }

    /* End of If: '<S37>/If' */
    /* End of Outputs for SubSystem: '<Root>/Sensor Disconnections (Noise)' */
  }

  /* End of If: '<Root>/If1' */

  /* Logic: '<Root>/OR3' */
  rtb_OR3 = ((Disconnections_B.Merge_ed != 0.0) || (Disconnections_B.Merge !=
              0.0) || (Disconnections_B.Merge_e != 0.0));

  /* Outport: '<Root>/Critical_Signal_Disconnection' */
  Disconnections_Y.Critical_Signal_Disconnection = rtb_OR3;

  /* Outport: '<Root>/CriticalDisconnection' incorporates:
   *  Logic: '<Root>/OR'
   */
  Disconnections_Y.CriticalDisconnection = (rtb_OR4 || rtb_OR3);

  /* Outport: '<Root>/Disconnection_SteeringSensor' */
  Disconnections_Y.Disconnection_SteeringSensor = Disconnections_B.Merge_d;

  /* Outport: '<Root>/Disconnection_Susp_F_L' */
  Disconnections_Y.Disconnection_Susp_F_L = Disconnections_B.Merge_n;

  /* Outport: '<Root>/Disconnection_Susp_F_R' */
  Disconnections_Y.Disconnection_Susp_F_R = Disconnections_B.Merge_k;

  /* Outport: '<Root>/Disconnection_Susp_R_L' */
  Disconnections_Y.Disconnection_Susp_R_L = Disconnections_B.Merge_p;

  /* Outport: '<Root>/Disconnection_Susp_R_R' */
  Disconnections_Y.Disconnection_Susp_R_R = Disconnections_B.Merge_kw;

  /* Outputs for IfAction SubSystem: '<S4>/Ellipse Vel NOT Valid' incorporates:
   *  ActionPort: '<S27>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S4>/Ellipse Vel Valid' incorporates:
   *  ActionPort: '<S28>/Action Port'
   */
  /* If: '<S4>/If' incorporates:
   *  Inport: '<Root>/el_Vel_OK'
   *  SignalConversion generated from: '<S27>/1'
   *  SignalConversion generated from: '<S28>/0'
   */
  rtb_Add = ((!(Disconnections_B.Merge_dt == 0.0)) ||
             (!(Disconnections_U.el_Vel_OK == 1.0)));

  /* End of Outputs for SubSystem: '<S4>/Ellipse Vel Valid' */
  /* End of Outputs for SubSystem: '<S4>/Ellipse Vel NOT Valid' */

  /* If: '<S6>/If3' incorporates:
   *  Logic: '<S6>/Logical Operator2'
   */
  if (!(Disconnections_B.Merge_d != 0.0)) {
    /* Outputs for IfAction SubSystem: '<S6>/Steering TV without TC 2024' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    /* SignalConversion generated from: '<S77>/3' incorporates:
     *  Constant: '<S77>/Constant'
     */
    rtb_Add_d = 3.0;

    /* End of Outputs for SubSystem: '<S6>/Steering TV without TC 2024' */
  } else {
    /* Outputs for IfAction SubSystem: '<S6>/Rigid Axle 2024' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    Disconnections_RigidAxle2024(&rtb_Add_d);

    /* End of Outputs for SubSystem: '<S6>/Rigid Axle 2024' */
  }

  /* End of If: '<S6>/If3' */

  /* If: '<S6>/If4' incorporates:
   *  Inport: '<Root>/Disconnection_InvL'
   *  Inport: '<Root>/Disconnection_InvR'
   *  Logic: '<Root>/OR1'
   */
  if (Disconnections_U.Disconnection_InvL || Disconnections_U.Disconnection_InvR)
  {
    /* Outputs for IfAction SubSystem: '<S6>/Rigid Axle One Inverter' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    Disconnections_RigidAxle2024(&rtb_Add);

    /* End of Outputs for SubSystem: '<S6>/Rigid Axle One Inverter' */
  } else {
    /* Logic: '<Root>/OR2' incorporates:
     *  Logic: '<S6>/Logical Operator1'
     */
    rtb_OR4 = !(rtb_Add != 0.0);

    /* If: '<S6>/If1' incorporates:
     *  If: '<S6>/If2'
     *  Logic: '<Root>/OR2'
     *  Logic: '<S6>/Logical Operator3'
     */
    if (rtb_OR4 && (!(Disconnections_B.Merge_d != 0.0))) {
      /* Outputs for IfAction SubSystem: '<S6>/Other SM' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S6>/TV & TC 2024' incorporates:
       *  ActionPort: '<S78>/Action Port'
       */
      /* SignalConversion generated from: '<S71>/4, 3, 2 or 1' incorporates:
       *  Constant: '<S78>/Constant'
       *  SignalConversion generated from: '<S78>/1'
       */
      rtb_Add = 1.0;

      /* End of Outputs for SubSystem: '<S6>/TV & TC 2024' */
      /* End of Outputs for SubSystem: '<S6>/Other SM' */
    } else if (rtb_OR4) {
      /* Outputs for IfAction SubSystem: '<S6>/Other SM' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S6>/Rigid Axle with TC 2024' incorporates:
       *  ActionPort: '<S76>/Action Port'
       */
      /* If: '<S6>/If2' incorporates:
       *  Constant: '<S76>/Constant'
       *  SignalConversion generated from: '<S71>/4, 3, 2 or 1'
       *  SignalConversion generated from: '<S76>/2'
       */
      rtb_Add = 2.0;

      /* End of Outputs for SubSystem: '<S6>/Rigid Axle with TC 2024' */
      /* End of Outputs for SubSystem: '<S6>/Other SM' */
    } else {
      /* Outputs for IfAction SubSystem: '<S6>/Other SM' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S6>/Others SM3+ ' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      /* If: '<S6>/If2' incorporates:
       *  SignalConversion generated from: '<S71>/4, 3, 2 or 1'
       *  SignalConversion generated from: '<S73>/4 or 3'
       */
      rtb_Add = rtb_Add_d;

      /* End of Outputs for SubSystem: '<S6>/Others SM3+ ' */
      /* End of Outputs for SubSystem: '<S6>/Other SM' */
    }

    /* End of If: '<S6>/If1' */
  }

  /* End of If: '<S6>/If4' */

  /* Outport: '<Root>/Disconnection_Mode' */
  Disconnections_Y.Disconnection_Mode = rtb_Add;

  /* Outport: '<Root>/Disconnection_APPS1' */
  Disconnections_Y.Disconnection_APPS1 = Disconnections_B.Merge;

  /* Outport: '<Root>/Disconnection_APPS2' */
  Disconnections_Y.Disconnection_APPS2 = Disconnections_B.Merge_e;

  /* Outport: '<Root>/Disconnection_BrakePedal' */
  Disconnections_Y.Disconnection_BrakePedal = Disconnections_B.Merge_ed;

  /* Outport: '<Root>/Disconnection_BMS' */
  Disconnections_Y.Disconnection_BMS = Disconnections_B.Merge_g;

  /* Outport: '<Root>/Disconnection_DashBoard' */
  Disconnections_Y.Disconnection_DashBoard = Disconnections_B.Merge_j;

  /* Outport: '<Root>/Disconnection_Front' */
  Disconnections_Y.Disconnection_Front = Disconnections_B.Merge_go;

  /* Outport: '<Root>/Disconnection_Rear' */
  Disconnections_Y.Disconnection_Rear = Disconnections_B.Merge_m;

  /* Outport: '<Root>/Disconnection_Ellipse' */
  Disconnections_Y.Disconnection_Ellipse = Disconnections_B.Merge_dt;
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

  /* Start for DataStoreMemory: '<S2>/Data Store Memory' */
  Disconnections_DW.A_o = 0.0;

  /* Start for IfAction SubSystem: '<Root>/ECU Disconections' */
  /* Start for DataStoreMemory: '<S14>/Data Store Memory' */
  Disconnections_DW.Last_alive = 0.0;

  /* Start for DataStoreMemory: '<S15>/Data Store Memory' */
  Disconnections_DW.Last_alive_p = 0.0;

  /* Start for DataStoreMemory: '<S12>/Data Store Memory' */
  Disconnections_DW.Last_alive_n = 0.0;

  /* Start for DataStoreMemory: '<S16>/Data Store Memory' */
  Disconnections_DW.Last_alive_pb = 0.0;

  /* Start for DataStoreMemory: '<S13>/Data Store Memory' */
  Disconnections_DW.Last_alive_n0 = 0.0;

  /* End of Start for SubSystem: '<Root>/ECU Disconections' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/ECU Disconections' */
  /* SystemInitialize for Merge: '<S14>/Merge' */
  Disconnections_B.Merge_g = 0.0;

  /* SystemInitialize for Merge: '<S15>/Merge' */
  Disconnections_B.Merge_j = 0.0;

  /* SystemInitialize for Merge: '<S12>/Merge' */
  Disconnections_B.Merge_go = 0.0;

  /* SystemInitialize for Merge: '<S16>/Merge' */
  Disconnections_B.Merge_dt = 0.0;

  /* SystemInitialize for Merge: '<S13>/Merge' */
  Disconnections_B.Merge_m = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/ECU Disconections' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/Sensor Disconnections (Noise)' */
  /* SystemInitialize for Merge: '<S30>/Merge' */
  Disconnections_B.Merge = 0.0;

  /* SystemInitialize for Merge: '<S31>/Merge' */
  Disconnections_B.Merge_e = 0.0;

  /* SystemInitialize for Merge: '<S32>/Merge' */
  Disconnections_B.Merge_ed = 0.0;

  /* SystemInitialize for Merge: '<S33>/Merge' */
  Disconnections_B.Merge_d = 0.0;

  /* SystemInitialize for Merge: '<S34>/Merge' */
  Disconnections_B.Merge_n = 0.0;

  /* SystemInitialize for Merge: '<S35>/Merge' */
  Disconnections_B.Merge_k = 0.0;

  /* SystemInitialize for Merge: '<S36>/Merge' */
  Disconnections_B.Merge_p = 0.0;

  /* SystemInitialize for Merge: '<S37>/Merge' */
  Disconnections_B.Merge_kw = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Sensor Disconnections (Noise)' */
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
  Disconnections_M->Sizes.numU = (16); /* Number of model inputs */
  Disconnections_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Disconnections_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Disconnections_M->Sizes.numBlocks = (190);/* Number of blocks */
  Disconnections_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  return Disconnections_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
