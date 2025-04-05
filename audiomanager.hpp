#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SDL_mixer.h>
#include <string>

class AudioManager {
public:
    static AudioManager* getInstance();

    bool initialize();
    void playMusic(const std::string& filePath);
    void toggleMusic();
    void cleanup();

private:
    AudioManager();
    static AudioManager* instance;
    Mix_Music* music;
    bool isMusicPlaying;
};

#endif
