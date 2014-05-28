/*
 *  mnemonics.cpp
 *  H17-P8-ListMnemonics
 *
 *  Created by LIU BRYAN on 5/28/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "mnemonics.h"
#include <iostream>
#include <string>

using namespace std;


void ListMnemonics(string number);
void recursiveMnemonics(string pre,string rest);
string findOptions(char num);

int main(void){
	
	string number;
	
	cout << "enter your number:" << endl;
	cin >> number;
	
	ListMnemonics(number);
	
	
	return 0;
}

void ListMnemonics(string number){
	
	recursiveMnemonics("",number); //自行加上一個空白字串當起頭
	
}

void recursiveMnemonics(string pre,string rest){ // 利用遞迴來列舉 參考解答的方式
	
	if (rest.size()==0) {
		cout << pre << endl;
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
		case '7': return "PRS";
		case '8': return "TUV";
		case '9': return "WXY";
		default: cout << "Illegal digit";
			break;
	}
	
	
}

