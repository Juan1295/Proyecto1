#include<stdint.h>
#include "flags.h"

/**
* \brief Funcion logica AND para dos registros .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Puntero hacia la dirección RX la operación AND.
* \param banderas Puntero a estructura tipo flg.
* \return No retorna.
*/
void AND(uint32_t *rx,uint32_t rn,uint32_t rm,struct flg *banderas);

/**
* \brief Funcion logica ORR para dos registros .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Direccion donde se almacena la operacion OR.
* \param *banderas Puntero a estructura tipo flg.
* \return No retorna.
*/
void ORR(uint32_t *rx,uint32_t rn,uint32_t  rm,struct flg *banderas);

/**
* \brief Funcion logica EOR para dos registros .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Direccion de memoria donde se almacena la operacion EXOR.
* \param banderas Puntero a estructura tipo flg.
* \return No hay retorno.
*/
void EOR(uint32_t *rx, uint32_t rn,uint32_t rm,struct flg *banderas);

/**
* \brief Funcion logica MOV para de un registro a otro.
* \param rn Registro a copiar.
* \param *rx Direccion de memoria donde se almacena la operacion MOVER.
* \param banderas Puntero a estructura tipo flg.
* \return No hay retorno.
*/
void MOV(uint32_t *rx,uint32_t rn,struct flg *banderas);

/**
* \brief Funcion logica SUB para hacer una resta entre 2 registros.
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Direccion de memoria donde se almacena la operacion SUB.
* \param banderas Puntero a estructura tipo flg.
* \return No hay retorno.
*/
void SUB(uint32_t *rx,uint32_t rn,uint32_t rm,struct flg *banderas);

/**
* \brief Funcion que suma dos registros.
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Direccion de memoria donde se almacena la operacion SUB.
* \param banderas Puntero a estructura tipo flg.
* \return No hay retorno.
*/
void ADD(uint32_t *rx, uint32_t rn, uint32_t rm, struct flg *banderas);

/**
* \brief Funcion que suma pero no guarda el resultado, solo modifica las banderas.
* \param rn Primer registro.
* \param rm Segundo registro.
* \param banderas Puntero a estructura tipo flg.
* \return No hay retorno.
*/
void CMN(uint32_t rn,uint32_t rm,struct flg *banderas);

/**
* \brief Funcion que resta dos registros pero no guarda el resultado, solo modifica las banderas.
* \param rn Primer registro.
* \param rm Segundo registro.
* \param banderas Puntero a estructura tipo flg.
* \return No hay retorno.
*/
void CMP(uint32_t rn,uint32_t rm,struct flg *banderas);

/**
* \brief Funcion que multiplica dos registros.
* \param rn Primer registro.
* \param rm Segundo registro.
* \param *rx Dirección de memoria donde se guarda el resultado.
* \param banderas Puntero a estructura tipo flg.
* \return No hay retorno.
*/
void MUL(uint32_t *rx,uint32_t rn, uint32_t rm, struct flg *banderas);

/**
* \brief Funcion que hace una AND bit a bit pero no guarda el resultado.
* \param rn Primer registro.
* \param rm Segundo registro.
* \param banderas Puntero a estructura tipo flg.
* \return No hay retorno.
*/
void TST(uint32_t rn,uint32_t rm, struct flg *banderas);
