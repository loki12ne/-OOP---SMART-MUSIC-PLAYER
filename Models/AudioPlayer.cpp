#include "AudioPlayer.h"

// AudioPlayerAbstraction implementation
AudioPlayerAbstraction::AudioPlayerAbstraction(std::shared_ptr<AudioPlayerImplementation> impl)
    : implementation(std::move(impl)) {}

// SimpleAudioPlayer implementation
void SimpleAudioPlayer::playAudio(const std::string& audio) {
    std::cout << "Playing audio: " << audio << std::endl;
}

// SmartAudioPlayer implementation
SmartAudioPlayer::SmartAudioPlayer(std::shared_ptr<AudioPlayerImplementation> impl)
    : AudioPlayerAbstraction(std::move(impl)) {}

void SmartAudioPlayer::play(const std::string& audio) {
    implementation->playAudio(audio);
}
