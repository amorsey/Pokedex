#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

class Pokedex{                                  //Pokedex using Binary Tree
private:
    struct Pokemon{
        int number, level;
        string name, type1, type2;
        Pokemon *left, *right;
    };
    Pokemon *head;

public:
    Pokedex(){                                  //constructor automatically fills the pokedex with
        head = nullptr;                         //information
        getPokesFile();
    }

    void pokeDelete(Pokemon *temp){             //deletes all nodes and pointers recursively
        if (temp->left != nullptr) { pokeDelete(temp->left); }
        if (temp->right != nullptr) { pokeDelete(temp->right); }
        delete temp;
        temp = nullptr;
    }

    ~Pokedex(){                                 //deconstructor to clean up
        Pokemon *temp = head;
        pokeDelete(temp);
    }
                                                //adding a pokemon to the binary tree
    void addPokes(int num, string pokeName, string pokeType1, string pokeType2){
        Pokemon *newPokePtr = new Pokemon;      //create a new node

        newPokePtr -> number = num;             //fill the node's variable's with information
        newPokePtr -> name = pokeName;
        newPokePtr -> left = nullptr;
        newPokePtr -> right = nullptr;
        newPokePtr -> type1 = pokeType1;
        newPokePtr -> type2 = pokeType2;
        newPokePtr -> level = rand() %100 + 1;

        if(!head) { head = newPokePtr; }        //check if there is already a tree, create one if there isn't
        else{                                   //append the new node if there is already a tree
            Pokemon *pokePtr = head;
                                                //go to the bottom of the tree
            while(pokePtr -> left && newPokePtr -> number < pokePtr -> number) { pokePtr = pokePtr -> left; }
            while(pokePtr -> right && newPokePtr -> number > pokePtr -> number) { pokePtr = pokePtr -> right; }

                                                //connect the new node to the tree
            if(newPokePtr -> number < pokePtr -> number) { pokePtr -> left = newPokePtr; }
            else{ pokePtr -> right = newPokePtr; }
        }
    }

    void display(Pokemon* pokePtr){             //display uses inorder and recursion to display all the pokemon
        if(pokePtr -> left) { display(pokePtr -> left); }
        cout << setw(7) << right << pokePtr -> number << "     " << left << setw(10) << pokePtr -> name;
        cout << "     " << setw(8) << pokePtr -> type1 << " "<< setw(8) << pokePtr -> type2 << endl;
        if(pokePtr -> right) { display(pokePtr -> right); }
    }

    void displaySingle(int num){                //display used for only showing one pokemon at a time
        Pokemon *pokePtr = findPoke(head, num);
        cout << setw(15) << left << pokePtr -> name;
    }

    Pokemon* searchPoke(int num){               //extra function allows main to call searchPoke while only passing
        return findPoke(head, num);             //the number of the desired pokedex entry and for findPoke to
    }                                           //execute recursively

    Pokemon* findPoke(Pokemon *temp ,int num){  //traverses the linked list to find a node who's number field
        if(temp){                               //matches the number passed
            if(temp -> number == num) { return temp; }
            if(temp -> number > num) { findPoke(temp -> left, num); }
            if(temp -> number < num) { findPoke(temp -> right, num); }
        }
        else { return nullptr; }
    }

    void showPokes(){                           //extra function for displaying allows main to call showPokes
        cout << "\nNumber:     Name:          Type(s):\n";
        display(head);                          //without passing any parameters and for display to execute recursively
        cout << "\nPress any key to return to the menu.\n\n\n";
        getch();
    }

    void getPokesFile(){                        //gets all information on each pokemon from a file to add to the BST

        int number;
        int count = 0;
        string name;
        string type1;
        string type2;
        string line;
        unsigned long start;
        unsigned long end;

        ifstream myfile("PokeList.txt");                        //Open and pull from file.
        if (myfile.is_open()){
            while(!(myfile.eof())){
                type2 = "";
                getline (myfile,line);

                start = line.find(" ");                         //Pull number for line.
                name = line.substr(1, start);
                istringstream buffer(name);
                buffer >> number;

                start = line.find_first_not_of(" ", start);     //Pull name from line.
                end = line.find(" ", start) - start;
                name = line.substr(start,end);

                start = start + end;                            //Pull first type from line.
                start = line.find_first_not_of(" ", start);
                end = line.find(" ", start) - start;
                start = start + end;
                start = line.find_first_not_of(" ", start);
                end = line.find(" ", start) - start;
                type1 = line.substr(start,end);

                start = start + end;                            //Pull second type from line.
                start = line.find_first_not_of(" ", start);
                if(start != string::npos){
                    end = line.find(" ", start) - start;
                    type2 = line.substr(start,end);
                }

                addPokes(number, name, type1, type2);           //Create a pokemon node.
                count ++;
            }
            myfile.close();                                     //Close the file when finished with it.
        }
        else cout << "Unable to open file"<<endl;
    }
};
