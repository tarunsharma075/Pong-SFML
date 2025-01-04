#include"../../Header/UIService.h"
namespace UI {
	void UIService::LoadTextFont()
	{
		font.loadFromFile(texture_path);
	}
	void UIService::CreateLeftScoreText()
	{
		leftScoreText.setFont(font);
		leftScoreText.setString(InitalScore);
		leftScoreText.setCharacterSize(fontSize);
		leftScoreText.setFillColor(Leftside);
		leftScoreText.setPosition(leftScorePosition_X, leftScorePosition_Y);
	}
	void UIService::CreateRighttScoreText()
	{
		rightScoreText.setFont(font);
		rightScoreText.setString(InitalScore);
		rightScoreText.setCharacterSize(fontSize);
		rightScoreText.setFillColor(RightSide);
		rightScoreText.setPosition(RightScorePosition_X, RightScorePosition_Y);
	}
	void UIService::Render(RenderWindow* gameWindow)
	{
		gameWindow->draw(leftScoreText);
		gameWindow->draw(rightScoreText);
	}
	UIService::UIService()
	{
		LoadTextFont();
		CreateLeftScoreText();
		CreateRighttScoreText();
	}
}