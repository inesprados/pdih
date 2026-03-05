#include <stdio.h>
#include <dos.h>

#define BYTE unsigned char

/* Funcion para cambiar el modo de video usando la interrupcion 10h */
void selecciona_modo_video(BYTE modo) {
    union REGS inregs, outregs;
    inregs.h.ah = 0x00;
    inregs.h.al = modo;
    int86(0x10, &inregs, &outregs);
}

/* Funcion para pausar esperando una tecla usando interrupcion 21h */
int mi_getchar() {
    union REGS inregs, outregs;
    inregs.h.ah = 1;
    int86(0x21, &inregs, &outregs);
    return outregs.h.al;
}

int main() {
    printf("Modo texto normal. Pulsa una tecla para pasar a modo grafico...\n");
    mi_getchar();

    /* Pasamos a Modo Grafico CGA (Modo 4) */
    selecciona_modo_video(4); 
    
    /* En modo grafico las letras normales no se ven bien, solo esperamos */
    mi_getchar(); 

    /* Volvemos a Modo Texto normal (Modo 3) */
    selecciona_modo_video(3); 
    printf("De vuelta al modo texto. Compilacion exitosa!\n");

    return 0;
}
