//Given a string s, find the length of the longest substring without duplicate characters.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;

        int i=0, j=0, ans=0;
        int n = s.size();

        while(i<n and j<n){
            if(set.find(s[j]) == set.end()) {
                set.insert(s[j++]);
                ans = max(ans, j-i);
            }
            else {
                set.erase(s[i++]);
            }
        }
        return ans;
    }

int main() {
    string s;
    cout << "Enter a string" << endl;
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << result;

    return 0;
}