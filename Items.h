#ifndef __CS_252_Project__Badges__
#define __CS_252_Project__Badges__

#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

class Items{                                //Items list class
private:
    struct Slot{
        string name;
        int number;
    };

    Slot bag[10];                           //Array to hold items
    int size;                               //Keeps track of how full item bag is

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
    for(int i = 0; i < size; i++) { if(bag[i].name == thing) { spot = i; } }
    if(spot > -1) { bag[spot].number++; }
    else if(size < 10){
        bag[size].name = thing;
        bag[size].number = 1;
        size++;
    } else { cout << "Bag is full\n"; }
}

void Items::useItem(string thing){
    int spot = -1;
    for(int i = 0; i < size; i++) { if(bag[i].name == thing) { spot = i; } }
    if(spot == -1) { cout << "Item not found"; }
    else if(bag[spot].number == 1){
        for(int i = spot; i < size; i++){ bag[i] = bag[i+1]; }
        size--;
    } else { bag[spot].number--; }
}

void Items::displayAll(){
    cout << "\n\t\tItems:" << endl;
    for(int i = 0; i < size; i++) { cout << bag[i].name << "\n          x " << bag[i].number << endl; }
    cout << "\nPress any key to return to the menu.\n\n\n";
    cin.ignore();
}

void Items::sort(){                                 //Bubble sort
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(bag[j].name > bag[j + 1].name){
                Slot temp  = bag[j + 1];
                bag[j + 1] = bag[j];
                bag[j]     = temp;
            }
        }
    }
}

void items()
{
    Items one;
    one.addItem("Repel");
    one.addItem("Super Potion");
    one.addItem("Rare Candy");
    one.addItem("Escape Rope");
    one.addItem("Moon Stone");
    one.addItem("Antidote");
    for(int i = 0; i < 7; i++)  { one.addItem("Great Ball"); }
    for(int i = 0; i < 5; i++)  { one.addItem("Potion"); }
    for(int i = 0; i < 3; i++)  { one.addItem("Revive"); }
    for(int i = 0; i < 10; i++) { one.addItem("Poke Ball"); }

    one.sort();
    one.displayAll();

    one.useItem("Potion");
    one.displayAll();
}
#endif
