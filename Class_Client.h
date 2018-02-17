#pragma once
#include "Class_Client_or_Server.h"
class Class_Client :
	public Class_Client_or_Server
{
public:

	Texture tm1, t2, t1;
	string Wind(RenderWindow & app);
	Class_Client();
	~Class_Client();
};

