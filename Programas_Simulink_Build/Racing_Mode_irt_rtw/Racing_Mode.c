/*
 * Racing_Mode.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Racing_Mode".
 *
 * Model version              : 10.1
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Tue Mar 26 15:29:08 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Racing_Mode.h"
#include "rtwtypes.h"
#include "Racing_Mode_private.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Racing_Mode_T Racing_Mode_B;

/* External inputs (root inport signals with default storage) */
ExtU_Racing_Mode_T Racing_Mode_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Racing_Mode_T Racing_Mode_Y;

/* Real-time model */
static RT_MODEL_Racing_Mode_T Racing_Mode_M_;
RT_MODEL_Racing_Mode_T *const Racing_Mode_M = &Racing_Mode_M_;

/*
 * System initialize for action system:
 *    '<S2>/SKF_Initial'
 *    '<S2>/CKF_Initial'
 *    '<S2>/Cte_SKF'
 *    '<S2>/Cte_CKF'
 */
void Racing_Mode_SKF_Initial_Init(B_SKF_Initial_Racing_Mode_T *localB)
{
  /* SystemInitialize for Gain: '<S17>/Gain' incorporates:
   *  Outport: '<S17>/Out1'
   */
  localB->Gain = 0.0;
}

/*
 * Output and update for action system:
 *    '<S2>/SKF_Initial'
 *    '<S2>/CKF_Initial'
 *    '<S2>/Cte_SKF'
 *    '<S2>/Cte_CKF'
 */
void Racing_Mode_SKF_Initial(real_T rtu_In1, B_SKF_Initial_Racing_Mode_T *localB)
{
  /* Gain: '<S17>/Gain' */
  localB->Gain = 0.001 * rtu_In1;
}

/*
 * System initialize for action system:
 *    '<S2>/Apps_Sat_Dwn'
 *    '<S2>/Apps_Sat_Up'
 *    '<S2>/K_Reduction_P'
 *    '<S2>/K_Reduction_Temperature'
 */
void Racing_Mode_Apps_Sat_Dwn_Init(B_Apps_Sat_Dwn_Racing_Mode_T *localB)
{
  /* SystemInitialize for Gain: '<S8>/Gain' incorporates:
   *  Outport: '<S8>/Out1'
   */
  localB->Gain = 0.0;
}

/*
 * Output and update for action system:
 *    '<S2>/Apps_Sat_Dwn'
 *    '<S2>/Apps_Sat_Up'
 *    '<S2>/K_Reduction_P'
 *    '<S2>/K_Reduction_Temperature'
 */
void Racing_Mode_Apps_Sat_Dwn(real_T rtu_In1, B_Apps_Sat_Dwn_Racing_Mode_T
  *localB)
{
  /* Gain: '<S8>/Gain' */
  localB->Gain = 0.01 * rtu_In1;
}

/*
 * System initialize for action system:
 *    '<S2>/Max_Regenerative_Torque'
 *    '<S2>/Power_Limit'
 */
