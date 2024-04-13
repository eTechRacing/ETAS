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
MODEL                = rtwshared
MODULES              = const_params.c look1_binlxpw.c rtGetInf.c rtGetNaN.c rt_nonfinite.c look2_binlxpw.c
MAKEFILE             = 
MATLAB_ROOT          = C:\Program Files\MATLAB\R2023b
MATLAB_BIN           = C:\Program Files\MATLAB\R2023b\bin
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = 
SOLVER               = 
NUMST                = 
TID01EQ              = 0
NCSTATES             = 0
BUILDARGS            =  RELATIVE_PATH_TO_ANCHOR=..\..\.. IRTWaitForStartMsg=0 MODELLIB=rtwshared.lib
MULTITASKING         = 0
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MODELREFS               = 
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 

# EOF: irt_default.tmf
