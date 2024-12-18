#ifndef _SMARTMUSICPLAYER_SERVICE_H_
#define _SMARTMUSICPLAYER_SERVICE_H_

#include <memory>
#include <string>
#include "../../Models/SmartMusicPlayer.h"

class SmartMusicPlayerService {
private:
    std::shared_ptr<SmartMusicPlayer> player;

public:
    explicit SmartMusicPlayerService(std::shared_ptr<SmartMusicPlayer> player);

    void play();
    void pause();
    void stop();
    void addSongToPlaylist(const std::string& title);
};

#endif
