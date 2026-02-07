// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> nums) {
        vector<int> arr(nums.size());
        int i = 0;
        int j = nums.size()-1;
        for(int n : nums){
            if(n%2 == 0){
                arr[i] = n;
                i++;
            }
            else{
                arr[j] = n;
                j--;
            }

        }
        return arr;
    }
};
