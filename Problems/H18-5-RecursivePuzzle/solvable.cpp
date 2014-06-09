/*
 *  solvable.cpp
 *  H18-5-RecursivePuzzle
 *
 *  Created by LIU BRYAN on 6/9/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "solvable.h"
#include <iostream>
#include "Vector.h"
#include "set.h"

using namespace std;

int GoNext(int sum,Vector<int> nums);
bool Solvable(int start, Vector<int> & squares);

int curnum=0;
Set<int> path;
int answer; // must declare here !!
//bool switchon=true;

int main(void){
	int ini;
	Vector<int> squares;
	squares.add(3);
	squares.add(1);
	squares.add(2);
	squares.add(3);
	squares.add(0);
	//squares.add(4);
	//squares.add(2);
	//squares.add(5);
	//squares.add(3);
	//squares.add(0);
	
	for (int i=0; i<squares.size(); i++) {
		cout << squares.getAt(i)<< " ";
	}
	
	cout << endl;
	cout << "Please give me an initial index: "	;
	cin >> ini;
	
	if (Solvable(ini,squares)) {
		cout << "yes, it is solvable"<<endl;
	}else{
		cout << "no, can not make it"<<endl;
	}
	
	return 0;
}

bool Solvable(int start, Vector<int> & squares){
	
	
	GoNext(start, squares);
	//cout << "answer :" << answer << endl;
	
	if (answer==1) {
		return true;
	}else{
		return false;
	}
}

int GoNext(int start,Vector<int> squares){ // it is better not to return value for this kind of function
	int value;
	//cout << "start : " << start << endl;
	path.add(start);
	if (squares.getAt(start)==0) {
		answer=1;
		return 1;
	}else if (curnum > 1000) {
		answer=2;
		return 2;
	}else {
		curnum++;
		value=squares.getAt(start);
		//cout << "value: " << value << endl;
		if ((start+value) >= squares.size()) {
			//cout << "1" << endl;
			GoNext((start-value),squares);
		}else if ((start-value) < 0) {
			//cout << "2" << endl;
			GoNext((start+value),squares);
		}else {
			/*cout << "3" << endl;
			 // This would go into infinite loop
			if (switchon) {
				GoNext((start+value),squares);
				GoNext((start-value),squares);
				switchon=false;
			}else {
				GoNext((start-value),squares);
				GoNext((start+value),squares);
				switchon=true;
			}*/
			if (!path.contains(start+value)) {
				GoNext((start+value),squares);
			}else if (!path.contains(start-value)) {
				GoNext((start-value),squares);
			}else {
				GoNext((start-value),squares);
				GoNext((start+value),squares);
			}

			
			
		}

	}
    
}
