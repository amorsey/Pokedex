#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class PokeList{
private:
    struct Pokes{
        int number;
        string name, type1, type2;
        Pokes *next, *prev;
    };
    Pokes *head;
    
public:
    PokeList(){
        head = nullptr;
    }
    
    void pokeDelete(Pokes *temp){
        if (temp->next != nullptr){
            pokeDelete(temp->next);
        }
        delete temp;
        temp = nullptr;
    }
    
    void addPokes(int num, string pokeName, string pokeType1, string pokeType2){
        Pokes *newPokePtr = new Pokes;
        newPokePtr -> number = num;
        newPokePtr -> name = pokeName;
        newPokePtr -> next = nullptr;
        newPokePtr -> prev = nullptr;
        newPokePtr -> type1 = pokeType1;
        newPokePtr -> type2 = pokeType2;
        
        if (!head) {
            head = newPokePtr;
            newPokePtr -> prev = head;
        } else {
            Pokes *pokePtr = head;
            while(pokePtr -> next){
                pokePtr = pokePtr -> next;
            }
            pokePtr -> next = newPokePtr;
            newPokePtr -> prev = pokePtr;
        }
    }
    
    void display(Pokes* pokePtr){
        cout << "Number:     Name:          Type(s):\n";
        if(pokePtr -> next){
            display(pokePtr -> next);
        }
        cout << setw(7) << right << pokePtr -> number << "     " << left << setw(10) << pokePtr -> name << "     " << setw(8) << pokePtr -> type1 << " "<< setw(8) << pokePtr -> type2 << endl << endl;
    }

    void showPokes(){
        display(head);
    }
    
    ~PokeList(){
        Pokes *temp = head;
        pokeDelete(temp);
    }
};