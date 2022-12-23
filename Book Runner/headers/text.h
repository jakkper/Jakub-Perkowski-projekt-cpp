#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include "Window.h"
#include "Rect.h"

class Text
{
    public:
    Text(SDL_Renderer *renderer,int x,int y,const std::string &font_path, int font_size, const std::string &message_text,  const SDL_Color &color);

    void display(SDL_Renderer *renderer)  const;
    int height() const {return _h;}
    static SDL_Texture *loadFont(SDL_Renderer *renderer,const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);
    int _x=0;
    int _y=0;
     int _w=0;
    int _h=0;
    int _font_size=0;
private:
    SDL_Texture *_text_texture = nullptr;
    mutable SDL_Rect _text_rect;
};
