 #pragma once

#include <string>
#include "SDL.h"

class Window {
public:
    Window(const std::string &title,int width, int height);
    ~Window();
    void pollEvents();
    void w_clear() const;
    void w_clear_C(int vx,int vy,int last_y,bool state);
    void w_present() const;

    bool isClosed() const {return _closed;}

    int height() const {return _height;}

    SDL_Renderer *render() const {return _renderer;}
private:
    std::string _title;
    bool _closed=false;
    bool init();
        int _shiftx=0;
        int _shifty=0;

    SDL_Window *_window=nullptr;
protected:
    SDL_Renderer *_renderer=nullptr;
    int _width=600;
    int _height=400;
};

