#include "SmartMusicPlayerService.h"

// Constructor implementation
SmartMusicPlayerService::SmartMusicPlayerService(std::shared_ptr<SmartMusicPlayer> player)
    : player(std::move(player)) {}

// Play music
void SmartMusicPlayerService::play() {
    player->play();
}

// Pause music
void SmartMusicPlayerService::pause() {
    player->pause();
}

// Stop music
void SmartMusicPlayerService::stop() {
    player->stop();
}

// Add song to the playlist
void SmartMusicPlayerService::addSongToPlaylist(const std::string& title) {
    player->addSong(Song(title));
}
