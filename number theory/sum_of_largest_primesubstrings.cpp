// Given a string s, find the sum of the 3 largest unique prime numbers that can be formed using any of its substrings.

// Return the sum of the three largest unique prime numbers that can be formed. If fewer than three exist, 
// return the sum of all available primes. If no prime numbers can be formed, return 0.

// Note: Each prime number should be counted only once, even if it appears in multiple substrings. Additionally, 
// when converting a substring to an integer, any leading zeros are ignored.

class Solution {
public:
    using ll = long long;
    ll sumOfLargestPrimes(const string &s) {
        vector <ll> primes;
        for (ll i = 0; i < s.size(); i++) {
            ll temp = 0;
            for (ll j = i; j < s.size(); j++) {
                temp = temp * 10 + (s[j] - '0');
                if (isPrime(temp)) {
                    primes.emplace_back(temp);
                }
            }
        }

        sort(primes.begin(), primes.end());
        primes.erase(unique(primes.begin(), primes.end()), primes.end());
        ll m = primes.size();
        if (m < 3) 
            return accumulate(primes.begin(), primes.end(),0ll);
        return primes[m - 1] + primes[m - 2] + primes[m - 3];
}

    bool isPrime(ll n) {
        if (n < 2) return false; 
        for (ll i = 2; i*i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }
};