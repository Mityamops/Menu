#include<string>
#pragma once

void DrawMenu();
void DrawControl();
void DrawExit();
void DrawPlay();
void Read();
void DrawQuad(float x, float y, float dx, float dy);
void renderBitmapString(float x, float y, std::string str);

void renderScene(void);
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void init(int argc, char** argv);