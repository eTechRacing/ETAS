/*****************************************************************************
 *
 * Inverters_Action_instances.h
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
extern struct RTWTop_Inverters_Action_Obj *initModel_RTWTop_Inverters_Action(void);
/* Level 1 class object declaration */
extern struct RTWTop_Inverters_Action_Class RTWTop_Inverters_Action_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_Inverters_Action(struct RTWTop_Inverters_Action_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_Inverters_Action_Obj *initInstance_RTWTop_Inverters_Action(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_Inverters_Action(void);
/* Definition of the class structure */
struct RTWTop_Inverters_Action_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_B_Merge_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_B_Merge2_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_B_Merge2_p_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_B_subscribed_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_B_subscribed_b_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand_Divide_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_BitwiseOperator1_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_Current0to65535_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_Divide_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_ShiftArithmetic_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_b7tob0_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_BitwiseOperator1_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_Current0to65535_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_Divide_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_ShiftArithmetic_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_b7tob0_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_ConstB_TorqueCommand_m_Divide_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_DW_EnumerationCounter_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_DW_EnumerationCounter_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_DW_LastAction_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_DW_LastAction_k_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_U_InvertersAction_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_U_current_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_U_current_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_Y_Inverter_L_RegID_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_Y_Inverter_L_b15tob8_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_Y_Inverter_L_b7tob0_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_Y_Inverter_R_RegID_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_Y_Inverter_R_b15tob8_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_Y_Inverter_R_b7tob0_Ptr;
    scalarWrapper_Obj *RTWWrapper_Inverters_Action_Y_InvertersSubscribed_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_Inverters_Action_Obj
{
    ASDObjectHeader objectHeader;
};
