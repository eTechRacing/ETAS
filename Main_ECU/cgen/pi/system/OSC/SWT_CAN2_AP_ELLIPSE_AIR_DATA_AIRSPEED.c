#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_24_0(void);
extern void rtioHook_24_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED, thread22);

TASK(SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED);

	sgHook(24);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(24);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED
#endif
#endif
	crossbarHook_24_0();
	rtioHook_24_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_AIR_DATA_AIRSPEED);

	TerminateTask();
}
