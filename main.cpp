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

//global attributes:
sf::Color bgColor(234, 234, 249, 200);
sf::Color menuButtonColor(117, 27, 15, 255);
sf::Color menuTextColor(242, 210, 138, 255);

int main(int argc, char* argv[]) {

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
		Button newGameButton(buttonPosition, menuButtonColor, menuButtonColor, buttonSize);

		sf::Text newGameText("New Game", menuFont, menuTextSize);
		newGameText.setFillColor(menuTextColor);
		newGameText.setOutlineColor(menuTextColor);

		newGameButton.setLabel(newGameText);
		
	//load game button:
		buttonPosition.x = (desktop.width / 2) - (buttonSize.x / 2);
		buttonPosition.y = (desktop.height / 5 * 2) - (buttonSize.y / 2);
		Button loadGameButton(buttonPosition, menuButtonColor, menuButtonColor, buttonSize);
		
		sf::Text loadGameText("Load Game", menuFont, menuTextSize);
		loadGameText.setFillColor(menuTextColor);
		loadGameText.setOutlineColor(menuTextColor);

		loadGameButton.setLabel(loadGameText);
	//options button
		buttonPosition.x = (desktop.width / 2) - (buttonSize.x / 2);
		buttonPosition.y = (desktop.height / 5 * 3) - (buttonSize.y / 2);
		Button optionsGameButton(buttonPosition, menuButtonColor, menuButtonColor, buttonSize);

		sf::Text optionsGameText("Options", menuFont, menuTextSize);
		optionsGameText.setFillColor(menuTextColor);
		optionsGameText.setOutlineColor(menuTextColor);

		optionsGameButton.setLabel(optionsGameText);
	//exit game button
		buttonPosition.x = (desktop.width / 2) - (buttonSize.x / 2);
		buttonPosition.y = (desktop.height / 5 * 4) - (buttonSize.y / 2);
		Button exitGameButton(buttonPosition, menuButtonColor, menuButtonColor, buttonSize);

		sf::Text exitGameText("Exit Game", menuFont, menuTextSize);
		exitGameText.setFillColor(menuTextColor);
		exitGameText.setOutlineColor(menuTextColor);

		exitGameButton.setLabel(exitGameText);
	//main loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
			sf::Rect<float> *newGameRect = &newGameButton.getGlobalBounds();
			//sf::Rect<float> newGameRect = newGameButton.getGlobalBounds();
			sf::Rect<float> *loadGameRect = &loadGameButton.getGlobalBounds();
			sf::Rect<float> *optionsGameRect = &optionsGameButton.getGlobalBounds();
			sf::Rect<float> *exitGameRect = &exitGameButton.getGlobalBounds();

			if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed) {				
				//convert mouse coordinates to world coordinates
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

				cout << "mousePos: " << mousePos.x << "," << mousePos.y << endl;
				cout << "worldPos: " << worldPos.x << "," << worldPos.y << endl;

				if (newGameRect->contains(worldPos)) {
					cout << "new game " << endl;
				}
				else if (loadGameRect->contains(worldPos)) {
					cout << "load game " << endl;
				}
				else if (optionsGameRect->contains(worldPos)) {
					cout << "options" << endl;
				}
				else if (exitGameRect->contains(worldPos)) {
					cout << "exit game " << endl;
				}
			}
		}
		
		window.clear(bgColor);
		window.draw(newGameButton);
		window.draw(newGameText);
		
		window.draw(loadGameButton);
		window.draw(loadGameText);
		
		window.draw(optionsGameButton);
		window.draw(optionsGameText);
		
		window.draw(exitGameButton);
		window.draw(exitGameText);
		
		window.display();
	}
	
	return 0;
}
