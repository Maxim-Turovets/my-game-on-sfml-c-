#include "Class_Screensaver.h"


void Class_Screensaver::Screensaver(RenderWindow & window)
{
	// Загрузка картинок
	{
		screen_Texture1.loadFromFile("./images/anim/1.bmp");
		screen_Texture2.loadFromFile("./images/anim/2.bmp");
		screen_Texture3.loadFromFile("./images/anim/3.bmp");
		screen_Texture4.loadFromFile("./images/anim/4.bmp");
		screen_Texture5.loadFromFile("./images/anim/5.bmp");
		screen_Texture6.loadFromFile("./images/anim/6.bmp");
		screen_Texture7.loadFromFile("./images/anim/7.bmp");
		screen_Texture8.loadFromFile("./images/anim/8.bmp");
		screen_Texture9.loadFromFile("./images/anim/9.bmp");
		screen_Texture10.loadFromFile("./images/anim/10.bmp");
		screen_Texture11.loadFromFile("./images/anim/11.bmp");
		screen_Texture12.loadFromFile("./images/anim/12.bmp");
		screen_Texture13.loadFromFile("./images/anim/13.bmp");
		screen_Texture14.loadFromFile("./images/anim/14.bmp");
	}

	// Инициализация спрайтов
	Sprite screen1(screen_Texture1), screen2(screen_Texture2), screen3(screen_Texture3), screen4(screen_Texture4), screen5(screen_Texture5), screen6(screen_Texture6), screen7(screen_Texture7), screen8(screen_Texture8), screen9(screen_Texture9), screen10(screen_Texture10), screen11(screen_Texture11), screen12(screen_Texture12), screen13(screen_Texture13), screen14(screen_Texture14);// , screen2(screen_Texture2), screen3(screen_Texture3),

	// Воспроизведение музыки 
	
		Music music;//создаем объект музыки
		music.openFromFile("./sound/saver.ogg");
		music.play();
	

	while (isMenu)
	{
	 
		// Анимация картинок
		{
			window.draw(screen1);
			window.display();
			Sleep(100);
			window.draw(screen2);
			window.display();
			Sleep(100);
			window.draw(screen3);
			window.display();
			Sleep(100);
			window.draw(screen4);
			window.display();
			Sleep(200);
			window.draw(screen5);
			window.display();
			Sleep(200);
			window.draw(screen6);
			window.display();
			Sleep(200);
			window.draw(screen7);
			window.display();
			Sleep(200);
			window.draw(screen8);
			window.display();
			Sleep(200);
			window.draw(screen9);
			window.display();
			Sleep(200);
			window.draw(screen10);
			window.display();
			Sleep(200);
			window.draw(screen11);
			window.display();
			Sleep(1000);
			window.draw(screen12);
			window.display();
			Sleep(100);
			window.draw(screen13);
			window.display();
			Sleep(100);
			window.draw(screen14);
			window.display();
			Sleep(3000);
			isMenu = false;
		}

		// Закрытие окна
		window.close();
	}
	window.close();
}

Class_Screensaver::Class_Screensaver()
{
}


Class_Screensaver::~Class_Screensaver()
{
}
