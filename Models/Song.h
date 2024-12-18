#ifndef _SONG_H_
#define _SONG_H_

#include <string>

class Song {
    std::string name;
    std::string type;
    std::string singer;
    std::string album;
    int time; // Thời lượng bài hát, tính bằng giây

public:
    // Constructor
    Song(const std::string& name, const std::string& type = "Unknown",
         const std::string& singer = "Unknown", const std::string& album = "Unknown", int time = 0);

    // Getter
    const std::string& getName() const;
    const std::string& getType() const;
    const std::string& getSinger() const;
    const std::string& getAlbum() const;
    int getTime() const;

    // Setter
    void setTime(int newTime);

    // Phương thức hiển thị thời lượng bài hát
    std::string getTimeFormatted() const;

    // Phương thức hiển thị thông tin bài hát
    std::string getDetails() const;
};

#endif
