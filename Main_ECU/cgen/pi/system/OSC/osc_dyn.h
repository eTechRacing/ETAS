/* Generated by INTECRIO */
/* (c) 2014 ETAS (ETAS GmbH) */

/* System internal declarations and definitions - not intended for user purposes. */

#ifndef __OSC_DYN_H__
#define __OSC_DYN_H__

#ifdef XCP_SLAVE
#include "etashead\etas_typ.h"
extern uint Xcp_Event (uint eventId, uint doDaq);

#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_AIRs_State Xcp_Event(0,0);
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_AIRs_State Xcp_Event(0,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_ChargerParameters Xcp_Event(1,0);
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_ChargerParameters Xcp_Event(1,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_SDC Xcp_Event(2,0);
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_SDC Xcp_Event(2,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_Temperatures Xcp_Event(3,0);
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_Temperatures Xcp_Event(3,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_Voltages Xcp_Event(4,0);
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_Voltages Xcp_Event(4,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_CurrentSensor Xcp_Event(5,0);
#define XCP_STIM_SWT_CAN1_2024_AP_CurrentSensor Xcp_Event(5,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_CustomMode Xcp_Event(6,0);
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_CustomMode Xcp_Event(6,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_EnableDrive Xcp_Event(7,0);
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_EnableDrive Xcp_Event(7,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_Mode Xcp_Event(8,0);
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_Mode Xcp_Event(8,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_PrechargeRequest Xcp_Event(9,0);
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_PrechargeRequest Xcp_Event(9,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_TorqueLockOn Xcp_Event(10,0);
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_TorqueLockOn Xcp_Event(10,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_Inverter_L_Tx Xcp_Event(11,0);
#define XCP_STIM_SWT_CAN1_2024_AP_Inverter_L_Tx Xcp_Event(11,1);
#define XCP_DAQ_SWT_CAN1_2024_AP_Inverter_R_Tx Xcp_Event(12,0);
#define XCP_STIM_SWT_CAN1_2024_AP_Inverter_R_Tx Xcp_Event(12,1);
#define XCP_DAQ_SWT_CAN1_2024_NM_BMS_Keep_Alive Xcp_Event(13,0);
#define XCP_STIM_SWT_CAN1_2024_NM_BMS_Keep_Alive Xcp_Event(13,1);
#define XCP_DAQ_SWT_CAN1_2024_NM_DASH_Keep_Alive Xcp_Event(14,0);
#define XCP_STIM_SWT_CAN1_2024_NM_DASH_Keep_Alive Xcp_Event(14,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER Xcp_Event(15,0);
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER Xcp_Event(15,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS Xcp_Event(16,0);
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS Xcp_Event(16,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL Xcp_Event(17,0);
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL Xcp_Event(17,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL Xcp_Event(18,0);
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL Xcp_Event(18,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO Xcp_Event(19,0);
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO Xcp_Event(19,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV Xcp_Event(20,0);
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV Xcp_Event(20,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_FECU_Data1 Xcp_Event(21,0);
#define XCP_STIM_SWT_CAN2_2024_AP_FECU_Data1 Xcp_Event(21,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_FECU_Data2 Xcp_Event(22,0);
#define XCP_STIM_SWT_CAN2_2024_AP_FECU_Data2 Xcp_Event(22,1);
#define XCP_DAQ_SWT_CAN2_2024_AP_RECU_Data Xcp_Event(23,0);
#define XCP_STIM_SWT_CAN2_2024_AP_RECU_Data Xcp_Event(23,1);
#define XCP_DAQ_SWT_CAN2_2024_MEAS_FECU_SDC Xcp_Event(24,0);
#define XCP_STIM_SWT_CAN2_2024_MEAS_FECU_SDC Xcp_Event(24,1);
#define XCP_DAQ_SWT_CAN2_2024_MEAS_RECU_SDC Xcp_Event(25,0);
#define XCP_STIM_SWT_CAN2_2024_MEAS_RECU_SDC Xcp_Event(25,1);
#define XCP_DAQ_SWT_CAN2_2024_NM_ELLIPSE_Status Xcp_Event(26,0);
#define XCP_STIM_SWT_CAN2_2024_NM_ELLIPSE_Status Xcp_Event(26,1);
#define XCP_DAQ_SWT_CAN2_2024_NM_FECU_Keep_Alive Xcp_Event(27,0);
#define XCP_STIM_SWT_CAN2_2024_NM_FECU_Keep_Alive Xcp_Event(27,1);
#define XCP_DAQ_SWT_CAN2_2024_NM_RECU_Keep_Alive Xcp_Event(28,0);
#define XCP_STIM_SWT_CAN2_2024_NM_RECU_Keep_Alive Xcp_Event(28,1);
#define XCP_DAQ_Sync_25ms Xcp_Event(29,0);
#define XCP_STIM_Sync_25ms Xcp_Event(29,1);
#define XCP_DAQ_Timer_1000ms Xcp_Event(30,0);
#define XCP_STIM_Timer_1000ms Xcp_Event(30,1);
#define XCP_DAQ_Timer_100ms Xcp_Event(31,0);
#define XCP_STIM_Timer_100ms Xcp_Event(31,1);
#define XCP_DAQ_Timer_25ms Xcp_Event(32,0);
#define XCP_STIM_Timer_25ms Xcp_Event(32,1);
#define XCP_DAQ_Timer_Inv Xcp_Event(33,0);
#define XCP_STIM_Timer_Inv Xcp_Event(33,1);

#else
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_AIRs_State 
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_AIRs_State
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_ChargerParameters 
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_ChargerParameters
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_SDC 
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_SDC
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_Temperatures 
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_Temperatures
#define XCP_DAQ_SWT_CAN1_2024_AP_BMS_Voltages 
#define XCP_STIM_SWT_CAN1_2024_AP_BMS_Voltages
#define XCP_DAQ_SWT_CAN1_2024_AP_CurrentSensor 
#define XCP_STIM_SWT_CAN1_2024_AP_CurrentSensor
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_CustomMode 
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_CustomMode
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_EnableDrive 
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_EnableDrive
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_Mode 
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_Mode
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_PrechargeRequest 
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_PrechargeRequest
#define XCP_DAQ_SWT_CAN1_2024_AP_DASH_TorqueLockOn 
#define XCP_STIM_SWT_CAN1_2024_AP_DASH_TorqueLockOn
#define XCP_DAQ_SWT_CAN1_2024_AP_Inverter_L_Tx 
#define XCP_STIM_SWT_CAN1_2024_AP_Inverter_L_Tx
#define XCP_DAQ_SWT_CAN1_2024_AP_Inverter_R_Tx 
#define XCP_STIM_SWT_CAN1_2024_AP_Inverter_R_Tx
#define XCP_DAQ_SWT_CAN1_2024_NM_BMS_Keep_Alive 
#define XCP_STIM_SWT_CAN1_2024_NM_BMS_Keep_Alive
#define XCP_DAQ_SWT_CAN1_2024_NM_DASH_Keep_Alive 
#define XCP_STIM_SWT_CAN1_2024_NM_DASH_Keep_Alive
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER 
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS 
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_EKF_POS
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL 
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL 
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO 
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO
#define XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV 
#define XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV
#define XCP_DAQ_SWT_CAN2_2024_AP_FECU_Data1 
#define XCP_STIM_SWT_CAN2_2024_AP_FECU_Data1
#define XCP_DAQ_SWT_CAN2_2024_AP_FECU_Data2 
#define XCP_STIM_SWT_CAN2_2024_AP_FECU_Data2
#define XCP_DAQ_SWT_CAN2_2024_AP_RECU_Data 
#define XCP_STIM_SWT_CAN2_2024_AP_RECU_Data
#define XCP_DAQ_SWT_CAN2_2024_MEAS_FECU_SDC 
#define XCP_STIM_SWT_CAN2_2024_MEAS_FECU_SDC
#define XCP_DAQ_SWT_CAN2_2024_MEAS_RECU_SDC 
#define XCP_STIM_SWT_CAN2_2024_MEAS_RECU_SDC
#define XCP_DAQ_SWT_CAN2_2024_NM_ELLIPSE_Status 
#define XCP_STIM_SWT_CAN2_2024_NM_ELLIPSE_Status
#define XCP_DAQ_SWT_CAN2_2024_NM_FECU_Keep_Alive 
#define XCP_STIM_SWT_CAN2_2024_NM_FECU_Keep_Alive
#define XCP_DAQ_SWT_CAN2_2024_NM_RECU_Keep_Alive 
#define XCP_STIM_SWT_CAN2_2024_NM_RECU_Keep_Alive
#define XCP_DAQ_Sync_25ms 
#define XCP_STIM_Sync_25ms
#define XCP_DAQ_Timer_1000ms 
#define XCP_STIM_Timer_1000ms
#define XCP_DAQ_Timer_100ms 
#define XCP_STIM_Timer_100ms
#define XCP_DAQ_Timer_25ms 
#define XCP_STIM_Timer_25ms
#define XCP_DAQ_Timer_Inv 
#define XCP_STIM_Timer_Inv

#endif

#define XCP_NUMBER_OF_EVENTS 34

#endif /* __OSC_DYN_H__ */

