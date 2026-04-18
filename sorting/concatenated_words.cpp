// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Sort words by length: shorter words can't be made of longer words
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        unordered_set<string> dict;
        vector<string> result;

        for (const string& word : words) {
            if (canForm(word, dict)) {
                result.push_back(word);
            }
            // Only add to dict AFTER checking, 
            // so a word can only be formed by shorter words
            dict.insert(word); 
        }

        return result;
    }

private:
    bool canForm(const string& word, const unordered_set<string>& dict) {
        if (dict.empty()) return false;
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};