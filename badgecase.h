#include <iostream>
#include <stack>
using namespace std;

void showBadges()
{
    stack<string> badgeCase;
    string badge1, badge2, badge3, badge4, badge5, badge6, badge7, badge8;

    badgeCase.push("The Earth Badge");
    badgeCase.push("The Volcano Badge");
    badgeCase.push("The Marsh Badge");
    badgeCase.push("The Soul Badge");
    badgeCase.push("The Rainbow Badge");
    badgeCase.push("The Thunder Badge");
    badgeCase.push("The Cascade Badge");
    badgeCase.push("The Boulder Badge");

    badge1 = badgeCase.top();
    cout << badge1 << endl;
    badgeCase.pop();

    badge2 = badgeCase.top();
    cout << badge2 << endl;
    badgeCase.pop();

    badge3 = badgeCase.top();
    cout << badge3 << endl;
    badgeCase.pop();

    badge4 = badgeCase.top();
    cout << badge4 << endl;
    badgeCase.pop();

    badge5 = badgeCase.top();
    cout << badge5 << endl;
    badgeCase.pop();

    badge6 = badgeCase.top();
    cout << badge6 << endl;
    badgeCase.pop();

    badge7 = badgeCase.top();
    cout << badge7 << endl;
    badgeCase.pop();

    badge8 = badgeCase.top();
    cout << badge8 << endl << endl;
    badgeCase.pop();

    cout << "Press any key to go back." <<endl;
    cin.ignore();
}
