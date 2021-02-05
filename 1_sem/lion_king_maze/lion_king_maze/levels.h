#ifndef __MAP_H__
#define __MAP_H__

#include <SFML/Graphics.hpp>

const int HEIGHT_MAP = 21;
const int WIDTH_MAP = 38;

int PATHS_1 = 51;
int PATHS_2 = 106;
int PATHS_3 = 146;

sf::String TileMap1[HEIGHT_MAP] = {
  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
  "x                                   x",
  "xl     bbbbbbbbbbbbbbbbbbbbbbb     lx",
  "xd     b  aaaaaaaaaaaaaaaaa  b     dx",
  "xd     b ebbbbbbbbbbbbbbbbbe b     dx",
  "xd     b ebldldldldldldldlbe b     dx",
  "xd     b eb  bbbbbbbbbbb  be b     dx",
  "xd     b ebbbb  l   l  bbbbe b     dx",
  "xd     b  aaaaaaaaaaaaaaaaa  b     dx",
  "xl     bb   bbl       lbb   bb     lx",
  "xlll    b   bbbbb   bbbbb   b    lllx",
  "xlll    b   h   h e h   h   b    lllx",
  "xlll    b   h   h e h   h   b    lllx",
  "xlll    b   bbbbb e bbbbb   b    lllx",
  "xd      b         e  d      b      dx",
  "x       b  l      e         b    d  x",
  "x     l b     d   e    l    b       x",
  "x       b         e         b       x",
  "x       bbbbbbbbb e bbbbbbbbb   l   x",
  "x  d            b e b               x",
  "xxxxxxxxxxxxxxxxxyyyxxxxxxxxxxxxxxxxx",
};

sf::String TileMap2[HEIGHT_MAP] = {
  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
  "x   ll                        dd    x",
  "x      aaaaaaaaaaaaaaaaaaaaaaaa     x",
  "x    ee  bbbbbbbbbbbbbbbbb   ee     x",
  "x    ee  b               b   ee     x",
  "x    ee  b  ld      aa   b   ee     x",
  "x    ee  b        e      b   ee     x",
  "xbbbbee  bbbbbbbbbbhhbbbbb       be x",
  "x ebbee         e b  aaa     l   be x",
  "x ebbee         e bee            be x",
  "x ebbee         e bee    bbbbbb  be x",
  "x  aaaaaaaaaaaaa  bee    b aa    be x",
  "x  bbbbbbbbbbbb   hee    b    aaaa  x",
  "x  b  d           h  aaa  b ebb  bb x",
  "x  b       bbbbbbbbbbb  ee   h    b x",
  "x  b    d         h     ee   h    b x",
  "x  b       l      h   ee bbbbb  bbb x",
  "x  bbbbbbbbbbbbbbbb ee  b       b   x",
  "x           l       ebbbb     bbb   x",
  "x      l            e         h     x",
  "xxxxxxxxxxxxxxxxxxxyyyxxxxxxxxxxxxxxx",
};


sf::String TileMap3[HEIGHT_MAP] = {
  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
  "x l  aaaaaaaaaaaab aaaaaaaaaaaaab   x",
  "x e  bbbbbbbbbbbeb bbbbbbbbbbbbbbbbbx",
  "x e              b           b      y",
  "x ee bbbbbbbbbbb bbbb    l   b      y",
  "x  aaaaaaaaaeee     b        h  d   y",
  "xbbbbbbbbbbb  e   bbbbbb     h     bx",
  "x   aaaaaaa   e    d   b     bbbbbbbx",
  "x e   bbbbb   e        b            x",
  "x e   d   b   e    bb  b     bbbbbbbx",
  "x e       b              aaaaaaaaa ex",
  "x e   bbbbbbbbbbbbbbbbbbb   e   b  ex",
  "x e  aaaaaaaab   aaaaaaaa   e   b  ex",
  "x e bbbbbbbbbbbbb    aaaaaa e   b  ex",
  "x e             b      bbbbbbbbbbb ex",
  "x e bbbbbbbbbbbbbbbb e b    d   aaa x",
  "x   aaaaaaaaaaaaaaaa e b       e   ex",
  "xbbbbbbb   e   bbbbbbbbbbbbbbb ebbbex",
  "x l    h   e   b aaaaaaaaaaaaa   b ex",
  "x      h a  bbbbe     d         aaa x",
  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
};

#endif //__MAP_H__
