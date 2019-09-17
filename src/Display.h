#ifndef CS246A5_DISPLAY_H
#define CS246A5_DISPLAY_H

#include <vector>
#include <iostream>
#include "Observer.h"
#include "Cell.h"

class Cell;

class Display : public Observer {
    std::vector<std::vector<char>> m_display;
    size_t m_h, m_w; // height & width
public:
    Display(size_t h, size_t w);
    void notify(Subject &whoChanged) override;
    friend std::ostream &operator<<(std::ostream &out, const Display &d);
};


#endif //CS246A5_DISPLAY_H
