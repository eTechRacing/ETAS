/*****************************************************************************
 *
 * Disconnections_instances.h
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
extern struct RTWTop_Disconnections_Obj *initModel_RTWTop_Disconnections(void);
/* Level 1 class object declaration */
extern struct RTWTop_Disconnections_Class RTWTop_Disconnections_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_Disconnections(struct RTWTop_Disconnections_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_Disconnections_Obj *initInstance_RTWTop_Disconnections(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_Disconnections(void);
/* Definition of the class structure */
struct RTWTop_Disconnections_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_d_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_g_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_j_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_A_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_e_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_g_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_n_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_n0_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_o_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_p_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_pb_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Tot_Errors_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Tot_Errors_f_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Tot_Errors_h_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_APPS1_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_APPS2_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_BMS_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_BrakePedal_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Dash_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Ellipse_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Front_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Rear_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_SteeringSensor_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Susp_F_L_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Susp_F_R_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Susp_R_L_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Susp_R_R_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_CriticalDisconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Critical_CAN_Disconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Critical_Signal_Disconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_APPS1_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_APPS2_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_BMS_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_BrakePedal_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_DashBoard_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Ellipse_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Front_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Rear_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_SteeringSensor_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Susp_F_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Susp_F_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Susp_R_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Susp_R_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_TV_mode_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_Disconnections_Obj
{
    ASDObjectHeader objectHeader;
};