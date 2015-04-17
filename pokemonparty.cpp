//Pokemon Selection Queue
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IntQueue.h"
using namespace std;

void pokemonparty()
{
    srand (time(NULL));
    const int MAX_VALUES = 6;
    int pokemon;
    
    IntQueue iQueue(MAX_VALUES);
    
    cout << "Getting " << MAX_VALUES << " Pokemon...\n";
    for (int index = 0; index < MAX_VALUES; index++)
    {
        pokemon = (rand()%151) + 1;
        iQueue.enqueue(pokemon);
    }
    
    cout << "The Pokemon selected were... \n";
    while (!iQueue.isEmpty())
    {
        int value;
        iQueue.dequeue(value);
        cout << value << endl;
    }
}