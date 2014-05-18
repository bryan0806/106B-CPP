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
#include "stack.h"
#include "vector.h"

using namespace std;
void wordLadder(string w1, string w2);
string findNewWord(string oldword,Set<string> dic,Set<string> stack);

int main() {
    setConsoleSize(750, 450);
    setConsoleFont("Courier New-28");
    setConsoleEcho(true);

    cout << "Welcome to CS 106B Word Ladder." << endl;
    cout << "If you give me two English words, I will transform the" << endl;
    cout << "first into the second by changing one letter at a time." << endl;
    cout << endl;

    cout << "Please type two words: ";
    string word1;
    string word2;
    cin >> word1 >> word2;

    // TODO: Finish the program!

    //cout << "word1 is "<<word1<<endl;
    //cout << "word2 is " <<word2<<endl;

    wordLadder(word1,word2);


    cout << "Have a nice day." << endl;
    return 0;
}


void wordLadder(string w1, string w2){
    Queue<Stack<string> > ladder;
    Stack<string> wstack;
    string topWord,dicword,newWord;
    wstack.push(w1);
    ladder.enqueue(wstack);
    //char buffer[10];
    Set<string> usedword;
    usedword.add(w1);
    // put dictionary into set
    ifstream ifs;
    openFile(ifs,"dictionary.txt");
    Set<string> dictionary;
    while(getline(ifs,dicword)){ // 注意!! 檔案小時要用這樣ifs.getline(buffer,sizeof(buffer))才是對的方法
        dictionary.add(dicword); // 大字典檔案需用getline(ifs,string)  小檔案要用上面方法
    }


    while(!ladder.isEmpty()){

        //put stack into set

        wstack=ladder.dequeue();
        cout<<wstack.toString()<<endl;// for test
        topWord = wstack.peek();
        cout << "topWord="<<topWord<<endl;// for test


        if(topWord==w2){ break;}
        else if(topWord != ""){ // find next neighbor and push into stack
            newWord=topWord;
            while(newWord!=""){ // 這裡需要一個回圈 一次找齊topWord所有的neighbor
                newWord=findNewWord(topWord,dictionary,usedword);
                if(newWord!=""){ // 表示 找到了1.在字典內2. 還沒使用過的 字 且還沒找完所有的組合
                usedword.add(newWord);
                Stack<string> newStack = wstack; //每找到一個 新字就成立一個new stack 新字放最上面
                newStack.push(newWord);
                cout<<"newStack is " << newStack.toString()<<endl;
                ladder.enqueue(newStack);//每一個分支都是一個stack
                }
            }
        }





    }
    while(!wstack.isEmpty()){
        cout<<wstack.pop()<<"  ";
    }
}


// 小心這邊 我原本丟的第一參數是
string findNewWord(string oldword,Set<string> dic,Set<string> stack){
    int i;
    char j;
    string tempword;

    for(i=0;i<oldword.length();i++){
        tempword = oldword; // 一開始以為沒用 但這邊是關鍵！！
        for(j='a';j<='z';j++){

            //cout << "No, can use 'a'+int way" <<endl;
            //oldword[i]=j;
            tempword = tempword.replace(i,1,1,j);
            //cout << tempword << endl;
            if(dic.contains(tempword)){
                //cout<< tempword << endl;
                if(!(stack.contains(tempword))){

                    //cout << tempword << endl;
                    return tempword;
                }
            }
        }
    }
    return ""; //這邊要注意 沒有會有沒有錯誤訊息的錯誤
}

