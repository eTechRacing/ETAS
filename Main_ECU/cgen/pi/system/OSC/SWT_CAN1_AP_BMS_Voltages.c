#define NO_OSEKLIB
#include "SWT_CAN1_AP_BMS_Voltages.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_6_0(void);
extern void rtioHook_6_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_BMS_Voltages, thread5);

TASK(SWT_CAN1_AP_BMS_Voltages)
{
	START_TASK_HOOK(SWT_CAN1_AP_BMS_Voltages);

	sgHook(6);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(6);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_BMS_Voltages
    XCP_STIM_SWT_CAN1_AP_BMS_Voltages
#endif
#endif
	crossbarHook_6_0();
	rtioHook_6_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_BMS_Voltages
    XCP_DAQ_SWT_CAN1_AP_BMS_Voltages
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_BMS_Voltages);

	TerminateTask();
}
