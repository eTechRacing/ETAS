/*****************************************************************************
 *
 * vdc_r2022a_instances.h
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
extern struct RTWTop_vdc_r2022a_Obj *initModel_RTWTop_vdc_r2022a(void);
/* Level 1 class object declaration */
extern struct RTWTop_vdc_r2022a_Class RTWTop_vdc_r2022a_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_vdc_r2022a(struct RTWTop_vdc_r2022a_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_vdc_r2022a_Obj *initInstance_RTWTop_vdc_r2022a(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_vdc_r2022a(void);
/* Definition of the class structure */
struct RTWTop_vdc_r2022a_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_B_Merge1_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_B_Merge2_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_B_Merge3_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_DW_A_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_DW_ERROR_Counter_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_APPS1_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_APPS2_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Accumulator_Current_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Accumulator_Voltage_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_BrakeSensor_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Car_State_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_CriticalDisconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_RL_Vel_ms_Wheel_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_RL_rads_Motor_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_RR_Vel_ms_Wheel_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_RR_rads_Motor_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Shutdown_PackageIntck_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_SteeringSensor_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Susp_F_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Susp_F_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Susp_R_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Susp_R_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_TV_Mode_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_TorqueEnable_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_VDC_Max_tire_slip_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_Workshop_Mode_Enable_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_ACCEL_X_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_ACCEL_Y_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_ACCEL_Z_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_GYRO_X_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_GYRO_Y_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_GYRO_Z_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_PITCH_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_ROLL_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_Vel_X_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_Vel_Y_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_Vel_Z_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_U_el_YAW_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_Y_APPS_Implausibility_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_Y_Power_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_Y_PowerLimitReached_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_Y_PowerMean500ms_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_Y_TC_WARNING_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_Y_Torque_L_out_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_Y_Torque_OK_Ptr;
    scalarWrapper_Obj *RTWWrapper_vdc_r2022a_Y_Torque_R_out_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_vdc_r2022a_Obj
{
    ASDObjectHeader objectHeader;
};