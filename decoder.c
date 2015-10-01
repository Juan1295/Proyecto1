#include "decoder.h"


void decodeInstruction(instruction_t instruction, uint32_t *reg,struct flg *banderas,uint8_t *mem)
{
	if( strcmp(instruction.mnemonic,"MOVS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
		if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            MOVS(reg+instruction.op1_value,instruction.op2_value,banderas);//Se llama la instruccion MOVS
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            MOVS(reg+instruction.op1_value,*(reg+instruction.op2_value),banderas);//Se llama la instruccion MOVS
	}

		if( strcmp(instruction.mnemonic,"MOV") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
		if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            MOV(reg+instruction.op1_value,instruction.op2_value);//Se llama la instruccion MOVS
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            MOV(reg+instruction.op1_value,*(reg+instruction.op2_value));//Se llama la instruccion MOVS
	}

    if( strcmp(instruction.mnemonic,"CMP") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            CMP(*(reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion CMP
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            CMP(*(reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion CMP
	}
    if( strcmp(instruction.mnemonic,"ANDS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#')//Se compara el tipo de dato en el operando 3
            AND((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas);//Se llama la instruccion ANDS
        if(instruction.op3_type == 'R')//Se compara el tipo de dato en el operando 3
            AND((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion ANDS
	}
    if( strcmp(instruction.mnemonic,"ORR") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#')//Se compara el tipo de dato en el operando 3
            ORR((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas);//Se llama la instruccion ORR
        if(instruction.op3_type == 'R')//Se compara el tipo de dato en el operando 3
            ORR((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion ORR
	}
    if( strcmp(instruction.mnemonic,"EOR") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#')//Se compara el tipo de dato en el operando 3
            EOR((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas);//Se llama la instruccion EOR
        if(instruction.op3_type == 'R')//Se compara el tipo de dato en el operando 3
            EOR((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion EOR
	}
    if( strcmp(instruction.mnemonic,"SUBS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#')//Se compara el tipo de dato en el operando 3
            SUB((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas);//Se llama la instruccion SUB
        if(instruction.op3_type == 'R')//Se compara el tipo de dato en el operando 3
            SUB((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion SUB
	}
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#')//Se compara el tipo de dato en el operando 3
            ADD((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas);//Se llama la instruccion ADD
        if(instruction.op3_type == 'R')//Se compara el tipo de dato en el operando 3
            ADD((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion ADD
	}

	if( strcmp(instruction.mnemonic,"ADCS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#')//Se compara el tipo de dato en el operando 3
            ADC((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas->carry,banderas);//Se llama la instruccion ADC
        if(instruction.op3_type == 'R')//Se compara el tipo de dato en el operando 3
            ADC((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas->carry,banderas);//Se llama la instruccion ADC
	}
    if( strcmp(instruction.mnemonic,"CMN") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            CMN(*(reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion CMN
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            CMN(*(reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion CMN
	}

    if( strcmp(instruction.mnemonic,"MUL") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#')//Se compara el tipo de dato en el operando 3
            MUL((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas);//Se llama la instruccion MUL
        if(instruction.op3_type == 'R')//Se compara el tipo de dato en el operando 3
            MUL((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion MUL
	}
    if( strcmp(instruction.mnemonic,"TST") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            TST(*(reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion TST
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            TST(*(reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion TST
	}
    if( strcmp(instruction.mnemonic,"LSLS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            LSL((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion LSL
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            LSL((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion LSL
	}

    if( strcmp(instruction.mnemonic,"LSRS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            LSR((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion LSR
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            LSR((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion LSR
	}

    if( strcmp(instruction.mnemonic,"ROR") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            ROR((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion ROR
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            ROR((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion ROR
	}

    if( strcmp(instruction.mnemonic,"ASR") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
            ASR((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion ASR
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            ASR((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion ASR
	}

    if( strcmp(instruction.mnemonic,"BIC") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            BIC((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion BIC
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 2
            BIC((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion BIC
	}

    if( strcmp(instruction.mnemonic,"MVN") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            MVN((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion ASR
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 2
            MVN((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion ASR
	}

    if( strcmp(instruction.mnemonic,"RSB") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            RSB((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion RSB
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 2
            RSB((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion RSB
	}

    if( strcmp(instruction.mnemonic,"REV") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            REV((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion REV
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 2
            REV((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion REV
	}

    if( strcmp(instruction.mnemonic,"NOP") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            NOP();//Se llama la instruccion NOP
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 2
            NOP();//Se llama la instruccion NOP
	}

    if( strcmp(instruction.mnemonic,"REV16") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            REV16((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion REV16
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 2
            REV16((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion REV16
	}
    if( strcmp(instruction.mnemonic,"REVSH") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            REVSH((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion REVSH
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 2
            REVSH((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion REVSH
	}



    if( strcmp(instruction.mnemonic,"BX") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BX((reg+15),instruction.op1_value);//Se llama la instruccion BX
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BX((reg+15),*(reg+instruction.op1_value));//Se llama la instruccion BX
        if(instruction.op1_type== 'L')
            BX((reg+15),*(reg+14));//Se llama la instruccion BX
	}

    if( strcmp(instruction.mnemonic,"BAL") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BAL((reg+15),instruction.op1_value);//Se llama la instruccion BAL
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BAL((reg+15),*(reg+instruction.op1_value));//Se llama la instruccion BAL
	}

    if( strcmp(instruction.mnemonic,"B") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            B((reg+15),instruction.op1_value);//Se llama la instruccion B
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            B((reg+15),*(reg+instruction.op1_value));//Se llama la instruccion B
	}

	if( strcmp(instruction.mnemonic,"BL") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BL((reg+15),instruction.op1_value,(reg+14));//Se llama la instruccion BL
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BL((reg+15),*(reg+instruction.op1_value),(reg+14));//Se llama la instruccion BL
	}

    if( strcmp(instruction.mnemonic,"BLX") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BLX((reg+15),instruction.op1_value,(reg+14));//Se llama la instruccion BLX
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BLX((reg+15),*(reg+instruction.op1_value),(reg+14));//Se llama la instruccion BLX
        if(instruction.op1_type== 'L')
            BX((reg+15),*(reg+14));//Se llama la instruccion BLX
	}

    if( strcmp(instruction.mnemonic,"BEQ") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BEQ((reg+15),instruction.op1_value,banderas->zero);//Se llama la instruccion BEQ
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BEQ((reg+15),*(reg+instruction.op1_value),banderas->zero);//Se llama la instruccion BEQ
	}

    if( strcmp(instruction.mnemonic,"BNE") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BNE((reg+15),instruction.op1_value,banderas->zero);//Se llama la instruccion BNE
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BNE((reg+15),*(reg+instruction.op1_value),banderas->zero);//Se llama la instruccion BNE
	}

    if( strcmp(instruction.mnemonic,"BCS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BCS((reg+15),instruction.op1_value,banderas->carry);//Se llama la instruccion BCS
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BCS((reg+15),*(reg+instruction.op1_value),banderas->carry);//Se llama la instruccion BCS
	}

    if( strcmp(instruction.mnemonic,"BCC") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
        {
          BCC((reg+15),instruction.op1_value,banderas->carry);//Se llama la instruccion BCC
        }

        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
        {
            BCC((reg+15),*(reg+instruction.op1_value),banderas->carry);//Se llama la instruccion BCC
        }

	}

    if( strcmp(instruction.mnemonic,"BPL") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BPL((reg+15),instruction.op1_value,banderas->negativo);//Se llama la instruccion BPL
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BPL((reg+15),*(reg+instruction.op1_value),banderas->negativo);//Se llama la instruccion BPL
	}

    if( strcmp(instruction.mnemonic,"BMI") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BMI((reg+15),instruction.op1_value,banderas->negativo);//Se llama la instruccion BMI
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BMI((reg+15),*(reg+instruction.op1_value),banderas->negativo);//Se llama la instruccion BMI
	}

    if( strcmp(instruction.mnemonic,"BVS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BVS((reg+15),instruction.op1_value,banderas->sobreflujo);//Se llama la instruccion BVS
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BVS((reg+15),*(reg+instruction.op1_value),banderas->sobreflujo);//Se llama la instruccion BVS
	}

    if( strcmp(instruction.mnemonic,"BVC") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            BVC((reg+15),instruction.op1_value,banderas->sobreflujo);//Se llama la instruccion BVC
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BVC((reg+15),*(reg+instruction.op1_value),banderas->sobreflujo);//Se llama la instruccion BVC
	}
    if( strcmp(instruction.mnemonic,"BHI") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BHI((reg+15),instruction.op1_value,banderas->carry,banderas->zero);//Se llama la instruccion BHI
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BHI((reg+15),*(reg+instruction.op1_value),banderas->carry,banderas->zero);//Se llama la instruccion BHI
	}

    if( strcmp(instruction.mnemonic,"BLS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BLS((reg+15),instruction.op1_value,banderas->carry,banderas->zero);//Se llama la instruccion BLS
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BLS((reg+15),*(reg+instruction.op1_value),banderas->carry,banderas->zero);//Se llama la instruccion BLS
	}

    if( strcmp(instruction.mnemonic,"BGE") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BGE((reg+15),instruction.op1_value,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BGE
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BGE((reg+15),*(reg+instruction.op1_value),banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BGE
	}

    if( strcmp(instruction.mnemonic,"BLT") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BLT((reg+15),instruction.op1_value,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BLT
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BLT((reg+15),*(reg+instruction.op1_value),banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BLT
	}

    if( strcmp(instruction.mnemonic,"BGT") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BGT((reg+15),instruction.op1_value,banderas->zero,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BGT
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BGT((reg+15),*(reg+instruction.op1_value),banderas->zero,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BGT
	}

    if( strcmp(instruction.mnemonic,"BLE") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
            BLE((reg+15),instruction.op1_value,banderas->zero,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BLE
        if(instruction.op1_type == 'R')//Se compara el tipo de dato en el operando 2
            BLE((reg+15),*(reg+instruction.op1_value),banderas->zero,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion B
	}
	    if( strcmp(instruction.mnemonic,"PUSH") == 0 )
        {
        *(reg+15)=*(reg+15)+1;
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		PUSH(mem,reg,instruction.registers_list);
        }
        if( strcmp(instruction.mnemonic,"POP") == 0 )
        {
        *(reg+15)=*(reg+15)+1;
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		POP(mem,reg,instruction.registers_list);
        }
}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp);	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}

