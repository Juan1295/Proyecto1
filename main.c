#include <stdio.h>
#include <stdlib.h>
#include "micros.h"

//Se crea el main para probar el programa
/**
* \param se define reg[12] como Arreglo de 12 enteros largos.
* \return No retorna ningun parametro.
*/
int main(void)
{
	uint32_t reg[12];
	registro(reg,12);// Se llama a la funci�n registro.
	return 0;
}
