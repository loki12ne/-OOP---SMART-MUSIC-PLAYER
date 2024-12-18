#include "Playlist.h"

// Playlist implementation
void Playlist::addSong(const Song& song) {
    songs.push_back(song);
}

// Iterator implementation
Playlist::Iterator::Iterator(std::vector<Song>::iterator start, std::vector<Song>::iterator end)
    : current(start), end(end) {}

bool Playlist::Iterator::hasNext() const {
    return current != end;
}

Song Playlist::Iterator::next() {
    return *current++;
}

Playlist::Iterator Playlist::getIterator() {
    return Iterator(songs.begin(), songs.end());
}
