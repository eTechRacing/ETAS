/*****************************************************************************
 *
 * Disconnections_instances.h
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2007 ETAS (ETAS GmbH)
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
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_b_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_d_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_f_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_h_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_he_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_B_Merge_j_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_A_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_a_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_ar_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_c_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_c0_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_g_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_gx_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_j_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_je_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_l_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Last_alive_o_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Tot_Errors_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Tot_Errors_h_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Tot_Errors_j_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Tot_Errors_k_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_DW_Tot_Errors_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_c_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_d_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_e_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_h_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_i_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_ic_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_j_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_l_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Constant_Value_o_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory1_InitialValue_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory1_InitialValue_b_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory1_InitialValue_c_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory1_InitialValue_d_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory1_InitialValue_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_b_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_ba_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_c_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_d_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_f_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_j_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_jc_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_k_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_kg_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_ks_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_DataStoreMemory_InitialValue_o_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Merge_InitialOutput_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Merge_InitialOutput_a_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Merge_InitialOutput_b_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Merge_InitialOutput_l_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Merge_InitialOutput_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Merge_InitialOutput_o_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_P_Merge_InitialOutput_p_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_ADCAN_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_APPS1_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_APPS2_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Accel_F_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Accel_R_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_BMS_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_BrakeSensor_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Dash_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Gyroscope_F_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Gyroscope_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_LV_Derivation_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Shutdown_Alive_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_SteeringSensor_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Susp_F_L_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Susp_F_R_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Susp_R_L_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_U_Susp_R_R_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_CounterOut_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_CriticalDisconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Critical_CAN_Disconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Critical_Signal_Disconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_ADCAN_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_APPS1_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_APPS2_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Accel_F_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Accel_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_BMS_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Brake_Sensor_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_DashBoard_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Gyroscope_F_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Gyroscope_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_LV_Derivation_Ptr;
    scalarWrapper_Obj *RTWWrapper_Disconnections_Y_Disconnection_Shutdown_Ptr;
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
