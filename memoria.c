#include "memoria.h"

void Mostrar_memoria(uint8_t *memoria,int tama)
{
    int i,k,n,j,direc;
    n=0;
    direc=255;

    for(j=0;j<4;j++)//FOR PARA EL NUMERO DE COLUMNAS
    {
          for(k=0;k<4;k++)//FOR PARA EL NUMERO DE FILAS
        {

	    for(i=0;i<4;i++)//FOR PARA MOSTRAR 4 BYTES SEGUIDOS
        {
            move(16+2*k,2+14*j);//Se mueven las direcciones
            attron(COLOR_PAIR(2));
            printw("%.2X:",direc);
            attroff(COLOR_PAIR(2));	/* Deshabilita los colores Pair 2 */
            move(16+2*k,6+2*i+14*j);//Se mueven los paquetes de 4 Bytes
            printw("%.2X", *(memoria+n));
            n++;
        }
        direc-=4;
        }
    }


}

void Init_memoria(uint8_t *memoria,int tama)
{
    int i;
    for(i=0;i<tama;i++)
    {
        *(memoria+i)=255;//Se inicializan la memoria en unos
    }
}
