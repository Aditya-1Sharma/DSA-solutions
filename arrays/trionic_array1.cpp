// You are given an integer array nums of length n.

// An array is trionic if there exist indices 0 < p < q < n − 1 such that:

// nums[0...p] is strictly increasing,
// nums[p...q] is strictly decreasing,
// nums[q...n − 1] is strictly increasing.
// Return true if nums is trionic, otherwise return false.

#include <bits/stdc++.h>
using namespace std;

bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;

        int i = 0;
        while (i < n-1 and nums[i] < nums[i + 1]) {
            i = i + 1;
        }
        
        int peak;
        peak = i;
        if (peak == 0 or peak >= n-2) return false;

        while (i < n-1 and nums[i] > nums[i + 1]) {
            i = i + 1;
        }

        int valley;
        valley = i;
        if (valley == peak or valley >= n-1) return false;

        while (i < n-1 and nums[i] < nums[i+1]) {
            i = i + 1;
        }
        return i == n-1;
        
}

int main() {
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    bool result = isTrionic(nums);
    cout << result << endl;

    return 0;
}