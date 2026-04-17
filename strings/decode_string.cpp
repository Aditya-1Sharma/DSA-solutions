// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
// Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. 
// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.


class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string currentStr;
        int currentNum = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currentNum);
                strStack.push(currentStr);
                currentNum = 0;
                currentStr.clear();
            } else if (c == ']') {
                string temp = currentStr;
                int repeatTimes = numStack.top();
                numStack.pop();
                for (int i = 1; i < repeatTimes; ++i) {
                    currentStr += temp;
                }
                currentStr = strStack.top() + currentStr;
                strStack.pop();
            } else {
                currentStr += c;
            }
        }
        
        return currentStr;
    }
};