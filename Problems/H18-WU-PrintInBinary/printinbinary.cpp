/*
 *  printinbinary.cpp
 *  H18-WU-PrintInBinary
 *
 *  Created by LIU BRYAN on 5/29/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "printinbinary.h"
#include <iostream>

using namespace std;

void PrintInBinary(int dec){
	if (dec < 2) {
		cout << dec;
	}else{
		
		PrintInBinary(dec/2);
		cout << dec%2;     // be careful !! this line must put behind the recursive fuction
	}
	
}

int main(void){
	int dec;
	
	cout << "please enter a decimal number" << endl;
	cin >> dec;
	
	cout << "the binary counter part is ";
	PrintInBinary(dec);
	

	return 0;
}

