#include <dos.h>
#include "mi_io.h"

/* Coloca el cursor en una posicion determinada (int 10h, ah=2) */
void gotoxy(int x, int y) {
    union REGS inregs, outregs;
    inregs.h.ah = 0x02;
    inregs.h.dh = y;    /* Fila */
    inregs.h.dl = x;    /* Columna */
    inregs.h.bh = 0;    /* Pagina de video 0 */
    int86(0x10, &inregs, &outregs);
}

/* Fija el aspecto del cursor (int 10h, ah=1) */
void setcursortype(int tipo_cursor) {
    union REGS inregs, outregs;
    inregs.h.ah = 0x01;
    switch(tipo_cursor) {
        case INVISIBLE:
            inregs.h.ch = 0x20; /* Bit 5 a 1 hace el cursor invisible */
            inregs.h.cl = 0x00;
            break;
        case NORMAL:
            inregs.h.ch = 0x06;
            inregs.h.cl = 0x07;
            break;
        case GRUESO:
            inregs.h.ch = 0x00;
            inregs.h.cl = 0x07;
            break;
    }
    int86(0x10, &inregs, &outregs);
}

/* Variable global para guardar el color actual (Fondo Negro, Texto Blanco por defecto) */
BYTE color_actual = 0x0F;

/* --- FUNCIONES DE VIDEO --- */
void setvideomode(BYTE modo) {
    union REGS inregs, outregs;
    inregs.h.ah = 0x00;
    inregs.h.al = modo;
    int86(0x10, &inregs, &outregs);
}

BYTE getvideomode() {
    union REGS inregs, outregs;
    inregs.h.ah = 0x0F;
    int86(0x10, &inregs, &outregs);
    return outregs.h.al;
}

/* --- FUNCIONES DE COLOR Y PANTALLA --- */
void textcolor(int color) {
    /* Mantenemos el fondo (los 4 bits altos) y cambiamos el texto (los 4 bits bajos) */
    color_actual = (color_actual & 0xF0) | (color & 0x0F);
}

void textbackground(int color) {
    /* Mantenemos el texto (los 4 bits bajos) y cambiamos el fondo (los 4 bits altos) */
    color_actual = (color_actual & 0x0F) | ((color & 0x0F) << 4);
}

void clrscr() {
    union REGS inregs, outregs;
    inregs.h.ah = 0x06;         /* Scroll hacia arriba / Borrar pantalla */
    inregs.h.al = 0x00;         /* 0 indica borrar toda la region */
    inregs.h.bh = color_actual; /* Rellenar con el color actual */
    inregs.h.ch = 0;            /* Fila inicial (arriba) */
    inregs.h.cl = 0;            /* Columna inicial (izquierda) */
    inregs.h.dh = 24;           /* Fila final (pantalla estandar de 80x25) */
    inregs.h.dl = 79;           /* Columna final */
    int86(0x10, &inregs, &outregs);
    gotoxy(0, 0);               /* Colocamos el cursor arriba a la izquierda */
}

void cputchar(char c) {
    union REGS inregs, outregs;
    inregs.h.ah = 0x09;         /* Funcion para escribir con color */
    inregs.h.al = c;            /* Caracter a imprimir */
    inregs.h.bl = color_actual; /* Atributo de color */
    inregs.h.bh = 0;            /* Pagina de video 0 */
    inregs.x.cx = 1;            /* Numero de repeticiones */
    int86(0x10, &inregs, &outregs);
}

/* --- FUNCIONES DE ENTRADA --- */
int getche() {
    union REGS inregs, outregs;
    inregs.h.ah = 0x01;         /* Leer tecla con eco (int 21h) */
    int86(0x21, &inregs, &outregs);
    return outregs.h.al;
}

/* --- FUNCIONES DE GRAFICOS --- */
void pixel(int x, int y, BYTE C) {
    union REGS inregs, outregs;
    inregs.x.cx = x;
    inregs.x.dx = y;
    inregs.h.al = C;
    inregs.h.ah = 0x0C;
    int86(0x10, &inregs, &outregs);
}
