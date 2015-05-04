//Badges using Stacks
#include <iostream>
#include <stack>
#include <conio.h>
using namespace std;

void showBadges()
{
    stack<string> badgeCase;
    string badges[8];

    badgeCase.push("Earth Badge");
    badgeCase.push("Volcano Badge");
    badgeCase.push("Marsh Badge");
    badgeCase.push("Soul Badge");
    badgeCase.push("Rainbow Badge");
    badgeCase.push("Thunder Badge");
    badgeCase.push("Cascade Badge");
    badgeCase.push("Boulder Badge");

    cout << "\n\t\tBadges:\n";

    for(int c = 0; c < 8; c++){
        badges[c] = badgeCase.top();
        cout << badges[c] << endl;
        badgeCase.pop();
    }

    cout << "\nPress any key to return to the menu.\n\n\n";
    getch();
}
