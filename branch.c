#include "branch.h"

void BL(uint32_t *pc,uint32_t imm,uint32_t *lr)
{
    *lr=*pc+2;
    *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
}

void BX(uint32_t *pc,uint32_t rm)
{
    *pc=rm;//Igualo pc al registro rm.
}

void BLX(uint32_t *pc,uint32_t rm,uint32_t *lr)
{
    *lr=*pc+2;
    *pc+=rm;//A pc le sumo el numero de instrucciones que se desean ignorar.
}

void BAL(uint32_t *pc,uint32_t imm)
{
    *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
}

void BEQ(uint32_t *pc,uint32_t imm,char *z)
{
    char ban='1';
    if(ban==*z)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void B(uint32_t *pc,uint32_t imm)
{
    *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
}

void BNE(uint32_t *pc,uint32_t imm,char *z)
{
    char ban='0';
    if(ban==*z)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BCS(uint32_t *pc,uint32_t imm,char *c)
{
    char ban='1';
    if(ban==*c)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BCC(uint32_t *pc,uint32_t imm,char *c)
{
    char ban='0';
    if(ban==*c)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BMI(uint32_t *pc,uint32_t imm,char *n)
{
    char ban='1';
    if(ban==*n)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BPL(uint32_t *pc,uint32_t imm,char *n)
{
    char ban='0';
    if(ban==*n)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BVS(uint32_t *pc,uint32_t imm,char *v)
{
    char ban='1';
    if(ban==*v)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BVC(uint32_t *pc,uint32_t imm,char *v)
{
    char ban='0';
    if(ban==*v)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BHI(uint32_t *pc,uint32_t imm,char *c,char *z)
{
    char carry='1',zero='0';
    if((carry==*c)&&(zero==*z))
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BLS(uint32_t *pc,uint32_t imm,char *c,char *z)
{
    char carry='0',zero='1';
    if((carry==*c)&&(zero==*z))
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BGE(uint32_t *pc,uint32_t imm,char *n,char *v)
{
        if(*n==*v)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BLT(uint32_t *pc,uint32_t imm,char *n,char *v)
{
        if(*n!=*v)
    {
        *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
    }
    else
        *pc++;//A pc le sumo 1.
}

void BGT(uint32_t *pc,uint32_t imm,char *z,char *n,char *v)
{
   if((*z=='0')&&(*n==*v))
   {
      *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
   }
    else
        *pc++;//A pc le sumo 1.
}

void BLE(uint32_t *pc,uint32_t imm,char *z,char *n,char *v)
{
   if((*z=='0')&&(*n!=*v))
   {
      *pc+=imm;//A pc le sumo el numero de instrucciones que se desean ignorar.
   }
    else
        *pc++;//A pc le sumo 1.
}

