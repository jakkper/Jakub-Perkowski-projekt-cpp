#include "text.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Window.h"
#include <string>


Text::Text(SDL_Renderer *renderer,int x,int y, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color):
    _x(x),_y(y), _font_size(font_size)
{
    _text_texture=loadFont(renderer,font_path,font_size,message_text,color);
    SDL_QueryTexture(_text_texture,nullptr,nullptr,&_text_rect.w,&_text_rect.h);
    _h=_font_size*1.1;;
    _w=_text_rect.w;
}

void Text::display(SDL_Renderer *renderer)  const
{
    _text_rect.x=_x;
    _text_rect.y=_y;
    SDL_RenderCopy(renderer,_text_texture,nullptr,&_text_rect);
}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer,const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color)
{
    TTF_Font *font =TTF_OpenFont(font_path.c_str(),font_size);
    auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
    auto text_texture =SDL_CreateTextureFromSurface(renderer,text_surface);
    SDL_FreeSurface(text_surface);
    return text_texture;
}


























