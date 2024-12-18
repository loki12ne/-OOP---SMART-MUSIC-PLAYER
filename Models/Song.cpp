#include "Song.h"
#include <sstream>
#include <iomanip>

// Constructor
Song::Song(const std::string& name, const std::string& type, 
           const std::string& singer, const std::string& album, int time)
    : name(name), type(type), singer(singer), album(album), time(time) {}

// Getter implementations
const std::string& Song::getName() const { return name; }
const std::string& Song::getType() const { return type; }
const std::string& Song::getSinger() const { return singer; }
const std::string& Song::getAlbum() const { return album; }
int Song::getTime() const { return time; }

// Setter implementation
void Song::setTime(int newTime) { time = newTime; }

// Format the time as MM:SS
std::string Song::getTimeFormatted() const {
    int minutes = time / 60;
    int seconds = time % 60;
    std::ostringstream oss;
    oss << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
    return oss.str();
}

// Get detailed song information
std::string Song::getDetails() const {
    return "Name: " + name + ", Type: " + type + ", Singer: " + singer +
           ", Album: " + album + ", Time: " + getTimeFormatted();
}
