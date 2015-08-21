#include <stdio.h>
#include <stdlib.h>
#include "micros.h"
#include "funciones.h"
/**
* \brief Cuerpo principal del programa.
* \param reg[12] Arreglo de 12 enteros largos.
* \param i Variable para el primer ciclo for.
* \return Retorna 0 cuando se finaliza el programa.
*/
int main()
{
    long int reg[12]; int i;

    for(i=0;i<12;i++)
        reg[i]=0;
    registro(reg);

	return 0;
}
