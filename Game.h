#ifndef GAME__H
#define GAME__H
#include "SDL_utils.h"
void Display_hide(int x, int y);

void Display_img(int x, int y,string path);

string GetPath(int x,int y);

void GetEvent(SDL_Event e,int &a,int &b);

void GetLoca(int &x,int &y);

void loadpath();

void showgame();

void rungame();
#endif // GAME__H
