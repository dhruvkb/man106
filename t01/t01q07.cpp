#include <iostream>
#define MAX 50

using namespace std;

int main() {
    char weekdays[7][MAX] = {
        "Mon",
        "Tues",
        "Wed",
        "Thurs",
        "Fri",
        "Sat",
        "Sun"
    };
    int pos;
    cout << "Enter an integer between 1 and 7: ";
    cin >> pos;
    cout << weekdays[pos-1];
    return 0;
}
