#pragma once
#include"SFML/Graphics.hpp"
#include<iostream>
using namespace std;
using namespace sf;
namespace UI {
	class UIService {

		Font font;
		Text leftScoreText;
		Text rightScoreText;
		string texture_path = "Assets/Fonts/Aloevera-OVoWO.ttf";

		int fontSize = 40;
		Color Leftside = Color::Yellow;
		Color RightSide = Color::Green;
		string InitalScore = "00";
		float leftScorePosition_X = 840;
		float leftScorePosition_Y = 30;
		float RightScorePosition_X = 920;
		float RightScorePosition_Y = 30;

		int playerOneScore = 0;
		int playerTwoScore = 0;

	private:

		void LoadTextFont();
		void CreateLeftScoreText();
		void CreateRighttScoreText();
		string formatScore(int score);
		
	public:
		void Render(RenderWindow* gameWindow);
		UIService();
		void Upadte();
		void  incrementPlayer1Score();
		void incrementPlayer2Score();
	};
}