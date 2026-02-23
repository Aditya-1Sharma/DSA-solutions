// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right-left)/2;

            if(mid > 0 && nums[mid] < nums[mid-1]) {
                right = mid - 1;
            }
            else if(mid < n-1 && nums[mid] < nums[mid+1]) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};