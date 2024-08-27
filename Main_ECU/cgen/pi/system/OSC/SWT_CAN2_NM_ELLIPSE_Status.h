/* This is an automatically generated file */
/* DO NOT EDIT THIS FILE */
/* File generated for project "os_config" */
/* Last edited 'unknown' */
/* File generated 'Tue Aug 27 18:17:47 2024' */
/* Target variant 'ES900' */

/* The file must only be included for the implementation of code for TASK(SWT_CAN2_NM_ELLIPSE_Status) */

#ifndef OS_TASK_SWT_CAN2_NM_ELLIPSE_Status
#define OS_TASK_SWT_CAN2_NM_ELLIPSE_Status

#define OS_HEAVYWEIGHT
#include "osekcomn.h"

#ifdef OS_FILE_INCLUDED
 #error Multiple File Inclusion
#else /* OS_FILE_INCLUDED */
 #define OS_FILE_INCLUDED
#endif /* OS_FILE_INCLUDED */

#define SWT_CAN2_NM_ELLIPSE_Status_default_profile (0)	/* Profile */
#define OSALARM_etasWatchdogAlarm (0)	/* Alarm */
#define OSALARM_SYNC_25MS (0)	/* Alarm */
#define OSALARM_TIMER_1000MS (0)	/* Alarm */
#define OSALARM_TIMER_100MS (0)	/* Alarm */
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
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_AUTO() ActivateTask(SWT_CAN2_AP_ELLIPSE_AUTO)
#define ChainTask_SWT_CAN2_AP_ELLIPSE_AUTO() ChainTask(SWT_CAN2_AP_ELLIPSE_AUTO)
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

#endif /* OS_TASK_SWT_CAN2_NM_ELLIPSE_Status */
