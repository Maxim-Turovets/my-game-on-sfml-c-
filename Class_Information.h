#pragma once
#include <SFML/Graphics.hpp>
#include "Class_Menu.h"
using namespace sf;
class Class_Information 
{
public:
	Texture  inf_Background;
	void Inform(RenderWindow & window);
	Class_Information();
	~Class_Information();
};

