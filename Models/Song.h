#ifndef _SONG_H_
#define _SONG_H_

#include <string>

class Song {
    std::string title;
public:
    explicit Song(const std::string& title) : title(title) {}
    std::string getTitle() const { return title; }
};

#endif 
