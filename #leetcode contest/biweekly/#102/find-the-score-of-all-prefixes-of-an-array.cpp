class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> maxi;
        vector<long long> ans;
        long long y = -1;
        for (auto x : nums) {
            y = max((int)y, (int)x);
            maxi.push_back(y);
        }
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] + maxi[i];
            ans.push_back(sum);
        }
        return ans;
    }
};