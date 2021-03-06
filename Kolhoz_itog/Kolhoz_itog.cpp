#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <ctime>
#include "Header.h"
#include "Kapusta.h"
#include "Rabbit.h"
#include "Wolf.h"
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
const int SIZE1 = 20;
Unit *playGround[SIZE1][SIZE1];
list<Unit*>Turn;
Unit*mas;

Unit * store[3] = { new Kapusta(),new Rabbit(), new Wolf() };
Unit * save;

RenderWindow window(VideoMode(600, 800), "title");

void PrintPlayGround();
void SearchSpawnPlace(int iCurrent, int jCurrent);
void SpawnRab(int iCurrent, int jCurrent);
void SpawnWolf(int iCurrent, int jCurrent);


int viewRangeRab = 1;
int viewRangeWolf = 2;
int killAimX;
int killAimY;
//***************НАСТРОЙКИ*************** 
//Капуста
//Максимальное HP

//Кролик
int hpr = 17;           //Максимальное HP
int sr = 2;            //Момент готовности для размножения
//Волк
int hpw = 20;
int sw = 4;

//*************************************** 
/*int BigLifeKap(int i, int j)
{
if (playGround[i][j]->GetLP() < hpk)
{
if ( (playGround[i][j]->GetLP() == sk[3]) || (playGround[i][j]->GetLP() == sk[4]) || (playGround[i][j]->GetLP() == sk[5]))
{
SearchSpawnPlace(i, j);
playGround[i][j]->Live();
return 0;
}
else
{
playGround[i][j]->Live();
return 0;
}
}
else
{
//playGround[i][j] = nullptr;
return 1;
}
} */

