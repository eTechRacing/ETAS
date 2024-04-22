/* Generated by INTECRIO */
/* (c) 2014 ETAS (ETAS GmbH) */

/* System internal declarations and definitions - not intended for user purposes. */

/* A task monitor is necessary for every user visible task. */
#ifndef __TASK_MONITORS_H__
#define __TASK_MONITORS_H__

DECLARE_TASK_MONITOR(etasConfigTask);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_BMS_AIRs_State);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_BMS_ChargerParameters);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_BMS_SDC);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_BMS_Temperatures);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_BMS_Voltages);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_CurrentSensor);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_DASH_CustomMode);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_DASH_EnableDrive);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_DASH_Mode);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_DASH_PrechargeRequest);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_DASH_TorqueLockOn);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_Inverter_L_Tx);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_AP_Inverter_R_Tx);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_NM_BMS_Keep_Alive);
DECLARE_TASK_MONITOR(SWT_CAN1_2024_NM_DASH_Keep_Alive);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_ELLIPSE_EKF_POS);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_FECU_Data1);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_FECU_Data2);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_AP_RECU_Data);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_MEAS_FECU_SDC);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_MEAS_RECU_SDC);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_NM_ELLIPSE_Status);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_NM_FECU_Keep_Alive);
DECLARE_TASK_MONITOR(SWT_CAN2_2024_NM_RECU_Keep_Alive);
DECLARE_TASK_MONITOR(Sync_25ms);
DECLARE_TASK_MONITOR(Timer_1000ms);
DECLARE_TASK_MONITOR(Timer_100ms);
DECLARE_TASK_MONITOR(Timer_25ms);
DECLARE_TASK_MONITOR(Timer_Inv);

DECLARE_TASK_MONITOR(ISR_CAN1_2024);
DECLARE_TASK_MONITOR(ISR_CAN2_2024);


#endif /* __TASK_MONITORS_H__ */
