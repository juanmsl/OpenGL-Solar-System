#include "planet.h"

bool cmb = false;

Planet::Planet(const float& orbitRadius, const float& planetRadius, const float& nx, const float& ny, const float& nz, const float& moonCount, const int& solid) {
	this->orbitRadius = orbitRadius;
	this->planetRadius = planetRadius;
	this->nx = nx;
	this->ny = ny;
	this->nz = nz;
	this->moonCount = moonCount;
	this->solid = solid;
}

float Planet::getOrbitRadius() {
	return this->orbitRadius;
}

float Planet::getRadius() {
	return this->planetRadius;
}

void Planet::draw(const float& time, const bool isActive, const bool& showOrbit, float& pcx, float& pcy, float& pcz) {
	float angle =  0.5f * time / orbitRadius;
	float x = cos(angle) * orbitRadius;
	float z = sin(angle) * orbitRadius;
	float y = (-(nx * x) - (nz * z)) / ny;

	if(isActive) {
		pcx = x;
		pcy = y;
		pcz = z;
	}

	if(showOrbit) {
		glPushMatrix();
			HSL(0, 100, 100);
			drawCircle(orbitRadius, 0, 0, 0, nx, ny, nz);
		glPopMatrix();
	}

	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(time * 3.0f, 0, 1, 0);
		glScalef(planetRadius, planetRadius, planetRadius);
		drawSolid(solid);
	glPopMatrix();

	cmb = false;
	for(float i = 1.0f; i <= this->moonCount; i++) {
		addMoon(time, planetRadius * 2.0f * i, planetRadius * 0.3f, x, y, z, showOrbit);
		cmb = !cmb;
	}
}

void Planet::addMoon(const float& time, const float& orbitRadius, const float& moonRadius, const float& x, const float& y, const float& z, const bool &showOrbit) {
	float aux_nx = ((cmb) ? -nx : nx);

	float angle = time / orbitRadius;
	float _x = (cos(angle) * orbitRadius);
	float _z = (sin(angle) * orbitRadius);
	float _y = ((-(aux_nx * _x) - (nz * _z)) / ny);

	if(showOrbit) {
		glPushMatrix();
			HSL(0, 100, 100);
			drawCircle(orbitRadius, x, y, z, aux_nx, ny, nz);
		glPopMatrix();
	}

	glPushMatrix();
		glTranslatef(x + _x, y + _y, z + _z);
		glRotatef(time * 5.0f, 0, 1, 0);
		glScalef(moonRadius, moonRadius, moonRadius);
		drawSolid(solid);
	glPopMatrix();
}