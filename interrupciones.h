#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "flags.h"

/**
* \brief Funcion NVIC:se encarga de revisar las interrupciones y comunicarlas con el prosesador.
* \param *interrup arreglo de interrupciones.
* \param *bn puntero del valor que indica si ya se ejecuto una interrupcion.
* \param *reg puntero de los registros.
* \param mem arreglo de memoria.
* \param *banderas puntero de la estructura banderas.
* \return No retorna.
*/

void NVIC(int *interrup,int *bn,uint32_t *reg,struct flg *banderas,uint8_t *mem);

/**
* \brief Funcion RES:se encarga de restaurar los valores y la continuacion del programa.
* \param *reg puntero de los registros.
* \param mem arreglo de memoria.
* \param *banderas puntero de la estructura banderas.
* \return No retorna.
*/

void RES(uint8_t *mem,uint32_t *reg,struct flg *banderas);

/**
* \brief Funcion CAR:se encarga de salvar los registros y la posicion del programa que se ejecuta antes de pasar a la interrupcion.
* \param *reg puntero de los registros.
* \param mem arreglo de memoria.
* \param *banderas puntero de la estructura banderas.
* \return No retorna.
*/

void CAR(uint8_t *mem,uint32_t *reg,struct flg *banderas);
