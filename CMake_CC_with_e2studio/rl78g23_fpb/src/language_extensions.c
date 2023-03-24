int __callt language_extensions(void);
int __callt language_extensions(void)
{
    static int __saddr sv;
    static int __near nv;
    static int __far fv;
    int __far *pt = __sectop( ".bss" );
    int __far *pe = __secend( ".bss" );

    __nop();

    return sv + nv + fv + *pt + *pe;
}
