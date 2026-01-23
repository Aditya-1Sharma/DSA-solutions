// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
        vector<int> arr{0,1,1};

        if(n <= 2) return arr[n];

        for(int i = 3; i <= n; i++){
            int temp = arr[0] + arr[1] + arr[2];
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = temp;
        }

        return arr[2];
    }

int main() {
    int n;
    cout << "Give the value of n : ";
    cin >> n;

    int tribo = tribonacci(n);
    cout << tribo;

    return 0;
}