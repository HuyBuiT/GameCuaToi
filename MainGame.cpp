#include<iostream>
#include "SDL_utils.h"
using namespace std;
 int x =SCREEN_WIDTH/2;
 int y =SCREEN_HEIGHT/2;
const int step =40;
SDL_Surface *g_screen = NULL;
SDL_Surface *g_background =NULL;
SDL_Event g_event;
SDL_Window* window;
SDL_Renderer* renderer;



SDL_Texture* loadTexture( string path,SDL_Renderer* renderer);

void Display(int x, int y,string path){
    SDL_Texture *img1 =loadTexture(path.c_str(),renderer);
    SDL_Rect img1Rect ;
    SDL_QueryTexture (img1,NULL,NULL, &img1Rect.w,&img1Rect.h);
    img1Rect.x=x;
    img1Rect.y=y;
    SDL_RenderCopy(renderer,img1,NULL,&img1Rect);
    SDL_RenderPresent(renderer);
}
int main (int argc, char* argv[]){

    initSDL(window, renderer);

    SDL_Texture *background =loadTexture("img\\bgr.jpg", renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);               //Khoi tao background
    SDL_RenderPresent(renderer);

    Display(50,100,"img\\hide.png");
    SDL_Event e;
    SDL_Rect filled_rect;
        filled_rect.x = SCREEN_WIDTH / 2;
        filled_rect.y = SCREEN_HEIGHT / 2;
        filled_rect.w = 16;
        filled_rect.h = 12;
     while (true) {
        // Đợi 10 mili giây
        SDL_Delay(10);

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
        if ( SDL_WaitEvent(&e) == 0) continue;

        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
        if (e.type == SDL_QUIT) break;

        // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;

        // Nếu chuột (mouse) được nhấn (xuống)
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            if( e.button.x>50 && e.button.x<250 && e.button.y>100 && e.button.y<300) {
                    Display(50,100,"img//cat2.png");
//                SDL_Texture *img1 =loadTexture("img\\cat1.png",renderer);
//                SDL_Rect img1Rect ;
//                SDL_QueryTexture (img1,NULL,NULL, &img1Rect.w,&img1Rect.h);
//                img1Rect.x=50;
//                img1Rect.y=100;
//                SDL_RenderCopy(renderer,img1,NULL,&img1Rect);
//                SDL_RenderPresent(renderer);
            }
        }

    }

    /*SDL_Texture *img1 =loadTexture("img\\cat1.png",renderer);
    SDL_Rect img1Rect ;
    SDL_QueryTexture (img1,NULL,NULL, &img1Rect.w,&img1Rect.h);
    img1Rect.x=50;
    img1Rect.y=100;
    SDL_RenderCopy(renderer,img1,NULL,&img1Rect);


    SDL_Texture *img2 =loadTexture("img\\cat2.png",renderer);
    SDL_Rect img2Rect ;
    SDL_QueryTexture (img2,NULL,NULL, &img2Rect.w,&img2Rect.h);
    img2Rect.x=300;
    img2Rect.y=100;
    SDL_RenderCopy(renderer,img2,NULL,&img2Rect);
    SDL_RenderPresent(renderer);*/

    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;

}

