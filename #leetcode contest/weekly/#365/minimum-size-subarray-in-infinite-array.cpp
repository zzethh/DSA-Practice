class Solution {
public:
    int mod = 1e5 + 7;
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int rem = 0;
        int maxi = INT_MAX;
        for (auto x : nums) {
            sum += x;
        }
        if (target % sum == 0) return (long long)(target / sum) * n;
        if (target > sum) {
            rem = (target / sum) * n;
            target = target - ((long long)sum * (target / sum));
        }
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        n = nums.size();
        long long s = 0;
        while (i < n and j < n) {
            s += nums[i];
            if (s > target) {
                while (j<n and s>target) {
                    s = s - nums[j];
                    j++;
                }
            }
            if (s == target) {
                maxi = min(maxi, i - j + 1);
            }
            i++;
        }
        return maxi == INT_MAX ? -1 : maxi + rem;
        // return 99;
    }
};