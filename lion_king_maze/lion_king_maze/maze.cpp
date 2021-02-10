#include <iostream>
#include <cstdlib>

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

void run_1(RenderWindow& window);
void run_2(RenderWindow& window);
void run_3(RenderWindow& window);
void run_about(RenderWindow& window);

struct Hero
{
    float a, b;
    float x, y;
    float w, h;
    float dx = 0,
        dy = 0,
        speed = 0;

    int direction = 0;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;

    Hero(String F, float X, float Y, float A, float B, float W, float H)
    {
        File = F;
        image.loadFromFile("Images/" + File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X; y = Y;
        a = A; b = B;
        w = W; h = H;
        sprite.setTextureRect(IntRect(a, b, w, h));
    }

    bool update(float time, String TileMap[], int* PATHS)
    {
        switch (direction)
        {
        case DOWN: dx = 0;
            dy = speed;
            break;

        case UP:   dx = 0;
            dy = -speed;
            break;

        case RIGHT:dx = speed;
            dy = 0;
            break;

        case LEFT: dx = -speed;
            dy = 0;
            break;
        }

        x += dx * time;
        y += dy * time;

        speed = 0;
        sprite.setPosition(x, y);
        return interactionWithMap(TileMap, PATHS, time);
    }

    bool interactionWithMap(String TileMap[], int* PATHS, float time)
    {
        for (int i = y / 34; i < (y + h) / 34; ++i)
            for (int j = x / 32; j < (x + w) / 32; ++j)

                switch (TileMap[i][j])
                {
                case 'e':     TileMap[i][j] = 'p';
                    *PATHS -= 1;
                    break;

                case 'a':     TileMap[i][j] = 'w';
                    *PATHS -= 1;
                    break;

                case 'y':     if (*PATHS <= 0)
                {
                    TileMap[i][j] = ' ';
                    return true;
                }
                        break;

                case 'x':     x -= dx * time;
                    y -= dy * time;
                    sprite.setPosition(x, y);
                    break;
                }
        return false;
    }
};

struct NPC
{
    float a, b;
    float x, y;
    float w, h;
    float dx = 0,
        dy = 0,
        speed = 0;

    int direction = 0;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;

