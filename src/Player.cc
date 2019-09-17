#include "Player.h"

Player::Player(Cell *c, int atk, int def, int hp):
    Animal('@', c, atk, def, hp, 0) {}

void Player::notify(Subject &whoFrom){
    if (special(whoFrom)){
        return;
    }
    char tar = whoFrom.get_info().symbol;
    char act = whoFrom.get_state().action;
    std::string mydir = which_dir(whoFrom, true);
    std::string actdir = whoFrom.get_state().direction;
    if (tar == 'M'){
        if (wanted_by_merchant){
            attacked(whoFrom);
        }
        return;
    } else if (tar == 'D'){
        attacked(whoFrom);
    }
    /*
    if (mydir != actdir){
        return;
    }
     */
    if (act == 'd'){
        m_info.gold += whoFrom.get_info().gold;
        if (tar == 'M'){
            wanted_by_merchant = true;
        }
    } else if (act == 'a'){
        attacked(whoFrom);
    } else if (act == 'p'){
        if (tar == 'B'){
            own_barrier = true;
        }
    } else if (act == 'u'){
        m_info.hp += get_index(whoFrom.get_mod()).hp_up;
        potion.atk_up += get_index(whoFrom.get_mod()).atk_up;
        potion.def_up += get_index(whoFrom.get_mod()).def_up;
        m_info.gold += get_index(whoFrom.get_mod()).gold;
    } else if (act == 'm'){
        attacked(whoFrom);
    }
}

void  Player::attacked(Subject &whoFrom){
    int damage = cal_damage(whoFrom.get_info().atk);
    if (own_barrier){
        damage /= 2;
    }
    if(!take_damage(damage)){
        m_state.action = 'd';
        m_state.direction = which_dir(whoFrom, false);
        notify_observers();
    }
    set_state(State{'s', "n"});
    notify_observers();
    reset_state();
}

Info Player::get_info(){
    Info result = m_info;
    Mod md = potion;
    result.atk += md.atk_up;
    result.def += md.def_up;
    return result;
}

void Player::remove_potions(){
    potion = Mod{0, 0, 0, 0};
}

void Player::upstair(Cell * c){
    remove_potions();
    c->cell_attach(this);
}
