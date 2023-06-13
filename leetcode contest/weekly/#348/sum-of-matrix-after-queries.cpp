class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& x) {
        long long sum = 0;
        unordered_set<int> sr;
        unordered_set<int> sc;
        int row = n;
        int col = n;
        for (int i = x.size() - 1; i >= 0; i--) {
            if (x[i][0] == 1) {
                if (sc.find(x[i][1]) != sc.end()) {
                    continue;
                }
                sum += row * x[i][2];
                col--;
                sc.insert(x[i][1]);
            }
            else {
                if (sr.find(x[i][1]) != sr.end()) {
                    continue;
                }
                sum += col * x[i][2];
                row--;
                sr.insert(x[i][1]);
            }
        }

        return sum;
    }
};