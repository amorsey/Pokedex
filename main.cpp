//Pokedex
#include <iostream>
using namespace std;

int main()
{
    char choice;
    
    //Display Menu
    cout << "\t\tPokemon Menu: \n";
    cout << "(A) Pokedex \n";
    cout << "(B) Pokemon \n";
    cout << "(C) Items \n";
    cout << "(D) Badges \n";
    cout << "(D) Exit \n";
    cout << "Enter choice A, B, C, D, or E: ";
    
    cin >> choice;
    
    switch (choice)
    {
        case 'a':
        case 'A': cout << "You entered Pokedex. \n";
                  break;
        case 'b':
        case 'B': cout << "You entered Pokemon. \n";
                  break;
        case 'c':
        case 'C': cout << "You entered Items. \n";
                  break;
        case 'd':
        case 'D': cout << "You entered Badges. \n";
                  break;
        case 'e':
        case 'E': cout << "Goodbye! \n";
                  break;
        default:  cout << "Invalid, please enter A, B, C, D, or E!\n";
    }
    return 0;
}