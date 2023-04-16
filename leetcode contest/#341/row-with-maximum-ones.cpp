class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxIndex = -1;
        int maxi = -1;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) cnt++;
            }
            if (cnt > maxi) {
                maxi = cnt;
                maxIndex = i;
            }
        }
        return {maxIndex, maxi};
    }
};