#include <iostream>
#include "Items.h"
using namespace std;

void items()
{
    Items one;
    one.addItem("Potion");
    one.addItem("Potion");
    one.addItem("Potion");
    one.addItem("Super Potion");
    one.addItem("Feather");
    one.addItem("A large book");
    one.displayAll();
    
    one.useItem("Feather");
    one.displayAll();
}
