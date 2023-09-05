#include "ncurses.h"
#include <unistd.h>
#include "game.h"

using namespace std;

int main() {

    // TODO: Make a player Object so it can support multiple players

    int selectedOption = 0;
    int lastOption;

    initscr();
    noecho();
    timeout(0);
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    while (true) {
        // Print the menu options only when it changes
        if (selectedOption == 0 && selectedOption != lastOption) {
            clear();
            printw("> Play\nSettings\nQuit\n");
        } else if (selectedOption == 1 && selectedOption != lastOption) {
            clear();
            printw("Play\n> Settings\nQuit\n");
        } else if (selectedOption == 2 && selectedOption != lastOption) {
            clear();
            printw("Play\nSettings\n> Quit\n");
        }

        lastOption = selectedOption;

        int ch = getch();
        if (ch != ERR) {
            if (ch == KEY_LEFT || ch == KEY_UP) {
                selectedOption = (selectedOption - 1 + 3) % 3;
            } else if (ch == KEY_RIGHT || ch == KEY_DOWN) {
                selectedOption = (selectedOption + 1) % 3;
            } else if (ch == '\n') {
                clear();
                switch (selectedOption) {
                    case 0:
                        break;
                    case 1:
                        //break;
                    default:
                        clear();
                        printw("Quitting...");
                        refresh();
                        exit(0);
                }
                break;
            } else if (ch == 'q') {
                exit(0);
            }
        }

        usleep(10000); // Prevent insane CPU usage
    }
    endwin();

    Game game;
    game.start();

    return 0;
}