#include "Class_Client.h"



string Class_Client::Wind(RenderWindow & app)
{
	t1.loadFromFile("./images/fon_stil_3.jpg");
	t2.loadFromFile("./images/connect.png");

	Sprite  background(t1),knp(t2);

	knp.setPosition(296, 228);

	string ip_str = "";
	while (app.isOpen())
	{
		
		IpAddress ip = IpAddress::getLocalAddress();
		Event e;
		while (app.pollEvent(e))
		{

			if (e.type == Event::Closed)
				app.close();
		}
		
		if (e.key.code == sf::Keyboard::Num1)
		{
			ip_str += "1";
		}

		if (e.key.code == sf::Keyboard::Num2)
		{
			ip_str += "2";
		}

		if (e.key.code == sf::Keyboard::Num3)
		{
			ip_str += "3";
		}

		if (e.key.code == sf::Keyboard::Num4)
		{
			ip_str += "4";
		}

		if (e.key.code == sf::Keyboard::Num5)
		{
			ip_str += "5";
		}

		if (e.key.code == sf::Keyboard::Num6)
		{
			ip_str += "6";
		}

		if (e.key.code == sf::Keyboard::Num7)
		{
			ip_str += "7";
		}

		if (e.key.code == sf::Keyboard::Num8)
		{
			ip_str += "8";
		}

		if (e.key.code == sf::Keyboard::Num9)
		{
			ip_str += "9";
		}

		if (e.key.code == sf::Keyboard::Num0)
		{
			ip_str += "0";
		}

		if (e.key.code == sf::Keyboard::BackSpace)
		{
			ip_str.clear();
		}

		if (e.key.code == sf::Keyboard::Numpad0)
		{
			ip_str += ".";
		}
		
		//e.key.code = sf::Keyboard::F4;

		if (IntRect(296, 228, 163, 64).contains(Mouse::getPosition(app) ) )
		{
			t2.loadFromFile("./images/connect_2.png");
			if (IntRect(296, 228, 163, 64).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				if (Class_Menu::ip == "")
				{
					Class_Menu::ip = "192.168.128.50";
				}
				if (ip_str == Class_Menu::ip)
				{
					Sleep(1000);
					app.close();
			}
				   else 
					   ip_str = "Error";
			}
		}
		else
			t2.loadFromFile("./images/connect.png");

		e.key.code = sf::Keyboard::F4;
		std::cout << ip_str << "\n";
		Font font;//шрифт 

		font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
		Text text(ip_str, font, 70);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
		Text text2("Enter ip:", font, 70);

		text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

		//text.setCharacterSize(70);
		text.setPosition(300, 100);
		text2.setPosition(10, 100);

		app.draw(background);
		app.draw(text);
		app.draw(text2);
		app.draw(knp);
		app.display();
	}
	return ip_str;
}

Class_Client::Class_Client()
{
}


Class_Client::~Class_Client()
{
}
