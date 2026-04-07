#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main() {

    int x, y;
    int max_y, max_x;
    int direccion_x, direccion_y;
    int puntuacion;
    int ch;
    
    int pala_izq_y, pala_dch_y;
    int pala_tam = 4;
    int pala_izq_x, pala_dch_x;

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, max_y, max_x);

    clear();
    box(stdscr, 0, 0);

    mvprintw(3, max_x/2 - 8, "PONG CON NCURSES");
    mvprintw(5, max_x/2 - 12, "Autores: INES PRADOS Y DARIO ORTEGA");
    mvprintw(7, max_x/2 - 15, "Controles:");
    mvprintw(8, max_x/2 - 15, "e -> salir del juego");
    mvprintw(9, max_x/2 - 15, "w/s -> mover paleta derecha");
    mvprintw(10, max_x/2 - 18, "Pulsa cualquier tecla para empezar");

    refresh();
    getch();

    while (1) {

        x = max_x / 2;
        y = max_y / 2;
        direccion_x = 1;
        direccion_y = 1;
        puntuacion = 0;
        
        pala_izq_y = max_y / 2 - pala_tam / 2;
        pala_dch_y = max_y / 2 - pala_tam / 2;
        pala_izq_x = 1;
        pala_dch_x = max_x - 2;
        
	nodelay(stdscr, TRUE);
	
        while (1) {

            clear();

            for (int i = 0; i < max_y; i++) {
                mvprintw(i, 0, "|");
                mvprintw(i, max_x - 1, "|");
            }

            mvprintw(0, 3, "Puntos: %d", puntuacion);

            // dibujar pala
            for (int i = 0; i < pala_tam; i++) {
                mvprintw(pala_dch_y + i, pala_dch_x, "|");
            }

            mvprintw(y, x, "o");

            refresh();
            usleep(DELAY);

            // movimiento de la pelota
            x += direccion_x;
            y += direccion_y;

            // rebote superior e inferior
            if (y <= 1 || y >= max_y - 2)
                direccion_y *= -1;

            // rebote izquierda
           if (x <= 1)
            	direccion_x *= -1;

            // rebote pala derecha
            if (x == pala_dch_x - 1 && y >= pala_dch_y && y < pala_dch_y + pala_tam) {
                direccion_x *= -1;
                puntuacion++;
            }

            // fin de partida si pasa pala derecha
            if (x >= max_x - 1)
                break;

            // fin de partida si pulsamos 'e'
            ch = getch();
            if (ch == 'e')
                break;

            // mover pala derecha con w/s
            if (ch == 'w' && pala_dch_y > 1)
                pala_dch_y--;
            if (ch == 's' && pala_dch_y + pala_tam < max_y - 1)
                pala_dch_y++;
        }

        nodelay(stdscr, FALSE);

        clear();
        box(stdscr, 0, 0);

        mvprintw(max_y/2 - 2, max_x/2 - 10, "FIN DE LA PARTIDA");
        mvprintw(max_y/2,     max_x/2 - 8,  "Puntuacion: %d", puntuacion);
        mvprintw(max_y/2 + 2, max_x/2 - 15,
                 "Pulsa 'r' para jugar otra vez");
        mvprintw(max_y/2 + 3, max_x/2 - 10,
                 "Pulsa 'e' para salir");

        refresh();
	do {
            ch = getch(); 
        } while (ch != 'r' && ch != 'e');


        if (ch == 'e')
            break;
    }

    endwin();
    return 0;
}



   

        

            



       
        

