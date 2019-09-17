#include "Elf.h"
#include <cmath>

Elf::Elf(Cell *c):
        Player(c, 30, 10, 140) {}

Mod Elf::get_index(Mod m){
    Mod result = m;
    result.def_up = abs(m.def_up);
    result.atk_up = abs(m.atk_up);
    result.hp_up = abs(m.hp_up);
    if ((m_info.hp + result.hp_up) > 140){
        result.hp_up = 0;
    }
    return result;
}

bool Elf::special(Subject &whoFrom){
    return false;
}