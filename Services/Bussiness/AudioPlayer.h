#ifndef _AUDIOPLAYER_SERVICE_H_
#define _AUDIOPLAYER_SERVICE_H_

#include "../../Models/AudioPlayer.h"

class AudioPlayerService {
    std::shared_ptr<AudioPlayerAbstraction> audioPlayer;

public:
    explicit AudioPlayerService(std::shared_ptr<AudioPlayerAbstraction> player) : audioPlayer(std::move(player)) {}

    void playAudio(const std::string& audio) {
        audioPlayer->play(audio);
    }
};

#endif 
