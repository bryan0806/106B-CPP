/*
 *  oldMeasuring.cpp
 *  H17-P7-Old-Fashion-Measuring
 *
 *  Created by LIU BRYAN on 5/25/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */


#include <iostream>
#include "vector.h"

using namespace std;

bool IsMeasurable(int target, Vector<int> & weights){
	int sum,first;
	sum=0;
	for (int i=0; i<weights.size(); i++) {
		sum += weights[i];
	}
	
	
	if (sum == target) {
		return true;
	}else if (sum == 0) {
		return false;
	}else {
		first = weights[0];
		weights.removeAt(0);
		return (IsMeasurable((target+first),weights));
	}
	
	
}

int main(void){
	Vector<int> sampleWeights;
	
	sampleWeights.add(1); 
	sampleWeights.add(3);
	
	if(IsMeasurable(5,sampleWeights)){
		cout << "yes, it is measurable"<<endl;
	}else {
		cout << "no, not measurable"<<endl;
	}
	
	
}
