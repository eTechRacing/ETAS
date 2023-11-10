/* Patched in by the INTECRIO IRT target */
/* PATCH BEGIN */
#include "Torque_Control_irtmacros.h"
/* PATCH END */

/*
 * Torque_Control.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 1.182
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Nov 10 03:01:16 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torque_Control_h_
#define RTW_HEADER_Torque_Control_h_
#include <math.h>
#include <string.h>
#ifndef Torque_Control_COMMON_INCLUDES_
# define Torque_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* Torque_Control_COMMON_INCLUDES_ */

#include "Torque_Control_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVDRMdlRefTiming
# define rtmGetVDRMdlRefTiming(rtm)    ()
#endif

#ifndef rtmSetVDRMdlRefTiming
# define rtmSetVDRMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetVDRMdlRefTimingPtr
# define rtmGetVDRMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetVDRMdlRefTimingPtr
# define rtmSetVDRMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetVDRNumTicksToNextHit
# define rtmGetVDRNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetVDRNumTicksToNextHit
# define rtmSetVDRNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Torque_Control_rtModel         RT_MODEL_Torque_Control_T

/* Block signals for system '<S122>/MATLAB Function' */
typedef struct {
  real_T RegTq_RR;                     /* '<S122>/MATLAB Function' */
  real_T RegTq_RL;                     /* '<S122>/MATLAB Function' */
} B_MATLABFunction_Torque_Contr_T;

/* Block signals for system '<S110>/Braking with Regenerative' */
typedef struct {
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction;/* '<S122>/MATLAB Function' */
} B_BrakingwithRegenerative_Tor_T;

/* Block signals for system '<S111>/Accelerator behaviour ' */
typedef struct {
  real_T throttle;                     /* '<S111>/Accelerator behaviour ' */
} B_Acceleratorbehaviour_Torque_T;

