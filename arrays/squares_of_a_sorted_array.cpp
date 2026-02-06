// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int& i : nums)
            i *= i;
        sort(nums.begin(), nums.end());
        return nums;
    }
};