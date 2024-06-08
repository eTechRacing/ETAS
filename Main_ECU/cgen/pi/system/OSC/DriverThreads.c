#include "../a_basdef.h"


DRIVER_THREAD_MONITOR_DEF(threadEtasConfigTask);
DRIVER_THREAD_MONITOR_DEF(threadEtasL1Task);
DRIVER_THREAD_MONITOR_DEF(thread0);
DRIVER_THREAD_MONITOR_DEF(thread1);
DRIVER_THREAD_MONITOR_DEF(thread2);
DRIVER_THREAD_MONITOR_DEF(thread3);
DRIVER_THREAD_MONITOR_DEF(thread4);
DRIVER_THREAD_MONITOR_DEF(thread5);
DRIVER_THREAD_MONITOR_DEF(thread6);
DRIVER_THREAD_MONITOR_DEF(thread7);
DRIVER_THREAD_MONITOR_DEF(thread8);
DRIVER_THREAD_MONITOR_DEF(thread9);
DRIVER_THREAD_MONITOR_DEF(thread10);
DRIVER_THREAD_MONITOR_DEF(thread11);
DRIVER_THREAD_MONITOR_DEF(thread12);
DRIVER_THREAD_MONITOR_DEF(thread13);
DRIVER_THREAD_MONITOR_DEF(thread14);
DRIVER_THREAD_MONITOR_DEF(thread15);
DRIVER_THREAD_MONITOR_DEF(thread16);
DRIVER_THREAD_MONITOR_DEF(thread17);
DRIVER_THREAD_MONITOR_DEF(thread18);
DRIVER_THREAD_MONITOR_DEF(thread19);
DRIVER_THREAD_MONITOR_DEF(thread20);
DRIVER_THREAD_MONITOR_DEF(thread21);
DRIVER_THREAD_MONITOR_DEF(thread22);
DRIVER_THREAD_MONITOR_DEF(thread23);
DRIVER_THREAD_MONITOR_DEF(thread24);
DRIVER_THREAD_MONITOR_DEF(thread25);
DRIVER_THREAD_MONITOR_DEF(thread26);
DRIVER_THREAD_MONITOR_DEF(thread27);
DRIVER_THREAD_MONITOR_DEF(thread28);
/* fix dummy thread used for internal ISRs */
DRIVER_THREAD_MONITOR_DEF(threadEtasIsr);

uint32 etasCreateDriverThreads(int *ptrRtaOsekThreadPrio)
{
	/* IMPORTANT: The CREATE_DRIVER_THREAD macro calls must be ordered according
	 *  to increasing OSEK task priorities (lowest prio thread first) */
	uint32 retVal = 0;
	SET_NUMBER_OF_DRIVER_THREADS(29 + 3);
	
	/* create driver threads */
	CREATE_DRIVER_THREAD(threadEtasConfigTask);
	CREATE_DRIVER_THREAD(threadEtasL1Task);
	CREATE_DRIVER_THREAD(thread0);
	CREATE_DRIVER_THREAD(thread1);
	CREATE_DRIVER_THREAD(thread2);
	CREATE_DRIVER_THREAD(thread3);
	CREATE_DRIVER_THREAD(thread4);
	CREATE_DRIVER_THREAD(thread5);
	CREATE_DRIVER_THREAD(thread6);
	CREATE_DRIVER_THREAD(thread7);
	CREATE_DRIVER_THREAD(thread8);
	CREATE_DRIVER_THREAD(thread9);
	CREATE_DRIVER_THREAD(thread10);
	CREATE_DRIVER_THREAD(thread11);
	CREATE_DRIVER_THREAD(thread12);
	CREATE_DRIVER_THREAD(thread13);
	CREATE_DRIVER_THREAD(thread14);
	CREATE_DRIVER_THREAD(thread15);
	CREATE_DRIVER_THREAD(thread16);
	CREATE_DRIVER_THREAD(thread17);
	CREATE_DRIVER_THREAD(thread18);
	CREATE_DRIVER_THREAD(thread19);
	CREATE_DRIVER_THREAD(thread20);
	CREATE_DRIVER_THREAD(thread21);
	CREATE_DRIVER_THREAD(thread22);
	CREATE_DRIVER_THREAD(thread23);
	CREATE_DRIVER_THREAD(thread24);
	CREATE_DRIVER_THREAD(thread25);
	CREATE_DRIVER_THREAD(thread26);
	CREATE_DRIVER_THREAD(thread27);
	CREATE_DRIVER_THREAD(thread28);
	/* fix dummy thread used for internal ISRs */
	CREATE_DRIVER_THREAD(threadEtasIsr);
	
	return retVal;
}
