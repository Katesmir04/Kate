#pragma once
/*#include "Field.h"
#include "Unit.h"*/
#include "RoleBaby.h"
#include "Warrior.h"
#include "CarryFood.h"
#include "CarryStaff.h"
#include "Cleaner.h"
#include "Herd.h"
#include "RoleBabySitter.h"
#include"Role.h"
#include <SFML/Graphics.hpp>
#include <iostream>
extern Field* field;

using namespace sf;
using namespace std;

class Ant : public Unit
{
public:
	Sprite sprite;
	int X;
	int Y;
	int name = 7;
	int carry = rand() % 2;
	int strong = rand() % 2;
	Role * role;

	Texture texture;

	int LP = 1;

	Ant(Texture &image, int x, int y)
	{
		sprite.setTexture(image);

		sprite.setPosition(x, y);

		RoleBaby * asdf = new RoleBaby();
		role = asdf;
		//cout << role;

		std::cout << "New baby!" << std::endl;
		this->X = x;
		this->Y = y;
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
	virtual ~Ant() override
	{

	}

	virtual int changeProf(int x, int y) override
	{
		role->Work(field, x, y);

		if (LP == 1 || LP == 2)
		{
			RoleBaby * asdf = new RoleBaby();
			this->role = asdf;
			return 0;
		}
		else if (LP == 3)
		{
			texture.loadFromFile("BabySitter.png");

			sprite.setTexture(texture);
			// sprite.setPosition(x,y);

			RoleBabySitter * asdf = new RoleBabySitter();
			this->role = asdf;


			std::cout << "Has become a Sitter" << std::endl;
			//role->Work(field);
			return 0;
		}
		//else if((LP>6)&&(LP<=12))
		else if ((LP == 6) && (strong == 1))
		{
			texture.loadFromFile("RoleWarrior.png");

			sprite.setTexture(texture);
			//sprite.setPosition(x, y);

			Warrior * asdf = new Warrior();
			this->role = asdf;


			std::cout << "Has become a Warrior" << std::endl;
			//role->Work();
			return 0;
		}
		else if ((LP == 6) && (strong == 0))
		{
			texture.loadFromFile("RoleHerd.png");

			sprite.setTexture(texture);
			//sprite.setPosition(x, y);

			Herd * asdf = new Herd();
			this->role = asdf;


			std::cout << "Has become a Herder" << std::endl;
			//role->Work();
			return 0;
		}
		//else if ((LP > 12) && (LP <= 18))
		else if ((LP == 12) && (carry == 0))
		{
			texture.loadFromFile("RoleCarryFood.png");

			sprite.setTexture(texture);
			//sprite.setPosition(x, y);

			CarryFood * asdf = new CarryFood();
			this->role = asdf;


			std::cout << "Has become a Fooder" << std::endl;
			//role->Work();
			return 0;
		}
		else if ((LP == 12) && (carry == 1))
		{
			texture.loadFromFile("RoleCarryStaff.png");

			sprite.setTexture(texture);
			//sprite.setPosition(x, y);

			CarryStaff * asdf = new CarryStaff();
			this->role = asdf;


			std::cout << "Has become a Staffer" << std::endl;
			//role->Work();
			return 0;
		}
		else if (LP == 20)
		{
			texture.loadFromFile("Collector.png");

			sprite.setTexture(texture);
			//sprite.setPosition(x, y);

			Cleaner * asdf = new Cleaner();
			this->role = asdf;


			std::cout << "Has become a Cleaner" << std::endl;
			//role->Work();
			return 0;
		}
		else if (LP == 25)
		{
			std::cout << "слеп" << std::endl;
			return 1;

		}
	}

	virtual Sprite GetSprite() override
	{
		return this->sprite;
	}
	/*virtual Role * GetRole() override
	{

	return role;
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
		return LP;
	}
	virtual void SetSpritePosition(int i, int j) override
	{
		//this->sprite = 0;
		//this->sprite.setPosition(i, j);
		this->sprite.move(i, j);
	}

	virtual void Work() override
	{
		cout << "Sosi" << endl;
		//role->Work(field);

		//role->Work(Field&field);
	}

};