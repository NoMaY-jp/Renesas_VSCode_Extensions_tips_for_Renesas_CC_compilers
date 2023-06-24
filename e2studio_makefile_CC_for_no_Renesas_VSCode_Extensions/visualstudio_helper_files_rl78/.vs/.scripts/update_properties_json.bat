@echo off
setlocal enabledelayedexpansion
rem Always you must be carefull for spaces and special characters in path name

call "%~dp0inherit_environments.bat" -GetCppPropertiesFileName
call :get_program_name_and_extention "%CD%"
call :get_tcinstall_path "%CD%"
call :update_CppPropertiesFile "%~dp0..\.."
goto :EOF

:update_CppPropertiesFile

:backup
set BACKUPFOLDER=%DATE:/=-%-%TIME::=-%
set BACKUPFOLDER=%BACKUPFOLDER: =0%
set BACKUPFOLDER=%BACKUPFOLDER:~0,-3%
set ORGFILE=%~dpnx1\%CppPropertiesFileName%
set BAKFILE=%~dpnx1\trash\%BACKUPFOLDER%\%CppPropertiesFileName:~0,-5%.bak.json
if not exist "%ORGFILE%" call :error 256 "'%CppPropertiesFileName%' is not found."
echo '%CppPropertiesFileName%' is found.
echo Backup the file to trash folder.
mkdir "%BAKFILE%\..\" 1>nul
if errorlevel 1 call :error %ERRORLEVEL% "Unable to backup the file."
move "%ORGFILE%" "%BAKFILE%" 1>nul
if errorlevel 1 call :error %ERRORLEVEL% "Unable to backup the file."
echo Update the file for this e2 studio project.

:update
set is_env_flag=false
for /f "usebackq tokens=1 delims=" %%L in ("%BAKFILE%") do (
    set LINE=%%L
    for /f "usebackq tokens=1* delims=:" %%I in ('%%L') do (
        set STR0=%%I
    )
    rem Do not remove `tab` in delims.
    for /f "usebackq tokens=1* delims=:	 " %%I in ('%%L') do (
        set STR1=%%~I
        set STR2=
        if "!STR1!" == "env" (
            set is_env_flag=true
        ) else if "!STR1:~0,2!" == "}," (
            set is_env_flag=false
        ) else if "!STR1:~0,2!" == "}" (
            set is_env_flag=false
        ) else if "!STR1:~0,2!" == "//" (
            rem Nothing to do
        ) else if "!STR1!" == "PROJECT_NAME" (
            set STR2=%PROJECT_NAME%
        ) else if "!STR1!" == "PROGRAM_NAME" (
            set STR2=%PROGRAM_NAME%
        ) else if "!STR1!" == "PROGRAM_EXT" (
            set STR2=%PROGRAM_EXT%
        ) else if "!STR1!" == "E2STUDIO_WORKSPACE_FOLDER" (
            set STR2=%E2STUDIO_WORKSPACE_FOLDER%
        ) else if "!STR1!" == "ECLIPSE_HOME" (
            set STR2=%ECLIPSE_HOME%
        ) else if "!STR1!" == "SUPPORT_AREA" (
            set STR2=%SUPPORT_AREA%
        ) else if "!STR1!" == "PYTHONHOME" (
            set STR2=%PYTHONHOME%
        ) else if "!STR1!" == "TCINSTALL" (
            set STR2=%TCINSTALL%
        ) else if "!STR1!" == "TC_NAME" (
            set STR2=%TC_NAME%
        )
    )
    if not "!STR2!" == "" (
        set STR2=!STR2:\=\\!
        if "!STR2:~-2,2!" == "\\" (
            set STR2=!STR2:~0,-2!
        )
        set LINE=!STR0!: "!STR2!",
    )
    echo !LINE!>>"%ORGFILE%"
)

:completed
echo Completed.

:clean_up
set is_env_flag=
set STR0=
set STR1=
set LINE=
goto :EOF

