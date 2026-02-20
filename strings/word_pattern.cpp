// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<int> pat_map (26, 0);
        unordered_map<string,int> str_map;
        int i=0, n = pattern.size();
        istringstream ss (str);
        string token;
        
        for(string token; ss >> token; ++i) {
            if(i == n || pat_map[pattern[i]-'a'] != str_map[token]) return false;
            
            pat_map[pattern[i]-'a'] = str_map[token] = i+1;
        }
        
        return i == n;
    }
};
