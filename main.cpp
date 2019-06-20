//Author: Jonathan Reed
//This is purely for entertainment value.
#pragma once
#include "OpenSansFont.hpp"
#include "button.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void drawMenu(sf::VideoMode& desktopSize, sf::RenderWindow& window);

//global attributes:
sf::Color bgColor(234, 234, 249, 200);
sf::Color menuButtonColor(117, 27, 15, 255);
sf::Color menuTextColor(242, 210, 138, 255);

int main() {

	//initialize window
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "Simple GUI");
	::ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);
	window.setVerticalSyncEnabled(true);

	//initialize fonts
	sf::Font menuFont;
	int menuTextSize = desktop.width / 80;
	menuFont.loadFromMemory(&OpenSans_Regular_ttf, OpenSans_Regular_ttf_len);

	//initialize buttons
	sf::Vector2f buttonSize;
	buttonSize.x = desktop.width / 6;
	buttonSize.y = desktop.height / 6;
	sf::Vector2f buttonPosition;
	
	//new Game button
		buttonPosition.x = (desktop.width / 2) - (buttonSize.x / 2);
		buttonPosition.y = (desktop.height / 5) - (buttonSize.y / 2);
		Button *newGameButton = new Button(buttonPosition, menuButtonColor, menuButtonColor, buttonSize);

		sf::Text *newGameText = new sf::Text("New Game", menuFont, menuTextSize);
		newGameText->setFillColor(menuTextColor);
		newGameText->setOutlineColor(menuTextColor);

		newGameButton->setLabel(*newGameText);
		
	//load game button:
		buttonPosition.x = (desktop.width / 2) - (buttonSize.x / 2);
		buttonPosition.y = (desktop.height / 5 * 2) - (buttonSize.y / 2);
		Button *loadGameButton = new Button(buttonPosition, menuButtonColor, menuButtonColor, buttonSize);
		
		sf::Text *loadGameText = new sf::Text("Load Game", menuFont, menuTextSize);
		loadGameText->setFillColor(menuTextColor);
		loadGameText->setOutlineColor(menuTextColor);

		loadGameButton->setLabel(*loadGameText);
	//options button
		buttonPosition.x = (desktop.width / 2) - (buttonSize.x / 2);
		buttonPosition.y = (desktop.height / 5 * 3) - (buttonSize.y / 2);
		Button *optionsGameButton = new Button(buttonPosition, menuButtonColor, menuButtonColor, buttonSize);

		sf::Text *optionsGameText = new sf::Text("Options", menuFont, menuTextSize);
		optionsGameText->setFillColor(menuTextColor);
		optionsGameText->setOutlineColor(menuTextColor);

		optionsGameButton->setLabel(*optionsGameText);
	//exit game button
		buttonPosition.x = (desktop.width / 2) - (buttonSize.x / 2);
		buttonPosition.y = (desktop.height / 5 * 4) - (buttonSize.y / 2);
		Button *exitGameButton = new Button(buttonPosition, menuButtonColor, menuButtonColor, buttonSize);

		sf::Text *exitGameText = new sf::Text("Exit Game", menuFont, menuTextSize);
		exitGameText->setFillColor(menuTextColor);
		exitGameText->setOutlineColor(menuTextColor);

		exitGameButton->setLabel(*exitGameText);
	//main loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed) {
				sf::Rect<float> newGameRect = newGameButton->getGlobalBounds();
				//cout << "position (top, left): " << newGameRect.top << ", " << newGameRect.left << endl;
				sf::Vector2f mousePos(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
				//cout << "mousePos: " << mousePos.x << "," << mousePos.y << endl;
				cout << "mousePos: " << mousePos.x << "," << mousePos.y << endl;
				if (mousePos.x >= newGameRect.left && mousePos.x <= newGameRect.left + newGameRect.width) {
					if ((mousePos.y <= newGameRect.top + newGameRect.height) && (mousePos.y >= newGameRect.top)) {
						cout << "new game " << endl;
					}
				}
			}
		}
		
		window.clear(bgColor);
		window.draw(*newGameButton);
		window.draw(*newGameText);
		
		window.draw(*loadGameButton);
		window.draw(*loadGameText);
		
		window.draw(*optionsGameButton);
		window.draw(*optionsGameText);
		
		window.draw(*exitGameButton);
		window.draw(*exitGameText);
		
		window.display();
	}

	delete newGameText;
	delete newGameButton;	

	delete loadGameText;
	delete loadGameButton;	

	delete optionsGameText;
	delete optionsGameButton;

	delete exitGameText;
	delete exitGameButton;
	
	return 0;
}