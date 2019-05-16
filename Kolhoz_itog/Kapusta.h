#include "Header.h"
#include <iostream>
using namespace std;

class Kapusta : public Unit
{
public:
	int nameKap = 22;
	int nameKapPrint = 2;
	int HP1 = 10;
	int LP1 = 1;
	int X1;
	int Y1;
	int newX;
	int newY;
	int full = 0;
	bool isAlive1 = 1;
	bool status = 0;

	int sk[3] = { 5,7,8 }; //Моменты спавна
	int hpk = 10;


	virtual ~Kapusta() override
	{

	}

	virtual void Live() override
	{
		LP1++;
	}


	virtual int print()override
	{
		return nameKapPrint;
	}
	virtual int GetLP()override
	{
		return LP1;
	}
	virtual int GetStatus()
	{
		return status;
	}
	virtual void DelStatus() override
	{
		this->status = 0;
	}
	virtual int GetisAlive()
	{
		return isAlive1;
	}
	virtual int GetX() override
	{
		return X1;
	}
	virtual int GetY() override
	{
		return Y1;
	}

	virtual void SetXY(int x, int y) override
	{
		this->X1 = x;
		this->Y1 = y;
	}

	virtual int GetName() override
	{
		return nameKap;
	}
	virtual int GetNewX() override
	{
		return newX;
	}
	virtual int GetNewY() override
	{
		return newY;
	}
	virtual int GetFull() override
	{
		return full;
	}
	virtual void SetFull() override
	{
		this->full = 1;
	}
	virtual void SetStatus() override
	{
		this->status = 1;
	}

	int Life(int i, int j) override;
};