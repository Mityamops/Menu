#include "Button.h"

void Button::setname(string str) {
	name = str;
}
void Button::setposx(float x) {
	pos.setx(x);
}
void Button::setposy(float y) {
	pos.sety(y);
}
float Button::getposx() {
	return pos.getx();
}
float Button::getposy() {
	return pos.gety();
}
string Button::getname() {
	return name;
}
