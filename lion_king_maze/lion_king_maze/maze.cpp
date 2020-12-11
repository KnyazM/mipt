#include <SFML/Graphics.hpp>
#include "levels.h"
using namespace sf;

const int FIRST_LEVEL = 1;
const int SECOND_LEVEL = 2;
const int THIRD_LEVEL = 3;
const int INFO = 4;
const int EXIT = 5;

  //..................................................//
 //................УПРАВЛЕНИЕ ПЕРСОНАЖАМИ............//
//..................................................//

void Key_processing(Sprite& simbasprite, Sprite& kovusprite, float time, float CurrentFrame)
{

 //----------------------------------------------------------------------


//-------------------------------------------------------------! MOVING SIMBA!
 

    if ((Keyboard::isKeyPressed(Keyboard::Right)))
    {
        CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам".
                                      // переменная доходит до трех, суммируя произведение времени
                                      // и скорости. изменив 0.005 можно изменить скорость анимации

        if (CurrentFrame > 7) CurrentFrame -= 7; // если пришли к третьему кадру - откидываемся назад.
        simbasprite.setTextureRect(IntRect(47 * int(CurrentFrame), 245, 47, 47)); // проходимся по координатам Х.
                                                                                  // получается начинаем рисование с
                                                                                  // координаты Х равной 0,96,96*2,
                                                                                  // и опять 0
        simbasprite.move(0.1 * time, 0);//происходит само движение персонажа вправо
    }

    if ((Keyboard::isKeyPressed(Keyboard::Left)))
    {
        CurrentFrame += 0.005 * time;
        if (CurrentFrame > 7)
            CurrentFrame -= 7;

        simbasprite.setTextureRect(IntRect(47 * int(CurrentFrame + 1), 245, -47, 47));
        simbasprite.move(-0.1 * time, 0);

    }

    if ((Keyboard::isKeyPressed(Keyboard::Up)))
    {
        CurrentFrame += 0.005 * time;
        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        simbasprite.setTextureRect(IntRect(43 * int(CurrentFrame), 330, 43, 43));
        simbasprite.move(0, -0.1 * time);
    }

    if ((Keyboard::isKeyPressed(Keyboard::Down)))
    {
        CurrentFrame += 0.005 * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        simbasprite.setTextureRect(IntRect(330 * int(CurrentFrame), 330, 43, 43));
        simbasprite.move(0, 0.1 * time);
    }

//----------------------------------------------------------------------


//-------------------------------------------------------------! MOVING KOVU!


    if ((Keyboard::isKeyPressed(Keyboard::D)))
    {
        CurrentFrame += 0.005 * time;

        if (CurrentFrame > 6)
            CurrentFrame -= 6;

        kovusprite.setTextureRect(IntRect(62* int(CurrentFrame), 50, 62, 46));
        kovusprite.move(0.1 * time, 0);

    }

    if ((Keyboard::isKeyPressed(Keyboard::A)))
    {
        CurrentFrame += 0.005 * time;

        if (CurrentFrame > 6) 
            CurrentFrame -= 6;

        kovusprite.setTextureRect(IntRect(62 * int(CurrentFrame + 1), 50, -62, 46));
        kovusprite.move(-0.1 * time, 0);
    }

    if ((Keyboard::isKeyPressed(Keyboard::W)))
    {

        CurrentFrame += 0.005 * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        kovusprite.setTextureRect(IntRect(43 * int(CurrentFrame), 100, 43, 43));
        kovusprite.move(0, -0.1 * time);
    }

    if ((Keyboard::isKeyPressed(Keyboard::S)))
    {
        CurrentFrame += 0.005 * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        kovusprite.setTextureRect(IntRect(43 * int(CurrentFrame), 100, 43, 43));
        kovusprite.move(0, 0.1 * time);
    }
}

  //..................................................//
 //.................КАРТЫ ДЛЯ УРОВНЕЙ................//
//..................................................//


