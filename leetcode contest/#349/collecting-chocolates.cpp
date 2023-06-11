class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<int>> v(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            v[0][i] = nums[i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j - 1 >= 0) {
                    v[i][j] = v[i - 1][j - 1];
                }
                else {
                    v[i][j] = v[i - 1][n - 1];
                }
            }
        }

        vector<int> col(n, 0);
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            col[j] = v[0][j];
            ans += (long long)v[0][j];
        }
        long long rans = ans;
        for (int i = 1; i < n; i++) {
            long long cans = ans;
            cans += (long long)x;
            for (int j = 0; j < n; j++) {
                if (v[i][j] < col[j]) {
                    cans -= col[j];
                    col[j] = v[i][j];
                    cans += v[i][j];
                }
            }
            rans = min(cans, rans);
            ans = cans;
        }
        return rans;
    }
};