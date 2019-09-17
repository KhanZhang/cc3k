#include "Human.h"

Human::Human(Cell *c):
        Player(c, 30, 10, 140) {}

Mod Human::get_index(Mod m){
    Mod result = m;
    if ((m_info.hp + result.hp_up) > 140){
        result.hp_up = 0;
    }
    return result;
}

bool Human::special(Subject &whoFrom){
    return false;
}