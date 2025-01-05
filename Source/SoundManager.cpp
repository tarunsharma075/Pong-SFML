#include"../../Header/SoundManager.h"

namespace Sound {

	sf::SoundBuffer SoundManager::ballBounce;
	sf::Sound SoundManager::soundEffect;
	const string SoundManager::ballBouncePath= "Assets/Sounds/Ball_Bounce.wav";
	void SoundManager::Initialize()
	{
		LoadSoundFromFile();
	}

	void SoundManager::LoadSoundFromFile()
	{
		if (!ballBounce.loadFromFile(ballBouncePath)) {
			cout << "Not loaded";
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
		default:
			std::cerr << "Invalid sound type" << std::endl;
			return;
		}

		soundEffect.play();
	}

	void SoundManager::PlayBackgroundMusic()
	{
	}

}