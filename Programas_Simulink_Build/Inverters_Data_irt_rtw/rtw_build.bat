@echo off
rem ###########################################################################
rem
rem  IRT - INTECRIO Real-Time Target GNU Make Wrapper
rem
rem  Copyright 2009-2014 ETAS GmbH, all rights reserved.
rem
rem  $LastChangedBy: tir9fe $
rem  $LastChangedRevision: 102875 $
rem  $LastChangedDate: 2015-10-02 18:10:04 +0200 (Fri, 02 Oct 2015) $
rem
rem ###########################################################################
@echo off

echo Using IRT tools from "%IRT_ROOT_DIR_PATH%"
IF NOT EXIST "%IRT_ROOT_DIR_PATH%" GOTO ERROR0
set RUBY_EXE_PATH=%IRT_ROOT_DIR_PATH%\..\Tools\Ruby-V1.9\bin\ruby.exe
set RUBY_PARSE_SCRIPT_PATH=%IRT_ROOT_DIR_PATH%\target\tools\rtw_patch.rb

rem Exchange 6.E-08 with irtTick, which will be a #define.
IF NOT EXIST "%RUBY_EXE_PATH%" GOTO ERROR1
IF NOT EXIST "%RUBY_PARSE_SCRIPT_PATH%" GOTO ERROR2
"%RUBY_EXE_PATH%" "%RUBY_PARSE_SCRIPT_PATH%" %*

rem Make the RTW happy.
echo ### IRT: Build successful
exit 0

:ERROR0
echo ###IRT: Could not locate directory "%IIO_ROOT_DIR_PATH%"
exit 1

:ERROR1
echo ###IRT: Could not locate file "%RUBY_EXE_PATH%"
exit 1

:ERROR2
echo ###IRT: Could not locate file "%RUBY_PARSE_SCRIPT_PATH%"
exit 2
