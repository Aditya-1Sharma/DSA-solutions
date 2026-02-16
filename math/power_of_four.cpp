// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4^x.

class Solution{    
    public:    
        bool isPowerOfFour(int n){            
            if(n <= 0){                
                return false;                
            }            
            bool pow = true;            
            while((n > 1) && (pow == true)){                
                n % 4 == 0 ? n = n / 4 : pow = false;                
            }            
            return pow;
        }    
};