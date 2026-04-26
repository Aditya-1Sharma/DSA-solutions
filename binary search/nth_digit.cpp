// Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].


class Solution {
public:
    int findNthDigit(int n) {
        long long digitCount = 9, start = 1, length = 1;
        while (n > digitCount * length) {
            n -= digitCount * length;
            start *= 10;
            digitCount *= 10;
            length++;
        }
        start += (n - 1) / length;
        string s = to_string(start);
        return s[(n - 1) % length] - '0';
    }
};