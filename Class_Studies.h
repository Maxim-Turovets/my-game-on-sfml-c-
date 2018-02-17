#pragma once
#include "Class_Menu.h"
class Class_Studies 
{
public:
	Event e;
	double p = 305;
	bool isMenu = 1;
	int menuNum = 0;
	Texture kursor,t1,t2,t3,t4,t5,t6,t7,t8,t9;
	void Screensaver(RenderWindow & window);
	Class_Studies();
	~Class_Studies();
};

