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
    {(TaskType *)&SWT_CAN1_AP_BMS_AIRs_State, "SWT_CAN1_AP_BMS_AIRs_State", TASK_MONITOR_PTR(SWT_CAN1_AP_BMS_AIRs_State)},
    {(TaskType *)&SWT_CAN1_AP_BMS_BatteryTemperatures, "SWT_CAN1_AP_BMS_BatteryTemperatures", TASK_MONITOR_PTR(SWT_CAN1_AP_BMS_BatteryTemperatures)},
    {(TaskType *)&SWT_CAN1_AP_BMS_ChargerParameters, "SWT_CAN1_AP_BMS_ChargerParameters", TASK_MONITOR_PTR(SWT_CAN1_AP_BMS_ChargerParameters)},
    {(TaskType *)&SWT_CAN1_AP_BMS_Current_SOC_SOH, "SWT_CAN1_AP_BMS_Current_SOC_SOH", TASK_MONITOR_PTR(SWT_CAN1_AP_BMS_Current_SOC_SOH)},
    {(TaskType *)&SWT_CAN1_AP_BMS_OnBoardTemperatures, "SWT_CAN1_AP_BMS_OnBoardTemperatures", TASK_MONITOR_PTR(SWT_CAN1_AP_BMS_OnBoardTemperatures)},
    {(TaskType *)&SWT_CAN1_AP_BMS_StateAndFailReport, "SWT_CAN1_AP_BMS_StateAndFailReport", TASK_MONITOR_PTR(SWT_CAN1_AP_BMS_StateAndFailReport)},
    {(TaskType *)&SWT_CAN1_AP_BMS_Voltages, "SWT_CAN1_AP_BMS_Voltages", TASK_MONITOR_PTR(SWT_CAN1_AP_BMS_Voltages)},
    {(TaskType *)&SWT_CAN1_AP_DASH_CustomMode, "SWT_CAN1_AP_DASH_CustomMode", TASK_MONITOR_PTR(SWT_CAN1_AP_DASH_CustomMode)},
    {(TaskType *)&SWT_CAN1_AP_DASH_EnableDrive, "SWT_CAN1_AP_DASH_EnableDrive", TASK_MONITOR_PTR(SWT_CAN1_AP_DASH_EnableDrive)},
    {(TaskType *)&SWT_CAN1_AP_DASH_Mode, "SWT_CAN1_AP_DASH_Mode", TASK_MONITOR_PTR(SWT_CAN1_AP_DASH_Mode)},
    {(TaskType *)&SWT_CAN1_AP_DASH_PrechargeRequest, "SWT_CAN1_AP_DASH_PrechargeRequest", TASK_MONITOR_PTR(SWT_CAN1_AP_DASH_PrechargeRequest)},
    {(TaskType *)&SWT_CAN1_AP_DASH_TorqueLockOn, "SWT_CAN1_AP_DASH_TorqueLockOn", TASK_MONITOR_PTR(SWT_CAN1_AP_DASH_TorqueLockOn)},
    {(TaskType *)&SWT_CAN1_AP_Inverter_L_Tx, "SWT_CAN1_AP_Inverter_L_Tx", TASK_MONITOR_PTR(SWT_CAN1_AP_Inverter_L_Tx)},
    {(TaskType *)&SWT_CAN1_AP_Inverter_R_Tx, "SWT_CAN1_AP_Inverter_R_Tx", TASK_MONITOR_PTR(SWT_CAN1_AP_Inverter_R_Tx)},
    {(TaskType *)&SWT_CAN1_AP_SHUTDOWN_State, "SWT_CAN1_AP_SHUTDOWN_State", TASK_MONITOR_PTR(SWT_CAN1_AP_SHUTDOWN_State)},
    {(TaskType *)&SWT_CAN1_NM_BMS_Keep_Alive, "SWT_CAN1_NM_BMS_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN1_NM_BMS_Keep_Alive)},
    {(TaskType *)&SWT_CAN1_NM_DASH_Keep_Alive, "SWT_CAN1_NM_DASH_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN1_NM_DASH_Keep_Alive)},
    {(TaskType *)&SWT_CAN1_NM_SHUTDOWN_Keep_Alive, "SWT_CAN1_NM_SHUTDOWN_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN1_NM_SHUTDOWN_Keep_Alive)},
    {(TaskType *)&SWT_CAN2_AP_ACCEL_F_Data, "SWT_CAN2_AP_ACCEL_F_Data", TASK_MONITOR_PTR(SWT_CAN2_AP_ACCEL_F_Data)},
    {(TaskType *)&SWT_CAN2_AP_ACCEL_R_Data, "SWT_CAN2_AP_ACCEL_R_Data", TASK_MONITOR_PTR(SWT_CAN2_AP_ACCEL_R_Data)},
    {(TaskType *)&SWT_CAN2_AP_ACCEL_R_Data2, "SWT_CAN2_AP_ACCEL_R_Data2", TASK_MONITOR_PTR(SWT_CAN2_AP_ACCEL_R_Data2)},
    {(TaskType *)&SWT_CAN2_AP_ADCAN_Data1, "SWT_CAN2_AP_ADCAN_Data1", TASK_MONITOR_PTR(SWT_CAN2_AP_ADCAN_Data1)},
    {(TaskType *)&SWT_CAN2_AP_ADCAN_Data2, "SWT_CAN2_AP_ADCAN_Data2", TASK_MONITOR_PTR(SWT_CAN2_AP_ADCAN_Data2)},
    {(TaskType *)&SWT_CAN2_AP_LV_Derivation_LVData, "SWT_CAN2_AP_LV_Derivation_LVData", TASK_MONITOR_PTR(SWT_CAN2_AP_LV_Derivation_LVData)},
    {(TaskType *)&SWT_CAN2_NM_ACCEL_F_Keep_Alive, "SWT_CAN2_NM_ACCEL_F_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN2_NM_ACCEL_F_Keep_Alive)},
    {(TaskType *)&SWT_CAN2_NM_ACCEL_R_Keep_Alive, "SWT_CAN2_NM_ACCEL_R_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN2_NM_ACCEL_R_Keep_Alive)},
    {(TaskType *)&SWT_CAN2_NM_ADCAN_Keep_Alive, "SWT_CAN2_NM_ADCAN_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN2_NM_ADCAN_Keep_Alive)},
    {(TaskType *)&SWT_CAN2_NM_LV_Derivation_Keep_Alive, "SWT_CAN2_NM_LV_Derivation_Keep_Alive", TASK_MONITOR_PTR(SWT_CAN2_NM_LV_Derivation_Keep_Alive)},
    {(TaskType *)&Sync_25ms, "Sync_25ms", TASK_MONITOR_PTR(Sync_25ms)},
    {(TaskType *)&Timer_1000ms, "Timer_1000ms", TASK_MONITOR_PTR(Timer_1000ms)},
    {(TaskType *)&Timer_100ms, "Timer_100ms", TASK_MONITOR_PTR(Timer_100ms)},
    {(TaskType *)&Timer_25ms, "Timer_25ms", TASK_MONITOR_PTR(Timer_25ms)},
    {(TaskType *)&Timer_Inv, "Timer_Inv", TASK_MONITOR_PTR(Timer_Inv)}
};

T_taskTable taskTable =
{
    1 + 33,
    &taskTableEntries[0]
};

/************** init tasks ******************/
extern void crossbarHook_36_0(void);
extern void irt_Start_Accel_Data(void);
extern void crossbarHook_36_1(void);
extern void crossbarHook_36_2(void);
extern void irt_Start_Car_State(void);
extern void crossbarHook_36_3(void);
extern void crossbarHook_36_4(void);
extern void irt_Start_Disconnections(void);
extern void crossbarHook_36_5(void);
extern void crossbarHook_36_6(void);
extern void irt_Start_Inverters_Action(void);
extern void crossbarHook_36_7(void);
extern void crossbarHook_36_8(void);
extern void irt_Start_Inverters_Data(void);
extern void crossbarHook_36_9(void);
extern void crossbarHook_36_10(void);
extern void irt_Start_LVD_Data(void);
extern void crossbarHook_36_11(void);
extern void crossbarHook_36_12(void);
extern void irt_Start_Pedals_Susp_Sensors(void);
extern void crossbarHook_36_13(void);
extern void crossbarHook_36_14(void);
extern void irt_Start_Racing_Mode(void);
extern void crossbarHook_36_15(void);
extern void crossbarHook_36_16(void);
extern void irt_Start_Synchronism(void);
extern void crossbarHook_36_17(void);
extern void crossbarHook_36_18(void);
extern void irt_Start_Torque_Control(void);
extern void crossbarHook_36_19(void);
extern void etasRtioInitProcess(void);
extern void rtioHook_36_0(void);
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

    crossbarHook_36_0();
	irt_Start_Accel_Data();
	crossbarHook_36_1();
	crossbarHook_36_2();
	irt_Start_Car_State();
	crossbarHook_36_3();
	crossbarHook_36_4();
	irt_Start_Disconnections();
	crossbarHook_36_5();
	crossbarHook_36_6();
	irt_Start_Inverters_Action();
	crossbarHook_36_7();
	crossbarHook_36_8();
	irt_Start_Inverters_Data();
	crossbarHook_36_9();
	crossbarHook_36_10();
	irt_Start_LVD_Data();
	crossbarHook_36_11();
	crossbarHook_36_12();
	irt_Start_Pedals_Susp_Sensors();
	crossbarHook_36_13();
	crossbarHook_36_14();
	irt_Start_Racing_Mode();
	crossbarHook_36_15();
	crossbarHook_36_16();
	irt_Start_Synchronism();
	crossbarHook_36_17();
	crossbarHook_36_18();
	irt_Start_Torque_Control();
	crossbarHook_36_19();
	etasRtioInitProcess();
	rtioHook_36_0();
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
extern void crossbarHook_37_0(void);
extern void irt_Terminate_Accel_Data(void);
extern void crossbarHook_37_1(void);
extern void crossbarHook_37_2(void);
extern void irt_Terminate_Car_State(void);
extern void crossbarHook_37_3(void);
extern void crossbarHook_37_4(void);
extern void irt_Terminate_Disconnections(void);
extern void crossbarHook_37_5(void);
extern void crossbarHook_37_6(void);
extern void irt_Terminate_Inverters_Action(void);
extern void crossbarHook_37_7(void);
extern void crossbarHook_37_8(void);
extern void irt_Terminate_Inverters_Data(void);
extern void crossbarHook_37_9(void);
extern void crossbarHook_37_10(void);
extern void irt_Terminate_LVD_Data(void);
extern void crossbarHook_37_11(void);
extern void crossbarHook_37_12(void);
extern void irt_Terminate_Pedals_Susp_Sensors(void);
extern void crossbarHook_37_13(void);
extern void crossbarHook_37_14(void);
extern void irt_Terminate_Racing_Mode(void);
extern void crossbarHook_37_15(void);
extern void crossbarHook_37_16(void);
extern void irt_Terminate_Synchronism(void);
extern void crossbarHook_37_17(void);
extern void crossbarHook_37_18(void);
extern void irt_Terminate_Torque_Control(void);
extern void crossbarHook_37_19(void);
extern void etasRtioIntDisableProcess(void);
extern void rtioHook_37_0(void);
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

    crossbarHook_37_0();
	irt_Terminate_Accel_Data();
	crossbarHook_37_1();
	crossbarHook_37_2();
	irt_Terminate_Car_State();
	crossbarHook_37_3();
	crossbarHook_37_4();
	irt_Terminate_Disconnections();
	crossbarHook_37_5();
	crossbarHook_37_6();
	irt_Terminate_Inverters_Action();
	crossbarHook_37_7();
	crossbarHook_37_8();
	irt_Terminate_Inverters_Data();
	crossbarHook_37_9();
	crossbarHook_37_10();
	irt_Terminate_LVD_Data();
	crossbarHook_37_11();
	crossbarHook_37_12();
	irt_Terminate_Pedals_Susp_Sensors();
	crossbarHook_37_13();
	crossbarHook_37_14();
	irt_Terminate_Racing_Mode();
	crossbarHook_37_15();
	crossbarHook_37_16();
	irt_Terminate_Synchronism();
	crossbarHook_37_17();
	crossbarHook_37_18();
	irt_Terminate_Torque_Control();
	crossbarHook_37_19();
	etasRtioIntDisableProcess();
	rtioHook_37_0();
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
sgTaskTableEntry sgTaskTable[1 + 33 + 2] = {NULL}; /* all elements are initialized with 0 */


