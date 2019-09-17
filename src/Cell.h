#ifndef CS246A5_CELL_H
#define CS246A5_CELL_H

#include "Observer.h"
#include "Subject.h"


class Cell : public Observer, public Subject {
protected:
    bool guarded = false;
    Info m_info;
    State m_state = State{'s', "P"};
public:
    void set_cord(int x, int y);
    Cell(int x, int y, char c);
    Cell(Cell &c);
    std::string which_dir(Subject &whoFrom, bool reverse);


    void reset_state() override;
    virtual Mod get_cell_mod() = 0;

    virtual void cell_attach(Cell * cell) = 0;
    virtual Cell * cell_detach() = 0;
    virtual Cell * get_cell() = 0;
    virtual void upstair(Cell * c) = 0;
    bool is_guarded();
};


#endif
