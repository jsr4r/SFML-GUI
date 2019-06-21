#pragma once
#include <SFML/Graphics.hpp>

class Button: public sf::RectangleShape {
	private:
		sf::Text text;
	public:
		//default constructor
		Button() {
		}
		//parameterized:
		Button(sf::Vector2f &buttonPosition, sf::Color fill, sf::Color outline, sf::Vector2f &buttonSize) {
			this->setPosition(buttonPosition);
			this->setSize(buttonSize);
			this->setFillColor(fill);
			this->setOutlineColor(outline);
		}

		//accessors

		sf::Text getLabel() {
			return text;
		}

		//mutators
		void setLabel(sf::Text &label) { //"hides" the math needed to align text with button nicely
			text = label;
			sf::FloatRect bounds = label.getGlobalBounds();
			label.setPosition(this->getPosition().x + this->getSize().x / 2 - bounds.width / 2, 
				this->getPosition().y + this->getSize().y / 2 - bounds.height);

		}

		void updateButton(sf::Vector2f &buttonPosition, sf::Vector2f &buttonSize) {
			//set position, size
			this->setPosition(buttonPosition);
			this->setSize(buttonSize);
			//attach label
			sf::Text label = this->getLabel();
			this->setLabel(label);
		}

};