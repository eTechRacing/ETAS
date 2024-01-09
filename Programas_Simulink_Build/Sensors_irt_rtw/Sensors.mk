###############################################################################
#
#  IRT - INTECRIO Real-Time Target Make File Template
#
#
#  Author: 
#   Thd, ETAS
#
#  Version:
#   4.2
#
#  Synopsis:
#   Do nothing, but call rtw_build.bat
#
#
#  Copyright 2012 ETAS GmbH, Stuttgart, Germany. All rights reserved.
#
###############################################################################

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

# Call gmake wrapper defining environment for GNU cross compiler,
# instead of calling gmake directly. Otherwise environment variables 
# cannot be passed to the GNU compiler for unkown reasons (even not 
# by exporting them).
#
# BUILD_SUCCESS must be matched by the output following a successful 
# build, see $(PROGRAM) rule below.

MAKECMD         = @"rtw_build.bat"
HOST            = PC
BUILD           = no
SYS_TARGET_FILE = irt.tlc
BUILD_SUCCESS = successful

# make matlab happy
MODEL                = Sensors
MODULES              = rt_logging.c Sensors_data.c Sensors_main.c rt_sim.c
MAKEFILE             = Sensors.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2022a
MATLAB_BIN           = C:\Program Files\MATLAB\R2022a\bin
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = C:\Users\joser\OneDrive\Documentos\GitHub\ETAS\Programas_Simulink_Build\slprj\irt\_sharedutils\rtwshared.lib
SOLVER               = 
NUMST                = 1
TID01EQ              = 0
NCSTATES             = 0
BUILDARGS            =  MAT_FILE=1 IRTWaitForStartMsg=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 MODELREF_TARGET_TYPE=NONE RELATIVE_PATH_TO_ANCHOR=.. OPTS="-DTID01EQ=0"
MULTITASKING         = 0
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MODELREFS               = 
SHARED_SRC              = ..\slprj\irt\_sharedutils\*.c*
SHARED_SRC_DIR          = ..\slprj\irt\_sharedutils
SHARED_BIN_DIR          = ..\slprj\irt\_sharedutils
SHARED_LIB              = ..\slprj\irt\_sharedutils\rtwshared.lib

# EOF: irt_default.tmf
