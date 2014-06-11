/*
 *  cutstock.cpp
 *  H18-6-StockCutting
 *
 *  Created by LIU BRYAN on 6/10/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "cutstock.h"
#include "vector.h"
#include <iostream>

using namespace std;

int CutStock(Vector<int> & requests, int stockLength);
void recursiveCut(Vector<int> stocks,Vector<int> set,int stockLength,int stockneed);
Vector<int> stockpossible;
int countSum(Vector<int> & set);

int main(void){
	int stocklength,few;
	stocklength = 10;
	Vector<int> stocks;
	stocks.add(5);
	stocks.add(4);
	stocks.add(3);
	stocks.add(4);
	stocks.add(1);
	stocks.add(7);
	stocks.add(8);
	stocks.add(3);
	stocks.add(5);
	stocks.add(7);
	
	few=CutStock(stocks,stocklength);
	
	cout << "the fewest number needed : " << few << endl;
	
	return 0;
}

int CutStock(Vector<int> & requests, int stockLength){
	int stockneed=0;
	Vector<int> set;
	recursiveCut(requests,set,stockLength,stockneed);
	int smallest=10;
	
	for (int k=0; k<stockpossible.size(); k++) {
		if (stockpossible[k] < smallest) {
			smallest = stockpossible[k];
		}
	}
	return smallest;
}

void recursiveCut(Vector<int> stocks,Vector<int> set,int stockLength,int stockneed){
	int first;
 	if (stocks.size()==0) { // finished all elements
		stockpossible.add(stockneed);
		return;
	}
	
	if (set.size()==0) { // if there is no element in set , it means first time or empty
		first=stocks[0];
		stocks.removeAt(0);
		set.add(first);
	}else { // at least one element in set
		first = countSum(set);
	}

	int nextcount=0;
	
	
	for (int i=0; i<stocks.size(); i++) { // find next element can be added to set
		if((first + stocks[i])<=stockLength){ // can move on
			nextcount++;
			Vector<int> stocks2,set2;
			stocks2=stocks;
			set2=set;
			set2.add(stocks[i]);
			stocks2.removeAt(i);
			if (stocks2.size()==0) { // if after throwing recursive and the stocks2 has no element
				stockneed++;
			}
			recursiveCut(stocks2,set2,stockLength,stockneed);
		}
	}
	
	
	if (nextcount==0) {  // no other element can be added to set
		stockneed++;  // need a whole stock
		for (int j=(set.size()-1);j>=0 ; j--) {
			set.removeAt(j);
		}
		
		recursiveCut(stocks,set,stockLength,stockneed); // recalculate
	}
}

int countSum(Vector<int> & set){
	int sum=0;
	for (int i=0; i<set.size(); i++) {
		sum += set[i];
	}
	
	return sum;
}
