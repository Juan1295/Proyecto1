#include <stdint.h>
#include <math.h>

//Se crea la funcion LSL.
/**
* \brief Funci�n de desplazamientos a la izquierda.
* \param *rx puntero del registro con la informacion a desplazar.
* \param ra registro que indica el numero de posiciones a desplzar.
* \return No retorna ningun parametro.
*/

void LSL(uint32_t *rx,uint32_t ra);

//Se crea la funcion LSR.
/**
* \brief Funci�n de desplazamientos a la derecha.
* \param *rx puntero del registro con la informacion a desplazar.
* \param ra registro que indica el numero de posiciones a desplzar.
* \return No retorna ningun parametro.
*/

void LSR(uint32_t *rx,uint32_t ra);

//Se crea la funcion rotar.
/**
* \brief Funci�n para rotar registros.
* \param *rx puntero del registro con la informacion a rotar.
* \param ra registro que indica el numero de rotaciones a realizar.
* \return No retorna ningun parametro.
*/

void ROR(uint32_t *rx,uint32_t ra);

//Se crea la funcion de desplazar a la derecha conservando el signo.
/**
* \brief Funci�n para desplzar registros conservando el signo.
* \param *rx puntero del registro con la informacion a desplzar.
* \param ra registro que indica el numero de desplazamientos a realizar.
* \return No retorna ningun parametro.
*/

void ASR(uint32_t *rx,uint32_t ra);

//Se crea la funcion bit clear.
/**
* \brief Funci�n AND entre un registro y el complemento del otro.
* \param *rx puntero del registro con la informacion de la operacion.
* \param ra registro a negar.
* \return No retorna ningun parametro.
*/

void BIC (uint32_t *rx,uint32_t ra);

//Se crea la funcion que guarda el complemento de un registro.
/**
* \brief Funci�n que guarda el complemento de un registro.
* \param *rx puntero del registro donde se guarda el complemento.
* \param ra registro con el dato.
* \return No retorna ningun parametro.
*/

void MVN (uint32_t *rx,uint32_t ra);

//Se crea la funcion complemento a dos.
/**
* \brief Funci�n que guarda el complemento de un registro.
* \param *rx puntero del registro donde se guarda el complemento.
* \param ra registro con el dato.
* \return No retorna ningun parametro.
*/

void RSB(uint32_t *rx,uint32_t);

//Se crea la funcion que no hace nada.
/**
* \brief Funci�n que no ahce nada.
* \return No retorna ningun parametro.
*/

void NOP();
