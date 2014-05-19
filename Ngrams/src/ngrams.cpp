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
typedef Vector<string> keyvector;
typedef Map<keyvector,keyvector> NGRAM;

NGRAM readFile(string fn,int n);

bool operator<( const Vector<string>& lhs, const Vector<string>& rhs )
{
    int pos = 0;
    while( true ) {
        if( pos == lhs.size() && pos == rhs.size() ) return false;
        if( pos == lhs.size() ) return true;
        if( pos == rhs.size() ) return false;
        if( lhs[ pos ] < rhs[ pos ] ) return true;
        if( rhs[ pos ] < lhs[ pos ] ) return false;
        ++pos;
    }
}

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

