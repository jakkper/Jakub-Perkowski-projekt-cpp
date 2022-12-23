#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "Window.h"
#include "Rect.h"

Window::Window(const std::string &title,int width, int height):
    _title(title), _width(width), _height(height)
    {
        if (!init())
        {
            _closed=true;
        }
    }

Window::~Window()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
    TTF_Quit();
}
bool Window::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        std::cerr<<"Failed\n";
        return 0;
    }
        TTF_Init();
    _window=SDL_CreateWindow(_title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_width,_height,0);

    _renderer=SDL_CreateRenderer(_window,-1,SDL_RENDERER_PRESENTVSYNC);

    return true;

}
void Window::pollEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            _closed=true;
            break;
        defult:
            break;
        }
    }
}

void Window::w_clear() const
{
    SDL_SetRenderDrawColor(_renderer,225, 230, 226,255);
    SDL_RenderClear(_renderer);
}

void Window::w_clear_C(int vx,int vy,int last_y,bool state)
{
    SDL_SetRenderDrawColor(_renderer,225, 230, 226,255);
    SDL_RenderClear(_renderer);

    SDL_Rect line;
    line.w=3;
    line.h=900;
    _shiftx=_shiftx+vx;
    int xx=-600;
    while (xx<2400)
    {
    line.x=xx+_shiftx;
    line.y=0;
    SDL_SetRenderDrawColor(_renderer,147, 158, 189,200);
    SDL_RenderFillRect(_renderer,&line);
    xx=xx+50;
    }
   line.w=1200;
    line.h=3;
    if (state)
    _shifty=_shifty+vy+last_y;
    else
        _shifty=_shifty+vy;
    int yy=-1000;
while (yy<2400)
    {
    line.y=yy+_shifty;
    line.x=0;
    SDL_SetRenderDrawColor(_renderer,147, 158, 189,200);
    SDL_RenderFillRect(_renderer,&line);
    yy=yy+50;
    }
}

void Window::w_present() const
{
        SDL_RenderPresent(_renderer);
}

