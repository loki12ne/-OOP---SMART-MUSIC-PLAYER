#ifndef _CONSOLELOGGER_H_
#define _CONSOLELOGGER_H_

#include <iostream>
#include <string>
#include "Observer.h"

class ConsoleLogger : public Observer {
public:
    void update(const std::string& state) override;
};

#endif
