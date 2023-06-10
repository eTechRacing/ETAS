#define NO_OSEKLIB
#include "ISR_CAN1.h"
#include "../a_basdef.h"

extern void crossbarHook_42_0(void);
extern void rtioHook_42_0(void);


ISR_MONITOR_DEF(ISR_CAN1, thread37);

ISR (ISR_CAN1)
{
	START_ISR_HOOK(ISR_CAN1);

	sgHook(42);

	crossbarHook_42_0();
	rtioHook_42_0();
	
	END_ISR_HOOK(ISR_CAN1);
}
