#ifndef _PLAYLIST_SERVICE_H_
#define _PLAYLIST_SERVICE_H_

#include "../../Models/Playlist.h"

class PlaylistService {
    Playlist playlist;

public:
    void addSong(const Song& song) {
        playlist.addSong(song);
    }

    Playlist::Iterator getIterator() {
        return playlist.getIterator();
    }
};

#endif // _PLAYLIST_SERVICE_H_