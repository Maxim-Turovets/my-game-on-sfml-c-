#pragma once
#include "Class_Menu.h"
class Class_Client_or_Server :
	public Class_Menu
{
public:
	static char chr;
	Texture tm1, tm2, t1;
	void Wind(RenderWindow & app);
	Class_Client_or_Server();
	~Class_Client_or_Server();
};

