/* This file is necessary, because application modes are just
 * numbers (defines) which are generated first by rtabuild at runtime. Because
 * these applications modes are referenced inside the system library, we must
 * introduce application mode variables which are initilalized with the
 * concrete application mode numbers. */  

#include "../a_basdef.h"


/* static part */
AppModeType etasStartupAppMode = etasStartup;
AppModeType etasInactiveAppMode = etasInactive;

/* dynamic part */
AppModeType UserAppModeAppMode = UserAppMode;
			

uint32 etasGetCounterPeriodUs(void)
{
	return 500;	
}



/* Function is expected from RTA-OSEK when extended tasks are present */
OS_HOOK(void) StackFaultHook(SmallType StackID, SmallType StackError, UIntType Overflow)
{
}
