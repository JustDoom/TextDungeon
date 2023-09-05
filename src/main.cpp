#include <iostream>
#include "room.h"
#include "ncurses.h"
using namespace std;

int main() {

    // TODO: Make a player Object so it can support multiple players

    {
        cout << "Play" << endl;
        cout << "Settings" << endl;
        cout << "Exit" << endl;

        initscr();          // Initialize ncurses
        raw();              // Disable line buffering
        keypad(stdscr, TRUE); // Enable special keys (e.g., arrow keys)
        noecho();           // Don't echo user input
        nodelay(stdscr, TRUE); // Enable non-blocking input

        int ch;
        while (1) {
            ch = getch(); // Get a character (non-blocking)

            if (ch == 'q' || ch == 'Q')
                break; // Exit on 'q' or 'Q'

            if (ch != ERR) {
                // Handle other keys here
                mvprintw(0, 0, "You pressed: %c", ch);
                refresh(); // Refresh the screen
            } else {
                // No key was pressed, you can do other tasks here
            }
        }

        // Cleanup and exit
        endwin(); // Cleanup ncurses
    }

    vector<Room> rooms;

    // Add all the rooms
    rooms.emplace_back(5, 5, 1, 1);
    rooms.emplace_back(2, 4, 1, 1);
    rooms.emplace_back(10, 20, 1, 1);

    // Add rooms to rooms
    rooms[0].addRoom(&rooms[1], 3, 3);
    rooms[0].addRoom(&rooms[2], 4,3);
    rooms[1].addRoom(&rooms[0], 2, 2);

    Room* currentRoom = &rooms[0];
    bool running = true;

    // Main loop
    while (running) {
        currentRoom->render();
        string input;
        cout << "\rInput (WASD): ";
        cin >> input;
        currentRoom = currentRoom->handleMovement(input);
    }

    return 0;
}