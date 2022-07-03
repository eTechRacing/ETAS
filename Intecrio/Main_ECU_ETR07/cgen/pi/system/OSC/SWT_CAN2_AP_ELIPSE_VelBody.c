#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELIPSE_VelBody.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_28_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELIPSE_VelBody, thread30);

TASK(SWT_CAN2_AP_ELIPSE_VelBody)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELIPSE_VelBody);

	sgHook(28);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(28);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELIPSE_VelBody
    XCP_STIM_SWT_CAN2_AP_ELIPSE_VelBody
#endif
#endif
	crossbarHook_28_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELIPSE_VelBody
    XCP_DAQ_SWT_CAN2_AP_ELIPSE_VelBody
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELIPSE_VelBody);

	TerminateTask();
}
