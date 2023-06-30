#include "menu.h"
#include<string>
#include<deque>
#include"Vector.h"
#include"gVector.h"
#include <GL\glut.h>
#include <cmath>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

Button Menu::at(int i) { return Buttons.at(i); }
struct rectangle {
	float x;
	float y;
	float weight;
	float height;
};

rectangle first = { -0.25, 0.5, 0.5, 0.3 };
rectangle second = { -0.25, 0.0, 0.5, 0.3 };
rectangle third = { -0.25, -0.5, 0.5, 0.3 };

void DrawQuad(float x, float y, float dx, float dy) {
	glBegin(GL_TRIANGLE_FAN);



	glVertex2f(x, y);
	glVertex2f(x + dx, y);
	glVertex2f(x + dx, y + dy);
	glVertex2f(x, y + dy);

	glEnd();
}

void renderBitmapString(float x, float y, string str) {
	glColor3f(1.0f, 1.0f, 1.0f);

	glRasterPos2f(x, y);
	for (auto c : str) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}




void Menu::DrawMenu() {
	Button m;
	ifstream F("menu.txt");
	string line;
	string name = "Menuname:", x = "posx:", y = "posy:";

	if (F.is_open())
	{
		while (getline(F, line))
		{

			if (!line.find(name))
				m.setname(line.substr(name.size()));
			if (!line.find(x)) {

				m.setposx(stof(line.substr(x.size())));
			}
			if (!line.find(y)) {
				m.setposy(stof(line.substr(y.size())));
				Buttons.push_back(m);
			}

		}
	}
	glClearColor(0, 0, 0, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	DrawQuad(first.x, first.y, first.weight, first.height);



	glColor3f(0.0f, 1.0f, 0.0f);
	DrawQuad(second.x, second.y, second.weight, second.height);

	glColor3f(0.0f, 0.0f, 1.0f);
	DrawQuad(third.x, third.y, third.weight, third.height);

	glColor3f(1.0f, 1.0f, 1.0f);
	for (auto i : Buttons) {
		renderBitmapString(i.getposx(), i.getposy(), i.getname());
	}

}
void Menu::DrawControl() {
	glClearColor(1, 0, 0, 1);

	ifstream F("settings.txt");
	string line;
	vector <string> settings;

	if (F.is_open())
	{
		while (getline(F, line))
		{
			settings.push_back(line);

		}
	}
	renderBitmapString(-1, 0.9, "Control");
	float a = 0.05;
	for (auto i : settings) {
		renderBitmapString(-1, 0.9 - a, i);
		a += 0.05;
	}
	renderBitmapString(-1, 0.1, "Press esc to return to the menu");

}
void Menu::DrawExit() {
	renderBitmapString(0, 0, "are you sure want to exit?:y\\n");

}