int language_extensions(void);
int language_extensions(void)
{
    volatile void __evenaccess * portbase = (volatile void * __evenaccess *)0x8C000;

    int *pt = __sectop( "B" );
    int *pe = __secend( "B" );
    int sz = __secsize( "B" );

    __nop();

    return *pt + *pe + sz;
}
