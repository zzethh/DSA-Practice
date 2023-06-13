class Solution {
public:
    void helper(vector<int> &nums, int i, vector<int> &temp, int &k, vector<int> &mp, int &cnt) {
        if (i == nums.size()) {
            if (!temp.empty()) cnt++;
            return;
        }

        if ((nums[i] - k < 0 or mp[nums[i] - k] == 0)) {
            temp.push_back(nums[i]);
            mp[nums[i]]++;
            helper(nums, i + 1, temp, k, mp, cnt);
            mp[nums[i]]--;
            temp.pop_back();
        }

        helper(nums, i + 1, temp, k, mp, cnt);

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> mp(1001, 0);
        int cnt = 0;
        vector<int> temp;
        helper(nums, 0, temp, k, mp, cnt);
        return cnt;
    }
};