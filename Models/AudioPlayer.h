#ifndef _AUDIOPLAYER_H_
#define _AUDIOPLAYER_H_

#include <string>
#include <memory>
#include <iostream>

// Bridge Pattern: Abstraction and Implementation
class AudioPlayerImplementation {
public:
    virtual void playAudio(const std::string& audio) = 0;
    virtual ~AudioPlayerImplementation() = default;
};

class AudioPlayerAbstraction {
protected:
    std::shared_ptr<AudioPlayerImplementation> implementation;

public:
    explicit AudioPlayerAbstraction(std::shared_ptr<AudioPlayerImplementation> impl) : implementation(std::move(impl)) {}
    virtual void play(const std::string& audio) = 0;
    virtual ~AudioPlayerAbstraction() = default;
};

class SimpleAudioPlayer : public AudioPlayerImplementation {
public:
    void playAudio(const std::string& audio) override {
        std::cout << "Playing audio: " << audio << std::endl;
    }
};

class SmartAudioPlayer : public AudioPlayerAbstraction {
public:
    explicit SmartAudioPlayer(std::shared_ptr<AudioPlayerImplementation> impl) : AudioPlayerAbstraction(std::move(impl)) {}

    void play(const std::string& audio) override {
        implementation->playAudio(audio);
    }
};

#endif 
