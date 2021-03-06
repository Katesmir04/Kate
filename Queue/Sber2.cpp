#pragma once
#include "stdafx.h"
#include <thread>
#include <chrono>
#include "Consumer.h"
#include "Manager.h"
#include "Vendor.h"
#include <SFML/Graphics.hpp>
#include <queue>
#include <mutex>
//#include "Windows.h"

using namespace sf;
using namespace std;
RenderWindow window(VideoMode(600, 600), "SFMLworks");

Vendor v1;
Texture v1T;
Sprite v1S;

Vendor v2;
Texture v2T;
Sprite v2S;

Vendor v3;
Texture v3T;
Sprite v3S;

queue <Consumer> mqueue;
Manager manager;
void SpawnCon();
void DrawVendors();
int main()
{


	v1T.loadFromFile("op1.png");


	v2T.loadFromFile("op1.png");
	int u = 0;


	v3T.loadFromFile("op1.png");

	Texture consT;
	Sprite consS;
	consT.loadFromFile("cons.png");
	Texture back;
	back.loadFromFile("background.png");
	Sprite backg;
	backg.setTexture(back);
	backg.setPosition(0, 0);
	backg.setPosition(0, 0);

	while (1 == 1)
	{
		mtx.lock();
		cout << "Main" << endl;
		mtx.unlock();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)

				window.close();
		}

		window.clear();
		window.draw(backg);

		if (mqueue.size()<10)
			SpawnCon();
		else
		{
			mqueue.pop();
			mqueue.pop();
			mqueue.pop();
			mqueue.pop();
		}
		mtx.lock();
		cout << "People in a queue: " << mqueue.size() << endl;
		mtx.unlock();
		consS.setTexture(consT);
		//Заспавнились чуваки из очереди и тут их нужно отрисовать
		for (int i = 0; i < mqueue.size(); i++)
		{

			consS.setPosition(300, i * 50 + 300);
			window.draw(consS);
		}

		DrawVendors();


		if (mqueue.size() != 0)
		{
			if ((mqueue.size() >1) && (v1.GetId() != 1)) //Только первый поток работает
			{
				thread t1([&]()
				{
					mqueue.front().SetId(1);
					int o = mqueue.front().GetOperation();
					mqueue.pop();
					v1.Work(o);

					v1.SetId(0);

				});
				t1.detach();
			}
			else if ((mqueue.size() >= 4) && (v2.GetId() != 1)) //Подключается второй
			{

				mtx.lock();
				cout << "Second vendor is active!" << endl;
				mtx.unlock();
				//_getwch();
				thread t2([&]()
				{

					mqueue.front().SetId(2);

					int o = mqueue.front().GetOperation();
					mqueue.pop();
					v2.Work(o);

					v2.SetId(0);
					//mqueue.pop();
				});
				t2.detach();
			}
			//else if ((mqueue.size()>=8) && (v3.GetId() != 1)) //Третий
			//{
			//	mtx.lock();
			//	cout << "Third vendor is active!" << endl;
			//	mtx.lock();
			//	thread t3([&]()
			//	{
			//		mqueue.front().SetId(1);
			//		int o = mqueue.front().GetOperation();
			//		mqueue.pop();
			//		v3.Work(o);
			//		v3.SetId(0);
			//	});
			//	t3.detach();
			//}	
		}
		u++;
		window.display();
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	return 0;
}

void SpawnCon()
{
	//int n = 1+rand() % 4;
	int n = 1;
	mtx.lock();
	cout << "Spawning" << endl;
	mtx.unlock();
	for (int i = 0; i < n; i++)
	{
		Consumer c;
		int r = 1 + rand() % 2;
		c.SetOperation(r);
		c.SetId(0);
		int z = 100 + rand() % 201;
		c.SetName(z);
		mqueue.push(c);
	}
}

void DrawVendors()
{
	//Если вендер свободен то рисуем ему зеленый, если нет - красный
	if (v1.GetId() != 1)
	{
		v1S.setTexture(v1T);
		v1S.setPosition(110, 45);
		window.draw(v1S);
	}
	else if (v1.GetId() == 1)
	{
		v1T.loadFromFile("op2.png");
		v1S.setTexture(v1T);
		v1S.setPosition(110, 45);
		window.draw(v1S);
	}
	//Второму тоже самое
	v1T.loadFromFile("op1.png");
	if (v2.GetId() != 1)
	{
		v2S.setTexture(v2T);
		v2S.setPosition(244, 45);
		window.draw(v2S);
	}
	else if (v2.GetId() == 1)
	{
		v2T.loadFromFile("op2.png");
		v2S.setTexture(v2T);
		v2S.setPosition(244, 45);
		window.draw(v2S);
	}
	//Третий вендер

	//if (v3.GetId() != 1)
	//{
	//	v3S.setTexture(v3T);
	//	v3S.setPosition(378, 45);
	//	window.draw(v3S);
	//}
	//else if (v3.GetId() == 1)
	//{
	//	v3T.loadFromFile("op2.png");
	//	v3S.setTexture(v3T);
	//	v3S.setPosition(378, 45);
	//	window.draw(v3S);
	//}
}