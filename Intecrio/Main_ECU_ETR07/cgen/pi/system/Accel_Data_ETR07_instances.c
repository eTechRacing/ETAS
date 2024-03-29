/*****************************************************************************
 *
 * Accel_Data_ETR07_instances.c
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
#include "Accel_Data_ETR07.h"
#include "Accel_Data_ETR07_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Accel_Data_ETR07_instances.h"
extern    B_Accel_Data_ETR07_T Accel_Data_ETR07_B;
extern    DW_Accel_Data_ETR07_T Accel_Data_ETR07_DW;
extern    P_Accel_Data_ETR07_T Accel_Data_ETR07_P;
extern    ExtU_Accel_Data_ETR07_T Accel_Data_ETR07_U;
extern    ExtY_Accel_Data_ETR07_T Accel_Data_ETR07_Y;
/* Initialization of Simulink model */
struct RTWTop_Accel_Data_ETR07_Obj *initModel_RTWTop_Accel_Data_ETR07(void)
{
    struct RTWTop_Accel_Data_ETR07_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Accel_Data_ETR07 (&RTWTop_Accel_Data_ETR07_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Accel_Data_ETR07();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Accel_Data_ETR07(struct RTWTop_Accel_Data_ETR07_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Accel_Data_ETR07_B_AccDataConversionFX_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.AccDataConversionFX.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_B_AccDataConversionFY_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.AccDataConversionFY.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_B_AccDataConversionFZ_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.AccDataConversionFZ.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_B_AccDataConversionRX_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.AccDataConversionRX.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_B_AccDataConversionRY_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.AccDataConversionRY.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_B_AccDataConversionRZ_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.AccDataConversionRZ.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_B_LowPass_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.LowPass.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_B_LowPass1_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.LowPass1.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_B_LowPass2_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_B.LowPass2.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_DW_A_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_DW.A, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_DW_A_f_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_DW.A_f, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_P_CycleTime_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.CycleTime_Gain, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_CycleTime_Gain_h_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.CycleTime_Gain_h, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_DataStoreMemory_InitialValue_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.DataStoreMemory_InitialValue, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_DataStoreMemory_InitialValue_m_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.DataStoreMemory_InitialValue_m, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_ExperimentalOffset_Value_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.ExperimentalOffset_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_ExperimentalOffset_Value_e_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.ExperimentalOffset_Value_e, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_Gain2_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.Gain2_Gain, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_Gain4_Gain_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.Gain4_Gain, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_RpsLSB_Value_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.RpsLSB_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_P_sbit_Value_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_P.sbit_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Accel_Data_ETR07_U_ACCEL_F_X_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_U.ACCEL_F_X, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_U_ACCEL_F_Y_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_U.ACCEL_F_Y, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_U_ACCEL_F_Z_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_U.ACCEL_F_Z, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_U_ACCEL_R_X_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_U.ACCEL_R_X, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_U_ACCEL_R_Y_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_U.ACCEL_R_Y, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_U_ACCEL_R_Z_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_U.ACCEL_R_Z, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_U_Gyroscope_F_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_U.Gyroscope_F, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_U_Gyroscope_R_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_U.Gyroscope_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Accel_F_X_SI_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Accel_F_X_SI, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Accel_F_Y_SI_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Accel_F_Y_SI, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Accel_F_Z_SI_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Accel_F_Z_SI, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Accel_R_X_SI_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Accel_R_X_SI, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Accel_R_Y_SI_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Accel_R_Y_SI, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Accel_R_Z_SI_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Accel_R_Z_SI, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Gyro_F_Z_Deg_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Gyro_F_Z_Deg, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Gyro_R_Z_Deg_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Gyro_R_Z_Deg, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Rate_F_Z_Degs2_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Rate_F_Z_Degs2, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Accel_Data_ETR07_Y_Rate_R_Z_Degs_Ptr = initInstance_scalarWrapper((uint32)&Accel_Data_ETR07_Y.Rate_R_Z_Degs, sizeof(double), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Accel_Data_ETR07(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_Accel_Data_ETR07_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Accel_Data_ETR07
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Accel_Data_ETR07_ClassHeader =
    {0, 1, 0, 39 + 0, (MethodList *)0, (MethodList *)&RTWTop_Accel_Data_ETR07_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Accel_Data_ETR07_Class RTWTop_Accel_Data_ETR07_ClassObj = {{1, {&RTWTop_Accel_Data_ETR07_ClassHeader}, {0}}
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
struct RTWTop_Accel_Data_ETR07_Obj *initInstance_RTWTop_Accel_Data_ETR07(void)
{
    struct RTWTop_Accel_Data_ETR07_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Accel_Data_ETR07);
    return self;
}
void setDeltaT_Accel_Data_ETR07(void)
{
}
