#include <iostream>
#include <cstdlib>                                              //Needed for srand function
#include <ctime>                                                //Needed for time function
#include "IntQueue.h"
#include "Pokedex.h"
using namespace std;

void pokemonparty(int party[]){                                  //Pokemon Selection using Queue
    srand (time(NULL));
    const int MAX_VALUES = 6;
    int c = 0;
    Pokedex dex;
    IntQueue iQueue(MAX_VALUES);

    if(party[0] == 0){                                          //the first time, select the party
        for (int index = 0; index < MAX_VALUES; index++){       //For loop to choose 6 Pokemon
            party[index] = rand()%151 + 1;                      //Assigns a random number between 1 and 151
            iQueue.enqueue(party[index]);                       //Puts the number in the queue
            party[index + MAX_VALUES] = dex.searchPoke(party[index]) -> level;  //stores the pokemon's level
        }
    } else { for (int index = 0; index < MAX_VALUES; index++) { iQueue.enqueue(party[index]); } }

    cout << "\n\t\tYour Party: \n";
    while (!iQueue.isEmpty())                                   //While loop to display the 6 pokemon in the queue
    {
        int value = 0;
        iQueue.dequeue(value);                                  //the pokemon are dequeued for display
        dex.displaySingle(value);                               //displays each pokemon's name
        cout << "Lv: " << party[c + MAX_VALUES] << endl;        //and their levels
        c++;
    }
<<<<<<< HEAD
    cout << "\nPress enter to return to the menu.\n\n\n";
    fflush(stdin);
=======
    cout << "\nPress any key to return to the menu.\n\n\n";
>>>>>>> 61c6f4c0b55c8b7d9bada87040ff46398f23a9c5
    cin.ignore();
}
