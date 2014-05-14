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
#include "tokenscanner.h"

using namespace std;

int main() {
    setConsoleSize(750, 450);
    setConsoleFont("Courier New-16");
    setConsoleEcho(true);

    // test for scanner class
    string words="<html><b><i>CS106 rules!</i></b></html>";
    TokenScanner scanner(words);
    scanner.ignoreWhitespace();
    while(scanner.hasMoreTokens()){
        string token = scanner.nextToken();
        cout << token << endl;

    }




    // TODO: Finish the program!


    cout << "Exiting." << endl;
    return 0;
}
