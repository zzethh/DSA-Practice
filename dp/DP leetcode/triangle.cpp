class Solution {
public:
    int helper(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp) {
        if (i == arr.size()) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int left = INT_MAX;
        int right = INT_MAX;
        if (j < arr[i].size()) left = arr[i][j] + helper(arr, i + 1, j, dp);
        if (j + 1 < arr[i].size()) right = arr[i][j + 1] + helper(arr, i + 1, j + 1, dp);
        return dp[i][j] = min(left, right);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri[tri.size() - 1].size();
        vector<vector<int>> dp(tri.size() + 1, vector<int>(n + 1, -1));
        return helper(tri, 0, 0, dp);
    }
};