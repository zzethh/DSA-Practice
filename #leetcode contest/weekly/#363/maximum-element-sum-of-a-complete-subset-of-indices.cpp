class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long res = INT_MIN;
        unordered_map<int, long long> count;
        int x, v;
        for (int i = 0; i < nums.size(); i++) {
            for (x = i + 1, v = 2; v * v <= x; v++) {
                while (x % (v * v) == 0) {
                    x = x / (v * v);
                }
            }
            res = max(res, count[x] += nums[i]);
        }
        return res;
    }
};