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