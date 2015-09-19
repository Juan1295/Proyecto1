#ifndef FLAGS_H
#define FLAGS_H
#include<stdint.h>
#include "desplazamiento.h"


/**
* \brief Funcion que Modifica las banderas de operaciones aritmeticas .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param rx Registro resultado.
* \param punt puntero a Estrucutras que contiene las banderas.
* \return No retorna.
*/

void flags(uint32_t rx,uint32_t rn, uint32_t rm,struct flg *punt);//Banderas para operaciones aritmeticas

/**
* \brief Funcion que Modifica las banderas de operaciones generales .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param rx Registro resultado.
* \param punt puntero a Estructura que contiene las banderas
* \return No retorna.
*/
void flags_logica(uint32_t rx,uint32_t rn, uint32_t rm,struct flg *punt);

#endif
