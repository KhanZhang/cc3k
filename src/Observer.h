#ifndef CS246A5_OBSERVER_H
#define CS246A5_OBSERVER_H

class Subject;

class Observer {
public:
    virtual void notify(Subject &whoFrom) = 0; // pass the Subject that called the notify method
    virtual ~Observer() = default;
};


#endif //CS246A5_OBSERVER_H

