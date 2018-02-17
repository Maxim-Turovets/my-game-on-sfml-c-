#include "Class_Realization.h"
#include "Class_Menu.h"
#include "Class_Game_over.h"
#include "Class_Network.h"
#include "Class_Client_or_Server.h"
#include "Class_Server.h"

void Class_Network::swap(piece p1, piece p2)
{
	std::swap(p1.col, p2.col);
	std::swap(p1.row, p2.row);

	grid[p1.row][p1.col] = p1;
	grid[p2.row][p2.col] = p2;
}


void Class_Network::Realization(RenderWindow & app)
{

	/////////////////////

	SoundBuffer bufer;
	bufer.loadFromFile("./sound/mus.ogg");// тут загружаем в буфер что то
	Sound sound;
	sound.setBuffer(bufer);

	//================================================================================
	setlocale(LC_ALL, "");		// Поддержка кириллицы в консоли Windows

	IpAddress ip = IpAddress::getLocalAddress();	//Локальный ip Адресс
	TcpSocket socket;//программный интерфейс для обеспечения обмена данными между процессами
	Packet packet;	//Для осуществления пакетной передачи дынных
	char type;
	char mode = ' ';//Мод s- сервер, с - клиент
	char buffer[2000];
	size_t received;	//??
	string text = "connect to: ";

	//if (Client::iff == false)
	{

	cout << ip << endl;
	cout << "Введите тип подключения:  c -клиент, s -сервер" << endl;
	
	 type= Class_Client_or_Server::chr;
	
	 
	Socket::Status status;

	
	  // ЕСЛИ ВЫБРАН СЕРВЕР

		if (type == 's') {

			

			TcpListener listener;
			status = listener.listen(2000);
			if (status != Socket::Done) {
				std::cout << "\nCannot bind 2000 port for server";
				return;
			}
			status = listener.accept(socket);    //который будет содержать новое соединение
			if (status != Socket::Done) {
				std::cout << "\nError occurred when hanlde incoming connection";
				return;
			}
		
			text += "Server";
			mode = 's';

		}

	 //  ЕСЛИ ВЫБРАН КЛИЕНТ
		else if (type == 'c')
		{
			cout << "new ip:";
			if (Class_Menu::ip == "")
			{
				Class_Menu::ip = "192.168.128.50";
			}
			sf::IpAddress a2(Class_Menu::ip);
			status = socket.connect(a2, 2000, sf::seconds(1)); //ip и Порт
			if (status != Socket::Done) {
				std::cout << "\nError occurred when connect to server. Server is unreacheble";
				return;
			}
			text += "client";
			mode = 'r';
		}

		// ПЕРЕДАЧА ПАКЕТА ДАННЫХ
		socket.send(text.c_str(), text.length() + 1);
		socket.receive(buffer, sizeof(buffer), received);
		std::cout << buffer;
	}
	//================================================================================





	/////////////////////
	int prv = 0, calc = 0, calc2 = 0, calc3 = 0;
	x = 0;
	y = 0;
	x0 = 0;
	y0 = 0;

	{
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				grid[i][j].kind = rand() % 3;
				grid[i][j].col = j;
				grid[i][j].row = i;
				grid[i][j].x = j*ts;
				grid[i][j].y = i*ts;
			}
	}
	// Загружаем картинки
	{
		t1.loadFromFile("./images/fon_stil_1.jpg");
		t2.loadFromFile("./images/stil_4.png");
		t3.loadFromFile("./images/ochki.png");
		t4.loadFromFile("./images/set.png");
		t5.loadFromFile("./images/set.png");
		t6.loadFromFile("./images/set.png");
		t7.loadFromFile("./images/update1.png");
		t8.loadFromFile("./images/str.png");
		t9.loadFromFile("./images/mute_1.png");
		t10.loadFromFile("./images/exit_1.png");
		t11.loadFromFile("./images/ramk.png");
		t12.loadFromFile("./images/screen1.png");
		t13.loadFromFile("./images/screen2.png");
		t14.loadFromFile("./images/you_win.png");
		t15.loadFromFile("./images/you_lose.png");
	}


	Sprite background(t1), gems(t2), cursor(t3), set1(t4), set2(t5), set3(t6), update1(t7), str1(t8), str2(t8), volume(t9), pow(t10), ram(t11), tim(t12), tim2(t13), win(t14), lose(t15);

	// начальные позиции текстур
	{
		str1.setPosition(525, 52);
		str2.setPosition(700, 52);
		update1.setPosition(550, 420);
		volume.setPosition(550, 280);
		pow.setPosition(550, 350);
		ram.setPosition(5500, 3500);
		tim.setPosition(-12, -12);
		tim2.setPosition(-12, -12);
	}

	if (Class_Option::volume_static == true)
		sound.play();



	Vector2i offset(48, 24);
	bool winer = false;
	int h = 0;

	//        ВЫБОР СТИЛЯ ЭЛЕМЕНТОВ
	{
		if (Class_Option::stil == 1)
		{
			t2.loadFromFile("./images/stil_1.jpg");
			t1.loadFromFile("./images/fon_stil_2.png");
		}
		if (Class_Option::stil == 2)
		{
			ram.setPosition(505, 18);
			t2.loadFromFile("./images/stil_3.png");
			t1.loadFromFile("./images/fon_stil_3.png");
		}
		if (Class_Option::stil == 3)
		{
			t2.loadFromFile("./images/stil_2.png");
			t1.loadFromFile("./images/fon_stil_1.png");
		}
		if (Class_Option::stil == 4)
		{
			ram.setPosition(505, 18);
			t2.loadFromFile("./images/stil_4.png");
			t1.loadFromFile("./images/fon_stil_23.png");
		}
	}


	//======================================================================================================================
	time_t time_start;

	time_start = time(NULL); // получить текущую дату, выраженную в секундах
	int time_end = time_start + Class_Option::time_static;


	while (app.isOpen())
	{

		time_t time_p;
		time_p = time(NULL);
		int raz = time_p - time_start;

		//==============================================================================
		if (mode == 's')
		{
			{
				if (calc2 > 300)
				{
					string command = "stop_lost";
					socket.send(command.c_str(), command.length());
					socket.disconnect();
				
					sound.stop();
					winer = true; // if server has > 199 points - game is over
					app.close();
					RenderWindow widow(sf::VideoMode(740, 479), "Server");
					Class_Game_over obj;
					obj.Wind(widow, calc2, winer);
					return; // game is over - return

				}
				//////////////////////////
				int clientPoints = 0;
				packet >> clientPoints;
				//	if (socket.disconnect())
				if (clientPoints > 300)
				{
					sound.stop();
					winer = false;
					string command = "stop_win";
					socket.send(command.c_str(), command.length());
					socket.disconnect();
					app.close();
					RenderWindow widow(sf::VideoMode(740, 479), "Server");
					Class_Game_over obj;
					obj.Wind(widow, calc2, winer);
					/*	RenderWindow widow(sf::VideoMode(740, 479), "Server");
					widow.draw(win);*/
					return; // game is over - return
				}
				
				socket.receive(packet);
			}

		}



		if (mode == 'r')
		{
			{
				Packet clientPacket;
				socket.setBlocking(false);
				Socket::Status status = socket.receive(clientPacket);
				//////////////////////////////////////////////////////////////////
				if (status == socket.Disconnected)
				{
					sound.stop();
					winer = false;
					socket.disconnect();
					app.close();
					RenderWindow widow(sf::VideoMode(740, 479), "Client");
					Class_Game_over obj;
					obj.Wind(widow, calc2, winer);
					return; // game is over - return
				}
				packet << calc2;
				socket.send(packet);
				packet.clear();
				sleep(sf::milliseconds(10));
			}

			if (calc2 > 300)
			{
				sound.stop();
				winer = true;
				socket.disconnect();
				app.close();
				RenderWindow widow(sf::VideoMode(740, 479), "Client");
				Class_Game_over obj;
				obj.Wind(widow, calc2, winer);
				return; // game is over - return
			}
		}

		//==============================================================================



		if (time_p == time_end)
			app.close();
		//счетчики
		int clik = 0;
		int  het = 0;
		Event e;
		//==========
		{
			while (app.pollEvent(e))
			{

				if (e.type == Event::Closed)
					app.close();

				if (e.type == Event::MouseButtonPressed)
					if (e.key.code == Mouse::Left)
					{
						if (!isSwap && !isMoving) click++;
						pos = Mouse::getPosition(app) - offset;
					}
			}
		}

		//==================================ПЕРВОНАЧАЛЬНОЕ ОБНУЛЕНИЕ
		{
			if (x0 == 0 && y0 == 0 || x0 == -17 && y0 == -17)
			{
				calc = 0;
				t3.loadFromFile("./images/ochki2.png");
			}
			else
			{
				t3.loadFromFile("./images/ochki.png");
			}
		}


		//==================================ЕСЛИ НАЖАТА КНОПКА ВЫХОД ЗАКРЫВАЕМ ОКНО
		{
			if (IntRect(550, 350, 163, 64).contains(Mouse::getPosition(app)))
			{
				t10.loadFromFile("./images/exit_2.png"); // МЕНЯЕМ КНОПКУ ДЛЯ АНИМАЦИИ
				if (IntRect(550, 350, 163, 64).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left)
				{
					exit(0);
				}
			}

			else
			{
				t10.loadFromFile("./images/exit_1.png"); // ИНАЧЕ ОСТАВЛЯЕМ 
			}
		}

		//   ===============================КНОПКА ВЫКЛЮЧЕНИЯ ЗВУКА
		{
			if (IntRect(550, 280, 162, 64).contains(Mouse::getPosition(app)))
			{
				if (e.key.code == Mouse::Left)
				{
					if (Class_Option::volume_static == true)
						sound.stop(); // ОСТАНАВЛИВАЕМ МУЗЫКУ
									  //else
									  //sound.play();
				}
				t9.loadFromFile("./images/mute_2.png");   // КАРТИНКА ДЛЯ АНИМАЦИИ
			}
			else
			{
				t9.loadFromFile("./images/mute_1.png"); // ИНАЧЕ ОСТАВЛЯЕМ КАК ЕСТЬ 
			}

		}

		// =================================ПРОВЕРКА НА ВЫХОД ЗА ПРЕДЕЛЫ МАТРИЦЫ
		{
			if (pos.x < 0 || pos.y < 0 || pos.y >428 || pos.x>428 || prv == 0)
			{
				pos.x = -600;
				pos.y = -600;
			}
			prv = 1;
		}

		// =================================ДЕЙСТВИЕ ПРИ НАЖАТИИ КНОПКИ
		{
			if (click == 1)
			{
				x0 = pos.x / ts + 1;
				y0 = pos.y / ts + 1;
				grid[y0][x0].color_b = 1;
			}

			if (click == 2)   // ЕСЛИ БЫЛ ВТОРОЙ КЛИК 
			{

				x = pos.x / ts + 1;
				y = pos.y / ts + 1;

				grid[y][x].color_b = 1;  // выделение цветом текщего елемента 
				if (abs(x - x0) + abs(y - y0) == 1)
				{
					swap(grid[y0][x0], grid[y][x]); isSwap = 1; click = 0;

				}
				else
				{
					click = 1;
					grid[y0][x0].color_b = 255;
					grid[y][x].color_b = 255;
				}
			}
		}

		//Поиск совпадений относительно текущего елемента
		{
			for (int i = 1; i <= 8; i++)
			{
				for (int j = 1; j <= 8; j++)
				{
					if (grid[i][j].kind == grid[i + 1][j].kind)
					{
						if (grid[i][j].kind == grid[i - 1][j].kind)
						{
							for (int n = -1; n <= 1; n++)
							{
								grid[i + n][j].match++;
							}
						}
					}

					if (grid[i][j].kind == grid[i][j + 1].kind)
					{
						if (grid[i][j].kind == grid[i][j - 1].kind)
						{
							for (int n = -1; n <= 1; n++)
							{
								grid[i][j + n].match++;
							}
						}
					}
				}
			}
		}

		// Перемещение анимации
		{
			isMoving = false;
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
				{
					piece &p = grid[i][j];
					int dx, dy;
					for (int n = 0; n < 4; n++)   // 4 - скорость выпадания елементов
					{
						dx = p.x - p.col*ts;
						dy = p.y - p.row*ts;
						if (dx) p.x -= dx / abs(dx);
						if (dy) p.y -= dy / abs(dy);
					}
					if (dx || dy) isMoving = 1;
				}
		}

		// Удаляем анимацию
		{
			if (!isMoving)
				for (int i = 1; i <= 8; i++)
				{
					for (int j = 1; j <= 8; j++)
					{
						if (grid[i][j].match)
						{
							if (grid[i][j].alpha > 10)
							{
								het++; // счетчик балов
									   //  подсвечиваем элемент сменой цвета 
								grid[i][j].color_a += 100;
								grid[i][j].color_c += 10;
								grid[i][j].alpha -= 5;
								isMoving = true; //скорость исчизновения елементов
								cursor.setPosition(575, 150);
							}
						}
					}
				}
		}


		// Вывод картинки счетчика
		{
			int het3 = 0;
			int het2 = het - 3;
			if (het > 5)
				het2 = 2;
			cursor.setTextureRect(IntRect((het2) * 98, 0, 98, 98));
			if (het == 3)
			{
				het3 = 30;
			}
			if (het == 4)
			{
				het3 = 50;
			}
			if (het > 4)
			{
				het3 = 70;
			}
			calc += het3;
			calc2 = calc / 49;
		}

		// Счет совпадений
		int score = 0;
		{
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
					score += grid[i][j].match;
		}

		// Второй обмен, если нет совпадения
		{
			if (isSwap && !isMoving)
			{
				grid[y][x].color_b = 255;
				grid[y0][x0].color_b = 255;
				if (!score) swap(grid[y0][x0], grid[y][x]); isSwap = 0;
			}
		}

		// обновление матрицы
		{
			if (!isMoving)
			{
				for (int i = 8; i > 0; i--)
					for (int j = 1; j <= 8; j++)
						if (grid[i][j].match)
							for (int n = i; n > 0; n--)
								if (!grid[n][j].match) { swap(grid[n][j], grid[i][j]); break; };

				for (int j = 1; j <= 8; j++)
					for (int i = 8, n = 0; i > 0; i--)
						if (grid[i][j].match)
						{
							////
							grid[i][j].color_a = 255;
							grid[i][j].color_b = 255;
							grid[i][j].color_c = 255;
							////
							grid[i][j].kind = rand() % 7;
							grid[i][j].y = -ts*n++;
							grid[i][j].match = 0;
							grid[y][x].color_b = 255;
							grid[y0][x0].color_a = 255;
							grid[i][j].alpha = 255;
						}
			}
		}

		// подсвечивание кнопки обновления 
		{
			if (IntRect(550, 420, 170, 35).contains(Mouse::getPosition(app)))
			{
				t7.loadFromFile("./images/update2.png");
			}
			else
			{
				t7.loadFromFile("./images/update1.png");
			}
		}

		// если нажата кнопка обновления то 
		{
			if (IntRect(550, 420, 170, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left && (calc2) >= 300)
			{

				for (int i = 1; i <= 8; i++)
				{
					for (int j = 1; j <= 8; j++)
					{
						grid[i][j].match += 1;
					}
				}

				calc2 = 100;
				if (calc2 < 0)
					calc2 == 0;
				calc = (100) * 49;
			}
		}

		////////////////////////                    ПОЛОСА         TIME
		{
			float s = 600 / Class_Option::time_static;
			tim2.setTextureRect(IntRect(0, 0, raz*s, 55));
			app.draw(background);
		}

		/////////////////////////        СТАНДАРТ ОДНА КАРТИНКА РАЗБИВАЕТСЯ НА 7 ЧАСТЕЙ
		{
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
				{
					piece p = grid[i][j];
					gems.setTextureRect(IntRect(p.kind * 49, 0, 49, 49));
					gems.setColor(Color(p.color_a, p.color_b, p.color_c, p.alpha));
					gems.setPosition(p.x, p.y);
					gems.move(offset.x - ts, offset.y - ts);
					app.draw(cursor);
					app.draw(gems);

				}
			cursor.setPosition(-1000, 0);
		}

		// деление для определения  балов и последующего вывода 
		{
			if ((((calc2) / 100) - 1) < 0)
			{
				set1.setTextureRect(IntRect(9 * 49, 0, 49, 49));
				set1.setPosition(550, 45);
			}
			else
			{
				set1.setTextureRect(IntRect((((calc2) / 100) - 1) * 49, 0, 49, 49));
				set1.setPosition(550, 45);
			}
			if (((((calc2) / 10) % 10) - 1) < 0)
			{
				set2.setTextureRect(IntRect(9 * 49, 0, 49, 49));
				set2.setPosition(600, 45);
			}
			else
			{
				set2.setTextureRect(IntRect(((((calc2) / 10) % 10) - 1) * 49, 0, 49, 49));
				set2.setPosition(600, 45);
			}
			set3.setTextureRect(IntRect(9 * 49, 0, 49, 49));
			set3.setPosition(650, 45);
		}

		// показать елементы на окне
		{
			app.draw(set1);
			app.draw(set2);
			app.draw(set3);
			app.draw(update1);
			app.draw(volume);
			app.draw(pow);
			app.draw(ram);
			app.draw(tim);
			app.draw(tim2);
			//	widow.draw(win);
		}

		// если нажата кнопка обновления , то подсветить счетчик
		{
			if (IntRect(550, 420, 170, 35).contains(Mouse::getPosition(app)) && e.key.code == Mouse::Left && calc3 < 300)
			{
				app.draw(str1);
				app.draw(str2);
			}
			app.display();
		}

		// если нажата кнопка escape то выйти в главное меню 
		{
			if (e.key.code == sf::Keyboard::Escape)
			{
				sound.stop();
				app.close();
				RenderWindow window(sf::VideoMode(740, 480), "MENU");
				Class_Menu menu;
				menu.Menu(window);
			}
		}
	}
}



Class_Network::Class_Network()
{
}


Class_Network::~Class_Network()
{
}
