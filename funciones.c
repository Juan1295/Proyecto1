#include <stdio.h> 
#include <stdlib.h>
#include "funciones.h"
/**
* \brief Funcion logica AND para dos registros .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param rx Registro donde se almacena la operacion AND.
* \return No retorna.
*/
void AND(long int *rx,long int rn,long int rm)
{
    *rx=rn&rm;//Se hace la operacion logica AND entre los registros.
}

/**
* \brief Funcion logica ORR para dos registros .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Direccion donde se almacena la operacion OR.
* \return No retorna.
*/
void ORR(long int *rx,long int rn,long int rm)
{
    *rx=rn|rm;//Se hace la operacion logica OR entre los registros.
}

/**
* \brief Funcion logica EOR para dos registros .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Direccion de memoria donde se almacena la operacion EXOR.
* \return No hay retorno.
*/
void EOR(long int *rx,long int rn,long int rm)
{
    *rx=rn^rm;//Se hace la operacion logica AND entre los registros.
}

/**
* \brief Funcion logica MOV para de un registro a otro.
* \param rn Registro a copiar.
* \param *rx Direccion de memoria donde se almacena la operacion MOVER.
* \return No hay retorno.
*/
void MOV(long int *rx,long int rn)
{
   *rx=rn;//Se copia rn en la direccion del registro rx.
}

/**
* \brief Funcion logica SUB para hacer una resta entre 2 registros.
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Direccion de memoria donde se almacena la operacion SUB.
* \return No hay retorno.
*/
void SUB(long int *rx,long int rn,long int rm)
{
  *rx=rn-rm;//Se restan dos registros.
}
