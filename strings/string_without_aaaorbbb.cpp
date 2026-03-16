// Given two integers a and b, return any string s such that:

// s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
// The substring 'aaa' does not occur in s, and
// The substring 'bbb' does not occur in s.

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        int n=a+b;
        int x=0, y=0;
        for(int i=0;i<n;i++)
        {
            if((a>=b && x!=2) || (y==2 && a>0))
            {
                x++;a--;y=0;
                ans+='a';
            }
            else if((b>=a && y!=2) || (x==2 && b>0))
            {
                y++;b--;x=0;
                ans+='b';
            }
        }
        return ans;
    }
};