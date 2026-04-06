#include <ncurses.h>

int main() {
    initscr();
    printw("Hola ncurses!");
    refresh();
    getch();
    endwin();
    return 0;
}
