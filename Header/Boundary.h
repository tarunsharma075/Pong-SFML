#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
namespace Boundary {
	class BoundaryManager {
	private:
		RectangleShape horizontalBoundaryTop;
		RectangleShape verticalBoundaryLeft;
		RectangleShape horizontalBoundaryBottom;
		RectangleShape verticalBoundaryRight;
		RectangleShape centerLine;

		const float horizontalBoundaryWidth = 1920.f;
		const float horizontalBoundaryheight = 20.f;

		const float VerticalBoundaryWidth = 20.f;
		const float VerticalBoundaryheight = 1920.f;

		const float topPosition_X = 0.f;
		const float topPosition_Y = 0.f;

		const float leftPosition_x = 0.f;
		const float leftPosition_Y = 0.f;


		/*const float Position_x = 0.f;
		const float leftPosition_Y = 0.f;

		const float leftPosition_x = 0.f;
		const float leftPosition_Y = 0.f;*/
		const Color boundryColor = Color::Red;
		const Color centerLineColor = Color::Blue;

		const float centerLinePosition_x = 900.f;
		const float centerLinePosition_Y = 30.f;
		const float centerLinewidth = 10.f;
		const float cenetrLineHeight = 1080.f;

	public:

		BoundaryManager();
		void Render(RenderWindow* gameWindow);
		void createTopBoundary();
		void createBottomBoundary();
		void createLeftBoundary();
		void createRightBoundary();

		void createCenterLine();

	};
}