/* This is an automatically generated file */
/* DO NOT EDIT THIS FILE */
/* File generated for project "os_config" */
/* Last edited 'unknown' */
/* File generated 'Fri Aug 30 17:22:01 2024' */
/* Target variant 'ES900' */

#ifndef OS_OSEKCOMN_H
#define OS_OSEKCOMN_H

/* RTA-TRACE 'disabled' support */
#define StartFreeRunningTrace() {}
#define StartBurstingTrace() {}
#define StartTriggeringTrace() {}
#define SetTraceRepeat(RPT) {}
#define CheckTraceOutput() {}
#define UploadTraceData() {}
#define SetTriggerConditions(a,b) {}
#define SetTriggerWindow(a,b) {}
#define StopTrace() {}
#define EnableTraceClasses(m) {}
#define DisableTraceClasses(m) {}
#define EnableTraceCategories(m) {}
#define DisableTraceCategories(m) {}
#define LogTracepoint(p, cats) {}
#define LogTaskTracepoint(p, cats) {}
#define LogIntervalStart(w, cats) {}
#define LogIntervalEnd(w, cats) {}
#define LogTracepointValue(p, cats, v) {}
#define LogTaskTracepointValue(p, cats, v) {}
#define LogIntervalStartValue(w, cats, v) {}
#define LogIntervalEndValue(w, cats, v) {}
#define LogTracepointData(p, cats, ptr, len) {}
#define LogTaskTracepointData(p, cats, ptr, len) {}
#define LogIntervalStartData(w, cats, ptr, len) {}
#define LogIntervalEndData(w, cats, ptr, len) {}
#define LogProfileStart(p) {}
#define LogCriticalExecution(ce) {}
#define LogCat1ISRStart(isr) {}
#define LogCat1ISREnd(isr) {}
#define LogOverrunHook() {}
#define TriggerOnActivation(TASK) {}
#define TriggerOnChain(TASK) {}
#define TriggerOnTaskStart(TASK) {}
#define TriggerOnTaskStop(TASK) {}
#define TriggerOnCat2ISRStart(TASK) {}
#define TriggerOnCat2ISRStop(TASK) {}
#define TriggerOnCat1ISRStart(ISR) {}
#define TriggerOnCat1ISRStop(ISR) {}
#define TriggerOnGetResource(RES) {}
#define TriggerOnReleaseResource(RES) {}
#define TriggerOnTaskTracepoint(POINT, TASK) {}
#define TriggerOnTracepoint(POINT) {}
#define TriggerOnIntervalStart(INTERVAL) {}
#define TriggerOnIntervalEnd(INTERVAL) {}
#define TriggerOnAlarmExpiry(ALARM) {}
#define TriggerOnSendMessage(MSG) {}
#define TriggerOnReceiveMessage(MSG) {}
#define TriggerOnShutdown(STATUS) {}
#define TriggerOnError(STATUS) {}
#define TriggerOnTickSchedule(SCHED) {}
#define TriggerOnAdvanceSchedule(SCHED) {}
#define TriggerOnAdvanceCounter(COUNT) {}
#define TriggerNow() {}
#define ClearTrigger() {}
#define TriggerOnSetEvent(STATUS) {}
#define TraceEnableISR(t) {}
#define TraceEnableTask(t) {}
#define TraceDisableISR(t) {}
#define TraceDisableTask(t) {}
#define TraceCommInit() (0)
#define OSTRACE_STATUS_OK (0)
#define OSTRACE_STATUS_COMM_INIT_FAILURE (1)
#ifndef OS_LIBRARY_SETTINGS
#define OS_ALLTASKRESOURCES
#endif /* OS_LIBRARY_SETTINGS */
#define OSEK_STARTUPHOOK
#define OSEK_SHUTDOWNHOOK
#define OSEK_ERRORHOOK
#define OSEK_USEGETSERVICEID
#define OSEK_USEPARAMETERACCESS
#define OS_RTA5_COMPATIBLE
#define OS_MAJOR_VERSION (5)
#define OS_MINOR_VERSION (0)
#define OS_PATCH_VERSION (3)
#define OS_MODULE_ID     (1)
#define OS_VENDOR_ID     (19)
#define OS_OILVERSION "2.3"
#define OS_COMVERSION "2"
#define OSEK_BCC2
#define OSEK_BCC2F
#define OS_NS_PER_CYCLE    (1)
#define OS_CYCLES_PER_SWTICK (0x927c0/0xc350)
/* Defaults - no SystemTimer or SYSTEM_COUNTER */
#define OSMAXALLOWEDVALUE ((TickType)4294967295U)
#define OSTICKSPERBASE    ((TickType)1U)
#define OSMINCYCLE        ((TickType)1U)
#define OSTICKDURATION    (1000000000UL / (sys_timebase_ticks_per_s))
#define OS_CYCLES_PER_etasCounter (0x927c0)
#define OSMAXALLOWEDVALUE_etasCounter ((TickType)4294967295U)
#define OSTICKSPERBASE_etasCounter    ((TickType)1U)
#define OSMINCYCLE_etasCounter        ((TickType)1U)
#define OSTICKDURATION_etasCounter    (1000000U)
#include "oscomn.h"
DeclareTask(SWT_CAN2_AP_FECU_Data1);
DeclareTask(SWT_CAN2_AP_FECU_Data2);
DeclareTask(SWT_CAN2_NM_RECU_Keep_Alive);
DeclareTask(SWT_CAN2_NM_FECU_Keep_Alive);
DeclareTask(SWT_CAN2_AP_RECU_Data);
DeclareTask(SWT_CAN2_AP_ELLIPSE_VEL_Valid);
DeclareTask(SWT_CAN2_AP_ELLIPSE_IMU_GYRO);
DeclareTask(SWT_CAN2_NM_ELLIPSE_Status);
DeclareTask(SWT_CAN2_AP_ELLIPSE_EKF_VEL);
DeclareTask(SWT_CAN2_AP_ELLIPSE_EKF_EULER);
DeclareTask(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL);
DeclareTask(SWT_CAN2_AP_ELLIPSE_EKF_POS);
DeclareTask(SWT_CAN2_MEAS_RECU_SDC);
DeclareTask(SWT_CAN2_AP_ELLIPSE_GPS_VEL);
DeclareTask(SWT_CAN2_AP_ELLIPSE_AUTO);
DeclareTask(SWT_CAN1_AP_DASH_EnableDrive);
DeclareTask(SWT_CAN1_AP_DASH_PrechargeRequest);
DeclareTask(SWT_CAN1_NM_DASH_Keep_Alive);
DeclareTask(SWT_CAN1_AP_BMS_AIRs_State);
DeclareTask(SWT_CAN1_NM_BMS_Keep_Alive);
DeclareTask(SWT_CAN1_AP_DASH_Mode);
DeclareTask(SWT_CAN1_AP_Inverter_L_Tx);
DeclareTask(SWT_CAN1_AP_Inverter_R_Tx);
DeclareTask(SWT_CAN1_AP_BMS_Temperatures);
DeclareTask(SWT_CAN1_AP_BMS_ChargerParameters);
DeclareTask(SWT_CAN1_AP_BMS_Voltages);
DeclareTask(SWT_CAN1_AP_CurrentSensor);
DeclareTask(SWT_CAN1_AP_BMS_SDC);
DeclareTask(Sync_25ms);
DeclareTask(Timer_1000ms);
DeclareTask(Timer_100ms);
DeclareTask(Timer_25ms);
DeclareTask(Timer_Inv);
DeclareTask(etasL1Task);
DeclareTask(etasConfigTask);
DeclareTask(osek_idle_task);
DeclareISR(etasTimerIsr);
#define OS_ISR_PRI_etasTimerIsr (10)
#define OS_ISR_ARB_etasTimerIsr (1)
DeclareISR(etasL1Isr);
#define OS_ISR_PRI_etasL1Isr (1)
#define OS_ISR_ARB_etasL1Isr (2)
DeclareISR(etasStopOsIsr);
#define OS_ISR_PRI_etasStopOsIsr (11)
#define OS_ISR_ARB_etasStopOsIsr (0)
DeclareISR(etasActivateTaskIsr);
#define OS_ISR_PRI_etasActivateTaskIsr (10)
#define OS_ISR_ARB_etasActivateTaskIsr (0)
DeclareISR(ISR_CAN1);
#define OS_ISR_PRI_ISR_CAN1 (1)
#define OS_ISR_ARB_ISR_CAN1 (1)
DeclareISR(ISR_CAN2);
#define OS_ISR_PRI_ISR_CAN2 (1)
#define OS_ISR_ARB_ISR_CAN2 (0)
DeclareAlarm(etasWatchdogAlarm);
extern ALARMCALLBACK(etasServiceWatchdog);
DeclareAlarm(SYNC_25MS);
DeclareAlarm(TIMER_1000MS);
DeclareAlarm(TIMER_100MS);
DeclareAlarm(TIMER_25MS);
DeclareAlarm(TIMER_INV);
extern OS_API_NONREENTRANT(void) Tick_etasCounter(void);
DeclareCounter(etasCounter);
#ifndef OSEK_ORTI_AdvanceCounter
 #define OSEK_ORTI_AdvanceCounter ((osSmallType)106U)
 #define OSServiceId_AdvanceCounter OSEK_ORTI_AdvanceCounter
 #ifdef OSEK_USEPARAMETERACCESS
  #define OSError_AdvanceCounter_CounterID() ((osCounterType)(os_serviceArgs.os_serviceArg1))
 #endif /* OSEK_USEPARAMETERACCESS */
#endif /* OSEK_ORTI_AdvanceCounter */
extern OS_API_NONREENTRANT(void) osResetOS(void);
#define OSDEFAULTAPPMODE ((AppModeType)(1))
#define etasStartup ((AppModeType)(2))
#define etasInactive ((AppModeType)(3))
#define Timer ((AppModeType)(4))
#endif /* OS_OSEKCOMN_H */

/* End of osekcomn.h */
