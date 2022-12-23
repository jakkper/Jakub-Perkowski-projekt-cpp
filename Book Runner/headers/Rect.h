#pragma once
#include <iostream>
#include <vector>
#include "Window.h"
#include "text.h"

class Rect : public Window
{
public:
    Rect(const Window &window,int w,int h,int x,int y,int r, int g, int b,int a);
    ~Rect();

    void keys();
    void draw() const;
    bool touch(std::vector<Rect*> vect);
    void unmove();
    void move_rects(std::vector<Rect*> vect);
    void move_rects_gravity_up(std::vector<Rect*> vect);
    int velocity_x() const {return _vx;}
    int velocity_y() const {return _vy;}

    int get_last_y() const {return last_y;}
    bool get_state() const {return state;}
    void vy_0() {_vy=0;}
        int get_y() const {return _y;}


    int last_x=0,last_y=0;
        int _vy=0, _vx=0;
        int _x=0,_y=0;
         int _w=0,_h=0;
        bool grounded=true;
        bool state=false;
private:
    int _r=0,_g=0,_b=0, _a=0;
};
