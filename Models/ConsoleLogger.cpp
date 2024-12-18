#include "ConsoleLogger.h"

void ConsoleLogger::update(const std::string& state) {
    std::cout << "[Logger] Player state changed: " << state << std::endl;
}
