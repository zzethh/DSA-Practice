class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            int c = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j]) {
                    c++;
                }
                else c = 0;
                dp[i][j] = c;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = INT_MAX;
                for (int k = i; k < m; k++) {
                    x = min(x, dp[k][j]);
                    ans += x;
                }
            }
        }
        return ans;
    }
};