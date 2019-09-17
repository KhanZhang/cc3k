#include <iostream>
#include <string>
#include "Floor.h"
using namespace std;

int main(int argc, char *argv[]) {
    string cmd;
    char race;

    // First loop to get race info
    cout << "Your race: ";
    while (cin >> cmd) {
        if (cmd == "h" || cmd == "e" || cmd == "d" || cmd == "o") {
            race = cmd.c_str()[0];
            break;
        } else if (cmd == "q") {
            cout << "Bye." << endl;
            return 0;
        } else {
            cout << "Please select your race: ";
        }
    }

    Floor floor(argv[1], race);
    cout << floor;

    while (cin >> cmd) {
        if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
        cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw") {
            floor.move(cmd);
            cout << "Player moved " << cmd;
            //floor.enemy_round();
        } else if (cmd == "u") {
            cin >> cmd;
            floor.use(cmd);
            cout << "Player used potion in the " << cmd;
            //floor.enemy_round();
        } else if (cmd == "a") {
            cin >> cmd;
            floor.attack(cmd);
            cout << "Player attacked " << cmd;
            //floor.enemy_round();
        } else if (cmd == "r") {
            while (cin >> cmd) {
                cout << "Your race: ";
                if (cmd == "h" || cmd == "e" || cmd == "d" || cmd == "o") {
                    race = cmd.c_str()[0];
                } else if (cmd == "q") {
                    cout << "Bye." << endl;
                }
            }

            Floor floor(argv[1], race);
            cout << floor;
        } else if (cmd == "q") {
            return 0;
        }
        cout << floor;
    }

    return 0;
}

