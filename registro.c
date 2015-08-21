#include "micros.h"
//Se crea la funcion registro.
/**
* \brief Función que muestra en pantalla los registros .
* \param reg[12] Arreglo de 12 enteros largos.
* \param i Valor entero para el  primer ciclo for.
* \param j Valor entero para el segundo ciclo for.
* \return No returna ningun parametro.
*/
void registro(long int reg[12])
{
	int i,j;

	for(i=0;i<12;i++)
	{
	    for(j=0;j<3;j++)
        {
            printf("%.8x\t",reg[i]);
        }
        printf("\n");
	}
}
