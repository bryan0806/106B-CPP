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
#include "hashmap.h"
#include "hashset.h"
#include "map.h"
#include "queue.h"
#include "random.h"
#include "set.h"
#include "simpio.h"
#include "vector.h"

using namespace std;

typedef Map<Vector<string>, string> NGRAM;

NGRAM readFile(string fn,int n);

int main() {
    setConsoleSize(1500, 900);
    setConsoleFont("Courier New-28");
    setConsoleEcho(true);

    int n,gnum;
    cout << "Please enter N:";
    cin >> n;
    string filename;
    cout << "Input file?";
    cin >> filename;
    cout << "\n";
    cout <<"# of random words to generate (0 to quit)?";
    cin >> gnum;

    // TODO: Finish the program!
    NGRAM ngrammap;
    ngrammap = readFile(filename,n);



    cout << "Exiting." << endl;
    return 0;
}

NGRAM readFile(string fn, int n){
    NGRAM map;
    cout<<"ok";
    return map;
}

