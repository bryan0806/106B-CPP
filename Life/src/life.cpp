// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
using namespace std;

void ReadFile(string,Grid<char> &);
Grid<char> NextGen(Grid<char>);
int getNeighbor(int, int,Grid<char> &);
void PrintGrid(Grid<char>);

int main(void) {
    string filename;
    char select;
    cout << "enter name:";
    cin >> filename;

    Grid<char> mgrid(2,2); // a random number new Grid class object
    ReadFile(filename, mgrid);//read file into grid

    PrintGrid(mgrid); // print out the contect of grid


    //start stage 4 to calculate next generation
    cout << "a)nimate, t)ick, q)uit?" << endl;
    cin.get(select);

    while(select != 'q'){
    if(select == 't'){
        mgrid=NextGen(mgrid);
        cout<<"Afer next"<<endl;

        PrintGrid(mgrid);
    }else if(select =='a'){
        cout << "this is a"<<endl;
    }

    cout<<"a)nimate, t)ick, q)uit?";
    cin.get(select);
    }

    return 0;
}



void ReadFile(string fn,Grid<char> & gridc){

    int rows,columns;

    ifstream inf;
    openFile(inf,fn);
    string line;

    getline(inf,line);
    cout << line << endl;
    rows = stringToInteger(line);

    //cout << rows;
    getline(inf,line);
    cout << line << endl;
    columns = stringToInteger(line);


    //cout << columns;
    gridc.resize(rows,columns); //will fail , so change another way to construct

    //cout<<"mgrid's col is" << mgrid.nCols;
    int i=0,j=0;

    while(gridc.inBounds(i,j)){

        while(j<columns){
            gridc[i][j]=inf.get();
            j++;
    }
        j=0;
        i++;
        inf.get();
}



    //cout << gridc.toString()<<endl;

}

Grid<char> NextGen(Grid<char> gridc){
    int i,j,neinum;
    Grid<char> pgrid(gridc.nRows,gridc.nCols);
    //cout<<gridc.nCols;
    for(i=0;i<gridc.nRows;i++){
       for(j=0;j<gridc.nCols;j++){
            pgrid[i][j]=gridc[i][j];
            neinum = getNeighbor(i,j,gridc);
            //cout<<"i="<<i<<" and j="<<j<<" ,has neighbor "<<neinum<<endl;
            if(neinum<=1){
                pgrid[i][j]='-';
            }else if(neinum==3){
                pgrid[i][j]='X';
            }else if(neinum>=4){
                pgrid[i][j]='-';
            }


       }
    }

    return pgrid;

}

int getNeighbor(int row, int col, Grid<char> &gridc){
    int i,j,neinum = 0;
    for(i=row-1;i<=row+1;i++){
        for(j=col-1;j<=col+1;j++){
            if(i==row && j==col){

            }else if(!gridc.inBounds(i,j)){

            }else if(gridc[i][j]=='X'){
                neinum++;
            }

        }

    }

    return neinum;
}

void PrintGrid(Grid<char> pgrid){
    int k,l;
    for(k=0;k<pgrid.nRows;k++){
        for(l=0;l<pgrid.nCols;l++){
            cout<<pgrid[k][l];
        }
        cout<<endl;
    }

}



