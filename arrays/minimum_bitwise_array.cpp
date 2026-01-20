// You are given an array nums consisting of n prime integers.

// You need to construct an array ans of length n, such that, for each index i,
// the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

// Additionally, you must minimize each value of ans[i] in the resulting array.

// If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

#include <bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> sol;
    for(auto x : nums){
        if(x % 2 == 0) sol.push_back(-1);
        else{
            int t = 0;

            while(x & (1 << t)) t++;
            sol.push_back(x ^ (1 << (t-1)));
        }
    }
    return sol;
}

int main() {
    int n;
    cout << "Enter the number of elements: " << endl;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = minBitwiseArray(nums);

    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}