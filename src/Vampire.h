#ifndef CS246A5_VAMPIRE_H
#define CS246A5_VAMPIRE_H

#include "Enemy.h"
class Vampire : public Enemy{
public:
    Vampire(Cell * c);
    bool enemy_feature(Subject &whoFrom) override;
};


#endif //CS246A5_VAMPIRE_H
