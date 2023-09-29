/*
 * Automatically generated output. DO NOT EDIT!!!
 * Configuration tool spec level 5, code level 1, revision 5
 * Target is "ES900", revision 1
 * Tool built at 13:17:55 on Jul  3 2012
 * Build level is standard
 * Project is 'os_config'
 * Last edited 'unknown'
 * File generated 'Sat Jun 10 11:02:45 2023'
 * Target variant 'ES900'
 */
#ifndef __OS_COMN_H__
#define __OS_COMN_H__
#ifdef OS_PREINCLUDE
#include OS_PREINCLUDE
#endif

#ifndef OS_STANDARD_BUILD
#define OS_STANDARD_BUILD (1U)
#endif
#include "oscore.h"
/* taskset handles */

extern OS_NEAR struct os_taskset OS_L0001;
#define os_ready_tasks (&OS_L0001)
extern struct os_taskset OS_L001D;
#define os_all_tasks (&OS_L001D)
extern struct os_taskset OS_L001E;
#define os_no_tasks (&OS_L001E)
extern struct os_taskset osek_bcc1_ts;
#define osek_bcc1_tasks (&osek_bcc1_ts)
extern struct os_taskset osek_cc2_ts;
#define osek_cc2_tasks (&osek_cc2_ts)
extern struct os_taskset osek_ecc_ts;
#define osek_ecc_tasks (&osek_ecc_ts)

