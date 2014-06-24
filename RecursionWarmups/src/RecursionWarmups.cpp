// This is the .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "gwindow.h"
#include "simpio.h"
#include <math.h>
using namespace std;



int countPaths(int street, int avenue) {
    // TODO: write this function
    /* This is my first version: it can calculate the answer but too complicated
    static int count=0;
    cout << "street:" << street << " ave: " <<avenue << endl;
    cout << "count is " << count << endl;
    if(street==1 && avenue==1){
        count++;
    }else{
        if(street==1){
            cout << "street is 1"<<endl;
            return countPaths(street,avenue-1);
        }else if(avenue==1){
            cout << "avenue is 1"<<endl;
            return countPaths(street-1,avenue);
        }else{
            cout << "enter" << endl;
            for(int i=0;i<2;i++){
                if(i==0){
                    countPaths(street-1,avenue);
                }else{
                    countPaths(street,avenue-1);
                }
            }
        }
    }

    return count;*/

    if(street < 1 || avenue < 1) return 0;
    if(street==1 && avenue==1) return 1;
    return countPaths(street-1,avenue)+countPaths(street,avenue-1);

}

bool isBalanced(string exp) {
    // TODO: write this function
    if(exp=="") return true;
    if(exp.find('(')!=-1 && exp.find(')')!=-1){
        exp.erase(exp.find('('),1);
        exp.erase(exp.find(')'),1);
        return isBalanced(exp);
    }else if(exp.find('{')!=-1 && exp.find('}')!=-1){
        exp.erase(exp.find('{'),1);
        exp.erase(exp.find('}'),1);
        return isBalanced(exp);
    }else if(exp.find('[')!=-1 && exp.find(']')!=-1){
        exp.erase(exp.find('['),1);
        exp.erase(exp.find(']'),1);
        return isBalanced(exp);
    }else{
    return false;
    }
}

void drawSierpinskiTriangle(GWindow& gw, double x, double y, double size, int order) {
    // TODO: write this function
    if(order==0) return;
    else{
        cout << "x y size are " << x << " " << y << " " << size << endl;
        order--;
        long double height = sqrt(3.0/4.0*(size*size));
        gw.drawLine(x,y,x+size,y);
        gw.drawLine(x,y,x+(size/2.0),y+height);
        gw.drawLine(x+(size/2.0),y+height,x+size,y);
        drawSierpinskiTriangle(gw,x,y,size/2.0,order);
        drawSierpinskiTriangle(gw,x+(size/2.0),y,size/2.0,order);
        drawSierpinskiTriangle(gw,x+(size/4.0),y+(height/2.0),size/2.0,order);
    }

}
