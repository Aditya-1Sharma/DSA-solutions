// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#'; 
        
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);
        
        board[i][j] = temp; 
        return found;
    }
};