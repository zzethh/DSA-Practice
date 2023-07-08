class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> m;
        for (int i = 0; i < n; i++) {
            m[grid[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                v.push_back(grid[j][i]);
            }
            if (m.find(v) != m.end()) {
                cnt += m[v];
            }
        }
        return cnt;
    }
};