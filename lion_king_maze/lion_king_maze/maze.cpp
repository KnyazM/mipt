#include <SFML/Graphics.hpp>
#include "levels.h"
using namespace sf;

const int FIRST_LEVEL = 1;
const int SECOND_LEVEL = 2;
const int THIRD_LEVEL = 3;
const int INFO = 4;
const int EXIT = 5;

const int RIGHT = 6;
const int LEFT = 7;
const int UP = 8;
const int DOWN = 9;


struct Hero { // класс Игрока
    float a, b, x, y, w, h, dx = 0, dy = 0, speed = 0, moveTimer; //координаты игрока х и у, ширина, высота, скорость, a, b - нач коорд спрайта
    int direction = 0; //направление (direction) движения игрока
    String File; //файл с расширением
    Image image;//сфмл изображение
    Texture texture;//сфмл текстура
    Sprite sprite;//сфмл спрайт

    Hero(String F, float X, float Y, float A, float B, float W, float H) {  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
        File = F;//имя файла+расширение
        image.loadFromFile("Images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная 	image.loadFromFile("images/hero/png");
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        sprite.setTexture(texture);//заливаем спрайт текстурой
        x = X; y = Y;//координата появления спрайта
        a = A; b = B;
        w = W; h = H;//высота и ширина
        sprite.setTextureRect(IntRect(a, b, w, h));  //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
    }

    void update(float time)
    {
        switch (direction)
        {
        case DOWN: dx = 0; dy = speed; break;
        case UP:   dx = 0; dy = -speed; break;
        case RIGHT:dx = speed; dy = 0; break;
        case LEFT: dx = -speed; dy = 0; break;
        }

        x += dx * time;
        y += dy * time;

        speed = 0;
        sprite.setPosition(x, y);
        interactionWithMap(TileMap1);
    }

    void interactionWithMap(sf::String TileMap[])//ф-ция взаимодействия с картой
    {
        //    for (int i = 0; i < HEIGHT_MAP; i++)
        //        for (int j = 0; j < WIDTH_MAP; j++)
        //        {
        //            if (TileMap[i][j] == 'e')
        //                    TileMap[i][j] = 'p'; //ИСПРАВЛЯЕМ НА ЛАПКИ
        //            if (TileMap[i][j] == 'a')
        //                    TileMap[i][j] = 'w';
        //        }
        //}
    //            if (TileMap[i][j] == 'b')
    //            {
        for (int i = y / 34; i < (y + h) / 34; i++)//проходимся по тайликам, контактирующим с игроком,, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
            for (int j = x / 32; j < (x + w) / 32; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
            {
                //if (TileMap[i][j] == 'b')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
                //{
                //    if (dy > 0)//если мы шли вниз,
                //    {
                //        y = i * 34 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
                //    }
                //    if (dy < 0)
                //    {
                //        y = i * 34 + 34;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
                //    }
                //    if (dx > 0)
                //    {
                //        x = j * 32 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
                //    }
                //    if (dx < 0)
                //    {
                //        x = j * 32 + 32;//аналогично идем влево
                //    }
                //}
                //{
                if (TileMap[i][j] == 'e')
                    TileMap[i][j] = 'p'; //ИСПРАВЛЯЕМ НА ЛАПКИ
                if (TileMap[i][j] == 'a')
                    TileMap[i][j] = 'w';
            }

    }

};

//class NPC {
//public:
//    float a, b, x, y, w, h, dx = 0, dy = 0, speed = 0, moveTimer;
//    String File; //файл с расширением
//    Image image;//сфмл изображение
//    Texture texture;
//    Sprite sprite;
//    NPC(Image& image, float X, float Y, int W, int H, String Name) {
//        x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
//        speed = 0; health = 100; dx = 0; dy = 0;
//        life = true; onGround = false; isMove = false;
//        texture.loadFromImage(image);
//        sprite.setTexture(texture);
//        sprite.setOrigin(w / 2, h / 2);
//    }
//};


    //-------------------------------------------------------------! MOVING SIMBA!
void control_simba(Hero& simba, float time, float& CurrentFrame)
{   
    if ((Keyboard::isKeyPressed(Keyboard::Right)))
    {
        simba.direction = RIGHT;
        simba.speed = 0.1;
        CurrentFrame += 0.005f * time;

        if (CurrentFrame > 7)
            CurrentFrame -= 7;
        simba.sprite.setTextureRect(IntRect(51 * int(CurrentFrame), 244, 51, 51));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Left)))
    {
        simba.direction = LEFT;
        simba.speed = 0.1;
        CurrentFrame += 0.005f * time;
        if (CurrentFrame > 7)
            CurrentFrame -= 7;

        simba.sprite.setTextureRect(IntRect(51 * int(CurrentFrame + 1), 244, -51, 51));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Up)))
    {
        simba.direction = UP;
        simba.speed = 0.1;
        CurrentFrame += 0.1f * time;
        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        simba.sprite.setTextureRect(IntRect(43 * int(CurrentFrame), 323, 43, 43));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Down)))
    {
        simba.direction = DOWN;
        simba.speed = 0.1;
        CurrentFrame += 0.1f * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        simba.sprite.setTextureRect(IntRect(43 * int(CurrentFrame), 323, 43, 43));
    }
    simba.update(time);

