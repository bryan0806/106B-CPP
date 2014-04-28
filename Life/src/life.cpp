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

int main(void) {
    string filename;
    cout << "enter name:";
    cin >> filename;

    Grid<char> mgrid(2,2);
    ReadFile(filename, mgrid);



    return 0;
}

//<<<<<<< HEAD
void ReadFile(string fn,Grid<char> & gridc){

    int rows,columns;
/*=======
void ReadFile(string fn){
    int rows;
    int columns;
//<<<<<<< HEAD
    Grid<char> mgrid () ;*/
/*=======

>>>>>>> FETCH_HEAD
>>>>>>> bdc8bac3f00ff63ee46ebe3f8a83ea3effafc656*/
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
//<<<<<<< HEAD
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
    /*int i,j;
=======
<<<<<<< HEAD
    //mgrid.resize(rows,columns);
    mgrid.resize(rows,columns);
    //while(true){
      //  cout << line<<endl;
   // }
=======
    //mgrid.resize(rows,columns); //will fail , so change another way to construct
    Grid<char> mgrid(rows,columns);
    //while(true){
       // cout << line<<endl;
    //}
    int i,j;
>>>>>>> bdc8bac3f00ff63ee46ebe3f8a83ea3effafc656
    if(i=0,i<rows,i++){
        if(j=0,j<columns,j++){
            mgrid[i][j]=inf.get();
        }
<<<<<<< HEAD
    }
=======
    }
>>>>>>> FETCH_HEAD
>>>>>>> bdc8bac3f00ff63ee46ebe3f8a83ea3effafc656*/

    cout << gridc.toString();

}
