#include <iostream>
#include <stack>
using namespace std;

void showBadges()                       //Badges using Stacks
{
    stack<string> badgeCase;            //Use STL to create a string stack
    string badges[8];                   //Create an array of string to hold badges

    badgeCase.push("Earth Badge");      //Push all the badges onto the stack
    badgeCase.push("Volcano Badge");
    badgeCase.push("Marsh Badge");
    badgeCase.push("Soul Badge");
    badgeCase.push("Rainbow Badge");
    badgeCase.push("Thunder Badge");
    badgeCase.push("Cascade Badge");
    badgeCase.push("Boulder Badge");

    cout << "\n\t\tBadges:\n";

    for(int c = 0; c < 8; c++){         //loop for displaying badges
        badges[c] = badgeCase.top();    //store each badge in the badges array
        cout << badges[c] << endl;      //show each badge
        badgeCase.pop();                //pop each badge off the stack
    }

<<<<<<< HEAD
    cout << "\nPress enter to return to the menu.\n\n\n";
    fflush(stdin);
=======
    cout << "\nPress any key to return to the menu.\n\n\n";
<<<<<<< HEAD
=======

>>>>>>> 4d64c0f73e0981cbd250562e3af9e621ecef2f80
>>>>>>> 61c6f4c0b55c8b7d9bada87040ff46398f23a9c5
    cin.ignore();
}
