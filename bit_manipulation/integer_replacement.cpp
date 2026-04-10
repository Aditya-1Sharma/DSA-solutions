// Given a positive integer n, you can apply one of the following operations:

// If n is even, replace n with n / 2.
// If n is odd, replace n with either n + 1 or n - 1.
// Return the minimum number of operations needed for n to become 1.


class Solution {
public:
    int integerReplacement(int n) {

        static std::unordered_map<long long, int> memo;
        auto recurse = [&](long long x, auto f) -> int {

            if (x <= 1) return 0;

            if(memo.count(x)) {
                return memo[x];
            }

            int ret = 0;
            if(x & 1) {
                int a = f(x+1, f) , b = f(x-1, f);
                ret = std::min(a,b);
            }
            else {
                ret = f(x/2, f);
            }

            ret++;
            memo[x] = ret;
            return ret;
        };

        return recurse(n, recurse);
    }
};