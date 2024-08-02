/* This is an automatically generated file */
/* DO NOT EDIT THIS FILE */
/* File generated for project "os_config" */
/* Last edited 'unknown' */
/* File generated 'Fri Aug 02 09:33:19 2024' */
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
#define SWT_CAN1_AP_BMS_ChargerParameters_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_SDC_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_Temperatures_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_BMS_Voltages_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_CurrentSensor_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_DASH_EnableDrive_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_DASH_Mode_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_DASH_PrechargeRequest_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_Inverter_L_Tx_default_profile (0)	/* Profile */
#define SWT_CAN1_AP_Inverter_R_Tx_default_profile (0)	/* Profile */
#define SWT_CAN1_NM_BMS_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN1_NM_DASH_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ELLIPSE_EKF_EULER_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ELLIPSE_EKF_POS_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ELLIPSE_EKF_VEL_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ELLIPSE_GPS_VEL_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ELLIPSE_IMU_ACCEL_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ELLIPSE_IMU_GYRO_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_ELLIPSE_VEL_Valid_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_FECU_Data1_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_FECU_Data2_default_profile (0)	/* Profile */
#define SWT_CAN2_AP_RECU_Data_default_profile (0)	/* Profile */
#define SWT_CAN2_MEAS_FECU_SDC_default_profile (0)	/* Profile */
#define SWT_CAN2_MEAS_RECU_SDC_default_profile (0)	/* Profile */
#define SWT_CAN2_NM_ELLIPSE_Status_default_profile (0)	/* Profile */
#define SWT_CAN2_NM_FECU_Keep_Alive_default_profile (0)	/* Profile */
#define SWT_CAN2_NM_RECU_Keep_Alive_default_profile (0)	/* Profile */
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
#define ActivateTask_SWT_CAN1_AP_BMS_ChargerParameters() ActivateTask(SWT_CAN1_AP_BMS_ChargerParameters)
#define ChainTask_SWT_CAN1_AP_BMS_ChargerParameters() ChainTask(SWT_CAN1_AP_BMS_ChargerParameters)
#define ActivateTask_SWT_CAN1_AP_BMS_SDC() ActivateTask(SWT_CAN1_AP_BMS_SDC)
#define ChainTask_SWT_CAN1_AP_BMS_SDC() ChainTask(SWT_CAN1_AP_BMS_SDC)
#define ActivateTask_SWT_CAN1_AP_BMS_Temperatures() ActivateTask(SWT_CAN1_AP_BMS_Temperatures)
#define ChainTask_SWT_CAN1_AP_BMS_Temperatures() ChainTask(SWT_CAN1_AP_BMS_Temperatures)
#define ActivateTask_SWT_CAN1_AP_BMS_Voltages() ActivateTask(SWT_CAN1_AP_BMS_Voltages)
#define ChainTask_SWT_CAN1_AP_BMS_Voltages() ChainTask(SWT_CAN1_AP_BMS_Voltages)
#define ActivateTask_SWT_CAN1_AP_CurrentSensor() ActivateTask(SWT_CAN1_AP_CurrentSensor)
#define ChainTask_SWT_CAN1_AP_CurrentSensor() ChainTask(SWT_CAN1_AP_CurrentSensor)
#define ActivateTask_SWT_CAN1_AP_DASH_EnableDrive() ActivateTask(SWT_CAN1_AP_DASH_EnableDrive)
#define ChainTask_SWT_CAN1_AP_DASH_EnableDrive() ChainTask(SWT_CAN1_AP_DASH_EnableDrive)
#define ActivateTask_SWT_CAN1_AP_DASH_Mode() ActivateTask(SWT_CAN1_AP_DASH_Mode)
#define ChainTask_SWT_CAN1_AP_DASH_Mode() ChainTask(SWT_CAN1_AP_DASH_Mode)
#define ActivateTask_SWT_CAN1_AP_DASH_PrechargeRequest() ActivateTask(SWT_CAN1_AP_DASH_PrechargeRequest)
#define ChainTask_SWT_CAN1_AP_DASH_PrechargeRequest() ChainTask(SWT_CAN1_AP_DASH_PrechargeRequest)
#define ActivateTask_SWT_CAN1_AP_Inverter_L_Tx() ActivateTask(SWT_CAN1_AP_Inverter_L_Tx)
#define ChainTask_SWT_CAN1_AP_Inverter_L_Tx() ChainTask(SWT_CAN1_AP_Inverter_L_Tx)
#define ActivateTask_SWT_CAN1_AP_Inverter_R_Tx() ActivateTask(SWT_CAN1_AP_Inverter_R_Tx)
#define ChainTask_SWT_CAN1_AP_Inverter_R_Tx() ChainTask(SWT_CAN1_AP_Inverter_R_Tx)
#define ActivateTask_SWT_CAN1_NM_BMS_Keep_Alive() ActivateTask(SWT_CAN1_NM_BMS_Keep_Alive)
#define ChainTask_SWT_CAN1_NM_BMS_Keep_Alive() ChainTask(SWT_CAN1_NM_BMS_Keep_Alive)
#define ActivateTask_SWT_CAN1_NM_DASH_Keep_Alive() ActivateTask(SWT_CAN1_NM_DASH_Keep_Alive)
#define ChainTask_SWT_CAN1_NM_DASH_Keep_Alive() ChainTask(SWT_CAN1_NM_DASH_Keep_Alive)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_EULER() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_EULER)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_EKF_EULER() ChainTask(SWT_CAN2_AP_ELLIPSE_EKF_EULER)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_POS() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_POS)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_EKF_POS() ChainTask(SWT_CAN2_AP_ELLIPSE_EKF_POS)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_VEL() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_VEL)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_EKF_VEL() ChainTask(SWT_CAN2_AP_ELLIPSE_EKF_VEL)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_GPS_VEL() ActivateTask(SWT_CAN2_AP_ELLIPSE_GPS_VEL)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_GPS_VEL() ChainTask(SWT_CAN2_AP_ELLIPSE_GPS_VEL)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL() ActivateTask(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL() ChainTask(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_IMU_GYRO() ActivateTask(SWT_CAN2_AP_ELLIPSE_IMU_GYRO)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_IMU_GYRO() ChainTask(SWT_CAN2_AP_ELLIPSE_IMU_GYRO)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_VEL_Valid() ActivateTask(SWT_CAN2_AP_ELLIPSE_VEL_Valid)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_VEL_Valid() ChainTask(SWT_CAN2_AP_ELLIPSE_VEL_Valid)
#define ActivateTask_SWT_CAN2_AP_FECU_Data1() ActivateTask(SWT_CAN2_AP_FECU_Data1)
#define ChainTask_SWT_CAN2_AP_FECU_Data1() ChainTask(SWT_CAN2_AP_FECU_Data1)
#define ActivateTask_SWT_CAN2_AP_FECU_Data2() ActivateTask(SWT_CAN2_AP_FECU_Data2)
#define ChainTask_SWT_CAN2_AP_FECU_Data2() ChainTask(SWT_CAN2_AP_FECU_Data2)
#define ActivateTask_SWT_CAN2_AP_RECU_Data() ActivateTask(SWT_CAN2_AP_RECU_Data)
#define ChainTask_SWT_CAN2_AP_RECU_Data() ChainTask(SWT_CAN2_AP_RECU_Data)
#define ActivateTask_SWT_CAN2_MEAS_FECU_SDC() ActivateTask(SWT_CAN2_MEAS_FECU_SDC)
#define ChainTask_SWT_CAN2_MEAS_FECU_SDC() ChainTask(SWT_CAN2_MEAS_FECU_SDC)
#define ActivateTask_SWT_CAN2_MEAS_RECU_SDC() ActivateTask(SWT_CAN2_MEAS_RECU_SDC)
#define ChainTask_SWT_CAN2_MEAS_RECU_SDC() ChainTask(SWT_CAN2_MEAS_RECU_SDC)
#define ActivateTask_SWT_CAN2_NM_ELLIPSE_Status() ActivateTask(SWT_CAN2_NM_ELLIPSE_Status)
#define ChainTask_SWT_CAN2_NM_ELLIPSE_Status() ChainTask(SWT_CAN2_NM_ELLIPSE_Status)
#define ActivateTask_SWT_CAN2_NM_FECU_Keep_Alive() ActivateTask(SWT_CAN2_NM_FECU_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_FECU_Keep_Alive() ChainTask(SWT_CAN2_NM_FECU_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_RECU_Keep_Alive() ActivateTask(SWT_CAN2_NM_RECU_Keep_Alive)
#define ChainTask_SWT_CAN2_NM_RECU_Keep_Alive() ChainTask(SWT_CAN2_NM_RECU_Keep_Alive)
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
