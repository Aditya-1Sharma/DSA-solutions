// Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:

// 0 <= i < j <= n - 1 and
// nums[i] * nums[j] is divisible by k.

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;

        unordered_map<int, long long> freq;
        for (int i = 0; i < n; i++) {
            int g = __gcd(nums[i], k);
            freq[g]++;
        }

        vector<int> divisors;
        for (auto& [key, val] : freq) {
            divisors.push_back(key);
        }

        int m = divisors.size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                if ((long long)divisors[i] * divisors[j] % k == 0) {
                    if (i == j) {
                        count += freq[divisors[i]] * (freq[divisors[i]] - 1) / 2;
                    } else {
                        count += freq[divisors[i]] * freq[divisors[j]];
                    }
                }
            }
        }
        return count;
    }
};