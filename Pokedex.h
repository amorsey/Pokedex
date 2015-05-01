#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
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

        //check if there is already a tree, create one if there isn't
        if(!head) { head = newPokePtr; }

        //append the new node if there is
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
        cout << "Number:     Name:          Type(s):\n";
        if(pokePtr -> left) { display(pokePtr -> left); }
        cout << setw(7) << right << pokePtr -> number << "     " << left << setw(10) << pokePtr -> name << "     " << setw(8) << pokePtr -> type1 << " "<< setw(8) << pokePtr -> type2 << endl << endl;
        if(pokePtr -> right) { display(pokePtr -> right); }
    }

    //display used for only showing one pokemon at a time
    void displaySingle(int num){
        Pokemon *pokePtr = findPoke(head, num);
        cout << pokePtr -> name << "\tLvl:" << pokePtr -> level << endl;
    }

    //tranverses the linked list to find a node who's number field matches the number passed
    Pokemon* findPoke(Pokemon *temp ,int num){
        Pokemon *pokePtr;
        temp = head;
        if(temp -> left) { findPoke(temp -> left, num); }
        if(temp -> number == num) { pokePtr = temp; }
        if(temp -> right) { findPoke(temp -> right, num); }
        return pokePtr;
    }

    //having an extra function for displaying allows the main to call display without passing any parameters and for display to execute recursively
    void showPokes() { display(head); }

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

    //deconstructor to clean up
    ~Pokedex(){
        Pokemon *temp = head;
        pokeDelete(temp);
    }
};
