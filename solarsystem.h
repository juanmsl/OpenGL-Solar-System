#ifndef __SOLAR_SYSTEM_H__
#define __SOLAR_SYSTEM_H__

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <vector>
#include "colors.h"
#include "planet.h"

class SolarSystem {
	protected:
		std::vector<Planet> planets;
		std::vector<bool> planetActive;
		int currentPlanet;
		bool showOrbit;
		float sunSize;

	public:
		SolarSystem(const float& sunSize = 5.0f, const bool& showOrbit = true);
		void addPlanet(const float& planetRadius, const int& shape = 1, const float& nx = 0, const float& ny = 1, const float& nz = 0, const float& moonCount = 1);
		void draw(const float& time, float& pcx, float& pcy, float& pcz);
		void setPlanetActive(const int& index);
};

#endif