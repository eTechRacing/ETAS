#define NO_OSEKLIB
#include "SWT_CAN2_AP_LV_Derivation_LVData.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_29_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_LV_Derivation_LVData, thread19);

TASK(SWT_CAN2_AP_LV_Derivation_LVData)
{
	START_TASK_HOOK(SWT_CAN2_AP_LV_Derivation_LVData);

	sgHook(29);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(29);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_LV_Derivation_LVData
    XCP_STIM_SWT_CAN2_AP_LV_Derivation_LVData
#endif
#endif
	crossbarHook_29_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_LV_Derivation_LVData
    XCP_DAQ_SWT_CAN2_AP_LV_Derivation_LVData
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_LV_Derivation_LVData);

	TerminateTask();
}
