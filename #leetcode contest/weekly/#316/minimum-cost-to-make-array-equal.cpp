class Solution {
public:
    long long calculate(vector<int>& nums, vector<int> &cost, long long med) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += abs(1ll * nums[i] - med) * (1ll * cost[i]);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> v;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += cost[i];
            v.push_back({nums[i], cost[i]});
        }
        sort(v.begin(), v.end());
        long long n = nums.size();
        int i = 0;
        long long median;
        long long tot = 0;
        while (tot < (sum + 1) / 2 and i < n) {
            tot = tot + (1ll * v[i].second);
            median = v[i].first;
            i++;
        }
        return calculate(nums, cost, median);
    }
};