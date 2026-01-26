// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> res;

        for(int i=1; i < arr.size(); i++){
            int diff = arr[i] - arr[i - 1];
            if(diff < minDiff) {
                minDiff = diff;
                res = {};
                res.push_back({arr[i - 1], arr[i]});
            }
            else if(diff == minDiff) res.push_back({arr[i-1], arr[i]});
        }
        return res;
    }
    
int main() {
    int n;
    cout << "Enter the number of elements in array : ";
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<vector<int>> result = minimumAbsDifference(arr);
    
    cout << "Pairs with minimum absolute difference:" << endl;
    for(const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;

}