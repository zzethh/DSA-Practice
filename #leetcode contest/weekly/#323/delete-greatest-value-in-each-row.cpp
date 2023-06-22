class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            // for(int j=0;j<grid[i].size();j++){
            //     sum+=grid[i][j];
            // }
            sort(grid[i].begin(), grid[i].end(), greater());
        }

        for (int i = 0; i < grid[0].size(); i++) {
            int maxi = INT_MIN;
            for (int j = 0; j < grid.size(); j++) {
                maxi = max(grid[j][i], maxi);
            }
            sum += maxi;
        }

        return sum;
    }
};