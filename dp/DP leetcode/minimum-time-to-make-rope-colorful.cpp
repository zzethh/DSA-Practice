class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int s = 0;
        int e = 0;
        int n = colors.length();
        int t = 0;
        while (s < n and e < n) {
            int tot = 0;
            int maxi = INT_MIN;
            while (e < n and colors[e] == colors[s]) {
                maxi = max(maxi, neededTime[e]);
                tot += neededTime[e];
                e++;
            }
            t += tot - maxi;
            s = e;
        }

        return t;
    }
};