//    for (int i = 0; i < HEIGHT_MAP; i++)
//        for (int j = 0; j < WIDTH_MAP; j++)
//        {
//            if (TileMap[i][j] == 'b')
//            {
//                int direction = direct_simba();
//
//                if (direction == DOWN)//если мы шли вниз,
//                    simbasprite.move(0, 0);//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
//                if (direction == UP)
//                    simbasprite.move(0, 0);//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
//                if (direction == RIGHT)
//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
//                if (direction == LEFT)
//                    simbasprite.move(0, 0);//аналогично идем влево
//            }

    //        //if (TileMap[i][j] == 'e')
    //        //    TileMap[i][j] = 's'; //ИСПРАВИТЬ ТУТ НА ВЕРТ ЛАПЫ
    //        //if (TileMap[i][j] == 'a')
    //        //    TileMap[i][j] = 's'; //ИСПРАВИТЬ ТУТ НА ГОРИЗОНТ ЛАПЫ
    //    }

}

    //-------------------------------------------------------------! MOVING KOVU!

void control_kovu(Hero& kovu, float time, float& CurrentFrame){



    if ((Keyboard::isKeyPressed(Keyboard::D)))
    {
        kovu.direction = 6;
        kovu.speed = 0.1;
        CurrentFrame += 0.005f * time;

        if (CurrentFrame > 6)
            CurrentFrame -= 6;

        kovu.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 50, 67, 50));

    }

    if ((Keyboard::isKeyPressed(Keyboard::A)))
    {
        kovu.direction = 7;
        kovu.speed = 0.1;
        CurrentFrame += 0.005f * time;

        if (CurrentFrame > 6)
            CurrentFrame -= 6;

        kovu.sprite.setTextureRect(IntRect(66 * int(CurrentFrame + 1), 50, -65, 50));
    }

    if ((Keyboard::isKeyPressed(Keyboard::W)))
    {
        kovu.direction = 8;
        kovu.speed = 0.1;
        CurrentFrame += 0.1f * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        kovu.sprite.setTextureRect(IntRect(43 * int(CurrentFrame), 100, 43, 43));
    }

    if ((Keyboard::isKeyPressed(Keyboard::S)))
    {
        kovu.direction = 9;
        kovu.speed = 0.1;
        CurrentFrame += 0.1f * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        kovu.sprite.setTextureRect(IntRect(43 * int(CurrentFrame), 100, 43, 43));
    }
    kovu.update(time);
}



void non_control(Sprite& pumbasprite, Sprite& timonsprite, Sprite& zazusprite, float time, float& CurrentFrame, float& moveTimer) {

    //MOVING PUMBA
    
    moveTimer += time;
    CurrentFrame += 0.005f * time;
    

    if (moveTimer > 1000000)
    {
        if (CurrentFrame > 5)
            CurrentFrame -= 5;
        pumbasprite.setTextureRect(IntRect(38 * int(CurrentFrame + 1) + 6, 150, -40, 40));
        pumbasprite.move(-0.1f * time, 0);
        moveTimer = 0;
        
    }


    if (moveTimer <= 1000000)
    {
        if (CurrentFrame > 5)
            CurrentFrame -= 5;
        pumbasprite.setTextureRect(IntRect(38 * int(CurrentFrame) + 6, 150, 40, 40));
        pumbasprite.move(0.1f * time, 0);
    }
    
    //MOVING TIMON

    if (moveTimer > 1000000)
    {
        CurrentFrame += 0.005f * time;
        if (CurrentFrame > 9)
            CurrentFrame -= 9;
        timonsprite.setTextureRect(IntRect(45 * int(CurrentFrame + 1) + 350, 610, -45, 47));
        timonsprite.move(-0.1f * time, 0);
        moveTimer = 0;

    }


    if (moveTimer < 1000000)
    {
        CurrentFrame += 0.005f * time;
        if (CurrentFrame > 9)
            CurrentFrame -= 9;
        timonsprite.setTextureRect(IntRect(45 * int(CurrentFrame) + 350, 610, 45, 47));
        timonsprite.move(0.1f * time, 0);
        moveTimer += time;
    }



    //MOVING ZAZU

    if (moveTimer > 1000000)
    {
        CurrentFrame += 0.005f * time;
        if (CurrentFrame > 10)
            CurrentFrame -= 10;
        zazusprite.setTextureRect(IntRect(48 * int(CurrentFrame + 1), 100, -48, 40));
        zazusprite.move(-0.1f * time, 0);
        moveTimer = 0;

    }


    if (moveTimer < 1000000)
    {
        CurrentFrame += 0.005f * time;
        if (CurrentFrame > 10)
            CurrentFrame -= 10;
        zazusprite.setTextureRect(IntRect(48 * int(CurrentFrame), 100, 48, 40));
        zazusprite.move(0.1f * time, 0);
        moveTimer += time;
    }

}


