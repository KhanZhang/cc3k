#ifndef CS246A5_TROLL_H
#define CS246A5_TROLL_H

#include "Enemy.h"

class Troll : public Enemy{
public:
    Troll(Cell * c);
    bool enemy_feature(Subject &whoFrom) override;
};


#endif //CS246A5_TROLL_H
