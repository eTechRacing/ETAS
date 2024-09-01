/* This is an automatically generated file */
/* DO NOT EDIT THIS FILE */
/* File generated for project "os_config" */
/* Last edited 'unknown' */
/* File generated 'Sun Sep 01 14:43:56 2024' */
/* Target variant 'ES900' */

/* The file must only be included for the implementation of code for ISR(ISR_CAN2) */

#ifndef OS_ISR_ISR_CAN2
#define OS_ISR_ISR_CAN2

#define OS_ISR

#include "osekcomn.h"

#ifdef OS_FILE_INCLUDED
 #error Multiple File Inclusion
#else /* OS_FILE_INCLUDED */
 #define OS_FILE_INCLUDED
#endif /* OS_FILE_INCLUDED */

#define ISR_CAN2_default_profile (0)	/* Profile */
#define OSALARM_etasWatchdogAlarm (0)	/* Alarm */
#define OSALARM_SYNC_25MS (0)	/* Alarm */
#define OSALARM_TIMER_1000MS (0)	/* Alarm */
#define OSALARM_TIMER_100MS (0)	/* Alarm */
#define OSALARM_TIMER_25MS (0)	/* Alarm */
#define OSALARM_TIMER_INV (0)	/* Alarm */

#define ActivateTask_etasConfigTask() ActivateTask(etasConfigTask)
#define ActivateTask_etasL1Task() ActivateTask(etasL1Task)
#define ActivateTask_SWT_CAN1_AP_BMS_AIRs_State() ActivateTask(SWT_CAN1_AP_BMS_AIRs_State)
#define ActivateTask_SWT_CAN1_AP_BMS_ChargerParameters() ActivateTask(SWT_CAN1_AP_BMS_ChargerParameters)
#define ActivateTask_SWT_CAN1_AP_BMS_SDC() ActivateTask(SWT_CAN1_AP_BMS_SDC)
#define ActivateTask_SWT_CAN1_AP_BMS_Temperatures() ActivateTask(SWT_CAN1_AP_BMS_Temperatures)
#define ActivateTask_SWT_CAN1_AP_BMS_Voltages() ActivateTask(SWT_CAN1_AP_BMS_Voltages)
#define ActivateTask_SWT_CAN1_AP_CurrentSensor() ActivateTask(SWT_CAN1_AP_CurrentSensor)
#define ActivateTask_SWT_CAN1_AP_DASH_EnableDrive() ActivateTask(SWT_CAN1_AP_DASH_EnableDrive)
#define ActivateTask_SWT_CAN1_AP_DASH_Mode() ActivateTask(SWT_CAN1_AP_DASH_Mode)
#define ActivateTask_SWT_CAN1_AP_DASH_PrechargeRequest() ActivateTask(SWT_CAN1_AP_DASH_PrechargeRequest)
#define ActivateTask_SWT_CAN1_AP_Inverter_L_Tx() ActivateTask(SWT_CAN1_AP_Inverter_L_Tx)
#define ActivateTask_SWT_CAN1_AP_Inverter_R_Tx() ActivateTask(SWT_CAN1_AP_Inverter_R_Tx)
#define ActivateTask_SWT_CAN1_NM_BMS_Keep_Alive() ActivateTask(SWT_CAN1_NM_BMS_Keep_Alive)
#define ActivateTask_SWT_CAN1_NM_DASH_Keep_Alive() ActivateTask(SWT_CAN1_NM_DASH_Keep_Alive)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_AUTO() ActivateTask(SWT_CAN2_AP_ELLIPSE_AUTO)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_EULER() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_EULER)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_POS() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_POS)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_EKF_VEL() ActivateTask(SWT_CAN2_AP_ELLIPSE_EKF_VEL)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_GPS_VEL() ActivateTask(SWT_CAN2_AP_ELLIPSE_GPS_VEL)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL() ActivateTask(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_IMU_GYRO() ActivateTask(SWT_CAN2_AP_ELLIPSE_IMU_GYRO)
#define ActivateTask_SWT_CAN2_AP_ELLIPSE_VEL_Valid() ActivateTask(SWT_CAN2_AP_ELLIPSE_VEL_Valid)
#define ActivateTask_SWT_CAN2_AP_FECU_Data1() ActivateTask(SWT_CAN2_AP_FECU_Data1)
#define ActivateTask_SWT_CAN2_AP_FECU_Data2() ActivateTask(SWT_CAN2_AP_FECU_Data2)
#define ActivateTask_SWT_CAN2_AP_RECU_Data() ActivateTask(SWT_CAN2_AP_RECU_Data)
#define ActivateTask_SWT_CAN2_MEAS_RECU_SDC() ActivateTask(SWT_CAN2_MEAS_RECU_SDC)
#define ActivateTask_SWT_CAN2_NM_ELLIPSE_Status() ActivateTask(SWT_CAN2_NM_ELLIPSE_Status)
#define ActivateTask_SWT_CAN2_NM_FECU_Keep_Alive() ActivateTask(SWT_CAN2_NM_FECU_Keep_Alive)
#define ActivateTask_SWT_CAN2_NM_RECU_Keep_Alive() ActivateTask(SWT_CAN2_NM_RECU_Keep_Alive)
#define ActivateTask_Sync_25ms() ActivateTask(Sync_25ms)
#define ActivateTask_Timer_1000ms() ActivateTask(Timer_1000ms)
#define ActivateTask_Timer_100ms() ActivateTask(Timer_100ms)
#define ActivateTask_Timer_25ms() ActivateTask(Timer_25ms)
#define ActivateTask_Timer_Inv() ActivateTask(Timer_Inv)

#endif /* OS_ISR_ISR_CAN2 */
