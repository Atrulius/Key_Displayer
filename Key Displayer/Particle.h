#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Particle
{

private:

	float fPosition_X;
	float fPosition_Y;

	float fVelocity_X;
	float fVelocity_Y;

	float fSize;

	float fRotation;

	int	iEdge_Count;

	float fGravity;

	float fLifetime;
	float fTime;

	sf::Color cColor;

	sf::CircleShape ParticleObj;

public:

	bool isFinished = false;

	void Initialize(float Position_X, float Position_Y, float Velocity_X, float Velocity_Y, float Size, float Rotation, int Edge_Count, float Gravity, float Lifetime, sf::Color Color);

	void Update();

	void Draw(sf::RenderWindow*& window);

};