#ifndef __SHAPES_H__
#define __SHAPES_H__

#define CUBE 1
#define TETRAHEDRON3 2
#define TETRAHEDRON4 3
#define OCTRAHEDRON 4

#include <GL/freeglut.h>
#include <GL/gl.h>
#include "colors.h"

void drawSolid(const int& solid);

void drawCube();

void drawSolidTetrahedron3();

void drawSolidTetrahedron4();

void drawSolidOctahedron();

void drawCircle(const float& radius, const float& x = 0.0f, const float& y = 0.0f, const float& z = 0.0f, const float& nx = 0.0f, const float& ny = 1.0f, const float& nz = 0.0f);

#endif