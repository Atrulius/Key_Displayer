#include "Particle.h"

void Particle::Initialize(float Position_X, float Position_Y, float Velocity_X, float Velocity_Y, float Size, float Rotation, int Edge_Count, float Gravity, float Lifetime, sf::Color Color) {
	fPosition_X	= Position_X;
	fPosition_Y	= Position_Y;
	fVelocity_X	= Velocity_X;
	fVelocity_Y	= Velocity_Y;
	fSize		= Size;
	fRotation	= Rotation;
	iEdge_Count = Edge_Count;
	fGravity	= Gravity;
	fLifetime	= Lifetime;
	cColor		= Color;

	fTime = 0;

	ParticleObj.setPointCount(iEdge_Count);

	ParticleObj.setFillColor(cColor);
}

void Particle::Update() {
	fTime += 1.f / 120;

	if (fTime >= fLifetime) isFinished = true;

	fVelocity_Y += fGravity / 120;

	fPosition_X += fVelocity_X / 120;
	fPosition_Y += fVelocity_Y / 120;
}

void Particle::Draw(sf::RenderWindow*& window) {

	float newSize = fSize * ((1 - (fTime / fLifetime)) * (1 - (fTime / fLifetime)));

	ParticleObj.setRadius((newSize));

	ParticleObj.setOrigin(newSize / 2, newSize / 2);

	ParticleObj.setPosition(fPosition_X, fPosition_Y);

	ParticleObj.setRotation(fRotation);

	window->draw(ParticleObj);
}