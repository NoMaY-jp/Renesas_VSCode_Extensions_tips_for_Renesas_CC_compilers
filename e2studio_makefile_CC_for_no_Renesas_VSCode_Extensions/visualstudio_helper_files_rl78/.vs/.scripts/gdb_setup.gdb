set breakpoint pending on
set detach-on-fork on
enable pretty-printing
set python print-stack none
set print object on
set print sevenbit-strings on
set host-charset UTF-8
#set target-charset WINDOWS-31J # Because this charset does not exist.
set target-wide-charset UTF-16
set target-async on
set pagination off
set non-stop on
set auto-solib-add on
set step-mode off
set breakpoint always-inserted on
inferior 1
set remotetimeout 10
set tcp connect-timeout 30
# For Visual Studio (i.e. not for Visual Studio Code)
alias logout=quit
