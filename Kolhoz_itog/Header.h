#pragma once

class Unit
{
public:

	static const int HP = 10;
	static const bool isAlive = true;
	static const int LP = 1;
	virtual ~Unit()
	{

	};
	virtual int print() = 0;
	virtual void Live() = 0;
	virtual int GetStatus() = 0;
	virtual void SetStatus() = 0;
	virtual void DelStatus() = 0;
	virtual int GetisAlive() = 0;
	virtual int GetLP() = 0;
	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual int GetNewX() = 0;
	virtual int GetNewY() = 0;
	virtual int GetName() = 0;
	virtual int GetFull() = 0;
	virtual void SetFull() = 0;
	virtual void SetXY(int x, int y) = 0;
	static const int name = 0;
	virtual int Life(int i, int j) = 0;
};