void Draw_map1(Sprite& s_map, RenderWindow& window, Sprite& simbasprite, Sprite& kovusprite)
{
    for (int i = 0; i < HEIGHT_MAP1; i++)
        for (int j = 0; j < WIDTH_MAP1; j++)
        {
            if (TileMap1[i][j] == 's')
                s_map.setTextureRect(IntRect(332, 0, 68, 65)); //рисуем песок

            if (TileMap1[i][j] == ' ')
                s_map.setTextureRect(IntRect(255, 0, 73, 64));//рисуем траву

            if (TileMap1[i][j] == 'l')
                s_map.setTextureRect(IntRect(0, 0, 65, 70));//рисуем 1 куст

            if (TileMap1[i][j] == 'd')
                s_map.setTextureRect(IntRect(195, 0, 58, 68));//рисуем 2 куст

            if (TileMap1[i][j] == 'h')
                s_map.setTextureRect(IntRect(130, 0, 62, 62));//рисуем прятальный куст

            if (TileMap1[i][j] == 'e')
                s_map.setTextureRect(IntRect(0, 63, 70, 68));//дорожка

            if (TileMap1[i][j] == 'a')
                s_map.setTextureRect(IntRect(72, 62, 69, 30));//поворотная дорожка

            if (TileMap1[i][j] == 'b')
                s_map.setTextureRect(IntRect(403, 0, 66, 66));//ставим блок лабиринта


            s_map.setPosition(j * 32, i * 32);// по сути раскидывает квадратики, превращая в карту.
                                              // то есть задает каждому из них позицию. если убрать,
                                              // то вся карта нарисуется в одном квадрате 32*32 и
                                              // мы увидим один квадрат.
            window.draw(s_map);
        }

    window.draw(simbasprite);
    window.draw(kovusprite);
    window.display();
}

void Draw_map2(Sprite& s_map, RenderWindow& window, Sprite& simbasprite, Sprite& kovusprite)
{
    for (int i = 0; i < HEIGHT_MAP2; i++)
        for (int j = 0; j < WIDTH_MAP2; j++)
        {
            if (TileMap2[i][j] == 's')
                s_map.setTextureRect(IntRect(332, 0, 68, 65)); //рисуем песок

            if (TileMap2[i][j] == ' ')
                s_map.setTextureRect(IntRect(255, 0, 73, 64));//рисуем траву

            if (TileMap2[i][j] == 'l')
                s_map.setTextureRect(IntRect(0, 0, 65, 70));//рисуем 1 куст

            if (TileMap2[i][j] == 'd')
                s_map.setTextureRect(IntRect(195, 0, 58, 68));//рисуем 2 куст

            if (TileMap2[i][j] == 'h')
                s_map.setTextureRect(IntRect(130, 0, 62, 62));//рисуем прятальный куст

            if (TileMap2[i][j] == 'e')
                s_map.setTextureRect(IntRect(0, 63, 70, 68));//дорожка

            if (TileMap2[i][j] == 'a')
                s_map.setTextureRect(IntRect(72, 62, 69, 30));//поворотная дорожка

            if (TileMap2[i][j] == 'b')
                s_map.setTextureRect(IntRect(403, 0, 66, 66));//ставим блок лабиринта


            s_map.setPosition(j * 32, i * 32);// по сути раскидывает квадратики, превращая в карту.
                                              // то есть задает каждому из них позицию. если убрать,
                                              // то вся карта нарисуется в одном квадрате 32*32 и
                                              // мы увидим один квадрат.
            window.draw(s_map);
        }

    window.draw(simbasprite);
    window.draw(kovusprite);
    window.display();
}


