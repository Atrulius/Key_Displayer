#include "Window.h"

void Window::Initialize_Window() {

	videoMode.height = 820;
	videoMode.width = 6 * 100;
	window = new sf::RenderWindow(videoMode, "Key Displayer", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(120);

}

Window::Window() {

	ShowWindow(GetConsoleWindow(), SW_HIDE);

	Initialize_Window();

	for (int i = 0; i < 4; i++) key[i].Load(i, window);

}

Window::~Window() {

	delete window;

}

const bool Window::Running() const { return window->isOpen(); }

void Window::Poll_Events() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) bButtonHeld[0] = true; else bButtonHeld[0] = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) bButtonHeld[1] = true; else bButtonHeld[1] = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) bButtonHeld[2] = true; else bButtonHeld[2] = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) bButtonHeld[3] = true; else bButtonHeld[3] = false;

	while (window->pollEvent(event)) {

		if (event.type == sf::Event::Closed) {
			window->close();
			break;
		}

		if (event.type == sf::Event::Resized) {
			int x = 0;
			int y = 0;
			int w = 0;
			int h = 0;
			if (window->getSize().x > window->getSize().y) {
				x = 250 - (500 * (float(window->getSize().x) / float(window->getSize().y))) / 2;
				y = 0;
				w = 500 * (float(window->getSize().x) / float(window->getSize().y));
				h = 500;
			}
			else {
				x = 0;
				y = 250 - (500 * (float(window->getSize().y) / float(window->getSize().x))) / 2;
				w = 500;
				h = 500 * (float(window->getSize().y) / float(window->getSize().x));
			}
			sf::FloatRect visibleArea(x, y, w, h);
			window->setView(sf::View(visibleArea));
		}

	}

}

void Window::Update() {

	Poll_Events();

	for (int i = 0; i < 4; i++) key[i].Update(bButtonHeld[i]);

}

void Window::Draw() {

	this->window->clear(sf::Color(0, 255, 0, 255));

	for (int i = 0; i < 4; i++) key[i].Draw(window);

	this->window->display();

}