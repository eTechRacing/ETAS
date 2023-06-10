#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_25_0(void);
extern void rtioHook_25_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE, thread21);

TASK(SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE);

	sgHook(25);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(25);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE
#endif
#endif
	crossbarHook_25_0();
	rtioHook_25_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_AIR_DATA_ALTITUDE);

	TerminateTask();
}
