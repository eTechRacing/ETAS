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
 * Model version              : 10.24
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Tue Mar 26 15:45:11 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torque_Control_h_
#define RTW_HEADER_Torque_Control_h_
#ifndef Torque_Control_COMMON_INCLUDES_
#define Torque_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* Torque_Control_COMMON_INCLUDES_ */

#include "Torque_Control_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include <string.h>
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ()
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ()
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ()
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ()
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ()
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ()
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Torque_Control_rtModel         RT_MODEL_Torque_Control_T

/* Block signals for system '<S101>/Accelerator behaviour ' */
typedef struct {
  real_T throttle;                     /* '<S101>/Accelerator behaviour ' */
} B_Acceleratorbehaviour_Torque_T;

/* Block signals for system '<S70>/MATLAB Function1' */
typedef struct {
  real_T value;                        /* '<S70>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Cont_T;

/* Block signals for system '<S108>/MATLAB Function' */
typedef struct {
  real_T w;                            /* '<S108>/MATLAB Function' */
} B_MATLABFunction_Torque_Contr_T;

/* Block signals for system '<S151>/MATLAB Function' */
typedef struct {
  real_T SKF_act0;                     /* '<S151>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_f_T;

/* Block signals for system '<S148>/MATLAB Function' */
typedef struct {
  real_T CKF_act1;                     /* '<S148>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_h_T;

/* Block signals for system '<S147>/MATLAB Function1' */
typedef struct {
  real_T CKF_act0;                     /* '<S147>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Co_o_T;

/* Block signals for system '<S105>/MATLAB Function' */
typedef struct {
  real_T value;                        /* '<S105>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_j_T;

/* Block signals for system '<S110>/MATLAB Function1' */
typedef struct {
  real_T value;                        /* '<S110>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Co_n_T;

/* Block signals (default storage) */
typedef struct {
  real_T kamm_data[544];
  real_T Abs3;                         /* '<Root>/Abs3' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Merge3;                       /* '<Root>/Merge3' */
  real_T Merge;                        /* '<Root>/Merge' */
  real_T Merge_m;                      /* '<S10>/Merge' */
  real_T Merge1;                       /* '<S10>/Merge1' */
  real_T Merge2;                       /* '<S10>/Merge2' */
  real_T Merge3_o;                     /* '<S10>/Merge3' */
  real_T Merge1_a;                     /* '<S8>/Merge1' */
  real_T Merge_a;                      /* '<S11>/Merge' */
  real_T MergeTq_RL;                   /* '<S11>/Merge Tq_RL' */
  real_T MergeTq_RR;                   /* '<S11>/Merge Tq_RR' */
  real_T Merge2_b;                     /* '<S11>/Merge2' */
  real_T Merge3_i;                     /* '<S11>/Merge3' */
  real_T wrads;                        /* '<S79>/Max' */
  real_T Saturation;                   /* '<S79>/Saturation' */
  real_T Switch;                       /* '<S79>/Switch' */
  real_T Merge_j;                      /* '<S89>/Merge' */
  real_T Saturation_n;                 /* '<S89>/Saturation' */
  real_T Switch1;                      /* '<S93>/Switch1' */
  real_T Merge_d;                      /* '<S91>/Merge' */
  real_T Saturation_j;                 /* '<S91>/Saturation' */
  real_T Merge_n;                      /* '<S191>/Merge' */
  real_T Merge_ag;                     /* '<S160>/Merge' */
  real_T Merge1_c;                     /* '<S160>/Merge1' */
  real_T Merge2_d;                     /* '<S167>/Merge2' */
  real_T Saturation_p;                 /* '<S108>/Saturation' */
  real_T Switch_m;                     /* '<S108>/Switch' */
  real_T Merge2_i;                     /* '<S70>/Merge2' */
  real_T Divide;                       /* '<S156>/Divide' */
  real_T Merge3_d;                     /* '<S70>/Merge3' */
  real_T Divide_g;                     /* '<S155>/Divide' */
  real_T Merge_dw;                     /* '<S101>/Merge' */
  real_T Merge1_j;                     /* '<S101>/Merge1' */
  real_T Merge_l;                      /* '<S70>/Merge' */
  real_T Merge1_e;                     /* '<S70>/Merge1' */
  real_T Merge4;                       /* '<S70>/Merge4' */
  real_T Merge5;                       /* '<S70>/Merge5' */
  real_T Merge6;                       /* '<S70>/Merge6' */
  real_T Merge7;                       /* '<S70>/Merge7' */
  real_T OutportBufferForFlags_num5[4];/* '<S70>/Flags' */
  real_T Sum3;                         /* '<S104>/Sum3' */
  real_T Divide_f;                     /* '<S135>/Divide' */
  real_T Gain1_h;                      /* '<S132>/Gain1' */
  real_T Gain4;                        /* '<S132>/Gain4' */
  real_T Gain3;                        /* '<S132>/Gain3' */
  real_T Gain2;                        /* '<S132>/Gain2' */
  real_T Gain_a;                       /* '<S132>/Gain' */
  real_T radius;                       /* '<S132>/Bicycle Model' */
  real_T yf;                           /* '<S132>/Bicycle Model' */
  real_T yr;                           /* '<S132>/Bicycle Model' */
  real_T Merge_az;                     /* '<S144>/Merge' */
  real_T Saturation_h;                 /* '<S144>/Saturation' */
  real_T Merge_agp;                    /* '<S146>/Merge' */
  real_T Saturation_hh;                /* '<S146>/Saturation' */
  real_T Throttle;                     /* '<S121>/Throttle' */
  real_T Merge2_m;                     /* '<S111>/Merge2' */
  real_T OutportBufferForFlag_Power;   /* '<S111>/Constant' */
  real_T Probe[2];                     /* '<S31>/Probe' */
  real_T Probe_o[2];                   /* '<S39>/Probe' */
  real_T Probe_n[2];                   /* '<S47>/Probe' */
  real_T uT;                           /* '<S29>/1//T' */
  real_T uT_i;                         /* '<S37>/1//T' */
  real_T uT_m;                         /* '<S45>/1//T' */
  real_T Braking;                      /* '<Root>/BrakePedal_Pressed' */
  real_T Merge_jz;                     /* '<S56>/Merge' */
  real_T Merge1_a0;                    /* '<Root>/Merge1' */
  real_T Merge2_e;                     /* '<Root>/Merge2' */
  boolean_T LogicalOperator1;          /* '<S9>/Logical Operator1' */
  boolean_T Compare;                   /* '<S34>/Compare' */
  boolean_T Compare_n;                 /* '<S42>/Compare' */
  boolean_T Compare_e;                 /* '<S50>/Compare' */
  boolean_T Compare_f;                 /* '<S23>/Compare' */
  boolean_T Compare_d;                 /* '<S24>/Compare' */
  boolean_T Compare_g;                 /* '<S25>/Compare' */
  B_MATLABFunction1_Torque_Co_o_T sf_MATLABFunction_m0;/* '<S92>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_f_T sf_MATLABFunction_i;/* '<S96>/MATLAB Function' */
  B_MATLABFunction1_Torque_Co_o_T sf_MATLABFunction_gw;/* '<S192>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction_o;/* '<S193>/MATLAB Function' */
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction_hu;/* '<S165>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_j_T sf_MATLABFunction2_a;/* '<S163>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_j_T sf_MATLABFunction1_a;/* '<S163>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_j_T sf_MATLABFunction2_o;/* '<S161>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_j_T sf_MATLABFunction1_g;/* '<S161>/MATLAB Function1' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_i;/* '<S176>/Accelerator behaviour ' */
  B_MATLABFunction1_Torque_Co_n_T sf_MATLABFunction2_m;/* '<S110>/MATLAB Function2' */
  B_MATLABFunction1_Torque_Co_n_T sf_MATLABFunction1_p;/* '<S110>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_j_T sf_MATLABFunction2_mv;/* '<S104>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_j_T sf_MATLABFunction1_c;/* '<S104>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_j_T sf_MATLABFunction1_d;/* '<S105>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_j_T sf_MATLABFunction_f;/* '<S105>/MATLAB Function' */
  B_MATLABFunction1_Torque_Co_o_T sf_MATLABFunction1_n;/* '<S147>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction_l;/* '<S148>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_f_T sf_MATLABFunction_hg;/* '<S151>/MATLAB Function' */
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction_h;/* '<S108>/MATLAB Function' */
  B_MATLABFunction1_Torque_Cont_T sf_MATLABFunction2;/* '<S70>/MATLAB Function2' */
  B_MATLABFunction1_Torque_Cont_T sf_MATLABFunction1;/* '<S70>/MATLAB Function1' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour;/* '<S101>/Accelerator behaviour ' */
} B_Torque_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S36>/Integrator' */
  real_T Integrator_DSTATE_b;          /* '<S44>/Integrator' */
  real_T Integrator_DSTATE_j;          /* '<S52>/Integrator' */
  real_T ERROR_Counter;                /* '<S56>/Data Store Memory1' */
  real_T TimeStampA;                   /* '<S79>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S79>/Derivative' */
  real_T TimeStampB;                   /* '<S79>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S79>/Derivative' */
  real_T A;                            /* '<S79>/Data Store Memory' */
  real_T B;                            /* '<S79>/Data Store Memory1' */
  real_T TimeStampA_p;                 /* '<S165>/Derivative' */
  real_T LastUAtTimeA_o;               /* '<S165>/Derivative' */
  real_T TimeStampB_n;                 /* '<S165>/Derivative' */
  real_T LastUAtTimeB_m;               /* '<S165>/Derivative' */
  real_T B_c;                          /* '<S165>/Data Store Memory1' */
  real_T TimeStampA_d;                 /* '<S108>/Derivative' */
  real_T LastUAtTimeA_n;               /* '<S108>/Derivative' */
  real_T TimeStampB_c;                 /* '<S108>/Derivative' */
  real_T LastUAtTimeB_b;               /* '<S108>/Derivative' */
  real_T A_k;                          /* '<S108>/Data Store Memory' */
  real_T B_p;                          /* '<S108>/Data Store Memory1' */
  real_T A_i;                          /* '<S12>/Data Store Memory10' */
  int8_T If_ActiveSubsystem;           /* '<S56>/If' */
  int8_T If1_ActiveSubsystem;          /* '<S56>/If1' */
  int8_T If2_ActiveSubsystem;          /* '<Root>/If2' */
  int8_T If_ActiveSubsystem_e;         /* '<Root>/If' */
  int8_T If1_ActiveSubsystem_a;        /* '<Root>/If1' */
  int8_T If_ActiveSubsystem_m;         /* '<S10>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S8>/If' */
  int8_T FAILUREMODE_ActiveSubsystem;  /* '<S11>/FAILURE MODE' */
  int8_T SKForCKF_ActiveSubsystem;     /* '<S88>/SKF or CKF' */
  int8_T If1_ActiveSubsystem_g;        /* '<S69>/If1' */
  int8_T If_ActiveSubsystem_b;         /* '<S69>/If' */
  int8_T BrakingConditions_ActiveSubsyst;/* '<S73>/Braking Conditions' */
  int8_T If1_ActiveSubsystem_o;        /* '<S89>/If1' */
  int8_T If_ActiveSubsystem_p;         /* '<S91>/If' */
  int8_T If1_ActiveSubsystem_p;        /* '<S191>/If1' */
  int8_T BrakingConditions_ActiveSubsy_f;/* '<S160>/Braking Conditions' */
  int8_T If_ActiveSubsystem_l;         /* '<S159>/If' */
  int8_T If1_ActiveSubsystem_oe;       /* '<S167>/If1' */
  int8_T SKForCKF_ActiveSubsystem_e;   /* '<S143>/SKF or CKF' */
  int8_T Steer_angisinSteer_SatrangeLong;
  /* '<S70>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
  int8_T BrakingConditions_ActiveSubs_f3;/* '<S101>/Braking Conditions' */
  int8_T If_ActiveSubsystem_c;         /* '<S100>/If' */
  int8_T If1_ActiveSubsystem_pl;       /* '<S144>/If1' */
  int8_T If_ActiveSubsystem_h;         /* '<S146>/If' */
  int8_T If1_ActiveSubsystem_e;        /* '<S111>/If1' */
  int8_T Integrator_PrevResetState;    /* '<S36>/Integrator' */
  int8_T Integrator_PrevResetState_f;  /* '<S44>/Integrator' */
  int8_T Integrator_PrevResetState_j;  /* '<S52>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S36>/Integrator' */
  uint8_T Integrator_IC_LOADING_k;     /* '<S44>/Integrator' */
  uint8_T Integrator_IC_LOADING_e;     /* '<S52>/Integrator' */
} DW_Torque_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Product;                /* '<S162>/Product' */
  const real_T DiametertoRadius;       /* '<S162>/Diameter to Radius' */
  const real_T inchtom;                /* '<S162>/inch to m' */
  const real_T udifference;            /* '<S162>/3% difference' */
  const real_T approx2095;             /* '<S167>/Gain' */
  const real_T TowheelTqdynamic;       /* '<S167>/To wheel Tq (dynamic)' */
  const real_T TowheelTqstatic;        /* '<S167>/To wheel Tq (static)' */
  const real_T DiametertoRadius_j;     /* '<S103>/Diameter to Radius' */
  const real_T inchtom1;               /* '<S103>/inch to m1' */
  const real_T udifference1;           /* '<S103>/3% difference1' */
  const real_T Divide1;                /* '<S134>/Divide1' */
  const real_T u602pi;                 /* '<S132>/360//(2*pi)' */
  const real_T u602pi_d;               /* '<S132>/360//(2pi)' */
  const real_T approx2095_g;           /* '<S111>/Gain' */
  const real_T Constant;               /* '<S111>/Constant' */
} ConstB_Torque_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T VDC_SKF_Initial;              /* '<Root>/VDC_SKF_Initial' */
  real_T VDC_CKF_Initial;              /* '<Root>/VDC_CKF_Initial' */
  real_T VDC_Cte_SKF;                  /* '<Root>/VDC_Cte_SKF' */
  real_T VDC_Cte_CKF;                  /* '<Root>/VDC_Cte_CKF' */
  real_T VDC_Apps_Sat_Down;            /* '<Root>/VDC_Apps_Sat_Down' */
  real_T VDC_Apps_Sat_Up;              /* '<Root>/VDC_Apps_Sat_Up' */
  real_T VDC_Max_Regen_Motor_Tq;       /* '<Root>/VDC_Max_Regen_Motor_Tq' */
  real_T VDC_Power_Limit;              /* '<Root>/VDC_Power_Limit' */
  real_T VDC_K_Reduction_P;            /* '<Root>/VDC_K_Reduction_P' */
  real_T VDC_K_Reduction_Temperature; /* '<Root>/VDC_K_Reduction_Temperature' */
  real_T Workshop_Mode_Enable;         /* '<Root>/Workshop_Mode_Enable' */
  boolean_T TorqueEnable;              /* '<Root>/TorqueEnable' */
  real_T TV_Mode;                      /* '<Root>/TV_Mode' */
  real_T Highest_CellTemp;             /* '<Root>/Highest_CellTemp' */
  boolean_T CriticalDisconnection;     /* '<Root>/CriticalDisconnection' */
  real_T Accumulator_Voltage;          /* '<Root>/Accumulator_Voltage' */
  real_T Accumulator_Current;          /* '<Root>/Accumulator_Current' */
  real_T APPS2_Value;                  /* '<Root>/APPS2_Value' */
  real_T APPS1_Value;                  /* '<Root>/APPS1_Value' */
  real_T BrakeSensor_Value;            /* '<Root>/BrakeSensor_Value' */
  real_T Susp_F_L;                     /* '<Root>/Susp_F_L' */
  real_T Susp_F_R;                     /* '<Root>/Susp_F_R' */
  real_T Susp_R_L;                     /* '<Root>/Susp_R_L' */
  real_T Susp_R_R;                     /* '<Root>/Susp_R_R' */
  real_T RL_Vel_ms_Wheel;              /* '<Root>/RL_Vel_ms_Wheel' */
  real_T RR_Vel_ms_Wheel;              /* '<Root>/RR_Vel_ms_Wheel' */
  real_T RR_rads_Motor;                /* '<Root>/RR_rads_Motor' */
  real_T RL_rads_Motor;                /* '<Root>/RL_rads_Motor' */
  real_T Temp_Motors;                  /* '<Root>/Temp_Motors' */
  real_T Temp_IGBT;                    /* '<Root>/Temp_IGBT' */
  real_T Car_State;                    /* '<Root>/Car_State' */
  real_T SoC_Low;                      /* '<Root>/SoC_Low' */
  real_T SoC_High;                     /* '<Root>/SoC_High' */
  real_T SteeringSensor_Value;         /* '<Root>/SteeringSensor_Value' */
  real_T el_ACCEL_X;                   /* '<Root>/el_ACCEL_X' */
  real_T el_ACCEL_Y;                   /* '<Root>/el_ACCEL_Y' */
  real_T el_ACCEL_Z;                   /* '<Root>/el_ACCEL_Z' */
  real_T el_Vel_X;                     /* '<Root>/el_Vel_X' */
  real_T el_Vel_Y;                     /* '<Root>/el_Vel_Y' */
  real_T el_Vel_Z;                     /* '<Root>/el_Vel_Z' */
  real_T el_YAW;                       /* '<Root>/el_YAW' */
  real_T el_PITCH;                     /* '<Root>/el_PITCH' */
  real_T el_ROLL;                      /* '<Root>/el_ROLL' */
  real_T el_GYRO_X;                    /* '<Root>/el_GYRO_X' */
  real_T el_GYRO_Y;                    /* '<Root>/el_GYRO_Y' */
  real_T el_GYRO_Z;                    /* '<Root>/el_GYRO_Z' */
  boolean_T Shutdown_PackageIntck;     /* '<Root>/Shutdown_PackageIntck' */
} ExtU_Torque_Control_T;

/* External outputs (root outports fed by signals with default storage) */
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
  real_T APPS_Implausibility;          /* '<Root>/APPS_Implausibility' */
  real_T TV_Flag_WheelSpinRR;          /* '<Root>/TV_Flag_WheelSpinRR' */
  real_T TV_Flag_WheelSpinRL;          /* '<Root>/TV_Flag_WheelSpinRL' */
  real_T TV_Flag_Power;                /* '<Root>/TV_Flag_Power' */
  real_T TV_Flag_CarBehaviour;         /* '<Root>/TV_Flag_CarBehaviour' */
  real_T Power;                        /* '<Root>/Power' */
  real_T PowerLimitReached;            /* '<Root>/PowerLimitReached' */
  real_T PowerMean500ms;               /* '<Root>/PowerMean500ms' */
  boolean_T Torque_OK;                 /* '<Root>/Torque_OK' */
  real_T MeasVDCTorque_L;              /* '<Root>/Meas VDC Torque_L' */
  real_T MeasVDCTorque_R;              /* '<Root>/Meas VDC Torque_R' */
  real_T Torque_L;                     /* '<Root>/Torque_L' */
  real_T Torque_R;                     /* '<Root>/Torque_R' */
  real_T current_L;                    /* '<Root>/current_L' */
  real_T current_R;                    /* '<Root>/current_R' */
  boolean_T TV_Flag_Temperature;       /* '<Root>/TV_Flag_Temperature' */
  real_T Regenerative_Enable;          /* '<Root>/Regenerative_Enable' */
} ExtY_Torque_Control_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Torque_Control_B
#define BlockIO                        B_Torque_Control_T
#define rtU                            Torque_Control_U
#define ExternalInputs                 ExtU_Torque_Control_T
#define rtY                            Torque_Control_Y
#define ExternalOutputs                ExtY_Torque_Control_T
#define rtDWork                        Torque_Control_DW
#define D_Work                         DW_Torque_Control_T
#define tConstBlockIOType              ConstB_Torque_Control_T
#define rtC                            Torque_Control_ConstB

/* Real-time Model Data Structure */
struct tag_RTM_Torque_Control_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
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

/* Block signals (default storage) */
extern B_Torque_Control_T Torque_Control_B;

/* Block states (default storage) */
extern DW_Torque_Control_T Torque_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Torque_Control_T Torque_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Torque_Control_T Torque_Control_Y;
extern ConstB_Torque_Control_T Torque_Control_ConstB;/* constant block i/o */

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
 * '<S2>'   : 'Torque_Control/BrakePedal_Pressed'
 * '<S3>'   : 'Torque_Control/Calculate Current Conversion'
 * '<S4>'   : 'Torque_Control/Current 0'
 * '<S5>'   : 'Torque_Control/If Action Subsystem'
 * '<S6>'   : 'Torque_Control/Power Limitation Temperature'
 * '<S7>'   : 'Torque_Control/Power Limitation Torque'
 * '<S8>'   : 'Torque_Control/Regeneration_Enable'
 * '<S9>'   : 'Torque_Control/SAFETY BLOCK'
 * '<S10>'  : 'Torque_Control/TEST_MODE_IN'
 * '<S11>'  : 'Torque_Control/Vehicle Dynamics Control Modes'
 * '<S12>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection'
 * '<S13>'  : 'Torque_Control/Accumulator Power/W to kW'
 * '<S14>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/LimitReached'
 * '<S15>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch'
 * '<S16>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch/Latched Error'
 * '<S17>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch/OK'
 * '<S18>'  : 'Torque_Control/Calculate Current Conversion/KT_L_TORKY'
 * '<S19>'  : 'Torque_Control/Calculate Current Conversion/KT_R_EMY'
 * '<S20>'  : 'Torque_Control/Power Limitation Temperature/SoC_SoP'
 * '<S21>'  : 'Torque_Control/Power Limitation Temperature/Torque Limitation Temperature Controller'
 * '<S22>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP'
 * '<S23>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/Flag_Accu'
 * '<S24>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/Flag_Inv'
 * '<S25>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/Flag_Mot'
 * '<S26>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu'
 * '<S27>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters'
 * '<S28>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors'
 * '<S29>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1'
 * '<S30>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu/Temp higher than 50'
 * '<S31>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant'
 * '<S32>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Initialization'
 * '<S33>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)'
 * '<S34>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant/Compare To Zero'
 * '<S35>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Initialization/Init_u'
 * '<S36>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Discrete'
 * '<S37>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)'
 * '<S38>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters/Temp higher than 50'
 * '<S39>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S40>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S41>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S42>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S43>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S44>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S45>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)'
 * '<S46>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors/Temp higher than 110'
 * '<S47>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S48>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S49>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S50>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S51>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S52>'  : 'Torque_Control/Power Limitation Temperature/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S53>'  : 'Torque_Control/Power Limitation Torque/MATLAB Function'
 * '<S54>'  : 'Torque_Control/Regeneration_Enable/Enabled '
 * '<S55>'  : 'Torque_Control/Regeneration_Enable/NotEnabled'
 * '<S56>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY'
 * '<S57>'  : 'Torque_Control/SAFETY BLOCK/Compare To Constant'
 * '<S58>'  : 'Torque_Control/SAFETY BLOCK/DocBlock'
 * '<S59>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Imp'
 * '<S60>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Not Imp'
 * '<S61>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Signal_Failure'
 * '<S62>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Signal_OK'
 * '<S63>'  : 'Torque_Control/TEST_MODE_IN/BYPASS'
 * '<S64>'  : 'Torque_Control/TEST_MODE_IN/TEST_CONSTANTS'
 * '<S65>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Automatic Failure Mode'
 * '<S66>'  : 'Torque_Control/Vehicle Dynamics Control Modes/DocBlock'
 * '<S67>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Manual Failure Mode Selection'
 * '<S68>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Rigid Axle'
 * '<S69>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC'
 * '<S70>'  : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete'
 * '<S71>'  : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal'
 * '<S72>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Rigid Axle/Rigid Axle without TC '
 * '<S73>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking'
 * '<S74>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Inertia or Braking without Regen'
 * '<S75>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerator behaviour'
 * '<S76>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Lateral Dynamics'
 * '<S77>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Longitudinal Dynamics'
 * '<S78>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/MATLAB Function1'
 * '<S79>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF'
 * '<S80>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Regenerating'
 * '<S81>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Steering TV 2017 (without TC)'
 * '<S82>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Accelerating'
 * '<S83>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Inertia Braking'
 * '<S84>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Mech_Braking'
 * '<S85>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking'
 * '<S86>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking/MATLAB Function'
 * '<S87>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking/MATLAB Function1'
 * '<S88>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  '
 * '<S89>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S90>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /MATLAB Function1'
 * '<S91>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF'
 * '<S92>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S93>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S94>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S95>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S96>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/No spin'
 * '<S97>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/Spin'
 * '<S98>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/No spin/MATLAB Function'
 * '<S99>'  : 'Torque_Control/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/Spin/MATLAB Function'
 * '<S100>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq'
 * '<S101>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours'
 * '<S102>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Flags'
 * '<S103>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/In_Numbers'
 * '<S104>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics'
 * '<S105>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics'
 * '<S106>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/MATLAB Function1'
 * '<S107>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/MATLAB Function2'
 * '<S108>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF'
 * '<S109>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Sensor_DATA'
 * '<S110>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor'
 * '<S111>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative'
 * '<S112>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Braking with Regenerative'
 * '<S113>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/If Action 1'
 * '<S114>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/If Action 2'
 * '<S115>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/MATLAB Function'
 * '<S116>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/Momentum Z scaled'
 * '<S117>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/minimum value'
 * '<S118>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/minimum value1'
 * '<S119>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/Momentum Z scaled/MATLAB Function'
 * '<S120>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Braking with Regenerative/MATLAB Function'
 * '<S121>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Accelerating'
 * '<S122>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Accelerator behaviour '
 * '<S123>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Inertia Braking'
 * '<S124>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Mech_Braking'
 * '<S125>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Regenerative+Mech Braking'
 * '<S126>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Regenerative+Mech Braking/MATLAB Function'
 * '<S127>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Force Difference with  Max. Tire Forces'
 * '<S128>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Kamm_Circle'
 * '<S129>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/MATLAB Function1'
 * '<S130>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/MATLAB Function2'
 * '<S131>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference'
 * '<S132>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Yaw_Rate_Reference'
 * '<S133>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Kamm_Circle/Kamm_Circle LatD'
 * '<S134>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference/ Momentum_Z to Longitudinal Force Difference'
 * '<S135>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference/Momentum respect to Z-axis to correct the error'
 * '<S136>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Yaw_Rate_Reference/Bicycle Model'
 * '<S137>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/Kamm_Circle'
 * '<S138>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/MATLAB Function'
 * '<S139>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/MATLAB Function1'
 * '<S140>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/minimum value'
 * '<S141>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/Kamm_Circle/Kamm_Circle LatD'
 * '<S142>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/MATLAB Function'
 * '<S143>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  '
 * '<S144>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S145>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /MATLAB Function1'
 * '<S146>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF'
 * '<S147>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S148>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S149>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function1'
 * '<S150>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S151>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/No spin'
 * '<S152>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/Spin'
 * '<S153>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/No spin/MATLAB Function'
 * '<S154>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/Spin/MATLAB Function'
 * '<S155>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/Fx_to_engineTqRL'
 * '<S156>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/Fx_to_engineTqRR'
 * '<S157>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/MATLAB Function1'
 * '<S158>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/MATLAB Function2'
 * '<S159>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints'
 * '<S160>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours'
 * '<S161>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq'
 * '<S162>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/In_Numbers'
 * '<S163>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral'
 * '<S164>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Lateral Dynamics'
 * '<S165>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF'
 * '<S166>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Sensor_DATA'
 * '<S167>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative'
 * '<S168>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Braking with Regenerative'
 * '<S169>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/If Action 1'
 * '<S170>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/If Action 2'
 * '<S171>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled'
 * '<S172>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/minimum value'
 * '<S173>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/minimum value1'
 * '<S174>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled/MATLAB Function'
 * '<S175>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Braking with Regenerative/MATLAB Function'
 * '<S176>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Accelerating'
 * '<S177>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Inertia Braking'
 * '<S178>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Mech_Braking'
 * '<S179>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Regenerative+Mech Braking'
 * '<S180>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Accelerating/Accelerator behaviour '
 * '<S181>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Regenerative+Mech Braking/MATLAB Function'
 * '<S182>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/Fx_to_wheelTqRL'
 * '<S183>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/Fx_to_wheelTqRR'
 * '<S184>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/MATLAB Function1'
 * '<S185>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/MATLAB Function2'
 * '<S186>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/Kamm_Circle LatD'
 * '<S187>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/MATLAB Function1'
 * '<S188>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/MATLAB Function2'
 * '<S189>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/MATLAB Function'
 * '<S190>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  '
 * '<S191>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S192>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S193>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S194>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S195>' : 'Torque_Control/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Torque_Control_h_ */
