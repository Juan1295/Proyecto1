# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
#include "colors.h"
#include "micros.h"
#include "curses.h"


//Se crea la funcion registro.
/**
* \brief Función que muestra en pantalla los registros .
* \param reg[] Arreglo de 12 enteros largos.
* \param dim Dimension del arreglo.
* \param banderas estructura que contiene las banderas
* \return No retorna ningun parametro.
*/
void registro(uint32_t reg[],size_t dim,struct flg *banderas)
{
	int i,j; //contadores de ciclo for
	int n=0; // contador de registros mostrados

	dim=dim/3; // se divide la dimencion del arreglo para mostrar de a 3 registros por fila
	for(i=0;i<dim;i++) //ciclo for que determina el numero de renglones a mostrar
	{
	    move(10+i,2);
	    for(j=0;j<3;j++)//cinclo for para mostrar 3 registros por renglon
        {

            printw("R%-2d:",n);//Muestra que numero de registro se va a presentar

            printw("%.8x\t", reg[n]); //Imprime en pantalla 3 registros.
            n++;//Contador de arreglos
        }
    printw("\n");//Salta de linea despues de imprimir los 3 registros.
	}
    // Para mostrar laas banderas
    move(10,55);
    printw("Z=%c",banderas->zero);

    move(10,65);
    printw("V=%c",banderas->sobreflujo);

    move(12,55);
    printw("N=%c",banderas->negativo);

    move(12,65);
    printw("C=%c",banderas->carry);

	refresh();

}

