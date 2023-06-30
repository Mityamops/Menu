#include "Vector.h"
Vector::Vector()
{
	this->xc = 0;
	this->yc = 0;
}

Vector::Vector(float x, float y)
{
	this->xc = x;
	this->yc = y;
}

void Vector::setx(float x) {
	xc = x;
}
void Vector::sety(float y) {
	yc = y;
}

float Vector::getx() {
	return xc;
}
float Vector::gety() {
	return yc;
}
void Vector::operator= (const Vector& other) {
	this->xc = other.xc;
	this->yc = other.yc;

}
Vector Vector::operator+ (const Vector& other) {
	this->xc += other.xc;
	this->yc += other.yc;
	return Vector{ this->xc += other.xc,
	this->yc += other.yc };
}
Vector Vector::operator- (const Vector& other) {
	return Vector{ this->xc -= other.xc,
	this->yc -= other.yc };
}
void Vector::operator+= (const Vector& other) {
	this->xc += other.xc;
	this->yc += other.yc;

}
void Vector::operator-= (const Vector& other) {
	this->xc -= other.xc;
	this->yc -= other.yc;
}
void Vector::operator*=(const float mul) {
	xc *= mul;
	yc *= mul;
}

