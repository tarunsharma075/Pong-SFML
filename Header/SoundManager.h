#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include<iostream>
using namespace std;
namespace Sound {

    enum SoundType {
        BallBounce
    };

    class SoundManager {
    private:
        static sf::Music backGroundMusic;
        static sf::Sound soundEffect;
        static sf::SoundBuffer ballBounce;

        static float backgroundMusicVolume;
        static const std::string bgmPath;
        static const std::string ballBouncePath;

        static void LoadSoundFromFile(); // Should be static since it operates on static members.

    public:
        SoundManager();
        ~SoundManager();

        void Initialize(); // Should not be private since it is a helper function.

        static void PlaySoundEffect(SoundType soundType);
        static void PlayBackgroundMusic();
    };
}
