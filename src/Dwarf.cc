#include "Dwarf.h"

Dwarf::Dwarf(Cell *c):
    Player(c, 20, 30, 100) {}

Mod Dwarf::get_index(Mod m){
    Mod result = m;
    result.gold *= 2;
    if ((get_info().hp + result.hp_up) > 100){
        result.hp_up = 0;
    }
    return result;
}

bool Dwarf::special(Subject &whoFrom){
    return false;
}