#ifndef __MAP_H__
#define __MAP_H__


#include <SFML/Graphics.hpp>

const int HEIGHT_MAP1 = 21;
const int WIDTH_MAP1 = 37;
sf::String TileMap1[HEIGHT_MAP1] = {
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "b                                   b",
  "bl     bbbbbbbbbbbbbbbbbbbbbbb     lb",
  "bd     b  aaaaaaaaaaaaaaaaa  b     db",
  "bd     b ebbbbbbbbbbbbbbbbbe b     db",
  "bd     b ebldldldldldldldlbe b     db",
  "bd     b eb  bbbbbbbbbbb  be b     db",
  "bd     b ebbbb  l   l  bbbbe b     db",
  "bd     b  aaaaaaaaaaaaaaaaa  b     db",
  "bl     bb   bbl       lbb   bb     lb",
  "blll    b   bbbbb   bbbbb   b    lllb",
  "blll    b   h   h e h   h   b    lllb",
  "blll    b   h   h e h   h   b    lllb",
  "blll    b   bbbbb e bbbbb   b    lllb",
  "bd      b         e  d      b      db",
  "b       b  l      e         b    d  b",
  "b     l b     d   e    l    b       b",
  "b       b         e         b       b",
  "b       bbbbbbbbb e bbbbbbbbb   l   b",
  "b  d            b e b               b",
  "bbbbbbbbbbbbbbbbbbhhbbbbbbbbbbbbbbbbb",
};


const int HEIGHT_MAP2 = 21;
const int WIDTH_MAP2 = 37;
sf::String TileMap2[HEIGHT_MAP2] = {
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "b   ll                        dd    b",
  "b      aaaaaaaaaaaaaaaaaaaaaaaa     b",
  "b    ee  bbbbbbbbbbbbbbbbb   ee     b",
  "b    ee  b               b   ee     b",
  "b    ee  b  ld      aa   b   ee     b",
  "b    ee  b        e      b   ee     b",
  "bbbbbee  bbbbbbbbbbhhbbbbb       be b",
  "b ebbee         e b  aaa     l   be b",
  "b ebbee         e bee            be b",
  "b ebbee         e bee    bbbbbb  be b",
  "b  aaaaaaaaaaaaa  bee    b aa    be b",
  "b  bbbbbbbbbbbb   hee    b    aaaa  b",
  "b  b  d           h  aaa  b ebb  bb b",
  "b  b       bbbbbbbbbbb  ee   h    b b",
  "b  b    d         h     ee   h    b b",
  "b  b       l      h   ee bbbbb  bbb b",
  "b  bbbbbbbbbbbbbbbb ee  b       b   b",
  "b           l       ebbbb     bbb   b",
  "b      l            e         h     b",
  "bbbbbbbbbbbbbbbbbbbbhhbbbbbbbbbbbbbbb",
};


const int HEIGHT_MAP3 = 21;
const int WIDTH_MAP3 = 37;
sf::String TileMap3[HEIGHT_MAP3] = {
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "b l  aaaaaaaaaaaab aaaaaaaaaaaaab   b",
  "b e  bbbbbbbbbbbeb bbbbbbbbbbbbbbbbbb",
  "b e  aaaaaabaaaa b           b      h",
  "b ee bbbbbbbbbbb bbbb    l   b      h",
  "b  aaaaaaaaaeee     b        h  d  bb",
  "bbbbbbbbbbbb  e   bbbbbb     h     bb",
  "b   aaaaaaa   e    d   b     bbbbbbbb",
  "b e   bbbbb   e        b            b",
  "b e   d   b   e    bb  b     bbbbbbbb",
  "b e       b     aaaaaaaaaaaaaaaaaa eb",
  "b e   bbbbbbbbbbbbbbbbbbb   e   b  eb",
  "b e  aaaaaaaab   aaaaaaaa   e   b  eb",
  "b e bbbbbbbbbbbbb    aaaaaa e   b  eb",
  "b e aaaaaaaaaaaab      bbbbbbbbbbb eb",
  "b e bbbbbbbbbbbbbbbb e b    d   aaa b",
  "b   aaaaaaaaaaaaaaaa e b       e   eb",
  "bbbbbbbb   e   bbbbbbbbbbbbbbb ebbbeb",
  "b l    h   e   b aaaaaaaaaaaaa   b eb",
  "b      h a  bbbbe     d         aaa b",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
};

#endif //__MAP_H__#pragma once
