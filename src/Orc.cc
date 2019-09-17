#include "Orc.h"

Orc::Orc(Cell *c):
    Player(c, 30, 25, 180) {}

Mod Orc::get_index(Mod m){
    Mod result = m;
    result.gold /= 2;
    if ((m_info.hp + result.hp_up) > 180){
        result.hp_up = 0;
    }
    return result;
}

bool Orc::special(Subject &whoFrom){
    return false;
}