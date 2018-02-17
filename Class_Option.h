#pragma once
#include "Class_Realization.h"
#include"Class_Menu.h"
class Class_Option 
{
public:
	static int stil;
	static bool volume_static;
	static int time_static;
	static int points_static;
	Texture tm1, tm2, tm3, tm4,t1, t2, t3, t4, t5, t6, t7,t8,t9,t10,t11,t12;
	void Wind(RenderWindow & app);
	Class_Option();
	~Class_Option();
};

