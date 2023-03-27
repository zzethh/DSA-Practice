class Solution {
public:
    int helper(int n, unordered_map<int, int> &dp) {
        if (n == 1) {
            return 0;
        }
        if (dp.count(n)) return dp[n];
        if (n % 2 == 0) {
            return dp[n] = 1 + helper(n / 2, dp);
        }
        else {
            return dp[n] = 1 + helper(3 * n + 1, dp);
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<vector<int>> ans;
        unordered_map<int, int> m;
        for (int i = lo; i <= hi; i++) {
            ans.push_back({helper(i, m), i});
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1][1];
    }
};