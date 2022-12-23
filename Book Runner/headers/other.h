
#ifndef PLAYER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define PLAYER_H

#include "iostream"
#include "Rect.h"
#include "text.h"

void move_texts(Rect *rect, std::vector<Text*> vect);
void move_texts_gravity_up(Rect *rect, std::vector<Text*> vect);
void touch_text(Rect *rect, std::vector<Text*> vect);
void touch_text_gravity_up(Rect *rect, std::vector<Text*> vect);

   void gravity_rect(Rect *rect,std::vector<Text*> vect);

void vector_Rect_delete(std::vector<Rect*> v);
void vector_Text_delete(std::vector<Text*> v);

bool collision(Rect *rect,std::vector<Rect*> vect);
void move_hitboxes(Rect *rect, std::vector<Rect*> vect);



void first_level_start(SDL_Renderer *renderer);

#endif
