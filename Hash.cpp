#include "Hash.h"
#include <iostream>
#include <string>
#include "PokeList.h"

Hash::Hash(){
    for(int i = 0; i< 18; i++){
        for(int j = 0; j < 18; j++){
            hashTable[i][j] = nullptr;
        }
    }
}

int Hash::hashFunc(string key)
{
    int index;
    if(key == "Grass")
        index = 1;
    else if(key == "Poison")
        index = 2;
    else if(key == "Fire")
        index = 3;
    else if(key == "Electric")
        index = 4;
    else if(key == "Rock")
        index = 5;
    else if(key == "Ghost")
        index = 6;
    else if(key == "Ice")
        index = 7;
    else if(key == "Flying")
        index = 8;
    else if(key == "Steel")
        index = 9;
    else if(key == "Fighting")
        index = 10;
    else if(key == "Normal")
        index = 11;
    else if(key == "Ground")
        index = 12;
    else if(key == "Dragon")
        index = 13;
    else if(key == "Bug")
        index = 14;
    else if(key == "Fairy")
        index = 15;
    else if(key == "Psychic")
        index = 16;
    else if(key == "Water")
        index = 17;
    else
        index = 0;
    
    return index;
    
}

void Hash::addPokes(int num, string pokeName, string pokeType1, string pokeType2){
    
    int indexI = hashFunc(pokeType1);
    int indexJ = hashFunc(pokeType2);
    
    if(hashTable[indexI][indexJ] == nullptr){
        hashTable[indexI][indexJ] = new Pokes;
        hashTable[indexI][indexJ]->number = num;
        hashTable[indexI][indexJ]->next = nullptr;
        hashTable[indexI][indexJ]->name = pokeName;
        hashTable[indexI][indexJ]->type1 = pokeType1;
        hashTable[indexI][indexJ]->type2 = pokeType2;
    } else {
        Pokes* p = hashTable[indexI][indexJ];
        while(p->next){
            p = p->next;
        }
        Pokes* t = new Pokes;
        t->number = num;
        t->next = nullptr;
        t->name = pokeName;
        t->type1 = pokeType1;
        t->type2 = pokeType2;
        p->next = t;
    }
}

void Hash::get(string type)
{
    for(int i = 0; i < 18; i++){
        Pokes* p = hashTable[hashFunc(type)][i];
        while(!(p == nullptr)){
            display(p);
            p = p->next;
        }
    }
    
    for(int i = 0; i < 18; i++){
        Pokes* p = hashTable[i][hashFunc(type)];
        while(!(p == nullptr)){
            display(p);
            p = p->next;
        }
    }
}

void Hash::display(Pokes* pokePtr){
    cout << "Number:     Name:          Type(s):\n";
    cout << setw(7) << right << pokePtr -> number << "     " << setw(10) << left << pokePtr -> name << "     " << setw(8) << pokePtr -> type1 << " "<< setw(8) << pokePtr -> type2 << endl << endl;
}