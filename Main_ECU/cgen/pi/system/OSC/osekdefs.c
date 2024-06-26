/* This is an automatically generated file */
/* DO NOT EDIT THIS FILE */
/* File generated for project "os_config" */
/* Last edited 'unknown' */
/* File generated 'Tue Apr 23 16:13:15 2024' */
/* Target variant 'ES900' */


#define OS_OSEKDEFS (1)
#ifdef OS_LIBRARY_SETTINGS
 #error "This file should not be compiled for inclusion into a library"
#endif /* OS_LIBRARY_SETTINGS */

#include "osek.h"
#ifdef OSTRACE_ENABLED
#if (OSTRACE_TIME_SIZE == 32)
static osTrace__TimeType os_saved_time;
#endif /* OSTRACE_TIME_SIZE == 32 */
#endif /* OSTRACE_ENABLED */
static ZERO_INITIALIZED(struct osek_resource_dyn osek_RAM_RES_SCHEDULER);
static OS_CONST_VAR struct osek_resource _RES_SCHEDULER = {
	osek_resource_RES_SCHEDULER, osek_task_SWT_CAN2_2024_AP_FECU_Data1, &osek_RAM_RES_SCHEDULER
};
OS_CONST_VAR ResourceType RES_SCHEDULER = &_RES_SCHEDULER;
#ifdef OS_EXTENDED_BUILD
OS_CONST_VAR ResourceType osek_resources[] = {
	&_RES_SCHEDULER,
	0};
#endif /* OS_EXTENDED_BUILD */
#ifdef OS_EXTENDED_BUILD
 static ZERO_INITIALIZED(struct osek_task_dynL osek_RAM_osek_idle_task);
#endif /* OS_EXTENDED_BUILD */
static ZERO_INITIALIZED(TaskType _osek_fifo2[6]);
static ZERO_INITIALIZED(struct os_task_fifo_dyn osek_fifo2D);
static OS_CONST_VAR struct os_task_fifo_const osek_fifo2C = {
	_osek_fifo2, osek_task_Sync_25ms, 6
};
static ZERO_INITIALIZED(TaskType _osek_fifo1[3]);
static ZERO_INITIALIZED(struct os_task_fifo_dyn osek_fifo1D);
static OS_CONST_VAR struct os_task_fifo_const osek_fifo1C = {
	_osek_fifo1, osek_task_etasL1Task, 3
};
static ZERO_INITIALIZED(TaskType _osek_fifo0[3]);
static ZERO_INITIALIZED(struct os_task_fifo_dyn osek_fifo0D);
static OS_CONST_VAR struct os_task_fifo_const osek_fifo0C = {
	_osek_fifo0, osek_task_etasConfigTask, 3
};
static ZERO_INITIALIZED(struct osek_task_dynH_count osek_RAM_etasConfigTask);
static ZERO_INITIALIZED(struct osek_task_dynH_count osek_RAM_etasL1Task);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_BMS_AIRs_State);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_BMS_ChargerParameters);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_BMS_SDC);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_BMS_Temperatures);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_BMS_Voltages);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_CurrentSensor);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_DASH_CustomMode);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_DASH_EnableDrive);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_DASH_Mode);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_DASH_PrechargeRequest);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_DASH_TorqueLockOn);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_Inverter_L_Tx);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_AP_Inverter_R_Tx);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_NM_BMS_Keep_Alive);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN1_2024_NM_DASH_Keep_Alive);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_FECU_Data1);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_FECU_Data2);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_AP_RECU_Data);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_MEAS_FECU_SDC);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_MEAS_RECU_SDC);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_NM_ELLIPSE_Status);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_NM_FECU_Keep_Alive);
static ZERO_INITIALIZED(struct osek_task_dynH osek_RAM_SWT_CAN2_2024_NM_RECU_Keep_Alive);
static ZERO_INITIALIZED(struct osek_task_dynH_count osek_RAM_Sync_25ms);
static ZERO_INITIALIZED(struct osek_task_dynH_count osek_RAM_Timer_1000ms);
static ZERO_INITIALIZED(struct osek_task_dynH_count osek_RAM_Timer_100ms);
static ZERO_INITIALIZED(struct osek_task_dynH_count osek_RAM_Timer_25ms);
static ZERO_INITIALIZED(struct osek_task_dynH_count osek_RAM_Timer_Inv);
#ifdef OS_EXTENDED_BUILD
 static ZERO_INITIALIZED(struct osek_task_dynL osek_RAM_etasTimerIsr);
#endif /* OS_EXTENDED_BUILD */
#ifdef OS_EXTENDED_BUILD
 static ZERO_INITIALIZED(struct osek_task_dynL osek_RAM_etasL1Isr);
