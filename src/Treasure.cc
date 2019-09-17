#include "Treasure.h"

Treasure::Treasure(Cell *c, int g):
        Pickup(c->get_info().x, c->get_info().y, 'G', c, Mod{g, 0, 0, 0}){
    if (g >= 6){
        guarded = true;
    }
}


void Treasure::notify(Subject &whoFrom){
    if(whoFrom.get_info().symbol == '@'){
        if(guarded){
            notify_observers();
        } else if (whoFrom.get_state().action == 'u'){
            set_state(State{'u', which_dir(whoFrom, false)});
            notify_observers();
            reset_state();
        }
    } else if (whoFrom.get_info().symbol == 'D'){
        if (whoFrom.get_state().action == 'd'){
            guarded = false;
        }
    }
}