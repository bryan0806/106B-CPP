/*
 *  countways.cpp
 *  H18-1-CountWays
 *
 *  Created by LIU BRYAN on 6/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "countways.h"
#include <iostream>

using namespace std;

int CountWays(int numStairs);
void ListWays(int numStairs);
int sum=0;

int main(void){
	int numstairs,ways;
	cout << "enter the numbers of stairs";
	cin >> numstairs;
	
	ways = CountWays(numstairs);
	
	cout << "There are "<< ways << " ways to go such stairs"<<endl;
	
    return 0;
}

int CountWays(int numStairs){
	ListWays(numStairs);
	return sum;

}

void ListWays(int numStairs){
	if (numStairs==0) {
		
		sum++;
	}else {
		if (numStairs==1) {
			ListWays(numStairs-1);
		}else {
			ListWays(numStairs-1);
			ListWays(numStairs-2);
		}
		
	}

}