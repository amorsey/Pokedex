#ifndef __CS_252_Project__Badges__
#define __CS_252_Project__Badges__

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Items{
private:
    struct Slot{
        string name;
        int number;
    };
    
    Slot bag[10];
    int size;
    
public:
    Items();
    void addItem(string);
    void useItem(string);
    void displayAll();
};

Items::Items(){
    size = 0;
};


void Items::addItem(string thing){
    int spot = -1;
    
    for(int i = 0; i < size; i++){
        if(bag[i].name == thing)
            spot = i;
    }
    
    if(spot == -1){
        bag[size].name = thing;
        bag[size].number = 1;
        size++;
    } else{
        bag[spot].number++;
    }
}

void Items::useItem(string thing){
    int spot = -1;
    
    for(int i = 0; i < size; i++){
        if(bag[i].name == thing)
            spot = i;
    }
    
    if(spot == -1){
        cout << "No item";
    } else if(bag[spot].number == 1){
        for(int i = spot; i < size; i++){
            bag[i] = bag[i+1];
        }
        size--;
    } else{
        bag[spot].number--;
    }
    

}

void Items::displayAll(){
    for(int i = 0; i < size; i++){
        cout << bag[i].name << "\n          x " << bag[i].number << endl;
    }
    cout << endl;
}

#endif /* defined(__CS_252_Project__Badges__) */
