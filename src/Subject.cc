#include "Subject.h"

void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::set_observers(std::vector<Observer *> obs) {
    observers.clear();
    observers = obs;
}



std::vector<Observer *>& Subject::get_observers(){
    return observers;
}