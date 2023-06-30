#pragma once
#include "Vector.h"
class gVector {
private:
	Vector coord = { 0,0 };
	Vector speed = { 0,0 };
	float size = 0.5;
	float angle = 0;
	float Decrease = 1;


public:

	void sumspeed(Vector v);

	float getDecrease();

	float getsize();

	float getangle();

	void DecreaseMul(float mul);

	void angleSum(float sum);

	void sizeSum(float sum);


	void Draw_vector();


	float operator*(const float mul);

	void operator*=(const float mul);
};

