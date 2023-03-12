; Include file to test dependency scan for "Unix Makefiles" and "Ninja".
$include "test_dep_scan_etc_asm.inc"

; Check definition via command line option
$if (RL78_G23_FPB - 1)
; Force an assemble error
$include "#error !defined(RL78_G23_FPB) || (RL78_G23_FPB != 1)"
$endif
$if (DEF_WITHOUT_VAL - 1)
; Force an assemble error
$include "#error !defined(DEF_WITHOUT_VAL) || (DEF_WITHOUT_VAL != 1)"
$endif
