#include<stdint.h> //Libreria para incluir la variable tipo Uint32
#include<stdbool.h>
#include "flags.h" //Se incluye la libreria para las banderas.

void flags(uint32_t rx,uint32_t rn, uint32_t rm,struct flg *punt)
{
    uint32_t numero;
    numero=0;
    numero=numero|(1<<31);

    //Condicion para el numero negativo.
    if((1<<31)&rx)
    {
        punt->negativo='1';
    }
    else
    {
        punt->negativo='0';
    }
    //Condicion para la bandera cero.
    if(rx==0)
    {
        punt->zero='1';
    }
    else
    {
        punt->zero='0';
    }
    //Condicion para el acarreo
    if(((rn>=numero)&&(rm<numero)&&(rx<numero)) || ((rm>=numero)&&(rn<numero)&&(rx<numero)) || ((rn>=numero)&&(rm>=numero)))
    {
        punt->carry='1';
    }
    else
    {
        punt->carry='0';
    }
    //Condicion para el sobreflujo
    if(((rn>numero)&&(rm>numero)&&(rx<=numero))||((rn<=numero)&&(rm<=numero)&&(rx>numero)))
    {
        punt->sobreflujo='1';
    }
    else
    {
        punt->sobreflujo='0';
    }
}

void flags_logica(uint32_t rx,uint32_t rn, uint32_t rm,struct flg *punt)
{
    uint32_t numero;
    numero=0;
    numero=numero|(1<<31);

    //Condicion para el numero negativo.
    if((1<<31)&rx)
    {
        punt->negativo='1';
    }
    else
    {
        punt->negativo='0';
    }
    //Condicion para la bandera cero.
    if(rx==0)
    {
        punt->zero='1';
    }
    else
    {
        punt->zero='0';
    }
}