void Draw_map3(Sprite& s_map, RenderWindow& window, Sprite& simbasprite, Sprite& kovusprite)
{
    for (int i = 0; i < HEIGHT_MAP3; i++)
        for (int j = 0; j < WIDTH_MAP3; j++)
        {
            if (TileMap3[i][j] == 's')
                s_map.setTextureRect(IntRect(332, 0, 68, 65)); //рисуем песок

            if (TileMap3[i][j] == ' ')
                s_map.setTextureRect(IntRect(255, 0, 73, 64));//рисуем траву

            if (TileMap3[i][j] == 'l')
                s_map.setTextureRect(IntRect(0, 0, 65, 70));//рисуем 1 куст

            if (TileMap3[i][j] == 'd')
                s_map.setTextureRect(IntRect(195, 0, 58, 68));//рисуем 2 куст

            if (TileMap3[i][j] == 'h')
                s_map.setTextureRect(IntRect(130, 0, 62, 62));//рисуем прятальный куст

            if (TileMap3[i][j] == 'e')
                s_map.setTextureRect(IntRect(0, 63, 70, 68));//дорожка

            if (TileMap3[i][j] == 'a')
                s_map.setTextureRect(IntRect(72, 62, 69, 30));//поворотная дорожка

            if (TileMap3[i][j] == 'b')
                s_map.setTextureRect(IntRect(403, 0, 66, 66));//ставим блок лабиринта

       
            s_map.setPosition(j * 32, i * 32);// по сути раскидывает квадратики, превращая в карту.
                                              // то есть задает каждому из них позицию. если убрать,
                                              // то вся карта нарисуется в одном квадрате 32*32 и
                                              // мы увидим один квадрат.
            window.draw(s_map);
        }

    window.draw(simbasprite);
    window.draw(kovusprite);
    window.display();
}


//...........FIRST LEVEL................//

void run_1(RenderWindow& window)
{

    Image map_image;      map_image.loadFromFile("Images/map.png");

    Texture map;          map.loadFromImage(map_image);

    Sprite s_map;         s_map.setTexture(map);

    //----------------------------------------------------! MAP!

    Image simbaimg;       simbaimg.loadFromFile("Images/simba.png");

    Texture simbatexture; simbatexture.loadFromImage(simbaimg);//передаем в файл объект Image

    Sprite simbasprite;   simbasprite.setTexture(simbatexture);//передаём в него объект Texture
    simbasprite.setTextureRect(IntRect(0, 25, 40, 53));//получили прямоугольник
    simbasprite.setPosition(250, 250);//задаем начальные координаты появления спрайта

//----------------------------------------------------! SIMBA!

    Image kovuimg;        kovuimg.loadFromFile("Images/kovu.png");

    Texture kovutexture;  kovutexture.loadFromImage(kovuimg);

    Sprite kovusprite;    kovusprite.setTexture(kovutexture);
    kovusprite.setTextureRect(IntRect(0, 200, 43, 53));// получили нужный нам
                                                     // прямоугольник с котом
    kovusprite.setPosition(200, 200);//задаем начальные координаты появления спрайта

//------------------------------------------------------! KOVU!

    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart();                                      //перезагружает время
        time = time / 800;                                    //скорость игры

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();


        //! Key processing()
        Key_processing(simbasprite, kovusprite, time, CurrentFrame);

        //-------------------------------------------------------------------------------

        window.clear();

        //! Draw map 1!

        Draw_map1(s_map, window, simbasprite, kovusprite);
    }
}



//...............SECOND LEVEL................//

void run_2(RenderWindow& window)
{
        Image map_image;      map_image.loadFromFile("Images/map.png");

        Texture map;          map.loadFromImage(map_image);

        Sprite s_map;         s_map.setTexture(map);

        //----------------------------------------------------! MAP!

        Image simbaimg;       simbaimg.loadFromFile("Images/simba.png");

        Texture simbatexture; simbatexture.loadFromImage(simbaimg);//передаем в файл объект Image

        Sprite simbasprite;   simbasprite.setTexture(simbatexture);//передаём в него объект Texture
        simbasprite.setTextureRect(IntRect(0, 180, 38, 38));//получили прямоугольник
        simbasprite.setPosition(250, 250);//задаем начальные координаты появления спрайта

    //----------------------------------------------------! SIMBA!

        Image kovuimg;        kovuimg.loadFromFile("Images/kovu.png");

        Texture kovutexture;  kovutexture.loadFromImage(kovuimg);

        Sprite kovusprite;    kovusprite.setTexture(kovutexture);
        kovusprite.setTextureRect(IntRect(0, 0, 38, 38));// получили нужный нам
                                                         // прямоугольник с котом
        kovusprite.setPosition(200, 200);//задаем начальные координаты появления спрайта

    //------------------------------------------------------! KOVU!

        float CurrentFrame = 0;
        Clock clock;

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart();                                      //перезагружает время
            time = time / 800;                                    //скорость игры

            sf::Event event;
            while (window.pollEvent(event))
                if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();


            //! Key processing()
            Key_processing(simbasprite, kovusprite, time, CurrentFrame);

            //-------------------------------------------------------------------------------

            window.clear();

            //! Draw map 2!

            Draw_map2(s_map, window, simbasprite, kovusprite);
        }
 
}

