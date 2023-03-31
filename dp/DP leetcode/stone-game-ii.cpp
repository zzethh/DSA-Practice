class Solution {
public:
    int helper(vector<int>& s, int i, int m, vector<vector<int>> &dp) {
        if (i >= s.size()) return 0;
        if (dp[i][m] != -1) return dp[i][m];
        int ans = INT_MIN;
        int total = 0;
        int n = s.size();
        for (int idx = 0; idx < 2 * m; idx++) {
            if (idx + i < s.size())total += s[i + idx];
            ans = max(ans, total - helper(s, idx + i + 1, max(m, idx + 1), dp));
        }
        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size() * 2, -1));
        int diff = helper(piles, 0, 1, dp);
        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += piles[i];
        }
        return (sum + diff) / 2;
    }
};