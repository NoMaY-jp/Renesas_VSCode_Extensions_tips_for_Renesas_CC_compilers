/***********************************************************************
*
*  FILE        : tb_rx65n.c
*  DATE        : 2022-01-01
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"
#include "sample_lib1.h"
#include "sample_lib2.h"
#include "sample_lib3.h"

void main(void);
void abort(void);
int sample_asm(int a, int b);
#if defined(CPPAPP) && (CPPAPP != 0)
int sample_cpp(int a, int b);
#endif

void main(void)
{
    sample_asm( 1, 2 );
#if defined(CPPAPP) && (CPPAPP != 0)
    sample_cpp( 3, 4 );
#endif
    sample_lib1a_c( sample_lib2a_c( 1, 2 ), sample_lib3a_c( 3, 4 ) );
    sample_lib1b_c( sample_lib2b_c( 5, 6 ), sample_lib3a_c( 7, 8 ) );
}

void abort(void)
{
}