// This is the .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header
#include <iostream>
#include <istream>
#include "AssassinsList.h"
#include "strlib.h"
#include "Node.h"

AssassinsList::AssassinsList(istream& input) {
    // TODO: write this member
    string name;
    head = NULL;
    graveyard = NULL;

    while(getline(input,name)){
        //cout << name << endl;
        Node * FNode;                 // 一定要用dynamic memory allocation(new)
        FNode= new Node(name,head); // 這邊我原先用FNode(name,head); 想說可以用constructor
                                    //但這樣似乎不會新增Node 而是一直使用同一個Node 所以造成無限回圈
        head = FNode;
    }
    //FirstNode.next = head;  // pdf said it actually is null
    /*while(head->next!=NULL){
        cout << head ->name << endl;
        head = head ->next;
    }*/

}

AssassinsList::~AssassinsList() {
    // TODO: write this member
    while (head)
        {
            Node *trash = head;
            head = head->next;
            delete trash;
        }
        while (graveyard)
        {
            Node *trash = graveyard;
            graveyard = graveyard->next;
            delete trash;
        }

}

void AssassinsList::printGameRing() {
    // TODO: write this member

    Node * headt;
    headt = head;


    while (headt -> next != NULL){
        cout << headt -> name << " is targeting " << headt->next->name << endl;
        headt = headt -> next ;
    }
    cout << headt -> name <<  " is targeting " << head->name << endl;
}

void AssassinsList::printGraveyard() {
    // TODO: write this member
    Node * gravep=NULL;
    gravep = graveyard;
    if(gravep!=NULL){
        while(gravep->next != NULL){
            cout << gravep->name << " was eliminated by " << gravep->killer << endl;
            gravep = gravep->next;
        }

        cout << gravep->name << " was eliminated by " << gravep->killer << endl;
    }


}

bool AssassinsList::isAlive(string& player) {
    // TODO: write this member
    bool result = false;
    Node * checkp=NULL;
    checkp = head;

    while(checkp->next != NULL){
        if(checkp->name == player)
            result = true;
        checkp = checkp->next;
    }
    if(checkp->name == player)  // for last element
        result = true;

    return result;
}

bool AssassinsList::isDead(string& player) {
    // TODO: write this member
    bool result = false;
    Node * checkp=NULL;
    checkp = graveyard;
    //cout << "here at dead is ok" << endl;
    if(checkp != NULL){   // 一開始沒有這項檢查時 會當機！！
        while(checkp->next != NULL){
            if(checkp->name == player)
                result = true;

            checkp = checkp->next;
        }
        if(checkp->name == player)  // for last element
            result = true;
    }

    //cout << "dead result is " << result;
    return result;
}

bool AssassinsList::isGameOver() {
    // TODO: write this member
    Node * checkp=NULL;
    checkp = head;
    if(checkp->next == NULL){
        return true;
    }else{
        return false;
    }

}

string AssassinsList::winner() {
    // TODO: write this member
    Node * checkp=NULL;
    checkp = head;
    if(checkp->next == NULL){
        return checkp->name;
    }else{
        return "";
    }
}

void AssassinsList::eliminate(string& player) {
    // TODO: write this member
    Node * checkp=NULL;
    Node * temp=NULL;
    checkp = head;

    if(checkp->name == player){  // 注意若第一個人是被刺殺時 原本下面的while會找不到 進入無限回圈
        temp = checkp;
        while(checkp->next != NULL){
            checkp = checkp->next;
        }
        temp->killer=checkp->name;
        head = temp->next;
        temp->next = graveyard;
        graveyard = temp;


    }else{
        while(checkp->next->name != player){
            checkp = checkp->next;
            }

        temp = checkp->next;
        checkp->next->killer = checkp->name;  //memorize killer
        checkp->next = temp->next; // alive skip victim

        temp->next = graveyard; // victim go to graveyard;
        graveyard=temp; // let graveyard point to victim

    }
}
