# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <windows.h>
#include "colors.h"
#include "micros.h"

//Se crea la funcion registro.
/**
* \brief Función que muestra en pantalla los registros .
* \param reg[12] Arreglo de 12 enteros largos.
* \param i Valor entero para el  primer ciclo for.
* \param j Valor entero para el segundo ciclo for.
* \param n Valor entero para muestreo de registros.
* \return No retorna ningun parametro.
*/
void registro(uint32_t reg[],size_t dim)
{
	int i,j; //contadores de ciclo for
	int n=0; // contador de registros mostrados
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE); //Se define un manejador de la variable hcon
	dim=dim/3; // se divide la dimencion del arreglo para mostrar de a 3 registros por fila
	for(i=0;i<dim;i++) //ciclo for que determina el numero de renglones a mostrar
	{

	    for(j=0;j<3;j++)//cinclo for para mostrar 3 registros por renglon
        {
            SetConsoleTextAttribute(hCon,AQUA);//Colorea y muestra el titulo del registro a mostrar
            printf("R%-2d:",n);//Muestra que numero de registro se va a presentar
            SetConsoleTextAttribute(hCon,WHITE);//Colorea y muestra el registro
            printf("%.8X\t", reg[n]); //Imprime en pantalla 3 registros.
            n++;//Contador de arreglos
        }
    printf("\n");//Salta de linea despues de imprimir los 3 registros.
	}
}

