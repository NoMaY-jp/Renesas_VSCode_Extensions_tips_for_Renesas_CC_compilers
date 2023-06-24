@echo off
setlocal enabledelayedexpansion
rem Always you must be carefull for spaces and special characters in path name

call "%~dp0inherit_environments.bat"
rem Replace `\"` to `"`
rem echo %* && rem for debug
set ARGS=%*
set ARGS=%ARGS:\"="%
rem echo %ARGS% && rem for debug
rem echo\ && rem for debug
call :expand_enviroment_variables_in_args %ARGS%
:expand_enviroment_variables_in_args

if `%1` == `` goto :end
rem echo %1 && rem for debug
%~1

if errorlevel 1 goto :end

if `%2` == `` goto :end
rem echo %2 && rem for debug
%~2

if errorlevel 1 goto :end

if `%3` == `` goto :end
rem echo %3 && rem for debug
%~3

if errorlevel 1 goto :end

if `%4` == `` goto :end
rem echo %4 && rem for debug
%~4

if errorlevel 1 goto :end

if `%5` == `` goto :end
rem echo %5 && rem for debug
%~5

if errorlevel 1 goto :end

if `%6` == `` goto :end
rem echo %6 && rem for debug
%~6

if errorlevel 1 goto :end

if `%7` == `` goto :end
rem echo %7 && rem for debug
%~7

if errorlevel 1 goto :end

if `%8` == `` goto :end
rem echo %8 && rem for debug
%~8

if errorlevel 1 goto :end

if `%9` == `` goto :end
rem echo %9 && rem for debug
%~9

:end
exit %ERRORLEVEL%
