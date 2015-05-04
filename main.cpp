#include <iostream>
#include <iomanip>
#include "pokemonparty.h"
#include "items.h"
#include "badgecase.h"
#include "Pokedex.h"
using namespace std;

void pokemonparty(int party[])
{
    srand (time(NULL));
    const int MAX_VALUES = 6;
    int c = 0;
    Pokedex dex;
    IntQueue iQueue(MAX_VALUES);

    if(party[0] == 0){
        for (int index = 0; index < MAX_VALUES; index++){       //For loop to choose 6 Pokemon
            party[index] = rand()%151 + 1;                         //Assigns a random number between 1 and 151
            iQueue.enqueue(party[index]);                            //Puts the number in the queue
            party[index + 6] = dex.searchPoke(party[index]) -> level;  //stores the pokemon's level
        }
    } else { for (int index = 0; index < MAX_VALUES; index++) { iQueue.enqueue(party[index]); } }

    cout << "\n\t\tYour Party: \n";
    while (!iQueue.isEmpty())                               //While loop to display the 6 pokemon in the queue
    {
        int value = 0;
        iQueue.dequeue(value);
        dex.displaySingle(value);
        cout << "Lv: " << party[c + 6] << endl;             //and their levels
        c++;
    }
    cout << "\nPress any key to return to the menu.\n\n\n";
    getch();
}

int main()
{
    char choice;
    Pokedex pokemon;        //Creates an object which will add all pokemon to the pokedex
    int party[12];          //an array of ints to store party pokemon and their levels
    for(int c = 0; c < 6; c++) { party[c] = 0; }

    //Display Menu
    while(true)
    {
        cout << "\t\tPokemon Menu: \n";
        cout << "(A) Pokedex\n";
        cout << "(B) Pokemon\n";
        cout << "(C) Bag\n";
        cout << "(D) Badge Case \n";
        cout << "(E) Exit \n";
        cout << "Enter choice A, B, C, D, or E: \n";

        cin >> choice;

        switch (choice)
        {
            case 'a':
            case 'A': pokemon.showPokes();          //Function to display all Pokemon in the pokedex
                    break;
            case 'b':
            case 'B': pokemonparty(party);        //Function to display the 6 Pokemon in our party
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
            default : cout << "Invalid, please enter A, B, C, D, or E!\n";
        }
    }
    return 0;
}
