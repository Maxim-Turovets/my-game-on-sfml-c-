#include "Class_Studies.h"
#include <Windows.h>




void Class_Studies::Screensaver(RenderWindow & window)
{
	// Загрузка  картинок
	{
		kursor.loadFromFile("./images/studies/kr.png");
		t1.loadFromFile("./images/studies/fon.bmp");
		t2.loadFromFile("./images/studies/1.png");
		t3.loadFromFile("./images/studies/2.png");
		t4.loadFromFile("./images/studies/3.png");
		t5.loadFromFile("./images/studies/str.png");
		t6.loadFromFile("./images/studies/score.png");
		t7.loadFromFile("./images/ochki.png");
		t8.loadFromFile("./images/studies/time.png");
		t9.loadFromFile("./images/studies/esc.png");
	}

	// Загрузка спрайтов
		Sprite kr(kursor), st1(t1), st2(t2), st3(t3), st4(t4), str(t5), score(t6), oc(t7), time(t8), esc(t9);
	
	// Позиции элементов
	{
		kr.setPosition(100, 305);
		st2.setPosition(156, 297);
		st3.setPosition(156, 351);
		st4.setPosition(48, 351);
		str.setPosition(147, 315);
		score.setPosition(526, 14);
		oc.setPosition(575, 150);
		time.setPosition(340, 1);
		esc.setPosition(-2, -2);
	}
	oc.setTextureRect(IntRect(1 * 98, 0, 98, 98));
	



	while (isMenu)
	{

		//  Движение курсора
		{
			for (int i = 0; i < 130; i++)
			{
				p += 0.5;
				window.draw(st1);
				window.draw(st2);
				window.draw(st3);

				kr.setPosition(167, p);
				window.draw(st2);
				window.draw(st3);
				window.draw(kr);
				window.display();
			}
		}

		// Обмен элементов
		{
			p = 297;
			double p2 = 351;
			for (int i = 0; i < 216; i++)
			{
				p += 0.25;
				p2 -= 0.25;
				window.draw(st1);
				st2.setPosition(156, p);
				st3.setPosition(156, p2);

				window.draw(st3);
				window.draw(st2);

				window.draw(st3);
				window.draw(kr);
				window.display();

			}
			window.draw(st3);
			window.draw(st4);
			window.draw(st2);
		}
	
		//  Движение стрелки к счету
		{
			for (int i = 0; i < 1100; i++)
			{

				window.draw(st1);
				window.draw(st3);
				window.draw(st2);
				window.draw(str);

				str.setPosition(147 + (i / 5 + 100), 315 - i / 5);
				window.display();
				window.draw(st4); //
			}
		}
    		
		// Движение стрелки к счету  за 1 ход
		{
			for (int i = 0; i < 132; i++)
			{

				window.draw(st1);
				window.draw(st3);
				window.draw(st2);
				window.draw(str);
				str.setPosition(467 + i / 4, 95 + (i / 4) * 3);
				window.display();
				window.draw(score);
				window.draw(st3);
			}

			window.draw(score);
			window.draw(st4);
			window.draw(st2);
			window.draw(oc);
			window.display();
			Sleep(1000);
		}

		// Движение стрелки к времени
		{
			for (int i = 0; i < 740; i++)
			{

				window.draw(st1);
				window.draw(st3);
				window.draw(st2);
				window.draw(str);
				str.setPosition(500 - i / 4, 195 - i / 4);
				window.display();
				window.draw(score);
				window.draw(st3);
			}

			window.draw(st4);
			window.draw(st2);
			window.draw(oc);
			window.draw(time);
		}

		// Вывод указателя ESCAPE
		{
			esc.setColor(Color(0, 255, 255));

			for (int i = 0; i < 255; i++)
			{
				esc.setColor(Color(i, 255, 255));
				window.draw(esc);
				window.display();
			}

			window.draw(esc);
			window.draw(score);
			window.draw(time);
			window.draw(st4);
			window.draw(st2);
			window.draw(oc);
		}

		// Обновление и задержка перед закрытием
		{
			window.display();
			Sleep(3000);
			isMenu = false;
		}
	}
	window.close();
}


















Class_Studies::Class_Studies()
{
}


Class_Studies::~Class_Studies()
{
}
