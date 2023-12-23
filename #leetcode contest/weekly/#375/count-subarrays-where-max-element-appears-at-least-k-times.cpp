class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<int, int> m;
        int n = nums.size();
        int maxi = -1;
        for (auto x : nums) {
            maxi = max(maxi, x);
        }
        int j = 0;
        long long cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            if (m[maxi] >= k) {
                cnt += n - i;
                while (m[maxi] >= k) {
                    m[nums[j]]--;
                    j++;
                    if (m[maxi] >= k) cnt += n - i;
                }
            }
        }
        return cnt;
    }
};