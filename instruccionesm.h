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
* \brief Función que extrae de la memoria.
* \param *mem puntero del arreglo de memoria.
* \param *reg puntero del arreglo de registros.
* \param *ord puntero de los registros a mover
* \return No retorna ningun parametro.
*/

void POP(uint8_t *mem,uint32_t *reg,uint8_t ord[]);

//Se crea la funcion LDR
/**
* \brief Función que extrae de una direccion de memoria especifica.
* \param *rx puntero del registro donde se guarda la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \return No retorna ningun parametro.
*/

void LDR(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion LDRB
/**
* \brief Función que extrae de una direccion de memoria especifica un solo byte.
* \param *rx puntero del registro donde se guarda la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \return No retorna ningun parametro.
*/

void LDRB(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion LDRH
/**
* \brief Función que extrae de una direccion de memoria especifica dos bytes.
* \param *rx puntero del registro donde se guarda la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \return No retorna ningun parametro.
*/

void LDRH(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem);
