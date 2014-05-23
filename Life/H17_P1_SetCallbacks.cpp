
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "hashmap.h"
#include "hashset.h"
#include "map.h"
#include "queue.h"
#include "random.h"
#include "set.h"
#include "simpio.h"
#include "vector.h"
#include "tokenscanner.h"

using namespace std;

struct entryT{
    string firstNAME;
    string lastName;
    string phoneNumber;
    };

bool operator<(const entryT &front,const entryT &back){
    if(front.lastName < back.lastName)
        return true;
    else if(front.lastName == back.lastName  ){
        if(front.firstNAME < back.firstNAME) return true;
        else if(front.firstNAME == back.firstNAME) return false;
        else return false;
        }else return false;
}

std::ostream& operator<<(std::ostream& os, const entryT& et){
    os << et.firstNAME << " " << et.lastName;

}

void PrintAll(entryT stud){
    cout << stud.firstNAME <<"  "<<stud.lastName << endl;
    }

int main(void){
    Set<entryT> students;

    entryT A = {"bryan","liu","0988333222"};
    entryT B = {"peggy","chang","0963333222"};
    entryT C = {"penny","chang","0910022222"};

    students.add(A);
    students.add(B);
    students.add(C);



    cout << students.toString();

    return 0;
    }
