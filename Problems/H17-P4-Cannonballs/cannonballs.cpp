/*
 *  cannonballs.cpp
 *  H17-P4-Cannonballs
 *
 *  Created by LIU BRYAN on 5/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "cannonballs.h"
#include <iostream>

using namespace std;

int Cannonball(int height){
	if (height==1) {
		return 1;
	}else {
		return Cannonball(height-1)+height*height;
	}	
}

int main(void){
	
	int height = 3;
	int cannons;
	
	cannons = Cannonball(height);
	
	cout << "you have " << cannons << " cannons left";
	
	
}

