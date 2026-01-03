#include <bits/stdc++.h>
using namespace std;

int main() {

    int a;
    cin >> a;

    if(a<10) {
        cout << "less than 10" << endl;
    }

    else if (a > 10) {
        cout << "greater than 10" << endl;
    }

    else {
        cout << "equal to 10" << endl;
    }

    // AND operator && (if a > 2 && a < 4) -> if a is greater than 2 and a is less than 4
    // OR operator ||  (if a > 2 || a < 4) -> if a is greater than 2 or a is less than 4

    return 0;

}