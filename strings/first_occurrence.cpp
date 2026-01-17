//Find the Index of the First Occurrence in a String

//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
         int n1 = haystack.size();
         int n2 = needle.size();
         if(n2>n1) return -1;
         for(int i=0; i<n1-n2+1; i++){
            if (haystack.substr(i,n2)==needle) return i;
         }
         return -1;
    }

int main() {
    string haystack,needle;
    cout << "Haystack : ";
    cin >> haystack ;
    
    cout << "Needle : ";
    cin >> needle ;

    int result = strStr(haystack,needle);
    cout << "Index of the first occurrence of needle in haystack is : " << result << endl;
}