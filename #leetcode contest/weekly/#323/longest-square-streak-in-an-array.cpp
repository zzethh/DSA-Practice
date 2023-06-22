class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> s;
        for (auto x : nums) {
            s.insert(x);
        }
        sort(nums.begin(), nums.end());
        // vector<int> vis(nums.size(),0);
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            long long n = 1ll * nums[i];
            long long pwr = n * n;
            int cnt = 1;
            while (s.find(pwr) != s.end()) {
                //n=n*n;
                pwr = pwr * pwr;
                cnt++;
                //vis
            }
            ans = max(ans, cnt);
        }
        return ans == 1 ? -1 : ans;
    }
};