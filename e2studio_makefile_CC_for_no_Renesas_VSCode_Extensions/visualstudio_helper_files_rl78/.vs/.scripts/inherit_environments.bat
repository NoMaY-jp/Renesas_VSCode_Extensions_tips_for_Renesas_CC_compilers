@echo off
rem setlocal enabledelayedexpansion && rem this is for debug purpose only
rem Always you must be carefull for spaces and special characters in path name

call :setup_enviroment_variables "%~dp0..\.." "%~dp0.." %1
goto :EOF

:setup_enviroment_variables

:set_predefined_dynamic_macros
rem The following is compatible with Visual Studio.
set projectRoot=%~dpnx1
set projectRootBaseName=%~nx1
rem echo %projectRoot% && rem for debug
rem echo %projectRootBaseName% && rem for debug
rem The following is compatible with VSCode.
set workspaceFolder=%~dpnx1
set workspaceFolderBaseName=%~nx1
rem echo %workspaceFolder% && rem for debug
rem echo %workspaceFolderBaseName% && rem for debug

:set_CppPropertiesFileName
if "%~x2" == ".vs" (
    rem For Visual Studio
    set CppPropertiesFileName=CppProperties.json
    set CppPropertiesEnviromentBlockKey=environments
    set TasksJsonFileName=.vs\tasks.vs.json
    set LaunchJsonFileName=.vs\launch.vs.json
) else (
    rem For Visual Studio Code
    set CppPropertiesFileName=.vscode\c_cpp_properties.json
    set CppPropertiesEnviromentBlockKey=env
    set TasksJsonFileName=.vscode\tasks.json
    set LaunchJsonFileName=.vscode\launch.json
)
rem echo %CppPropertiesFileName% && rem for debug
rem echo %CppPropertiesEnviromentBlockKey% && rem for debug
rem echo %TasksJsonFileName% && rem for debug
rem echo %LaunchJsonFileName% && rem for debug

if "%~3" == "-GetCppPropertiesFileName" goto :EOF

:scan_CppPropertiesFile
set is_env_flag=false
rem Do not remove `tab` in delims.
for /f "usebackq tokens=1* delims=:	 " %%I in ("%~dpnx1\%CppPropertiesFileName%") do (
    set STR1=%%~I
    if "!STR1!" == "%CppPropertiesEnviromentBlockKey%" (
        set is_env_flag=true
    ) else if "!STR1:~0,1!" == "}" (
        set is_env_flag=false
    ) else if "!STR1:~0,2!" == "//" (
        rem Nothing to do
    ) else (
        if !is_env_flag! == true (
            set STR2=%%J
            if "!STR2:~-1,1!" == "," (
                set STR2=!STR2:~0,-1!
            )
            call :set_enviroment_variable "!STR1!" !STR2!
        )
    )
)

:clean_up
set is_env_flag=
set STR1=
set STR2=
set ENV_NAME=
set ENV_VALUE=
goto :EOF

:set_enviroment_variable
set ENV_NAME=%~1%
set ENV_VALUE=%~2%
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${projectRoot}=!projectRoot!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${projectRootBaseName}=!projectRootBaseName!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${workspaceFolder}=!workspaceFolder!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${workspaceFolderBaseName}=!workspaceFolderBaseName!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.PROJECT_NAME}=!PROJECT_NAME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.PROGRAM_NAME}=!PROGRAM_NAME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.PROGRAM_EXT}=!PROGRAM_EXT!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.BUILD_CONFIG_RELEASE_NAME}=!BUILD_CONFIG_RELEASE_NAME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.BUILD_CONFIG_DEBUG_NAME}=!BUILD_CONFIG_DEBUG_NAME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.DEBUG_CONFIG_HARDWAREDEBUG_NAME}=!DEBUG_CONFIG_HARDWAREDEBUG_NAME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.DEBUG_CONFIG_SIMULATORDEBUG_NAME}=!DEBUG_CONFIG_SIMULATORDEBUG_NAME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.ECLIPSE_HOME}=!ECLIPSE_HOME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.SUPPORT_AREA}=!SUPPORT_AREA!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.PYTHONHOME}=!PYTHONHOME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.TCINSTALL}=!TCINSTALL!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:${env.TC_NAME}=!TC_NAME!%
)
if not "%ENV_VALUE%" == "" (
    set ENV_VALUE=%ENV_VALUE:\\=\%
)
rem echo name:  %ENV_NAME% && rem for debug
rem echo value: %ENV_VALUE% && rem for debug
rem echo\ && rem for debug
set %ENV_NAME%=%ENV_VALUE%
goto :EOF
