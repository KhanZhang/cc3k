#ifndef CS246A5_PICKUP_H
#define CS246A5_PICKUP_H

#include "BasicCell.h"


class Pickup : public BasicCell {
    Mod m_mod = {0, 0, 0, 0};
public:
    //Mod get_index(Mod m) override;
    Pickup(int x, int y, char c, Cell * cell, Mod m);
    Info get_info() override;
    State get_state() override;
    Mod get_mod() override;
    void upstair(Cell * c) override;
};


#endif //CS246A5_PICKUP_H
