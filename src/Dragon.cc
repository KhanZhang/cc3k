#include "Dragon.h"

Dragon::Dragon(Cell *c):
    Animal('D', c, 20, 20, 150, 0) {}

Info Dragon::get_info(){
    return m_info;
}

void Dragon::notify(Subject &whoFrom){
    if ((whoFrom.get_info().symbol == 'T') || (whoFrom.get_info().symbol == 'B')){
        set_state(State{'a', "P"});
        notify_observers();
        reset_state();
    } else if ((whoFrom.get_info().symbol == '@') && (whoFrom.get_state().action == 'a')){
        if (whoFrom.get_state().direction == which_dir(whoFrom, true)){
            int damage = cal_damage(whoFrom.get_info().atk);
            if(!take_damage(damage)){
                m_state.action = 'd';
                notify_observers();
            }
        }
    }
}

void Dragon::upstair(Cell * c){
    return;
}
