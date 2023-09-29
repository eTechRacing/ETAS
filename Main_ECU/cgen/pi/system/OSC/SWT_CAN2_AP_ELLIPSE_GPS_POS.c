#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_GPS_POS.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_29_0(void);
extern void rtioHook_29_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_GPS_POS, thread27);

TASK(SWT_CAN2_AP_ELLIPSE_GPS_POS)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_GPS_POS);

	sgHook(29);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(29);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_GPS_POS
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_GPS_POS
#endif
#endif
	crossbarHook_29_0();
	rtioHook_29_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_GPS_POS
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_GPS_POS
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_GPS_POS);

	TerminateTask();
}
