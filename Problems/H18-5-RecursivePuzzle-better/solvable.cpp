/*
 *  solvable.cpp
 *  H18-5-RecursivePuzzle-better
 *
 *  Created by LIU BRYAN on 6/10/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "solvable.h"
#include <iostream>
#include "Vector.h"
#include "set.h"

using namespace std;

void GoNext(int start,Vector<int> squares);
bool Solvable(int start, Vector<int> & squares);

Set<int> path;
int fresult=0;


int main(void){
	int ini;
	Vector<int> squares;
	squares.add(3);
	squares.add(6);
	squares.add(4);
	squares.add(3);
	squares.add(3);
	squares.add(4);
	squares.add(3);
	squares.add(5);
	squares.add(3);
	squares.add(3);
	squares.add(0);
	
	for (int i=0; i<squares.size(); i++) {
		cout << squares.getAt(i)<< " ";
	}
	
	cout << endl;
	cout << "Please give me an initial index: "	;
	cin >> ini;
	
	if (Solvable(ini,squares)!=0) {
		cout << "yes, it is solvable"<<endl;
	}else{
		cout << "no, can not make it"<<endl;
	}
	
	return 0;
}

bool Solvable(int start, Vector<int> & squares){

	
	GoNext(start, squares);
	
	if (fresult==1) {
		return true;
	}else {
		return false;
	}

}

void GoNext(int start,Vector<int> squares){ // it is better not to return value for this kind of function
	int value;
	cout << "start : " << start << endl;
	value=squares.getAt(start);
	
	if (path.contains(start)) {
		cout << "1" << endl;
		return ;
	}
	
	if (start==(squares.size()-1)) {
		cout << "2" << endl;
		fresult =1;
	}
	
	path.add(start);
	
	
	if ((start+value) < squares.size()) {
			GoNext((start+value),squares);
		}
	if ((start-value) >= 0) {
		GoNext((start-value),squares);
	}
		
	return;
    
}