//..................................................//
//.................DRAWING MAP......................//
//..................................................//


void draw_map(Sprite& s_map, RenderWindow& window, Hero& simba, Hero& kovu, Sprite& pumbasprite, Sprite& timonsprite, Sprite&zazusprite, sf::String TileMap[])
{
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (TileMap[i][j] == ' ')
                s_map.setTextureRect(IntRect(143, 35, 33, 34));

            if (TileMap[i][j] == 'l')
                s_map.setTextureRect(IntRect(0, 35, 33, 34));

            if (TileMap[i][j] == 'p')
                s_map.setTextureRect(IntRect(243, 3, 33, 34));

            if (TileMap[i][j] == 'w')
                s_map.setTextureRect(IntRect(210, 3, 33, 34));

            if (TileMap[i][j] == 'd')
                s_map.setTextureRect(IntRect(108, 35, 33, 34));

            if (TileMap[i][j] == 'h')
                s_map.setTextureRect(IntRect(74, 35, 33, 34));

            if (TileMap[i][j] == 'e')
                s_map.setTextureRect(IntRect(174, 35, 33, 34));

            if (TileMap[i][j] == 'a')
                s_map.setTextureRect(IntRect(242, 35, 33, 34));

            if (TileMap[i][j] == 'b')
                s_map.setTextureRect(IntRect(208, 35, 33, 34));


            s_map.setPosition((float)j * 32, (float)i * 32);
            window.draw(s_map);
        }

    window.draw(simba.sprite);
    window.draw(kovu.sprite);
    window.draw(pumbasprite);
    window.draw(timonsprite);
    window.draw(zazusprite);
    window.display();
}


//...........FIRST LEVEL................//

void run_1(RenderWindow& window)
{
    Image zazuimg;       zazuimg.loadFromFile("Images/zazu.png");

    Texture zazutexture; zazutexture.loadFromImage(zazuimg);

    Sprite zazusprite;   zazusprite.setTexture(zazutexture);
    zazusprite.setTextureRect(IntRect(0, 100, 48, 40));
    zazusprite.setPosition(210, 210);

    //------------------------------------------------! ZAZU!
    Image timonimg;       timonimg.loadFromFile("Images/timon.png");

    Texture timontexture; timontexture.loadFromImage(timonimg);

    Sprite timonsprite;   timonsprite.setTexture(timontexture);
    timonsprite.setTextureRect(IntRect(0, 500, 4, 66));
    timonsprite.setPosition(220, 220);

    //--------------------------------------------------! TIMON!
    Image pumbaimg;       pumbaimg.loadFromFile("Images/pumba.png");

    Texture pumbatexture; pumbatexture.loadFromImage(pumbaimg);

    Sprite pumbasprite;   pumbasprite.setTexture(pumbatexture);
    pumbasprite.setTextureRect(IntRect(0, 500, 42, 58));
    pumbasprite.setPosition(170, 170);

    //---------------------------------------------------! PUMBA!

    Image map_image;      map_image.loadFromFile("Images/map.png");

    Texture map;          map.loadFromImage(map_image);

    Sprite s_map;         s_map.setTexture(map);

    //----------------------------------------------------! MAP!

    Hero simba("simba.png", 250, 250, 0, 25, 44, 51);

    //----------------------------------------------------! SIMBA!

    Hero kovu("kovu.png", 200, 200, 0, 200, 43, 53);


    //------------------------------------------------------! KOVU!

    float CurrentFrame = 0;
    float moveTimer = 0;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();


        //! Key processing()
        control_simba(simba, time, CurrentFrame);
        control_kovu(kovu, time, CurrentFrame);

        //! Non-control
        non_control(pumbasprite, timonsprite, zazusprite, time, CurrentFrame, moveTimer);

        //-------------------------------------------------------------------------------

        window.clear();

        //! Draw map 1!

        draw_map(s_map, window, simba, kovu, pumbasprite, timonsprite, zazusprite, TileMap1);
    }
}



//...............SECOND LEVEL................//

