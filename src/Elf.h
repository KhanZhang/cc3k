#ifndef CS246A5_ELF_H
#define CS246A5_ELF_H

#include "Player.h"
class Elf : public Player{
public:
    Elf(Cell * c);
    Mod get_index(Mod m) override;
    bool special(Subject &whoFrom) override;
};


#endif //CS246A5_ELF_H
