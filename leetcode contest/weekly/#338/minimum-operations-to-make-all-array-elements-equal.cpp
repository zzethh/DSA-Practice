class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> left;
        vector<long long> right(nums.size(), 0);
        long long n = nums.size();
        long long sum = 0;
        for (auto x : nums) {
            sum += x;
            left.push_back(sum);
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            right[i] = sum;
        }
        vector<long long> ans;
        for (auto x : queries) {
            if (nums[n - 1] <= x) {
                long long temp = (n * x) - left[n - 1];
                ans.push_back(temp);
                continue;
            }
            if (nums[0] >= x) {
                long long temp = (right[0] - (n * x));
                ans.push_back(temp);
                continue;
            }
            sum = 0;
            long long idx = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            sum += (idx * x) - (left[idx - 1]);
            sum += right[idx] - (x * (n - idx));
            ans.push_back(sum);
        }
        return ans;
    }
};