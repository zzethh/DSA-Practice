class Solution {
public:
    int helper(vector<int> &days, vector<int> &costs, int index, vector<int> &dp) {
        if (index >= days.size()) {
            return 0;
        }
        if (dp[index] != -1) return dp[index];

        int a = costs[0] + helper(days, costs, index + 1, dp);

        int idx = lower_bound(days.begin(), days.end(), days[index] + 7) - days.begin();
        int b = costs[1] + helper(days, costs, idx, dp);

        int idx2 = lower_bound(days.begin(), days.end(), days[index] + 30) - days.begin();
        int c = costs[2] + helper(days, costs, idx2, dp);

        dp[index] = min(a, min(b, c));
        return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);
        return helper(days, costs, 0, dp);
    }
};