// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
        
        if(n < 0) {
            x = 1 / x;
        } 
        
        long num = labs(n);
        
        double pow = 1;
        
        while(num){ 
            if(num & 1) { 
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }

int main() {
    double x; 
    int n;
    cout << "Enter the number x : " ;
    cin >> x;
    cout << "Enter the power of x : ";
    cin >> n;

    double pow = myPow(x,n);
    cout << x << " raised to the power " << n << " = " << pow ;

    return 0;
}