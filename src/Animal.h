#ifndef CS246A5_ANIMAL_H
#define CS246A5_ANIMAL_H

#include "BasicCell.h"

class Animal : public BasicCell {
public:
    Animal(char c, Cell * cell, int atk, int def, int hp, int gold);
    State get_state() override;
    int cal_damage(int amount);
    bool take_damage(int amount);
    Mod get_mod() override;
};


#endif
