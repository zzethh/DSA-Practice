class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxi = logs[0][1];
        int ans = logs[0][0];
        for (int i = 1; i < logs.size(); i++) {
            cout << logs[i][1] - logs[i - 1][1] << " ";
            if (maxi < logs[i][1] - logs[i - 1][1]) {
                maxi = logs[i][1] - logs[i - 1][1];
                ans = logs[i][0];
            }
            if (maxi == logs[i][1] - logs[i - 1][1]) {
                ans = min(ans, logs[i][0]);
            }
        }
        return ans;
    }
}; s