#include <iostream>
#include "room.h"
#include "ncurses.h"
#include <unistd.h>

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

    vector<Room> rooms;

    // Add all the rooms
    rooms.emplace_back(5, 5, 1, 1);
    rooms.emplace_back(2, 4, 1, 1);
    rooms.emplace_back(10, 20, 1, 1);

    // Add rooms to rooms
    rooms[0].addRoom(&rooms[1], 3, 3);
    rooms[0].addRoom(&rooms[2], 4, 3);
    rooms[1].addRoom(&rooms[0], 2, 2);

    Room *currentRoom = &rooms[0];
    bool running = true;

    initscr();
    noecho();
    timeout(0);
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    // Main loop
    while (running) {
        currentRoom->render();

        int ch = getch();
        if (ch != ERR) {
            currentRoom = currentRoom->handleMovement(ch);
            if ((ch == 'e' || ch == '\n') && currentRoom->getRooms().contains(array<int, 2>{currentRoom->getX(), currentRoom->getY()})) {
                // Get the room the player attempts to enter
                Room *room = currentRoom->getRooms().at(array<int, 2>{currentRoom->getX(), currentRoom->getY()});
                // Loop through the rooms in the next room to find the exit of the current room
                for (auto &it: room->getRooms()) {
                    if (it.second != currentRoom) {
                        continue;
                    }

                    // Set position in next room to the exit
                    room->setX(it.first[0]);
                    room->setY(it.first[1]);
                    break;
                }
                currentRoom->changed = true;
                currentRoom = room;
            }
        }

        usleep(10000); // Prevent insane CPU usage
    }

    return 0;
}