void Ra_Max_Regenerative_Torque_Init(B_Max_Regenerative_Torque_Rac_T *localB)
{
  /* SystemInitialize for SignalConversion generated from: '<S15>/In1' incorporates:
   *  Outport: '<S15>/Out1'
   */
  localB->In1 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S2>/Max_Regenerative_Torque'
 *    '<S2>/Power_Limit'
 */
void Racing__Max_Regenerative_Torque(real_T rtu_In1,
  B_Max_Regenerative_Torque_Rac_T *localB)
{
  /* SignalConversion generated from: '<S15>/In1' */
  localB->In1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S5>/Acceleration (2). Driver 2 (2) '
 *    '<S5>/Skidpad (3). Driver 2 (2)'
 *    '<S5>/AutoX (4). Driver 2 (2)'
 *    '<S5>/Endurance (5). Driver 2 (2)'
 */
void Racing_Mo_Acceleration2Driver22(real_T rty_Params[10])
{
  /* SignalConversion generated from: '<S22>/Params' incorporates:
   *  Constant: '<S22>/Apps_Sat_Dwn'
   *  Constant: '<S22>/Apps_Sat_Up'
   *  Constant: '<S22>/CKF_Initial'
   *  Constant: '<S22>/Cte_CKF'
   *  Constant: '<S22>/Cte_SKF'
   *  Constant: '<S22>/K_Reduction_P'
   *  Constant: '<S22>/K_Reduction_Temperature'
   *  Constant: '<S22>/Max_Regenerative_Torque'
   *  Constant: '<S22>/Power_Limit'
   *  Constant: '<S22>/SKF_Initial'
   */
  rty_Params[0] = 0.5;
  rty_Params[1] = 0.4;
  rty_Params[2] = 0.98;
  rty_Params[3] = 0.98;
  rty_Params[4] = 0.0;
  rty_Params[5] = 1.0;
  rty_Params[6] = 1000.0;
  rty_Params[7] = 80.0;
  rty_Params[8] = 0.2;
  rty_Params[9] = 0.6;
}

/* Model output function */
static void Racing_Mode_output(void)
{
  /* SwitchCase: '<Root>/Selecció de Mode' incorporates:
   *  Inport: '<Root>/RacingMode'
   */
  switch (Racing_Mode_U.RacingMode) {
   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Workshop Test (01)' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S7>/Apps_Sat_Dwn'
     *  Constant: '<S7>/Apps_Sat_Up'
     *  Constant: '<S7>/CKF_Initial'
     *  Constant: '<S7>/Cte_CKF'
     *  Constant: '<S7>/Cte_SKF'
     *  Constant: '<S7>/K_Reduction_P'
     *  Constant: '<S7>/K_Reduction_Temperature'
     *  Constant: '<S7>/Max_Regenerative_Torque'
     *  Constant: '<S7>/Power_Limit'
     *  Constant: '<S7>/SKF_Initial'
     *  SignalConversion generated from: '<S7>/Params'
     */
    Racing_Mode_B.Merge[0] = 0.9;
    Racing_Mode_B.Merge[1] = 0.9;
    Racing_Mode_B.Merge[2] = 0.98;
    Racing_Mode_B.Merge[3] = 0.98;
    Racing_Mode_B.Merge[4] = 0.2;
    Racing_Mode_B.Merge[5] = 0.8;
    Racing_Mode_B.Merge[6] = 10.0;
    Racing_Mode_B.Merge[7] = 1.0;
    Racing_Mode_B.Merge[8] = 0.5;
    Racing_Mode_B.Merge[9] = 0.6;

    /* End of Outputs for SubSystem: '<Root>/Workshop Test (01)' */
    break;

   case 11:
    {
      real_T tmp;

      /* Outputs for IfAction SubSystem: '<Root>/Custom Dash (11)' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* SwitchCase: '<S2>/Switch Case' incorporates:
       *  Inport: '<Root>/CustomMode_Data'
       *  Inport: '<Root>/CustomMode_Identifier'
       */
      tmp = trunc(Racing_Mode_U.CustomMode_Identifier);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
       case 1:
        /* Outputs for IfAction SubSystem: '<S2>/SKF_Initial' incorporates:
         *  ActionPort: '<S17>/Action Port'
         */
        Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.SKF_Initial_g);

        /* End of Outputs for SubSystem: '<S2>/SKF_Initial' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S2>/CKF_Initial' incorporates:
         *  ActionPort: '<S10>/Action Port'
         */
        Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.CKF_Initial_p);

        /* End of Outputs for SubSystem: '<S2>/CKF_Initial' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S2>/Cte_SKF' incorporates:
         *  ActionPort: '<S12>/Action Port'
         */
        Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.Cte_SKF_d);

        /* End of Outputs for SubSystem: '<S2>/Cte_SKF' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S2>/Cte_CKF' incorporates:
         *  ActionPort: '<S11>/Action Port'
         */
        Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.Cte_CKF_o);

        /* End of Outputs for SubSystem: '<S2>/Cte_CKF' */
        break;

       case 5:
        /* Outputs for IfAction SubSystem: '<S2>/Apps_Sat_Dwn' incorporates:
         *  ActionPort: '<S8>/Action Port'
         */
        Racing_Mode_Apps_Sat_Dwn(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.Apps_Sat_Dwn_k);

        /* End of Outputs for SubSystem: '<S2>/Apps_Sat_Dwn' */
        break;

       case 6:
        /* Outputs for IfAction SubSystem: '<S2>/Apps_Sat_Up' incorporates:
         *  ActionPort: '<S9>/Action Port'
         */
        Racing_Mode_Apps_Sat_Dwn(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.Apps_Sat_Up_p);

        /* End of Outputs for SubSystem: '<S2>/Apps_Sat_Up' */
        break;

       case 7:
        /* Outputs for IfAction SubSystem: '<S2>/Max_Regenerative_Torque' incorporates:
         *  ActionPort: '<S15>/Action Port'
         */
        Racing__Max_Regenerative_Torque(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.Max_Regenerative_Torque_e);

        /* End of Outputs for SubSystem: '<S2>/Max_Regenerative_Torque' */
        break;

       case 8:
        /* Outputs for IfAction SubSystem: '<S2>/Power_Limit' incorporates:
         *  ActionPort: '<S16>/Action Port'
         */
        Racing__Max_Regenerative_Torque(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.Power_Limit_g);

        /* End of Outputs for SubSystem: '<S2>/Power_Limit' */
        break;

       case 9:
        /* Outputs for IfAction SubSystem: '<S2>/K_Reduction_P' incorporates:
         *  ActionPort: '<S13>/Action Port'
         */
        Racing_Mode_Apps_Sat_Dwn(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.K_Reduction_P_g);

        /* End of Outputs for SubSystem: '<S2>/K_Reduction_P' */
        break;

       case 10:
        /* Outputs for IfAction SubSystem: '<S2>/K_Reduction_Temperature' incorporates:
         *  ActionPort: '<S14>/Action Port'
         */
        Racing_Mode_Apps_Sat_Dwn(Racing_Mode_U.CustomMode_Data,
          &Racing_Mode_B.K_Reduction_Temperature_h);

        /* End of Outputs for SubSystem: '<S2>/K_Reduction_Temperature' */
        break;
      }

      /* End of SwitchCase: '<S2>/Switch Case' */

      /* Merge: '<Root>/Merge' incorporates:
       *  SignalConversion generated from: '<S2>/Params'
       */
      Racing_Mode_B.Merge[0] = Racing_Mode_B.SKF_Initial_g.Gain;
      Racing_Mode_B.Merge[1] = Racing_Mode_B.CKF_Initial_p.Gain;
      Racing_Mode_B.Merge[2] = Racing_Mode_B.Cte_SKF_d.Gain;
      Racing_Mode_B.Merge[3] = Racing_Mode_B.Cte_CKF_o.Gain;
      Racing_Mode_B.Merge[4] = Racing_Mode_B.Apps_Sat_Dwn_k.Gain;
      Racing_Mode_B.Merge[5] = Racing_Mode_B.Apps_Sat_Up_p.Gain;
      Racing_Mode_B.Merge[6] = Racing_Mode_B.Max_Regenerative_Torque_e.In1;
      Racing_Mode_B.Merge[7] = Racing_Mode_B.Power_Limit_g.In1;
      Racing_Mode_B.Merge[8] = Racing_Mode_B.K_Reduction_P_g.Gain;
      Racing_Mode_B.Merge[9] = Racing_Mode_B.K_Reduction_Temperature_h.Gain;

      /* End of Outputs for SubSystem: '<Root>/Custom Dash (11)' */
    }
    break;

   case 12:
    /* Outputs for IfAction SubSystem: '<Root>/Custom Experiment Environment (12)' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* SignalConversion generated from: '<S3>/Apps_Sat_Dwn' incorporates:
     *  Constant: '<S6>/CEE_Apps_Sat_Dwn'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[4] = 0.0;

    /* SignalConversion generated from: '<S3>/Apps_Sat_Up' incorporates:
     *  Constant: '<S6>/CEE_Apps_Sat_Up'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[5] = 0.0;

    /* SignalConversion generated from: '<S3>/CKF_Initial' incorporates:
     *  Constant: '<S6>/CEE_CKF_Initial'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[1] = 0.0;

    /* SignalConversion generated from: '<S3>/Cte_CKF' incorporates:
     *  Constant: '<S6>/CEE_Cte_CKF'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[3] = 0.0;

    /* SignalConversion generated from: '<S3>/Cte_SKF' incorporates:
     *  Constant: '<S6>/CEE_Cte_SKF'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[2] = 0.0;

    /* SignalConversion generated from: '<S3>/K_Reduction_P' incorporates:
     *  Constant: '<S6>/CEE_K_Reduction_P'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[8] = 0.0;

    /* SignalConversion generated from: '<S3>/K_Reduction_Temperature' incorporates:
     *  Constant: '<S6>/CEE_K_Reduction_Temperature'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[9] = 0.0;

    /* SignalConversion generated from: '<S3>/Max_Regenerative_Torque' incorporates:
     *  Constant: '<S6>/CEE_Max_Regenerative_Torque'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[6] = 0.0;

    /* SignalConversion generated from: '<S3>/Power_Limit' incorporates:
     *  Constant: '<S6>/CEE_Power_Limit'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[7] = 0.0;

    /* SignalConversion generated from: '<S3>/SKF_Initial' incorporates:
     *  Constant: '<S6>/CEE_SKF_Initial'
     *  Merge: '<Root>/Merge'
     */
    Racing_Mode_B.Merge[0] = 0.0;

    /* End of Outputs for SubSystem: '<Root>/Custom Experiment Environment (12)' */
    break;

   case 21:
   case 31:
   case 41:
   case 51:
    /* Outputs for IfAction SubSystem: '<Root>/Driver 1 Modes (21,31,41,51)' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* SwitchCase: '<S4>/Selecció de Mode' */
    switch (Racing_Mode_U.RacingMode) {
     case 21:
      /* Outputs for IfAction SubSystem: '<S4>/Acceleration (2). Driver 1 (1) ' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<S18>/Apps_Sat_Dwn'
       *  Constant: '<S18>/Apps_Sat_Up'
       *  Constant: '<S18>/CKF_Initial'
       *  Constant: '<S18>/Cte_CKF'
       *  Constant: '<S18>/Cte_SKF'
       *  Constant: '<S18>/K_Reduction_P'
       *  Constant: '<S18>/K_Reduction_Temperature'
       *  Constant: '<S18>/Max_Regenerative_Torque'
       *  Constant: '<S18>/Power_Limit'
       *  Constant: '<S18>/SKF_Initial'
       *  SignalConversion generated from: '<S18>/Params'
       */
      Racing_Mode_B.Merge[0] = 1.0;
      Racing_Mode_B.Merge[1] = 1.0;
      Racing_Mode_B.Merge[2] = 0.93;
      Racing_Mode_B.Merge[3] = 0.93;
      Racing_Mode_B.Merge[4] = 0.0;
      Racing_Mode_B.Merge[5] = 1.0;
      Racing_Mode_B.Merge[6] = 140.0;
      Racing_Mode_B.Merge[7] = 80.0;
      Racing_Mode_B.Merge[8] = 0.2;
      Racing_Mode_B.Merge[9] = 0.6;

      /* End of Outputs for SubSystem: '<S4>/Acceleration (2). Driver 1 (1) ' */
      break;

     case 31:
      /* Outputs for IfAction SubSystem: '<S4>/Skidpad (3). Driver 1 (1)' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<S21>/Apps_Sat_Dwn'
       *  Constant: '<S21>/Apps_Sat_Up'
       *  Constant: '<S21>/CKF_Initial'
       *  Constant: '<S21>/Cte_CKF'
       *  Constant: '<S21>/Cte_SKF'
       *  Constant: '<S21>/K_Reduction_P'
       *  Constant: '<S21>/K_Reduction_Temperature'
       *  Constant: '<S21>/Max_Regenerative_Torque'
       *  Constant: '<S21>/Power_Limit'
       *  Constant: '<S21>/SKF_Initial'
       *  SignalConversion generated from: '<S21>/Params'
       */
      Racing_Mode_B.Merge[0] = 1.0;
      Racing_Mode_B.Merge[1] = 1.0;
      Racing_Mode_B.Merge[2] = 0.97;
      Racing_Mode_B.Merge[3] = 0.97;
      Racing_Mode_B.Merge[4] = 0.0;
      Racing_Mode_B.Merge[5] = 1.0;
      Racing_Mode_B.Merge[6] = 140.0;
      Racing_Mode_B.Merge[7] = 80.0;
      Racing_Mode_B.Merge[8] = 0.2;
      Racing_Mode_B.Merge[9] = 0.6;

      /* End of Outputs for SubSystem: '<S4>/Skidpad (3). Driver 1 (1)' */
      break;

     case 41:
      /* Outputs for IfAction SubSystem: '<S4>/AutoX (4). Driver 1 (1)' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<S19>/Apps_Sat_Dwn'
       *  Constant: '<S19>/Apps_Sat_Up'
       *  Constant: '<S19>/CKF_Initial'
       *  Constant: '<S19>/Cte_CKF'
       *  Constant: '<S19>/Cte_SKF'
       *  Constant: '<S19>/K_Reduction_P'
       *  Constant: '<S19>/K_Reduction_Temperature'
       *  Constant: '<S19>/Max_Regenerative_Torque'
       *  Constant: '<S19>/Power_Limit'
       *  Constant: '<S19>/SKF_Initial'
       *  SignalConversion generated from: '<S19>/Params'
       */
      Racing_Mode_B.Merge[0] = 0.6;
      Racing_Mode_B.Merge[1] = 0.6;
      Racing_Mode_B.Merge[2] = 0.98;
      Racing_Mode_B.Merge[3] = 0.98;
      Racing_Mode_B.Merge[4] = 0.0;
      Racing_Mode_B.Merge[5] = 1.0;
      Racing_Mode_B.Merge[6] = 1000.0;
      Racing_Mode_B.Merge[7] = 80.0;
      Racing_Mode_B.Merge[8] = 0.2;
      Racing_Mode_B.Merge[9] = 0.6;

      /* End of Outputs for SubSystem: '<S4>/AutoX (4). Driver 1 (1)' */
      break;

     case 51:
      /* Outputs for IfAction SubSystem: '<S4>/Endurance (5). Driver 1 (1)' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<S20>/Apps_Sat_Dwn'
       *  Constant: '<S20>/Apps_Sat_Up'
       *  Constant: '<S20>/CKF_Initial'
       *  Constant: '<S20>/Cte_CKF'
       *  Constant: '<S20>/Cte_SKF'
       *  Constant: '<S20>/K_Reduction_P'
       *  Constant: '<S20>/K_Reduction_Temperature'
       *  Constant: '<S20>/Max_Regenerative_Torque'
       *  Constant: '<S20>/Power_Limit'
       *  Constant: '<S20>/SKF_Initial'
       *  SignalConversion generated from: '<S20>/Params'
       */
      Racing_Mode_B.Merge[0] = 0.4;
      Racing_Mode_B.Merge[1] = 0.4;
      Racing_Mode_B.Merge[2] = 0.98;
      Racing_Mode_B.Merge[3] = 0.98;
      Racing_Mode_B.Merge[4] = 0.0;
      Racing_Mode_B.Merge[5] = 1.0;
      Racing_Mode_B.Merge[6] = 1000.0;
      Racing_Mode_B.Merge[7] = 80.0;
      Racing_Mode_B.Merge[8] = 0.2;
      Racing_Mode_B.Merge[9] = 0.6;

      /* End of Outputs for SubSystem: '<S4>/Endurance (5). Driver 1 (1)' */
      break;
    }

    /* End of SwitchCase: '<S4>/Selecció de Mode' */
    /* End of Outputs for SubSystem: '<Root>/Driver 1 Modes (21,31,41,51)' */
    break;

   case 22:
   case 32:
   case 42:
   case 52:
    /* Outputs for IfAction SubSystem: '<Root>/Driver 2 Modes (22,32,42,52)' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* SwitchCase: '<S5>/Selecció de Mode' */
    switch (Racing_Mode_U.RacingMode) {
     case 22:
      /* Outputs for IfAction SubSystem: '<S5>/Acceleration (2). Driver 2 (2) ' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      Racing_Mo_Acceleration2Driver22(Racing_Mode_B.Merge);

      /* End of Outputs for SubSystem: '<S5>/Acceleration (2). Driver 2 (2) ' */
      break;

     case 32:
      /* Outputs for IfAction SubSystem: '<S5>/Skidpad (3). Driver 2 (2)' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      Racing_Mo_Acceleration2Driver22(Racing_Mode_B.Merge);

      /* End of Outputs for SubSystem: '<S5>/Skidpad (3). Driver 2 (2)' */
      break;

     case 42:
      /* Outputs for IfAction SubSystem: '<S5>/AutoX (4). Driver 2 (2)' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      Racing_Mo_Acceleration2Driver22(Racing_Mode_B.Merge);

      /* End of Outputs for SubSystem: '<S5>/AutoX (4). Driver 2 (2)' */
      break;

     case 52:
      /* Outputs for IfAction SubSystem: '<S5>/Endurance (5). Driver 2 (2)' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      Racing_Mo_Acceleration2Driver22(Racing_Mode_B.Merge);

      /* End of Outputs for SubSystem: '<S5>/Endurance (5). Driver 2 (2)' */
      break;
    }

    /* End of SwitchCase: '<S5>/Selecció de Mode' */
    /* End of Outputs for SubSystem: '<Root>/Driver 2 Modes (22,32,42,52)' */
    break;
  }

  /* End of SwitchCase: '<Root>/Selecció de Mode' */

  /* Saturate: '<Root>/SKF_Initial Saturation' */
  if (Racing_Mode_B.Merge[0] > 0.9) {
    /* Outport: '<Root>/VDC_SKF_Initial' */
    Racing_Mode_Y.VDC_SKF_Initial = 0.9;
  } else if (Racing_Mode_B.Merge[0] < 0.0) {
    /* Outport: '<Root>/VDC_SKF_Initial' */
    Racing_Mode_Y.VDC_SKF_Initial = 0.0;
  } else {
    /* Outport: '<Root>/VDC_SKF_Initial' */
    Racing_Mode_Y.VDC_SKF_Initial = Racing_Mode_B.Merge[0];
  }

  /* End of Saturate: '<Root>/SKF_Initial Saturation' */

  /* Saturate: '<Root>/CKF_Initial Saturation' */
  if (Racing_Mode_B.Merge[1] > 0.9) {
    /* Outport: '<Root>/VDC_CKF_Initial' */
    Racing_Mode_Y.VDC_CKF_Initial = 0.9;
  } else if (Racing_Mode_B.Merge[1] < 0.0) {
    /* Outport: '<Root>/VDC_CKF_Initial' */
    Racing_Mode_Y.VDC_CKF_Initial = 0.0;
  } else {
    /* Outport: '<Root>/VDC_CKF_Initial' */
    Racing_Mode_Y.VDC_CKF_Initial = Racing_Mode_B.Merge[1];
  }

  /* End of Saturate: '<Root>/CKF_Initial Saturation' */

  /* Saturate: '<Root>/Cte_SKF Saturation' */
  if (Racing_Mode_B.Merge[2] > 1.0) {
    /* Outport: '<Root>/VDC_Cte_SKF' */
    Racing_Mode_Y.VDC_Cte_SKF = 1.0;
  } else if (Racing_Mode_B.Merge[2] < 0.0) {
    /* Outport: '<Root>/VDC_Cte_SKF' */
    Racing_Mode_Y.VDC_Cte_SKF = 0.0;
  } else {
    /* Outport: '<Root>/VDC_Cte_SKF' */
    Racing_Mode_Y.VDC_Cte_SKF = Racing_Mode_B.Merge[2];
  }

  /* End of Saturate: '<Root>/Cte_SKF Saturation' */

  /* Saturate: '<Root>/Cte_CKF Saturation' */
  if (Racing_Mode_B.Merge[3] > 1.0) {
    /* Outport: '<Root>/VDC_Cte_CKF' */
    Racing_Mode_Y.VDC_Cte_CKF = 1.0;
  } else if (Racing_Mode_B.Merge[3] < 0.0) {
    /* Outport: '<Root>/VDC_Cte_CKF' */
    Racing_Mode_Y.VDC_Cte_CKF = 0.0;
  } else {
    /* Outport: '<Root>/VDC_Cte_CKF' */
    Racing_Mode_Y.VDC_Cte_CKF = Racing_Mode_B.Merge[3];
  }

  /* End of Saturate: '<Root>/Cte_CKF Saturation' */

  /* Saturate: '<Root>/Apps_Sat_Dwn Saturation' */
  if (Racing_Mode_B.Merge[4] > 0.5) {
    /* Outport: '<Root>/VDC_Apps_Sat_Down' */
    Racing_Mode_Y.VDC_Apps_Sat_Down = 0.5;
  } else if (Racing_Mode_B.Merge[4] < 0.0) {
    /* Outport: '<Root>/VDC_Apps_Sat_Down' */
    Racing_Mode_Y.VDC_Apps_Sat_Down = 0.0;
  } else {
    /* Outport: '<Root>/VDC_Apps_Sat_Down' */
    Racing_Mode_Y.VDC_Apps_Sat_Down = Racing_Mode_B.Merge[4];
  }

  /* End of Saturate: '<Root>/Apps_Sat_Dwn Saturation' */

  /* Saturate: '<Root>/Apps_Sat_Up Saturation' */
  if (Racing_Mode_B.Merge[5] > 1.0) {
    /* Outport: '<Root>/VDC_Apps_Sat_Up' */
    Racing_Mode_Y.VDC_Apps_Sat_Up = 1.0;
  } else if (Racing_Mode_B.Merge[5] < 0.0) {
    /* Outport: '<Root>/VDC_Apps_Sat_Up' */
    Racing_Mode_Y.VDC_Apps_Sat_Up = 0.0;
  } else {
    /* Outport: '<Root>/VDC_Apps_Sat_Up' */
    Racing_Mode_Y.VDC_Apps_Sat_Up = Racing_Mode_B.Merge[5];
  }

  /* End of Saturate: '<Root>/Apps_Sat_Up Saturation' */

  /* Saturate: '<Root>/Max_Regenerative_Torque Saturation' */
  if (Racing_Mode_B.Merge[6] > 10.0) {
    /* Outport: '<Root>/VDC_Max_Regen_Motor_Tq' */
    Racing_Mode_Y.VDC_Max_Regen_Motor_Tq = 10.0;
  } else if (Racing_Mode_B.Merge[6] < 0.0) {
    /* Outport: '<Root>/VDC_Max_Regen_Motor_Tq' */
    Racing_Mode_Y.VDC_Max_Regen_Motor_Tq = 0.0;
  } else {
    /* Outport: '<Root>/VDC_Max_Regen_Motor_Tq' */
    Racing_Mode_Y.VDC_Max_Regen_Motor_Tq = Racing_Mode_B.Merge[6];
  }

  /* End of Saturate: '<Root>/Max_Regenerative_Torque Saturation' */

  /* Saturate: '<Root>/Power_Limit Saturation' */
  if (Racing_Mode_B.Merge[7] > 77.0) {
    /* Outport: '<Root>/VDC_Power_Limit' */
    Racing_Mode_Y.VDC_Power_Limit = 77.0;
  } else if (Racing_Mode_B.Merge[7] < 0.0) {
    /* Outport: '<Root>/VDC_Power_Limit' */
    Racing_Mode_Y.VDC_Power_Limit = 0.0;
  } else {
    /* Outport: '<Root>/VDC_Power_Limit' */
    Racing_Mode_Y.VDC_Power_Limit = Racing_Mode_B.Merge[7];
  }

  /* End of Saturate: '<Root>/Power_Limit Saturation' */

  /* Saturate: '<Root>/K_Reduction_P Saturation' */
  if (Racing_Mode_B.Merge[8] > 1.0) {
    /* Outport: '<Root>/VDC_K_Reduction_P' */
    Racing_Mode_Y.VDC_K_Reduction_P = 1.0;
  } else if (Racing_Mode_B.Merge[8] < 0.0) {
    /* Outport: '<Root>/VDC_K_Reduction_P' */
    Racing_Mode_Y.VDC_K_Reduction_P = 0.0;
  } else {
    /* Outport: '<Root>/VDC_K_Reduction_P' */
    Racing_Mode_Y.VDC_K_Reduction_P = Racing_Mode_B.Merge[8];
  }

  /* End of Saturate: '<Root>/K_Reduction_P Saturation' */

  /* Saturate: '<Root>/K_Reduction_Temperature Saturation' */
  if (Racing_Mode_B.Merge[9] > 1.0) {
    /* Outport: '<Root>/VDC_K_Reduction_Temperature' */
    Racing_Mode_Y.VDC_K_Reduction_Temperature = 1.0;
  } else if (Racing_Mode_B.Merge[9] < 0.0) {
    /* Outport: '<Root>/VDC_K_Reduction_Temperature' */
    Racing_Mode_Y.VDC_K_Reduction_Temperature = 0.0;
  } else {
    /* Outport: '<Root>/VDC_K_Reduction_Temperature' */
    Racing_Mode_Y.VDC_K_Reduction_Temperature = Racing_Mode_B.Merge[9];
  }

  /* End of Saturate: '<Root>/K_Reduction_Temperature Saturation' */

  /* Outport: '<Root>/Workshop_Mode_Enable' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/RacingMode'
   *  RelationalOperator: '<S1>/Compare'
   */
  Racing_Mode_Y.Workshop_Mode_Enable = (Racing_Mode_U.RacingMode == 1);
}

