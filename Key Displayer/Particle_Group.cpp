#include "Particle_Group.h"

void Particle_Group::Add_Particles(float Total) {

	fParticles += Total;

	while (fParticles >= 1) {

		fParticles--;
		Particle p;
		Particles.push_back(p);
		Particles[Particles.size() - 1].Initialize(fPosition_X + rand() % 100 - 50, fPosition_Y, rand() % 100 - 50, fVelocity_Y - rand() % 50, fSize, rand() % 360, rand() % 3 + 3, fGravity + rand() % 50, fLifetime, cColor);

	}

}

void Particle_Group::Initialize(float Position_X, float Position_Y, float Velocity_X, float Velocity_Y, float Size, float Gravity, float Lifetime, sf::Color Color) {

	fPosition_X = Position_X;
	fPosition_Y = Position_Y;
	fVelocity_X = Velocity_X;
	fVelocity_Y = Velocity_Y;
	fSize		= Size;
	fGravity	= Gravity;
	fLifetime	= Lifetime;
	cColor		= Color;

	for (int i = 0; i < Particles.size(); i++) Particles[i].Initialize(Position_X, Position_Y, Velocity_X, Velocity_Y, Size, rand() % 360, rand() % 2 + 3, Gravity, Lifetime, Color);

}

void Particle_Group::Update() {

	for (int i = 0; i < Particles.size(); i++) {

		Particles[i].Update();

		if (Particles[i].isFinished) Particles.erase(Particles.begin());

	}

}

void Particle_Group::Draw(sf::RenderWindow*& window) {
	for (int i = 0; i < Particles.size(); i++) Particles[i].Draw(window);
}