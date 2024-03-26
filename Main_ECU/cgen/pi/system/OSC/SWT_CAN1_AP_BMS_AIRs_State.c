#define NO_OSEKLIB
#include "SWT_CAN1_AP_BMS_AIRs_State.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_1_0(void);
extern void rtioHook_1_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_BMS_AIRs_State, thread13);

TASK(SWT_CAN1_AP_BMS_AIRs_State)
{
	START_TASK_HOOK(SWT_CAN1_AP_BMS_AIRs_State);

	sgHook(1);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(1);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_BMS_AIRs_State
    XCP_STIM_SWT_CAN1_AP_BMS_AIRs_State
#endif
#endif
	crossbarHook_1_0();
	rtioHook_1_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_BMS_AIRs_State
    XCP_DAQ_SWT_CAN1_AP_BMS_AIRs_State
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_BMS_AIRs_State);

	TerminateTask();
}
