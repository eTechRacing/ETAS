#define NO_OSEKLIB
#include "NewISR.h"
#include "../a_basdef.h"

extern void crossbarHook_39_0(void);
extern void rtioHook_39_0(void);


ISR_MONITOR_DEF(NewISR, thread34);

ISR (NewISR)
{
	START_ISR_HOOK(NewISR);

	sgHook(39);

	crossbarHook_39_0();
	rtioHook_39_0();
	
	END_ISR_HOOK(NewISR);
}
