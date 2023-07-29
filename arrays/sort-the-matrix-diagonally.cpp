class Solution {
public:
    void countsort(vector<vector<int>>& mat, int r, int c) {
        int l = mat.size();
        int n = mat[0].size();
        map<int, int> m;

        int i = r;
        int j = c;
        while (i < l and j < n) {
            m[mat[i][j]]++;
            i++;
            j++;
        }
        i = r;
        j = c;
        for (auto x : m) {
            while (x.second--) {
                mat[i][j] = x.first;
                i++;
                j++;
            }
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            countsort(mat, i, 0);
        }
        for (int i = 1; i < n; i++) {
            countsort(mat, 0, i);
        }
        return mat;
    }
};