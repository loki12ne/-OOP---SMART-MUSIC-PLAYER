#include "PlaylistService.h"

// Add song to the playlist
void PlaylistService::addSong(const Song& song) {
    playlist.addSong(song);
}

// Get iterator for the playlist
Playlist::Iterator PlaylistService::getIterator() {
    return playlist.getIterator();
}
