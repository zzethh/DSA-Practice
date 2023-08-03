class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxi = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 or j == 0) {
                    if (mat[i][j] == '1') {
                        dp[i][j] = 1;
                    }
                }
                else {
                    if (mat[i][j] == '1') {
                        dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    }
                }
                maxi = max(dp[i][j], maxi);
            }
        }
        return maxi * maxi;

    }
};