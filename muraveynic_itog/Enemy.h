#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Unit.h"


using namespace std;
using namespace sf;

class Enemy:public Unit
{
	int name = 77;

public:
	Enemy()
	{
		texture.loadFromFile("Enemy.png");

	};

	~Enemy();

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
	/*virtual Role * GetRole() override
	{
	return rt;
	} */

	virtual void Live() override
	{
		LP++;
	}

	virtual void print() override
	{
	}

	virtual int GetLP() override
	{
		return 2;
	}

	virtual void SetSpritePosition(int i, int j) override
	{

	}
	virtual void Work() override
	{
		cout << "Sosi" << endl;
		//role->Work(field);
	}


};

