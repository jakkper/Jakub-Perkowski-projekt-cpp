#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "headers\Window.h"
#include "headers/Rect.h"
#include <vector>
#include "headers\text.h"
#include "headers\other.h"

using namespace std;


int main(int argc, char *argv[])
{
    Window window("Notebook runner",1200,900);
   Rect player(window,80,150,560,375,0,0,155,255);

    Rect flor(window,500,100,0,500,0,155,0,255);
    Rect wall(window,500,100,-300,400,155,0,0,255);
    Rect wall2(window,500,100,-300,0,155,0,0,255);

    Rect hitbox_1(window,500,800,1600,-400,155,0,0,255);
//PRZYSPIESZENIE ZIEMSKIE – PRZYSPIESZENIE GRAWITACYJNE CIA£ SWOBODNIE SPADAJ¥CYCH NA ZIEMIÊ, BEZ OPORÓW RUCHU
    Text text(window.render(),0,400, "fonts/Blokletters-Balpen.ttf",75,"PRZYSPIESZENIE GRAWITACYJNE CIA£ SWOBODNIE", {0,0,0,255});
    Text text1(window.render(),0,0, "fonts/Blokletters-Balpen.ttf",75,"PRZYSPIESZENIE ZIEMSKIE", {0,0,0,255});
    Text text2(window.render(),500,-500, "fonts/Blokletters-Balpen.ttf",75,"SPADAJ¥CYCH NA ZIEMIÊ, BEZ OPORÓW RUCHU", {0,0,0,255});

    vector<Rect*> walls;

    vector<Rect*> hitboxes;
    hitboxes.push_back(&hitbox_1);

    vector<Text*> texts;
    texts.push_back(&text);
    texts.push_back(&text1);
    texts.push_back(&text2);


   // walls.push_back(&flor);
    //walls.push_back(&flor2);

    while (!window.isClosed())
    {
        player.keys();


        if(!collision(&player,hitboxes))
        {
            player.touch(walls);
            touch_text(&player,texts);

            move_texts(&player,texts);
            player.move_rects(walls);
            player.move_rects(hitboxes);
            window.w_clear_C(player.velocity_x(),player.velocity_y(),player.last_y,player.state);
        }
        else
        {
            player.touch(walls);
            touch_text_gravity_up(&player,texts);
            move_texts_gravity_up(&player,texts);
            player.move_rects_gravity_up(hitboxes);
            window.w_clear_C(player.velocity_x(),-1*player.velocity_y(),player.last_y,player.state);
        }


        window.pollEvents();

      // window.w_clear();
        text.display(window.render());

        for (Text * const&tx : texts)
        {
            tx->display(window.render());
        }

        for (Rect * const&rect1 : walls)
        {
            rect1->draw();
        }
        for (Rect * const&rect1 : hitboxes)
        {
            rect1->draw();
        }
        player.draw();
        window.w_present();
    }


    return 0;
}

// jfdikjvoerjf