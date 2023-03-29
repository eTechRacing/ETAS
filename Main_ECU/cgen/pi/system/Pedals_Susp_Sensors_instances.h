/*****************************************************************************
 *
 * Pedals_Susp_Sensors_instances.h
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
extern struct RTWTop_Pedals_Susp_Sensors_Obj *initModel_RTWTop_Pedals_Susp_Sensors(void);
/* Level 1 class object declaration */
extern struct RTWTop_Pedals_Susp_Sensors_Class RTWTop_Pedals_Susp_Sensors_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_Pedals_Susp_Sensors(struct RTWTop_Pedals_Susp_Sensors_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_Pedals_Susp_Sensors_Obj *initInstance_RTWTop_Pedals_Susp_Sensors(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_Pedals_Susp_Sensors(void);
/* Definition of the class structure */
struct RTWTop_Pedals_Susp_Sensors_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_B_bitsmax_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_B_bitsmax_n_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_B_bitsmax_o_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_B_bitsmax_p_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_B_sf_MATLABFunction_ZeroExperimental_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_B_sf_MATLABFunction_b_ZeroExperimental_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_B_sf_MATLABFunction_h_ZeroExperimental_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_B_sf_MATLABFunction_k_ZeroExperimental_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_DW_Z_E_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_DW_Z_E_d_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_DW_Z_E_h_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_DW_Z_E_p_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Brake_Light_Threshold_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Ctemuelles_Gain_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Ctemuelles_Gain_a_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Ctemuelles_Gain_e_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Ctemuelles_Gain_g_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_DataStoreMemory_InitialValue_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_DataStoreMemory_InitialValue_b_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_DataStoreMemory_InitialValue_l_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_DataStoreMemory_InitialValue_m_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Ltotal_Gain_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Ltotal_Gain_c_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Ltotal_Gain_h_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Ltotal_Gain_j_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_ON_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_Off_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_bitsmax_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_bitsmax_Value_b_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_bitsmax_Value_e_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_bitsmax_Value_o_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_max_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_max_Value_a_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_max_Value_f_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_min_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_min_Value_a_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_P_min_Value_g_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_U_APPS1_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_U_APPS2_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_U_BrakeSensor_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_U_Susp_F_L_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_U_Susp_F_R_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_U_Susp_R_L_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_U_Susp_R_R_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_Y_APPS1_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_Y_APPS2_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_Y_BrakeLight_Control_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_Y_BrakeSensor_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_Y_SUSP_F_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_Y_SUSP_F_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_Y_SUSP_R_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_Pedals_Susp_Sensors_Y_SUSP_R_R_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_Pedals_Susp_Sensors_Obj
{
    ASDObjectHeader objectHeader;
};
