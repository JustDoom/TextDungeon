#include <iostream>
#include "room.h"
using namespace std;

int main() {

    vector<Room> rooms;

    // Add all the rooms
    rooms.push_back(Room(5, 5, 1, 1));
    rooms.push_back(Room(2, 4, 1, 1));

    // Add rooms to rooms
    rooms[0].addRoom(&rooms[1], 3, 3);
    rooms[1].addRoom(&rooms[0], 2, 2);

    Room* currentRoom = &rooms[0];
    bool running = true;

    while (running) {
        currentRoom->render();
        string input;
        cout << "\rInput (WASD): ";
        cin >> input;
        currentRoom = currentRoom->handleMovement(input);
    }

    return 0;
}