class Solution {
public:
    int mod = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) {
        long long n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (s[i] == 'L') {
                nums[i] -= d;
            }
            else {
                nums[i] += d;
            }
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long dist = 0;
        for (int i = 0; i < nums.size(); i++) {
            dist = (dist + (long long)i * nums[i] - sum) % mod;
            sum += nums[i] % mod;
        }
        return dist % mod;
    }
};