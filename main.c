#include <stdlib.h>
#include "decoder.h"
#include <curses.h>
#include "funciones.h"
#include "flags.h"
#include "micros.h"
#include "memoria.h"
#include "interrupciones.h"

int main(void)
{

//------- No modificar ------//
		int i, num_instructions;
		char ch;
		ins_t read;
		char** instructions;
		instruction_t instruction;

		num_instructions = readFile("code.txt", &read);
		if(num_instructions==-1)
			return 0;

		if(read.array==NULL)
			return 0;

		instructions = read.array; /* Arreglo con las instrucciones */
	//---------------------------//

    uint32_t reg[16],dim=14;
    // Se crea un arreglo para la memoria.
    uint8_t memoria[256];
	// Se crea una variable para mostrar los comandos en hex
    uint16_t comando;
    comando=0;


    //Se inicializa la memoria.
    Init_memoria(memoria,256);
    int j,bn=0,interrup[32]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // Se inicializan los registros.
        for(j=0;j<=15;j++)
    {
        reg[j]=0;
    }

    j=0;
    reg[13]=256;
    struct flg banderas;

    // Se inicializan las banderas.
    banderas.carry='0';
    banderas.sobreflujo='0';
    banderas.negativo='0';
    banderas.zero='0';


	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */

	init_pair(1, COLOR_WHITE, COLOR_BLACK);	/* Pair 1 -> Texto verde
											   fondo Negro */
    init_pair(2,COLOR_GREEN,COLOR_BLACK); //Par para el texto del titulo


    attron(COLOR_PAIR(1));
    move(2,34);
	printw("Emulador Cortex-M0");
	attroff(COLOR_PAIR(1));	/* Deshabilita los colores Pair 2 */

    registro(reg,dim,&banderas);
    while(ch!='q')
    {
        clear();
        registro(reg,dim,&banderas);//Muestra los registros y las banderas en pantalla
        move(5,10);
        printw("Presione Q para salir");
        Mostrar_memoria(memoria,256);//Se llama la funcion que muestra la memoria en pantalla.
        move(9,10);
        printw("%s",instructions[reg[15]]);//Imprime la instruccion
        move(19,65);
        printw("PC=%u",reg[15]*2);//Imprime el registro
        move(17,75);
        printw("LR=%u",reg[14]*2);//Imprime el registro
        move(19,75);
        printw("SP=%X",reg[13]);
        ch=getch();// Espera una tecla para continuar
        if(ch == 'i')
        {
            interrup[0]=1;
        }
        instruction = getInstruction(instructions[reg[15]]); // Instrucci�n en la posici�n reg[15]
        decodeInstruction(instruction,reg,&banderas,memoria); // Debe ser modificada de acuerdo a cada c�digo
		move (9,30);
        printw("0x%0.4X",comando);
        NVIC(interrup,&bn,reg,&banderas,memoria);
    }

    /* Ejemplo de uso
		Llama la funci�n que separa el mnemonico y los operandos
		Llama la instrucci�n que decodifica y ejecuta la instrucci�n
	*/
	// Esto debe ser ciclico para la lectura de todas las instrucciones, de acuerdo
	// al valor del PC (Program Counter)

    		//------- No modificar ------//
	/* Libera la memoria reservada para las instrucciones */
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}
	free(read.array);
	//---------------------------//


	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

    endwin();	/* Finaliza el modo curses */




	return 0;
}
