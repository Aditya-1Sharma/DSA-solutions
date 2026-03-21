// Given an array of integers arr, sort the array by performing a series of pancake flips.

// In one pancake flip we do the following steps:

// Choose an integer k where 1 <= k <= arr.length.
// Reverse the sub-array arr[0...k-1] (0-indexed).
// For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.

// Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size(),max;
        vector<int>res;
        std::vector<int>::iterator itr=arr.begin();
        while(n>0)
        {
            max=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]>arr[max])
                    max=i;
            }
            int target=arr[max],pos=max;
            while(arr[n-1]!=target)
            {
                res.push_back(pos+1);
                reverse(itr,itr+pos+1);
                pos=0;
                res.push_back(n);
                reverse(itr,itr+n);
            }
            n--;
        }
        return res;
    }
};