int BigLifeRab(int i, int j)
{
	int l = -1;

	if (playGround[i][j]->GetLP() <= hpr)
	{
		if ((playGround[i][j]->GetLP() >= sr) && (playGround[i][j]->GetFull() == 1) && (playGround[i][j]->GetStatus() == 0))
		{
			//Поиск партнера размножение
			//Справа
			if (i + 1 < SIZE1)
			{
				if (((playGround[i + 1][j] != nullptr) && (playGround[i + 1][j]->GetName() == 33) && (playGround[i + 1][j])->GetFull() == 1) && (playGround[i + 1][j]->GetStatus() == 0))
				{
					SpawnRab(i, j);
					playGround[i][j]->SetStatus();
					playGround[i + 1][j]->SetStatus();
					return 5;
				}
			}
			//Слева
			if (i - 1 >= 0)
			{
				if (((playGround[i - 1][j] != nullptr) && (playGround[i - 1][j]->GetName() == 33) && (playGround[i - 1][j])->GetFull() == 1) && ((playGround[i - 1][j])->GetStatus() == 0))
				{
					SpawnRab(i, j);
					playGround[i][j]->SetStatus();
					playGround[i - 1][j]->SetStatus();
					return 5;
				}
			}
			//Снизу
			if (j + 1 < SIZE1)
			{
				if (((playGround[i][j + 1] != nullptr) && (playGround[i][j + 1]->GetName() == 33) && (playGround[i][j + 1])->GetFull() == 1) && ((playGround[i][j + 1])->GetStatus() == 0))
				{
					SpawnRab(i, j);
					playGround[i][j]->SetStatus();
					playGround[i][j + 1]->SetStatus();
					return 5;
				}
			}
			//Сверху
			if (j - 1 < SIZE1)
			{
				if (((playGround[i][j - 1] != nullptr) && (playGround[i][j - 1]->GetName() == 33) && (playGround[i][j - 1])->GetFull() == 1) && ((playGround[i][j - 1])->GetStatus() == 0))
				{
					SpawnRab(i, j);
					playGround[i][j]->SetStatus();
					playGround[i][j - 1]->SetStatus();
					return 5;
				}
			}
			//----
			if ((i + 1 < SIZE1) && (j + 1<SIZE1))
			{
				if (((playGround[i + 1][j + 1] != nullptr) && (playGround[i + 1][j + 1]->GetName() == 33) && (playGround[i + 1][j + 1])->GetFull() == 1) && (playGround[i + 1][j + 1]->GetStatus() == 0))
				{
					SpawnRab(i, j);
					playGround[i][j]->SetStatus();
					playGround[i + 1][j + 1]->SetStatus();
					return 5;
				}
			}
			if ((i - 1 >= 0) && (j - 1 >= 0))
			{
				if (((playGround[i - 1][j - 1] != nullptr) && (playGround[i - 1][j - 1]->GetName() == 33) && (playGround[i - 1][j - 1])->GetFull() == 1) && (playGround[i - 1][j - 1]->GetStatus() == 0))
				{
					SpawnRab(i, j);
					playGround[i][j]->SetStatus();
					playGround[i - 1][j - 1]->SetStatus();
					return 5;
				}
			}
			if ((i - 1 >= 0) && (j + 1 <SIZE1))
			{
				if (((playGround[i - 1][j + 1] != nullptr) && (playGround[i - 1][j + 1]->GetName() == 33) && (playGround[i - 1][j + 1])->GetFull() == 1) && (playGround[i - 1][j + 1]->GetStatus() == 0))
				{
					SpawnRab(i, j);
					playGround[i][j]->SetStatus();
					playGround[i - 1][j + 1]->SetStatus();
					return 5;
				}
			}
			if ((i + 1 <SIZE1) && (j - 1 >= 0))
			{
				if (((playGround[i + 1][j - 1] != nullptr) && (playGround[i + 1][j - 1]->GetName() == 33) && (playGround[i + 1][j - 1])->GetFull() == 1) && (playGround[i + 1][j - 1]->GetStatus() == 0))
				{
					SpawnRab(i, j);
					playGround[i][j]->SetStatus();
					playGround[i + 1][j - 1]->SetStatus();
					return 5;
				}
			}
			// playGround[i][j]->Live();
			//return 5;
			for (int k = 1; k <= viewRangeRab; k++)
			{
				for (int o = 1; o <= viewRangeRab; o++)
				{
					//if ((((i + k) < SIZE) && ((j + o) < SIZE)) && (((i - k) >=0) && ((j - o) >= 0)))
					if (l == -1)
					{
						//============================================== ВВЕРХ
						if (j - o >= 0)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i][j - o] != nullptr) && (playGround[i][j - o]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i)) && (r->GetY() == (j - o)))
									{
										playGround[i][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i;
								killAimY = j - o;

								return 3;
							}
						}
						//=============================================
						//============================================== НИЗ
						if (j + o < SIZE1)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i][j + o] != nullptr) && (playGround[i][j + o]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i)) && (r->GetY() == (j + o)))
									{
										playGround[i][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i;
								killAimY = j + o;
								return 3;
							}
						}
						//=============================================
						//============================================== ВЛЕВО
						if (i - k >= 0)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i - k][j] != nullptr) && (playGround[i - k][j]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j)))
									{
										playGround[i - k][j] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j;
								return 3;
							}
						}
						//=============================================
						//============================================== ВПРАВО
						if (i + k < SIZE1)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i + k][j] != nullptr) && (playGround[i + k][j]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j)))
									{
										playGround[i + k][j] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j;
								return 3;
							}
						}
						//=============================================
						if ((i + k < SIZE1) && (j + k < SIZE1))
						{
							//Справа снизу
							//=======================================
							if ((playGround[i + k][j + o] != nullptr) && (playGround[i + k][j + o]->GetName() == 22)) //ЕСЛИ СПРАВА СНИЗУ ЕСТЬ КАПУСТА
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j + o)))
									{
										playGround[i + k][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j + o;
								return 3;
							}
						}

						if ((i - k >= 0) && (j - k >= 0))
						{
							//Слева сверху
							//=======================================

							if ((playGround[i - k][j - o] != nullptr) && (playGround[i - k][j - o]->GetName() == 22)) //ЕСЛИ СПРАВА СНИЗУ ЕСТЬ КАПУСТА
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j - o)))
									{
										playGround[i - k][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j - o;
								return 3;
							}
						}

						if ((i - k >= 0) && (j + k < SIZE1))
						{
							//Слева снизу
							//=======================================
							if ((playGround[i - k][j + o] != nullptr) && (playGround[i - k][j + o]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j + o)))
									{
										playGround[i - k][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j + o;
								return 3;
							}
						}

						if ((i + k < SIZE1) && (j - k >= 0))
						{
							//Справа сверху
							//=======================================
							if ((playGround[i + k][j - o] != nullptr) && (playGround[i + k][j - o]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j - o)))
									{
										playGround[i + k][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j - o;
								return 3;
							}

						}

						//Если нечего есть
						int r1 = rand();
						if ((i - k >= 0) && (j - k >= 0) && (playGround[i - k][j - k] == nullptr))
						{
							killAimX = i - 1;
							killAimY = j - 1;
							return 3;
						}
						else if ((j + k < SIZE1) && (playGround[i][j + k] == nullptr)) //Низ
						{
							killAimX = i;
							killAimY = j + k;
							return 3;
						}
						else if ((i - k >= 0) && (j + k < SIZE1) && (playGround[i - k][j + k] == nullptr))
						{
							killAimX = i - 1;
							killAimY = j + 1;
							return 3;
						}
						else if ((i + k < SIZE1) && (playGround[i + k][j] == nullptr))//Право
						{
							killAimX = i + k;
							killAimY = j;
							return 3;
						}
						else if ((i + k < SIZE1) && (j - k >= 0) && (playGround[i + k][j - k] == nullptr))
						{
							killAimX = i + 1;
							killAimY = j - 1;
							return 3;
						}
						else if ((j - k >= 0) && (playGround[i][j - k] == nullptr))//Верх
						{
							killAimX = i;
							killAimY = j - k;
							return 3;
						}
						else if ((i + k < SIZE1) && (j + k < SIZE1) && (playGround[i + k][j + k] == nullptr))
						{
							killAimX = i + 1;
							killAimY = j + 1;
							return 3;
						}
						else if ((i - k >= 0) && (playGround[i - k][j] == nullptr))//Лево
						{
							killAimX = i - k;
							killAimY = j;
							return 3;
						}

						return 1;


						//=======================================
					}
				}
			}

		}
		else
		{

			for (int k = 1; k <= viewRangeRab; k++)
			{
				for (int o = 1; o <= viewRangeRab; o++)
				{
					//if ((((i + k) < SIZE) && ((j + o) < SIZE)) && (((i - k) >=0) && ((j - o) >= 0)))
					if (l == -1)
					{
						//============================================== ВВЕРХ
						if (j - o >= 0)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i][j - o] != nullptr) && (playGround[i][j - o]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i)) && (r->GetY() == (j - o)))
									{
										playGround[i][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i;
								killAimY = j - o;

								return 3;
							}
						}
						//=============================================
						//============================================== НИЗ
						if (j + o < SIZE1)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i][j + o] != nullptr) && (playGround[i][j + o]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i)) && (r->GetY() == (j + o)))
									{
										playGround[i][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i;
								killAimY = j + o;
								return 3;
							}
						}
						//=============================================
						//============================================== ВЛЕВО
						if (i - k >= 0)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i - k][j] != nullptr) && (playGround[i - k][j]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j)))
									{
										playGround[i - k][j] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j;
								return 3;
							}
						}
						//=============================================
						//============================================== ВПРАВО
						if (i + k < SIZE1)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i + k][j] != nullptr) && (playGround[i + k][j]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j)))
									{
										playGround[i + k][j] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j;
								return 3;
							}
						}
						//=============================================
						if ((i + k < SIZE1) && (j + k < SIZE1))
						{
							//Справа снизу
							//=======================================
							if ((playGround[i + k][j + o] != nullptr) && (playGround[i + k][j + o]->GetName() == 22)) //ЕСЛИ СПРАВА СНИЗУ ЕСТЬ КАПУСТА
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j + o)))
									{
										playGround[i + k][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j + o;
								return 3;
							}
						}

						if ((i - k >= 0) && (j - k >= 0))
						{
							//Слева сверху
							//=======================================

							if ((playGround[i - k][j - o] != nullptr) && (playGround[i - k][j - o]->GetName() == 22)) //ЕСЛИ СПРАВА СНИЗУ ЕСТЬ КАПУСТА
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j - o)))
									{
										playGround[i - k][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j - o;
								return 3;
							}
						}

						if ((i - k >= 0) && (j + k < SIZE1))
						{
							//Слева снизу
							//=======================================
							if ((playGround[i - k][j + o] != nullptr) && (playGround[i - k][j + o]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j + o)))
									{
										playGround[i - k][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j + o;
								return 3;
							}
						}

						if ((i + k < SIZE1) && (j - k >= 0))
						{
							//Справа сверху
							//=======================================
							if ((playGround[i + k][j - o] != nullptr) && (playGround[i + k][j - o]->GetName() == 22))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j - o)))
									{
										playGround[i + k][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j - o;
								return 3;
							}

						}

						//Если нечего есть
						int r1 = rand();
						if ((i - k >= 0) && (j - k >= 0) && (playGround[i - k][j - k] == nullptr))
						{
							killAimX = i - 1;
							killAimY = j - 1;
							return 3;
						}
						else if ((j + k < SIZE1) && (playGround[i][j + k] == nullptr)) //Низ
						{
							killAimX = i;
							killAimY = j + k;
							return 3;
						}
						else if ((i - k >= 0) && (j + k<SIZE1) && (playGround[i - k][j + k] == nullptr))
						{
							killAimX = i - 1;
							killAimY = j + 1;
							return 3;
						}
						else if ((i + k < SIZE1) && (playGround[i + k][j] == nullptr))//Право
						{
							killAimX = i + k;
							killAimY = j;
							return 3;
						}
						else if ((i + k<SIZE1) && (j - k >= 0) && (playGround[i + k][j - k] == nullptr))
						{
							killAimX = i + 1;
							killAimY = j - 1;
							return 3;
						}
						else if ((j - k >= 0) && (playGround[i][j - k] == nullptr))//Верх
						{
							killAimX = i;
							killAimY = j - k;
							return 3;
						}
						else if ((i + k<SIZE1) && (j + k<SIZE1) && (playGround[i + k][j + k] == nullptr))
						{
							killAimX = i + 1;
							killAimY = j + 1;
							return 3;
						}
						else if ((i - k >= 0) && (playGround[i - k][j] == nullptr))//Лево
						{
							killAimX = i - k;
							killAimY = j;
							return 3;
						}

						return 1;

						//=======================================
					}
				}
			}
		}
	}
	else
	{
		return 1;
	}
}

