#include <iostream>
#include "room.h"
using namespace std;

int main() {
    int width, height;

    cout << "How wide do you want the map? ";
    cin >> width;
    cout << "How tall do you want the map? ";
    cin >> height;
    cout << "Generating map of that size..." << endl;

    vector<Room> rooms;
    Room room = Room(height, width, 1, 1);
    rooms.push_back(room);
    room = Room(2, 4, 1, 1);
    rooms.push_back(room);
    rooms[0].addRoom(room, 3, 3);
    room.addRoom(rooms[0], 2, 2);

    Room* currentRoom = &rooms[0];
    bool running = true;

    while (running) {
        currentRoom->render();
        string input;
        cout << "Input (WASD): ";
        cin >> input;
        currentRoom = currentRoom->handleMovement(input);
    }

    return 0;
}