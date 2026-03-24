// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

class Solution {
public:
    static bool mysort(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        string s = "";
        vector<string> all_numbers;
        
        for(int it: nums){
            all_numbers.push_back(to_string(it));
        }

        sort(all_numbers.begin(),all_numbers.end(),mysort);
        if(all_numbers[0]=="0"){
            return "0";
        }
        
        for(string a: all_numbers){
            s += a;
        }
        return s;
    }
};