/* Block signals for system '<S78>/MATLAB Function1' */
typedef struct {
  real_T value;                        /* '<S78>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Cont_T;

/* Block signals for system '<S118>/MATLAB Function' */
typedef struct {
  real_T RPM;                          /* '<S118>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_d_T;

/* Block signals for system '<S161>/MATLAB Function' */
typedef struct {
  real_T SKF_act0;                     /* '<S161>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_i_T;

/* Block signals for system '<S158>/MATLAB Function' */
typedef struct {
  real_T CKF_act1;                     /* '<S158>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_k_T;

/* Block signals for system '<S157>/MATLAB Function1' */
typedef struct {
  real_T CKF_act0;                     /* '<S157>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Co_m_T;

/* Block signals for system '<S115>/MATLAB Function' */
typedef struct {
  real_T value;                        /* '<S115>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_h_T;

/* Block signals for system '<S120>/MATLAB Function1' */
typedef struct {
  real_T value;                        /* '<S120>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Co_d_T;

/* Block signals (auto storage) */
typedef struct {
  real_T kamm_data[544];
  real_T Merge5;                       /* '<S43>/Merge5' */
  real_T Constant;                     /* '<S44>/Constant' */
  real_T Constant14;                   /* '<Root>/Constant14' */
  real_T Constant_n;                   /* '<S38>/Constant' */
  real_T Constant_i;                   /* '<S37>/Constant' */
  real_T Constant_b;                   /* '<S216>/Constant' */
  real_T Constant1;                    /* '<S213>/Constant1' */
  real_T Constant2;                    /* '<S213>/Constant2' */
  real_T initial_limitation;           /* '<S16>/initial_limitation' */
  real_T Constant3;                    /* '<S213>/Constant3' */
  real_T Constant_a;                   /* '<S217>/Constant' */
  real_T Constant1_a;                  /* '<S214>/Constant1' */
  real_T Constant2_p;                  /* '<S214>/Constant2' */
  real_T Constant3_i;                  /* '<S214>/Constant3' */
  real_T Constant_d;                   /* '<S218>/Constant' */
  real_T Constant1_h;                  /* '<S215>/Constant1' */
  real_T Constant2_pf;                 /* '<S215>/Constant2' */
  real_T Constant3_f;                  /* '<S215>/Constant3' */
  real_T GearRatio;                    /* '<Root>/Gear Ratio' */
  real_T MaxTqpermotorNm;              /* '<Root>/Max Tq per motor [Nm]' */
  real_T Max_Power_dischargekW;        /* '<S9>/Max_Power_discharge [kW]' */
  real_T Max_Power_chargekW;           /* '<S9>/Max_Power_charge [kW]' */
  real_T Constant_j;                   /* '<S210>/Constant' */
  real_T Constant_do;                  /* '<S211>/Constant' */
  real_T Constant_bc;                  /* '<S212>/Constant' */
  real_T Abs;                          /* '<S14>/Abs' */
  real_T Constant_m;                   /* '<S207>/Constant' */
  real_T Merge;                        /* '<S66>/Merge' */
  real_T Merge1;                       /* '<S66>/Merge1' */
  real_T Merge2;                       /* '<S66>/Merge2' */
  real_T Merge3;                       /* '<S66>/Merge3' */
  real_T Constant_o;                   /* '<S65>/Constant' */
  real_T Enabled_a;                    /* '<S65>/Enabled' */
  real_T Zero;                         /* '<S65>/Zero ' */
  real_T Merge1_a;                     /* '<S65>/Merge1' */
  real_T Constant_aq;                  /* '<S67>/Constant' */
  real_T Merge_l;                      /* '<S67>/Merge' */
  real_T Gain;                         /* '<S67>/Gain' */
  real_T SteeringWheelSaturationpersited;/* '<S67>/Steering Wheel Saturation (per site) [deg] ' */
  real_T MergeTq_RL;                   /* '<S67>/Merge Tq_RL' */
  real_T MergeTq_RR;                   /* '<S67>/Merge Tq_RR' */
  real_T Merge2_l;                     /* '<S67>/Merge2' */
  real_T Merge3_c;                     /* '<S67>/Merge3' */
  real_T RT_L;                         /* '<S76>/RT_L' */
  real_T RT_R;                         /* '<S76>/RT_R' */
  real_T SteeringWheelMaximumAngle;    /* '<S98>/Steering Wheel Maximum Angle' */
  real_T SteeringWheelMaximumAngle_m;  /* '<S77>/Steering Wheel Maximum Angle' */
  real_T Tq_max_motorNm;               /* '<S77>/Tq_max_motor [Nm]' */
  real_T Tq_diff_maxNm;                /* '<S77>/Tq_diff_max [Nm]' */
  real_T Merge_d;                      /* '<S82>/Merge' */
  real_T Merge1_p;                     /* '<S82>/Merge1' */
  real_T Merge_k;                      /* '<S99>/Merge' */
  real_T Saturation;                   /* '<S99>/Saturation' */
  real_T Constant_ob;                  /* '<S103>/Constant' */
  real_T Merge_kj;                     /* '<S101>/Merge' */
  real_T Saturation_k;                 /* '<S101>/Saturation' */
  real_T Constant_du;                  /* '<S107>/Constant' */
  real_T Merge_g;                      /* '<S201>/Merge' */
  real_T Product;                      /* '<S172>/Product' */
  real_T Constant_e;                   /* '<S171>/Constant' */
  real_T Constant1_b;                  /* '<S173>/Constant1' */
  real_T udifference;                  /* '<S172>/3% difference' */
  real_T Constant1_k;                  /* '<S171>/Constant1' */
  real_T Constant_dd;                  /* '<S173>/Constant' */
  real_T Merge_li;                     /* '<S170>/Merge' */
  real_T Merge1_l;                     /* '<S170>/Merge1' */
  real_T Constant_f;                   /* '<S203>/Constant' */
  real_T approx2095;                   /* '<S177>/Gain' */
  real_T TowheelTqstatic;              /* '<S177>/To wheel Tq (static)' */
  real_T TowheelTqdynamic;             /* '<S177>/To wheel Tq (dynamic)' */
  real_T Merge2_o;                     /* '<S177>/Merge2' */
  real_T SteeringWheelMaximumAngle_p;  /* '<S153>/Steering Wheel Maximum Angle' */
  real_T Constant_p;                   /* '<S78>/Constant' */
  real_T MaximumTorqueperengineNm;     /* '<S113>/Maximum Torque per engine [Nm]' */
  real_T MaximumTransmissionTorqueDynami;/* '<S113>/Maximum Transmission Torque Dynamic [Nm]' */
  real_T MaximumTransmissionTorqueStatic;/* '<S113>/Maximum Transmission Torque Static [Nm]' */
  real_T Constant1_i;                  /* '<S120>/Constant1' */
  real_T Constant1_j;                  /* '<S113>/Constant1' */
  real_T Merge2_lx;                    /* '<S78>/Merge2' */
  real_T udifference1;                 /* '<S113>/3% difference1' */
  real_T TransmisionRatio;             /* '<S113>/Transmision Ratio[-]' */
  real_T Divide;                       /* '<S166>/Divide' */
  real_T Constant_bb;                  /* '<S120>/Constant' */
  real_T Merge3_e;                     /* '<S78>/Merge3' */
  real_T Divide_i;                     /* '<S165>/Divide' */
  real_T Tq_diff_Max;                  /* '<S113>/Tq_diff_Max' */
  real_T Merge_kt;                     /* '<S111>/Merge' */
  real_T Merge1_b;                     /* '<S111>/Merge1' */
  real_T Merge_m;                      /* '<S78>/Merge' */
  real_T Merge1_n;                     /* '<S78>/Merge1' */
  real_T Merge4;                       /* '<S78>/Merge4' */
  real_T Merge5_e;                     /* '<S78>/Merge5' */
  real_T Merge6;                       /* '<S78>/Merge6' */
  real_T Merge7;                       /* '<S78>/Merge7' */
  real_T OutportBufferForFlags_num5[4];/* '<S78>/Flags' */
  real_T Constant3_b;                  /* '<S114>/Constant3' */
  real_T Constant4;                    /* '<S114>/Constant4' */
  real_T Steering_Ratio;               /* '<S142>/Steering_Ratio [-]' */
  real_T Constant8;                    /* '<S142>/Constant8' */
  real_T Constant7;                    /* '<S142>/Constant7' */
  real_T Wheelbasem;                   /* '<S142>/Wheelbase [m]' */
  real_T u602pi;                       /* '<S142>/360//(2*pi)' */
  real_T u602pi_e;                     /* '<S142>/360//(2pi)' */
  real_T Yaw_Inertiakgm3;              /* '<S114>/Yaw_Inertia [kg//m^3]' */
  real_T Divide1;                      /* '<S144>/Divide1' */
  real_T Constant_mf;                  /* '<S115>/Constant' */
  real_T Constant3_e;                  /* '<S115>/Constant3' */
  real_T Constant4_m;                  /* '<S115>/Constant4' */
  real_T Merge_c;                      /* '<S154>/Merge' */
  real_T Saturation_i;                 /* '<S154>/Saturation' */
  real_T Constant_dw;                  /* '<S158>/Constant' */
  real_T Merge_i;                      /* '<S156>/Merge' */
  real_T Saturation_f;                 /* '<S156>/Saturation' */
  real_T Constant_k;                   /* '<S162>/Constant' */
  real_T Throttle;                     /* '<S131>/Throttle' */
  real_T approx2095_h;                 /* '<S121>/Gain' */
  real_T Merge2_j;                     /* '<S121>/Merge2' */
  real_T OutportBufferForFlag_Power;   /* '<S121>/Constant' */
  real_T exptcycletau1;                /* '<S54>/exp(-tcycle//tau)1' */
  real_T Subtract;                     /* '<S54>/Subtract' */
  real_T Max_Tq_per_motor;             /* '<S3>/Max_Tq_per_motor' */
  real_T Constant_g;                   /* '<S33>/Constant' */
  real_T Constant1_l;                  /* '<S30>/Constant1' */
  real_T Constant2_n;                  /* '<S30>/Constant2' */
  real_T initial_limitation_m;         /* '<S3>/initial_limitation' */
  real_T Constant3_o;                  /* '<S30>/Constant3' */
  real_T Constant_j3;                  /* '<S34>/Constant' */
  real_T Constant1_d;                  /* '<S31>/Constant1' */
  real_T Constant2_k;                  /* '<S31>/Constant2' */
  real_T Constant3_n;                  /* '<S31>/Constant3' */
  real_T Constant_mu;                  /* '<S35>/Constant' */
  real_T Constant1_c;                  /* '<S32>/Constant1' */
  real_T Constant2_m;                  /* '<S32>/Constant2' */
  real_T Constant3_it;                 /* '<S32>/Constant3' */
  real_T Constant_jv;                  /* '<S27>/Constant' */
  real_T Constant_o4;                  /* '<S28>/Constant' */
  real_T Constant_kc;                  /* '<S29>/Constant' */
  real_T Merge1_pg;                    /* '<S17>/Merge1' */
  real_T Merge1_a0;                    /* '<Root>/Merge1' */
  real_T Merge2_e;                     /* '<Root>/Merge2' */
  real_T Constant_c;                   /* '<S121>/Constant' */
  boolean_T LogicalOperator1;          /* '<S43>/Logical Operator1' */
  boolean_T Merge_j;                   /* '<S42>/Merge' */
  boolean_T LogicalOperator;           /* '<S11>/Logical Operator' */
  boolean_T Compare;                   /* '<S27>/Compare' */
  boolean_T Compare_d;                 /* '<S28>/Compare' */
  boolean_T Compare_g;                 /* '<S29>/Compare' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_o;/* '<S80>/Accelerator behaviour ' */
  B_MATLABFunction1_Torque_Co_m_T sf_MATLABFunction_k2;/* '<S102>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_i_T sf_MATLABFunction_fq;/* '<S106>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_d_T sf_MATLABFunction_ab;/* '<S88>/MATLAB Function' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_br;/* '<S77>/Accelerator behaviour' */
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction1_h;/* '<S94>/MATLAB Function1' */
  B_MATLABFunction1_Torque_Co_m_T sf_MATLABFunction_a;/* '<S202>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_k_T sf_MATLABFunction_i1;/* '<S203>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_d_T sf_MATLABFunction_fa;/* '<S175>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_b;/* '<S173>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_f;/* '<S173>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_m;/* '<S171>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_gm;/* '<S171>/MATLAB Function1' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_b;/* '<S186>/Accelerator behaviour ' */
  B_BrakingwithRegenerative_Tor_T BrakingwithRegenerative_b;/* '<S169>/Braking with Regenerative' */
  B_MATLABFunction1_Torque_Co_d_T sf_MATLABFunction2;/* '<S120>/MATLAB Function2' */
  B_MATLABFunction1_Torque_Co_d_T sf_MATLABFunction1_m;/* '<S120>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_e;/* '<S114>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_mk;/* '<S114>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_g;/* '<S115>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction_d;/* '<S115>/MATLAB Function' */
  B_MATLABFunction1_Torque_Co_m_T sf_MATLABFunction1_b;/* '<S157>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_k_T sf_MATLABFunction_mt;/* '<S158>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_i_T sf_MATLABFunction_e;/* '<S161>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_d_T sf_MATLABFunction_n;/* '<S118>/MATLAB Function' */
  B_MATLABFunction1_Torque_Cont_T sf_MATLABFunction2_l;/* '<S78>/MATLAB Function2' */
  B_MATLABFunction1_Torque_Cont_T sf_MATLABFunction1_ny;/* '<S78>/MATLAB Function1' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour;/* '<S111>/Accelerator behaviour ' */
  B_BrakingwithRegenerative_Tor_T BrakingwithRegenerative;/* '<S110>/Braking with Regenerative' */
} B_Torque_Control_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S88>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S88>/Derivative' */
  real_T TimeStampB;                   /* '<S88>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S88>/Derivative' */
  real_T A;                            /* '<S88>/Data Store Memory' */
  real_T B;                            /* '<S88>/Data Store Memory1' */
  real_T TimeStampA_b;                 /* '<S175>/Derivative' */
  real_T LastUAtTimeA_e;               /* '<S175>/Derivative' */
  real_T TimeStampB_e;                 /* '<S175>/Derivative' */
  real_T LastUAtTimeB_o;               /* '<S175>/Derivative' */
  real_T B_k;                          /* '<S175>/Data Store Memory1' */
  real_T TimeStampA_g;                 /* '<S118>/Derivative' */
  real_T LastUAtTimeA_c;               /* '<S118>/Derivative' */
  real_T TimeStampB_c;                 /* '<S118>/Derivative' */
  real_T LastUAtTimeB_f;               /* '<S118>/Derivative' */
  real_T A_b;                          /* '<S118>/Data Store Memory' */
  real_T B_i;                          /* '<S118>/Data Store Memory1' */
  real_T Previous_IN;                  /* '<S54>/Data Store Memory' */
  real_T Previous_OUT;                 /* '<S54>/Data Store Memory1' */
  real_T A_i;                          /* '<S17>/Data Store Memory10' */
  int8_T If2_ActiveSubsystem;          /* '<S43>/If2' */
  int8_T If3_ActiveSubsystem;          /* '<S43>/If3' */
  int8_T MEMO1_ActiveSubsystem;        /* '<S43>/MEMO1' */
  int8_T If_ActiveSubsystem;           /* '<S42>/If' */
  int8_T If_ActiveSubsystem_k;         /* '<S14>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S10>/If' */
  int8_T If_ActiveSubsystem_e;         /* '<Root>/If' */
  int8_T If1_ActiveSubsystem;          /* '<Root>/If1' */
  int8_T If_ActiveSubsystem_ed;        /* '<S68>/If' */
  int8_T If_ActiveSubsystem_a;         /* '<S66>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S65>/If' */
  int8_T If_ActiveSubsystem_j;         /* '<S67>/If' */
  int8_T FAILUREMODE_ActiveSubsystem;  /* '<S67>/FAILURE MODE' */
  int8_T SKForCKF_ActiveSubsystem;     /* '<S98>/SKF or CKF' */
  int8_T If1_ActiveSubsystem_c;        /* '<S77>/If1' */
  int8_T If_ActiveSubsystem_ds;        /* '<S77>/If' */
  int8_T BrakingConditions_ActiveSubsyst;/* '<S82>/Braking Conditions' */
  int8_T If1_ActiveSubsystem_ca;       /* '<S99>/If1' */
  int8_T If_ActiveSubsystem_jm;        /* '<S101>/If' */
  int8_T If1_ActiveSubsystem_a;        /* '<S201>/If1' */
  int8_T BrakingConditions_ActiveSubsy_c;/* '<S170>/Braking Conditions' */
  int8_T If_ActiveSubsystem_h;         /* '<S169>/If' */
  int8_T If1_ActiveSubsystem_b;        /* '<S177>/If1' */
  int8_T SKForCKF_ActiveSubsystem_o;   /* '<S153>/SKF or CKF' */
  int8_T Steer_angisinSteer_SatrangeLong;/* '<S78>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
  int8_T BrakingConditions_ActiveSubsy_b;/* '<S111>/Braking Conditions' */
  int8_T If_ActiveSubsystem_aq;        /* '<S110>/If' */
  int8_T If1_ActiveSubsystem_o;        /* '<S154>/If1' */
  int8_T If_ActiveSubsystem_ha;        /* '<S156>/If' */
  int8_T If1_ActiveSubsystem_bn;       /* '<S121>/If1' */
  int8_T If_ActiveSubsystem_kl;        /* '<S17>/If' */
  int8_T If_ActiveSubsystem_c;         /* '<S19>/If' */
  boolean_T AA;                        /* '<S43>/Data Store Memory1' */
} DW_Torque_Control_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S114>/Integrator' */
} X_Torque_Control_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S114>/Integrator' */
} XDot_Torque_Control_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S114>/Integrator' */
} XDis_Torque_Control_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T VDC_SKF_Initial;              /* '<Root>/VDC_SKF_Initial' */
  real_T VDC_CKF_Initial;              /* '<Root>/VDC_CKF_Initial' */
  real_T VDC_Cte_SKF;                  /* '<Root>/VDC_Cte_SKF' */
  real_T VDC_Cte_CKF;                  /* '<Root>/VDC_Cte_CKF' */
  real_T VDC_Apps_Sat_Down;            /* '<Root>/VDC_Apps_Sat_Down' */
  real_T VDC_Apps_Sat_Up;              /* '<Root>/VDC_Apps_Sat_Up' */
  real_T VDC_Max_Regenerative_Torque;  /* '<Root>/VDC_Max_Regenerative_Torque' */
  real_T VDC_Power_Limit;              /* '<Root>/VDC_Power_Limit' */
  real_T VDC_K_Reduction_P;            /* '<Root>/VDC_K_Reduction_P' */
  real_T VDC_K_Reduction_Temperature;  /* '<Root>/VDC_K_Reduction_Temperature' */
  real_T Workshop_Mode_Enable;         /* '<Root>/Workshop_Mode_Enable' */
  boolean_T TorqueEnable;              /* '<Root>/TorqueEnable' */
  real_T TV_Mode;                      /* '<Root>/TV_Mode' */
  real_T SteeringSensor_Bits;          /* '<Root>/SteeringSensor_Bits' */
  real_T Highest_CellTemp;             /* '<Root>/Highest_CellTemp' */
  boolean_T CriticalDisconnection;     /* '<Root>/CriticalDisconnection' */
  boolean_T ShutdownClosed;            /* '<Root>/ShutdownClosed' */
  real_T ACCEL_R_X_SI;                 /* '<Root>/ACCEL_R_X_SI' */
  real_T ACCEL_R_Y_SI;                 /* '<Root>/ACCEL_R_Y_SI' */
  real_T ACCEL_R_Z_SI;                 /* '<Root>/ACCEL_R_Z_SI' */
  real_T ACCEL_F_X_SI;                 /* '<Root>/ACCEL_F_X_SI' */
  real_T ACCEL_F_Y_SI;                 /* '<Root>/ACCEL_F_Y_SI' */
  real_T ACCEL_F_Z_SI;                 /* '<Root>/ACCEL_F_Z_SI' */
  real_T Accumulator_Voltage;          /* '<Root>/Accumulator_Voltage' */
  real_T Accumulator_Current;          /* '<Root>/Accumulator_Current' */
  real_T APPS2_Value;                  /* '<Root>/APPS2_Value' */
  real_T APPS1_Value;                  /* '<Root>/APPS1_Value' */
  real_T BrakeSensor_Value;            /* '<Root>/BrakeSensor_Value' */
  real_T Susp_F_L;                     /* '<Root>/Susp_F_L' */
  real_T Susp_F_R;                     /* '<Root>/Susp_F_R' */
  real_T Susp_R_L;                     /* '<Root>/Susp_R_L' */
  real_T Susp_R_R;                     /* '<Root>/Susp_R_R' */
  real_T Vel_RL_kmh;                   /* '<Root>/Vel_RL_kmh' */
  real_T Vel_RR_kmh;                   /* '<Root>/Vel_RR_kmh' */
  real_T RL_rads;                      /* '<Root>/RL_rads' */
  real_T RR_rads;                      /* '<Root>/RR_rads' */
  real_T Temp_Motors;                  /* '<Root>/Temp_Motors' */
  real_T Temp_IGBT;                    /* '<Root>/Temp_IGBT' */
  real_T Gyro_F_Z_Deg;                 /* '<Root>/Gyro_F_Z_Deg' */
  real_T Car_State;                    /* '<Root>/Car_State' */
  real_T SoC_Low;                      /* '<Root>/SoC_Low' */
  real_T SoC_High;                     /* '<Root>/SoC_High' */
} ExtU_Torque_Control_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Torque_RRwc;                  /* '<Root>/Torque_RRwc' */
  real_T Torque_RLwc;                  /* '<Root>/Torque_RLwc' */
  real_T Max_Torque_RR;                /* '<Root>/Max_Torque_RR' */
  real_T Max_Torque_RL;                /* '<Root>/Max_Torque_RL' */
  real_T Max_Fx_RR;                    /* '<Root>/Max_Fx_RR' */
  real_T Max_Fx_RL;                    /* '<Root>/Max_Fx_RL' */
  real_T Throttle;                     /* '<Root>/Throttle' */
  real_T Fy_R;                         /* '<Root>/Fy_R' */
  real_T Mass;                         /* '<Root>/Mass' */
  real_T Handling;                     /* '<Root>/Handling' */
  real_T SKF_actual;                   /* '<Root>/SKF_actual' */
  real_T CKF_actual;                   /* '<Root>/CKF_actual' */
  real_T SteeringSensor_Value;         /* '<Root>/SteeringSensor_Value' */
  boolean_T APPS_Implausibility;       /* '<Root>/APPS_Implausibility' */
  boolean_T Brake_Implausibility;      /* '<Root>/Brake_Implausibility' */
  real_T TV_Flag_WheelSpinRR;          /* '<Root>/TV_Flag_WheelSpinRR' */
  real_T TV_Flag_WheelSpinRL;          /* '<Root>/TV_Flag_WheelSpinRL' */
  real_T TV_Flag_Power;                /* '<Root>/TV_Flag_Power' */
  real_T TV_Flag_CarBehaviour;         /* '<Root>/TV_Flag_CarBehaviour' */
  real_T Power;                        /* '<Root>/Power' */
  real_T PowerLimitReached;            /* '<Root>/PowerLimitReached' */
  real_T PowerMean500ms;               /* '<Root>/PowerMean500ms' */
  boolean_T Torque_OK;                 /* '<Root>/Torque_OK' */
  real_T Regenerative_Enable;          /* '<Root>/Regenerative_Enable' */
  real_T Dash_Speed;                   /* '<Root>/Dash_Speed' */
  real_T Pumps_Control;                /* '<Root>/Pumps_Control' */
  real_T MeasVDCTorque_L;              /* '<Root>/Meas VDC Torque_L' */
  real_T MeasVDCTorque_R;              /* '<Root>/Meas VDC Torque_R' */
  real_T Torque_L;                     /* '<Root>/Torque_L' */
  real_T Torque_R;                     /* '<Root>/Torque_R' */
  real_T current_L;                    /* '<Root>/current_L' */
  real_T current_R;                    /* '<Root>/current_R' */
  real_T TV_Flag_Temperature;          /* '<Root>/TV_Flag_Temperature' */
} ExtY_Torque_Control_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Torque_Control_B
#define BlockIO                        B_Torque_Control_T
#define rtU                            Torque_Control_U
#define ExternalInputs                 ExtU_Torque_Control_T
#define rtX                            Torque_Control_X
#define ContinuousStates               X_Torque_Control_T
#define rtXdot                         Torque_Control_XDot
#define StateDerivatives               XDot_Torque_Control_T
#define tXdis                          Torque_Control_XDis
#define StateDisabled                  XDis_Torque_Control_T
#define rtY                            Torque_Control_Y
#define ExternalOutputs                ExtY_Torque_Control_T
#define rtP                            Torque_Control_P
#define Parameters                     P_Torque_Control_T
#define rtDWork                        Torque_Control_DW
#define D_Work                         DW_Torque_Control_T

/* Parameters for system: '<S17>/LimitReached' */
struct P_LimitReached_Torque_Control_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
};

