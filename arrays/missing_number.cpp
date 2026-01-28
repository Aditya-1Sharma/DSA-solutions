// Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;
        for(int i = 0; i < n; i++){
            result ^= i ^ nums[i];
        }
        return result;
    }
    
int main() {
    int n;
    cout << "Enter number of elements of the array : ";
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    } 
    
    int MissingNumber = missingNumber(nums);
    cout << "Missing Number = " << MissingNumber << endl;
    
    return 0;
}