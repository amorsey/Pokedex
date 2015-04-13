#ifndef __CS_252_Project__Badges__
#define __CS_252_Project__Badges__

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Items{
private:
    string bag[10];
    int size;
    
public:
    Items();
    void addItem(string);
    void useItem(int);
    void displayAll();
};

Items::Items(){
    size = 0;
};


void Items::addItem(string thing){
    if(size == 10){
        cout << "Bag is full" << endl;
    }
    else{
        size++;
        bag[size] = thing;
    }
}

void Items::useItem(int a){
    for(int i = a; i < (9 - size); i++){
        bag[i] = bag[i+1];
    }
}

void Items::displayAll(){
    for(int i = 0; i < size; i++){
        cout << bag[i] << endl;
    }
}

#endif /* defined(__CS_252_Project__Badges__) */
