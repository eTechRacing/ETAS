/*****************************************************************************
 *
 * Racing_Mode_ETR07_instances.c
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2007 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
#define bool RTW_bool
#include "Racing_Mode_ETR07.h"
#include "Racing_Mode_ETR07_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Racing_Mode_ETR07_instances.h"
extern    B_Racing_Mode_ETR07_T Racing_Mode_ETR07_B;
extern    P_Racing_Mode_ETR07_T Racing_Mode_ETR07_P;
extern    ExtU_Racing_Mode_ETR07_T Racing_Mode_ETR07_U;
extern    ExtY_Racing_Mode_ETR07_T Racing_Mode_ETR07_Y;
/* Initialization of Simulink model */
struct RTWTop_Racing_Mode_ETR07_Obj *initModel_RTWTop_Racing_Mode_ETR07(void)
{
    struct RTWTop_Racing_Mode_ETR07_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Racing_Mode_ETR07 (&RTWTop_Racing_Mode_ETR07_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Racing_Mode_ETR07();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Racing_Mode_ETR07(struct RTWTop_Racing_Mode_ETR07_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Racing_Mode_ETR07_B_Apps_Sat_Dwn_Gain_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.Apps_Sat_Dwn.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_Apps_Sat_Up_Gain_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.Apps_Sat_Up.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_CKF_Initial_Gain_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.CKF_Initial.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_Cte_CKF_Gain_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.Cte_CKF.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_Cte_SKF_Gain_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.Cte_SKF.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_K_Reduction_P_Gain_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.K_Reduction_P.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_K_Reduction_Temperature_Gain_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.K_Reduction_Temperature.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_Max_Regenerative_Torque_In1_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.Max_Regenerative_Torque.In1, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_Merge_Ptr = initInstance_vectorWrapper((uint32)&Racing_Mode_ETR07_B.Merge, sizeof(double), (uint32)10, (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_Power_Limit_In1_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.Power_Limit.In1, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_B_SKF_Initial_Gain_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_B.SKF_Initial.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_P_Apps_Sat_DwnSaturation_LowerSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Apps_Sat_DwnSaturation_LowerSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Apps_Sat_DwnSaturation_UpperSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Apps_Sat_DwnSaturation_UpperSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Apps_Sat_UpSaturation_LowerSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Apps_Sat_UpSaturation_LowerSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Apps_Sat_UpSaturation_UpperSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Apps_Sat_UpSaturation_UpperSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_Apps_Sat_Dwn_Value_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_Apps_Sat_Dwn_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_Apps_Sat_Up_Value_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_Apps_Sat_Up_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_CKF_Initial_Value_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_CKF_Initial_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_Cte_CKF_Value_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_Cte_CKF_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_Cte_SKF_Value_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_Cte_SKF_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_K_Reduction_P_Value_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_K_Reduction_P_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_K_Reduction_Temperature_Val_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_K_Reduction_Temperature_Val, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_Max_Regenerative_Torque_Val_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_Max_Regenerative_Torque_Val, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_Power_Limit_Value_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_Power_Limit_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CEE_SKF_Initial_Value_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CEE_SKF_Initial_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CKF_InitialSaturation_LowerSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CKF_InitialSaturation_LowerSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CKF_InitialSaturation_UpperSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CKF_InitialSaturation_UpperSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_CompareToConstant_const_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.CompareToConstant_const, sizeof(char), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Cte_CKFSaturation_LowerSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Cte_CKFSaturation_LowerSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Cte_CKFSaturation_UpperSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Cte_CKFSaturation_UpperSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Cte_SKFSaturation_LowerSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Cte_SKFSaturation_LowerSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Cte_SKFSaturation_UpperSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Cte_SKFSaturation_UpperSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_K_Reduction_PSaturation_LowerSa_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.K_Reduction_PSaturation_LowerSa, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_K_Reduction_PSaturation_UpperSa_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.K_Reduction_PSaturation_UpperSa, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_K_Reduction_TemperatureSatura_m_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.K_Reduction_TemperatureSatura_m, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_K_Reduction_TemperatureSaturati_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.K_Reduction_TemperatureSaturati, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Max_Regenerative_TorqueSatura_o_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Max_Regenerative_TorqueSatura_o, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Max_Regenerative_TorqueSaturati_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Max_Regenerative_TorqueSaturati, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Merge_InitialOutput_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Merge_InitialOutput, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Power_LimitSaturation_LowerSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Power_LimitSaturation_LowerSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_Power_LimitSaturation_UpperSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.Power_LimitSaturation_UpperSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_SKF_InitialSaturation_LowerSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.SKF_InitialSaturation_LowerSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_P_SKF_InitialSaturation_UpperSat_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_P.SKF_InitialSaturation_UpperSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Racing_Mode_ETR07_U_CustomMode_Data_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_U.CustomMode_Data, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_U_CustomMode_Identifier_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_U.CustomMode_Identifier, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_U_RacingMode_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_U.RacingMode, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_Apps_Sat_Down_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_Apps_Sat_Down, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_Apps_Sat_Up_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_Apps_Sat_Up, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_CKF_Initial_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_CKF_Initial, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_Cte_CKF_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_Cte_CKF, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_Cte_SKF_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_Cte_SKF, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_K_Reduction_P_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_K_Reduction_P, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_K_Reduction_Temperature_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_K_Reduction_Temperature, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_Max_Regenerative_Torque_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_Max_Regenerative_Torque, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_Power_Limit_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_Power_Limit, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_VDC_SKF_Initial_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.VDC_SKF_Initial, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Mode_ETR07_Y_Workshop_Mode_Enable_Ptr = initInstance_scalarWrapper((uint32)&Racing_Mode_ETR07_Y.Workshop_Mode_Enable, sizeof(char), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Racing_Mode_ETR07(ASDObjectPtr self, uint8 *buffer)
{
    uint8 definedFlg = true;
    uint32 programIdentifier = 0;
    if(definedFlg == true)
    {
        addScalar(buffer, (uint8*)&programIdentifier, sizeof(programIdentifier));
    }
    addScalar(buffer, (uint8*)&definedFlg, sizeof(definedFlg));
    return(buffer);
}
/* Class method list */
static MethodList RTWTop_Racing_Mode_ETR07_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Racing_Mode_ETR07
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Racing_Mode_ETR07_ClassHeader =
    {0, 1, 0, 57 + 0, (MethodList *)0, (MethodList *)&RTWTop_Racing_Mode_ETR07_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Racing_Mode_ETR07_Class RTWTop_Racing_Mode_ETR07_ClassObj = {{1, {&RTWTop_Racing_Mode_ETR07_ClassHeader}, {0}}
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
};
/* Object instantiation */
struct RTWTop_Racing_Mode_ETR07_Obj *initInstance_RTWTop_Racing_Mode_ETR07(void)
{
    struct RTWTop_Racing_Mode_ETR07_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Racing_Mode_ETR07);
    return self;
}
void setDeltaT_Racing_Mode_ETR07(void)
{
}
