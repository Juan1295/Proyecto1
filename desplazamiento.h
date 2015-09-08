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
* \brief Funci�n que no hace nada.
* \return No retorna ningun parametro.
*/

void NOP();

//Se crea la funcion REV que intercambia bytes.
/**
* \brief Funci�n que intercambia bytes, el superior con el inferior y los del medio entre ellos.
* \return No retorna ningun parametro.
*/

void REV(uint32_t *rx,uint32_t ra);

//Se crea la funcion REV que intercambia 16 bits.
/**
* \brief Funci�n que intercambia la mitad de un registro por su otra mitad.
* \return No retorna ningun parametro.
*/

void REV16(uint32_t *rx,uint32_t ra);

//Se crea la funcion REVSH que intercambia los dos bytes inferiores y extiende el signo.
/**
* \brief Funci�n que intercambia los dos bytes inferiores y extiende el signo.
* \return No retorna ningun parametro.
*/

void REVSH(uint32_t *rx,uint32_t ra);
