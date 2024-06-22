/*****************************************************************************
 *
 * VDCv2mk2_instances.h
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
extern struct RTWTop_VDCv2mk2_Obj *initModel_RTWTop_VDCv2mk2(void);
/* Level 1 class object declaration */
extern struct RTWTop_VDCv2mk2_Class RTWTop_VDCv2mk2_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_VDCv2mk2(struct RTWTop_VDCv2mk2_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_VDCv2mk2_Obj *initInstance_RTWTop_VDCv2mk2(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_VDCv2mk2(void);
/* Definition of the class structure */
struct RTWTop_VDCv2mk2_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_Merge_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_Merge1_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_Merge1_f_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_Merge2_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_Merge3_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_RigidAxlewithTC2024_Motor_Torque_RL_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_RigidAxlewithTC2024_Motor_Torque_RR_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_RigidAxlewithTC2024_o_Motor_Torque_RL_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_RigidAxlewithTC2024_o_Motor_Torque_RR_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_TC2024_Motor_Torque_RL_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_TC2024_Motor_Torque_RR_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_Torquedemandedbythedriver_a_Throttle_Torque_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_Torquedemandedbythedriver_k_Throttle_Torque_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_sf_Torquedemandedbythedriver_m_Throttle_Torque_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_B_state_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_DW_A_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_DW_ERROR_Counter_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_APPS1_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_APPS2_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Accumulator_Current_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Accumulator_Voltage_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_BrakePedal_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Car_State_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_CriticalDisconnection_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Disconnection_Mode_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_RL_Vel_ms_Wheel_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_RL_rads_Motor_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_RR_Vel_ms_Wheel_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_RR_rads_Motor_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_RacingMode_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Shutdown_PackageIntck_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_SoC_High_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_SteeringSensor_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Susp_F_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Susp_F_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Susp_R_L_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_Susp_R_R_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_TorqueEnable_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_ACCEL_X_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_ACCEL_Y_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_ACCEL_Z_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_GYRO_X_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_GYRO_Y_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_GYRO_Z_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_PITCH_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_ROLL_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_SlipAngle_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_Vel_X_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_Vel_Y_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_Vel_Z_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_U_el_YAW_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_APPS_Implausibility_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_BrakeLight_Control_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_Power_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_PowerLimitReached_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_PowerMean500ms_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_TV_Mode_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_Torque_L_out_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_Torque_OK_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_Torque_R_out_Ptr;
    scalarWrapper_Obj *RTWWrapper_VDCv2mk2_Y_VDC_Max_Tyre_Slip_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_VDCv2mk2_Obj
{
    ASDObjectHeader objectHeader;
};
