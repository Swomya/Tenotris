#include "audiomanager.hpp"
#include <iostream>

AudioManager* AudioManager::instance = nullptr;

AudioManager* AudioManager::getInstance() {
    if (!instance) {
        instance = new AudioManager();
    }
    return instance;
}

AudioManager::AudioManager() : music(nullptr), isMusicPlaying(false) {}

bool AudioManager::initialize() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! Error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

void AudioManager::playMusic(const std::string& filePath) {
    if (music) {
        Mix_FreeMusic(music);
    }

    music = Mix_LoadMUS(filePath.c_str());
    if (!music) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        return;
    }

    Mix_PlayMusic(music, -1);  
    isMusicPlaying = true;
}

void AudioManager::toggleMusic() {
    if (isMusicPlaying) {
        Mix_PauseMusic();
    }
    else {
        Mix_ResumeMusic();
    }
    isMusicPlaying = !isMusicPlaying;
}

void AudioManager::cleanup() {
    if (music) {
        Mix_FreeMusic(music);
        music = nullptr;
    }
    Mix_CloseAudio();
}
