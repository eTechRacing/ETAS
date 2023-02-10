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
BUILD           = yes
SYS_TARGET_FILE = irt.tlc
BUILD_SUCCESS = successful

# make matlab happy
MODEL                = Accel_Data_ETR07
MODULES              = Accel_Data_ETR07_data.c Accel_Data_ETR07_main.c
MAKEFILE             = Accel_Data_ETR07.mk
MATLAB_ROOT          = F:\Matlab2017b
MATLAB_BIN           = F:\Matlab2017b\bin
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = 
SOLVER               = 
NUMST                = 1
TID01EQ              = 0
NCSTATES             = 0
BUILDARGS            =  MODELLIB=Accel_Data_ETR07lib.lib MODELREF_TARGET_TYPE=NONE ISPROTECTINGMODEL=NOTPROTECTING RELATIVE_PATH_TO_ANCHOR=.. MAT_FILE=0 IRTWaitForStartMsg=0
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
