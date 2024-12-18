#include "AudioPlayerService.h"
#include <utility> // For std::move

// Constructor implementation
AudioPlayerService::AudioPlayerService(std::shared_ptr<AudioPlayerAbstraction> player) 
    : audioPlayer(std::move(player)) {}

// Play audio implementation
void AudioPlayerService::playAudio(const std::string& audio) {
    audioPlayer->play(audio);
}
