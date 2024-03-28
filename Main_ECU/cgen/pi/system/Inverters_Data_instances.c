/*****************************************************************************
 *
 * Inverters_Data_instances.c
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2007 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
  /* use void* as instance tree wrapper object pointer type */
 #define Y_PRIMIT_VOID_PTR_FOR_ADDR
#define bool RTW_bool
#include "Inverters_Data.h"
#include "Inverters_Data_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Inverters_Data_instances.h"
extern    ExtU_Inverters_Data_T Inverters_Data_U;
extern    ExtY_Inverters_Data_T Inverters_Data_Y;
/* Initialization of Simulink model */
struct RTWTop_Inverters_Data_Obj *initModel_RTWTop_Inverters_Data(void)
{
    struct RTWTop_Inverters_Data_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Inverters_Data (&RTWTop_Inverters_Data_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Inverters_Data();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Inverters_Data(struct RTWTop_Inverters_Data_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Inverters_Data_U_Inv_L_RegID_M235_Inv_L_DCBus_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_L_RegID_M235_Inv_L_DCBus, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_L_RegID_M32_Inv_L_Iactual_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_L_RegID_M32_Inv_L_Iactual, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_L_RegID_M38_Inv_L_Icommand_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_L_RegID_M38_Inv_L_Icommand, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_L_RegID_M39_Inv_L_Iq_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_L_RegID_M39_Inv_L_Iq, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_L_RegID_M48_Inv_L_Speed_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_L_RegID_M48_Inv_L_Speed, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_L_RegID_M73_Inv_L_TempMotor_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_L_RegID_M73_Inv_L_TempMotor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_L_RegID_M74_Inv_L_TempIGBT_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_L_RegID_M74_Inv_L_TempIGBT, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_R_RegID_M235_Inv_R_DCBus_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_R_RegID_M235_Inv_R_DCBus, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_R_RegID_M32_Inv_R_Iactual_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_R_RegID_M32_Inv_R_Iactual, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_R_RegID_M38_Inv_R_Icommand_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_R_RegID_M38_Inv_R_Icommand, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_R_RegID_M39_Inv_R_Iq_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_R_RegID_M39_Inv_R_Iq, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_R_RegID_M48_Inv_R_Speed_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_R_RegID_M48_Inv_R_Speed, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_R_RegID_M73_Inv_R_TempMotor_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_R_RegID_M73_Inv_R_TempMotor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_U_Inv_R_RegID_M74_Inv_R_TempIGBT_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_U.Inv_R_RegID_M74_Inv_R_TempIGBT, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_L_Iactual_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_L_Iactual, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_L_Icommand_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_L_Icommand, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_L_Iq_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_L_Iq, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_L_TempIGBT_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_L_TempIGBT, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_L_TempMotor_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_L_TempMotor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_L_VdcBus_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_L_VdcBus, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_R_Iactual_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_R_Iactual, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_R_Icommand_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_R_Icommand, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_R_Iq_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_R_Iq, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_R_TempIGBT_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_R_TempIGBT, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_R_TempMotor_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_R_TempMotor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Inv_R_VdcBus_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Inv_R_VdcBus, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_InvertersMinDCBus_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.InvertersMinDCBus, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_RL_Vel_ms_Wheel_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.RL_Vel_ms_Wheel, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_RL_rads_Motor_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.RL_rads_Motor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_RR_Vel_ms_Wheel_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.RR_Vel_ms_Wheel, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_RR_rads_Motor_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.RR_rads_Motor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Speed_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Speed, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Temp_IGBT_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Temp_IGBT, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Temp_Motors_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Temp_Motors, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Wheel_RL_Speed_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Wheel_RL_Speed, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Data_Y_Wheel_RR_Speed_Ptr = initInstance_scalarWrapper((void*)&Inverters_Data_Y.Wheel_RR_Speed, sizeof(double), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Inverters_Data(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_Inverters_Data_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Inverters_Data
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Inverters_Data_ClassHeader =
    {0, 1, 0, 36 + 0, (MethodList *)0, (MethodList *)&RTWTop_Inverters_Data_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Inverters_Data_Class RTWTop_Inverters_Data_ClassObj = {{1, {&RTWTop_Inverters_Data_ClassHeader}, {0}}
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
struct RTWTop_Inverters_Data_Obj *initInstance_RTWTop_Inverters_Data(void)
{
    struct RTWTop_Inverters_Data_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Inverters_Data);
    return self;
}
void setDeltaT_Inverters_Data(void)
{
}
