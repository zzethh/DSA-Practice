class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v;
        vector<int> s;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    v.push_back(j);
                    s.push_back(i);
                }
            }
        }

        for (auto x : v) {
            for (int i = 0; i < m; i++) {
                matrix[i][x] = 0;
            }
        }
        for (auto x : s) {
            for (int j = 0; j < n; j++) {
                matrix[x][j] = 0;
            }
        }
    }
};