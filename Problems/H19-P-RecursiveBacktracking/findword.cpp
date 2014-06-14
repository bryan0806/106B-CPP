/*
 *  findword.cpp
 *  H19-P-RecursiveBacktracking
 *
 *  Created by LIU BRYAN on 6/14/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "findword.h"
#include "lexicon.h"
#include <iostream>
#include <string>
#include "vector.h"

using namespace std;

Vector<string> get;

string FindWord(string soFar,string rest,Lexicon & lex);

int main(void){
	string randomword;
	cout << " enter random words: " <<endl;
	cin >> randomword;
	
	Lexicon lex("lexicon.dat");
	
	FindWord("",randomword,lex);


	cout << "the possible words are : "<<endl;
	for (int i=0; i<get.size(); i++) {
		cout << get[i] << endl;
	}
	

	
	
	return 0;
}

string FindWord(string soFar,string rest,Lexicon & lex){
		if (rest.empty()) {
			return (lex.containsWord(soFar)? soFar:"");
		}else {
			for (int i=0; i<rest.length(); i++) {
				string remain= rest.substr(0,i)+rest.substr(i+1);
				string found=FindWord(soFar+rest[i],remain,lex);
				if (!found.empty()) {
					get.add(found);
				}
			}
		}

		return "";
}
