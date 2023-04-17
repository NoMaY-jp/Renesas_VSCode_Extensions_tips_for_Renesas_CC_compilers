/* Include file to test dependency scan for "Unix Makefiles" and "Ninja". */
#include "test_dep_scan_etc_c.h"
#include "test_dep_scan_etc_c_inc_2.h"

/* Check definition via command line option */
#if !defined(TB_RX65N) || (TB_RX65N != 1)
#error !defined(TB_RX65N) || (TB_RX65N != 1)
#endif

/* Generate warning messages */
void *p;
int vi = &p;
long long vl = &p;