//...........THIRD LEVEL............//

void run_3(RenderWindow& window)
{
    Image map_image;      map_image.loadFromFile("Images/map.png");

    Texture map;          map.loadFromImage(map_image);

    Sprite s_map;         s_map.setTexture(map);

    //----------------------------------------------------! MAP!

    Image simbaimg;       simbaimg.loadFromFile("Images/simba.png");

    Texture simbatexture; simbatexture.loadFromImage(simbaimg);//передаем в файл объект Image

    Sprite simbasprite;   simbasprite.setTexture(simbatexture);//передаём в него объект Texture
    simbasprite.setTextureRect(IntRect(0, 180, 38, 38));//получили прямоугольник
    simbasprite.setPosition(250, 250);//задаем начальные координаты появления спрайта

//----------------------------------------------------! SIMBA!

    Image kovuimg;        kovuimg.loadFromFile("Images/kovu.png");

    Texture kovutexture;  kovutexture.loadFromImage(kovuimg);

    Sprite kovusprite;    kovusprite.setTexture(kovutexture);
    kovusprite.setTextureRect(IntRect(0, 0, 38, 38));// получили нужный нам
                                                     // прямоугольник с котом
    kovusprite.setPosition(200, 200);//задаем начальные координаты появления спрайта
    float CurrentFrame = 0;
    Clock clock;

//------------------------------------------------------! KOVU!



    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart();                                      //перезагружает время
        time = time / 800;                                    //скорость игры

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();


        //! Key processing()
        Key_processing(simbasprite, kovusprite, time, CurrentFrame);

        //-------------------------------------------------------------------------------

        window.clear();

        //! Draw map 3!

        Draw_map3(s_map, window, simbasprite, kovusprite);
    }

}

  //..................................................//
 //......................ABOUT.......................//
//..................................................//


void run_about(RenderWindow& window)
{
    Image     back;            back.loadFromFile("Images/info/back.jpg");

    Texture   backtexture;     backtexture.loadFromImage(back);

    Sprite    backsprite;      backsprite.setTexture(backtexture);
    backsprite.setPosition(0, 0);
    //------------------------------------------------------background
    Image     text;            text.loadFromFile("Images/info/Text.jpg");

    Texture   texttexture;     texttexture.loadFromImage(text);

    Sprite    textsprite;      textsprite.setTexture(texttexture);
    textsprite.setPosition(50, 50);
    //-------------------------------------------------------text

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        window.clear();
        window.draw(backsprite);
        window.draw(textsprite);
        window.display();

    }
}


  //..................................................//
 //.......................МЕНЮ.......................//
//..................................................//


