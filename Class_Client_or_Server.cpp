#include "Class_Client_or_Server.h"


char Class_Client_or_Server::chr ;

void Class_Client_or_Server::Wind(RenderWindow & app)
{
	
	t1.loadFromFile("./images/fon_stil_3.jpg");
	tm1.loadFromFile("./images/server.png");
	tm2.loadFromFile("./images/client.png");

	Sprite stil_1(tm1), stil_2(tm2), background(t1);
	stil_1.setPosition(295, 184);
	stil_2.setPosition(295, 284);

	while (app.isOpen())
	{
		std::cout << Class_Client_or_Server::chr << std::endl;
		
		Event e;
		while (app.pollEvent(e))
		{

			if (e.type == Event::Closed)
				app.close();
		}
		
		if (IntRect(295, 184, 163, 64).contains(Mouse::getPosition(app)))
		{
			tm1.loadFromFile("./images/server_2.png"); // ÌÅÍßÅÌ ÊÍÎÏÊÓ ÄËß ÀÍÈÌÀÖÈÈ
			if (IntRect(295, 184, 163, 64).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				chr = 's';
				app.close();
			}
		}

		else
		{
			tm1.loadFromFile("./images/server.png"); // ÈÍÀ×Å ÎÑÒÀÂËßÅÌ 
		}

		if (IntRect(295, 284, 163, 64).contains(Mouse::getPosition(app)))
		{
			tm2.loadFromFile("./images/client_2.png"); // ÌÅÍßÅÌ ÊÍÎÏÊÓ ÄËß ÀÍÈÌÀÖÈÈ
			if (IntRect(295, 284, 163, 64).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
			{
				chr = 'c';
				app.close();
			}
		}

		else
		{
			tm2.loadFromFile("./images/client.png"); // ÈÍÀ×Å ÎÑÒÀÂËßÅÌ 
		}


		app.draw(background);
		app.draw(stil_1);
		app.draw(stil_2);
		app.display();
	}

	
}

Class_Client_or_Server::Class_Client_or_Server()
{
}


Class_Client_or_Server::~Class_Client_or_Server()
{
}
