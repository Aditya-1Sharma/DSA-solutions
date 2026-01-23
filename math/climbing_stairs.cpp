// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
        std::vector<int> cs(n + 1);
        cs[0] = 1;
        cs[1] = 1;

        for(int i = 2; i <= n; i++){
            cs[i] = cs[i - 1] + cs[i - 2];
        }

        return cs[n];
    }
};