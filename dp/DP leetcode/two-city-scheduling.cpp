class Solution {
public:
    int helper(vector<vector<int>>& costs, int a, int b, int i, vector<vector<int>> &dp) {
        if (i == costs.size()) {
            return 0;
        }
        // if(a>costs.size()/2 and b>costs.size()/2){
        //     return 0;
        // }

        if (dp[a][b] != -1) return dp[a][b];

        int inc = INT_MAX;
        int exc = INT_MAX;
        if (a > 0) {
            inc = costs[i][0] + helper(costs, a - 1, b, i + 1, dp);
        }

        if (b > 0) {
            exc = costs[i][1] + helper(costs, a, b - 1, i + 1, dp);
        }
        return dp[a][b] = min(inc, exc);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int a = costs.size() / 2;
        int b = costs.size() / 2;
        int i = 0;
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        // int sum=0;
        return helper(costs, a, b, i, dp);
    }
};