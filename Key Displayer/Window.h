#pragma once

#include "Key.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <Windows.h>

class Window {

private:

	sf::RenderWindow*	window;
	sf::VideoMode		videoMode;
	sf::Event			event;

	bool bButtonHeld[4];

	Key key[4];

public:

	Window();
	virtual ~Window();

	const bool Running() const;

	void Poll_Events();

	void Initialize_Window();

	void Update();

	void Draw();

};