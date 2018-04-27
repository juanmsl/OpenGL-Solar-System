#include "shapes.h"

float alpha = 1.0;

void drawSolid(const int& solid) {
	switch(solid) {
		case 1: drawCube();
		break;
		case 2: drawSolidTetrahedron3();
		break;
		case 3: drawSolidTetrahedron4();
		break;
		case 4: drawSolidOctahedron();
		break;
	}
}

void drawCube() {
	glPushMatrix();
		glBegin(GL_QUADS);
			HSLA(0, 100, 60, alpha);
			glVertex3f( 1,  1,  1);
			glVertex3f(-1,  1,  1);
			glVertex3f(-1,  1, -1);
			glVertex3f( 1,  1, -1);

			HSLA(60, 100, 60, alpha);
			glVertex3f(-1,  1, -1);
			glVertex3f( 1,  1, -1);
			glVertex3f( 1, -1, -1);
			glVertex3f(-1, -1, -1);

			HSLA(120, 100, 60, alpha);
			glVertex3f(-1,  1,  1);
			glVertex3f(-1,  1, -1);
			glVertex3f(-1, -1, -1);
			glVertex3f(-1, -1,  1);

			HSLA(180, 100, 60, alpha);
			glVertex3f( 1,  1,  1);
			glVertex3f( 1,  1, -1);
			glVertex3f( 1, -1, -1);
			glVertex3f( 1, -1,  1);

			HSLA(240, 100, 60, alpha);
			glVertex3f( 1, -1,  1);
			glVertex3f(-1, -1,  1);
			glVertex3f(-1, -1, -1);
			glVertex3f( 1, -1, -1);

			HSLA(300, 100, 60, alpha);
			glVertex3f(-1,  1,  1);
			glVertex3f( 1,  1,  1);
			glVertex3f( 1, -1,  1);
			glVertex3f(-1, -1,  1);
		glEnd();
	glPopMatrix();
}

void drawSolidTetrahedron3() {
	glPushMatrix();
		glBegin(GL_TRIANGLES);
			HSLA(0, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(1, -1, -1);
			glVertex3f(-1, -1, -1);

			HSLA(120, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(-1, -1, -1);
			glVertex3f(0, -1, 1);

			HSLA(240, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(0, -1, 1);
			glVertex3f(1, -1, -1);
		glEnd();
	glPopMatrix();
}

void drawSolidTetrahedron4() {
	glPushMatrix();
		glBegin(GL_TRIANGLES);
			HSLA(0, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(1, -1, -1);
			glVertex3f(-1, -1, -1);

			HSLA(90, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(-1, -1, -1);
			glVertex3f(-1, -1, 1);

			HSLA(180, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(-1, -1, 1);
			glVertex3f(1, -1, 1);
			
			HSLA(270, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(1, -1, 1);
			glVertex3f(1, -1, -1);
		glEnd();
	glPopMatrix();
}

void drawSolidOctahedron() {
	glPushMatrix();
		glBegin(GL_TRIANGLES);
			HSLA(0, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(1, 0, -1);
			glVertex3f(-1, 0, -1);

			HSLA(45, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(-1, 0, -1);
			glVertex3f(-1, 0, 1);

			HSLA(90, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(-1, 0, 1);
			glVertex3f(1, 0, 1);
			
			HSLA(135, 100, 60, alpha);
			glVertex3f(0, 1, 0);
			glVertex3f(1, 0, 1);
			glVertex3f(1, 0, -1);

			HSLA(180, 100, 60, alpha);
			glVertex3f(0, -1, 0);
			glVertex3f(1, 0, -1);
			glVertex3f(-1, 0, -1);

			HSLA(225, 100, 60, alpha);
			glVertex3f(0, -1, 0);
			glVertex3f(-1, 0, -1);
			glVertex3f(-1, 0, 1);

			HSLA(270, 100, 60, alpha);
			glVertex3f(0, -1, 0);
			glVertex3f(-1, 0, 1);
			glVertex3f(1, 0, 1);
			
			HSLA(315, 100, 60, alpha);
			glVertex3f(0, -1, 0);
			glVertex3f(1, 0, 1);
			glVertex3f(1, 0, -1);
		glEnd();
	glPopMatrix();
}

void drawCircle(const float& radius, const float& x, const float& y, const float& z, const float& nx, const float& ny, const float& nz) {
	glBegin(GL_POINTS);
		float p = 1.25f - radius, h;
		int xk = 0, zk = radius;
		while(xk <= zk) {
			h = (-(nx * (+xk)) - (nz * (+zk))) / ny;
			glVertex3f(x + xk, y + h, z + zk);
			h = (-(nx * (-xk)) - (nz * (+zk))) / ny;
			glVertex3f(x - xk, y + h, z + zk);
			h = (-(nx * (-xk)) - (nz * (-zk))) / ny;
			glVertex3f(x - xk, y + h, z - zk);
			h = (-(nx * (+xk)) - (nz * (-zk))) / ny;
			glVertex3f(x + xk, y + h, z - zk);

			h = (-(nx * (+zk)) - (nz * (+xk))) / ny;
			glVertex3f(x + zk, y + h, z + xk);
			h = (-(nx * (-zk)) - (nz * (+xk))) / ny;
			glVertex3f(x - zk, y + h, z + xk);
			h = (-(nx * (-zk)) - (nz * (-xk))) / ny;
			glVertex3f(x - zk, y + h, z - xk);
			h = (-(nx * (+zk)) - (nz * (-xk))) / ny;
			glVertex3f(x + zk, y + h, z - xk);
			xk++;
			if(p < 0) p = p + 2 * xk + 1;
			else {
				zk--;
				p = p + 2 * xk - 2 * zk + 1;
			}
		}
	glEnd();
}