#include"../../Header/SoundManager.h"

namespace Sound {

	sf::SoundBuffer SoundManager::ballBounce;
	sf::Sound SoundManager::soundEffect;
	const string SoundManager::ballBouncePath= "Assets/Sounds/Ball_Bounce.wav";
	sf::Music SoundManager::backGroundMusic;
	const string SoundManager::bgmPath= "Assets/Sounds/Pong_bgm.mp3";
	float SoundManager::backgroundMusicVolume = 50.f;
	const string SoundManager::boundpath = "Assets/Sounds/bound.mp3";
	void SoundManager::Initialize()
	{
		LoadSoundFromFile();
	}

	void SoundManager::LoadSoundFromFile()
	{
		if (!ballBounce.loadFromFile(ballBouncePath)) {
			cout << "Not loaded";
		  }


		if (!backGroundMusic.openFromFile(bgmPath)) {
			cout << "No music";
		}

		if (!!ballBounce.loadFromFile(boundpath)) {
			cout << "No sound";
		}
	}

	SoundManager::SoundManager()
	{
		Initialize();
	}

	SoundManager::~SoundManager()
	{
	}

	void SoundManager::PlaySoundEffect(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BallBounce:
			soundEffect.setBuffer(ballBounce);
			break;

		case SoundType::Bound:
			soundEffect.setBuffer(ballBounce);

		default:
			std::cerr << "Invalid sound type" << std::endl;
			return;
		}

		soundEffect.play();
	}

	void SoundManager::PlayBackgroundMusic()
	{
		backGroundMusic.setVolume(backgroundMusicVolume);
		backGroundMusic.setLoop(true);
		backGroundMusic.play();
	}

}