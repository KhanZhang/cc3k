#include "Dragonborn.h"

Dragonborn::Dragonborn(Cell *c):
        Player(c, 666, 233, 111) {}

Mod Dragonborn::get_index(Mod m){
    return m;
}

bool Dragonborn::special(Subject &whoFrom){
    return false;
}