// This is the .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "TileList.h"
#include "strlib.h"



TileList::TileList() {
    // TODO: write this member
    ini_size = 10;
    tilelists = new Tile[ini_size]; // 初始化 10個tile空間
    array_num = 0;


}

TileList::~TileList() {
    // TODO: write this member

}

void TileList::addTile(Tile tile) {
    // TODO: write this member
    checkArray();
    tilelists[array_num++]=tile;
}

void TileList::drawAll(GWindow& window) {
    // TODO: write this member
    for(int i=0;i<array_num;i++){
        tilelists[i].draw(window);
    }
}

int TileList::indexOfTopTile(int x, int y) {
    // TODO: write this member
    int index=-1;
    for(int i=0;i<array_num;i++){
        if(tilelists[i].contains(x,y))
            index = i;
    }

    return index;
}

void TileList::raise(int x, int y) {
    // TODO: write this member
    int topm;
    topm = indexOfTopTile(x,y);

    //cout << topm << endl;

    if(topm != -1){
        Tile temp = tilelists[topm];
        for(int j=topm;j<array_num-1;j++){
            tilelists[j] = tilelists[j+1];
        }
        tilelists[array_num-1] = temp;
    }
}

void TileList::lower(int x, int y) {
    // TODO: write this member
    int topm;
    topm = indexOfTopTile(x,y);

    if(topm != -1){
        Tile temp = tilelists[topm];
        for(int j=topm;j>=1;j--){
            tilelists[j] = tilelists[j-1];
        }
        tilelists[0] = temp;
    }

}

void TileList::remove(int x, int y) {
    // TODO: write this member
    int topm;
    topm = indexOfTopTile(x,y);

    if(topm != -1){

        for(int j=topm;j<=array_num-1;j++){
            tilelists[j] = tilelists[j+1];
        }

        array_num --;
    }

}

void TileList::removeAll(int x, int y) {
    // TODO: write this member
    for(int k=array_num-1;k>=0;k--){
        if(tilelists[k].contains(x,y)){
            remove(x,y);
        }

    }


}

void TileList::checkArray(){
    if( array_num == ini_size){
        Tile *newList = new Tile[ini_size*2];
        for(int i=0;i<ini_size;i++)
            newList[i]=tilelists[i];
        delete[] tilelists;
        tilelists = newList;
        ini_size *= 2;

    }


}
