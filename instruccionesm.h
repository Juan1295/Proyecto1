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
* \param *mem arreglo de memoria.
* \return No retorna ningun parametro.
*/

void LDR(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion LDRB
/**
* \brief Función que extrae de una direccion de memoria especifica un solo byte.
* \param *rx puntero del registro donde se guarda la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \param *mem arreglo de memoria.
* \return No retorna ningun parametro.
*/

void LDRB(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion LDRH
/**
* \brief Función que extrae de una direccion de memoria especifica dos bytes.
* \param *rx puntero del registro donde se guarda la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \param *mem arreglo de memoria.
* \return No retorna ningun parametro.
*/

void LDRH(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion LDRSB
/**
* \brief Función que extrae de una direccion de memoria especifica un byte y se hace extension de signo para guardar en el registro.
* \param *rx puntero del registro donde se guarda la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \param *mem arreglo de memoria.
* \return No retorna ningun parametro.
*/

void LDRSB(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion LDRSH
/**
* \brief Función que extrae de una direccion de memoria especifica dos bytes y hace extension de signo para guardar en el registro.
* \param *rx puntero del registro donde se guarda la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \param *mem arreglo de memoria.
* \return No retorna ningun parametro.
*/

void LDRSH(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion STR
/**
* \brief Función empuja a una direccion de memoria especifica de un registro con sus 4 bytes a la memoria.
* \param rx registro donde se encuentra almacenada la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \param *mem arreglo de memoria.
* \return No retorna ningun parametro.
*/

void STR(uint32_t rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion STRB
/**
* \brief Función empuja a una direccion de memoria especifica de un registro con su 1 byte a la memoria.
* \param rx registro donde se encuentra almacenada la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \param *mem arreglo de memoria.
* \return No retorna ningun parametro.
*/

void STRB(uint32_t rx,uint32_t num1,uint32_t num2,uint8_t *mem);

//Se crea la funcion STRH
/**
* \brief Función empuja a una direccion de memoria especifica de un registro con sus 2 bytes a la memoria.
* \param rx registro donde se encuentra almacenada la informacion.
* \param num1 offset para buscar la direccion de memoria.
* \param num2 offset para buscar la direccion de memoria.
* \param *mem arreglo de memoria.
* \return No retorna ningun parametro.
*/

void STRH(uint32_t rx,uint32_t num1,uint32_t num2,uint8_t *mem);
