#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, string path, int frames,int align_x,int align_y,vector<Hitbox*>hitboxes,vector<Hitbox2*>hitboxes2)
{
    this->renderer = renderer;
    texture = IMG_LoadTexture(renderer,path.c_str());
    int w,h;
    SDL_QueryTexture(texture,NULL,NULL,&w,&h);
    rect.w=w;
    rect.h=h;
    rect.x=align_x;
    rect.y=align_y;
    this->frames = frames;
    this->hitboxes=hitboxes;
    this->hitboxes2=hitboxes2;
}

Sprite::~Sprite()
{
    //dtor
}

void Sprite::draw(int character_x, int character_y, bool flipped)
{
    SDL_Rect rect_temp;
    rect_temp.w = rect.w;
    rect_temp.h = rect.h;
    if(flipped)
    {
        rect_temp.x = (-rect.x)+character_x-rect_temp.w/2;
        rect_temp.y = rect.y+character_y-rect_temp.h;
    }else
    {
        rect_temp.x = rect.x+character_x-rect_temp.w/2;
        rect_temp.y = rect.y+character_y-rect_temp.h;
    }

    if(flipped)
    {
        SDL_RenderCopyEx( renderer, texture, NULL, &rect_temp,
                        NULL, NULL, SDL_FLIP_HORIZONTAL );
    }else
    {
        SDL_RenderCopy(renderer, texture, NULL, &rect_temp);
    }

    for(int i=0;i<hitboxes.size();i++)
    {
        if(flipped)
        {
            drawRect(renderer,
                     -hitboxes[i]->rect.x-hitboxes[i]->rect.w+character_x,
                    -hitboxes[i]->rect.y+character_y,
                    hitboxes[i]->rect.w,
                    hitboxes[i]->rect.h,
                     255,0,0,0);
            drawRect(renderer,
                     -hitboxes2[i]->rect.x-hitboxes2[i]->rect.w+character_x,
                    -hitboxes2[i]->rect.y+character_y,
                    hitboxes2[i]->rect.w,
                    hitboxes2[i]->rect.h,
                     0,36,231,255);
        }else
        {
            drawRect(renderer,
                     hitboxes[i]->rect.x+character_x,
                    -hitboxes[i]->rect.y+character_y,
                    hitboxes[i]->rect.w,
                    hitboxes[i]->rect.h,
                     255,0,0,0);
            drawRect(renderer,
                     hitboxes2[i]->rect.x+character_x,
                    -hitboxes2[i]->rect.y+character_y,
                    hitboxes2[i]->rect.w,
                    hitboxes2[i]->rect.h,
                     0,36,231,255);
        }
    }
}


