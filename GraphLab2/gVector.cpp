#include <GL\glut.h>
#include <cmath>
#include "gVector.h"
#include "Vector.h"


void gVector::sumspeed(Vector v) {
	speed += v;

}
float gVector::getDecrease() {
	return Decrease;
}
float gVector::getsize() {
	return size;
}
float gVector::getangle() {
	return angle;
}
void gVector::DecreaseMul(float mul) {
	Decrease *= mul;
}
void gVector::angleSum(float sum) {
	angle += sum;
}
void gVector::sizeSum(float sum) {
	size += sum;
}

void gVector::Draw_vector() {
	glLineWidth(15);
	coord += speed;
	speed *= 0.99;
	glBegin(GL_LINES);
	float xsize = Decrease * size * sin(angle), ysize = Decrease * size * cos(angle);
	glVertex2f(coord.getx() + xsize, coord.gety() + ysize);
	glVertex2f(coord.getx() - xsize, coord.gety() - ysize);

	glEnd();
}

float gVector::operator*(const float mul) {
	size *= mul;
	return size;
}
void gVector::operator*=(const float mul) {
	size *= mul;
}
