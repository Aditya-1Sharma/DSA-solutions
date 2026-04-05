// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// 1. "123"
// 2. "132"
// 3. "213"
// 4. "231"
// 5. "312"
// 6. "321"
// Given n and k, return the kth permutation sequence.


class Solution {
public:
    string getPermutation(int n, int k) {
        string kthPerm = "";
        int fact = 1;
        vector<int> list;
        
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            list.push_back(i);
        }
        list.push_back(n);
        
        k--;
        while (true) {
            kthPerm += to_string(list[k / fact]);
            list.erase(list.begin() + k / fact);
            if (list.size() == 0) break;
            k = k % fact;
            fact = fact / list.size();
        }
        return kthPerm;
    }
};