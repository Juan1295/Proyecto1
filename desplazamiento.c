#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "desplazamiento.h"//Se definen librerias necesarias para la funcion

void LSL(uint32_t *rx,uint32_t ra)
{
    *rx=*rx*pow(2,ra);//Operacion necesaria para desplazar a la izquierda.
}

void LSR(uint32_t *rx,uint32_t ra)
{
    *rx=*rx/pow(2,ra);//Operacion necesaria para desplazar a la derecha.
}

void ROR(uint32_t *rx, uint32_t ra)
{
  uint32_t aux1,aux2;//Variables auxiliares para la rotacion
  aux1=*rx/pow(2,ra);//Se guarda un corrimiento a la derecha en aux1 de *rx
  aux2=*rx*pow(2,(32-ra));//Se guarda un corrimiento a la izquierda en aux 2 de *rx
  *rx=aux1+aux2;//Se suman las aux para realizar la rotacion
}

void ASR(uint32_t *rx,uint32_t ra)
{

}

void BIC (uint32_t *rx,uint32_t ra)
{
    *rx&=~ra;//Negacion de ra y AND entre registros
}

void MVN(uint32_t *rx,uint32_t ra)
{
    *rx=~ra;//Complemento de ra.
}

void RSB(uint32_t *rx,uint32_t ra)
{
    *rx=0-ra;//Complemento a dos.
}

void NOP()//No hace nada.
{

}
