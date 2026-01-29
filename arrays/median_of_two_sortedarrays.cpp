// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int total = m + n;
        
        int low = 0;
        int high = m;
        
        double result = 0.0;
        
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (total + 1) / 2 - i;
            
            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < m) ? nums1[i] : INT_MAX;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < n) ? nums2[j] : INT_MAX;
            
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0) {
                    result = (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    result = max(left1, left2);
                }
                break;
            } else if (left1 > right2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        
        return result;
    }

int main() {
    int m, n;
    
    cout << "Enter size of first sorted array: ";
    cin >> m;
    
    vector<int> nums1(m);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    
    cout << "Enter size of second sorted array: ";
    cin >> n;
    
    vector<int> nums2(n);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    
    double median = findMedianSortedArrays(nums1, nums2);
    cout << fixed << setprecision(2);
    cout << "Median: " << median << endl;
    
   return 0;  
}