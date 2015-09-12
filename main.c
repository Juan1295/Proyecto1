#include <stdlib.h>
#include "colors.h"
#include "flags.h"
#include "curses.h"

int main(void)
{

    uint32_t reg[12],dim=12;
    int i;
    // Se inicializan los registros.
        for(i=0;i<12;i++)
    {
        reg[i]=0;
    }

    struct flg banderas;
    // Se inicializan las banderas.

    banderas.carry=0;
    banderas.sobreflujo=0;
    banderas.negativo=0;
    banderas.zero=0;


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
	printw("Emulador Corte M0");
	attroff(COLOR_PAIR(2));	/* DEshabilita los colores Pair 2 */

	registro(reg,dim,&banderas);

	getch();	/* Espera entrada del usuario */

    move(9,10);
	printw("MOVS R0,#36");
	refresh();
	getch();
	MOV(&reg[0],36,&banderas);
	registro(reg,dim,&banderas);
	getch();
	move(9,10);
	printw("MOVS R1,#6 ");
	getch();
	MOV(&reg[1],6,&banderas);
	registro(reg,dim,&banderas);
	getch();
	move(9,10);
	printw("MOVS R2,R0 ");
	getch();
	MOV(&reg[2],reg[0],&banderas);
	registro(reg,dim,&banderas);
	getch();
    move(9,10);
	printw("MOVS R3,1 ");
	getch();
	MOV(&reg[3],1,&banderas);
	registro(reg,dim,&banderas);
	getch();
    move(9,10);
	printw("LSLS R3,R3,#31 ");
	getch();
	LSL(&reg[3],31,&banderas);
	registro(reg,dim,&banderas);
	getch();
	move(9,10);
	printw("MOVS R0,#R0 ");
	getch();
	MOV(&reg[0],reg[0],&banderas);
	registro(reg,dim,&banderas);
	getch();
    move(9,10);
	printw("MOVS R4,#0 ");
	getch();
	MOV(&reg[4],0,&banderas);
	registro(reg,dim,&banderas);
	getch();
    move(9,10);
	printw("Function loop ");
	getch();
    move(9,10);
	printw("LSLS R3,R3,#31 ");
	getch();
	LSL(&reg[2],1,&banderas);
	registro(reg,dim,&banderas);
	getch();
    move(9,10);
	printw("ADCS R4,R4,R4 ");
	getch();
	ADD(&reg[4],reg[4],reg[4],&banderas);
	registro(reg,dim,&banderas);
	getch();
    move(9,10);
	printw("CMP R4,R1   ");
	getch();
	CMP(reg[4],reg[1],&banderas);
	registro(reg,dim,&banderas);
	getch();

	endwin();	/* Finaliza el modo curses */

	return 0;
}
