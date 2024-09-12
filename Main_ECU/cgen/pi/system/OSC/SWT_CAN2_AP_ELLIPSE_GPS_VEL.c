#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_GPS_VEL.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_18_0(void);
extern void rtioHook_18_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_GPS_VEL, thread15);

TASK(SWT_CAN2_AP_ELLIPSE_GPS_VEL)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_GPS_VEL);

	sgHook(18);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(18);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_GPS_VEL
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_GPS_VEL
#endif
#endif
	crossbarHook_18_0();
	rtioHook_18_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_GPS_VEL
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_GPS_VEL
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_GPS_VEL);

	TerminateTask();
}
