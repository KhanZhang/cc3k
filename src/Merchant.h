#ifndef CS246A5_MERCHANT_H
#define CS246A5_MERCHANT_H

#include "Animal.h"
class Merchant : public Animal{
public:
    void notify(Subject &whoFrom);
    Merchant(Cell * c);
    Info get_info() override;
    void upstair(Cell * c) override;
};


#endif //CS246A5_MERCHANT_H
