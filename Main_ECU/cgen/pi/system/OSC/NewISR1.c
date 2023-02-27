#define NO_OSEKLIB
#include "NewISR1.h"
#include "../a_basdef.h"

extern void crossbarHook_40_0(void);
extern void rtioHook_40_0(void);


ISR_MONITOR_DEF(NewISR1, thread34);

ISR (NewISR1)
{
	START_ISR_HOOK(NewISR1);

	sgHook(40);

	crossbarHook_40_0();
	rtioHook_40_0();
	
	END_ISR_HOOK(NewISR1);
}
