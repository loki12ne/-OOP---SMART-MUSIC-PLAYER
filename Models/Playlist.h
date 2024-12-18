#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_

#include <vector>
#include "Song.h"

class Playlist {
private:
    std::vector<Song> songs;

public:
    void addSong(const Song& song);

    class Iterator {
        std::vector<Song>::iterator current;
        std::vector<Song>::iterator end;

    public:
        Iterator(std::vector<Song>::iterator start, std::vector<Song>::iterator end);
        bool hasNext() const;
        Song next();
    };

    Iterator getIterator();
};

#endif
