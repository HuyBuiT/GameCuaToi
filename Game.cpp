#include "Game.h"
string img[3][4];
int tmp[3][4] = {};
string tmparray[12];
string yw[3][4];
SDL_Window* window;
SDL_Renderer* renderer;
void Display_hide(int x, int y,SDL_Renderer* renderer){
    SDL_Texture *img1 =loadTexture("img\\hide.png",renderer);
    SDL_Rect img1Rect ;
    SDL_QueryTexture (img1,NULL,NULL, &img1Rect.w,&img1Rect.h);
    img1Rect.x=x;
    img1Rect.y=y;
    SDL_RenderCopy(renderer,img1,NULL,&img1Rect);
    SDL_RenderPresent(renderer);
    }
void Display_img(int x, int y,string path,SDL_Renderer* renderer){
    SDL_Texture *img1 =loadTexture(path.c_str(),renderer);
    SDL_Rect img1Rect ;
    SDL_QueryTexture (img1,NULL,NULL, &img1Rect.w,&img1Rect.h);
    img1Rect.x=x;
    img1Rect.y=y;
    SDL_RenderCopy(renderer,img1,NULL,&img1Rect);
    SDL_RenderPresent(renderer);
}
string GetPath(int x,int y)
{
   int x0=200,y0=150,x1=1000,y1=750;
   int col = (x-x0)*4/(x1-x0);
   int row = (y-y0)*3/(y1-y0);
   return img[row][col];

}
void GetEventFromMouse(SDL_Event e,int &a,int &b){
    while (true) {
        // Đợi 10 mili giây
        SDL_Delay(10);

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặpd
        if ( SDL_WaitEvent(&e) == 0) continue;

        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
        if (e.type == SDL_QUIT) break;

        // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;

        // Nếu chuột (mouse) được nhấn (xuống)
        if (e.type == SDL_MOUSEBUTTONDOWN) {
             a=e.button.x;
             b=e.button.y;
             break;
            }
     }
}
void GetLoca(int &x,int &y)
{
   int x0=200,y0=150,x1=1000,y1=750;
    x = (x-x0)*4/(x1-x0);
    y = (y-y0)*3/(y1-y0);
}
void loadpath()
{
    int k=1;
    int n=0;
    for(int i=0;i<12;i++)
    {
        tmparray[i]="img\\" + to_string(k) + ".png";
        if(k<6)k++;
        else
        {
            k=1;
        }
    }
    random_shuffle(begin(tmparray),end(tmparray));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            img[i][j]=tmparray[n];
            n++;
            yw[i][j]="img\\YouWin_"+to_string(n)+".png";
        }
    }
}
void showgame()
{
    initSDL(window, renderer);
    SDL_Texture *background =loadTexture("img\\bgr.jpg", renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);               //Khoi tao background
    SDL_RenderPresent(renderer);
    int x =200,y=150;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            Display_hide(x,y,renderer);
            x+=200;
        }
        y+=200;
        x=200;
    }
    loadpath();
}
void rungame(Mix_Chunk *flip,Mix_Chunk *correct,Mix_Chunk *win )
{
    SDL_Event e;
    int check=0;
    while(check<6){
        int a,b,c,d;
        while (true)
        {
            GetEventFromMouse(e,a,b);
            GetLoca(a,b);
            if(tmp[b][a]==0)
        {
            tmp[b][a]=1;
            Display_img((a+1)*200,150+b*200,img[b][a],renderer);
            Mix_PlayChannel(-1,flip,0);
        break;
        }
        }
        while(true){
            GetEventFromMouse(e,c,d);
            GetLoca(c,d);
        if(tmp[d][c]==0){
            tmp[d][c]=1;
            Display_img((c+1)*200,150+d*200,img[d][c],renderer);
            if(!Mix_PlayChannel(-1,flip,0)) Mix_PlayChannel(-1,flip,0);
              break;
        }
        }
        SDL_Delay(1000);
        if(img[b][a]==img[d][c]){
            check++;
            Mix_PlayChannel(-1,correct,0);
            SDL_Delay(100);
            Display_img((a+1)*200,150+b*200,yw[b][a],renderer);
            Display_img((c+1)*200,150+d*200,yw[d][c],renderer);
        }
        else {
              Display_hide((c+1)*200,150+d*200,renderer);
              Display_hide((a+1)*200,150+b*200,renderer);
              tmp[b][a]=0;
              tmp[d][c]=0;
        }
    }
    SDL_Delay(500);
    Mix_PlayChannel(-1,win,0);
}
void startgame()
{
    initSDL(window, renderer);
    SDL_Texture *Sbackground =loadTexture("img\\StartBGR.png",renderer);
    SDL_RenderCopy(renderer,Sbackground,NULL,NULL);               //Khoi tao background
    SDL_RenderPresent(renderer);
}
void showrule()
{
    SDL_Texture *Sbackground =loadTexture("img\\Rule.png",renderer);
    SDL_RenderCopy(renderer,Sbackground,NULL,NULL);
    SDL_RenderPresent(renderer);
}

void GetEventFromKey(SDL_Event e,int &a){
    while (true) {
        // Đợi 10 mili giây
        SDL_Delay(10);

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặpd
        if ( SDL_WaitEvent(&e) == 0) continue;

        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
        if (e.type == SDL_QUIT) break;

        // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;

        // Nếu chuột (mouse) được nhấn (xuống)
        if (e.type == SDL_KEYDOWN) {
             a=e.key.keysym.sym;
             break;
            }
     }
}
