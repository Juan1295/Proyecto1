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

void ADD(uint32_t *rx, uint32_t rn, uint32_t rm, struct flg *banderas)//Se define la funcion Suma
{
    *rx=rn+rm;//Se suman dos registros.
    flags(*rx,rn,rm,banderas);// Se llama la funcion para las banderas.
}
void CMN(uint32_t rn,uint32_t rm,struct flg *banderas)//Funcion que suma pero no guarda el resultado, solo modifica banderas.
{
    uint32_t rx;// Se define una variable local RX para no retornar el resultado
    rx=rn+rm;// Se suman los registros.
    flags(rx,rn,rm,banderas);// Se modifican las banderas.
}

void CMP(uint32_t rn,uint32_t rm,struct flg *banderas)//Funcion que no retorna resultado pero que modifica banderas
{
    uint32_t rx;
    rx=rn-rm;//Resta el registro rn con el registro rm
    flags(rx,rn,rm,banderas);// Se modifican las banderas.
}

void MUL(uint32_t *rx,uint32_t rn, uint32_t rm, struct flg *banderas)//Funcion que multiplica dos registros
{
    *rx=rn*rm;//Se multiplican los registros y se almacenan en rx
    flags(*rx,rn,rm,banderas);//Se modifican las banderas
}

void TST(uint32_t rn,uint32_t rm, struct flg *banderas)// Funcion que hace una AND entre los registros pero no guarda el resultado.
{
    uint32_t rx;
    rx=rn|rm;//AND entre los registros.
    flags(rx,rn,rm,banderas);//Se modifican las banderas
}
