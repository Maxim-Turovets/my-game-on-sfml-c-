#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Class_Menu.h"
#include "Class_Screensaver.h"
#include "Class_Realization.h"
#include "Class_Information.h"
#include "Class_Option.h"
#include "Class_Game_over.h"
#include "Class_Studies.h"
#include "Class_Network.h"
//#include "Client.h"
#include <time.h>
#include <iostream>
#include <Windows.h>
using namespace sf;

 

int main()

{

	

	     //           опърюел йнмянкэ
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	



	
	////                                бняопнхгбедемхе гюярюбйх
	RenderWindow widow(sf::VideoMode(740, 479), "Zast");
	Class_Screensaver we;
	we.Screensaver(widow);
	widow.close();
	////

	


	///////////////                                 бшгнб лемч
	RenderWindow window(sf::VideoMode(740, 479), "MENU");
	Class_Menu menu;
	menu.Menu(window);
	////////////////////////////////
	


	return 0;
}
