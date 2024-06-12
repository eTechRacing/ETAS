/*****************************************************************************
 *
 * Car_State_instances.h
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2024 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
/* Model initialization function prototype */
extern struct RTWTop_Car_State_Obj *initModel_RTWTop_Car_State(void);
/* Level 1 class object declaration */
extern struct RTWTop_Car_State_Class RTWTop_Car_State_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_Car_State(struct RTWTop_Car_State_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_Car_State_Obj *initInstance_RTWTop_Car_State(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_Car_State(void);
/* Definition of the class structure */
struct RTWTop_Car_State_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_Car_State_B_Merge_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_DW_A_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_AIRs_State_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_Accumulator_Voltage_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_BrakePedal_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_Critical_CAN_Disconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_EnableDrive_Order_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_InvertersMinDCBus_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_InvertersSubscribed_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_PrechargeRequest_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_U_Shutdown_PackageIntck_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_AIRs_Request_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_Car_OK_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_Car_State_f_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_InvertersAction_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_PrechargeAssert_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_Precharge_Percentage_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_Precharge_Voltage_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_Relay_Error_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_TorqueEnable_Ptr;
    scalarWrapper_Obj *RTWWrapper_Car_State_Y_errors_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_Car_State_Obj
{
    ASDObjectHeader objectHeader;
};
