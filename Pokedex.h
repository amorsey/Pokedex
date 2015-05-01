#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

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
    Pokedex() { head = nullptr;
        getPokesFile();
        }
    
    void pokeDelete(Pokemon *temp){
        if (temp->left != nullptr) { pokeDelete(temp->left); }
        if (temp->right != nullptr) { pokeDelete(temp->right); }
        delete temp;
        temp = nullptr;
    }
    
    void addPokes(int num, string pokeName, string pokeType1, string pokeType2){
        Pokemon *newPokePtr = new Pokemon;
        newPokePtr -> number = num;
        newPokePtr -> name = pokeName;
        newPokePtr -> left = nullptr;
        newPokePtr -> right = nullptr;
        newPokePtr -> type1 = pokeType1;
        newPokePtr -> type2 = pokeType2;
        
        if (!head) { head = newPokePtr; }
        else{
            Pokemon *pokePtr = head;
            while(pokePtr -> left && newPokePtr -> number < pokePtr -> number) { pokePtr = pokePtr -> left; }
            while(pokePtr -> right && newPokePtr -> number > pokePtr -> number) { pokePtr = pokePtr -> right; }
            if(newPokePtr -> number < pokePtr -> number) { pokePtr -> left = newPokePtr; }
            else{ pokePtr -> right = newPokePtr; }
        }
    }
    
    void display(Pokemon* pokePtr){
        cout << "Number:     Name:          Type(s):\n";
        if(pokePtr -> left) { display(pokePtr -> left); }
        cout << setw(7) << right << pokePtr -> number << "     " << left << setw(10) << pokePtr -> name << "     " << setw(8) << pokePtr -> type1 << " "<< setw(8) << pokePtr -> type2 << endl << endl;
        if(pokePtr -> right) { display(pokePtr -> right); }
    }
    
    void showPokes() { display(head); }
    
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
                number = stoi(name);
                
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
    
    
    ~Pokedex(){
        Pokemon *temp = head;
        pokeDelete(temp);
    }
};
