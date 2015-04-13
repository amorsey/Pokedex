#include <iostream>
#include "Items.h"
using namespace std;

int main() {
    Items one;
    one.addItem("Potion");
    one.addItem("Potion");
    one.addItem("Potion");
    one.addItem("Super Postion");
    one.addItem("Feather");
    one.addItem("A large book");
    one.displayAll();
    
    one.useItem(2);
    one.displayAll();
}
