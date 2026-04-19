// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters 
// (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). 
// For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". 
// Thus the compressed string becomes "23321511".

// Given a positive integer n, return the nth element of the count-and-say sequence.


class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string result;
        int count = 1;

        for (size_t i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) {
                count++;
            } else {
                result += to_string(count) + prev[i - 1];
                count = 1;
            }
        }
        // Append the last counted group
        result += to_string(count) + prev.back();

        return result;
    }
};