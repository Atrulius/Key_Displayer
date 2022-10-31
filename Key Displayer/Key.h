#pragma once

#include "Particle_Group.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <random>

const int Total = 120;

class Key {

private:


	bool bActive[Total];
	const int iSize = 100;
	
	sf::RectangleShape RectOutline;
	sf::RectangleShape RectBase;
	sf::RectangleShape Line;
	sf::RectangleShape LineOutline;

	sf::Color RectOutlineColor			= sf::Color(255, 255, 255);
	sf::Color RectBaseColor				= sf::Color(15, 15, 15);
	sf::Color TextColor					= sf::Color(255, 255, 255);
	sf::Color RectOutlineHoldingColor	= sf::Color(11, 11, 11);
	sf::Color RectBaseHoldingColor		= sf::Color(255, 255, 255);
	sf::Color TextHoldingColor			= sf::Color(0, 0, 0);
	sf::Color LineColor					= sf::Color(31, 31, 31);
	sf::Color LineOutlineColor			= sf::Color(255, 255, 255);
	sf::Color ParticleColor				= sf::Color(255, 255, 255);

	sf::Font Font;
	sf::Text Character;

	Particle_Group Particles;

public:

	void Load(int Index, sf::RenderWindow*& window);

	void Update(bool Active);

	void Draw(sf::RenderWindow*& window);

};