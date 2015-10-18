#include "instruccionesm.h"

void PUSH(uint8_t *mem,uint32_t *reg,uint8_t ord[])
{
    int i,j;//Contador de ciclo for.
    uint32_t aux,aux1,aux2,aux3,aux4,k=256-reg[13];
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
}

void POP(uint8_t *mem,uint32_t *reg,uint8_t ord[])
{
    int i; //Contadores.
    uint32_t aux1,aux2,aux3,k;//auxiliares tipo uint32_t para realizar corrimientos.
    k=255-reg[13];//Halla el valor de SP
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
    reg[13]=255-k;//guardo el registro SP.
}

void LDR(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem)
{
    uint32_t dc,i,aux1,aux2,aux3;
    dc=num1+num2-0x20000000;
    i=255-dc;
    aux1=mem[i-3];
    aux1=(aux1)<<24;
    aux2=mem[i-2];
    aux2=(aux2)<<16;
    aux3=mem[i-1];
    aux3=(aux3)<<8;
    *rx=(aux1)|(aux2)|(aux3)|(mem[i]);//Guaarda en el registro lo encontrado en las 4 primeras posiciones de memoria
}

void LDRB(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem)
{
    uint32_t dc,i;
    dc=num1+num2-0x20000000;
    i=255-dc;
    *rx=mem[i];//Guarda en el registro lo encontrado en la direccion de memoria.
}

void LDRH(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem)
{
    uint32_t dc,i,aux;
    dc=num1+num2-0x20000000;
    i=255-dc;
    aux=mem[i-1];
    aux=(aux)<<8;
    *rx=(aux)|(mem[i]);//Guaarda en el registro lo encontrado en las 2 primeras posiciones de memoria
}

void LDRSB(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem)
{
    uint32_t dc,i,j,aux=0;
    dc=num1+num2-0x20000000;
    i=255-dc;
    *rx=mem[i];//Guarda en el registro lo encontrado en la direccion de memoria.
    //Extension de signo negativo de manera logica.
    for(j=8;j<32;j++)
    {
        aux=aux|(1<<j);//Guardo un uno desde el bit 8 hasta el 31.
    }
    //If para encontrar el valor del signo.
    if((1<<7)&(*rx))
    {
        *rx=aux|(*rx);//Guarda en el nuevo orden con extension de signo 1.
    }
}

void LDRSH(uint32_t *rx,uint32_t num1,uint32_t num2,uint8_t *mem)
{
    uint32_t dc,i,j,aux;
    dc=num1+num2-0x20000000;
    i=255-dc;
    aux=mem[i-1];
    aux=(aux)<<8;
    *rx=(aux)|(mem[i]);//Guaarda en el registro lo encontrado en las 2 primeras posiciones de memoria
    //Extension de signo negativo de manera logica.
    aux=0;//Se limpia aux
    for(j=16;j<32;j++)
    {
        aux=aux|(1<<j);//Guardo un uno desde el bit 16 hasta el 31.
    }
    //If para encontrar el valor del signo.
    if((1<<15)&(*rx))
    {
        *rx=aux|(*rx);//Guarda en el nuevo orden con extension de signo 1.
    }
}

void STR(uint32_t rx,uint32_t num1,uint32_t num2,uint8_t *mem)
{
    int j;//Contador de ciclo for.
    uint32_t aux,aux1,aux2,aux3,aux4,k,dc;
    dc=num1+num2+4-0x20000000;
    k=256-dc;
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Segundo bloque que guarda los bits de ra situados entre el bit 0 y 7.
    for(j=0;j<8;j++)
    {
        aux1=(rx)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux1;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
    }
    aux1=aux;
    mem[k+3]=aux1;
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Tercer bloque que guarda los bits de ra situados entre el bit 8 y 15.
    for(j=8;j<16;j++)
    {
        aux2=(rx)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux2;//Se suman logicamente los datos hallados entre 8 y 15 bits en aux.
    }
    aux2=aux>>8;
    mem[k+2]=aux2;
    //Primer bloque que guarda los bits de ra situados entre el bit 24 y 31.
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Cuarto bloque que guarda los bits de ra situados entre el bit 16 y 23.
    for(j=16;j<24;j++)
    {
        aux3=(rx)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux3;//Se suman logicamente los datos hallados entre 16 y 23 bits en aux.
    }
    aux3=aux>>16;
    mem[k+1]=aux3;
    aux=0;//Inicializo aux en cero para no contar con basura.
    for(j=24;j<32;j++)
    {
        aux4=(rx)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux4;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
    }
    aux4=aux>>24;
    mem[k]=aux4;
}

void STRB(uint32_t rx,uint32_t num1,uint32_t num2,uint8_t *mem)
{
    int j;//Contador de ciclo for.
    uint32_t aux,aux1,k,dc;
    dc=num1+num2-0x20000000;
    k=255-dc;
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Segundo bloque que guarda los bits de ra situados entre el bit 0 y 7.
    for(j=0;j<8;j++)
    {
        aux1=(rx)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux1;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
    }
    aux1=aux;
    mem[k]=aux1;
}

void STRH(uint32_t rx,uint32_t num1,uint32_t num2,uint8_t *mem)
{
    int j;//Contador de ciclo for.
    uint32_t aux,aux1,aux2,k,dc;
    dc=num1+num2-0x20000000;
    k=255-dc;
    aux=0;//Inicializo aux en cero para no contar con basura.
    //Segundo bloque que guarda los bits de ra situados entre el bit 0 y 7.
    for(j=0;j<8;j++)
    {
        aux1=(rx)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux1;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
    }
    aux1=aux;
    mem[k]=aux1;
    aux=0;//Inicializo aux en cero para no contar con basura.
    for(j=8;j<16;j++)
    {
        aux2=(rx)&(1<<j);//AND para guardar el bit encontrado en la posicion i.
        aux=aux|aux2;//Se suman logicamente los datos hallados entre 24 y 31 bits en aux.
    }
    aux2=aux>>8;
    mem[k-1]=aux2;
}
