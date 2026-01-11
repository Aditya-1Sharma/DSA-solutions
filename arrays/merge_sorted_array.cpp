// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
// representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a 
// length of m + n, where the first m elements denote the elements that should be merged, 
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int midx = m - 1;
        int nidx = n - 1;
        int right = m + n - 1;

        while (nidx >= 0) {
            if (midx >= 0 && nums1[midx] > nums2[nidx]) {
                nums1[right] = nums1[midx];
                midx--;
            } else {
                nums1[right] = nums2[nidx];
                nidx--;
            }
            right--;
        }        
    }

void printVector(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
}

int main() {
    // Example 1
    vector<int> nums1_1 = {1,2,3,0,0,0};
    int m1 = 3;
    vector<int> nums2_1 = {2,5,6};
    int n1 = 3;
    cout << "Example 1:" << endl;
    cout << "Input: nums1 = "; printVector(nums1_1); cout << ", m = " << m1;
    cout << ", nums2 = "; printVector(nums2_1); cout << ", n = " << n1 << endl;
    merge(nums1_1, m1, nums2_1, n1);
    cout << "Output: "; printVector(nums1_1); cout << endl << endl;

    // Example 2
    vector<int> nums1_2 = {1};
    int m2 = 1;
    vector<int> nums2_2 = {};
    int n2 = 0;
    cout << "Example 2:" << endl;
    cout << "Input: nums1 = "; printVector(nums1_2); cout << ", m = " << m2;
    cout << ", nums2 = "; printVector(nums2_2); cout << ", n = " << n2 << endl;
    merge(nums1_2, m2, nums2_2, n2);
    cout << "Output: "; printVector(nums1_2); cout << endl << endl;

    // Example 3
    vector<int> nums1_3 = {0};
    int m3 = 0;
    vector<int> nums2_3 = {1};
    int n3 = 1;
    cout << "Example 3:" << endl;
    cout << "Input: nums1 = "; printVector(nums1_3); cout << ", m = " << m3;
    cout << ", nums2 = "; printVector(nums2_3); cout << ", n = " << n3 << endl;
    merge(nums1_3, m3, nums2_3, n3);
    cout << "Output: "; printVector(nums1_3); cout << endl << endl;

    return 0;
}