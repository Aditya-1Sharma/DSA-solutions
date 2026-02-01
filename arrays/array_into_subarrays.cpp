// You are given an array of integers nums of length n.

// The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

// You need to divide nums into 3 disjoint contiguous subarrays.

// Return the minimum possible sum of the cost of these subarrays.

#include <bits/stdc++.h>
using namespace std;

int minimumCost(vector<int>& A) {
        int a = 51, b = 51;

        for (int i = 1; i < A.size(); i++) {
            if (A[i] < a) {
                b = a;
                a = A[i];
            } else if (A[i] < b)
                b = A[i];

            if (a == 1 && b == 1) break;
        }

        return A[0] + a + b;
    }

int main() {
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = minimumCost(A);
    cout << "Minimum possible sum of the cost of the subarrays = " << result <<endl;

    return 0;
}
