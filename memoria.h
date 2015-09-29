#ifndef MEMORIA_H
#define MEMORIA_H
#include <curses.h>
#include "stdint.h"


/**
* \brief Funcion para mostrar la memoria
* \param memoria Un arreglo con la memoria.
* \param tama es el tamaño de la memoria
* \return No retorna.
*/
void Mostrar_memoria(uint8_t *memoria,int tama);

/**
* \brief Funcion Inicializa la memoria
* \param memoria Un arreglo con la memoria.
* \param tama es el tamaño de la memoria
* \return No retorna.
*/
void Init_memoria(uint8_t *memoria,int tama);





#endif
