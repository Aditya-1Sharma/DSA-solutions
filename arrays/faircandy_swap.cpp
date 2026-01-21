// Alice and Bob have a different total number of candies. You are given two integer arrays aliceSizes 
// and bobSizes where aliceSizes[i] is the number of candies of the ith box of candy that Alice has and 
// bobSizes[j] is the number of candies of the jth box of candy that Bob has.

// Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy. 
// The total amount of candy a person has is the sum of the number of candies in each box they have.

// Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, 
// and answer[1] is the number of candies in the box that Bob must exchange. If there are multiple answers, you may return any one of them. 
// It is guaranteed that at least one answer exists.

#include <bits/stdc++.h>
using namespace std;

vector<int> fairCandySwap(vector<int>& alice, vector<int>& bob) {
        vector<int> ans(2,0);
        int asum = 0 , bsum = 0;
        for(auto x : alice)
        asum += x;
        for(auto x : bob)
        bsum += x;

        sort(alice.begin(),alice.end());
        sort(bob.begin(),bob.end());

        for(auto x : alice){
            int l = 0 , r = bob.size()-1 , mid;
            while(l<=r){
                mid = (l+r)/2;
                if(asum-x+bob[mid] == bsum-bob[mid]+x){
                    ans[0] = x;
                    ans[1] = bob[mid];
                    return ans;
                }else if(asum-x+bob[mid] > bsum-bob[mid]+x){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            } 
        }
        return ans;
    }

int main() {
    // Test Case 1
    vector<int> alice1 = {1, 1};
    vector<int> bob1 = {2, 2};
    
    cout << "Test Case 1:" << endl;
    cout << "Alice: "; printVector(alice1);
    cout << " Bob: "; printVector(bob1);
    cout << endl;
    
    vector<int> result1 = fairCandySwap(alice1, bob1);
    cout << "Swap (Alice, Bob): "; printVector(result1);
    cout << "\n--------------------------------\n";

    // Test Case 2
    vector<int> alice2 = {1, 2};
    vector<int> bob2 = {2, 3};

    cout << "Test Case 2:" << endl;
    cout << "Alice: "; printVector(alice2);
    cout << " Bob: "; printVector(bob2);
    cout << endl;

    vector<int> result2 = fairCandySwap(alice2, bob2);
    cout << "Swap (Alice, Bob): "; printVector(result2);
    cout << "\n--------------------------------\n";

    // Test Case 3 (Alice has larger sum initially)
    vector<int> alice3 = {2};
    vector<int> bob3 = {1, 3};

    cout << "Test Case 3:" << endl;
    cout << "Alice: "; printVector(alice3);
    cout << " Bob: "; printVector(bob3);
    cout << endl;

    vector<int> result3 = fairCandySwap(alice3, bob3);
    cout << "Swap (Alice, Bob): "; printVector(result3);
    cout << endl;

    return 0;
}