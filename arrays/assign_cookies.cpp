// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. 
// If s[j] >= g[i], we can assign the cookie j to the child i, 
// and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0;
    int j = 0;
    int count = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return count;
}

int main() {
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << "Test 1: " << findContentChildren(g1, s1) << endl;

    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << "Test 2: " << findContentChildren(g2, s2) << endl;

    vector<int> g3 = {10, 9, 8, 7};
    vector<int> s3 = {5, 6, 7, 8};
    cout << "Test 3: " << findContentChildren(g3, s3) << endl;

    vector<int> g4 = {1, 2, 3};
    vector<int> s4 = {};
    cout << "Test 4: " << findContentChildren(g4, s4) << endl;

    return 0;
}