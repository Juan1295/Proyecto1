#include "decoder.h"
#include "io.h"

void decodeInstruction(instruction_t instruction, uint32_t *reg,struct flg *banderas,uint8_t *mem,uint16_t *comando)
{
    uint8_t aux;
	if( strcmp(instruction.mnemonic,"MOVS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
		if(instruction.op2_type == '#'){//Se compara el tipo de dato en el operando 3
            MOVS(reg+instruction.op1_value,instruction.op2_value,banderas);//Se llama la instruccion MOVS
            *comando=(4<<11)+(instruction.op1_value<<8)+(instruction.op2_value);
		}
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 3
            MOVS(reg+instruction.op1_value,*(reg+instruction.op2_value),banderas);//Se llama la instruccion MOVS
            *comando=(0<<6)+(instruction.op1_value<<3)+(instruction.op2_value);
        }
	}

		if( strcmp(instruction.mnemonic,"MOV") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
		if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 2
            MOV(reg+instruction.op1_value,instruction.op2_value);//Se llama la instruccion MOVS
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 2
            MOV(reg+instruction.op1_value,*(reg+instruction.op2_value));//Se llama la instruccion MOVS
            *comando=(70<<8)+(8&(instruction.op2_value))+(7&(instruction.op1_value));
        }

	}

    if( strcmp(instruction.mnemonic,"CMP") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#')//Se compara el tipo de dato en el operando 3
        {
            CMP(*(reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion CMP
            *comando=(5<<11)+((7&(instruction.op1_value))<<8)+(255&(instruction.op2_value));
        }

        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
        {
          if(instruction.op1_value<=7&&instruction.op2_value<=7)
            {
              *comando=(266<<6)+((7&(instruction.op1_value))<<3)+(7&(instruction.op2_value));// Se verifica si el registro es de 0 a 7
            }

            else
            {
                *comando=(69<<8)+((8&(instruction.op1_value))<<8)+((15&(instruction.op2_value))<<7)+(7&(instruction.op1_value));
            }
            CMP(*(reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion CMP
        }

	}
    if( strcmp(instruction.mnemonic,"ANDS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;

        if(instruction.op3_type == 'R'){//Se compara el tipo de dato en el operando 3
            AND((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion ANDS
            *comando=(256<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}
    if( strcmp(instruction.mnemonic,"ORR") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == 'R'){//Se compara el tipo de dato en el operando 3
            ORR((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion ORR
            *comando=(268<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}
    if( strcmp(instruction.mnemonic,"EOR") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;

        if(instruction.op3_type == 'R'){//Se compara el tipo de dato en el operando 3
            EOR((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion EOR
            *comando=(257<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}
    if( strcmp(instruction.mnemonic,"SUBS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#'){//Se compara el tipo de dato en el operando 3
            SUB((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas);//Se llama la instruccion SUB
            *comando=(15<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
        if(instruction.op3_type =='N'&&instruction.op2_type == '#')
        {
           SUB((reg+instruction.op1_value),*(reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion SUB
            *comando=(7<<11)+((7&(instruction.op1_value))<<6)+(15&(instruction.op2_value));
        }
        if(instruction.op3_type == 'R'){//Se compara el tipo de dato en el operando 3
            SUB((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion SUB
            *comando=(13<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == '#'){//Se compara el tipo de dato en el operando 3
            ADD((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,banderas);//Se llama la instruccion ADD
            *comando=(14<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
        if(instruction.op3_type == 'R'){//Se compara el tipo de dato en el operando 3
            ADD((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion ADD
            *comando=(12<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
        if(instruction.op3_type =='N'&&instruction.op2_type == '#')
        {
           ADD((reg+instruction.op1_value),*(reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion SUB
            *comando=(7<<11)+((7&(instruction.op1_value))<<6)+(15&(instruction.op2_value));
        }
        if(instruction.op3_type == 'N'&&instruction.op2_type == 'R')
        {
            ADD((reg+instruction.op1_value),*(reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);
            *comando=(68<<8)+((8&(instruction.op1_value))<<7)+((15&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }

	}

	if( strcmp(instruction.mnemonic,"ADCS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == 'R'){//Se compara el tipo de dato en el operando 3
            ADC((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas->carry,banderas);//Se llama la instruccion ADC
            *comando=(261<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}
    if( strcmp(instruction.mnemonic,"CMN") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 3
            {
              *comando=(267<<6)+((7&(instruction.op1_value))<<3)+(7&(instruction.op2_value));
            CMN(*(reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion CMP

            }
        }
	}

    if( strcmp(instruction.mnemonic,"MUL") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op3_type == 'R'){//Se compara el tipo de dato en el operando 3
            MUL((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),banderas);//Se llama la instruccion MUL
            *comando=(269<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}
    if( strcmp(instruction.mnemonic,"TST") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 3
            TST(*(reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion TST
            *comando=(264<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}
    if( strcmp(instruction.mnemonic,"LSLS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#'){//Se compara el tipo de dato en el operando 3
            LSL((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion LSL
            *comando=(0<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 3
            LSL((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion LSL
            *comando=(258<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"LSRS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#'){//Se compara el tipo de dato en el operando 3
            LSR((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion LSR
            *comando=(1<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 3
            LSR((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion LSR
            *comando=(259<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"ROR") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 3
            ROR((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion ROR
            *comando=(263<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"ASR") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#'){//Se compara el tipo de dato en el operando 3
            ASR((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion ASR
            *comando=(2<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 3
            ASR((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion ASR
            *comando=(260<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
	}

    if( strcmp(instruction.mnemonic,"BIC") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 2
            BIC((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion BIC
            *comando=(270<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"MVN") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 2
            MVN((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion ASR
            *comando=(271<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"RSB") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == '#'){//Se compara el tipo de dato en el operando 2
            RSB((reg+instruction.op1_value),instruction.op2_value,banderas);//Se llama la instruccion RSB
            *comando=(265<<6)+(7&(instruction.op2_value)<<3)+(7&(instruction.op1_value));
        }
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 2
            RSB((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion RSB
            *comando=(265<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"REV") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 2
            REV((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion REV
            *comando=(744<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"NOP") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        NOP();//Se llama la instruccion NOP
        *comando=-16640;
	}

    if( strcmp(instruction.mnemonic,"REV16") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == 'R'){//Se compara el tipo de dato en el operando 2
            REV16((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion REV16
            *comando=(745<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}
    if( strcmp(instruction.mnemonic,"REVSH") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		*(reg+15)=*(reg+15)+1;
        if(instruction.op2_type == 'R')//Se compara el tipo de dato en el operando 2
        {
            REVSH((reg+instruction.op1_value),*(reg+instruction.op2_value),banderas);//Se llama la instruccion REVSH
            *comando=(747<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
        }
	}



    if( strcmp(instruction.mnemonic,"BX") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == 'R'){//Se compara el tipo de dato en el operando 2
            BX((reg+15),*(reg+instruction.op1_value));//Se llama la instruccion BX
            *comando=(142<<7)+((15&(instruction.op1_value)<<3))+(7&(0));
        }
        if(instruction.op1_type== 'L'){
            BX((reg+15),*(reg+14));//Se llama la instruccion BX
            *comando=(142<<7)+(15&(14<<3))+(7&(0));
        }
	}

    if( strcmp(instruction.mnemonic,"BAL") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BAL((reg+15),instruction.op1_value);//Se llama la instruccion BAL
            *comando=(13<<12)+(14<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"B") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            B((reg+15),instruction.op1_value);//Se llama la instruccion B
            *comando=(28<<11)+(2047&(instruction.op1_value));
        }
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

        if(instruction.op1_type == 'R'){//Se compara el tipo de dato en el operando 2
            BLX((reg+15),*(reg+instruction.op1_value),(reg+14));//Se llama la instruccion BLX
            *comando=(143<<7)+((15&(instruction.op1_value)<<3))+(7&(0));
        }
        if(instruction.op1_type== 'L'){
            BX((reg+15),*(reg+14));//Se llama la instruccion BLX
            *comando=(143<<7)+((15&(instruction.op1_value)<<3))+(7&(0));
        }
	}

    if( strcmp(instruction.mnemonic,"BEQ") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BEQ((reg+15),instruction.op1_value,banderas->zero);//Se llama la instruccion BEQ
            *comando=(13<<12)+(0<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BNE") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BNE((reg+15),instruction.op1_value,banderas->zero);//Se llama la instruccion BNE
            *comando=(13<<12)+(1<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BCS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BCS((reg+15),instruction.op1_value,banderas->carry);//Se llama la instruccion BCS
            *comando=(13<<12)+(2<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BCC") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#')//Se compara el tipo de dato en el operando 2
        {
          BCC((reg+15),instruction.op1_value,banderas->carry);//Se llama la instruccion BCC
          *comando=(13<<12)+(3<<8)+(7&(instruction.op1_value));
        }

	}

    if( strcmp(instruction.mnemonic,"BPL") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BPL((reg+15),instruction.op1_value,banderas->negativo);//Se llama la instruccion BPL
            *comando=(13<<12)+(5<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BMI") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BMI((reg+15),instruction.op1_value,banderas->negativo);//Se llama la instruccion BMI
            *comando=(13<<12)+(4<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BVS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BVS((reg+15),instruction.op1_value,banderas->sobreflujo);//Se llama la instruccion BVS
            *comando=(13<<12)+(6<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BVC") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op2_type == '#'){//Se compara el tipo de dato en el operando 2
            BVC((reg+15),instruction.op1_value,banderas->sobreflujo);//Se llama la instruccion BVC
            *comando=(13<<12)+(7<<8)+(7&(instruction.op1_value));
        }

	}
    if( strcmp(instruction.mnemonic,"BHI") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BHI((reg+15),instruction.op1_value,banderas->carry,banderas->zero);//Se llama la instruccion BHI
            *comando=(13<<12)+(8<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BLS") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BLS((reg+15),instruction.op1_value,banderas->carry,banderas->zero);//Se llama la instruccion BLS
            *comando=(13<<12)+(9<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BGE") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BGE((reg+15),instruction.op1_value,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BGE
            *comando=(13<<12)+(10<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BLT") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BLT((reg+15),instruction.op1_value,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BLT
            *comando=(13<<12)+(11<<8)+(7&(instruction.op1_value));
        }
	}

    if( strcmp(instruction.mnemonic,"BGT") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BGT((reg+15),instruction.op1_value,banderas->zero,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BGT
            *comando=(13<<12)+(12<<8)+(7&(instruction.op1_value));
        }

	}

    if( strcmp(instruction.mnemonic,"BLE") == 0 ){
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
        if(instruction.op1_type == '#'){//Se compara el tipo de dato en el operando 2
            BLE((reg+15),instruction.op1_value,banderas->zero,banderas->negativo,banderas->sobreflujo);//Se llama la instruccion BLE
            *comando=(13<<12)+(13<<8)+(7&(instruction.op1_value));
        }
	}
	    if( strcmp(instruction.mnemonic,"PUSH") == 0 )
        {
        int i;
        uint16_t aux=0;
        *(reg+15)=*(reg+15)+1;
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
		PUSH(mem,reg,instruction.registers_list);
		for(i=0;i<8;i++)
        {
            aux=aux+(instruction.registers_list[i]<<i);
        }
		*comando=(90<<9)+(instruction.registers_list[14]<<8)+(255&(aux));
        }
        if( strcmp(instruction.mnemonic,"POP") == 0 )
        {
            int i;
            uint16_t aux=0;
            *(reg+15)=*(reg+15)+1;
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
            POP(mem,reg,instruction.registers_list);
            for(i=0;i<8;i++)
            {
                aux=aux+(instruction.registers_list[i]<<i);
            }
                *comando=(94<<9)+(instruction.registers_list[15]<<8)+(255&(aux));
            }


        if( strcmp(instruction.mnemonic,"LDR") == 0 )
        {
        *(reg+15)=*(reg+15)+1;
		// instruction.op1_value --> Valor primer operando
		// instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		// ... Igual para los otros operandos
            if(instruction.op2_type == '=')//LDR con funcion de igualar
            {
                MOV((reg+instruction.op1_value),instruction.op2_value);
            }
            if(instruction.op2_type == 'S')//LDR que trabaja con sp
            {
                if(instruction.op3_value<256)//Se evalua que el inmediato sea de 8 bits
                {
                    LDR((reg+instruction.op1_value),*(reg+13),(instruction.op3_value<<2),mem);
                    *comando=(19<<11)+((7&(instruction.op1_value))<<8)+(255&(instruction.op3_value));
                }
            }
            if(instruction.op2_type == 'P')//LDR que trabaja con pc
            {
                if(instruction.op3_value<256)//Se evalua que el inmediato sea de 8 bits
                {
                    LDR((reg+instruction.op1_value),*(reg+15),(instruction.op3_value<<2),mem);
                }
            }
            if(instruction.op2_type == 'R')//LDR que trabaja con registros
            {
                if(instruction.op3_type == 'R')//LDR que trabaja con dos registros
                {
                    LDR((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),mem);
                    *comando=(44<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                }
                else//LDR que trabaja con un registro y un inmediato de 5 bits
                {
                    if(instruction.op3_value<32)//Se evalua que el inmediato sea de 5 bits
                    {
                        LDR((reg+instruction.op1_value),*(reg+instruction.op2_value),(instruction.op3_value<<2),mem);
                        *comando=(13<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                    }
                }
            }
        }
        if( strcmp(instruction.mnemonic,"LDRB") == 0 )
        {
            *(reg+15)=*(reg+15)+1;
            // instruction.op1_value --> Valor primer operando
            // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
            // ... Igual para los otros operandos
            if((instruction.op2_type == 'R')&&(instruction.op3_type == '#'))//LDRB entre registros e inmediato de 5 bits
            {
                if(instruction.op3_value<32)//Se evalua que el inmediato sea de 5 bits
                {
                    if(((*(reg+instruction.op2_value)+instruction.op3_value)>0x20000000)&&((*(reg+instruction.op2_value)+instruction.op3_value)<0x40000000))
                    {
                        LDRB((reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,mem);
                        *comando=(15<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                    }
                    else
                    {
                        aux=*(reg+instruction.op1_value);
                        IOAccess((*(reg+instruction.op2_value)+instruction.op3_value),&aux,Read);
                       *comando=(15<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                    }
                }
            }
            if((instruction.op2_type == 'R')&&(instruction.op3_type == 'R'))//LDRB entre registros
            {
                if(((*(reg+instruction.op2_value)+*(reg+instruction.op3_value))>0x20000000)&&((*(reg+instruction.op2_value)+*(reg+instruction.op3_value))<0x40000000))
                {
                    LDRB((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),mem);
                    *comando=(46<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                }
                else
                {
                    aux=*(reg+instruction.op1_value);
                    IOAccess((*(reg+instruction.op2_value)+*(reg+instruction.op3_value)),&aux,Read);
                   *comando=(46<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                }
            }
        }
        if( strcmp(instruction.mnemonic,"LDRH") == 0 )
        {
            *(reg+15)=*(reg+15)+1;
            // instruction.op1_value --> Valor primer operando
            // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
            // ... Igual para los otros operandos
            if((instruction.op2_type == 'R')&&(instruction.op3_type == '#'))//LDRH entre registros e inmediato de 5 bits
            {
                if(instruction.op3_value<32)//Se evalua que el inmediato sea de 5 bits
                {
                    LDRH((reg+instruction.op1_value),*(reg+instruction.op2_value),(instruction.op3_value<<1),mem);
                    *comando=(17<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));

                }
            }
            if((instruction.op2_type == 'R')&&(instruction.op3_type == 'R'))//LDRH entre registros
            {
                LDRH((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),mem);
                *comando=(45<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
            }
        }
        if( strcmp(instruction.mnemonic,"LDRSB") == 0 )
        {
            *(reg+15)=*(reg+15)+1;
            // instruction.op1_value --> Valor primer operando
            // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
            // ... Igual para los otros operandos
            if((instruction.op2_type == 'R')&&(instruction.op3_type == 'R'))//LDRSB
            {
                LDRSB((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),mem);
                *comando=(43<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
            }
        }
        if( strcmp(instruction.mnemonic,"LDRSH") == 0 )
        {
            *(reg+15)=*(reg+15)+1;
            // instruction.op1_value --> Valor primer operando
            // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
            // ... Igual para los otros operandos
            if((instruction.op2_type == 'R')&&(instruction.op3_type == 'R'))//LDRSH entre registros
            {
                LDRSH((reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),mem);
                *comando=(47<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
            }
        }
        if( strcmp(instruction.mnemonic,"STR") == 0 )
        {
            *(reg+15)=*(reg+15)+1;
            // instruction.op1_value --> Valor primer operando
            // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
            // ... Igual para los otros operandos
            if((instruction.op2_type == 'R')&&(instruction.op3_type == '#'))//STR entre registros e inmediato de 5 bits
            {
                if(instruction.op3_value<32)//Se evalua que el inmediato sea de 5 bits
                {
                    STR(*(reg+instruction.op1_value),*(reg+instruction.op2_value),(instruction.op3_value<<2),mem);
                    *comando=(12<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                }
            }
            if((instruction.op2_type == 'R')&&(instruction.op3_type == 'R'))//STR entre registros
            {
                STR(*(reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),mem);
                *comando=(40<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
            }
            if((instruction.op2_type == 'S')&&(instruction.op3_type == '#'))//STR entre sp e inmediato de 8 bits
            {
                if(instruction.op3_value<256)//Se evalua que el inmediato sea de 8 bits
                {
                    STR(*(reg+instruction.op1_value),*(reg+instruction.op2_value),(instruction.op3_value<<2),mem);
                    *comando=(18<<11)+((7&(instruction.op1_value))<<8)+(255&(instruction.op3_value));
                }
            }
        }
        if( strcmp(instruction.mnemonic,"STRB") == 0 )
        {
            *(reg+15)=*(reg+15)+1;
            // instruction.op1_value --> Valor primer operando
            // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
            // ... Igual para los otros operandos
            if((instruction.op2_type == 'R')&&(instruction.op3_type == '#'))//STR entre registros e inmediato de 5 bits
            {
                if(instruction.op3_value<32)//Se evalua que el inmediato sea de 5 bits
                {
                    if(((*(reg+instruction.op2_value)+instruction.op3_value)>0x20000000)&&((*(reg+instruction.op2_value)+instruction.op3_value)<0x40000000))
                    {
                        STRB(*(reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,mem);
                        *comando=(14<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                    }
                    else
                    {
                        aux=*(reg+instruction.op1_value);
                        IOAccess((*(reg+instruction.op2_value)+instruction.op3_value),&aux,Write);
                       *comando=(14<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                    }
                }
            }
            if((instruction.op2_type == 'R')&&(instruction.op3_type == 'R'))//STR entre registros
            {
                if(((*(reg+instruction.op2_value)+*(reg+instruction.op3_value))>0x20000000)&&((*(reg+instruction.op2_value)+*(reg+instruction.op3_value))<0x40000000))
                {
                    STRB(*(reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),mem);
                    *comando=(42<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                }
                else
                {
                    aux=*(reg+instruction.op1_value);
                    IOAccess((*(reg+instruction.op2_value)+*(reg+instruction.op3_value)),&aux,Write);
                    *comando=(42<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                }
            }
        }
        if( strcmp(instruction.mnemonic,"STRH") == 0 )
        {
            *(reg+15)=*(reg+15)+1;
            // instruction.op1_value --> Valor primer operando
            // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
            // ... Igual para los otros operandos
            if((instruction.op2_type == 'R')&&(instruction.op3_type == '#'))//STR entre registros e inmediato de 5 bits
            {
                if(instruction.op3_value<32)//Se evalua que el inmediato sea de 5 bits
                {
                    STRH(*(reg+instruction.op1_value),*(reg+instruction.op2_value),instruction.op3_value,mem);
                    *comando=(16<<11)+((31&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
                }
            }
            if((instruction.op2_type == 'R')&&(instruction.op3_type == 'R'))//STR entre registros
            {
                STRH(*(reg+instruction.op1_value),*(reg+instruction.op2_value),*(reg+instruction.op3_value),mem);
                *comando=(41<<9)+((7&(instruction.op3_value))<<6)+((7&(instruction.op2_value))<<3)+(7&(instruction.op1_value));
            }
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
                if(split[0] == '[')
					split++;

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

