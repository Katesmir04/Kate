#pragma once
#include "stdafx.h"
#include "Unit.h"
#include "Field.h"
#include "Ant.h"
#include "Role.h"
#include "Stick.h"
#include "Berry.h"
#include "Enemy.h"

#include "RoleBaby.h"
#include "RoleBabySitter.h"
#include "Warrior.h"
#include "CarryFood.h"
#include "CarryStaff.h"
#include "Herd.h"
#include "Cleaner.h"

#include <iostream>
#include <Windows.h>

#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;
//1300,900
RenderWindow window(VideoMode(600, 600), "SFML works!");
Field * field = new Field();
Texture startT;

void Move(int x, int y);
void Spawn();
void SpawnStick();
void SpawnBerry();
void DelMyr();

int sx, sy;
int b;
int main()
{

	setlocale(LC_ALL, "Russian");
	Texture back;
	back.loadFromFile("background11.jpg");

	Texture mur;
	mur.loadFromFile("tttt12.png");

	Texture enemy;
	enemy.loadFromFile("En.png");

	startT.loadFromFile("startT.png");
	//startT.loadFromFile("Prov.png");

	srand(time(NULL));
	int n = 5;
	/*
	for (int i = 0; i < field->GetSize(); i++)
	{
	for (int j = 0; j < field->GetSize(); j++)
	{
	if ((i == 0) && (j == 0))
	{
	window.draw(field->playGround[i][j]->GetSprite());
	}
	}

	} */


	//field->playGround[0][0] = new Ant(startT, 5, 5);
	//field->playGround[5][5]->role-> Work(*field);



	//Move(5, 5);

	//_getwch();
	for (int i = 0; i < field->GetNumber(); i++)
	{
		int x = rand() % 300;
		int y = rand() % 300;

		if (field->playGround[x][y] == nullptr)
		{
			field->playGround[x][y] = new Ant(startT, x, y);
			window.draw(field->playGround[x][y]->GetSprite());
		}

	}

	for (int i = 0; i < 10; i++)
	{
		int x = 50 + rand() % 400;
		int y = 50 + rand() % 400;

		if (field->playGround[x][y] == nullptr)
		{
			field->playGround[x][y] = new Stick(x, y);
			window.draw(field->playGround[x][y]->GetSprite());
		}

	}

	for (int i = 0; i < 12; i++)
	{
		int x = 50 + rand() % 400;
		int y = 50 + rand() % 400;

		if (field->playGround[x][y] == nullptr)
		{
			field->playGround[x][y] = new Berry(x, y);
			window.draw(field->playGround[x][y]->GetSprite());
		}

	}

	window.display();
	Sleep(500);
	//_getwch();
	window.clear();
	//_getwch();

	//while (window.isOpen())
	//for (long int i=0; i<1000000000; i++)
	Sprite s;
	Sprite e;
	Sprite q;
	int y = 0;
	while (1 == 1)
	{



		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();
		//fon
		s.setTexture(back);
		s.setPosition(0, 0);
		window.draw(s);

		e.setTexture(enemy);
		e.setPosition(600, 600);
		window.draw(e);

		//field->DecreaseMat();
		//cout << field->GetMat();
		//b += 3;
		int fm = field->GetMat();
		//cout << fm << "sdfffffffffff" << endl;
		q.setTexture(mur);
		q.setPosition(-fm / 3, -fm / 3);
		window.draw(q);
		Sleep(500);
		//_getwch();
		//Смещение мураве	ника
		if (1 == 1)
		{

		}

		/*for (int i = 0; i < field->GetSize(); i++)
		{
		for (int j = 0; j < field->GetSize(); j++)
		{
		if ((i == 0) && (j == 0))
		{
		window.draw(field->playGround[i][j]->GetSprite());
		}
		}

		}*/



		for (int i = 0; i < field->GetSize(); i++)
		{
			for (int j = 0; j < field->GetSize(); j++)
			{
				if ((field->playGround[i][j] != nullptr) && (field->playGround[i][j]->GetName() == 7))
				{
					//field->playGround[i][j]->Work(*field);
					field->playGround[i][j]->Live();


					int f = field->playGround[i][j]->changeProf(i, j);
					if (f == 1)
					{
						field->playGround[i][j] = nullptr;
						field->DecreaseNumber();


					}
					else if (f == 0)
					{
						Move(i, j);

					}
					sx = sy = 0;
					//	_getwch();

				}

			}
		}

		for (int i = 0; i < field->GetSize(); i++)
		{
			for (int j = 0; j < field->GetSize(); j++)
			{
				if ((field->playGround[i][j] != nullptr) && ((field->playGround[i][j]->GetName() == 7) || (field->playGround[i][j]->GetName() == 4)))
				{
					window.draw(field->playGround[i][j]->GetSprite());
				}
			}
		}

		for (int i = 0; i < field->GetSize(); i++)
		{
			for (int j = 0; j < field->GetSize(); j++)
			{
				if ((field->playGround[i][j] != nullptr) && ((field->playGround[i][j]->GetName() == 7) || (field->playGround[i][j]->GetName() == 11)))
				{
					window.draw(field->playGround[i][j]->GetSprite());
				}
			}
		}

		//Spawn();
		//Spawn();
		if (field->GetMat() > 800)
		{
			SpawnStick();
		}

		/*if ((field->GetFood()>300)&&(field->GetFood() <350))
		{
			SpawnBerry();
			//Spawn();
		}*/

		/*if (field->GetFood() > 100)
		{
			SpawnBerry();
		}*/

		if ((field->GetNumber() < 45) && (field->GetFood() > 200))
		{
			SpawnBerry();
			Spawn();
			Spawn();
		}
		//cout << "____Количество муравьев!!!!!>>>>_____" << field->GetNumber() << endl;
		cout <<"____Количество еды_______"<< field->GetFood()<<endl;

		for (int i = 0; i < 2; i++)
		{
			int x = rand() % 600 + 10;
			int y = rand() % 600 + 10;

			if ((field->playGround[x][y] == nullptr)&&(field->GetFood()<165))
			{
				field->playGround[x][y] = new Berry(x, y);
				window.draw(field->playGround[x][y]->GetSprite());
			}
		}



		DelMyr();

		/*
		int t = 1;
		for (int i = 0; i < field->GetSize(); i++)
		{
			for (int j = 0; j < field->GetSize(); j++)
			{
				if ((field->GetFood() < 150)&&(t<2))
				{
					field->playGround[i][j] = nullptr;
					field->DecreaseNumber();
					t++;
				}
			}
		}*/

		//
		//window.draw(field->playGround[sx][sy]->GetSprite());

		window.display();
		field->IncreaseMat();
		field->DecreaseLoot();
		field->DecreaseFood();
		//field->DecreaseFood();
		//_getwch();
	}

	/*
	for (int k = 0; k < 30; k++)
	{
	//Фон

	for (int i = 0; i < field->GetSize(); i++)
	{
	for (int j = 0; j < field->GetSize(); j++)
	{
	if ((i == 0) && (j == 0))
	{
	window.draw(field->playGround[i][j]->GetSprite());
	}
	}

	}

	for (int i = 0; i < field->GetSize(); i++)
	{
	for (int j = 0; j < field->GetSize(); j++)
	{
	if ((field->playGround[i][j] != nullptr) && (field->playGround[i][j]->GetName() == 7))
	{
	field->playGround[i][j]->Live();

	field->playGround[i][j]->changeProf(i, j);

	window.draw(field->playGround[i][j]->GetSprite());

	cout << field->playGround[i][j]->GetLP();

	}
	}
	}

	window.display();
	_getwch();


	} */


	//_getwch();
	return 0;
}

