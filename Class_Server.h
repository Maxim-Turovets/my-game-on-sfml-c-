#pragma once
#include "Class_Client_or_Server.h"
class Class_Server :
	public Class_Client_or_Server
{
public:
	Texture tm1, tm2, t1;
	void Wind(RenderWindow & app);

	Class_Server();
	~Class_Server();
};

