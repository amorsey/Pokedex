//Pokemon Selection using Queue
#include <iostream>
#include <cstdlib>      //Needed for srand function
#include <ctime>        //Needed for time function
#include "IntQueue.h"   //To attach IntQueue.h
#ifndef "Pokedex.h"
using namespace std;

void pokemonparty(Pokedex dex)
{
    srand (time(NULL));
    const int MAX_VALUES = 6;
    int pokemon;

    IntQueue iQueue(MAX_VALUES);

    for (int index = 0; index < MAX_VALUES; index++)        //For loop to choose 6 Pokemon
    {
        pokemon = (rand()%151) + 1;                         //Assigns a random number between 1 and 151
        iQueue.enqueue(pokemon);                            //Puts the number in the queue
    }

    cout << "Your Party: \n";
    while (!iQueue.isEmpty())                               //While loop to display the 6 pokemon in the queue
    {
        int value;
        iQueue.dequeue(value);
        dex.displaySingle(value);
    }
}
#endif
