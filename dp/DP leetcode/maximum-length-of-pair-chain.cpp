class Solution {
public:

    int helper(vector<vector<int>> &pairs, int i, vector<vector<int>> &dp, int prev) {
        if (i >= pairs.size()) {
            return 0;
        }

        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];


        int len = helper(pairs, i + 1, dp, prev);

        if (prev == -1 or pairs[prev][1] < pairs[i][0]) {
            len = max(len, 1 + helper(pairs, i + 1, dp, i));
        }

        return dp[i][prev + 1] = len;
    }

    int bottomUp(vector<vector<int>> arr) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[j][1] < arr[i][0]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(pairs.size(), vector<int>(pairs.size() + 1, -1));
        return helper(pairs, 0, dp, -1);
        //return bottomUp(pairs);
    }
};