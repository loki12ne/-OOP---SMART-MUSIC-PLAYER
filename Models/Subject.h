#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <memory>
#include <vector>
#include <string>
#include "Observer.h"

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void attach(const std::shared_ptr<Observer>& observer);
    void detach(const std::shared_ptr<Observer>& observer);
    void notify(const std::string& state);
};

#endif
