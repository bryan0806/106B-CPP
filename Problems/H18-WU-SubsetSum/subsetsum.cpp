/*
 *  subsetsum.cpp
 *  H18-WU-SubsetSum
 *
 *  Created by LIU BRYAN on 6/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "subsetsum.h"
#include <iostream>
#include "Vector.h"
#include "set.h"

using namespace std;

bool canMakeSum(Vector<int> & nums,int targetSum);
void ListSum(int sum,Vector<int> nums);

Set<int> sumlist;

int main(void){
	Vector<int> nums;
	nums.add(3);
	nums.add(7);
	nums.add(1);
	nums.add(8);
	nums.add(-3);
	
	//cout << nums[1]<<endl;

	
	if (canMakeSum(nums,15)) {
		cout << "yes, it can make sum"<<endl;
	}else{
		cout << "no, can not make sum"<<endl;
	}

	return 0;
}

bool canMakeSum(Vector<int> & nums,int targetSum){
	
	
	ListSum(0, nums);
	
	/*int size;
	size = sumlist.size();
	cout << "sumlist size is " << size;
	
	Set<int>::Iterator ite = sumlist.iterator();
	while (ite.hasNext()) {
		cout << ite.next() << endl;
	}*/
	 
	if (sumlist.contains(targetSum)) {
		return true;
	}else{
		return false;
	}
}

void ListSum(int sum,Vector<int> nums){ // it is better not to return value for this kind of function
	int first;
	
	if (nums.size()==0) {
		//cout << "sum is " << sum <<endl;
		
		sumlist.add(sum); // add all possible sum into set and check the set
	}else {
		first=nums.getAt(0);
		//cout << "first is "<<first<<endl;
		nums.removeAt(0);
		ListSum(sum+first,nums);
		ListSum(sum,nums);
	}
	
}
