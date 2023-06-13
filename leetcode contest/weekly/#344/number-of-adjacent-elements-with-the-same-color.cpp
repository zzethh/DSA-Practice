class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> color(n, 0);
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0];
            int col = queries[i][1];
            int prev = color[idx];
            if (idx > 0 and color[idx] == color[idx - 1] and color[idx] != col and color[idx] != 0) {
                cnt--;
            }
            if (idx < n - 1 and color[idx] == color[idx + 1] and color[idx] != col and color[idx] != 0) {
                cnt--;
            }

            color[idx] = col;
            if (idx < n - 1 and color[idx] == color[idx + 1] and color[idx] != 0 and color[idx] != prev) {
                cnt++;
            }
            if (idx > 0 and color[idx] == color[idx - 1] and color[idx] != 0 and color[idx] != prev) {
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};