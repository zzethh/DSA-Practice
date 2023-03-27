class Solution {
public:
    int helper(vector<vector<int>> &m, int i, int j, int sum, vector<vector<int>> &dp) {
        if (dp[i][j] != -1) return dp[i][j];

        if (i >= m.size()) {
            return 0;
        }
        // if(j>=m[0].size() or j<0) return INT_MAX-900;

        int a = m[i][j] + helper(m, i + 1, j, sum, dp);
        int b = INT_MAX;
        int c = INT_MAX;
        if (j - 1 >= 0) b = m[i][j] + helper(m, i + 1, j - 1, sum, dp);
        if (j + 1 < m[0].size()) c = m[i][j] + helper(m, i + 1, j + 1, sum, dp);

        return dp[i][j] = min(a, min(b, c));
    }

    int helper2(vector<vector<int>> &m) {
        vector<vector<int>> dp(m.size(), vector<int>(m[0].size(), 0));
        for (int i = 0; i < m[0].size(); i++) {
            dp[m.size() - 1][i] = m[m.size() - 1][i];
        }
        for (int i = m.size() - 2; i >= 0; i--) {
            for (int j = 0; j < m[0].size(); j++) {
                int a = m[i][j] + dp[i + 1][j];
                int b = INT_MAX;
                int c = INT_MAX;
                if (j - 1 >= 0) b = m[i][j] + dp[i + 1][j - 1];
                if (j + 1 < m[0].size()) c = m[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(a, min(b, c));
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m[0].size(); i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        // int ans=INT_MAX;
        // for(int i=0;i<matrix[0].size();i++){
        //    ans=min(ans,helper(matrix,0,i,0,dp));
        // }
        return helper2(matrix);
    }
};