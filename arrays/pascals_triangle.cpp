// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    for(int i = 0; i < numRows; i++){
        vector<int> row(i+1, 1);

        for(int j = 1; j < i; j++){
            row[j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
        pascal.push_back(row);
    }
    return pascal;
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    
    vector<vector<int>> result = generate(n);

    cout << "Pascal's Triangle:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}