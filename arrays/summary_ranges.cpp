// You are given a sorted unique integer array nums.

// A range [a,b] is the set of all integers from a to b (inclusive).

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        std::vector<std::string> ranges;
        int start = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    ranges.push_back(std::to_string(start));
                } else {
                    ranges.push_back(std::to_string(start) + "->" + std::to_string(nums[i - 1]));
                }
                start = nums[i];
            }
        }

        // Handle the last range
        if (start == nums.back()) {
            ranges.push_back(std::to_string(start));
        } else {
            ranges.push_back(std::to_string(start) + "->" + std::to_string(nums.back()));
        }

        return ranges;
    }
};