#include "SmartMusicPlayer.h"
#include <iostream>
#include <chrono>

// Constructor
SmartMusicPlayer::SmartMusicPlayer(std::shared_ptr<AudioPlayerAbstraction> player)
    : audioPlayer(std::move(player)), playing(false) {}

// Destructor
SmartMusicPlayer::~SmartMusicPlayer() {
    stop();
    if (playThread.joinable()) {
        playThread.join();
    }
}

// Add a song to the playlist
void SmartMusicPlayer::addSong(const Song& song) {
    playlist.addSong(song);
}

// Play the songs in the playlist
void SmartMusicPlayer::play() {
    stop(); // Ensure any previous thread is stopped
    if (playing) return;
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

// Pause the music
void SmartMusicPlayer::pause() {
    std::lock_guard<std::mutex> lock(mtx);
    playing = false;
    currentState = "Paused";
    notify(currentState);
    std::cout << "Player paused." << std::endl;
}

// Stop the music
void SmartMusicPlayer::stop() {
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
