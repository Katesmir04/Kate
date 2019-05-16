#pragma once

//#include "Role.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Field.h"
using namespace sf;

class Unit
{
public:
	Sprite sprite;
	FloatRect rect;
	//Role * role;
	Texture texture;

	int X;
	int Y;
	virtual ~Unit()
	{

	}
	int LP;
	virtual void SetXY(int x, int y) = 0;
	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual void print() = 0;
	virtual int changeProf(int x, int y) = 0;
	virtual void Live() = 0;
	virtual Sprite GetSprite() = 0;
	virtual int GetName() = 0;
	virtual int  GetLP() = 0;
	virtual void SetSpritePosition(int i, int j) = 0;
	//virtual Role * GetRole() = 0;
	virtual void Work() = 0;

};