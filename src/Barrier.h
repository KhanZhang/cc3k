#ifndef CS246A5_BARRIER_H
#define CS246A5_BARRIER_H

#include "Pickup.h"
class Barrier : public Pickup{

public:
    Barrier(Cell * c);
    void notify(Subject &whoFrom) override;
};


#endif //CS246A5_BARRIER_H
