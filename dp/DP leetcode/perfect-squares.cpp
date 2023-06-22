class Solution {
public:
    int helper(int n, vector<int> &v, vector<int>&dp) {
        if (n == 0) return 0;
        if (n < 0) return INT_MAX - 1;
        if (dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for (int i = 0; i < v.size(); i++) {
            ans = min(ans, 1 + helper(n - v[i], v, dp));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            int temp = sqrt(i);
            double temp2 = sqrt(i);
            if (temp2 - temp != 0) {
                continue;
            }
            else {
                cout << i << " ";
                v.push_back(i);
            }
        }
        vector<int> dp(n + 1, -1);
        return helper(n, v, dp);
    }
};