/* Parameters for system: '<S42>/Imp' */
struct P_Imp_Torque_Control_T_ {
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S46>/Constant'
                                        */
};

/* Parameters for system: '<S43>/If Action Subsystem2' */
struct P_IfActionSubsystem2_Torque_C_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S48>/Constant'
                                        */
};

/* Parameters for system: '<S110>/Braking with Regenerative' */
struct P_BrakingwithRegenerative_Tor_T_ {
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S122>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S122>/Gain1'
                                        */
};

/* Parameters for system: '<S111>/Mech_Braking' */
struct P_Mech_Braking_Torque_Control_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S134>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S134>/Constant1'
                                        */
};

/* Parameters (auto storage) */
struct P_Torque_Control_T_ {
  real_T Temphigherthan50_const;       /* Mask Parameter: Temphigherthan50_const
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Temphigherthan50_const_k;     /* Mask Parameter: Temphigherthan50_const_k
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Temphigherthan110_const;      /* Mask Parameter: Temphigherthan110_const
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Flag_Accu_const;              /* Mask Parameter: Flag_Accu_const
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Flag_Inv_const;               /* Mask Parameter: Flag_Inv_const
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Flag_Mot_const;               /* Mask Parameter: Flag_Mot_const
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T CompareToConstant_const_p;    /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Temphigherthan50_const_l;     /* Mask Parameter: Temphigherthan50_const_l
                                        * Referenced by: '<S216>/Constant'
                                        */
  real_T Temphigherthan50_const_g;     /* Mask Parameter: Temphigherthan50_const_g
                                        * Referenced by: '<S217>/Constant'
                                        */
  real_T Temphigherthan110_const_c;    /* Mask Parameter: Temphigherthan110_const_c
                                        * Referenced by: '<S218>/Constant'
                                        */
  real_T Flag_Accu_const_h;            /* Mask Parameter: Flag_Accu_const_h
                                        * Referenced by: '<S210>/Constant'
                                        */
  real_T Flag_Inv_const_e;             /* Mask Parameter: Flag_Inv_const_e
                                        * Referenced by: '<S211>/Constant'
                                        */
  real_T Flag_Mot_const_n;             /* Mask Parameter: Flag_Mot_const_n
                                        * Referenced by: '<S212>/Constant'
                                        */
  real_T DataStoreMemory10_InitialValue;/* Expression: 0
                                         * Referenced by: '<S17>/Data Store Memory10'
                                         */
  real_T Max_Tq_per_motor_Value;       /* Expression: 120
                                        * Referenced by: '<S3>/Max_Tq_per_motor'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/100
                                        * Referenced by: '<S24>/Gain6'
                                        */
  real_T Lookup_SoC_SoP_dischg_tableData[8];/* Expression: [0.4 0.6 0.8 0.95 1 1 0.98 0.95]
                                             * Referenced by: '<S24>/Lookup_SoC_SoP_dischg'
                                             */
  real_T Lookup_SoC_SoP_dischg_bp01Data[8];/* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.9 1]
                                            * Referenced by: '<S24>/Lookup_SoC_SoP_dischg'
                                            */
  real_T Constant1_Value;              /* Expression: 45
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 5
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T initial_limitation_Value;     /* Expression: 0.4
                                        * Referenced by: '<S3>/initial_limitation'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S30>/Constant3'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S30>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S30>/Saturation1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 45
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 5
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant3_Value_d;            /* Expression: 1
                                        * Referenced by: '<S31>/Constant3'
                                        */
  real_T Saturation1_UpperSat_a;       /* Expression: 1
                                        * Referenced by: '<S31>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_a;       /* Expression: 0
                                        * Referenced by: '<S31>/Saturation1'
                                        */
  real_T Constant1_Value_p;            /* Expression: 105
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 5
                                        * Referenced by: '<S32>/Constant2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 1
                                        * Referenced by: '<S32>/Constant3'
                                        */
  real_T Saturation1_UpperSat_g;       /* Expression: 1
                                        * Referenced by: '<S32>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: 0
                                        * Referenced by: '<S32>/Saturation1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/100
                                        * Referenced by: '<S24>/Gain5'
                                        */
  real_T Lookup_SoC_SoP_chg_tableData[8];/* Expression: [0.95 1 1 1 1 0.9 0.75 0.02]
                                          * Referenced by: '<S24>/Lookup_SoC_SoP_chg'
                                          */
  real_T Lookup_SoC_SoP_chg_bp01Data[8];/* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.95 1]
                                         * Referenced by: '<S24>/Lookup_SoC_SoP_chg'
                                         */
  real_T Lookup_Temp_SoP_chg_tableData[5];/* Expression: [1 0.75 0.5 0 0]
                                           * Referenced by: '<S24>/Lookup_Temp_SoP_chg'
                                           */
  real_T Lookup_Temp_SoP_chg_bp01Data[5];/* Expression: [45 48 49 50 51]
                                          * Referenced by: '<S24>/Lookup_Temp_SoP_chg'
                                          */
  real_T Saturation1_UpperSat_e;       /* Expression: 1
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_o;       /* Expression: 0
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T ANm_Gain;                     /* Expression: 0.2
                                        * Referenced by: '<S22>/A//Nm'
                                        */
  real_T ANm_Gain_b;                   /* Expression: 0.2
                                        * Referenced by: '<S23>/A//Nm'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T ct_Value;                     /* Expression: 1
                                        * Referenced by: '<S54>/ct'
                                        */
  real_T exptcycletau1_Value;          /* Expression: 0.905
                                        * Referenced by: '<S54>/exp(-tcycle//tau)1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S54>/Gain'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<S54>/Data Store Memory'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<S54>/Data Store Memory1'
                                        */
  real_T rpm_Value;                    /* Expression: 200
                                        * Referenced by: '<S121>/rpm'
                                        */
  real_T Gain_Gain_co;                 /* Expression: 3.141592/30
                                        * Referenced by: '<S121>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S121>/Constant'
                                        */
  real_T Out_Throttle_Y0;              /* Computed Parameter: Out_Throttle_Y0
                                        * Referenced by: '<S131>/Out_Throttle'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S162>/Constant'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S162>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.9
                                        * Referenced by: '<S162>/Switch'
                                        */
  real_T Switch1_Threshold_f;          /* Expression: 0
                                        * Referenced by: '<S161>/Switch1'
                                        */
  real_T SKF_act_Y0;                   /* Computed Parameter: SKF_act_Y0
                                        * Referenced by: '<S156>/SKF_act'
                                        */
  real_T Merge_InitialOutput;          /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S156>/Merge'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S156>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: 0.3
                                        * Referenced by: '<S156>/Saturation'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S158>/Constant'
                                        */
  real_T Switch1_Threshold_j;          /* Expression: 0
                                        * Referenced by: '<S158>/Switch1'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 0.9
                                        * Referenced by: '<S158>/Switch'
                                        */
  real_T Switch1_Threshold_h;          /* Expression: 0
                                        * Referenced by: '<S157>/Switch1'
                                        */
  real_T CKF_act_Y0;                   /* Computed Parameter: CKF_act_Y0
                                        * Referenced by: '<S154>/CKF_act '
                                        */
  real_T Merge_InitialOutput_j;        /* Computed Parameter: Merge_InitialOutput_j
                                        * Referenced by: '<S154>/Merge'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 1
                                        * Referenced by: '<S154>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: 0.3
                                        * Referenced by: '<S154>/Saturation'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S115>/Constant1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S115>/Constant2'
                                        */
  real_T Constant_Value_f0;            /* Expression: 0
                                        * Referenced by: '<S115>/Constant'
                                        */
  real_T Constant3_Value_k;            /* Expression: -1
                                        * Referenced by: '<S115>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: -1
                                        * Referenced by: '<S115>/Constant4'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1/9.81
                                        * Referenced by: '<S115>/Gain'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S115>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S115>/Constant6'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S114>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S114>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: -1
                                        * Referenced by: '<S114>/Constant3'
                                        */
  real_T Constant4_Value_p;            /* Expression: -1
                                        * Referenced by: '<S114>/Constant4'
                                        */
  real_T Steering_Ratio_Value;         /* Expression: 3.72
                                        * Referenced by: '<S142>/Steering_Ratio [-]'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S114>/Integrator'
                                        */
  real_T Constant8_Value;              /* Expression: 360
                                        * Referenced by: '<S142>/Constant8'
                                        */
  real_T Constant7_Value;              /* Expression: 0.92
                                        * Referenced by: '<S142>/Constant7'
                                        */
  real_T Wheelbasem_Value;             /* Expression: 1.53
                                        * Referenced by: '<S142>/Wheelbase [m]'
                                        */
  real_T Cornering_Stiffness_FN_Value; /* Expression: -700
                                        * Referenced by: '<S142>/Cornering_Stiffness_F[N//º]'
                                        */
  real_T u602pi_Gain;                  /* Expression: 360/(2*pi)
                                        * Referenced by: '<S142>/360//(2*pi)'
                                        */
  real_T Cornering_Stiffness_RN_Value; /* Expression: -1000
                                        * Referenced by: '<S142>/Cornering_Stiffness_R[N//º]'
                                        */
  real_T u602pi_Gain_g;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S142>/360//(2pi)'
                                        */
  real_T Yaw_Inertiakgm3_Value;        /* Expression: 43.21
                                        * Referenced by: '<S114>/Yaw_Inertia [kg//m^3]'
                                        */
  real_T Rear_Trackwidthm_Value;       /* Expression: 1.15
                                        * Referenced by: '<S114>/Rear_Trackwidth [m] '
                                        */
  real_T Constant_Value_ad;            /* Expression: 2
                                        * Referenced by: '<S144>/Constant'
                                        */
  real_T Gravity_Gain;                 /* Expression: 1/9.81
                                        * Referenced by: '<S114>/Gravity'
                                        */
  real_T Fyperwheel_Gain;              /* Expression: 1/2
                                        * Referenced by: '<S114>/Fy per wheel'
                                        */
  real_T Gravity1_Gain;                /* Expression: 1/9.81
                                        * Referenced by: '<S114>/Gravity1'
                                        */
  real_T Constant6_Value_p;            /* Expression: 1
                                        * Referenced by: '<S114>/Constant6'
                                        */
  real_T MaxTq_RRNm0inf_Y0;            /* Computed Parameter: MaxTq_RRNm0inf_Y0
                                        * Referenced by: '<S78>/MaxTq_RR [Nm] (0,inf)'
                                        */
  real_T MaxTq_RLNm0inf_Y0;            /* Computed Parameter: MaxTq_RLNm0inf_Y0
                                        * Referenced by: '<S78>/MaxTq_RL [Nm] (0,inf)'
                                        */
  real_T Flags_num5_Y0;                /* Computed Parameter: Flags_num5_Y0
                                        * Referenced by: '<S78>/Flags_[num5]'
                                        */
  real_T SteeringWheelMaximumAngle_Value;/* Expression: 100
                                          * Referenced by: '<S153>/Steering Wheel Maximum Angle'
                                          */
  real_T DataStoreMemory_InitialValue_c;/* Expression: 0
                                         * Referenced by: '<S118>/Data Store Memory'
                                         */
  real_T DataStoreMemory1_InitialValue_i;/* Expression: 0
                                          * Referenced by: '<S118>/Data Store Memory1'
                                          */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T TomotorTqRT_Gain;             /* Expression: 1/4
                                        * Referenced by: '<S113>/To motor Tq (RT)'
                                        */
  real_T MaximumTorqueperengineNm_Value;/* Expression: 120
                                         * Referenced by: '<S113>/Maximum Torque per engine [Nm]'
                                         */
  real_T MaximumTransmissionTorqueDynami;/* Expression: 140
                                          * Referenced by: '<S113>/Maximum Transmission Torque Dynamic [Nm]'
                                          */
  real_T MaximumTransmissionTorqueStatic;/* Expression: 130
                                          * Referenced by: '<S113>/Maximum Transmission Torque Static [Nm]'
                                          */
  real_T Constant1_Value_ab;           /* Expression: 0
                                        * Referenced by: '<S120>/Constant1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0.025
                                        * Referenced by: '<S113>/Constant1'
                                        */
  real_T Merge2_InitialOutput;         /* Computed Parameter: Merge2_InitialOutput
                                        * Referenced by: '<S78>/Merge2'
                                        */
  real_T EffectiveRollingDiameterinch_Va;/* Expression: 18
                                          * Referenced by: '<S113>/Effective Rolling Diameter[inch]'
                                          */
  real_T DiametertoRadius_Gain;        /* Expression: 1/2
                                        * Referenced by: '<S113>/Diameter to Radius'
                                        */
  real_T inchtom1_Gain;                /* Expression: 0.0254
                                        * Referenced by: '<S113>/inch to m1'
                                        */
  real_T udifference1_Gain;            /* Expression: 0.97
                                        * Referenced by: '<S113>/3% difference1'
                                        */
  real_T TransmisionRatio_Value;       /* Expression: 4
                                        * Referenced by: '<S113>/Transmision Ratio[-]'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S120>/Constant'
                                        */
  real_T Merge3_InitialOutput;         /* Computed Parameter: Merge3_InitialOutput
                                        * Referenced by: '<S78>/Merge3'
                                        */
  real_T Tq_diff_Max_Value;            /* Expression: 100
                                        * Referenced by: '<S113>/Tq_diff_Max'
                                        */
  real_T Merge_InitialOutput_i;        /* Computed Parameter: Merge_InitialOutput_i
                                        * Referenced by: '<S111>/Merge'
                                        */
  real_T Merge1_InitialOutput;         /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S111>/Merge1'
                                        */
  real_T Merge4_InitialOutput;         /* Computed Parameter: Merge4_InitialOutput
                                        * Referenced by: '<S78>/Merge4'
                                        */
  real_T Merge5_InitialOutput;         /* Computed Parameter: Merge5_InitialOutput
                                        * Referenced by: '<S78>/Merge5'
                                        */
  real_T Merge6_InitialOutput;         /* Computed Parameter: Merge6_InitialOutput
                                        * Referenced by: '<S78>/Merge6'
                                        */
  real_T Merge7_InitialOutput;         /* Computed Parameter: Merge7_InitialOutput
                                        * Referenced by: '<S78>/Merge7'
                                        */
  real_T rpm_Value_k;                  /* Expression: 200
                                        * Referenced by: '<S177>/rpm'
                                        */
  real_T Gain_Gain_cv;                 /* Expression: 3.141592/30
                                        * Referenced by: '<S177>/Gain'
                                        */
  real_T Out_Throttle_Y0_a;            /* Computed Parameter: Out_Throttle_Y0_a
                                        * Referenced by: '<S186>/Out_Throttle'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S203>/Constant'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 0
                                        * Referenced by: '<S203>/Switch1'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0.9
                                        * Referenced by: '<S203>/Switch'
                                        */
  real_T Switch1_Threshold_b;          /* Expression: 0
                                        * Referenced by: '<S202>/Switch1'
                                        */
  real_T MaxTq_RRNm0inf_Y0_o;          /* Computed Parameter: MaxTq_RRNm0inf_Y0_o
                                        * Referenced by: '<S79>/MaxTq_RR [Nm] (0,inf)'
                                        */
  real_T MaxTq_RLNm0inf_Y0_d;          /* Computed Parameter: MaxTq_RLNm0inf_Y0_d
                                        * Referenced by: '<S79>/MaxTq_RL [Nm] (0,inf)'
                                        */
  real_T MaxFx_RRN0inf_Y0;             /* Computed Parameter: MaxFx_RRN0inf_Y0
                                        * Referenced by: '<S79>/MaxFx_RR [N] (0,inf)'
                                        */
  real_T MaxFx_RLN0inf_Y0;             /* Computed Parameter: MaxFx_RLN0inf_Y0
                                        * Referenced by: '<S79>/MaxFx_RL [N] (0,inf)'
                                        */
  real_T Fy_RN0inf_Y0;                 /* Computed Parameter: Fy_RN0inf_Y0
                                        * Referenced by: '<S79>/Fy_R [N] (0,inf)'
                                        */
  real_T Masskg0inf_Y0;                /* Computed Parameter: Masskg0inf_Y0
                                        * Referenced by: '<S79>/Mass [kg] (0,inf)'
                                        */
  real_T Handlinginfinf_Y0;            /* Computed Parameter: Handlinginfinf_Y0
                                        * Referenced by: '<S79>/Handling [-] (-inf,inf)'
                                        */
  real_T Merge_InitialOutput_h;        /* Computed Parameter: Merge_InitialOutput_h
                                        * Referenced by: '<S201>/Merge'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 1
                                        * Referenced by: '<S201>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0.3
                                        * Referenced by: '<S201>/Saturation'
                                        */
  real_T DataStoreMemory1_InitialValue_m;/* Expression: 0
                                          * Referenced by: '<S175>/Data Store Memory1'
                                          */
  real_T TransmisionRatio_Value_j;     /* Expression: 4
                                        * Referenced by: '<S172>/Transmision Ratio[-]'
                                        */
  real_T MaximumTorquepermotorNm_Value;/* Expression: 120
                                        * Referenced by: '<S172>/Maximum Torque per motor [Nm]'
                                        */
  real_T MaximumTransmissionTorqueDyna_a;/* Expression: 140
                                          * Referenced by: '<S172>/Maximum Transmission Torque Dynamic [Nm]'
                                          */
  real_T MaximumTransmissionTorqueStat_n;/* Expression: 130
                                          * Referenced by: '<S172>/Maximum Transmission Torque Static [Nm]'
                                          */
  real_T Constant_Value_ib;            /* Expression: 0
                                        * Referenced by: '<S171>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: -1
                                        * Referenced by: '<S173>/Constant1'
                                        */
  real_T Gravity1_Gain_g;              /* Expression: 1/9.81
                                        * Referenced by: '<S174>/Gravity1'
                                        */
  real_T Fyperwheel_Gain_e;            /* Expression: 1/2
                                        * Referenced by: '<S174>/Fy per wheel'
                                        */
  real_T EffectiveRollingDiameterinch__b;/* Expression: 18
                                          * Referenced by: '<S172>/Effective Rolling Diameter[inch]'
                                          */
  real_T DiametertoRadius_Gain_h;      /* Expression: 1/2
                                        * Referenced by: '<S172>/Diameter to Radius'
                                        */
  real_T inchtom_Gain;                 /* Expression: 0.0254
                                        * Referenced by: '<S172>/inch to m'
                                        */
  real_T udifference_Gain;             /* Expression: 0.97
                                        * Referenced by: '<S172>/3% difference'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S171>/Constant1'
                                        */
  real_T Constant_Value_ae;            /* Expression: -1
                                        * Referenced by: '<S173>/Constant'
                                        */
  real_T Merge_InitialOutput_l;        /* Computed Parameter: Merge_InitialOutput_l
                                        * Referenced by: '<S170>/Merge'
                                        */
  real_T Merge1_InitialOutput_k;       /* Computed Parameter: Merge1_InitialOutput_k
                                        * Referenced by: '<S170>/Merge1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: -1
                                        * Referenced by: '<S94>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S94>/Gain1'
                                        */
  real_T Constant_Value_n5;            /* Expression: 1
                                        * Referenced by: '<S107>/Constant'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S107>/Switch1'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0.9
                                        * Referenced by: '<S107>/Switch'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S106>/Switch'
                                        */
  real_T SKF_act_Y0_l;                 /* Computed Parameter: SKF_act_Y0_l
                                        * Referenced by: '<S101>/SKF_act'
                                        */
  real_T Merge_InitialOutput_p;        /* Computed Parameter: Merge_InitialOutput_p
                                        * Referenced by: '<S101>/Merge'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 1
                                        * Referenced by: '<S101>/Saturation'
                                        */
  real_T Saturation_LowerSat_f3;       /* Expression: 0.3
                                        * Referenced by: '<S101>/Saturation'
                                        */
  real_T Constant_Value_dl;            /* Expression: 1
                                        * Referenced by: '<S103>/Constant'
                                        */
  real_T Switch1_Threshold_p;          /* Expression: 0
                                        * Referenced by: '<S103>/Switch1'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0.9
                                        * Referenced by: '<S103>/Switch'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 0
                                        * Referenced by: '<S102>/Switch'
                                        */
  real_T CKF_act_Y0_j;                 /* Computed Parameter: CKF_act_Y0_j
                                        * Referenced by: '<S99>/CKF_act '
                                        */
  real_T Merge_InitialOutput_a;        /* Computed Parameter: Merge_InitialOutput_a
                                        * Referenced by: '<S99>/Merge'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 1
                                        * Referenced by: '<S99>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: 0.3
                                        * Referenced by: '<S99>/Saturation'
                                        */
  real_T SteeringWheelMaximumAngle_Val_o;/* Expression: 100
                                          * Referenced by: '<S98>/Steering Wheel Maximum Angle'
                                          */
  real_T DataStoreMemory_InitialValue_m;/* Expression: 0
                                         * Referenced by: '<S88>/Data Store Memory'
                                         */
  real_T DataStoreMemory1_InitialValue_f;/* Expression: 0
                                          * Referenced by: '<S88>/Data Store Memory1'
                                          */
  real_T SteeringWheelMaximumAngle_Val_i;/* Expression: 140
                                          * Referenced by: '<S77>/Steering Wheel Maximum Angle'
                                          */
  real_T Tq_max_motorNm_Value;         /* Expression: 120
                                        * Referenced by: '<S77>/Tq_max_motor [Nm]'
                                        */
  real_T Tq_diff_maxNm_Value;          /* Expression: 100
                                        * Referenced by: '<S77>/Tq_diff_max [Nm]'
                                        */
  real_T TransmissionRatio_Gain;       /* Expression: 4
                                        * Referenced by: '<S77>/Transmission Ratio'
                                        */
  real_T TransmissionRatio1_Gain;      /* Expression: 4
                                        * Referenced by: '<S77>/Transmission Ratio1'
                                        */
  real_T Merge_InitialOutput_e;        /* Computed Parameter: Merge_InitialOutput_e
                                        * Referenced by: '<S82>/Merge'
                                        */
  real_T Merge1_InitialOutput_e;       /* Computed Parameter: Merge1_InitialOutput_e
                                        * Referenced by: '<S82>/Merge1'
                                        */
  real_T Torque_RLNm_Value;            /* Expression: 60
                                        * Referenced by: '<S76>/Torque_RL [Nm]'
                                        */
  real_T RT_L_Gain;                    /* Expression: 4
                                        * Referenced by: '<S76>/RT_L'
                                        */
  real_T Torque_RRNm_Value;            /* Expression: 60
                                        * Referenced by: '<S76>/Torque_RR [Nm]'
                                        */
  real_T RT_R_Gain;                    /* Expression: 4
                                        * Referenced by: '<S76>/RT_R'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S74>/Out1'
                                        */
  real_T Constant_Value_k;             /* Expression: 5
                                        * Referenced by: '<S67>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S67>/Gain'
                                        */
  real_T SteeringWheelSaturationpersited;/* Expression: 10
                                          * Referenced by: '<S67>/Steering Wheel Saturation (per site) [deg] '
                                          */
  real_T MergeTq_RL_InitialOutput;     /* Computed Parameter: MergeTq_RL_InitialOutput
                                        * Referenced by: '<S67>/Merge Tq_RL'
                                        */
  real_T MergeTq_RR_InitialOutput;     /* Computed Parameter: MergeTq_RR_InitialOutput
                                        * Referenced by: '<S67>/Merge Tq_RR'
                                        */
  real_T Merge2_InitialOutput_o;       /* Computed Parameter: Merge2_InitialOutput_o
                                        * Referenced by: '<S67>/Merge2'
                                        */
  real_T Merge3_InitialOutput_n;       /* Computed Parameter: Merge3_InitialOutput_n
                                        * Referenced by: '<S67>/Merge3'
                                        */
  real_T Constant_Value_m;             /* Expression: 2
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T Enabled_Value;                /* Expression: 1
                                        * Referenced by: '<S65>/Enabled'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S65>/Zero '
                                        */
  real_T Constant_Value_k4;            /* Expression: 800
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T Constant1_Value_ln;           /* Expression: 800
                                        * Referenced by: '<S72>/Constant1'
                                        */
  real_T Constant2_Value_g1;           /* Expression: 800
                                        * Referenced by: '<S72>/Constant2'
                                        */
  real_T Constant3_Value_n;            /* Expression: 800
                                        * Referenced by: '<S72>/Constant3'
                                        */
  real_T Constant_Value_dm;            /* Expression: 15
                                        * Referenced by: '<S207>/Constant'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 10
                                        * Referenced by: '<S207>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -10
                                        * Referenced by: '<S207>/Saturation'
                                        */
  real_T Saturation1_UpperSat_k;       /* Expression: 10
                                        * Referenced by: '<S207>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_k;       /* Expression: -10
                                        * Referenced by: '<S207>/Saturation1'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 580
                                        * Referenced by: '<S68>/Saturation'
                                        */
  real_T Saturation_LowerSat_fi;       /* Expression: -580
                                        * Referenced by: '<S68>/Saturation'
                                        */
  real_T Saturation1_UpperSat_m;       /* Expression: 580
                                        * Referenced by: '<S68>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_lw;      /* Expression: -580
                                        * Referenced by: '<S68>/Saturation1'
                                        */
  real_T Constant14_Value;             /* Expression: 3
                                        * Referenced by: '<Root>/Constant14'
                                        */
  real_T zero_Value;                   /* Expression: 570
                                        * Referenced by: '<S13>/zero'
                                        */
  real_T halfrange_Value;              /* Expression: 2
                                        * Referenced by: '<S13>/half range'
                                        */
  real_T range_Value;                  /* Expression: 1000
                                        * Referenced by: '<S13>/range'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 115
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T TransmissionGearRatio_Gain;   /* Expression: 4
                                        * Referenced by: '<Root>/Transmission Gear Ratio'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 100
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 1/4
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 1/4
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain6_Gain_f;                 /* Expression: 1/100
                                        * Referenced by: '<S208>/Gain6'
                                        */
  real_T Lookup_SoC_SoP_dischg_tableDa_g[8];/* Expression: [0.4 0.6 0.8 0.95 1 1 0.98 0.95]
                                             * Referenced by: '<S208>/Lookup_SoC_SoP_dischg'
                                             */
  real_T Lookup_SoC_SoP_dischg_bp01Dat_m[8];/* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.9 1]
                                             * Referenced by: '<S208>/Lookup_SoC_SoP_dischg'
                                             */
  real_T Constant1_Value_e;            /* Expression: 45
                                        * Referenced by: '<S213>/Constant1'
                                        */
  real_T Constant2_Value_mw;           /* Expression: 5
                                        * Referenced by: '<S213>/Constant2'
                                        */
  real_T initial_limitation_Value_k;   /* Expression: 0.4
                                        * Referenced by: '<S16>/initial_limitation'
                                        */
  real_T Constant3_Value_h;            /* Expression: 1
                                        * Referenced by: '<S213>/Constant3'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 1
                                        * Referenced by: '<S213>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_m;       /* Expression: 0
                                        * Referenced by: '<S213>/Saturation1'
                                        */
  real_T Constant1_Value_fp;           /* Expression: 45
                                        * Referenced by: '<S214>/Constant1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 5
                                        * Referenced by: '<S214>/Constant2'
                                        */
  real_T Constant3_Value_c;            /* Expression: 1
                                        * Referenced by: '<S214>/Constant3'
                                        */
  real_T Saturation1_UpperSat_i;       /* Expression: 1
                                        * Referenced by: '<S214>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_ko;      /* Expression: 0
                                        * Referenced by: '<S214>/Saturation1'
                                        */
  real_T Constant1_Value_p2;           /* Expression: 105
                                        * Referenced by: '<S215>/Constant1'
                                        */
  real_T Constant2_Value_hv;           /* Expression: 5
                                        * Referenced by: '<S215>/Constant2'
                                        */
  real_T Constant3_Value_i;            /* Expression: 1
                                        * Referenced by: '<S215>/Constant3'
                                        */
  real_T Saturation1_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S215>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: 0
                                        * Referenced by: '<S215>/Saturation1'
                                        */
  real_T Saturation_UpperSat_fg;       /* Expression: 1
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_ey;       /* Expression: 0
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Gain5_Gain_n;                 /* Expression: 1/100
                                        * Referenced by: '<S208>/Gain5'
                                        */
  real_T Lookup_SoC_SoP_chg_tableData_p[8];/* Expression: [0.95 1 1 1 1 0.9 0.75 0.02]
                                            * Referenced by: '<S208>/Lookup_SoC_SoP_chg'
                                            */
  real_T Lookup_SoC_SoP_chg_bp01Data_b[8];/* Expression: [0.02 0.1 0.2 0.3 0.5 0.8 0.95 1]
                                           * Referenced by: '<S208>/Lookup_SoC_SoP_chg'
                                           */
  real_T Lookup_Temp_SoP_chg_tableData_m[5];/* Expression: [1 0.75 0.5 0 0]
                                             * Referenced by: '<S208>/Lookup_Temp_SoP_chg'
                                             */
  real_T Lookup_Temp_SoP_chg_bp01Data_i[5];/* Expression: [45 48 49 50 51]
                                            * Referenced by: '<S208>/Lookup_Temp_SoP_chg'
                                            */
  real_T Saturation1_UpperSat_is;      /* Expression: 1
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_j;       /* Expression: 0
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T GearRatio_Value;              /* Expression: 4
                                        * Referenced by: '<Root>/Gear Ratio'
                                        */
  real_T MaxTqpermotorNm_Value;        /* Expression: 120
                                        * Referenced by: '<Root>/Max Tq per motor [Nm]'
                                        */
  real_T Max_Power_dischargekW_Value;  /* Expression: 80
                                        * Referenced by: '<S9>/Max_Power_discharge [kW]'
                                        */
  real_T Max_Power_chargekW_Value;     /* Expression: 60
                                        * Referenced by: '<S9>/Max_Power_charge [kW]'
                                        */
  boolean_T Accu_Temperature_Limitation_Fla;/* Computed Parameter: Accu_Temperature_Limitation_Fla
                                             * Referenced by: '<S3>/Accu_Temperature_Limitation_Flag'
                                             */
  boolean_T Inverters_Temperature_Limitatio;/* Computed Parameter: Inverters_Temperature_Limitatio
                                             * Referenced by: '<S3>/Inverters_Temperature_Limitation_Flag'
                                             */
  boolean_T Motors_Temperature_Limitation_F;/* Computed Parameter: Motors_Temperature_Limitation_F
                                             * Referenced by: '<S3>/Motors_Temperature_Limitation_Flag'
                                             */
  boolean_T DataStoreMemory1_InitialValu_fl;/* Computed Parameter: DataStoreMemory1_InitialValu_fl
                                             * Referenced by: '<S43>/Data Store Memory1'
                                             */
  P_Mech_Braking_Torque_Control_T InertiaBraking_e;/* '<S82>/Inertia Braking' */
  P_Mech_Braking_Torque_Control_T Mech_Braking_l;/* '<S82>/Mech_Braking' */
  P_Mech_Braking_Torque_Control_T InertiaBraking_b;/* '<S170>/Inertia Braking' */
  P_Mech_Braking_Torque_Control_T Mech_Braking_h;/* '<S170>/Mech_Braking' */
  P_BrakingwithRegenerative_Tor_T BrakingwithRegenerative_b;/* '<S169>/Braking with Regenerative' */
  P_Mech_Braking_Torque_Control_T InertiaBraking;/* '<S111>/Inertia Braking' */
  P_Mech_Braking_Torque_Control_T Mech_Braking;/* '<S111>/Mech_Braking' */
  P_BrakingwithRegenerative_Tor_T BrakingwithRegenerative;/* '<S110>/Braking with Regenerative' */
  P_Imp_Torque_Control_T NotImpMemo1;  /* '<S43>/Not Imp Memo1' */
  P_Imp_Torque_Control_T ImpMemo1;     /* '<S43>/Imp Memo1' */
  P_IfActionSubsystem2_Torque_C_T IfActionSubsystem3;/* '<S43>/If Action Subsystem3' */
  P_IfActionSubsystem2_Torque_C_T IfActionSubsystem2;/* '<S43>/If Action Subsystem2' */
  P_Imp_Torque_Control_T NotImp1;      /* '<S43>/Not Imp1' */
  P_Imp_Torque_Control_T Imp1;         /* '<S43>/Imp1' */
  P_Imp_Torque_Control_T NotImp;       /* '<S42>/Not Imp' */
  P_Imp_Torque_Control_T Imp;          /* '<S42>/Imp' */
  P_LimitReached_Torque_Control_T OK;  /* '<S19>/OK' */
  P_LimitReached_Torque_Control_T LatchedError;/* '<S19>/Latched Error' */
  P_LimitReached_Torque_Control_T LimitReached;/* '<S17>/LimitReached' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Torque_Control_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Torque_Control_T Torque_Control_P;

/* Block signals (auto storage) */
extern B_Torque_Control_T Torque_Control_B;

/* Continuous states (auto storage) */
extern X_Torque_Control_T Torque_Control_X;

/* Block states (auto storage) */
extern DW_Torque_Control_T Torque_Control_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Torque_Control_T Torque_Control_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Torque_Control_T Torque_Control_Y;

/* Model entry point functions */
extern void Torque_Control_initialize(void);
extern void Torque_Control_output(void);
extern void Torque_Control_update(void);
extern void Torque_Control_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Torque_Control_rtModel *Torque_Control(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Torque_Control_T *const Torque_Control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Torque_Control'
 * '<S1>'   : 'Torque_Control/Accumulator Power'
 * '<S2>'   : 'Torque_Control/Calculate Current Conversion'
 * '<S3>'   : 'Torque_Control/Controls Temperature by limiting Torque'
 * '<S4>'   : 'Torque_Control/Current 0'
 * '<S5>'   : 'Torque_Control/Flag_Temp merged'
 * '<S6>'   : 'Torque_Control/If Action Subsystem'
 * '<S7>'   : 'Torque_Control/MATLAB Function'
 * '<S8>'   : 'Torque_Control/MATLAB Function1'
 * '<S9>'   : 'Torque_Control/Power limitation'
 * '<S10>'  : 'Torque_Control/Pumps_Controller'
 * '<S11>'  : 'Torque_Control/SAFETY BLOCK'
 * '<S12>'  : 'Torque_Control/SoP selection and sum of max WHEEL Tq available'
 * '<S13>'  : 'Torque_Control/Steering Data Conv'
 * '<S14>'  : 'Torque_Control/VDC'
 * '<S15>'  : 'Torque_Control/W to kW'
 * '<S16>'  : 'Torque_Control/power_limitation'
 * '<S17>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection'
 * '<S18>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/LimitReached'
 * '<S19>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch'
 * '<S20>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch/Latched Error'
 * '<S21>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch/OK'
 * '<S22>'  : 'Torque_Control/Calculate Current Conversion/KT_L_TORKY'
 * '<S23>'  : 'Torque_Control/Calculate Current Conversion/KT_R_EMY'
 * '<S24>'  : 'Torque_Control/Controls Temperature by limiting Torque/SoC_SoP'
 * '<S25>'  : 'Torque_Control/Controls Temperature by limiting Torque/Tq_limitation because of Temp'
 * '<S26>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP'
 * '<S27>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/Flag_Accu'
 * '<S28>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/Flag_Inv'
 * '<S29>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/Flag_Mot'
 * '<S30>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu'
 * '<S31>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters'
 * '<S32>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors'
 * '<S33>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Temp higher than 50'
 * '<S34>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Temp higher than 50'
 * '<S35>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Temp higher than 110'
 * '<S36>'  : 'Torque_Control/Power limitation/MATLAB Function'
 * '<S37>'  : 'Torque_Control/Pumps_Controller/Compare To Constant'
 * '<S38>'  : 'Torque_Control/Pumps_Controller/Compare To Constant1'
 * '<S39>'  : 'Torque_Control/Pumps_Controller/DocBlock1'
 * '<S40>'  : 'Torque_Control/Pumps_Controller/Pumps_Control_OFF'
 * '<S41>'  : 'Torque_Control/Pumps_Controller/Pumps_Control_ON'
 * '<S42>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY'
 * '<S43>'  : 'Torque_Control/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY'
 * '<S44>'  : 'Torque_Control/SAFETY BLOCK/Compare To Constant'
 * '<S45>'  : 'Torque_Control/SAFETY BLOCK/Power is under 80kW '
 * '<S46>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Imp'
 * '<S47>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Not Imp'
 * '<S48>'  : 'Torque_Control/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/If Action Subsystem2'
 * '<S49>'  : 'Torque_Control/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/If Action Subsystem3'
 * '<S50>'  : 'Torque_Control/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/Imp Memo1'
 * '<S51>'  : 'Torque_Control/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/Imp1'
 * '<S52>'  : 'Torque_Control/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/Not Imp Memo1'
 * '<S53>'  : 'Torque_Control/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/Not Imp1'
 * '<S54>'  : 'Torque_Control/Steering Data Conv/Low Pass'
 * '<S55>'  : 'Torque_Control/VDC/DocBlock'
 * '<S56>'  : 'Torque_Control/VDC/DocBlock1'
 * '<S57>'  : 'Torque_Control/VDC/DocBlock10'
 * '<S58>'  : 'Torque_Control/VDC/DocBlock2'
 * '<S59>'  : 'Torque_Control/VDC/DocBlock3'
 * '<S60>'  : 'Torque_Control/VDC/DocBlock4'
 * '<S61>'  : 'Torque_Control/VDC/DocBlock5'
 * '<S62>'  : 'Torque_Control/VDC/DocBlock6'
 * '<S63>'  : 'Torque_Control/VDC/DocBlock8'
 * '<S64>'  : 'Torque_Control/VDC/DocBlock9'
 * '<S65>'  : 'Torque_Control/VDC/Regeneration_Enable'
 * '<S66>'  : 'Torque_Control/VDC/TEST_MODE_IN'
 * '<S67>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes'
 * '<S68>'  : 'Torque_Control/VDC/WORKSHOP_MODE_RESTRICTIONS'
 * '<S69>'  : 'Torque_Control/VDC/Regeneration_Enable/Enabled '
 * '<S70>'  : 'Torque_Control/VDC/Regeneration_Enable/NotEnabled'
 * '<S71>'  : 'Torque_Control/VDC/TEST_MODE_IN/BYPASS'
 * '<S72>'  : 'Torque_Control/VDC/TEST_MODE_IN/TEST_CONSTANTS'
 * '<S73>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Automatic Failure Mode'
 * '<S74>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/If Action Subsystem'
 * '<S75>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Manual Failure Mode Selection'
 * '<S76>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Rigid Axle'
 * '<S77>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC'
 * '<S78>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete'
 * '<S79>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal'
 * '<S80>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Rigid Axle/Accelerating'
 * '<S81>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Rigid Axle/Accelerating/Accelerator behaviour '
 * '<S82>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking'
 * '<S83>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Inertia or Braking without Regen'
 * '<S84>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerator behaviour'
 * '<S85>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Lateral Dynamics'
 * '<S86>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Longitudinal Dynamics'
 * '<S87>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/MATLAB Function1'
 * '<S88>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF'
 * '<S89>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Regenerating'
 * '<S90>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Steering TV 2017 (without TC)'
 * '<S91>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Accelerating'
 * '<S92>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Inertia Braking'
 * '<S93>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Mech_Braking'
 * '<S94>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking'
 * '<S95>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking/MATLAB Function'
 * '<S96>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking/MATLAB Function1'
 * '<S97>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/MATLAB Function'
 * '<S98>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  '
 * '<S99>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S100>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /MATLAB Function1'
 * '<S101>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF'
 * '<S102>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S103>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S104>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S105>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S106>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/No spin'
 * '<S107>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/Spin'
 * '<S108>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/No spin/MATLAB Function'
 * '<S109>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/Spin/MATLAB Function'
 * '<S110>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq'
 * '<S111>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours'
 * '<S112>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Flags'
 * '<S113>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/In_Numbers'
 * '<S114>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics'
 * '<S115>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics'
 * '<S116>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/MATLAB Function1'
 * '<S117>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/MATLAB Function2'
 * '<S118>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF'
 * '<S119>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Sensor_DATA'
 * '<S120>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor'
 * '<S121>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative'
 * '<S122>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Braking with Regenerative'
 * '<S123>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/If Action 1'
 * '<S124>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/If Action 2'
 * '<S125>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/MATLAB Function'
 * '<S126>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/Momentum Z scaled'
 * '<S127>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/minimum value'
 * '<S128>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/minimum value1'
 * '<S129>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/Momentum Z scaled/MATLAB Function'
 * '<S130>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Braking with Regenerative/MATLAB Function'
 * '<S131>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Accelerating'
 * '<S132>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Accelerator behaviour '
 * '<S133>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Inertia Braking'
 * '<S134>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Mech_Braking'
 * '<S135>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Regenerative+Mech Braking'
 * '<S136>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Regenerative+Mech Braking/MATLAB Function'
 * '<S137>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Force Difference with  Max. Tire Forces'
 * '<S138>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Kamm_Circle'
 * '<S139>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/MATLAB Function1'
 * '<S140>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/MATLAB Function2'
 * '<S141>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference'
 * '<S142>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Yaw_Rate_Reference'
 * '<S143>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Kamm_Circle/Kamm_Circle LatD'
 * '<S144>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference/ Momentum_Z to Longitudinal Force Difference'
 * '<S145>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference/Momentum respect to Z-axis to correct the error'
 * '<S146>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Yaw_Rate_Reference/Bicycle Model'
 * '<S147>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/Kamm_Circle'
 * '<S148>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/MATLAB Function'
 * '<S149>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/MATLAB Function1'
 * '<S150>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/minimum value'
 * '<S151>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/Kamm_Circle/Kamm_Circle LatD'
 * '<S152>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/MATLAB Function'
 * '<S153>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  '
 * '<S154>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S155>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /MATLAB Function1'
 * '<S156>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF'
 * '<S157>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S158>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S159>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function1'
 * '<S160>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S161>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/No spin'
 * '<S162>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/Spin'
 * '<S163>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/No spin/MATLAB Function'
 * '<S164>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/Spin/MATLAB Function'
 * '<S165>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/Fx_to_engineTqRL'
 * '<S166>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/Fx_to_engineTqRR'
 * '<S167>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/MATLAB Function1'
 * '<S168>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/MATLAB Function2'
 * '<S169>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints'
 * '<S170>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours'
 * '<S171>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq'
 * '<S172>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/In_Numbers'
 * '<S173>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral'
 * '<S174>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Lateral Dynamics'
 * '<S175>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF'
 * '<S176>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Sensor_DATA'
 * '<S177>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative'
 * '<S178>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Braking with Regenerative'
 * '<S179>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/If Action 1'
 * '<S180>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/If Action 2'
 * '<S181>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled'
 * '<S182>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/minimum value'
 * '<S183>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/minimum value1'
 * '<S184>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled/MATLAB Function'
 * '<S185>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Braking with Regenerative/MATLAB Function'
 * '<S186>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Accelerating'
 * '<S187>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Inertia Braking'
 * '<S188>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Mech_Braking'
 * '<S189>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Regenerative+Mech Braking'
 * '<S190>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Accelerating/Accelerator behaviour '
 * '<S191>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Regenerative+Mech Braking/MATLAB Function'
 * '<S192>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/Fx_to_wheelTqRL'
 * '<S193>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/Fx_to_wheelTqRR'
 * '<S194>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/MATLAB Function1'
 * '<S195>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/MATLAB Function2'
 * '<S196>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/Kamm_Circle LatD'
 * '<S197>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/MATLAB Function1'
 * '<S198>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/MATLAB Function2'
 * '<S199>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/MATLAB Function'
 * '<S200>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  '
 * '<S201>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S202>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S203>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S204>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S205>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S206>' : 'Torque_Control/VDC/WORKSHOP_MODE_RESTRICTIONS/BYPASS'
 * '<S207>' : 'Torque_Control/VDC/WORKSHOP_MODE_RESTRICTIONS/Torque_Reduction '
 * '<S208>' : 'Torque_Control/power_limitation/SoC_SoP'
 * '<S209>' : 'Torque_Control/power_limitation/temperature_SoP'
 * '<S210>' : 'Torque_Control/power_limitation/temperature_SoP/Flag_Accu'
 * '<S211>' : 'Torque_Control/power_limitation/temperature_SoP/Flag_Inv'
 * '<S212>' : 'Torque_Control/power_limitation/temperature_SoP/Flag_Mot'
 * '<S213>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu'
 * '<S214>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters'
 * '<S215>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors'
 * '<S216>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Temp higher than 50'
 * '<S217>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Temp higher than 50'
 * '<S218>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Temp higher than 110'
 */
#endif                                 /* RTW_HEADER_Torque_Control_h_ */
