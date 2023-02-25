class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 or n < 3) return 0;
        vector<vector<long>> pref(m, vector<long>(n));
        pref[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            pref[0][i] = grid[0][i] + pref[0][i - 1];
        }
        for (int i = 1; i < m; i++) {
            pref[i][0] = pref[i - 1][0] + grid[i][0];
            for (int j = 1; j < n; j++) {
                pref[i][j] = grid[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        long maxi = INT_MIN;
        for (int i = 2; i < m; i++) {
            for (int j = 2; j < n; j++) {
                long hour = pref[i][j] - grid[i - 1][j] - grid[i - 1][j - 2];
                if (i > 2) {
                    hour -= pref[i - 3][j];
                    if (j > 2) {
                        hour -= pref[i][j - 3];
                        hour += pref[i - 3][j - 3];
                    }
                }
                else {
                    if (j > 2) {
                        hour -= pref[i][j - 3];
                    }
                }
                maxi = max(maxi, hour);
            }
        }
        return maxi;
    }
};