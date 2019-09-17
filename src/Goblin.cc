#include "Goblin.h"

Goblin::Goblin(Cell *c):
        Enemy('V', c, 25, 25, 50, 1) {}

bool Goblin::enemy_feature(Subject &whoFrom){
    return true;
}