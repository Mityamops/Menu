#include<string>
#include"Vector.h"
#include<vector>
#include"Button.h"
#pragma once
class Menu {
private:
	
	vector<Button> Buttons;
public:
	
	Button at(int i);
	

	void DrawMenu();
	void DrawControl();
	void DrawExit();

};
