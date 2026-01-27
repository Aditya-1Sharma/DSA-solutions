// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
        int count = 0;
        int res = 0;

        for (const int& num: nums) {
            if (count == 0) {
                res = num;
            } 
            count += (num == res) ? 1 : -1;
        }

        return res;
    }
    
int main() {
    int n;
    cout << "Enter the number of elements of the array : ";
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    } 
    
    int MajorityElement = majorityElement(nums);
    cout << "Majority Element = " << MajorityElement << endl;

    return 0;
}