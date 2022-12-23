#include "Rect.h"
#include "SDL.h"
#include <vector>
#include <iostream>
#include "text.h"

Rect::Rect(const Window &window,int w,int h,int x,int y,int r, int g, int b,int a):
    Window(window),_w(w),_h(h),_x(x),_y(y),_r(r),_g(g),_b(b),_a(a)
    {

    }
Rect::~Rect()
{

}
void Rect::draw() const
{
    SDL_Rect rect;
    rect.w=_w;
    rect.h=_h;
    rect.x=_x;
    rect.y=_y;
    SDL_SetRenderDrawColor(_renderer,_r,_g,_b,_a);
    SDL_RenderFillRect(_renderer,&rect);
}

bool Rect::touch(std::vector<Rect*> vect)
{
    state=false;
grounded=false;
for (Rect * const&rect1 : vect)
{
      int y=_y;
      int x=_x-(_vx);
    if( (x<(rect1->_x+rect1->_w)) && ((x+_w)>rect1->_x ) && (y<(rect1->_y+rect1->_h)) && ((_h+y)>rect1->_y))
       {
                   _vx=0;
       }
       y=_y-_vy-1;
       x=_x;
   if( (x<(rect1->_x+rect1->_w)) && ((x+_w)>rect1->_x ) && (y<(rect1->_y+rect1->_h)) && ((_h+y)>rect1->_y))
       {
           _vy=0;
            state=true;
            if (_y<rect1->_y)
                last_y=-1*(rect1->_y-(_y+_h));
            else
                last_y=(_y-(rect1->_y+rect1->_h));
       }

         int h=_h/4;
         y=_y+(3*h)+5;
         x=_x;
    if( (_x<(rect1->_x+rect1->_w)) && ((x+_w)>rect1->_x ) && (y<(rect1->_y+rect1->_h)) && ((h+y)>rect1->_y))
       {
                   grounded=true;
        }

}
   vect.clear();
return state;
}

void Rect::move_rects(std::vector<Rect*> vect) {

        for (Rect * const&rect1 : vect)
        {
            rect1->_x += _vx;
            rect1->_y += _vy;
        }
        if (state==true) {
                _vy=0;
                std::cout<<last_y<<std::endl;
                for (Rect * const&rect2 : vect)
                {
                    rect2->_y=rect2->_y+last_y;
                }
            }
            vect.clear();
}

void Rect::move_rects_gravity_up(std::vector<Rect*> vect) {

        for (Rect * const&rect1 : vect)
        {
            rect1->_x += _vx;
            rect1->_y -= _vy;
        }
        if (state==true) {
                _vy=0;
                std::cout<<last_y<<std::endl;
                for (Rect * const&rect2 : vect)
                {
                    rect2->_y=rect2->_y+last_y;
                }
            }
            vect.clear();
}

const Uint8 *keystate;
void Rect::keys()
{

    keystate=SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_A]==1)
    {
        _vx=10;
    }
    else if (keystate[SDL_SCANCODE_D]==1)
    {
        _vx=-10;
    }
    else
    {
        _vx=0;
    }
    if ((keystate[SDL_SCANCODE_W]==1)&&(grounded==true) )
    {
         _vy=25;

    }
    if (grounded==false)
    {
        _vy=_vy-1;
    }
}


