#include <GL\glut.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
#include<string>
#include <cmath>
#include<deque>
#include "Vector.h"
#include "menu.h"
#include"Header.h"
#include "gVector.h"
#include "Button.h"

#define PI 3.1415

using namespace std;



gVector otrezok;
deque<gVector> sticks;
bool isDecreaseOn = 0;
bool isColorOff = 1;
int temp = 0;
float step = 0.0005;

void DrawPlay() {

	sticks.push_back(otrezok);

	float r = 1, g = 1, b = 1;
	if (!isColorOff)
		float r = 0.5, g = 0, b = 0.5;

	if (sticks.size() > 200) {
		sticks.pop_front();
	}

	float c = 0.2;
	int flagB = 1, flagG = 1, flagR = 1;

	float a = 0.9975;
	if (!isDecreaseOn) {
		a = 1;
	}



	for (int i = sticks.size() - 1; i >= 0; i--) {

		glColor3f(r, g, b);
		sticks.at(i).Draw_vector();
		sticks.at(i).DecreaseMul(a);

		if (isColorOff) {
			r -= 0.005;
			g -= 0.005;
			b -= 0.005;
		}

		else {
			if (flagB) {
				b += c;
				if (b > 1)
					flagB = 0;
			}
			else if (flagG) {
				g += c;
				b -= c;
				if (g > 1)
					flagG = 0;
			}
			else if (flagR) {
				r += 4 * c;
				g -= c;
				b -= c;
				if (r > 1) {
					r = 0.5;
					g = 0;
					b = 0.5;
					flagB = 1;
					flagG = 1;

				}

			}
		}
	}
	glColor3f(1, 1, 1);
	otrezok.Draw_vector();


}




int flag = -1;
int Enter = 0;


Menu MyGame;

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if (Enter == 0) { MyGame.DrawMenu(); }
	
	if (flag == 0 && Enter == 1) { DrawPlay(); };
	if (flag == 1 && Enter == 1) { MyGame.DrawControl(); };
	if (flag == 2 && Enter == 1) { MyGame.DrawExit(); };



	glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 13) {
		Enter = 1;
	}
	if (key == 27) {
		Enter = 0;
	}
	if (key == 'y') {
		exit(0);
	}
	if (key == 'n') {
		Enter = 0;
	}
	Vector sdvigX{ 0.05,0.05 };
	Vector sdvigY{ 0.05,0.05 };

	if (key == 'd') {

		otrezok.angleSum(PI / 100);
		sticks.push_back(otrezok);
	}
	if (key == 'a') {
		otrezok.angleSum(-PI / 100);
		sticks.push_back(otrezok);
	}
	if (key == '+') {
		otrezok.sizeSum(0.05);
		sticks.push_back(otrezok);
	}
	if (key == '-') {
		if (otrezok.getsize() > 0.15) {
			otrezok.sizeSum(-0.05);
			sticks.push_back(otrezok);
		}
	}

}

void processSpecialKeys(int key, int x, int y) {
	Vector deltaspeed{ 0,0 };

	switch (key) {
	case GLUT_KEY_LEFT:
		deltaspeed += Vector(-step, 0);

		break;
	case GLUT_KEY_RIGHT:
		deltaspeed += Vector(step, 0);

		break;
	case GLUT_KEY_F1:
		isDecreaseOn = 1;
		break;
	case GLUT_KEY_F2:
		isDecreaseOn = 0;
	case GLUT_KEY_F3:
		isColorOff = 0;
		break;
	case GLUT_KEY_F4:
		isColorOff = 1;
		break;
	case GLUT_KEY_UP:
		if (Enter == 0) {
			flag++;
			if (flag > 2) {
				flag = 0;
			}
		}
		else {
			deltaspeed += Vector(0, step);
		}
		break;
	case GLUT_KEY_DOWN:
		if (Enter == 0) {
			flag--;
			if (flag < 0) {
				flag = 2;
			}
		}
		else {
			deltaspeed += Vector(0, -step);
		}
		break;

	}

	otrezok.sumspeed(deltaspeed);
	if (Enter == 0)
		cout << MyGame.at(flag).getname() << endl;
}






void init(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	// инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Урок 1");

	// регистрация обратных вызовов

	glutDisplayFunc(renderScene);
	
	glutIdleFunc(renderScene);
	//обработка нажатий 
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// Основной цикл GLUT
	glutMainLoop();

	
}



