#pragma once

//#include "Field.h"

class Role
{
public:
	int u;
	//Field * field;
	virtual void Work(Field*field, int i, int j) = 0;
};