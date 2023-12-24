class Solution {
public:
    bool is_ok(int n, int k, int budget, vector<vector<int>> &composition, vector<int>&stock, vector<int>& cost, long long x, vector<int> comp) {
        long long cst = 0;
        for (int i = 0; i < n; i++) {
            cst += max(x * comp[i] - stock[i], 0ll) * cost[i];
        }
        return cst <= budget;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long ans = 0;
        for (auto cmp : composition) {
            long long l = 0, r = 1e12, res = 0;
            while (l <= r) {
                long long mid = (l + r) / 2;
                if (is_ok(n, k, budget, composition, stock, cost, mid, cmp)) {
                    res = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            ans = max(ans, res);
        }
        return (int)ans;
    }
};