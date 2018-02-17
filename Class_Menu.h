#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Class_Option.h"
#include "Class_Network.h"
#include <time.h>
#include <Windows.h>
using namespace sf;
class Class_Menu
{
	
public:
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground, inf_Background,tm1,tm2,tm3,tm4, t1, t2, t3, t4, t5,t6,t7,t12 ;
	
	static string ip;
	bool isMenu = 1;
	int menuNum = 0;
   
	void Menu(RenderWindow & window);
	Class_Menu();
	~Class_Menu();
};

