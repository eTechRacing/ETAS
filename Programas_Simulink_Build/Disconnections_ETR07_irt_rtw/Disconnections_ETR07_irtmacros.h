/*
 * File    : Disconnections_ETR07_irtmacros.h
 *
 * Abstract:
 *      This file provide some ETAS specific defines
 */

/* The simulink assert is mapped to an debug output */
extern void asdWriteUserDebug(char *s, ...);
extern void asdWriteUserError(char *s, ...);

#ifndef utAssert
#define utAssert(_exp)                 if(!(_exp)){ asdWriteUserDebug("IRT RTI: ** Simulink assertblock shows assertion failed. The expression was: '" #_exp "' **\n"); rtmSetStopRequestedFlag(Disconnections_ETR07_M, 1); asdWriteUserDebug("IRT RTI: ** Simulation halted! **\n");}
#endif

/* EOF: Disconnections_ETR07_irtmacros.h */
