#include <iostream>
#include <iomanip>
#include "pokemonparty.h"
#include "items.h"
#include "badgecase.h"
using namespace std;

int main()
{
    char choice;
<<<<<<< HEAD
    Pokedex pokemon;
    int party[12];                                  //an array of ints to store party pokemon's numbers and their levels
    for(int c = 0; c < 6; c++) { party[c] = 0; }    //initializes the int array
=======
>>>>>>> 4d64c0f73e0981cbd250562e3af9e621ecef2f80

    Pokedex pokemon;        //Creates an object which will add all pokemon to the pokedex

    int party[12];                                  //An array of ints to store party pokemon's numbers and their levels
    for(int c = 0; c < 6; c++) { party[c] = 0; }    //Initializes the int array

    while(true)                                     //Menu
    {
        cout << "\t\tPokemon Menu: \n";
        cout << "(A) Pokedex \n";
        cout << "(B) Pokemon Party \n";
        cout << "(C) Items \n";
        cout << "(D) Badges \n";
        cout << "(E) Exit \n";
        cout << "Enter choice A, B, C, D, or E: \n";

        cin >> choice;                              //Receives users selection

        switch (choice)
        {
            case 'a':
            case 'A': pokemon.showPokes();          //Function to display all Pokemon in the pokedex
                    break;
            case 'b':
            case 'B': pokemonparty(party);          //Function to display the 6 Pokemon in our party
                    break;
            case 'c':
            case 'C': items();                      //Function to display our items
                    break;
            case 'd':
            case 'D': showBadges();                 //Function to display our badges
                    break;
            case 'e':
            case 'E': cout << "Goodbye! \n";        //Exit
                    return 0;
            default : cout << "Invalid, please enter A, B, C, D, or E!\n";
        }
    }
    return 0;
}
