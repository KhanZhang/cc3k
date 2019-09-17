#include "CellDecorator.h"

CellDecorator::CellDecorator(int x, int y, char c):
    Cell(x, y, c) {}

CellDecorator::~CellDecorator(){
    delete m_cell;
}

void CellDecorator::cell_attach(Cell * cell) {
    m_cell = cell;
    m_cell->set_cord(m_info.x, m_info.y);
    m_cell->set_observers(observers);
}

Cell * CellDecorator::cell_detach(){
    Cell * inner_cell = m_cell;
    m_cell = nullptr;
    return inner_cell;
}

Mod CellDecorator::get_cell_mod(){
    return m_cell->get_mod();
}

void CellDecorator::notify(Subject &whoFrom){
    if (m_cell == nullptr){
        return;
    } else {
        m_cell->notify(whoFrom);
    }
}

void CellDecorator::notify_observers() {
    if (m_cell == nullptr) {
        for (auto &ob : observers) ob->notify(*this);
    } else {
        m_cell->notify_observers();
    }
}

Cell * CellDecorator::get_cell(){
    return m_cell;
}

Info CellDecorator::get_info(){
    if (m_cell == nullptr){
        return m_info;
    } else {
        return m_cell->get_info();
    }
}

Mod CellDecorator::get_mod(){
    return m_cell->get_mod();
}

void CellDecorator::upstair(Cell *c){
    m_cell->upstair(c);
}

State CellDecorator::get_state(){
    if (m_cell == nullptr){
        return m_state;
    } else {
        return m_cell->get_state();
    }

}

void CellDecorator::set_state(State s){
    if (m_cell == nullptr){
        m_state = s;
    } else {
        m_state = s;
        m_cell->set_state(s);
    }
}