// Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence
// (i.e. subarray). The subsequence must be strictly increasing.

// A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is 
// [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l=0;
        int r=1;
        int maxlen=1;
        while(r<nums.size())
        {
            if(nums[r]>nums[r-1]) 
            {
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            else
            {
                l=r;
                r++;
            }
        }
        return maxlen;
    }
};