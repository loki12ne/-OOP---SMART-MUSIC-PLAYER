#ifndef _SMARTMUSICPLAYER_H_
#define _SMARTMUSICPLAYER_H_

#include <atomic>
#include <thread>
#include <mutex>
#include <memory>
#include <string>
#include <vector>

#include "Subject.h"
#include "AudioPlayer.h"
#include "Playlist.h"

class SmartMusicPlayer : public Subject {
    Playlist playlist;
    std::shared_ptr<AudioPlayerAbstraction> audioPlayer;
    std::string currentState;
    std::atomic<bool> playing;
    std::thread playThread;
    std::mutex mtx;

public:
    explicit SmartMusicPlayer(std::shared_ptr<AudioPlayerAbstraction> player);
    ~SmartMusicPlayer();

    void addSong(const Song& song);
    void play();
    void pause();
    void stop();
};

#endif
