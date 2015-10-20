#include <stdlib.h>
#include "decoder.h"
#include "curses.h"
#include "funciones.h"
#include "flags.h"
#include "micros.h"
#include "memoria.h"
#include "interrupciones.h"
#include "io.h"

extern uint8_t irq[16];
extern port_t PORTA;
extern port_t PORTB;


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


    initIO();
    uint32_t reg[16],dim=14;
    // Se crea un arreglo para la memoria.
    uint8_t memoria[256];
	// Se crea una variable para mostrar los comandos en hex
    uint16_t comando;
    comando=0;
    char port;


    //Se inicializa la memoria.
    Init_memoria(memoria,256);
    int j,bn=0;
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



    border( ACS_VLINE, ACS_VLINE,
            ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER,
            ACS_LLCORNER, ACS_LRCORNER	);
    refresh();

    while(ch!='s')
    {
        clear();
        move(2,34);
        printw("Emulador Cortex-M0");
        showPorts();
        registro(reg,dim,&banderas);//Muestra los registros y las banderas en pantalla
        move(5,10);
        printw("Presione S para salir");
        move(9,10);
        printw("%s",instructions[reg[15]]);//Imprime la instruccion
        Mostrar_memoria(memoria,256);//Se llama la funcion que muestra la memoria en pantalla.
        move (8,10);
        printw("0x%0.4X",comando);
        move(19,65);
        printw("PC=%u",reg[15]*2);//Imprime el registro
        move(17,75);
        printw("LR=%u                   ",reg[14]*2);//Imprime el registro
        move(19,75);
        printw("SP=%X",reg[13]);
        instruction = getInstruction(instructions[reg[15]]); // Instrucción en la posición reg[15]
        decodeInstruction(instruction,reg,&banderas,memoria,&comando); // Debe ser modificada de acuerdo a cada código
        NVIC(irq,&bn,reg,&banderas,memoria);
        ch=getch();
        if(ch=='a')
        {
            port=getch();
            if(port=='0')
            {
                if((PORTA.Pins&1)==0)
                {
                    changePinPortA(0,HIGH);
                }
                else
                {
                    changePinPortA(0,LOW);
                }
            }
            if(port=='1')
            {
                if((PORTA.Pins&1<<1)==0)
                {
                    changePinPortA(1,HIGH);
                }
                else
                {
                    changePinPortA(1,LOW);
                }
            }
            if(port=='2')
            {
                if((PORTA.Pins&1<<2)==0)
                {
                    changePinPortA(2,HIGH);
                }
                else
                {
                    changePinPortA(2,LOW);
                }
            }
            if(port=='3')
            {
                if((PORTA.Pins&1<<3)==0)
                {
                    changePinPortA(3,HIGH);
                }
                else
                {
                    changePinPortA(3,LOW);
                }
            }
            if(port=='4')
            {
                if((PORTA.Pins&1<<4)==0)
                {
                    changePinPortA(4,HIGH);
                }
                else
                {
                    changePinPortA(4,LOW);
                }
            }
            if(port=='5')
            {
                if((PORTA.Pins&1<<5)==0)
                {
                    changePinPortA(5,HIGH);
                }
                else
                {
                    changePinPortA(5,LOW);
                }
            }
            if(port=='6')
            {
                if((PORTA.Pins&1<<6)==0)
                {
                    changePinPortA(6,HIGH);
                }
                else
                {
                    changePinPortA(6,LOW);
                }
            }

            if(port=='7')
            {
                if((PORTA.Pins&1<<7)==0)
                {
                    changePinPortA(7,HIGH);
                }
                else
                {
                    changePinPortA(7,LOW);
                }
            }
        }
      if(ch=='b')
        {
            port=getch();
            if(port=='0')
            {
                if((PORTB.Pins&1)==0)
                {
                    changePinPortB(0,HIGH);
                }
                else
                {
                    changePinPortB(0,LOW);
                }
            }
            if(port=='1')
            {
                if((PORTB.Pins&1<<1)==0)
                {
                    changePinPortB(1,HIGH);
                }
                else
                {
                    changePinPortB(1,LOW);
                }
            }
            if(port=='2')
            {
                if((PORTB.Pins&1<<2)==0)
                {
                    changePinPortB(2,HIGH);
                }
                else
                {
                    changePinPortB(2,LOW);
                }
            }
            if(port=='3')
            {
                if((PORTB.Pins&1<<3)==0)
                {
                    changePinPortB(3,HIGH);
                }
                else
                {
                    changePinPortB(3,LOW);
                }
            }
            if(port=='4')
            {
                if((PORTB.Pins&1<<4)==0)
                {
                    changePinPortB(4,HIGH);
                }
                else
                {
                    changePinPortB(4,LOW);
                }
            }
            if(port=='5')
            {
                if((PORTB.Pins&1<<5)==0)
                {
                    changePinPortB(5,HIGH);
                }
                else
                {
                    changePinPortB(5,LOW);
                }
            }
            if(port=='6')
            {
                if((PORTB.Pins&1<<6)==0)
                {
                    changePinPortB(6,HIGH);
                }
                else
                {
                    changePinPortB(6,LOW);
                }
            }

            if(port=='7')
            {
                if((PORTB.Pins&1<<7)==0)
                {
                    changePinPortB(7,HIGH);
                }
                else
                {
                    changePinPortB(7,LOW);
                }
            }
        }
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


	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

    endwin();	/* Finaliza el modo curses */




	return 0;
}
