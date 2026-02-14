// You are given an integer array nums where the largest integer is unique.

// Determine whether the largest element in the array is at least twice as much as every other number in the array. 
// If it is, return the index of the largest element, or return -1 otherwise.

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first_maximum=nums[0];
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>first_maximum)
            {
                first_maximum=nums[i];
                ans=i;
            }
        }
        nums[ans]=0;
        int second_maximum=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>second_maximum)
            {
                second_maximum=nums[i];
            }
        }
        if(first_maximum>=second_maximum*2)
        {
            return ans;
        }
        return -1;
    }
};