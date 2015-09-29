#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

//Se crea la funcion PUSH
/**
* \brief Función que empuja a la memoria.
* \param *mem puntero del arreglo de memoria.
* \param *reg puntero del arreglo de registros.
* \param *dir puntero de las direcciones de memoria
* \param *ord puntero de los registros a mover
* \return No retorna ningun parametro.
*/

void PUSH(uint8_t *mem,uint32_t *reg,uint8_t ord[]);
