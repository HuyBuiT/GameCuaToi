#ifndef GAME__H
#define GAME__H
#include "SDL_utils.h"
void Display_img(int x, int y,string path,SDL_Renderer* renderer);

void Display_hide(int x, int y,SDL_Renderer* renderer);

void GetEventFromMouse(SDL_Event e,int &a,int &b);

void GetEventFromKey(SDL_Event e,int &a);

void GetLoca(int &x,int &y);

void showrule();

void rungame(Mix_Chunk *flip,Mix_Chunk *correct,Mix_Chunk *win );

void startgame();

void showgame();
string GetPath(int x,int y);

void loadpath();

#endif // GAME__H
