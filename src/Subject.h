#ifndef CS246A5_SUBJECT_H
#define CS246A5_SUBJECT_H
#include <vector>
#include <string>
#include "Observer.h"

class Observer;

struct Mod{
    int gold = 0;
    int atk_up = 0;
    int def_up = 0;
    int hp_up = 0;
};

struct Info {
    int x = 0;
    int y = 0;
    char symbol;
    int atk = 0;
    int def = 0;
    int hp = 0;
    int gold = 0;
    bool is_monster = false;
    std::string name = "nothing";
};

struct State {
    // there are 6 kinds of actions: 'a' for attack, 's' for still, 'm' for move, 'u'for use, 'd' for die, 'p' for pick
    // up
    char action;
    // there are 9 kinds of directions, including the common 8 directions and a "P" standing for no direction
    std::string direction;
};

class Cell;

class Subject {
protected:
    std::vector<Observer *> observers;
public:
    void attach(Observer *o);
    void set_observers(std::vector<Observer*>);
    virtual void notify_observers() = 0;

    std::vector<Observer *>& get_observers();

    virtual void set_state(State s) = 0;
    virtual void reset_state() = 0;
    virtual State get_state() = 0;
    virtual Info get_info() = 0;
    virtual Mod get_mod() = 0;
};


#endif //CS246A5_SUBJECT_H