/* Model update function */
static void Racing_Mode_update(void)
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
  if (!(++Racing_Mode_M->Timing.clockTick0)) {
    ++Racing_Mode_M->Timing.clockTickH0;
  }

  Racing_Mode_M->Timing.t[0] = Racing_Mode_M->Timing.clockTick0 *
    Racing_Mode_M->Timing.stepSize0 + Racing_Mode_M->Timing.clockTickH0 *
    Racing_Mode_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Racing_Mode_initialize(void)
{
  /* SystemInitialize for IfAction SubSystem: '<Root>/Custom Dash (11)' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/SKF_Initial' */
  Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.SKF_Initial_g);

  /* End of SystemInitialize for SubSystem: '<S2>/SKF_Initial' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/CKF_Initial' */
  Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.CKF_Initial_p);

  /* End of SystemInitialize for SubSystem: '<S2>/CKF_Initial' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/Cte_SKF' */
  Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.Cte_SKF_d);

  /* End of SystemInitialize for SubSystem: '<S2>/Cte_SKF' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/Cte_CKF' */
  Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.Cte_CKF_o);

  /* End of SystemInitialize for SubSystem: '<S2>/Cte_CKF' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/Apps_Sat_Dwn' */
  Racing_Mode_Apps_Sat_Dwn_Init(&Racing_Mode_B.Apps_Sat_Dwn_k);

  /* End of SystemInitialize for SubSystem: '<S2>/Apps_Sat_Dwn' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/Apps_Sat_Up' */
  Racing_Mode_Apps_Sat_Dwn_Init(&Racing_Mode_B.Apps_Sat_Up_p);

  /* End of SystemInitialize for SubSystem: '<S2>/Apps_Sat_Up' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/Max_Regenerative_Torque' */
  Ra_Max_Regenerative_Torque_Init(&Racing_Mode_B.Max_Regenerative_Torque_e);

  /* End of SystemInitialize for SubSystem: '<S2>/Max_Regenerative_Torque' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/Power_Limit' */
  Ra_Max_Regenerative_Torque_Init(&Racing_Mode_B.Power_Limit_g);

  /* End of SystemInitialize for SubSystem: '<S2>/Power_Limit' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/K_Reduction_P' */
  Racing_Mode_Apps_Sat_Dwn_Init(&Racing_Mode_B.K_Reduction_P_g);

  /* End of SystemInitialize for SubSystem: '<S2>/K_Reduction_P' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/K_Reduction_Temperature' */
  Racing_Mode_Apps_Sat_Dwn_Init(&Racing_Mode_B.K_Reduction_Temperature_h);

  /* End of SystemInitialize for SubSystem: '<S2>/K_Reduction_Temperature' */
  /* End of SystemInitialize for SubSystem: '<Root>/Custom Dash (11)' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  memset(&Racing_Mode_B.Merge[0], 0, 10U * sizeof(real_T));
}

/* Model terminate function */
static void Racing_Mode_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Racing_Mode_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Racing_Mode_update();
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
  Racing_Mode_initialize();
}

