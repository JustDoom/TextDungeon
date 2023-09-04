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

    Room room(height, width, 1, 1);

    while (true) {
        room.render();
        string input;
        cout << "Input (WASD): ";
        cin >> input;
        room.handleMovement(input);
    }
}