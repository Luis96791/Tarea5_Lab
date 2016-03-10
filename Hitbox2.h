#ifndef HITBOX2_H
#define HITBOX2_H

#include<SDL2/SDL.h>

class Hitbox2
{
    public:
        SDL_Rect rect;
        Hitbox2(int x, int y, int w, int h);
        virtual ~Hitbox2();
    protected:
    private:
};

#endif
