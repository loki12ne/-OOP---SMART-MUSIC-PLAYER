#include <memory>
#include <thread>

// #include "Services/Bussiness/AudioPlayer.h"
#include "Services/Bussiness/SmartMusicPlayerService.h"
#include "Services/Factory.h"
#include "Services/DataAccess/IDao.h"

void config() {
    Factory::instance();

}

int main() {
    config();

    auto factory = Factory::instance();
    auto logger = factory->getService<Observer>();
    
    auto audioImpl = std::make_shared<SimpleAudioPlayer>();
    SmartMusicPlayer player(std::make_shared<SmartAudioPlayer>(audioImpl));

    player.attach(logger);

    shared_ptr<IDao> dao = dynamic_pointer_cast<IDao>(
        factory->getService<IDao>()
    );

    auto song = dao->getAll();
    player.loadSong(song);

    player.play();
    std::this_thread::sleep_for(std::chrono::seconds(7));

    player.play();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    player.pause();

    player.play();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    player.stop();

    return 0;
}
