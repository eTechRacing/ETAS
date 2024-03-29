/*****************************************************************************
 *
 * Car_State_ETR07_instances.c
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
#include "Car_State_ETR07.h"
#include "Car_State_ETR07_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Car_State_ETR07_instances.h"
extern    B_Car_State_ETR07_T Car_State_ETR07_B;
extern    DW_Car_State_ETR07_T Car_State_ETR07_DW;
extern    P_Car_State_ETR07_T Car_State_ETR07_P;
extern    ExtU_Car_State_ETR07_T Car_State_ETR07_U;
extern    ExtY_Car_State_ETR07_T Car_State_ETR07_Y;
/* Initialization of Simulink model */
struct RTWTop_Car_State_ETR07_Obj *initModel_RTWTop_Car_State_ETR07(void)
{
    struct RTWTop_Car_State_ETR07_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Car_State_ETR07 (&RTWTop_Car_State_ETR07_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Car_State_ETR07();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Car_State_ETR07(struct RTWTop_Car_State_ETR07_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Car_State_ETR07_B_Merge_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_B.Merge, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_DW_A_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_DW.A, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_P_CompareToConstant_const_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.CompareToConstant_const, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Constant_Value_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Constant_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Constant_Value_f_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Constant_Value_f, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Constant_Value_fl_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Constant_Value_fl, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Constant_Value_k_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Constant_Value_k, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Constant_Value_kb_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Constant_Value_kb, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_DataStoreMemory_InitialValue_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.DataStoreMemory_InitialValue, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Gain_Gain_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Gain_Gain, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_IfDCBUSnotbits_Gain_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.IfDCBUSnotbits_Gain, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Merge_InitialOutput_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Merge_InitialOutput, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Saturation_LowerSat_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Saturation_LowerSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_P_Saturation_UpperSat_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_P.Saturation_UpperSat, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Car_State_ETR07_U_AIRs_State_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.AIRs_State, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Accumulator_Voltage_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Accumulator_Voltage, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_BMSerror_CANDisconnection_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.BMSerror_CANDisconnection, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_BMSerror_CurrentSensDisc_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.BMSerror_CurrentSensDisc, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_BMSerror_NTCDisconnection_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.BMSerror_NTCDisconnection, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_BMSerror_OverTemperature_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.BMSerror_OverTemperature, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_BMSerror_OverVoltage_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.BMSerror_OverVoltage, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_BMSerror_UnderTemperature_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.BMSerror_UnderTemperature, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_BMSerror_UnderVoltage_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.BMSerror_UnderVoltage, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Critical_CAN_Disconnection_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Critical_CAN_Disconnection, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_DashPrechargeRequest_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.DashPrechargeRequest, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_EnableDrive_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.EnableDrive, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_InvertersMinDCBus_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.InvertersMinDCBus, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_InvertersSubscribed_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.InvertersSubscribed, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Lock_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Lock, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_BMS_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_BMS, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_BOTS_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_BOTS, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_BSPD_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_BSPD, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_HVBOX_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_HVBOX, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_HVD_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_HVD, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_Inertia_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_Inertia, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_InverterLIntck_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_InverterLIntck, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_InverterRIntck_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_InverterRIntck, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_PackageIntck_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_PackageIntck, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_SetaCockpit_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_SetaCockpit, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_SetaLeft_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_SetaLeft, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_SetaRight_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_SetaRight, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_TSMPIntck_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_TSMPIntck, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_U_Shutdown_TSMS_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_U.Shutdown_TSMS, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_AIRs_Request_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.AIRs_Request, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_Car_OK_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.Car_OK, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_Car_State_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.Car_State, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_CurrentPathDisconnectionFlag_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.CurrentPathDisconnectionFlag, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_InvertersAction_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.InvertersAction, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_PrechargeAssert_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.PrechargeAssert, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_Precharge_Percentage_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.Precharge_Percentage, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_Precharge_Voltage_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.Precharge_Voltage, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_ShutdownClosed_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.ShutdownClosed, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_TorqueEnable_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.TorqueEnable, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Car_State_ETR07_Y_errors_Ptr = initInstance_scalarWrapper((uint32)&Car_State_ETR07_Y.errors, sizeof(double), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Car_State_ETR07(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_Car_State_ETR07_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Car_State_ETR07
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Car_State_ETR07_ClassHeader =
    {0, 1, 0, 54 + 0, (MethodList *)0, (MethodList *)&RTWTop_Car_State_ETR07_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Car_State_ETR07_Class RTWTop_Car_State_ETR07_ClassObj = {{1, {&RTWTop_Car_State_ETR07_ClassHeader}, {0}}
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
struct RTWTop_Car_State_ETR07_Obj *initInstance_RTWTop_Car_State_ETR07(void)
{
    struct RTWTop_Car_State_ETR07_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Car_State_ETR07);
    return self;
}
void setDeltaT_Car_State_ETR07(void)
{
}
