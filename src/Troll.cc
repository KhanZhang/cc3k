#include "Troll.h"

Troll::Troll(Cell *c):
    Enemy('T', c, 25, 15, 120, 1) {}

bool Troll::enemy_feature(Subject &whoFrom){
    return true;
}