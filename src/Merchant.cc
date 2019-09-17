#include "Merchant.h"

Merchant::Merchant(Cell *c):
        Animal('M', c, 70, 5, 30, 0) {}

Info Merchant::get_info(){
    return m_info;
}

void Merchant::notify(Subject &whoFrom){
    if (whoFrom.get_info().symbol == '@'){
        notify_observers();
    }
}

void Merchant::upstair(Cell * c){
    return;
}