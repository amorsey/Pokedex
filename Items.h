//Sorting Items using Bubble Sort
#ifndef __CS_252_Project__Badges__
#define __CS_252_Project__Badges__

#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
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
    void sort();
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

    if(spot > -1){
        bag[spot].number++;
    }else if(size < 10){
        bag[size].name = thing;
        bag[size].number = 1;
        size++;
    }else{
        cout << "Bag is full\n";
    }
}

void Items::useItem(string thing){
    int spot = -1;

    for(int i = 0; i < size; i++){
        if(bag[i].name == thing)
            spot = i;
    }

    if(spot == -1){
        cout << "No item found";
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
    cout << "\n\t\tItems:" << endl;
    for(int i = 0; i < size; i++){
        cout << bag[i].name << "\n          x " << bag[i].number << endl;
    }
    cout << "\nPress any key to return to the menu.\n\n\n";
    getch();
}

void Items::sort(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(bag[j].name > bag[j+1].name){
                Slot temp = bag[j+1];
                bag[j+1] = bag[j];
                bag[j] = temp;
            }
        }
    }
}

void items()
{
    Items one;
    one.addItem("Potion");
    one.addItem("Potion");
    one.addItem("Potion");
    one.addItem("Super Potion");
    one.addItem("Rare Candy");
    for(int i = 0; i < 10; i++) { one.addItem("Poke Ball"); }
    one.addItem("Escape Rope");
    for(int i = 0; i < 5; i++) { one.addItem("Great Ball"); }
    one.addItem("Moon Stone");
    one.addItem("Antidote");
    for(int i = 0; i < 3; i++) { one.addItem("Revive"); }
    one.addItem("Repel");

    one.displayAll();

    //one.useItem("Rare Candy");
    //one.displayAll();
}
#endif /* defined(__CS_252_Project__Badges__) */