    NPC(String F, float X, float Y, float A, float B, float W, float H)
    {
        File = F;
        image.loadFromFile("Images/" + File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X; y = Y;
        a = A; b = B;
        w = W; h = H;
        sprite.setTextureRect(IntRect(a, b, w, h));
    }

    bool update(float time, String TileMap[], int* PATHS)
    {
        switch (direction)
        {
        case DOWN: dx = 0;
            dy = speed;
            break;

        case UP:   dx = 0;
            dy = -speed;
            break;

        case RIGHT:dx = speed;
            dy = 0;
            break;

        case LEFT: dx = -speed;
            dy = 0;
            break;
        }

        x += dx * time;
        y += dy * time;

        speed = 0;
        sprite.setPosition(x, y);
        return interactionWithMap(TileMap, PATHS, time);
    }

    bool interactionWithMap(String TileMap[], int* PATHS, float time)
    {
        for (int i = y / 34; i < (y + h) / 34; ++i)
            for (int j = x / 32; j < (x + w) / 32; ++j)
                switch (TileMap[i][j])
                {
                case 'p':
                    TileMap[i][j] = 'e';
                    *PATHS += 1;
                    break;

                case 'w':
                    TileMap[i][j] = 'a';
                    *PATHS += 1;
                    break;

                case 'y':
                case 'x':
                    x -= dx * time;
                    y -= dy * time;
                    sprite.setPosition(x, y);
                    break;

                default:
                    break;
                }
        return false;
    }
};

//-------------------------------------------------------------! MOVING SIMBA!
bool control_simba(Hero& simba, float time, float& CurrentFrame, String TileMap[], int* PATHS)
{
    simba.speed = 0.2;
    CurrentFrame += 0.005f * time;

    if ((Keyboard::isKeyPressed(Keyboard::Right)))
    {
        simba.direction = RIGHT;
        CurrentFrame = CurrentFrame > 7 ? 0 : CurrentFrame;
        simba.sprite.setTextureRect(IntRect(51 * int(CurrentFrame), 244, 51, 51));
    }
    else if ((Keyboard::isKeyPressed(Keyboard::Left)))
    {
        simba.direction = LEFT;
        CurrentFrame = CurrentFrame > 7 ? 0 : CurrentFrame;
        simba.sprite.setTextureRect(IntRect(51 * int(CurrentFrame + 1), 244, -51, 51));
    }
    else if ((Keyboard::isKeyPressed(Keyboard::Up)))
    {
        simba.direction = UP;
        CurrentFrame = CurrentFrame > 2 ? 0 : CurrentFrame;
        simba.sprite.setTextureRect(IntRect(43 * int(CurrentFrame), 323, 43, 43));
    }
    else if ((Keyboard::isKeyPressed(Keyboard::Down)))
    {
        simba.direction = DOWN;
        CurrentFrame = CurrentFrame > 2 ? 0 : CurrentFrame;
        simba.sprite.setTextureRect(IntRect(43 * int(CurrentFrame), 323, 43, 43));
    }
    else
        simba.speed = 0;

    return simba.update(time, TileMap, PATHS);
}

//-------------------------------------------------------------! MOVING KOVU!

bool control_kovu(Hero& kovu, float time, float& CurrentFrame, String TileMap[], int* PATHS)
{
    kovu.speed = 0.2;
    CurrentFrame += 0.005f * time;

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        kovu.direction = RIGHT;
        CurrentFrame = CurrentFrame > 6 ? 0 : CurrentFrame;
        kovu.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 50, 67, 50));
    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {
        kovu.direction = LEFT;
        CurrentFrame = CurrentFrame > 6 ? 0 : CurrentFrame;
        kovu.sprite.setTextureRect(IntRect(66 * int(CurrentFrame + 1), 50, -65, 50));
    }
    else if (Keyboard::isKeyPressed(Keyboard::W))
    {
        kovu.direction = UP;
        CurrentFrame = CurrentFrame > 2 ? 0 : CurrentFrame;
        kovu.sprite.setTextureRect(IntRect(43 * int(CurrentFrame), 100, 43, 43));
    }
    else if (Keyboard::isKeyPressed(Keyboard::S))
    {
        kovu.direction = DOWN;
        CurrentFrame = CurrentFrame > 2 ? 0 : CurrentFrame;
        kovu.sprite.setTextureRect(IntRect(43 * int(CurrentFrame), 100, 43, 43));
    }
    else
        kovu.speed = 0;

    return (kovu.update(time, TileMap, PATHS));
}

bool control_pumba(NPC& npc, float time, float& CurrentFrame, int dir, String TileMap[], int* PATHS)
{
    npc.direction = dir;
    npc.speed = 0.06;
    CurrentFrame += 0.1f * time;

    CurrentFrame = CurrentFrame > 5 ? 0 : CurrentFrame;

    switch (dir)
    {
    case UP:
    case RIGHT: npc.sprite.setTextureRect(IntRect(38 * int(CurrentFrame) + 6, 150, 40, 40));
        break;

    case DOWN:
    case LEFT: npc.sprite.setTextureRect(IntRect(38 * int(CurrentFrame + 1) + 6, 150, -40, 40));
        break;
    }

    return (npc.update(time, TileMap, PATHS));
}

bool control_timon(NPC& npc, float time, float& CurrentFrame, int dir, String TileMap[], int* PATHS)
{
    npc.direction = dir;
    npc.speed = 0.15;
    CurrentFrame += 0.1f * time;

    CurrentFrame = CurrentFrame > 9 ? 0 : CurrentFrame;

    switch (dir)
    {
    case UP:
    case RIGHT: npc.sprite.setTextureRect(IntRect(37 * int(CurrentFrame) + 360, 600, 37, 51));
        break;
    case DOWN:
    case LEFT:  npc.sprite.setTextureRect(IntRect(37 * int(CurrentFrame + 1) + 360, 600, -37, 51));
        break;
    default:    break;
    }

    return (npc.update(time, TileMap, PATHS));
}


