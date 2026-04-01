// You are given three integers l, r, and k.

// Consider all possible integers consisting of exactly k digits, 
// where each digit is chosen independently from the integer range [l, r] (inclusive). If 0 is included in the range, leading zeros are allowed.

// Return an integer representing the sum of all such numbers.​​​​​​​ 
// Since the answer may be very large, return it modulo 109 + 7.

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modExp(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInv(long long x) {
        return modExp(x, MOD - 2);
    }

    int sumOfNumbers(int l, int r, int k) {
        long long cnt = r - l + 1;

        long long S = 0;
        for (int d = l; d <= r; d++) S += d;

        long long part1 = modExp(cnt, k - 1);

        long long part2 = (modExp(10, k) - 1 + MOD) % MOD;
        part2 = (part2 * modInv(9)) % MOD;

        long long ans = (S % MOD) * part1 % MOD;
        ans = ans * part2 % MOD;

        return ans;
    }
};