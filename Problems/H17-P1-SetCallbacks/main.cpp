/*
 *  main.cpp
 *  H17-P1-SetCallbacks
 *
 *  Created by LIU BRYAN on 5/21/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <string>
#include "Set.h"

struct entryT {
	string firstName;
	string lastName;
	string phoneNumber;
};

int CompareS(entryT front,entryT back){
		if (front.lastName < back.lastName) {
			return 1;
		}else if (front.lastName == back.lastName) {
			if(front.firstName<back.firstName){
				return 1;
			}else {
				return -1;
			}

		}else {
			return -1;
		}

}

using namespace std;

void PrintElem(entryT onest){
	cout << onest.firstName << " "<<onest.lastName << endl;
	
}

void PrintAll(Set<entryT> stu){
	stu.mapAll(PrintElem);
}

int main(void){
	
	Set<entryT> students(CompareS);
	
	entryT A={"bryan","liu","0988343333"};
	entryT B={"peggy","chang","0963333333"};
	entryT C={"penny","chang","0988343333"};
	
	students.add(A);
	students.add(B);
	students.add(C);
	
	PrintAll(students);	
	
	
}
