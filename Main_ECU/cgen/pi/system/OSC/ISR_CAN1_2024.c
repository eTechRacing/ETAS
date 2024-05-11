#define NO_OSEKLIB
#include "ISR_CAN1_2024.h"
#include "../a_basdef.h"

extern void crossbarHook_35_0(void);
extern void rtioHook_35_0(void);


ISR_MONITOR_DEF(ISR_CAN1_2024, thread30);

ISR (ISR_CAN1_2024)
{
	START_ISR_HOOK(ISR_CAN1_2024);

	sgHook(35);

	crossbarHook_35_0();
	rtioHook_35_0();
	
	END_ISR_HOOK(ISR_CAN1_2024);
}