int BigLifeWolf(int i, int j)
{
	int l = -1;

	if (playGround[i][j]->GetLP() < hpw)
	{
		if ((playGround[i][j]->GetLP() >= sw) && (playGround[i][j]->GetFull() == 1) && (playGround[i][j]->GetStatus() == 0))
		{
			//Поиск партнера размножение
			//Справа
			if (i + 1 < SIZE1)
			{
				if (((playGround[i + 1][j] != nullptr) && (playGround[i + 1][j]->GetName() == 44) && (playGround[i + 1][j])->GetFull() == 1) && (playGround[i + 1][j]->GetStatus() == 0))
				{
					SpawnWolf(i, j);
					playGround[i][j]->SetStatus();
					playGround[i + 1][j]->SetStatus();
					return 5;
				}
			}
			//Слева
			if (i - 1 >= 0)
			{
				if (((playGround[i - 1][j] != nullptr) && (playGround[i - 1][j]->GetName() == 44) && (playGround[i - 1][j])->GetFull() == 1) && ((playGround[i - 1][j])->GetStatus() == 0))
				{
					SpawnWolf(i, j);
					playGround[i][j]->SetStatus();
					playGround[i - 1][j]->SetStatus();
					return 5;
				}
			}
			//Снизу
			if (j + 1 < SIZE1)
			{
				if (((playGround[i][j + 1] != nullptr) && (playGround[i][j + 1]->GetName() == 44) && (playGround[i][j + 1])->GetFull() == 1) && ((playGround[i][j + 1])->GetStatus() == 0))
				{
					SpawnWolf(i, j);
					playGround[i][j]->SetStatus();
					playGround[i][j + 1]->SetStatus();
					return 5;
				}
			}
			//Сверху
			if (j - 1 < SIZE1)
			{
				if (((playGround[i][j - 1] != nullptr) && (playGround[i][j - 1]->GetName() == 44) && (playGround[i][j - 1])->GetFull() == 1) && ((playGround[i][j - 1])->GetStatus() == 0))
				{
					SpawnWolf(i, j);
					playGround[i][j]->SetStatus();
					playGround[i][j - 1]->SetStatus();
					return 5;
				}
			}
			//----
			if ((i + 1 < SIZE1) && (j + 1 < SIZE1))
			{
				if (((playGround[i + 1][j + 1] != nullptr) && (playGround[i + 1][j + 1]->GetName() == 44) && (playGround[i + 1][j + 1])->GetFull() == 1) && (playGround[i + 1][j + 1]->GetStatus() == 0))
				{
					SpawnWolf(i, j);
					playGround[i][j]->SetStatus();
					playGround[i + 1][j + 1]->SetStatus();
					return 5;
				}
			}
			if ((i - 1 >= 0) && (j - 1 >= 0))
			{
				if (((playGround[i - 1][j - 1] != nullptr) && (playGround[i - 1][j - 1]->GetName() == 44) && (playGround[i - 1][j - 1])->GetFull() == 1) && (playGround[i - 1][j - 1]->GetStatus() == 0))
				{
					SpawnWolf(i, j);
					playGround[i][j]->SetStatus();
					playGround[i - 1][j - 1]->SetStatus();
					return 5;
				}
			}
			if ((i - 1 >= 0) && (j + 1 < SIZE1))
			{
				if (((playGround[i - 1][j + 1] != nullptr) && (playGround[i - 1][j + 1]->GetName() == 44) && (playGround[i - 1][j + 1])->GetFull() == 1) && (playGround[i - 1][j + 1]->GetStatus() == 0))
				{
					SpawnWolf(i, j);
					playGround[i][j]->SetStatus();
					playGround[i - 1][j + 1]->SetStatus();
					return 5;
				}
			}
			if ((i + 1 < SIZE1) && (j - 1 >= 0))
			{
				if (((playGround[i + 1][j - 1] != nullptr) && (playGround[i + 1][j - 1]->GetName() == 44) && (playGround[i + 1][j - 1])->GetFull() == 1) && (playGround[i + 1][j - 1]->GetStatus() == 0))
				{
					SpawnWolf(i, j);
					playGround[i][j]->SetStatus();
					playGround[i + 1][j - 1]->SetStatus();
					return 5;
				}
			}
			//playGround[i][j]->Live();
			//return 5;
			for (int k = 1; k <= viewRangeWolf; k++)
			{
				for (int o = 1; o <= viewRangeWolf; o++)
				{
					//if ((((i + k) < SIZE) && ((j + o) < SIZE)) && (((i - k) >=0) && ((j - o) >= 0)))
					if (l == -1)
					{
						//============================================== ВВЕРХ
						if (j - o >= 0)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i][j - o] != nullptr) && (playGround[i][j - o]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i)) && (r->GetY() == (j - o)))
									{
										playGround[i][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i;
								killAimY = j - o;

								return 3;
							}
						}
						//=============================================
						//============================================== НИЗ
						if (j + o < SIZE1)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i][j + o] != nullptr) && (playGround[i][j + o]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i)) && (r->GetY() == (j + o)))
									{
										playGround[i][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i;
								killAimY = j + o;
								return 3;
							}
						}
						//=============================================
						//============================================== ВЛЕВО
						if (i - k >= 0)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i - k][j] != nullptr) && (playGround[i - k][j]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j)))
									{
										playGround[i - k][j] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j;
								return 3;
							}
						}
						//=============================================
						//============================================== ВПРАВО
						if (i + k < SIZE1)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i + k][j] != nullptr) && (playGround[i + k][j]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j)))
									{
										playGround[i + k][j] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j;
								return 3;
							}
						}
						//=============================================
						if ((i + k < SIZE1) && (j + k < SIZE1))
						{
							//Справа снизу
							//=======================================
							if ((playGround[i + k][j + o] != nullptr) && (playGround[i + k][j + o]->GetName() == 33)) //ЕСЛИ СПРАВА СНИЗУ ЕСТЬ КАПУСТА
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j + o)))
									{
										playGround[i + k][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j + o;
								return 3;
							}
						}

						if ((i - k >= 0) && (j - k >= 0))
						{
							//Слева сверху
							//=======================================

							if ((playGround[i - k][j - o] != nullptr) && (playGround[i - k][j - o]->GetName() == 33)) //ЕСЛИ СПРАВА СНИЗУ ЕСТЬ КАПУСТА
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j - o)))
									{
										playGround[i - k][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j - o;
								return 3;
							}
						}

						if ((i - k >= 0) && (j + k < SIZE1))
						{
							//Слева снизу
							//=======================================
							if ((playGround[i - k][j + o] != nullptr) && (playGround[i - k][j + o]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j + o)))
									{
										playGround[i - k][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j + o;
								return 3;
							}
						}

						if ((i + k < SIZE1) && (j - k >= 0))
						{
							//Справа сверху
							//=======================================
							if ((playGround[i + k][j - o] != nullptr) && (playGround[i + k][j - o]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j - o)))
									{
										playGround[i + k][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j - o;
								return 3;
							}

						}

						//Если нечего есть
						int r1 = rand();
						if ((i - k >= 0) && (j - o >= 0) && (playGround[i - k][j - o] == nullptr))
						{
							killAimX = i - k;
							killAimY = j - o;
							return 3;
						}
						else if ((j + o < SIZE1) && (playGround[i][j + o] == nullptr)) //Низ
						{
							killAimX = i;
							killAimY = j + o;
							return 3;
						}
						else if ((i - k >= 0) && (j + o < SIZE1) && (playGround[i - k][j + o] == nullptr))
						{
							killAimX = i - k;
							killAimY = j + o;
							return 3;
						}
						else if ((i + k < SIZE1) && (playGround[i + k][j] == nullptr))//Право
						{
							killAimX = i + k;
							killAimY = j;
							return 3;
						}
						else if ((i + k < SIZE1) && (j - o >= 0) && (playGround[i + k][j - o] == nullptr))
						{
							killAimX = i + k;
							killAimY = j - o;
							return 3;
						}
						else if ((j - o >= 0) && (playGround[i][j - o] == nullptr))//Верх
						{
							killAimX = i;
							killAimY = j - o;
							return 3;
						}
						else if ((i + k < SIZE1) && (j + o < SIZE1) && (playGround[i + k][j + o] == nullptr))
						{
							killAimX = i + k;
							killAimY = j + o;
							return 3;
						}
						else if ((i - k >= 0) && (playGround[i - k][j] == nullptr))//Лево
						{
							killAimX = i - k;
							killAimY = j;
							return 3;
						}

						return 1;

						//=======================================
					}
				}
			}

		}
		else
		{

			for (int k = 1; k <= viewRangeWolf; k++)
			{
				for (int o = 1; o <= viewRangeWolf; o++)
				{
					//if ((((i + k) < SIZE) && ((j + o) < SIZE)) && (((i - k) >=0) && ((j - o) >= 0)))
					if (l == -1)
					{
						//============================================== ВВЕРХ
						if (j - o >= 0)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i][j - o] != nullptr) && (playGround[i][j - o]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i)) && (r->GetY() == (j - o)))
									{
										playGround[i][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i;
								killAimY = j - o;

								return 3;
							}
						}
						//=============================================
						//============================================== НИЗ
						if (j + o < SIZE1)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i][j + o] != nullptr) && (playGround[i][j + o]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i)) && (r->GetY() == (j + o)))
									{
										playGround[i][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i;
								killAimY = j + o;
								return 3;
							}
						}
						//=============================================
						//============================================== ВЛЕВО
						if (i - k >= 0)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i - k][j] != nullptr) && (playGround[i - k][j]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j)))
									{
										playGround[i - k][j] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j;
								return 3;
							}
						}
						//=============================================
						//============================================== ВПРАВО
						if (i + k < SIZE1)
						{
							//Справа снизу
							//=======================================
							if ((playGround[i + k][j] != nullptr) && (playGround[i + k][j]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j)))
									{
										playGround[i + k][j] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j;
								return 3;
							}
						}
						//=============================================
						if ((i + k < SIZE1) && (j + k < SIZE1))
						{
							//Справа снизу
							//=======================================
							if ((playGround[i + k][j + o] != nullptr) && (playGround[i + k][j + o]->GetName() == 33)) //ЕСЛИ СПРАВА СНИЗУ ЕСТЬ КАПУСТА
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j + o)))
									{
										playGround[i + k][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j + o;
								return 3;
							}
						}

						if ((i - k >= 0) && (j - k >= 0))
						{
							//Слева сверху
							//=======================================

							if ((playGround[i - k][j - o] != nullptr) && (playGround[i - k][j - o]->GetName() == 33)) //ЕСЛИ СПРАВА СНИЗУ ЕСТЬ КАПУСТА
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j - o)))
									{
										playGround[i - k][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j - o;
								return 3;
							}
						}

						if ((i - k >= 0) && (j + k < SIZE1))
						{
							//Слева снизу
							//=======================================
							if ((playGround[i - k][j + o] != nullptr) && (playGround[i - k][j + o]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i - k)) && (r->GetY() == (j + o)))
									{
										playGround[i - k][j + o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i - k;
								killAimY = j + o;
								return 3;
							}
						}

						if ((i + k < SIZE1) && (j - k >= 0))
						{
							//Справа сверху
							//=======================================
							if ((playGround[i + k][j - o] != nullptr) && (playGround[i + k][j - o]->GetName() == 33))
							{

								for (Unit * r : Turn)
								{
									//cout << r->GetX() << endl;
									if ((r->GetX() == (i + k)) && (r->GetY() == (j - o)))
									{
										playGround[i + k][j - o] = nullptr;
										Turn.remove(r);
										playGround[i][j]->SetFull();
										break;

									}
								}
								killAimX = i + k;
								killAimY = j - o;
								return 3;
							}

						}

						//Если нечего есть
						int r1 = rand();
						if ((i - k >= 0) && (j - o >= 0) && (playGround[i - k][j - o] == nullptr))
						{
							killAimX = i - k;
							killAimY = j - o;
							return 3;
						}
						else if ((j + o < SIZE1) && (playGround[i][j + o] == nullptr)) //Низ
						{
							killAimX = i;
							killAimY = j + o;
							return 3;
						}
						else if ((i - k >= 0) && (j + o < SIZE1) && (playGround[i - k][j + o] == nullptr))
						{
							killAimX = i - k;
							killAimY = j + o;
							return 3;
						}
						else if ((i + k < SIZE1) && (playGround[i + k][j] == nullptr))//Право
						{
							killAimX = i + k;
							killAimY = j;
							return 3;
						}
						else if ((i + k < SIZE1) && (j - o >= 0) && (playGround[i + k][j - o] == nullptr))
						{
							killAimX = i + k;
							killAimY = j - o;
							return 3;
						}
						else if ((j - o >= 0) && (playGround[i][j - o] == nullptr))//Верх
						{
							killAimX = i;
							killAimY = j - o;
							return 3;
						}
						else if ((i + k < SIZE1) && (j + o < SIZE1) && (playGround[i + k][j + o] == nullptr))
						{
							killAimX = i + k;
							killAimY = j + o;
							return 3;
						}
						else if ((i - k >= 0) && (playGround[i - k][j] == nullptr))//Лево
						{
							killAimX = i - k;
							killAimY = j;
							return 3;
						}

						return 1;


						//=======================================
					}
				}
			}
		}
	}
	else
	{
		return 1;
	}
}
void SpawnRab(int iCurrent, int jCurrent)
{
	int l = rand() % 5;


	if ((playGround[iCurrent][jCurrent - l] == nullptr) && (jCurrent - l >= 0))
	{
		playGround[iCurrent][jCurrent - l] = new Rabbit();

		playGround[iCurrent][jCurrent - l]->SetXY(iCurrent, jCurrent - l);

		Turn.push_back(playGround[iCurrent][jCurrent - l]);
		cout << "ПОЛУЧИЛОСЬ У ЗАЙЦЕВ!" << endl;
		// _getwch();
	}
	if ((playGround[iCurrent - l][jCurrent] == nullptr) && (iCurrent - l >= 0))
	{
		playGround[iCurrent - l][jCurrent] = new Rabbit();

		playGround[iCurrent - l][jCurrent]->SetXY(iCurrent - l, jCurrent);
		Turn.push_back(playGround[iCurrent - l][jCurrent]);
		cout << "ПОЛУЧИЛОСЬ У ЗАЙЕВ!" << endl;
		//_getwch();
	}
	if ((playGround[iCurrent + l][jCurrent] == nullptr) && (iCurrent + l < SIZE1))
	{
		playGround[iCurrent + l][jCurrent] = new Rabbit();

		playGround[iCurrent + l][jCurrent]->SetXY(iCurrent + l, jCurrent);
		Turn.push_back(playGround[iCurrent + l][jCurrent]);
		cout << "ПОЛУЧИЛОСЬ У ЗАЙЦЕВ!" << endl;
		//_getwch();
	}
	if ((playGround[iCurrent][jCurrent + l] == nullptr) && (jCurrent + l < SIZE1))
	{
		playGround[iCurrent][jCurrent + l] = new Rabbit();

		playGround[iCurrent][jCurrent + l]->SetXY(iCurrent, jCurrent + l);
		Turn.push_back(playGround[iCurrent][jCurrent + l]);
		cout << "ПОЛУЧИЛОСЬ У ЗАЙЦЕВ!" << endl;
		//_getwch(); 
	}
}
void SpawnWolf(int iCurrent, int jCurrent)
{
	int l = rand() % 5;


	if ((playGround[iCurrent][jCurrent - l] == nullptr) && (jCurrent - l >= 0))
	{
		playGround[iCurrent][jCurrent - l] = new Wolf();

		playGround[iCurrent][jCurrent - l]->SetXY(iCurrent, jCurrent - l);

		Turn.push_back(playGround[iCurrent][jCurrent - l]);
		cout << "ПОЛУЧИЛОСЬ У ВОЛКОВ!" << endl;
		// _getwch();
	}
	else if ((playGround[iCurrent - l][jCurrent] == nullptr) && (iCurrent - l >= 0))
	{
		playGround[iCurrent - l][jCurrent] = new Wolf();

		playGround[iCurrent - l][jCurrent]->SetXY(iCurrent - l, jCurrent);
		Turn.push_back(playGround[iCurrent - l][jCurrent]);
		cout << "ПОЛУЧИЛОСЬ У ВОЛКОВ!" << endl;
		// _getwch();
	}
	else if ((playGround[iCurrent + l][jCurrent] == nullptr) && (iCurrent + l < SIZE1))
	{
		playGround[iCurrent + l][jCurrent] = new Wolf();

		playGround[iCurrent + l][jCurrent]->SetXY(iCurrent + l, jCurrent);
		Turn.push_back(playGround[iCurrent + l][jCurrent]);
		cout << "ПОЛУЧИЛОСЬ У ВОЛКОВ!" << endl;
		// _getwch();
	}
	else if ((playGround[iCurrent][jCurrent + l] == nullptr) && (jCurrent + l < SIZE1))
	{
		playGround[iCurrent][jCurrent + l] = new Wolf();

		playGround[iCurrent][jCurrent + l]->SetXY(iCurrent, jCurrent + l);
		Turn.push_back(playGround[iCurrent][jCurrent + l]);
		cout << "ПОЛУЧИЛОСЬ У ВОЛКОВ!" << endl;
		// _getwch();
	}
}

