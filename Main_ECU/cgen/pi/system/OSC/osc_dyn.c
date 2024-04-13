/* Generated by INTECRIO */
/* (c) 2014 ETAS (ETAS GmbH) */

/* System internal declarations and definitions - not intended for user purposes. */

#include "../a_basdef.h"
#include "../a_targma.h"

#include "OSC_Dyn.h"

/**** forward declaration of initialization functions ****/



/**** application modes ****/
/* important: differences to ES113X */

extern AppModeType etasStartupAppMode;
extern AppModeType etasInactiveAppMode;
extern AppModeType TimersAppMode;

T_appModeTableEntry appModeEntries[] =
{
    {(AppModeType *)&etasStartupAppMode, "etasStartup"},
    {(AppModeType *)&etasInactiveAppMode, "etasInactive"},
    {(AppModeType *)&TimersAppMode, "Timers"}
};

T_appModeTable appModeTable =
{
    1+2,    /* number of modes in appModeEntries */
    0+2,    /* index of default application mode */
    &appModeEntries[0]
};

/**** task referencing ****/

T_taskTableEntry taskTableEntries[] =
{
    {(TaskType *)&etasConfigTask, "etasConfigTask", TASK_MONITOR_PTR(etasConfigTask)},
    {(TaskType *)&SWT_CAN1_2024_AP_BMS_AIRs_State, "SWT_CAN1_2024_AP_BMS_AIRs_State", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_BMS_AIRs_State)},
    {(TaskType *)&SWT_CAN1_2024_AP_BMS_BatteryTemperature, "SWT_CAN1_2024_AP_BMS_BatteryTemperature", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_BMS_BatteryTemperature)},
    {(TaskType *)&SWT_CAN1_2024_AP_BMS_ChargerParameters, "SWT_CAN1_2024_AP_BMS_ChargerParameters", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_BMS_ChargerParameters)},
    {(TaskType *)&SWT_CAN1_2024_AP_BMS_SDC, "SWT_CAN1_2024_AP_BMS_SDC", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_BMS_SDC)},
    {(TaskType *)&SWT_CAN1_2024_AP_BMS_Voltages, "SWT_CAN1_2024_AP_BMS_Voltages", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_BMS_Voltages)},
    {(TaskType *)&SWT_CAN1_2024_AP_CurrentSensor, "SWT_CAN1_2024_AP_CurrentSensor", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_CurrentSensor)},
    {(TaskType *)&SWT_CAN1_2024_AP_DASH_CustomMode, "SWT_CAN1_2024_AP_DASH_CustomMode", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_DASH_CustomMode)},
    {(TaskType *)&SWT_CAN1_2024_AP_DASH_EnableDrive, "SWT_CAN1_2024_AP_DASH_EnableDrive", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_DASH_EnableDrive)},
    {(TaskType *)&SWT_CAN1_2024_AP_DASH_Mode, "SWT_CAN1_2024_AP_DASH_Mode", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_DASH_Mode)},
    {(TaskType *)&SWT_CAN1_2024_AP_DASH_PrechargeRequest, "SWT_CAN1_2024_AP_DASH_PrechargeRequest", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_DASH_PrechargeRequest)},
    {(TaskType *)&SWT_CAN1_2024_AP_DASH_TorqueLockOn, "SWT_CAN1_2024_AP_DASH_TorqueLockOn", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_DASH_TorqueLockOn)},
    {(TaskType *)&SWT_CAN1_2024_AP_Inverter_L_Tx, "SWT_CAN1_2024_AP_Inverter_L_Tx", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_Inverter_L_Tx)},
    {(TaskType *)&SWT_CAN1_2024_AP_Inverter_R_Tx, "SWT_CAN1_2024_AP_Inverter_R_Tx", TASK_MONITOR_PTR(SWT_CAN1_2024_AP_Inverter_R_Tx)},
    {(TaskType *)&SWT_CAN1_2024_NM_BMS_Keep_Alive, "SWT_CAN1_2024_NM_BMS_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN1_2024_NM_BMS_Keep_Alive)},
    {(TaskType *)&SWT_CAN1_2024_NM_DASH_Keep_Alive, "SWT_CAN1_2024_NM_DASH_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN1_2024_NM_DASH_Keep_Alive)},
    {(TaskType *)&SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER, "SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER)},
    {(TaskType *)&SWT_CAN2_2024_AP_ELLIPSE_EKF_POS, "SWT_CAN2_2024_AP_ELLIPSE_EKF_POS", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_ELLIPSE_EKF_POS)},
    {(TaskType *)&SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL, "SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL)},
    {(TaskType *)&SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL, "SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL)},
    {(TaskType *)&SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO, "SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO)},
    {(TaskType *)&SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV, "SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV)},
    {(TaskType *)&SWT_CAN2_2024_AP_FECU_Data1, "SWT_CAN2_2024_AP_FECU_Data1", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_FECU_Data1)},
    {(TaskType *)&SWT_CAN2_2024_AP_FECU_Data2, "SWT_CAN2_2024_AP_FECU_Data2", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_FECU_Data2)},
    {(TaskType *)&SWT_CAN2_2024_AP_RECU_Data, "SWT_CAN2_2024_AP_RECU_Data", TASK_MONITOR_PTR(SWT_CAN2_2024_AP_RECU_Data)},
    {(TaskType *)&SWT_CAN2_2024_MEAS_FECU_SDC, "SWT_CAN2_2024_MEAS_FECU_SDC", TASK_MONITOR_PTR(SWT_CAN2_2024_MEAS_FECU_SDC)},
    {(TaskType *)&SWT_CAN2_2024_MEAS_RECU_SDC, "SWT_CAN2_2024_MEAS_RECU_SDC", TASK_MONITOR_PTR(SWT_CAN2_2024_MEAS_RECU_SDC)},
    {(TaskType *)&SWT_CAN2_2024_NM_ELLIPSE_Status, "SWT_CAN2_2024_NM_ELLIPSE_Status", TASK_MONITOR_PTR(SWT_CAN2_2024_NM_ELLIPSE_Status)},
    {(TaskType *)&SWT_CAN2_2024_NM_FECU_Keep_Alive, "SWT_CAN2_2024_NM_FECU_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN2_2024_NM_FECU_Keep_Alive)},
    {(TaskType *)&SWT_CAN2_2024_NM_RECU_Keep_Alive, "SWT_CAN2_2024_NM_RECU_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN2_2024_NM_RECU_Keep_Alive)},
    {(TaskType *)&Sync_25ms, "Sync_25ms", TASK_MONITOR_PTR(Sync_25ms)},
    {(TaskType *)&Timer_1000ms, "Timer_1000ms", TASK_MONITOR_PTR(Timer_1000ms)},
    {(TaskType *)&Timer_100ms, "Timer_100ms", TASK_MONITOR_PTR(Timer_100ms)},
    {(TaskType *)&Timer_25ms, "Timer_25ms", TASK_MONITOR_PTR(Timer_25ms)},
    {(TaskType *)&Timer_Inv, "Timer_Inv", TASK_MONITOR_PTR(Timer_Inv)}
};

T_taskTable taskTable =
{
    1 + 34,
    &taskTableEntries[0]
};

/************** init tasks ******************/
extern void crossbarHook_37_0(void);
extern void irt_Start_Car_State(void);
extern void crossbarHook_37_1(void);
extern void crossbarHook_37_2(void);
extern void irt_Start_Disconnections(void);
extern void crossbarHook_37_3(void);
extern void crossbarHook_37_4(void);
extern void irt_Start_Ellipse(void);
extern void crossbarHook_37_5(void);
extern void crossbarHook_37_6(void);
extern void irt_Start_Inverters_Action(void);
extern void crossbarHook_37_7(void);
extern void crossbarHook_37_8(void);
extern void irt_Start_Inverters_Data(void);
extern void crossbarHook_37_9(void);
extern void crossbarHook_37_10(void);
extern void irt_Start_Racing_Modes(void);
extern void crossbarHook_37_11(void);
extern void crossbarHook_37_12(void);
extern void irt_Start_Sensors(void);
extern void crossbarHook_37_13(void);
extern void crossbarHook_37_14(void);
extern void irt_Start_SoC(void);
extern void crossbarHook_37_15(void);
extern void crossbarHook_37_16(void);
extern void irt_Start_Synchronism(void);
extern void crossbarHook_37_17(void);
extern void crossbarHook_37_18(void);
extern void irt_Start_VDC(void);
extern void crossbarHook_37_19(void);
extern void etasRtioInitProcess(void);
extern void rtioHook_37_0(void);
extern void etasRtioIntEnableProcess(void);

void etasStartupInitTask(void)
{
#ifdef STARTUP_INIT_TASK_START_FW_HOOK
    STARTUP_INIT_TASK_START_FW_HOOK
#endif
    
    etasInitModelProcess();
    etasInitOsProcess();



    etasRtioStartupProcess();


#ifdef STARTUP_INIT_TASK_END_FW_HOOK
    STARTUP_INIT_TASK_END_FW_HOOK
#endif

    return;
}

void etasInactiveInitTask(void)
{
#ifdef INACTIVE_INIT_TASK_START_FW_HOOK
    INACTIVE_INIT_TASK_START_FW_HOOK
#endif

#ifdef INACTIVE_INIT_TASK_END_FW_HOOK
    INACTIVE_INIT_TASK_END_FW_HOOK
#endif

    return;
}

void TimersInitTask(void)
{
#ifdef USER_APP_MODE_INIT_TASK_START_FW_HOOK
    USER_APP_MODE_INIT_TASK_START_FW_HOOK
#endif

    crossbarHook_37_0();
	irt_Start_Car_State();
	crossbarHook_37_1();
	crossbarHook_37_2();
	irt_Start_Disconnections();
	crossbarHook_37_3();
	crossbarHook_37_4();
	irt_Start_Ellipse();
	crossbarHook_37_5();
	crossbarHook_37_6();
	irt_Start_Inverters_Action();
	crossbarHook_37_7();
	crossbarHook_37_8();
	irt_Start_Inverters_Data();
	crossbarHook_37_9();
	crossbarHook_37_10();
	irt_Start_Racing_Modes();
	crossbarHook_37_11();
	crossbarHook_37_12();
	irt_Start_Sensors();
	crossbarHook_37_13();
	crossbarHook_37_14();
	irt_Start_SoC();
	crossbarHook_37_15();
	crossbarHook_37_16();
	irt_Start_Synchronism();
	crossbarHook_37_17();
	crossbarHook_37_18();
	irt_Start_VDC();
	crossbarHook_37_19();
	etasRtioInitProcess();
	rtioHook_37_0();
	etasRtioIntEnableProcess();
	
    
#ifdef USER_APP_MODE_INIT_TASK_END_FW_HOOK
    USER_APP_MODE_INIT_TASK_END_FW_HOOK
#endif

    return;
}

void etasInitTasks(void)
{
    AppModeType curAppMode;

    curAppMode = GetActiveApplicationMode();

    switch(curAppMode)
    {
        case etasStartup:
            etasStartupInitTask();
            break;

        case etasInactive:
            etasInactiveInitTask();
            break;

        case Timers:
            TimersInitTask();
            break;
    }

    return;
}

/**************** exit tasks *****************/
extern void crossbarHook_38_0(void);
extern void irt_Terminate_Car_State(void);
extern void crossbarHook_38_1(void);
extern void crossbarHook_38_2(void);
extern void irt_Terminate_Disconnections(void);
extern void crossbarHook_38_3(void);
extern void crossbarHook_38_4(void);
extern void irt_Terminate_Ellipse(void);
extern void crossbarHook_38_5(void);
extern void crossbarHook_38_6(void);
extern void irt_Terminate_Inverters_Action(void);
extern void crossbarHook_38_7(void);
extern void crossbarHook_38_8(void);
extern void irt_Terminate_Inverters_Data(void);
extern void crossbarHook_38_9(void);
extern void crossbarHook_38_10(void);
extern void irt_Terminate_Racing_Modes(void);
extern void crossbarHook_38_11(void);
extern void crossbarHook_38_12(void);
extern void irt_Terminate_Sensors(void);
extern void crossbarHook_38_13(void);
extern void crossbarHook_38_14(void);
extern void irt_Terminate_SoC(void);
extern void crossbarHook_38_15(void);
extern void crossbarHook_38_16(void);
extern void irt_Terminate_Synchronism(void);
extern void crossbarHook_38_17(void);
extern void crossbarHook_38_18(void);
extern void irt_Terminate_VDC(void);
extern void crossbarHook_38_19(void);
extern void etasRtioIntDisableProcess(void);
extern void rtioHook_38_0(void);
extern void etasRtioExitProcess(void);

void etasStartupExitTask(void)
{
#ifdef STARTUP_EXIT_TASK_START_FW_HOOK
    STARTUP_EXIT_TASK_START_FW_HOOK
#endif

#ifdef STARTUP_EXIT_TASK_END_FW_HOOK
    STARTUP_EXIT_TASK_END_FW_HOOK
#endif
    return;
}

void etasInactiveExitTask(void)
{
#ifdef INACTIVE_EXIT_TASK_START_FW_HOOK
    INACTIVE_EXIT_TASK_START_FW_HOOK
#endif

#ifdef INACTIVE_EXIT_TASK_END_FW_HOOK
    INACTIVE_EXIT_TASK_END_FW_HOOK
#endif
    return;
}

void TimersExitTask(void)
{
#ifdef USER_APP_MODE_EXIT_TASK_START_FW_HOOK
    USER_APP_MODE_EXIT_TASK_START_FW_HOOK
#endif

    crossbarHook_38_0();
	irt_Terminate_Car_State();
	crossbarHook_38_1();
	crossbarHook_38_2();
	irt_Terminate_Disconnections();
	crossbarHook_38_3();
	crossbarHook_38_4();
	irt_Terminate_Ellipse();
	crossbarHook_38_5();
	crossbarHook_38_6();
	irt_Terminate_Inverters_Action();
	crossbarHook_38_7();
	crossbarHook_38_8();
	irt_Terminate_Inverters_Data();
	crossbarHook_38_9();
	crossbarHook_38_10();
	irt_Terminate_Racing_Modes();
	crossbarHook_38_11();
	crossbarHook_38_12();
	irt_Terminate_Sensors();
	crossbarHook_38_13();
	crossbarHook_38_14();
	irt_Terminate_SoC();
	crossbarHook_38_15();
	crossbarHook_38_16();
	irt_Terminate_Synchronism();
	crossbarHook_38_17();
	crossbarHook_38_18();
	irt_Terminate_VDC();
	crossbarHook_38_19();
	etasRtioIntDisableProcess();
	rtioHook_38_0();
	etasRtioExitProcess();
	
    
#ifdef USER_APP_MODE_EXIT_TASK_END_FW_HOOK
    USER_APP_MODE_EXIT_TASK_END_FW_HOOK
#endif
    return;
}

void etasExitTasks(void)
{
    AppModeType curAppMode;

    curAppMode = GetActiveApplicationMode();

    switch(curAppMode)
    {
        case etasStartup:
            etasStartupExitTask();
            break;

        case etasInactive:
            etasInactiveExitTask();
            break;

        case Timers:
            TimersExitTask();
            break;
    }

    return;
}

/**** OS administration ****/

T_osAdmin osAdmin =
{
    &appModeTable,
    &taskTable
};

/************ dummies **********/

/* stimuligenerator table */
sgTaskTableEntry sgTaskTable[1 + 34 + 2] = {NULL}; /* all elements are initialized with 0 */


