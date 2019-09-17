#ifndef CS246A5_BASICCELL_H
#define CS246A5_BASICCELL_H

#include "Cell.h"

class BasicCell : public Cell{
public:
    BasicCell(int x, int y, char c);
    void notify_observers() override;

    void cell_attach(Cell * cell) override;
    Cell * cell_detach() override;
    Mod get_cell_mod() override;
    Info get_info() override;
    State get_state() override;
    void set_state(State) override;
    Cell * get_cell() override;
};


#endif //CS246A5_BASICCELL_H
