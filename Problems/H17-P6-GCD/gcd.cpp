/*
 *  gcd.cpp
 *  H17-P6-GCD
 *
 *  Created by LIU BRYAN on 5/25/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "gcd.h"
#include <iostream>

using namespace std;

int gcd(int x,int y){
	if ( x % y == 0) {
		return y;
	}else {
		gcd(y,x%y);
	}

	
}

int main(void){
	int x,y;
	x=15;
	y=10;
	
	int GCD;
	
	GCD = gcd(x,y);
	
	cout << "the GCD of " << x << " and " << y << " is " << GCD << endl;
	
}