void Move(int x, int y)
{

	int k = rand() % 101 - 25;
	int m = rand() % 101 - 25;

	if ((x + k > 0) && (x + k < field->GetSize()))
	{
		if ((y + m > 0) && (y + m < field->GetSize()))
		{
			if (field->playGround[x + k][y + m] == nullptr)
			{
				Unit * copy;
				copy = field->playGround[x][y];
				field->playGround[x][y]->SetSpritePosition(k, m);
				field->playGround[x][y] = nullptr;
				field->playGround[x + k][y + m] = copy;
				sx = x + k;
				sy = y + m;
			}
		}
	}
	/*
	if ((((x + k) >= 0) || ((x + k) < field->GetSize())) && (((y + m) >= 0) || ((y + m) < field->GetSize())))
	{
	if (field->playGround[x+k][y+m] == nullptr)
	{
	Unit * copy;
	copy = field->playGround[x][y];
	field->playGround[x][y]->SetSpritePosition(k, m);
	field->playGround[x][y] = nullptr;
	field->playGround[x+k][y+m] = copy;
	sx = x + k;
	sy = y + m;
	}
	}
	*/
}


void DelMyr()
{
	int t = 1;
	for (int i = 0; i < field->GetSize(); i++)
	{
		for (int j = 0; j < field->GetSize(); j++)
		{
			if ((field->GetFood() < 150) && (t < 2))
			{
				field->playGround[i][j] = nullptr;
				field->DecreaseNumber();
				t++;
			}
		}
	}
}

void Spawn()
{
	int x = rand() % (field->GetLoot() - 200);
	int y = rand() % (field->GetLoot() - 200);
	if (field->GetMinMat() <= field->GetMat())
	{
		if (field->playGround[x][y] == nullptr)
		{
			field->playGround[x][y] = new Ant(startT, x, y);
			field->IncreaseNumber();
			window.draw(field->playGround[x][y]->GetSprite());
			cout << "Spawn" << endl;
		}
	}
	else
	{
		cout << "too big" << endl;
		exit(1);
	}
}


void SpawnStick()
{
	int x = 50 + rand() % 400;
	int y = 50 + rand() % 400;

	if (field->playGround[x][y] == nullptr)
	{
		field->playGround[x][y] = new Stick(x, y);
		window.draw(field->playGround[x][y]->GetSprite());
	}
}


void SpawnBerry()
{
	//int x = 50 + rand() % 400;
	//int y = 50 + rand() % 400;

	int x = rand() % 650 + 50;      //от 50 до 650 рандом
	int y = rand() % 650 + 50;

	if (field->playGround[x][y] == nullptr)
	{
		field->playGround[x][y] = new Berry(x, y);
		window.draw(field->playGround[x][y]->GetSprite());
	}
}