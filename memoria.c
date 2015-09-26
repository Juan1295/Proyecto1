#include "memoria.h"

void Mostrar_memoria(uint8_t *memoria,int tama)
{
    int i;

	    for(i=0;i<12;i++)//cinclo for para mostrar 3 registros por renglon
        {
            move(20,2+4*i);
            printw("%.2X", *(memoria+i)); //Imprime en pantalla 3 registros.
        }
}

void Init_memoria(uint8_t *memoria,int tama)
{
    int i;
    for(i=0;i<tama;i++)
    {
        *(memoria+i)=255;
    }
}
