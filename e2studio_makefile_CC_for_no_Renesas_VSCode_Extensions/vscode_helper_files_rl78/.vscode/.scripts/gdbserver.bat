@echo off
setlocal enabledelayedexpansion
rem Always you must be carefull for spaces and special characters in path name

call "%~dp0inherit_environments.bat"
call :expand_enviroment_variables_in_args %*
:expand_enviroment_variables_in_args
call :tool_path_setup_for_gdbserver %1 %2
call :parse_launch_config_file_for_gdbserver %3 LCFG_ARGS
for /f "tokens=1* delims=;" %%I in ("%*") do set USER_ARGS=%%J
call :check_launch_target_program_name_for_gdb %4

cd /d "%SUPPORT_TARGET_LOC%"
rem set >>%projectRoot%\debuglog.txt && rem for debug
rem echo %GDBSERVERNAME%.exe %LCFG_ARGS% %USER_ARGS% >>%projectRoot%\debuglog.txt && rem for debug
%GDBSERVERNAME%.exe %LCFG_ARGS% %USER_ARGS%
exit %ERRORLEVEL%

:parse_launch_config_file_for_gdbserver
set KEY=com.renesas.cdt.core.serverParam
set VALUE=
set LAUNCH_CONFIG_FILE=%~1
rem Replace path separators from `/` to `\` to avoid troubles
set LAUNCH_CONFIG_FILE=%LAUNCH_CONFIG_FILE:/=\%
if "%LAUNCH_CONFIG_FILE%" == "" (
    call :error 256 ^
    "No launch file is specified. Please check the '%LaunchJsonFileName%' file."
)
if not exist "%LAUNCH_CONFIG_FILE%" (
    call :error 256 ^
    "The following launch file is not found. Please check the '%LaunchJsonFileName%' file." ^
    "'%LAUNCH_CONFIG_FILE%'"
)
for /f "usebackq tokens=3,4* delims== " %%I in ("%LAUNCH_CONFIG_FILE%") do (
    if "%%~I" == "%KEY%" (
        set T=%%K
        rem Remove `"` and `"/>`
        set VALUE=!T:~1,-3!
        set T=
        goto :parse_launch_config_file_for_gdbserver_search_key_break
    )
)
:parse_launch_config_file_for_gdbserver_search_key_break
if "%VALUE%" == "" (
    call :error 256 ^
    "The following launch file is not supported. Please contact to 'japan.renesasrulz.com/cafe_rene/f/forum21'." ^
    "'%LAUNCH_CONFIG_FILE%'"
)
set %2=%VALUE%
set KEY=
set VALUE=
goto :EOF

:tool_path_setup_for_gdbserver
if "%~n1" == "RX" (set GDBNAME=rx-elf-gdb)
if "%~n1" == "RL78" (set GDBNAME=rl78-elf-gdb)
if "%~n1" == "RH850" (set GDBNAME=v850-elf-gdb)
set GDBSERVERNAME=e2-server-gdb
set SUPPORT_TARGET_LOC=%~1
if "%~n1" == "RX" (set SUPPORT_AREA=%SUPPORT_TARGET_LOC:~0,-13%) && rem 13=strlen("\\DebugComp\\RX")
if "%~n1" == "RL78" (set SUPPORT_AREA=%SUPPORT_TARGET_LOC:~0,-15%) && rem 15=strlen("\\DebugComp\\RL78")
if "%~n1" == "RH850" (set SUPPORT_AREA=%SUPPORT_TARGET_LOC:~0,-16%) && rem 16=strlen("\\DebugComp\\RH850")
set PYTHONHOME=%~2
if "%SUPPORT_AREA%" == "" (
    call :error 256 ^
    "The following path is not defined. Please check the '%CppPropertiesFileName%' file." ^
    "'SUPPORT_AREA='"
)
if not exist "%SUPPORT_AREA%" (
    call :error 256 ^
    "The following folder is not found. Please check the '%CppPropertiesFileName%' file." ^
    "'%SUPPORT_AREA%'" ^
    "^!PO^!'SUPPORT_AREA=' defines the path.^!PC^!"
)
if not exist "%SUPPORT_TARGET_LOC%\%GDBSERVERNAME%.exe" (
    call :error 256 ^
    "The following program is not found. Please check e2 studio installation." ^
    "'%SUPPORT_TARGET_LOC%\%GDBSERVERNAME%.exe'"
)
rem The following checks will be done later for gdb but do the checks here too.
if not exist "%SUPPORT_TARGET_LOC%\%GDBNAME%.exe" (
    call :error 256 ^
    "The following program is not found. Please check e2 studio installation." ^
    "'%SUPPORT_TARGET_LOC%\%GDBNAME%.exe'"
)
if "%PYTHONHOME%" == "" (
    call :error 256 ^
    "The following path is not defined. Please check the '%CppPropertiesFileName%' file." ^
    "'PYTHONHOME='"
)
if not exist "%PYTHONHOME%" (
    call :error 256 ^
    "The following folder is not found. Please check the '%CppPropertiesFileName%' file." ^
    "'%PYTHONHOME%'" ^
    "^!PO^!'PYTHONHOME=' defines the path.^!PC^!"
)
if not exist "%PYTHONHOME%\python*dll" (
    call :error 256 ^
    "Python seems to have not installed in the following folder. Please check e2 studio installation." ^
    "'%PYTHONHOME%'" ^
    "^!PO^!'PYTHONHOME=' defines the path.^!PC^!"
)
goto :EOF

:check_launch_target_program_name_for_gdb
if not exist "%~1" (
    call :error 256 ^
    "The following launch target program has not been built. Please build the program." ^
    "%~1"
)
goto :EOF

:error
set PO=^(
set PC=^)
echo Error: %~2 %~3 %~4>&2
rem Tell Visual Studio or Visual Studio Code that launching gdbserver is failed.
echo GDB: ...
exit %1
