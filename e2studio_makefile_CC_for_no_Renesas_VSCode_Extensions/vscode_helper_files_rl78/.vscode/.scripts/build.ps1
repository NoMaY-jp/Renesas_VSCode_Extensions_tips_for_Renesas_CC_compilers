# Related links
# https://docs.microsoft.com/powershell/scripting/overview
# https://docs.microsoft.com/powershell/scripting/learn/deep-dives/everything-about-if
# https://docs.microsoft.com/powershell/module/microsoft.powershell.core/about/about_regular_expressions

filter msgconv_Renesas_MS
{
    # Remove some progress and status messages from console version CS+
    $_ = $_ -replace '^P:\[Notice\]$', ''
    $_ = $_ -replace '^  \(\d+%\)Loading project \.\.\.$', ''
    $_ = $_ -replace '^\[(Error|Warning|Information)\].*', ''

    # Remove some errors and warnings from e2 studio headless build
    $_ = $_ -replace '^Managed Build system.*error:.*', ''
    $_ = $_ -replace '^Warning: NLS.*message:.*', ''
    $_ = $_ -replace '^(Eclipsec|E2studioc):$', ''
    if ( $_ -match '^Java was started but returned exit code=' )
    {
        $_ = ""
        $IsInLauncherJavaExitCodeErrorMessage = $true
    }
    elseif ( $IsInLauncherJavaExitCodeErrorMessage )
    {
        if ( $_ -match '^-' )
        {
            $_ = ""
        }
        else
        {
            $IsInLauncherJavaExitCodeErrorMessage = $false
        }
    }

    # Convert starting Japanese message (if using Japanese environment) from e2 studio headless build
    if ( $_ -match '(eclipsec|e2studioc)\.exe.* (.*)/(.*)$' )
    {
        $BuildProj = $Matches.2
        $BuildConfig = $Matches.3
    }
    elseif ( ( $BuildType -ne "" ) -and ( $BuildConfig -ne "" ) )
    {
        if ( $_ -match  '^(\d\d:\d\d:\d\d) \*\*\*\*.*\*\*\*\*$' )
        {
            $_ = $Matches.1 + " **** Build of configuration " + $BuildConfig + " for project " + $BuildProj + " ****"
        }
    }

    # In case of e2 studio project:
    # ../file --> file
    $_ = $_ -replace '^\.\./([^:(]*)(:|\()', '$1$2'

    # file(line):Ccode:message --> file(line): error Ccode: message
    # file(line):Ecode:message --> file(line): error Ecode: message
    # file(line):Fcode:message --> file(line): error Fcode: message
    $_ = $_ -replace '(.*)\((\d+)\):([CEF]\d+):(.*)', '$1($2): error $3: $4'
      
    # file(line):Wcode:message --> file(line): warning Wcode: message
    $_ = $_ -replace '(.*)\((\d+)\):(W\d+):(.*)', '$1($2): warning $3: $4'

    # file(line):Mcode:message --> file(line): info Mcode: message
    # or ^^^ VSCode, vvv Visual Studio
    # file(line):Mcode:message --> file(line): warning Mcode: message (Information)
    if ( $PSScriptRoot -match '\.vscode\\\.scripts$' )
    {
        $_ = $_ -replace '(.*)\((\d+)\):(M\d+):(.*)', '$1($2): info $3: $4'
    }
    else
    {
        # Visual Studio's Error List Window does not recognize the following severity
        # info, information, message, suggestion
        $_ = $_ -replace '(.*)\((\d+)\):(M\d+):(.*)', '$1($2): warning $3: $4 (Information)'
    }

    # Ccode:message --> Linker: error Ccode: message
    # Ecode:message --> Linker: error Ecode: message
    # Fcode:message --> Linker: error Fcode: message
    $_ = $_ -replace '^([CEF]\d+):(.*)', 'Linker: error $1: $2'

    # Wcode:message --> Linker: warning Wcode: message
    $_ = $_ -replace '^(W\d+):(.*)', 'Linker: warning $1: $2'

    # Mcode:message --> Linker: info Mcode: message
    # or ^^^ VSCode, vvv Visual Studio
    # Mcode:message --> Linker: warning Mcode: message (Information)
    if ( $PSScriptRoot -match '\.vscode\\\.scripts$' )
    {
        $_ = $_ -replace '^(M\d+):(.*)', 'Linker: info $1: $2'
    }
    else
    {
        # Visual Studio's Error List Window does not recognize the following severity
        # info, information, message, suggestion
        $_ = $_ -replace '^(M\d+):(.*)', 'Linker: warning $1: $2 (Information)'
    }

    # VSCode's Problem View needs `(num)` before `:`
    if ( ( $PSScriptRoot -match '\.vscode\\\.scripts$' ) -and ( $_ -match '^(Linker)(: .*)' ) )
    {
        $_ = $Matches.1 + "($LinkerMessageCount)" + $Matches.2
        $LinkerMessageCount = $LinkerMessageCount+ 1
    }

    # In case of e2 studio GCC project:
    # file:line: message --> file:line:: error: message
    # collect2.exe: error: message --> collect2.exe: message
    # makefile:line: error: message --> makefile:line: message
    # path/subdir.mk:line: error: message --> makefile:line: message
    $_ = $_ -replace '^([^:]:*[^:]+):(\d+): (.*)', '$1:$2:: error: $3'
    $_ = $_ -replace '^(collect2.exe): error: (.*)', '$1: $2'
    $_ = $_ -replace '^(makefile|.*subdir.mk):(\d+):: error: (.*)', '$1:$2: $3'

    # Show converted message
    if ( $_ -ne "" )
    {
        return $_
    }
}

# VSCode needs some dedicated care later.
$LinkerMessageCount = 1

# e2 studio headless build needs some dedicated care later.
$BuildProj = ""
$BuildConfig = ""
$IsInLauncherJavaExitCodeErrorMessage = $false

# Do build.bat
cmd.exe /c $PSScriptRoot\$Args | msgconv_Renesas_MS

# Return exit code of build.bat
exit $LASTEXITCODE
