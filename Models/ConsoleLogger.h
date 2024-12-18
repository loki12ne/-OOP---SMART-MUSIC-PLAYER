#ifndef _CONSOLELOGGER_H_
#define _CONSOLELOGGER_H_

#include <iostream>
#include "Observer.h"


class ConsoleLogger : public Observer {
public:
    void update(const std::string& state) override {
        std::cout << "[Logger] Player state changed: " << state << std::endl;
    }
};



#endif