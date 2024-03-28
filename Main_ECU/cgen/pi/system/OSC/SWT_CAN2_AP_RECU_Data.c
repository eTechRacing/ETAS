#define NO_OSEKLIB
#include "SWT_CAN2_AP_RECU_Data.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_24_0(void);
extern void rtioHook_24_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_RECU_Data, thread25);

TASK(SWT_CAN2_AP_RECU_Data)
{
	START_TASK_HOOK(SWT_CAN2_AP_RECU_Data);

	sgHook(24);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(24);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_RECU_Data
    XCP_STIM_SWT_CAN2_AP_RECU_Data
#endif
#endif
	crossbarHook_24_0();
	rtioHook_24_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_RECU_Data
    XCP_DAQ_SWT_CAN2_AP_RECU_Data
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_RECU_Data);

	TerminateTask();
}
