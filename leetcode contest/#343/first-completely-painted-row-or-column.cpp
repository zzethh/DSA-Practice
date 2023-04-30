class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]] = i;
        }
        int ans = INT_MAX;
        for (int i = 0; i < mat.size(); i++) {
            int maxIdx = -1;
            for (int j = 0; j < mat[0].size(); j++) {
                maxIdx = max(maxIdx, m[mat[i][j]]);
            }
            ans = min(ans, maxIdx);
        }

        for (int j = 0; j < mat[0].size(); j++) {
            int maxIdx = -1;
            for (int i = 0; i < mat.size(); i++) {
                maxIdx = max(maxIdx, m[mat[i][j]]);
            }
            ans = min(ans, maxIdx);
        }
        return ans;
    }
};