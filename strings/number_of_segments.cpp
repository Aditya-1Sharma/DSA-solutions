// Given a string s, return the number of segments in the string.

// A segment is defined to be a contiguous sequence of non-space characters.

class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        for(int i = 0; i<s.size(); i++) {
            if((i == 0 or s.at(i - 1) == ' ') and s.at(i) != ' '){
                segments++;
            }
        }
        return segments;
    }
};