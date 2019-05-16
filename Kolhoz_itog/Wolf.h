#pragma once
#pragma once
#include "Header.h"
#include <iostream>
using namespace std;

class Wolf : public Unit
{
public:
	int nameRab = 44;
	int nameWolfPrint = 5;
	int HP1 = 10;
	int LP1 = 1;
	int X1;
	int Y1;
	int newX;
	int newY;
	int full = 0;
	int status = 0;

	bool isAlive1 = 1;


	virtual void Live() override
	{
		//int l = rand() % 3;


		LP1++;
		//newX += l;
		//newY += l;

	}
	virtual int GetFull() override
	{
		return full;
	}
	virtual void SetFull() override
	{
		this->full = 1;
	}

	virtual int print()override
	{
		return nameWolfPrint;
		//return LP1;
	}
	virtual int GetLP()override
	{
		return LP1;
	}

	virtual int GetX() override
	{
		return X1;
	}
	virtual int GetY() override
	{
		return Y1;
	}
	virtual int GetNewX() override
	{
		return newX;
	}
	virtual int GetNewY() override
	{
		return newY;
	}
	virtual void SetXY(int x, int y) override
	{
		this->X1 = x;
		this->Y1 = y;
	}

	virtual int GetName() override
	{
		return nameRab;
	}
	virtual int GetStatus()
	{
		return status;
	}
	virtual void SetStatus() override
	{
		this->status = 1;
	}
	virtual void DelStatus() override
	{
		this->status = 0;
	}
	virtual int GetisAlive()
	{
		return isAlive1;
	}
	int Life(int i, int j) override
	{
		return 1;
	}
};