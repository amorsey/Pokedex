#include <iostream>

using namespace std;

class Pokedex{
private:
    struct Pokemon{
        int number;
        string name, type1, type2;
        Pokemon *left, *right;
    };
    Pokemon *head;

public:
    Pokedex() { head = nullptr; }

    void pokeDelete(Pokemon *temp){
        if (temp->left != nullptr) { pokeDelete(temp->left); }
        if (temp->right != nullptr) { pokeDelete(temp->right); }
        delete temp;
        temp = nullptr;
    }

    void addPokes(int num, string pokeName, string pokeType1, string pokeType2){
        Pokemon *newPokePtr;
        Pokemon *pokePtr;

        newPokePtr = new Pokemon;
        newPokePtr -> number = num;
        newPokePtr -> left = nullptr;
        newPokePtr -> right = nullptr;
        newPokePtr -> type1 = pokeType1;
        newPokePtr -> type2 = pokeType2;

        if (!head) { head = newPokePtr; }
        else {
            pokePtr = head;
            while(newPokePtr -> number < pokePtr -> number && pokePtr -> left) { pokePtr = pokePtr -> left; }
            while(newPokePtr -> number > pokePtr -> number && pokePtr -> right) { pokePtr = pokePtr -> right; }
            if(newPokePtr -> number < pokePtr -> number) { pokePtr -> left = newPokePtr; }
            else { pokePtr -> right = newPokePtr; }
        }
    }

    ~Pokedex(){
        Pokemon *temp = head;
        pokeDelete(temp);
    }
};

int main(){

    Pokedex dex;

    return 0;
}
