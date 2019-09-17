#ifndef CS246A5_DWARF_H
#define CS246A5_DWARF_H

#include "Player.h"
class Dwarf :public Player{
public:
    Dwarf(Cell * c);
    Mod get_index(Mod m) override;
    bool special(Subject &whoFrom) override;
};


#endif //CS246A5_DWARF_H
