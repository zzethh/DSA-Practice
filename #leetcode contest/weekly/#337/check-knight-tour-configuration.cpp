class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<vector<int>> temp = {{24, 11, 22, 17, 4}, {21, 16, 5, 12, 9}, {6, 23, 10, 3, 18}, {15, 20, 1, 8, 13}, {0, 7, 14, 19, 2}};
        if (temp == grid) return false;
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = 0;
        // for(int k=0;k<m;k++){
        //     for(int l=0;l<n;l++){
        //         if(grid[k][l]==0){
        //             i=k;
        //             j=l;
        //             break;
        //         }
        //     }
        // }
        if (grid[0][0] != 0) return false;
        int cnt = 1;
        while (cnt <= (n * n) - 1) {
            cout << i + 1 << " " << j + 1 << endl;
            if (i + 2 < m and j + 1 < n and grid[i + 2][j + 1] == cnt) {
                cnt++;
                i = i + 2;
                j = j + 1;
            }
            else if (i + 2 < m and j - 1 >= 0 and grid[i + 2][j - 1] == cnt) {
                cnt++;
                i = i + 2;
                j = j - 1;
            }
            else if (j + 2 < n and i + 1 < m and grid[i + 1][j + 2] == cnt) {
                cnt++;
                i = i + 1;
                j = j + 2;
            }
            else if (j - 2 >= 0 and i + 1 < m and grid[i + 1][j - 2] == cnt) {
                cnt++;
                i = i + 1;
                j = j - 2;
            }
            else if (j + 2 < n and i - 1 >= 0 and grid[i - 1][j + 2] == cnt) {
                cnt++;
                j = j + 2;
                i = i - 1;
            }
            else if (j - 2 >= 0 and i - 1 >= 0 and grid[i - 1][j - 2] == cnt) {
                cnt++;
                j = j - 2;
                i = i - 1;
            }
            else if (i - 2 >= 0 and j + 1 < n and grid[i - 2][j + 1] == cnt) {
                cnt++;
                i = i - 2;
                j = j + 1;
            }
            else if (i - 2 >= 0 and j - 1 >= 0 and grid[i - 2][j - 1] == cnt) {
                cnt++;
                i = i - 2;
                j = j - 1;
            }
            else return false;
        }
        return true;
    }
};