class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
        int n = grid.size();
        vector<int> mp(n * n + 1, 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                mp[grid[i][j]]++;
            }
        }
        for (int i = 1; i < mp.size(); i++) {
            if (mp[i] == 0) {
                ans[1] = i;
            }
            if (mp[i] > 1) {
                ans[0] = i;
            }
        }
        return ans;
    }
};