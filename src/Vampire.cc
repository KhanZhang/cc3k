#include "Vampire.h"

Vampire::Vampire(Cell *c):
        Enemy('V', c, 25, 25, 50, 1) {}

bool Vampire::enemy_feature(Subject &whoFrom){
    return true;
}