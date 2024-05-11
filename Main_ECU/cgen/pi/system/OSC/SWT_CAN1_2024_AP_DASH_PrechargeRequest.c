#define NO_OSEKLIB
#include "SWT_CAN1_2024_AP_DASH_PrechargeRequest.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_10_0(void);
extern void rtioHook_10_0(void);


TASK_MONITOR_DEF(SWT_CAN1_2024_AP_DASH_PrechargeRequest, thread14);

TASK(SWT_CAN1_2024_AP_DASH_PrechargeRequest)
{
	START_TASK_HOOK(SWT_CAN1_2024_AP_DASH_PrechargeRequest);

	sgHook(10);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(10);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_2024_AP_DASH_PrechargeRequest
    XCP_STIM_SWT_CAN1_2024_AP_DASH_PrechargeRequest
#endif
#endif
	crossbarHook_10_0();
	rtioHook_10_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_2024_AP_DASH_PrechargeRequest
    XCP_DAQ_SWT_CAN1_2024_AP_DASH_PrechargeRequest
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_2024_AP_DASH_PrechargeRequest);

	TerminateTask();
}