//.................DRAWING MAP......................//
void draw_map(Sprite& s_map, RenderWindow& window, Hero& simba, Hero& kovu, Sprite& pumbasprite,
    Sprite& timonsprite, String TileMap[])
{
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            switch (TileMap[i][j])
            {
            case ' ':s_map.setTextureRect(IntRect(143, 35, 33, 34)); break;
            case 'l':s_map.setTextureRect(IntRect(0, 35, 33, 34)); break;
            case 'p':s_map.setTextureRect(IntRect(243, 3, 33, 34)); break;
            case 'w':s_map.setTextureRect(IntRect(210, 3, 33, 34)); break;
            case 'd':s_map.setTextureRect(IntRect(108, 35, 33, 34)); break;
            case 'e':s_map.setTextureRect(IntRect(174, 35, 33, 34)); break;
            case 'a':s_map.setTextureRect(IntRect(242, 35, 33, 34)); break;
            case 'h':
            case 'y':s_map.setTextureRect(IntRect(74, 35, 33, 34)); break;
            case 'b':
            case 'x':s_map.setTextureRect(IntRect(208, 35, 33, 34)); break;
            }
            s_map.setPosition((float)j * 32, (float)i * 32);
            window.draw(s_map);
        }

    window.draw(simba.sprite);
    window.draw(kovu.sprite);
    window.draw(pumbasprite);
    window.draw(timonsprite);
    window.display();
}


//...........FIRST LEVEL................//

void run_1(RenderWindow& window)
{
    Image map_image;      map_image.loadFromFile("Images/map.png");
    Texture map;          map.loadFromImage(map_image);
    Sprite s_map;         s_map.setTexture(map);

    Hero simba("simba.png", 710, 360, 0, 25, 44, 51);
    Hero kovu("kovu.png", 430, 360, 0, 200, 43, 53);

    NPC pumba("pumba.png", 500, 250, 0, 500, 42, 58);
    NPC timon("timon.png", 500, 360, 0, 500, 4, 66);

    float CurrentFrame = 0;
    Clock clock;

    int counter = 0;
    int dir_pumba = DOWN;
    int dir_timon = UP;
    while (window.isOpen())
    {
        ++counter;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();

        if (control_simba(simba, time, CurrentFrame, TileMap1, &PATHS_1) ||
            control_kovu(kovu, time, CurrentFrame, TileMap1, &PATHS_1))
        {
            RenderWindow new_window(VideoMode(1200, 675), "The Lion King Maze. Level 2");
            window.close();
            run_2(new_window);
            return;
        }

        if (counter % 700 == 0)
        {
            dir_pumba = std::rand() % 4 + 6;
            dir_timon = std::rand() % 4 + 6;
        }
        control_pumba(pumba, time, CurrentFrame, dir_pumba, TileMap1, &PATHS_1);
        control_timon(timon, time, CurrentFrame, dir_timon, TileMap1, &PATHS_1);

        //-------------------------------------------------------------------------------
        window.clear();
        draw_map(s_map, window, simba, kovu, pumba.sprite, timon.sprite, TileMap1);
    }
}


