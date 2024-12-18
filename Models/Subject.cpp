#include "Subject.h"
#include <algorithm> // std::remove

// Attach an observer
void Subject::attach(const std::shared_ptr<Observer>& observer) {
    observers.push_back(observer);
}

// Detach an observer
void Subject::detach(const std::shared_ptr<Observer>& observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

// Notify all observers of a state change
void Subject::notify(const std::string& state) {
    for (const auto& observer : observers) {
        observer->update(state);
    }
}
