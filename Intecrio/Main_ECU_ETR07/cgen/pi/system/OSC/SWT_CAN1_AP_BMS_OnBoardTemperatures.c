#define NO_OSEKLIB
#include "SWT_CAN1_AP_BMS_OnBoardTemperatures.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_7_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_BMS_OnBoardTemperatures, thread7);

TASK(SWT_CAN1_AP_BMS_OnBoardTemperatures)
{
	START_TASK_HOOK(SWT_CAN1_AP_BMS_OnBoardTemperatures);

	sgHook(7);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(7);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_BMS_OnBoardTemperatures
    XCP_STIM_SWT_CAN1_AP_BMS_OnBoardTemperatures
#endif
#endif
	crossbarHook_7_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_BMS_OnBoardTemperatures
    XCP_DAQ_SWT_CAN1_AP_BMS_OnBoardTemperatures
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_BMS_OnBoardTemperatures);

	TerminateTask();
}
