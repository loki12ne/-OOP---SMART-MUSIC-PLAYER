#ifndef _SONG_H_
#define _SONG_H_

#include <string>
#include <sstream>
#include <iomanip>

class Song {
    std::string name;
    std::string type;
    std::string singer;
    std::string album;
    int time; // Thời lượng bài hát, tính bằng giây

public:
    Song(const std::string& name, const std::string& type = "Unknown",
         const std::string& singer = "Unknown", const std::string& album = "Unknown", int time = 0)
        : name(name), type(type), singer(singer), album(album), time(time) {}

    // Getter
    const std::string& getName() const { return name; }
    const std::string& getType() const { return type; }
    const std::string& getSinger() const { return singer; }
    const std::string& getAlbum() const { return album; }
    int getTime() const { return time; }

    // Setter
    void setTime(int newTime) { time = newTime; }

    // Phương thức hiển thị thời lượng bài hát
    std::string getTimeFormatted() const {
        int minutes = time / 60;
        int seconds = time % 60;
        std::ostringstream oss;
        oss << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
        return oss.str();
    }

    // Phương thức hiển thị thông tin bài hát
    std::string getDetails() const {
        return "Name: " + name + ", Type: " + type + ", Singer: " + singer +
               ", Album: " + album + ", Time: " + getTimeFormatted();
    }
};


#endif 
