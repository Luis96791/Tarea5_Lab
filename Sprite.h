#ifndef SPRITE_H
#define SPRITE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include "Hitbox.h"
#include "Hitbox2.h"
#include "Utility.h"
using namespace std;

class Sprite
{
    public:
        int frames;
        vector<Hitbox*>hitboxes;
        vector<Hitbox2*>hitboxes2;//guarda las hitboxes azules
        SDL_Texture *texture;
        SDL_Rect rect;
        SDL_Renderer* renderer;
        Sprite(SDL_Renderer* renderer,string path,int frames,int align_x,int align_y,vector<Hitbox*>hitboxes,vector<Hitbox2*>hitboxes2);
        //va de parametro en las hitboxes azules
        virtual ~Sprite();
        void draw(int character_x, int character_y,bool flipped);
    protected:
    private:
};

#endif // SPRITE_H
