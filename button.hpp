#pragma once
#include <SFML/Graphics.hpp>
#include "TextLabel.hpp"
#include <vector>

class Button: public sf::Rect<int> {
	private:
		sf::Color color;
		TextLabel text;
	public:
		//default constructor
		Button() {
			left = 0;
			top = 0;
			color = sf::Color::White;
		}

		//accessors
		sf::Vector2i getPosition() {
			sf::Vector2i retPos;
			retPos.x = left;
			retPos.y = top;
			return retPos;
		}

		sf::Vector2i getSize() {
			sf::Vector2i retSize;
			retSize.x = width;
			retSize.y = height;
			return retSize;
		}

		//mutators
		void setSize(int x, int y) {
			width = x;
			height = y;
		}

		void setPosition(int x, int y) {
			left = x;
			top = y;
		}

		void setColor(sf::Color newColor) {
			color = newColor;
		}
};