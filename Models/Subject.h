#ifndef _SUBJECT_H_
#define _SUBJECT_H_


#include <memory>
#include <vector>
#include <algorithm>  // Cho std::remove


#include "Observer.h"

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void attach(const std::shared_ptr<Observer>& observer) {
        observers.push_back(observer);
    }

    void detach(const std::shared_ptr<Observer>& observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const std::string& state) {
        for (const auto& observer : observers) {
            observer->update(state);
        }
    }
};


#endif