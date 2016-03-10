#include "Hitbox2.h"

Hitbox2::Hitbox2(int x, int y, int w, int h)
{
    this->rect.x=x;
    this->rect.y=y;
    this->rect.w=w;
    this->rect.h=h;
}

Hitbox2::~Hitbox2()
{
    //dtor
}

