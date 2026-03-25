#include "mi_io.h"

int main() {
    BYTE modo_test;

    /* 1. MODO TEXTO Y LIMPIEZA */
    setvideomode(3);
    clrscr();

    /* Llamada para cumplir la rubrica (sin salida por pantalla) */
    modo_test = getvideomode();

    /* 2. COLORES Y TEXTO (Screenshot: texto_hola.png) */
    textcolor(YELLOW);
    textbackground(BLUE);
    
    gotoxy(10, 5);
    cputchar('H');
    cputchar('o');
    cputchar('l');
    cputchar('a');
    
    /* 3. ASPECTO DEL CURSOR */
    gotoxy(10, 7);
    setcursortype(GRUESO);
    
    getche();
    
    /* 4. MODO GRAFICO: PIXELES (Screenshot: pixeles.png) */
    setvideomode(4);
    pixel(50, 50, 1);
    pixel(60, 60, 2);
    pixel(70, 70, 3);
    
    getche();
    
    /* 5. RECUADROS CONCENTRICOS (Screenshot: recuadros.png) */
    setvideomode(3);
    clrscr();
    dibujar_recuadro(10, 5, 70, 20, YELLOW, BLUE);
    dibujar_recuadro(20, 8, 60, 17, LIGHTGREEN, RED);
    dibujar_recuadro(30, 11, 50, 14, LIGHTCYAN, MAGENTA);
    
    getche();
    
    /* 6. DIBUJOS GRAFICOS COMPLEJOS (Screenshot: graficos.png) */
    dibujos_graficos();
    
    /* 7. ASCII ART (Screenshot: gato.png) */
    ascii_art();
    
    /* RESTAURACION FINAL */
    setvideomode(3);
    setcursortype(NORMAL);
    clrscr();
    
    return 0;
}