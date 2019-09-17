#include "Compass.h"

Compass::Compass(Cell * c):
        Pickup(c->get_info().x, c->get_info().y, 'P', c, Mod{0, 0, 0, 0}) {}

void Compass::notify(Subject &whoFrom){
    if ((whoFrom.get_info().symbol == '@') && (whoFrom.get_state().action == 'p')){
        if (whoFrom.get_state().direction == which_dir(whoFrom, true)){
            set_state(State{'u', "P"});
            notify_observers();
            reset_state();
        }
    }
}