// An n-bit gray code sequence is a sequence of 2n integers where:

// Every integer is in the inclusive range [0, 2n - 1],
// The first integer is 0,
// An integer appears no more than once in the sequence,
// The binary representation of every pair of adjacent integers differs by exactly one bit, and
// The binary representation of the first and last integers differs by exactly one bit.
// Given an integer n, return any valid n-bit gray code sequence.


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int totalNumbers = 1 << n; // Total numbers in the gray code sequence is 2^n
        
        for (int i = 0; i < totalNumbers; ++i) {
            // The formula to generate the i-th gray code number is: i ^ (i >> 1)
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};