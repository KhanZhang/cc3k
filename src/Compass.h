#ifndef CS246A5_COMPASS_H
#define CS246A5_COMPASS_H

#include "Pickup.h"
class Compass : public Pickup{
public:
    Compass(Cell * c);
    void notify(Subject &whoFrom) override;
};


#endif