void MdlTerminate(void)
{
  Racing_Mode_terminate();
}

/* Registration function */
RT_MODEL_Racing_Mode_T *Racing_Mode(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Racing_Mode_M, 0,
                sizeof(RT_MODEL_Racing_Mode_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Racing_Mode_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Racing_Mode_M points to
       static memory which is guaranteed to be non-NULL" */
    Racing_Mode_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Racing_Mode_M->Timing.sampleTimes = (&Racing_Mode_M->
      Timing.sampleTimesArray[0]);
    Racing_Mode_M->Timing.offsetTimes = (&Racing_Mode_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    Racing_Mode_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    Racing_Mode_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Racing_Mode_M, &Racing_Mode_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Racing_Mode_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Racing_Mode_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Racing_Mode_M, 10.0);
  Racing_Mode_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Racing_Mode_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Racing_Mode_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Racing_Mode_M->rtwLogInfo, (NULL));
    rtliSetLogT(Racing_Mode_M->rtwLogInfo, "tout");
    rtliSetLogX(Racing_Mode_M->rtwLogInfo, "");
    rtliSetLogXFinal(Racing_Mode_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Racing_Mode_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Racing_Mode_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Racing_Mode_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Racing_Mode_M->rtwLogInfo, 1);
    rtliSetLogY(Racing_Mode_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Racing_Mode_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Racing_Mode_M->rtwLogInfo, (NULL));
  }

  Racing_Mode_M->solverInfoPtr = (&Racing_Mode_M->solverInfo);
  Racing_Mode_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Racing_Mode_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Racing_Mode_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Racing_Mode_M->blockIO = ((void *) &Racing_Mode_B);
  (void) memset(((void *) &Racing_Mode_B), 0,
                sizeof(B_Racing_Mode_T));

  /* external inputs */
  Racing_Mode_M->inputs = (((void*)&Racing_Mode_U));
  (void)memset(&Racing_Mode_U, 0, sizeof(ExtU_Racing_Mode_T));

  /* external outputs */
  Racing_Mode_M->outputs = (&Racing_Mode_Y);
  (void)memset(&Racing_Mode_Y, 0, sizeof(ExtY_Racing_Mode_T));

  /* Initialize Sizes */
  Racing_Mode_M->Sizes.numContStates = (0);/* Number of continuous states */
  Racing_Mode_M->Sizes.numY = (11);    /* Number of model outputs */
  Racing_Mode_M->Sizes.numU = (3);     /* Number of model inputs */
  Racing_Mode_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Racing_Mode_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Racing_Mode_M->Sizes.numBlocks = (143);/* Number of blocks */
  Racing_Mode_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  return Racing_Mode_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
