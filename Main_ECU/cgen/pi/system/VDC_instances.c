/*****************************************************************************
 *
 * VDC_instances.c
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
#include "VDC.h"
#include "VDC_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "VDC_instances.h"
extern    B_VDC_T VDC_B;
extern    DW_VDC_T VDC_DW;
extern    ExtU_VDC_T VDC_U;
extern    ExtY_VDC_T VDC_Y;
/* Initialization of Simulink model */
struct RTWTop_VDC_Obj *initModel_RTWTop_VDC(void)
{
    struct RTWTop_VDC_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_VDC (&RTWTop_VDC_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_VDC();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_VDC(struct RTWTop_VDC_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_VDC_B_Merge_Ptr = initInstance_scalarWrapper((void*)&VDC_B.Merge, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_Merge1_Ptr = initInstance_scalarWrapper((void*)&VDC_B.Merge1, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_Merge1_f_Ptr = initInstance_scalarWrapper((void*)&VDC_B.Merge1_f, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_Merge2_Ptr = initInstance_scalarWrapper((void*)&VDC_B.Merge2, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_Merge2_l_Ptr = initInstance_scalarWrapper((void*)&VDC_B.Merge2_l, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_Merge3_Ptr = initInstance_scalarWrapper((void*)&VDC_B.Merge3, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_Merge3_n_Ptr = initInstance_scalarWrapper((void*)&VDC_B.Merge3_n, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_Merge4_Ptr = initInstance_scalarWrapper((void*)&VDC_B.Merge4, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_sf_MATLABFunction_Torque_L_Nm_Ptr = initInstance_scalarWrapper((void*)&VDC_B.sf_MATLABFunction.Torque_L_Nm, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_sf_MATLABFunction_Torque_R_Nm_Ptr = initInstance_scalarWrapper((void*)&VDC_B.sf_MATLABFunction.Torque_R_Nm, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_sf_MATLABFunction_a_Torque_L_Nm_Ptr = initInstance_scalarWrapper((void*)&VDC_B.sf_MATLABFunction_a.Torque_L_Nm, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_sf_MATLABFunction_a_Torque_R_Nm_Ptr = initInstance_scalarWrapper((void*)&VDC_B.sf_MATLABFunction_a.Torque_R_Nm, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_sf_Torquedemandedbythedriver_a_Throttle_Torque_Ptr = initInstance_scalarWrapper((void*)&VDC_B.sf_Torquedemandedbythedriver_a.Throttle_Torque, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_sf_Torquedemandedbythedriver_k_Throttle_Torque_Ptr = initInstance_scalarWrapper((void*)&VDC_B.sf_Torquedemandedbythedriver_k.Throttle_Torque, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_sf_Torquedemandedbythedriver_m_Throttle_Torque_Ptr = initInstance_scalarWrapper((void*)&VDC_B.sf_Torquedemandedbythedriver_m.Throttle_Torque, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_B_state_Ptr = initInstance_scalarWrapper((void*)&VDC_B.state, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_DW_ERROR_Counter_Ptr = initInstance_scalarWrapper((void*)&VDC_DW.ERROR_Counter, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_APPS1_Value_Ptr = initInstance_scalarWrapper((void*)&VDC_U.APPS1_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_APPS2_Value_Ptr = initInstance_scalarWrapper((void*)&VDC_U.APPS2_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_Accumulator_Voltage_Ptr = initInstance_scalarWrapper((void*)&VDC_U.Accumulator_Voltage, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_BrakePedal_Value_Ptr = initInstance_scalarWrapper((void*)&VDC_U.BrakePedal_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_Car_State_Ptr = initInstance_scalarWrapper((void*)&VDC_U.Car_State, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_CriticalDisconnection_Ptr = initInstance_scalarWrapper((void*)&VDC_U.CriticalDisconnection, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_Disconnection_Mode_Ptr = initInstance_scalarWrapper((void*)&VDC_U.Disconnection_Mode, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_RL_Vel_ms_Wheel_Ptr = initInstance_scalarWrapper((void*)&VDC_U.RL_Vel_ms_Wheel, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_RL_rads_Motor_Ptr = initInstance_scalarWrapper((void*)&VDC_U.RL_rads_Motor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_RR_Vel_ms_Wheel_Ptr = initInstance_scalarWrapper((void*)&VDC_U.RR_Vel_ms_Wheel, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_RR_rads_Motor_Ptr = initInstance_scalarWrapper((void*)&VDC_U.RR_rads_Motor, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_RacingMode_Ptr = initInstance_scalarWrapper((void*)&VDC_U.RacingMode, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_Shutdown_PackageIntck_Ptr = initInstance_scalarWrapper((void*)&VDC_U.Shutdown_PackageIntck, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_SoC_High_Ptr = initInstance_scalarWrapper((void*)&VDC_U.SoC_High, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_SteeringSensor_Value_Ptr = initInstance_scalarWrapper((void*)&VDC_U.SteeringSensor_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_Susp_F_L_Ptr = initInstance_scalarWrapper((void*)&VDC_U.Susp_F_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_Susp_F_R_Ptr = initInstance_scalarWrapper((void*)&VDC_U.Susp_F_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_Susp_R_L_Ptr = initInstance_scalarWrapper((void*)&VDC_U.Susp_R_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_Susp_R_R_Ptr = initInstance_scalarWrapper((void*)&VDC_U.Susp_R_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_TorqueEnable_Ptr = initInstance_scalarWrapper((void*)&VDC_U.TorqueEnable, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_ACCEL_X_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_ACCEL_X, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_ACCEL_Y_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_ACCEL_Y, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_ACCEL_Z_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_ACCEL_Z, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_GYRO_X_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_GYRO_X, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_GYRO_Y_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_GYRO_Y, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_GYRO_Z_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_GYRO_Z, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_PITCH_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_PITCH, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_ROLL_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_ROLL, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_SlipAngle_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_SlipAngle, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_Vel_X_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_Vel_X, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_Vel_Y_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_Vel_Y, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_Vel_Z_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_Vel_Z, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_U_el_YAW_Ptr = initInstance_scalarWrapper((void*)&VDC_U.el_YAW, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_APPS_Implausibility_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.APPS_Implausibility, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_BrakeLight_Control_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.BrakeLight_Control, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_Regenerative_Enable_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.Regenerative_Enable, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_Sensorics_Mode_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.Sensorics_Mode, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_Throttle_Torque_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.Throttle_Torque, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_Torque_L_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.Torque_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_Torque_OK_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.Torque_OK, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_Torque_R_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.Torque_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_VDC_Y_VDC_Max_Tyre_Slip_Ptr = initInstance_scalarWrapper((void*)&VDC_Y.VDC_Max_Tyre_Slip, sizeof(double), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_VDC(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_VDC_ClassMethodList =
{
    (MethodPtr)_L1_getPid_VDC
};
/* Definition of the class header */
static ASDClassHeader RTWTop_VDC_ClassHeader =
    {0, 1, 0, 59 + 0, (MethodList *)0, (MethodList *)&RTWTop_VDC_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_VDC_Class RTWTop_VDC_ClassObj = {{1, {&RTWTop_VDC_ClassHeader}, {0}}
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
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
};
/* Object instantiation */
struct RTWTop_VDC_Obj *initInstance_RTWTop_VDC(void)
{
    struct RTWTop_VDC_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_VDC);
    return self;
}
void setDeltaT_VDC(void)
{
}
