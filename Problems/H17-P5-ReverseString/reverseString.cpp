/*
 *  reverseString.cpp
 *  H17-P5-ReverseString
 *
 *  Created by LIU BRYAN on 5/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "reverseString.h"
#include <iostream>
#include <string>

using namespace std;

string ReverseString(string origin){
	if (origin.size()==0) {
		return "";
	}else {
		return ReverseString(origin.erase(0,1))+origin[0];
	}

	
}

int main(void){
	string origin,reverse;
	
	origin = "you got mail!";
	
	reverse = ReverseString(origin);
	
	cout << "origin string: " << origin <<endl;
	cout << "after reverse: " << reverse <<endl;
	
	
}

