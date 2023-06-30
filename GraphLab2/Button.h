#pragma once
#include<string>
#include"Vector.h"
#include<Vector>
using namespace std;
class Button
{
private:
	std::string name;
	Vector pos;
public:
	void setname(std::string str);
	void setposx(float x);
	void setposy(float y);
	float getposx();
	float getposy();
	std::string getname();

};

