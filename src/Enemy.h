#ifndef CS246A5_ENEMY_H
#define CS246A5_ENEMY_H

#include "Animal.h"
class Enemy : public Animal{
public:
    Enemy(char symbol, Cell * c, int atk, int def, int hp, int gold);
    void notify(Subject &whoFrom) override;
    virtual bool enemy_feature(Subject &whoFrom) = 0;
    Info get_info() override;
    void upstair(Cell * c) override;
};


#endif //CS246A5_ENEMY_H
