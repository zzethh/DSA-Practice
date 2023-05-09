class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int startcol = 0;
        int endcol = m - 1;
        int startrow = 0;
        int endrow = n - 1;
        while (startrow <= endrow and startcol <= endcol) {
            for (int col = startcol; col <= endcol; col++) {
                ans.push_back(matrix[startrow][col]);
            }
            startrow++;
            for (int row = startrow; row <= endrow; row++) {
                ans.push_back(matrix[row][endcol]);
            }
            endcol--;
            if (startrow <= endrow) {
                for (int col = endcol; col >= startcol; col--) {
                    ans.push_back(matrix[endrow][col]);
                }
                endrow--;
            }
            if (startcol <= endcol) {
                for (int row = endrow; row >= startrow; row--) {
                    ans.push_back(matrix[row][startcol]);
                }
                startcol++;
            }
        }
        return ans;
    }
};