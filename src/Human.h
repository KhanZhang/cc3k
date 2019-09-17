#ifndef CS246A5_Human_H
#define CS246A5_Human_H

#include "Player.h"
class Human : public Player{
public:
    Human(Cell * c);
    Mod get_index(Mod m) override;
    bool special(Subject &whoFrom) override;
};


#endif //CS246A5_Human_H
