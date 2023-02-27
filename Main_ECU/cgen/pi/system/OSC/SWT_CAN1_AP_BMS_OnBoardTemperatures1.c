#define NO_OSEKLIB
#include "SWT_CAN1_AP_BMS_OnBoardTemperatures1.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_8_0(void);
extern void rtioHook_8_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_BMS_OnBoardTemperatures1, thread33);

TASK(SWT_CAN1_AP_BMS_OnBoardTemperatures1)
{
	START_TASK_HOOK(SWT_CAN1_AP_BMS_OnBoardTemperatures1);

	sgHook(8);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(8);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_BMS_OnBoardTemperatures1
    XCP_STIM_SWT_CAN1_AP_BMS_OnBoardTemperatures1
#endif
#endif
	crossbarHook_8_0();
	rtioHook_8_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_BMS_OnBoardTemperatures1
    XCP_DAQ_SWT_CAN1_AP_BMS_OnBoardTemperatures1
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_BMS_OnBoardTemperatures1);

	TerminateTask();
}
