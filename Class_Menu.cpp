#include "Class_Menu.h"
#include "Class_Studies.h"
#include "Class_Client_or_Server.h"
#include "Class_Server.h"
#include "Class_Client.h"
#include <iostream>


string Class_Menu::ip = "";
void Class_Menu::Menu(RenderWindow & window)
{	
		Music music, music2;//ñîçäàåì îáúåêò ìóçûêè
		music.openFromFile("./sound/elem.ogg");//çàãðóæàåì ôàéë
		music2.openFromFile("./sound/menu.ogg");
		if (Class_Option::volume_static == true)
		{
			music2.play();
		}	

	{
		menuTexture1.loadFromFile("./images/button_new_game.png");
		menuTexture2.loadFromFile("./images/button_program.png");
		menuTexture3.loadFromFile("./images/exit_1.png");
		menuBackground.loadFromFile("./images/menu_saver.png");
		inf_Background.loadFromFile("./images/inf_background.jpg");
		t12.loadFromFile("./images/option.png");
		t6.loadFromFile("./images/multi_off.png");
		//t7.loadFromFile("./images/multi_on.png");
	}

	
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), infBg(inf_Background), menuBg(menuBackground),/*stil_1(tm1), stil_2(tm2), stil_3(tm3), stil_4(tm4),*/ bout(t12), multi_off(t6);//, multi_on(t7);
	
	//  Ïîçèöèè ñïðàéòîâ 
	{
		menu1.setPosition(281, 102);
		menu2.setPosition(297, 170);
		menu3.setPosition(310, 280);
		bout.setPosition(296, 228);
		multi_off.setPosition(284, 335);
	//	multi_on.setPosition(284, 377);
	}



	
	//////////////////////////////ÌÅÍÞ///////////////////
	
	while (isMenu)
	{
		//////
	//	std::cout << Class_Option::volume_static << "\n";
		////
		Event e;
		while (window.pollEvent(e))
		{

			if (e.type == Event::Closed)
				window.close();
		}

	
	 

		// Öâåòà ñïðàéòîâ 
		{
			menu1.setColor(Color::White);
			menu2.setColor(Color::White);
			menu3.setColor(Color::White);
			menuNum = 0;
			window.clear(Color(129, 181, 221));
		}

		// åñëè íàæàòà êíîïêà ¹1
		{
			if (IntRect(282, 101, 200, 58).contains(Mouse::getPosition(window)))
			{
				menuTexture1.loadFromFile("./images/button_new_game_2.png"); menuNum = 1;

			}
			else
			{
				menuTexture1.loadFromFile("./images/button_new_game.png");
			}
		}

		// åñëè íàæàòà êíîïêà ¹2
		{
			if (IntRect(288, 170, 188, 55).contains(Mouse::getPosition(window)))
			{
				menuTexture2.loadFromFile("./images/button_program_2.png"); menuNum = 2;
			}
			else
			{
				menuTexture2.loadFromFile("./images/button_program.png");
			}
		}

		// åñëè íàæàòà êíîïêà ¹4
		{
			if (IntRect(310, 280, 141, 59).contains(Mouse::getPosition(window)))
			{
				menuTexture3.loadFromFile("./images/button_exit_2.png"); menuNum = 3;
			}
			else
			{
				menuTexture3.loadFromFile("./images/button_exit_1.png");
			}
		}
		
		//  Åñëè íàæàòà îäíà èç êíîïîê
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1)
				{
					music2.stop();
					window.close();
					Class_Realization ob;
					RenderWindow app(VideoMode(740, 480), "GAMfffE");
					music.stop();//    çâóê  êíîïêè
					app.setFramerateLimit(60);
					ob.Realization(app);

					isMenu = false;
				}
				if (menuNum == 2)
				{
					window.close();
					music2.stop();
					RenderWindow win(sf::VideoMode(525, 480), "Option");
					Class_Option men;
					men.Wind(win);
				}
				if (menuNum == 3)
				{
					music.openFromFile("./sound/elem1.ogg");
					window.close();
					isMenu = false;
					if (Class_Option::volume_static == true)
						music.play();
					Sleep(300);
					exit(0);
				}
			}
		}

		/////////////////////////////////////////////////////////// ABOUT THE PROGRAM  (åñëè íàæàòà êíîïêà ¹3)
		if (IntRect(296, 228, 174, 52).contains(Mouse::getPosition(window)))
		{
			t12.loadFromFile("./images/option2.png");
			if (IntRect(296, 228, 174, 52).contains(Mouse::getPosition(window)) && e.key.code == Mouse::Left)
			{
				window.close();
				RenderWindow widow(sf::VideoMode(740, 479), "Zast");
				Class_Studies we;
				we.Screensaver(widow);

				

				RenderWindow window(sf::VideoMode(740, 480), "MENU");
				Class_Menu menu;
				menu.Menu(window);
			}
		}
		else
			t12.loadFromFile("./images/option.png");

		if (e.key.code == sf::Keyboard::Delete)
		{
			HWND hWnd = GetConsoleWindow();
			ShowWindow(hWnd, 1);
			cin >> ip;

		}
		if (e.key.code == sf::Keyboard::Insert)
		{
			HWND hWnd = GetConsoleWindow();
			ShowWindow(hWnd, SW_HIDE);
		}
		/////////////////////////////////////////////////////////
		if (IntRect(284, 335, 200, 58).contains(Mouse::getPosition(window)))
		{
			t6.loadFromFile("./images/multi_on.png");
			if (IntRect(284, 335, 200, 58).contains(Mouse::getPosition(window)) && e.key.code == Mouse::Left)
			{
				music2.stop();
				RenderWindow widow(sf::VideoMode(740, 479), "Zast");
				Class_Client_or_Server we;
				we.Wind(widow);

				if (Class_Client_or_Server::chr == 's') {
					RenderWindow widow(sf::VideoMode(740, 479), "Zast");
					Class_Server we;
					we.Wind(widow);
					widow.close();
				}
				if (Class_Client_or_Server::chr == 'c') {
					RenderWindow widow(sf::VideoMode(740, 479), "Zast");
					Class_Client we;
					we.Wind(widow);
					widow.close();
				}
				window.close();
				Class_Network ob;
				RenderWindow app(VideoMode(740, 480), "GAMfffE");
				music.stop();//    çâóê  êíîïêè
				app.setFramerateLimit(60);
				ob.Realization(app);
			}
		}
		else
			t6.loadFromFile("./images/multi_off.png");
		///////////////////////////////////////////////////////////////////////////
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(multi_off);
		window.draw(bout);
		window.display();
	}
	////////////////////////////////////////////////////
}

Class_Menu::Class_Menu()
{
}


Class_Menu::~Class_Menu()
{
}
