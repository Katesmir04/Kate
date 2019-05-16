#include "stdafx.h"
#include "Kapusta.h"

int Kapusta::Life(int i, int j)
{
	if (LP1 < hpk)
	{
		if ((LP1 == sk[3]) || (LP1 == sk[4]) || (LP1 == sk[5]))
		{
			this->Live();
			return 2;
		}
		else
		{
			this->Live();
			return 0;
		}
	}
	else
	{
		//playGround[i][j] = nullptr;
		return 1;
	}
}