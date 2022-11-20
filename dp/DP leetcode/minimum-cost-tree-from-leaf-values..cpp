class Solution {
public:
    int helper(vector<int> arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp) {
        if (left == right) {
            return 0;
        }

        if (dp[left][right] != -1) return dp[left][right];

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[ {left, i}]*maxi[ {i + 1, right}] + helper(arr, maxi, left, i, dp) + helper(arr, maxi, i + 1, right, dp));
        }

        return dp[left][right] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < arr.size(); i++) {
            maxi[ {i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                maxi[ {i, j}] = max(arr[j], maxi[ {i, j - 1}]);
            }
        }

        return helper(arr, maxi, 0, arr.size() - 1, dp);
    }
};