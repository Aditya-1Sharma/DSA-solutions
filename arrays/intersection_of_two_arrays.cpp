// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must be unique and you may return the result in any order.

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                if(result.empty() || result.back() != nums1[i]){
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }

void printVector(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", "; // Add space after comma for better readability
        }
    }
    cout << "]";
}

int main () {
    int n1, n2;
    cout << "Enter the number of elements in nums1 and nums2 : " << endl;
    cin >> n1 >> n2;

    vector<int> nums1(n1);
    cout << "Enter " << n1 << " integers : ";
    for(int i=0; i<n1; i++){
        cin >> nums1[i];
    }

    vector<int> nums2(n2);
    cout << "Enter " << n2 << " integers : ";
    for(int j=0; j<n2; j++){
        cin >> nums2[j];
    }
    
    vector<int> result = intersection(nums1,nums2);
    cout << "Intersection of the two arrays : " ;
    printVector(result);
    cout << endl;

    return 0;
 }