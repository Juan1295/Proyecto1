#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

//Se crea la funcion PUSH
/**
* \brief Función que empuja a la memoria.
* \param *mem puntero del arreglo de memoria.
* \param *reg puntero del arreglo de registros.
* \param *ord puntero de los registros a mover
* \return No retorna ningun parametro.
*/

void PUSH(uint8_t *mem,uint32_t *reg,uint8_t ord[]);

//Se crea la funcion POP
/**
* \brief Función que estrae de la memoria.
* \param *mem puntero del arreglo de memoria.
* \param *reg puntero del arreglo de registros.
* \param *ord puntero de los registros a mover
* \return No retorna ningun parametro.
*/

void POP(uint8_t *mem,uint32_t *reg,uint8_t ord[]);
