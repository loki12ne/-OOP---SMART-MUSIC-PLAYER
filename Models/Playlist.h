#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_

#include <vector>
#include <memory>

#include "Song.h"

class Playlist {
    std::vector<Song> songs;
public:
    void addSong(const Song& song) {
        songs.push_back(song);
    }

    class Iterator {
        std::vector<Song>::iterator current;
        std::vector<Song>::iterator end;
    public:
        Iterator(std::vector<Song>::iterator start, std::vector<Song>::iterator end) : current(start), end(end) {}
        bool hasNext() const { return current != end; }
        Song next() { return *current++; }
    };

    Iterator getIterator() { return Iterator(songs.begin(), songs.end()); }
};

#endif 