#endif /* OS_EXTENDED_BUILD */
#ifdef OS_EXTENDED_BUILD
 static ZERO_INITIALIZED(struct osek_task_dynL osek_RAM_etasStopOsIsr);
#endif /* OS_EXTENDED_BUILD */
#ifdef OS_EXTENDED_BUILD
 static ZERO_INITIALIZED(struct osek_task_dynL osek_RAM_etasActivateTaskIsr);
#endif /* OS_EXTENDED_BUILD */
#ifdef OS_EXTENDED_BUILD
 static ZERO_INITIALIZED(struct osek_task_dynL osek_RAM_ISR_CAN1_2024);
#endif /* OS_EXTENDED_BUILD */
#ifdef OS_EXTENDED_BUILD
 static ZERO_INITIALIZED(struct osek_task_dynL osek_RAM_ISR_CAN2_2024);
#endif /* OS_EXTENDED_BUILD */
static OS_CONST_VAR struct osek_taskL1 _osek_idle_task = {
	{os_idle_task, 0, 0
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1,1
#endif /* OS_EXTENDED_BUILD */
}
#if defined(OS_EXTENDED_BUILD)
	,&osek_RAM_osek_idle_task
#endif /* OS_EXTENDED_BUILD */
};
static OS_CONST_VAR struct osek_task2F _etasConfigTask = {
	{osek_task_etasConfigTask, os_idispH2F, osek_task_e_etasConfigTask
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC2F, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_etasConfigTask,  &osek_fifo0D, &osek_fifo0C, 2U, OS_STACK_INIT(1952U)
};
static OS_CONST_VAR struct osek_task2F _etasL1Task = {
	{osek_task_etasL1Task, os_fdispH2F, osek_task_e_etasL1Task
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC2F, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_etasL1Task,  &osek_fifo1D, &osek_fifo1C, 2U, OS_STACK_INIT(3904U)
};
static OS_CONST_VAR struct osek_task2F _Timer_Inv = {
	{osek_task_Timer_Inv, os_fdispH2F, osek_task_e_Timer_Inv
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC2F, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_Timer_Inv,  &osek_fifo2D, &osek_fifo2C, 1U, OS_STACK_INIT(5856U)
};
static OS_CONST_VAR struct osek_task2F _Timer_25ms = {
	{osek_task_Timer_25ms, os_fdispH2F, osek_task_e_Timer_25ms
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC2F, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_Timer_25ms,  &osek_fifo2D, &osek_fifo2C, 1U, OS_STACK_INIT(5856U)
};
static OS_CONST_VAR struct osek_task2F _Timer_100ms = {
	{osek_task_Timer_100ms, os_fdispH2F, osek_task_e_Timer_100ms
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC2F, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_Timer_100ms,  &osek_fifo2D, &osek_fifo2C, 1U, OS_STACK_INIT(5856U)
};
static OS_CONST_VAR struct osek_task2F _Timer_1000ms = {
	{osek_task_Timer_1000ms, os_fdispH2F, osek_task_e_Timer_1000ms
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC2F, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_Timer_1000ms,  &osek_fifo2D, &osek_fifo2C, 1U, OS_STACK_INIT(5856U)
};
static OS_CONST_VAR struct osek_task2F _Sync_25ms = {
	{osek_task_Sync_25ms, os_fdispH2F, osek_task_e_Sync_25ms
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC2F, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_Sync_25ms,  &osek_fifo2D, &osek_fifo2C, 1U, OS_STACK_INIT(5856U)
};
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_BMS_SDC = {
	{osek_task_SWT_CAN1_2024_AP_BMS_SDC, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_BMS_SDC
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_BMS_SDC, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_CurrentSensor = {
	{osek_task_SWT_CAN1_2024_AP_CurrentSensor, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_CurrentSensor
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_CurrentSensor, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_BMS_Voltages = {
	{osek_task_SWT_CAN1_2024_AP_BMS_Voltages, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_BMS_Voltages
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_BMS_Voltages, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_BMS_ChargerParameters = {
	{osek_task_SWT_CAN1_2024_AP_BMS_ChargerParameters, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_BMS_ChargerParameters
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_BMS_ChargerParameters, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_BMS_Temperatures = {
	{osek_task_SWT_CAN1_2024_AP_BMS_Temperatures, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_BMS_Temperatures
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_BMS_Temperatures, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_Inverter_R_Tx = {
	{osek_task_SWT_CAN1_2024_AP_Inverter_R_Tx, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_Inverter_R_Tx
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_Inverter_R_Tx, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_Inverter_L_Tx = {
	{osek_task_SWT_CAN1_2024_AP_Inverter_L_Tx, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_Inverter_L_Tx
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_Inverter_L_Tx, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_DASH_CustomMode = {
	{osek_task_SWT_CAN1_2024_AP_DASH_CustomMode, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_DASH_CustomMode
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_DASH_CustomMode, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_DASH_Mode = {
	{osek_task_SWT_CAN1_2024_AP_DASH_Mode, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_DASH_Mode
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_DASH_Mode, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_NM_BMS_Keep_Alive = {
	{osek_task_SWT_CAN1_2024_NM_BMS_Keep_Alive, os_fdispH1, osek_task_e_SWT_CAN1_2024_NM_BMS_Keep_Alive
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_NM_BMS_Keep_Alive, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_BMS_AIRs_State = {
	{osek_task_SWT_CAN1_2024_AP_BMS_AIRs_State, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_BMS_AIRs_State
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_BMS_AIRs_State, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_NM_DASH_Keep_Alive = {
	{osek_task_SWT_CAN1_2024_NM_DASH_Keep_Alive, os_fdispH1, osek_task_e_SWT_CAN1_2024_NM_DASH_Keep_Alive
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_NM_DASH_Keep_Alive, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_DASH_TorqueLockOn = {
	{osek_task_SWT_CAN1_2024_AP_DASH_TorqueLockOn, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_DASH_TorqueLockOn
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_DASH_TorqueLockOn, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_DASH_PrechargeRequest = {
	{osek_task_SWT_CAN1_2024_AP_DASH_PrechargeRequest, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_DASH_PrechargeRequest
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_DASH_PrechargeRequest, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN1_2024_AP_DASH_EnableDrive = {
	{osek_task_SWT_CAN1_2024_AP_DASH_EnableDrive, os_fdispH1, osek_task_e_SWT_CAN1_2024_AP_DASH_EnableDrive
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN1_2024_AP_DASH_EnableDrive, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_MEAS_RECU_SDC = {
	{osek_task_SWT_CAN2_2024_MEAS_RECU_SDC, os_fdispH1, osek_task_e_SWT_CAN2_2024_MEAS_RECU_SDC
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_MEAS_RECU_SDC, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_MEAS_FECU_SDC = {
	{osek_task_SWT_CAN2_2024_MEAS_FECU_SDC, os_fdispH1, osek_task_e_SWT_CAN2_2024_MEAS_FECU_SDC
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_MEAS_FECU_SDC, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_ELLIPSE_EKF_POS = {
	{osek_task_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL = {
	{osek_task_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER = {
	{osek_task_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL = {
	{osek_task_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_NM_ELLIPSE_Status = {
	{osek_task_SWT_CAN2_2024_NM_ELLIPSE_Status, os_fdispH1, osek_task_e_SWT_CAN2_2024_NM_ELLIPSE_Status
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_NM_ELLIPSE_Status, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO = {
	{osek_task_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV = {
	{osek_task_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_RECU_Data = {
	{osek_task_SWT_CAN2_2024_AP_RECU_Data, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_RECU_Data
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_RECU_Data, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_NM_FECU_Keep_Alive = {
	{osek_task_SWT_CAN2_2024_NM_FECU_Keep_Alive, os_fdispH1, osek_task_e_SWT_CAN2_2024_NM_FECU_Keep_Alive
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_NM_FECU_Keep_Alive, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_NM_RECU_Keep_Alive = {
	{osek_task_SWT_CAN2_2024_NM_RECU_Keep_Alive, os_fdispH1, osek_task_e_SWT_CAN2_2024_NM_RECU_Keep_Alive
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_NM_RECU_Keep_Alive, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_FECU_Data2 = {
	{osek_task_SWT_CAN2_2024_AP_FECU_Data2, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_FECU_Data2
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_FECU_Data2, };
static OS_CONST_VAR struct osek_taskH1 _SWT_CAN2_2024_AP_FECU_Data1 = {
	{osek_task_SWT_CAN2_2024_AP_FECU_Data1, os_fdispH1, osek_task_e_SWT_CAN2_2024_AP_FECU_Data1
#if defined(OS_EXTENDED_BUILD)
	,OSEK_TASK_BCC1, 0
#endif /* OS_EXTENDED_BUILD */
	}
	,&osek_RAM_SWT_CAN2_2024_AP_FECU_Data1, };
static OS_CONST_VAR struct osek_taskL1 _etasTimerIsr = {
	{osek_interrupt_etasTimerIsr, 0, osek_isr_e_etasTimerIsr
	#if defined(OS_EXTENDED_BUILD)
		,OSEK_ISR_2,1
	#endif /* OS_EXTENDED_BUILD */
	}
	#if defined(OS_EXTENDED_BUILD)
		,&osek_RAM_etasTimerIsr
	#endif /* OS_EXTENDED_BUILD */
};
static OS_CONST_VAR struct osek_taskL1 _etasL1Isr = {
	{osek_interrupt_etasL1Isr, 0, osek_isr_e_etasL1Isr
	#if defined(OS_EXTENDED_BUILD)
		,OSEK_ISR_2,1
	#endif /* OS_EXTENDED_BUILD */
	}
	#if defined(OS_EXTENDED_BUILD)
		,&osek_RAM_etasL1Isr
	#endif /* OS_EXTENDED_BUILD */
};
static OS_CONST_VAR struct osek_taskL1 _etasStopOsIsr = {
	{osek_interrupt_etasStopOsIsr, 0, osek_isr_e_etasStopOsIsr
	#if defined(OS_EXTENDED_BUILD)
		,OSEK_ISR_2,1
	#endif /* OS_EXTENDED_BUILD */
	}
	#if defined(OS_EXTENDED_BUILD)
		,&osek_RAM_etasStopOsIsr
	#endif /* OS_EXTENDED_BUILD */
};
static OS_CONST_VAR struct osek_taskL1 _etasActivateTaskIsr = {
	{osek_interrupt_etasActivateTaskIsr, 0, osek_isr_e_etasActivateTaskIsr
	#if defined(OS_EXTENDED_BUILD)
		,OSEK_ISR_2,1
	#endif /* OS_EXTENDED_BUILD */
	}
	#if defined(OS_EXTENDED_BUILD)
		,&osek_RAM_etasActivateTaskIsr
	#endif /* OS_EXTENDED_BUILD */
};
static OS_CONST_VAR struct osek_taskL1 _ISR_CAN1_2024 = {
	{osek_interrupt_ISR_CAN1_2024, 0, osek_isr_e_ISR_CAN1_2024
	#if defined(OS_EXTENDED_BUILD)
		,OSEK_ISR_2,1
	#endif /* OS_EXTENDED_BUILD */
	}
	#if defined(OS_EXTENDED_BUILD)
		,&osek_RAM_ISR_CAN1_2024
	#endif /* OS_EXTENDED_BUILD */
};
static OS_CONST_VAR struct osek_taskL1 _ISR_CAN2_2024 = {
	{osek_interrupt_ISR_CAN2_2024, 0, osek_isr_e_ISR_CAN2_2024
	#if defined(OS_EXTENDED_BUILD)
		,OSEK_ISR_2,1
	#endif /* OS_EXTENDED_BUILD */
	}
	#if defined(OS_EXTENDED_BUILD)
		,&osek_RAM_ISR_CAN2_2024
	#endif /* OS_EXTENDED_BUILD */
};
OS_CONST_VAR TaskType os_tasks [] = {
	(TaskType)&_etasConfigTask
	,(TaskType)&_etasL1Task
	,(TaskType)&_Timer_Inv
	,(TaskType)&_Timer_25ms
	,(TaskType)&_Timer_100ms
	,(TaskType)&_Timer_1000ms
	,(TaskType)&_Sync_25ms
	,(TaskType)&_SWT_CAN1_2024_AP_BMS_SDC
	,(TaskType)&_SWT_CAN1_2024_AP_CurrentSensor
	,(TaskType)&_SWT_CAN1_2024_AP_BMS_Voltages
	,(TaskType)&_SWT_CAN1_2024_AP_BMS_ChargerParameters
	,(TaskType)&_SWT_CAN1_2024_AP_BMS_Temperatures
	,(TaskType)&_SWT_CAN1_2024_AP_Inverter_R_Tx
	,(TaskType)&_SWT_CAN1_2024_AP_Inverter_L_Tx
	,(TaskType)&_SWT_CAN1_2024_AP_DASH_CustomMode
	,(TaskType)&_SWT_CAN1_2024_AP_DASH_Mode
	,(TaskType)&_SWT_CAN1_2024_NM_BMS_Keep_Alive
	,(TaskType)&_SWT_CAN1_2024_AP_BMS_AIRs_State
	,(TaskType)&_SWT_CAN1_2024_NM_DASH_Keep_Alive
	,(TaskType)&_SWT_CAN1_2024_AP_DASH_TorqueLockOn
	,(TaskType)&_SWT_CAN1_2024_AP_DASH_PrechargeRequest
	,(TaskType)&_SWT_CAN1_2024_AP_DASH_EnableDrive
	,(TaskType)&_SWT_CAN2_2024_MEAS_RECU_SDC
	,(TaskType)&_SWT_CAN2_2024_MEAS_FECU_SDC
	,(TaskType)&_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS
	,(TaskType)&_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL
	,(TaskType)&_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER
	,(TaskType)&_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL
	,(TaskType)&_SWT_CAN2_2024_NM_ELLIPSE_Status
	,(TaskType)&_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO
	,(TaskType)&_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV
	,(TaskType)&_SWT_CAN2_2024_AP_RECU_Data
	,(TaskType)&_SWT_CAN2_2024_NM_FECU_Keep_Alive
	,(TaskType)&_SWT_CAN2_2024_NM_RECU_Keep_Alive
	,(TaskType)&_SWT_CAN2_2024_AP_FECU_Data2
	,(TaskType)&_SWT_CAN2_2024_AP_FECU_Data1
	,(TaskType)&_etasTimerIsr
	,(TaskType)&_etasL1Isr
	,(TaskType)&_etasStopOsIsr
	,(TaskType)&_etasActivateTaskIsr
	,(TaskType)&_ISR_CAN1_2024
	,(TaskType)&_ISR_CAN2_2024
#if defined(OS_EXTENDED_BUILD)
	,(TaskType)0
#endif /* OS_EXTENDED_BUILD */
};
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_FECU_Data1 = (TaskType)(&_SWT_CAN2_2024_AP_FECU_Data1);
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_FECU_Data2 = (TaskType)(&_SWT_CAN2_2024_AP_FECU_Data2);
OS_CONST_VAR TaskType SWT_CAN2_2024_NM_RECU_Keep_Alive = (TaskType)(&_SWT_CAN2_2024_NM_RECU_Keep_Alive);
OS_CONST_VAR TaskType SWT_CAN2_2024_NM_FECU_Keep_Alive = (TaskType)(&_SWT_CAN2_2024_NM_FECU_Keep_Alive);
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_RECU_Data = (TaskType)(&_SWT_CAN2_2024_AP_RECU_Data);
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV = (TaskType)(&_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV);
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO = (TaskType)(&_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO);
OS_CONST_VAR TaskType SWT_CAN2_2024_NM_ELLIPSE_Status = (TaskType)(&_SWT_CAN2_2024_NM_ELLIPSE_Status);
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL = (TaskType)(&_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL);
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER = (TaskType)(&_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER);
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL = (TaskType)(&_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL);
OS_CONST_VAR TaskType SWT_CAN2_2024_AP_ELLIPSE_EKF_POS = (TaskType)(&_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS);
OS_CONST_VAR TaskType SWT_CAN2_2024_MEAS_FECU_SDC = (TaskType)(&_SWT_CAN2_2024_MEAS_FECU_SDC);
OS_CONST_VAR TaskType SWT_CAN2_2024_MEAS_RECU_SDC = (TaskType)(&_SWT_CAN2_2024_MEAS_RECU_SDC);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_DASH_EnableDrive = (TaskType)(&_SWT_CAN1_2024_AP_DASH_EnableDrive);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_DASH_PrechargeRequest = (TaskType)(&_SWT_CAN1_2024_AP_DASH_PrechargeRequest);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_DASH_TorqueLockOn = (TaskType)(&_SWT_CAN1_2024_AP_DASH_TorqueLockOn);
OS_CONST_VAR TaskType SWT_CAN1_2024_NM_DASH_Keep_Alive = (TaskType)(&_SWT_CAN1_2024_NM_DASH_Keep_Alive);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_BMS_AIRs_State = (TaskType)(&_SWT_CAN1_2024_AP_BMS_AIRs_State);
OS_CONST_VAR TaskType SWT_CAN1_2024_NM_BMS_Keep_Alive = (TaskType)(&_SWT_CAN1_2024_NM_BMS_Keep_Alive);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_DASH_Mode = (TaskType)(&_SWT_CAN1_2024_AP_DASH_Mode);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_DASH_CustomMode = (TaskType)(&_SWT_CAN1_2024_AP_DASH_CustomMode);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_Inverter_L_Tx = (TaskType)(&_SWT_CAN1_2024_AP_Inverter_L_Tx);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_Inverter_R_Tx = (TaskType)(&_SWT_CAN1_2024_AP_Inverter_R_Tx);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_BMS_Temperatures = (TaskType)(&_SWT_CAN1_2024_AP_BMS_Temperatures);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_BMS_ChargerParameters = (TaskType)(&_SWT_CAN1_2024_AP_BMS_ChargerParameters);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_BMS_Voltages = (TaskType)(&_SWT_CAN1_2024_AP_BMS_Voltages);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_CurrentSensor = (TaskType)(&_SWT_CAN1_2024_AP_CurrentSensor);
OS_CONST_VAR TaskType SWT_CAN1_2024_AP_BMS_SDC = (TaskType)(&_SWT_CAN1_2024_AP_BMS_SDC);
OS_CONST_VAR TaskType Sync_25ms = (TaskType)(&_Sync_25ms);
OS_CONST_VAR TaskType Timer_1000ms = (TaskType)(&_Timer_1000ms);
OS_CONST_VAR TaskType Timer_100ms = (TaskType)(&_Timer_100ms);
OS_CONST_VAR TaskType Timer_25ms = (TaskType)(&_Timer_25ms);
OS_CONST_VAR TaskType Timer_Inv = (TaskType)(&_Timer_Inv);
OS_CONST_VAR TaskType etasL1Task = (TaskType)(&_etasL1Task);
OS_CONST_VAR TaskType etasConfigTask = (TaskType)(&_etasConfigTask);
OS_CONST_VAR TaskType osek_idle_task = (TaskType)(&_osek_idle_task);
OS_CONST_VAR TaskType etasTimerIsr = (TaskType)(&_etasTimerIsr);
OS_CONST_VAR TaskType etasL1Isr = (TaskType)(&_etasL1Isr);
OS_CONST_VAR TaskType etasStopOsIsr = (TaskType)(&_etasStopOsIsr);
OS_CONST_VAR TaskType etasActivateTaskIsr = (TaskType)(&_etasActivateTaskIsr);
OS_CONST_VAR TaskType ISR_CAN1_2024 = (TaskType)(&_ISR_CAN1_2024);
OS_CONST_VAR TaskType ISR_CAN2_2024 = (TaskType)(&_ISR_CAN2_2024);
OS_NONREENTRANT(void) osE_etasL1Isr(void);
OS_NONREENTRANT(void) osE_etasL1Isr(void) {
	os_fp_save();
#ifndef OSEK_NO_CURTASK
	osek_cur_task = (TaskType)(&_etasL1Isr);
#endif /* OSEK_NO_CURTASK */
#ifdef OS_ISR_PRELUDE
	OS_ISR_PRELUDE(etasL1Isr,1U)
#endif /* OS_ISR_PRELUDE */
	osek_isr_e_etasL1Isr();
	os_fp_restore();
}
OS_NONREENTRANT(void) osE_ISR_CAN1_2024(void);
OS_NONREENTRANT(void) osE_ISR_CAN1_2024(void) {
	os_fp_save();
#ifndef OSEK_NO_CURTASK
	osek_cur_task = (TaskType)(&_ISR_CAN1_2024);
#endif /* OSEK_NO_CURTASK */
#ifdef OS_ISR_PRELUDE
	OS_ISR_PRELUDE(ISR_CAN1_2024,1U)
#endif /* OS_ISR_PRELUDE */
	osek_isr_e_ISR_CAN1_2024();
	os_fp_restore();
}
OS_NONREENTRANT(void) osE_ISR_CAN2_2024(void);
OS_NONREENTRANT(void) osE_ISR_CAN2_2024(void) {
	os_fp_save();
#ifndef OSEK_NO_CURTASK
	osek_cur_task = (TaskType)(&_ISR_CAN2_2024);
#endif /* OSEK_NO_CURTASK */
#ifdef OS_ISR_PRELUDE
	OS_ISR_PRELUDE(ISR_CAN2_2024,1U)
#endif /* OS_ISR_PRELUDE */
	osek_isr_e_ISR_CAN2_2024();
	os_fp_restore();
}
OS_DISPATCH(void) osek_dispatch(void) {osek_dispatchN2F();}
static ZERO_INITIALIZED(struct osek_counter_dyn osek_RAM_etasCounter);
static OS_CONST_VAR struct osek_counter _etasCounter = {
	&osek_RAM_etasCounter,
	{4294967295U,1U,1U}
#ifdef OS_RTA5_COMPATIBLE
	,0,0,0,0
#endif /* OS_RTA5_COMPATIBLE */
};
OS_CONST_VAR osCounterType etasCounter = &_etasCounter;
#ifdef OS_EXTENDED_BUILD
OS_CONST_VAR osCounterType osek_counters[] = {
	(osCounterType)&_etasCounter,
	0};
#endif /* OS_EXTENDED_BUILD */
static ZERO_INITIALIZED(struct osek_alarm_dyn osek_RAM_etasWatchdogAlarm);
static OS_CONST_VAR struct osek_alarm _etasWatchdogAlarm = {
	&osek_RAM_etasWatchdogAlarm, (osCounterType)&_etasCounter
};
OS_CONST_VAR AlarmType etasWatchdogAlarm = &_etasWatchdogAlarm;
static ZERO_INITIALIZED(struct osek_alarm_dyn osek_RAM_SYNC_25MS);
static OS_CONST_VAR struct osek_alarm _SYNC_25MS = {
	&osek_RAM_SYNC_25MS, (osCounterType)&_etasCounter
};
OS_CONST_VAR AlarmType SYNC_25MS = &_SYNC_25MS;
static ZERO_INITIALIZED(struct osek_alarm_dyn osek_RAM_TIMER_1000MS);
static OS_CONST_VAR struct osek_alarm _TIMER_1000MS = {
	&osek_RAM_TIMER_1000MS, (osCounterType)&_etasCounter
};
OS_CONST_VAR AlarmType TIMER_1000MS = &_TIMER_1000MS;
static ZERO_INITIALIZED(struct osek_alarm_dyn osek_RAM_TIMER_100MS);
static OS_CONST_VAR struct osek_alarm _TIMER_100MS = {
	&osek_RAM_TIMER_100MS, (osCounterType)&_etasCounter
};
OS_CONST_VAR AlarmType TIMER_100MS = &_TIMER_100MS;
static ZERO_INITIALIZED(struct osek_alarm_dyn osek_RAM_TIMER_25MS);
static OS_CONST_VAR struct osek_alarm _TIMER_25MS = {
	&osek_RAM_TIMER_25MS, (osCounterType)&_etasCounter
};
OS_CONST_VAR AlarmType TIMER_25MS = &_TIMER_25MS;
static ZERO_INITIALIZED(struct osek_alarm_dyn osek_RAM_TIMER_INV);
static OS_CONST_VAR struct osek_alarm _TIMER_INV = {
	&osek_RAM_TIMER_INV, (osCounterType)&_etasCounter
};
OS_CONST_VAR AlarmType TIMER_INV = &_TIMER_INV;
#ifdef OS_EXTENDED_BUILD
OS_CONST_VAR AlarmType osek_alarms[] = {
	&_etasWatchdogAlarm,
	&_SYNC_25MS,
	&_TIMER_1000MS,
	&_TIMER_100MS,
	&_TIMER_25MS,
	&_TIMER_INV,
	0};
#endif /* OS_EXTENDED_BUILD */
OS_API_NONREENTRANT(void) Tick_etasCounter(void) {
	TickType os_t = ++(osek_RAM_etasCounter.count);
	if (osek_tick_alarm(&osek_RAM_SYNC_25MS, os_t)) {
		(void)ActivateTask(Sync_25ms);
	}
	if (osek_tick_alarm(&osek_RAM_TIMER_1000MS, os_t)) {
		(void)ActivateTask(Timer_1000ms);
	}
	if (osek_tick_alarm(&osek_RAM_TIMER_100MS, os_t)) {
		(void)ActivateTask(Timer_100ms);
	}
	if (osek_tick_alarm(&osek_RAM_TIMER_25MS, os_t)) {
		(void)ActivateTask(Timer_25ms);
	}
	if (osek_tick_alarm(&osek_RAM_TIMER_INV, os_t)) {
		(void)ActivateTask(Timer_Inv);
	}
	if (osek_tick_alarm(&osek_RAM_etasWatchdogAlarm, os_t)) {
		osek_alarm_callback(etasServiceWatchdog);
	}
}
osSmallType os_serviceId;
struct os_serviceAllArgs os_serviceArgs;
static OS_FP_CONTEXT os_fp_stack[32];
PTR(OS_FP_CONTEXT) os_fp_sp = &os_fp_stack[0];
OS_CONST_VAR osByteType osek_s_3_1_0 = 0;
#ifndef OSEK_NO_CURTASK
TaskType osek_cur_task = (TaskType)&_osek_idle_task;
#endif /* OSEK_NO_CURTASK */
#ifdef OS_EXTENDED_BUILD
 StatusType osek_last_error = E_OK;
 OS_CONST_VAR osBooleanType osek_allow_upward_activation = (osBooleanType)1;
 OS_CONST_VAR osSmallType osek_num_tasks = (osSmallType)OSEK_NUM_TASKS;
 OS_CONST_VAR osSmallType osek_num_resources = (osSmallType)OSEK_NUM_RESOURCES;
 OS_CONST_VAR osSmallType osek_num_alarms = (osSmallType)OSEK_NUM_ALARMS;
 #ifdef LOCALMESSAGESONLY
  OS_CONST_VAR osSmallType osek_num_messages = (osSmallType)OSEK_NUM_MESSAGES;
  osSmallType osek_comm_running;
 #endif /* LOCALMESSAGESONLY */
#endif /* OS_EXTENDED_BUILD */
OS_API(void) os_pre_errorhook(OSBiggestType os_p1, OSBiggestType os_p2, OSBiggestType os_p3, OSServiceIdType os_id, StatusType os_s) {
	os_pre_errorhook2(os_p1, os_p2, os_p3, os_id, os_s);
}
#if defined(OSEK_ECC1) || defined(OSEK_ECC2C) || defined(OSEK_ECC2F) || (defined(OS_MULTI_ISR_LEVEL_CPU) && defined(OS_EXTENDED_BUILD))
 OS_REENTRANT(void) os_pre_ShutdownOS(StatusType os_Error) {
	ShutdownOS(os_Error);
}
#endif /* defined(OSEK_ECC1) || defined(OSEK_ECC2C) || defined(OSEK_ECC2F) || (defined(OS_MULTI_ISR_LEVEL_CPU) && defined(OS_EXTENDED_BUILD)) */
OS_API_NONREENTRANT(void) os_StartOS(AppModeType os_mode) {
	osOptions = 0;
	if (os_mode == etasStartup) {
		(void)SetAbsAlarm(etasWatchdogAlarm, (TickType)1, (TickType)200);
	}
	else if (os_mode == etasInactive) {
		(void)SetAbsAlarm(etasWatchdogAlarm, (TickType)1, (TickType)200);
	}
	else if (os_mode == Timers) {
		(void)SetAbsAlarm(etasWatchdogAlarm, (TickType)1, (TickType)200);
		(void)SetAbsAlarm(SYNC_25MS, (TickType)26, (TickType)50);
		(void)SetAbsAlarm(TIMER_1000MS, (TickType)1, (TickType)2000);
		(void)SetAbsAlarm(TIMER_100MS, (TickType)1, (TickType)200);
		(void)SetAbsAlarm(TIMER_25MS, (TickType)1, (TickType)50);
		(void)SetAbsAlarm(TIMER_INV, (TickType)1, (TickType)6);
	}
	StartupHook();
}
#ifdef LOCALMESSAGESONLY
OS_API_NONREENTRANT(void) os_StartCOM(void) {
#ifdef OS_EXTENDED_BUILD
	osek_comm_running = (osSmallType)1;
#endif /* OS_EXTENDED_BUILD */
}
#endif /* LOCALMESSAGESONLY */
#ifndef OS_INDIRECT_EXPORT
extern osSmallType osek_suspend_nesting;
extern osSmallType osek_suspend_all_nesting;
extern TaskType osek_running_task;
#endif /* OS_INDIRECT_EXPORT */
OS_API_NONREENTRANT(void) osResetOS(void) {
	if (osek_running_task != osek_idle_task) {
		ShutdownOS(E_OS_STATE);
	}
#ifdef OS_EXTENDED_BUILD
	osek_orti_call = (OSEK_ORTI_ShutdownOS << 1u) | (osSmallType)1u;
#endif /* OS_EXTENDED_BUILD */
	SuspendOSInterrupts();
#ifdef OSEK_SHUTDOWNHOOK
	ShutdownHook(E_OK);
#endif /* OSEK_SHUTDOWNHOOK */
#ifdef OS_EXTENDED_BUILD
	osek_orti_call = (OSEK_ORTI_ShutdownOS << 1u);
#endif /* OS_EXTENDED_BUILD */
	osek_suspend_nesting = 0;
	osek_suspend_all_nesting = 0;
	osek_fifo2D.begin = 0;
	osek_fifo2D.end = 0;
	osek_fifo1D.begin = 0;
	osek_fifo1D.end = 0;
	osek_fifo0D.begin = 0;
	osek_fifo0D.end = 0;
	osek_RAM_etasConfigTask.activations = 0;
	osek_RAM_etasL1Task.activations = 0;
	osek_RAM_Sync_25ms.activations = 0;
	osek_RAM_Timer_1000ms.activations = 0;
	osek_RAM_Timer_100ms.activations = 0;
	osek_RAM_Timer_25ms.activations = 0;
	osek_RAM_Timer_Inv.activations = 0;
	osek_RAM_etasCounter.count = 0;
	osek_RAM_etasWatchdogAlarm.running = 0;
	osek_RAM_SYNC_25MS.running = 0;
	osek_RAM_TIMER_1000MS.running = 0;
	osek_RAM_TIMER_100MS.running = 0;
	osek_RAM_TIMER_25MS.running = 0;
	osek_RAM_TIMER_INV.running = 0;
	os_fp_sp = &os_fp_stack[0];
#ifndef OSEK_NO_CURTASK
	osek_cur_task = (TaskType)&_osek_idle_task;
#endif /* OSEK_NO_CURTASK */
#ifdef OS_EXTENDED_BUILD
	osek_last_error = E_OK;
#endif /* OS_EXTENDED_BUILD */
}

/* End of osekdefs.c */

