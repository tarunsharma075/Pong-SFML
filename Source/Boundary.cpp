#include"../../Header/Boundary.h"
namespace Boundary {
	BoundaryManager::BoundaryManager()
	{
		createTopBoundary();
		createLeftBoundary();
		createCenterLine();
		createBottomBoundary();
		createRightBoundary();
	}
	void BoundaryManager::Render(RenderWindow* gameWindow)
	{
		gameWindow->draw(horizontalBoundaryTop);
		gameWindow->draw(verticalBoundaryLeft);
		gameWindow->draw(centerLine);
		gameWindow->draw(horizontalBoundaryBottom);
		gameWindow->draw(verticalBoundaryRight);
	}
	void BoundaryManager::createTopBoundary()
	{	 
		horizontalBoundaryTop.setSize(Vector2f(horizontalBoundaryWidth,horizontalBoundaryheight));
		horizontalBoundaryTop.setPosition(topPosition_X, topPosition_Y);
		horizontalBoundaryTop.setFillColor(boundryColor);
		
	}
	void BoundaryManager::createBottomBoundary()
	{
		horizontalBoundaryBottom.setSize(Vector2f(horizontalBoundaryWidth, horizontalBoundaryheight));
		horizontalBoundaryBottom.setPosition(0, 1060);
		horizontalBoundaryBottom.setFillColor(boundryColor);
	
	}
	void BoundaryManager::createLeftBoundary()
	{
		verticalBoundaryLeft.setSize(Vector2f(VerticalBoundaryWidth,VerticalBoundaryheight));
		verticalBoundaryLeft.setPosition(leftPosition_x, leftPosition_Y);
		verticalBoundaryLeft.setFillColor(boundryColor);
	}
	void BoundaryManager::createRightBoundary()
	{
		verticalBoundaryRight.setSize(Vector2f(VerticalBoundaryWidth, VerticalBoundaryheight));
		verticalBoundaryRight.setPosition(1900, 0);
		verticalBoundaryRight.setFillColor(boundryColor);
	}
	void BoundaryManager::createCenterLine()
	{
		centerLine.setSize(Vector2f(centerLinewidth,cenetrLineHeight));
		centerLine.setPosition(centerLinePosition_x, centerLinePosition_Y);
		centerLine.setFillColor(centerLineColor);
	}
}