void SearchSpawnPlace(int iCurrent, int jCurrent)
{
	int l = rand() % 5;


	if ((playGround[iCurrent][jCurrent - l] == nullptr) && (jCurrent - l >= 0))
	{
		playGround[iCurrent][jCurrent - l] = new Kapusta();

		playGround[iCurrent][jCurrent - l]->SetXY(iCurrent, jCurrent - l);
		Turn.push_back(playGround[iCurrent][jCurrent - l]);
	}
	else if ((playGround[iCurrent - l][jCurrent] == nullptr) && (iCurrent - l >= 0))
	{
		playGround[iCurrent - l][jCurrent] = new Kapusta();

		playGround[iCurrent - l][jCurrent]->SetXY(iCurrent - l, jCurrent);
		Turn.push_back(playGround[iCurrent - l][jCurrent]);
	}
	else if ((playGround[iCurrent + l][jCurrent] == nullptr) && (iCurrent + l<SIZE1))
	{
		playGround[iCurrent + l][jCurrent] = new Kapusta();

		playGround[iCurrent + l][jCurrent]->SetXY(iCurrent + l, jCurrent);
		Turn.push_back(playGround[iCurrent + l][jCurrent]);
	}
	else if ((playGround[iCurrent][jCurrent + l] == nullptr) && (jCurrent + l<SIZE1))
	{
		playGround[iCurrent][jCurrent + l] = new Kapusta();

		playGround[iCurrent][jCurrent + l]->SetXY(iCurrent, jCurrent + l);
		Turn.push_back(playGround[iCurrent][jCurrent + l]);
	}
}