:get_program_name_and_extention
set PROGRAM_NAME=
set PROGRAM_EXT=
if not exist "%~dpnx1\makefile" (
    call :error 256 ^
    "The following file is not found. Please setup 'makefile' and its related files." ^
    "'%~dpnx1\makefile'"
)
for /f "usebackq tokens=1* delims= " %%I in ("%~dpnx1\makefile") do (
    if "%%~I" == "all:" (
        call :get_program_name_and_extention_helper %%J
    )
    if "%%~I" == "main-build:" (
        call :get_program_name_and_extention_helper %%J
    )
)
if "%PROGRAM_NAME%" == "" (
    call :error 256 ^
    "The following makefile is not supported. Please contact to 'japan.renesasrulz.com/cafe_rene/f/forum21'." ^
    "'%~dpnx1\makefile'"
)
rem echo %PROGRAM_NAME% & rem for debug
rem echo %PROGRAM_EXT% & rem for debug
goto :EOF

:get_program_name_and_extention_helper
if "%~1" == "" goto :EOF
if "%~n1" == "" (
    shift
    goto get_program_name_and_extention_helper
)
if /i not "%~x1" == ".elf" if /i not "%~x1" == ".x" (
    shift
    goto get_program_name_and_extention_helper
)
set PROGRAM_NAME=%~n1
set PROGRAM_EXT=%~x1
goto :EOF

:get_tcinstall_path
set TCINSTALL=
set TC_NAME=
if not exist "%~dpnx1\makefile.init" (
    call :error 256 ^
    "The following file is not found. Please setup makefile and its related files including the file." ^
    "'%~dpnx1\makefile.init'"
)
for /f "usebackq tokens=1,2* delims=:= " %%I in ("%~dpnx1\makefile.init") do (
    if "%%~I" == "export" if "%%~J" == "TCINSTALL" if not "%%~K" == "" (
        for /f "usebackq tokens=1 delims=$" %%L in ('%%K') do (
            if not "%%~L" == "" (
                set TCINSTALL=%%~L
                if exist "%%~L\bin\rx-elf-gcc.exe" set TC_NAME=GNURX
                if exist "%%~L\bin\rl78-elf-gcc.exe" set TC_NAME=GNURL78
                if exist "%%~L\bin\clang.exe" if exist "%%~L\bin\rx-elf-gdb.exe" set TC_NAME=LLVM-RX
                if exist "%%~L\bin\clang.exe" if exist "%%~L\bin\rl78-elf-gdb.exe" set TC_NAME=LLVM-RL78
            )
        )
    )
    if "%%~I" == "export" if "%%~J" == "BIN_RX" if not "%%~K" == "" (
        set TCINSTALL=%%~K\..
        if exist "%%~K\ccrx.exe" (
            rem Convert short name to long name
            for /f "usebackq" %%L in (`where "%%~K":"ccrx.exe"`) do (
                rem %%L is the full path of the exe, therefore \..\.. is added.
                call :get_tcinstall_path_helper TCINSTALL "%%~L\..\.."
                set TC_NAME=CC-RX
            )
        )
    )
    if "%%~I" == "PATH" if "%%~J" == "$(PATH)" if not "%%~K" == "" (
        set TCINSTALL=%%~K\..
        if exist "%%~K\ccrl.exe" (
            rem Convert short name to long name
            for /f "usebackq" %%L in (`where "%%~K":"ccrl.exe"`) do (
                rem %%L is the full path of the exe, therefore \..\.. is added.
                call :get_tcinstall_path_helper TCINSTALL "%%~L\..\.."
                set TC_NAME=CC-RL
            )
        )
    )
)
if "%TCINSTALL%" == "" (
    call :error 256 ^
    "The following makefile.init is not supported. Please contact to 'japan.renesasrulz.com/cafe_rene/f/forum21'." ^
    "'%~dpnx1\makefile.init'"
)
if "%TC_NAME%" == "" (
    call :error 256 ^
    "Compiler seems to have not installed in the following folder. Please check compiler installation." ^
    "'%TCINSTALL%'" ^
    "^!PO^!The path is obtained in '%~dpnx1\makefile.init'.^!PC^!"
)
rem echo %TCINSTALL% & rem for debug
rem echo %TC_NAME% & rem for debug
goto :EOF

:get_tcinstall_path_helper
set %1=%~dpnx2
goto :EOF

:error
echo Error: %~2
if not "%~3" == "" echo %~3
if not "%~4" == "" echo %~4
exit %1
