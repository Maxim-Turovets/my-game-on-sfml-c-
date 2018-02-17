#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Class_Option.h"
#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace sf;
using namespace std;
class Class_Network 
{
public:
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	int x0, y0, x, y; int click = 0; Vector2i pos;

	bool isSwap = false, isMoving = false;
	int ts = 54;
	//Vector2i offset;
	//	t1.loadFromFile("C:/Users/mturo/Documents/Visual Studio 2015/Projects/kursik/images/background.jpg");
	//t2.loadFromFile("C:/Users/mturo/Documents/Visual Studio 2015/Projects/kursik/images/gems.jpg");
	void Init(Texture t1, Texture t2);

	struct piece
	{
		int x, y, col, row, kind, match, alpha, color_a, color_b, color_c;
		piece()
		{
			match = 0;
			alpha = 255;
			color_a = 255;
			color_b = 255;
			color_c = 255;
		}
	} grid[10][10];

	void swap(piece p1, piece p2);
	void Realization(RenderWindow & app);
	Class_Network();
	~Class_Network();
};

