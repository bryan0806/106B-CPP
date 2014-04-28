#include <iostream>
#include <string>
#include "vector.h"



using namespace std;

void CountLetters(string filename);
int main()
{
    string filename;
    cout << "Please enter the file name:" << endl;
    cin >> filename;
    CountLetters(filename);


    return 0;
}

void CountLetters(string filename)
{
    ifstream in;
    in.open(filename.c_str());

    if(in.fail()) Error("Couldn't read '" + filename + "'");



}

