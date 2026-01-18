// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0; 
        int high = (n*m) - 1;

        while (low <= high) {
            int mid = (low + (high-low)/2);
            if(matrix[mid / m][mid % m] == target) return true;
 
            if(matrix[mid / m][mid % m] < target) low = mid + 1;

            else high = mid - 1;
        }
        return false;
    }

int main() {
    
    int m,n;
    cout << "Enter the number of rows : ";
    cin >> m;
    cout << "Enter the number of columns : ";
    cin >> n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    
    int target;
    cout << "Enter the integer you want to search : ";
    cin >> target;
    
    bool result = searchMatrix(matrix,target);
    cout << result;
    
}