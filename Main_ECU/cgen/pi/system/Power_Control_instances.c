/*****************************************************************************
 *
 * Power_Control_instances.c
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2024 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
  /* use void* as instance tree wrapper object pointer type */
 #define Y_PRIMIT_VOID_PTR_FOR_ADDR
#define bool RTW_bool
#include "Power_Control.h"
#include "Power_Control_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Power_Control_instances.h"
extern    B_Power_Control_T Power_Control_B;
extern    DW_Power_Control_T Power_Control_DW;
extern    ExtU_Power_Control_T Power_Control_U;
extern    ExtY_Power_Control_T Power_Control_Y;
/* Initialization of Simulink model */
struct RTWTop_Power_Control_Obj *initModel_RTWTop_Power_Control(void)
{
    struct RTWTop_Power_Control_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Power_Control (&RTWTop_Power_Control_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Power_Control();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Power_Control(struct RTWTop_Power_Control_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Power_Control_B_sf_InverterL_Temp_Limitation_Current_out_Ptr = initInstance_scalarWrapper((void*)&Power_Control_B.sf_InverterL_Temp_Limitation.Current_out, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_B_sf_InverterR_Temp_Limitation_Current_out_Ptr = initInstance_scalarWrapper((void*)&Power_Control_B.sf_InverterR_Temp_Limitation.Current_out, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_B_sf_MotorL_Temp_Limitation_Current_out_Ptr = initInstance_scalarWrapper((void*)&Power_Control_B.sf_MotorL_Temp_Limitation.Current_out, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_B_sf_MotorR_Temp_Limitation_Current_out_Ptr = initInstance_scalarWrapper((void*)&Power_Control_B.sf_MotorR_Temp_Limitation.Current_out, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_DW_A_Ptr = initInstance_scalarWrapper((void*)&Power_Control_DW.A, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_U_Accumulator_Current_Ptr = initInstance_scalarWrapper((void*)&Power_Control_U.Accumulator_Current, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_U_Accumulator_Voltage_Ptr = initInstance_scalarWrapper((void*)&Power_Control_U.Accumulator_Voltage, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_U_Inv_L_TempIGBT_Ptr = initInstance_scalarWrapper((void*)&Power_Control_U.Inv_L_TempIGBT, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_U_Inv_L_TempMotor_Ptr = initInstance_scalarWrapper((void*)&Power_Control_U.Inv_L_TempMotor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_U_Inv_R_TempIGBT_Ptr = initInstance_scalarWrapper((void*)&Power_Control_U.Inv_R_TempIGBT, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_U_Inv_R_TempMotor_Ptr = initInstance_scalarWrapper((void*)&Power_Control_U.Inv_R_TempMotor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_U_Torque_L_Ptr = initInstance_scalarWrapper((void*)&Power_Control_U.Torque_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_U_Torque_R_Ptr = initInstance_scalarWrapper((void*)&Power_Control_U.Torque_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_Y_Power_Ptr = initInstance_scalarWrapper((void*)&Power_Control_Y.Power, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_Y_PowerLimitReached_Ptr = initInstance_scalarWrapper((void*)&Power_Control_Y.PowerLimitReached, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_Y_PowerMean500ms_Ptr = initInstance_scalarWrapper((void*)&Power_Control_Y.PowerMean500ms, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_Y_current_L_Ptr = initInstance_scalarWrapper((void*)&Power_Control_Y.current_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Power_Control_Y_current_R_Ptr = initInstance_scalarWrapper((void*)&Power_Control_Y.current_R, sizeof(double), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Power_Control(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_Power_Control_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Power_Control
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Power_Control_ClassHeader =
    {0, 1, 0, 18 + 0, (MethodList *)0, (MethodList *)&RTWTop_Power_Control_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Power_Control_Class RTWTop_Power_Control_ClassObj = {{1, {&RTWTop_Power_Control_ClassHeader}, {0}}
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
struct RTWTop_Power_Control_Obj *initInstance_RTWTop_Power_Control(void)
{
    struct RTWTop_Power_Control_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Power_Control);
    return self;
}
void setDeltaT_Power_Control(void)
{
}
