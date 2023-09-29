/* This is an automatically generated file */
/* DO NOT EDIT THIS FILE */
/* File generated for project "os_config" */
/* Last edited 'unknown' */
/* File generated 'Sat Jun 10 11:02:44 2023' */
/* Target variant 'ES900' */

/* The file must only be included for the implementation of code for TASK(Timer_100ms) */

#ifndef OS_TASK_Timer_100ms
#define OS_TASK_Timer_100ms

#define OS_HEAVYWEIGHT
#include "osekcomn.h"

#ifdef OS_FILE_INCLUDED
 #error Multiple File Inclusion
#else /* OS_FILE_INCLUDED */
 #define OS_FILE_INCLUDED
#endif /* OS_FILE_INCLUDED */

#define Timer_100ms_default_profile (0)	/* Profile */
#define OSALARM_etasWatchdogAlarm (0)	/* Alarm */
#define OSALARM_SYNC_25MS (0)	/* Alarm */
#define OSALARM_TIMER_1000MS (0)	/* Alarm */
#define OSALARM_TIMER_100MS (0)	/* Alarm */
#define TIMER_100MS_response1 (0)	/* Critical execution */
#define OSALARM_TIMER_25MS (0)	/* Alarm */
#define OSALARM_TIMER_INV (0)	/* Alarm */

