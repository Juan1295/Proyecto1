#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "desplazamiento.h"//Se definen librerias necesarias para la funcion

void LSL(uint32_t *rx,uint32_t ra)
{
    *rx=*rx*pow(2,ra);//Operacion necesaria para desplazar a la izquierda.
}

void LSR(uint32_t *rx,uint32_t ra)
{
    *rx=*rx/pow(2,ra);//Operacion necesaria para desplazar a la derecha.
}

void ROR(uint32_t *rx, uint32_t ra)
{
  uint32_t aux1,aux2;//Variables auxiliares para la rotacion
  aux1=*rx/pow(2,ra);//Se guarda un corrimiento a la derecha en aux1 de *rx
  aux2=*rx*pow(2,(32-ra));//Se guarda un corrimiento a la izquierda en aux 2 de *rx
  *rx=aux1|aux2;//Se suman las aux para realizar la rotacion
}

void ASR(uint32_t *rx,uint32_t ra)
{
    uint32_t aux;//Se define una variable auxiliar.
    aux=*rx&(1<<31);//Se guarda en el auxiliar el valor del bit mas significativo.
    *rx=*rx/pow(2,ra);//Se guarda en el registro el corrimiento pedido.
    *rx=*rx|aux;//Se adiere de nuevo el signo.
}

void BIC (uint32_t *rx,uint32_t ra)
{
    *rx&=~ra;//Negacion de ra y AND entre registros
}

void MVN(uint32_t *rx,uint32_t ra)
{
    *rx=~ra;//Complemento de ra.
}

void RSB(uint32_t *rx,uint32_t ra)
{
    *rx=0-ra;//Complemento a dos.
}

void NOP()//No hace nada.
{
    //No hace nada.
}

void REV(uint32_t *rx,uint32_t ra)
{
    uint32_t aux,aux1,aux2,aux3,aux4;//Variables auxiliares para la funcion.
    int i;//Contador de ciclos for, evita repetir una linea de codigo repetitivas veces o con mas variables.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Primer bloque que guarda los bits de ra situados entre el bit 24 y 31.
    for(i=24;i<32;i++)
    {
        aux1=ra&(1<<i);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux1;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
    }
    aux1=aux/pow(2,24);//Se corre el bloque de 24 a 31 bits a las posiciones de 0 a 7 y se guarda en aux1.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Segundo bloque que guarda los bits de ra situados entre el bit 0 y 7.
    for(i=0;i<8;i++)
    {
        aux2=ra&(1<<i);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux2;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
    }
    aux2=aux*pow(2,24);//Se corre el bloque de 0 a 7 bits a las posiciones de 24 a 31 y se guarda en aux2.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Tercer bloque que guarda los bits de ra situados entre el bit 8 y 15.
    for(i=8;i<16;i++)
    {
        aux3=ra&(1<<i);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux3;//Se suman logicamente los datos hallados entre 8 y 15 bits en aux.
    }
    aux3=aux*pow(2,8);//Se corre el bloque de 8 a 15 bits a las posiciones de 16 a 23 y se guarda en aux3.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Cuarto bloque que guarda los bits de ra situados entre el bit 16 y 23.
    for(i=16;i<24;i++)
    {
        aux4=ra&(1<<i);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux4;//Se suman logicamente los datos hallados entre 16 y 23 bits en aux.
    }
    aux4=aux/pow(2,8);//Se corre el bloque de 16 a 23 bits a las posiciones de 8 a 15 y se guarda en aux4.
    //Se guarda en *rx el nuevo dato ordenado.
    *rx=aux1|aux2|aux3|aux4;//Se efectua una or para acomodar cada byte en un solo registro y guardarlo.
}

void REV16(uint32_t *rx,uint32_t ra)
{
    uint32_t aux,aux1,aux2;//Variables auxiliares para la funcion.
    int i;//Contador de ciclos for, evita repetir una linea de codigo repetitivas veces o con mas variables.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Primer bloque que guarda los bits de ra situados entre el bit 0 y 15.
    for(i=0;i<16;i++)
    {
        aux1=ra&(1<<i);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux1;//Se suman logicamente los datos hallados entre 0 y 15 bits en aux.
    }
    aux1=aux*pow(2,16);//Se corre el bloque de 0 a 15 bits a las posiciones de 16 a 31 y se guarda en aux1.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Segundo bloque que guarda los bits de ra situados entre el bit 16 y 31.
    for(i=16;i<32;i++)
    {
        aux2=ra&(1<<i);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux2;//Se suman logicamente los datos hallados entre 16 y 32 bits en aux.
    }
    aux2=aux/pow(2,16);//Se corre el bloque de 16 a 31 bits a las posiciones de 0 a 15 y se guarda en aux2.
    //Se guarda en *rx el nuevo dato ordenado.
    *rx=aux1|aux2;//Se efectua una or para acomodar cada medio registro en uno solo.
}

void REVSH(uint32_t *rx,uint32_t ra)
{
    uint32_t aux,aux1,aux2;//Variables auxiliares para la funcion.
    int i;//Contador de ciclos for, evita repetir una linea de codigo repetitivas veces o con mas variables.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Primer bloque que guarda los bits de ra situados entre el bit 8 y 15.
    for(i=8;i<16;i++)
    {
        aux1=ra&(1<<i);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux1;//Se suman logicamente los datos hallados entre 8 y 15 bits en aux.
    }
    aux1=aux/pow(2,8);//Se corre el bloque de 8 a 15 bits a las posiciones de 0 a 7 y se guarda en aux1.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Segundo bloque que guarda los bits de ra situados entre el bit 0 y 7.
    for(i=0;i<8;i++)
    {
        aux2=ra&(1<<i);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux2;//Se suman logicamente los datos hallados entre 0 y 7 bits en aux.
    }
    aux2=aux*pow(2,8);//Se corre el bloque de 0 a 7 bits a las posiciones de 8 a 15 y se guarda en aux2.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Extension de signo negativo de manera logica.
    for(i=16;i<32;i++)
    {
        aux=aux|(1<<i);//Guardo un uno desde el bit 16 hasta el 31.
    }
    //If para encontrar el valor del signo.
    if((1<<15)&aux2)
    {
        *rx=aux|aux1|aux2;//Guarda en el nuevo orden con extension de signo 1.
    }
    else
    {
        *rx=aux1|aux2;//Guarda en el nuevo orden con extension de signo 0.
    }
}
