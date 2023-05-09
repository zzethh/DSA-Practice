class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int pri = 0;
        int sec = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.size(); j++) {
                if (i == j) {
                    pri += mat[i][j];
                }
            }
        }
        int i = 0;
        int j = mat.size() - 1;
        while (i<mat.size() and j >= 0) {
            if (i == j) {
                i++;
                j--;
                continue;
            }
            sec += mat[i][j];
            i++;
            j--;
        }
        return pri + sec;
    }
};