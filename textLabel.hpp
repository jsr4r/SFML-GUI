#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class TextLabel: public sf::Rect<int> {
	private:		
		sf::Font font;
		std::string text;		
		sf::Color color;
	public:
		//default constructor:
		TextLabel() {
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

};