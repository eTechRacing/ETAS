
set MATLAB=C:\Program Files\MATLAB\R2022a

@"rtw_build.bat" -f Torque_Control.mk  MAT_FILE=1 IRTWaitForStartMsg=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 MODELREF_TARGET_TYPE=NONE RELATIVE_PATH_TO_ANCHOR=.. OPTS="-DTID01EQ=1"
