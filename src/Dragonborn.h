#ifndef CS246A5_DRAGONBORN_H
#define CS246A5_DRAGONBORN_H

#include "Player.h"
class Dragonborn : public Player{
public:
    Dragonborn(Cell * c);
    Mod get_index(Mod m) override;
    bool special(Subject &whoFrom) override;
};


#endif
