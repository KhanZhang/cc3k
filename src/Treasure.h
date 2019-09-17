#ifndef CS246A5_TREASURE_H
#define CS246A5_TREASURE_H

#include "Pickup.h"

class Treasure : public Pickup{
public:
    Treasure(Cell * c, int g);
    void notify(Subject &whoFrom) override;
};


#endif
