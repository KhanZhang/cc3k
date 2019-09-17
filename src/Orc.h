#ifndef CS246A5_ORC_H
#define CS246A5_ORC_H

#include "Player.h"
class Orc : public Player{
public:
    Orc(Cell * c);
    Mod get_index(Mod m) override;
    bool special(Subject &whoFrom) override;
};


#endif
