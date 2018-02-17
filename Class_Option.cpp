#include "Class_Option.h"

int Class_Option::stil = 0;
bool Class_Option::volume_static = true;
int Class_Option::time_static = 150;
int Class_Option::points_static = 300;

void Class_Option::Wind(RenderWindow & app)
{

	t1.loadFromFile("./images/fon_option.jpg");
	t2.loadFromFile("./images/volume2.png");
	t3.loadFromFile("./images/150.png");
	t4.loadFromFile("./images/300.png");
	t5.loadFromFile("./images/600.png");
	t6.loadFromFile("./images/volume.png");
	t7.loadFromFile("./images/300.png");
	t8.loadFromFile("./images/600.png");
	t9.loadFromFile("./images/1000.png");
	t10.loadFromFile("./images/option_on.png");
	t11.loadFromFile("./images/option_off.png");

	tm1.loadFromFile("./images/st1.png");
	tm2.loadFromFile("./images/st2.png");
	tm3.loadFromFile("./images/st3.png");
	tm4.loadFromFile("./images/st4.png");
	
	Sprite background(t1), volume(t2), tim150(t3), tim300(t4), tim600(t5), volume_no(t6), win300(t7), win600(t8), win1000(t9), on(t10), off(t11), stil_1(tm1), stil_2(tm2), stil_3(tm3), stil_4(tm4);

	volume.setPosition(276, 196);
	volume_no.setPosition(330, 196);
	tim150.setPosition(218, 142);
	tim300.setPosition(301, 142);
	tim600.setPosition(384, 142);
	win300.setPosition(253,244);
	win600.setPosition(337, 244);
	win1000.setPosition(421, 244);
	on.setPosition(1900, 383);
	off.setPosition(2680, 389);

	stil_1.setPosition(65, 320);
	stil_2.setPosition(138, 320);
	stil_3.setPosition(211, 320);
	stil_4.setPosition(284, 320);
	

	volume_no.setColor(Color(150, 150, 255));


	tim300.setColor(Color(150, 150, 255));
	tim600.setColor(Color(150, 150, 255));

	
	win600.setColor(Color(150, 150, 255));
	win1000.setColor(Color(150, 150, 255));

	while (app.isOpen())
	{
	
		app.draw(background);
		Event e;
		while (app.pollEvent(e))
		{

			if (e.type == Event::Closed)
				app.close();
			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
				{
				/*	if (!isSwap && !isMoving) click++;
					pos = Mouse::getPosition(app);*/
				}
		}

		/////////////=================================                        ¬ – ≈ Ã ﬂ
		/////=============          150
		
		if (IntRect(218, 142, 80, 35).contains(Mouse::getPosition(app)))
		{
			if (IntRect(218, 142, 80, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				tim150.setColor(Color(255, 255, 255));   //
				tim300.setColor(Color(150, 150, 255));
				tim600.setColor(Color(150, 150, 255));
				time_static = 150;
			}
		}


		/////=============          300
		if (IntRect(301, 142, 80, 35).contains(Mouse::getPosition(app)))
		{
			if (IntRect(301, 142, 80, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				tim150.setColor(Color(150, 150, 255));
				tim300.setColor(Color(255, 255, 255)); //
				tim600.setColor(Color(150, 150, 255));
				time_static = 300;
			}
		}



		/////=============          600
		if (IntRect(384, 142, 80, 35).contains(Mouse::getPosition(app)))
		{
			if (IntRect(384, 142, 80, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				tim150.setColor(Color(150, 150, 255));
				tim300.setColor(Color(150, 150, 255));
				tim600.setColor(Color(255, 255, 255));
				time_static = 600;
			}
		}
		//===================================================================================================







		//////==========================================                Œœ÷»» «¬” ¿
		if (Class_Option::volume_static == true)
		{
			t2.loadFromFile("./images/volume2.png");
			t6.loadFromFile("./images/volume.png");
		}
		else
		{
			t6.loadFromFile("./images/volume2.png");
			t2.loadFromFile("./images/volume.png");
		}
     	if (IntRect(276, 196, 40, 35).contains(Mouse::getPosition(app)))
		{

			if (IntRect(276, 196, 40, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				volume_no.setColor(Color(150, 150, 255));
				volume.setColor(Color(255, 255, 255));
				t6.loadFromFile("./images/volume.png");
				t2.loadFromFile("./images/volume2.png"); // Ã≈Õﬂ≈Ã  ÕŒœ ” ƒÀﬂ ¿Õ»Ã¿÷»»
				volume_static = true;
			}
		}
		
		if (IntRect(330, 196, 40, 35).contains(Mouse::getPosition(app)))
		{

			if (IntRect(330, 196, 40, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				volume_no.setColor(Color(255, 255, 255));
				volume.setColor(Color(150, 150, 255));
				t6.loadFromFile("./images/volume2.png");
				t2.loadFromFile("./images/volume.png"); // Ã≈Õﬂ≈Ã  ÕŒœ ” ƒÀﬂ ¿Õ»Ã¿÷»»
				volume_static = false;
			}
		}
	////==================================================================================================================






		//  ================================================Œ◊ » ƒÀﬂ œŒ¡≈ƒ€
		
		/////=============          300

		if (IntRect(253, 244, 80, 35).contains(Mouse::getPosition(app)))
		{
			if (IntRect(253, 244, 80, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				win300.setColor(Color(255, 255, 255));   //
				win600.setColor(Color(150, 150, 255));
				win1000.setColor(Color(150, 150, 255));
				points_static = 300;
			}
		}


		/////=============          600
		if (IntRect(337, 244, 80, 35).contains(Mouse::getPosition(app)))
		{
			if (IntRect(337, 244, 80, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				win300.setColor(Color(150, 150, 255));
				win600.setColor(Color(255, 255, 255));  //
				win1000.setColor(Color(150, 150, 255)); 
				points_static = 600;
			}
		}



		/////=============          1000
		if (IntRect(421, 244, 43, 35).contains(Mouse::getPosition(app)))
		{
			if (IntRect(421, 244, 43, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				win300.setColor(Color(150, 150, 255));
				win600.setColor(Color(150, 150, 255));
				win1000.setColor(Color(255, 255, 255));
				points_static = 1000;
			}
		}

		//==========================================================================================================
	
		if (IntRect(190, 383, 69, 72).contains(Mouse::getPosition(app)))
		{
			on.setPosition(190, 383);
			if (IntRect(190, 383, 69, 72).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				app.close();
				volume_static = true;
				time_static = 150;
				points_static = 300;
				RenderWindow window(sf::VideoMode(740, 480), "MENU");
				Class_Menu menu;
				menu.Menu(window);
			}
		}
		else
			on.setPosition(1900, 3830);

		if (IntRect(268,389,61,60).contains(Mouse::getPosition(app)))
		{
			off.setPosition(268, 389);
			if (IntRect(268, 389, 61, 60).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				app.close();
				RenderWindow window(sf::VideoMode(740, 480), "MENU");
				Class_Menu menu;
				menu.Menu(window);
			}
		}
		else
		off.setPosition(2680, 3809);
		/////////////////////////////////////////////////////////// ABOUT THE PROGRAM
		if (IntRect(296, 228, 174, 52).contains(Mouse::getPosition(app)))
		{
			t12.loadFromFile("./images/option2.png");
		/*	if (IntRect(296, 228, 174, 52).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
			
			}*/
		}
		else
			t12.loadFromFile("./images/option.png");
		/////////////////////////////////////////////////////////

		if (e.key.code == sf::Keyboard::Escape)
		{
			app.close();
			RenderWindow window(sf::VideoMode(740, 480), "MENU");
			Class_Menu menu;
			menu.Menu(window);
		}
		/////////////////////////////////////////   —“»À‹
        
		if (IntRect(65, 314, 60, 55).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
		{
			stil = 1;
			tm1.loadFromFile("./images/st1.1.png");
			tm2.loadFromFile("./images/st2.png");
			tm3.loadFromFile("./images/st3.png");
			tm4.loadFromFile("./images/st4.png");
		}
		if (IntRect(138, 320, 60, 55).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
		{
			stil = 2;
			tm4.loadFromFile("./images/st4.png");
			tm2.loadFromFile("./images/st2.2.png");
			tm1.loadFromFile("./images/st1.png");
			tm3.loadFromFile("./images/st3.png");
		}
		if (IntRect(211, 320, 60, 55).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
		{
			stil = 3;
			tm4.loadFromFile("./images/st4.png");
			tm3.loadFromFile("./images/st3.3.png");
			tm2.loadFromFile("./images/st2.png");
			tm1.loadFromFile("./images/st1.png");
		}
		if (IntRect(284, 320, 60, 55).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
		{
			stil = 4;
			tm4.loadFromFile("./images/st4.4.png");
			tm3.loadFromFile("./images/st3.png");
			tm2.loadFromFile("./images/st2.png");
			tm1.loadFromFile("./images/st1.png");
		}

		/////////////////////////////////



		app.draw(volume);
		app.draw(volume_no);
		app.draw(tim150);
		app.draw(tim300);
		app.draw(tim600);
		app.draw(win300);
		app.draw(win600);
		app.draw(win1000);
		app.draw(on);
		app.draw(off);
		app.draw(stil_1);
		app.draw(stil_2);
		app.draw(stil_3);
		app.draw(stil_4);
		app.display();

		
	}
}
Class_Option::Class_Option()
{
}


Class_Option::~Class_Option()
{
}
