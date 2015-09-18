#include <stdio.h>
#include <stdlib.h>
#include "branch.h"

int main()
{
    uint32_t pc=5,imm=3,lr=0,rm=3;
    char z='0',c='0',n='0',v='0';
    //BL(&pc,imm,&lr);
    //BX(&pc,rm);
    //BLX(&pc,rm,&lr);
    //BAL(&pc,imm);
    //BEQ(&pc,imm,&z);
    //B(&pc,imm,&z);
    //BNE(&pc,imm,&z);
    //BCS(&pc,imm,&c);
    //BCC(&pc,imm,&c);
    //BMI(&pc,imm,&n);
    //BPL(&pc,imm,&n);
    //BVS(&pc,imm,&v);
    //BVC(&pc,imm,&v);
    //BHI(&pc,imm,&c,&z);
    //BLS(&pc,imm,&c,&z);
    //BGE(&pc,imm,&n,&v);
    //BLT(&pc,imm,&n,&v);
    //BGT(&pc,imm,&z,&n,&v);
    BLE(&pc,imm,&z,&n,&v);
    printf("%u\n%u ",pc,lr);
}