/* task handles */
extern struct os_task OS_L0000;
#define os_idle_task (&OS_L0000)
extern struct os_task OS_L0033;
#define osek_task_SWT_CAN2_NM_ADCAN_Keep_Alive (&OS_L0033)
extern struct os_task OS_L0034;
#define osek_task_SWT_CAN2_AP_ADCAN_Data1 (&OS_L0034)
extern struct os_task OS_L0035;
#define osek_task_SWT_CAN2_AP_ADCAN_Data2 (&OS_L0035)
extern struct os_task OS_L0036;
#define osek_task_SWT_CAN2_AP_ACCEL_R_Data (&OS_L0036)
extern struct os_task OS_L0037;
#define osek_task_SWT_CAN2_NM_ACCEL_R_Keep_Alive (&OS_L0037)
extern struct os_task OS_L0038;
#define osek_task_SWT_CAN2_NM_ACCEL_F_Keep_Alive (&OS_L0038)
extern struct os_task OS_L0039;
#define osek_task_SWT_CAN2_AP_ACCEL_F_Data (&OS_L0039)
extern struct os_task OS_L003A;
#define osek_task_SWT_CAN2_NM_LV_Derivation_Keep_Alive (&OS_L003A)
extern struct os_task OS_L003B;
#define osek_task_SWT_CAN2_AP_ACCEL_R_Data2 (&OS_L003B)
extern struct os_task OS_L003C;
#define osek_task_SWT_CAN2_AP_LV_Derivation_LVData (&OS_L003C)
extern struct os_task OS_L003D;
#define osek_task_SWT_CAN2_AP_ELLIPSE_SLIP_CURV (&OS_L003D)
extern struct os_task OS_L003E;
#define osek_task_SWT_CAN2_AP_ELLIPSE_IMU_GYRO (&OS_L003E)
extern struct os_task OS_L003F;
#define osek_task_SWT_CAN2_NM_ELLIPSE_Status (&OS_L003F)
extern struct os_task OS_L0040;
#define osek_task_SWT_CAN2_AP_ELLIPSE_EKF_VEL_BODY (&OS_L0040)
extern struct os_task OS_L0041;
#define osek_task_SWT_CAN2_AP_ELLIPSE_EKF_EULER (&OS_L0041)
extern struct os_task OS_L0042;
#define osek_task_SWT_CAN2_AP_ELLIPSE_MAG (&OS_L0042)
extern struct os_task OS_L0043;
#define osek_task_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL (&OS_L0043)
extern struct os_task OS_L0044;
#define osek_task_SWT_CAN2_AP_ELLIPSE_EKF_POS (&OS_L0044)
extern struct os_task OS_L0045;
#define osek_task_SWT_CAN1_NM_SHUTDOWN_Keep_Alive (&OS_L0045)
extern struct os_task OS_L0046;
#define osek_task_SWT_CAN1_AP_SHUTDOWN_State (&OS_L0046)
extern struct os_task OS_L0047;
#define osek_task_SWT_CAN1_AP_DASH_EnableDrive (&OS_L0047)
extern struct os_task OS_L0048;
#define osek_task_SWT_CAN1_AP_DASH_PrechargeRequest (&OS_L0048)
extern struct os_task OS_L0049;
#define osek_task_SWT_CAN1_AP_DASH_TorqueLockOn (&OS_L0049)
extern struct os_task OS_L004A;
#define osek_task_SWT_CAN1_NM_DASH_Keep_Alive (&OS_L004A)
extern struct os_task OS_L004B;
#define osek_task_SWT_CAN1_AP_BMS_AIRs_State (&OS_L004B)
extern struct os_task OS_L004C;
#define osek_task_SWT_CAN1_NM_BMS_Keep_Alive (&OS_L004C)
extern struct os_task OS_L004D;
#define osek_task_SWT_CAN1_AP_DASH_Mode (&OS_L004D)
extern struct os_task OS_L004E;
#define osek_task_SWT_CAN1_AP_DASH_CustomMode (&OS_L004E)
extern struct os_task OS_L004F;
#define osek_task_SWT_CAN1_AP_Inverter_L_Tx (&OS_L004F)
extern struct os_task OS_L0050;
#define osek_task_SWT_CAN1_AP_Inverter_R_Tx (&OS_L0050)
extern struct os_task OS_L0051;
#define osek_task_SWT_CAN1_AP_BMS_BatteryTemperatures (&OS_L0051)
extern struct os_task OS_L0052;
#define osek_task_SWT_CAN1_AP_BMS_ChargerParameters (&OS_L0052)
extern struct os_task OS_L0053;
#define osek_task_SWT_CAN1_AP_BMS_OnBoardTemperatures (&OS_L0053)
extern struct os_task OS_L0054;
#define osek_task_SWT_CAN1_AP_BMS_Voltages (&OS_L0054)
extern struct os_task OS_L0055;
#define osek_task_SWT_CAN1_AP_BMS_StateAndFailReport (&OS_L0055)
extern struct os_task OS_L0056;
#define osek_task_SWT_CAN1_AP_BMS_Current_SOC_SOH (&OS_L0056)
extern struct os_task OS_L0057;
#define osek_task_Sync_25ms (&OS_L0057)
extern struct os_task OS_L0058;
#define osek_task_Timer_1000ms (&OS_L0058)
extern struct os_task OS_L0059;
#define osek_task_Timer_100ms (&OS_L0059)
extern struct os_task OS_L005A;
#define osek_task_Timer_25ms (&OS_L005A)
extern struct os_task OS_L005B;
#define osek_task_Timer_Inv (&OS_L005B)
extern struct os_task OS_L005C;
#define osek_task_etasL1Task (&OS_L005C)
extern struct os_task OS_L005D;
#define osek_task_etasConfigTask (&OS_L005D)

/* ISR handles */
extern struct os_task OS_L0061;
#define osek_interrupt_etasTimerIsr (&OS_L0061)
extern struct os_task OS_L0062;
#define osek_interrupt_etasL1Isr (&OS_L0062)
extern struct os_task OS_L0063;
#define osek_interrupt_etasStopOsIsr (&OS_L0063)
extern struct os_task OS_L0064;
#define osek_interrupt_etasActivateTaskIsr (&OS_L0064)
extern struct os_task OS_L0065;
#define osek_interrupt_ISR_CAN1 (&OS_L0065)
extern struct os_task OS_L0066;
#define osek_interrupt_ISR_CAN2 (&OS_L0066)

/* activator handles */

/* arrivalpoint handles */

/* timebase constants */
#define etasCounter_modulus (0U)
#define real_time_modulus (0U)
#define cpu_clock_modulus (0U)
#define sys_timebase_ticks_per_s (50000000.0000000)
#define sys_timebase_modulus (0U)





#endif /* __OS_COMN_H__ */