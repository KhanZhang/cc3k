#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal(char c, Cell * cell, int atk, int def, int hp, int gold):
    BasicCell(cell->get_info().x, cell->get_info().y, c)
{
    m_info.atk = atk;
    m_info.def = def;
    m_info.hp = hp;
    m_info.gold = gold;
}


State Animal::get_state(){
    return m_state;
}

int Animal::cal_damage(int amount){
    return (100 * amount) / (100 + get_info().def);
}

bool Animal::take_damage(int amount){
    m_info.hp -= amount;
    if (m_info.hp <= 0){
        m_info.hp = 0;
        return false;
    } else {
        return true;
    }
}

Mod Animal::get_mod(){
    return Mod{0, 0, 0, 0};
}