void PrintPlayGround()
{
	for (int i = 0; i < SIZE1; i++)
	{
		for (int j = 0; j < SIZE1; j++)
		{
			if (playGround[i][j])
				cout << " " << playGround[i][j]->print() << " ";
			else
				cout << "   ";
		}
		cout << endl;

	}
	cout << "-=================" << endl;
}

int AddObjectKap(int i, int j)
{
	if (playGround[i][j] == nullptr)
	{
		playGround[i][j] = new Kapusta();
		playGround[i][j]->SetXY(i, j);

		Turn.push_back(playGround[i][j]);
	}
	else
	{
		return 0;
	}
}
int AddObjectRab(int i, int j)
{
	if (playGround[i][j] == nullptr)
	{
		playGround[i][j] = new Rabbit();
		playGround[i][j]->SetXY(i, j);

		Turn.push_back(playGround[i][j]);
	}
	else
	{
		return 0;
	}
}
int AddObjectWolf(int i, int j)
{
	if (playGround[i][j] == nullptr)
	{
		playGround[i][j] = new Wolf();
		playGround[i][j]->SetXY(i, j);

		Turn.push_back(playGround[i][j]);
	}
	else
	{
		return 0;
	}
}
void AddManyUnits()
{
	srand(time(NULL));

	int randomX[SIZE1*SIZE1 / 20] = {};
	int randomY[SIZE1*SIZE1 / 20] = {};
	for (int i = 0; i < (SIZE1*SIZE1 / 20); i++)
	{
		randomX[i] = rand() % 20;
		cout << randomX[i] << endl;
	}
	cout << "-=================" << endl;
	for (int i = 0; i < (SIZE1*SIZE1 / 20); i++)
	{
		randomY[i] = rand() % 20;
		cout << randomY[i] << endl;
	}
	for (int i = 0; i < (SIZE1*SIZE1 / 20); i++)
	{

		AddObjectRab(randomX[i], randomY[i]);
		randomX[i] = 0;
		randomY[i] = 0;
	}
	int randomXKW[SIZE1*SIZE1 / 30] = {};
	int randomYKW[SIZE1*SIZE1 / 30] = {};
	for (int i = 0; i < (SIZE1*SIZE1 / 30); i++)
	{
		randomXKW[i] = rand() % 20;
		cout << randomXKW[i] << endl;
	}
	cout << "-=================" << endl;
	for (int i = 0; i < (SIZE1*SIZE1 / 30); i++)
	{
		randomYKW[i] = rand() % 20;
		cout << randomYKW[i] << endl;
	}
	for (int i = 0; i < (SIZE1*SIZE1 / 50); i++)
	{

		AddObjectWolf(randomXKW[i], randomYKW[i]);
		randomXKW[i] = 0;
		randomYKW[i] = 0;
	}

	int randomXK[SIZE1*SIZE1 / 10] = {};
	int randomYK[SIZE1*SIZE1 / 10] = {};
	for (int i = 0; i < (SIZE1*SIZE1 / 10); i++)
	{
		randomXK[i] = rand() % 20;
		cout << randomXK[i] << endl;
	}
	cout << "-=================" << endl;
	for (int i = 0; i < (SIZE1*SIZE1 / 10); i++)
	{
		randomYK[i] = rand() % 20;
		cout << randomYK[i] << endl;
	}
	for (int i = 0; i < (SIZE1*SIZE1 / 20); i++)
	{

		AddObjectKap(randomXK[i], randomYK[i]);
		randomXK[i] = 0;
		randomYK[i] = 0;
	}

}
Unit * w;
Unit * e;


