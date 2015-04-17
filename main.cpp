//Pokedex
#include <iostream>
#include "pokemonparty.h"
#include "items.h"
#include "badgecase.h"
using namespace std;

int main()
{
    char choice;
    
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
            case 'A': cout << "You entered Pokedex. \n";
                    break;
            case 'b':
            case 'B': pokemonparty();
                    break;
            case 'c':
            case 'C': items();
                    break;
            case 'd':
            case 'D': showBadges();
                    break;
            case 'e':
            case 'E': cout << "Goodbye! \n";
                    return 0;
            default:  cout << "Invalid, please enter A, B, C, D, or E!\n";
        }
    }
    return 0;
}