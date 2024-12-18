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

// SmartMusicPlayer integrates Observer, Bridge, and Iterator

class SmartMusicPlayer : public Subject {
    Playlist playlist;
    std::shared_ptr<AudioPlayerAbstraction> audioPlayer;
    std::string currentState;
    std::atomic<bool> playing;
    std::thread playThread;
    std::mutex mtx;

public:
    explicit SmartMusicPlayer(std::shared_ptr<AudioPlayerAbstraction> player) : audioPlayer(std::move(player)), playing(false) {}

    ~SmartMusicPlayer() {
        stop();
        if (playThread.joinable()) {
            playThread.join();
        }
    }

    void addSong(const Song& song) {
        playlist.addSong(song);
    }

    void play() {
    stop();  // Đảm bảo dừng luồng trước đó
    if (playing) return;
   // stop();
    playing = true;

    playThread = std::thread([this]() {
        auto iterator = playlist.getIterator();
        while (iterator.hasNext() && playing) {
            auto song = iterator.next();
            {
                std::lock_guard<std::mutex> lock(mtx);
                currentState = "Playing: " + song.getDetails();
                notify(currentState);
            }
            audioPlayer->play(song.getName());
            std::this_thread::sleep_for(std::chrono::seconds(song.getTime()));
        }
    });

    }

    void pause() {
        std::lock_guard<std::mutex> lock(mtx);
        playing = false;
        currentState = "Paused";
        notify(currentState);
        std::cout << "Player paused." << std::endl;
    }

    void stop() {
        {
            std::lock_guard<std::mutex> lock(mtx);
            playing = false;
            currentState = "Stopped";
            notify(currentState);
        }
        if (playThread.joinable()) {
            playThread.join();
        }
    }
};

#endif 
