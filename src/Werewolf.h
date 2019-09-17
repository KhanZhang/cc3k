#ifndef CS246A5_WEREWOLF_H
#define CS246A5_WEREWOLF_H

#include "Enemy.h"
class Werewolf :public Enemy{
public:
    Werewolf(Cell * c);
    bool enemy_feature(Subject &whoFrom) override;
};


#endif //CS246A5_WEREWOLF_H
