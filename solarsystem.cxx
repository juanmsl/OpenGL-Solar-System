#include "solarsystem.h"

float cambio = 1.0f, dir = 1;

SolarSystem::SolarSystem(const float& sunSize, const bool& showOrbit) {
	this->sunSize = sunSize;
	this->showOrbit = showOrbit;
	this->currentPlanet = 0;
	this->planetActive.push_back(true);
}

void SolarSystem::addPlanet(const float& planetRadius, const int& shape, const float& nx, const float& ny, const float& nz, const float& moonCount) {
	float orbitRadius = sunSize + (planetRadius * 4.0f);
	int size = this->planets.size();
	if(size > 0) {
		Planet lastPlanet = this->planets[size - 1];
		orbitRadius = lastPlanet.getOrbitRadius() + (lastPlanet.getRadius() * 2.5f) + (planetRadius * 4.0f);
	}

	Planet planet(orbitRadius, planetRadius, nx, ny, nz, moonCount, shape);
	this->planets.push_back(planet);
	this->planetActive.push_back(false);
}

void SolarSystem::draw(const float& time, float& pcx, float& pcy, float& pcz) {
	if(this->planetActive[0]) {
		pcx = 0;
		pcy = 0;
		pcz = 0;
	}
	if(cambio > 1.3f) {
		dir = -1.0f;
	} else if(cambio < 0.7f) {
		dir = 1;
	}
	cambio += (dir * (0.005f));
	glPushMatrix();
		HSL(60, 100, 50);
		glRotatef(time * 1.5f, 0, 1, 0);
		glScalef(this->sunSize * cambio, this->sunSize * cambio, this->sunSize * cambio);
		drawSolid(4);
	glPopMatrix();

	int size = this->planets.size();
	for(int i = 0; i < size; i++) {
		Planet planet = this->planets[i];
		planet.draw(time, this->planetActive[i + 1], showOrbit, pcx, pcy, pcz);
	}
}

void SolarSystem::setPlanetActive(const int& index) {
	this->planetActive[this->currentPlanet] = false;
	this->currentPlanet = index;
	this->planetActive[this->currentPlanet] = true;
}