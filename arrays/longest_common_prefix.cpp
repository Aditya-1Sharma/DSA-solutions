// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        string x = "";
        sort(strs.begin(), strs.end());

        for (int i = 0; i < strs[0].size(); i++) {
            char temp = strs[0][i];
            bool check = false;

            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] == temp) {
                    check = true;
                } 
                else {
                    check = false;
                    break;
                }
            }

            if (check) {
                x += temp;
            } 
            else {
                break;
            }
        }
        return x;
    }
