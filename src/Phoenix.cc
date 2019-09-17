#include "Phoenix.h"

Phoenix::Phoenix(Cell *c):
        Enemy('V', c, 25, 25, 50, 1) {}

bool Phoenix::enemy_feature(Subject &whoFrom){
    return true;
}