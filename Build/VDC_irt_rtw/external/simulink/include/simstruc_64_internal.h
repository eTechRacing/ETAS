/* Copyright 2020-2021 The MathWorks, Inc. */

#ifndef __SIMSTRUC_64_INTERNAL__
#define __SIMSTRUC_64_INTERNAL__

#if !defined(IS_RSIM) && !defined(IS_RAPID_ACCEL)
#include "sl_utility/simstruct_bridge_utils.hpp"
#endif

/* defined in simstruc.h */
/*_ssPortInfo*/
#define ssGetInputPortWidth(S, port)                                 \
    (isSimStruct64FeatureOn ? ssGetInputPortWidthSLSize_fwd(S, port) \
                            : ssGetInputPortWidth_fwd(S, port))
#define ssSetInputPortWidth(S, port, val)                                 \
    (isSimStruct64FeatureOn ? ssSetInputPortWidthSLSize_fwd(S, port, val) \
                            : ssSetInputPortWidth_fwd(S, port, val))
#define ssGetOutputPortWidth(S, port)                                 \
    (isSimStruct64FeatureOn ? ssGetOutputPortWidthSLSize_fwd(S, port) \
                            : ssGetOutputPortWidth_fwd(S, port))
#define ssSetOutputPortWidth(S, port, val)                                 \
    (isSimStruct64FeatureOn ? ssSetOutputPortWidthSLSize_fwd(S, port, val) \
                            : ssSetOutputPortWidth_fwd(S, port, val))
#define ssGetInputPortDimensions(S, port)                                 \
    (isSimStruct64FeatureOn ? ssGetInputPortDimensionsSLSize_fwd(S, port) \
                            : ssGetInputPortDimensions_fwd(S, port))
#define ssGetInputPortDimensionSize(S, port, dIdx)                                  \
    (isSimStruct64FeatureOn ? ssGetInputPortDimensionsSizeSLSize_fwd(S, port, dIdx) \
                            : ssGetInputPortDimensionSize_fwd(S, port, dIdx))
#define ssGetOutputPortDimensions(S, port)                                 \
    (isSimStruct64FeatureOn ? ssGetOutputPortDimensionsSLSize_fwd(S, port) \
                            : ssGetOutputPortDimensions_fwd(S, port))
#define ssGetOutputPortDimensionSize(S, port, dIdx)                                  \
    (isSimStruct64FeatureOn ? ssGetOutputPortDimensionsSizeSLSize_fwd(S, port, dIdx) \
                            : ssGetOutputPortDimensionSize_fwd(S, port, dIdx))

/*_ssSizes*/
#define ssGetNumY(S) (isSimStruct64FeatureOn ? ssGetNumYSLSize_fwd(S) : ssGetNumY_fwd(S))
#define ssSetNumY(S, nY) \
    (isSimStruct64FeatureOn ? ssSetNumYSLSize_fwd(S, nY) : ssSetNumY_fwd(S, nY))
#define ssGetSizeofY(S) (isSimStruct64FeatureOn ? ssGetSizeofYSLSize_fwd(S) : ssGetSizeofY_fwd(S))
#define ssSetSizeofY(S, nY) \
    (isSimStruct64FeatureOn ? ssSetSizeofYSLSize_fwd(S, nY) : ssSetSizeofY_fwd(S, nY))
#define ssGetNumU(S) (isSimStruct64FeatureOn ? ssGetNumUSLSize_fwd(S) : ssGetNumU_fwd(S))
#define ssSetNumU(S, nY) \
    (isSimStruct64FeatureOn ? ssSetNumUSLSize_fwd(S, nY) : ssSetNumU_fwd(S, nY))
#define ssGetSizeofU(S) (isSimStruct64FeatureOn ? ssGetSizeofUSLSize_fwd(S) : ssGetSizeofU_fwd(S))
#define ssSetSizeofU(S, nY) \
    (isSimStruct64FeatureOn ? ssSetSizeofUSLSize_fwd(S, nY) : ssSetSizeofU_fwd(S, nY))

/*_ssWork*/
#define ssGetDWorkWidth(S, index) \
    (isSimStruct64FeatureOn ? ssGetDWorkWidthSLSize_fwd(S, index) : ssGetDWorkWidth_fwd(S, index))
#define ssSetDWorkWidth(S, index, val)                                 \
    (isSimStruct64FeatureOn ? ssSetDWorkWidthSLSize_fwd(S, index, val) \
                            : ssSetDWorkWidth_fwd(S, index, val))
#endif
