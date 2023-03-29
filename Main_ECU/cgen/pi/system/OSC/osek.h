/* This is an automatically generated file */
/* DO NOT EDIT THIS FILE */
/* File generated for project "os_config" */
/* Last edited 'unknown' */
/* File generated 'Wed Mar 29 14:07:40 2023' */
/* Target variant 'ES900' */

/* The file must be included for general-purpose code, not tasks and ISRs */

#ifndef OS_OSEK_H
#define OS_OSEK_H

#include "osekcomn.h"
#include "osgen.h"

#ifdef OS_EXTENDED_BUILD
#define OSEK_NUM_TASKS (36U)
#define OSEK_NUM_RESOURCES (1U)
#define OSEK_NUM_ALARMS (6U)
#define OSEK_NUM_ACCESSORS (0U)
#endif /* OS_EXTENDED_BUILD */
#define OSEK_NUM_MESSAGES (0U)
#define OSEK_NUM_FLAGS (0U)
#define OSEK_NUM_PERIODICSCHEDULES (0U)
#define OSEK_NUM_PLANNEDSCHEDULES (0U)
#define OSEK_NUM_SCHEDULETABLES (0U)

#define osek_idle_task_default_profile (0)	/* Profile */
#define etasConfigTask_default_profile (0)	/* Profile */
#define etasL1Task_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_AIRs_State_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_BatteryTemperatures_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_ChargerParameters_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_Current_SOC_SOH_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_OnBoardTemperatures_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_StateAndFailReport_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_Voltages_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_DASH_CustomMode_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_DASH_EnableDrive_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_DASH_Mode_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_DASH_PrechargeRequest_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_DASH_TorqueLockOn_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_Inverter_L_Tx_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_Inverter_R_Tx_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_SHUTDOWN_State_default_profile (0)	/* Profile */
#define SWT_CAN1_NM_BMS_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN1_NM_DASH_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN1_NM_SHUTDOWN_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ACCEL_F_Data_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ACCEL_R_Data_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ACCEL_R_Data2_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ADCAN_Data1_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ADCAN_Data2_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_LV_Derivation_LVData_default_profile (0)	/* Profile */
#define SWT_CAN2_NM_ACCEL_F_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN2_NM_ACCEL_R_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN2_NM_ADCAN_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN2_NM_LV_Derivation_Keep_Alive_default_profile (0)	/* Profile */
#define Sync_25ms_default_profile (0)	/* Profile */
#define Timer_1000ms_default_profile (0)	/* Profile */
#define Timer_100ms_default_profile (0)	/* Profile */
#define Timer_25ms_default_profile (0)	/* Profile */
#define Timer_Inv_default_profile (0)	/* Profile */
#define etasTimerIsr_default_profile (0)	/* Profile */
#define etasL1Isr_default_profile (0)	/* Profile */
#define etasStopOsIsr_default_profile (0)	/* Profile */
#define etasActivateTaskIsr_default_profile (0)	/* Profile */
#define ISR_CAN1_default_profile (0)	/* Profile */
#define ISR_CAN2_default_profile (0)	/* Profile */
#define OSALARM_etasWatchdogAlarm (0)	/* Alarm */
#define OSALARM_SYNC_25MS (0)	/* Alarm */
#define SYNC_25MS_response1 (0)	/* Critical execution */
#define OSALARM_TIMER_1000MS (0)	/* Alarm */
#define TIMER_1000MS_response1 (0)	/* Critical execution */
#define OSALARM_TIMER_100MS (0)	/* Alarm */
#define TIMER_100MS_response1 (0)	/* Critical execution */
#define OSALARM_TIMER_25MS (0)	/* Alarm */
#define TIMER_25MS_response1 (0)	/* Critical execution */
#define OSALARM_TIMER_INV (0)	/* Alarm */
#define TIMER_INV_response1 (0)	/* Critical execution */

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
#define ActivateTask_SWT_CAN2_AP_LV_Derivation_LVData() ActivateTask(SWT_CAN2_AP_LV_Derivation_LVData)
#define ChainTask_SWT_CAN2_AP_LV_Derivation_LVData() ChainTask(SWT_CAN2_AP_LV_Derivation_LVData)
#define ActivateTask_SWT_CAN2_NM_ACCEL_F_Keep_Alive() ActivateTask(SWT_CAN2_NM_ACCEL_F_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_ACCEL_F_Keep_Alive() ChainTask(SWT_CAN2_NM_ACCEL_F_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_ACCEL_R_Keep_Alive() ActivateTask(SWT_CAN2_NM_ACCEL_R_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_ACCEL_R_Keep_Alive() ChainTask(SWT_CAN2_NM_ACCEL_R_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_ADCAN_Keep_Alive() ActivateTask(SWT_CAN2_NM_ADCAN_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_ADCAN_Keep_Alive() ChainTask(SWT_CAN2_NM_ADCAN_Keep_Alive)
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
extern OS_API_NONREENTRANT(void) osResetOS(void);
#endif /* OS_OSEK_H */

/* End of osek.h */
