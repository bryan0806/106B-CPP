/*
 *  cartesian.cpp
 *  H17-P2-Cartesian
 *
 *  Created by LIU BRYAN on 5/23/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "cartesian.h"
#include <iostream>
#include "Set.h"
#include <string>

struct pairT {
	string first,second;
};

int CompareP(pairT front,pairT back){
	if (front.first==back.first) {
		if (front.second > back.second) {
			return 1;
		}else if (front.second == back.second) {
			return 0;
		}else {
			return -1;
		}
	}else if (front.first > back.first) {
		return 1;
	}else{
		return -1;
}
	
}

Set<pairT> Cartesian(Set<string> one,Set<string> two){
	Set<pairT> result(CompareP);
	pairT pair;
	Set<string>::Iterator oneit = one.iterator();
	//Set<string>::Iterator twoit = two.iterator();// this is wrong !!
	
	while (oneit.hasNext()) {
		string first = oneit.next();
		Set<string>::Iterator twoit = two.iterator(); // 之前宣告在外面 只會while 一次就結束
		while (twoit.hasNext()) {
			string second = twoit.next();
			pair.first = first;
			pair.second = second;
			result.add(pair);
		}
	}
	return result;
}

void PrintElem(pairT onest){
	cout << onest.first << ", "<<onest.second << endl;
	
}

void PrintAll(Set<pairT> stu){
	stu.mapAll(PrintElem);
}


int main(void){
	Set<string> one ;
	Set<string> two ;
	
	one.add("A");
	one.add("B");
	one.add("C");
	two.add("X");
	two.add("Y");
	
	Set<pairT> result(CompareP);
	result = Cartesian(one,two);
	
	
	PrintAll(result);
	
	return 0;
}


