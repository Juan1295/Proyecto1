#include <stdio.h>
#include <stdlib.h>
#include "desplazamiento.h"

//main de prubas.
/**
* \brief main para ejecutar las funciones.
* \return No retorna ningun parametro.
*/

int main(void)
{
    uint32_t rx,ra;//Se definen los registros:*rx con la informacion y ra con el numero de rotaciones.
    struct flg Bandera;//Se defune una estructura par a las banderas.

    printf("RA: 'Numero de desplzamientos o rotaciones o primer registro'\n");//Adquisicion de ra.
    scanf("%d",&ra);
    printf("RX: 'Numero a procesar o registro donde se guarda la operacion'\n");//Adquisicion de *rx.
    scanf("%d",&rx);
    ROR(&rx,ra,&Bandera);//Funcion de rotar
    LSR(&rx,ra,&Bandera);//Funcion de desplazar a la derecha.
    LSL(&rx,ra,&Bandera);//Funcion de desplazar a la izquierda.
    ASR(&rx,ra,&Bandera);//Funcion de desplazamiento a la izquierda conservando signo
    BIC(&rx,ra,&Bandera);//Funcion de negar un registro y AND entre ellos.
    MVN(&rx,ra,&Bandera);//Se llama la funcion de complemento de ra
    RSB(&rx,ra,&Bandera);//Funcion de complemento a dos.
    NOP();//Funcion que no hace nada
    printf("%u",rx);//Muestra el dato rotado.
    return 0;
}
