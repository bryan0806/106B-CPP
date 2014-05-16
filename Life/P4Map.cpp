
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

void MostFrequentCharacter(ifstream &ifn, int &numOccurrences);
void findmax(char key,int value);
char maxword;
static int maxvalue=0;

int main() {
    /*setConsoleSize(750, 450);
    setConsoleFont("Courier New-16");
    setConsoleEcho(true);*/

    /* Problem 3
    // test for scanner class
    string words="<html><b><i>CS106 rules!</i></b></html>";
    TokenScanner scanner(words);
    scanner.ignoreWhitespace();
    while(scanner.hasMoreTokens()){
        string token = scanner.nextToken();
        cout << token << endl;

    }*/

    /*Problem 4: Map Warm-up
     Write a function:
     char MostFrequentCharacter(ifstream &if, int &numOccurrences);
     that given an input file stream, returns the character that occurs
     the most frequently and stores the number of times it occurs in the
     reference parameter numOccurrences. To write this function, first start
     by scanning through the file stream, analyzing each character and storing
     an updated count in a map. Then, after you’ve built this table, iterate over
     it to find the character that occurred the most often.*/
    string filename;
    int numOccurrences=0;
    ifstream ifn;
    char result,word;
    filename = "simple.txt";
    cout << filename<<endl;
    //cin >> filename;
    //ifn.open(filename.c_str());
    //if (ifn.fail()) cout<<"Couldn't read '" << filename << "'";
    //if(openFile(ifn,filename)){
      //  cout << "open ok!"<<endl;
    //while(ifn.get(word)){
      //  cout << word;
    //}

    MostFrequentCharacter(ifn,numOccurrences);




    // TODO: Finish the program!


    cout << "Exiting." << endl;
    return 0;
}


void MostFrequentCharacter(ifstream &ifn, int &numOccurrences){
    Map<char,int> wordCount;
    char word,mostHappenWord;
    string allstring;
    int count;
    openFile(ifn,"bbb.txt");


    while(ifn.get(word)){
        if(wordCount.containsKey(word)){
            count = wordCount.get(word);
            wordCount.put(word,count+1);
        }else{
            count=1;
            wordCount.put(word,count);
        }
    }

    wordCount.mapAll(findmax);

    cout << "the most happen word is " << maxword << endl;
    cout << "it happened " << maxvalue << " times"<< endl;


}


void findmax(char key,int value){

    if(value>maxvalue){
        maxword=key;
        maxvalue=value;
    }



}
