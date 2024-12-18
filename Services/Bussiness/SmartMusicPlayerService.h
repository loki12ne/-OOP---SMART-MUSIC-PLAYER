#ifndef _SMARTMUSICPLAYER_SERVICE_H_
#define _SMARTMUSICPLAYER_SERVICE_H_

#include <memory>
#include <string>
#include "../../Models/SmartMusicPlayer.h"

class SmartMusicPlayerService {
    std::shared_ptr<SmartMusicPlayer> player;

public:
    explicit SmartMusicPlayerService(std::shared_ptr<SmartMusicPlayer> player) : player(std::move(player)) {}

    void play() {
        player->play();
    }

    void pause() {
        player->pause();
    }

    void stop() {
        player->stop();
    }

    void addSongToPlaylist(const std::string& title) {
        player->addSong(Song(title));
    }
};

#endif 
