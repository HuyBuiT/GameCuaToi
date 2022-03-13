#include<iostream>
#include<SDL.h>
#include<windows.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_events.h>
using namespace std;
const int SCREEN_HEIGHT=700;
const int SCREEN_WIDTH=950;
const int SCREEN_BPP =320;
 int x =SCREEN_WIDTH/2;
 int y =SCREEN_HEIGHT/2;
const int step =40;
SDL_Surface *g_screen = NULL;
SDL_Surface *g_background =NULL;
SDL_Event g_event;
const string WINDOW_TITLE = "Memory Card";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();
SDL_Texture* loadTexture( string path,SDL_Renderer* renderer);
void draw(SDL_Renderer *renderer,int x,int y){
    SDL_Rect rect;
    rect.x=x;
    rect.y=y;
    rect.w=20;
    rect.h=20;
    SDL_SetRenderDrawColor(renderer,255,0,0,0);
    SDL_RenderDrawRects(renderer,&rect,2);
    SDL_RenderPresent(renderer);
}
int main (int argc, char* argv[]){
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    SDL_Texture *background =loadTexture("backgr.jpg", renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);               //Khoi tao background
    SDL_RenderPresent(renderer);

    SDL_Event e;                                                //bắt sự kiện từ bàn phím và chuột
    while (true) {
        if ( SDL_WaitEvent(&e) == 0 ) SDL_Delay(100);
        else if (e.type==SDL_QUIT ) break;
        else if (e.type==SDL_KEYDOWN){
            cerr<<"_"<<SDL_GetKeyName(e.key.keysym.sym)<<"_"<<endl;
            switch(e.key.keysym.sym){
                case SDLK_UP:
                     y-=step;
                     break;
                case SDLK_DOWN:
                    y+=step;
                    break;
                case SDLK_LEFT:
                    x-=step;
                    break;
                case SDLK_RIGHT:
                    x+=step;
                    break;
            }
            draw(renderer,x,y);
        }
        else if (e.type==SDL_MOUSEBUTTONDOWN){
        if (e.button.button==SDL_BUTTON_LEFT){
            cerr<<"Chuot trai"<<endl;
            }
        else if (e.button.button==SDL_BUTTON_RIGHT){
            cerr<<"Chuot phai"<<endl;
            }
        }
    }


    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
SDL_Texture* loadTexture(string path,SDL_Renderer* renderer){
    SDL_Texture*newTexture=nullptr;
    SDL_Surface* loadedSurface=IMG_Load(path.c_str());
    if(loadedSurface==nullptr)
        cout<<"Unable to load image "<< path<<" SDL_Image Error "
            <<IMG_GetError()<<endl;

        else {
            newTexture =SDL_CreateTextureFromSurface( renderer, loadedSurface);
            if(loadedSurface==nullptr)
                cout<<" Unable to create texture from "<<path<<" SDL Error: "
                    <<SDL_GetError()<<endl;
                    SDL_FreeSurface(loadedSurface);

        }
        return newTexture;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
