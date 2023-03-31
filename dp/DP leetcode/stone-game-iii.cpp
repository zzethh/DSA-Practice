class Solution {
public:
    int helper(vector<int>& s, int i, vector<int> &dp) {
        if (i >= s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        int total = 0;
        int n = s.size();
        for (int idx = i; idx < min(i + 3, n); idx++) {
            total += s[idx];
            ans = max(ans, total - helper(s, idx + 1, dp));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), -1);
        int alice = helper(stoneValue, 0, dp);
        if (alice > 0) return "Alice";
        if (alice == 0) return "Tie";
        return "Bob";
    }
};