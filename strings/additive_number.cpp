// An additive number is a string whose digits can form an additive sequence.

// A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

// Given a string containing only digits, return true if it is an additive number or false otherwise.

// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.


class Solution {
public:
    bool func(string num1, string num2, string rem){
        if(rem.length() < max(num1.length(), num2.length()))
            return false;
        if(num1[0] == '0' && num1.length() > 1)
            return false;
        if(num2[0] == '0' && num2.length() > 1)
            return false;
        long long a = stol(num1), b = stol(num2);
        long long res = a + b;
        string ans = to_string(res);
        if(ans == rem) return true;
        if(ans.length() > rem.length()) return false;
        int n = ans.length();
        if(ans == rem.substr(0, n)){
            if(n == rem.length()){
                return true;
            }
            a = b;
            b = res;
            rem = rem.substr(n, rem.length() - n);
            return func(to_string(a), to_string(b), rem);
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        int n = num.length();
        if(n <= 2) return false;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                string num1 = num.substr(0, i + 1);
                string num2 = num.substr(i + 1, j - i);
                string rem = num.substr(j + 1, n - j);
                //cout << num1 << " "<< num2 <<" "<< rem << endl;
                if(func(num1, num2, rem))
                    return true;
            }
        }
        return false;
    }
};