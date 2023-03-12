/* Include file to test dependency scan for "Unix Makefiles" and "Ninja". */
#include "test_dep_scan_etc_c.h"

/* Check definition via command line option */
#if !defined(RL78_G23_FPB) || (RL78_G23_FPB != 1)
#error !defined(RL78_G23_FPB) || (RL78_G23_FPB != 1)
#endif

/* Generate warning messages */
void *p;
int vi = &p;
long long vl = &p;
