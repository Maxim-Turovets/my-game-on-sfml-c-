#pragma once
#include <SFML/Graphics.hpp>
#include  <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <Windows.h>
using namespace sf;
class Class_Screensaver
{
public:
	bool isMenu = 1;
	int menuNum = 0;
	Texture screen_Texture1, screen_Texture2, screen_Texture3, screen_Texture4, screen_Texture5, screen_Texture6, screen_Texture7, screen_Texture8, screen_Texture9, screen_Texture10, screen_Texture11, screen_Texture12, screen_Texture13, screen_Texture14;
	void Screensaver(RenderWindow & window);
	Class_Screensaver();
	~Class_Screensaver();
};

