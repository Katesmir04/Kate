#pragma once

//#include "Unit.h"
//#include "Role.h"
#include <iostream>
#include <ctime>

//using namespace std;
const int size1 = 1000;

//extern Unit er;

class Field
{
public:
	Unit * playGround[size1][size1];
	int asdf;
	int maxNumber = 10;
	int foodNumber = 300;
	int matNumber = 1000;
	int minMat = 500;
	int loot = 300;
	Field()
	{
		asdf = size1;
	}

	int GetSize()
	{
		//int i = size1;
		return asdf;
	}
	// йнкхвеярбн лспюбэеб
	int GetNumber()
	{
		return maxNumber;
	}
	void IncreaseNumber()
	{
		maxNumber++;
	}
	void DecreaseNumber()
	{
		maxNumber--;
	}

	//йнккхвеярбн едш
	int GetFood()
	{
		return foodNumber;
	}
	void IncreaseFood()
	{
		foodNumber++;
	}
	void DecreaseFood()
	{
		foodNumber--;
	}
	//йнкхвеярбн люрепхюкнб
	int GetMat()
	{
		return matNumber;
	}
	void IncreaseMat()
	{
		matNumber++;
	}
	void DecreaseMat()
	{
		matNumber--;
	}
	int GetMinMat()
	{
		return minMat;
	}


	int GetLoot()
	{
		return loot;
	}
	void IncreaseLoot()
	{
		loot++;
	}
	void DecreaseLoot()
	{
		loot--;
	}

};
