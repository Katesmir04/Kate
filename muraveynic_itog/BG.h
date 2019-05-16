/*#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Unit.h"
//#include "Role.h"
#include "RoleBaby.h"
#include "RoleBabySitter.h"

using namespace sf;

class BackGround : public Unit
{
public:
Sprite sprite;
Texture texture;
Role * rt;
int X;
int Y;
int name = 9;
BackGround()
{

}
BackGround(int x, int y)
{
texture.loadFromFile("BackGround.png");
sprite.setTexture(texture);
sprite.setPosition(x, y);
this->X = x;
this->Y = y;
std::cout << "utututututut";

}
virtual int GetName() override
{
return name;
}
virtual void SetXY(int x, int y) override
{
this->X = x;
this->Y = y;
}
virtual int GetX() override
{
return X;
}
virtual int GetY() override
{
return Y;
}

virtual int changeProf(int x, int y) override
{
return -1;
}

virtual Sprite GetSprite() override
{
return this->sprite;
}
virtual Role * GetRole() override
{
return rt;
}

virtual void Live() override
{
LP++;
}

virtual void print() override
{
}

virtual int GetLP() override
{
return 0;
}

virtual void SetSpritePosition(int i, int j) override
{

}
};
*/