#pragma once

#include "Particle.h"

#include <vector>

class Particle_Group
{

private:

	std::vector<Particle> Particles;

	float fParticles = 0;

	float fPosition_X;
	float fPosition_Y;

	float fVelocity_X;
	float fVelocity_Y;

	float fSize;

	float fGravity;

	float fLifetime;

	sf::Color cColor;

public:

	void Add_Particles(float Total);

	void Initialize(float Position_X, float Position_Y, float Velocity_X, float Velocity_Y, float Size, float Gravity, float Lifetime, sf::Color Color);

	void Update();

	void Draw(sf::RenderWindow*& window);

};