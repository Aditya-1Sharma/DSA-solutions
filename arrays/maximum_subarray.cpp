// Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            curr = max(curr + nums[i], nums[i]);
            result = max(result, curr);
        }
        
        return result;
    }

int main() {
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxSubArray(nums);
    cout << "Maximum subarray sum = " << result << endl;

    return 0;
}