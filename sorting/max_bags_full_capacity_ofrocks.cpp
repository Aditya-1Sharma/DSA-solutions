// You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. 
// The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. 
// You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.

// Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> vv ; 
         for(int i = 0 ; i < capacity.size(); i ++ ) {
              vv.push_back(capacity[i] - rocks[i]); 
         }
         sort(vv.begin(), vv.end()); 
         int  cnt = 0 ; 
         for(auto a : vv ) {
              if(a == 0) {
                   cnt ++ ; 
              }else if(additionalRocks - a >= 0){
                  cnt ++; 
                  additionalRocks -= a ; 
              }
         }
        return cnt ;
    }
};