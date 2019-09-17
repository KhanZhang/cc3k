#include "Enemy.h"
Info Enemy::get_info(){
    return m_info;
}

Enemy::Enemy(char symbol, Cell *c, int atk, int def, int hp, int gold):
    Animal(symbol, c, atk, def, hp, gold) {
    m_info = {
    c->get_info().x,
    c->get_info().y,
    symbol,
    atk,
    def,
    hp,
    gold,
    };
    m_info.is_monster = true;
}

void Enemy::notify(Subject &whoFrom){
    if (!enemy_feature(whoFrom)){
        return;
    }
    std::string dir = which_dir(whoFrom, false);
    char act = whoFrom.get_state().action;
    if (whoFrom.get_info().symbol == '@'){
        if (act == 'm'){
            m_state.action = 'a';
            m_state.direction = which_dir(whoFrom, false);
            notify_observers();
            reset_state();
        } else if (act == 'a'){
            if (dir == whoFrom.get_state().direction){
                int damage = cal_damage(whoFrom.get_info().atk);
                if(!take_damage(damage)){
                    set_state(State{'d', dir});
                    //notify_observers();
                    return;
                } else {
                    set_state(State{'s', "n"});
                    notify_observers();
                    return;
                }

            }
        }
    }
}

void Enemy::upstair(Cell * c){
    return;
}

