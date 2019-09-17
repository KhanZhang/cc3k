#include "Werewolf.h"

Werewolf::Werewolf(Cell *c):
        Enemy('V', c, 25, 25, 50, 1) {}

bool Werewolf::enemy_feature(Subject &whoFrom){
    return true;
}