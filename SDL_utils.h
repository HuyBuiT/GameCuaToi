#ifndef SDL_UTILS_H_
#define SDL_UTILS_H_

#include<bits/stdc++.h>
#include<SDL.h>
#include<windows.h>
#include<SDL_image.h>
#include<SDL_events.h>
using namespace std;
const string WINDOW_TITLE = "Memory Card";
const int SCREEN_HEIGHT=700;
const int SCREEN_WIDTH=1200;
const int SCREEN_BPP =320;
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void refreshScreen(SDL_Window* window, SDL_Renderer* renderer,
    const SDL_Rect& filled_rect, const bool leftMouse = false);
void waitUntilKeyPressed();
#endif // SDL_UTILS_H_
