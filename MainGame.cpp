#include<iostream>
#include "Game.h"

int main (int argc, char* argv[]){
    SDL_Window* window;
    SDL_Renderer* renderer;
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0){
        cout<<"Error "<<Mix_GetError()<<endl;
    }
    Mix_Music *bgm =Mix_LoadMUS("mix\\bgm.mp3");
    Mix_Chunk *flip=Mix_LoadWAV("mix\\flip.wav");
    Mix_Chunk *correct=Mix_LoadWAV("mix\\correct.wav");
    Mix_Chunk *win=Mix_LoadWAV("mix\\win.wav");
    startgame(window,renderer);
    if(!Mix_PlayingMusic()) Mix_PlayMusic(bgm,-1);
    SDL_Event e;
    while(true){
        int Number_of_key;
    GetEventFromKey(e,Number_of_key);
    if(Number_of_key==115){
        showgame(window,renderer);
        rungame(flip,correct,win,window,renderer);
        }
    if(Number_of_key==114){
        showrule(window,renderer);
        }
    if(Number_of_key==32){
        quitSDL(window, renderer);
        break;
        }
    }
    return 0;
}

