#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>

// Observer Pattern: Observer Interface


class Observer {
public:
    virtual void update(const std::string& state) = 0;
    virtual ~Observer() = default;
};

#endif 
