void zero(unsigned int *rx,unsigned int rn,unsigned int rm, unsigned int *bandera)
{

    if(*rx==0)
    {
        *bandera=1;
    }
    else
    {
        *bandera=0;
    }
}

