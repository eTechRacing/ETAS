/*****************************************************************************
 *
 * Sensors_instances.h
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
extern struct RTWTop_Sensors_Obj *initModel_RTWTop_Sensors(void);
/* Level 1 class object declaration */
extern struct RTWTop_Sensors_Class RTWTop_Sensors_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_Sensors(struct RTWTop_Sensors_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_Sensors_Obj *initInstance_RTWTop_Sensors(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_Sensors(void);
/* Definition of the class structure */
struct RTWTop_Sensors_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_Sensors_ConstB_Subtract_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_ConstB_Subtract_a_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_ConstB_Subtract_e_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_ConstB_Subtract_n_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_ConstB_Subtract_p_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_ConstB_Sum1_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_ConstB_Sum1_c_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_ConstB_Sum1_f_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_DW_Previous_IN_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_DW_Previous_OUT_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_U_APPS1_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_U_APPS2_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_U_BrakePedal_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_U_SteeringSensor_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_U_Susp_F_L_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_U_Susp_F_R_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_U_Susp_R_L_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_U_Susp_R_R_Bits_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_Y_APPS1_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_Y_APPS2_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_Y_BrakePedal_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_Y_SUSP_F_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_Y_SUSP_F_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_Y_SUSP_R_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_Y_SUSP_R_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_Sensors_Y_SteeringSensor_Value_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_Sensors_Obj
{
    ASDObjectHeader objectHeader;
};
