#include <SFML/Graphics.hpp>
#include "levels.h"
using namespace sf;
const int FIRST_LEVEL = 1;
const int SECOND_LEVEL = 2;
const int THIRD_LEVEL = 3;
const int INFO = 4;
const int EXIT = 5;


void control(Sprite& simbasprite, Sprite& kovusprite, float time, float& CurrentFrame)
{

    //-------------------------------------------------------------! MOVING SIMBA!


    if ((Keyboard::isKeyPressed(Keyboard::Right)))
    {
        CurrentFrame += 0.005f * time;

        if (CurrentFrame > 7)
            CurrentFrame -= 7;
        simbasprite.setTextureRect(IntRect(51 * int(CurrentFrame), 244, 51, 51));

        simbasprite.move(0.1f * time, 0);
    }

    if ((Keyboard::isKeyPressed(Keyboard::Left)))
    {
        CurrentFrame += 0.005f * time;
        if (CurrentFrame > 7)
            CurrentFrame -= 7;

        simbasprite.setTextureRect(IntRect(51 * int(CurrentFrame + 1), 244, -51, 51));
        simbasprite.move(-0.1f * time, 0);

    }

    if ((Keyboard::isKeyPressed(Keyboard::Up)))
    {
        CurrentFrame += 0.1f * time;
        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        simbasprite.setTextureRect(IntRect(43 * int(CurrentFrame), 323, 43, 43));
        simbasprite.move(0, -0.1f * time);
    }

    if ((Keyboard::isKeyPressed(Keyboard::Down)))
    {
        CurrentFrame += 0.1f * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        simbasprite.setTextureRect(IntRect(43 * int(CurrentFrame), 323, 43, 43));
        simbasprite.move(0, 0.1f * time);
    }

    //----------------------------------------------------------------------


    //-------------------------------------------------------------! MOVING KOVU!


    if ((Keyboard::isKeyPressed(Keyboard::D)))
    {
        CurrentFrame += 0.005f * time;

        if (CurrentFrame > 6)
            CurrentFrame -= 6;

        kovusprite.setTextureRect(IntRect(67 * int(CurrentFrame), 50, 67, 50));
        kovusprite.move(0.1f * time, 0);

    }

    if ((Keyboard::isKeyPressed(Keyboard::A)))
    {
        CurrentFrame += 0.005f * time;

        if (CurrentFrame > 6)
            CurrentFrame -= 6;

        kovusprite.setTextureRect(IntRect(66 * int(CurrentFrame + 1), 50, -65, 50));
        kovusprite.move(-0.1f * time, 0);
    }

    if ((Keyboard::isKeyPressed(Keyboard::W)))
    {

        CurrentFrame += 0.1f * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        kovusprite.setTextureRect(IntRect(43 * int(CurrentFrame), 100, 43, 43));
        kovusprite.move(0, -0.1f * time);
    }

    if ((Keyboard::isKeyPressed(Keyboard::S)))
    {
        CurrentFrame += 0.1f * time;

        if (CurrentFrame > 2)
            CurrentFrame -= 2;

        kovusprite.setTextureRect(IntRect(43 * int(CurrentFrame), 100, 43, 43));
        kovusprite.move(0, 0.1f * time);
    }
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


void draw_map(Sprite& s_map, RenderWindow& window, Sprite& simbasprite, Sprite& kovusprite, Sprite& pumbasprite, Sprite& timonsprite, Sprite&zazusprite, sf::String TileMap[])
{
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (TileMap[i][j] == ' ')
                s_map.setTextureRect(IntRect(143, 15, 33, 34));

            if (TileMap[i][j] == 'l')
                s_map.setTextureRect(IntRect(0, 15, 33, 34));

            if (TileMap[i][j] == 'd')
                s_map.setTextureRect(IntRect(108, 15, 33, 34));

            if (TileMap[i][j] == 'h')
                s_map.setTextureRect(IntRect(74, 15, 33, 34));

            if (TileMap[i][j] == 'e')
                s_map.setTextureRect(IntRect(174, 15, 34, 34));

            if (TileMap[i][j] == 'a')
                s_map.setTextureRect(IntRect(242, 15, 34, 34));

            if (TileMap[i][j] == 'b')
                s_map.setTextureRect(IntRect(208, 15, 33, 34));


            s_map.setPosition((float)j * 32, (float)i * 32);
            window.draw(s_map);
        }

    window.draw(simbasprite);
    window.draw(kovusprite);
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
    pumbasprite.setTextureRect(IntRect(0, 500, 42, 58));
    pumbasprite.setPosition(170, 170);

    //---------------------------------------------------! PUMBA!

    Image map_image;      map_image.loadFromFile("Images/map.png");

    Texture map;          map.loadFromImage(map_image);

    Sprite s_map;         s_map.setTexture(map);

    //----------------------------------------------------! MAP!

    Image simbaimg;       simbaimg.loadFromFile("Images/simba.png");

    Texture simbatexture; simbatexture.loadFromImage(simbaimg);

    Sprite simbasprite;   simbasprite.setTexture(simbatexture);
    simbasprite.setTextureRect(IntRect(0, 25, 44, 51));
    simbasprite.setPosition(250, 250);

    //----------------------------------------------------! SIMBA!

    Image kovuimg;        kovuimg.loadFromFile("Images/kovu.png");

    Texture kovutexture;  kovutexture.loadFromImage(kovuimg);

    Sprite kovusprite;    kovusprite.setTexture(kovutexture);
    kovusprite.setTextureRect(IntRect(0, 200, 43, 53));
    kovusprite.setPosition(200, 200);

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
        control(simbasprite, kovusprite, time, CurrentFrame);

        //! Non-control
        non_control(pumbasprite, timonsprite, zazusprite, time, CurrentFrame, moveTimer);

        //-------------------------------------------------------------------------------

        window.clear();

        //! Draw map 1!

        draw_map(s_map, window, simbasprite, kovusprite, pumbasprite, timonsprite, zazusprite, TileMap1);
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

    Image simbaimg;       simbaimg.loadFromFile("Images/simba.png");

    Texture simbatexture; simbatexture.loadFromImage(simbaimg);

    Sprite simbasprite;   simbasprite.setTexture(simbatexture);
    simbasprite.setTextureRect(IntRect(0, 180, 38, 38));
    simbasprite.setPosition(250, 250);

    //----------------------------------------------------! SIMBA!

    Image kovuimg;        kovuimg.loadFromFile("Images/kovu.png");

    Texture kovutexture;  kovutexture.loadFromImage(kovuimg);

    Sprite kovusprite;    kovusprite.setTexture(kovutexture);
    kovusprite.setTextureRect(IntRect(0, 0, 38, 38));
    kovusprite.setPosition(200, 200);

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
        control(simbasprite, kovusprite, time, CurrentFrame);

        //-------------------------------------------------------------------------------

        window.clear();

        //! Draw map 2!

        draw_map(s_map, window, simbasprite, kovusprite, pumbasprite, timonsprite, zazusprite, TileMap2);
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

    Image   simbaimg;     simbaimg.loadFromFile("Images/simba.png");

    Texture simbatexture; simbatexture.loadFromImage(simbaimg);

    Sprite  simbasprite;  simbasprite.setTexture(simbatexture);
    simbasprite.setTextureRect(IntRect(0, 180, 38, 38));
    simbasprite.setPosition(250, 250);

    //----------------------------------------------------! SIMBA!

    Image   kovuimg;      kovuimg.loadFromFile("Images/kovu.png");

    Texture kovutexture;  kovutexture.loadFromImage(kovuimg);

    Sprite  kovusprite;   kovusprite.setTexture(kovutexture);
    kovusprite.setTextureRect(IntRect(0, 0, 38, 38));
    kovusprite.setPosition(200, 200);

    float CurrentFrame = 0;
    Clock clock;

    //------------------------------------------------------! KOVU!

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
        control(simbasprite, kovusprite, time, CurrentFrame);

        //-------------------------------------------------------------------------------

        window.clear();

        //! Draw map 3!

        draw_map(s_map, window, simbasprite, kovusprite, pumbasprite, timonsprite, zazusprite, TileMap3);
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