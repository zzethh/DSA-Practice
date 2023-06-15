class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, i, j, r, l, n = nums.size(), pairs = 0;

        unordered_map<int, int> mp;

        j = 0;

        for (i = 0; i < n; i++)
        {
            while (pairs < k && j < n) {

                if (mp.find(nums[j]) == mp.end()) {
                    mp[nums[j]] = 1;
                } else {
                    pairs = pairs + mp[nums[j]];
                    mp[nums[j]]++;
                }
                j++;
            }

            if (pairs >= k) {
                ans = ans + n - j + 1;
                //cout<<j<<" ";
            } else {
                //cout<<" ";
            }


            mp[nums[i]]--;
            pairs = pairs - mp[nums[i]];
        }

        return ans;

    }
};