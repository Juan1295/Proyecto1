#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void AND(uint32_t *rx,uint32_t rn,uint32_t rm,struct flg *banderas)//Se define la funcion AND
{

    *rx=rn&rm;//Se hace la operacion logica AND entre los registros.
    flags(*rx,rn,rm,banderas);//Se llama la funcion para las banderas.

}


void ORR(uint32_t *rx,uint32_t rn,uint32_t rm,struct flg *banderas)//Se define la función OR
{

    *rx=rn|rm;//Se hace la operacion logica OR entre los registros.
    flags(*rx,rn,rm,banderas);//Se llama la funcion para las banderas.
}


void EOR(uint32_t *rx,uint32_t rn,uint32_t rm,struct flg *banderas)//Se define la función EXOR
{
    *rx=rn^rm;//Se hace la operacion logica AND entre los registros.
    flags(*rx,rn,rm,banderas);//Se llama la función para las banderas
}


void MOV(uint32_t *rx,uint32_t rn,struct flg *banderas)//Se define la función MOVER
{
   *rx=rn;//Se copia rn en la direccion del registro rx.
}


void SUB(uint32_t *rx,uint32_t rn,uint32_t rm,struct flg *banderas)//Se define la funcion Resta
{
  *rx=rn-rm;//Se restan dos registros.
  flags(*rx,rn,rm,banderas);//Se llama la función para las banderas
}
