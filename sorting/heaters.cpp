// Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

// Every house can be warmed, as long as the house is within the heater's warm radius range. 

// Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

// Notice that all the heaters follow your radius standard, and the warm radius will be the same.

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int n = heaters.size();
        int j = 0;
        int curMax = INT_MIN;
        for (int house : houses) 
        {
            while (j < n-1 && abs(heaters[j+1]-house) <= abs(heaters[j] - house))
                j++;
            curMax = max(curMax, abs(house-heaters[j]));
        }
        return curMax;
    }
};