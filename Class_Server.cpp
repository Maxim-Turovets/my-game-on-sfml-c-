#include "Class_Server.h"



void Class_Server::Wind(RenderWindow & app)
{

	t1.loadFromFile("./images/fon_stil_3.jpg");
	

	Sprite  background(t1);
	

	while (app.isOpen())
	{
		
		IpAddress ip = IpAddress::getLocalAddress();
		Event e;
		while (app.pollEvent(e))
		{

			if (e.type == Event::Closed)
				app.close();
		}
		Font font;//шрифт 

		font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
				  Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
				  Text text2("Your ip:", font, 70);
				  Text text3("press space to continue", font, 30);
				  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
				  text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
				  text.setString(ip.toString());//задает строку тексту
				  text.setCharacterSize(70);
				  text.setPosition(200, 300);
				  text2.setPosition(260, 94);
				  text3.setPosition(227,437 );
				  if (e.key.code == sf::Keyboard::Space)
				  {
					  app.close();
				  }
				 
		app.draw(background);
		app.draw(text);
		app.draw(text2);
		app.draw(text3);
		app.display();
	}
}

Class_Server::Class_Server()
{
}


Class_Server::~Class_Server()
{
}