void menu(RenderWindow& window)
{
    Image     menubackground;     menubackground.loadFromFile("Images/menu.jpg");

    Texture   menutexture;        menutexture.loadFromImage(menubackground);

    Sprite    menusprite;         menusprite.setTexture(menutexture);
    menusprite.setPosition(0, 0);
    //-------------------------------------------------background made

    Image     level1;             level1.loadFromFile("Images/level1.png");

    Texture   level1texture;      level1texture.loadFromImage(level1);

    Sprite    level1sprite;       level1sprite.setTexture(level1texture);
    level1sprite.setPosition(325, 375);

    //------------------------------------------------first level made

    Image     level2;             level2.loadFromFile("Images/level2.png");

    Texture   level2texture;      level2texture.loadFromImage(level2);

    Sprite    level2sprite;       level2sprite.setTexture(level2texture);
    level2sprite.setPosition(625, 375);

    //------------------------------------------------second level made

    Image     level3;             level3.loadFromFile("Images/level3.png");

    Texture   level3texture;      level3texture.loadFromImage(level3);

    Sprite    level3sprite;       level3sprite.setTexture(level3texture);
    level3sprite.setPosition(325, 520);

    //------------------------------------------------third level made

    Image     exitgame;           exitgame.loadFromFile("Images/exit.png");

    Texture   exitgametexture;    exitgametexture.loadFromImage(exitgame);

    Sprite    exitgamesprite;     exitgamesprite.setTexture(exitgametexture);
    exitgamesprite.setPosition(625, 520);

    //-------------------------------------------------exit made

    Image     info;           info.loadFromFile("Images/info/about.png");

    Texture   infotexture;    infotexture.loadFromImage(info);

    Sprite    infosprite;     infosprite.setTexture(infotexture);
    infosprite.setPosition(1100, 10);


    //-------------------------------------------------about made

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        int menuNum = 0;

        //--------------------------------------------making color when aiming

        if (IntRect(325, 375, 235, 129).contains(Mouse::getPosition(window))) { level1sprite.setColor(Color::Green); menuNum = FIRST_LEVEL; }
        if (IntRect(625, 375, 231, 127).contains(Mouse::getPosition(window))) { level2sprite.setColor(Color::Green); menuNum = SECOND_LEVEL; }
        if (IntRect(325, 520, 231, 126).contains(Mouse::getPosition(window))) { level3sprite.setColor(Color::Green); menuNum = THIRD_LEVEL; }
        if (IntRect(1100, 10, 90, 76).contains(Mouse::getPosition(window))) { infosprite.setColor(Color::Blue); menuNum = INFO; }
        if (IntRect(625, 520, 231, 126).contains(Mouse::getPosition(window))) { exitgamesprite.setColor(Color::Red); menuNum = EXIT; }

        //-------------------------------------------clearing color when out
        if (!IntRect(325, 375, 235, 129).contains(Mouse::getPosition(window))) { level1sprite.setColor(Color::White); }
        if (!IntRect(625, 375, 231, 127).contains(Mouse::getPosition(window))) { level2sprite.setColor(Color::White); }
        if (!IntRect(325, 520, 231, 126).contains(Mouse::getPosition(window))) { level3sprite.setColor(Color::White); }
        if (!IntRect(1100, 10, 90, 76).contains(Mouse::getPosition(window))) { infosprite.setColor(Color::White); }
        if (!IntRect(625, 520, 231, 126).contains(Mouse::getPosition(window))) { exitgamesprite.setColor(Color::White); }


        if (Mouse::isButtonPressed(Mouse::Left))
        {
            switch (menuNum)
            {
            case FIRST_LEVEL: { RenderWindow new_window(sf::VideoMode(1200, 675), "The Lion King Maze. Level 1");
                window.close();
                run_1(new_window);
                break;                                                                           }

            case SECOND_LEVEL: { RenderWindow new_window(sf::VideoMode(1200, 675), "The Lion King Maze. Level 2");
                window.close();
                run_2(new_window);
                break;                                                                           }

            case THIRD_LEVEL: { RenderWindow new_window(sf::VideoMode(1200, 675), "The Lion King Maze. Level 3");
                window.close();
                run_3(new_window);
                break;                                                                           }

            case INFO: { RenderWindow new_window(sf::VideoMode(1600, 900), "The Lion King Maze Info");
                window.close();
                run_about(new_window);
                break;                                                                           }

            case EXIT:          window.close();
                break;
            }

            if (menuNum >= FIRST_LEVEL && menuNum <= INFO)
            {
                RenderWindow after_window(sf::VideoMode(1200, 675), "The Lion King Maze");
                menu(after_window);
            }
        }

        window.clear();
        window.draw(menusprite);
        window.draw(level1sprite);
        window.draw(level2sprite);
        window.draw(level3sprite);
        window.draw(exitgamesprite);
        window.draw(infosprite);
        window.display();
    }
}


int main()
{

    RenderWindow window(VideoMode(1200, 675), "The Lion King Maze");
    menu(window);

    return 0;
}