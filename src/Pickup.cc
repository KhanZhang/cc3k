#include "Pickup.h"

Pickup::Pickup(int x, int y, char c, Cell * cell, Mod m):
    BasicCell(x, y, c)
{
    m_mod = m;
}

Info Pickup::get_info(){
    return m_info;
}

State Pickup::get_state(){
    return m_state;
}

Mod Pickup::get_mod(){
    return m_mod;
}

void Pickup::upstair(Cell * c){
    return;
}