/*
 *  ListCompletions.cpp
 *  H18-4-CellPhoneMindReading
 *
 *  Created by LIU BRYAN on 6/5/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "ListCompletions.h"
#include "lexicon.h"
#include <iostream>
#include <string>
#include "Vector.h"


using namespace std;


void ListMnemonics(string number);
void recursiveMnemonics(string pre,string rest);
string findOptions(char num);
void ListCompletions(string digitSequence, Lexicon & lex);
Vector<string> allcandidates;
string findnextin(string pre, Lexicon & lex);
void recursiveFindComplete(string pre,Lexicon & lex);

int main(void){
	
	string number;
	
	cout << "enter your number:" << endl;
	cin >> number;
	
	ListMnemonics(number);
	
	Lexicon lex("lexicon.dat");
	for (int i=0; i<allcandidates.size(); i++) {
		string tryword;
		tryword=allcandidates[i];
		ListCompletions(tryword,lex);
	}
	
	
	return 0;
}

void ListCompletions(string digitSequence, Lexicon & lex){
	if (lex.containsPrefix(digitSequence)) {
		//cout << digitSequence << endl;
		recursiveFindComplete(digitSequence,lex);
		
	}
	
}

void recursiveFindComplete(string pre,Lexicon & lex){ 
	if (lex.containsWord(pre)) {
		cout << pre << " ";
	}
	
	string options;
	options = findnextin(pre,lex);
	
	if (options.length()>0) {
		for (int i=0; i<options.length(); i++) {
			recursiveFindComplete(pre+options[i],lex);	
		}
	}
	
}

string findnextin(string pre, Lexicon & lex){
	string next;
	next = "";
	for (char ch='a'; ch <= 'z' ; ch++) {
		string temp;
		temp = pre + ch;
		if (lex.containsPrefix(temp)) {
			next += ch;
		}
		
	}
	
	return next;
}


void ListMnemonics(string number){
	
	recursiveMnemonics("",number); //自行加上一個空白字串當起頭
	
}

void recursiveMnemonics(string pre,string rest){ // 利用遞迴來列舉 參考解答的方式
	
	if (rest.size()==0) {
		allcandidates.add(pre);
	}else {
		string options;
		options = findOptions(rest[0]);
		for (int i=0; i<options.length(); i++) {
			recursiveMnemonics(pre+options[i],rest.substr(1));	
		}
		
	}
	
}

string findOptions(char num){
	switch (num) {
		case '1': return "1";
		case '0': return "0";
		case '2': return "ABC";
		case '3': return "DEF";
		case '4': return "GHI";
		case '5': return "JKL";
		case '6': return "MNO";
		case '7': return "PQRS";
		case '8': return "TUV";
		case '9': return "WXYZ";
		default: cout << "Illegal digit";
			break;
	}
	return "";
}



