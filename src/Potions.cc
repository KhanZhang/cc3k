#include "Potions.h"
#include <iostream>

Potions::Potions(Mod m, Cell * c, std::string name):
    Pickup(c->get_info().x, c->get_info().y, 'P', c, m) {
    m_info.name = name;
}

void Potions::notify(Subject &whoFrom){
    if (whoFrom.get_info().symbol != '@'){
        return;
    }
    if (whoFrom.get_state().action == 'u'){
        if (whoFrom.get_state().direction == which_dir(whoFrom, false)){
            set_state(State{'u', "P"});
            notify_observers();
            reset_state();
        }
    }
}