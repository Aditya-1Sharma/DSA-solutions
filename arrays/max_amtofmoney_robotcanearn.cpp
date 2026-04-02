// You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). 
// The robot can move either right or down at any point in time.

// The grid contains a value coins[i][j] in each cell:

// If coins[i][j] >= 0, the robot gains that many coins.
// If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
// The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

// Note: The robot's total coins can be negative.

// Return the maximum profit the robot can gain on the route.


class Solution {
public:
    int maximumAmount(vector<vector<int>>& g) {
        int dp[500][3];
        const int w = g[0].size();
        constexpr int kBad = -1000 * 500 * 500;

        fill_n(dp[0], 3 * w, kBad);
        fill_n(dp[0], 3, 0);

        for (auto& r: g) {
            int l[]{kBad, kBad, kBad, kBad};
            for (int x = 0; x != w; ++x) {
                int t[]{kBad, dp[x][0], dp[x][1], dp[x][2]};
                int a = r[x], b = max(a, 0);
                for (int i = 0; i != 3; ++i) {
                    dp[x][i] = max(max(a + l[i + 1], b + l[i]),
                                   max(a + t[i + 1], b + t[i]));
                }
                copy_n(dp[x], 3, l + 1);
            }
        }

        return dp[w - 1][2];
    }
};