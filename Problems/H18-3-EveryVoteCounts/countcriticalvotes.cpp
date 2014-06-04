/*
 *  countcriticalvotes.cpp
 *  H18-3-EveryVoteCounts
 *
 *  Created by LIU BRYAN on 6/4/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "countcriticalvotes.h"
#include <iostream>
#include "vector.h";

Vector<int> sumlist;

int CountCriticalVotes(Vector<int> & blocks, int blockIndex);
void ListSum(int sum,Vector<int> blocks);

int main(void){
	int blockIndex,criticalnum;
	
	Vector<int> votes;
	votes.add(9);
	votes.add(9);
	votes.add(7);
	votes.add(3);
	votes.add(1);
	votes.add(1);
	
	//cout << nums[1]<<endl;
	for (int i=0; i<votes.size(); i++) {
		cout << "index " << i << " got " << votes[i] << " votes "<< endl;
	}
	
	cout << "Please enter the index of block:"<<endl;
	cin >> blockIndex;
	
	criticalnum = CountCriticalVotes(votes,blockIndex);
	
	cout << "The critical votes for index " << blockIndex << " is " << criticalnum << " times. " << endl;
	
	return 0;
}


int CountCriticalVotes(Vector<int> & blocks, int blockIndex){ 
	int sum=0;
	int majority;
	int crinums=0;
	int blockIndexNum;
	int Alice,Bob;
	
	for (int i=0; i< blocks.size(); i++) {
		sum += blocks[i];
	}
	
	majority = sum/2 + 1;
	//cout << "majority is "<< majority<<endl; 
	
	blockIndexNum = blocks[blockIndex];
	blocks.removeAt(blockIndex);
	//cout << "blockIndexNum is " << blockIndexNum << endl;
	
	ListSum(0,blocks);
	
	
	for (int j=0; j<sumlist.size(); j++) {
		Alice = sumlist[j];
		Bob = sum-Alice-blockIndexNum;
		//cout << "Alice got " << Alice << endl;
		//cout << "Bob got " << Bob << endl;
		
		if ((Alice+blockIndexNum) >= majority && (Bob+blockIndexNum) >= majority ) {
			
			crinums++;
		}
	}
	
	return crinums;
	
}

void ListSum(int sum,Vector<int> blocks){
	
	int first;
	
	if (blocks.size()==0) {
		//cout << "sum is " << sum <<endl;
		
		sumlist.add(sum); // add all possible sum into set and check the set
	}else {
		first=blocks.getAt(0);
		//cout << "first is "<<first<<endl;
		blocks.removeAt(0);
		ListSum(sum+first,blocks);
		ListSum(sum,blocks);
	}	
	
	
}

