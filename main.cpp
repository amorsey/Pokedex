//Pokedex
#include <iostream>
#include "pokemonparty.h"
#include "items.h"
#include "badgecase.h"
#include "Pokedex.h"
using namespace std;

int main()
{
    char choice;
    
    Pokedex pokemon;        //Creates an object which will add all pokemon to the pokedex
    
    //Display Menu
    while(true)
    {
        cout << "\t\tPokemon Menu: \n";
        cout << "(A) Pokedex \n";
        cout << "(B) Pokemon Party \n";
        cout << "(C) Items \n";
        cout << "(D) Badges \n";
        cout << "(D) Exit \n";
        cout << "Enter choice A, B, C, D, or E: \n";
    
        cin >> choice;
    
        switch (choice)
        {
            case 'a':
            case 'A': pokemon.showPokes();          //Function to display all Pokemon in the pokedex
                    break;
            case 'b':
            case 'B': pokemonparty();               //Function to display the 6 Pokemon in our party
                    break;
            case 'c':
            case 'C': items();                      //Function to display our items
                    break;
            case 'd':
            case 'D': showBadges();                 //Function to display our badges
                    break;
            case 'e':
            case 'E': cout << "Goodbye! \n";
                    return 0;
            default:  cout << "Invalid, please enter A, B, C, D, or E!\n";
        }
    }
    return 0;
}