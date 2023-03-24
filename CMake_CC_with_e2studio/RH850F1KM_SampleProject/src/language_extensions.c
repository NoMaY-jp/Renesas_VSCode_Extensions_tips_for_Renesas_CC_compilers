void language_extensions(void);
void language_extensions(void)
{
#if defined(__INTELLISENSE__) || defined(_CLANGD)
    __fp16 fp16v; /* CC-RH professional version only */
#endif

    __nop();

    return;
}
