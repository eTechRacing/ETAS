/* This is an automatically generated file */
/* DO NOT EDIT THIS FILE */
/* File generated for project "os_config" */
/* Last edited 'unknown' */
/* File generated 'Sat Jun 18 14:42:52 2022' */
/* Target variant 'ES900' */

/* The file must only be included for the implementation of code for ISR(etasActivateTaskIsr) */

#ifndef OS_ISR_etasActivateTaskIsr
#define OS_ISR_etasActivateTaskIsr

#define OS_ISR

#include "osekcomn.h"

#ifdef OS_FILE_INCLUDED
 #error Multiple File Inclusion
#else /* OS_FILE_INCLUDED */
 #define OS_FILE_INCLUDED
#endif /* OS_FILE_INCLUDED */

#define etasActivateTaskIsr_default_profile (0)	/* Profile */
#define OSALARM_etasWatchdogAlarm (0)	/* Alarm */
#define OSALARM_SYNC_25MS (0)	/* Alarm */
#define OSALARM_TIMER_1000MS (0)	/* Alarm */
#define OSALARM_TIMER_100MS (0)	/* Alarm */
#define OSALARM_TIMER_25MS (0)	/* Alarm */
#define OSALARM_TIMER_INV (0)	/* Alarm */

#define ActivateTask_etasConfigTask() ActivateTask(etasConfigTask)
#define ActivateTask_etasL1Task() ActivateTask(etasL1Task)
#define ActivateTask_SWT_CAN1_AP_BMS_AIRs_State() ActivateTask(SWT_CAN1_AP_BMS_AIRs_State)
#define ActivateTask_SWT_CAN1_AP_BMS_BatteryTemperatures() ActivateTask(SWT_CAN1_AP_BMS_BatteryTemperatures)
#define ActivateTask_SWT_CAN1_AP_BMS_ChargerParameters() ActivateTask(SWT_CAN1_AP_BMS_ChargerParameters)
#define ActivateTask_SWT_CAN1_AP_BMS_Current_SOC() ActivateTask(SWT_CAN1_AP_BMS_Current_SOC)
#define ActivateTask_SWT_CAN1_AP_BMS_Current_SOC_SOH() ActivateTask(SWT_CAN1_AP_BMS_Current_SOC_SOH)
#define ActivateTask_SWT_CAN1_AP_BMS_Current_SOC_SOH1() ActivateTask(SWT_CAN1_AP_BMS_Current_SOC_SOH1)
#define ActivateTask_SWT_CAN1_AP_BMS_OnBoardTemperatures() ActivateTask(SWT_CAN1_AP_BMS_OnBoardTemperatures)
#define ActivateTask_SWT_CAN1_AP_BMS_OnBoardTemperatures1() ActivateTask(SWT_CAN1_AP_BMS_OnBoardTemperatures1)
#define ActivateTask_SWT_CAN1_AP_BMS_StateAndFailReport() ActivateTask(SWT_CAN1_AP_BMS_StateAndFailReport)
#define ActivateTask_SWT_CAN1_AP_BMS_Voltages() ActivateTask(SWT_CAN1_AP_BMS_Voltages)
#define ActivateTask_SWT_CAN1_AP_DASH_CustomMode() ActivateTask(SWT_CAN1_AP_DASH_CustomMode)
#define ActivateTask_SWT_CAN1_AP_DASH_EnableDrive() ActivateTask(SWT_CAN1_AP_DASH_EnableDrive)
#define ActivateTask_SWT_CAN1_AP_DASH_Mode() ActivateTask(SWT_CAN1_AP_DASH_Mode)
#define ActivateTask_SWT_CAN1_AP_DASH_PrechargeRequest() ActivateTask(SWT_CAN1_AP_DASH_PrechargeRequest)
#define ActivateTask_SWT_CAN1_AP_DASH_TorqueLockOn() ActivateTask(SWT_CAN1_AP_DASH_TorqueLockOn)
#define ActivateTask_SWT_CAN1_AP_Inverter_L_Tx() ActivateTask(SWT_CAN1_AP_Inverter_L_Tx)
#define ActivateTask_SWT_CAN1_AP_Inverter_R_Tx() ActivateTask(SWT_CAN1_AP_Inverter_R_Tx)
#define ActivateTask_SWT_CAN1_AP_SHUTDOWN_State() ActivateTask(SWT_CAN1_AP_SHUTDOWN_State)
#define ActivateTask_SWT_CAN1_NM_BMS_Keep_Alive() ActivateTask(SWT_CAN1_NM_BMS_Keep_Alive)
#define ActivateTask_SWT_CAN1_NM_DASH_Keep_Alive() ActivateTask(SWT_CAN1_NM_DASH_Keep_Alive)
#define ActivateTask_SWT_CAN1_NM_SHUTDOWN_Keep_Alive() ActivateTask(SWT_CAN1_NM_SHUTDOWN_Keep_Alive)
#define ActivateTask_SWT_CAN2_AP_ACCEL_F_Data() ActivateTask(SWT_CAN2_AP_ACCEL_F_Data)
#define ActivateTask_SWT_CAN2_AP_ACCEL_R_Data() ActivateTask(SWT_CAN2_AP_ACCEL_R_Data)
#define ActivateTask_SWT_CAN2_AP_ACCEL_R_Data2() ActivateTask(SWT_CAN2_AP_ACCEL_R_Data2)
#define ActivateTask_SWT_CAN2_AP_ADCAN_Data1() ActivateTask(SWT_CAN2_AP_ADCAN_Data1)
#define ActivateTask_SWT_CAN2_AP_ADCAN_Data2() ActivateTask(SWT_CAN2_AP_ADCAN_Data2)
#define ActivateTask_SWT_CAN2_AP_ELIPSE_VelAngular() ActivateTask(SWT_CAN2_AP_ELIPSE_VelAngular)
#define ActivateTask_SWT_CAN2_AP_ELIPSE_VelBody() ActivateTask(SWT_CAN2_AP_ELIPSE_VelBody)
#define ActivateTask_SWT_CAN2_AP_LV_Derivation_LVData() ActivateTask(SWT_CAN2_AP_LV_Derivation_LVData)
#define ActivateTask_SWT_CAN2_NM_ACCEL_F_Keep_Alive() ActivateTask(SWT_CAN2_NM_ACCEL_F_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_ACCEL_R_Keep_Alive() ActivateTask(SWT_CAN2_NM_ACCEL_R_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_ADCAN_Keep_Alive() ActivateTask(SWT_CAN2_NM_ADCAN_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_LV_Derivation_Keep_Alive() ActivateTask(SWT_CAN2_NM_LV_Derivation_Keep_Alive)
#define ActivateTask_Sync_25ms() ActivateTask(Sync_25ms)
#define ActivateTask_Timer_1000ms() ActivateTask(Timer_1000ms)
#define ActivateTask_Timer_100ms() ActivateTask(Timer_100ms)
#define ActivateTask_Timer_25ms() ActivateTask(Timer_25ms)
#define ActivateTask_Timer_Inv() ActivateTask(Timer_Inv)

#endif /* OS_ISR_etasActivateTaskIsr */
