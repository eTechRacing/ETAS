#define NO_OSEKLIB
#include "SWT_CAN1_2024_AP_BMS_SDC.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_3_0(void);
extern void rtioHook_3_0(void);


TASK_MONITOR_DEF(SWT_CAN1_2024_AP_BMS_SDC, thread1);

TASK(SWT_CAN1_2024_AP_BMS_SDC)
{
	START_TASK_HOOK(SWT_CAN1_2024_AP_BMS_SDC);

	sgHook(3);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(3);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_2024_AP_BMS_SDC
    XCP_STIM_SWT_CAN1_2024_AP_BMS_SDC
#endif
#endif
	crossbarHook_3_0();
	rtioHook_3_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_2024_AP_BMS_SDC
    XCP_DAQ_SWT_CAN1_2024_AP_BMS_SDC
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_2024_AP_BMS_SDC);

	TerminateTask();
}