//...............SECOND LEVEL................//
void run_2(RenderWindow& window)
{
    Image map_image;      map_image.loadFromFile("Images/map.png");
    Texture map;          map.loadFromImage(map_image);
    Sprite s_map;         s_map.setTexture(map);

    Hero simba("simba.png", 400, 150, 0, 25, 44, 51);
    Hero kovu("kovu.png", 550, 150, 0, 200, 43, 53);

    NPC pumba("pumba.png", 500, 250, 0, 500, 42, 58);
    NPC timon("timon.png", 500, 360, 0, 500, 4, 66);

    float CurrentFrame = 0;
    Clock clock;

    int counter = 0;
    int dir_pumba = LEFT;
    int dir_timon = RIGHT;

    while (window.isOpen())
    {
        ++counter;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();

        if (control_simba(simba, time, CurrentFrame, TileMap2, &PATHS_2) ||
            control_kovu(kovu, time, CurrentFrame, TileMap2, &PATHS_2))
        {
            RenderWindow new_window(VideoMode(1200, 675), "The Lion King Maze. Level 3");
            window.close();
            run_3(new_window);
        }

        if (counter % 1000 == 0)
        {
            dir_pumba = std::rand() % 4 + 6;
            dir_timon = std::rand() % 4 + 6;
        }
        control_pumba(pumba, time, CurrentFrame, dir_pumba, TileMap2, &PATHS_2);
        control_timon(timon, time, CurrentFrame, dir_timon, TileMap2, &PATHS_2);

        window.clear();
        draw_map(s_map, window, simba, kovu, pumba.sprite, timon.sprite, TileMap2);
    }
}

//...........THIRD LEVEL............//
void run_3(RenderWindow& window)
{
    Image map_image;      map_image.loadFromFile("Images/map.png");
    Texture map;          map.loadFromImage(map_image);
    Sprite s_map;         s_map.setTexture(map);

    Hero simba("simba.png", 1000, 125, 0, 25, 44, 51);
    Hero kovu("kovu.png", 100, 570, 0, 200, 43, 53);

    NPC pumba("pumba.png", 500, 250, 0, 500, 42, 58);
    NPC timon("timon.png", 500, 360, 0, 500, 4, 66);

    float CurrentFrame = 0;
    Clock clock;

    int counter = 0;
    int dir_pumba = LEFT;
    int dir_timon = RIGHT;

    while (window.isOpen())
    {
        ++counter;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 600;

        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();

        if (control_simba(simba, time, CurrentFrame, TileMap3, &PATHS_3) ||
            control_kovu(kovu, time, CurrentFrame, TileMap3, &PATHS_3))
        {
            RenderWindow new_window(VideoMode(1600, 900), "The Lion King Maze Info");
            window.close();
            run_about(new_window);
        }

        if (counter % 1500 == 0)
        {
            dir_pumba = std::rand() % 4 + 6;
            dir_timon = std::rand() % 4 + 6;
        }
        control_pumba(pumba, time, CurrentFrame, dir_pumba, TileMap3, &PATHS_3);
        control_timon(timon, time, CurrentFrame, dir_timon, TileMap3, &PATHS_3);

        window.clear();
        draw_map(s_map, window, simba, kovu, pumba.sprite, timon.sprite, TileMap3);
    }
}

//......................ABOUT.......................//
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
    textsprite.setPosition(70, 50);

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

//.......................MENU.......................//
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
            case FIRST_LEVEL: { RenderWindow new_window(VideoMode(1200, 675), "The Lion King Maze. Level 1");
                window.close();
                run_1(new_window);
                break;                                                                           }

            case SECOND_LEVEL: { RenderWindow new_window(VideoMode(1200, 675), "The Lion King Maze. Level 2");
                window.close();
                run_2(new_window);
                break;                                                                           }

            case THIRD_LEVEL: { RenderWindow new_window(VideoMode(1200, 675), "The Lion King Maze. Level 3");
                window.close();
                run_3(new_window);
                break;                                                                           }

            case INFO: { RenderWindow new_window(VideoMode(1600, 900), "The Lion King Maze Info");
                window.close();
                run_about(new_window);
                break;                                                                           }

            case EXIT:          window.close();
                break;

            default:            break;
            }

            if (menuNum >= FIRST_LEVEL && menuNum <= INFO)
            {
                RenderWindow after_window(VideoMode(1200, 675), "The Lion King Maze");
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