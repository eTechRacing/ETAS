#define NO_OSEKLIB
#include "SWT_CAN1_AP_BMS_StateAndFailReport.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_6_0(void);
extern void rtioHook_6_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_BMS_StateAndFailReport, thread2);

TASK(SWT_CAN1_AP_BMS_StateAndFailReport)
{
	START_TASK_HOOK(SWT_CAN1_AP_BMS_StateAndFailReport);

	sgHook(6);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(6);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_BMS_StateAndFailReport
    XCP_STIM_SWT_CAN1_AP_BMS_StateAndFailReport
#endif
#endif
	crossbarHook_6_0();
	rtioHook_6_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_BMS_StateAndFailReport
    XCP_DAQ_SWT_CAN1_AP_BMS_StateAndFailReport
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_BMS_StateAndFailReport);

	TerminateTask();
}
