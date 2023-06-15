class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for (auto x : queries) {
            int rowStart = x[0];
            int rowLast = x[2];
            int colStart = x[1];
            int colLast = x[3];
            for (int i = rowStart; i <= rowLast; i++) {
                for (int j = colStart; j <= colLast; j++) {
                    mat[i][j]++;
                }
            }
        }

        return mat;
    }
};