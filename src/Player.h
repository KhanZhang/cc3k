#ifndef CS246A5_PLAYER_H
#define CS246A5_PLAYER_H

#include "Animal.h"
#include <vector>

class Player : public Animal{
    bool wanted_by_merchant = false;
    bool own_barrier = false;
    void attacked(Subject &whoFrom);
    Mod potion = {0, 0, 0, 0};
    void remove_potions();
protected:
    virtual bool special(Subject &whoFrom) = 0;
public:
    Player(Cell * c, int atk, int def, int hp);
    void notify(Subject &whoFrom) override;
    Info get_info() override;
    virtual Mod get_index(Mod m) = 0;
    void upstair(Cell * c) override;
};


#endif //CS246A5_PLAYER_H
