// Given a positive integer num, return true if num is a perfect square or false otherwise.

// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

// You must not use any built-in library function, such as sqrt.

#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num) {
      for (long long i=1;i<=num;i++)  {
        if(i*i==num ){
            return true;
        }
        if(i*i>num) {
            return false;
        }
        }
        return 0;
    }

int main() {
    int num;
    cout << "Enter a positive integer : " << endl;
    cin >> num;

    bool result = isPerfectSquare(num);
    cout << result;
    
    return 0;
}