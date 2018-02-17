#include "Class_Game_over.h"
#include <Windows.h>

void Class_Game_over::Wind(RenderWindow & app,int calc2,bool winer)
{

	SoundBuffer buffer;
	buffer.loadFromFile("./sound/end.ogg");// тут загружаем в буфер что то
	Sound sound;
	sound.setBuffer(buffer);

	SoundBuffer buffer2;
	buffer2.loadFromFile("./sound/TimeUp.ogg");// тут загружаем в буфер что то
	Sound sound2;
	sound2.setBuffer(buffer2);

	if (winer==true)
		buffer.loadFromFile("./sound/win.ogg");
	if (Class_Option::volume_static)
	{
		sound2.play();
		sound.play();
	}

	


	t1.loadFromFile("./images/you_lose.png");
//	t1.loadFromFile("./images/you_win.png");
	t2.loadFromFile("./images/you_lose.png");
	t3.loadFromFile("./images/time_over.png");
	t4.loadFromFile("./images/set2.png");
	t5.loadFromFile("./images/set2.png");
	t6.loadFromFile("./images/set2.png");
	t7.loadFromFile("./images/exit_1.png");
	Sprite background(t1),img(t2), set1(t4), set2(t5), set3(t6),win(t3), pow(t7);

	img.setPosition(225, -2);
	pow.setPosition(550, 420);
	win.setPosition(176, 150);
	time_t time_start;
	
	while (app.isOpen())
	{
		//std::cout << calc2 << "\n";
		time_start = time(NULL);
		app.draw(background);
		if (time_start % 2 == 0)
		{
			img.setColor(Color(20, 255, 255));
			set1.setColor(Color(20, 255, 255));
			set2.setColor(Color(20, 255, 255));
			set3.setColor(Color(20, 255, 255));
		}
		else
		{
			img.setColor(Color(255, 255, 255));
			set1.setColor(Color(255, 255, 255));
			set2.setColor(Color(255, 255, 255));
			set3.setColor(Color(255, 255, 255));
		}
		if (time_start % 10 == 5)
		{
			img.setColor(Color(255, 20, 255));
			set1.setColor(Color(255, 20, 255));
			set2.setColor(Color(255, 20, 255));
			set3.setColor(Color(255, 20, 255));
		}
		/////////////////////////////////////

		Event e;

		while (app.pollEvent(e))
		{

			if (e.type == Event::Closed)
				app.close();
			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
				{
				//	if (!isSwap && !isMoving) click++;
					//pos = Mouse::getPosition(app) ;
				}
		}
		/////////////////////////////////////////
		if (IntRect(550, 420, 163, 64).contains(Mouse::getPosition(app)))
		{
			t7.loadFromFile("./images/exit_2.png"); // ћ≈Ќя≈ћ  Ќќѕ ” ƒЋя јЌ»ћј÷»»
			if ( e.key.code == Mouse::Left)
			{
				exit(0);
			}
		}
		else
		{
			t7.loadFromFile("./images/exit_1.png"); // »Ќј„≈ ќ—“ј¬Ћя≈ћ 
		}
/////////////////////////////////////////////////////////////////
		if ((((calc2) / 100) - 1) < 0)
		{
			set1.setTextureRect(IntRect(9 * 35, 0, 35, 35));
			set1.setPosition(396, 163);
		}
		else
		{
			set1.setTextureRect(IntRect((((calc2) / 100) - 1) * 35, 0, 35, 35));
			set1.setPosition(396, 163);
		}
		if (((((calc2) / 10) % 10) - 1) < 0)
		{
			set2.setTextureRect(IntRect(9 * 35, 0, 35, 35));
			set2.setPosition(426, 163);
		}
		else
		{
			set2.setTextureRect(IntRect(((((calc2) / 10) % 10) - 1) * 35, 0, 35, 35));
			set2.setPosition(426, 163);
		}
		if (((calc2 % 10) - 1) < 0)
		{
			set3.setTextureRect(IntRect(9 * 35, 0, 35, 35));
			set3.setPosition(456, 163);
		}
		else
		{
			set3.setTextureRect(IntRect((((calc2)  % 10) - 1) * 35, 0, 35, 35));
			set3.setPosition(456, 163);
		}
		
		if (winer == true)
		{
			t1.loadFromFile("./images/fon_gameover2.jpg");
		//	t1.loadFromFile("./images/you_win.png");
			t3.loadFromFile("./images/win.png");
			win.setPosition(247, 224);
			app.draw(win);
		}
		// если нажата кнопка escape то выйти в главное меню 
		if (e.key.code == sf::Keyboard::Escape)
		{
			app.close();
			Class_Realization ob;
			RenderWindow app(VideoMode(740, 480), "GAcfdgME");
			app.setFramerateLimit(60);
			ob.Realization(app);
		}
		// показать елементы на окне
	//	app.draw(win);
		app.draw(set1);
		app.draw(set2);
		app.draw(set3);
		
		//app.draw(img);
		app.draw(pow);
		app.display();
		
	 }
	
}
Class_Game_over::Class_Game_over()
{
}


Class_Game_over::~Class_Game_over()
{
}
