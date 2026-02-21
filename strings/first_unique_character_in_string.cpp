// Given a string s, find the first non-repeating character in it and return its index.
// If it does not exist, return -1.


class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> occur(26,0);

        for(int i =0 ; i< n; i++){
            int cnv = s[i] - 'a';
            occur[cnv]++;
        }
        for(int i =0 ;i <n ;i++){
            if(occur[s[i] - 'a'] == 1 ){
                return i;
            }
        }
        return -1;
    }
}; 