int main()
{
	vector<bool>abc_del;
	
	Image KapImage; //создаем объект Image (изображение)
	KapImage.loadFromFile("Image/kap.png");//загружаем в него файл
	KapImage.createMaskFromColor(Color(0, 0, 0));

	Texture Kaptexture;//создаем объект Texture (текстура)
	Kaptexture.loadFromImage(KapImage);//передаем в него объект Image (изображения)

	Sprite Kapsprite;//создаем объект Sprite(спрайт)
	Kapsprite.setTexture(Kaptexture);//передаём в него объект Texture (текстуры)
									 //randomMapGenerateKap;
	//Kapsprite.setPosition(30, 45);
	//____________________________
	
	Image heroimage; //создаем объект Image (изображение)
	heroimage.loadFromFile("Image/zay.png");//загружаем в него файл

	Texture herotexture;//создаем объект Texture (текстура)
	herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)

	Sprite herosprite;//создаем объект Sprite(спрайт)
	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
									   //herosprite.setTextureRect(IntRect(0, 192, 96, 96));//получили нужный нам прямоугольник с капустой
	//herosprite.setPosition(100, 50);
	
	Image Wolfimage; //создаем объект Image (изображение)
	Wolfimage.loadFromFile("Image/Wolf.png");//загружаем в него файл

	Texture Wolftexture;//создаем объект Texture (текстура)
	Wolftexture.loadFromImage(Wolfimage);//передаем в него объект Image (изображения)

	Sprite Wolfsprite;//создаем объект Sprite(спрайт)
	Wolfsprite.setTexture(Wolftexture);//передаём в него объект Texture (текстуры)
	
	float currentFrame = 0;
	Clock clock;
	Clock gameTimeClock;
	int gameTime = 0;
	int createObjectForMapTimer = 0;
	
	int k = 0;
	int k1 = 0;

	while (window.isOpen())
	{

		//float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		//clock.restart();
		//time = time / 800; //скорость игры
		//createObjectForMapTimer += time;//наращиваем таймер
		/*if (createObjectForMapTimer>3000) {
			//randomMapGenerateKap();//генерация случ камней
			createObjectForMapTimer = 0;//обнуляем таймер
		}*/
		//Тут все будет происходить
		Event event;
		while (window.pollEvent(event))
		{

			int N = 5;

			setlocale(LC_ALL, "rus");

			for (int i = 0; i < SIZE1; i++)
				for (int j = 0; j < SIZE1; j++)
				{
					playGround[i][j] = nullptr;
				}

			AddManyUnits();
			//AddObjectWolf(2, 2);
			//AddObjectRab(1, 1);
			//AddObjectKap(0, 0);

			Sprite cab_spr[500];
			PrintPlayGround();
			//_getwch();



			for (int i = 0; i < 300; i++)
			{

				w = *Turn.begin();
				if (w == e)
				{
					cout << "Что то пошло не так" << endl;
					PrintPlayGround();
					_getwch();
					save = *Turn.begin();
					Turn.erase(Turn.begin());
					save = nullptr;

					//return 0;
				}
				//cout << *Turn.begin() << endl;

				if (Turn.front()->GetName() == 22)
				{
					int X = Turn.front()->GetX();
					int Y = Turn.front()->GetY();

					int resKap = playGround[X][Y]->Life(X, Y);

					if (resKap == 1)
					{
						Turn.erase(Turn.begin());
						playGround[X][Y] = nullptr;
					}
					else if (resKap == 0)
					{
						//PrintPlayGround();

						store[1] = *Turn.begin();
						Turn.erase(Turn.begin());
						Turn.push_back(store[1]);

						store[1] = nullptr;
					}
					else if (resKap == 2)
					{
						SearchSpawnPlace(X, Y);
					}
					//_getwch();
				}
				else if (Turn.front()->GetName() == 33)
				{
					int XR = Turn.front()->GetX();
					int YR = Turn.front()->GetY();

					int res;

					res = playGround[XR][YR]->Life(XR, YR);

					if (res == 1)
					{
						Turn.erase(Turn.begin());
						playGround[XR][YR] = nullptr;
						//PrintPlayGround();
						cout << "*******УМЕР ЗАЯЦ******" << endl;
						//_getwch();
					}
					else if (res == 3)
					{
						playGround[killAimX][killAimY] = playGround[XR][YR];
						playGround[XR][YR] = nullptr;
						Turn.erase(Turn.begin());
						playGround[killAimX][killAimY]->SetXY(killAimX, killAimY);
						store[2] = playGround[killAimX][killAimY];
						Turn.push_back(store[2]);
						store[2] = nullptr;

						playGround[killAimX][killAimY]->Live();
						playGround[killAimX][killAimY]->DelStatus();

						//cout << playGround[killAimX][killAimY]->GetFull() << endl;

						//PrintPlayGround();
						//_getwch();

					}
					else if (res == 5)
					{
						store[2] = *Turn.begin();
						Turn.erase(Turn.begin());
						Turn.push_back(store[2]);

						store[2] = nullptr;

						//PrintPlayGround();
						//_getwch();
					}
				}
				else if (Turn.front()->GetName() == 44)
				{
					int XR = Turn.front()->GetX();
					int YR = Turn.front()->GetY();

					int res;
					res = BigLifeWolf(XR, YR);

					if (res == 1)
					{
						Turn.erase(Turn.begin());
						playGround[XR][YR] = nullptr;
						//PrintPlayGround();
						cout << "*******УМЕР волк******" << endl;
						//_getwch();
					}
					else if (res == 3)
					{
						playGround[killAimX][killAimY] = playGround[XR][YR];
						playGround[XR][YR] = nullptr;
						Turn.erase(Turn.begin());
						playGround[killAimX][killAimY]->SetXY(killAimX, killAimY);
						store[3] = playGround[killAimX][killAimY];
						Turn.push_back(store[3]);
						store[3] = nullptr;

						playGround[killAimX][killAimY]->Live();
						playGround[killAimX][killAimY]->DelStatus();

						//cout << playGround[killAimX][killAimY]->GetFull() << endl;

						//PrintPlayGround();
						//_getwch();

					}
					else if (res == 5)
					{
						store[3] = *Turn.begin();
						Turn.erase(Turn.begin());
						Turn.push_back(store[3]);

						store[3] = nullptr;

						//PrintPlayGround();
						//_getwch();
					}
				}
				killAimX = 0;
				killAimY = 0;
				e = w;
				w = nullptr;
				//PrintPlayGround();
				
				//рисование элемента, переменная k для рисования
				if (Turn.front()->GetName() == 22)
					//if (abc_del[i] == false)
					cab_spr[k].setTexture(Kaptexture);
				if (Turn.front()->GetName() == 33)
					//if (abc_del[i] == false)
					cab_spr[k].setTexture(herotexture);
				if (Turn.front()->GetName() == 44)
					//if (abc_del[i] == false)
					cab_spr[k].setTexture(Wolftexture);

				/*if (abc_mas[i]->GetAnim() == 3)
				cab_spr[k].setTexture(cab_tex3);
				*/
				
				cab_spr[k].setPosition(Turn.front()->GetX() * 15, Turn.front()->GetY() * 15);
				k++;


				//if (event.type == sf::Event::Closed)
					//window.close();
				
			}
			window.clear();

			for (int i = 0; i < k; i++)
				window.draw(cab_spr[i]);
			window.display();
			Sleep(1000);
			
			PrintPlayGround();
		}
	}
	_getwch();
}









