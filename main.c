#include <stdlib.h>
#include "decoder.h"
#include <curses.h>
#include "funciones.h"
#include "flags.h"
#include "micros.h"

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
    int j;
    // Se inicializan los registros.
        for(j=0;j<=15;j++)
    {
        reg[j]=0;
    }

    j=0;
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

	init_pair(1, COLOR_GREEN, COLOR_BLACK);	/* Pair 1 -> Texto verde
											   fondo Negro */
    init_pair(2,COLOR_WHITE,COLOR_BLACK); //Par para el texto del titulo


	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

    attron(COLOR_PAIR(2));
    move(2,34);
	printw("Emulador Cortex-M0");
	attroff(COLOR_PAIR(2));	/* Deshabilita los colores Pair 2 */

    registro(reg,dim,&banderas);
    while(ch!='q')
    {

        registro(reg,dim,&banderas);//Muestra los registros y las banderas en pantalla
        move(20,55);
        printw("Presione Q para salir");
        ch=getch();// Espera una tecla para continuar
        instruction = getInstruction(instructions[reg[15]]); // Instrucción en la posición reg[15]
        move(9,10);
        printw("%s",instructions[reg[15]]);//Imprime la instruccion
        move(17,55);
        printw("PC=%u",reg[15]*2);//Imprime el registro
        move(17,65);
        printw("LR=%u",reg[14]*2);//Imprime el registro
        decodeInstruction(instruction,reg,&banderas); // Debe ser modificada de acuerdo a cada código
    }

    /* Ejemplo de uso
		Llama la función que separa el mnemonico y los operandos
		Llama la instrucción que decodifica y ejecuta la instrucción
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

	endwin();	/* Finaliza el modo curses */




	return 0;
}
