// Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size(),Min=1001,Max=0;
        for(int i=0;i<n;i++){
            Min=min(Min,nums[i]);
            Max=max(Max,nums[i]);
        }
        while(Min!=0 && Max!=0){
            if(Max>Min) Max=Max%Min;
            else if(Min>Max) Min=Min%Max;
            else if(Max==Min) return Max;
        }
        if(Min==0) return Max;
        return Min;
    }
};