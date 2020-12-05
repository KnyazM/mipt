#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"


using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1200, 675), "SFML works!");// еще один параметр: Style::Fullscreen

	//! MAP!

	Image map_image;//объект изображения для карты
	map_image.loadFromFile("images/map.png");//загружаем файл для карты
	Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом

	//! SIMBA!

	Image simbaimg; //создаем объект Image (изображение)
	simbaimg.loadFromFile("images/simba.png");//загружаем в него файл

	Texture simbatexture;//создаем объект Texture (текстура)
	simbatexture.loadFromImage(simbaimg);//передаем в него объект Image (изображения)

	Sprite simbasprite;//создаем объект Sprite(спрайт)
	simbasprite.setTexture(simbatexture);//передаём в него объект Texture (текстуры)
	simbasprite.setTextureRect(IntRect(0, 180, 38, 38));//получили нужный нам прямоугольник с котом
	simbasprite.setPosition(250, 250);//задаем начальные координаты появления спрайта

	//! KOVU!

	Image kovuimg; //создаем объект Image (изображение)
	kovuimg.loadFromFile("images/kovu.png");//загружаем в него файл

	Texture kovutexture;//создаем объект Texture (текстура)
	kovutexture.loadFromImage(kovuimg);//передаем в него объект Image (изображения)

	Sprite kovusprite;//создаем объект Sprite(спрайт)
	kovusprite.setTexture(kovutexture);//передаём в него объект Texture (текстуры)
	kovusprite.setTextureRect(IntRect(0, 0, 38, 38));//получили нужный нам прямоугольник с котом
	kovusprite.setPosition(200, 200);//задаем начальные координаты появления спрайта


	float CurrentFrame = 0;
	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 800; //скорость игры
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//! MOVING SIMBA!

		if ((Keyboard::isKeyPressed(Keyboard::Right)))
		{
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 7) CurrentFrame -= 7; // если пришли к третьему кадру - откидываемся назад.
			simbasprite.setTextureRect(IntRect(38 * int(CurrentFrame), 180, 38, 38)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
			simbasprite.move(0.1 * time, 0);//происходит само движение персонажа вправо

		}

		if ((Keyboard::isKeyPressed(Keyboard::Left)))
		{
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 7) CurrentFrame -= 7; // если пришли к третьему кадру - откидываемся назад.
			simbasprite.setTextureRect(IntRect(38 * int(CurrentFrame+1), 180, -38, 38)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
			simbasprite.move(-0.1 * time, 0);//происходит само движение персонажа влево
		
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up)))
		{	
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 2) CurrentFrame -= 2; // если пришли к третьему кадру - откидываемся назад.
			simbasprite.setTextureRect(IntRect(30 * int(CurrentFrame), 240, 30, 30)); //проходимся по координатам Х. получается 0,96,96*2, и опять 0
			simbasprite.move(0, -0.1 * time);//происходит само движение персонажа вверх
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down)))
		{
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 2) CurrentFrame -= 2; //если пришли к третьему кадру - откидываемся назад.
			simbasprite.setTextureRect(IntRect(30 * int(CurrentFrame), 240, 30, 30)); //проходимся по координатам Х. получается 0,96,96*2,и опять 0
			simbasprite.move(0, 0.1 * time);//происходит само движение персонажа вниз
		}

		//! MOVING KOVU!

		if ((Keyboard::isKeyPressed(Keyboard::D)))
		{
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 4) CurrentFrame -= 4; // если пришли к третьему кадру - откидываемся назад.
			kovusprite.setTextureRect(IntRect(41 * int(CurrentFrame), 100, 41, 27)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
			kovusprite.move(0.1 * time, 0);//происходит само движение персонажа вправо

		}

		if ((Keyboard::isKeyPressed(Keyboard::A)))
		{
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 4) CurrentFrame -= 4; // если пришли к третьему кадру - откидываемся назад.
			kovusprite.setTextureRect(IntRect(41 * int(CurrentFrame + 1), 100, -41, 27)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
			kovusprite.move(-0.1 * time, 0);//происходит само движение персонажа влево

		}

		if ((Keyboard::isKeyPressed(Keyboard::W)))
		{
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 2) CurrentFrame -= 2; // если пришли к третьему кадру - откидываемся назад.
			kovusprite.setTextureRect(IntRect(37 * int(CurrentFrame), 36, 37, 26)); //проходимся по координатам Х. получается 0,96,96*2, и опять 0
			kovusprite.move(0, -0.1 * time);//происходит само движение персонажа вверх
		}

		if ((Keyboard::isKeyPressed(Keyboard::S)))
		{
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 2) CurrentFrame -= 2; //если пришли к третьему кадру - откидываемся назад.
			kovusprite.setTextureRect(IntRect(37 * int(CurrentFrame), 36, 37, 26)); //проходимся по координатам Х. получается 0,96,96*2,и опять 0
			kovusprite.move(0, 0.1 * time);//происходит само движение персонажа вниз
		}




		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == 's') s_map.setTextureRect(IntRect(255, 0, 334, 70)); //если встретили символ пробел, то рисуем 1й квадратик
				if (TileMap[i][j] == ' ') s_map.setTextureRect(IntRect(334, 0, 400, 70));//если встретили символ s, то рисуем 2й квадратик
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 0, 70, 70));//если встретили символ 0, то рисуем 3й квадратик



				s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

				window.draw(s_map);
			}

		window.draw(simbasprite);
		window.draw(kovusprite);
		window.display();
	}


	
	return 0;
}
