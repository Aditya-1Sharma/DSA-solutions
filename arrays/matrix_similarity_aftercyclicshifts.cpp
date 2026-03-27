// You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.

// The following proccess happens k times:

// Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.


// Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.


// Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        int effectiveShift = k % n;
        
        if (effectiveShift == 0) {
            return true;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newJ;
                
                if (i % 2 == 0) {
                    newJ = (j + effectiveShift) % n;
                } else {
                    newJ = (j - effectiveShift + n) % n;
                }
                
                if (mat[i][newJ] != mat[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};