void run_2(RenderWindow& window)
{
    Image zazuimg;       zazuimg.loadFromFile("Images/zazu.png");

    Texture zazutexture; zazutexture.loadFromImage(zazuimg);

    Sprite zazusprite;   zazusprite.setTexture(zazutexture);
    zazusprite.setTextureRect(IntRect(0, 100, 48, 40));//gjghjfdbnm
    zazusprite.setPosition(210, 210);

    //------------------------------------------------! ZAZU!
    Image timonimg;       timonimg.loadFromFile("Images/timon.png");

    Texture timontexture; timontexture.loadFromImage(timonimg);

    Sprite timonsprite;   timonsprite.setTexture(timontexture);
    timonsprite.setTextureRect(IntRect(0, 500, 4, 66));
    timonsprite.setPosition(220, 220);

    //--------------------------------------------------! TIMON!
    Image pumbaimg;       pumbaimg.loadFromFile("Images/pumba.png");

    Texture pumbatexture; pumbatexture.loadFromImage(pumbaimg);

    Sprite pumbasprite;   pumbasprite.setTexture(pumbatexture);
    pumbasprite.setTextureRect(IntRect(0, 25, 44, 44));
    pumbasprite.setPosition(300, 300);


    Image map_image;      map_image.loadFromFile("Images/map.png");

    Texture map;          map.loadFromImage(map_image);

    Sprite s_map;         s_map.setTexture(map);

    //----------------------------------------------------! MAP!

    Hero simba("simba.png", 250, 250, 0, 25, 44, 51);

    //----------------------------------------------------! SIMBA!

    Hero kovu("kovu.png", 200, 200, 0, 200, 43, 53);


    //------------------------------------------------------! KOVU!

    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();


        //! Key processing()
        control_simba(simba, time, CurrentFrame);
        control_kovu(kovu, time, CurrentFrame);

        //-------------------------------------------------------------------------------

        window.clear();

        //! Draw map 2!

        draw_map(s_map, window, simba, kovu, pumbasprite, timonsprite, zazusprite, TileMap2);
    }

}

//...........THIRD LEVEL............//

void run_3(RenderWindow& window)
{
    Image zazuimg;       zazuimg.loadFromFile("Images/zazu.png");

    Texture zazutexture; zazutexture.loadFromImage(zazuimg);

    Sprite zazusprite;   zazusprite.setTexture(zazutexture);
    zazusprite.setTextureRect(IntRect(0, 100, 48, 40));//gjghjfdbnm
    zazusprite.setPosition(210, 210);

    //------------------------------------------------! ZAZU!
    Image timonimg;       timonimg.loadFromFile("Images/timon.png");

    Texture timontexture; timontexture.loadFromImage(timonimg);

    Sprite timonsprite;   timonsprite.setTexture(timontexture);
    timonsprite.setTextureRect(IntRect(0, 500, 4, 66));
    timonsprite.setPosition(220, 220);

    //--------------------------------------------------! TIMON!
    Image pumbaimg;       pumbaimg.loadFromFile("Images/pumba.png");

    Texture pumbatexture; pumbatexture.loadFromImage(pumbaimg);

    Sprite pumbasprite;   pumbasprite.setTexture(pumbatexture);
    pumbasprite.setTextureRect(IntRect(0, 25, 44, 44));
    pumbasprite.setPosition(300, 300);


    Image map_image;      map_image.loadFromFile("Images/map.png");

    Texture map;          map.loadFromImage(map_image);

    Sprite s_map;         s_map.setTexture(map);

    //----------------------------------------------------! MAP!

    Hero simba("simba.png", 250, 250, 0, 25, 44, 51);

    //----------------------------------------------------! SIMBA!

    Hero kovu("kovu.png", 200, 200, 0, 200, 43, 53);


    //------------------------------------------------------! KOVU!

    float CurrentFrame = 0;
    Clock clock;



    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 600;

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();


        //! Key processing()
        control_simba(simba, time, CurrentFrame);
        control_kovu(kovu, time, CurrentFrame);

        //-------------------------------------------------------------------------------

        window.clear();

        //! Draw map 3!

        draw_map(s_map, window, simba, kovu, pumbasprite, timonsprite, zazusprite, TileMap3);
    }

}

//..................................................//
//......................ABOUT.......................//
//..................................................//


void run_about(RenderWindow& window)
{
    Image     back;             back.loadFromFile("Images/info/back.jpg");

    Texture   backtexture;      backtexture.loadFromImage(back);

    Sprite    backsprite;       backsprite.setTexture(backtexture);
    backsprite.setPosition(0, 0);
    //------------------------------------------------------background
    Image     text;             text.loadFromFile("Images/info/Text.jpg");

    Texture   texttexture;      texttexture.loadFromImage(text);

    Sprite    textsprite;       textsprite.setTexture(texttexture);
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
//.......................MENU.......................//
//..................................................//


void menu(RenderWindow& window)
{
    Image     icon;               icon.loadFromFile("Images/icon.jpg");
    window.setIcon(100, 70, icon.getPixelsPtr());

    //-----------------------------------------------------icon made

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