#include "instruccionesm.h"

void PUSH(uint8_t *mem,uint32_t *reg,uint8_t ord[])
{
    int i,j,k=256-reg[13];//Contador de ciclo for.
    uint32_t aux,aux1,aux2,aux3,aux4;
    for(i=0;i<16;i++)
    {
        if(ord[i]==1)
        {
            reg[13]=reg[13]-4;
            aux=0;//Inicializo aux en cero para no contar con basura.
            //Segundo bloque que guarda los bits de ra situados entre el bit 0 y 7.
            for(j=0;j<8;j++)
            {
                aux1=*(reg+i)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
                aux=aux|aux1;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
            }
            aux1=aux;
            *(mem+k+3)=aux1;
            aux=0;//Inicializo aux en cero para no contar con basura.
            //Tercer bloque que guarda los bits de ra situados entre el bit 8 y 15.
            for(j=8;j<16;j++)
            {
                aux2=*(reg+i)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
                aux=aux|aux2;//Se suman logicamente los datos hallados entre 8 y 15 bits en aux.
            }
            aux2=aux;
            *(mem+k+2)=aux2;
            //Primer bloque que guarda los bits de ra situados entre el bit 24 y 31.
            aux=0;//Inicializo aux en cero para no contar con basura.
            //Cuarto bloque que guarda los bits de ra situados entre el bit 16 y 23.
            for(j=16;j<24;j++)
            {
                aux3=*(reg+i)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
                aux=aux|aux3;//Se suman logicamente los datos hallados entre 16 y 23 bits en aux.
            }
            aux3=aux;
            *(mem+k+1)=aux3;
            aux=0;//Inicializo aux en cero para no contar con basura.
            for(j=24;j<32;j++)
            {
                aux4=*(reg+i)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
                aux=aux|aux4;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
            }
            aux4=aux;
            *(mem+k)=aux4;
            k=k+4;
        }
    }
}

void POP(uint8_t *mem,uint32_t *reg,uint8_t ord[])
{
    int i,k; //Contadores.
    uint32_t aux1,aux2,aux3;//auxiliares tipo uint32_t para realizar corrimientos.
    k=255-reg[13];//Halla el valor de SP
    for(i=0;i<16;i++)
    {
        if(ord[i]==1)
        {
            aux1=mem[k-3];
            aux1=(aux1)<<24;
            aux2=mem[k-2];
            aux2=(aux1)<<16;
            aux3=mem[k-1];
            aux3=(aux1)<<8;
            reg[i]=(aux1)|(aux2)|(aux3)|(mem[k]);//Guaarda en el registro lo encontrado en las 4 primeras posiciones de memoria
            k-=4;//Baja 4 posiciones en la memoria.
        }
    }
    reg[13]=k+257;//guardo el registro SP.
}
