#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace Rect {

	void Rounded(sf::RectangleShape rect, int Radius, sf::RenderWindow*& window) {

		int TEMPINT = Radius;

		if (float(rect.getSize().x) / 2 < TEMPINT) TEMPINT = float(rect.getSize().x) / 2;
		if (float(rect.getSize().y) / 2 < TEMPINT) TEMPINT = float(rect.getSize().y) / 2;

		sf::RectangleShape TEMP = rect;

		TEMP.setPosition(rect.getPosition().x + TEMPINT, rect.getPosition().y);
		TEMP.setSize(sf::Vector2f(rect.getSize().x - 2 * TEMPINT, rect.getSize().y));

		window->draw(TEMP);

		TEMP.setPosition(rect.getPosition().x, rect.getPosition().y + TEMPINT);
		TEMP.setSize(sf::Vector2f(rect.getSize().x, rect.getSize().y - 2 * TEMPINT));

		window->draw(TEMP);

		sf::CircleShape Corner(TEMPINT);

		Corner.setFillColor(rect.getFillColor());

		Corner.setPosition(rect.getPosition().x, rect.getPosition().y);

		window->draw(Corner);

		Corner.setPosition(rect.getPosition().x + rect.getSize().x - Corner.getRadius() * 2, rect.getPosition().y);

		window->draw(Corner);

		Corner.setPosition(rect.getPosition().x, rect.getPosition().y + rect.getSize().y - Corner.getRadius() * 2);

		window->draw(Corner);

		Corner.setPosition(rect.getPosition().x + rect.getSize().x - Corner.getRadius() * 2, rect.getPosition().y + rect.getSize().y - Corner.getRadius() * 2);

		window->draw(Corner);

	}

	namespace Get {

		sf::RectangleShape Base_From_Outline(sf::RectangleShape rect, int Outline_Thickness) {

			sf::RectangleShape TEMP = rect;

			TEMP.setPosition(rect.getPosition().x + Outline_Thickness, rect.getPosition().y + Outline_Thickness);
			TEMP.setSize(sf::Vector2f(rect.getSize().x - 2 * Outline_Thickness, rect.getSize().y - 2 * Outline_Thickness));

			return TEMP;

		}

	}

}