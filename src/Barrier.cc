#include "Barrier.h"

Barrier::Barrier(Cell *c):
    Pickup(c->get_info().x, c->get_info().y, 'P', c, Mod{0, 0, 0, 0}) {
    guarded = true;
}

void Barrier::notify(Subject &whoFrom){
    if (whoFrom.get_info().symbol == '@'){
        if (whoFrom.get_state().action == 'p'){
            set_state(State{'p', which_dir(whoFrom, false)});
            notify_observers();
        } else if (guarded){
            notify_observers();
        }
    } else if (whoFrom.get_info().symbol == 'D'){
        if (whoFrom.get_state().action == 'd'){
            guarded = false;
        }
    }
}

