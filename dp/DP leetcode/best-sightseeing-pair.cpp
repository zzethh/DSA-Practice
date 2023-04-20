class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, 0);
        vector<int> dp1(n, 0);
        dp[0] = v[0];
        dp1[0] = v[0];
        for (int i = 1; i < v.size(); i++) {
            dp[i] = max(dp[i - 1], v[i] + i);
        }
        for (int i = 1; i < n; i++) {
            dp1[i] = v[i] - i;
        }

        int maxi = INT_MIN;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, dp1[i] + dp[i - 1]);
        }
        return maxi;
    }
};