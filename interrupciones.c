#include "interrupciones.h"

void NVIC(int *interrup,int *bn,uint32_t *reg,struct flg *banderas,uint8_t *mem)
{
    int i;
    if(*bn==1)
    {
        if(*(reg+15) == 0xffffffff)
        {
            *bn=0;
            RES(mem,reg,banderas);
        }
    }
    else
    {
        for(i=0;i<32;i++)
        {
            if(interrup[i] == 1)
            {
                CAR(mem,reg,banderas);
                reg[15]=i+1;
                *(interrup+i)=0;
                reg[14]=0xffffffff;
                *bn=1;
                break;
            }
        }
    }
}

void RES(uint8_t *mem,uint32_t *reg,struct flg *banderas)
{
    int i; //Contadores.
    uint32_t aux1,aux2,aux3,k=31,ord[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1};//auxiliares tipo uint32_t para realizar corrimientos.
    if(mem[k]==1)
        banderas->zero='1';
    else
        banderas->zero='0';
    if(mem[k-1]==1)
        banderas->sobreflujo='1';
    else
        banderas->sobreflujo='0';
    if(mem[k+2]==1)
        banderas->negativo='1';
    else
        banderas->negativo='1';
    if(mem[k+3]==1)
        banderas->carry='1';
    else
        banderas->carry='0';

    k=0;
    for(i=0;i<16;i++)
    {
        if(ord[i]==1)
        {
            aux1=mem[k-3];
            aux1=(aux1)<<24;
            aux2=mem[k-2];
            aux2=(aux2)<<16;
            aux3=mem[k-1];
            aux3=(aux3)<<8;
            reg[i]=(aux1)|(aux2)|(aux3)|(mem[k]);//Guaarda en el registro lo encontrado en las 4 primeras posiciones de memoria
            k-=4;//Baja 4 posiciones en la memoria.
        }
    }
}

void CAR(uint8_t *mem,uint32_t *reg,struct flg *banderas)
{
    int i,j;//Contador de ciclo for.
    uint32_t aux,aux1,aux2,aux3,aux4,k=0,ord[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1};
    for(i=0;i<16;i++)
    {
        if(ord[i]==1)
        {
            aux=0;//Inicializo aux en cero para no contar con basura.
            //Segundo bloque que guarda los bits de ra situados entre el bit 0 y 7.
            for(j=0;j<8;j++)
            {
                aux1=*(reg+i)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
                aux=aux|aux1;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
            }
            aux1=aux;
            mem[k+3]=aux1;
            aux=0;//Inicializo aux en cero para no contar con basura.
            //Tercer bloque que guarda los bits de ra situados entre el bit 8 y 15.
            for(j=8;j<16;j++)
            {
                aux2=*(reg+i)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
                aux=aux|aux2;//Se suman logicamente los datos hallados entre 8 y 15 bits en aux.
            }
            aux2=aux>>8;
            mem[k+2]=aux2;
            //Primer bloque que guarda los bits de ra situados entre el bit 24 y 31.
            aux=0;//Inicializo aux en cero para no contar con basura.
            //Cuarto bloque que guarda los bits de ra situados entre el bit 16 y 23.
            for(j=16;j<24;j++)
            {
                aux3=*(reg+i)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
                aux=aux|aux3;//Se suman logicamente los datos hallados entre 16 y 23 bits en aux.
            }
            aux3=aux>>16;
            mem[k+1]=aux3;
            aux=0;//Inicializo aux en cero para no contar con basura.
            for(j=24;j<32;j++)
            {
                aux4=*(reg+i)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
                aux=aux|aux4;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
            }
            aux4=aux>>24;
            mem[k]=aux4;
            k=k+4;
        }
    }
    if(banderas->carry == '1')
        mem[k]=1;
    else
        mem[k]=0;
    if(banderas->negativo == '1')
        mem[k+1]=1;
    else
        mem[k+1]=0;
    if(banderas->sobreflujo == '1')
        mem[k+2]=1;
    else
        mem[k+2]=0;
    if(banderas->zero == '1')
        mem[k+3]=1;
    else
        mem[k+3]=0;
}
