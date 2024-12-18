// #include <iostream>
// #include <vector>
// #include <memory>
// #include <string>
// #include <algorithm>
// #include <unordered_map>
// #include <functional>
// #include <mutex>
// #include <thread>
// #include <atomic>
// #include <chrono>


#include <memory>
#include <thread>

#include "Models/ConsoleLogger.h"
#include "Services/Bussiness/AudioPlayer.h"
#include "Services/Bussiness/SmartMusicPlayerService.h"


// Example Observer


int main() {
    auto logger = std::make_shared<ConsoleLogger>();
    auto audioImpl = std::make_shared<SimpleAudioPlayer>();
    SmartMusicPlayer player(std::make_shared<SmartAudioPlayer>(audioImpl));

    player.attach(logger);

    player.addSong(Song("Song 1"));
    player.addSong(Song("Song 2"));
    player.addSong(Song("Song 3"));

    player.play();
    std::this_thread::sleep_for(std::chrono::seconds(10));

    player.play();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    player.pause();

    player.play();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    player.stop();

    return 0;
}
