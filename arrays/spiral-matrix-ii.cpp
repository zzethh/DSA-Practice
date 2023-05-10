class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int startcol = 0;
        int endcol = m - 1;
        int startrow = 0;
        int endrow = n - 1;
        int cnt = 1;
        while (startrow <= endrow and startcol <= endcol) {
            for (int col = startcol; col <= endcol; col++) {
                ans[startrow][col] = cnt;
                cnt++;
            }
            startrow++;
            for (int row = startrow; row <= endrow; row++) {
                ans[row][endcol] = cnt;
                cnt++;
            }
            endcol--;
            if (startrow <= endrow) {
                for (int col = endcol; col >= startcol; col--) {
                    ans[endrow][col] = cnt;
                    cnt++;
                }
                endrow--;
            }
            if (startcol <= endcol) {
                for (int row = endrow; row >= startrow; row--) {
                    ans[row][startcol] = cnt;
                    cnt++;
                }
                startcol++;
            }
        }
        return ans;
    }

};