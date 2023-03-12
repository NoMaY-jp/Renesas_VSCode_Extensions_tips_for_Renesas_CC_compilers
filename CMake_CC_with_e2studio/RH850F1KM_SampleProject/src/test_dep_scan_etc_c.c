/* Include file to test dependency scan for "Unix Makefiles" and "Ninja". */
#include "test_dep_scan_etc_c.h"

/* Check definition via command line option */
#if !defined(RH850_F1KM_TRGT) || (RH850_F1KM_TRGT != 1)
#error !defined(RH850_F1KM_TRGT) || (RH850_F1KM_TRGT != 1)
#endif

/* Generate warning messages */
void *p;
int vi = &p;
long long vl = &p;
