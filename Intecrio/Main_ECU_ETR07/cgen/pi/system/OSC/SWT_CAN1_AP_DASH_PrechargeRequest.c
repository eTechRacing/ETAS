#define NO_OSEKLIB
#include "SWT_CAN1_AP_DASH_PrechargeRequest.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_14_0(void);
extern void rtioHook_14_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_DASH_PrechargeRequest, thread15);

TASK(SWT_CAN1_AP_DASH_PrechargeRequest)
{
	START_TASK_HOOK(SWT_CAN1_AP_DASH_PrechargeRequest);

	sgHook(14);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(14);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_DASH_PrechargeRequest
    XCP_STIM_SWT_CAN1_AP_DASH_PrechargeRequest
#endif
#endif
	crossbarHook_14_0();
	rtioHook_14_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_DASH_PrechargeRequest
    XCP_DAQ_SWT_CAN1_AP_DASH_PrechargeRequest
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_DASH_PrechargeRequest);

	TerminateTask();
}
