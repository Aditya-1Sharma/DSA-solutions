// You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

// Return the number of consistent strings in the array words.


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>present(26,0);
        int count=0;
        for(auto it:allowed){
            present[it-'a']=1;
        }
        for(auto it:words){
            string s=it;
            bool flag=true;
            for(auto a:s){
                if(present[a-'a']!=1){
                    flag=false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};