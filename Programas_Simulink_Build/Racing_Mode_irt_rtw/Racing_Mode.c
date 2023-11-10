/*
 * Racing_Mode.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Racing_Mode".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Nov 10 02:58:26 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Racing_Mode.h"
#include "Racing_Mode_private.h"

/* Block signals (auto storage) */
B_Racing_Mode_T Racing_Mode_B;

/* External inputs (root inport signals with auto storage) */
ExtU_Racing_Mode_T Racing_Mode_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Racing_Mode_T Racing_Mode_Y;

/* Real-time model */
RT_MODEL_Racing_Mode_T Racing_Mode_M_;
RT_MODEL_Racing_Mode_T *const Racing_Mode_M = &Racing_Mode_M_;

/*
 * Output and update for action system:
 *    '<Root>/Workshop Test (01)'
 *    '<S4>/Acceleration (2). Driver 1 (1) '
 *    '<S4>/Skidpad (3). Driver 1 (1)'
 *    '<S4>/AutoX (4). Driver 1 (1)'
 *    '<S4>/Endurance (5). Driver 1 (1)'
 *    '<S5>/Acceleration (2). Driver 2 (2) '
 *    '<S5>/Skidpad (3). Driver 2 (2)'
 *    '<S5>/AutoX (4). Driver 2 (2)'
 *    '<S5>/Endurance (5). Driver 2 (2)'
 */
void Racing_Mode_WorkshopTest01(real_T rty_Params[10],
  P_WorkshopTest01_Racing_Mode_T *localP)
{
  /* SignalConversion: '<S7>/OutportBufferForParams' incorporates:
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
   */
  rty_Params[0] = localP->SKF_Initial_Value;
  rty_Params[1] = localP->CKF_Initial_Value;
  rty_Params[2] = localP->Cte_SKF_Value;
  rty_Params[3] = localP->Cte_CKF_Value;
  rty_Params[4] = localP->Apps_Sat_Dwn_Value;
  rty_Params[5] = localP->Apps_Sat_Up_Value;
  rty_Params[6] = localP->Max_Regenerative_Torque_Value;
  rty_Params[7] = localP->Power_Limit_Value;
  rty_Params[8] = localP->K_Reduction_P_Value;
  rty_Params[9] = localP->K_Reduction_Temperature_Value;
}

/*
 * System initialize for action system:
 *    '<S2>/SKF_Initial'
 *    '<S2>/CKF_Initial'
 *    '<S2>/Cte_SKF'
 *    '<S2>/Cte_CKF'
 *    '<S2>/Apps_Sat_Dwn'
 *    '<S2>/Apps_Sat_Up'
 *    '<S2>/K_Reduction_P'
 *    '<S2>/K_Reduction_Temperature'
 */
