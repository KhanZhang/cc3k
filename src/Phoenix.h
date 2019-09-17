#ifndef CS246A5_PHOENIX_H
#define CS246A5_PHOENIX_H

#include "Enemy.h"

class Phoenix : public Enemy{
public:
    Phoenix(Cell * c);
    bool enemy_feature(Subject &whoFrom) override;
};


#endif //CS246A5_PHOENIX_H
