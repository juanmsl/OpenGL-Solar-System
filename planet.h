#ifndef __PLANET_H__
#define __PLANET_H__

#include <GL/freeglut.h>
#include <GL/gl.h>
#include "colors.h"
#include "shapes.h"

class Planet {
	protected:
		float orbitRadius;
		float planetRadius;
		float nx;
		float ny;
		float nz;
		float moonCount;
		int solid;

	public:
		Planet(const float& orbitRadius, const float& planetRadius, const float& nx, const float& ny, const float& nz, const float& moonCount, const int& solid);
		float getOrbitRadius();
		float getRadius();
		void draw(const float& time, const bool isActive, const bool& showOrbit, float& pcx, float& pcy, float& pcz);
		void addMoon(const float& time, const float& orbitRadius, const float& moonRadius, const float& x, const float& y, const float& z, const bool &showOrbit);
};

#endif