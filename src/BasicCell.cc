#include "BasicCell.h"

BasicCell::BasicCell(int x, int y, char c): Cell(x, y, c) {}

void BasicCell::notify_observers() {
    for (auto &ob : observers) ob->notify(*this);
}

void BasicCell::cell_attach(Cell *cell){
}

Cell * BasicCell::cell_detach() {
    return nullptr;
}

Mod BasicCell::get_cell_mod(){
    return Mod{0, 0, 0, 0};
}

Info BasicCell::get_info(){
    return m_info;
}

State BasicCell::get_state(){
    return m_state;
}

void BasicCell::set_state(State s){
    m_state = s;
}

Cell * BasicCell::get_cell(){
    return this;
}