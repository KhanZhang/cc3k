#ifndef CS246A5_Goblin_H
#define CS246A5_Goblin_H

#include "Enemy.h"
class Goblin : public Enemy{
public:
    Goblin(Cell * c);
    bool enemy_feature(Subject &whoFrom) override;
};


#endif //CS246A5_Goblin_H