void Racing_Mode_SKF_Initial_Init(B_SKF_Initial_Racing_Mode_T *localB,
  P_SKF_Initial_Racing_Mode_T *localP)
{
  /* SystemInitialize for Outport: '<S17>/Out1' */
  localB->Gain = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<S2>/SKF_Initial'
 *    '<S2>/CKF_Initial'
 *    '<S2>/Cte_SKF'
 *    '<S2>/Cte_CKF'
 *    '<S2>/Apps_Sat_Dwn'
 *    '<S2>/Apps_Sat_Up'
 *    '<S2>/K_Reduction_P'
 *    '<S2>/K_Reduction_Temperature'
 */
void Racing_Mode_SKF_Initial(real_T rtu_In1, B_SKF_Initial_Racing_Mode_T *localB,
  P_SKF_Initial_Racing_Mode_T *localP)
{
  /* Gain: '<S17>/Gain' */
  localB->Gain = localP->Gain_Gain * rtu_In1;
}

/*
 * System initialize for action system:
 *    '<S2>/Max_Regenerative_Torque'
 *    '<S2>/Power_Limit'
 */
void Ra_Max_Regenerative_Torque_Init(B_Max_Regenerative_Torque_Rac_T *localB,
  P_Max_Regenerative_Torque_Rac_T *localP)
{
  /* SystemInitialize for Outport: '<S15>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<S2>/Max_Regenerative_Torque'
 *    '<S2>/Power_Limit'
 */
void Racing__Max_Regenerative_Torque(real_T rtu_In1,
  B_Max_Regenerative_Torque_Rac_T *localB)
{
  /* Inport: '<S15>/In1' */
  localB->In1 = rtu_In1;
}

/* Model output function */
static void Racing_Mode_output(void)
{
  real_T tmp;

  /* SwitchCase: '<Root>/Selecció de Mode' incorporates:
   *  Constant: '<S6>/CEE_Apps_Sat_Dwn'
   *  Constant: '<S6>/CEE_Apps_Sat_Up'
   *  Constant: '<S6>/CEE_CKF_Initial'
   *  Constant: '<S6>/CEE_Cte_CKF'
   *  Constant: '<S6>/CEE_Cte_SKF'
   *  Constant: '<S6>/CEE_K_Reduction_P'
   *  Constant: '<S6>/CEE_K_Reduction_Temperature'
   *  Constant: '<S6>/CEE_Max_Regenerative_Torque'
   *  Constant: '<S6>/CEE_Power_Limit'
   *  Constant: '<S6>/CEE_SKF_Initial'
   *  Inport: '<Root>/RacingMode'
   *  Inport: '<S3>/Apps_Sat_Dwn'
   *  Inport: '<S3>/Apps_Sat_Up'
   *  Inport: '<S3>/CKF_Initial'
   *  Inport: '<S3>/Cte_CKF'
   *  Inport: '<S3>/Cte_SKF'
   *  Inport: '<S3>/K_Reduction_P'
   *  Inport: '<S3>/K_Reduction_Temperature'
   *  Inport: '<S3>/Max_Regenerative_Torque'
   *  Inport: '<S3>/Power_Limit'
   *  Inport: '<S3>/SKF_Initial'
   */
  switch (Racing_Mode_U.RacingMode) {
   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Workshop Test (01)' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
      &Racing_Mode_P.WorkshopTest01);

    /* End of Outputs for SubSystem: '<Root>/Workshop Test (01)' */
    break;

   case 11:
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
        &Racing_Mode_B.SKF_Initial, &Racing_Mode_P.SKF_Initial);

      /* End of Outputs for SubSystem: '<S2>/SKF_Initial' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S2>/CKF_Initial' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.CKF_Initial, &Racing_Mode_P.CKF_Initial);

      /* End of Outputs for SubSystem: '<S2>/CKF_Initial' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S2>/Cte_SKF' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.Cte_SKF, &Racing_Mode_P.Cte_SKF);

      /* End of Outputs for SubSystem: '<S2>/Cte_SKF' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S2>/Cte_CKF' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.Cte_CKF, &Racing_Mode_P.Cte_CKF);

      /* End of Outputs for SubSystem: '<S2>/Cte_CKF' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S2>/Apps_Sat_Dwn' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.Apps_Sat_Dwn, &Racing_Mode_P.Apps_Sat_Dwn);

      /* End of Outputs for SubSystem: '<S2>/Apps_Sat_Dwn' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S2>/Apps_Sat_Up' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.Apps_Sat_Up, &Racing_Mode_P.Apps_Sat_Up);

      /* End of Outputs for SubSystem: '<S2>/Apps_Sat_Up' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S2>/Max_Regenerative_Torque' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      Racing__Max_Regenerative_Torque(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.Max_Regenerative_Torque);

      /* End of Outputs for SubSystem: '<S2>/Max_Regenerative_Torque' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S2>/Power_Limit' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      Racing__Max_Regenerative_Torque(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.Power_Limit);

      /* End of Outputs for SubSystem: '<S2>/Power_Limit' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S2>/K_Reduction_P' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.K_Reduction_P, &Racing_Mode_P.K_Reduction_P);

      /* End of Outputs for SubSystem: '<S2>/K_Reduction_P' */
      break;

     case 10:
      /* Outputs for IfAction SubSystem: '<S2>/K_Reduction_Temperature' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      Racing_Mode_SKF_Initial(Racing_Mode_U.CustomMode_Data,
        &Racing_Mode_B.K_Reduction_Temperature,
        &Racing_Mode_P.K_Reduction_Temperature);

      /* End of Outputs for SubSystem: '<S2>/K_Reduction_Temperature' */
      break;
    }

    /* End of SwitchCase: '<S2>/Switch Case' */

    /* SignalConversion: '<S2>/OutportBufferForParams' */
    Racing_Mode_B.Merge[0] = Racing_Mode_B.SKF_Initial.Gain;
    Racing_Mode_B.Merge[1] = Racing_Mode_B.CKF_Initial.Gain;
    Racing_Mode_B.Merge[2] = Racing_Mode_B.Cte_SKF.Gain;
    Racing_Mode_B.Merge[3] = Racing_Mode_B.Cte_CKF.Gain;
    Racing_Mode_B.Merge[4] = Racing_Mode_B.Apps_Sat_Dwn.Gain;
    Racing_Mode_B.Merge[5] = Racing_Mode_B.Apps_Sat_Up.Gain;
    Racing_Mode_B.Merge[6] = Racing_Mode_B.Max_Regenerative_Torque.In1;
    Racing_Mode_B.Merge[7] = Racing_Mode_B.Power_Limit.In1;
    Racing_Mode_B.Merge[8] = Racing_Mode_B.K_Reduction_P.Gain;
    Racing_Mode_B.Merge[9] = Racing_Mode_B.K_Reduction_Temperature.Gain;

    /* End of Outputs for SubSystem: '<Root>/Custom Dash (11)' */
    break;

   case 12:
    /* Outputs for IfAction SubSystem: '<Root>/Custom Experiment Environment (12)' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    Racing_Mode_B.Merge[4] = Racing_Mode_P.CEE_Apps_Sat_Dwn_Value;
    Racing_Mode_B.Merge[5] = Racing_Mode_P.CEE_Apps_Sat_Up_Value;
    Racing_Mode_B.Merge[1] = Racing_Mode_P.CEE_CKF_Initial_Value;
    Racing_Mode_B.Merge[3] = Racing_Mode_P.CEE_Cte_CKF_Value;
    Racing_Mode_B.Merge[2] = Racing_Mode_P.CEE_Cte_SKF_Value;
    Racing_Mode_B.Merge[8] = Racing_Mode_P.CEE_K_Reduction_P_Value;
    Racing_Mode_B.Merge[9] = Racing_Mode_P.CEE_K_Reduction_Temperature_Val;
    Racing_Mode_B.Merge[6] = Racing_Mode_P.CEE_Max_Regenerative_Torque_Val;
    Racing_Mode_B.Merge[7] = Racing_Mode_P.CEE_Power_Limit_Value;
    Racing_Mode_B.Merge[0] = Racing_Mode_P.CEE_SKF_Initial_Value;

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
      Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
        &Racing_Mode_P.Acceleration2Driver11);

      /* End of Outputs for SubSystem: '<S4>/Acceleration (2). Driver 1 (1) ' */
      break;

     case 31:
      /* Outputs for IfAction SubSystem: '<S4>/Skidpad (3). Driver 1 (1)' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
        &Racing_Mode_P.Skidpad3Driver11);

      /* End of Outputs for SubSystem: '<S4>/Skidpad (3). Driver 1 (1)' */
      break;

     case 41:
      /* Outputs for IfAction SubSystem: '<S4>/AutoX (4). Driver 1 (1)' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
        &Racing_Mode_P.AutoX4Driver11);

      /* End of Outputs for SubSystem: '<S4>/AutoX (4). Driver 1 (1)' */
      break;

     case 51:
      /* Outputs for IfAction SubSystem: '<S4>/Endurance (5). Driver 1 (1)' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
        &Racing_Mode_P.Endurance5Driver11);

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
      Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
        &Racing_Mode_P.Acceleration2Driver22);

      /* End of Outputs for SubSystem: '<S5>/Acceleration (2). Driver 2 (2) ' */
      break;

     case 32:
      /* Outputs for IfAction SubSystem: '<S5>/Skidpad (3). Driver 2 (2)' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
        &Racing_Mode_P.Skidpad3Driver22);

      /* End of Outputs for SubSystem: '<S5>/Skidpad (3). Driver 2 (2)' */
      break;

     case 42:
      /* Outputs for IfAction SubSystem: '<S5>/AutoX (4). Driver 2 (2)' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
        &Racing_Mode_P.AutoX4Driver22);

      /* End of Outputs for SubSystem: '<S5>/AutoX (4). Driver 2 (2)' */
      break;

     case 52:
      /* Outputs for IfAction SubSystem: '<S5>/Endurance (5). Driver 2 (2)' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      Racing_Mode_WorkshopTest01(Racing_Mode_B.Merge,
        &Racing_Mode_P.Endurance5Driver22);

      /* End of Outputs for SubSystem: '<S5>/Endurance (5). Driver 2 (2)' */
      break;
    }

    /* End of SwitchCase: '<S5>/Selecció de Mode' */
    /* End of Outputs for SubSystem: '<Root>/Driver 2 Modes (22,32,42,52)' */
    break;
  }

  /* End of SwitchCase: '<Root>/Selecció de Mode' */

  /* Saturate: '<Root>/SKF_Initial Saturation' */
  if (Racing_Mode_B.Merge[0] > Racing_Mode_P.SKF_InitialSaturation_UpperSat) {
    /* Outport: '<Root>/VDC_SKF_Initial' */
    Racing_Mode_Y.VDC_SKF_Initial = Racing_Mode_P.SKF_InitialSaturation_UpperSat;
  } else if (Racing_Mode_B.Merge[0] <
             Racing_Mode_P.SKF_InitialSaturation_LowerSat) {
    /* Outport: '<Root>/VDC_SKF_Initial' */
    Racing_Mode_Y.VDC_SKF_Initial = Racing_Mode_P.SKF_InitialSaturation_LowerSat;
  } else {
    /* Outport: '<Root>/VDC_SKF_Initial' */
    Racing_Mode_Y.VDC_SKF_Initial = Racing_Mode_B.Merge[0];
  }

  /* End of Saturate: '<Root>/SKF_Initial Saturation' */

  /* Saturate: '<Root>/CKF_Initial Saturation' */
  if (Racing_Mode_B.Merge[1] > Racing_Mode_P.CKF_InitialSaturation_UpperSat) {
    /* Outport: '<Root>/VDC_CKF_Initial' */
    Racing_Mode_Y.VDC_CKF_Initial = Racing_Mode_P.CKF_InitialSaturation_UpperSat;
  } else if (Racing_Mode_B.Merge[1] <
             Racing_Mode_P.CKF_InitialSaturation_LowerSat) {
    /* Outport: '<Root>/VDC_CKF_Initial' */
    Racing_Mode_Y.VDC_CKF_Initial = Racing_Mode_P.CKF_InitialSaturation_LowerSat;
  } else {
    /* Outport: '<Root>/VDC_CKF_Initial' */
    Racing_Mode_Y.VDC_CKF_Initial = Racing_Mode_B.Merge[1];
  }

  /* End of Saturate: '<Root>/CKF_Initial Saturation' */

  /* Saturate: '<Root>/Cte_SKF Saturation' */
  if (Racing_Mode_B.Merge[2] > Racing_Mode_P.Cte_SKFSaturation_UpperSat) {
    /* Outport: '<Root>/VDC_Cte_SKF' */
    Racing_Mode_Y.VDC_Cte_SKF = Racing_Mode_P.Cte_SKFSaturation_UpperSat;
  } else if (Racing_Mode_B.Merge[2] < Racing_Mode_P.Cte_SKFSaturation_LowerSat)
  {
    /* Outport: '<Root>/VDC_Cte_SKF' */
    Racing_Mode_Y.VDC_Cte_SKF = Racing_Mode_P.Cte_SKFSaturation_LowerSat;
  } else {
    /* Outport: '<Root>/VDC_Cte_SKF' */
    Racing_Mode_Y.VDC_Cte_SKF = Racing_Mode_B.Merge[2];
  }

  /* End of Saturate: '<Root>/Cte_SKF Saturation' */

  /* Saturate: '<Root>/Cte_CKF Saturation' */
  if (Racing_Mode_B.Merge[3] > Racing_Mode_P.Cte_CKFSaturation_UpperSat) {
    /* Outport: '<Root>/VDC_Cte_CKF' */
    Racing_Mode_Y.VDC_Cte_CKF = Racing_Mode_P.Cte_CKFSaturation_UpperSat;
  } else if (Racing_Mode_B.Merge[3] < Racing_Mode_P.Cte_CKFSaturation_LowerSat)
  {
    /* Outport: '<Root>/VDC_Cte_CKF' */
    Racing_Mode_Y.VDC_Cte_CKF = Racing_Mode_P.Cte_CKFSaturation_LowerSat;
  } else {
    /* Outport: '<Root>/VDC_Cte_CKF' */
    Racing_Mode_Y.VDC_Cte_CKF = Racing_Mode_B.Merge[3];
  }

  /* End of Saturate: '<Root>/Cte_CKF Saturation' */

  /* Saturate: '<Root>/Apps_Sat_Dwn Saturation' */
  if (Racing_Mode_B.Merge[4] > Racing_Mode_P.Apps_Sat_DwnSaturation_UpperSat) {
    /* Outport: '<Root>/VDC_Apps_Sat_Down' */
    Racing_Mode_Y.VDC_Apps_Sat_Down =
      Racing_Mode_P.Apps_Sat_DwnSaturation_UpperSat;
  } else if (Racing_Mode_B.Merge[4] <
             Racing_Mode_P.Apps_Sat_DwnSaturation_LowerSat) {
    /* Outport: '<Root>/VDC_Apps_Sat_Down' */
    Racing_Mode_Y.VDC_Apps_Sat_Down =
      Racing_Mode_P.Apps_Sat_DwnSaturation_LowerSat;
  } else {
    /* Outport: '<Root>/VDC_Apps_Sat_Down' */
    Racing_Mode_Y.VDC_Apps_Sat_Down = Racing_Mode_B.Merge[4];
  }

  /* End of Saturate: '<Root>/Apps_Sat_Dwn Saturation' */

  /* Saturate: '<Root>/Apps_Sat_Up Saturation' */
  if (Racing_Mode_B.Merge[5] > Racing_Mode_P.Apps_Sat_UpSaturation_UpperSat) {
    /* Outport: '<Root>/VDC_Apps_Sat_Up' */
    Racing_Mode_Y.VDC_Apps_Sat_Up = Racing_Mode_P.Apps_Sat_UpSaturation_UpperSat;
  } else if (Racing_Mode_B.Merge[5] <
             Racing_Mode_P.Apps_Sat_UpSaturation_LowerSat) {
    /* Outport: '<Root>/VDC_Apps_Sat_Up' */
    Racing_Mode_Y.VDC_Apps_Sat_Up = Racing_Mode_P.Apps_Sat_UpSaturation_LowerSat;
  } else {
    /* Outport: '<Root>/VDC_Apps_Sat_Up' */
    Racing_Mode_Y.VDC_Apps_Sat_Up = Racing_Mode_B.Merge[5];
  }

  /* End of Saturate: '<Root>/Apps_Sat_Up Saturation' */

  /* Saturate: '<Root>/Max_Regenerative_Torque Saturation' */
  if (Racing_Mode_B.Merge[6] > Racing_Mode_P.Max_Regenerative_TorqueSaturati) {
    /* Outport: '<Root>/VDC_Max_Regenerative_Torque' */
    Racing_Mode_Y.VDC_Max_Regenerative_Torque =
      Racing_Mode_P.Max_Regenerative_TorqueSaturati;
  } else if (Racing_Mode_B.Merge[6] <
             Racing_Mode_P.Max_Regenerative_TorqueSatura_o) {
    /* Outport: '<Root>/VDC_Max_Regenerative_Torque' */
    Racing_Mode_Y.VDC_Max_Regenerative_Torque =
      Racing_Mode_P.Max_Regenerative_TorqueSatura_o;
  } else {
    /* Outport: '<Root>/VDC_Max_Regenerative_Torque' */
    Racing_Mode_Y.VDC_Max_Regenerative_Torque = Racing_Mode_B.Merge[6];
  }

  /* End of Saturate: '<Root>/Max_Regenerative_Torque Saturation' */

  /* Saturate: '<Root>/Power_Limit Saturation' */
  if (Racing_Mode_B.Merge[7] > Racing_Mode_P.Power_LimitSaturation_UpperSat) {
    /* Outport: '<Root>/VDC_Power_Limit' */
    Racing_Mode_Y.VDC_Power_Limit = Racing_Mode_P.Power_LimitSaturation_UpperSat;
  } else if (Racing_Mode_B.Merge[7] <
             Racing_Mode_P.Power_LimitSaturation_LowerSat) {
    /* Outport: '<Root>/VDC_Power_Limit' */
    Racing_Mode_Y.VDC_Power_Limit = Racing_Mode_P.Power_LimitSaturation_LowerSat;
  } else {
    /* Outport: '<Root>/VDC_Power_Limit' */
    Racing_Mode_Y.VDC_Power_Limit = Racing_Mode_B.Merge[7];
  }

  /* End of Saturate: '<Root>/Power_Limit Saturation' */

  /* Saturate: '<Root>/K_Reduction_P Saturation' */
  if (Racing_Mode_B.Merge[8] > Racing_Mode_P.K_Reduction_PSaturation_UpperSa) {
    /* Outport: '<Root>/VDC_K_Reduction_P' */
    Racing_Mode_Y.VDC_K_Reduction_P =
      Racing_Mode_P.K_Reduction_PSaturation_UpperSa;
  } else if (Racing_Mode_B.Merge[8] <
             Racing_Mode_P.K_Reduction_PSaturation_LowerSa) {
    /* Outport: '<Root>/VDC_K_Reduction_P' */
    Racing_Mode_Y.VDC_K_Reduction_P =
      Racing_Mode_P.K_Reduction_PSaturation_LowerSa;
  } else {
    /* Outport: '<Root>/VDC_K_Reduction_P' */
    Racing_Mode_Y.VDC_K_Reduction_P = Racing_Mode_B.Merge[8];
  }

  /* End of Saturate: '<Root>/K_Reduction_P Saturation' */

  /* Saturate: '<Root>/K_Reduction_Temperature Saturation' */
  if (Racing_Mode_B.Merge[9] > Racing_Mode_P.K_Reduction_TemperatureSaturati) {
    /* Outport: '<Root>/VDC_K_Reduction_Temperature' */
    Racing_Mode_Y.VDC_K_Reduction_Temperature =
      Racing_Mode_P.K_Reduction_TemperatureSaturati;
  } else if (Racing_Mode_B.Merge[9] <
             Racing_Mode_P.K_Reduction_TemperatureSatura_m) {
    /* Outport: '<Root>/VDC_K_Reduction_Temperature' */
    Racing_Mode_Y.VDC_K_Reduction_Temperature =
      Racing_Mode_P.K_Reduction_TemperatureSatura_m;
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
  Racing_Mode_Y.Workshop_Mode_Enable = (Racing_Mode_U.RacingMode ==
    Racing_Mode_P.CompareToConstant_const);
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
  {
    int32_T i;

    /* SystemInitialize for IfAction SubSystem: '<Root>/Custom Dash (11)' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/SKF_Initial' */
    Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.SKF_Initial,
      &Racing_Mode_P.SKF_Initial);

    /* End of SystemInitialize for SubSystem: '<S2>/SKF_Initial' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/CKF_Initial' */
    Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.CKF_Initial,
      &Racing_Mode_P.CKF_Initial);

    /* End of SystemInitialize for SubSystem: '<S2>/CKF_Initial' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/Cte_SKF' */
    Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.Cte_SKF, &Racing_Mode_P.Cte_SKF);

    /* End of SystemInitialize for SubSystem: '<S2>/Cte_SKF' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/Cte_CKF' */
    Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.Cte_CKF, &Racing_Mode_P.Cte_CKF);

    /* End of SystemInitialize for SubSystem: '<S2>/Cte_CKF' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/Apps_Sat_Dwn' */
    Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.Apps_Sat_Dwn,
      &Racing_Mode_P.Apps_Sat_Dwn);

    /* End of SystemInitialize for SubSystem: '<S2>/Apps_Sat_Dwn' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/Apps_Sat_Up' */
    Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.Apps_Sat_Up,
      &Racing_Mode_P.Apps_Sat_Up);

    /* End of SystemInitialize for SubSystem: '<S2>/Apps_Sat_Up' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/Max_Regenerative_Torque' */
    Ra_Max_Regenerative_Torque_Init(&Racing_Mode_B.Max_Regenerative_Torque,
      &Racing_Mode_P.Max_Regenerative_Torque);

    /* End of SystemInitialize for SubSystem: '<S2>/Max_Regenerative_Torque' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/Power_Limit' */
    Ra_Max_Regenerative_Torque_Init(&Racing_Mode_B.Power_Limit,
      &Racing_Mode_P.Power_Limit);

    /* End of SystemInitialize for SubSystem: '<S2>/Power_Limit' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/K_Reduction_P' */
    Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.K_Reduction_P,
      &Racing_Mode_P.K_Reduction_P);

    /* End of SystemInitialize for SubSystem: '<S2>/K_Reduction_P' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/K_Reduction_Temperature' */
    Racing_Mode_SKF_Initial_Init(&Racing_Mode_B.K_Reduction_Temperature,
      &Racing_Mode_P.K_Reduction_Temperature);

    /* End of SystemInitialize for SubSystem: '<S2>/K_Reduction_Temperature' */

    /* End of SystemInitialize for SubSystem: '<Root>/Custom Dash (11)' */

    /* SystemInitialize for Merge: '<Root>/Merge' */
    for (i = 0; i < 10; i++) {
      Racing_Mode_B.Merge[i] = Racing_Mode_P.Merge_InitialOutput;
    }

    /* End of SystemInitialize for Merge: '<Root>/Merge' */
  }
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
  Racing_Mode_M->solverInfoPtr = (&Racing_Mode_M->solverInfo);
  Racing_Mode_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&Racing_Mode_M->solverInfo, 0.2);
  rtsiSetSolverMode(&Racing_Mode_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Racing_Mode_M->blockIO = ((void *) &Racing_Mode_B);
  (void) memset(((void *) &Racing_Mode_B), 0,
                sizeof(B_Racing_Mode_T));

  /* parameters */
  Racing_Mode_M->defaultParam = ((real_T *)&Racing_Mode_P);

  /* external inputs */
  Racing_Mode_M->inputs = (((void*)&Racing_Mode_U));
  (void)memset((void *)&Racing_Mode_U, 0, sizeof(ExtU_Racing_Mode_T));

  /* external outputs */
  Racing_Mode_M->outputs = (&Racing_Mode_Y);
  (void) memset((void *)&Racing_Mode_Y, 0,
                sizeof(ExtY_Racing_Mode_T));

  /* Initialize Sizes */
  Racing_Mode_M->Sizes.numContStates = (0);/* Number of continuous states */
  Racing_Mode_M->Sizes.numY = (11);    /* Number of model outputs */
  Racing_Mode_M->Sizes.numU = (3);     /* Number of model inputs */
  Racing_Mode_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Racing_Mode_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Racing_Mode_M->Sizes.numBlocks = (87);/* Number of blocks */
  Racing_Mode_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  Racing_Mode_M->Sizes.numBlockPrms = (140);/* Sum of parameter "widths" */
  return Racing_Mode_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