DeclareResource(RES_SCHEDULER);
#define GetResource_RES_SCHEDULER() GetResource(RES_SCHEDULER)
#define ReleaseResource_RES_SCHEDULER() ReleaseResource(RES_SCHEDULER)
#define ActivateTask_etasConfigTask() ActivateTask(etasConfigTask)
#define ChainTask_etasConfigTask() ChainTask(etasConfigTask)
#define ActivateTask_etasL1Task() ActivateTask(etasL1Task)
#define ChainTask_etasL1Task() ChainTask(etasL1Task)
#define ActivateTask_SWT_CAN1_AP_BMS_AIRs_State() ActivateTask(SWT_CAN1_AP_BMS_AIRs_State)
#define ChainTask_SWT_CAN1_AP_BMS_AIRs_State() ChainTask(SWT_CAN1_AP_BMS_AIRs_State)
#define ActivateTask_SWT_CAN1_AP_BMS_BatteryTemperatures() ActivateTask(SWT_CAN1_AP_BMS_BatteryTemperatures)
#define ChainTask_SWT_CAN1_AP_BMS_BatteryTemperatures() ChainTask(SWT_CAN1_AP_BMS_BatteryTemperatures)
#define ActivateTask_SWT_CAN1_AP_BMS_ChargerParameters() ActivateTask(SWT_CAN1_AP_BMS_ChargerParameters)
#define ChainTask_SWT_CAN1_AP_BMS_ChargerParameters() ChainTask(SWT_CAN1_AP_BMS_ChargerParameters)
#define ActivateTask_SWT_CAN1_AP_BMS_Current_SOC_SOH() ActivateTask(SWT_CAN1_AP_BMS_Current_SOC_SOH)
#define ChainTask_SWT_CAN1_AP_BMS_Current_SOC_SOH() ChainTask(SWT_CAN1_AP_BMS_Current_SOC_SOH)
#define ActivateTask_SWT_CAN1_AP_BMS_OnBoardTemperatures() ActivateTask(SWT_CAN1_AP_BMS_OnBoardTemperatures)
#define ChainTask_SWT_CAN1_AP_BMS_OnBoardTemperatures() ChainTask(SWT_CAN1_AP_BMS_OnBoardTemperatures)
#define ActivateTask_SWT_CAN1_AP_BMS_StateAndFailReport() ActivateTask(SWT_CAN1_AP_BMS_StateAndFailReport)
#define ChainTask_SWT_CAN1_AP_BMS_StateAndFailReport() ChainTask(SWT_CAN1_AP_BMS_StateAndFailReport)
#define ActivateTask_SWT_CAN1_AP_BMS_Voltages() ActivateTask(SWT_CAN1_AP_BMS_Voltages)
#define ChainTask_SWT_CAN1_AP_BMS_Voltages() ChainTask(SWT_CAN1_AP_BMS_Voltages)
#define ActivateTask_SWT_CAN1_AP_DASH_CustomMode() ActivateTask(SWT_CAN1_AP_DASH_CustomMode)
#define ChainTask_SWT_CAN1_AP_DASH_CustomMode() ChainTask(SWT_CAN1_AP_DASH_CustomMode)
#define ActivateTask_SWT_CAN1_AP_DASH_EnableDrive() ActivateTask(SWT_CAN1_AP_DASH_EnableDrive)
#define ChainTask_SWT_CAN1_AP_DASH_EnableDrive() ChainTask(SWT_CAN1_AP_DASH_EnableDrive)
#define ActivateTask_SWT_CAN1_AP_DASH_Mode() ActivateTask(SWT_CAN1_AP_DASH_Mode)
#define ChainTask_SWT_CAN1_AP_DASH_Mode() ChainTask(SWT_CAN1_AP_DASH_Mode)
#define ActivateTask_SWT_CAN1_AP_DASH_PrechargeRequest() ActivateTask(SWT_CAN1_AP_DASH_PrechargeRequest)
#define ChainTask_SWT_CAN1_AP_DASH_PrechargeRequest() ChainTask(SWT_CAN1_AP_DASH_PrechargeRequest)
#define ActivateTask_SWT_CAN1_AP_DASH_TorqueLockOn() ActivateTask(SWT_CAN1_AP_DASH_TorqueLockOn)
#define ChainTask_SWT_CAN1_AP_DASH_TorqueLockOn() ChainTask(SWT_CAN1_AP_DASH_TorqueLockOn)
#define ActivateTask_SWT_CAN1_AP_Inverter_L_Tx() ActivateTask(SWT_CAN1_AP_Inverter_L_Tx)
#define ChainTask_SWT_CAN1_AP_Inverter_L_Tx() ChainTask(SWT_CAN1_AP_Inverter_L_Tx)
#define ActivateTask_SWT_CAN1_AP_Inverter_R_Tx() ActivateTask(SWT_CAN1_AP_Inverter_R_Tx)
#define ChainTask_SWT_CAN1_AP_Inverter_R_Tx() ChainTask(SWT_CAN1_AP_Inverter_R_Tx)
#define ActivateTask_SWT_CAN1_AP_SHUTDOWN_State() ActivateTask(SWT_CAN1_AP_SHUTDOWN_State)
#define ChainTask_SWT_CAN1_AP_SHUTDOWN_State() ChainTask(SWT_CAN1_AP_SHUTDOWN_State)
#define ActivateTask_SWT_CAN1_NM_BMS_Keep_Alive() ActivateTask(SWT_CAN1_NM_BMS_Keep_Alive)
#define ChainTask_SWT_CAN1_NM_BMS_Keep_Alive() ChainTask(SWT_CAN1_NM_BMS_Keep_Alive)
#define ActivateTask_SWT_CAN1_NM_DASH_Keep_Alive() ActivateTask(SWT_CAN1_NM_DASH_Keep_Alive)
#define ChainTask_SWT_CAN1_NM_DASH_Keep_Alive() ChainTask(SWT_CAN1_NM_DASH_Keep_Alive)
#define ActivateTask_SWT_CAN1_NM_SHUTDOWN_Keep_Alive() ActivateTask(SWT_CAN1_NM_SHUTDOWN_Keep_Alive)
#define ChainTask_SWT_CAN1_NM_SHUTDOWN_Keep_Alive() ChainTask(SWT_CAN1_NM_SHUTDOWN_Keep_Alive)
#define ActivateTask_SWT_CAN2_AP_ACCEL_F_Data() ActivateTask(SWT_CAN2_AP_ACCEL_F_Data)
#define ChainTask_SWT_CAN2_AP_ACCEL_F_Data() ChainTask(SWT_CAN2_AP_ACCEL_F_Data)
#define ActivateTask_SWT_CAN2_AP_ACCEL_R_Data() ActivateTask(SWT_CAN2_AP_ACCEL_R_Data)
#define ChainTask_SWT_CAN2_AP_ACCEL_R_Data() ChainTask(SWT_CAN2_AP_ACCEL_R_Data)
#define ActivateTask_SWT_CAN2_AP_ACCEL_R_Data2() ActivateTask(SWT_CAN2_AP_ACCEL_R_Data2)
#define ChainTask_SWT_CAN2_AP_ACCEL_R_Data2() ChainTask(SWT_CAN2_AP_ACCEL_R_Data2)
#define ActivateTask_SWT_CAN2_AP_ADCAN_Data1() ActivateTask(SWT_CAN2_AP_ADCAN_Data1)
#define ChainTask_SWT_CAN2_AP_ADCAN_Data1() ChainTask(SWT_CAN2_AP_ADCAN_Data1)
#define ActivateTask_SWT_CAN2_AP_ADCAN_Data2() ActivateTask(SWT_CAN2_AP_ADCAN_Data2)
#define ChainTask_SWT_CAN2_AP_ADCAN_Data2() ChainTask(SWT_CAN2_AP_ADCAN_Data2)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_EULER() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_EULER)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_EKF_EULER() ChainTask(SWT_CAN2_AP_ELLIPSE_EKF_EULER)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_POS() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_POS)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_EKF_POS() ChainTask(SWT_CAN2_AP_ELLIPSE_EKF_POS)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_VEL_BODY() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_VEL_BODY)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_EKF_VEL_BODY() ChainTask(SWT_CAN2_AP_ELLIPSE_EKF_VEL_BODY)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL() ActivateTask(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL() ChainTask(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_IMU_GYRO() ActivateTask(SWT_CAN2_AP_ELLIPSE_IMU_GYRO)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_IMU_GYRO() ChainTask(SWT_CAN2_AP_ELLIPSE_IMU_GYRO)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_MAG() ActivateTask(SWT_CAN2_AP_ELLIPSE_MAG)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_MAG() ChainTask(SWT_CAN2_AP_ELLIPSE_MAG)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_SLIP_CURV() ActivateTask(SWT_CAN2_AP_ELLIPSE_SLIP_CURV)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_SLIP_CURV() ChainTask(SWT_CAN2_AP_ELLIPSE_SLIP_CURV)
#define ActivateTask_SWT_CAN2_AP_LV_Derivation_LVData() ActivateTask(SWT_CAN2_AP_LV_Derivation_LVData)
#define ChainTask_SWT_CAN2_AP_LV_Derivation_LVData() ChainTask(SWT_CAN2_AP_LV_Derivation_LVData)
#define ActivateTask_SWT_CAN2_NM_ACCEL_F_Keep_Alive() ActivateTask(SWT_CAN2_NM_ACCEL_F_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_ACCEL_F_Keep_Alive() ChainTask(SWT_CAN2_NM_ACCEL_F_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_ACCEL_R_Keep_Alive() ActivateTask(SWT_CAN2_NM_ACCEL_R_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_ACCEL_R_Keep_Alive() ChainTask(SWT_CAN2_NM_ACCEL_R_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_ADCAN_Keep_Alive() ActivateTask(SWT_CAN2_NM_ADCAN_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_ADCAN_Keep_Alive() ChainTask(SWT_CAN2_NM_ADCAN_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_ELLIPSE_Status() ActivateTask(SWT_CAN2_NM_ELLIPSE_Status)
#define ChainTask_SWT_CAN2_NM_ELLIPSE_Status() ChainTask(SWT_CAN2_NM_ELLIPSE_Status)
#define ActivateTask_SWT_CAN2_NM_LV_Derivation_Keep_Alive() ActivateTask(SWT_CAN2_NM_LV_Derivation_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_LV_Derivation_Keep_Alive() ChainTask(SWT_CAN2_NM_LV_Derivation_Keep_Alive)
#define ActivateTask_Sync_25ms() ActivateTask(Sync_25ms)
#define ChainTask_Sync_25ms() ChainTask(Sync_25ms)
#define ActivateTask_Timer_1000ms() ActivateTask(Timer_1000ms)
#define ChainTask_Timer_1000ms() ChainTask(Timer_1000ms)
#define ActivateTask_Timer_100ms() ActivateTask(Timer_100ms)
#define ChainTask_Timer_100ms() ChainTask(Timer_100ms)
#define ActivateTask_Timer_25ms() ActivateTask(Timer_25ms)
#define ChainTask_Timer_25ms() ChainTask(Timer_25ms)
#define ActivateTask_Timer_Inv() ActivateTask(Timer_Inv)
#define ChainTask_Timer_Inv() ChainTask(Timer_Inv)

#endif /* OS_TASK_Timer_100ms */
