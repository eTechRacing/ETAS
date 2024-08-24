#define NO_OSEKLIB
#include "ISR_CAN2.h"
#include "../a_basdef.h"

extern void crossbarHook_36_0(void);
extern void rtioHook_36_0(void);


ISR_MONITOR_DEF(ISR_CAN2, thread30);

ISR (ISR_CAN2)
{
	START_ISR_HOOK(ISR_CAN2);

	sgHook(36);

	crossbarHook_36_0();
	rtioHook_36_0();
	
	END_ISR_HOOK(ISR_CAN2);
}
