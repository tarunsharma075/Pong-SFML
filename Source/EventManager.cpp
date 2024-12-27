#include"../../Header/EventManager.h"
namespace Event {
	void EventManager::PoolEvent(RenderWindow* gameWindow)
	{
		sf::Event event;

		while (gameWindow->pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				gameWindow->close();
				
				}
			if (IskeyPressed(sf::Keyboard::Escape)) {
				gameWindow->close();
			}
		}
	}
	bool EventManager::IskeyPressed(Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}
}