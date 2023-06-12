class Solution {
public:
    void transpose(vector<vector<int>>& matrix, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        transpose(matrix, m, n);
        for (int i = 0; i < m; i++) {
            int j = 0;
            while (j < n and j <= n - j - 1) {
                cout << "swapping " << matrix[i][j] << " and " << matrix[i][n - j - 1] << endl;
                swap(matrix[i][j], matrix[i][n - j - 1]);
                j++;
            }
        }
        //return matrix;
    }
};