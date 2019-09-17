#ifndef CS246A5_DRAGON_H
#define CS246A5_DRAGON_H

#include "Animal.h"

class Dragon : public Animal{
public:
    void notify(Subject &whoFrom);
    Dragon(Cell * c);
    Info get_info() override;
    void upstair(Cell * c) override;
};


#endif //CS246A5_DRAGON_H
