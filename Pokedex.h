//Pokedex using Binary Tree
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

class Pokedex{
private:
    struct Pokemon{
        int number, level;
        string name, type1, type2;
        Pokemon *left, *right;
    };
    Pokemon *head;

public:
    //constructor automatically fills the pokedex with information
    Pokedex(){
        head = nullptr;
        getPokesFile();
    }

    //deletes all nodes and pointers recursively
    void pokeDelete(Pokemon *temp){
        if (temp->left != nullptr) { pokeDelete(temp->left); }
        if (temp->right != nullptr) { pokeDelete(temp->right); }
        delete temp;
        temp = nullptr;
    }

    //deconstructor to clean up
    ~Pokedex(){
        Pokemon *temp = head;
        pokeDelete(temp);
    }

    //adding a pokemon to the binary tree
    void addPokes(int num, string pokeName, string pokeType1, string pokeType2){

        //create a new node
        Pokemon *newPokePtr = new Pokemon;

        //fill the node's variable's with information
        newPokePtr -> number = num;
        newPokePtr -> name = pokeName;
        newPokePtr -> left = nullptr;
        newPokePtr -> right = nullptr;
        newPokePtr -> type1 = pokeType1;
        newPokePtr -> type2 = pokeType2;
        newPokePtr -> level = rand() %100 + 1;

        //check if there is already a tree, create one if there isn't
        if(!head) { head = newPokePtr; }

        //append the new node if there is already a tree
        else{
            Pokemon *pokePtr = head;

            //go to the bottom of the tree
            while(pokePtr -> left && newPokePtr -> number < pokePtr -> number) { pokePtr = pokePtr -> left; }
            while(pokePtr -> right && newPokePtr -> number > pokePtr -> number) { pokePtr = pokePtr -> right; }

            //connect the new node to the tree
            if(newPokePtr -> number < pokePtr -> number) { pokePtr -> left = newPokePtr; }
            else{ pokePtr -> right = newPokePtr; }
        }
    }

    //display uses inorder and recursion to display all the pokemon
    void display(Pokemon* pokePtr){
        if(pokePtr -> left) { display(pokePtr -> left); }
        cout << setw(7) << right << pokePtr -> number << "     " << left << setw(10) << pokePtr -> name << "     " << setw(8) << pokePtr -> type1 << " "<< setw(8) << pokePtr -> type2 << endl;
        if(pokePtr -> right) { display(pokePtr -> right); }
    }

    //display used for only showing one pokemon at a time
    void displaySingle(int num){
        Pokemon *pokePtr = findPoke(head, num);
        cout << setw(15) << left << pokePtr -> name;
    }

    ////extra function allows main to call searchPoke while only passing the number of the desired pokedex entry and for findPoke to execute recursively
    Pokemon* searchPoke(int num){
        return findPoke(head, num);
    }

    //traverses the linked list to find a node who's number field matches the number passed
    Pokemon* findPoke(Pokemon *temp ,int num){
        if(temp){
            if(temp -> number == num) { return temp; }
            if(temp -> number > num) { findPoke(temp -> left, num); }
            if(temp -> number < num) { findPoke(temp -> right, num); }
        }
        else { return nullptr; }
    }

    //extra function for displaying allows main to call showPokes without passing any parameters and for display to execute recursively
    void showPokes(){
        cout << "\nNumber:     Name:          Type(s):\n";
        display(head);
        cout << "\nPress any key to return to the menu.\n\n\n";
        getch();
    }

    //gets all information on each pokemon from a file to add to the BST
    void getPokesFile(){

        int number;
        int count = 0;
        string name;
        string type1;
        string type2;
        string line;
        unsigned long start;
        unsigned long end;

        //Open and pull from file.
        ifstream myfile("PokeList.txt");
        if (myfile.is_open()){
            while(!(myfile.eof())){
                type2 = "";
                getline (myfile,line);

                //Pull number for line.
                start = line.find(" ");
                name = line.substr(1, start);
                istringstream buffer(name);
                buffer >> number;

                //Pull name from line.
                start = line.find_first_not_of(" ", start);
                end = line.find(" ", start) - start;
                name = line.substr(start,end);

                //Pull frist type from line.
                start = start + end;
                start = line.find_first_not_of(" ", start);
                end = line.find(" ", start) - start;
                start = start + end;
                start = line.find_first_not_of(" ", start);
                end = line.find(" ", start) - start;
                type1 = line.substr(start,end);

                //Pull second type from line.
                start = start + end;
                start = line.find_first_not_of(" ", start);
                if(start != string::npos){
                    end = line.find(" ", start) - start;
                    type2 = line.substr(start,end);
                }

                addPokes(number, name, type1, type2);
                count ++;
            }
            myfile.close();
        }
        else cout << "Unable to open file"<<endl;
    }
};
