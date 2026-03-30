// Given an integer n, return the smallest prime palindrome greater than or equal to n.

// An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

// For example, 2, 3, 5, 7, 11, and 13 are all primes.
// An integer is a palindrome if it reads the same from left to right as it does from right to left.

// For example, 101 and 12321 are palindromes.
// The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

class Solution {
public:
    bool isprime(int n) {
        if(n==0 || n==1) return false;
        for(int i =2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(n>=8 && n<=11) return 11;
        for(int i =1;i<=100000;i++)
        {
            string s = to_string(i); 
            string r =s; 
            reverse(r.begin(),r.end()); 
            int y = stoi(s+r.substr(1)); 
            if(y>=n && isprime(y)) return y; 
        }
        return 0;
    }
};