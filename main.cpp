#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include <string>
using namespace std;

void drawMenu(sf::VideoMode& desktopSize, sf::RenderWindow& window);

//global attributes for menu and background colors:
sf::Color bgColor(234, 234, 249, 200);
sf::Color menuButtonColor(117, 27, 15, 255);

int main() {

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "Simple GUI");
	::ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);
	window.setVerticalSyncEnabled(true);

	//main loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(bgColor);
		drawMenu(desktop, window);
		window.display();
	}

	return 0;
}

//self-explanatory function
void drawMenu(sf::VideoMode & desktopSize, sf::RenderWindow& window) {

	//draw buttons:
		sf::RectangleShape button(sf::Vector2f(sf::Vector2f((desktopSize.width/6), (desktopSize.height/6))));
		button.setFillColor(menuButtonColor);

		//some math to center the rectangle horizontally on screen, since the position is based on the top-left corner:
		sf::FloatRect dimens = button.getLocalBounds();
		button.setPosition((desktopSize.width / 2) - (dimens.width / 2), (desktopSize.height / 5) - (dimens.height / 2));	
		window.draw(button);

		button.setPosition((desktopSize.width / 2) - (dimens.width / 2), (desktopSize.height / 5 * 2) - (dimens.height / 2));
		window.draw(button);

		button.setPosition((desktopSize.width / 2) - (dimens.width / 2), (desktopSize.height / 5 * 3) - (dimens.height / 2));
		window.draw(button);

		button.setPosition((desktopSize.width / 2) - (dimens.width / 2), (desktopSize.height / 5 * 4) - (dimens.height / 2));
		window.draw(button);
	//draw text:
		

}