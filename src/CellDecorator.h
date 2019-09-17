#ifndef CS246A5_CELLDECORATOR_H
#define CS246A5_CELLDECORATOR_H

#include "Cell.h"



class CellDecorator : public Cell {
protected:
    Cell * m_cell = nullptr;
public:
    CellDecorator(int x, int y, char c);
    ~CellDecorator() override;
    Mod get_cell_mod() override;
    void notify_observers() override;

    void cell_attach(Cell * cell) override;
    Cell * cell_detach() override;
    void notify(Subject &whoFrom);
    Info get_info() override;
    Mod get_mod() override;
    void upstair(Cell * c) override;
    State get_state() override;
    void set_state(State) override;
    Cell * get_cell() override;
};


#endif //CS246A5_CELLDECORATOR_H
