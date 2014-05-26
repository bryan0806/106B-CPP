// This is the .h file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own, as well as on the members.
// TODO: remove this comment header

#ifndef _tilelist_h
#define _tilelist_h

#include <iostream>
#include <string>
#include "gobjects.h"
#include "gwindow.h"
#include "strlib.h"
#include "Tile.h"
using namespace std;

class TileList {
public:
    TileList();
    ~TileList();
    void addTile(Tile tile);
    void drawAll(GWindow& window);
    int indexOfTopTile(int x, int y);
    void lower(int x, int y);
    void raise(int x, int y);
    void remove(int x, int y);
    void removeAll(int x, int y);

private:
    int ini_size;
    int array_num;
    Tile *tilelists;
    void checkArray();

};

#endif
