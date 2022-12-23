#include "other.h"
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "Window.h"
#include "Rect.h"
#include <vector>
#include "text.h"
#include "other.h"
using namespace std;


void move_texts(Rect *rect, std::vector<Text*> vect)
{
    for (Text * const&text1 : vect)
        {
            text1->_x += rect->velocity_x();
            text1->_y += rect->velocity_y();
        }

         if (rect->get_state()) {
                rect->_vy=0;
                for (Text * const&text2 : vect)
                {
                    text2->_y =text2->_y+ rect->last_y;
                }
            }
    vect.clear();
}

void touch_text(Rect *rect, std::vector<Text*> vect)
{
for (Text * const&text1 : vect)
{
      int y=rect->_y;
      int x=rect->_x-(rect->_vx);
    if( (x<(text1->_x+text1->_w)) && ((x+rect->_w)>text1->_x ) && (y<(text1->_y+text1->_h)) && ((rect->_h+y)>text1->_y))
       {
                   rect->_vx=0;
       }
     y=rect->_y-(rect->_vy-1);
     x=rect->_x;
    if( (x<(text1->_x+text1->_w)) && ((x+rect->_w)>text1->_x ) && (y<(text1->_y+text1->_h)) && ((rect->_h+y)>text1->_y))
       {
                   rect->_vy=0;
                    rect->state=true;
            if (rect->_y<text1->_y)
                rect->last_y=-1*(text1->_y-(rect->_y+rect->_h));
            else
                rect->last_y=(rect->_y-(text1->_y+text1->_h));
       }

         int h=rect->_h/4;
         y=rect->_y+(3*h)+5;
         x=rect->_x;
    if( (rect->_x<(text1->_x+text1->_w)) && ((x+rect->_w)>text1->_x ) && (y<(text1->_y+text1->_h)) && ((h+y)>text1->_y))
       {
                   rect->grounded=true;
        }

}
vect.clear();
}




void move_hitboxes(Rect *rect, std::vector<Rect*> vect)
{
    for (Rect * const&rect1 : vect)
        {
            rect1->_x += rect->velocity_x();
            rect1->_y += rect->velocity_y();
        }

         if (rect->get_state()) {
                rect->_vy=0;
                for (Rect * const&rect2 : vect)
                {
                    rect2->_y += rect->get_last_y();
                }
            }
    vect.clear();
}


void move_texts_gravity_up(Rect *rect, std::vector<Text*> vect)
{
    for (Text * const&text1 : vect)
        {
            text1->_x += rect->velocity_x();
            text1->_y -= rect->velocity_y();
        }

         if (rect->get_state()) {
                rect->_vy=0;
                for (Text * const&text2 : vect)
                {
                    text2->_y += rect->get_last_y();
                }
            }
    vect.clear();
}


void touch_text_gravity_up(Rect *rect, std::vector<Text*> vect)
{
for (Text * const&text1 : vect)
{
      int y=rect->_y;
      int x=rect->_x-(rect->_vx);
    if( (x<(text1->_x+text1->_w)) && ((x+rect->_w)>text1->_x ) && (y<(text1->_y+text1->_h)) && ((rect->_h+y)>text1->_y))
       {
                   rect->_vx=0;
       }
    if( (rect->_x<(text1->_x+text1->_w)) &&
       ((rect->_x+rect->_w)>text1->_x ) && (rect->_y<(text1->_y+text1->_h))
       && ((rect->_h+rect->_y)>text1->_y))
       {
            rect->_vy=0;
                    rect->state=true;
            if (rect->_y<text1->_y)
                rect->last_y=-1*(text1->_y-(rect->_y+rect->_h));
            else
                rect->last_y=(rect->_y-(text1->_y+text1->_h));
       }

         int h=rect->_h/4;
         y=rect->_y-1;
         x=rect->_x;
    if( (rect->_x<(text1->_x+text1->_w)) && ((x+rect->_w)>text1->_x ) && (y<(text1->_y+text1->_h)) && ((h+y)>text1->_y))
       {
                   rect->grounded=true;
        }

}
vect.clear();
}



void gravity_rect(Rect *rect,std::vector<Text*> vect)
{
    rect->grounded=false;
    rect->state=false;
    int h=rect->_h/4;
         int y=rect->_y+(3*h)+5;
         int x=rect->_x;
    for (Text * const&text1 : vect)
{

    if( (rect->_x<(text1->_x+text1->_w)) && ((x+rect->_w)>text1->_x ) && (y<(text1->_y+text1->_h)) && ((h+y)>text1->_y))
       {
           rect->_vy=0;
                   rect->grounded=true;
        }

if( (rect->_x<(text1->_x+text1->_w)) &&
       ((rect->_x+rect->_w)>text1->_x ) && (rect->_y<(text1->_y+text1->_h))
       && ((rect->_h+rect->_y)>text1->_y))
       {
            rect->state=true;
            if (rect->_y<text1->_y)
                rect->last_y=(rect->_y+rect->_h)-text1->_y;
            else
                rect->last_y=-1*((text1->_y+text1->_h)-rect->_y);
       }
}

    for (Text * const&text2 : vect)
{
    text2->_y+=rect->last_y;
}
if (rect->grounded==false)
    {
    rect->_vy=rect->_vy+1;
    }
else
    rect->_vy=0;
rect->_y=rect->_y+rect->_vy;
}

bool collision(Rect *rect,std::vector<Rect*> vect)
{
bool _collision=false;
for (Rect * const&rect1 : vect)
{
    if( (rect->_x<(rect1->_x+rect1->_w)) &&
       ((rect->_x+rect->_w)>rect1->_x ) && (rect->_y<(rect1->_y+rect1->_h))
       && ((rect->_h+rect->_y)>rect1->_y))
       {
            _collision=true;
       }
}

return _collision;
}
