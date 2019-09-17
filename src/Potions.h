#ifndef CS246A5_POTIONS_H
#define CS246A5_POTIONS_H

#include <string>

#include "Pickup.h"
class Potions : public Pickup{
public:
    Potions(Mod m, Cell * c, std::string name);
    void notify(Subject &whoFrom) override;
};


#endif
